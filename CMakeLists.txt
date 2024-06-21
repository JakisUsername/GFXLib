cmake_minimum_required(VERSION 3.29.3)

set(CMAKE_C_COMPILER "clang")
set(CMAKE_CXX_COMPILER "clang++")

set(CMAKE_INSTALL_PREFIX ${CMAKE_SOURCE_DIR}/build/install)

project(DrawLIB)

set(CMAKE_CXX_FLAGS "-g")

set(SRC "src/main.cpp" "src/Printer.cpp")

add_executable(App ${SRC})
target_include_directories(App PRIVATE "include")
target_precompile_headers(App PRIVATE "include/pch.hpp")

install(TARGETS App)
