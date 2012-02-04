#include <QtGui/QApplication>

#include "mainwindow.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iostream>
#include <QDebug>
#include "../core/beatmap.h"
#include "../core/osugame.h"
int main(int argc, char *argv[])
{


//	std::ifstream file("songs/song.osz", std::ios::in|std::ios::binary|std::ios::ate);
//	char * memblock;
//	std::ifstream::pos_type size;
//	if (file.is_open())
//  {
//	size = file.tellg();
//	memblock = new char [size];
//	file.seekg (0, std::ios::beg);
//	file.read (memblock, size);
//	file.close();

//	OsuGame *g = new OsuGame(memblock, size);
//	g->start(0);
//	delete[] memblock;
//  }

//	std::wfstream file("songs/Heaven/Envy - Heaven (Charles445) [Easy].osu");
//	std::wstring line;
//	std::wstringstream stream;
//	if(file.is_open())
//	{
//		while(file.good())
//		{
//			std::getline(file, line);
//			stream << line << std::endl;
//		}
//		file.close();
//	}
//	else
//	{
//		std::cerr << "Failed to open file." << std::endl;
//	}

//	BeatMap *bm = new BeatMap(stream.str());
//	std::wcout << bm->general().filename << std::endl;
//	std::wcout << bm->timingpoints().size() << std::endl;
// delete bm;

	QApplication a(argc, argv);
	MainWindow w;
	w.show();



	return a.exec();
}
