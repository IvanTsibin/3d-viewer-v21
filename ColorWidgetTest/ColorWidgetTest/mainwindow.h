#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QColorDialog>
#include <QDebug>
#include <QPalette>

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
    void on_PBVertexColor_clicked();

private:
    Ui::MainWindow *ui;
    QColor current_color_;
    QColor GetColor(void);
};

#endif // MAINWINDOW_H
