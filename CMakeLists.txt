cmake_minimum_required(VERSION 3.0)

project(yandex-training-2.0)

# pre-settings
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_CXX_STANDARD 17)

# list of divisions
add_subdirectory(division-b)
