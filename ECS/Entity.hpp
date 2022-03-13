#pragma once

#include <vector>
#include <memory>
#include <algorithm>
#include <bitset>
#include <array>

#include "Components/Component.hpp"

using ComponentID = std::size_t;

constexpr std::size_t maxComponents = 32;

inline ComponentID getComponentTypeID()
{
	static ComponentID lastID = 0;
	return lastID++;
}

template <typename T>
inline ComponentID getComponentTypeID() noexcept
{
	static ComponentID typeID = getComponentTypeID();
	return typeID;
}

using ComponentBitset = std::bitset<maxComponents>;
using ComponentArray = std::array<Component*, maxComponents>;

class Entity
{
public:
	void Update();
	void Draw() const;

	bool IsActive() const;

	void Destroy();

	template <typename T>
	bool HasComponent() const;

	template <typename T, typename... TArgs>
	T& AddComponent(TArgs&&... mArgs);

	template <typename T>
	T& GetComponent() const;

private:
	bool m_isActive;
	std::vector<std::unique_ptr<Component>> m_components;

	ComponentArray m_componentArray;
	ComponentBitset m_componentBitset;
};

template <typename T>
bool Entity::HasComponent() const
{
	return m_componentBitset[getComponentTypeID<T>()];
}

template <typename T, typename... TArgs>
T& Entity::AddComponent(TArgs&&... mArgs)
{
	T* component(new T(std::forward<TArgs>(mArgs)...));

	component->entity = this;
	std::unique_ptr<Component> uPtr{ component };

	m_components.emplace_back(std::move(uPtr));

	m_componentArray[getComponentTypeID<T>()] = component;
	m_componentBitset[getComponentTypeID<T>()] = true;

	component->Init();

	return *component;
}

template <typename T>
T& Entity::GetComponent() const
{
	auto ptr(m_componentArray[getComponentTypeID<T>()]);
	return *static_cast<T*>(ptr);
}

