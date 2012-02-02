#include "glwidget.h"
#include <iostream>
GLWidget::GLWidget(QWidget *parent) :
	QGLWidget(parent), m_timer(this)
{
	this->setAutoBufferSwap(false);
	connect(&m_timer, SIGNAL(timeout()), this, SLOT(repaint()));
}


void GLWidget::initializeGL()
{
	m_timer.start(1000.0f / 60);
}

void GLWidget::paintGL()
{


	this->swapBuffers();
}
