cmake_minimum_required(VERSION 3.15)
project(DM_computer_algebra_test_branch_for_elek34ka)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(DM_computer_algebra_test_branch_for_elek34ka
        BTest.cpp
        Btest.h
        Frac.cpp
        Frac.h
        Integ.cpp
        Integ.h
        main.cpp
        Manipulator.cpp
        Manipulator.h
        Natural.cpp
        Natural.h
        Poly.cpp
        Poly.h
        Test.cpp
        Test.h)
