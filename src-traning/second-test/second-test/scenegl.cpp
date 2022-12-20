#include "scenegl.h"

SceneGL::SceneGL(QWidget *parent) :
    QGLWidget(parent)
{
}

void SceneGL::initializeGL(){
 
  glClearColor(0.0f,0.0f,0.0f,1.0f);
}
void SceneGL::resizeGL(int nWidth,int nHeight){
 glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
   gluPerspective(120.0, (GLdouble)nWidth / (GLdouble)nHeight, 0,1000.0);
  glViewport(0,0,(GLint)nWidth,(GLint)nHeight);
}


void SceneGL::paintGL(){
 glLoadIdentity();
  glClear(GL_COLOR_BUFFER_BIT);
} 