#pragma once

#include "Entity.hpp"

class ECS
{
public:
	void Update();
	void Draw();
	void Refresh();

	Entity& AddEntity();

private:
	std::vector<std::unique_ptr<Entity>> m_entities;
};
