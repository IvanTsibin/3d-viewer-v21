#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <iostream>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    label_timer = new QTimer(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_BackgroundColor_currentTextChanged(const QString &arg1)
{
    if (arg1 == "yellow") {
        ui->openGLWidget->a1 = 1;
        ui->openGLWidget->a2 = 1;
        ui->openGLWidget->a3 = 0;
        ui->openGLWidget->a4 = 1;
        ui->openGLWidget->paintGL();
    } else if (arg1 == "red") {
        ui->openGLWidget->a1 = 1;
        ui->openGLWidget->a2 = 0;
        ui->openGLWidget->a3 = 0;
        ui->openGLWidget->a4 = 1;
        ui->openGLWidget->paintGL();
    } else if (arg1 == "black") {
        ui->openGLWidget->a1 = 0;
        ui->openGLWidget->a2 = 0;
        ui->openGLWidget->a3 = 0;
        ui->openGLWidget->a4 = 0;
        ui->openGLWidget->paintGL();
    } else if (arg1 == "blue") {
        ui->openGLWidget->a1 = 0;
        ui->openGLWidget->a2 = 0;
        ui->openGLWidget->a3 = 1;
        ui->openGLWidget->a4 = 1;
        ui->openGLWidget->paintGL();
    } else if (arg1 == "green") {
        ui->openGLWidget->a1 = 0;
        ui->openGLWidget->a2 = 1;
        ui->openGLWidget->a3 = 0;
        ui->openGLWidget->a4 = 1;
        ui->openGLWidget->paintGL();
    } else if (arg1 == "white") {
        ui->openGLWidget->a1 = 1;
        ui->openGLWidget->a2 = 1;
        ui->openGLWidget->a3 = 1;
        ui->openGLWidget->a4 = 1;
        ui->openGLWidget->paintGL();
    }
    update();
}

void MainWindow::on_EdgeSize_valueChanged(double arg1)
{
    ui->openGLWidget->linesi = arg1;
}


void MainWindow::on_BackgroundColor_3_currentTextChanged(const QString &arg1)
{
    if (arg1 == "yellow") {
        ui->openGLWidget->edgecolor[0] = 1.0f;
        ui->openGLWidget->edgecolor[1] = 1.0f;
        ui->openGLWidget->edgecolor[2] = .0f;
        ui->openGLWidget->edgecolor[3] = 1.0f;
        ui->openGLWidget->paintGL();
    } else if (arg1 == "red") {
        ui->openGLWidget->edgecolor[0] = 1.0f;
        ui->openGLWidget->edgecolor[1] = .0f;
        ui->openGLWidget->edgecolor[2] = .0f;
        ui->openGLWidget->edgecolor[3] = 1.0f;
        ui->openGLWidget->paintGL();
    } else if (arg1 == "black") {
        ui->openGLWidget->edgecolor[0] = .0f;
        ui->openGLWidget->edgecolor[1] = .0f;
        ui->openGLWidget->edgecolor[2] = .0f;
        ui->openGLWidget->edgecolor[3] = 1.0f;
        ui->openGLWidget->paintGL();
    } else if (arg1 == "blue") {
        ui->openGLWidget->edgecolor[0] = .0f;
        ui->openGLWidget->edgecolor[1] = .0f;
        ui->openGLWidget->edgecolor[2] = 1.0f;
        ui->openGLWidget->edgecolor[3] = 1.0f;
        ui->openGLWidget->paintGL();
    } else if (arg1 == "green") {
        ui->openGLWidget->edgecolor[0] = .0f;
        ui->openGLWidget->edgecolor[1] = 1.0f;
        ui->openGLWidget->edgecolor[2] = .0f;
        ui->openGLWidget->edgecolor[3] = 1.0f;
        ui->openGLWidget->paintGL();
    } else if (arg1 == "white") {
        ui->openGLWidget->edgecolor[0] = 1.0f;
        ui->openGLWidget->edgecolor[1] = 1.0f;
        ui->openGLWidget->edgecolor[2] = 1.0f;
        ui->openGLWidget->edgecolor[3] = 1.0f;
        ui->openGLWidget->paintGL();
    }
    update();
}


void MainWindow::on_VerticeSize_valueChanged(double arg1)
{
    ui->openGLWidget->verts = arg1;
}


void MainWindow::on_BackgroundColor_4_currentTextChanged(const QString &arg1)
{
    if (arg1 == "yellow") {
        ui->openGLWidget->vertcolor[0] = 1.0f;
        ui->openGLWidget->vertcolor[1] = 1.0f;
        ui->openGLWidget->vertcolor[2] = .0f;
        ui->openGLWidget->vertcolor[3] = 1.0f;
        ui->openGLWidget->paintGL();
    } else if (arg1 == "red") {
        ui->openGLWidget->vertcolor[0] = 1.0f;
        ui->openGLWidget->vertcolor[1] = .0f;
        ui->openGLWidget->vertcolor[2] = .0f;
        ui->openGLWidget->vertcolor[3] = 1.0f;
        ui->openGLWidget->paintGL();
    } else if (arg1 == "black") {
        ui->openGLWidget->vertcolor[0] = .0f;
        ui->openGLWidget->vertcolor[1] = .0f;
        ui->openGLWidget->vertcolor[2] = .0f;
        ui->openGLWidget->vertcolor[3] = 1.0f;
        ui->openGLWidget->paintGL();
    } else if (arg1 == "blue") {
        ui->openGLWidget->vertcolor[0] = .0f;
        ui->openGLWidget->vertcolor[1] = .0f;
        ui->openGLWidget->vertcolor[2] = 1.0f;
        ui->openGLWidget->vertcolor[3] = 1.0f;
        ui->openGLWidget->paintGL();
    } else if (arg1 == "green") {
        ui->openGLWidget->vertcolor[0] = .0f;
        ui->openGLWidget->vertcolor[1] = 1.0f;
        ui->openGLWidget->vertcolor[2] = .0f;
        ui->openGLWidget->vertcolor[3] = 1.0f;
        ui->openGLWidget->paintGL();
    } else if (arg1 == "white") {
        ui->openGLWidget->vertcolor[0] = 1.0f;
        ui->openGLWidget->vertcolor[1] = 1.0f;
        ui->openGLWidget->vertcolor[2] = 1.0f;
        ui->openGLWidget->vertcolor[3] = 1.0f;
        ui->openGLWidget->paintGL();
    }
    update();
}


void MainWindow::on_CleanColor_clicked()
{
    ui->EdgeSize->setValue(1);
    ui->VerticeSize->setValue(1);
    ui->BackgroundColor->setCurrentText("white");
    ui->BackgroundColor_3->setCurrentText("red");
    ui->BackgroundColor_4->setCurrentText("red");
    ui->openGLWidget->paintGL();
}


void MainWindow::on_ChooseFile_clicked()
{
//    filepath = NULL;
//    filename = NULL;

    filepath = QFileDialog::getOpenFileName(0, "", "../../../../OBJECTS", "*.obj");
    filename = filepath.right(filepath.length() - filepath.lastIndexOf("/") - 1);
    ui->pathToFile->setText(filename);
//    ui->EdgeNum->setNum(r);
}


void MainWindow::on_EdgeType_currentTextChanged(const QString &arg1)
{
    if (arg1 == "line") {
        ui->openGLWidget->z[0] = 0;
    } else {
        ui->openGLWidget->z[0] = 1;
    }
}


void MainWindow::on_VerticeType_currentTextChanged(const QString &arg1)
{
    if (arg1 == "cubes") {
        ui->openGLWidget->z[1] = 1;
    } else {
        ui->openGLWidget->z[1] = 0;
    }
}


void MainWindow::on_Screenshot_clicked()
{
//    screenname = NULL;
    screenname = QFileDialog::getSaveFileName(nullptr, "Спаси и сохрани в жипег", "../../../../SHOTS", "*.jpeg");
    ui->openGLWidget->grab().save(screenname);
}



void MainWindow::on_Screenshot_2_clicked()
{
//    screenname = NULL;
    screenname = QFileDialog::getSaveFileName(nullptr, "Спаси и сохрани в бмп", "../../../../SHOTS", "*.bmp");
    ui->openGLWidget->grab().save(screenname);
}


void MainWindow::on_Gif_clicked()
{
//    label_timer->start(1000);
//    ui->openGLWidget->TimerSlot();
}


void MainWindow::on_XMovement_valueChanged(int value)
{
    ui->openGLWidget->xval += value;
}


void MainWindow::on_YMovement_valueChanged(int value)
{
    ui->openGLWidget->yval += value;
}


void MainWindow::on_ZMovement_valueChanged(int value)
{
    ui->openGLWidget->zval += value;
}

