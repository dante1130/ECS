#include "Entity.hpp"

void Entity::Update()
{
	for (auto& component : m_components)
		component->Update();
}

void Entity::Draw() const
{
	for (auto& component : m_components)
		component->Draw();
}

bool Entity::IsActive() const
{
	return m_isActive;
}

void Entity::Destroy()
{
	m_isActive = false;
}
