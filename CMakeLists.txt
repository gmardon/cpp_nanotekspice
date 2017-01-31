cmake_minimum_required(VERSION 3.6)
project(cpp_nanotekspice)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

find_package(Qt5Widgets)
find_package(Qt5Gui)
find_package(Qt5Core)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -W -Wall -Werror -std=c++11")

set(SOURCE_FILES main.cpp src/editor/Block.cpp src/editor/Connection.cpp src/editor/MainWindow.cpp src/editor/Port.cpp src/editor/Editor.cpp src/editor/EditorView.cpp src/editor/EditorView.h)
add_executable(cpp_nanotekspice ${SOURCE_FILES})

target_link_libraries(cpp_nanotekspice ${CURSES_LIBRARIES})
target_link_libraries(cpp_nanotekspice Qt5Core)
target_link_libraries(cpp_nanotekspice Qt5Gui)
target_link_libraries(cpp_nanotekspice Qt5Widgets)

qt5_use_modules(cpp_nanotekspice Core Widgets Gui)