#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "glwidget.h"
#include <QWidget>
#include <QFileDialog>
#include <iostream>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_MainWindow_iconSizeChanged(const QSize &iconSize);
    void on_InputObject_2_clicked();
    void on_PBDraw_2_clicked();
    void on_SBRedColor_valueChanged(int arg1);
    void on_SBGreenColor_valueChanged(int arg1);
    void on_SBBlueColor_valueChanged(int arg1);
    void on_SBRedColorLine_valueChanged(int arg1);
    void on_SBGreenColorLine_valueChanged(int arg1);
    void on_SBBlueColorLine_valueChanged(int arg1);
    void on_SBRedColorVertex_valueChanged(int arg1);
    void on_SBGreenColorVertex_valueChanged(int arg1);
    void on_SBBlueColorVertex_valueChanged(int arg1);
    void on_SBLineWidth_valueChanged(int arg1);
    void on_SBVertexSize_valueChanged(int arg1);
    void on_CBVertexType_currentTextChanged(const QString &arg1);
    void on_CBPerspective_toggled(bool checked);
    void on_CBDashLine_toggled(bool checked);

    void on_PBToZero_clicked();

    void on_PBJpgPhoto_clicked();

    void on_PBBmpPhoto_clicked();

private:
    Ui::MainWindow *ui;
    GLWidget *MyGLWidget;
    void read_start_pos(void);
    double convert_str_to_double(char number[], int counter);

public slots:
    void get_vertexes_amount(int amount);
    void get_facets_amount(int amount);

signals:
    void send_main_window_size_changed(const QSize);
    void send_file_name(char*);
    void send_red_color(int);
    void send_green_color(int);
    void send_blue_color(int);
    void send_red_color_line(int);
    void send_green_color_line(int);
    void send_blue_color_line(int);
    void send_red_color_vertex(int);
    void send_green_color_vertex(int);
    void send_blue_color_vertex(int);
    void send_line_width(int);
    void send_vertex_size(int);
    void send_vertex_type(int);
    void send_perspect_status(int);
    void send_dash_line_signal(int);
    void send_save_jpg_file(char*);
    void send_save_bmp_file(char*);
};

#endif // MAINWINDOW_H
