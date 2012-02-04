#include "audio.h"

#include <AL/al.h>
#include <AL/alc.h>
#include <thread>
#include <iostream>
#include <sstream>
#include <iostream>
#include <stdio.h>
#include <cmath>

Audio::Audio(unsigned char *audiodata, size_t audiosize, bool destroydata)
{
	m_destroyData = destroydata;
	m_soundBuffer = new short[1152 * 2]; //@todo make this dynamic

	m_audioData = audiodata;
	m_audioSize = audiosize;
}

Audio::~Audio()
{
	delete m_soundBuffer;
	if(m_destroyData)
		delete m_audioData;
}

void Audio::playAudio()
{

	ALCdevice *device;
	ALCcontext *context;
	device = alcOpenDevice (NULL);
	context = alcCreateContext (device, NULL);
	if (!alcMakeContextCurrent (context));
	alGenSources(1, m_source);
	alGenBuffers(MAX_AUDIO_BUFFERS, m_buffers);

	mad_stream_init(&m_madInfo.stream);
	mad_timer_reset(&m_madInfo.timer);
	mad_frame_init(&m_madInfo.frame);
	mad_synth_init(&m_madInfo.synth);
	mad_stream_buffer(&m_madInfo.stream, m_audioData, m_audioSize);// / sizeof(unsigned char));

	m_isPlaying = true;

	int numfilled = 0;
	while(numfilled < MAX_AUDIO_BUFFERS)
	{
		if(mad_frame_decode(&m_madInfo.frame, &m_madInfo.stream) == -1){
			if(!MAD_RECOVERABLE(m_madInfo.stream.error)) break;
			else continue;
		}
		mad_synth_frame(&m_madInfo.synth, &m_madInfo.frame);
		mad_timer_add(&m_madInfo.timer, m_madInfo.frame.header.duration);
		writepcm(m_madInfo.synth.pcm, m_soundBuffer);
		alBufferData(m_buffers[numfilled++], m_madInfo.synth.pcm.channels == 2 ?
					 AL_FORMAT_STEREO16 : AL_FORMAT_MONO16,
					 m_soundBuffer, m_madInfo.synth.pcm.length*m_madInfo.synth.pcm.channels*sizeof(ALshort),
					 m_madInfo.synth.pcm.samplerate);

	}

	alSourceQueueBuffers(m_source[0], MAX_AUDIO_BUFFERS, m_buffers);
	alSourcePlay(m_source[0]);

	while (1)
	{
		ALuint buffer;
		ALint val;
		alGetSourcei(m_source[0], AL_BUFFERS_PROCESSED, &val);
		if(val <= 0)
			continue;
		while(val--)
		{
			alSourceUnqueueBuffers(m_source[0], 1, &buffer);
			if(mad_frame_decode(&m_madInfo.frame, &m_madInfo.stream) == -1){
				if(!MAD_RECOVERABLE(m_madInfo.stream.error)) break;
				else continue;
			}
			mad_synth_frame(&m_madInfo.synth, &m_madInfo.frame);
			mad_timer_add(&m_madInfo.timer, m_madInfo.frame.header.duration);
			writepcm(m_madInfo.synth.pcm, m_soundBuffer);
			alBufferData(buffer, m_madInfo.synth.pcm.channels == 2 ?
						 AL_FORMAT_STEREO16 : AL_FORMAT_MONO16,
						 &m_soundBuffer[0], m_madInfo.synth.pcm.length*m_madInfo.synth.pcm.channels*sizeof(ALshort),
						 m_madInfo.synth.pcm.samplerate);
			alSourceQueueBuffers(m_source[0], 1, &buffer);
		}
		alGetSourcei(m_source[0], AL_SOURCE_STATE, &val);
		if(val != AL_PLAYING)
			alSourcePlay(m_source[0]);
	}

	m_isPlaying = false;

	mad_synth_finish(&m_madInfo.synth);
	mad_frame_finish(&m_madInfo.frame);
	mad_stream_finish(&m_madInfo.stream);

	alcCloseDevice(device);
	alcDestroyContext(context);

}

void Audio::play()
{

	this->playAudio();
}

long Audio::elapsedTime() const
{
	return mad_timer_count(m_madInfo.timer, MAD_UNITS_MILLISECONDS);
}

bool Audio::isfinished() const
{
	return m_isPlaying;
}

std::string Audio::listAvailableDevices()
{
	std::string str = "Sound Devices available : ";
	if ( alcIsExtensionPresent( NULL, "ALC_ENUMERATION_EXT" ) == AL_TRUE )
	{
		str = "List of Devices : ";
		str += (char*) alcGetString( NULL, ALC_DEVICE_SPECIFIER );
		str += "\n";
	}
	else
		str += " ... enumeration error.\n";
	return str;
}

short Audio::downsample(signed int sample)
{
    /* round */
    sample += (1L << (MAD_F_FRACBITS - 16));

    /* clip */
    if (sample >= MAD_F_ONE)
      sample = MAD_F_ONE - 1;
    else if (sample < -MAD_F_ONE)
      sample = -MAD_F_ONE;

    /* quantize */
    return sample >> (MAD_F_FRACBITS + 1 - 16);
}

void Audio::writepcm(const mad_pcm &pcm, short *buffer)
{
    /* pcm->samplerate contains the sampling frequency */
    unsigned int nchannels = pcm.channels;
    unsigned int nsamples  = pcm.length;
    mad_fixed_t const *left_ch   = pcm.samples[0];
    mad_fixed_t const *right_ch  = pcm.samples[1];
      int k=0;
    while (nsamples--) {
      /* output sample(s) in 16-bit signed little-endian PCM */
      buffer[k++] = downsample(*left_ch++);

      if (nchannels == 2) {
        buffer[k++] = downsample(*right_ch++);
      }
    }
}
