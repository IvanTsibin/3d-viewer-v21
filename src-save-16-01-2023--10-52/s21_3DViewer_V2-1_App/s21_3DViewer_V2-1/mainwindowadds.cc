#include "mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::ConnectControllerToMainWidget(void) {
    connect(MyController_, SIGNAL(SendSettingsToGLWidget(Settings_t *)),
            MyGLWidget, SLOT(getSettingsFromController(Settings_t *)));
    connect(MyGLWidget, SIGNAL(sendSettingsToController(Settings_t *)),
            MyController_, SLOT(SettingsFromGLWidgetToController(Settings_t *)));
    connect(this, SIGNAL(SendRequestForSettings(void)), MyController_,
            SLOT(RequestFromMainWindowForSettings(void)));
    connect(this, SIGNAL(SendSaveSettingsSignal(void)), MyController_,
            SLOT(SaveStartPos(void)));
    connect(this, SIGNAL(SendRequestForSavedSettings(void)), MyController_,
            SLOT(ReadStartPos(void)));
    connect(MyController_, SIGNAL(SendSettingsToMainWindow(Settings_t *)), this,
            SLOT(GetSettingsFromController(Settings_t *)));
    connect(this, &MainWindow::SendFileName, MyGLWidget,
            &GLWidget::GetFileName);
    connect(MyGLWidget, &GLWidget::SendVertexesAmount, this,
            &MainWindow::GetVertexesAmount);
    connect(MyGLWidget, &GLWidget::SendFacetsAmount, this,
            &MainWindow::GetFacetsAmount);
    connect(MyGLWidget, SIGNAL(SaveStartPos()), MyController_,
            SLOT(SaveStartPos()));
    connect(ui->CBFacets, &QCheckBox::toggled, MyController_,
            &Controller::GetFacetsStatus);
    connect(ui->xSlider, &QSlider::valueChanged, MyController_,
            &Controller::SetXRotation);
    connect(MyController_, &Controller::XRotationChanged, ui->xSlider,
            &QSlider::setValue);
    connect(ui->ySlider, &QSlider::valueChanged, MyController_,
            &Controller::SetYRotation);
    connect(MyController_, &Controller::YRotationChanged, ui->ySlider,
            &QSlider::setValue);
    connect(ui->zSlider, &QSlider::valueChanged, MyController_,
            &Controller::SetZRotation);
    connect(MyController_, &Controller::ZRotationChanged, ui->zSlider,
            &QSlider::setValue);
    connect(ui->MultipSlider, &QSlider::valueChanged, MyController_,
            &Controller::SetMultip);
    connect(MyController_, &Controller::MultipChanged, ui->MultipSlider,
            &QSlider::setValue);
    connect(ui->xMoveSlider, &QSlider::valueChanged, MyController_,
            &Controller::SetXMove);
    connect(ui->yMoveSlider, &QSlider::valueChanged, MyController_,
            &Controller::SetYMove);
    connect(ui->zMoveSlider, &QSlider::valueChanged, MyController_,
            &Controller::SetZMove);
    connect(ui->xLightSlider, &QSlider::valueChanged, MyController_,
            &Controller::SetXLight);
    connect(ui->yLightSlider, &QSlider::valueChanged, MyController_,
            &Controller::SetYLight);
    connect(this, &MainWindow::SendRedColor, MyController_,
            &Controller::SetRedColor);
    connect(this, &MainWindow::SendGreenColor, MyController_,
            &Controller::SetGreenColor);
    connect(this, &MainWindow::SendBlueColor, MyController_,
            &Controller::SetBlueColor);
    connect(this, &MainWindow::SendRedColorLine, MyController_,
            &Controller::SetRedColorLine);
    connect(this, &MainWindow::SendGreenColorLine, MyController_,
            &Controller::SetGreenColorLine);
    connect(this, &MainWindow::SendBlueColorLine, MyController_,
            &Controller::SetBlueColorLine);
    connect(this, &MainWindow::SendRedColorVertex, MyController_,
            &Controller::SetRedColorVertex);
    connect(this, &MainWindow::SendGreenColorVertex, MyController_,
            &Controller::SetGreenColorVertex);
    connect(this, &MainWindow::SendBlueColorVertex, MyController_,
            &Controller::SetBlueColorVertex);
    connect(this, &MainWindow::SendRedColorFacets, MyController_,
            &Controller::SetRedColorFacets);
    connect(this, &MainWindow::SendGreenColorFacets, MyController_,
            &Controller::SetGreenColorFacets);
    connect(this, &MainWindow::SendBlueColorFacets, MyController_,
            &Controller::SetBlueColorFacets);
    connect(this, &MainWindow::SendRedColorLight, MyController_,
            &Controller::SetRedColorLight);
    connect(this, &MainWindow::SendGreenColorLight, MyController_,
            &Controller::SetGreenColorLight);
    connect(this, &MainWindow::SendBlueColorLight, MyController_,
            &Controller::SetBlueColorLight);
    connect(this, &MainWindow::SendLineWidth, MyController_,
            &Controller::SetLineWidth);
    connect(this, &MainWindow::SendVertexSize, MyController_,
            &Controller::SetVertexSize);
    connect(this, &MainWindow::SendVertexType, MyController_,
            &Controller::SetVertexType);
    connect(this, &MainWindow::SendPerspectStatus, MyController_,
            &Controller::SetPerspectiveStatus);
    connect(this, &MainWindow::SendFacetsStatus, MyController_,
            &Controller::SetFacetsStatus);
    connect(this, &MainWindow::SendDashLineSignal, MyController_,
            &Controller::SetDashLineSignal);
    connect(this, &MainWindow::SendNormalGuroSignal, MyController_,
            &Controller::GetNormalGuroSignal);
    connect(this, &MainWindow::SendSavePictureSignal, MyController_,
            &Controller::GetSavePictureSignal);
    connect(ui->PByRotGif, &QPushButton::clicked, MyController_,
            &Controller::GetSaveYRotGifSignal);
}

void MainWindow::on_MainWindow_iconSizeChanged(const QSize &iconSize) {
  if (iconSize.width() > 100)
    emit SendMainWindowSizeChanged(iconSize);
}

void MainWindow::on_InputObject_2_clicked() {
  QString str = QFileDialog::getOpenFileName(
      this, tr("Choose obj file"), QDir::currentPath(),
      tr("OBJ Image (*.obj);; All Files (*.*);; JPEG Image (*.jpg)"));
  QFileInfo fileinfo(str);
  QString str_1 = fileinfo.fileName();
  ui->ObjFileName->setText(str_1);
  QString str_2 = fileinfo.filePath();
  ui->ObjFilePath->setText(str_2);
}

void MainWindow::on_PBDraw_2_clicked() {
  char path[255] = "";
  if (ui->ObjFilePath->text() != "home directory" || ui->ObjFilePath->text() != "") {
    QByteArray bytes_2 = ui->ObjFilePath->text().toLocal8Bit();
    strcpy(path, bytes_2.data());
    emit SendFileName(path);
  }
}

void MainWindow::GetVertexesAmount(int amount) {
  QString vertexes_amount_str = QString::number(amount, 'f', 0);
  ui->LBAmountOfVertexes_2->setText(vertexes_amount_str);
}

void MainWindow::GetFacetsAmount(int amount) {
  QString facets_amount_str = QString::number(amount, 'f', 0);
  ui->LBAmountOfFacets_2->setText(facets_amount_str);
}

void MainWindow::on_SBRedColor_valueChanged(int arg1) {
  emit SendRedColor(arg1);
}

void MainWindow::on_SBGreenColor_valueChanged(int arg1) {
  emit SendGreenColor(arg1);
}

void MainWindow::on_SBBlueColor_valueChanged(int arg1) {
  emit SendBlueColor(arg1);
}

void MainWindow::on_SBRedColorLine_valueChanged(int arg1) {
  emit SendRedColorLine(arg1);
}

void MainWindow::on_SBGreenColorLine_valueChanged(int arg1) {
  emit SendGreenColorLine(arg1);
}

void MainWindow::on_SBBlueColorLine_valueChanged(int arg1) {
  emit SendBlueColorLine(arg1);
}

void MainWindow::on_SBRedColorVertex_valueChanged(int arg1) {
  emit SendRedColorVertex(arg1);
}

void MainWindow::on_SBGreenColorVertex_valueChanged(int arg1) {
  emit SendGreenColorVertex(arg1);
}

void MainWindow::on_SBBlueColorVertex_valueChanged(int arg1) {
  emit SendBlueColorVertex(arg1);
}

void MainWindow::on_SBRedFacets_valueChanged(int arg1) {
  emit SendRedColorFacets(arg1);
}

void MainWindow::on_SBGreenFacets_valueChanged(int arg1) {
  emit SendGreenColorFacets(arg1);
}

void MainWindow::on_SBBlueFacets_valueChanged(int arg1) {
  emit SendBlueColorFacets(arg1);
}

void MainWindow::on_SBRedLight_valueChanged(int arg1) {
  emit SendRedColorLight(arg1);
}

void MainWindow::on_SBGreenLight_valueChanged(int arg1) {
  emit SendGreenColorLight(arg1);
}

void MainWindow::on_SBBlueLight_valueChanged(int arg1) {
  emit SendBlueColorLight(arg1);
}

void MainWindow::on_SBLineWidth_valueChanged(int arg1) {
  //    std::cout << "MainWindow::on_SBLineWidth_valueChanged(int arg1) arg1 = "
  //    << arg1 << std::endl;
  emit SendLineWidth(arg1);
}

void MainWindow::on_SBVertexSize_valueChanged(int arg1) {
  emit SendVertexSize(arg1);
}

void MainWindow::on_CBVertexType_currentTextChanged(const QString &arg1) {
  if (arg1 == "none") {
    emit SendVertexType(0);
  } else if (arg1 == "circle") {
    emit SendVertexType(1);
  } else {
    emit SendVertexType(2);
  }
}

void MainWindow::on_CBPerspective_toggled(bool checked) {
  emit SendPerspectStatus((int)checked);
}

void MainWindow::on_CBFacets_toggled(bool checked) {
  emit SendFacetsStatus((int)checked);
}

void MainWindow::on_CBDashLine_toggled(bool checked) {
  emit SendDashLineSignal((int)checked);
}

void MainWindow::ReadStartPos() {
  //    std::cout << "MainWindow::ReadStartPos() MWSet_.Multip = " <<
  //    MWSet_.Multip << std::endl;
  FILE *start_pos;
  if ((start_pos = fopen("start_pos-v2.pos", "r")) == NULL) {
    emit SendSaveSettingsSignal();
  } else {
    emit SendRequestForSavedSettings();
    ApplySettingsToMainWindow();
  }
  fclose(start_pos);
  //    std::cout << "on Load m_Multip = " << Multip << std::endl;

  //    std::cout << "error = " << error << std::endl;
}

void MainWindow::ApplySettingsToMainWindow(void) {
  //        std::cout << "MainWindow::ApplySettingsToMainWindow " <<
  //        std::endl;
  ui->MultipSlider->setValue((int)(MWSet_.Multip * 100));
  ui->zMoveSlider->setSliderPosition((int)MWSet_.Multip);
  ui->MultipSlider->repaint();
  ui->SBRedColor->setValue((int)(MWSet_.RedColor * 255));
  ui->SBRedColor->repaint();
  ui->SBGreenColor->setValue((int)(MWSet_.GreenColor * 255));
  ui->SBGreenColor->repaint();
  ui->SBBlueColor->setValue((int)(MWSet_.BlueColor * 255));
  ui->SBBlueColor->repaint();
  ui->SBRedColorLine->setValue((int)(MWSet_.RedColorLine * 255));
  ui->SBRedColorLine->repaint();
  ui->SBGreenColorLine->setValue((int)(MWSet_.GreenColorLine * 255));
  ui->SBGreenColorLine->repaint();
  ui->SBBlueColorLine->setValue((int)(MWSet_.BlueColorLine * 255));
  ui->SBBlueColorLine->repaint();
  ui->SBRedColorVertex->setValue((int)(MWSet_.RedColorVertex * 255));
  ui->SBRedColorVertex->repaint();
  ui->SBGreenColorVertex->setValue((int)(MWSet_.GreenColorVertex * 255));
  ui->SBGreenColorVertex->repaint();
  ui->SBBlueColorVertex->setValue((int)(MWSet_.BlueColorVertex * 255));
  ui->SBBlueColorVertex->repaint();
  ui->SBRedFacets->setValue((int)(MWSet_.RedColorFacets * 255));
  ui->SBRedFacets->repaint();
  ui->SBGreenFacets->setValue((int)(MWSet_.GreenColorFacets * 255));
  ui->SBGreenFacets->repaint();
  ui->SBBlueFacets->setValue((int)(MWSet_.BlueColorFacets * 255));
  ui->SBBlueFacets->repaint();
  ui->SBRedLight->setValue((int)(MWSet_.RedColorLight * 255));
  ui->SBRedLight->repaint();
  ui->SBGreenLight->setValue((int)(MWSet_.GreenColorLight * 255));
  ui->SBGreenLight->repaint();
  ui->SBBlueLight->setValue((int)(MWSet_.BlueColorLight * 255));
  ui->SBBlueLight->repaint();
  ui->xSlider->setValue(MWSet_.xRot);
  ui->xSlider->setSliderPosition(MWSet_.xRot);
  ui->xSlider->repaint();
  ui->ySlider->setValue(MWSet_.yRot);
  ui->ySlider->setSliderPosition(MWSet_.yRot);
  ui->ySlider->repaint();
  ui->zSlider->setValue(MWSet_.zRot);
  ui->zSlider->setSliderPosition(MWSet_.zRot);
  ui->zSlider->repaint();
  ui->xMoveSlider->setValue(MWSet_.xMove);
  ui->xMoveSlider->setSliderPosition(MWSet_.xMove);
  ui->xMoveSlider->repaint();
  ui->yMoveSlider->setValue(MWSet_.yMove);
  ui->yMoveSlider->setSliderPosition(MWSet_.yMove);
  ui->yMoveSlider->repaint();
  ui->zMoveSlider->setValue(MWSet_.zMove);
  ui->zMoveSlider->setSliderPosition(MWSet_.zMove);
  ui->zMoveSlider->repaint();
  ui->xLightSlider->setValue(MWSet_.xLight);
  ui->xLightSlider->setSliderPosition(MWSet_.xLight);
  ui->xLightSlider->repaint();
  ui->yLightSlider->setValue(MWSet_.yLight);
  ui->yLightSlider->setSliderPosition(MWSet_.yLight);
  ui->xLightSlider->repaint();
  ui->SBLineWidth->setValue(MWSet_.LineWidth);
  ui->SBLineWidth->repaint();
  ui->SBVertexSize->setValue(MWSet_.VertexSize);
  ui->SBVertexSize->repaint();
  ui->CBVertexType->setCurrentIndex(MWSet_.VertexType);
  ui->SBVertexSize->repaint();
  ui->CBPerspective->setChecked(bool(MWSet_.perspect));
  ui->CBPerspective->repaint();
  ui->CBDashLine->setChecked(bool(MWSet_.lineType));
  ui->CBDashLine->repaint();
  ui->CBFacets->setChecked(bool(MWSet_.facets));
  ui->CBFacets->repaint();
  ui->CBNormalGuro->setChecked(bool(MWSet_.NormalGuro));
  ui->CBNormalGuro->repaint();
}

void MainWindow::on_PBToZero_clicked() {
  emit SendRequestForSettings();
  ApplySettingsToMainWindow();
}

void MainWindow::on_PBJpgPhoto_clicked() { SavePictureViaType(0); }

void MainWindow::on_PBBmpPhoto_clicked() { SavePictureViaType(1); }

void MainWindow::on_PBGifMovie_clicked() { SavePictureViaType(2); }

void MainWindow::SavePictureViaType(int type) {
  char path[255] = "";
  if (ui->ObjFilePath->text() != "home directory") {
    QByteArray bytes_2 = ui->ObjFilePath->text().toLocal8Bit();
    strcpy(path, bytes_2.data());
  } else {
    QByteArray bytes = ui->ObjFileName->text().toLocal8Bit();
    strcpy(path, bytes.data());
  }
  emit SendSavePictureSignal(path, type);
}

void MainWindow::on_xSlider_valueChanged(int value) {
  ui->SBxRot->setValue(value / 16);
}

void MainWindow::on_ySlider_valueChanged(int value) {
  ui->SByRot->setValue(value / 16);
}

void MainWindow::on_zSlider_valueChanged(int value) {
  ui->SBzRot->setValue(value / 16);
}

void MainWindow::on_MultipSlider_valueChanged(int value) {
  ui->DSBMultip->setValue(round((double)(value)) / 100);
}

void MainWindow::on_xMoveSlider_valueChanged(int value) {
  ui->DSBxMove->setValue(round((double)value) / 100);
}

void MainWindow::on_yMoveSlider_valueChanged(int value) {
  ui->DSByMove->setValue(round((double)value) / 100);
}

void MainWindow::on_zMoveSlider_valueChanged(int value) {
  ui->DSBzMove->setValue(round((double)value) / 100);
}

void MainWindow::on_xLightSlider_valueChanged(int value) {
  ui->DSBxLight->setValue(((double)value) / 100);
}

void MainWindow::on_yLightSlider_valueChanged(int value) {
  ui->DSByLight->setValue(((double)value) / 100);
}

void MainWindow::on_SBxRot_valueChanged(int arg1) {
  ui->xSlider->setValue(arg1 * 16);
}

void MainWindow::on_SByRot_valueChanged(int arg1) {
  ui->ySlider->setValue(arg1 * 16);
}

void MainWindow::on_SBzRot_valueChanged(int arg1) {
  ui->zSlider->setValue(arg1 * 16);
}

void MainWindow::on_DSBMultip_valueChanged(double arg1) {
  int temp = (int)round((arg1 * 100));
  ui->MultipSlider->setValue(temp);
  ui->MultipSlider->setSliderPosition(temp);
}

void MainWindow::on_DSBxMove_valueChanged(double arg1) {
  int temp = (int)round(arg1 * 100);
  ui->xMoveSlider->setValue(temp);
  ui->xMoveSlider->setSliderPosition(temp);
}

void MainWindow::on_DSByMove_valueChanged(double arg1) {
  int temp = (int)round(arg1 * 100);
  ui->yMoveSlider->setValue(temp);
  ui->yMoveSlider->setSliderPosition(temp);
}

void MainWindow::on_DSBzMove_valueChanged(double arg1) {
  int temp = (int)round(arg1 * 100);
  ui->zMoveSlider->setValue(temp);
  ui->zMoveSlider->setSliderPosition(temp);
}

void MainWindow::on_DSBxLight_valueChanged(double arg1) {
  ui->xLightSlider->setValue((int)(arg1 * 100));
  ui->xLightSlider->setSliderPosition((int)(arg1 * 100));
}

void MainWindow::on_DSByLight_valueChanged(double arg1) {
  ui->yLightSlider->setValue((int)(arg1 * 100));
  ui->yLightSlider->setSliderPosition((int)(arg1 * 100));
}

void MainWindow::on_PByRotGif_clicked() { on_PBGifMovie_clicked(); }

void MainWindow::on_CBNormalGuro_toggled(bool checked) {
  emit SendNormalGuroSignal((int)checked);
}

void MainWindow::GetSettingsFromController(Settings_t *set_) {
  MWSet_ = *set_;
  //   std::cout << "MainWindow::GetSettingsFromController(settings_t *set_)
  //   MWSet_.facets = " << MWSet_.facets  << std::endl;
}
