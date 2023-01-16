#include <QApplication>
#include <QColorDialog>

#include <QDebug>
int main(int argc, char *argv[])
{
    QApplication app(argc,argv);

    QColor color = QColorDialog::getColor(QColor(255,100,200,255));
    if (!color.isValid()) {
         qDebug()<<"Отмена выбора цвета";
    }
    else { qDebug()<<"Выбран цвет"<<color.name();}
    return 0;
}

