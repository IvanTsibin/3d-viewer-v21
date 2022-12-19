

#include "afines.h"
#include <iostream>

afines::afines()
{

}

void afines::init_matrix(int rows, int columns) {
    this->setRows(rows);
    this->setColumns(columns);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            this->matrix[i][j] = 0;
        }
    }
}

void afines::set_unary() {
    if (this->rows_given() == this->collumns_given()) {
        for (int i = 0; i < this->rows_given(); i++) {
            this->matrix[i][i] = 1;
        }
    }
}

void afines::move_matrix(double x_move, double y_move, double z_move) {
    S21Matrix temp = S21Matrix(4,4);
    for (int i = 0; i < temp.rows_given(); ++i) {
        temp.matrix[i][i] = 1;
    }
    temp.matrix[0][3] = x_move;
    temp.matrix[1][3] = y_move;
    temp.matrix[2][3] = z_move;
    this->mul_matrix((const S21Matrix)temp);
}

void afines::rotate_matrix(double x_rot, double y_rot, double z_rot) {
    this->x_rotate_matrix(x_rot);
    this->y_rotate_matrix(y_rot);
    this->z_rotate_matrix(z_rot);
}

void afines::x_rotate_matrix(double x_rot) {
    S21Matrix temp = S21Matrix(4,4);
    double alfa = (x_rot * S21_PI) / 180;
    temp.matrix[0][0] = 1;
    temp.matrix[1][1] = cos(alfa);
    temp.matrix[1][2] = sin(alfa);
    temp.matrix[2][2] = cos(alfa);
    temp.matrix[2][1] = -sin(alfa);
    temp.matrix[3][3] = 1;
    this->mul_matrix((const S21Matrix)temp);
}

void afines::y_rotate_matrix(double y_rot) {
    S21Matrix temp = S21Matrix(4,4);
    double betta = (y_rot * S21_PI) / 180;
    temp.matrix[0][0] = cos(betta);
    temp.matrix[1][1] = 1;
    temp.matrix[0][2] = -1 * sin(betta);
    temp.matrix[2][2] = cos(betta);
    temp.matrix[2][0] = sin(betta);
    temp.matrix[3][3] = 1;
    this->mul_matrix((const S21Matrix)temp);
}

void afines::z_rotate_matrix(double z_rot) {
    S21Matrix temp = S21Matrix(4,4);
    double gamma = (z_rot * S21_PI) / 180;
    temp.matrix[0][0] = cos(gamma);
    temp.matrix[1][1] = cos(gamma);
    temp.matrix[0][1] = sin(gamma);
    temp.matrix[2][2] = 1;
    temp.matrix[1][0] = -1 * sin(gamma);
    temp.matrix[3][3] = 1;
    this->mul_matrix((const S21Matrix)temp);
}

void afines::resize_matrix(double coeff) {
    S21Matrix temp = S21Matrix(4,4);
    for (int i = 0; i < temp.rows_given() - 1; ++i) {
        temp.matrix[i][i] = coeff;
    }
    temp.matrix[3][3] = 1;
    this->mul_matrix((const S21Matrix)temp);
}

void afines::project_matrix(double angle, double aspect,double near_point, double far_point) {
    S21Matrix temp = S21Matrix(4,4);
    for (int i = 0; i < temp.rows_given(); ++i) {
        temp.matrix[i][i] = 1;
    }
    if (angle < 1.0) {
        temp.matrix[0][0] = 2.0 /  aspect;
        temp.matrix[1][1] = 2.0 ;
        temp.matrix[2][2] = - 1.0;
        temp.matrix[2][3] = - 1.0;
        temp.matrix[3][3] = 1;
    } else {
        temp.matrix[0][0] = 2.0 / (sin(angle) * aspect);
        temp.matrix[1][1] = 2.0 / sin(angle);
        temp.matrix[2][2] = -1.0 * (far_point - near_point) / 100.0;
        temp.matrix[2][3] = -near_point * 2;
        temp.matrix[3][0] = 0;
        temp.matrix[3][1] = 0;
        temp.matrix[3][2] = - 1;
        temp.matrix[3][3] = 0;
    }
    this->mul_matrix((const S21Matrix)temp);
}

QMatrix4x4 afines::convertToQMatrix4x4() {
    QMatrix4x4 matrix4x4(this->matrix[0][0],this->matrix[0][1],this->matrix[0][2],this->matrix[0][3],
        this->matrix[1][0],this->matrix[1][1],this->matrix[1][2],this->matrix[1][3],
        this->matrix[2][0],this->matrix[2][1],this->matrix[2][2],this->matrix[2][3],
        this->matrix[3][0],this->matrix[3][1],this->matrix[3][2],this->matrix[3][3]);
    return matrix4x4;
}
