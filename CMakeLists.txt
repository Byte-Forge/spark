cmake_minimum_required(VERSION 3.1)
project(spark)

option(SPARK_USE_GL3 "Use opengl 3" OFF)
add_subdirectory(src)

option(SPARK_BUILD_TEST "Build test project" ON)

if(SPARK_BUILD_TEST)
    set(GLFW_BUILD_EXAMPLES CACHE BOOL OFF)
    set(GLFW_BUILD_TESTS CACHE BOOL OFF)
    set(GLFW_BUILD_DOCS CACHE BOOL OFF)
    add_subdirectory(deps/glfw)
    add_subdirectory(test)
endif()