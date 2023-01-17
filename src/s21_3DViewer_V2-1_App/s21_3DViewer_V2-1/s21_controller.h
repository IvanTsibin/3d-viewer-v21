#ifndef S21_CONTROLLER_H
#define S21_CONTROLLER_H

#include "s21_glwidget.h"
#include "s21_savepictures.h"
#include <QObject>
#include <QTimer>
#include <iostream>
#include <QColorDialog>
#include <QDebug>
#include <QPalette>

class Controller : public QObject {
  Q_OBJECT
public:
  Controller();
  ~Controller();

  void connectWidget(GLWidget *widget) {
    //            std::cout << "Hello, You are in connectWidget(GLWidget
    //            *widget)" << std::endl;
    controled_widget_ = widget;
  }

public slots:
  void SettingsFromGLWidgetToController(Settings_t *);
  void GetFacetsStatus(bool checked);
  void SetXRotation(int angle);
  void SetYRotation(int angle);
  void SetZRotation(int angle);
  void SetMultip(int multip);
  void SetXMove(int x_move);
  void SetYMove(int y_move);
  void SetZMove(int z_move);
  void SetXLight(int x_light);
  void SetYLight(int y_light);
  void SetSceneColor(QColor SceneColor);
  void SetLineColor(QColor LineColor);
  void SetVertexColor(QColor VertexColor);
  void SetFacetsColor(QColor FacetsColor);
  void SetLightColor(QColor LightColor);

  void SetLineWidth(int LineWidth);
  void SetVertexSize(int VertexSize);
  void SetVertexType(int VertexType);
  void SetPerspectiveStatus(int PerspectiveStatus);
  void SetFacetsStatus(int FacetsStatus);
  void SetDashLineSignal(int signal);
  void SaveStartPos(void);
  void GetSavePictureSignal(char str[], int type);
  void GetSaveYRotGifSignal(void);
  void GetNormalGuroSignal(int signal);
  void RequestFromMainWindowForSettings(void);
  void ReadStartPos(void);

signals:
  void SendSettingsToGLWidget(Settings_t *);
  void XRotationChanged(int angle);
  void YRotationChanged(int angle);
  void ZRotationChanged(int angle);
  void MultipChanged(int multip);
  void SendSavePictureSignal(char str[], int type, float aspect,
                             int gifCounter);
  void SendSettingsToMainWindow(Settings_t *);
  void SendLablesColorChangeSignal(void);

private:
  Settings_t set_for_controller_, start_set_;
  int gifCounter_;
  char *pictureFileName_;
  int type_;
  float aspect_;
  int yRotCounter_;
  GLWidget *controled_widget_;
  SavePictures *MySavePicture_;
  QTimer *timer_;
  void EmitSettings();
  void StepsForGifPicture();
};

#endif // S21_CONTROLLER_H
