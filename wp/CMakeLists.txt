cmake_minimum_required(VERSION 3.22.1)

project(a.out)

include_directories(header)


add_executable(${PROJECT_NAME} 
    core/main.cpp
    core/Student.cpp
    core/Subject.cpp
)