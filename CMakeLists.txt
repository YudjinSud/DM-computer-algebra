cmake_minimum_required(VERSION 3.15)
project(DM_computer_algebra)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(DM_computer_algebra
        main.cpp
        Natural.cpp
        Natural.h
        README.md Test.cpp Test.h BTest.cpp Btest.h Integ.cpp Integ.h Frac.cpp Frac.h Poly.cpp Poly.h)
