#ifndef S21_SAVEGIF_H
#define S21_SAVEGIF_H

#include "s21_glwidget.h"
#include <QObject>
#include <cstdio>
#include <iostream>

class SaveGif : public QObject {
  Q_OBJECT
public:
  SaveGif();

  void ConnectWidget(GLWidget *widget) {
    controled_widget_ = widget;
    //         std::cout << "Hello, You are in Savegif class
    //         connectWidget(GLWidget *widget)  controled_widget_ = " <<
    //         controled_widget_ << std::endl;
  }

public slots:
  void GetSaveGifFile(char str[], int gifCounter, float aspect);

private:
  GLWidget *controled_widget_;
  char gifFileName_[255];
  float aspect_;
  void CollectAllForGif(char str[]);
};

#endif // S21_SAVEGIF_H
