#include "PhisicsComponent.h"
#include "Engine.h"

namespace nc
{
	void PhisicsComponenet::Update()
	{
		velocity += acceleration * owner->scene->engine->time.deltaTime;
		owner->transform.position += velocity * owner->scene->engine->time.deltaTime;
		velocity *= damping;
		acceleration = { 0.0f, 0.0f, 0.0f };
	}
	bool PhisicsComponenet::Write(const rapidjson::Value& value) const
	{
		return false;
	}
	bool PhisicsComponenet::Read(const rapidjson::Value& value)
	{
		JSON_READ(value, damping);

		return true;
	}
}