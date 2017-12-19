cmake_minimum_required(VERSION 3.10.1) # Проверка версии CMake.

project(chisw_test_task_final) #название проэкта

set(SOURCE_EXE main.cpp)# Установка переменной со списком исходников для исполняемого файла

set(SOURCE_LIB find_dependencies.cpp find_file.cpp Header_file.cpp)

add_library(allstatlib STATIC ${SOURCE_LIB}) # Создание статической библиотеки c подходящим именем

add_executable(find_dep ${SOURCE_EXE}) # Создает исполняемый файл с именем find_dep

target_link_libraries(find_dep allstatlib) # Линковка программы с библиотекой

