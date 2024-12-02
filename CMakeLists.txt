cmake_minimum_required(VERSION 3.14)
project(Dragon_game)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp
        main.h
        input.cpp
        input.h
        creature.cpp
        creature.h
        heros.cpp
        heros.h
        map.cpp
        map.h
        potion.cpp
        potion.h
)
add_executable(Dragon_game ${SOURCE_FILES})
include_directories(/usr/local/include)

find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)
include_directories(${SFML_INCLUDE_DIRS})
target_link_libraries(Dragon_game sfml-system sfml-window sfml-graphics sfml-audio sfml-network)
