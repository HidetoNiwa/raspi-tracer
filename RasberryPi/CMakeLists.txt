add_definitions(-std=c++11)
# OpenCVのパッケージを探す
cmake_minimum_required(VERSION 2.8)
project(MyOpenCVProject)

# Copy resouce
file(COPY ${CMAKE_SOURCE_DIR}/resource/ DESTINATION ${PROJECT_BINARY_DIR}/resource/)
add_definitions(-DRESOURCE_DIR="${PROJECT_BINARY_DIR}/resource/")

# Create Main project
set(SOURCES
    ./src/main.cpp
)

set(HEADERS
    ./src/includes.h
    # main.h
)

add_executable(Main
    ${SOURCES}
    ${HEADERS}
)

find_package(OpenCV REQUIRED)
if(OpenCV_FOUND)
    target_include_directories(Main PUBLIC ${OpenCV_INCLUDE_DIRS})
    target_link_libraries(Main ${OpenCV_LIBS})
endif()
