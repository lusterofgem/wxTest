cmake_minimum_required(VERSION 3.22.1)
project(wxTest)

find_package(wxWidgets REQUIRED COMPONENTS core base gl)
add_executable(wxTest src/main.cpp)

# wxWidgets
include(${wxWidgets_USE_FILE})
target_link_libraries(wxTest ${wxWidgets_LIBRARIES})
