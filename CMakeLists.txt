cmake_minimum_required(VERSION 3.6)
project(cpp_nanotekspice)
include_directories(include)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

find_package(Qt5Widgets)
find_package(Qt5Gui)
find_package(Qt5Core)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -W -Wall -Werror -std=c++11")

set(SOURCE_FILES src/components/Clock.cpp src/components/c4514.cpp src/commands/Commands.cpp src/commands/Save.cpp src/errors/Error.cpp src/parser/Create.cpp src/parser/Parser.cpp include/Error.hpp include/c4030.hpp include/c4071.hpp include/Clock.hpp include/False.hpp include/Editor.hpp include/EditorView.hpp include/MainWindow.hpp include/Connection.hpp include/Editor.hpp include/c4001.hpp include/c4001.hpp include/c4008.hpp include/c4013.hpp include/c4040.hpp src/components/c4040.cpp src/components/AComponent.cpp src/components/c4008.cpp src/components/c4013.cpp src/components/c4017.cpp src/components/c4001.cpp src/components/False.cpp src/components/Input.cpp src/components/c4011.cpp src/components/c4030.cpp src/components/c4069.cpp src/components/c4071.cpp src/components/c4081.cpp src/components/Pin.cpp src/components/Tristate.cpp src/components/Output.cpp src/components/True.cpp src/main_editor.cpp src/editor/elements/Block.cpp src/editor/elements/Connection.cpp src/editor/MainWindow.cpp src/editor/elements/Port.cpp src/editor/Editor.cpp src/editor/EditorView.cpp include/EditorView.hpp)
add_executable(cpp_nanotekspice ${SOURCE_FILES})

target_link_libraries(cpp_nanotekspice ${CURSES_LIBRARIES})
target_link_libraries(cpp_nanotekspice Qt5Core)
target_link_libraries(cpp_nanotekspice Qt5Gui)
target_link_libraries(cpp_nanotekspice Qt5Widgets)

qt5_use_modules(cpp_nanotekspice Core Widgets Gui)