# setting
cmake_minimum_required(VERSION 3.22.1)
project(wxTest)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(wxTest)
target_include_directories(wxTest PRIVATE include)
target_sources(
    wxTest
        PRIVATE src/main.cpp
        # PRIVATE src/TestGLContext.cpp
)

# wxWidgets
add_subdirectory(3rdparty/wxWidgets)
target_link_libraries(
    wxTest
        PRIVATE wx::base
        PRIVATE wx::core
        PRIVATE wx::gl
)
