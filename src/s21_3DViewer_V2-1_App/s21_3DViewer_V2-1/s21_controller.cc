#include "s21_controller.h"
#include "s21_savepictures.h"

Controller::Controller() {
//  std::cout << " Controller::Controller() " << std::endl;
  start_set_.facets_on = true;
  start_set_.xRot = 0;
  start_set_.yRot = 0;
  start_set_.zRot = 0;
  start_set_.xMove = 0;
  start_set_.yMove = 0;
  start_set_.zMove = 0;
  start_set_.Multip = 1.0;
  start_set_.xLight = 0;
  start_set_.yLight = 0;
  start_set_.RedColor = 0.2;
  start_set_.GreenColor = 0.2;
  start_set_.BlueColor = 0.2;
  start_set_.RedColorLine = 0.8;
  start_set_.GreenColorLine = 0.5;
  start_set_.BlueColorLine = 0.2;
  start_set_.RedColorVertex = 0.5;
  start_set_.GreenColorVertex = 0.8;
  start_set_.BlueColorVertex = 0.2;
  start_set_.RedColorFacets = 0.5;
  start_set_.GreenColorFacets = 0.2;
  start_set_.BlueColorFacets = 0.8;
  start_set_.RedColorLight = 1.0;
  start_set_.GreenColorLight = 1.0;
  start_set_.BlueColorLight = 1.0;
  start_set_.LineWidth = 1;
  start_set_.VertexSize = 5;
  start_set_.VertexType = 1;
  start_set_.perspect = 1;
  start_set_.lineType = 0;
  start_set_.NormalGuro = 1;
  start_set_.aspect = 1.0;
  start_set_.facets = 1;
  set_for_controller_ = start_set_;
  gifCounter_ = -1;
  yRotCounter_ = -1;
  pictureFileName_ = nullptr;
  aspect_ = 1.0;
  type_ = 0;
  MySavePicture_ = new SavePictures();
  MySavePicture_->connectWidget(controled_widget_);
  connect(this, &Controller::SendSavePictureSignal, MySavePicture_,
          &SavePictures::GetSavePictureSignal);
  timer_ = new QTimer(this);
  SendSettingsToGLWidget(&start_set_);
}

Controller::~Controller() {
  delete controled_widget_;
  SaveStartPos();
}

static void qNormalizeAngle(int &angle) {
  while (angle < 0)
    angle += 360 * 16;
  while (angle > 360 * 16)
    angle -= 360 * 16;
}

void Controller::SettingsFromGLWidgetToController(Settings_t *set) {
  //    std::cout << "Hello, You are in
  //    Controller::SettingsFromGLWidgetToController(settings_t *)" <<
  //    std::endl;
  set_for_controller_ = *set;
  qNormalizeAngle(set_for_controller_.xRot);
  qNormalizeAngle(set_for_controller_.yRot);
  qNormalizeAngle(set_for_controller_.zRot);
  emit XRotationChanged(set_for_controller_.xRot);
  emit YRotationChanged(set_for_controller_.yRot);
  emit ZRotationChanged(set_for_controller_.zRot);
  int temp = (int)round((set_for_controller_.Multip * 100));
  emit MultipChanged(temp);
}

void Controller::GetFacetsStatus(bool checked) {
  //        std::cout << "Hello, You are in Controller::getFacetsStatus(bool
  //        checked)" << std::endl;
}

void Controller::SetXRotation(int angle) {
  qNormalizeAngle(angle);
  set_for_controller_.xRot = angle;
  emit XRotationChanged(angle);
  EmitSettings();
}

void Controller::SetYRotation(int angle) {
  qNormalizeAngle(angle);
  set_for_controller_.yRot = angle;
  emit YRotationChanged(angle);
  EmitSettings();
}

void Controller::SetZRotation(int angle) {
  qNormalizeAngle(angle);
  set_for_controller_.zRot = angle;
  emit ZRotationChanged(angle);
  EmitSettings();
}

void Controller::SetMultip(int multip) {
  set_for_controller_.Multip = ((float)multip) / 100;
  emit MultipChanged(multip);
  EmitSettings();
}

void Controller::SetXMove(int x_move) {
  set_for_controller_.xMove = x_move;
  EmitSettings();
}

void Controller::SetYMove(int y_move) {
  set_for_controller_.yMove = y_move;
  EmitSettings();
}

void Controller::SetZMove(int z_move) {
  set_for_controller_.zMove = z_move;
  EmitSettings();
}

void Controller::SetXLight(int x_light) {
  set_for_controller_.xLight = x_light;
  EmitSettings();
}

void Controller::SetYLight(int y_light) {
  set_for_controller_.yLight = y_light;
  EmitSettings();
}

void Controller::SetRedColor(int RedColor) {
  set_for_controller_.RedColor = (float)RedColor / 255.0;
  EmitSettings();
}
void Controller::SetGreenColor(int GreenColor) {
  set_for_controller_.GreenColor = (float)GreenColor / 255.0;
  EmitSettings();
}
void Controller::SetBlueColor(int BlueColor) {
  set_for_controller_.BlueColor = (float)BlueColor / 255.0;
  EmitSettings();
}

void Controller::SetRedColorLine(int RedColorLine) {
  set_for_controller_.RedColorLine = (float)RedColorLine / 255.0;
  EmitSettings();
}
void Controller::SetGreenColorLine(int GreenColorLine) {
  set_for_controller_.GreenColorLine = (float)GreenColorLine / 255.0;
  EmitSettings();
}
void Controller::SetBlueColorLine(int BlueColorLine) {
  set_for_controller_.BlueColorLine = (float)BlueColorLine / 255.0;
  EmitSettings();
}

void Controller::SetRedColorVertex(int RedColorVertex) {
  set_for_controller_.RedColorVertex = (float)RedColorVertex / 255.0;
  EmitSettings();
}
void Controller::SetGreenColorVertex(int GreenColorVertex) {
  set_for_controller_.GreenColorVertex = (float)GreenColorVertex / 255.0;
  EmitSettings();
}
void Controller::SetBlueColorVertex(int BlueColorVertex) {
  set_for_controller_.BlueColorVertex = (float)BlueColorVertex / 255.0;
  EmitSettings();
}

void Controller::SetRedColorFacets(int RedColorFacets) {
  set_for_controller_.RedColorFacets = (float)RedColorFacets / 255.0;
  EmitSettings();
}
void Controller::SetGreenColorFacets(int GreenColorFacets) {
  set_for_controller_.GreenColorFacets = (float)GreenColorFacets / 255.0;
  EmitSettings();
}
void Controller::SetBlueColorFacets(int BlueColorFacets) {
  set_for_controller_.BlueColorFacets = (float)BlueColorFacets / 255.0;
  EmitSettings();
}

void Controller::SetRedColorLight(int RedColorLight) {
  set_for_controller_.RedColorLight = (float)RedColorLight / 255.0;
  EmitSettings();
}
void Controller::SetGreenColorLight(int GreenColorLight) {
  set_for_controller_.GreenColorLight = (float)GreenColorLight / 255.0;
  EmitSettings();
}
void Controller::SetBlueColorLight(int BlueColorLight) {
  set_for_controller_.BlueColorLight = (float)BlueColorLight / 255.0;
  EmitSettings();
}

void Controller::SetLineWidth(int LineWidth) {
  set_for_controller_.LineWidth = LineWidth;
  EmitSettings();
}

void Controller::SetVertexSize(int VertexSize) {
  set_for_controller_.VertexSize = VertexSize;
  EmitSettings();
}

void Controller::SetVertexType(int VertexType) {
  set_for_controller_.VertexType = VertexType;
  EmitSettings();
}

void Controller::SetPerspectiveStatus(int PerspectiveStatus) {
  set_for_controller_.perspect = PerspectiveStatus;
  //    std::cout << "in get_perspect_status set_for_controller_.perspect = " <<
  //    set_for_controller_.perspect << std::endl;
  EmitSettings();
}

void Controller::SetFacetsStatus(int FacetsStatus) {
  set_for_controller_.facets = FacetsStatus;
  //    std::cout << "in setFacetsStatus set_for_controller_.facets = " <<
  //    set_for_controller_.facets << std::endl;
  EmitSettings();
}

void Controller::SetDashLineSignal(int signal) {
  if (signal == 1) {
    set_for_controller_.lineType = 1;
  } else {
    set_for_controller_.lineType = 0;
  }
  EmitSettings();
}

void Controller::SaveStartPos() {
  //    std::cout << "Let's save file - Let's write in it!!!" << std::endl;
  setlocale(LC_ALL, "C");
  FILE *start_pos;
  start_pos = fopen("start_pos-v2.pos", "w");
  //    std::cout << "on save set_for_controller_.Multip = " <<
  //    set_for_controller_.Multip  << std::endl;
  fprintf(start_pos, "%.2lf %.2lf %.2lf %.2lf ", set_for_controller_.Multip,
          set_for_controller_.RedColor, set_for_controller_.GreenColor,
          set_for_controller_.BlueColor);
  fprintf(start_pos, "%.2lf %.2lf %.2lf %.2lf %.2lf %.2lf ",
          set_for_controller_.RedColorLine, set_for_controller_.GreenColorLine,
          set_for_controller_.BlueColorLine, set_for_controller_.RedColorVertex,
          set_for_controller_.GreenColorVertex,
          set_for_controller_.BlueColorVertex);
  fprintf(
      start_pos, "%.2lf %.2lf %.2lf %.2lf %.2lf %.2lf ",
      set_for_controller_.RedColorFacets, set_for_controller_.GreenColorFacets,
      set_for_controller_.BlueColorFacets, set_for_controller_.RedColorLight,
      set_for_controller_.GreenColorLight, set_for_controller_.BlueColorLight);
  fprintf(start_pos, "%d %d %d %d %d %d ", set_for_controller_.xRot,
          set_for_controller_.yRot, set_for_controller_.zRot,
          set_for_controller_.xMove, set_for_controller_.yMove,
          set_for_controller_.zMove);
  fprintf(start_pos, "%d %d %d %d %d %d ", set_for_controller_.LineWidth,
          set_for_controller_.VertexSize, set_for_controller_.VertexType,
          set_for_controller_.perspect, set_for_controller_.lineType,
          set_for_controller_.facets);
  fprintf(start_pos, "%d %d %d ", set_for_controller_.xLight,
          set_for_controller_.yLight, set_for_controller_.NormalGuro);
  fclose(start_pos);
//  printf("%+.2f %+.2f %+.2f %+.2f ", set_for_controller_.Multip,
//         set_for_controller_.RedColor, set_for_controller_.GreenColor,
//         set_for_controller_.BlueColor);
//  printf("%+.2f %+.2f %+.2f %+.2f %+.2f %+.2f ",
//         set_for_controller_.RedColorLine, set_for_controller_.GreenColorLine,
//         set_for_controller_.BlueColorLine, set_for_controller_.RedColorVertex,
//         set_for_controller_.GreenColorVertex,
//         set_for_controller_.BlueColorVertex);
//  printf(
//      "%+.2f %+.2f %+.2f %+.2f %+.2f %+.2f ",
//      set_for_controller_.RedColorFacets, set_for_controller_.GreenColorFacets,
//      set_for_controller_.BlueColorFacets, set_for_controller_.RedColorLight,
//      set_for_controller_.GreenColorLight, set_for_controller_.BlueColorLight);
//  printf("%d %d %d %d %d %d ", set_for_controller_.xRot,
//         set_for_controller_.yRot, set_for_controller_.zRot,
//         set_for_controller_.xMove, set_for_controller_.yMove,
//         set_for_controller_.zMove);
//  printf("%d %d %d %d %d %d ", set_for_controller_.LineWidth,
//         set_for_controller_.VertexSize, set_for_controller_.VertexType,
//         set_for_controller_.perspect, set_for_controller_.lineType,
//         set_for_controller_.facets);
//  printf("%d %d %d\n", set_for_controller_.xLight, set_for_controller_.yLight,
//         set_for_controller_.NormalGuro);
}

void Controller::GetSavePictureSignal(char *str_file_name, int type) {
  //    std::cout << "Controller::getSavePictureSignal" << std::endl;
  type_ = type;
  pictureFileName_ = str_file_name;
  MySavePicture_->connectWidget(controled_widget_);
  gifCounter_ = 0;
  emit SendSavePictureSignal(str_file_name, type, set_for_controller_.aspect,
                             gifCounter_);
}

void Controller::GetSaveYRotGifSignal(void) {
  //    std::cout << "Controller::getSaveYRotGifSignal(void)" << std::endl;
  timer_->setInterval(40);
  yRotCounter_ = 0;
  connect(timer_, &QTimer::timeout, this, &Controller::StepsForGifPicture);
  timer_->start(40);
}

void Controller::StepsForGifPicture() {
  //    std::cout << "Controller::stepsForGifPicture() yRotCounter = " <<
  //    yRotCounter_ << std::endl;
  if (yRotCounter_ > -1 && yRotCounter_ < 51) {
    set_for_controller_.yRot += 115;
    EmitSettings();
    yRotCounter_++;
  } else {
    yRotCounter_ = -1;
    disconnect(timer_, &QTimer::timeout, this, &Controller::StepsForGifPicture);
  }
}

void Controller::EmitSettings() {
  //        std::cout << "Hello, you are in Controller::EmitSettings() " <<
  //        std::endl;
  if (gifCounter_ > -1) {
    gifCounter_++;
    if (gifCounter_ < 51) {
      MySavePicture_->connectWidget(controled_widget_);
      emit SendSavePictureSignal(pictureFileName_, type_,
                                 set_for_controller_.aspect, gifCounter_);
    } else {
      gifCounter_ = -1;
    }
  }
  //    std::cout << "set_for_controller_.LineWidth =  " <<
  //    set_for_controller_.LineWidth << std::endl;
  emit SendSettingsToGLWidget(&set_for_controller_);
}

void Controller::GetNormalGuroSignal(int signal) {
  if (signal == 1) {
    set_for_controller_.NormalGuro = 1;
  } else {
    set_for_controller_.NormalGuro = 0;
  }
  EmitSettings();
}

void Controller::RequestFromMainWindowForSettings(void) {
  //    std::cout << "Controller::requestFromMainWindowForSettings " <<
  //    std::endl;
  emit SendSettingsToMainWindow(&start_set_);
}

void Controller::ReadStartPos() {
  //    std::cout << "Controller::read_start_pos() " << std::endl;
  FILE *start_pos;
  setlocale(LC_ALL, "C");
  int error = 0;
  if ((start_pos = fopen("start_pos-v2.pos", "r")) == NULL) {
    emit SendSettingsToMainWindow(&start_set_);
    SaveStartPos();
  } else {
    error +=
        fscanf(start_pos, "%f%f%f%f", &set_for_controller_.Multip,
               &set_for_controller_.RedColor, &set_for_controller_.GreenColor,
               &set_for_controller_.BlueColor);
    error += fscanf(
        start_pos, "%f%f%f%f%f%f", &set_for_controller_.RedColorLine,
        &set_for_controller_.GreenColorLine, &set_for_controller_.BlueColorLine,
        &set_for_controller_.RedColorVertex,
        &set_for_controller_.GreenColorVertex,
        &set_for_controller_.BlueColorVertex);
    error +=
        fscanf(start_pos, "%f%f%f%f%f%f", &set_for_controller_.RedColorFacets,
               &set_for_controller_.GreenColorFacets,
               &set_for_controller_.BlueColorFacets,
               &set_for_controller_.RedColorLight,
               &set_for_controller_.GreenColorLight,
               &set_for_controller_.BlueColorLight);
    error += fscanf(start_pos, "%d%d%d%d%d%d", &set_for_controller_.xRot,
                    &set_for_controller_.yRot, &set_for_controller_.zRot,
                    &set_for_controller_.xMove, &set_for_controller_.yMove,
                    &set_for_controller_.zMove);
    error +=
        fscanf(start_pos, "%d%d%d%d%d%d", &set_for_controller_.LineWidth,
               &set_for_controller_.VertexSize, &set_for_controller_.VertexType,
               &set_for_controller_.perspect, &set_for_controller_.lineType,
               &set_for_controller_.facets);
    error +=
        fscanf(start_pos, "%d%d%d", &set_for_controller_.xLight,
               &set_for_controller_.yLight, &set_for_controller_.NormalGuro);

//    printf("%+.2f %+.2f %+.2f %+.2f ", set_for_controller_.Multip,
//           set_for_controller_.RedColor, set_for_controller_.GreenColor,
//           set_for_controller_.BlueColor);
//    printf("%+.2f %+.2f %+.2f %+.2f %+.2f %+.2f ",
//           set_for_controller_.RedColorLine, set_for_controller_.GreenColorLine,
//           set_for_controller_.BlueColorLine,
//           set_for_controller_.RedColorVertex,
//           set_for_controller_.GreenColorVertex,
//           set_for_controller_.BlueColorVertex);
//    printf("%+.2f %+.2f %+.2f %+.2f %+.2f %+.2f ",
//           set_for_controller_.RedColorFacets,
//           set_for_controller_.GreenColorFacets,
//           set_for_controller_.BlueColorFacets,
//           set_for_controller_.RedColorLight,
//           set_for_controller_.GreenColorLight,
//           set_for_controller_.BlueColorLight);
//    printf("%d %d %d %d %d %d ", set_for_controller_.xRot,
//           set_for_controller_.yRot, set_for_controller_.zRot,
//           set_for_controller_.xMove, set_for_controller_.yMove,
//           set_for_controller_.zMove);
//    printf("%d %d %d %d %d %d ", set_for_controller_.LineWidth,
//           set_for_controller_.VertexSize, set_for_controller_.VertexType,
//           set_for_controller_.perspect, set_for_controller_.lineType,
//           set_for_controller_.facets);
//    printf("%d %d %d\n", set_for_controller_.xLight, set_for_controller_.yLight,
//           set_for_controller_.NormalGuro);
  }
  fclose(start_pos);
  //    std::cout << "on Load m_Multip = " << Multip << std::endl;
  if (error == 31) {
    emit SendSettingsToMainWindow(&set_for_controller_);
  } else {
    emit SendSettingsToMainWindow(&start_set_);
  }
  //    std::cout << "error = " << error << std::endl;
}
