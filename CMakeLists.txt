cmake_minimum_required(VERSION 3.16.3)
project(wxTest)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(wxTest)
target_include_directories(${PROJECT_NAME} PUBLIC include)
target_sources(
    wxTest
    PRIVATE src/main.cpp
    PUBLIC src/TestApp.cpp
)

# wxWidgets
find_package(wxWidgets REQUIRED gl core base OPTIONAL_COMPONENTS net)
include(${wxWidgets_USE_FILE})
target_link_libraries(${PROJECT_NAME} PUBLIC ${wxWidgets_LIBRARIES})
