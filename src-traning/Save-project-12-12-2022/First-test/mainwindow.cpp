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
    connect(ui->colorSlider, &QSlider::valueChanged, MyGLWidget, &GLWidget::setColor);
    connect(ui->xMoveSlider, &QSlider::valueChanged, MyGLWidget, &GLWidget::setXMove);
    connect(MyGLWidget, &GLWidget::xMoveChanged, ui->xMoveSlider, &QSlider::setValue);
    connect(ui->yMoveSlider, &QSlider::valueChanged, MyGLWidget, &GLWidget::setYMove);
    connect(MyGLWidget, &GLWidget::yMoveChanged, ui->yMoveSlider, &QSlider::setValue);
    connect(ui->zMoveSlider, &QSlider::valueChanged, MyGLWidget, &GLWidget::setZMove);
    connect(MyGLWidget, &GLWidget::zMoveChanged, ui->zMoveSlider, &QSlider::setValue);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_MainWindow_iconSizeChanged(const QSize &iconSize)
{
    if (iconSize.width() > 100) emit send_main_window_size_changed(iconSize);
}
