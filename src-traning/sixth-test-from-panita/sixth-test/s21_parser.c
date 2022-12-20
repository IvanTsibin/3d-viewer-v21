#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include "s21_3dviewer.h"
#include "s21_parser.h"

int read_data_from_file(const char file_name[], figure_t *figure) {
    printf("Hello, You are in read_data_from_file function\n");
    FILE *obj_file;
    figure->dots_number = 0; figure->lines_number = 0; figure->triangles_number = 0;
    int error = 0, str_number = 0;
    char strs_from_file[STR_NUMBER][LINE_LENTH];
    if ((obj_file = fopen(file_name, "r")) == NULL) {
        error = 1;
        printf("file %s: is not found, sorry!!!\n", file_name);
    } else {
        printf("We fond file %s !!!\n", file_name);
        read_str_from_file(obj_file, strs_from_file, &str_number);
        // print_str_from_file(strs_from_file, str_number);
        read_dots_from_str(strs_from_file, str_number, figure);
        // print_figure(figure);
        read_triangles_from_str(strs_from_file, str_number, figure);
        // print_figure(figure);
        make_lines_set(figure);
        // print_figure(figure);
        fclose(obj_file);
    }
    return error;
}

void make_lines_set(figure_t *figure) {
    printf("Hello, You are in make_lines_set function\n");
    int temp_lines[LINES][2], lines_counter = 0, counter = 0, flag = 1;
    for (int i = 0; i < figure->triangles_number; i++) {
        temp_lines[lines_counter][0] = figure->triangles[i][0];
        temp_lines[lines_counter][1] = figure->triangles[i][1]; lines_counter++;
        temp_lines[lines_counter][0] = figure->triangles[i][1];
        temp_lines[lines_counter][1] = figure->triangles[i][2]; lines_counter++;
        temp_lines[lines_counter][0] = figure->triangles[i][2];
        temp_lines[lines_counter][1] = figure->triangles[i][0]; lines_counter++;
        if (figure->triangles[i][3] != -1) {
        temp_lines[lines_counter][0] = figure->triangles[i][2];
        temp_lines[lines_counter][1] = figure->triangles[i][3]; lines_counter++;
        temp_lines[lines_counter][0] = figure->triangles[i][3];
        temp_lines[lines_counter][1] = figure->triangles[i][0]; lines_counter++;
        }
    }
    for (int i = 0; i < lines_counter; i++) {
        // printf("temp_lines[%d][0] = %d   temp_lines[%d][1] = %d\n", i, temp_lines[i][0], i, temp_lines[i][1]);
        for (int j = 0; j < counter; j++) {
            if (temp_lines[i][0] == figure->lines[j][0] && temp_lines[i][1] == figure->lines[j][1]) {
                flag = 0; break;
            } else if (temp_lines[i][0] == figure->lines[j][1] && temp_lines[i][1] == figure->lines[j][0]) {
                flag = 0; break;
            }
        }
        if (flag == 0) {
            flag = 1;
            continue;
        } else {
            figure->lines[counter][0] = temp_lines[i][0];
            figure->lines[counter][1] = temp_lines[i][1];
            counter++;
        }
    }
    figure->lines_number = counter;
}

void print_str_from_file(char strs_from_file[STR_NUMBER][LINE_LENTH], int str_number) {
    printf("Hello, You are in print_str_from_file function\n");
    for (int i = 0; i < str_number; i++) {
        printf("%s", strs_from_file[i]);
        // printf("\n");
    }
}

void read_dots_from_str(char strs_from_file[STR_NUMBER][LINE_LENTH], int str_number, figure_t *figure) {
    printf("Hello, You are in read_dots_from_str function\n");
    int counter = 0;
        for (int i = 0; i < str_number; i++) {
            char letter, str1[20], str2[20], str3[20];
            if (strs_from_file[i][0] == 'v' && strs_from_file[i][1] == ' ') {
                // sscanf((const char *)strs_from_file[i], "%c%lf%lf%lf", &letter, &figure->dots[counter][0], &figure->dots[counter][1], &figure->dots[counter][2]);
                sscanf((const char *)strs_from_file[i], "%c%s%s%s", &letter, str1, str2, str3);
                // printf("str1 = %s, str2 = %s, str3 = %s \n", str1, str2, str3);
                figure->dots[counter][0] = convert_str_to_double(str1, strlen(str1));
                figure->dots[counter][1] = convert_str_to_double(str2, strlen(str2));
                figure->dots[counter][2] = convert_str_to_double(str3, strlen(str3));
                // printf("figure->dots[%d][0] = %lf", counter, figure->dots[counter][0]);
                // printf("  figure->dots[%d][1] = %lf", counter, figure->dots[counter][1]);
                // printf("  figure->dots[%d][2] = %lf\n", counter, figure->dots[counter][2]);
                // sscanf((const char *)str1, "%lf", &figure->dots[counter][0]);
                // sscanf((const char *)str2, "%lf", &figure->dots[counter][1]);
                // sscanf((const char *)str3, "%lf", &figure->dots[counter][2]);
                figure->dots[i][3] = 1;
                counter++;
            }
    }
    figure->dots_number = counter;
}

double convert_str_to_double(char number[], int counter) {
    // printf("We got str = %s and counter = %d  \n", number, counter);
    int before_dot_flag = 1, devider = 10, add = 0;
    double multiplyer = 1, rezult;
    if (number[0] == '-') {
        multiplyer = -1;
        rezult = (double)(number[1] - 48);
        add = 1;
    } else {
        rezult = (double)(number[0] - 48);
    }
    // printf("step 0 rezult = %lf\n", rezult);
    for (int i = 1 + add; i < counter; i++) {
        if (number[i] == '.') {
            before_dot_flag = 0;
            continue;
        }
        if (before_dot_flag == 1) {
            rezult = rezult*10 + (double) (number[i] - 48);
        } else {
            rezult = rezult + ((double)(number[i] - 48))/devider;
            devider *= 10;
        }
        // printf("step %d rezult = %lf\n", i, rezult);
    }
    rezult *= multiplyer;
    return rezult;
}


void read_triangles_from_str(char strs_from_file[STR_NUMBER][LINE_LENTH], int str_number, figure_t *figure) {
    printf("Hello, You are in read_triangles_from_str function\n");
    int counter = 0;
        for (int i = 0; i < str_number; i++) {
            char letter, str1[20], str2[20], str3[20], str4[20] = "\0";
            if (strs_from_file[i][0] == 'f' && strs_from_file[i][1] == ' ') {
                sscanf((const char *)strs_from_file[i], "%c%s%s%s%s", &letter, str1, str2, str3, str4);
                printf("strs_from_file[%d] = %s", i, strs_from_file[i]);
                printf("str1 = %s, str2 = %s, str3 = %s str4 = %s\n", str1, str2, str3, str4);
                sscanf((const char *)str1, "%d", &figure->triangles[counter][0]);
                sscanf((const char *)str2, "%d", &figure->triangles[counter][1]);
                sscanf((const char *)str3, "%d", &figure->triangles[counter][2]);
                if (strlen(str4) != 0) {
                    sscanf((const char *)str4, "%d", &figure->triangles[counter][3]);
                } else {
                    figure->triangles[counter][3] = -1;
                }
                figure->triangles[counter][0] -= 1;
                figure->triangles[counter][1] -= 1;
                figure->triangles[counter][2] -= 1;
                
                counter++;
            }
    }
    figure->triangles_number = counter;
}

void read_str_from_file(FILE *obj_file, char strs_from_file[STR_NUMBER][LINE_LENTH], int *str_number) {
    printf("Hello, You are in read_str_from_file function\n");
     char letter;
     int counter = 0;
     while (!feof(obj_file)) {
         letter = fgetc(obj_file);
         if (letter == 10 || letter == EOF) {
            // printf("%c", letter);
            if (letter == EOF) {
                strs_from_file[*str_number][counter] = '\0';
            } else {
                strs_from_file[*str_number][counter] = letter;
            }
            counter = 0;
            *str_number = *str_number + 1;
         } else {
            // printf("%c", letter);
            strs_from_file[*str_number][counter] = letter;
            counter++;
         }
     }
}