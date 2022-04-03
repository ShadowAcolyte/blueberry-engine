
cmake_minimum_required (VERSION 3.18)

link_libraries (blueberry)
include_directories ("../include" "../libs/glad/include" "../libs/glfw/include" "../glm" "../spdlog/include" "../stb/include")

add_executable (window_test "window_test.cc")
add_executable (input_test "input_test.cc")
