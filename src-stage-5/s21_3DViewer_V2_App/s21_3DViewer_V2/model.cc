#include "model.h"
#include <qmath.h>
#include <iostream>

Model::Model()
    : m_count(0)
{
    figure_t figure;
    creat_model(&figure);
    loadFigure(&figure);
    remove_figure(&figure);
}

void Model::reLoadData(const char file_name[]) {
    figure_t temp_figure;
    std::cout << "ReLoad Step - 1" << std::endl;
    read_data_from_file(file_name, &temp_figure);
    std::cout << "ReLoad Step - 2" << std::endl;
    loadFigure(&temp_figure);
    std::cout << "ReLoad Step - 3" << std::endl;
    remove_figure(&temp_figure);
    std::cout << "ReLoad Step - 4" << std::endl;
}

void Model::loadFigure(figure_t *figure) {
    vertexs_amount = figure->dots_number;
    facets_amount = figure->triangles_number;
    triangles_amount = figure->triangles_number;
    std::cout << "LoadFigure Step - 2 - 1" << std::endl;
    print_figure(figure);
    convert_poligons_to_triangles(figure);
    std::cout << "LoadFigure Step - 2 - 2" << std::endl;
    print_figure(figure);
    resize_and_move_figure(figure);
    std::cout << "LoadFigure Step - 3" << std::endl;
    loadDots(figure);
    loadLines(figure);
    loadTriangles(figure);
    std::cout << "LoadFigure Step - 4" << std::endl;
}

void Model::loadDots(figure_t *figure) {
    m_dots_count = 0;
    m_dot_data.resize(figure->dots_number * 6);
    GLfloat *g = m_dot_data.data();
    for (int i = 0; i < figure->dots_number; i++) {
            *g++ = figure->dots[i][0];
            *g++ = (-1) * figure->dots[i][1];
            *g++ = figure->dots[i][2];
            *g++ = 0; *g++ = 0; *g++ = 1;
            m_dots_count += 6;
    }
//    for (int i = 0; i < m_dots_count; i++) {
//        std::cout << "m_dot_data[" << i << "] = " << m_dot_data[i] << std::endl;
//    }
    std::cout << "LoadDots Step m_dots_count = " << m_dots_count << std::endl;
}
void Model::loadLines(figure_t *figure) {
    m_count = 0;
    m_data.resize(2 * figure->lines_number * 6);
    GLfloat *p = m_data.data();
    for (int i = 0; i < figure->lines_number; i++) {
        for (int j = 0; j < 2; j++) {
            *p++ = figure->dots[figure->lines[i][j]][0];
            *p++ = (-1) * figure->dots[figure->lines[i][j]][1];
            *p++ = figure->dots[figure->lines[i][j]][2];
            *p++ = 0; *p++ = 0; *p++ = 1;
            m_count += 6;
        }
    }
//    for (int i = 0; i < m_count; i++) {
//        std::cout << "m_data[" << i << "] = " << m_data[i] << std::endl;
//    }
    std::cout << "LoadLines m_count = " << m_count << std::endl;
}
void Model::loadTriangles(figure_t *figure) {
    m_triangles_count = 0;
    m_triangles_data.resize(2 * 3 * figure->triangles_number * 6);
    GLfloat *k = m_triangles_data.data();
    QVector3D normal;
    double x1, y1, z1, x2, y2, z2;
    for (int i = 0; i < figure->triangles_number; i++) {
//    for (int i = 0; i < 2; i++) {
        x1 = figure->dots[figure->triangles[i][2]][0] - figure->dots[figure->triangles[i][0]][0];
        y1 = figure->dots[figure->triangles[i][2]][1] - figure->dots[figure->triangles[i][0]][1];
        z1 = figure->dots[figure->triangles[i][2]][2] - figure->dots[figure->triangles[i][0]][2];
        x2 = figure->dots[figure->triangles[i][1]][0] - figure->dots[figure->triangles[i][0]][0];
        y2 = figure->dots[figure->triangles[i][1]][1] - figure->dots[figure->triangles[i][0]][1];
        z2 = figure->dots[figure->triangles[i][1]][2] - figure->dots[figure->triangles[i][0]][2];

        normal = QVector3D::normal(QVector3D(x2, y2, z2), QVector3D(x1, y1, z1));
        for (int j = 2; j > -1; j--) {
            *k++ = figure->dots[figure->triangles[i][j]][0];
            *k++ = (-1) * figure->dots[figure->triangles[i][j]][1];
            *k++ = figure->dots[figure->triangles[i][j]][2];
            *k++ = normal.x(); *k++ = - normal.y(); *k++ = normal.z();
            m_triangles_count += 6;
        }
        for (int j = 0; j < 3; j++) {
            *k++ = figure->dots[figure->triangles[i][j]][0];
            *k++ = (-1) * figure->dots[figure->triangles[i][j]][1];
            *k++ = figure->dots[figure->triangles[i][j]][2];
            *k++ = - normal.x(); *k++ = normal.y(); *k++ = - normal.z();
            m_triangles_count += 6;
        }
    }
    for (int i = 0; i < m_triangles_count; i++) {
        std::cout << "m_triangles_data[" << i << "] = " << m_triangles_data[i] << std::endl;
    }
    std::cout << "LoadTriangles m_triangles_count = " << m_triangles_count << std::endl;
}

void Model::modelMove(GLfloat xMove, GLfloat yMove, GLfloat zMove) {
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
    GLfloat *k = m_triangles_data.data();
    for (int i = 0; i < m_triangles_count; i += 6) {
        *k = *k + xMove; *k++;
        *k = *k + yMove; *k++;
        *k = *k + zMove; *k++;
        *k++; *k++; *k++;
    }
}

void Model::init_figure(figure_t *figure) {
    if (figure->dots_number > 1500000) figure->dots_number = 1500000;
    if (figure->dots_number < 0) figure->dots_number = 1;
    figure->dots = new double*[figure->dots_number];
    for (int i = 0; i < figure->dots_number; i++) {
        figure->dots[i] = new double[4];
        figure->dots[i][0] = 0;
        figure->dots[i][1] = 0;
        figure->dots[i][2] = 0;
        figure->dots[i][3] = 1;
    }
    if (figure->triangles_number > 4000000) figure->triangles_number = 4000000;
    if (figure->triangles_number < 0) figure->triangles_number = 1;
    figure->triangles = new int*[figure->triangles_number];
    for (int i = 0; i < figure->triangles_number; i++) {
        figure->triangles[i] = new int[200];
        for (int j = 0; j < DOTS_IN_POLYGON; j++) {
            figure->triangles[i][j] = -1;
        }
    }
    if (figure->lines_number > 12000000) figure->lines_number = 12000000;
    if (figure->lines_number < 0) figure->lines_number = 1;
    figure->lines = new int*[figure->lines_number];
    for (int i = 0; i < figure->lines_number; i++) {
        figure->lines[i] = new int[2];
        figure->lines[i][0] = 0;
        figure->lines[i][1] = 0;
    }
}

void Model::creat_model(figure_t *figure) {
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

void Model::remove_figure(figure_t *figure) {
//    std::cout << "remove_figure Stage - 1" << std::endl;
    if (figure->dots_number != 0) {
        for (int i = 0; i < figure->dots_number; i++) {
//            free(figure->dots[i]);
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
//             std::cout << "figure->lines_number = " << figure->lines_number << " line i = " << i << std::endl;
        }
        delete[] figure->lines;
    } else {
        figure->lines_number = 0;
    }
//    std::cout << "remove_figure Stage - 4" << std::endl;
}

void Model::print_figure(figure_t *figure) {
    for (int i = 0; i < figure->dots_number; i++) {
        printf("figure->dots[%2d][0] = %+4.0f", i, figure->dots[i][0]);
        printf("  figure->dots[%2d][1] = %+4.0f", i, figure->dots[i][1]);
        printf("  figure->dots[%2d][2] = %+4.0f\n", i, figure->dots[i][2]);
    }

    for (int i = 0; i < figure->triangles_number; i++) {
        printf("fig->trg[%2d][0] = %2d", i, figure->triangles[i][0]);
        printf("  fig->trg[%2d][1] = %2d", i, figure->triangles[i][1]);
        printf("  fig->trig[%2d][2] = %2d", i, figure->triangles[i][2]);
        printf("  fig->trig[%2d][3] = %2d\n", i, figure->triangles[i][3]);
    }
    printf("\n");
    for (int i = 0; i < figure->lines_number; i++) {
        printf("figure->lines[%2d][0] = %2d", i, figure->lines[i][0]);
        printf("  figure->lines[%2d][1] = %2d\n", i, figure->lines[i][1]);
    }
    printf("figure->dots_number %d\n", figure->dots_number);
    printf("figure->triangles_number %d\n", figure->triangles_number);
    printf("figure->lines_number %d\n", figure->lines_number);
}

void Model::copy_figure(figure_t *dist_figure, figure_t *src_figure) {
    dist_figure->dots_number = src_figure->dots_number;
    dist_figure->triangles_number = src_figure->triangles_number;
    dist_figure->lines_number = src_figure->lines_number;
    init_figure(dist_figure);
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
    }
    for (int i = 0; i < src_figure->lines_number; i++) {
        dist_figure->lines[i][0] = src_figure->lines[i][0];
        dist_figure->lines[i][1] = src_figure->lines[i][1];
    }
}


void Model::resize_and_move_figure(figure_t *temp_figure) {
    double x_max = temp_figure->dots[0][0], x_min = temp_figure->dots[0][0];
    double y_max = temp_figure->dots[0][1], y_min = temp_figure->dots[0][1];
    double z_max = temp_figure->dots[0][2], z_min = temp_figure->dots[0][2];
    for (int i = 1; i < temp_figure->dots_number; i++) {
        if (temp_figure->dots[i][0] > x_max) x_max = temp_figure->dots[i][0];
        if (temp_figure->dots[i][0] < x_min) x_min = temp_figure->dots[i][0];
        if (temp_figure->dots[i][1] > y_max) y_max = temp_figure->dots[i][1];
        if (temp_figure->dots[i][1] < y_min) y_min = temp_figure->dots[i][1];
        if (temp_figure->dots[i][2] > z_max) z_max = temp_figure->dots[i][2];
        if (temp_figure->dots[i][2] < z_min) z_min = temp_figure->dots[i][2];
    }
    double max_size = x_max - x_min, y_size = y_max - y_min;
    if (max_size < y_size) max_size = y_size;
    double z_size = z_max - z_min;
    if (max_size < z_size) max_size = z_size;
    double size_coeff = 0.5/max_size;
    move_figure(temp_figure, -1 * (x_min + (x_max - x_min) / 2), -1 * (y_min + (y_max - y_min) / 2), -1 * (z_min + (z_max - z_min) / 2));
    resize_figure(temp_figure, size_coeff, size_coeff, size_coeff);
}

void Model::move_figure(figure_t *figure, double x, double y, double z) {
    for (int i = 0; i < figure->dots_number; i++) {
        figure->dots[i][0] = figure->dots[i][0] + x;
        figure->dots[i][1] = figure->dots[i][1] + y;
        figure->dots[i][2] = figure->dots[i][2] + z;
    }
}

void Model::resize_figure(figure_t *figure, double x, double y, double z) {
    for (int i = 0; i < figure->dots_number; i++) {
        figure->dots[i][0] = figure->dots[i][0] * x;
        figure->dots[i][1] = figure->dots[i][1] * y;
        figure->dots[i][2] = figure->dots[i][2] * z;
    }
}

int Model::read_data_from_file(const char file_name[], figure_t *figure) {
//    std::cout << "Step - 1" << std::endl;
    FILE *obj_file;
    figure->dots_number = 0; figure->lines_number = 0; figure->triangles_number = 0;
    int error = 0, str_number = 0;
    if ((obj_file = fopen(file_name, "r")) == NULL) {
        error = 1;
    } else {
        figure_t temp_figure;
        int lines_number = number_of_lines_from_file(obj_file);
        fclose(obj_file);
        obj_file = NULL;
        obj_file = fopen(file_name, "r");
        int *lines_lenths;
        lines_lenths = new int[lines_number];
        read_line_lenth(obj_file, lines_lenths);
        fclose(obj_file);
        obj_file = NULL;
        char **strs_from_file = NULL;
        strs_from_file = new char*[lines_number];
        for (int i = 0; i < lines_number; i++) {
            strs_from_file[i] = new char[lines_lenths[i]];
            for (int j = 0; j < lines_lenths[i]; j++) strs_from_file[i][j] = '\0';
        }
        obj_file = fopen(file_name, "r");
        read_str_from_file(obj_file, strs_from_file, &str_number);
//        std::cout << "Step - 2" << std::endl;
        fclose(obj_file);
        read_number_of_dots_and_facets_from_str(strs_from_file, str_number, &temp_figure);
        temp_figure.lines_number = temp_figure.triangles_number * 5;
        int temp_lines_amount = temp_figure.lines_number;
        init_figure(&temp_figure);
//        print_figure(&temp_figure);
        read_dots_from_str(strs_from_file, lines_number, &temp_figure);
//        std::cout << "Step - 3" << std::endl;
        read_polygons_from_str(strs_from_file, lines_number, &temp_figure, lines_lenths);
//        std::cout << "Step - 4" << std::endl;
        delete[] lines_lenths;
        for (int i = 0; i < lines_number; i++) delete[] strs_from_file[i];
        delete[] strs_from_file;
        find_lines_number(&temp_figure);
//        print_figure(&temp_figure);
//        std::cout << "Step - 5" << std::endl;
        copy_figure(figure, &temp_figure);
//        print_figure(figure);
//        std::cout << "Step - 6" << std::endl;
        temp_figure.lines_number = temp_lines_amount;
        remove_figure(&temp_figure);
//        std::cout << "Step - 7" << std::endl;
    }
    return error;
}

void Model::read_number_of_dots_and_facets_from_str(char **strs_from_file, int str_number, figure_t *figure) {
    figure->dots_number = 0;
    figure->triangles_number = 0;
    for (int i = 0; i < str_number; i++) {
        if (strs_from_file[i][0] == 'v' && strs_from_file[i][1] == ' ' ) figure->dots_number += 1;
        if (strs_from_file[i][0] == 'f' && strs_from_file[i][1] == ' ' ) figure->triangles_number += 1;
    }
}

int Model::number_of_lines_from_file(FILE *obj_file) {
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

void Model::convert_poligons_to_triangles(figure_t *figure) {
    int **temp_triangles;
    temp_triangles = new int*[figure->triangles_number * TEMP_LINES_NUMBER];
    int counter = 0;
    for (int i = 0; i < figure->triangles_number * TEMP_LINES_NUMBER; i++) {
        temp_triangles[i] = new int[4]; temp_triangles[i][0] = -1; temp_triangles[i][1] = -1;temp_triangles[i][2] = -1;temp_triangles[i][3] = -1;
        }
    for (int i = 0; i < figure->triangles_number; i++) {
        temp_triangles[counter][0] = figure->triangles[i][0];
        temp_triangles[counter][1] = figure->triangles[i][1];
        temp_triangles[counter][2] = figure->triangles[i][2];
        counter++;
        int temp_counter = 3;
        while (figure->triangles[i][temp_counter] != -1) {
            temp_triangles[counter][0] = figure->triangles[i][0];
            temp_triangles[counter][1] = figure->triangles[i][temp_counter - 1];
            temp_triangles[counter][2] = figure->triangles[i][temp_counter];
            temp_counter++;
            counter++;
        }
    }
    for (int i = 0; i < figure->triangles_number; i++) delete[] figure->triangles[i];
    delete[] figure->triangles;
    figure->triangles_number = counter;
    figure->triangles = new int*[counter];
    for (int i =0; i < counter; i++) {
        figure->triangles[i] = new int[4];
        figure->triangles[i][0] = temp_triangles[i][0];
        figure->triangles[i][1] = temp_triangles[i][1];
        figure->triangles[i][2] = temp_triangles[i][2];
        figure->triangles[i][3] = -1;
        delete[] temp_triangles[i];
    }
    delete[] temp_triangles;
}

void Model::find_lines_number(figure_t *figure) {
    int counter = 0, counter_2 = 0, hash_amount = figure->triangles_number * TEMP_LINES_NUMBER * 2;
    int **temp_lines, **hash_arr;
    temp_lines = new int*[figure->triangles_number * TEMP_LINES_NUMBER];
    for (int i = 0; i < figure->triangles_number * TEMP_LINES_NUMBER; i++) {
        temp_lines[i] = new int[2]; temp_lines[i][0] = -1; temp_lines[i][1] = -1;
        }
    for (int i = 0; i < figure->triangles_number; i++) {
        int dots_counter = 1;
        while (figure->triangles[i][dots_counter] != -1) {
            temp_lines[counter][0] = figure->triangles[i][dots_counter - 1];
            temp_lines[counter][1] = figure->triangles[i][dots_counter];
            counter++;
            dots_counter++;
        }
        if (figure->triangles[i][dots_counter] == -1) {
            temp_lines[counter][0] = figure->triangles[i][0];
            temp_lines[counter][1] = figure->triangles[i][dots_counter - 1];
            counter++;
        }
    }
    hash_arr = new int*[hash_amount];
    for (int i = 0; i < hash_amount; i++) {
        hash_arr[i] = new int[2]; hash_arr[i][0] = -1; hash_arr[i][1] = -1;
    }
    creat_hash_for_lines_number(temp_lines, counter, hash_arr, hash_amount);
    for (int i = 0; i < hash_amount; i++) {
        if (hash_arr[i][0] != -1 && hash_arr[i][1] != -1) {
            figure->lines[counter_2][0] = hash_arr[i][0];
            figure->lines[counter_2][1] = hash_arr[i][1];
            counter_2++;
        }
    }
    figure->lines_number = counter_2;
//    std::cout << "counter_2 = " << counter_2 << std::endl;
    for (int i = 0; i < figure->triangles_number * TEMP_LINES_NUMBER; i++) {
        delete[] temp_lines[i];
    }
     delete[] temp_lines;
    for (int i = 0; i < hash_amount; i++) {
        delete[] hash_arr[i];
    }
    delete[] hash_arr;
}

void Model::creat_hash_for_lines_number(int **temp_lines, int counter, int **hash_arr, int hash_amount) {
    int counter_3 = 0;
    for (int i = 0; i < counter; i++) {
        int max = temp_lines[i][0], min = temp_lines[i][1];
        if (max < min) {
            max = temp_lines[i][1];
            min = temp_lines[i][0];
        }
        unsigned int hash = ((max * 6342) % hash_amount  + min); hash = hash % hash_amount;
        if (hash_arr[hash][0] == -1 && hash_arr[hash][1] == -1) {
            hash_arr[hash][0] = temp_lines[i][0];
            hash_arr[hash][1] = temp_lines[i][1];
            counter_3++;
        } else {
            if (hash_arr[hash][0] == temp_lines[i][0] && hash_arr[hash][1] == temp_lines[i][1]) {
                continue;
            } else if (hash_arr[hash][0] == temp_lines[i][1] && hash_arr[hash][1] == temp_lines[i][0]) {
                continue;
            } else {
                while (hash_arr[hash][0] != -1 && hash_arr[hash][1] != -1) {
                    hash++;
//                    hash %= hash_amount;
                    if (hash_arr[hash][0] == temp_lines[i][0] && hash_arr[hash][1] == temp_lines[i][1]) {
                        break;
                    } else if (hash_arr[hash][0] == temp_lines[i][1] && hash_arr[hash][1] == temp_lines[i][0]) {
                        break;
                    } else if (hash_arr[hash][0] == -1 && hash_arr[hash][1] == -1) {
                        hash_arr[hash][0] = temp_lines[i][0];
                        hash_arr[hash][1] = temp_lines[i][1];
                        counter_3++; break;
                    }
                }
            }
        }
    }
}

void Model::print_str_from_file(char **strs_from_file, int str_number) {
    printf("Hello, You are in print_str_from_file function\n");
    for (int i = 0; i < str_number; i++) {
        printf("%s", strs_from_file[i]);
        printf("\n");
    }
    printf("\n");
}

void Model::read_dots_from_str(char **strs_from_file, int str_number, figure_t *figure) {
    int counter = 0;
        for (int i = 0; i < str_number; i++) {
            char letter = 0, str1[20], str2[20], str3[20];
            for (int j = 0; j < 20; j++) {
                str1[j] = '\0';
                str1[j] = '\0';
                str1[j] = '\0';
            }
            if (strs_from_file[i][0] == 'v' && strs_from_file[i][1] == ' ') {
                sscanf((const char *)strs_from_file[i], "%c%s%s%s", &letter, str1, str2, str3);
                figure->dots[counter][0] = convert_str_to_double(str1, strlen(str1));
                figure->dots[counter][1] = convert_str_to_double(str2, strlen(str2));
                figure->dots[counter][2] = convert_str_to_double(str3, strlen(str3));

                figure->dots[counter][3] = 1;
                counter++;
            }
    }
    figure->dots_number = counter;
}

double Model::convert_str_to_double(char number[], int counter) {
    int before_dot_flag = 1, devider = 10, add = 0;
    double multiplyer = 1, rezult;
    if (number[0] == '-') {
        multiplyer = -1;
        rezult = (double)(number[1] - 48);
        add = 1;
    } else {
        rezult = (double)(number[0] - 48);
    }
    for (int i = 1 + add; i < counter; i++) {
        if (number[i] == '.' || number[i] == ',') {
            before_dot_flag = 0;
            continue;
        }
        if (before_dot_flag == 1) {
            rezult = rezult*10 + (double) (number[i] - 48);
        } else {
            rezult = rezult + ((double)(number[i] - 48))/devider;
            devider *= 10;
        }
    }
    rezult *= multiplyer;
    return rezult;
}


void Model::read_polygons_from_str(char **strs_from_file, int str_number, figure_t *figure, int *lines_lenths) {
    int counter = 0, calloc_flag = 0;
    for (int i = 0; i < str_number; i++) {
        if (strs_from_file[i][0] == 'f' && strs_from_file[i][1] == ' ') {
            int counter_of_dots = 0, flag = 0, temp_number = 0, slash_flag = 0;
            for (int j = 1; j < lines_lenths[i]; j++) {
                if (counter_of_dots == DOTS_IN_POLYGON && calloc_flag == 0) {
                    free(figure->triangles[counter]);
                    delete[] figure->triangles[counter];
                    figure->triangles[counter] = new int [200];
                    for (int k = 0; k < 200; k++) figure->triangles[counter][k] = -1;
                    calloc_flag = 1;
                    i--;
                    counter--;
                    break;
                }
                if (flag == 0 && strs_from_file[i][j] == ' ') {
                    slash_flag = 0;
                }
                if (strs_from_file[i][j] >= '0' && strs_from_file[i][j] <= '9' && flag == 0 && slash_flag == 0) {
                    figure->triangles[counter][counter_of_dots] =strs_from_file[i][j] - 48;
                    temp_number = figure->triangles[counter][counter_of_dots] * 10;
                    flag = 1;
                } else if (strs_from_file[i][j] >= '0' && strs_from_file[i][j] <= '9' && flag == 1 && slash_flag == 0) {
                    figure->triangles[counter][counter_of_dots] = temp_number + strs_from_file[i][j] - 48;
                    temp_number = figure->triangles[counter][counter_of_dots] * 10;
                } else if (strs_from_file[i][j] == '/' && flag == 1 && slash_flag == 0) {
                    slash_flag = 1;
                } else if (flag == 1 && (slash_flag == 1 || strs_from_file[i][j] >= ' ' || strs_from_file[i][j] >= '\0')) {
                    flag = 0;
                    figure->triangles[counter][counter_of_dots] -= 1;
                    counter_of_dots++;
                    if (counter_of_dots > DOTS_IN_POLYGON && calloc_flag == 1) {
                        calloc_flag = 0;
                    }
                }
            }
            counter++;
        }
    }
    figure->triangles_number = counter;
}



void Model::read_str_from_file(FILE *obj_file, char **strs_from_file, int *str_number) {
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


void Model::read_line_lenth(FILE *obj_file, int *line_lenths) {
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
