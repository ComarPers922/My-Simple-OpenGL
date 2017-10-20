#include "openwidget.h"
#include <QOpenGLWidget>
#include <GL/glu.h>

void openWidget::initializeGL()
{
    glMatrixMode(GL_PROJECTION);
    gluPerspective(50, this->width() / this->height(), 0.1, 1000);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glClearColor(.7f,.8f,.7f,1.0f);
}

void openWidget::paintGL()
{
    const float myZ = -15.0f;
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
    glRotatef(ang, 0.0f, 0.0f, 1.0f);
    glBegin(GL_TRIANGLES);
    glColor4ub(255, 255, 255, 255);
    glVertex3f(0.0f, 0.0f, myZ);
    glVertex3f(-4.0f, 0.0f, myZ);
    glVertex3f(-4.0f, -2.0f, myZ);
    glEnd();
    glRotatef(90,0.0f,0.0f,1.0f);
    glBegin(GL_TRIANGLES);
    glColor4ub(100, 255, 100, 255);
    glVertex3f(0.0f, 0.0f, myZ);
    glVertex3f(-4.0f, 0.0f, myZ);
    glVertex3f(-4.0f, -2.0f, myZ);
    glEnd();
    glRotatef(180, 0.0f, 0.0f, 1.0f);
    glBegin(GL_TRIANGLES);
    glColor4ub(100, 100, 100, 255);
    glVertex3f(0.0f, 0.0f, myZ);
    glVertex3f(-4.0f, 0.0f, myZ);
    glVertex3f(-4.0f, -2.0f, myZ);
    glEnd();
    glRotatef(270, 0.0f, 0.0f, 1.0f);
    glBegin(GL_TRIANGLES);
    glColor4ub(100, 100, 255, 255);
    glVertex3f(0.0f, 0.0f, myZ);
    glVertex3f(-4.0f, 0.0f, myZ);
    glVertex3f(-4.0f, -2.0f, myZ);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(pos,0,0);
    glBegin(GL_TRIANGLES);
    glColor4ub(200, 200, 255, 255);
    glVertex3f(0.0f,1.0f,myZ);
    glVertex3f(-2.0f,-3.0f,myZ);
    glVertex3f(2.0f,-3.0f,myZ);
    glEnd();
    glPopMatrix();
}
void openWidget::resizeGL(int w, int h)
{
}
void openWidget::Rotate()
{
    this->ang += 45;
    this->updateGL();
}
void openWidget::Translate(bool left)
{
    this->pos += left? -1 : 1;
    this->updateGL();
}
