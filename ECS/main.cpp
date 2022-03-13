#include <iostream>

#include "ECS.hpp"
#include "Components/TransformComponent.hpp"

int main()
{
	ECS ecs;

	auto& newPlayer(ecs.AddEntity());

	newPlayer.AddComponent<TransformComponent>();

	auto& x = newPlayer.GetComponent<TransformComponent>().position.x;
	auto& y = newPlayer.GetComponent<TransformComponent>().position.y;
	auto& z = newPlayer.GetComponent<TransformComponent>().position.z;

	for (size_t i = 0; i < 100; ++i)
	{
		x++;
		y++;
		z++;

		std::cout << x << " " << y << " " << z << '\n';
	}

	return 0;
}
