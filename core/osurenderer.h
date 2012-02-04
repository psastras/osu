#ifndef OSURENDERER_H
#define OSURENDERER_H

#include <unordered_map>
#include <string>

#include "audio.h"

class Primitive;
class BeatMap;
class ShaderProgram;
class OsuRenderer
{
public:
	OsuRenderer(int width, int height);

	void resize(int width, int height);
	void draw(const BeatMap *beatmap, long elapsed, const AudioMetadata &mdata) ;

protected:
	void ortho() const;

	int m_width, m_height;

	std::unordered_map<std::string, Primitive *>		m_primitives;
	std::unordered_map<std::string, ShaderProgram *>	m_shaders;
};

#endif // OSURENDERER_H
