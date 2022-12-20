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

#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QOpenGLVertexArrayObject>
#include <QOpenGLBuffer>
#include <QMatrix4x4>
#include "model.h"
#include "afines.h"

QT_FORWARD_DECLARE_CLASS(QOpenGLShaderProgram)

class GLWidget : public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT

public:
    GLWidget(QWidget *parent = 0);
    ~GLWidget();

    static bool isTransparent() { return m_transparent; }
    static void setTransparent(bool t) { m_transparent = t; }

    QSize minimumSizeHint() const override;
    QSize sizeHint() const override;

public slots:
    void setXRotation(int angle);
    void setYRotation(int angle);
    void setZRotation(int angle);
    void setMultip(int multip);
    void setXMove(int x_move);
    void setYMove(int y_move);
    void setZMove(int z_move);
    void cleanup();
    void get_main_window_size_changed(const QSize &iconSize);
    void get_file_name(char str[]);
    void setRedColor(int RedColor);
    void setGreenColor(int GreenColor);
    void setBlueColor(int BlueColor);
    void setRedColorLine(int RedColorLine);
    void setGreenColorLine(int GreenColorLine);
    void setBlueColorLine(int BlueColorLine);
    void setRedColorVertex(int RedColorVertex);
    void setGreenColorVertex(int GreenColorVertex);
    void setBlueColorVertex(int BlueColorVertex);
    void setLineWidth(int LineWidth);
    void setVertexSize(int VertexSize);
    void setVertexType(int VertexType);
    void setPerspectiveStatus(int PerspectiveStatus);
    void setDashLineSignal(int signal);
    void getSaveJpgFile(char str[]);
    void getSaveBmpFile(char str[]);
    void getSaveGifFileSignal(char str[]);

signals:
    void xRotationChanged(int angle);
    void yRotationChanged(int angle);
    void zRotationChanged(int angle);
    void xMoveChanged(int x_move);
    void yMoveChanged(int y_move);
    void zMoveChanged(int z_move);
    void multipChanged(int multip);
    void send_vertexes_amount(int);
    void send_facets_amount(int);
    void RedColorChanged(int RedColor);
    void GreenColorChanged(int GreenColor);
    void BlueColorChanged(int BlueColor);
    void RedColorLineChanged(int RedColorLine);
    void GreenColorLineChanged(int GreenColorLine);
    void BlueColorLineChanged(int BlueColorLine);
    void RedColorVertexChanged(int RedColorVertex);
    void GreenColorVertexChanged(int GreenColorVertex);
    void BlueColorVertexChanged(int BlueColorVertex);
    void LineWidthChanged(int LineWidth);
    void VertexSizeChanged(int VertexSize);
    void VertexTypeChanged(int VertexType);
    void PersectiveChanged(int PerspectiveStatus);
    void DashLineChanged(int DashLine);

protected:
    void initializeGL() override;
    void paintGL() override;
    void resizeGL(int width, int height) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void wheelEvent(QWheelEvent *event) override;
    void checkForSpecs();

private:
    void setupVertexAttribs();

    bool m_core;
    int m_xRot;
    int m_yRot;
    int m_zRot;
    int m_xMove;
    int m_yMove;
    int m_zMove;
    float m_Multip;
    float m_RedColor;
    float m_GreenColor;
    float m_BlueColor;
    float m_RedColorLine;
    float m_GreenColorLine;
    float m_BlueColorLine;
    float m_RedColorVertex;
    float m_GreenColorVertex;
    float m_BlueColorVertex;
    int m_LineWidth;
    int m_VertexSize;
    int m_VertexType;
    int m_perspect;
    int m_lineType;
    GLfloat m_aspect;
    QPoint m_lastPos;
    Model m_model;
    QOpenGLVertexArrayObject m_vao;
    QOpenGLBuffer m_modelVbo;
    QOpenGLShaderProgram *m_program;
    int m_projMatrixLoc;
    int m_mvMatrixLoc;
    int m_normalMatrixLoc;
    int m_lightPosLoc;
    int m_colorChange;
    int m_PointSize;
    QMatrix4x4 m_camera;
    afines unary_matrix;
    afines project_matrix;
    static bool m_transparent;
    int gifCounter;
    char *gifFileName;
    void save_start_pos(void);
    void getSaveGifFile(char str[]);
};

#endif
