#include "s21_matrix.h"

matrix_t s21_create_matrix(int rows, int columns) {
    // printf("Hello, you are in s21_create_matrix function!!!\n");
    matrix_t answer;
    if (rows <= 0 || columns <= 0) {
        answer.matrix_type = INCORRECT_MATRIX;
        answer.rows = rows;
        answer.columns = columns;
        answer.matrix = NULL;
    } else {
        answer.matrix_type = ZERO_MATRIX;
        answer.rows = rows;
        answer.columns = columns;
        answer.matrix = (double **)calloc(rows, sizeof(double*));
        for (int i = 0; i < rows; i++) {
            answer.matrix[i] = (double *)calloc(columns, sizeof(double));
        }
        // printf("We created matrix!!!\n");
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                answer.matrix[i][j] = 0;
            }
        }
    }
    // printf ("We are out of s21_creat_matrix function!!!\n");
    return answer;
}

void s21_remove_matrix(matrix_t *A) {
    // printf("Hello, you are in s21_remove_matrix function!!!\n");
    if (A != NULL && A->matrix_type != INCORRECT_MATRIX) {
        if (A->rows > 0) {
            for (int i = 0; i < A->rows; i++) {
                free(A->matrix[i]);
            }
            free(A->matrix);
        }
        A->matrix_type = INCORRECT_MATRIX;
    }
}

int check_for_dimention_and_type(matrix_t *A, matrix_t *B) {
    int answer = 1;
    if (A->matrix_type == 1 || B->matrix_type == 1) {
        answer = 0;
    } else if (A->rows != B->rows || A->columns != B->columns) {
        answer = 0;
    }
    if (answer == 0) {
        // printf("matrix A does NOT match to matrix B\n");
    } else {
        // printf("matrix A MATCHS to matrix B\n");
    }
    return answer;
}

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
    printf("Hello, you are in s21_eq_matrix function!!!\n");
    int answer = 1;
    if (s21_check_matrix_for_no_mistakes(A) == 0 || s21_check_matrix_for_no_mistakes(B) == 0) {
        answer = 0;
        printf("We found matrix with mistakes\n");
    } else if (check_for_dimention_and_type(A, B)) {
        int flag = 0;
        for (int i = 0; i < A->rows; i++) {
            for (int j = 0; j < A->columns; j++) {
                double diff = fabs(A->matrix[i][j] - B->matrix[i][j]);
                if (diff > +1e-07) {
                    printf("A->matrix[%d][%d] != B->matrix[%d][%d]\n", i, j, i, j);
                    printf("The difference is = %e\n", diff);
                    flag = 1;
                    break;
                }
            }
        }
        if (flag == 1) answer = 0;
    } else {
        printf("The dimention or type is wrong\n");
        answer = 0;
    }
    if (answer == 0) {
        printf("matrix A is NOT equal to matrix B\n");
    } else {
        printf("matrix A is EQUAL to matrix B\n");
    }
    return answer;
}

matrix_t s21_sum_matrix(matrix_t *A, matrix_t *B) {
    // printf("Hello, you are in s21_sum_matrix function!!!\n");
    matrix_t rezult;
    if (!s21_check_matrix_for_no_mistakes(A) || !s21_check_matrix_for_no_mistakes(B)) {
        rezult = s21_create_matrix(1, 1);
        rezult.matrix_type = 1;
    } else if (check_for_dimention_and_type(A, B)) {
        rezult = s21_create_matrix(A->rows, A->columns);
        for (int i = 0; i < A->rows; i++) {
            for (int j = 0; j < A->columns; j++) {
                rezult.matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
            }
        }
        s21_matrix_type_check_for_correct_zero_and_identity(&rezult);
        // rezult.matrix_type = 0;
    } else {
        rezult = s21_create_matrix(1, 1);
        rezult.matrix_type = 1;
    }
    return rezult;
}

matrix_t s21_sub_matrix(matrix_t *A, matrix_t *B) {
    // printf("Hello, you are in s21_sub_matrix function!!!\n");
    matrix_t rezult;
    if (!s21_check_matrix_for_no_mistakes(A) || !s21_check_matrix_for_no_mistakes(B)) {
        rezult = s21_create_matrix(1, 1);
        rezult.matrix_type = 1;
    } else if (check_for_dimention_and_type(A, B)) {
        rezult = s21_create_matrix(A->rows, A->columns);
        for (int i = 0; i < A->rows; i++) {
            for (int j = 0; j < A->columns; j++) {
                rezult.matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
            }
        }
        s21_matrix_type_check_for_correct_zero_and_identity(&rezult);
    } else {
        rezult = s21_create_matrix(1, 1);
        rezult.matrix_type = 1;
    }
    return rezult;
}

matrix_t s21_mult_number(matrix_t *A, double number) {
    // printf("Hello, you are in s21_mult_number function!!!\n");
    matrix_t rezult;
    if (s21_check_matrix_for_no_mistakes(A)) {
        rezult = s21_create_matrix(A->rows, A->columns);
        for (int i = 0; i < A->rows; i++) {
            for (int j = 0; j < A->columns; j++) {
                rezult.matrix[i][j] = A->matrix[i][j] * number;
            }
        }
        s21_matrix_type_check_for_correct_zero_and_identity(&rezult);
    } else {
        rezult = s21_create_matrix(1, 1);
        rezult.matrix_type = 1;
    }
    return rezult;
}

matrix_t s21_mult_matrix(matrix_t *A, matrix_t *B) {
    // printf("Hello, you are in s21_mult_matrix function!!!\n");
    matrix_t rezult;
    int flag = 1;
    if (s21_check_matrix_for_no_mistakes(A) && s21_check_matrix_for_no_mistakes(B)) {
        if (A->columns == B->rows) {
            rezult = s21_create_matrix(A->rows, B->columns);
            for (int i = 0; i < A->rows; i++) {
                for (int j = 0; j < B->columns; j++) {
                    double temp_number = 0;
                    for (int k = 0; k < B->rows; k++) {
                        temp_number += A->matrix[i][k] * B->matrix[k][j];
                    }
                    rezult.matrix[i][j] = temp_number;
                }
            }
            s21_matrix_type_check_for_correct_zero_and_identity(&rezult);
        } else {
            flag = 0;
        }
    } else {
        flag = 0;
    }
    if (flag == 0) {
        rezult = s21_create_matrix(1, 1);
        rezult.matrix_type = 1;
    }
    return rezult;
}

matrix_t s21_transpose(matrix_t *A) {
    // printf("Hello, you are in s21_transpose function!!!\n");
    matrix_t rezult;
    if (!s21_check_matrix_for_no_mistakes(A)) {
        rezult = s21_create_matrix(1, 1);
        rezult.matrix_type = 1;
    } else {
        rezult = s21_create_matrix(A->columns, A->rows);
        for (int i = 0; i < A->columns; i++) {
            for (int j = 0; j < A->rows; j++) {
                rezult.matrix[i][j] = A->matrix[j][i];
            }
        }
        s21_matrix_type_check_for_correct_zero_and_identity(&rezult);
    }
    return rezult;
}

matrix_t s21_calc_complements(matrix_t *A) {
    // printf("Hello, you are in s21_calc_complements function!!!\n");
    matrix_t rezult;
    if (s21_check_matrix_for_no_mistakes(A)) {
        if (A->rows == A->columns) {
            rezult = s21_create_matrix(A->rows, A->columns);
            for (int i = 0; i < A->rows; i++) {
                for (int j = 0; j < A->columns; j++) {
                    int det = A->rows - 1, counter_rows = 0, counter_columns;
                    matrix_t temp = s21_create_matrix(det, det);
                    for (int k = 0; k < A->rows; k++) {
                        if (k != i) {
                            counter_columns = 0;
                            for (int m = 0; m < A->columns; m++) {
                                if (m != j) {
                                    temp.matrix[counter_rows][counter_columns] = A->matrix[k][m];
                                    counter_columns++;
                                }
                            }
                            counter_rows++;
                        }
                    }
                    temp.matrix_type = 0;
                    // printf("We have i = %d and j = %d\n", i, j);
                    // s21_print_matrix(&temp);
                    rezult.matrix[i][j] = s21_determinant(&temp) * ((i + j)%2 == 0 ? 1: -1);
                    s21_remove_matrix(&temp);
                }
            }
            s21_matrix_type_check_for_correct_zero_and_identity(&rezult);
        } else {
            rezult = s21_create_matrix(1, 1);
            rezult.matrix_type = 1;
        }
    } else {
        rezult = s21_create_matrix(1, 1);
        rezult.matrix_type = 1;
    }
    return rezult;
}

double s21_determinant(matrix_t *A) {
    // printf("Hello, you are in s21_determinant function!!!\n");
    // printf("We have matrix:\n");
    // s21_print_matrix(A);
    double answer;
    if (!s21_check_matrix_for_no_mistakes(A)) {
        // printf("det var 1\n");
        answer = NAN;
    } else if (A->columns != A->rows) {
        // printf("det var 2\n");
        answer = NAN;
    } else if (A->matrix_type == ZERO_MATRIX) {
        // printf("det var 3\n");
        answer = 0;
    } else if (A->matrix_type == 2) {
        // printf("det var 4\n");
        answer = 1;
    } else {
        // printf("det var 5\n");
        if (A->rows == 1) {
            answer = A->matrix[0][0];
        } else if (A->rows == 2) {
            answer = A->matrix[0][0] * A->matrix[1][1] - A->matrix[0][1] * A->matrix[1][0];
        } else {
            answer = 0;
            for (int i = 0; i < A->rows; i++) {
                int dem = A->rows - 1;
                matrix_t temp = s21_create_matrix(dem, dem);
                int counter_columns = 0;
                for (int j = 0; j < A->rows; j++) {
                    if (j != i) {
                        for (int k = 1; k < A->rows; k++) {
                            temp.matrix[k - 1][counter_columns] = A->matrix[k][j];
                        }
                        counter_columns++;
                    }
                }
                temp.matrix_type = 0;
                answer += A->matrix[0][i] * s21_determinant(&temp) * ((i % 2) == 0 ? 1 : -1);
                s21_remove_matrix(&temp);
            }
        }
    }
    // printf("We made determinant = %.2lf\n", answer);
    return answer;
}

matrix_t s21_inverse_matrix(matrix_t *A) {
    // printf("Hello, you are in s21_inverse_matrix function!!!\n");
        matrix_t rezult;
        int flag = 1;
    if (s21_check_matrix_for_no_mistakes(A)) {
        if (A->rows == A->columns) {
            double det = s21_determinant(A);
            if (det != 0.0) {
                matrix_t temp_rezult = s21_calc_complements(A);
                rezult  = s21_transpose(&temp_rezult);
                // printf("We have matrix:\n");
                // s21_print_matrix(&rezult);
                for (int i = 0; i < A->rows; i++) {
                    for (int j = 0; j < A->columns; j++) {
                        rezult.matrix[i][j] /= det;
                    }
                }
                // printf("We made matrix:\n");
                // s21_print_matrix(&rezult);
                s21_matrix_type_check_for_correct_zero_and_identity(&rezult);
                s21_remove_matrix(&temp_rezult);
            } else {
                flag = 0;
            }
        } else {
            flag = 0;
        }
    } else {
        flag = 0;
    }
    if (flag == 0) {
        rezult = s21_create_matrix(1, 1);
        rezult.matrix_type = 1;
    }
    return rezult;
}

int s21_check_matrix_for_no_mistakes(matrix_t *A) {
    // printf("Hello, you are in s21_check_matrix_for_mistakes function!!!\n");
    int rezult = 1;
    if (A == NULL) {
        // printf("mistake - NULL pointer\n");
        rezult = 0;
    } else if (A->matrix_type == 1) {
        // printf("mistake - A->matrix_type == 1\n");
        rezult = 0;
    } else if (A->rows <= 0 || A->columns <= 0) {
        // printf("mistake - A->rows <=0 || A->columns <= 0\n");
        rezult = 0;
    } else {
        for (int i = 0; i < A->rows; i++) {
            for (int j = 0; j < A->columns; j++) {
                if (isinf(A->matrix[i][j])) {
                    // printf("mistake - inf\n");
                    rezult = 0;
                    break;
                }
                if (isnan(A->matrix[i][j])) {
                    // printf("mistake - nan\n");
                    rezult = 0;
                    break;
                }
            }
            if (rezult == 0) break;
        }
    }
    // if (rezult == 1) printf("There is NO mistakes in this matrix!!!\n");
    return rezult;
}

void s21_matrix_type_check_for_correct_zero_and_identity(matrix_t *A) {
    // printf("Hello, you are in s21_matrix_type_check function!!!\n");
    if (A != NULL) {
        // printf("We got matrix:\n");
        // s21_print_matrix(A);
        if (A->rows > 0 && A->columns > 0) {
            int zero_count = 0;
            // printf("step 1\n");
            for (int i = 0; i < A->rows; i++) {
                for (int j = 0; j < A->columns; j++) {
                    if (fabs(A->matrix[i][j]) < +1e-07) {
                        zero_count++;
                    }
                }
            }
            if (zero_count == A->rows * A->columns) {
                // printf("step 2\n");
                A->matrix_type = 3;
            } else {
                // printf("step 3\n");
                zero_count = 0;
                if (A->rows == A->columns) {
                    int one_count = 0;
                    // printf("step 4\n");
                    for (int i = 0; i < A->rows; i++) {
                        for (int j = 0; j < A->columns; j++) {
                            if (i == j && fabs((A->matrix[i][j]) - 1.0) < +1e-07) {
                                one_count++;
                                // printf("A-matrix[%d][%d] = %d\n", i, j, A->matrix[i][j]);
                            } else if (fabs(A->matrix[i][j]) < +1e-07) {
                                zero_count++;
                            }
                        }
                    }
                    // printf("one_count = %d  and zero_count = %d\n", one_count, zero_count);
                    if (zero_count == A->rows * A->columns - A->rows && one_count == A->rows) {
                        // printf("step 5\n");
                        A->matrix_type = 2;
                    } else {
                        // printf("step 6\n");
                        A->matrix_type = 0;
                        // printf("It is CORRECT MATRIX!!!\n");
                    }
                } else {
                    // printf("step 7\n");
                    A->matrix_type = 0;
                    // printf("It is CORRECT MATRIX!!!\n");
                }
            }
        } else {
            A->matrix_type = 1;
        }
    }
    // printf("We are out of check function!!!\n");
}


void s21_print_matrix(matrix_t *A) {
    // printf("Hello, you are in s21_print_matrix function!!!\n");
    if (A == NULL) {
        printf("There is no matrix. NULL pointer is given\n");
    } else if (A->matrix_type == INCORRECT_MATRIX) {
        printf("This is INCORRECT_MATRIX!!!\n");
    } else if (A->matrix_type == IDENTITY_MATRIX) {
        printf("This matrix is an IDENTITY_MATRIX!!!\n");
        printf("A->rows = %d A->columns = %d\n", A->rows, A->columns);
        for (int i = 0; i < A->rows; i++) {
            for (int j = 0; j < A->columns; j++) {
                printf("%+7.1f   ", A->matrix[i][j]);
            }
            printf("\n");
        }
    } else if (A->matrix_type == ZERO_MATRIX) {
        printf("This matrix is ZERO_MATRIX!!!\n");
        printf("A->rows = %d A->columns = %d\n", A->rows, A->columns);
        for (int i = 0; i < A->rows; i++) {
            for (int j = 0; j < A->columns; j++) {
                printf("%+7.1f   ", A->matrix[i][j]);
            }
            printf("\n");
        }
    } else {
        printf("This matrix is a CORRECT_MATRIX!!!\n");
        printf("A->rows = %d A->columns = %d\n", A->rows, A->columns);
        for (int i = 0; i < A->rows; i++) {
            for (int j = 0; j < A->columns; j++) {
                printf("%+7.1f   ", A->matrix[i][j]);
            }
            printf("\n");
        }
    }
}
