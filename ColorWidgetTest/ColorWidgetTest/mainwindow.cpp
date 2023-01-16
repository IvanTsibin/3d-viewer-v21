#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_PBVertexColor_clicked()
{
    current_color_ = GetColor();
    qDebug()<<"И Мы выбрали цвет"<<current_color_.name();
    QPalette pal = palette();
    pal.setColor(QPalette::Background, (const QColor)current_color_);
    ui->LColor->setAutoFillBackground(true);
    ui->LColor->setPalette(pal);
    pal.setColor(QPalette::Background, (const QColor)current_color_);
    ui->PBVertexColor->setAutoFillBackground(true);
    ui->PBVertexColor->setPalette(pal);
    std::cout << "Ther Red component of the color is int and = " << current_color_.red() << std::endl;
    std::cout << "Ther Red component of the color is QReal and = " << current_color_.redF() << std::endl;
    current_color_.name() = "#55aa00";
    std::cout << "Ther Red component of the color is int and = " << current_color_.red() << std::endl;
    std::cout << "Ther Red component of the color is QReal and = " << current_color_.redF() << std::endl;
    current_color_.setRed(25);
    std::cout << "Ther Red component of the color is int and = " << current_color_.red() << std::endl;
    std::cout << "Ther Red component of the color is QReal and = " << current_color_.redF() << std::endl;
    current_color_.setRedF(0.9);
    std::cout << "Ther Red component of the color is int and = " << current_color_.red() << std::endl;
    std::cout << "Ther Red component of the color is QReal and = " << current_color_.redF() << std::endl;
    FILE *start_pos;
    start_pos = fopen("start_pos-v3.pos", "w");
    fprintf(start_pos, "%.2lf ", current_color_.redF());
    fprintf(start_pos, " %s ", current_color_.name());
    fclose(start_pos);
    current_color_.setRgbF(0.6,0.6,0.6);
    std::cout << "Ther Red component of the color is int and = " << current_color_.red() << std::endl;
    std::cout << "Ther Red component of the color is QReal and = " << current_color_.redF() << std::endl;
}

QColor MainWindow::GetColor(void) {
    QColor color_ = QColorDialog::getColor(QColor(255,100,200,255));
    return color_;
}
