cmake_minimum_required (VERSION 3.18)

project (blueberry VERSION 0.1)

add_subdirectory (libs/glad)
add_subdirectory (libs/glfw)
add_subdirectory (libs/glm)
add_subdirectory (libs/stb)
add_subdirectory (libs/spdlog)

set (SRC
 "src/application.cc"
 "src/log.cc")

add_library (blueberry ${SRC})

# testing directory
add_subdirectory (test)

target_compile_features (blueberry PRIVATE cxx_std_17)
target_link_libraries (blueberry PRIVATE glad glfw glm stb spdlog::spdlog)
target_include_directories (blueberry PUBLIC "include/")
