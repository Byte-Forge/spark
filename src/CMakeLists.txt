set(LIB_NAME "spark")

find_package(OpenGL REQUIRED)

add_library(${LIB_NAME} core.cpp
                        element.cpp
						container.cpp
                        view.cpp
                        grid.cpp
                        label.cpp
                        flextGL.c
                        ../deps/nanovg/src/nanovg.c)

target_link_libraries(${LIB_NAME} ${OPENGL_LIBRARIES})
target_include_directories(${LIB_NAME} PRIVATE ../deps/nanovg/src)
target_include_directories(${LIB_NAME} PUBLIC ../include)

set_property(TARGET ${LIB_NAME} PROPERTY CXX_STANDARD 14)
