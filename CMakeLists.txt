cmake_minimum_required(VERSION 3.16)
project(WebView)
set(CMAKE_CXX_STANDARD 11)
include(GNUInstallDirs)
include(FetchContent)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/DownloadWebView.cmake)
option(BUILD_SHARED_LIBS "Build using shared libraries" OFF)
option(WEBVIEW_BUILD_SHARED_LIBS "Build WebView using shared libraries" OFF)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

if (BUILD_SHARED_LIBS OR WEBVIEW_BUILD_SHARED_LIBS)
add_library(WebView_shared SHARED src/webview.cc)
else()
add_library(WebView_static STATIC src/webview.cc)
endif()

if(APPLE)
    find_library(OBJC_LIBRARY objc)
    set(LIBRARIES
            ${OBJC_LIBRARY}
            "-framework WebKit"
    )
elseif (UNIX)
    include_directories(/usr/include)
elseif (WIN32)
    set(LIBRARIES ws2_32 wsock32)
endif()

if (BUILD_SHARED_LIBS OR WEBVIEW_BUILD_SHARED_LIBS)
target_link_libraries(WebView_shared ${LIBRARIES})
else()
target_link_libraries(WebView_static ${LIBRARIES})
endif()

# include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src/include)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/examples/example_navigation)
