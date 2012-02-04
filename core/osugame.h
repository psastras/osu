#ifndef OSUGAME_H
#define OSUGAME_H


#include <string>
#include <vector>
#include <unordered_map>
#include <sys/time.h>
#include <thread>
#include "beatmap.h"
#include "audio.h"
#include "osurenderer.h"

class OsuGame
{
public:
	OsuGame(const char *oszdata, size_t oszsize);
	~OsuGame();
	// plays the beatmap at the selected index

	void start(int idx, int width, int height);
	long elapsedTime();
	bool isStarted() const { return m_isPlaying; }
	void update();


	std::vector<BeatMap *> const& beatmaps() const { return m_beatmaps; }



protected:
	std::unordered_map<std::wstring, Audio *> m_audio;
	std::vector<BeatMap *> m_beatmaps;
	std::thread *m_audioThread;
	Audio *m_audios;
	OsuRenderer *m_renderer;
	bool m_isPlaying;
	timeval m_startTime;
private:
	BeatMap *m_active;
};

#endif // OSUGAME_H
