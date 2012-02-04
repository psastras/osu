#ifndef AUDIO_H
#define AUDIO_H
#include "3rdparty/install/include/mad.h"
#include "3rdparty/install/include/AL/al.h"
#include <string>

#define MAX_AUDIO_BUFFERS 6

class Audio
{
public:
	Audio(const unsigned char *audiodata, size_t audiosize);
    ~Audio();
    static std::string listAvailableDevices();

protected:

    static int decode(const unsigned char *data, unsigned long length);
    static short downsample(signed int sample);
    void writepcm(const mad_pcm &pcm, short *buffer); //writes the pcm to the buffer

    short *m_soundBuffer;
    ALuint m_source[1];
    ALuint m_buffers[MAX_AUDIO_BUFFERS];

    struct mad_info
    {
        mad_stream stream;
        mad_frame frame;
        mad_synth synth;
    };

    mad_info m_madInfo;
};

#endif // AUDIO_H
