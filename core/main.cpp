#include "beatmap.h"
#include <fstream>
#include <sstream>
#include <iostream>
int main(int argc, char *arg[])
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
    delete bm;

    return 0;
}
