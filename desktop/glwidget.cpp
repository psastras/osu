#include "glwidget.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <QDebug>
#include <iostream>
#include "../core/beatmap.h"
#include "../core/osugame.h"
GLWidget::GLWidget(QWidget *parent) :
	QGLWidget(parent), m_timer(this)
{
	this->setAutoBufferSwap(false);
	connect(&m_timer, SIGNAL(timeout()), this, SLOT(repaint()));

		std::ifstream file("songs/song.osz", std::ios::in|std::ios::binary|std::ios::ate);
		char * memblock;
		std::ifstream::pos_type size;
		if (file.is_open())
	  {
		size = file.tellg();
		memblock = new char [size];
		file.seekg (0, std::ios::beg);
		file.read (memblock, size);
		file.close();

		m_game = new OsuGame(memblock, size);
		delete[] memblock;
	  }

}


void GLWidget::initializeGL()
{

	m_timer.start(1000.0f / 60);
}

void GLWidget::paintGL()
{
	if(!m_game->isStarted())
		m_game->start(0, this->width(), this->height());

	m_game->update();

//	qDebug() << m_game->elapsedTime();

	this->swapBuffers();
}
