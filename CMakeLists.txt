cmake_minimum_required(VERSION 3.18)
project(WebView)
set(CMAKE_CXX_STANDARD 11)
include(FetchContent)
# FetchContent_Declare(
#     webview
#     GIT_REPOSITORY https://github.com/Michaelzhouisnotwhite/webview-cmake.git
#     GIT_TAG main
# )
# FetchContent_MakeAvailable(webview)
include(${CMAKE_SOURCE_DIR}/cmake/DownloadWebView.cmake)
add_library(WebView STATIC src/include/webview.h src/webview.cc)
target_include_directories(WebView INTERFACE ${CMAKE_SOURCE_DIR}/src/include)
add_library(WebView_shared SHARED src/include/webview.h src/webview.cc)
target_include_directories(WebView_shared INTERFACE ${CMAKE_SOURCE_DIR}/src/include)
include_directories(${CMAKE_SOURCE_DIR}/src/include)
add_subdirectory(${CMAKE_SOURCE_DIR}/examples/example_navigation)