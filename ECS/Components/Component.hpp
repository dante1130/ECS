#pragma once

class Entity;

struct Component
{
	Entity* entity;

	virtual void Init() {}
	virtual void Update() {}
	virtual void Draw() const {}

	virtual ~Component() {}
};
