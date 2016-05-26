cmake_minimum_required(VERSION 3.1)
project(spark)

add_subdirectory(src)

option(BUILD_TEST "Build test project" ON)

if(BUILD_TEST)
    set(GLFW_BUILD_EXAMPLES CACHE BOOL OFF)
    set(GLFW_BUILD_TESTS CACHE BOOL OFF)
    set(GLFW_BUILD_DOCS CACHE BOOL OFF)
    add_subdirectory(deps/glfw)
    add_subdirectory(test)
endif()