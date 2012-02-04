#include "osugame.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <3rdparty/miniz/miniz.c>
#include <algorithm>
#include <thread>
OsuGame::OsuGame(const char *oszdata, size_t oszsize)
{
	m_isPlaying = false;
	m_renderer = 0; //this can only be init when theres a valid gl context
	mz_zip_archive zip_archive;
	memset(&zip_archive, 0, sizeof(zip_archive));
	mz_zip_reader_init_mem(&zip_archive, oszdata, oszsize, 0);
	for (int i = 0; i < mz_zip_reader_get_num_files(&zip_archive); i++)
	{
		mz_zip_archive_file_stat file_stat;
		if (!mz_zip_reader_file_stat(&zip_archive, i, &file_stat))
		{
		 printf("mz_zip_reader_file_stat() failed!\n");
		 mz_zip_reader_end(&zip_archive);
		}
		std::string fname = file_stat.m_filename;
		std::transform(fname.begin(), fname.end(), fname.begin(), ::tolower);
		if(!fname.substr(fname.length() - 4, fname.length() - 1).compare(".osu"))
		{
			size_t uncomp_size;
			void *p = mz_zip_reader_extract_file_to_heap(&zip_archive,
														 file_stat.m_filename, &uncomp_size, 0);
			std::stringstream wis((char *)p);
			std::string data = wis.str().substr(0, uncomp_size / sizeof(char)); //@todo: we need a way to detect utf-16 encodings...
			std::wstring wdata(data.length(), L' ');
			std::copy(data.begin(), data.end(), wdata.begin());
			m_beatmaps.push_back(new BeatMap(wdata));
			free(p);
		}
		else if(!fname.substr(fname.length() - 4, fname.length() - 1).compare(".mp3"))
		{
			size_t uncomp_size;
			void *p = mz_zip_reader_extract_file_to_heap(&zip_archive,
														 file_stat.m_filename, &uncomp_size, 0);

			fname = file_stat.m_filename;
			std::wstring wdata(fname.length(), L' ');
			std::copy(fname.begin(), fname.end(), wdata.begin());
			//std:: wcout << wdata << std::endl;
			m_audio[wdata] = new Audio((unsigned char *)p, uncomp_size);;

			//free(p);
		}
	}

	mz_zip_reader_end(&zip_archive);

}

OsuGame::~OsuGame()
{
	//delete all the audio in m_audio

	delete m_renderer;
}

long OsuGame::elapsedTime()
{
	return m_audio[m_active->general().filename]->elapsedTime();
}

void OsuGame::update()
{

	m_renderer->draw(m_active, m_audio[m_active->general().filename]->elapsedTime(),
					 m_audio[m_active->general().filename]->metadata());
//	timeval cur_time;
//	gettimeofday(&cur_time, 0);
//	long elapsed = cur_time.tv_usec - m_startTime.tv_usec;
//	std::cout << m_audio[m_active->general().filename]->elapsedTime() << std::endl;
//	fflush(stdout);
}


void OsuGame::start(int idx, int width, int height)
{
	m_isPlaying = true;
	m_active = m_beatmaps[idx];
	m_audioThread = new std::thread(&Audio::play,m_audio[m_active->general().filename]);
	if(!m_renderer)
		m_renderer = new OsuRenderer(width, height);
}
