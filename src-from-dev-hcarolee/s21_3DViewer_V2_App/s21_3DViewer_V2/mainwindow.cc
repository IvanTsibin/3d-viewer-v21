#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    MyGLWidget = new GLWidget();
    ui->gridLayout->addWidget(MyGLWidget);

    connect(ui->xSlider, &QSlider::valueChanged, MyGLWidget, &GLWidget::setXRotation);
    connect(MyGLWidget, &GLWidget::xRotationChanged, ui->xSlider, &QSlider::setValue);
    connect(ui->ySlider, &QSlider::valueChanged, MyGLWidget, &GLWidget::setYRotation);
    connect(MyGLWidget, &GLWidget::yRotationChanged, ui->ySlider, &QSlider::setValue);
    connect(ui->zSlider, &QSlider::valueChanged, MyGLWidget, &GLWidget::setZRotation);
    connect(MyGLWidget, &GLWidget::zRotationChanged, ui->zSlider, &QSlider::setValue);
    connect(ui->MultipSlider, &QSlider::valueChanged, MyGLWidget, &GLWidget::setMultip);
    connect(MyGLWidget, &GLWidget::multipChanged, ui->MultipSlider, &QSlider::setValue);
    connect(ui->xMoveSlider, &QSlider::valueChanged, MyGLWidget, &GLWidget::setXMove);
    connect(MyGLWidget, &GLWidget::xMoveChanged, ui->xMoveSlider, &QSlider::setValue);
    connect(ui->yMoveSlider, &QSlider::valueChanged, MyGLWidget, &GLWidget::setYMove);
    connect(MyGLWidget, &GLWidget::yMoveChanged, ui->yMoveSlider, &QSlider::setValue);
    connect(ui->zMoveSlider, &QSlider::valueChanged, MyGLWidget, &GLWidget::setZMove);
    connect(MyGLWidget, &GLWidget::zMoveChanged, ui->zMoveSlider, &QSlider::setValue);
    connect(this, &MainWindow::send_file_name, MyGLWidget, &GLWidget::get_file_name);
    connect(MyGLWidget, &GLWidget::send_vertexes_amount, this, &MainWindow::get_vertexes_amount);
    connect(MyGLWidget, &GLWidget::send_facets_amount, this, &MainWindow::get_facets_amount);

    connect(this, &MainWindow::send_red_color, MyGLWidget, &GLWidget::setRedColor);
    connect(this, &MainWindow::send_green_color, MyGLWidget, &GLWidget::setGreenColor);
    connect(this, &MainWindow::send_blue_color, MyGLWidget, &GLWidget::setBlueColor);
    connect(this, &MainWindow::send_red_color_line, MyGLWidget, &GLWidget::setRedColorLine);
    connect(this, &MainWindow::send_green_color_line, MyGLWidget, &GLWidget::setGreenColorLine);
    connect(this, &MainWindow::send_blue_color_line, MyGLWidget, &GLWidget::setBlueColorLine);
    connect(this, &MainWindow::send_red_color_vertex, MyGLWidget, &GLWidget::setRedColorVertex);
    connect(this, &MainWindow::send_green_color_vertex, MyGLWidget, &GLWidget::setGreenColorVertex);
    connect(this, &MainWindow::send_blue_color_vertex, MyGLWidget, &GLWidget::setBlueColorVertex);
    connect(this, &MainWindow::send_line_width, MyGLWidget, &GLWidget::setLineWidth);
    connect(this, &MainWindow::send_vertex_size, MyGLWidget, &GLWidget::setVertexSize);
    connect(this, &MainWindow::send_vertex_type, MyGLWidget, &GLWidget::setVertexType);
    connect(this, &MainWindow::send_perspect_status, MyGLWidget, &GLWidget::setPerspectiveStatus);
    connect(this, &MainWindow::send_dash_line_signal, MyGLWidget, &GLWidget::setDashLineSignal);

    connect(this, &MainWindow::send_save_jpg_file, MyGLWidget, &GLWidget::getSaveJpgFile);
    connect(this, &MainWindow::send_save_bmp_file, MyGLWidget, &GLWidget::getSaveBmpFile);
    connect(this, &MainWindow::send_save_gif_file, MyGLWidget, &GLWidget::getSaveGifFileSignal);
    read_start_pos();
}

MainWindow::~MainWindow()
{
    delete ui;
}
