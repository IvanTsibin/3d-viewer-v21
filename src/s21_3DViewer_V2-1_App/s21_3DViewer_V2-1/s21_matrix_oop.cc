#include "s21_matrix_oop.h"
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <stdexcept>

s21::S21Matrix::S21Matrix() : rows_(0), columns_(0), matrix(nullptr) {}

void s21::S21Matrix::FreeMemory() {
  if (matrix != nullptr) {
    for (int i = 0; i < rows_; i++) {
      delete[] matrix[i];
    }
    delete[] matrix;
  }
}

void s21::S21Matrix::GetMemory() {
  matrix = new double *[rows_];
  for (int i = 0; i < rows_; i++) {
    matrix[i] = new double[columns_];
    for (int j = 0; j < columns_; j++) {
      matrix[i][j] = 0.0;
    }
  }
}

s21::S21Matrix::~S21Matrix() { FreeMemory(); }

s21::S21Matrix::S21Matrix(int rows, int cols)
    : rows_(rows), columns_(cols), matrix(nullptr) {
  if (cols < 0) {
    throw std::invalid_argument("number of columns should be >= 0");
  } else if (rows < 0) {
    throw std::invalid_argument("number of rows should be >= 0");
  }
  GetMemory();
}

s21::S21Matrix::S21Matrix(const S21Matrix &other)
    : rows_(other.rows_), columns_(other.columns_) {
  GetMemory();
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < columns_; j++) {
      matrix[i][j] = other.matrix[i][j];
    }
  }
}

s21::S21Matrix::S21Matrix(S21Matrix &&other) {
  rows_ = other.rows_;
  columns_ = other.columns_;
  matrix = other.matrix;
  other.matrix = nullptr;
  other.rows_ = 0;
  other.columns_ = 0;
}

bool s21::S21Matrix::EqMatrix(const S21Matrix &other) {
  bool answer = true;
  if (columns_ == other.columns_ && rows_ == other.rows_) {
    for (int i = 0; i < rows_ && answer == true; i++) {
      for (int j = 0; j < columns_ && answer == true; j++) {
        double x1 = matrix[i][j];
        double x2 = other.matrix[i][j];
        if (x1 - x2 > EPS || x2 - x1 > EPS) {
          answer = false;
        }
      }
    }
  } else {
    answer = false;
  }
  return answer;
}

void s21::S21Matrix::SumMatrix(const S21Matrix &other) {
  if (rows_ != other.rows_ || columns_ != other.columns_) {
    throw std::invalid_argument("incorrect dimentions of matrixs");
  }
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < columns_; j++) {
      matrix[i][j] += other.matrix[i][j];
    }
  }
}

void s21::S21Matrix::SubMatrix(const S21Matrix &other) {
  if (rows_ != other.rows_ || columns_ != other.columns_) {
    throw std::invalid_argument("incorrect dimentions of matrixs");
  }
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < columns_; j++) {
      matrix[i][j] -= other.matrix[i][j];
    }
  }
}

void s21::S21Matrix::MulNumber(const double num) {
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < columns_; j++) {
      matrix[i][j] *= num;
    }
  }
}

void s21::S21Matrix::MulMatrix(const S21Matrix &other) {
  //    std::cout << "Helo" << std::endl;
  if (other.rows_ != columns_) {
    throw std::invalid_argument("incorrect dimentions of matrixs");
  }
  double answer = 0;
  S21Matrix temp(rows_, other.columns_);
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < other.columns_; j++) {
      for (int k = 0; k < columns_; k++) {
        answer += (matrix[i][k] * other.matrix[k][j]);
      }
      temp.matrix[i][j] = answer;
      answer = 0;
    }
  }
  //  temp.print();
  *this = temp;
}

s21::S21Matrix s21::S21Matrix::Transpose() {
  S21Matrix temp(columns_, rows_);
  for (int i = 0; i < columns_; i++) {
    for (int j = 0; j < rows_; j++) {
      temp.matrix[i][j] = matrix[j][i];
    }
  }
  *this = temp;
  return *this;
}

s21::S21Matrix s21::S21Matrix::CalcComplements() {
  S21Matrix temp(rows_, columns_);
  if (columns_ == rows_) {
    if (columns_ > 1) {
      for (int i = 0; i < rows_; i++) {
        for (int j = 0; j < columns_; j++) {
          S21Matrix minor(rows_ - 1, columns_ - 1);
          S21Minor(minor, j, i);
          if ((i + j) % 2 != 1) {
            temp.matrix[j][i] = minor.Determinant();
          } else {
            temp.matrix[j][i] = -minor.Determinant();
          }
        }
      }
    }
  } else {
    throw std::invalid_argument("matrix is not square");
  }
  (*this) = temp;
  return *this;
}

double s21::S21Matrix::Determinant() {
  double temp = 0;
  if (columns_ == rows_) {
    if (columns_ > 1) {
      S21Matrix minor(rows_ - 1, columns_ - 1);
      for (int i = 0; i < rows_; i++) {
        S21Minor(minor, 0, i);
        if (i % 2 != 1) {
          temp += matrix[0][i] * minor.Determinant();
        } else {
          temp -= matrix[0][i] * minor.Determinant();
        }
      }
    } else {
      temp = matrix[0][0];
    }
  } else {
    throw std::invalid_argument("matrix is not square");
  }
  return temp;
}

s21::S21Matrix s21::S21Matrix::InverseMatrix() {
  S21Matrix temp;
  double d = Determinant();
  if (d != 0 && columns_ == rows_ && columns_ != 1) {
    S21Matrix sas = Transpose();
    double num = 1 / d;
    S21Matrix pas = sas.CalcComplements();
    pas.MulNumber(num);
    temp = pas;
  } else if (d != 0 && columns_ == rows_ && columns_ == 1) {
    temp.SetRows(1);
    temp.SetColumns(1);
    temp.matrix[0][0] = 1 / d;
  } else {
    throw std::invalid_argument("matrix is not valid");
  }
  (*this) = temp;
  return *this;
}

void s21::S21Matrix::S21Minor(const S21Matrix &other, int rows, int columns) {
  for (int i = 0, c1 = 0; i < rows_; i++) {
    if (i == rows) {
      c1 = 1;
    } else {
      for (int j = 0, c2 = 0; j < columns_; j++) {
        if (j == columns) {
          c2 = 1;
        } else {
          other.matrix[i - c1][j - c2] = matrix[i][j];
        }
      }
    }
  }
}

int s21::S21Matrix::RowsGiven() { return rows_; }

int s21::S21Matrix::CollumnsGiven() { return columns_; }

void s21::S21Matrix::SetRows(int rows) {
  if (rows == rows_)
    return;
  if (rows <= 0) {
    throw std::invalid_argument("number of rows should be > 0");
  }
  S21Matrix buf(rows, columns_);
  if (rows < rows_) {
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < columns_; j++) {
        buf(i, j) = matrix[i][j];
      }
    }
  } else {
    int i = 0;
    for (; i < rows_; i++) {
      for (int j = 0; j < columns_; j++) {
        buf(i, j) = matrix[i][j];
      }
    }
  }
  *this = buf;
}

void s21::S21Matrix::SetColumns(int columns) {
  if (columns == columns_)
    return;
  if (columns <= 0) {
    throw std::invalid_argument("number of columns should be > 0");
  }
  S21Matrix buf(rows_, columns);
  if (columns < columns_) {
    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < columns; j++) {
        buf(i, j) = matrix[i][j];
      }
    }
  } else {
    for (int i = 0; i < rows_; i++) {
      int j = 0;
      for (; j < columns_; j++) {
        buf(i, j) = matrix[i][j];
      }
      for (; j < columns; j++) {
        buf(i, j) = 0.0;
      }
    }
  }
  *this = buf;
}

s21::S21Matrix s21::S21Matrix::operator+(const S21Matrix &other) {
  S21Matrix matrix(*this);
  matrix.SumMatrix(other);
  return matrix;
}

s21::S21Matrix s21::S21Matrix::operator-(const S21Matrix &other) {
  S21Matrix matrix(*this);
  matrix.SubMatrix(other);
  return matrix;
}

s21::S21Matrix s21::S21Matrix::operator*(const S21Matrix &other) {
  S21Matrix matrix(*this);
  matrix.MulMatrix(other);
  return matrix;
}

s21::S21Matrix s21::S21Matrix::operator*(const double num) {
  S21Matrix matrix(*this);
  matrix.MulNumber(num);
  return matrix;
}

bool s21::S21Matrix::operator==(const S21Matrix &other) {
  S21Matrix matrix(*this);
  return matrix.EqMatrix(other);
}

s21::S21Matrix &s21::S21Matrix::operator=(const S21Matrix &other) {
  if (rows_ != other.rows_ || columns_ != other.columns_) {
    FreeMemory();
    rows_ = other.rows_;
    columns_ = other.columns_;
    GetMemory();
  }
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < columns_; ++j) {
      matrix[i][j] = other.matrix[i][j];
    }
  }
  return *this;
}

s21::S21Matrix s21::S21Matrix::operator+=(const S21Matrix &other) {
  SumMatrix(other);
  return *this;
}

s21::S21Matrix s21::S21Matrix::operator-=(const S21Matrix &other) {
  SubMatrix(other);
  return *this;
}

s21::S21Matrix s21::S21Matrix::operator*=(const double num) {
  MulNumber(num);
  return *this;
}

s21::S21Matrix s21::S21Matrix::operator*=(const S21Matrix &other) {
  MulMatrix(other);
  return *this;
}

double &s21::S21Matrix::operator()(int i, int j) const {
  if (i < 0 || j < 0) {
    throw std::invalid_argument("index is too small");
  } else if (i > rows_ || j > columns_) {
    throw std::invalid_argument("index is too big");
  }
  return matrix[i][j];
}

void s21::S21Matrix::Print() {
  std::cout << "\n Let's print this matrix \n";
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < columns_; j++) {
      std::cout << matrix[i][j] << " ";
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
}
