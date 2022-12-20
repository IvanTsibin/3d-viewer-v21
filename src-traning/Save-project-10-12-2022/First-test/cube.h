#ifndef CUBE_H
#define CUBE_H


#include <qopengl.h>
#include <QVector>
#include <QVector3D>

#define DOTS_IN_POLYGON 200

class Cube
{
public:
    Cube();
    const GLfloat *constData() const { return m_data.constData(); }
    const GLfloat *constDotData() const { return m_dot_data.constData(); }
    int count() const { return m_count; }
    int dotsCount() const {return m_dots_count;}
    int linesAmount() const { return m_count / 6;}
    int dotsAmount() const {return m_dots_count / 6;}
    void cubeMove(GLfloat xMove, GLfloat yMove, GLfloat zMove);

private:
    typedef struct figure_struct {
        int dots_number;
        double **dots;
        int triangles_number;
        int **triangles;
        int lines_number;
        int **lines;
    } figure_t;
    void init_figure(figure_t *figure);
    void creat_cube(figure_t *figure);
    QVector<GLfloat> m_data, m_dot_data;
    int m_count;
    int m_dots_count;
};

#endif // CUBE_H
