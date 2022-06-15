cmake_minimum_required(VERSION 3.21)
project(projektv3)

set(CMAKE_CXX_STANDARD 20)

add_executable(projektv3 main.cpp
        Monster.cpp Monster.hpp
        Water.hpp Water.cpp Earth.cpp Earth.hpp Air.cpp Air.hpp Fire.cpp Fire.hpp Ice.cpp Ice.hpp Steel.cpp Steel.hpp Start.cpp Start.hpp Opponent.cpp Opponent.hpp Player.cpp Player.hpp)
