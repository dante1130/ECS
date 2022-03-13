# CMakeList.txt : CMake project for ECS, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
add_executable (ECS "ECS.cpp" "ECS.hpp" "main.cpp"  "Components/Component.hpp" "Entity.hpp" "Entity.cpp" "Components/TransformComponent.hpp")

# TODO: Add tests and install targets if needed.
