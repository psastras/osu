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
			  ~Primitive();

			  virtual void tesselate(Float3 tess, Float3 translate, Float3 scale) = 0; //tesselates and reuploads into vbo
			  void draw(ShaderProgram *program);

			  GLuint vertexID() { return vertexId_; }
			  GLuint indexID() { return indexId_; }

			  const Float3& scale() { return scale_; }
			  const Float3& translate() { return scale_; }
		  protected:
			  Primitive(Float3 &tess, Float3 &translate, Float3 &scale);

			  GLuint vertexId_, indexId_;
			  GLenum type_;
			  GLuint idxCount_;
			  GLuint typeCount_;
			  int vOffset_, tOffset_;
			  ShaderProgram *shader_;
			  Float3 scale_, translate_;
		};
		class Quad : public Primitive {
			public:
			Quad(Float3 tess, Float3 translate, Float3 scale, bool flip = false);
			~Quad();

			void tesselate(Float3 tess, Float3 translate, Float3 scale);

			protected:
			bool flip_;
		};

		class Rect : public Primitive {
		public:
			Rect(Float3 tess, Float3 translate, Float3 scale);
			~Rect();

			void tesselate(Float3 tess, Float3 translate, Float3 scale);
		};

		class Circle : public Primitive {
		public:
			Circle(Float3 tess, Float3 translate, Float3 scale);
			~Circle();

			void tesselate(Float3 tess, Float3 translate, Float3 scale);
		};

		class Disc : public Primitive {
		public:
			Disc(Float3 tess, Float3 translate, Float3 scale);
			~Disc();

			void tesselate(Float3 tess, Float3 translate, Float3 scale);
		};

		class Plane : public Primitive {
			public:
			Plane(Float3 tess, Float3 translate, Float3 scale);
			~Plane();

			void tesselate(Float3 tess, Float3 translate, Float3 scale);
		};


		class GLTriangle : public Primitive {
			public:
			GLTriangle(Float3 tess, Float3 translate, Float3 scale);
			~GLTriangle();

			void tesselate(Float3 tess, Float3 translate, Float3 scale);
		};

#endif // PRIMITIVE_H
