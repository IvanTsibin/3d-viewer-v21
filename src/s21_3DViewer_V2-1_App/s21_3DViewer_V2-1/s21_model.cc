#include "s21_model.h"
#include <iostream>
#include <qmath.h>

s21::Model::Model() {
  Figure_t figure;
  m_count_=0;
  m_dots_count_ = 0 ;
  m_triangles_count_ = 0;
  m_triangles_guro_count_ = 0;
  vertexs_amount_ = 0;
  facets_amount_ =0;
  triangles_amount_=0;
  triangles_guro_amount_=0;
  CreatModel(&figure);
  //    PrintFigure(&figure);
  LoadFigure(&figure);
  //    PrintFigure(&figure);
  RemoveFigure(&figure);
  std::cout << std::endl;
}

void s21::Model::ReLoadData(const char file_name[]) {
  Figure_t temp_figure;
  //    std::cout << "ReLoad Step - 1" << std::endl;
  ReadDataFromFile(file_name, &temp_figure);
  //    std::cout << "ReLoad Step - 2" << std::endl;
  LoadFigure(&temp_figure);
//  PrintFigure(&temp_figure);
  //    std::cout << "ReLoad Step - 3" << std::endl;
  RemoveFigure(&temp_figure);
  //    std::cout << "ReLoad Step - 4" << std::endl;
}

void s21::Model::LoadFigure(Figure_t *figure) {
  //    std::cout << "Hello, you are in s21::Model::loadFigure(Figure_t *figure)
  //    " << std::endl;
  vertexs_amount_ = figure->dots_number;
  facets_amount_ = figure->triangles_number;
  triangles_amount_ = figure->triangles_number;
  //    std::cout << "LoadFigure Step - 2 - 1" << std::endl;
  //    print_figure(figure);
  //    std::cout << "LoadFigure Step - 2 - 2" << std::endl;
  //    print_figure(figure);
  ResizeAndMoveFigure(figure);
  //    std::cout << "LoadFigure Step - 3" << std::endl;
  LoadDots(figure);
  //    std::cout << "LoadFigure Step - 4" << std::endl;
  LoadLines(figure);
  //    std::cout << "LoadFigure Step - 5" << std::endl;
  LoadTriangles(figure);
  //    std::cout << "LoadFigure Step - 6" << std::endl;
}

void s21::Model::LoadDots(Figure_t *figure) {
  m_dots_count_ = 0;
  m_dot_data.resize(figure->dots_number * 6);
  GLfloat *g = m_dot_data.data();
  for (int i = 0; i < figure->dots_number; i++) {
    *g++ = figure->dots[i][0];
    *g++ = (-1) * figure->dots[i][1];
    *g++ = figure->dots[i][2];
    *g++ = 0;
    *g++ = 0;
    *g++ = 1;
    m_dots_count_ += 6;
  }
  //    for (int i = 0; i < m_dots_count_; i++) {
  //        std::cout << "m_dot_data[" << i << "] = " << m_dot_data[i] <<
  //        std::endl;
  //    }
//      std::cout << "LoadDots Step m_dots_count_ = " << m_dots_count_ <<
//      std::endl;
}
void s21::Model::LoadLines(Figure_t *figure) {
  m_count_ = 0;
  m_data.resize(2 * figure->lines_number * 6);
  GLfloat *p = m_data.data();
  for (int i = 0; i < figure->lines_number; i++) {
    for (int j = 0; j < 2; j++) {
      *p++ = figure->dots[figure->lines[i][j]][0];
      *p++ = (-1) * figure->dots[figure->lines[i][j]][1];
      *p++ = figure->dots[figure->lines[i][j]][2];
      *p++ = 0;
      *p++ = 0;
      *p++ = 1;
      m_count_ += 6;
    }
  }
  //    for (int i = 0; i < m_count_; i++) {
  //        std::cout << "m_data[" << i << "] = " << m_data[i] << std::endl;
  //    }
//      std::cout << "LoadLines m_count_ = " << m_count_ << std::endl;
}
void s21::Model::LoadTriangles(Figure_t *figure) {
  m_triangles_count_ = 0;
  m_triangles_data.resize(2 * 3 * figure->triangles_number * 6);
  GLfloat *k = m_triangles_data.data();
  QVector3D normal;
  //    float min = 1.0, max = 0.0, lenth = 1.0;
  double x1, y1, z1, x2, y2, z2;
  for (int i = 0; i < figure->triangles_number; i++) {
    x1 = (figure->dots[figure->triangles[i][4]][0] * 1000 -
          figure->dots[figure->triangles[i][0]][0] * 1000 + 0.01);
    y1 = (figure->dots[figure->triangles[i][4]][1] * 1000 -
          figure->dots[figure->triangles[i][0]][1] * 1000 + 0.01);
    z1 = (figure->dots[figure->triangles[i][4]][2] * 1000 -
          figure->dots[figure->triangles[i][0]][2] * 1000 + 0.01);
    x2 = (figure->dots[figure->triangles[i][2]][0] * 1000 -
          figure->dots[figure->triangles[i][0]][0] * 1000 + 0.01);
    y2 = (figure->dots[figure->triangles[i][2]][1] * 1000 -
          figure->dots[figure->triangles[i][0]][1] * 1000 + 0.01);
    z2 = (figure->dots[figure->triangles[i][2]][2] * 1000 -
          figure->dots[figure->triangles[i][0]][2] * 1000 + 0.01);
    normal = QVector3D::normal(QVector3D(x2, y2, z2), QVector3D(x1, y1, z1));
    normal.normalize();

    for (int j = 2; j > -1; j--) {
      *k++ = figure->dots[figure->triangles[i][j * 2]][0];
      *k++ = (-1) * figure->dots[figure->triangles[i][j * 2]][1];
      *k++ = figure->dots[figure->triangles[i][j * 2]][2];
      *k++ = normal.x();
      *k++ = -normal.y();
      *k++ = normal.z();
      m_triangles_count_ += 6;
    }
    for (int j = 0; j < 3; j++) {
      *k++ = figure->dots[figure->triangles[i][j * 2]][0];
      *k++ = (-1) * figure->dots[figure->triangles[i][j * 2]][1];
      *k++ = figure->dots[figure->triangles[i][j * 2]][2];
      *k++ = -normal.x();
      *k++ = normal.y();
      *k++ = -normal.z();
      m_triangles_count_ += 6;
    }
  }
  //    for (int i = 0; i < m_triangles_count_; i++) {
  //        std::cout << "m_triangles_data[" << i << "] = " <<
  //        m_triangles_data[i] << std::endl;
  //    }
  if (figure->normals_number == 0) {
    m_triangles_guro_count_ = 0;
    m_triangles_guro_data.resize(2 * 3 * figure->triangles_number * 6);
    m_triangles_guro_data = m_triangles_data;
    m_triangles_guro_count_ = m_triangles_count_;
  } else {
    LoadTrianglesGuro(figure);
  }
//      std::cout << "Hi LoadTriangles m_triangles_count_ = " <<
//      m_triangles_count_ << std::endl;
}

void s21::Model::LoadTrianglesGuro(Figure_t *figure) {
  m_triangles_guro_count_ = 0;
  m_triangles_guro_data.resize(2 * 3 * figure->triangles_number * 6);
  GLfloat *k = m_triangles_guro_data.data();
  for (int i = 0; i < figure->triangles_number; i++) {
    for (int j = 0; j < 3; j++) {
      *k++ = figure->dots[figure->triangles[i][j * 2]][0];
      *k++ = (-1) * figure->dots[figure->triangles[i][j * 2]][1];
      *k++ = figure->dots[figure->triangles[i][j * 2]][2];
      *k++ = figure->normals[figure->triangles[i][j * 2 + 1]][0];
      *k++ = (-1) * figure->normals[figure->triangles[i][j * 2 + 1]][1];
      *k++ = figure->normals[figure->triangles[i][j * 2 + 1]][2];
      m_triangles_guro_count_ += 6;
    }
    for (int j = 2; j > -1; j--) {
      *k++ = figure->dots[figure->triangles[i][j * 2]][0];
      *k++ = (-1) * figure->dots[figure->triangles[i][j * 2]][1];
      *k++ = figure->dots[figure->triangles[i][j * 2]][2];
      *k++ = figure->normals[figure->triangles[i][j * 2 + 1]][0];
      *k++ = (-1) * figure->normals[figure->triangles[i][j * 2 + 1]][1];
      *k++ = figure->normals[figure->triangles[i][j * 2 + 1]][2];
      m_triangles_guro_count_ += 6;
    }
  }
  //    for (int i = 0; i < m_triangles_count_; i++) {
  //        std::cout << "m_triangles_guro_data[" << i << "] = " <<
  //        m_triangles_guro_data[i] << std::endl;
  //    }
  //    std::cout << "Hi LoadTriangles m_triangles_guro_count = " <<
  //    m_triangles_guro_count << std::endl;
}

void s21::Model::ModelMove(GLfloat xMove, GLfloat yMove, GLfloat zMove) {
  GLfloat *p = m_data.data();
  for (int i = 0; i < m_count_; i += 6) {
    *p = *p + xMove;
    *p++;
    *p = *p + yMove;
    *p++;
    *p = *p + zMove;
    *p++;
    *p++;
    *p++;
    *p++;
  }
  GLfloat *g = m_dot_data.data();
  for (int i = 0; i < m_dots_count_; i += 6) {
    *g = *g + xMove;
    *g++;
    *g = *g + yMove;
    *g++;
    *g = *g + zMove;
    *g++;
    *g++;
    *g++;
    *g++;
  }
  GLfloat *k = m_triangles_data.data();
  for (int i = 0; i < m_triangles_count_; i += 6) {
    *k = *k + xMove;
    *k++;
    *k = *k + yMove;
    *k++;
    *k = *k + zMove;
    *k++;
    *k++;
    *k++;
    *k++;
  }
}

void s21::Model::InitFigure(Figure_t *figure) {
  if (figure->dots_number > MAX_NUMBER_OF_DOTS)
    figure->dots_number = MAX_NUMBER_OF_DOTS;
  if (figure->dots_number <= 0)
    figure->dots_number = 0;
  figure->dots = new double *[figure->dots_number];
  for (int i = 0; i < figure->dots_number; i++) {
    figure->dots[i] = new double[4];
    figure->dots[i][0] = 0;
    figure->dots[i][1] = 0;
    figure->dots[i][2] = 0;
    figure->dots[i][3] = 1;
  }
  if (figure->triangles_number > MAX_NUMBER_OF_TRIANGLES)
    figure->triangles_number = MAX_NUMBER_OF_TRIANGLES;
  if (figure->triangles_number <= 0)
    figure->triangles_number = 0;
  figure->triangles = new int *[figure->triangles_number];
  for (int i = 0; i < figure->triangles_number; i++) {
    figure->triangles[i] = new int[DOTS_IN_POLYGON];
    for (int j = 0; j < DOTS_IN_POLYGON; j++) {
      figure->triangles[i][j] = -1;
    }
  }
  if (figure->lines_number > MAX_NUMBER_OF_LINES)
    figure->lines_number = MAX_NUMBER_OF_LINES;
  if (figure->lines_number <= 0)
    figure->lines_number = 0;
  figure->lines = new int *[figure->lines_number];
  for (int i = 0; i < figure->lines_number; i++) {
    figure->lines[i] = new int[2];
    figure->lines[i][0] = 0;
    figure->lines[i][1] = 0;
  }
  if (figure->normals_number > MAX_NUMBER_OF_NORMALS)
    figure->normals_number = MAX_NUMBER_OF_NORMALS;
  if (figure->normals_number <= 0) {
    figure->normals_number = 0;
    figure->normals = nullptr;
  } else {
    figure->normals = new double *[figure->normals_number];
    for (int i = 0; i < figure->normals_number; i++) {
      figure->normals[i] = new double[4];
      figure->normals[i][0] = 0;
      figure->normals[i][1] = 0;
      figure->normals[i][2] = 0;
      figure->normals[i][3] = 1;
    }
  }
}

void s21::Model::CreatModel(Figure_t *figure) {
  figure->dots_number = 8;
  figure->triangles_number = 12;
  figure->lines_number = 18;
  figure->normals_number = 8;
  InitFigure(figure);
  figure->dots[0][0] = -0.2;
  figure->dots[0][1] = 0.2;
  figure->dots[0][2] = 0.2;
  figure->dots[1][0] = -0.2;
  figure->dots[1][1] = 0.2;
  figure->dots[1][2] = -0.2;
  figure->dots[2][0] = -0.2;
  figure->dots[2][1] = -0.2;
  figure->dots[2][2] = -0.2;
  figure->dots[3][0] = -0.2;
  figure->dots[3][1] = -0.2;
  figure->dots[3][2] = 0.2;
  figure->dots[4][0] = 0.2;
  figure->dots[4][1] = 0.2;
  figure->dots[4][2] = 0.2;
  figure->dots[5][0] = 0.2;
  figure->dots[5][1] = 0.2;
  figure->dots[5][2] = -0.2;
  figure->dots[6][0] = 0.2;
  figure->dots[6][1] = -0.2;
  figure->dots[6][2] = -0.2;
  figure->dots[7][0] = 0.2;
  figure->dots[7][1] = -0.2;
  figure->dots[7][2] = 0.2;

  figure->triangles[0][0] = 0;
  figure->triangles[0][1] = 0;
  figure->triangles[0][2] = 1;
  figure->triangles[0][3] = 1;
  figure->triangles[0][4] = 2;
  figure->triangles[0][5] = 2;
  figure->triangles[0][6] = -1;
  figure->triangles[1][0] = 0;
  figure->triangles[1][1] = 0;
  figure->triangles[1][2] = 2;
  figure->triangles[1][3] = 2;
  figure->triangles[1][4] = 3;
  figure->triangles[1][5] = 3;
  figure->triangles[1][6] = -1;
  figure->triangles[2][0] = 1;
  figure->triangles[2][1] = 1;
  figure->triangles[2][2] = 2;
  figure->triangles[2][3] = 2;
  figure->triangles[2][4] = 6;
  figure->triangles[2][5] = 6;
  figure->triangles[2][6] = -1;
  figure->triangles[3][0] = 1;
  figure->triangles[3][1] = 1;
  figure->triangles[3][2] = 6;
  figure->triangles[3][3] = 6;
  figure->triangles[3][4] = 5;
  figure->triangles[3][5] = 5;
  figure->triangles[3][6] = -1;
  figure->triangles[4][0] = 5;
  figure->triangles[4][1] = 5;
  figure->triangles[4][2] = 6;
  figure->triangles[4][3] = 6;
  figure->triangles[4][4] = 7;
  figure->triangles[4][5] = 7;
  figure->triangles[4][6] = -1;
  figure->triangles[5][0] = 5;
  figure->triangles[5][1] = 5;
  figure->triangles[5][2] = 7;
  figure->triangles[5][3] = 7;
  figure->triangles[5][4] = 4;
  figure->triangles[5][5] = 4;
  figure->triangles[5][6] = -1;
  figure->triangles[6][0] = 0;
  figure->triangles[6][1] = 0;
  figure->triangles[6][2] = 4;
  figure->triangles[6][3] = 4;
  figure->triangles[6][4] = 7;
  figure->triangles[6][5] = 7;
  figure->triangles[6][6] = -1;
  figure->triangles[7][0] = 0;
  figure->triangles[7][1] = 0;
  figure->triangles[7][2] = 7;
  figure->triangles[7][3] = 7;
  figure->triangles[7][4] = 3;
  figure->triangles[7][5] = 3;
  figure->triangles[7][6] = -1;
  figure->triangles[8][0] = 0;
  figure->triangles[8][1] = 0;
  figure->triangles[8][2] = 1;
  figure->triangles[8][3] = 1;
  figure->triangles[8][4] = 5;
  figure->triangles[8][5] = 5;
  figure->triangles[8][6] = -1;
  figure->triangles[9][0] = 0;
  figure->triangles[9][1] = 0;
  figure->triangles[9][2] = 5;
  figure->triangles[9][3] = 5;
  figure->triangles[9][4] = 4;
  figure->triangles[9][5] = 4;
  figure->triangles[9][6] = -1;
  figure->triangles[10][0] = 3;
  figure->triangles[10][1] = 3;
  figure->triangles[10][2] = 2;
  figure->triangles[10][3] = 2;
  figure->triangles[10][4] = 6;
  figure->triangles[10][5] = 6;
  figure->triangles[10][6] = -1;
  figure->triangles[11][0] = 3;
  figure->triangles[11][1] = 3;
  figure->triangles[11][2] = 6;
  figure->triangles[11][3] = 6;
  figure->triangles[11][4] = 7;
  figure->triangles[11][5] = 7;
  figure->triangles[11][6] = -1;

  figure->lines[0][0] = 0;
  figure->lines[0][1] = 1;
  figure->lines[1][0] = 1;
  figure->lines[1][1] = 2;
  figure->lines[2][0] = 2;
  figure->lines[2][1] = 3;
  figure->lines[3][0] = 3;
  figure->lines[3][1] = 0;
  figure->lines[4][0] = 0;
  figure->lines[4][1] = 2;
  figure->lines[5][0] = 4;
  figure->lines[5][1] = 5;
  figure->lines[6][0] = 5;
  figure->lines[6][1] = 6;
  figure->lines[7][0] = 6;
  figure->lines[7][1] = 7;
  figure->lines[8][0] = 7;
  figure->lines[8][1] = 4;
  figure->lines[9][0] = 4;
  figure->lines[9][1] = 6;
  figure->lines[10][0] = 0;
  figure->lines[10][1] = 4;
  figure->lines[11][0] = 1;
  figure->lines[11][1] = 5;
  figure->lines[12][0] = 2;
  figure->lines[12][1] = 6;
  figure->lines[13][0] = 3;
  figure->lines[13][1] = 7;
  figure->lines[14][0] = 0;
  figure->lines[14][1] = 5;
  figure->lines[15][0] = 1;
  figure->lines[15][1] = 6;
  figure->lines[16][0] = 2;
  figure->lines[16][1] = 7;
  figure->lines[17][0] = 3;
  figure->lines[17][1] = 4;
  figure->normals[0][0] = -0.577;
  figure->normals[0][1] = 0.577;
  figure->normals[0][2] = 0.577;
  figure->normals[1][0] = -0.577;
  figure->normals[1][1] = 0.577;
  figure->normals[1][2] = -0.577;
  figure->normals[2][0] = -0.577;
  figure->normals[2][1] = -0.577;
  figure->normals[2][2] = -0.577;
  figure->normals[3][0] = -0.577;
  figure->normals[3][1] = -0.577;
  figure->normals[3][2] = 0.577;
  figure->normals[4][0] = 0.577;
  figure->normals[4][1] = 0.577;
  figure->normals[4][2] = 0.577;
  figure->normals[5][0] = 0.577;
  figure->normals[5][1] = 0.577;
  figure->normals[5][2] = -0.577;
  figure->normals[6][0] = 0.577;
  figure->normals[6][1] = -0.577;
  figure->normals[6][2] = -0.577;
  figure->normals[7][0] = 0.577;
  figure->normals[7][1] = -0.577;
  figure->normals[7][2] = 0.577;
}

void s21::Model::RemoveFigure(Figure_t *figure) {
  //    std::cout << "remove_figure Stage - 1" << std::endl;
  if (figure->dots_number != 0) {
    for (int i = 0; i < figure->dots_number; i++) {
      delete[] figure->dots[i];
    }
    delete[] figure->dots;
  } else {
    figure->dots_number = 0;
  }
  //    std::cout << "remove_figure Stage - 2" << std::endl;
  if (figure->triangles_number != 0) {
    for (int i = 0; i < figure->triangles_number; i++) {
      delete[] figure->triangles[i];
    }
    delete[] figure->triangles;
  } else {
    figure->triangles_number = 0;
  }
  //    std::cout << "remove_figure Stage - 3" << std::endl;
  if (figure->lines_number != 0) {
    for (int i = 0; i < figure->lines_number; i++) {
      delete[] figure->lines[i];
      //             std::cout << "figure->lines_number = " <<
      //             figure->lines_number << " line i = " << i << std::endl;
    }
    delete[] figure->lines;
  } else {
    figure->lines_number = 0;
  }
  //    std::cout << "remove_figure Stage - 4" << std::endl;
  if (figure->normals_number != 0) {
    for (int i = 0; i < figure->normals_number; i++) {
      delete[] figure->normals[i];
      //             std::cout << "figure->lines_number = " <<
      //             figure->lines_number << " line i = " << i << std::endl;
    }
    delete[] figure->normals;
  } else {
    figure->normals_number = 0;
  }
  //        std::cout << "remove_figure Stage - 5" << std::endl;
}

// void s21::Model::PrintFigure(Figure_t *figure) {
////    for (int i = 0; i < figure->dots_number; i++) {
////        printf("figure->dots[%2d][0] = %+4.2f", i, figure->dots[i][0]);
////        printf("  figure->dots[%2d][1] = %+4.2f", i, figure->dots[i][1]);
////        printf("  figure->dots[%2d][2] = %+4.2f\n", i, figure->dots[i][2]);
////    }
////    for (int i = 0; i < figure->triangles_number; i++) {
////        printf("FR[%2d][0] = %2d", i, figure->triangles[i][0]);
////        printf("  FR[%2d][1] = %2d", i, figure->triangles[i][1]);
////        printf("  FR[%2d][2] = %2d", i, figure->triangles[i][2]);
////        printf("  FR[%2d][3] = %2d", i, figure->triangles[i][3]);
////        printf("  FR[%2d][4] = %2d", i, figure->triangles[i][4]);
////        printf("  FR[%2d][5] = %2d", i, figure->triangles[i][5]);
////        printf("  FR[%2d][6] = %2d", i, figure->triangles[i][6]);
////        printf("  FR[%2d][7] = %2d", i, figure->triangles[i][7]);
////        printf("  FR[%2d][8] = %2d\n", i, figure->triangles[i][8]);
////    }
////    printf("\n");
////    for (int i = 0; i < figure->lines_number; i++) {
////        printf("figure->lines[%2d][0] = %2d", i, figure->lines[i][0]);
////        printf("  figure->lines[%2d][1] = %2d\n", i, figure->lines[i][1]);
////    }
////    for (int i = 0; i < figure->normals_number; i++) {
////        printf("figure->normals[%2d][0] = %+4.2f", i,
//// figure->normals[i][0]); /        printf("  figure->normals[%2d][1] =
//// %+4.2f", i, figure->normals[i][1]); /        printf("
//// figure->normals[%2d][2]
//// =
////%+4.2f\n", i, figure->normals[i][2]); /    }
//    printf("figure->dots_number %d\n", figure->dots_number);
//    printf("figure->triangles_number %d\n", figure->triangles_number);
//    printf("figure->lines_number %d\n", figure->lines_number);
//    printf("figure->normals_number %d\n", figure->normals_number);
//}

void s21::Model::CopyFigure(Figure_t *dist_figure, Figure_t *src_figure) {
  dist_figure->dots_number = src_figure->dots_number;
  dist_figure->triangles_number = src_figure->triangles_number;
  dist_figure->lines_number = src_figure->lines_number;
  dist_figure->normals_number = src_figure->normals_number;
  InitFigure(dist_figure);
  for (int i = 0; i < src_figure->dots_number; i++) {
    dist_figure->dots[i][0] = src_figure->dots[i][0];
    dist_figure->dots[i][1] = src_figure->dots[i][1];
    dist_figure->dots[i][2] = src_figure->dots[i][2];
    dist_figure->dots[i][3] = src_figure->dots[i][3];
  }
  for (int i = 0; i < src_figure->triangles_number; i++) {
    dist_figure->triangles[i][0] = src_figure->triangles[i][0];
    dist_figure->triangles[i][1] = src_figure->triangles[i][1];
    dist_figure->triangles[i][2] = src_figure->triangles[i][2];
    dist_figure->triangles[i][3] = src_figure->triangles[i][3];
    dist_figure->triangles[i][4] = src_figure->triangles[i][4];
    dist_figure->triangles[i][5] = src_figure->triangles[i][5];
    dist_figure->triangles[i][6] = src_figure->triangles[i][6];
  }
  for (int i = 0; i < src_figure->lines_number; i++) {
    dist_figure->lines[i][0] = src_figure->lines[i][0];
    dist_figure->lines[i][1] = src_figure->lines[i][1];
  }
  for (int i = 0; i < src_figure->normals_number; i++) {
    dist_figure->normals[i][0] = src_figure->normals[i][0];
    dist_figure->normals[i][1] = src_figure->normals[i][1];
    dist_figure->normals[i][2] = src_figure->normals[i][2];
    dist_figure->normals[i][3] = src_figure->normals[i][3];
  }
}

void s21::Model::ResizeAndMoveFigure(Figure_t *temp_figure) {
  double x_max = temp_figure->dots[0][0], x_min = temp_figure->dots[0][0];
  double y_max = temp_figure->dots[0][1], y_min = temp_figure->dots[0][1];
  double z_max = temp_figure->dots[0][2], z_min = temp_figure->dots[0][2];
  for (int i = 1; i < temp_figure->dots_number; i++) {
    if (temp_figure->dots[i][0] > x_max)
      x_max = temp_figure->dots[i][0];
    if (temp_figure->dots[i][0] < x_min)
      x_min = temp_figure->dots[i][0];
    if (temp_figure->dots[i][1] > y_max)
      y_max = temp_figure->dots[i][1];
    if (temp_figure->dots[i][1] < y_min)
      y_min = temp_figure->dots[i][1];
    if (temp_figure->dots[i][2] > z_max)
      z_max = temp_figure->dots[i][2];
    if (temp_figure->dots[i][2] < z_min)
      z_min = temp_figure->dots[i][2];
  }
  double max_size = x_max - x_min, y_size = y_max - y_min;
  if (max_size < y_size)
    max_size = y_size;
  double z_size = z_max - z_min;
  if (max_size < z_size)
    max_size = z_size;
  double size_coeff = 0.5 / max_size;
  MoveFigure(temp_figure, -1 * (x_min + (x_max - x_min) / 2),
              -1 * (y_min + (y_max - y_min) / 2),
              -1 * (z_min + (z_max - z_min) / 2));
  ResizeFigure(temp_figure, size_coeff, size_coeff, size_coeff);
}

void s21::Model::MoveFigure(Figure_t *figure, double x, double y, double z) {
  for (int i = 0; i < figure->dots_number; i++) {
    figure->dots[i][0] = figure->dots[i][0] + x;
    figure->dots[i][1] = figure->dots[i][1] + y;
    figure->dots[i][2] = figure->dots[i][2] + z;
  }
}

void s21::Model::ResizeFigure(Figure_t *figure, double x, double y, double z) {
  for (int i = 0; i < figure->dots_number; i++) {
    figure->dots[i][0] = figure->dots[i][0] * x;
    figure->dots[i][1] = figure->dots[i][1] * y;
    figure->dots[i][2] = figure->dots[i][2] * z;
  }
}

int s21::Model::ReadDataFromFile(const char file_name[], Figure_t *figure) {
  //    std::cout << "s21::Model::ReadDataFromFile Step - 1" << std::endl;
  FILE *obj_file;
  figure->dots_number = 0;
  figure->lines_number = 0;
  figure->triangles_number = 0, figure->normals_number = 0;
  int error = 0, str_number = 0;
  if ((obj_file = fopen(file_name, "r")) == NULL) {
    std::cout << "error = 1 file_name = " << file_name << std::endl;
    error = 1;
  } else {
    Figure_t temp_figure;
    int lines_number = NumberOfLinesFromFile(obj_file);
    fclose(obj_file);
    obj_file = NULL;
    obj_file = fopen(file_name, "r");
    int *lines_lenths;
    lines_lenths = new int[lines_number];
    ReadLineLenth(obj_file, lines_lenths);
    fclose(obj_file);
    obj_file = NULL;
    char **strs_from_file = NULL;
    strs_from_file = new char *[lines_number];
    for (int i = 0; i < lines_number; i++) {
      strs_from_file[i] = new char[lines_lenths[i]];
      for (int j = 0; j < lines_lenths[i]; j++)
        strs_from_file[i][j] = '\0';
    }
    obj_file = fopen(file_name, "r");
    ReadStrFromFile(obj_file, strs_from_file, &str_number);
    //        std::cout << "Step - 2" << std::endl;
    fclose(obj_file);
    ReadNumberOfDotsAndFacetsFromStr(strs_from_file, str_number,
                                            &temp_figure);
    temp_figure.lines_number = temp_figure.triangles_number * 5;
    int temp_lines_amount = temp_figure.lines_number;
    InitFigure(&temp_figure);
    //        print_figure(&temp_figure);
    ReadDotsFromStr(strs_from_file, lines_number, &temp_figure);
    ReadNormalsFromStr(strs_from_file, lines_number, &temp_figure);
    //        std::cout << "Step - 3" << std::endl;
    //        read_polygons_from_str(strs_from_file, lines_number, &temp_figure,
    //        lines_lenths); std::cout << "Step - 4" << std::endl;
    //        print_figure(&temp_figure);
    ReadPolygonsFromStrNew(strs_from_file, lines_number, &temp_figure,
                               lines_lenths);
    //        print_figure(&temp_figure);
    delete[] lines_lenths;
    for (int i = 0; i < lines_number; i++)
      delete[] strs_from_file[i];
    delete[] strs_from_file;
    FindLinesFromPolygons(&temp_figure);
    //        print_figure(&temp_figure);
    //        std::cout << "Step - 5" << std::endl;
    ConvertPolygonsToTriangles(&temp_figure);
    //        print_figure(&temp_figure);
    //        std::cout << "Step - 6" << std::endl;
    CopyFigure(figure, &temp_figure);
    //        print_figure(figure);
    //        std::cout << "Step - 7" << std::endl;
    temp_figure.lines_number = temp_lines_amount;
    RemoveFigure(&temp_figure);
    //        std::cout << "Step - 8" << std::endl;
  }
  return error;
}

void s21::Model::ReadNumberOfDotsAndFacetsFromStr(char **strs_from_file,
                                                         int str_number,
                                                         Figure_t *figure) {
  figure->dots_number = 0;
  figure->triangles_number = 0;
  figure->normals_number = 0;
  for (int i = 0; i < str_number; i++) {
    if (strs_from_file[i][0] == 'v' && strs_from_file[i][1] == ' ')
      figure->dots_number += 1;
    if (strs_from_file[i][0] == 'f' && strs_from_file[i][1] == ' ')
      figure->triangles_number += 1;
    if (strs_from_file[i][0] == 'v' && strs_from_file[i][1] == 'n' &&
        strs_from_file[i][2] == ' ')
      figure->normals_number += 1;
  }
}

int s21::Model::NumberOfLinesFromFile(FILE *obj_file) {
  char letter;
  int str_counter = 0;
  while (!feof(obj_file)) {
    letter = fgetc(obj_file);
    if (letter == 10 || letter == EOF) {
      str_counter++;
    }
  }
  return str_counter;
}

void s21::Model::ConvertPolygonsToTriangles(Figure_t *figure) {
  int **temp_triangles,
      temp_triangles_size = figure->triangles_number * TEMP_LINES_NUMBER;
  temp_triangles = new int *[temp_triangles_size];
  int counter = 0;
  for (int i = 0; i < temp_triangles_size; i++) {
    temp_triangles[i] = new int[6];
    temp_triangles[i][0] = -1;
    temp_triangles[i][1] = -1;
    temp_triangles[i][2] = -1;
    temp_triangles[i][3] = -1;
    temp_triangles[i][4] = -1;
    temp_triangles[i][5] = -1;
  }
  for (int i = 0; i < figure->triangles_number; i++) {
    temp_triangles[counter][0] = figure->triangles[i][0];
    temp_triangles[counter][1] = figure->triangles[i][1];
    temp_triangles[counter][2] = figure->triangles[i][2];
    temp_triangles[counter][3] = figure->triangles[i][3];
    temp_triangles[counter][4] = figure->triangles[i][4];
    temp_triangles[counter][5] = figure->triangles[i][5];
    counter++;
    int temp_counter = 6;
    while (figure->triangles[i][temp_counter] != -1) {
      temp_triangles[counter][0] = figure->triangles[i][0];
      temp_triangles[counter][1] = figure->triangles[i][1];
      temp_triangles[counter][2] = figure->triangles[i][temp_counter - 2];
      temp_triangles[counter][3] = figure->triangles[i][temp_counter - 1];
      temp_triangles[counter][4] = figure->triangles[i][temp_counter];
      temp_triangles[counter][5] = figure->triangles[i][temp_counter + 1];
      temp_counter += 2;
      counter++;
    }
  }
  for (int i = 0; i < figure->triangles_number; i++)
    delete[] figure->triangles[i];
  delete[] figure->triangles;
  figure->triangles_number = counter;
  figure->triangles = new int *[counter];
  for (int i = 0; i < counter; i++) {
    figure->triangles[i] = new int[7];
    figure->triangles[i][0] = temp_triangles[i][0];
    figure->triangles[i][1] = temp_triangles[i][1];
    figure->triangles[i][2] = temp_triangles[i][2];
    figure->triangles[i][3] = temp_triangles[i][3];
    figure->triangles[i][4] = temp_triangles[i][4];
    figure->triangles[i][5] = temp_triangles[i][5];
    figure->triangles[i][6] = -1;
  }
  for (int i = 0; i < temp_triangles_size; i++) {
    delete[] temp_triangles[i];
  }
  delete[] temp_triangles;
}

void s21::Model::FindLinesFromPolygons(Figure_t *figure) {
  //    std::cout << "Hello, you are in FindLinesFromPolygons,
  //    figure->lines_number = " << figure->lines_number << std::endl;
  int counter = 0;
  for (int i = 0; i < figure->triangles_number; i++) {
    int dots_counter = 2;
    while (figure->triangles[i][dots_counter] != -1) {
      //            std::cout << "figure->triangles[" << i <<"][" <<
      //            dots_counter << "] = " << figure->triangles[i][dots_counter]
      //            << std ::endl;
      figure->lines[counter][0] = figure->triangles[i][dots_counter - 2];
      figure->lines[counter][1] = figure->triangles[i][dots_counter];
      //            std::cout << "figure->triangles[" << i <<"][" <<
      //            dots_counter-2 << "] = " <<
      //            figure->triangles[i][dots_counter-2] << "
      //            figure->triangles[" << i << "][" << dots_counter << "] = "
      //            << figure->triangles[i][dots_counter] << std ::endl;
      counter++;
      dots_counter += 2;
    }
    if (figure->triangles[i][dots_counter] == -1) {
      //            std::cout << "figure->triangles[" << i <<"][" <<
      //            dots_counter << "] = " << figure->triangles[i][dots_counter]
      //            << std ::endl;
      figure->lines[counter][0] = figure->triangles[i][0];
      figure->lines[counter][1] = figure->triangles[i][dots_counter - 2];
      //            std::cout << "figure->triangles[" << i <<"][" << 0 << "] = "
      //            << figure->triangles[i][0] << "  figure->triangles[" << i <<
      //            "][" << dots_counter-2 << "] = " <<
      //            figure->triangles[i][dots_counter-2] << std ::endl;
      counter++;
    }
  }
  //    std::cout << "By by, you are out of FindLinesFromPolygons,
  //    figure->lines_number = " << figure->lines_number << std::endl;
}

// void s21::Model::FindLinesFromPolygons(Figure_t *figure) {
////    std::cout << "Hello, you are in FindLinesFromPolygons,
/// figure->lines_number = " << figure->lines_number << std::endl;
//    int counter = 0, counter_2 = 0, hash_amount = figure->triangles_number *
//    TEMP_LINES_NUMBER * 2; int **temp_lines, **hash_arr; temp_lines = new
//    int*[hash_amount]; for (int i = 0; i < hash_amount; i++) {
//        temp_lines[i] = new int[2]; temp_lines[i][0] = -1; temp_lines[i][1] =
//        -1;
//        }
//    for (int i = 0; i < figure->triangles_number; i++) {
//        int dots_counter = 2;
//        while (figure->triangles[i][dots_counter] != -1) {
////            std::cout << "figure->triangles[" << i <<"][" << dots_counter <<
///"] = " << figure->triangles[i][dots_counter] << std ::endl;
//            temp_lines[counter][0] = figure->triangles[i][dots_counter - 2];
//            temp_lines[counter][1] = figure->triangles[i][dots_counter];
////            std::cout << "figure->triangles[" << i <<"][" << dots_counter-2
///<< "] = " << figure->triangles[i][dots_counter-2] << "  figure->triangles["
///<< i << "][" << dots_counter << "] = " << figure->triangles[i][dots_counter]
///<< std ::endl;
//            counter++;
//            dots_counter += 2;
//        }
//        if (figure->triangles[i][dots_counter] == -1) {
////            std::cout << "figure->triangles[" << i <<"][" << dots_counter <<
///"] = " << figure->triangles[i][dots_counter] << std ::endl;
//            temp_lines[counter][0] = figure->triangles[i][0];
//            temp_lines[counter][1] = figure->triangles[i][dots_counter - 2];
////            std::cout << "figure->triangles[" << i <<"][" << 0 << "] = " <<
/// figure->triangles[i][0] << "  figure->triangles[" << i << "][" <<
/// dots_counter-2 << "] = " << figure->triangles[i][dots_counter-2] << std
///::endl;
//            counter++;
//        }
//    }
//    for (int i = 0; i < counter; i++) {
////        std::cout << "    temp_lines["<< i << "][0] = " << temp_lines[i][0]
///<< "  temp_lines["<< i << "][1] = " << temp_lines[i][1] << std::endl;
//    }
////    std::cout << "counter = " << counter << "  hash_amount = " <<
/// hash_amount << std::endl;
//    hash_arr = new int*[hash_amount];
//    for (int i = 0; i < hash_amount; i++) {
//        hash_arr[i] = new int[2]; hash_arr[i][0] = -1; hash_arr[i][1] = -1;
//    }
//    creat_hash_for_lines_number(temp_lines, counter, hash_arr, hash_amount);
//    for (int i = 0; i < hash_amount; i++) {
//        if (hash_arr[i][0] != -1 && hash_arr[i][1] != -1) {
//            figure->lines[counter_2][0] = hash_arr[i][0];
//            figure->lines[counter_2][1] = hash_arr[i][1];
////            std::cout << "figure->lines[" << counter_2 << "][0] = " <<
/// figure->lines[counter_2][0] << "  figure->lines[" << counter_2 << "][1] = "
///<< figure->lines[counter_2][1] << std::endl;
//            counter_2++;
//        }
//    }
//     figure->lines_number = counter_2;
////    std::cout << "counter_2 = " << counter_2 << std::endl;
//    for (int i = 0; i < hash_amount; i++) {
//        delete[] temp_lines[i];
//    }
//     delete[] temp_lines;
//    for (int i = 0; i < hash_amount; i++) {
//        delete[] hash_arr[i];
//    }
//    delete[] hash_arr;
////    std::cout << "By by, you are out of FindLinesFromPolygons,
/// figure->lines_number = " << figure->lines_number << std::endl;
//}

// void s21::Model::creat_hash_for_lines_number(int **temp_lines, int counter,
// int **hash_arr, int hash_amount) {
////    std::cout << "Hello, you are in s21::Model::creat_hash_for_lines_number
///" << std::endl;
//    int counter_3 = 0;
//    for (int i = 0; i < counter; i++) {
//        int max = temp_lines[i][0], min = temp_lines[i][1];
//        if (max < min) {
//            max = temp_lines[i][1];
//            min = temp_lines[i][0];
//        }
//        unsigned int hash = ((max * 6342) % hash_amount  + min); hash = hash %
//        hash_amount; if (hash_arr[hash][0] == -1 && hash_arr[hash][1] == -1) {
//            hash_arr[hash][0] = temp_lines[i][0];
//            hash_arr[hash][1] = temp_lines[i][1];
//            counter_3++;
//        } else {
//            if (hash_arr[hash][0] == temp_lines[i][0] && hash_arr[hash][1] ==
//            temp_lines[i][1]) {
//                continue;
//            } else if (hash_arr[hash][0] == temp_lines[i][1] &&
//            hash_arr[hash][1] == temp_lines[i][0]) {
//                continue;
//            } else {
//                while (hash_arr[hash][0] != -1 && hash_arr[hash][1] != -1) {
//                    hash++;
//                    hash %= hash_amount;
//                    if (hash_arr[hash][0] == temp_lines[i][0] &&
//                    hash_arr[hash][1] == temp_lines[i][1]) {
//                        break;
//                    } else if (hash_arr[hash][0] == temp_lines[i][1] &&
//                    hash_arr[hash][1] == temp_lines[i][0]) {
//                        break;
//                    } else if (hash_arr[hash][0] == -1 && hash_arr[hash][1] ==
//                    -1) {
//                        hash_arr[hash][0] = temp_lines[i][0];
//                        hash_arr[hash][1] = temp_lines[i][1];
//                        counter_3++; break;
//                    }
//                }
//            }
//        }
//    }
////    std::cout << "By by, you are out of
/// s21::Model::creat_hash_for_lines_number counter_3 = " << counter_3 <<
/// std::endl;
//}

// void s21::Model::print_str_from_file(char **strs_from_file, int str_number) {
//    printf("Hello, You are in print_str_from_file function\n");
//    for (int i = 0; i < str_number; i++) {
//        printf("%s", strs_from_file[i]);
//        printf("\n");
//    }
//    printf("\n");
//}

void s21::Model::ReadDotsFromStr(char **strs_from_file, int str_number,
                                    Figure_t *figure) {

  //    std::cout << "You are in s21::Model::ReadDotsFromStr function
  //    figure->normals_number = " << figure->dots_number << std::endl;
  setlocale(LC_ALL, "C");
  int counter = 0;
  for (int i = 0; i < str_number; i++) {
    char letter = 0;
    if (strs_from_file[i][0] == 'v' && strs_from_file[i][1] == ' ') {
      //                std::cout << "strs_from_file[" << i << "] = " <<
      //                strs_from_file[i] << std::endl;
      sscanf((const char *)strs_from_file[i], "%c%lf%lf%lf", &letter,
             &figure->dots[counter][0], &figure->dots[counter][1],
             &figure->dots[counter][2]);
      figure->dots[counter][3] = 1;
      counter++;
    }
  }
}

void s21::Model::ReadNormalsFromStr(char **strs_from_file, int str_number,
                                       Figure_t *figure) {
  //        std::cout << "You are in s21::Model::ReadNormalsFromStr function
  //        figure->normals_number = " << figure->normals_number << std::endl;
  setlocale(LC_ALL, "C");
  int counter = 0;
  for (int i = 0; i < str_number; i++) {
    char letter = 0, letter_2 = 0;
    if (strs_from_file[i][0] == 'v' && strs_from_file[i][1] == 'n' &&
        strs_from_file[i][2] == ' ') {
      //            std::cout << "strs_from_file[" << i << "] = " <<
      //            strs_from_file[i] << std::endl;
      sscanf((const char *)strs_from_file[i], "%c%c%lf%lf%lf", &letter,
             &letter_2, &figure->normals[counter][0],
             &figure->normals[counter][1], &figure->normals[counter][2]);
      figure->normals[counter][3] = 1;
      counter++;
    }
  }
  //    std::cout << "figure->normals_number = " << figure->normals_number << "
  //    conter = " << counter << std::endl;
}

void s21::Model::ReadPolygonsFromStrNew(char **strs_from_file,
                                            int str_number, Figure_t *figure,
                                            int *lines_lenths) {
  //    std::cout << "Hello, you are in s21::Model::ReadPolygonsFromStrNew"
  //    << std::endl;
  int triangles_counter = 0;
  figure->lines_number = 0;
  for (int i = 0; i < str_number; i++) {
    if (strs_from_file[i][0] == 'f' && strs_from_file[i][1] == ' ') {
      ReadPolygonsFromStrNewOneLine(strs_from_file, figure, lines_lenths,
                                          i, triangles_counter);
      triangles_counter++;
    }
  }
  figure->triangles_number = triangles_counter;
  //    print_figure(figure);
  //    std::cout << "By by, you are out of
  //    s21::Model::ReadPolygonsFromStrNew" << std::endl;
}

void s21::Model::ReadPolygonsFromStrNewOneLine(char **strs_from_file,
                                                     Figure_t *figure,
                                                     int *lines_lenths, int i,
                                                     int triangles_counter) {
  //    std::cout << "Hello, you are in
  //    s21::Model::ReadPolygonsFromStrNewOneLine" << std::endl;
  int *temp_line = new int[MAX_NUMBER_OF_DOTS_IN_POLYGON];
  for (int f = 0; f < MAX_NUMBER_OF_DOTS_IN_POLYGON; f++)
    temp_line[f] = -1;
  int temp_counter = 0;
  for (int j = 1; j < lines_lenths[i]; j++) {
    if (strs_from_file[i][j] >= '0' && strs_from_file[i][j] <= '9') {
      ReadPolygonsFromStrNewOneLineComplect(
          strs_from_file, temp_line, lines_lenths[i], &temp_counter, i, &j);
      j--;
    }
  }
  delete[] figure->triangles[triangles_counter];
  figure->triangles[triangles_counter] = new int[temp_counter + 1];
  for (int k = 0; k < temp_counter; k++)
    figure->triangles[triangles_counter][k] = temp_line[k] - 1;
  figure->triangles[triangles_counter][temp_counter] = -1;
  delete[] temp_line;
  figure->lines_number = figure->lines_number + temp_counter / 2;
  //    std::cout << "By by, you are out of
  //    s21::Model::ReadPolygonsFromStrNewOneLine   temp_counter = " <<
  //    temp_counter << std::endl;
}

void s21::Model::ReadPolygonsFromStrNewOneLineComplect(
    char **strs_from_file, int *temp_line, int max_lines_lenths, int *counter,
    int i, int *j) {
  //    std::cout << "Hello, you are in
  //    s21::Model::ReadPolygonsFromStrNewOneLineComplect
  //    max_lines_lenths = " << max_lines_lenths << std::endl;
  int slash_flag = 0, first_number = -1, second_number = -1;
  while (strs_from_file[i][*j] != ' ' || strs_from_file[i][*j] != '\0') {
    if (strs_from_file[i][*j] >= '0' && strs_from_file[i][*j] <= '9' &&
        first_number == -1) {
      first_number = ReadUnaryNumber(strs_from_file, i, j);
    } else if (strs_from_file[i][*j] >= '0' && strs_from_file[i][*j] <= '9' &&
               second_number == -1 && slash_flag == 2) {
      second_number = ReadUnaryNumber(strs_from_file, i, j);
    } else if (strs_from_file[i][*j] == '/') {
      slash_flag++;
      *j = *j + 1;
    } else if (strs_from_file[i][*j] == ' ' || strs_from_file[i][*j] == '\0') {
      break;
    } else {
      *j = *j + 1;
    }

    //        std::cout << "*j = " << *j << std::endl;
    if (*j >= max_lines_lenths)
      break;
  }
  if (second_number == -1)
    second_number = first_number;
  temp_line[*counter] = first_number;
  *counter = *counter + 1;
  temp_line[*counter] = second_number;
  *counter = *counter + 1;
  //    std::cout << "first_number = " << first_number << "   second_number = "
  //    << second_number << std::endl;
}

int s21::Model::ReadUnaryNumber(char **strs_from_file, int i, int *j) {
  //    std::cout << "Hello, you are in s21::Model::ReadUnaryNumber *j = " <<
  //    *j << std::endl;
  int temp_number = 0;
  while (strs_from_file[i][*j] >= '0' && strs_from_file[i][*j] <= '9') {
    temp_number = temp_number * 10 + strs_from_file[i][*j] - 48;
    *j = *j + 1;
  }
  //    std::cout << "temp_number = " << temp_number << std::endl;
  return temp_number;
}

// void s21::Model::read_polygons_from_str(char **strs_from_file, int
// str_number, Figure_t *figure, int *lines_lenths) {
////    std::cout << "Hello, you are in s21::Model::read_polygons_from_str" <<
/// std::endl;
//    int counter = 0;
//    for (int i = 0; i < str_number; i++) {
//        if (strs_from_file[i][0] == 'f' && strs_from_file[i][1] == ' ') {
//            int counter_of_dots = 0, flag = 0, temp_number = 0, slash_flag =
//            0; for (int j = 1; j < lines_lenths[i]; j++) {
//                if (flag == 0 && strs_from_file[i][j] == ' ') {
////                    std::cout << "step 1" << std::endl;
//                    slash_flag = 0;
//                }
//                if (strs_from_file[i][j] >= '0' && strs_from_file[i][j] <= '9'
//                && flag == 0 && slash_flag == 0) {
////                    std::cout << "step 2" << std::endl;
//                    figure->triangles[counter][counter_of_dots]
//                    =strs_from_file[i][j] - 48; temp_number =
//                    figure->triangles[counter][counter_of_dots] * 10; flag =
//                    1;
//                } else if (strs_from_file[i][j] >= '0' && strs_from_file[i][j]
//                <= '9' && flag == 1 && slash_flag == 0) {
////                    std::cout << "step 3" << std::endl;
//                    figure->triangles[counter][counter_of_dots] = temp_number
//                    + strs_from_file[i][j] - 48; temp_number =
//                    figure->triangles[counter][counter_of_dots] * 10;
//                } else if (strs_from_file[i][j] == '/' && flag == 1 &&
//                slash_flag == 0) {
////                    std::cout << "step 4" << std::endl;
//                    figure->triangles[counter][counter_of_dots] -= 1;
////                    std::cout << "figure->triangles[ " << counter << "][" <<
/// counter_of_dots << "] = " << figure->triangles[counter][counter_of_dots] <<
/// std::endl;
//                    counter_of_dots++;
//                    slash_flag = 1;
//                } else if (flag == 1 && slash_flag == 1 &&
//                (strs_from_file[i][j] >= '0' && strs_from_file[i][j] <= '9'))
//                {
////                    std::cout << "step 5" << std::endl;
//                    continue;
//                } else if (slash_flag == 1 && strs_from_file[i][j] == '/') {
////                    std::cout << "step 6" << std::endl;
//                    slash_flag = 2;
//                } else if (slash_flag == 1 && ( strs_from_file[i][j] == ' ' ||
//                strs_from_file[i][j] == '\0')){
//                    flag = 0;
//                    figure->triangles[counter][counter_of_dots] -= 1;
////                    std::cout << "figure->triangles[ " << counter << "][" <<
/// counter_of_dots << "] = " << figure->triangles[counter][counter_of_dots] <<
/// std::endl;
//                    counter_of_dots++;
//                    slash_flag = 0;
//                } else if (slash_flag == 2 && strs_from_file[i][j] >= '0' &&
//                strs_from_file[i][j] <= '9' && flag == 1) {
////                    std::cout << "step 7" << std::endl;
//                    figure->triangles[counter][counter_of_dots]
//                    =strs_from_file[i][j] - 48; temp_number =
//                    figure->triangles[counter][counter_of_dots] * 10; flag =
//                    2;
//                } else if (strs_from_file[i][j] >= '0' && strs_from_file[i][j]
//                <= '9' && flag == 2 && slash_flag == 2) {
////                    std::cout << "step 8" << std::endl;
//                    figure->triangles[counter][counter_of_dots] = temp_number
//                    + strs_from_file[i][j] - 48; temp_number =
//                    figure->triangles[counter][counter_of_dots] * 10;
//                } else if (flag == 2  && slash_flag == 2 && (
//                strs_from_file[i][j] == ' ' || strs_from_file[i][j] == '\0'))
//                {
////                    std::cout << "step 9" << std::endl;
//                    flag = 0;
//                    figure->triangles[counter][counter_of_dots] -= 1;
////                    std::cout << "figure->triangles[ " << counter << "][" <<
/// counter_of_dots << "] = " << figure->triangles[counter][counter_of_dots] <<
/// std::endl;
//                    counter_of_dots++;
//                    slash_flag = 0;
//                } else if (flag == 1  && slash_flag == 0 && (
//                strs_from_file[i][j] == ' ' || strs_from_file[i][j] == '\0'))
//                {
////                    std::cout << "step 10" << std::endl;
//                    flag = 0;
//                    figure->triangles[counter][counter_of_dots] -= 1;
////                    std::cout << "figure->triangles[ " << counter << "][" <<
/// counter_of_dots << "] = " << figure->triangles[counter][counter_of_dots] <<
/// std::endl;
//                    counter_of_dots++;
//                    figure->triangles[counter][counter_of_dots] =
//                    figure->triangles[counter][counter_of_dots - 1];
////                    std::cout << "figure->triangles[ " << counter << "][" <<
/// counter_of_dots << "] = " << figure->triangles[counter][counter_of_dots] <<
/// std::endl;
//                    counter_of_dots++;
//                }
//            }
//            counter++;
//        }
//    }
////    std::cout << "max_number_of_dot = " << max_number_of_dot << std::endl;
//    figure->triangles_number = counter;
//}

void s21::Model::ReadStrFromFile(FILE *obj_file, char **strs_from_file,
                                    int *str_number) {
  char letter;
  int counter = 0;
  while (!feof(obj_file)) {
    letter = fgetc(obj_file);
    if (letter == 10 || letter == EOF) {
      if (letter == EOF) {
        strs_from_file[*str_number][counter] = '\0';
      } else {
        strs_from_file[*str_number][counter] = '\0';
      }
      counter = 0;
      *str_number = *str_number + 1;
    } else {
      strs_from_file[*str_number][counter] = letter;
      counter++;
    }
  }
}

void s21::Model::ReadLineLenth(FILE *obj_file, int *line_lenths) {
  int counter = 0, line_counter = 0;
  char letter;
  while (!feof(obj_file)) {
    letter = fgetc(obj_file);
    if (letter == 10 || letter == EOF) {
      counter++;
      counter++;
      line_lenths[line_counter] = counter;
      counter = 0;
      line_counter++;
    } else {
      counter++;
    }
  }
}
