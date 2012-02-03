#include "osugame.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <3rdparty/miniz/miniz.c>
#include <algorithm>

OsuGame::OsuGame(const char *oszdata, size_t oszsize)
{
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
			Audio *aud = new Audio((unsigned char *)p, uncomp_size);
			free(p);
		}
	}

	mz_zip_reader_end(&zip_archive);

}

void OsuGame::play(int idx)
{

}
