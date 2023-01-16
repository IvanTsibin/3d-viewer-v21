#include "mainwindow.h"
#include "ui_mainwindow.h"

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

void MainWindow::on_PBChooseColor_clicked()
{
    current_color_ = GetColor();
    qDebug()<<"И Мы выбрали цвет"<<current_color_.name();
    QPalette pal = palette();
    pal.setColor(QPalette::Background, (const QColor)current_color_);
   ui->LColor->setAutoFillBackground(true);
    ui->LColor->setPalette(pal);
    pal.setColor(QPalette::Background, (const QColor)current_color_);
    ui->PBChooseColor->setAutoFillBackground(true);
    ui->PBChooseColor->setPalette(pal);
}

QColor MainWindow::GetColor(void) {
    QColor color_ = QColorDialog::getColor(QColor(255,100,200,255));
//    if (!color_.isValid()) {
//         qDebug()<<"Отмена выбора цвета";
//    }
//    else { qDebug()<<"Выбран цвет"<<color_.name();}
    return color_;
}
