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
#include <QMouseEvent>
#include <QOpenGLShaderProgram>
#include <QCoreApplication>
#include <math.h>
#include <iostream>
#include <QVector3D>

bool GLWidget::m_transparent = false;

GLWidget::GLWidget(QWidget *parent)
    : QOpenGLWidget(parent),
      m_xRot(0),
      m_yRot(0),
      m_zRot(0),
      m_xMove(0),
      m_yMove(0),
      m_zMove(0),
      m_Multip(1.0),
      m_RedColor(0.2),
      m_GreenColor(0.2),
      m_BlueColor(0.2),
      m_RedColorLine(0.8),
      m_GreenColorLine(0.5),
      m_BlueColorLine(0.2),
      m_RedColorVertex(0.5),
      m_GreenColorVertex(0.8),
      m_BlueColorVertex(0.2),
      m_LineWidth(1),
      m_VertexSize(5),
      m_VertexType(0),
      m_perspect(1),
      m_aspect(1.0),
      m_lineType(0),
      m_program(0)

{
    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    this->setMinimumHeight(100);
    this->setMinimumWidth(100);
    m_core = QSurfaceFormat::defaultFormat().profile() == QSurfaceFormat::CoreProfile;
    // --transparent causes the clear color to be transparent. Therefore, on systems that
    // support it, the widget will become transparent apart from the logo.
    if (m_transparent) {
        QSurfaceFormat fmt = format();
        fmt.setAlphaBufferSize(8);
        setFormat(fmt);
    }
}

GLWidget::~GLWidget()
{
    save_start_pos();
    cleanup();
}

QSize GLWidget::minimumSizeHint() const
{
    return QSize(50, 50);
}

QSize GLWidget::sizeHint() const
{
    return QSize(400, 400);
}

static void qNormalizeAngle(int &angle)
{
    while (angle < 0)
        angle += 360 * 16;
    while (angle > 360 * 16)
        angle -= 360 * 16;
}

void GLWidget::setXRotation(int angle)
{
    qNormalizeAngle(angle);
    if (angle != m_xRot) {
        m_xRot = angle;
        emit xRotationChanged(angle);
        update();
    }
}

void GLWidget::setYRotation(int angle)
{
    qNormalizeAngle(angle);
    if (angle != m_yRot) {
        m_yRot = angle;
        emit yRotationChanged(angle);
        update();
    }
}

void GLWidget::setZRotation(int angle)
{
    qNormalizeAngle(angle);
    if (angle != m_zRot) {
        m_zRot = angle;
        emit zRotationChanged(angle);
        update();
    }
}

void GLWidget::setMultip(int multip)
{
    m_Multip = 1.0 + ((float)multip) / 100;
    emit multipChanged(multip);
    update();
}

void GLWidget::setXMove(int x_move)
{
    if (x_move != m_xMove) {
        m_xMove = x_move;
        emit xMoveChanged(x_move);
        update();
    }
}

void GLWidget::setYMove(int y_move)
{
    if (y_move != m_yMove) {
        m_yMove = y_move;
        emit yMoveChanged(y_move);
        update();
    }
}

void GLWidget::setZMove(int z_move)
{
    if (z_move != m_zMove) {
        m_zMove = z_move;
        emit zMoveChanged(z_move);
        update();
    }
}

void GLWidget::cleanup()
{
    if (m_program == nullptr)
        return;
    makeCurrent();
    m_logoVbo.destroy();
    delete m_program;
    m_program = 0;
    doneCurrent();
}

void GLWidget::get_main_window_size_changed(const QSize &iconSize) {
    if (iconSize.width() > 100) {
        resizeGL(iconSize.width(), iconSize.height());
        update();
    }
}

void GLWidget::get_file_name(char *str) {
    char str_file_name[255];
    int lenth = strlen(str);
    for (int i = 0; i < 255; i++) str_file_name[i] = '\0';
    for (int i = 0; i < lenth; i++) {
        str_file_name[i] = str[i];
    }
    str_file_name[lenth] = '\0';
    if (strlen(str) != 0) {
        m_cube.reLoadData(str_file_name);
        emit send_facets_amount(m_cube.linesAmount());
        emit send_vertexes_amount(m_cube.dotsAmount());
        m_logoVbo.bind();
        m_logoVbo.allocate((m_cube.count() + m_cube.dotsCount())* sizeof(GLfloat));
        m_logoVbo.write(0, m_cube.constData(), m_cube.count() * sizeof(GLfloat));
        m_logoVbo.write(m_cube.count() * sizeof(GLfloat), m_cube.constDotData(), m_cube.dotsCount() * sizeof(GLfloat));
    }
    update();
}

void GLWidget::setRedColor(int RedColor) {
    m_RedColor = (float) RedColor / 255.0;
    emit RedColorChanged(RedColor);
    update();
}
void GLWidget::setGreenColor(int GreenColor) {
    m_GreenColor = (float) GreenColor / 255.0;
    emit GreenColorChanged(GreenColor);
    update();
}
void GLWidget::setBlueColor(int BlueColor) {
    m_BlueColor = (float) BlueColor / 255.0;
    emit BlueColorChanged(BlueColor);
    update();
}

void GLWidget::setRedColorLine(int RedColorLine) {
    m_RedColorLine = (float) RedColorLine / 255.0;
    emit RedColorLineChanged(RedColorLine);
    update();
}
void GLWidget::setGreenColorLine(int GreenColorLine) {
    m_GreenColorLine = (float) GreenColorLine / 255.0;
    emit GreenColorLineChanged(GreenColorLine);
    update();
}
void GLWidget::setBlueColorLine(int BlueColorLine) {
    m_BlueColorLine = (float) BlueColorLine / 255.0;
    emit BlueColorLineChanged(BlueColorLine);
    update();
}

void GLWidget::setRedColorVertex(int RedColorVertex) {
    m_RedColorVertex = (float) RedColorVertex / 255.0;
    emit RedColorVertexChanged(RedColorVertex);
    update();
}
void GLWidget::setGreenColorVertex(int GreenColorVertex) {
    m_GreenColorVertex = (float) GreenColorVertex / 255.0;
    emit GreenColorVertexChanged(GreenColorVertex);
    update();
}
void GLWidget::setBlueColorVertex(int BlueColorVertex) {
    m_BlueColorVertex = (float) BlueColorVertex / 255.0;
    emit BlueColorVertexChanged(BlueColorVertex);
    update();
}

void GLWidget::setLineWidth(int LineWidth) {
    m_LineWidth = LineWidth;
    emit LineWidthChanged(LineWidth);
    update();
}

void GLWidget::setVertexSize(int VertexSize) {
    m_VertexSize = VertexSize;
    emit VertexSizeChanged(VertexSize);
    update();
}

void GLWidget::setVertexType(int VertexType) {
    m_VertexType = VertexType;
    emit VertexTypeChanged(VertexType);
    update();
}


void GLWidget::setPerspectiveStatus(int PerspectiveStatus) {
    m_perspect = PerspectiveStatus;
    std::cout << "in get_perspect_status m_perspective = " << m_perspect << std::endl;
    emit PersectiveChanged(PerspectiveStatus);
    update();
}

void GLWidget::setDashLineSignal(int signal) {
    if (signal == 1) {
        m_lineType = 1;
    } else {
        m_lineType = 0;
    }
    std::cout << "m_lineType = " << m_lineType << std::endl;
    emit DashLineChanged(signal);
    update();
}

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
    "attribute vec3 normal;\n"
    "varying vec3 vert;\n"
    "varying vec3 vertNormal;\n"
    "varying float forColor;\n"
    "uniform mat4 projMatrix;\n"
    "uniform mat4 mvMatrix;\n"
    "uniform mat3 normalMatrix;\n"
    "uniform float vertexSize;\n"
    "void main() {\n"
    "   vert = vertex.xyz;\n"
    "   vertNormal = normalMatrix * normal;\n"
    "   gl_Position = projMatrix * mvMatrix * vertex;\n"
    "   gl_PointSize = vertexSize;\n"
    "   forColor = clamp((1.3 - (1.0 + gl_Position.z)/3.0) * 1.2, 0.0, 1.0);\n"
    "}\n";



static const char *fragmentShaderSource =
    "varying float colorD;\n"
    "varying highp vec3 vert;\n"
    "varying highp vec3 vertNormal;\n"
    "varying float forColor;\n"
    "uniform highp vec3 lightPos;\n"
    "uniform vec3 ColorLine;\n"
    "void main() {\n"
    "   highp vec3 L = normalize(lightPos - vert);\n"
    "   highp float NL = max(dot(normalize(vertNormal), L), 0.0);\n"
    "   highp vec3 color = ColorLine * forColor;\n"
    "   highp vec3 col = clamp(color * 0.2 + color * 0.8 * NL, 0.0, 1.0);\n"
    "   gl_FragColor = vec4(color, 1.0);\n"
    "}\n";

void GLWidget::initializeGL()
{
    // In this example the widget's corresponding top-level window can change
    // several times during the widget's lifetime. Whenever this happens, the
    // QOpenGLWidget's associated context is destroyed and a new one is created.
    // Therefore we have to be prepared to clean up the resources on the
    // aboutToBeDestroyed() signal, instead of the destructor. The emission of
    // the signal will be followed by an invocation of initializeGL() where we
    // can recreate all resources.

//    std::cout << " *fragmentShaderSource = \n" << fragmentShaderSource << std::endl;

//    m_cube.reLoadData("d:/School-21/CPP4_3DViewer_v2.0-0/src-traning/obj-images/Rocket-1.obj");

//    GLfloat *k = (GLfloat *) m_cube.constData();
//    for (int i = 0; i < m_cube.count(); i++) {
//        std::cout << " i = " << i << " *p = " << *k++ << std::endl;
//    }

    connect(context(), &QOpenGLContext::aboutToBeDestroyed, this, &GLWidget::cleanup);

    initializeOpenGLFunctions();

    glClearColor(m_RedColor, m_GreenColor, m_BlueColor, m_transparent ? 0 : 1);

    std::cout << " m_RedColor = " << m_RedColor << std::endl;

    m_program = new QOpenGLShaderProgram;

    m_program->addShaderFromSourceCode(QOpenGLShader::Vertex, m_core ? vertexShaderSourceCore : vertexShaderSource);
    m_program->addShaderFromSourceCode(QOpenGLShader::Fragment, m_core ? fragmentShaderSourceCore : fragmentShaderSource);
    m_program->bindAttributeLocation("vertex", 0);
    m_program->bindAttributeLocation("normal", 1);
    m_program->link();

    m_program->bind();
    m_projMatrixLoc = m_program->uniformLocation("projMatrix");
    m_mvMatrixLoc = m_program->uniformLocation("mvMatrix");
    m_normalMatrixLoc = m_program->uniformLocation("normalMatrix");
    m_lightPosLoc = m_program->uniformLocation("lightPos");
    m_colorChange = m_program->uniformLocation("ColorLine");
    m_PointSize = m_program->uniformLocation("vertexSize");

    // Create a vertex array object. In OpenGL ES 2.0 and OpenGL 2.x
    // implementations this is optional and support may not be present
    // at all. Nonetheless the below code works in all cases and makes
    // sure there is a VAO when one is needed.
    m_vao.create();
    QOpenGLVertexArrayObject::Binder vaoBinder(&m_vao);

    // Setup our vertex buffer object.
    m_logoVbo.create();
    m_logoVbo.bind();
    m_logoVbo.allocate((m_cube.count() + m_cube.dotsCount())* sizeof(GLfloat));
    m_logoVbo.write(0, m_cube.constData(), m_cube.count() * sizeof(GLfloat));
    m_logoVbo.write(m_cube.count() * sizeof(GLfloat), m_cube.constDotData(), m_cube.dotsCount() * sizeof(GLfloat));

    // Store the vertex attribute bindings for the program.
    setupVertexAttribs();

    // Our camera never changes in this example.
    m_camera.setToIdentity();
    m_camera.translate(0, 0, -1);

    // Light position is fixed.
    m_program->setUniformValue(m_lightPosLoc, QVector3D(0, 0, 5));

    m_program->release();

}

void GLWidget::setupVertexAttribs()
{
    m_logoVbo.bind();
    QOpenGLFunctions *f = QOpenGLContext::currentContext()->functions();
    f->glEnableVertexAttribArray(0);
    f->glEnableVertexAttribArray(1);
    f->glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), 0);
    f->glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), reinterpret_cast<void *>(3 * sizeof(GLfloat)));
    m_logoVbo.release();
}

void GLWidget::paintGL()
{
    glClearColor(m_RedColor, m_GreenColor, m_BlueColor, m_transparent ? 0 : 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);

    if (m_lineType == 1) {
            glEnable(GL_LINE_STIPPLE);
#ifdef __linux__
            glLineStipple(4, 0x00FF);
#endif
    } else {
            glDisable(GL_LINE_STIPPLE);
    }
    if (m_VertexType == 1) {
#ifdef __linux__
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
//      std::cout << "New m_VertexSize = " << m_VertexSize << std::endl;
    }
//    std::cout << "m_VertexType = " << m_VertexType << std::endl;
//    std::cout << "New m_VertexSize = " << m_VertexSize << std::endl;
    glLineWidth(m_LineWidth);

    m_world.setToIdentity();
    m_world.rotate(180.0f - (m_xRot / 16.0f), 1, 0, 0);
    m_world.rotate(m_yRot / 16.0f, 0, 1, 0);
    m_world.rotate(m_zRot / 16.0f, 0, 0, 1);
    m_world.translate((float)m_xMove / 100, (float)m_yMove / 100, (float)m_zMove / 100);
    unary_matrix.init_matrix(4,4);
//    unary_matrix.print();
    unary_matrix.set_unary();
//    unary_matrix.print();
    unary_matrix.rotate_matrix(180.0f - (m_xRot / 16.0f), m_yRot / 16.0f, m_zRot / 16.0f);
//    unary_matrix.print();
    unary_matrix.resize_matrix(m_Multip);
//    unary_matrix.print();
    unary_matrix.move_matrix((float)m_xMove / 100, (float)m_yMove / 100, (float)m_zMove / 100);
//    unary_matrix.print();
    QMatrix4x4 m_test(unary_matrix.matrix[0][0],unary_matrix.matrix[0][1],unary_matrix.matrix[0][2],unary_matrix.matrix[0][3],
        unary_matrix.matrix[1][0],unary_matrix.matrix[1][1],unary_matrix.matrix[1][2],unary_matrix.matrix[1][3],
        unary_matrix.matrix[2][0],unary_matrix.matrix[2][1],unary_matrix.matrix[2][2],unary_matrix.matrix[2][3],
        unary_matrix.matrix[3][0],unary_matrix.matrix[3][1],unary_matrix.matrix[3][2],unary_matrix.matrix[3][3]);

//    std::cout << "Let's print QMatrix4x4" << std::endl;
//    QVector4D temp_move[4];
//    for (int i = 0; i < 4; i++) {
//        temp_move[i] = m_test.column(i);
//    }
//    for (int i = 0; i < 4; i++) {
//        for (int j = 0; j < 4; j++) {
//            std::cout << temp_move[j][i] << " ";
//        }
//        std::cout << std::endl;
//    }

    QOpenGLVertexArrayObject::Binder vaoBinder(&m_vao);

    project_matrix.init_matrix(4, 4);
    project_matrix.set_unary();
    if (m_perspect == 1) {
        project_matrix.project_matrix(45.0f, m_aspect, 0.01f, 100.0f);
    } else {
        project_matrix.project_matrix(0.0f, m_aspect, 0.01f, 100.0f);
    }
//    std::cout << "m_perspective = " << m_perspect << std::endl;
//    project_matrix.print();

    QMatrix4x4 m_test_proj(project_matrix.matrix[0][0],project_matrix.matrix[0][1],project_matrix.matrix[0][2],project_matrix.matrix[0][3],
        project_matrix.matrix[1][0],project_matrix.matrix[1][1],project_matrix.matrix[1][2],project_matrix.matrix[1][3],
        project_matrix.matrix[2][0],project_matrix.matrix[2][1],project_matrix.matrix[2][2],project_matrix.matrix[2][3],
        project_matrix.matrix[3][0],project_matrix.matrix[3][1],project_matrix.matrix[3][2],project_matrix.matrix[3][3]);

//    std::cout << "Let's print QMatrix4x4" << std::endl;
//    QVector4D temp_proj[4];
//    for (int i = 0; i < 4; i++) {
//        temp_proj[i] = m_test_proj.column(i);
//    }
//    for (int i = 0; i < 4; i++) {
//        for (int j = 0; j < 4; j++) {
//            std::cout << temp_proj[j][i] << " ";
//        }
//        std::cout << std::endl;
//    }

//    std::cout << "Let's print QMatrix4x4 from - master" << std::endl;
//    QVector4D temp_m_proj[4];
//    for (int i = 0; i < 4; i++) {
//        temp_m_proj[i] = m_proj.column(i);
//    }
//    for (int i = 0; i < 4; i++) {
//        for (int j = 0; j < 4; j++) {
//            std::cout << temp_m_proj[j][i] << " ";
//        }
//        std::cout << std::endl;
//    }

    m_program->bind();
//    m_program->setUniformValue(m_projMatrixLoc, m_proj);
    m_program->setUniformValue(m_projMatrixLoc, m_test_proj);
//    m_program->setUniformValue(m_mvMatrixLoc, m_camera * m_world);
    m_program->setUniformValue(m_mvMatrixLoc, m_camera * m_test);
    m_program->setUniformValue(m_PointSize, (GLfloat)m_VertexSize);
    QMatrix3x3 normalMatrix = m_world.normalMatrix();
//    QMatrix3x3 normalMatrix_test = m_test.normalMatrix();
    m_program->setUniformValue(m_normalMatrixLoc, normalMatrix);
//    m_program->setUniformValue(m_normalMatrixLoc, normalMatrix_test);
    m_program->setUniformValue(m_colorChange, QVector3D(m_RedColorLine, m_GreenColorLine, m_BlueColorLine));
    glDrawArrays(GL_LINES, 0, m_cube.linesAmount());
    if (m_VertexType == 1 || m_VertexType == 2) {
        m_program->setUniformValue(m_colorChange, QVector3D(m_RedColorVertex, m_GreenColorVertex, m_BlueColorVertex));
        glDrawArrays(GL_POINTS, m_cube.linesAmount(), m_cube.dotsAmount());
    }
    m_program->release();
}

void GLWidget::resizeGL(int w, int h)
{
    m_proj.setToIdentity();
    m_proj.perspective(45.0f, GLfloat(w) / h, 0.01f, 100.0f);
    m_aspect = GLfloat(w) / h;
//    project_matrix.init_matrix(4, 4);
//    project_matrix.set_unary();
//    if (m_perspect == 1) {
//        project_matrix.project_matrix(45.0f, m_aspect, 0.01f, 100.0f);
//    } else {
//        project_matrix.project_matrix(0.0f, m_aspect, 0.01f, 100.0f);
//    }
//    std::cout << "m_perspective = " << m_perspect << std::endl;
//    project_matrix.print();

}

void GLWidget::mousePressEvent(QMouseEvent *event)
{
    m_lastPos = event->pos();
}

void GLWidget::mouseMoveEvent(QMouseEvent *event)
{
    int dx = event->x() - m_lastPos.x();
    int dy = event->y() - m_lastPos.y();

    if (event->buttons() & Qt::LeftButton) {
        setXRotation(m_xRot + 8 * dy);
        setYRotation(m_yRot + 8 * dx);
    } else if (event->buttons() & Qt::RightButton) {
        setXRotation(m_xRot + 8 * dy);
        setZRotation(m_zRot + 8 * dx);
    }
    m_lastPos = event->pos();
}

void GLWidget::save_start_pos() {
    std::cout << "Let's save file - Let's write in it!!!" << std::endl;
    FILE *start_pos;
    start_pos = fopen("start_pos-v2.pos", "w");
    std::cout << "on save m_Multip - 1 = " << m_Multip - 1 << std::endl;
    fprintf(start_pos, "%.2lf %.2lf %.2lf %.2lf ", m_Multip - 1, m_RedColor, m_GreenColor, m_BlueColor);
    fprintf(start_pos, "%.2lf %.2lf %.2lf %.2lf %.2lf %.2lf ", m_RedColorLine, m_GreenColorLine, m_BlueColorLine, m_RedColorVertex, m_GreenColorVertex, m_BlueColorVertex);
    fprintf(start_pos, "%d %d %d %d %d %d ", m_xRot, m_yRot, m_zRot, m_xMove, m_yMove, m_zMove);
    fprintf(start_pos, "%d %d %d %d %d ", m_LineWidth,m_VertexSize, m_VertexType, m_perspect, m_lineType);
    fclose(start_pos);
}

void GLWidget::getSaveJpgFile(char *str_file_name) {
    std::cout << "You are in getSaveJpgFile function !!!" << std::endl;
    const time_t current_time = time(NULL);
       struct tm *current_year = NULL;
       char s1[40] = { 0 };
       current_year = localtime(&current_time);
       strftime(s1, 80, "%d.%m.%Y %H:%M:%S ", current_year);
    int lenth = strlen(str_file_name);
    char temp_str[255], final_temp_str[300];
    if (lenth == 0) {
        strncpy(temp_str, "temp_number", 12);
        temp_str[12] = '\0';
    } else {
        for (int i = 0; i < lenth -4; i++) {
            temp_str[i] = str_file_name[i];
        }
        temp_str[lenth - 4] = '\0';
    }
    sprintf(final_temp_str, "%s%c%s%s", temp_str, '-', s1, ".jpg");
    QString fileName = final_temp_str;
    std::cout << "We made file name = " << final_temp_str << std::endl;
    this->grab().save(fileName);
}

void GLWidget::getSaveBmpFile(char *str_file_name) {
    const time_t current_time = time(NULL);
       struct tm *current_year = NULL;
       char s1[40] = { 0 };
       current_year = localtime(&current_time);
       strftime(s1, 80, "%d.%m.%Y %H:%M:%S ", current_year);
    int lenth = strlen(str_file_name);
    char temp_str[255], final_temp_str[300];
    if (lenth == 0) {
        strncpy(temp_str, "temp_number", 12);
        temp_str[12] = '\0';
    } else {
        for (int i = 0; i < lenth -4; i++) {
            temp_str[i] = str_file_name[i];
        }
        temp_str[lenth - 4] = '\0';
    }
    sprintf(final_temp_str, "%s%c%s%s", temp_str, '-', s1, ".bmp");
    QString fileName = final_temp_str;
    this->grab().save(fileName);
}


