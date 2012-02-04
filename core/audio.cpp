#include "audio.h"

#include <AL/al.h>
#include <AL/alc.h>
#include <thread>

#include <iostream>
#include <sstream>



#include <iostream>
#include <stdio.h>
#include <cmath>

Audio::Audio(const unsigned char *audiodata, size_t audiosize)
{
    m_soundBuffer = new short[1152 * 2];

	ALCdevice *device;
	ALCcontext *context;
    device = alcOpenDevice (NULL);
	context = alcCreateContext (device, NULL);
    if (!alcMakeContextCurrent (context));
    alGenSources(1, m_source);
    alGenBuffers(MAX_AUDIO_BUFFERS, m_buffers);
    alSourcei(m_source[0], AL_SOURCE_RELATIVE, AL_TRUE);
    alSource3f(m_source[0], AL_POSITION, 0.0f, 0.0f, 0.0f);
	struct mad_stream stream;
	struct mad_frame frame;
	struct mad_synth synth;
	mad_stream_init(&stream);
	mad_frame_init(&frame);
	mad_synth_init(&synth);
	mad_stream_buffer(&stream, audiodata, audiosize);// / sizeof(unsigned char));

    fflush(stdout);
	int numfilled = 0;
	while(numfilled < 6)
	{
		if(mad_frame_decode(&frame, &stream) == -1){
			if(!MAD_RECOVERABLE(stream.error)) break;
			else continue;
		}
		mad_synth_frame(&synth, &frame);
        writepcm(synth.pcm, m_soundBuffer);
        alBufferData(m_buffers[numfilled++], synth.pcm.channels == 2 ? AL_FORMAT_STEREO16 : AL_FORMAT_MONO16,
                     m_soundBuffer, synth.pcm.length*synth.pcm.channels*sizeof(ALshort), synth.pcm.samplerate);

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
			if(mad_frame_decode(&frame, &stream) == -1){
				if(!MAD_RECOVERABLE(stream.error)) break;
				else continue;
			}
			mad_synth_frame(&synth, &frame);
            writepcm(synth.pcm, m_soundBuffer);
            alBufferData(buffer, synth.pcm.channels == 2 ? AL_FORMAT_STEREO16 : AL_FORMAT_MONO16,
                         &m_soundBuffer[0], synth.pcm.length*synth.pcm.channels*sizeof(ALshort), synth.pcm.samplerate);
            alSourceQueueBuffers(m_source[0], 1, &buffer);
		}
        alGetSourcei(m_source[0], AL_SOURCE_STATE, &val);
		if(val != AL_PLAYING)
            alSourcePlay(m_source[0]);
	}

	mad_synth_finish(&synth);
	mad_frame_finish(&frame);
    mad_stream_finish(&stream);
}

Audio::~Audio()
{
    delete m_soundBuffer;
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
           str += " ... eunmeration error.\n";

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
