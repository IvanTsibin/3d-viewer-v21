#ifndef S21_GLWIDGET_H
#define S21_GLWIDGET_H

#include "s21_afines.h"
#include "s21_model.h"
#include <QMatrix4x4>
#include <QOpenGLBuffer>
#include <QOpenGLFunctions>
#include <QOpenGLVertexArrayObject>
#include <QOpenGLWidget>

QT_FORWARD_DECLARE_CLASS(QOpenGLShaderProgram)

typedef struct Settings {
  bool facets_on;
  int xRot;
  int yRot;
  int zRot;
  int xMove;
  int yMove;
  int zMove;
  float Multip;
  int xLight;
  int yLight;
  float RedColor;
  float GreenColor;
  float BlueColor;
  float RedColorLine;
  float GreenColorLine;
  float BlueColorLine;
  float RedColorVertex;
  float GreenColorVertex;
  float BlueColorVertex;
  float RedColorFacets;
  float GreenColorFacets;
  float BlueColorFacets;
  float RedColorLight;
  float GreenColorLight;
  float BlueColorLight;
  int LineWidth;
  int VertexSize;
  int VertexType;
  int perspect;
  int facets;
  int lineType;
  int NormalGuro;
  GLfloat aspect;
} Settings_t;

class GLWidget : public QOpenGLWidget, protected QOpenGLFunctions {
  Q_OBJECT

public:
  GLWidget(QWidget *parent = 0);
  ~GLWidget();

  static bool isTransparent() { return m_transparent_; }
  static void setTransparent(bool t) { m_transparent_ = t; }

  QSize minimumSizeHint() const override;
  QSize sizeHint() const override;

public slots:
  void Cleanup();
  void GetMainWindowSizeChanged(const QSize &iconSize);
  void GetFileName(char str[]);
  void getSettingsFromController(Settings_t *);

signals:
  void SendVertexesAmount(int);
  void SendFacetsAmount(int);
  void sendSettingsToController(Settings_t *);
  void SaveStartPos();

protected:
  void initializeGL() override;
  void paintGL() override;
  void resizeGL(int width, int height) override;
  void mousePressEvent(QMouseEvent *event) override;
  void mouseMoveEvent(QMouseEvent *event) override;
  void wheelEvent(QWheelEvent *event) override;
  void CheckForSpecs();

private:
  void SetupVertexAttribs();
  void AddDataToModelVBO();

  Settings_t *set_;
  GLfloat m_aspect_;
  bool m_core_;
  QPoint m_last_pos_;
  s21::Model m_model_;
  QOpenGLVertexArrayObject m_vao;
  QOpenGLBuffer m_model_vbo_;
  QOpenGLShaderProgram *m_program_;
  int m_proj_matrix_loc_;
  int m_mv_matrix_loc_;
  int m_normal_matrix_loc_;
  int m_light_pos_loc_;
  int m_color_flag_;
  int m_color_line_;
  int m_color_vertex_;
  int m_color_light_;
  int m_color_facets_;
  int m_point_size_;
  int m_normal_guro_;
  QMatrix4x4 m_camera_;
  s21::Afines unary_matrix_;
  s21::Afines project_matrix_;
  static bool m_transparent_;
};

#endif // S21_GLWIDGET_H
