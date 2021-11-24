#pragma once
#include "../Grapics/Render.h"
#include "Resource/Resource.h"
#include <vector>


namespace nc
{
	class VertexBuffer : public Resource
	{
	public:
		virtual ~VertexBuffer();
		bool Load(const std::string& name, void* null = nullptr) override;
		void CreateVertexBuffer(GLsizei size, GLsizei vertexCount, void* data);
		void SetAttribute(int index, GLint size, GLsizei stride, size_t offset);
		virtual void Draw(GLenum primitiveType = GL_TRIANGLES);
		void Bind() { glBindVertexArray(vao); }

	protected:
		GLuint vao{ 0 };
		GLuint vbo{ 0 };
		GLuint vertexCount{ 0 };
	};
}