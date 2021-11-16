#pragma once
#include "Resource/Resource.h"
#include "../Math/MathTypes.h"
#include<SDL.h>

namespace nc
{
	class Render;
	class Texture : public Resource
	{
	public:
		Texture(){}
		Texture(Render* render);
		bool Create(SDL_Surface* surface);
		bool Load(const std::string& name,void* data) override;
		glm::vec2 getSize()const;


		friend class Render;

	private:
		SDL_Texture* textur{ nullptr };
		SDL_Renderer* renderer{ nullptr };

	};
}