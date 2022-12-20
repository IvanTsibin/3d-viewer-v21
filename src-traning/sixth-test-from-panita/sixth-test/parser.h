#ifndef PARSER_H
#define PARSER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct matrix_s {
    double **matrix;
    int rows;
    int columns;
} matrix_t;

typedef struct facets_s {
    int *vert;              // массив номеров вершин
    int linked_vertexes;    // кол-во вершин необходимых для соединения
} facets_t;

typedef struct data_s {
    unsigned vertexes;      // кол-во вершин
    unsigned facets;        // кол-во полигонов
    unsigned edges;         // кол-во рёбер
    matrix_t *matrix_3d;
    facets_t *polygons;
} data_t;


matrix_t create_matrix(int rows, int columns);
matrix_t mult_matrix(matrix_t *A, matrix_t *B);
void remove_matrix(matrix_t *A);
void parse_file(data_t *data, FILE *file);
void free_data(data_t *data);
void rotation_by_ox(matrix_t *A, double angle);
void rotation_by_oy(matrix_t *A, double angle);
void rotation_by_oz(matrix_t *A, double angle);
void move_x(matrix_t *A, int a);
void move_y(matrix_t *A, int a);
void move_z(matrix_t *A, int a);

#endif  // PARSER_H
