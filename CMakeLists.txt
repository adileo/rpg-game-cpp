cmake_minimum_required(VERSION 3.4)

project(RPG)

#Bring the headers, such as Student.h into the project
include_directories(src)

file(GLOB SOURCES "src/*.cpp")

add_executable(rpg ${SOURCES})

set(CMAKE_CXX_STANDARD 11) # C++11...
set(CMAKE_CXX_STANDARD_REQUIRED ON) #...is required...
set(CMAKE_CXX_EXTENSIONS OFF) #...without compiler extensions like gnu++11

set_target_properties(rpg PROPERTIES
    CXX_STANDARD 11
    CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS OFF
)
