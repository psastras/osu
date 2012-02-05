#include "osurenderer.h"
#include "primitive.h"
#include "beatmap.h"
#include "shaders/solid.h"
#include "shaders/background.h"
#include <vsml.h>
#include <GLES2/gl2.h>

OsuRenderer::OsuRenderer(int width, int height)
{
	glClearColor(0.f, 0.f, 0.f, 0.f);
	glDisable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_FRONT);

	this->resize(width, height);

}

void OsuRenderer::resize(int width, int height)
{


	m_width = width;
	m_height = height;

	this->ortho();

	m_primitives["fsq"] = new Quad(Float3(10, 10, 1), Float3(m_width / 2.0, m_height / 2.0, 0),
								   Float3(width, height, 0));
	m_primitives["prg"] = new Quad(Float3(1, 1, 1), Float3(m_width / 2.0, m_height - 2.5, 0),
								   Float3(width, 5, 0));
	m_primitives["dsc"] = new Disc(Float3(30, 1, 1), Float3(0.f, 0.f, 0),
								   Float3(100, 100, 0));
	m_shaders["bg"] = new ShaderProgram(shaders_background_glsl, VertexShader | FragmentShader,
									  shaders_background_glsl_len);
	m_shaders["sl"] = new ShaderProgram(shaders_solid_glsl, VertexShader | FragmentShader,
									  shaders_solid_glsl_len);

}

void OsuRenderer::ortho() const
{
	glViewport(0, 0, m_width, m_height);
	VSML::instance()->loadIdentity(VSML::PROJECTION);
	VSML::instance()->ortho(0.f, m_width, m_height, 0.f);
	VSML::instance()->loadIdentity(VSML::MODELVIEW);
}

void OsuRenderer::draw(const BeatMap *beatmap, long elapsed,
					   const AudioMetadata &mdata)
{
	m_shaders["bg"]->bind(VSML::instance());
	m_primitives["fsq"]->draw(m_shaders["bg"]);
	m_shaders["bg"]->release();

	VSML::instance()->pushMatrix(VSML::MODELVIEW);
	VSML::instance()->scale(elapsed / (float)mdata.songlength,
							1.f, 1.f);
	m_shaders["sl"]->bind(VSML::instance());
	m_primitives["prg"]->draw(m_shaders["sl"]);
	m_shaders["sl"]->release();
	VSML::instance()->popMatrix(VSML::MODELVIEW);
	const std::vector<Beat> &beats = beatmap->beats();
	for(int i=0; i<beats.size(); i++)
	{
		if(abs(elapsed - beats[i].time) < 300 && elapsed > beats[i].time)
		{
			VSML::instance()->pushMatrix(VSML::MODELVIEW);
			VSML::instance()->translate(beats[i].x, beats[i].y, 0.f);

			m_shaders["sl"]->bind(VSML::instance());
			m_primitives["dsc"]->draw(m_shaders["sl"]);
			m_shaders["sl"]->release();
			VSML::instance()->popMatrix(VSML::MODELVIEW);
		}
	}


}
