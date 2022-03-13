#pragma once

#include "Component.hpp"

struct Vector3f
{
	float x, y, z;

	void Init() { x = 0.0f; y = 0.0f; z = 0.0f; }
};

struct TransformComponent : Component
{
	Vector3f position, rotation, scale;

	void Init() override
	{
		position.Init();
		rotation.Init();
		scale.Init();
	}
};
