#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QGLWidget>
#include <QTimer>

class GLWidget : public QGLWidget
{
    Q_OBJECT
public:
	explicit GLWidget(QWidget *parent = 0);


signals:

protected:
	void initializeGL();
	void paintGL();

	QTimer m_timer;


public slots:

};

#endif // GLWIDGET_H
