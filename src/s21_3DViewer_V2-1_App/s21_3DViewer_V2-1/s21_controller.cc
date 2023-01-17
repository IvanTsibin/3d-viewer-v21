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
//  start_set_.ColorScene.name() = "#333333";
//  start_set_.ColorLine.name() = "#cd8033";
//  start_set_.ColorVertex.name() = "#80cd33";
//  start_set_.ColorFacets.name() = "#8033cd";
//  start_set_.ColorLight.name() = "#ffffff";
  start_set_.ColorScene.setRgbF(0.2, 0.2, 0.2);
  start_set_.ColorLine.setRgbF(0.8, 0.5,0.2);
  start_set_.ColorVertex.setRgbF(0.5, 0.8,0.2);
  start_set_.ColorFacets.setRgbF(0.5, 0.2,0.8);
  start_set_.ColorLight.setRgbF(1.0, 1.0,1.0);
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

void Controller::SetSceneColor(QColor SceneColor) {
    set_for_controller_.ColorScene = SceneColor;
    emit SendSettingsToMainWindow(&set_for_controller_);
  SendLablesColorChangeSignal();
EmitSettings();
}
void Controller::SetLineColor(QColor LineColor) {
    set_for_controller_.ColorLine = LineColor;
    emit SendSettingsToMainWindow(&set_for_controller_);
  SendLablesColorChangeSignal();
EmitSettings();
}
void Controller::SetVertexColor(QColor VertexColor) {
    set_for_controller_.ColorVertex = VertexColor;
    emit SendSettingsToMainWindow(&set_for_controller_);
  SendLablesColorChangeSignal();
EmitSettings();
}
void Controller::SetFacetsColor(QColor FacetsColor) {
    set_for_controller_.ColorFacets = FacetsColor;
    emit SendSettingsToMainWindow(&set_for_controller_);
  SendLablesColorChangeSignal();
EmitSettings();
}
void Controller::SetLightColor(QColor LightColor) {
    set_for_controller_.ColorLight = LightColor;
    emit SendSettingsToMainWindow(&set_for_controller_);
  SendLablesColorChangeSignal();
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
  std::cout << "Let's save file - Let's write in it!!!" << std::endl;
  setlocale(LC_ALL, "C");
  FILE *start_pos;
  start_pos = fopen("start_pos-v3.pos", "w");
  fprintf(start_pos, "%.2lf %.2lf %.2lf %.2lf ", set_for_controller_.Multip,
          set_for_controller_.ColorScene.redF(), set_for_controller_.ColorScene.greenF(),
          set_for_controller_.ColorScene.blueF());
  fprintf(start_pos, "%.2lf %.2lf %.2lf %.2lf %.2lf %.2lf ",
          set_for_controller_.ColorLine.redF(), set_for_controller_.ColorLine.greenF(),
          set_for_controller_.ColorLine.blueF(), set_for_controller_.ColorVertex.redF(),
          set_for_controller_.ColorVertex.greenF(),
          set_for_controller_.ColorVertex.blueF());
  fprintf(
      start_pos, "%.2lf %.2lf %.2lf %.2lf %.2lf %.2lf ",
      set_for_controller_.ColorFacets.redF(), set_for_controller_.ColorFacets.greenF(),
      set_for_controller_.ColorFacets.blueF(), set_for_controller_.ColorLight.redF(),
      set_for_controller_.ColorLight.greenF(), set_for_controller_.ColorLight.blueF());
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

  printf("%+.2f %+.2f %+.2f %+.2f ", set_for_controller_.Multip,
          set_for_controller_.ColorScene.redF(), set_for_controller_.ColorScene.greenF(),
          set_for_controller_.ColorScene.blueF());
  printf("%+.2f %+.2f %+.2f %+.2f %+.2f %+.2f ",
          set_for_controller_.ColorLine.redF(), set_for_controller_.ColorLine.greenF(),
          set_for_controller_.ColorLine.blueF(), set_for_controller_.ColorVertex.redF(),
          set_for_controller_.ColorVertex.greenF(),
          set_for_controller_.ColorVertex.blueF());
  printf(
      "%+.2f %+.2f %+.2f %+.2f %+.2f %+.2f ",
      set_for_controller_.ColorFacets.redF(), set_for_controller_.ColorFacets.greenF(),
      set_for_controller_.ColorFacets.blueF(), set_for_controller_.ColorLight.redF(),
      set_for_controller_.ColorLight.greenF(), set_for_controller_.ColorLight.blueF());
  printf("%d %d %d %d %d %d ", set_for_controller_.xRot,
          set_for_controller_.yRot, set_for_controller_.zRot,
          set_for_controller_.xMove, set_for_controller_.yMove,
          set_for_controller_.zMove);
  printf("%d %d %d %d %d %d ", set_for_controller_.LineWidth,
          set_for_controller_.VertexSize, set_for_controller_.VertexType,
          set_for_controller_.perspect, set_for_controller_.lineType,
          set_for_controller_.facets);
  printf("%d %d %d \n", set_for_controller_.xLight,
          set_for_controller_.yLight, set_for_controller_.NormalGuro);

}

void Controller::GetSavePictureSignal(char *str_file_name, int type) {
  //    std::cout << "Controller::getSavePictureSignal" << std::endl;
  type_ = type;
  pictureFileName_ = str_file_name;
  MySavePicture_->connectWidget(controled_widget_);
  gifCounter_ = 0;
  if (type == 3) {GetSaveYRotGifSignal();}
  emit SendSavePictureSignal(pictureFileName_, type_, set_for_controller_.aspect,
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
      std::cout << " Controller::ReadStartPosNew() " << std::endl;
  FILE *start_pos;
  setlocale(LC_ALL, "C");
  int error = 0;
  float
            RedColor ,
            GreenColor ,
            BlueColor ,
            RedColorLine ,
            GreenColorLine ,
            BlueColorLine ,
            RedColorVertex ,
            GreenColorVertex ,
            BlueColorVertex ,
            RedColorFacets ,
            GreenColorFacets ,
            BlueColorFacets ,
            RedColorLight ,
            GreenColorLight ,
            BlueColorLight;
  if ((start_pos = fopen("start_pos-v3.pos", "r")) == NULL) {
     std::cout << " Didn't find any file - sorry - have to start with start_set_ " << std::endl;
    emit SendSettingsToMainWindow(&start_set_);
    SaveStartPos();
  } else {
    error +=
        fscanf(start_pos, "%f%f%f%f", &set_for_controller_.Multip,
               &RedColor, &GreenColor,
               &BlueColor);
    error += fscanf(
        start_pos, "%f%f%f%f%f%f", &RedColorLine,
        &GreenColorLine, &BlueColorLine,
        &RedColorVertex,
        &GreenColorVertex,
        &BlueColorVertex);
    error +=
        fscanf(start_pos, "%f%f%f%f%f%f", &RedColorFacets,
               &GreenColorFacets,
               &BlueColorFacets,
               &RedColorLight,
               &GreenColorLight,
               &BlueColorLight);
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
    set_for_controller_.ColorScene.setRgbF(RedColor, GreenColor, BlueColor);
    set_for_controller_.ColorLine.setRgbF(RedColorLine, GreenColorLine,BlueColorLine);
    set_for_controller_.ColorVertex.setRgbF(RedColorVertex, GreenColorVertex,BlueColorVertex);
    set_for_controller_.ColorFacets.setRgbF(RedColorFacets, GreenColorFacets,BlueColorFacets);
    set_for_controller_.ColorLight.setRgbF(RedColorLight, GreenColorLight,BlueColorLight);
  }
  fclose(start_pos);
    printf("%+.2f %+.2f %+.2f %+.2f ", set_for_controller_.Multip,
            set_for_controller_.ColorScene.redF(), set_for_controller_.ColorScene.greenF(),
            set_for_controller_.ColorScene.blueF());
    printf("%+.2f %+.2f %+.2f %+.2f %+.2f %+.2f ",
            set_for_controller_.ColorLine.redF(), set_for_controller_.ColorLine.greenF(),
            set_for_controller_.ColorLine.blueF(), set_for_controller_.ColorVertex.redF(),
            set_for_controller_.ColorVertex.greenF(),
            set_for_controller_.ColorVertex.blueF());
    printf(
        "%+.2f %+.2f %+.2f %+.2f %+.2f %+.2f ",
        set_for_controller_.ColorFacets.redF(), set_for_controller_.ColorFacets.greenF(),
        set_for_controller_.ColorFacets.blueF(), set_for_controller_.ColorLight.redF(),
        set_for_controller_.ColorLight.greenF(), set_for_controller_.ColorLight.blueF());
    printf("%d %d %d %d %d %d ", set_for_controller_.xRot,
            set_for_controller_.yRot, set_for_controller_.zRot,
            set_for_controller_.xMove, set_for_controller_.yMove,
            set_for_controller_.zMove);
    printf("%d %d %d %d %d %d ", set_for_controller_.LineWidth,
            set_for_controller_.VertexSize, set_for_controller_.VertexType,
            set_for_controller_.perspect, set_for_controller_.lineType,
            set_for_controller_.facets);
    printf("%d %d %d \n", set_for_controller_.xLight,
            set_for_controller_.yLight, set_for_controller_.NormalGuro);

  std::cout << "error = " << error << std::endl;
    if (error == 31) {
    emit SendSettingsToMainWindow(&set_for_controller_);
  } else {
    emit SendSettingsToMainWindow(&start_set_);
  }
  //    std::cout << "error = " << error << std::endl;
}
