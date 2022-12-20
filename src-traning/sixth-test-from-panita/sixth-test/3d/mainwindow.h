#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "form.h"
#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QMatrix4x4>
#include <QQuaternion>
#include <QVector2D>
#include <QBasicTimer>
#include <QFileDialog>
#include <QOpenGLShaderProgram>
#include <QOpenGLTexture>
#include "mainwidget.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QString filepath;
    QString filename;
    QString save_filepath;
    QString screenname;
//    QTimer *label_timer;

private slots:

    void on_BackgroundColor_currentTextChanged(const QString &arg1);

    void on_EdgeSize_valueChanged(double arg1);

    void on_BackgroundColor_3_currentTextChanged(const QString &arg1);

    void on_VerticeSize_valueChanged(double arg1);

    void on_BackgroundColor_4_currentTextChanged(const QString &arg1);

    void on_CleanColor_clicked();

    void on_ChooseFile_clicked();

    void on_EdgeType_currentTextChanged(const QString &arg1);

    void on_VerticeType_currentTextChanged(const QString &arg1);

    void on_Screenshot_clicked();

    void on_Screenshot_2_clicked();

    void on_Gif_clicked();

    void on_XMovement_valueChanged(int value);

    void on_YMovement_valueChanged(int value);

    void on_ZMovement_valueChanged(int value);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
