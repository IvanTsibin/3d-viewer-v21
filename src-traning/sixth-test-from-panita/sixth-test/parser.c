#include "parser.h"

matrix_t create_matrix(int rows, int columns) {
    matrix_t matrix;
    matrix.rows = rows;
    matrix.columns = columns;
    matrix.matrix = (double **)malloc(rows * sizeof(double *));
    for (int i = 0; i < rows; i++) {
        matrix.matrix[i] = (double *)calloc(columns, sizeof(double));
    }
    return matrix;
}

void remove_matrix(matrix_t *A) {
    for (int i = 0; i < A->rows; i++) {
        free(A->matrix[i]);
    }
    free(A->matrix);
}

matrix_t mult_matrix(matrix_t *A, matrix_t *B) {
    matrix_t matrix;
    matrix = create_matrix(A->rows, B->columns);
    for (int i = 0; i < matrix.rows; ++i) {
        for (int j = 0; j < matrix.columns; ++j) {
            for (int k = 0; k < A->columns;) {
                matrix.matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
                k++;
            }
        }
    }

    return matrix;
}

static int count_vertex(data_t *data, FILE *file) {
    if (file != NULL) {
        fseek(file, 0, SEEK_SET);
        data->vertexes = 0;
        data->facets = 0;

        while (!feof(file)) {
            size_t len;
            char *line = (char *)calloc(255, sizeof(char));

            getline(&line, &len, file);

            if (strncmp(line, "v ", 2) == 0) {
                data->vertexes++;
            } else if (strncmp(line, "f ", 2) == 0) {
                data->facets++;
            }
            free(line);
        }
    }
    data->polygons = (facets_t *)calloc(data->facets, sizeof(facets_t));
    data->matrix_3d = (matrix_t *)calloc(data->vertexes, sizeof(matrix_t));

    for (unsigned int i = 0; i < data->vertexes; ++i) {
        data->matrix_3d[i] = create_matrix(4, 1);
    }

    return data->vertexes;
}

static void fill_vertex(data_t *data, FILE *file) {
    fseek(file, 0, SEEK_SET);
    int i = 0;
    while (!feof(file)) {
        size_t len;
        char *line = (char *)calloc(255, sizeof(char));
        getline(&line, &len, file);
        if (strncmp(line, "v ", 2) == 0) {
            sscanf(line, "v %lf %lf %lf", &data->matrix_3d[i].matrix[0][0], &data->matrix_3d[i].matrix[1][0],
                   &data->matrix_3d[i].matrix[2][0]);
            data->matrix_3d[i].matrix[3][0] = 1;
            i++;
        }

        free(line);
    }
}

static void count_facets(data_t *data, FILE *file) {
    fseek(file, 0, SEEK_SET);
    int j = 0;
    data->edges = 0;
    while (!feof(file)) {
        size_t len;
        char *line = (char *)calloc(255, sizeof(char));
        getline(&line, &len, file);

        if (strncmp(line, "f ", 2) == 0) {
            int count_f_num = 0;
            char *pch = strtok(line, "f ");
            while (pch != NULL) {
                int chislo = atoi(pch);
                if (chislo > 0) {
                    count_f_num++;
                }
                pch = strtok(NULL, "f ");
            }
            data->edges += count_f_num;
            data->polygons[j].linked_vertexes = count_f_num;
            data->polygons[j].vert = (int *)calloc(data->polygons[j].linked_vertexes, sizeof(int));
            j++;
        }

        free(line);
    }
}

static void fill_facets(data_t *data, FILE *file) {
    fseek(file, 0, SEEK_SET);
    int j_v = 0;
    while (!feof(file)) {
        size_t len;
        char *line = (char *)calloc(255, sizeof(char));
        getline(&line, &len, file);
        if (strncmp(line, "f ", 2) == 0) {
            int i = 0;
            char *pch = strtok(line, "f ");
            while (pch != NULL) {
                int chislo = atoi(pch);
                if (chislo != 0) {
                    data->polygons[j_v].vert[i] = chislo;
                }
                pch = strtok(NULL, "f ");
                i++;
            }
            j_v++;
        }
        free(line);
    }
}

static void free_data_matrix(data_t *data) {
    for (unsigned int i = 0; i < data->vertexes; ++i) {
        remove_matrix(&data->matrix_3d[i]);
    }
    free(data->matrix_3d);
}

static void free_polygons(data_t *data) {
    for (unsigned int i = 0; i < data->facets; ++i) {
        free(data->polygons[i].vert);
    }
    free(data->polygons);
}

void parse_file(data_t *data, FILE *file) {
    count_vertex(data, file);
    fill_vertex(data, file);
    count_facets(data, file);
    fill_facets(data, file);
}

void free_data(data_t *data) {
    free_polygons(data);
    free_data_matrix(data);
    data->vertexes = 0;
    data->facets = 0;
    data->edges = 0;
}
