#include <QApplication>
#include <QLabel>
#include <QSurfaceFormat>

#ifndef QT_NO_OPENGL
#include "mainwidget.h"
#include "mainwindow.h"
#endif

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("DIMA_LOX");
    w.show();
    QSurfaceFormat format;
    format.setDepthBufferSize(240);
    QSurfaceFormat::setDefaultFormat(format);

    a.setApplicationName("DIMALOX");
    a.setApplicationVersion("0.1");
    return a.exec();
}
