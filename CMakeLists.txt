cmake_minimum_required(VERSION 3.22.1)
project(wxTest)

add_executable(wxTest src/main.cpp)

# wxWidgets
add_subdirectory(3rdparty/wxWidgets)
target_link_libraries(wxTest wx::base wx::core wx::gl)
