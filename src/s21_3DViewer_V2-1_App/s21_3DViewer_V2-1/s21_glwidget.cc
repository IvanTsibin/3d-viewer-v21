#include "s21_glwidget.h"
#include <QCoreApplication>
#include <QMouseEvent>
#include <QOpenGLShaderProgram>
#include <QVector3D>
#include <iostream>
#include <math.h>
#include <stdio.h>

bool GLWidget::m_transparent_ = false;

GLWidget::GLWidget(QWidget *parent)
    : QOpenGLWidget(parent), m_program_(0), m_aspect_(1.0), set_(nullptr) {

  this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

  this->setMinimumHeight(100);
  this->setMinimumWidth(100);
  m_core_ =
      QSurfaceFormat::defaultFormat().profile() == QSurfaceFormat::CoreProfile;
  // --transparent causes the clear color to be transparent. Therefore, on
  // systems that support it, the widget will become transparent apart from the
  // model.
  if (m_transparent_) {
    QSurfaceFormat fmt = format();
    fmt.setAlphaBufferSize(8);
    setFormat(fmt);
  }
//  std::cout << " GLWidget::GLWidget(QWidget *parent) " << std::endl;
}

GLWidget::~GLWidget() {
  emit SaveStartPos();
  Cleanup();
}

QSize GLWidget::minimumSizeHint() const { return QSize(50, 50); }

QSize GLWidget::sizeHint() const { return QSize(400, 400); }

static const char *vertexShaderSource =
    "attribute vec4 vertex;\n"
    "attribute vec3 normal;\n"
    "varying vec3 vert;\n"
    "varying vec3 vertNormal;\n"
    "varying float forColor;\n"
    "uniform mat4 projMatrix;\n"
    "uniform mat4 mvMatrix;\n"
    "uniform float vertexSize;\n"
    "uniform mat3 normalMatrix;\n"
    "void main() {\n"
    "   vert = vertex.xyz;\n"
    "   vertNormal = normalMatrix * normal;\n"
    "   gl_Position = projMatrix * mvMatrix * vertex;\n"
    "   gl_PointSize = vertexSize;\n"
    "   forColor = clamp((1.3 - (1.0 + gl_Position.z)/3.0) * 1.2, 0.0, 1.0);\n"
    "}\n";

static const char *fragmentShaderSource =
    "varying highp vec3 vert;\n"
    "varying highp vec3 vertNormal;\n"
    "uniform highp vec3 lightPos;\n"
    "varying float forColor;\n"
    "uniform vec3 ColorLine;\n"
    "uniform vec3 ColorVertex;\n"
    "uniform vec3 ColorFacets;\n"
    "uniform vec3 ColorLight;\n"
    "uniform int colorFlag;\n"
    "void main() {\n"
    "   highp vec3 L = normalize(lightPos - vert);\n"
    "   highp float NL = max(dot(normalize(vertNormal), L), 0.0);\n"
    "   highp vec3 colorL = ColorLine * forColor;\n"
    "   highp vec3 colorV = ColorVertex * forColor;\n"
    "   if (colorFlag == 1) {\n"
    "       gl_FragColor = vec4(colorV, 1.0);\n"
    "   } else if (colorFlag == 2) {\n"
    "       gl_FragColor = vec4(colorL, 1.0);\n"
    "   } else if (colorFlag == 3) {\n"
    "       highp vec3 col;\n"
    "       highp vec3 colN = ColorFacets * 0.2 + ColorFacets * 0.8 * NL;\n"
    "       highp vec3 colNCL;\n"
    "       colNCL = colN * ColorLight;\n"
    "       col = clamp(colNCL, 0.0, 1.0);\n"
    "       gl_FragColor = vec4(col, 1.0);\n"
    "   }\n"
    "}\n";

void GLWidget::initializeGL() {

  connect(context(), &QOpenGLContext::aboutToBeDestroyed, this,
          &GLWidget::Cleanup);

  initializeOpenGLFunctions();

  glClearColor(set_->RedColor, set_->GreenColor, set_->BlueColor,
               m_transparent_ ? 0 : 1);

  m_program_ = new QOpenGLShaderProgram;
  m_program_->addShaderFromSourceCode(QOpenGLShader::Vertex, vertexShaderSource);
  m_program_->addShaderFromSourceCode(QOpenGLShader::Fragment,fragmentShaderSource);
  //    m_program_->addShaderFromSourceFile(QOpenGLShader::Vertex,
  //    "../s21_3DViewer_V2-1/vshader.glsl");
  //    m_program_->addShaderFromSourceFile(QOpenGLShader::Fragment,
  //    "../s21_3DViewer_V2-1/fshader.glsl");
  m_program_->bindAttributeLocation("vertex", 0);
  m_program_->bindAttributeLocation("normal", 1);
  m_program_->link();

  m_program_->bind();
  m_proj_matrix_loc_ = m_program_->uniformLocation("projMatrix");
  m_mv_matrix_loc_ = m_program_->uniformLocation("mvMatrix");
  m_color_line_ = m_program_->uniformLocation("ColorLine");
  m_color_vertex_ = m_program_->uniformLocation("ColorVertex");
  m_color_light_ = m_program_->uniformLocation("ColorLight");
  m_color_facets_ = m_program_->uniformLocation("ColorFacets");
  m_point_size_ = m_program_->uniformLocation("vertexSize");

  m_normal_matrix_loc_ = m_program_->uniformLocation("normalMatrix");
  m_light_pos_loc_ = m_program_->uniformLocation("lightPos");
  m_color_flag_ = m_program_->uniformLocation("colorFlag");

  m_vao.create();
  QOpenGLVertexArrayObject::Binder vaoBinder(&m_vao);

  // Setup our vertex buffer object.
  m_model_vbo_.create();
  m_model_vbo_.bind();
  //    GLfloat *p = (float*) m_model_.constTriangleData();
  //    for (int i = 0; i < m_model_.trianglesCount(); i++) {
  //        std::cout << "m_model.constTriangleData(" << i << ") = " << *p++ <<
  //        std::endl;
  //    }
  AddDataToModelVBO();
  //    GLfloat *p = (float*) m_model_.constDotData();
  //    for (int i = 0; i < m_model_.dotsCount(); i++) {
  //        std::cout << "m_model.constDotData(" << i << ") = " << *p++ <<
  //        std::endl;
  //    }

  // Store the vertex attribute bindings for the program.
  SetupVertexAttribs();
  // Our camera never changes in this example.
  m_camera_.setToIdentity();
  m_camera_.translate(0, 0, -1);

  // Light position is fixed.
  //    m_program_->setUniformValue(m_light_pos_loc_, QVector3D(0, 0, 5));
  m_program_->release();
}

void GLWidget::AddDataToModelVBO() {
  m_model_vbo_.allocate((m_model_.Count() + m_model_.DotsCount() +
                       m_model_.TrianglesCount() +
                       m_model_.TrianglesGuroCount()) *
                      sizeof(GLfloat));
  m_model_vbo_.write(0, m_model_.ConstData(), m_model_.Count() * sizeof(GLfloat));
  m_model_vbo_.write(m_model_.Count() * sizeof(GLfloat), m_model_.ConstDotData(),
                   m_model_.DotsCount() * sizeof(GLfloat));
  m_model_vbo_.write((m_model_.Count() + m_model_.DotsCount()) * sizeof(GLfloat),
                   m_model_.ConstTriangleData(),
                   m_model_.TrianglesCount() * sizeof(GLfloat));
  m_model_vbo_.write(
      (m_model_.Count() + m_model_.DotsCount() + m_model_.TrianglesCount()) *
          sizeof(GLfloat),
      m_model_.ConstTriangleGuroData(),
      m_model_.TrianglesGuroCount() * sizeof(GLfloat));
  //    int size_bytes = (m_model.count() + m_model_.dotsCount() +
  //    m_model_.trianglesCount() + m_model_.trianglesGuroCount()) *
  //    sizeof(GLfloat); int size_kylo_bytes = size_bytes / 1024; std::cout <<
  //    "Model stze is " << size_bytes << "  bytes, Kb =  " << size_kylo_bytes
  //    << " Mb = " << size_kylo_bytes / 1024 << std::endl;
}

void GLWidget::SetupVertexAttribs() {
  m_model_vbo_.bind();
  QOpenGLFunctions *f = QOpenGLContext::currentContext()->functions();
  f->glEnableVertexAttribArray(0);
  f->glEnableVertexAttribArray(1);
  f->glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), 0);
  f->glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat),
                           reinterpret_cast<void *>(3 * sizeof(GLfloat)));
  m_model_vbo_.release();
}

void GLWidget::paintGL() {
  CheckForSpecs();

  unary_matrix_.InitMatrix(4, 4);
  unary_matrix_.SetUnary();
  unary_matrix_.RotateMatrix(180.0f - (set_->xRot / 16.0f), set_->yRot / 16.0f,
                             set_->zRot / 16.0f);
  unary_matrix_.ResizeMatrix(set_->Multip);
  unary_matrix_.MoveMatrix((float)set_->xMove / 100, (float)set_->yMove / 100,
                           (float)set_->zMove / 100);
  QMatrix4x4 m_test_ = unary_matrix_.convertToQMatrix4x4();

  QOpenGLVertexArrayObject::Binder vaoBinder(&m_vao);

  project_matrix_.InitMatrix(4, 4);
  project_matrix_.SetUnary();
  if (set_->perspect == 1) {
    project_matrix_.ProjectMatrix(45.0f, m_aspect_, 0.01f, 100.0f);
  } else {
    project_matrix_.ProjectMatrix(0.0f, m_aspect_, 0.01f, 100.0f);
  }

  QMatrix4x4 m_test_proj_ = project_matrix_.convertToQMatrix4x4();

  m_program_->bind();
  m_program_->setUniformValue(m_light_pos_loc_,
                             QVector3D(((GLfloat)set_->xLight) / 100,
                                       ((GLfloat)set_->yLight) / 100, 5));
  m_program_->setUniformValue(m_proj_matrix_loc_, m_test_proj_);
  m_program_->setUniformValue(m_mv_matrix_loc_, m_camera_ * m_test_);
  QMatrix3x3 normalMatrix = m_test_.normalMatrix();
  m_program_->setUniformValue(m_normal_matrix_loc_, normalMatrix);
  m_program_->setUniformValue(m_point_size_, (GLfloat)set_->VertexSize);
  m_program_->setUniformValue(
      m_color_line_,
      QVector3D(set_->RedColorLine, set_->GreenColorLine, set_->BlueColorLine));
  m_program_->setUniformValue(m_color_light_, QVector3D(set_->RedColorLight,
                                                     set_->GreenColorLight,
                                                     set_->BlueColorLight));
  m_program_->setUniformValue(m_color_flag_, 2);
  if (set_->LineWidth != 0)
    glDrawArrays(GL_LINES, 0, m_model_.LinesAmount());
  if ((set_->VertexType == 1 || set_->VertexType == 2) &&
      set_->VertexSize != 0) {
    m_program_->setUniformValue(m_color_flag_, 1);
    m_program_->setUniformValue(m_color_vertex_, QVector3D(set_->RedColorVertex,
                                                        set_->GreenColorVertex,
                                                        set_->BlueColorVertex));
    glDrawArrays(GL_POINTS, m_model_.LinesAmount(), m_model_.DotsAmount());
  }
  if (set_->facets == 1) {
    m_program_->setUniformValue(m_color_flag_, 3);
    m_program_->setUniformValue(m_color_facets_, QVector3D(set_->RedColorFacets,
                                                        set_->GreenColorFacets,
                                                        set_->BlueColorFacets));
    if (set_->NormalGuro == 1) {
      glDrawArrays(GL_TRIANGLES,
                   m_model_.LinesAmount() + m_model_.DotsAmount() +
                       m_model_.TrianglesAmount(),
                   m_model_.TrianglesGuroAmount());
    } else {
      glDrawArrays(GL_TRIANGLES, m_model_.LinesAmount() + m_model_.DotsAmount(),
                   m_model_.TrianglesAmount());
    }
  }
  m_program_->release();
}

void GLWidget::CheckForSpecs() {
  glClearColor(set_->RedColor, set_->GreenColor, set_->BlueColor,
               m_transparent_ ? 0 : 1);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_CULL_FACE);

  if (set_->lineType == 1) {
    glEnable(GL_LINE_STIPPLE);
#ifdef __linux__
    glLineStipple(4, 0x00FF);
#endif
#ifdef __APPLE__
    glLineStipple(4, 0x00FF);
#endif
  } else {
    glDisable(GL_LINE_STIPPLE);
  }
  if (set_->VertexType == 1) {
#ifdef __linux__
    glPointSize((GLfloat)set_->VertexSize);
#endif
#ifdef __APPLE__
    glPointSize((GLfloat)set_->VertexSize);
#endif
    glEnable(GL_POINT_SMOOTH);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_PROGRAM_POINT_SIZE);
  }
  if (set_->VertexType == 2) {
    glDisable(GL_PROGRAM_POINT_SIZE);
    glDisable(GL_POINT_SMOOTH);
    glDisable(GL_BLEND);
    glBlendFunc(GL_ZERO, GL_ONE);
#ifdef __linux__
    glPointSize((GLfloat)set_->VertexSize);
#endif
#ifdef __APPLE__
    glPointSize((GLfloat)set_->VertexSize);
#endif
  }
  glLineWidth(set_->LineWidth);
}

void GLWidget::resizeGL(int w, int h) {
  m_aspect_ = GLfloat(w) / h;
  set_->aspect = m_aspect_;
  emit sendSettingsToController(set_);
}
