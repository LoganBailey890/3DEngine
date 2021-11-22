#include"Render.h"
#include"Math/MathUtilis.h"
#include<SDL_image.h>
#include<SDL_ttf.h>
#include<iostream>


namespace nc
{
	void nc::Render::Startup()
	{
		if (SDL_Init(SDL_INIT_VIDEO) != 0)
		{
			std::cout << "SDL_inti Error." << SDL_GetError << std::endl;
		}
		IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG);
		TTF_Init();
	}

	void nc::Render::Shutdown()
	{
		SDL_GL_DeleteContext(context);
		SDL_DestroyWindow(window);

		IMG_Quit();
		TTF_Quit();
		SDL_Quit();
	}

	void nc::Render::Update(float dt)
	{
		
	}

	void nc::Render::Create(const std::string& name, int with, int height)
	{
		window = SDL_CreateWindow(name.c_str(), 100, 100, with, height, SDL_WINDOW_OPENGL);
		if (window == nullptr)
		{
			std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl; 
			SDL_Quit();
		}

		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_COMPATIBILITY);

		SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
		SDL_GL_SetAttribute(SDL_GL_ACCELERATED_VISUAL, 1);
		SDL_GL_SetSwapInterval(1);
		context = SDL_GL_CreateContext(window);

		if (!gladLoadGL())
		{
			SDL_Log("Failed to create OpenGL context");
			exit(-1);
		}
	}

	void nc::Render::BeginFrame()
	{
		glClearColor(0.2f, 0.2f, 1.0f, 1);
		glClear(GL_COLOR_BUFFER_BIT);
	}

	void nc::Render::EndFrame()
	{
		SDL_GL_SwapWindow(window);
	}

	

}
