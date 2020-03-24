cmake_minimum_required(VERSION 3.10)

project(Matrix)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


include_directories(utils)
find_package(GTest)
set(HEADER_FILES matrix.h matrixElement.h)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wextra")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Weffc++")

add_executable(MyMatrix main.cc matrix.cc matrixTests.cc)

target_link_libraries(MyMatrix GTest::GTest)
