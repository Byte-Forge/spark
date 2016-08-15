set(LIB_NAME "spark")

if(SPARK_USE_GL3)
	add_definitions(-DNANOVG_GL3_IMPLEMENTATION)
else()
	add_definitions(-DNANOVG_GL2_IMPLEMENTATION)
endif()

find_package(OpenGL REQUIRED)

find_package(Freetype REQUIRED)

add_library(${LIB_NAME} util.hpp
			button.cpp
			core.cpp
			element.cpp
			container.cpp
			view.cpp
			grid.cpp
			image.cpp
			input.cpp
			label.cpp
			xmlbuilder.cpp
			stackpanel.cpp
			textbox.cpp
			checkbox.cpp
			flextGL.c
			../include/spark/button.hpp
			../include/spark/core.hpp
			../include/spark/element.hpp
			../include/spark/container.hpp
			../include/spark/view.hpp
			../include/spark/grid.hpp
			../include/spark/image.hpp
			../include/spark/input.hpp
			../include/spark/label.hpp
			../include/spark/xmlbuilder.hpp
			../include/spark/scriptengine.hpp
			../include/spark/stackpanel.hpp
			../include/spark/textbox.hpp
			../include/spark/checkbox.hpp
			../include/spark/vector.hpp
			../deps/nanovg/src/nanovg.c
			../deps/pugixml/src/pugixml.cpp)

target_link_libraries(${LIB_NAME} ${OPENGL_LIBRARIES} ${FREETYPE_LIBRARIES})
target_include_directories(${LIB_NAME} PRIVATE ../deps/nanovg/src ../deps/pugixml/src ${FREETYPE_INCLUDE_DIRS})
target_include_directories(${LIB_NAME} PUBLIC ../include)

set_property(TARGET ${LIB_NAME} PROPERTY CXX_STANDARD 14)
add_definitions(-DFONS_USE_FREETYPE)
