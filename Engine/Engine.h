#pragma once


#define REGISTER_CLASS(CLASS) nc::ObjectFactory::Instance().Register<CLASS>(#CLASS);
#define CREATE_ENGINE_OBJECT(class) nc::ObjectFactory::Instance().Create<nc::class>(#class);


//#include"../Engine/Audio/AudioSystem.h"

#include "Graphics/Program.h"
#include "Graphics/Material.h"
#include "Graphics/Shader.h"
#include "Graphics/VertexBuffer.h"

//input
#include "Input/InputSystem.h"

//core
#include "Core/FileSystem.h"
#include "Core/Timer.h"
#include "Core/Utilites.h"
#include "Core/Json.h"
#include "Core/Serializable.h"


//framework
#include "FrameWork/EventSystem.h"
#include "Resource/ResorceSystem.h"
#include "Framework/Singltion.h"
#include "Framework/Factory.h"
//Math

#include "Math/Random.h"
#include "Math/MathUtilis.h"
#include "Math/Transform.h"
#include "Audio/AudioSystem.h"
//graphics
#include "Grapics/Render.h"
#include "Grapics/Texture.h"


//math
#include "../Math/MathTypes.h"

#include "Object/Actor.h"
#include "Object/Scene.h"

//compentes

#include "Componet/PhisicsComponent.h"
#include "Componet/AudioComponent.h"
#include "Componet/MeshComponent.h"
#include "Componet/CameraComponent.h"
#include "Componet/FreeCameracontroller.h"
#include "Componet/ModelComponent.h"
#include "Componet/LightComponent.h"
#include <vector>
#include <memory>
#include<algorithm>
namespace nc
{
	using ObjectFactory = Singleton<Factory<std::string, Object>>;



	class Engine
	{
	public:
		void Startup();
		void Shutdown();

		void Update();
		void Draw(Render* render);

		template<typename T>
		T* Get();
	public:
		FrameTimer time;
	private:
		std::vector<std::unique_ptr<System>> systems;
	};
	template<typename T>
	inline T* Engine::Get()
	{
		for (auto& system : systems)
		{
			if (dynamic_cast<T*>(system.get())) return dynamic_cast<T*>(system.get());
		}
		return nullptr;
	}
}