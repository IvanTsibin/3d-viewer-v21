#ifndef SRC_TRAINING_S21_PARSER_H_
#define SRC_TRAINING_S21_PARSER_H_



#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include "s21_3dviewer.h"

#define STR_NUMBER 2000
#define LINE_LENTH 255

int read_data_from_file(const char file_name[], figure_t *figure);
void make_lines_set(figure_t *figure);
void print_str_from_file(char strs_from_file[STR_NUMBER][LINE_LENTH], int str_number);
void read_dots_from_str(char strs_from_file[STR_NUMBER][LINE_LENTH], int str_number, figure_t *figure);
double convert_str_to_double(char number[], int counter);
void read_triangles_from_str(char strs_from_file[STR_NUMBER][LINE_LENTH], int str_number, figure_t *figure);
void read_str_from_file(FILE *obj_file, char strs_from_file[STR_NUMBER][LINE_LENTH], int *str_number);

#ifdef __cplusplus
}
#endif

#endif  // SRC_TRAINING_S21_PARSER_H_