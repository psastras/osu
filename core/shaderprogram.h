#ifndef SHADERPROGRAM_H
#define SHADERPROGRAM_H

#include "vec.h"
#include <GL/gl.h>
#include <string>
#include <unordered_map>
#include <vector>


        class VSML;
        enum ShaderType
        {
            FragmentShader		= 0x01,
            VertexShader		= 0x02,
            GeometryShader		= 0x04,
            EvaluationShader	= 0x08,
            ControlShader		= 0x10
        };

        class ShaderProgram
        {
        public:
            ShaderProgram();
            ShaderProgram(const char *filename, int type);
            ShaderProgram(unsigned char *data, int type, size_t size);
            ~ShaderProgram();

            void loadShaderFromFile(GLenum type, std::string source);
            void loadShaderFromSource(GLenum type, const std::string &source);
            bool link();
            void bind();
            void bind(VSML *instance);
            void release();
            GLint getUniformLocation(const char *name);
            GLint getAttributeLocation(const char *name);
            void setUniformValue(const char *name, bool value);
            void setUniformValue(const char *name, float *mat4x4);
            void setUniformValue(const char *name, Float2 *vals, int n);
            void setUniformValue(const char *name, float *vals, int n);
            void setUniformValue(const char *name, Float2 val);
            void setUniformValue(const char *name, Float3 val);
            void setUniformValue(const char *name, Float3 *vals, int n);
            void setUniformValue(const char *name, Float4 val);
            void setUniformValue(const char *name, float val);
            void setUniformValue(const char *name, Int2 *vals, int n);
            void setUniformValue(const char *name, int *vals, int n);
            void setUniformValue(const char *name, Int2 val);
            void setUniformValue(const char *name, Int3 val);
            void setUniformValue(const char *name, Int3 *vals, int n);
            void setUniformValue(const char *name, Int4 val);

            void setUniformValue(const char *name, int val);
            void setUniformValue(const char *name, unsigned int val);
            GLuint id() const;
        protected:

            std::unordered_map <const char *, GLint> m_uniformVars;
            std::unordered_map <const char *, GLint> m_attributes;
            std::vector<GLuint> m_shaderIDs;
            GLuint m_programID;
        };


#endif // SHADERPROGRAM_H
