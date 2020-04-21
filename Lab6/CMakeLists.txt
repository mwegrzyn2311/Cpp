cmake_minimum_required(VERSION 3.15)
project(Lab6)

set(CMAKE_CXX_STANDARD 20)

find_package(GTest REQUIRED)

include_directories("include")

add_executable(my-string-tests "")

add_library(my-string SHARED "")

target_link_libraries(my-string-tests PRIVATE GTest::GTest)
target_link_libraries(my-string-tests PRIVATE my-string)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wextra")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pedantic")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Weffc++")

add_subdirectory("include")
add_subdirectory("src")
add_subdirectory("testing")
