#pragma once
#include "Object.h"
#include "Math/Transform.h"
#include "Object/Scene.h"
#include "Componet/Component.h"
#include <Core/Serializable.h>


#include <memory>
#include <vector>
namespace nc
{

    class Scene;
    class Texture;
    class Render;

    class Actor : public Object, public ISerializable
    {
    public:

        Actor() {}
        Actor(const Transform& transform) : transform{ transform }{}
        Actor(const Actor& other);

        std::unique_ptr<Object> Clone() const { return std::make_unique<Actor>(*this); }
        
        virtual void Initialize() {}

        virtual void Update(float dt);
        virtual void Draw(Render* render);

        void AddChild(std::unique_ptr<Actor> actor);

        void AddComponent(std::unique_ptr<Component> component);

        void BeginContact(Actor* other);
        void EndContact(Actor* other);


       

        template<class T>
        T* AddComponent();

        template<class T>
        T* GetComponent();

        virtual bool Write(const rapidjson::Value& value) const override;
        virtual bool Read(const rapidjson::Value& value) override;

    public:
        bool active{ true };
        bool destroy{ false };
        std::string tag;
        std::string name;


        Transform transform;
        Scene* scene{ nullptr };
        Actor* parent{nullptr};
        std::vector<std::unique_ptr<Actor>> children;
        std::vector<std::unique_ptr<Component>> components;


    };
    template<class T>
    inline T* Actor::AddComponent()
    {
        std::unique_ptr<T> component = std::make_unique<T>();
        component->owner = this;

        components.push_back(std::move(component));
        return dynamic_cast<T*>(components.back().get());
    }
    template<class T>
    inline T* Actor::GetComponent()
    {
        for (auto& component : components)
        {
            if (dynamic_cast <T*> (component.get()))
            {
                return dynamic_cast <T*> (component.get());
            }
        }



        return nullptr;
    }
}