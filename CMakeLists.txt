cmake_minimum_required(VERSION 3.22.1)
project(wxTest)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_SHARED_LIBS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(wxTest)
target_include_directories(${PROJECT_NAME} PUBLIC include)
target_sources(
    wxTest
    PRIVATE src/main.cpp
    PUBLIC src/TestApp.cpp
)

# static c++  
target_link_libraries(${PROJECT_NAME} PUBLIC -static-libstdc++)
# static gcc
target_link_libraries(${PROJECT_NAME} PUBLIC -static-libgcc)

# wxWidgets 
set(wxWidgets_USE_STATIC ON)
find_package(wxWidgets REQUIRED gl core base OPTIONAL_COMPONENTS net)
include(${wxWidgets_USE_FILE})
target_link_libraries(${PROJECT_NAME} PUBLIC ${wxWidgets_LIBRARIES})