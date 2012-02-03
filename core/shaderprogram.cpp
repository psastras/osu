#include <iostream>
#include "shaderprogram.h"
#include "vsml.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sstream>
#include <fstream>
#include <algorithm>

using namespace std;



        ShaderProgram::ShaderProgram() {
            m_programID =  glCreateProgram();
        }

        ShaderProgram::ShaderProgram(const char *filename, int type)
        {
            m_programID = glCreateProgram();
            if(type & FragmentShader) this->loadShaderFromFile(GL_FRAGMENT_SHADER, filename);
            if(type & VertexShader) this->loadShaderFromFile(GL_VERTEX_SHADER, filename);
            this->link();
        }

        ShaderProgram::ShaderProgram(unsigned char *data, int type, size_t size)
        {

            m_programID = glCreateProgram();
            std::string src = (const char *)data;
            src = src.substr(0, size);
            if(type & FragmentShader) this->loadShaderFromSource(GL_FRAGMENT_SHADER, src);
            if(type & VertexShader) this->loadShaderFromSource(GL_VERTEX_SHADER, src);
            this->link();
        }

        ShaderProgram::~ShaderProgram()
        {
            while(!m_shaderIDs.empty())
            {
                glDeleteShader(m_shaderIDs.back());
                m_shaderIDs.pop_back();
            }
            glDeleteProgram(m_programID);
        }

        void printLog(GLuint obj, const std::string &str)
        {
            int infologLength = 0;
            char infoLog[1024];
            if (glIsShader(obj))
                glGetShaderInfoLog(obj, 1024, &infologLength, infoLog);
            else
                glGetProgramInfoLog(obj, 1024, &infologLength, infoLog);
//			if (infologLength > 0) {
//				LOGI(str);
//				LOGE(infoLog);
//			}
            fflush(stdout);

        }

        void ShaderProgram::loadShaderFromFile(GLenum type, std::string fname)
        {
            stringstream ss;

            ifstream file(fname.c_str());
            string line;
            if (file.is_open())
            {
                if(file.good())
                {
                    getline(file, line);
                    ss << line << endl;
                }
            }

            if(type == GL_FRAGMENT_SHADER)
            ss << "#define _FRAGMENT_" << endl;
            else if(type == GL_VERTEX_SHADER)
            ss << "#define _VERTEX_" << endl;


            if (file.is_open())
            {
                while (file.good())
                {
                    getline(file, line);
                    ss << line << endl;
                }
                file.close();
            }
            else
            {
                std::cerr << "Failed to open file " << fname << std::endl;
                return;
            }
            std::string str = ss.str();
            int length = str.length();
            const char *data = str.c_str();
            GLuint id = glCreateShader(type);
            glShaderSource(id, 1, (const char **)&data, &length);
            glCompileShader(id);
            printLog(id, fname);
            glAttachShader(m_programID, id);
            m_shaderIDs.push_back(id);
        }


        void ShaderProgram::loadShaderFromSource(GLenum type, const std::string &source) {
            stringstream ss;
            // @TODO: need to check for a #version line and put that first for ATI compatibility
            if(type == GL_FRAGMENT_SHADER)
            ss << "#define _FRAGMENT_" << endl;
            else if(type == GL_VERTEX_SHADER)
            ss << "#define _VERTEX_" << endl;


            ss << source;
            std::string str = ss.str();
            int length = str.length();
            const char *data = str.c_str();
            GLuint id = glCreateShader(type);
            glShaderSource(id, 1, (const char **)&data, &length);
            glCompileShader(id);
            printLog(id, source);
            glAttachShader(m_programID, id);
            m_shaderIDs.push_back(id);
        }

        bool ShaderProgram::link()
        {
            glLinkProgram(m_programID);
            return true;
        }

        void ShaderProgram::bind(VSML *instance)
        {
            glUseProgram(m_programID);
            instance->initUniformLocs(this->getUniformLocation("modelviewMatrix"),
                          this->getUniformLocation("projMatrix"));
            instance->matrixToUniform(VSML::MODELVIEW);
            instance->matrixToUniform(VSML::PROJECTION);
        }

        void ShaderProgram::release()
        {
             glUseProgram(0);
        }

        void ShaderProgram::bind()
        {
             glUseProgram(m_programID);
        }


        GLint ShaderProgram::getUniformLocation(const char *name)
        {
            if(m_uniformVars.find(name) == m_uniformVars.end())
            {
                m_uniformVars[name] = glGetUniformLocation(m_programID, name);
            }
            return m_uniformVars[name];
        }

        GLint ShaderProgram::getAttributeLocation(const char *name)
        {
            if(m_attributes.find(name) == m_attributes.end())
            {
                m_attributes[name] = glGetAttribLocation(m_programID, name);
            }
            return m_attributes[name];
        }

        void ShaderProgram::setUniformValue(const char *name, bool value)
        {
            glUniform1i(getUniformLocation(name), value);
        }

        void ShaderProgram::setUniformValue(const char *name, float *mat4x4)
        {
            glUniformMatrix4fv(getUniformLocation(name), 1, false, mat4x4);
        }

        void ShaderProgram::setUniformValue(const char *name, Float2 *vals, int n) {
            glUniform2fv(getUniformLocation(name), n, &vals->x);
        }

        void ShaderProgram::setUniformValue(const char *name, float *vals, int n)
        {
            glUniform1fv(getUniformLocation(name), n, vals);
        }

        void ShaderProgram::setUniformValue(const char *name, Float2 val)
        {
            glUniform2fv(getUniformLocation(name), 1, &val.x);
        }

        void ShaderProgram::setUniformValue(const char *name, Float3 val)
        {
            glUniform3fv(getUniformLocation(name), 1, &val.x);
        }

        void ShaderProgram::setUniformValue(const char *name, Float3 *vals, int n)
        {
            glUniform3fv(getUniformLocation(name), n,&vals[0].x);
        }

        void ShaderProgram::setUniformValue(const char *name, Float4 val)
        {
            glUniform4fv(getUniformLocation(name), 1, &val.x);
        }

        void ShaderProgram::setUniformValue(const char *name, float val)
        {
            glUniform1f(getUniformLocation(name), val);
        }

        void ShaderProgram::setUniformValue(const char *name, Int2 *vals, int n) {
            glUniform2iv(getUniformLocation(name), n, &vals->x);
        }

        void ShaderProgram::setUniformValue(const char *name, int *vals, int n)
        {
            glUniform1iv(getUniformLocation(name), n, vals);
        }

        void ShaderProgram::setUniformValue(const char *name, Int2 val)
        {
            glUniform2iv(getUniformLocation(name), 1, &val.x);
        }


        void ShaderProgram::setUniformValue(const char *name, Int3 *vals, int n)
        {
            glUniform3iv(getUniformLocation(name), n,&vals[0].x);
        }

        void ShaderProgram::setUniformValue(const char *name, Int4 val)
        {
            glUniform4iv(getUniformLocation(name), 1, &val.x);
        }


        void ShaderProgram::setUniformValue(const char *name, int val)
        {
            glUniform1i(getUniformLocation(name), val);
        }

        GLuint ShaderProgram::id() const
        {
            return m_programID;
        }
