cmake_minimum_required(VERSION 3.0 FATAL_ERROR)

project(SFMLGame VERSION 1.0
        DESCRIPTION "SFML Game"
        LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
find_package(SFML COMPONENTS system window graphics audio REQUIRED)

include_directories(include)
file(GLOB SOURCES "src/*.cpp")
add_executable(SFMLGame ${SOURCES})

target_link_libraries(SFMLGame sfml-graphics sfml-window sfml-system sfml-audio)


