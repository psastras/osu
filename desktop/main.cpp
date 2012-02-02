#include <QtGui/QApplication>
#include "../core/beatmap.h"
#include "mainwindow.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <QDebug>
int main(int argc, char *argv[])
{
	std::wfstream file("songs/Heaven/Envy - Heaven (Charles445) [Easy].osu");
	std::wstring line;
	std::wstringstream stream;
	if(file.is_open())
	{
		while(file.good())
		{
			std::getline(file, line);
			stream << line << std::endl;
		}
		file.close();
	}
	else
	{
		std::cerr << "Failed to open file." << std::endl;
	}

	BeatMap *bm = new BeatMap(stream.str());
	std::wcout << bm->general().filename << std::endl;
	std::wcout << bm->timingpoints().size() << std::endl;

	QApplication a(argc, argv);
	MainWindow w;
	w.show();



	delete bm;
	return a.exec();
}
