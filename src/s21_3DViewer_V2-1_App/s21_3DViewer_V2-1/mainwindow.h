#ifndef S21_MAINWINDOW_H
#define S21_MAINWINDOW_H


#include <QFileDialog>
#include <QMainWindow>
#include <QWidget>
#include <cmath>
#include <iostream>
#include <clocale>
#include "s21_controller.h"
#include "s21_glwidget.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

private slots:
  void on_MainWindow_iconSizeChanged(const QSize &iconSize);
  void on_InputObject_2_clicked();
  void on_PBDraw_2_clicked();
  void on_SBRedColor_valueChanged(int arg1);
  void on_SBGreenColor_valueChanged(int arg1);
  void on_SBBlueColor_valueChanged(int arg1);
  void on_SBRedColorLine_valueChanged(int arg1);
  void on_SBGreenColorLine_valueChanged(int arg1);
  void on_SBBlueColorLine_valueChanged(int arg1);
  void on_SBRedColorVertex_valueChanged(int arg1);
  void on_SBGreenColorVertex_valueChanged(int arg1);
  void on_SBBlueColorVertex_valueChanged(int arg1);
  void on_SBLineWidth_valueChanged(int arg1);
  void on_SBVertexSize_valueChanged(int arg1);
  void on_CBVertexType_currentTextChanged(const QString &arg1);
  void on_CBPerspective_toggled(bool checked);
  void on_CBFacets_toggled(bool checked);
  void on_CBDashLine_toggled(bool checked);
  void on_PBToZero_clicked();
  void on_PBJpgPhoto_clicked();
  void on_PBBmpPhoto_clicked();
  void on_PBGifMovie_clicked();
  void on_xSlider_valueChanged(int value);
  void on_ySlider_valueChanged(int value);
  void on_zSlider_valueChanged(int value);
  void on_MultipSlider_valueChanged(int value);
  void on_xMoveSlider_valueChanged(int value);
  void on_yMoveSlider_valueChanged(int value);
  void on_zMoveSlider_valueChanged(int value);
  void on_SBxRot_valueChanged(int arg1);
  void on_SByRot_valueChanged(int arg1);
  void on_SBzRot_valueChanged(int arg1);
  void on_DSBMultip_valueChanged(double arg1);
  void on_DSBxMove_valueChanged(double arg1);
  void on_DSByMove_valueChanged(double arg1);
  void on_DSBzMove_valueChanged(double arg1);
  void on_xLightSlider_valueChanged(int value);
  void on_yLightSlider_valueChanged(int value);
  void on_DSBxLight_valueChanged(double arg1);
  void on_DSByLight_valueChanged(double arg1);
  void on_PByRotGif_clicked();
  void on_CBNormalGuro_toggled(bool checked);
  void on_SBRedFacets_valueChanged(int arg1);
  void on_SBGreenFacets_valueChanged(int arg1);
  void on_SBRedLight_valueChanged(int arg1);
  void on_SBGreenLight_valueChanged(int arg1);
  void on_SBBlueLight_valueChanged(int arg1);
  void on_SBBlueFacets_valueChanged(int arg1);

private:
  Ui::MainWindow *ui;
  GLWidget *MyGLWidget;
  void ReadStartPos(void);
  void ApplySettingsToMainWindow(void);
  void ConnectControllerToMainWidget(void);
  //    void updateSettings(settings_t *set);
  Controller *MyController_;
  Settings_t MWSet_;

public slots:
  void GetVertexesAmount(int amount);
  void GetFacetsAmount(int amount);
  void SavePictureViaType(int type);
  void GetSettingsFromController(Settings_t *set_);

signals:
  void SendMainWindowSizeChanged(const QSize);
  void SendFileName(char *);
  void SendRedColor(int);
  void SendGreenColor(int);
  void SendBlueColor(int);
  void SendRedColorLine(int);
  void SendGreenColorLine(int);
  void SendBlueColorLine(int);
  void SendRedColorVertex(int);
  void SendGreenColorVertex(int);
  void SendBlueColorVertex(int);

  void SendRedColorFacets(int);
  void SendGreenColorFacets(int);
  void SendBlueColorFacets(int);

  void SendRedColorLight(int);
  void SendGreenColorLight(int);
  void SendBlueColorLight(int);

  void SendLineWidth(int);
  void SendVertexSize(int);
  void SendVertexType(int);
  void SendPerspectStatus(int);
  void SendFacetsStatus(int);
  void SendDashLineSignal(int);
  void SendSavePictureSignal(char *, int);
  void SendNormalGuroSignal(int);
  void SendRequestForSettings(void);
  void SendRequestForSavedSettings(void);
  void SendSaveSettingsSignal(void);
};

#endif // S21_MAINWINDOW_H
