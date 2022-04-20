cmake_minimum_required(VERSION 3.21)
project(lab7)

set(CMAKE_CXX_STANDARD 14)

add_executable(lab7 main.cpp Entity/Entity.cpp Entity/Entity.h Repo/Repo.cpp Repo/Repo.h console/console.cpp console/console.h Tests/tests.cpp Tests/tests.h Service/Service.cpp Service/Service.h Menu/Menu.cpp Menu/Menu.h)
