cmake_minimum_required(VERSION 3.10)

project(MyList4Students LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(GTest REQUIRED)

add_executable(MyList include/myList.h include/mySorting.h
        src/main.cpp src/MyListTests.cpp src/MySortTests.cpp)

target_link_libraries(MyList GTest::GTest)
