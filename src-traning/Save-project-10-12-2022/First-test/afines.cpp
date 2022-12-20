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
    std::cout << "move_matrix Let's print this on start" << std::endl;
    this->print();
    for (int i = 0; i < temp.rows_given(); ++i) {
        temp.matrix[i][i] = 1;
    }
    temp.matrix[0][3] = x_move;
    temp.matrix[1][3] = y_move;
    temp.matrix[2][3] = z_move;
    std::cout << "Let's print temp" << std::endl;
    temp.print();
    this->mul_matrix((const S21Matrix)temp);
    std::cout << "Let's print this at the end" << std::endl;
    this->print();
}

void afines::rotate_matrix(double x_rot, double y_rot, double z_rot) {
    std::cout << "rotate matrix - Let's print this on start" << std::endl;
    this->print();
    this->x_rotate_matrix(x_rot);
    this->y_rotate_matrix(y_rot);
    this->z_rotate_matrix(z_rot);
    std::cout << "at the end - Let's print this matrix" << std::endl;
    this->print();
}

void afines::x_rotate_matrix(double x_rot) {
    S21Matrix temp = S21Matrix(4,4);
    std::cout << "x_rotate_matrix Let's print this on start" << std::endl;
    this->print();
    double alfa = (x_rot * S21_PI) / 180;
    temp.matrix[0][0] = 1;
    temp.matrix[1][1] = cos(alfa);
    temp.matrix[1][2] = sin(alfa);
    temp.matrix[2][2] = cos(alfa);
    temp.matrix[2][1] = -sin(alfa);
    temp.matrix[3][3] = 1;
    this->mul_matrix((const S21Matrix)temp);
    std::cout << "Let's print this at the end" << std::endl;
    this->print();
}

void afines::y_rotate_matrix(double y_rot) {
    S21Matrix temp = S21Matrix(4,4);
    std::cout << "y_rotate_matrix Let's print this on start" << std::endl;
    this->print();
    double betta = (y_rot * S21_PI) / 180;
    temp.matrix[0][0] = cos(betta);
    temp.matrix[1][1] = 1;
    temp.matrix[0][2] = -1 * sin(betta);
    temp.matrix[2][2] = cos(betta);
    temp.matrix[2][0] = sin(betta);
    temp.matrix[3][3] = 1;
    this->mul_matrix((const S21Matrix)temp);
    std::cout << "Let's print this at the end" << std::endl;
    this->print();
}

void afines::z_rotate_matrix(double z_rot) {
    S21Matrix temp = S21Matrix(4,4);
    std::cout << "z_rotate_matrix Let's print this on start" << std::endl;
    this->print();
    double gamma = (z_rot * S21_PI) / 180;
    temp.matrix[0][0] = cos(gamma);
    temp.matrix[1][1] = cos(gamma);
    temp.matrix[0][1] = sin(gamma);
    temp.matrix[2][2] = 1;
    temp.matrix[1][0] = -1 * sin(gamma);
    temp.matrix[3][3] = 1;
    this->mul_matrix((const S21Matrix)temp);
    std::cout << "Let's print this at the end" << std::endl;
    this->print();
}

void afines::resize_matrix(double coeff) {
    S21Matrix temp = S21Matrix(4,4);
    std::cout << "resize_matrix Let's print this on start" << std::endl;
    this->print();
    for (int i = 0; i < temp.rows_given() - 1; ++i) {
        temp.matrix[i][i] = coeff;
    }
    temp.matrix[3][3] = 1;
    this->mul_matrix((const S21Matrix)temp);
    std::cout << "Let's print this at the end" << std::endl;
    this->print();
}

void afines::project_matrix(double first, double second,double third, double fourth) {
    S21Matrix temp = S21Matrix(4,4);
//    std::cout << "project_matrix Let's print this on start" << std::endl;
//    this->print();
    for (int i = 0; i < temp.rows_given(); ++i) {
        temp.matrix[i][i] = 1;
    }
    temp.matrix[0][0] = 2.12016;
    temp.matrix[1][1] = 2.41421;
    temp.matrix[2][2] = -1.0002;
    temp.matrix[2][3] = -0.02002;
    temp.matrix[3][0] = first;
    temp.matrix[3][1] = second;
    temp.matrix[3][2] = third;
    temp.matrix[3][3] = fourth;
//    std::cout << "Let's print temp" << std::endl;
//    temp.print();
    this->mul_matrix((const S21Matrix)temp);
    std::cout << "Let's print project_matrix at the end" << std::endl;
    this->print();
}
