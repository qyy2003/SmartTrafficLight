cmake_minimum_required(VERSION 2.8)
project( generate )
find_package( OpenCV REQUIRED )
add_executable( generate generate.cpp )
target_link_libraries( generate ${OpenCV_LIBS} )
