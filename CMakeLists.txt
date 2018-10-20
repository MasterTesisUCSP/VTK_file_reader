cmake_minimum_required(VERSION 2.8)

PROJECT(VTK_file_reader)

find_package(VTK REQUIRED)
include(${VTK_USE_FILE})

add_executable(VTK_file_reader MACOSX_BUNDLE VTK_file_reader.cpp )

target_link_libraries(VTK_file_reader ${VTK_LIBRARIES})
