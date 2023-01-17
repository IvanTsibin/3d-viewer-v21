#ifndef S21_SAVEPICTURES_H
#define S21_SAVEPICTURES_H

#include "s21_glwidget.h"
#include "s21_savegif.h"
#include "s21_savejpgbmp.h"
#include <QObject>
#include <cstdio>
#include <iostream>

class SavePictures : public QObject {
  Q_OBJECT
public:
  SavePictures();

  void connectWidget(GLWidget *widget) {
    controled_widget_ = widget;
    //            std::cout << "Hello, You are in Savepictures class
    //            connectWidget(GLWidget *widget)  controled_widget_ = " <<
    //            controled_widget_ << std::endl;
  }

public slots:
  void GetSavePictureSignal(char str[], int type, float aspect, int gifCounter);

private:
  GLWidget *controled_widget_;
  char gifFileName_[255];
  float aspect_;
  SaveJpgBmp *MySaveJpgBmp_;
  SaveGif *MySaveGif_;
signals:
  void SaveJpgBmpFile(char str[], int type);
  void SaveGifFile(char str[], int gifCounter, float aspect);
};

#endif // S21_SAVEPICTURES_H
