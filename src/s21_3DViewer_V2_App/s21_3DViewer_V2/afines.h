#ifndef AFINES_H
#define AFINES_H

#include "s21_matrix_oop.h"
#include <QMatrix4x4>
#include <cmath>

#define S21_PI 3.1415926535

class afines : public S21Matrix {
public:
  afines();
  void init_matrix(int, int);
  void set_unary();
  void move_matrix(double, double, double);
  void rotate_matrix(double, double, double);
  void x_rotate_matrix(double);
  void y_rotate_matrix(double);
  void z_rotate_matrix(double);
  void resize_matrix(double);
  void project_matrix(double, double, double, double);
  QMatrix4x4 convertToQMatrix4x4();
};

#endif // AFINES_H
