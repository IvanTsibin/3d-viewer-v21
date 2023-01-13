#ifndef S21_SAVEJPGBMP_H
#define S21_SAVEJPGBMP_H

#include "s21_glwidget.h"
#include <QObject>
#include <cstdio>
#include <iostream>

class SaveJpgBmp : public QObject {
  Q_OBJECT
public:
  SaveJpgBmp();

  void ConnectWidget(GLWidget *widget) {
    controled_widget_ = widget;
    //         std::cout << "Hello, You are in Savejpgbmp class
    //         connectWidget(GLWidget *widget)  controled_widget_ = " <<
    //         controled_widget_ << std::endl;
  }

public slots:
  void GetSaveJpgBmpFile(char str[], int type);

private:
  GLWidget *controled_widget_;
};

#endif // S21_SAVEJPGBMP_H
