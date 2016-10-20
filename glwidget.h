#ifndef GLWIDGET_H
#define GLWIDGET_H


// Include GLM
#include <glm/glm.hpp>

//Include GLEW
#define GLEW_STATIC
#include <GL/glew.h>

//Qt includes
#include <QOpenGLWidget>
#include <QKeyEvent>
#include <QTimer>
#include <QVector2D>

//My headers
#include "shader.h"
#include "camera.h"
#include "model.h"
#include "directionallight.h"
#include "material.h"

using namespace glm;

class GLWidget:public QOpenGLWidget
{

public:
    explicit GLWidget(QWidget *parent = 0);
    ~GLWidget();
    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();

private:
    void keyPressEvent(QKeyEvent* event);
    void keyReleaseEvent(QKeyEvent* event);
    void mousePressEvent(QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent* event);
    void mouseMoveEvent(QMouseEvent* event);
    void wheelEvent(QWheelEvent *event);
private:
    Shader* shaderObject;
    QTimer timer;
    Camera camObject;
    QVector2D lastMousePos;
    Model* ourModel;
    DirectionalLight light;
    Material material;

};
#endif // GLWIDGET_H
