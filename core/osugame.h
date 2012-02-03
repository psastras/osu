#ifndef OSUGAME_H
#define OSUGAME_H


#include <string>
#include <vector>
#include <unordered_map>
#include "beatmap.h"
#include "audio.h"

class OsuGame
{
public:
	OsuGame(const char *oszdata, size_t oszsize);

	// plays the beatmap at the selected index
	void play(int idx);

	std::vector<BeatMap *> const& beatmaps() const { return m_beatmaps; }

protected:
	std::unordered_map<std::string, Audio *> m_audio;
	std::vector<BeatMap *> m_beatmaps;
};

#endif // OSUGAME_H
