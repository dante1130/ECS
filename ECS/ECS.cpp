#include "ECS.hpp"

void ECS::Update()
{
	for (auto& entity : m_entities)
	{
		entity->Update();
	}
}

void ECS::Draw()
{
	for (const auto& entity : m_entities)
	{
		entity->Draw();
	}
}

void ECS::Refresh()
{
	m_entities.erase(std::remove_if(std::begin(m_entities), std::end(m_entities),
		[](const std::unique_ptr<Entity>& mEntity)
		{
			return !mEntity->IsActive();
		}),
		std::end(m_entities));
}

Entity& ECS::AddEntity()
{
	Entity* newEntity = new Entity();
	std::unique_ptr<Entity> uPtr{ newEntity };

	m_entities.emplace_back(std::move(uPtr));

	return *newEntity;
}