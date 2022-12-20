#ifndef SCENEGL_H
#define SCENEGL_H

#include <QGLWidget>
#include <GL/glu.h>
class SceneGL : public QGLWidget
{
    Q_OBJECT
public:
    explicit SceneGL(QWidget *parent = 0);
 protected:
  void initializeGL();
  void resizeGL(int nWidth,int nHeight);
  void paintGL();  
signals:
    
public slots:
    
};

#endif // SCENEGL_H
