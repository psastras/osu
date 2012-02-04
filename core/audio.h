#ifndef AUDIO_H
#define AUDIO_H
#include "3rdparty/install/include/mad.h"
#include "3rdparty/install/include/AL/al.h"
#include <string>
#include <thread>
#define MAX_AUDIO_BUFFERS 6

class Audio
{
public:
	Audio(unsigned char *audiodata, size_t audiosize,
		  bool destroydata = true);
    ~Audio();
    static std::string listAvailableDevices();

	void play();
	bool isfinished() const;
	long elapsedTime() const; //ms

protected:

    static int decode(const unsigned char *data, unsigned long length);
    static short downsample(signed int sample);
    void writepcm(const mad_pcm &pcm, short *buffer); //writes the pcm to the buffer
	void playAudio();

    short *m_soundBuffer;
    ALuint m_source[1];
    ALuint m_buffers[MAX_AUDIO_BUFFERS];

    struct mad_info
    {
        mad_stream stream;
        mad_frame frame;
        mad_synth synth;
		mad_timer_t timer;
    };

	bool m_destroyData, m_isPlaying;
    mad_info m_madInfo;
	std::thread *m_thread;

	unsigned char *m_audioData;
	size_t m_audioSize;
};

#endif // AUDIO_H
