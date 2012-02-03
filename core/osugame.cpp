#include "osugame.h"
#include <3rdparty/miniz/miniz.c>
OsuGame::OsuGame(const char *oszdata, size_t oszsize)
{
	mz_zip_archive zip_archive;
	mz_zip_reader_init_mem(&zip_archive, oszdata, oszsize, 0);

	// Get and print information about each file in the archive.
	 for (i = 0; i < mz_zip_reader_get_num_files(&zip_archive); i++)
	 {
	   mz_zip_archive_file_stat file_stat;
	   if (!mz_zip_reader_file_stat(&zip_archive, i, &file_stat))
	   {
		 printf("mz_zip_reader_file_stat() failed!\n");
		 mz_zip_reader_end(&zip_archive);
		 return EXIT_FAILURE;
	   }

	   printf("Filename: \"%s\", Comment: \"%s\", Uncompressed size: %u, Compressed size: %u\n", file_stat.m_filename, file_stat.m_comment, (uint)file_stat.m_uncomp_size, (uint)file_stat.m_comp_size);
	 }
}
