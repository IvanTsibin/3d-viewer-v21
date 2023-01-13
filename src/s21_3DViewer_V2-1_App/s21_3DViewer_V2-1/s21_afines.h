#ifndef S21_AFINES_H
#define S21_AFINES_H

#include "s21_matrix_oop.h"
#include <QMatrix4x4>
#include <cmath>

#define S21_PI 3.1415926535

namespace s21 {

class Afines : public S21Matrix {
public:
  Afines();
  void InitMatrix(int, int);
  void SetUnary();
  void MoveMatrix(double, double, double);
  void RotateMatrix(double, double, double);
  void XRotateMatrix(double);
  void YRotateMatrix(double);
  void ZRotateMatrix(double);
  void ResizeMatrix(double);
  void ProjectMatrix(double, double, double, double);
  QMatrix4x4 convertToQMatrix4x4();
};
} // namespace s21

#endif // S21_AFINES_H
