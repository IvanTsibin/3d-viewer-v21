#include "s21_glwidget.h"
#include <QCoreApplication>
#include <QMouseEvent>
#include <QOpenGLShaderProgram>
#include <QVector3D>
#include <iostream>
#include <math.h>

void GLWidget::Cleanup() {
  if (m_program_ == nullptr)
    return;
  makeCurrent();
  m_model_vbo_.destroy();
  delete m_program_;
  m_program_ = 0;
  doneCurrent();
}

void GLWidget::GetMainWindowSizeChanged(const QSize &iconSize) {
  if (iconSize.width() > 100) {
    resizeGL(iconSize.width(), iconSize.height());
    update();
  }
}

void GLWidget::GetFileName(char *str) {
  //    std::cout << "Hello, you are in GLWidget::GetFileName(char *str)" <<
  //    std::endl;
  if (strlen(str) != 0) {
    m_model_.ReLoadData(str);
    emit SendFacetsAmount(m_model_.FacetsAmount());
    emit SendVertexesAmount(m_model_.VertexsAmount());
    AddDataToModelVBO();
  }
  update();
  //    std::cout << "GetFileName Step - 2" << std::endl;
}

void GLWidget::mousePressEvent(QMouseEvent *event) { m_last_pos_ = event->pos(); }

void GLWidget::mouseMoveEvent(QMouseEvent *event) {
  int dx = event->x() - m_last_pos_.x();
  int dy = event->y() - m_last_pos_.y();

  if (event->buttons() & Qt::LeftButton) {
    set_->xRot += 8 * dy;
    set_->yRot += 8 * dx;
  } else if (event->buttons() & Qt::RightButton) {
    set_->xRot += 8 * dy;
    set_->zRot += 8 * dx;
  }
  emit sendSettingsToController(set_);
  m_last_pos_ = event->pos();
}

void GLWidget::wheelEvent(QWheelEvent *event) {
  if ((event->delta()) > 0 && set_->Multip < 10.0) {
    set_->Multip += 0.05;
  } else if ((event->delta()) < 0 && set_->Multip > 0.05) {
    set_->Multip -= 0.05;
  }
  emit sendSettingsToController(set_);
}

void GLWidget::getSettingsFromController(Settings_t *set) {
  //    std::cout << "Hello, You are in
  //    GLWidget::getSettingsFromController(Settings_t * set)" << std::endl;
      set_ = set;
  update();
}
