#include <GL/glew.h>
#include "primitive.h"

#define BUFFER_OFFSET(i) ((char *)NULL + (i))


        Primitive::Primitive(Float3 &tess, Float3 &translate, Float3 &scale) :
                vertexId_(0), indexId_(0)
        {
            translate_ = translate;
            scale_ = scale;
        }

        Primitive::~Primitive()
        {
            if(vertexId_) glDeleteBuffers(1, &vertexId_);
            if(indexId_) glDeleteBuffers(1, &indexId_);
        }

        void Primitive::draw(ShaderProgram *program, int instances) const
        {
            glBindBuffer(GL_ARRAY_BUFFER, vertexId_);
            GLint ids[3] = {
                program->getAttributeLocation("in_Position"),
                program->getAttributeLocation("in_Normal"),
                program->getAttributeLocation("in_TexCoord")
            };
            if(ids[0] >= 0)
            glVertexAttribPointer(ids[0], 3, GL_FLOAT, GL_FALSE, sizeof(Vertex),
                                  (GLvoid *)vOffset_);
            if(ids[1] >= 0)
            glVertexAttribPointer(ids[1], 3, GL_FLOAT, GL_FALSE, sizeof(Vertex),
                                  (GLvoid *)nOffset_);
            if(ids[2] >= 0)
            glVertexAttribPointer(ids[2], 3, GL_FLOAT, GL_FALSE, sizeof(Vertex),
                                  (GLvoid *)tOffset_);
            glBindBuffer(GL_ARRAY_BUFFER, 0);
            if(ids[0] >= 0) glEnableVertexAttribArray(ids[0]);
            if(ids[1] >= 0) glEnableVertexAttribArray(ids[1]);
            if(ids[2] >= 0) glEnableVertexAttribArray(ids[2]);

            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexId_);
            if(type_ == GL_PATCHES) glPatchParameteri(GL_PATCH_VERTICES, typeCount_);
            glDrawElementsInstanced(type_, idxCount_, GL_UNSIGNED_SHORT,
                                    BUFFER_OFFSET(0), instances);
            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
            if(ids[0] >= 0) glDisableVertexAttribArray(ids[0]);
            if(ids[1] >= 0) glDisableVertexAttribArray(ids[1]);
            if(ids[2] >= 0) glDisableVertexAttribArray(ids[2]);
        }

        void Primitive::draw(ShaderProgram *program) const
        {
            glBindBuffer(GL_ARRAY_BUFFER, vertexId_);

            GLint ids[3] = {
            program->getAttributeLocation("in_Position"),
            program->getAttributeLocation("in_Normal"),
            program->getAttributeLocation("in_TexCoord")
            };
            if(ids[0] >= 0)
            glVertexAttribPointer(ids[0], 3, GL_FLOAT, GL_FALSE, sizeof(Vertex),
                                  (GLvoid *)vOffset_);
            if(ids[1] >= 0)
            glVertexAttribPointer(ids[1], 3, GL_FLOAT, GL_FALSE, sizeof(Vertex),
                                  (GLvoid *)nOffset_);
            if(ids[2] >= 0)
            glVertexAttribPointer(ids[2], 3, GL_FLOAT, GL_FALSE, sizeof(Vertex),
                                  (GLvoid *)tOffset_);
            glBindBuffer(GL_ARRAY_BUFFER, 0);
            if(ids[0] >= 0) glEnableVertexAttribArray(ids[0]);
            if(ids[1] >= 0) glEnableVertexAttribArray(ids[1]);
            if(ids[2] >= 0) glEnableVertexAttribArray(ids[2]);

            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexId_);
            if(type_ == GL_PATCHES) glPatchParameteri(GL_PATCH_VERTICES, typeCount_);

            glDrawElements(type_, idxCount_, GL_UNSIGNED_SHORT, BUFFER_OFFSET(0));

            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

            if(ids[0] >= 0) glDisableVertexAttribArray(ids[0]);
            if(ids[1] >= 0) glDisableVertexAttribArray(ids[1]);
            if(ids[2] >= 0) glDisableVertexAttribArray(ids[2]);
        }

        Quad::Quad(Float3 tess, Float3 translate, Float3 scale) :
                Primitive(tess, translate, scale)
        {
             this->tesselate(tess, translate, scale);
        }

        Quad::~Quad()
        {

        }

        void Quad::tesselate(Float3 tess, Float3 translate, Float3 scale)
        {

            if(vertexId_) glDeleteBuffers(1, &vertexId_);
            if(indexId_) glDeleteBuffers(1, &indexId_);


            type_ = GL_QUADS;
            idxCount_ = 4 * tess.x * tess.y;
            Float3 delta = scale / tess;
            Float3 tdelta = 1.0 / tess;
            delta.z = 0;

            Vertex *pVertex = new Vertex[(int)((tess.x + 1) * (tess.y + 1))];
            for(int y=0, i=0; y<=tess.y; y++)
            {
                for(int x=0; x<=tess.x; x++, i++)
                {
                    pVertex[i].p = Float3(-0.5, -0.5, 0.0) * scale  + translate
                                   + delta * Float3(x, y, 0);
                    pVertex[i].n = Float3(0.0, 0.0, 1.0);
                    pVertex[i].t = Float3(x, y, 0) * tdelta;
                }
            }


            glGenBuffers(1, &vertexId_);
            glBindBuffer(GL_ARRAY_BUFFER, vertexId_);
            glBufferData(GL_ARRAY_BUFFER,
                         sizeof(Vertex)*((tess.x + 1) * (tess.y + 1)),
                         &pVertex[0].p.x, GL_STATIC_DRAW);

            unsigned short *pIndices = new unsigned short[idxCount_];
            for(int y=0, i=0; y<tess.y; y++)
            {
                for(int x=0; x<tess.x; x++, i+=4)
                {
                   pIndices[i] = y*(tess.x+1)+x;
                   pIndices[i+1] = y*(tess.x+1)+x+1;
                   pIndices[i+2] = (y+1)*(tess.x+1)+x+1;
                   pIndices[i+3] = (y+1)*(tess.x+1)+x;

                }
            }

            glGenBuffers(1, &indexId_);
            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexId_);
            glBufferData(GL_ELEMENT_ARRAY_BUFFER,
                         sizeof(unsigned short)*idxCount_,
                         &pIndices[0], GL_STATIC_DRAW);

            delete[] pVertex, delete[] pIndices;

            vOffset_ = 0;
            nOffset_ = 12;
            tOffset_ = 24;
        }
