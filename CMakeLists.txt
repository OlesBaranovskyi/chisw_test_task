cmake_minimum_required(VERSION 2.8.1) # check version CMake.

project(chisw_test_task_final) #name project

set(SOURCE_EXE main.cpp)# set variable with list source for executable file

set(SOURCE_LIB find_dependencies.cpp find_file.cpp Header_file.cpp)


add_library(allstatlib STATIC ${SOURCE_LIB}) # create static library 

add_executable(find_dep ${SOURCE_EXE}) # create executable file with name find_dep

target_link_libraries(find_dep allstatlib) # linking programm with library

