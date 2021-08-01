set(PROJECT_NAME LLVM-TOY)
PROJECT(${PROJECT_NAME})
SET(CMAKE_C_COMPILER "clang")
SET(CMAKE_CXX_COMPILER "clang++")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

message("project name: " ${PROJECT_NAME})
message("project directory: " ${PROJECT_SOURCE_DIR})

cmake_minimum_required(VERSION 3.11)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib)

include_directories(
    ${PROJECT_SOURCE_DIR}/include
    ${PROJECT_SOURCE_DIR}/lib

    /usr/local/include
    /usr/include
)

link_directories(
    ${LIBRARY_OUTPUT_PATH}

    /usr/local/lib
    /usr/lib
)

add_subdirectory(lib)
add_subdirectory(tool)

enable_testing()
add_subdirectory(ut)
