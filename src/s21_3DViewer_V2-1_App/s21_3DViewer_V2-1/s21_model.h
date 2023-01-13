#ifndef S21_MODEL_H_
#define S21_MODEL_H_

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "s21_matrix_oop.h"
#include <QVector3D>
#include <QVector>
#include <qopengl.h>

#define DOTS_IN_POLYGON 10
#define MAX_NUMBER_OF_DOTS_IN_POLYGON 200
#define LINE_LENTH 2000
#define TEMP_LINES_NUMBER 10
#define MAX_NUMBER_OF_DOTS 5000000
#define MAX_NUMBER_OF_TRIANGLES 10000000
#define MAX_NUMBER_OF_LINES 30000000
#define MAX_NUMBER_OF_NORMALS 5000000

namespace s21 {

class Model {
public:
  Model();
  void ReLoadData(const char file_name[]);
  const GLfloat *ConstData() const { return m_data.constData(); }
  const GLfloat *ConstDotData() const { return m_dot_data.constData(); }
  const GLfloat *ConstTriangleData() const {
    return m_triangles_data.constData();
  }
  const GLfloat *ConstTriangleGuroData() const {
    return m_triangles_guro_data.constData();
  }
  int Count() const { return m_count_; }
  int DotsCount() const { return m_dots_count_; }
  int TrianglesCount() const { return m_triangles_count_; }
  int TrianglesGuroCount() const { return m_triangles_guro_count_; }
  int LinesAmount() const { return m_count_ / 6; }
  int DotsAmount() const { return m_dots_count_ / 6; }
  int TrianglesAmount() const { return m_triangles_count_ / 6; }
  int TrianglesGuroAmount() const { return m_triangles_guro_count_ / 6; }
  int VertexsAmount() const { return vertexs_amount_; }
  int FacetsAmount() const { return facets_amount_; }
  void ModelMove(GLfloat xMove, GLfloat yMove, GLfloat zMove);

private:
  typedef struct Figure_struct {
    int dots_number;
    double **dots;
    int triangles_number;
    int **triangles;
    int lines_number;
    int **lines;
    double **normals;
    int normals_number;
  } Figure_t;
  void LoadFigure(Figure_t *figure);
  void LoadDots(Figure_t *figure);
  void LoadLines(Figure_t *figure);
  void LoadTriangles(Figure_t *figure);
  void LoadTrianglesGuro(Figure_t *figure);
  void InitFigure(Figure_t *figure);
  void CreatModel(Figure_t *figure);
//      void PrintFigure(Figure_t *figure);
  void RemoveFigure(Figure_t *figure);
  void CopyFigure(Figure_t *dist_figure, Figure_t *src_figure);
  void ResizeAndMoveFigure(Figure_t *figure);
  void MoveFigure(Figure_t *figure, double x, double y, double z);
  void ResizeFigure(Figure_t *figure, double x, double y, double z);
  void ConvertPolygonsToTriangles(Figure_t *figure);

  int ReadDataFromFile(const char file_name[], Figure_t *figure);
  void ReadNumberOfDotsAndFacetsFromStr(char **strs_from_file,
                                               int str_number,
                                               Figure_t *temp_figure);
  int NumberOfLinesFromFile(FILE *obj_file);
  void FindLinesFromPolygons(Figure_t *figure);
  //    void creat_hash_for_lines_number(int **temp_lines, int counter, int
  //    **hesh_arr, int hash_amount); void print_str_from_file(char
  //    **strs_from_file, int str_number);
  void ReadDotsFromStr(char **strs_from_file, int str_number,
                          Figure_t *figure);
  void ReadNormalsFromStr(char **strs_from_file, int str_number,
                             Figure_t *figure);
  //    void read_polygons_from_str(char **strs_from_file, int str_number,
  //    Figure_t *figure, int *lines_lenths);
  void ReadPolygonsFromStrNew(char **strs_from_file, int str_number,
                                  Figure_t *figure, int *lines_lenths);
  void ReadPolygonsFromStrNewOneLine(char **strs_from_file,
                                           Figure_t *figure, int *lines_lenths,
                                           int i, int triangles_counter);
  void ReadPolygonsFromStrNewOneLineComplect(char **strs_from_file,
                                                    int *temp_line,
                                                    int max_lines_lenths,
                                                    int *counter, int i,
                                                    int *j);
  int ReadUnaryNumber(char **strs_from_file, int i, int *j);
  void ReadStrFromFile(FILE *obj_file, char **strs_from_file,
                          int *str_number);
  void ReadLineLenth(FILE *obj_file, int *line_lenths);

  QVector<GLfloat> m_data, m_dot_data, m_triangles_data, m_triangles_guro_data;
  int m_count_;
  int m_dots_count_;
  int m_triangles_count_;
  int m_triangles_guro_count_;
  int vertexs_amount_;
  int facets_amount_;
  int triangles_amount_;
  int triangles_guro_amount_;
};

} // namespace s21

#endif // S21_MODEL_H_
