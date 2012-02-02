#include "beatmap.h"
#include <fstream>
#include <sstream>
#include <iostream>
int main(int argc, char *arg[])
{

    std::ifstream file("example.txt");
    std::string line;
    std::stringstream stream;
    if(file.is_open())
    {
        while(file.good())
        {
            std::getline(file, line);
            stream << line << std::endl;
        }
    }
    file.close();

    BeatMap *bm = new BeatMap(stream.str());
    std::cout << bm->general().filename << std::endl;
    std::cout << bm->timingpoints().size() << std::endl;
    delete bm;

    return 0;
}
