cmake_minimum_required(VERSION 3.5.1)
project(glImshow)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_MODULE_PATH $ENV{HOME}/oss/cotire/CMake) # 追加
include(cotire)
find_package(OpenCV REQUIRED)
find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS} ${GLUT_INCLUDE_DIR} ${OPENGL_INCLUDE_DIR})
set_directory_properties(COTIRE_PREFIX_HEADER_INCLUDE_PATH ${OpenCV_INCLUDE_DIRS} ${GLUT_INCLUDE_DIR} ${OPENGL_INCLUDE_DIR})
add_executable(glImshow main.cpp glImshow.cpp glImshow.h)
target_link_libraries(glImshow ${OpenCV_LIBRARIES} ${GLUT_glut_LIBRARY} ${OPENGL_gl_LIBRARY} ${OPENGL_glu_LIBRARY} )
cotire(glImshow)