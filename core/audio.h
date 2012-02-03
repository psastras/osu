#ifndef AUDIO_H
#define AUDIO_H
#include <string>
class Audio
{
public:
	Audio(const unsigned char *audiodata, size_t audiosize);

protected:



	int decode(const unsigned char *data, unsigned long length);
};

#endif // AUDIO_H
