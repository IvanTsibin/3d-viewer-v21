#include "gif.h"
#include "glwidget.h"
#include <QCoreApplication>
#include <QMouseEvent>
#include <QOpenGLShaderProgram>
#include <QVector3D>
#include <iostream>
#include <math.h>

GifWriter gifWriter;

static void qNormalizeAngle(int &angle) {
  while (angle < 0)
    angle += 360 * 16;
  while (angle > 360 * 16)
    angle -= 360 * 16;
}

void GLWidget::setXRotation(int angle) {
  qNormalizeAngle(angle);
  if (angle != m_xRot) {
    m_xRot = angle;
    emit xRotationChanged(angle);
    if (gifCounter > 0)
      getSaveGifFile(gifFileName);
    update();
  }
}

void GLWidget::setYRotation(int angle) {
  qNormalizeAngle(angle);
  if (angle != m_yRot) {
    m_yRot = angle;
    emit yRotationChanged(angle);
    if (gifCounter > 0)
      getSaveGifFile(gifFileName);
    update();
  }
}

void GLWidget::setZRotation(int angle) {
  qNormalizeAngle(angle);
  if (angle != m_zRot) {
    m_zRot = angle;
    emit zRotationChanged(angle);
    if (gifCounter > 0)
      getSaveGifFile(gifFileName);
    update();
  }
}

void GLWidget::setMultip(int multip) {
  m_Multip = 1.0 + ((float)multip) / 100;
  emit multipChanged(multip);
  if (gifCounter > 0)
    getSaveGifFile(gifFileName);
  update();
}

void GLWidget::setXMove(int x_move) {
  if (x_move != m_xMove) {
    m_xMove = x_move;
    emit xMoveChanged(x_move);
    if (gifCounter > 0)
      getSaveGifFile(gifFileName);
    update();
  }
}

void GLWidget::setYMove(int y_move) {
  if (y_move != m_yMove) {
    m_yMove = y_move;
    emit yMoveChanged(y_move);
    if (gifCounter > 0)
      getSaveGifFile(gifFileName);
    update();
  }
}

void GLWidget::setZMove(int z_move) {
  if (z_move != m_zMove) {
    m_zMove = z_move;
    emit zMoveChanged(z_move);
    if (gifCounter > 0)
      getSaveGifFile(gifFileName);
    update();
  }
}

void GLWidget::cleanup() {
  if (m_program == nullptr)
    return;
  makeCurrent();
  m_modelVbo.destroy();
  delete m_program;
  m_program = 0;
  doneCurrent();
}

void GLWidget::get_main_window_size_changed(const QSize &iconSize) {
  if (iconSize.width() > 100) {
    resizeGL(iconSize.width(), iconSize.height());
    if (gifCounter > 0)
      getSaveGifFile(gifFileName);
    update();
  }
}

void GLWidget::get_file_name(char *str) {
  char str_file_name[255];
  int lenth = strlen(str);
  for (int i = 0; i < 255; i++)
    str_file_name[i] = '\0';
  for (int i = 0; i < lenth; i++) {
    str_file_name[i] = str[i];
  }
  str_file_name[lenth] = '\0';
  if (strlen(str) != 0) {
    m_model.reLoadData(str_file_name);
    emit send_facets_amount(m_model.facetsAmount());
    emit send_vertexes_amount(m_model.vertexsAmount());
    m_modelVbo.bind();
    m_modelVbo.allocate((m_model.count() + m_model.dotsCount()) *
                        sizeof(GLfloat));
    m_modelVbo.write(0, m_model.constData(), m_model.count() * sizeof(GLfloat));
    m_modelVbo.write(m_model.count() * sizeof(GLfloat), m_model.constDotData(),
                     m_model.dotsCount() * sizeof(GLfloat));
  }
  update();
}

void GLWidget::setRedColor(int RedColor) {
  m_RedColor = (float)RedColor / 255.0;
  emit RedColorChanged(RedColor);
  if (gifCounter > 0)
    getSaveGifFile(gifFileName);
  update();
}
void GLWidget::setGreenColor(int GreenColor) {
  m_GreenColor = (float)GreenColor / 255.0;
  emit GreenColorChanged(GreenColor);
  if (gifCounter > 0)
    getSaveGifFile(gifFileName);
  update();
}
void GLWidget::setBlueColor(int BlueColor) {
  m_BlueColor = (float)BlueColor / 255.0;
  emit BlueColorChanged(BlueColor);
  if (gifCounter > 0)
    getSaveGifFile(gifFileName);
  update();
}

void GLWidget::setRedColorLine(int RedColorLine) {
  m_RedColorLine = (float)RedColorLine / 255.0;
  emit RedColorLineChanged(RedColorLine);
  if (gifCounter > 0)
    getSaveGifFile(gifFileName);
  update();
}
void GLWidget::setGreenColorLine(int GreenColorLine) {
  m_GreenColorLine = (float)GreenColorLine / 255.0;
  emit GreenColorLineChanged(GreenColorLine);
  if (gifCounter > 0)
    getSaveGifFile(gifFileName);
  update();
}
void GLWidget::setBlueColorLine(int BlueColorLine) {
  m_BlueColorLine = (float)BlueColorLine / 255.0;
  emit BlueColorLineChanged(BlueColorLine);
  if (gifCounter > 0)
    getSaveGifFile(gifFileName);
  update();
}

void GLWidget::setRedColorVertex(int RedColorVertex) {
  m_RedColorVertex = (float)RedColorVertex / 255.0;
  emit RedColorVertexChanged(RedColorVertex);
  if (gifCounter > 0)
    getSaveGifFile(gifFileName);
  update();
}
void GLWidget::setGreenColorVertex(int GreenColorVertex) {
  m_GreenColorVertex = (float)GreenColorVertex / 255.0;
  emit GreenColorVertexChanged(GreenColorVertex);
  if (gifCounter > 0)
    getSaveGifFile(gifFileName);
  update();
}
void GLWidget::setBlueColorVertex(int BlueColorVertex) {
  m_BlueColorVertex = (float)BlueColorVertex / 255.0;
  emit BlueColorVertexChanged(BlueColorVertex);
  if (gifCounter > 0)
    getSaveGifFile(gifFileName);
  update();
}

void GLWidget::setLineWidth(int LineWidth) {
  m_LineWidth = LineWidth;
  emit LineWidthChanged(LineWidth);
  if (gifCounter > 0)
    getSaveGifFile(gifFileName);
  update();
}

void GLWidget::setVertexSize(int VertexSize) {
  m_VertexSize = VertexSize;
  emit VertexSizeChanged(VertexSize);
  if (gifCounter > 0)
    getSaveGifFile(gifFileName);
  update();
}

void GLWidget::setVertexType(int VertexType) {
  m_VertexType = VertexType;
  emit VertexTypeChanged(VertexType);
  if (gifCounter > 0)
    getSaveGifFile(gifFileName);
  update();
}

void GLWidget::setPerspectiveStatus(int PerspectiveStatus) {
  m_perspect = PerspectiveStatus;
  emit PersectiveChanged(PerspectiveStatus);
  if (gifCounter > 0)
    getSaveGifFile(gifFileName);
  update();
}

void GLWidget::setDashLineSignal(int signal) {
  if (signal == 1) {
    m_lineType = 1;
  } else {
    m_lineType = 0;
  }
  emit DashLineChanged(signal);
  if (gifCounter > 0)
    getSaveGifFile(gifFileName);
  update();
}

void GLWidget::mousePressEvent(QMouseEvent *event) { m_lastPos = event->pos(); }

void GLWidget::mouseMoveEvent(QMouseEvent *event) {
#ifdef __APPLE__
  int dx = event->position().x() - m_lastPos.x();
  int dy = event->position().y() - m_lastPos.y();
#else
  int dx = event->x() - m_lastPos.x();
  int dy = event->y() - m_lastPos.y();
#endif

  if (event->buttons() & Qt::LeftButton) {
    setXRotation(m_xRot + 8 * dy);
    setYRotation(m_yRot + 8 * dx);
  } else if (event->buttons() & Qt::RightButton) {
    setXRotation(m_xRot + 8 * dy);
    setZRotation(m_zRot + 8 * dx);
  }
  m_lastPos = event->pos();
}

void GLWidget::wheelEvent(QWheelEvent *event) {
#ifdef __APPLE__
  if ((event->angleDelta().y()) > 0 && m_Multip < 10.0) {
    m_Multip += 0.05;
  } else if ((event->angleDelta().y()) < 0 && m_Multip > 0.05) {
    m_Multip -= 0.05;
  }
#else
  if ((event->delta()) > 0 && m_Multip < 10.0) {
    m_Multip += 0.05;
  } else if ((event->delta()) < 0 && m_Multip > 0.05) {
    m_Multip -= 0.05;
  }
#endif

  int temp = (int)round(((m_Multip - 1.0) * 100));
  setMultip(temp);
  if (gifCounter > 0)
    getSaveGifFile(gifFileName);
}

void GLWidget::save_start_pos() {
  FILE *start_pos;
  start_pos = fopen("start_pos-v2.pos", "w");
  fprintf(start_pos, "%.2lf %.2lf %.2lf %.2lf ", m_Multip - 1, m_RedColor,
          m_GreenColor, m_BlueColor);
  fprintf(start_pos, "%.2lf %.2lf %.2lf %.2lf %.2lf %.2lf ", m_RedColorLine,
          m_GreenColorLine, m_BlueColorLine, m_RedColorVertex,
          m_GreenColorVertex, m_BlueColorVertex);
  fprintf(start_pos, "%d %d %d %d %d %d ", m_xRot, m_yRot, m_zRot, m_xMove,
          m_yMove, m_zMove);
  fprintf(start_pos, "%d %d %d %d %d ", m_LineWidth, m_VertexSize, m_VertexType,
          m_perspect, m_lineType);
  fclose(start_pos);
}

void GLWidget::getSaveJpgFile(char *str_file_name) {
  const time_t current_time = time(NULL);
  struct tm *current_year = NULL;
  char s1[40] = {0};
  current_year = localtime(&current_time);
  strftime(s1, 80, "%d-%m-%Y--%H-%M-%S", current_year);
  int lenth = strlen(str_file_name);
  char temp_str[255], final_temp_str[300];
  if (lenth == 0) {
    strncpy(temp_str, "temp_number", 12);
    temp_str[12] = '\0';
  } else {
    for (int i = 0; i < lenth - 4; i++) {
      temp_str[i] = str_file_name[i];
    }
    temp_str[lenth - 4] = '\0';
  }
  sprintf(final_temp_str, "%s%c%s%s", temp_str, '-', s1, ".jpg");
  QString fileName = final_temp_str;
  this->grab().save(fileName);
}

void GLWidget::getSaveBmpFile(char *str_file_name) {
  const time_t current_time = time(NULL);
  struct tm *current_year = NULL;
  char s1[40] = {0};
  current_year = localtime(&current_time);
  strftime(s1, 80, "%d-%m-%Y--%H-%M-%S", current_year);
  int lenth = strlen(str_file_name);
  char temp_str[255], final_temp_str[300];
  if (lenth == 0) {
    strncpy(temp_str, "temp_number", 12);
    temp_str[12] = '\0';
  } else {
    for (int i = 0; i < lenth - 4; i++) {
      temp_str[i] = str_file_name[i];
    }
    temp_str[lenth - 4] = '\0';
  }
  sprintf(final_temp_str, "%s%c%s%s", temp_str, '-', s1, ".bmp");
  QString fileName = final_temp_str;
  this->grab().save(fileName);
}

void GLWidget::getSaveGifFileSignal(char str[]) {
  gifCounter = 0;
  getSaveGifFile(str);
}

void GLWidget::getSaveGifFile(char *str_file_name) {
  if (gifCounter == 0) {
    if (gifFileName != nullptr) delete[] gifFileName;
    gifFileName = new char[strlen(str_file_name + 1)];
    sprintf(gifFileName, "%s", str_file_name);
    gifFileName[strlen(str_file_name)] = '\0';
  }
  int lenth = strlen(gifFileName);
  char temp_str[255], final_temp_str[275], gif_temp_str[299];
  if (lenth == 0) {
    strncpy(temp_str, "temp_number", 12);
    temp_str[12] = '\0';
  } else {
    for (int i = 0; i < lenth - 4; i++) {
      temp_str[i] = gifFileName[i];
    }
    temp_str[lenth - 4] = '\0';
  }
  temp_str[lenth - 4] = '\0';
  sprintf(final_temp_str, "%s%s", temp_str, "-temp.png");
  const time_t current_time = time(NULL);
  struct tm *current_year = NULL;
  char s1[40] = {0};
  current_year = localtime(&current_time);
  strftime(s1, 80, "%d-%m-%Y--%H-%M-%S", current_year);

  sprintf(gif_temp_str, "%s-%s%s", temp_str, s1, ".gif");
  QString fileName = final_temp_str;
  this->grab().save(fileName);
  QImage image_1;
  image_1.load(fileName);
  QImage image = image_1.scaled((int)480 * m_aspect, 480);
  int frame_delay = 20;
  if (gifCounter == 0) {
    GifBegin(&gifWriter, gif_temp_str, image.width(), image.height(), 100);
    GifWriteFrame(&gifWriter,
                  image.convertToFormat(QImage::Format_RGBA8888)
                      .convertToFormat(QImage::Format_RGBA8888)
                      .constBits(),
                  static_cast<uint32_t>(image.width()),
                  static_cast<uint32_t>(image.height()),
                  static_cast<uint32_t>(frame_delay));
    gifCounter = 1;
  }
  if (gifCounter > 0 && gifCounter < 51) {
    GifWriteFrame(&gifWriter,
                  image.convertToFormat(QImage::Format_RGBA8888)
                      .convertToFormat(QImage::Format_RGBA8888)
                      .constBits(),
                  static_cast<uint32_t>(image.width()),
                  static_cast<uint32_t>(image.height()),
                  static_cast<uint32_t>(frame_delay));
    gifCounter += 1;
  } else if (gifCounter == 51) {
    GifWriteFrame(&gifWriter,
                  image.convertToFormat(QImage::Format_RGBA8888)
                      .convertToFormat(QImage::Format_RGBA8888)
                      .constBits(),
                  static_cast<uint32_t>(image.width()),
                  static_cast<uint32_t>(image.height()),
                  static_cast<uint32_t>(frame_delay));
    GifEnd(&gifWriter);
    gifCounter = -1;
  }
}
