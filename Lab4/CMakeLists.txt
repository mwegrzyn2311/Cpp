cmake_minimum_required(VERSION 3.10)

project(Shapes LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


include_directories(utils)
find_package(GTest)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/CMakeModules/")
find_package(gd)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wextra")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Weffc++")

add_executable(Shapes main.cpp circle.cpp stage.cpp shapecomposite.cpp utils/memoryManagement.cpp ShapesTests.cpp
               shape.h rectangle.h shapecomposite.h stage.h circle.h utils/memoryManagement.h)

target_link_libraries(Shapes GTest::GTest gd)
