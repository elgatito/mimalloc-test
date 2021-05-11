cmake_minimum_required(VERSION 3.15.0)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

project(mimalloc-test
    LANGUAGES C CXX
)

set(minMimallocVersion 1.4)

include(CheckCXXSourceCompiles)

include_directories(
    src/
)

find_package(mimalloc ${minMimallocVersion} REQUIRED)
message(STATUS "Using mimalloc Version: ${mi_version}")
add_definitions(-DUSE_MIMALLOC)

add_executable(test 
    src/memory_storage.cxx 
    src/main.cxx
)

target_include_directories(test PUBLIC .)

target_link_libraries(test PUBLIC mimalloc-static)
