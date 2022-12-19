/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** BSD License Usage
** Alternatively, you may use this file under the terms of the BSD license
** as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include "glwidget.h"
#include <QCoreApplication>
#include <QMouseEvent>
#include <QOpenGLShaderProgram>
#include <QVector3D>
#include <iostream>
#include <math.h>

bool GLWidget::m_transparent = false;

GLWidget::GLWidget(QWidget *parent)
    : QOpenGLWidget(parent), m_xRot(0), m_yRot(0), m_zRot(0), m_xMove(0),
      m_yMove(0), m_zMove(0), m_Multip(1.0), m_RedColor(0.2), m_GreenColor(0.2),
      m_BlueColor(0.2), m_RedColorLine(0.8), m_GreenColorLine(0.5),
      m_BlueColorLine(0.2), m_RedColorVertex(0.5), m_GreenColorVertex(0.8),
      m_BlueColorVertex(0.2), m_LineWidth(1), m_VertexSize(5), m_VertexType(0),
      m_perspect(1), m_lineType(0), m_aspect(1.0), m_program(0), gifCounter(-1),
      gifFileName(nullptr) {
  this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

  this->setMinimumHeight(100);
  this->setMinimumWidth(100);
  m_core =
      QSurfaceFormat::defaultFormat().profile() == QSurfaceFormat::CoreProfile;
  if (m_transparent) {
    QSurfaceFormat fmt = format();
    fmt.setAlphaBufferSize(8);
    setFormat(fmt);
  }
}

GLWidget::~GLWidget() {
  save_start_pos();
  if (gifFileName != nullptr) delete[] gifFileName;
  cleanup();
}

QSize GLWidget::minimumSizeHint() const { return QSize(50, 50); }

QSize GLWidget::sizeHint() const { return QSize(400, 400); }

static const char *vertexShaderSourceCore =
    "#version 150\n"
    "in vec4 vertex;\n"
    "in vec3 normal;\n"
    "out vec3 vert;\n"
    "out vec3 vertNormal;\n"
    "uniform mat4 projMatrix;\n"
    "uniform mat4 mvMatrix;\n"
    "uniform mat3 normalMatrix;\n"
    "void main() {\n"
    "   vert = vertex.xyz;\n"
    "   vertNormal = normalMatrix * normal;\n"
    "   vec4 moved_vertex = mvMatrix * vertex;\n"
    " //  gl_Position = projMatrix * moved_vertex;\n"
    "   gl_Position = mvMatrix * vertex;\n"
    "}\n";

static const char *fragmentShaderSourceCore =
    "#version 150\n"
    "in highp vec3 vert;\n"
    "in highp vec3 vertNormal;\n"
    "out highp vec4 fragColor;\n"
    "uniform highp vec3 lightPos;\n"
    "void main() {\n"
    "   highp vec3 L = normalize(lightPos - vert);\n"
    "   highp float NL = max(dot(normalize(vertNormal), L), 0.0);\n"
    "   highp vec3 color = vec3(0.89, 1.0, 0.0);\n"
    "   highp vec3 col = clamp(color * 0.2 + color * 0.8 * NL, 0.0, 1.0);\n"
    "   fragColor = vec4(col, 1.0);\n"
    "}\n";

static const char *vertexShaderSource =
    "attribute vec4 vertex;\n"
    "varying float forColor;\n"
    "uniform mat4 projMatrix;\n"
    "uniform mat4 mvMatrix;\n"
    "uniform float vertexSize;\n"
    "void main() {\n"
    "   gl_Position = projMatrix * mvMatrix * vertex;\n"
    "   gl_PointSize = vertexSize;\n"
    "   forColor = clamp((1.3 - (1.0 + gl_Position.z)/3.0) * 1.2, 0.0, 1.0);\n"
    "}\n";

static const char *fragmentShaderSource =
    "varying float forColor;\n"
    "uniform vec3 ColorLine;\n"
    "void main() {\n"
    "   highp vec3 color = ColorLine * forColor;\n"
    "   gl_FragColor = vec4(color, 1.0);\n"
    "}\n";

void GLWidget::initializeGL() {
  connect(context(), &QOpenGLContext::aboutToBeDestroyed, this,
          &GLWidget::cleanup);

  initializeOpenGLFunctions();

  glClearColor(m_RedColor, m_GreenColor, m_BlueColor, m_transparent ? 0 : 1);
  m_program = new QOpenGLShaderProgram;
  m_program->addShaderFromSourceCode(QOpenGLShader::Vertex,
                                     m_core ? vertexShaderSourceCore
                                            : vertexShaderSource);
  m_program->addShaderFromSourceCode(QOpenGLShader::Fragment,
                                     m_core ? fragmentShaderSourceCore
                                            : fragmentShaderSource);
  m_program->bindAttributeLocation("vertex", 0);
  m_program->link();

  m_program->bind();
  m_projMatrixLoc = m_program->uniformLocation("projMatrix");
  m_mvMatrixLoc = m_program->uniformLocation("mvMatrix");
  m_colorChange = m_program->uniformLocation("ColorLine");
  m_PointSize = m_program->uniformLocation("vertexSize");

  m_vao.create();
  QOpenGLVertexArrayObject::Binder vaoBinder(&m_vao);

  m_modelVbo.create();
  m_modelVbo.bind();
  m_modelVbo.allocate((m_model.count() + m_model.dotsCount()) *
                      sizeof(GLfloat));
  m_modelVbo.write(0, m_model.constData(), m_model.count() * sizeof(GLfloat));
  m_modelVbo.write(m_model.count() * sizeof(GLfloat), m_model.constDotData(),
                   m_model.dotsCount() * sizeof(GLfloat));

  setupVertexAttribs();

  m_camera.setToIdentity();
  m_camera.translate(0, 0, -1);

  m_program->setUniformValue(m_lightPosLoc, QVector3D(0, 0, 5));

  m_program->release();
}

void GLWidget::setupVertexAttribs() {
  m_modelVbo.bind();
  QOpenGLFunctions *f = QOpenGLContext::currentContext()->functions();
  f->glEnableVertexAttribArray(0);
  f->glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), 0);
  m_modelVbo.release();
}

void GLWidget::paintGL() {
  checkForSpecs();

  unary_matrix.init_matrix(4, 4);
  unary_matrix.set_unary();
  unary_matrix.rotate_matrix(180.0f - (m_xRot / 16.0f), m_yRot / 16.0f,
                             m_zRot / 16.0f);
  unary_matrix.resize_matrix(m_Multip);
  unary_matrix.move_matrix((float)m_xMove / 100, (float)m_yMove / 100,
                           (float)m_zMove / 100);
  QMatrix4x4 m_test = unary_matrix.convertToQMatrix4x4();

  QOpenGLVertexArrayObject::Binder vaoBinder(&m_vao);

  project_matrix.init_matrix(4, 4);
  project_matrix.set_unary();
  if (m_perspect == 1) {
    project_matrix.project_matrix(45.0f, m_aspect, 0.01f, 100.0f);
  } else {
    project_matrix.project_matrix(0.0f, m_aspect, 0.01f, 100.0f);
  }

  QMatrix4x4 m_test_proj = project_matrix.convertToQMatrix4x4();

  m_program->bind();
  m_program->setUniformValue(m_projMatrixLoc, m_test_proj);
  m_program->setUniformValue(m_mvMatrixLoc, m_camera * m_test);
  m_program->setUniformValue(m_PointSize, (GLfloat)m_VertexSize);
  m_program->setUniformValue(
      m_colorChange,
      QVector3D(m_RedColorLine, m_GreenColorLine, m_BlueColorLine));
  glDrawArrays(GL_LINES, 0, m_model.linesAmount());
  if (m_VertexType == 1 || m_VertexType == 2) {
    m_program->setUniformValue(
        m_colorChange,
        QVector3D(m_RedColorVertex, m_GreenColorVertex, m_BlueColorVertex));
    glDrawArrays(GL_POINTS, m_model.linesAmount(), m_model.dotsAmount());
  }
  m_program->release();
}

void GLWidget::checkForSpecs() {
  glClearColor(m_RedColor, m_GreenColor, m_BlueColor, m_transparent ? 0 : 1);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_CULL_FACE);

  if (m_lineType == 1) {
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
  if (m_VertexType == 1) {
#ifdef __linux__
    glPointSize((GLfloat)m_VertexSize);
#endif
#ifdef __APPLE__
    glPointSize((GLfloat)m_VertexSize);
#endif
    glEnable(GL_POINT_SMOOTH);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_PROGRAM_POINT_SIZE);
  }
  if (m_VertexType == 2) {
    glDisable(GL_PROGRAM_POINT_SIZE);
    glDisable(GL_POINT_SMOOTH);
    glDisable(GL_BLEND);
    glBlendFunc(GL_ZERO, GL_ONE);
#ifdef __linux__
    glPointSize((GLfloat)m_VertexSize);
#endif
  }
  glLineWidth(m_LineWidth);
}

void GLWidget::resizeGL(int w, int h) { m_aspect = GLfloat(w) / h; }
