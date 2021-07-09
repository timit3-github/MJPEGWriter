# set compiler
set(CMAKE_CXX_COMPILER arm-none-linux-gnueabihf-g++)
set(CMAKE_C_COMPILER arm-none-linux-gnueabihf-gcc)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g2 -ggdb")
SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")
# project name
PROJECT(MJPEGWriter)
# requirement of cmake version
cmake_minimum_required(VERSION 3.5)

# Enable C++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

# set the directory of executable files
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

# find required opencv
find_package(OpenCV REQUIRED)
find_package(Threads REQUIRED)
# directory of opencv headers
include_directories(${OpenCV_INCLUDE_DIRS})
# name of executable file and path of source file
add_executable(MJPEGWriter main/main.cpp main/MJPEGWriter.cpp)
# directory of opencv library
link_directories(${OpenCV_LIBRARY_DIRS})
# opencv libraries
target_link_libraries(MJPEGWriter ${OpenCV_LIBS})

# includes
include_directories(./)

# .so link

FILE(GLOB_RECURSE PRJ_SRC
        "./src/*.c"
        "./src/*.cpp"
#        "${PROJECT_SOURCE_DIR}/src/*.c"
#        "${PROJECT_SOURCE_DIR}/src/*.cpp"
        )

target_link_libraries(MJPEGWriter Threads::Threads)
