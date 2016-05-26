
set(BIN_NAME "ui_test")
add_executable(${BIN_NAME} main.cpp)

target_include_directories(${BIN_NAME} PRIVATE glfw spark )
target_link_libraries(${BIN_NAME} glfw spark ${GLFW_LIBRARIES})

set_property(TARGET ${BIN_NAME} PROPERTY CXX_STANDARD 14)