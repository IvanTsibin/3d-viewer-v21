#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
//  std::cout << " MainWindow::MainWindow(QWidget *parent) " << std::endl;
  ui->setupUi(this);
  MyGLWidget = new GLWidget();
  ui->gridLayout->addWidget(MyGLWidget);
  MyController_ = new Controller();
  MyController_->connectWidget(MyGLWidget);
  ConnectControllerToMainWidget();
  ReadStartPos();
}

MainWindow::~MainWindow() { delete ui; }
