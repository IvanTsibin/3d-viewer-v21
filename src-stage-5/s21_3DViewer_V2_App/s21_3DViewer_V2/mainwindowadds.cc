#include "mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::on_MainWindow_iconSizeChanged(const QSize &iconSize)
{
    if (iconSize.width() > 100) emit send_main_window_size_changed(iconSize);
}

void MainWindow::on_InputObject_2_clicked()
{
    QString str = QFileDialog::getOpenFileName(this, tr("Choose obj file"),
    QDir::currentPath(),tr("OBJ Image (*.obj);; All Files (*.*);; JPEG Image (*.jpg)"));
    QFileInfo fileinfo(str);
    QString str_1 = fileinfo.fileName();
    ui->ObjFileName->setText(str_1);
    QString str_2 = fileinfo.filePath();
    ui->ObjFilePath->setText(str_2);
}

void MainWindow::on_PBDraw_2_clicked()
{
    char path[255] = "";
    if (ui->ObjFilePath->text() != "home directory") {
         QByteArray bytes_2 = ui->ObjFilePath->text().toLocal8Bit();
         strcpy(path, bytes_2.data());
          emit send_file_name(path);
    }
}

void MainWindow::get_vertexes_amount(int amount) {
    QString vertexes_amount_str = QString::number(amount, 'f', 0);
    ui->LBAmountOfVertexes_2->setText(vertexes_amount_str);
}

void MainWindow::get_facets_amount(int amount) {
    QString facets_amount_str = QString::number(amount, 'f', 0);
    ui->LBAmountOfFacets_2->setText(facets_amount_str);
}

void MainWindow::on_SBRedColor_valueChanged(int arg1)
{
    emit send_red_color(arg1);
}

void MainWindow::on_SBGreenColor_valueChanged(int arg1)
{
    emit send_green_color(arg1);
}

void MainWindow::on_SBBlueColor_valueChanged(int arg1)
{
    emit send_blue_color(arg1);
}

void MainWindow::on_SBRedColorLine_valueChanged(int arg1)
{
    emit send_red_color_line(arg1);
}

void MainWindow::on_SBGreenColorLine_valueChanged(int arg1)
{
    emit send_green_color_line(arg1);
}

void MainWindow::on_SBBlueColorLine_valueChanged(int arg1)
{
    emit send_blue_color_line(arg1);
}

void MainWindow::on_SBRedColorVertex_valueChanged(int arg1)
{
    emit send_red_color_vertex(arg1);
}

void MainWindow::on_SBGreenColorVertex_valueChanged(int arg1)
{
    emit send_green_color_vertex(arg1);
}

void MainWindow::on_SBBlueColorVertex_valueChanged(int arg1)
{
    emit send_blue_color_vertex(arg1);
}

void MainWindow::on_SBLineWidth_valueChanged(int arg1)
{
    emit send_line_width(arg1);
}

void MainWindow::on_SBVertexSize_valueChanged(int arg1)
{
    emit send_vertex_size(arg1);
}

void MainWindow::on_CBVertexType_currentTextChanged(const QString &arg1)
{
    if (arg1 == "none") {
        emit send_vertex_type(0);
    } else if (arg1 == "circle") {
        emit send_vertex_type(1);
    } else {
        emit send_vertex_type(2);
    }
}

void MainWindow::on_CBPerspective_toggled(bool checked)
{
    if (checked) {
        emit send_perspect_status(1);
//        std::cout << "Perspective is checked" << std::endl;
    } else {
        emit send_perspect_status(0);
//        std::cout << "Perspective is NOT checked" << std::endl;
    }
}

void MainWindow::on_CBFacets_toggled(bool checked)
{
    if (checked) {
        emit send_facets_status(1);
//        std::cout << "Perspective is checked" << std::endl;
    } else {
        emit send_facets_status(0);
//        std::cout << "Perspective is NOT checked" << std::endl;
    }
}

void MainWindow::on_CBDashLine_toggled(bool checked)
{
    if (checked) {
        emit send_dash_line_signal(1);
    } else {
        emit send_dash_line_signal(0);
    }
}

void MainWindow::read_start_pos() {
    FILE *start_pos;

    float Multip = 0.0, RedC = 0.2, GreenC = 0.2, BlueC = 0.2;
    float RedCL = 0.8, GreenCL = 0.5, BlueCL = 0.2, RedCV = 0.5, GreenCV = 0.8, BlueCV = 0.2;
    int xRot = 0, yRot = 0, zRot = 0, xMove = 0, yMove = 0, zMove = 0, error = 0;
    int LineWidth = 1, VertexSize = 5, VertexType = 0, perspect = 1, lineType = 0, facets = 1;

    if ((start_pos = fopen("start_pos-v2.pos", "r")) == NULL) {
        start_pos = fopen("start_pos-v2.pos", "w");
        fprintf(start_pos, "%.2lf %.2lf %.2lf %.2lf ", 1.0, 0.2, 0.2, 0.2);
        fprintf(start_pos, "%.2lf %.2lf %.2lf %.2lf %.2lf %.2lf", 0.8, 0.5, 0.2, 0.5, 0.8, 0.2);
        fprintf(start_pos, "%d %d %d %d %d %d ", 0, 0, 0, 0, 0, 0);
        fprintf(start_pos, "%d %d %d %d %d ", 1, 1, 0, 0, 0);
//        std::cout << "Didn't find a file - Let's creat it!!!" << std::endl;
    } else {
//        std::cout << "We found file - Let's write in it!!!" << std::endl;
        char Multip_str[20] = {0}, RedC_str[20] = {0}, GreenC_str[20] = {0}, BlueC_str[20] = {0};
        char RedCL_str[20] = {0}, GreenCL_str[20] = {0}, BlueCL_str[20] = {0}, RedCV_str[20] = {0}, GreenCV_str[20] = {0}, BlueCV_str[20] = {0};
        error += fscanf(start_pos, "%s%s%s%s", Multip_str, RedC_str, GreenC_str, BlueC_str);
        error += fscanf(start_pos, "%s%s%s%s%s%s", RedCL_str, GreenCL_str, BlueCL_str, RedCV_str, GreenCV_str, BlueCV_str);
        error += fscanf(start_pos, "%d%d%d%d%d%d", &xRot, &yRot, &zRot, &xMove, &yMove, &zMove);
        error += fscanf(start_pos, "%d%d%d%d%d%d", &LineWidth, &VertexSize, &VertexType, &perspect, &lineType, &facets);

        Multip = convert_str_to_double(Multip_str, strlen(Multip_str));
        RedC = convert_str_to_double(RedC_str, strlen(RedC_str));
        GreenC = convert_str_to_double(GreenC_str, strlen(GreenC_str));
        BlueC = convert_str_to_double(BlueC_str, strlen(BlueC_str));
        RedCL = convert_str_to_double(RedCL_str, strlen(RedCL_str));
        GreenCL = convert_str_to_double(GreenCL_str, strlen(GreenCL_str));
        BlueCL = convert_str_to_double(BlueCL_str, strlen(BlueCL_str));
        RedCV = convert_str_to_double(RedCV_str, strlen(RedCV_str));
        GreenCV = convert_str_to_double(GreenCV_str, strlen(GreenCV_str));
        BlueCV = convert_str_to_double(BlueCV_str, strlen(BlueCV_str));
    }
    fclose(start_pos);
//    std::cout << "on Load m_Multip = " << Multip << std::endl;
    ui->MultipSlider->setValue((int)(Multip * 100)); ui->zMoveSlider->setSliderPosition((int)Multip); ui->MultipSlider->repaint();
    ui->SBRedColor->setValue((int)(RedC * 255)); ui->SBRedColor->repaint();
    ui->SBGreenColor->setValue((int)(GreenC * 255)); ui->SBGreenColor->repaint();
    ui->SBBlueColor->setValue((int)(BlueC * 255)); ui->SBBlueColor->repaint();
    ui->SBRedColorLine->setValue((int)(RedCL * 255)); ui->SBRedColorLine->repaint();
    ui->SBGreenColorLine->setValue((int)(GreenCL * 255)); ui->SBGreenColorLine->repaint();
    ui->SBBlueColorLine->setValue((int)(BlueCL * 255)); ui->SBBlueColorLine->repaint();
    ui->SBRedColorVertex->setValue((int)(RedCV * 255)); ui->SBRedColorVertex->repaint();
    ui->SBGreenColorVertex->setValue((int)(GreenCV * 255)); ui->SBGreenColorVertex->repaint();
    ui->SBBlueColorVertex->setValue((int)(BlueCV * 255)); ui->SBBlueColorVertex->repaint();
    ui->xSlider->setValue(xRot); ui->xSlider->setSliderPosition(xRot); ui->xSlider->repaint();
    ui->ySlider->setValue(yRot); ui->ySlider->setSliderPosition(yRot); ui->ySlider->repaint();
    ui->zSlider->setValue(zRot); ui->zSlider->setSliderPosition(zRot); ui->zSlider->repaint();
    ui->xMoveSlider->setValue(xMove); ui->xMoveSlider->setSliderPosition(xMove); ui->xMoveSlider->repaint();
    ui->yMoveSlider->setValue(yMove); ui->yMoveSlider->setSliderPosition(yMove); ui->yMoveSlider->repaint();
    ui->zMoveSlider->setValue(zMove); ui->zMoveSlider->setSliderPosition(zMove); ui->zMoveSlider->repaint();
    ui->SBLineWidth->setValue(LineWidth); ui->SBLineWidth->repaint();
    ui->SBVertexSize->setValue(VertexSize); ui->SBVertexSize->repaint();
    ui->CBVertexType->setCurrentIndex(VertexType); ui->SBVertexSize->repaint();
    if (perspect == 1) {
        ui->CBPerspective->setChecked(true);
    } else {
        ui->CBPerspective->setChecked(false);
    }
    ui->CBPerspective->repaint();
    if (lineType == 1) {
        ui->CBDashLine->setChecked(true);
    } else {
        ui->CBDashLine->setChecked(false);
    }
    ui->CBDashLine->repaint();
    if (facets == 1) {
        ui->CBFacets->setChecked(true);
    } else {
        ui->CBFacets->setChecked(false);
    }
    ui->CBFacets->repaint();
//    std::cout << "error = " << error << std::endl;
}

double MainWindow::convert_str_to_double(char number[], int counter) {
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

void MainWindow::on_PBToZero_clicked()
{
    float Multip = 0.0, RedC = 0.2, GreenC = 0.2, BlueC = 0.2;
    float RedCL = 0.8, GreenCL = 0.5, BlueCL = 0.2, RedCV = 0.5, GreenCV = 0.8, BlueCV = 0.2;
    int xRot = 0, yRot = 0, zRot = 0, xMove = 0, yMove = 0, zMove = 0;
    int LineWidth = 1, VertexSize = 5, VertexType = 0, perspect = 1, lineType = 0;

    ui->MultipSlider->setValue((int)(Multip * 100)); ui->zMoveSlider->setSliderPosition((int)Multip); ui->MultipSlider->repaint();
    ui->SBRedColor->setValue((int)(RedC * 255)); ui->SBRedColor->repaint();
    ui->SBGreenColor->setValue((int)(GreenC * 255)); ui->SBGreenColor->repaint();
    ui->SBBlueColor->setValue((int)(BlueC * 255)); ui->SBBlueColor->repaint();
    ui->SBRedColorLine->setValue((int)(RedCL * 255)); ui->SBRedColorLine->repaint();
    ui->SBGreenColorLine->setValue((int)(GreenCL * 255)); ui->SBGreenColorLine->repaint();
    ui->SBBlueColorLine->setValue((int)(BlueCL * 255)); ui->SBBlueColorLine->repaint();
    ui->SBRedColorVertex->setValue((int)(RedCV * 255)); ui->SBRedColorVertex->repaint();
    ui->SBGreenColorVertex->setValue((int)(GreenCV * 255)); ui->SBGreenColorVertex->repaint();
    ui->SBBlueColorVertex->setValue((int)(BlueCV * 255)); ui->SBBlueColorVertex->repaint();
    ui->xSlider->setValue(xRot); ui->xSlider->setSliderPosition(xRot); ui->xSlider->repaint();
    ui->ySlider->setValue(yRot); ui->ySlider->setSliderPosition(yRot); ui->ySlider->repaint();
    ui->zSlider->setValue(zRot); ui->zSlider->setSliderPosition(zRot); ui->zSlider->repaint();
    ui->xMoveSlider->setValue(xMove); ui->xMoveSlider->setSliderPosition(xMove); ui->xMoveSlider->repaint();
    ui->yMoveSlider->setValue(yMove); ui->yMoveSlider->setSliderPosition(yMove); ui->yMoveSlider->repaint();
    ui->zMoveSlider->setValue(zMove); ui->zMoveSlider->setSliderPosition(zMove); ui->zMoveSlider->repaint();
    ui->SBLineWidth->setValue(LineWidth); ui->SBLineWidth->repaint();
    ui->SBVertexSize->setValue(VertexSize); ui->SBVertexSize->repaint();
    ui->CBVertexType->setCurrentIndex(VertexType); ui->SBVertexSize->repaint();
    if (perspect == 1) {
        ui->CBPerspective->setChecked(true);
    } else {
        ui->CBPerspective->setChecked(false);
    }
    ui->CBPerspective->repaint();
    if (lineType == 1) {
        ui->CBDashLine->setChecked(true);
    } else {
        ui->CBDashLine->setChecked(false);
    }
    ui->CBDashLine->repaint();
}

void MainWindow::on_PBJpgPhoto_clicked()
{
    char path[255] = "";
    if (ui->ObjFilePath->text() != "home directory") {
         QByteArray bytes_2 = ui->ObjFilePath->text().toLocal8Bit();
         strcpy(path, bytes_2.data());
    } else {
        QByteArray bytes = ui->ObjFileName->text().toLocal8Bit();
        strcpy(path, bytes.data());
    }
    emit send_save_jpg_file(path);
}

void MainWindow::on_PBBmpPhoto_clicked()
{
    char path[255] = "";
    if (ui->ObjFilePath->text() != "home directory") {
         QByteArray bytes_2 = ui->ObjFilePath->text().toLocal8Bit();
         strcpy(path, bytes_2.data());
    } else {
        QByteArray bytes = ui->ObjFileName->text().toLocal8Bit();
        strcpy(path, bytes.data());
    }
    emit send_save_bmp_file(path);
}

void MainWindow::on_PBGifMovie_clicked()
{
    char path[255] = "";
    if (ui->ObjFilePath->text() != "home directory") {
         QByteArray bytes_2 = ui->ObjFilePath->text().toLocal8Bit();
         strcpy(path, bytes_2.data());
    } else {
        QByteArray bytes = ui->ObjFileName->text().toLocal8Bit();
        strcpy(path, bytes.data());
    }
    emit send_save_gif_file(path);
}

void MainWindow::on_xSlider_valueChanged(int value)
{
    ui->SBxRot->setValue(value / 16);
}

void MainWindow::on_ySlider_valueChanged(int value)
{
    ui->SByRot->setValue(value / 16);
}

void MainWindow::on_zSlider_valueChanged(int value)
{
     ui->SBzRot->setValue(value / 16);
}

void MainWindow::on_MultipSlider_valueChanged(int value)
{
//    std::cout << "for MultipSlider we got value = " << value << std::endl;
//    double temp = round((double)(value + 100)) / 100;
//    std::cout << "for MultipSlider we made temp = " << temp << std::endl;
    ui->DSBMultip->setValue(round((double)(value + 100)) / 100);
}

void MainWindow::on_xMoveSlider_valueChanged(int value)
{
    ui->DSBxMove->setValue(round((double) value) / 100);
}

void MainWindow::on_yMoveSlider_valueChanged(int value)
{
    ui->DSByMove->setValue(round((double) value) / 100);
}

void MainWindow::on_zMoveSlider_valueChanged(int value)
{
    ui->DSBzMove->setValue(round((double) value) / 100);
}

void MainWindow::on_SBxRot_valueChanged(int arg1)
{
    ui->xSlider->setValue(arg1 * 16);
}

void MainWindow::on_SByRot_valueChanged(int arg1)
{
    ui->ySlider->setValue(arg1 * 16);
}

void MainWindow::on_SBzRot_valueChanged(int arg1)
{
    ui->zSlider->setValue(arg1 * 16);
}

void MainWindow::on_DSBMultip_valueChanged(double arg1)
{
//    std::cout << "DSBMultip = " << arg1 << std::endl;
    int temp = (int)round(((arg1 - 1.0) * 100));
//    std::cout << "     temp = " << temp << std::endl;
    ui->MultipSlider->setValue(temp); ui->MultipSlider->setSliderPosition(temp);
}


void MainWindow::on_DSBxMove_valueChanged(double arg1)
{
    int temp = (int)round(arg1 * 100);
    ui->xMoveSlider->setValue(temp);ui->xMoveSlider->setSliderPosition(temp);
}

void MainWindow::on_DSByMove_valueChanged(double arg1)
{
    int temp = (int)round(arg1 * 100);
    ui->yMoveSlider->setValue(temp);ui->yMoveSlider->setSliderPosition(temp);
}

void MainWindow::on_DSBzMove_valueChanged(double arg1)
{
    int temp = (int)round(arg1 * 100);
    ui->zMoveSlider->setValue(temp);ui->zMoveSlider->setSliderPosition(temp);
}
