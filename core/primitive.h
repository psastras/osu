#ifndef PRIMITIVE_H
#define PRIMITIVE_H

#include "shaderprogram.h"

        /**
          Struct which holds (for each vertex), a position, normal and texture
          coordinate.  This is primarily an internal data structure, and probably
          does not to be used outside of this class
          **/
        struct Vertex
        {
          Float3 p, n, t;
        };

        /**
          Base class defining all primitives.  The primitive class describes
          and VBO based OpenGL object.

          See implementations for more details.

          **/
        class Primitive {
          public:

              /// The primitive destructor.  This will delete any existing
              /// vbos associated with this primitive.
              virtual ~Primitive();

              /// Tesselates and reuploads into vbo.  Note that upon primitive
              /// construction, this is automatically called.  You do not need to
              /// call tesselate unless you wish to change the tesselation parameters.
              virtual void tesselate(Float3 tess, Float3 translate, Float3 scale) = 0;

              /// Draws the primitive with the given shader program applied.
              /// Note that the shader program must be bound prior to calling this.
              void draw(ShaderProgram *program) const;

              /// Draws the primitive instanced n times  with the given shader program
              /// applied. Note that the shader program must be bound prior to calling this.
              /// The instance can be accessed via gl_InstanceID in a shader.
              void draw(ShaderProgram *program, int instances) const;

              /// Returns the vbo id holding the vertices of this primitive
              GLuint vertexID() { return vertexId_; }
              /// Returns the vbo id holding the index information of this primitive
              GLuint indexID() { return indexId_; }

              /// Returns a const reference to the scale factor of this primitive
              const Float3& scale() { return scale_; }
              /// Returns a const reference to the translation factor of this primitive
              const Float3& translate() { return translate_; }
          protected:
              /// Protected primitive constructor
              Primitive(Float3 &tess, Float3 &translate, Float3 &scale);

              GLuint vertexId_, indexId_; /// The vertex and index vbo ids
              GLenum type_; /// The patch type of the primitive (ex. GL_QUAD)
              GLuint idxCount_; /// The number of indices
              GLuint typeCount_; /// The number of vertices per patch (ex. 4 for GL_QUAD)
              int vOffset_, tOffset_, nOffset_; /// The offset of each data in the Vertex struct (currently 0, 12, 24)

              Float3 scale_, translate_; /// The scale and translation factors
        };

        /**
          Defines a simple quad (in the xy axis).  Useful for drawing textures
          to the screen.  To draw a fullscreen quad, you must set up an
          orthographic camera with width and height equal to the viewport.
          Then set the scale to the viewport (or rendering context's) width and
          height.  Translation should then be set to the half width and half height.
          Tesselation may be set to 1.
          **/
        class Quad : public Primitive {
            public:
            Quad(Float3 tess, Float3 translate, Float3 scale);
            ~Quad();

            void tesselate(Float3 tess, Float3 translate, Float3 scale);
        };

#endif // PRIMITIVE_H
