#include "cube.h"
#include <qmath.h>
#include <iostream>

Cube::Cube()
    : m_count(0)
{
    m_data.resize(100 * 6);
    m_dot_data.resize(20 * 6);
    figure_t figure;
    creat_cube(&figure);
    GLfloat *p = m_data.data();
    for (int i = 0; i < figure.lines_number; i++) {
        for (int j = 0; j < 2; j++) {
            *p++ = figure.dots[figure.lines[i][j]][0];
            *p++ = figure.dots[figure.lines[i][j]][1];
            *p++ = figure.dots[figure.lines[i][j]][2];
            *p++ = 0; *p++ = 0; *p++ = 1;
            m_count += 6;
        }
    }
//    for (int i = 0; i < m_count; i++) {
//        std::cout << "m_data[" << i << "] = " << m_data[i] << std::endl;
//    }
    m_dots_count = 0;
    GLfloat *g = m_dot_data.data();
    for (int i = 0; i < figure.dots_number; i++) {
            *g++ = figure.dots[i][0];
            *g++ = figure.dots[i][1];
            *g++ = figure.dots[i][2];
            *g++ = 0; *g++ = 0; *g++ = 0;
            m_dots_count += 6;
    }
}

void Cube::cubeMove(GLfloat xMove, GLfloat yMove, GLfloat zMove) {
    GLfloat *p = m_data.data();
    for (int i = 0; i < m_count; i += 6) {
        *p = *p + xMove; *p++;
        *p = *p + yMove; *p++;
        *p = *p + zMove; *p++;
        *p++; *p++; *p++;
    }
    GLfloat *g = m_dot_data.data();
    for (int i = 0; i < m_dots_count; i += 6) {
        *g = *g + xMove; *g++;
        *g = *g + yMove; *g++;
        *g = *g + zMove; *g++;
        *g++; *g++; *g++;
    }
}

void Cube::init_figure(figure_t *figure) {
    if (figure->dots_number > 100) figure->dots_number = 100;
    if (figure->dots_number < 0) figure->dots_number = 1;
    figure->dots = (double **)calloc(figure->dots_number, sizeof(double*));
    for (int i = 0; i < figure->dots_number; i++) {
        figure->dots[i] = (double*)calloc(4, sizeof(double));
        figure->dots[i][0] = 0;
        figure->dots[i][1] = 0;
        figure->dots[i][2] = 0;
        figure->dots[i][3] = 1;
    }
    if (figure->triangles_number > 300) figure->triangles_number = 300;
    if (figure->triangles_number < 0) figure->triangles_number = 1;
    figure->triangles = (int **)calloc(figure->triangles_number, sizeof(int*));
    for (int i = 0; i < figure->triangles_number; i++) {
        figure->triangles[i] = (int*)calloc(200, sizeof(int));
        for (int j = 0; j < DOTS_IN_POLYGON; j++) {
            figure->triangles[i][j] = -1;
        }
    }
    if (figure->lines_number > 600) figure->lines_number = 600;
    if (figure->lines_number < 0) figure->lines_number = 1;
    figure->lines = (int **)calloc(figure->lines_number, sizeof(int*));
    for (int i = 0; i < figure->lines_number; i++) {
        figure->lines[i] = (int*)calloc(2, sizeof(int));
        figure->lines[i][0] = 0;
        figure->lines[i][1] = 0;
    }
}

void Cube::creat_cube(figure_t *figure) {
    figure->dots_number = 8;
    figure->triangles_number = 12;
    figure->lines_number = 18;
    init_figure(figure);
    figure->dots[0][0] = -0.2;figure->dots[0][1] = 0.2;figure->dots[0][2] = 0.2;
    figure->dots[1][0] = -0.2;figure->dots[1][1] = 0.2;figure->dots[1][2] = -0.2;
    figure->dots[2][0] = -0.2;figure->dots[2][1] = -0.2;figure->dots[2][2] = -0.2;
    figure->dots[3][0] = -0.2;figure->dots[3][1] = -0.2;figure->dots[3][2] = 0.2;
    figure->dots[4][0] = 0.2;figure->dots[4][1] = 0.2;figure->dots[4][2] = 0.2;
    figure->dots[5][0] = 0.2;figure->dots[5][1] = 0.2;figure->dots[5][2] = -0.2;
    figure->dots[6][0] = 0.2;figure->dots[6][1] = -0.2;figure->dots[6][2] = -0.2;
    figure->dots[7][0] = 0.2;figure->dots[7][1] = -0.2;figure->dots[7][2] = 0.2;
    figure->triangles[0][0] = 0;figure->triangles[0][1] = 1;figure->triangles[0][2] = 2;figure->triangles[0][3] = -1;
    figure->triangles[1][0] = 0;figure->triangles[1][1] = 2;figure->triangles[1][2] = 3;figure->triangles[1][3] = -1;
    figure->triangles[2][0] = 1;figure->triangles[2][1] = 2;figure->triangles[2][2] = 6;figure->triangles[2][3] = -1;
    figure->triangles[3][0] = 1;figure->triangles[3][1] = 6;figure->triangles[3][2] = 5;figure->triangles[3][3] = -1;
    figure->triangles[4][0] = 5;figure->triangles[4][1] = 6;figure->triangles[4][2] = 7;figure->triangles[4][3] = -1;
    figure->triangles[5][0] = 5;figure->triangles[5][1] = 7;figure->triangles[5][2] = 4;figure->triangles[5][3] = -1;
    figure->triangles[6][0] = 0;figure->triangles[6][1] = 4;figure->triangles[6][2] = 7;figure->triangles[6][3] = -1;
    figure->triangles[7][0] = 0;figure->triangles[7][1] = 7;figure->triangles[7][2] = 3;figure->triangles[7][3] = -1;
    figure->triangles[8][0] = 0;figure->triangles[8][1] = 1;figure->triangles[8][2] = 5;figure->triangles[8][3] = -1;
    figure->triangles[9][0] = 0;figure->triangles[9][1] = 5;figure->triangles[9][2] = 4;figure->triangles[9][3] = -1;
    figure->triangles[10][0] = 3;figure->triangles[10][1] = 2;figure->triangles[10][2] = 6;figure->triangles[10][3] = -1;
    figure->triangles[11][0] = 3;figure->triangles[11][1] = 6;figure->triangles[11][2] = 7;figure->triangles[11][3] = -1;
    figure->lines[0][0] = 0; figure->lines[0][1] = 1;
    figure->lines[1][0] = 1; figure->lines[1][1] = 2;
    figure->lines[2][0] = 2; figure->lines[2][1] = 3;
    figure->lines[3][0] = 3; figure->lines[3][1] = 0;
    figure->lines[4][0] = 0; figure->lines[4][1] = 2;
    figure->lines[5][0] = 4; figure->lines[5][1] = 5;
    figure->lines[6][0] = 5; figure->lines[6][1] = 6;
    figure->lines[7][0] = 6; figure->lines[7][1] = 7;
    figure->lines[8][0] = 7; figure->lines[8][1] = 4;
    figure->lines[9][0] = 4; figure->lines[9][1] = 6;
    figure->lines[10][0] = 0; figure->lines[10][1] = 4;
    figure->lines[11][0] = 1; figure->lines[11][1] = 5;
    figure->lines[12][0] = 2; figure->lines[12][1] = 6;
    figure->lines[13][0] = 3; figure->lines[13][1] = 7;
    figure->lines[14][0] = 0; figure->lines[14][1] = 5;
    figure->lines[15][0] = 1; figure->lines[15][1] = 6;
    figure->lines[16][0] = 2; figure->lines[16][1] = 7;
    figure->lines[17][0] = 3; figure->lines[17][1] = 4;
}



