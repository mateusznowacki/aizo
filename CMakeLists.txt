cmake_minimum_required(VERSION 3.24)
project(aizo)

set(CMAKE_CXX_STANDARD 17)
MATH(EXPR stack_size "16 * 1024 * 1024")
set(CMAKE_EXE_LINKER_FLAGS "-Wl,--stack,${stack_size}")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,--stack,16777216")


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++ -static-libgcc")
set(CMAKE_EXE_LINKER_FLAGS "-static")

add_executable(aizo_sortowanie main.cpp
        Algorithms.cpp
        Algorithms.h
        DataGenerator.cpp
        DataGenerator.h
        ConsoleManager.cpp
        ConsoleManager.h
        Controller.cpp
        Controller.h
        FileManager.cpp
        FileManager.h
        AutoPerformanceTester.cpp
        AutoPerformanceTester.h
        )
