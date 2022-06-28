cmake_minimum_required(VERSION 3.22.1)
project(wxTest)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(wxTest)
target_include_directories(${PROJECT_NAME} PRIVATE include)
target_sources(
    wxTest
    PRIVATE src/cube.cpp
)

# wxWidgets
find_package(wxWidgets REQUIRED COMPONENTS net core base gl)
include(${wxWidgets_USE_FILE})
target_link_libraries(${PROJECT_NAME} PRIVATE ${wxWidgets_LIBRARIES})

# opengl
find_package(OpenGL REQUIRED)
target_include_directories(${PROJECT_NAME} PRIVATE ${OPENGL_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME} PRIVATE ${OPENGL_LIBRARIES})

# glew
find_package(GLEW 2.0 REQUIRED)
target_include_directories(${PROJECT_NAME} PRIVATE ${GLEW_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} PRIVATE ${GLEW_LIBRARIES})
target_link_libraries(${PROJECT_NAME} PRIVATE GLEW::GLEW)
