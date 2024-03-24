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
add_library(WebView_shared SHARED src/include/webview.h src/webview.cc)
if(APPLE)
    find_library(OBJC_LIBRARY objc)
    set(LIBRARIES
            ${OBJC_LIBRARY}
            "-framework WebKit"
    )
elseif (UNIX)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -I/usr/include/javascriptcore")
    set(CMAKE_LINK_FLAGS "${CMAKE_LINK_FLAGS} -L/usr/lib/javascriptcore")
    set(LIBRARIES javascriptcore)
elseif (WIN32)
    set(LIBRARIES ws2_32 wsock32)
endif()
target_include_directories(WebView INTERFACE ${CMAKE_SOURCE_DIR}/src/include)
target_include_directories(WebView_shared INTERFACE ${CMAKE_SOURCE_DIR}/src/include)
target_link_libraries(WebView ${LIBRARIES})
tarGet_link_libraries(WebView_shared ${LIBRARIES})
include_directories(${CMAKE_SOURCE_DIR}/src/include)
add_subdirectory(${CMAKE_SOURCE_DIR}/examples/example_navigation)