cmake_minimum_required(VERSION 3.16)
project(example_navigation)
add_executable(example_navigation src/main.cpp)
target_link_libraries(example_navigation PRIVATE WebView)