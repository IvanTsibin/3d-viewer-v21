#ifndef MODEL_H
#define MODEL_H

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

#include <qopengl.h>
#include <QVector>
#include <QVector3D>
#include "s21_matrix_oop.h"

#define DOTS_IN_POLYGON 200
#define LINE_LENTH 2000
#define TEMP_LINES_NUMBER 5

class Model
{
public:
    Model();
    void reLoadData(const char file_name[]);
    const GLfloat *constData() const { return m_data.constData(); }
    const GLfloat *constDotData() const { return m_dot_data.constData(); }
    const GLfloat *constTriangleData() const { return m_triangles_data.constData(); }
    int count() const { return m_count; }
    int dotsCount() const {return m_dots_count;}
    int trianglesCount() const {return m_triangles_count;}
    int linesAmount() const { return m_count / 6;}
    int dotsAmount() const {return m_dots_count / 6;}

    int vertexsAmount() const {return vertexs_amount;}
    int facetsAmount() const {return facets_amount;}
    int trianglesAmount() const {return triangles_amount;}
    void modelMove(GLfloat xMove, GLfloat yMove, GLfloat zMove);

private:
    typedef struct figure_struct {
        int dots_number;
        double **dots;
        int triangles_number;
        int **triangles;
        int lines_number;
        int **lines;
    } figure_t;
    void init_figure(figure_t *figure);
    void creat_model(figure_t *figure);
    void print_figure(figure_t *figure);
    void remove_figure(figure_t *figure);
    void copy_figure(figure_t *dist_figure, figure_t *src_figure);
    void resize_and_move_figure(figure_t *figure);
    void move_figure(figure_t *figure, double x, double y, double z);
    void resize_figure(figure_t *figure, double x, double y, double z);
    void convert_poligons_to_triangles(figure_t *figure);



    int read_data_from_file(const char file_name[], figure_t *figure);
    void read_number_of_dots_and_facets_from_str(char **strs_from_file, int str_number, figure_t *temp_figure);
    int number_of_lines_from_file(FILE *obj_file);
    void find_lines_number(figure_t *figure);
    void creat_hash_for_lines_number(int **temp_lines, int counter, int **hesh_arr, int hash_amount);
    void print_str_from_file(char **strs_from_file, int str_number);
    void read_dots_from_str(char **strs_from_file, int str_number, figure_t *figure);
    double convert_str_to_double(char number[], int counter);
    void read_polygons_from_str(char **strs_from_file, int str_number, figure_t *figure, int *lines_lenths);
    void read_str_from_file(FILE *obj_file, char **strs_from_file, int *str_number);
    void read_line_lenth(FILE *obj_file, int *line_lenths);



    QVector<GLfloat> m_data, m_dot_data, m_triangles_data;
    int m_count;
    int m_dots_count;
    int m_triangles_count;
    int vertexs_amount;
    int facets_amount;
    int triangles_amount;
};

#endif // MODEL_H
