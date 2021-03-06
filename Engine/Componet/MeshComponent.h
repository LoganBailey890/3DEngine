#pragma once
#include "GraphicsComponent.h"
#include "Graphics/Material.h"
#include "Graphics/VertexBuffer.h"
namespace nc
{
	class Render;

	class MeshComponent : public GraphicsComponent
	{
	public:
		virtual void Update() override;
		virtual void Draw(Render* render) override;

		virtual bool Write(const rapidjson::Value& value) const override;
		virtual bool Read(const rapidjson::Value& value) override;

	public:
		std::shared_ptr<VertexBuffer> vertexBuffer;
		std::shared_ptr<Material> material;
		std::shared_ptr<Program> program;
	};
}

