cmake_minimum_required(VERSION 3.10)

project(MyVector LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


include_directories(utils)
find_package(GTest)
set(HEADER_FILES vector.h fraction.h)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wextra")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Weffc++")

add_executable(MyVector main.cpp vector.cpp fraction.cpp utils/memoryManagement.cpp fractionTests.cpp vectorTests.cpp)

target_link_libraries(MyVector GTest::GTest)
