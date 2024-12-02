cmake_minimum_required(VERSION 3.30)
project(Projet)

set(CMAKE_CXX_STANDARD 20)

add_executable(Projet main.cpp
        Controller.cpp
        Controller.h
        View.cpp
        View.h
        Model.cpp
        Model.h)
