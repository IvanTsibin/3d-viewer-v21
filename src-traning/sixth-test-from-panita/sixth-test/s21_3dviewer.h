#ifndef SRC_TRAINING_S21_3DVIEWER_H_
#define SRC_TRAINING_S21_3DVIEWER_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include "s21_matrix.h"

#define DOTS 100
#define TRIANGLES 1000
#define LINES 2000
#define S21_PI 3.1415926535

typedef struct figure_struct {
    int dots_number;
    double dots[DOTS][4];
    int triangles_number;
    int triangles[TRIANGLES][4];
    int lines_number;
    int lines[LINES][2];
} figure_t;

void init_figure(figure_t *figure);
void creat_cube(figure_t *figure);
void print_figure(figure_t *figure);
void copy_figure(figure_t *dist_figure, figure_t *src_figure);
matrix_t transform_matrix(double x, double y, double z);
matrix_t move_matrix(double x, double y, double z);
matrix_t resize_matrix(double x, double y, double z);
matrix_t rotation_matrix(double alfa);
matrix_t rotation_matrix(double betta);
matrix_t z_rotation_matrix(double gamma);
void copy_to_matrix(matrix_t *matrix, figure_t *figure, int number);
void copy_from_matrix(figure_t *figure, matrix_t *matrix, int number);
void copy_figure_to_matrix(matrix_t *matrix, figure_t *figure);
void copy_figure_from_matrix(figure_t *figure, matrix_t *matrix);
void transform_figure(figure_t *figure, double x, double y, double z);
void move_figure(figure_t *figure, double x, double y, double z);
void resize_figure(figure_t *figure, double x, double y, double z);
void rotate_figure(figure_t *figure, double alfa, double betta, double gamma);


#ifdef __cplusplus
}
#endif

#endif  // SRC_TRAINING_S21_3DVIEWER_H_
