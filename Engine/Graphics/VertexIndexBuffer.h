#pragma once
#include "VertexBuffer.h"

namespace nc
{
	class VertexIndexBuffer : public VertexBuffer
	{
	public:
		~VertexIndexBuffer();
		bool Load(const std::string& name, void* null = nullptr) override;
		void CreateIndexBuffer(GLenum indexType, GLsizei count, void* data);
		void Draw(GLenum primitiveType = GL_TRIANGLES) override;

	protected:
		GLuint ibo = 0;
		GLuint indexCount = 0;
		GLuint indexType = 0;
	};
}
