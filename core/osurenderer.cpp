#include "osurenderer.h"
#include "primitive.h"
#include "shaders/solid.h"
#include <vsml.h>
#include <GLES2/gl2.h>

OsuRenderer::OsuRenderer(int width, int height)
{
	this->resize(width, height);

}

void OsuRenderer::resize(int width, int height)
{
	m_width = width;
	m_height = height;

	this->ortho();

	m_primitives["fsq"] = new Quad(Float3(1, 1, 1), Float3(m_width / 2, m_height/2, 0),
								   Float3(width, height, 0));
	m_shaders["solid"] = new ShaderProgram(shaders_solid_glsl, VertexShader | FragmentShader,
									  shaders_solid_glsl_len);

}

void OsuRenderer::ortho() const
{
	glViewport(0, 0, m_width, m_height);
	VSML::instance()->loadIdentity(VSML::PROJECTION);
	VSML::instance()->ortho(0.f, m_width, m_height, 0.f);
	VSML::instance()->loadIdentity(VSML::MODELVIEW);
}

void OsuRenderer::draw(const BeatMap *beatmap, long elapsed)
{
	glClearColor(0.f, 0.f, 0.f, 0.f);
	glClear(GL_COLOR_BUFFER_BIT);
	m_shaders["solid"]->bind(VSML::instance());
	m_primitives["fsq"]->draw(m_shaders["solid"]);
	m_shaders["solid"]->release();
}
