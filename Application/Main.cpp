#include"Engine.h"
#include <glad\glad.h>
#include <sdl.h>
#include<glm/vec3.hpp>
#include<glm/vec4.hpp>

#include<iostream>

// vertices
const float vertices[] =
{
    -0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f,
     0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f,
     0.5f,  0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f,
    -0.5f,  0.5f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 1.0f
};

const GLuint indices[] =
{
    0, 2, 1,
    0, 3, 2
};


int main(int argc, char** argv)
{
    nc::Engine engine;
    engine.Startup();
    engine.Get<nc::Render>()->Create("OpenGL", 800, 600);

    nc::SeedRandom(static_cast<unsigned int>(time(nullptr)));
    nc::setFilePath("../resources");

    std::shared_ptr<nc::Program> program = engine.Get<nc::ResourceSystem>()->Get<nc::Program>("basic_program");
    std::shared_ptr<nc::Shader> vshader = engine.Get<nc::ResourceSystem>()->Get<nc::Shader>("shaders/basic.vert", (void*)GL_VERTEX_SHADER);
    std::shared_ptr<nc::Shader> fshader = engine.Get<nc::ResourceSystem>()->Get<nc::Shader>("shaders/basic.frag", (void*)GL_FRAGMENT_SHADER);

    program->AddShader(vshader);
    program->AddShader(fshader);
    program->Link();
    program->Use();

    // vertex array
    GLuint vao;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    // create vertex buffer
    GLuint vbo;
    glGenBuffers(1, &vbo);

    // bind vertex buffer as active 
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // element buffer object
    GLuint ebo;
    glGenBuffers(1, &ebo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);



    // position
    //(GLubyte*)NULL
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), 0);
    glEnableVertexAttribArray(0);

    // Color
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (GLubyte*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    //uv
    //glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (GLubyte*)(6 * sizeof(float)));
    //glEnableVertexAttribArray(2);

    //texture
    //nc::Texture texture;
    //texture.CreateTexture("textures/llama.jpg");
    //texture.Bind();

    //uniform
    float time = 1;
    program->SetUniform("scale", time);

    glm::vec3 tint{ 1.0f, 0.5f, 0.5f };
    program->SetUniform("tint", tint);




    bool quit = false;
    while (!quit)
    {
        SDL_Event event;
        SDL_PollEvent(&event);

        switch (event.type)
        {
        case SDL_QUIT:
            quit = true;
            break;
        case SDL_KEYDOWN:
            if (event.key.keysym.sym == SDLK_ESCAPE)
            {
                quit = true;
            }
        }

        SDL_PumpEvents();
        engine.Update();

        time += engine.time.deltaTime;
        program->SetUniform("scale", std::sin(time));


        engine.Get<nc::Render>()->BeginFrame();

        //glDrawArrays(GL_TRIANGLES, 0, 3);
        glDrawElements(GL_TRIANGLES, 8, GL_UNSIGNED_INT, 0);

        engine.Get<nc::Render>()->EndFrame();

    }

    return 0;
}