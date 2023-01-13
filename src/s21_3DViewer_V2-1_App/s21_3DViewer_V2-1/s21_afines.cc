

#include "s21_afines.h"
#include <iostream>

s21::Afines::Afines() {}

void s21::Afines::InitMatrix(int rows, int columns) {
  this->SetRows(rows);
  this->SetColumns(columns);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      this->matrix[i][j] = 0;
    }
  }
}

void s21::Afines::SetUnary() {
  if (this->RowsGiven() == this->CollumnsGiven()) {
    for (int i = 0; i < this->RowsGiven(); i++) {
      this->matrix[i][i] = 1;
    }
  }
}

void s21::Afines::MoveMatrix(double x_move, double y_move, double z_move) {
  S21Matrix temp = S21Matrix(4, 4);
  //    std::cout << "MoveMatrix Let's print this on start" << std::endl;
  //    this->print();
  for (int i = 0; i < temp.RowsGiven(); ++i) {
    temp.matrix[i][i] = 1;
  }
  temp.matrix[0][3] = x_move;
  temp.matrix[1][3] = y_move;
  temp.matrix[2][3] = z_move;
  //    std::cout << "Let's print temp" << std::endl;
  //    temp.print();
  this->MulMatrix((const S21Matrix)temp);
  //    std::cout << "Let's print this at the end" << std::endl;
  //    this->print();
}

void s21::Afines::RotateMatrix(double x_rot, double y_rot, double z_rot) {
  //    std::cout << "RotateMatrix - Let's print this on start" << std::endl;
  //    this->print();
  this->XRotateMatrix(x_rot);
  this->YRotateMatrix(y_rot);
  this->ZRotateMatrix(z_rot);
  //    std::cout << "at the end - Let's print this matrix" << std::endl;
  //    this->print();
}

void s21::Afines::XRotateMatrix(double x_rot) {
  S21Matrix temp = S21Matrix(4, 4);
  //    std::cout << "XRotateMatrix Let's print this on start" << std::endl;
  //    this->print();
  double alfa = (x_rot * S21_PI) / 180;
  temp.matrix[0][0] = 1;
  temp.matrix[1][1] = cos(alfa);
  temp.matrix[1][2] = sin(alfa);
  temp.matrix[2][2] = cos(alfa);
  temp.matrix[2][1] = -sin(alfa);
  temp.matrix[3][3] = 1;
  this->MulMatrix((const S21Matrix)temp);
  //    std::cout << "Let's print this at the end" << std::endl;
  //    this->print();
}

void s21::Afines::YRotateMatrix(double y_rot) {
  S21Matrix temp = S21Matrix(4, 4);
  //    std::cout << "YRotateMatrix Let's print this on start" << std::endl;
  //    this->print();
  double betta = (y_rot * S21_PI) / 180;
  temp.matrix[0][0] = cos(betta);
  temp.matrix[1][1] = 1;
  temp.matrix[0][2] = -1 * sin(betta);
  temp.matrix[2][2] = cos(betta);
  temp.matrix[2][0] = sin(betta);
  temp.matrix[3][3] = 1;
  this->MulMatrix((const S21Matrix)temp);
  //    std::cout << "Let's print this at the end" << std::endl;
  //    this->print();
}

void s21::Afines::ZRotateMatrix(double z_rot) {
  S21Matrix temp = S21Matrix(4, 4);
  //    std::cout << "ZRotateMatrix Let's print this on start" << std::endl;
  //    this->print();
  double gamma = (z_rot * S21_PI) / 180;
  temp.matrix[0][0] = cos(gamma);
  temp.matrix[1][1] = cos(gamma);
  temp.matrix[0][1] = sin(gamma);
  temp.matrix[2][2] = 1;
  temp.matrix[1][0] = -1 * sin(gamma);
  temp.matrix[3][3] = 1;
  this->MulMatrix((const S21Matrix)temp);
  //    std::cout << "Let's print this at the end" << std::endl;
  //    this->print();
}

void s21::Afines::ResizeMatrix(double coeff) {
  S21Matrix temp = S21Matrix(4, 4);
  //    std::cout << "ResizeMatrix Let's print this on start" << std::endl;
  //    this->print();
  for (int i = 0; i < temp.RowsGiven() - 1; ++i) {
    temp.matrix[i][i] = coeff;
  }
  temp.matrix[3][3] = 1;
  this->MulMatrix((const S21Matrix)temp);
  //    std::cout << "Let's print this at the end" << std::endl;
  //    this->print();
}

// 45.0f, GLfloat(w) / h, 0.01f, 100.0f

void s21::Afines::ProjectMatrix(double angle, double aspect, double near_point,
                                 double far_point) {
  S21Matrix temp = S21Matrix(4, 4);
  //    std::cout << "ProjectMatrix Let's print this on start" << std::endl;
  //    this->print();
  for (int i = 0; i < temp.RowsGiven(); ++i) {
    temp.matrix[i][i] = 1;
  }
  //    temp.matrix[0][0] = 2.0 / (sin(angle) * aspect);
  //    temp.matrix[1][1] = 2.0 / sin(angle);
  //    temp.matrix[2][2] = -1.0 * (far_point - near_point) / 100.0;
  //    temp.matrix[2][3] = -near_point * 2;
  //    temp.matrix[3][0] = 0;
  //    temp.matrix[3][1] = 0;
  //    temp.matrix[3][2] = - 1;
  //    temp.matrix[3][3] = 0;
  if (angle < 1.0) {
    temp.matrix[0][0] = 2.0 / aspect;
    temp.matrix[1][1] = 2.0;
    temp.matrix[2][2] = -1.0;
    temp.matrix[2][3] = -1.0;
    temp.matrix[3][3] = 1;
  } else {
    temp.matrix[0][0] = 2.0 / (sin(angle) * aspect);
    temp.matrix[1][1] = 2.0 / sin(angle);
    temp.matrix[2][2] = -1.0 * (far_point - near_point) / 100.0;
    temp.matrix[2][3] = -near_point * 2;
    temp.matrix[3][0] = 0;
    temp.matrix[3][1] = 0;
    temp.matrix[3][2] = -1;
    temp.matrix[3][3] = 0;
  }

  //    std::cout << "Let's print temp" << std::endl;
  //    temp.print();
  this->MulMatrix((const S21Matrix)temp);
  //    std::cout << "Let's print project_matrix at the end" << std::endl;
  //    this->print();
}

QMatrix4x4 s21::Afines::convertToQMatrix4x4() {
  QMatrix4x4 matrix4x4(
      this->matrix[0][0], this->matrix[0][1], this->matrix[0][2],
      this->matrix[0][3], this->matrix[1][0], this->matrix[1][1],
      this->matrix[1][2], this->matrix[1][3], this->matrix[2][0],
      this->matrix[2][1], this->matrix[2][2], this->matrix[2][3],
      this->matrix[3][0], this->matrix[3][1], this->matrix[3][2],
      this->matrix[3][3]);
  return matrix4x4;
}
