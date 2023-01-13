#include "s21_afines.h"
#include "s21_matrix_oop.h"
#include "s21_model.h"
#include <cmath>
#include <gtest/gtest.h>
#include <iostream>

TEST(construct_1, test_1) {
  using namespace s21;
  S21Matrix test;

  EXPECT_EQ(test.RowsGiven(), 0);
  EXPECT_EQ(test.CollumnsGiven(), 0);
}

TEST(construct_2, test_1) {
  using namespace s21;
  S21Matrix test(4, 6);

  EXPECT_EQ(test.RowsGiven(), 4);
  EXPECT_EQ(test.CollumnsGiven(), 6);
}

TEST(construct_3, test_1) {
  using namespace s21;
  S21Matrix first(3, 5);
  S21Matrix second(first);

  EXPECT_EQ(second.RowsGiven(), 3);
  EXPECT_EQ(second.CollumnsGiven(), 5);
  EXPECT_EQ(first.RowsGiven(), 3);
  EXPECT_EQ(first.CollumnsGiven(), 5);
}

TEST(construct_4, test_1) {
  using namespace s21;
  S21Matrix first(3, 5);
  S21Matrix second(std::move(first));

  EXPECT_EQ(second.RowsGiven(), 3);
  EXPECT_EQ(second.CollumnsGiven(), 5);
  EXPECT_EQ(first.RowsGiven(), 0);
  EXPECT_EQ(first.CollumnsGiven(), 0);
}

TEST(print_matrix, test_1) {
  using namespace s21;
  S21Matrix first(2, 2);
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      first(i, j) = 1;
    }
  }
  first.Print();
}

TEST(sum_matrix, test_1) {
  using namespace s21;
  S21Matrix first(3, 5);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 5; j++) {
      first(i, j) = 1;
    }
  }
  S21Matrix second(3, 5);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 5; j++) {
      second(i, j) = 2;
    }
  }

  first.SumMatrix(second);

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 5; j++) {
      EXPECT_EQ(first(i, j), 3);
    }
  }
}

TEST(sub_matrix, test_1) {
  using namespace s21;
  S21Matrix first(3, 5);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 5; j++) {
      first(i, j) = 1;
    }
  }
  S21Matrix second(3, 5);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 5; j++) {
      second(i, j) = 2;
    }
  }

  first.SubMatrix(second);

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 5; j++) {
      EXPECT_EQ(first(i, j), -1);
    }
  }
}

TEST(mul_number, test_1) {
  using namespace s21;
  S21Matrix first(3, 5);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 5; j++) {
      first(i, j) = 1;
    }
  }

  first.MulNumber(4);

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 5; j++) {
      EXPECT_EQ(first(i, j), 4);
    }
  }
}

TEST(matrix_mult, test_1) {
  using namespace s21;
  S21Matrix first(2, 2);
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      first(i, j) = 1;
    }
  }
  S21Matrix second(2, 3);
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
      second(i, j) = 1;
    }
  }

  first.MulMatrix(second);

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
      EXPECT_EQ(first(i, j), 2);
    }
  }
}

TEST(transpose, test_1) {
  using namespace s21;
  S21Matrix first(2, 3);
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
      first(i, j) = 1;
    }
  }
  S21Matrix second = first.Transpose();

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 2; j++) {
      EXPECT_EQ(second(i, j), 1);
    }
  }
}

TEST(EqMatrix, test_1) {
  using namespace s21;
  S21Matrix first(2, 1), second(1, 2);
  EXPECT_FALSE(first.EqMatrix(second));
}

TEST(EqMatrix, test_2) {
  using namespace s21;
  S21Matrix first(2, 1), second(2, 1);
  EXPECT_TRUE(first.EqMatrix(second));
}

TEST(EqMatrix, test_3) {
  using namespace s21;
  S21Matrix first(5, 5);
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      first(i, j) = 2;
    }
  }

  S21Matrix second(5, 5);
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      second(i, j) = 2;
    }
  }

  EXPECT_EQ(first.EqMatrix(second), true);
  EXPECT_EQ(first == second, true);
}

TEST(EqMatrix, test_4) {
  using namespace s21;
  S21Matrix first(5, 5);
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      first(i, j) = 2;
    }
  }

  S21Matrix second(5, 5);
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      second(i, j) = 3;
    }
  }

  EXPECT_EQ(first.EqMatrix(second), false);
  EXPECT_EQ(first == second, false);
}

TEST(getters_setters, test_1) {
  using namespace s21;
  S21Matrix first;

  first.SetRows(10);
  first.SetColumns(20);

  EXPECT_EQ(first.RowsGiven(), 10);
  EXPECT_EQ(first.CollumnsGiven(), 20);

  first.SetRows(3);
  first.SetColumns(2);

  EXPECT_EQ(first.RowsGiven(), 3);
  EXPECT_EQ(first.CollumnsGiven(), 2);
}

TEST(getters_setters, test_2) {
  using namespace s21;
  S21Matrix first;

  first.SetRows(10);
  first.SetColumns(20);
  int q = first.RowsGiven();
  int w = first.CollumnsGiven();

  EXPECT_EQ(q, 10);
  EXPECT_EQ(w, 20);

  first.SetRows(3);
  first.SetColumns(2);

  EXPECT_EQ(first.RowsGiven(), 3);
  EXPECT_EQ(first.CollumnsGiven(), 2);
}

TEST(determinant, test_1) {
  using namespace s21;
  S21Matrix first(5, 5);
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      first(i, j) = 2;
    }
  }

  double det = first.Determinant();

  EXPECT_EQ(det, 0);
}

TEST(determinant, test_2) {
  using namespace s21;
  S21Matrix first(5, 5);
  int temp = 0;
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      first(i, j) = temp;
      temp += 1;
    }
  }

  double det = first.Determinant();

  EXPECT_EQ(det, 0);
}

TEST(determinant, test_3) {
  using namespace s21;
  S21Matrix first(3, 3);
  const int temp[9] = {12, 3, 4, 23, 5, 2, 4, 2, 5};
  int count = 0;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      first(i, j) = temp[count];
      count += 1;
    }
  }

  double det = first.Determinant();

  EXPECT_EQ(det, 35);
}

TEST(conforment, test_1) {
  using namespace s21;
  S21Matrix first(3, 3);
  S21Matrix second(2, 2);

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      first(i, j) = 12;
    }
  }
  second = first;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      EXPECT_EQ(second(i, j), 12);
    }
  }
}

TEST(Matrix_complement_calc, test_1) {
  using namespace s21;
  S21Matrix first(3, 3);
  S21Matrix second(3, 3);
  const int values_for_first[9] = {1, 2, 3, 0, 4, 2, 5, 2, 1};
  const int values_for_second[9] = {0, 10, -20, 4, -14, 8, -8, -2, 4};
  int count = 0;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      first(i, j) = values_for_first[count];
      second(i, j) = values_for_second[count];
      count++;
    }
  }
  first.CalcComplements();
  EXPECT_EQ(first.EqMatrix(second), true);
}

TEST(matrix_sum, test_2) {
  using namespace s21;
  S21Matrix first(3, 5);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 5; j++) {
      first(i, j) = 1;
    }
  }
  S21Matrix second(3, 5);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 5; j++) {
      second(i, j) = 2;
    }
  }

  first += second;

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 5; j++) {
      EXPECT_EQ(first(i, j), 3);
    }
  }
}

TEST(matrix_sub, test_3) {
  using namespace s21;
  S21Matrix first(3, 5);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 5; j++) {
      first(i, j) = 1;
    }
  }
  S21Matrix second(3, 5);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 5; j++) {
      second(i, j) = 2;
    }
  }

  S21Matrix result = first + second;

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 5; j++) {
      EXPECT_EQ(result(i, j), 3);
    }
  }
}

TEST(matrix_sub, test_4) {
  using namespace s21;
  S21Matrix first(3, 5);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 5; j++) {
      first(i, j) = 1;
    }
  }
  S21Matrix second(3, 5);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 5; j++) {
      second(i, j) = 2;
    }
  }

  first.SubMatrix(second);

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 5; j++) {
      EXPECT_EQ(first(i, j), -1);
    }
  }
}

TEST(matrix_sub, test_5) {
  using namespace s21;
  S21Matrix first(3, 5);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 5; j++) {
      first(i, j) = 1;
    }
  }
  S21Matrix second(3, 5);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 5; j++) {
      second(i, j) = 2;
    }
  }

  first -= second;

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 5; j++) {
      EXPECT_EQ(first(i, j), -1);
    }
  }
}

TEST(matrix_sub, test_6) {
  using namespace s21;
  S21Matrix first(3, 5);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 5; j++) {
      first(i, j) = 1;
    }
  }
  S21Matrix second(3, 5);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 5; j++) {
      second(i, j) = 2;
    }
  }
  S21Matrix result = first - second;

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 5; j++) {
      EXPECT_EQ(result(i, j), -1);
    }
  }
}

TEST(inverse, test_1) {
  using namespace s21;
  S21Matrix matrix_array[2] = {S21Matrix(3, 3), S21Matrix(3, 3)};
  const int values_for_first[9] = {2, 5, 7, 6, 3, 4, 5, -2, -3};
  const int values_for_second[9] = {1, -1, 1, -38, 41, -34, 27, -29, 24};
  int counter = 0;

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      matrix_array[0](i, j) = values_for_first[counter];
      matrix_array[1](i, j) = values_for_second[counter++];
    }
  }

  S21Matrix result = matrix_array[0].InverseMatrix();
  EXPECT_EQ(result.EqMatrix(matrix_array[1]), true);
}

TEST(matrix_mult, test_2) {
  using namespace s21;
  S21Matrix m(3, 5);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 5; j++) {
      m(i, j) = 1;
    }
  }
  S21Matrix res = m * 4;

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 5; j++) {
      EXPECT_EQ(res(i, j), 4);
    }
  }
}

TEST(matrix_mult, test_3) {
  using namespace s21;
  S21Matrix first(3, 5);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 5; j++) {
      first(i, j) = 1;
    }
  }
  first *= 4;

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 5; j++) {
      EXPECT_EQ(first(i, j), 4);
    }
  }
}

TEST(matrix_mult, test_4) {
  using namespace s21;
  S21Matrix first(2, 2);
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      first(i, j) = 1;
    }
  }
  S21Matrix second(2, 3);
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
      second(i, j) = 1;
    }
  }

  first *= second;

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
      EXPECT_EQ(first(i, j), 2);
    }
  }
}

TEST(matrix_mult, test_5) {
  using namespace s21;
  S21Matrix first(2, 2);
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      first(i, j) = 1;
    }
  }
  S21Matrix second(2, 3);
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
      second(i, j) = 1;
    }
  }

  S21Matrix result(2, 3);
  result = first * second;

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
      EXPECT_EQ(result(i, j), 2);
    }
  }
}

TEST(matrix_mult, test_6) {
  using namespace s21;
  S21Matrix first(3, 5);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 5; j++) {
      first(i, j) = 1;
    }
  }
  S21Matrix second(3, 5);
  second = first * 4;

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 5; j++) {
      EXPECT_EQ(second(i, j), 4);
    }
  }
}

TEST(afines, test_1) {
  using namespace s21;
  Afines temp;
  temp.InitMatrix(3, 3);
  temp.SetUnary();
  for (int i = 0; i < 3; i++) {
    EXPECT_EQ(temp.matrix[i][i], 1);
  }
}

TEST(afines, test_2) {
  using namespace s21;
  Afines temp;
  temp.InitMatrix(4, 4);
  temp.SetUnary();
  temp.MoveMatrix(2, 2, 2);
  for (int i = 0; i < 3; i++) {
    EXPECT_EQ(temp.matrix[i][3], 2);
  }
}

TEST(afines, test_3) {
  using namespace s21;
  Afines temp;
  temp.InitMatrix(4, 4);
  temp.SetUnary();
  temp.RotateMatrix(90, 90, 90);
  EXPECT_LT(temp.matrix[0][0], 0.0001);
  EXPECT_EQ(temp.matrix[1][1], 1);
  EXPECT_LT(temp.matrix[2][2], 0.0001);
}

TEST(afines, test_4) {
  using namespace s21;
  Afines temp;
  temp.InitMatrix(4, 4);
  temp.SetUnary();
  temp.ResizeMatrix(2.0);
  QMatrix4x4 temp2 = temp.convertToQMatrix4x4();
  float test2 = temp2.determinant();
  for (int i = 0; i < 3; i++) {
    EXPECT_EQ(temp.matrix[i][i], 2);
    EXPECT_LT(test2, 9);
  }
}

TEST(afines, test_5) {
  using namespace s21;
  Afines temp;
  temp.InitMatrix(4, 4);
  temp.SetUnary();
  temp.ProjectMatrix(45, 1, 100, 1);
  EXPECT_GT(temp.matrix[0][0], 2.35);
  EXPECT_GT(temp.matrix[1][1], 2.35);
  EXPECT_LT(temp.matrix[2][2], 1.0);
}

TEST(afines, test_6) {
  using namespace s21;
  Afines temp;
  temp.InitMatrix(4, 4);
  temp.SetUnary();
  temp.ProjectMatrix(0.5, 1, 100, 1);
  EXPECT_GT(temp.matrix[0][0], 1.9);
  EXPECT_GT(temp.matrix[1][1], 1.9);
  EXPECT_LT(temp.matrix[2][2], 1.0);
}

TEST(model, test_1) {
  using namespace s21;
  Model test_model;
  test_model.ModelMove(0.01, 0.01, 0.01);
  EXPECT_EQ(test_model.Count(), 216);
}

TEST(model, test_2) {
  using namespace s21;
  Model test_model;
  test_model.ModelMove(0.01, 0.01, 0.01);
  EXPECT_EQ(test_model.Count(), 216);
}

TEST(model, test_3) {
  using namespace s21;
  Model test_model;
  test_model.ReLoadData("cube-4.obj");
  EXPECT_EQ(test_model.Count(), 288);
}

int main() {
  testing::InitGoogleTest();
  return RUN_ALL_TESTS();
}
