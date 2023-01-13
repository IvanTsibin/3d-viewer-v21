#include "s21_savegif.h"
#include "gif.h"

SaveGif::SaveGif() {}

void SaveGif::GetSaveGifFile(char *str_file_name, int gifCounter,
                             float aspect) {
  //    std::cout << "You are in getSaveGifFile function gifCounter_ = " <<
  //    gifCounter << std::endl; std::cout << "str_file_name = " <<
  //    str_file_name << std::endl;
  if (gifCounter == 0) {
    strncpy(gifFileName_, str_file_name, strlen(str_file_name));
    gifFileName_[strlen(str_file_name)] = '\0';
    aspect_ = aspect;
  }
  //    std::cout << "gifFileName_ = " << gifFileName_ << std::endl;
  int lenth = strlen(gifFileName_);
  char temp_str[255], final_temp_str[275];
  if (lenth == 0) {
    strncpy(temp_str, "temp_number", 12);
    temp_str[12] = '\0';
  } else {
    for (int i = 0; i < lenth - 4; i++) {
      temp_str[i] = gifFileName_[i];
    }
    temp_str[lenth - 4] = '\0';
  }
  temp_str[lenth - 4] = '\0';
  sprintf(final_temp_str, "%s-%2d%s", temp_str, gifCounter, "-temp.png");
  //    std::cout << "final_temp_str = " << final_temp_str << std::endl;
  QString fileName = final_temp_str;
  controled_widget_->grab().save(fileName);
  if (gifCounter == 50)
    CollectAllForGif(gifFileName_);
  //    std::cout << "We made for Gif file name = " << final_temp_str <<
  //    std::endl;
}
void SaveGif::CollectAllForGif(char *str_file_name) {
  //        std::cout << "You are in Savepictures::collectAllForGif(char str[])"
  //        << std::endl;
  GifWriter gifWriter;
  int lenth = strlen(str_file_name);
  char temp_str[255], final_temp_str[275], gif_temp_str[299];
  if (lenth == 0) {
    strncpy(temp_str, "temp_number", 12);
    temp_str[12] = '\0';
  } else {
    for (int i = 0; i < lenth - 4; i++)
      temp_str[i] = str_file_name[i];
    temp_str[lenth - 4] = '\0';
  }
  temp_str[lenth - 4] = '\0';
  //        sprintf(final_temp_str, "%s%s", temp_str, "-temp.png");
  const time_t current_time = time(NULL);
  struct tm *current_year = NULL;
  char s1[40] = {0};
  current_year = localtime(&current_time);
  strftime(s1, 80, "%d-%m-%Y--%H-%M-%S", current_year);
  sprintf(gif_temp_str, "%s-%s%s", temp_str, s1, ".gif");
  int frame_delay = 20;
  for (int i = 0; i < 52; i++) {
    sprintf(final_temp_str, "%s-%2d%s", temp_str, i, "-temp.png");
    //        std::cout << "final_temp_str = " << final_temp_str << std::endl;
    QString fileName = final_temp_str;
    QImage image_1;
    image_1.load(fileName);
    QImage image = image_1.scaled((int)480 * aspect_, 480);
    if (i == 0) {
      GifBegin(&gifWriter, gif_temp_str, image.width(), image.height(), 100);
      GifWriteFrame(&gifWriter,
                    image.convertToFormat(QImage::Format_RGBA8888)
                        .convertToFormat(QImage::Format_RGBA8888)
                        .constBits(),
                    static_cast<uint32_t>(image.width()),
                    static_cast<uint32_t>(image.height()),
                    static_cast<uint32_t>(frame_delay));
    }
    if (i > 0 && i < 50) {
      GifWriteFrame(&gifWriter,
                    image.convertToFormat(QImage::Format_RGBA8888)
                        .convertToFormat(QImage::Format_RGBA8888)
                        .constBits(),
                    static_cast<uint32_t>(image.width()),
                    static_cast<uint32_t>(image.height()),
                    static_cast<uint32_t>(frame_delay));
    } else if (i == 50) {
      GifWriteFrame(&gifWriter,
                    image.convertToFormat(QImage::Format_RGBA8888)
                        .convertToFormat(QImage::Format_RGBA8888)
                        .constBits(),
                    static_cast<uint32_t>(image.width()),
                    static_cast<uint32_t>(image.height()),
                    static_cast<uint32_t>(frame_delay));
      GifEnd(&gifWriter);
    }
    remove(final_temp_str);
  }
}
