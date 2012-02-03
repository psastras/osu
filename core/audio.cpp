#include "audio.h"
#include <mad.h>
#include <AL/al.h>
#include <AL/alc.h>
#include <AL/alut.h>

/*
 * The following utility routine performs simple rounding, clipping, and
 * scaling of MAD's high-resolution samples down to 16 bits. It does not
 * perform any dithering or noise shaping, which would be recommended to
 * obtain any exceptional audio quality. It is therefore not recommended to
 * use this routine if high-quality output is desired.
 */

static inline
ALshort scale(mad_fixed_t sample)
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

/*
 * This is the output callback function. It is called after each frame of
 * MPEG audio data has been completely decoded. The purpose of this callback
 * is to output (or play) the decoded PCM audio.
 */
#include <iostream>
#include <sstream>

ALshort  bufffff[1152*8];
static
enum mad_flow output(
			 struct mad_pcm *pcm)
{

  unsigned int nchannels, nsamples;
  mad_fixed_t const *left_ch, *right_ch;

  /* pcm->samplerate contains the sampling frequency */

  nchannels = pcm->channels;
  nsamples  = pcm->length;
  left_ch   = pcm->samples[0];
  right_ch  = pcm->samples[1];
	int k=0;
  while (nsamples--) {
	signed int samplel;
	signed int sampler;
	/* output sample(s) in 16-bit signed little-endian PCM */

	samplel = scale(*left_ch++);
	bufffff[k++] = samplel;

	if (nchannels == 2) {
	  sampler = scale(*right_ch++);
	  bufffff[k++] = sampler;
	}
  }

  return MAD_FLOW_CONTINUE;
}

#include <iostream>

#include <cmath>

Audio::Audio(const unsigned char *audiodata, size_t audiosize)
{
	ALCdevice *device;
	ALCcontext *context;
	device = alcOpenDevice (NULL);
	context = alcCreateContext (device, NULL);
	if (!alcMakeContextCurrent (context));
	ALuint buffers[6];
	alGenBuffers(6, buffers);
	ALuint source[1];
	alGenSources(1, source);

	struct mad_stream stream;
	struct mad_frame frame;
	struct mad_synth synth;
	mad_stream_init(&stream);
	mad_frame_init(&frame);
	mad_synth_init(&synth);
	mad_stream_buffer(&stream, audiodata, audiosize);// / sizeof(unsigned char));

	int numfilled = 0;
	while(numfilled < 6)
	{
		if(mad_frame_decode(&frame, &stream) == -1){
			if(!MAD_RECOVERABLE(stream.error)) break;
			else continue;
		}
		mad_synth_frame(&synth, &frame);
		output(&synth.pcm);
		alBufferData(buffers[numfilled++], synth.pcm.channels == 2 ? AL_FORMAT_STEREO16 : AL_FORMAT_STEREO8,
					 bufffff, synth.pcm.length*synth.pcm.channels*sizeof(ALshort), synth.pcm.samplerate);

	}

	alSourceQueueBuffers(source[0], 6, buffers);
	alSourcePlay(source[0]);

	while (1)
	{
		ALuint buffer;
		ALint val;
		alGetSourcei(source[0], AL_BUFFERS_PROCESSED, &val);
		if(val <= 0)
			continue;
		while(val--)
		{
			alSourceUnqueueBuffers(source[0], 1, &buffer);
			if(mad_frame_decode(&frame, &stream) == -1){
				if(!MAD_RECOVERABLE(stream.error)) break;
				else continue;
			}
			mad_synth_frame(&synth, &frame);
			output(&synth.pcm);
			alBufferData(buffer, synth.pcm.channels == 2 ? AL_FORMAT_STEREO16 : AL_FORMAT_STEREO8,
						 &bufffff[0], synth.pcm.length*synth.pcm.channels*sizeof(ALshort), synth.pcm.samplerate);
			alSourceQueueBuffers(source[0], 1, &buffer);
		}
		alGetSourcei(source[0], AL_SOURCE_STATE, &val);
		if(val != AL_PLAYING)
			alSourcePlay(source[0]);
	}

	mad_synth_finish(&synth);
	mad_frame_finish(&frame);
	mad_stream_finish(&stream);
}
