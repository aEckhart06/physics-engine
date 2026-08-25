cmake_minimum_required(VERSION 3.15)
project(physics-engine)

set(CMAKE_CXX_STANDARD 20)  # raylib-cpp expects C++17+

# Enable debug symbols for debugging
set(CMAKE_CXX_FLAGS_DEBUG "-g -O0")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")

find_package(raylib QUIET)
if (NOT raylib_FOUND)
    include(FetchContent)
    FetchContent_Declare(raylib
        GIT_REPOSITORY https://github.com/raysan5/raylib.git
        GIT_TAG 5.5
        GIT_SHALLOW TRUE
    )
    FetchContent_MakeAvailable(raylib)
endif()

find_package(raylib_cpp QUIET)
if (NOT raylib_cpp_FOUND)
    include(FetchContent)
    FetchContent_Declare(raylib_cpp
        GIT_REPOSITORY https://github.com/RobLoach/raylib-cpp.git
        GIT_TAG v5.5.0  # match your raylib version
    )
    FetchContent_MakeAvailable(raylib_cpp)
endif()

add_executable(main 
main.cpp
experiments/objects.cpp
experiments/bouncing_square.cpp
)
target_link_libraries(main PRIVATE raylib raylib_cpp)


