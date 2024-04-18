cmake_minimum_required(VERSION 3.24)
project(aizo)

set(CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++ -static-libgcc")




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
