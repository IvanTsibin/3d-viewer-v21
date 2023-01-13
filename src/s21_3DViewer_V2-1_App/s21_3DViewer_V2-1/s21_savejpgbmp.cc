#include "s21_savejpgbmp.h"

SaveJpgBmp::SaveJpgBmp() {}

void SaveJpgBmp::GetSaveJpgBmpFile(char *str_file_name, int type) {

  //    std::cout << "You are in Savejpgbmp::getSaveJpgBmpFile" << std::endl;
  //    std::cout << "str_file_name = " << str_file_name << std::endl;
  const time_t current_time = time(NULL);
  struct tm *current_year = NULL;
  char s1[40] = {0};
  current_year = localtime(&current_time);
  strftime(s1, 80, "%d-%m-%Y--%H-%M-%S", current_year);
  int lenth = strlen(str_file_name);
  char temp_str[255], final_temp_str[300];
  if (lenth == 0) {
    strncpy(temp_str, "temp_number", 12);
    temp_str[12] = '\0';
  } else {
    for (int i = 0; i < lenth - 4; i++) {
      temp_str[i] = str_file_name[i];
    }
    temp_str[lenth - 4] = '\0';
  }
  if (type == 0) {
    sprintf(final_temp_str, "%s%c%s%s", temp_str, '-', s1, ".jpg");
  } else {
    sprintf(final_temp_str, "%s%c%s%s", temp_str, '-', s1, ".bmp");
  }

  QString fileName = final_temp_str;
  //    std::cout << "We made for JPG file name = " << final_temp_str <<
  //    std::endl;
  controled_widget_->grab().save(fileName);
}
