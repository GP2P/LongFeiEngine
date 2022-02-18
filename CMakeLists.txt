# Basic settings, project name can be whatever.
cmake_minimum_required(VERSION 3.21)
project(df)
set(CMAKE_CXX_STANDARD 20) # C++ standard version

# Bring SFML into the project (not used as a dependency yet)
find_package(SFML REQUIRED COMPONENTS graphics audio)

## ENGINE LIBRARY
## Compile the engine itself (/src) to a static library which can be linked to the demo

# Collect all of the source files
# One note here: You must manually reload the cmake project in clion whenever you add a file when using GLOB_RECURSE. Otherwise you can just add the file paths in the add_library call
file(GLOB_RECURSE DF_SRC src/*.cpp)

# Create the library with the given sources (named the same as the project above)
add_library(${PROJECT_NAME} ${DF_SRC} src/Manager.cpp src/Manager.h src/LogManager.cpp src/LogManager.h src/utility.cpp src/utility.h src/GameManager.cpp src/GameManager.h src/Clock.cpp src/Clock.h src/Vector.cpp src/Vector.h src/Object.cpp src/Object.h src/ObjectList.cpp src/ObjectList.h src/ObjectListIterator.cpp src/ObjectListIterator.h src/Event.cpp src/Event.h src/EventStep.cpp src/EventStep.h src/WorldManager.cpp src/WorldManager.h src/DisplayManager.cpp src/DisplayManager.h src/Color.h src/InputManager.cpp src/InputManager.h src/EventKeyboard.cpp src/EventKeyboard.h src/EventMouse.cpp src/EventMouse.h src/EventCollision.cpp src/EventCollision.h src/EventOut.cpp src/EventOut.h src/ResourceManager.cpp src/ResourceManager.h src/SpriteResourceManager.h src/Sprite.cpp src/Sprite.h src/Sound.cpp src/Sound.h src/Music.cpp src/Music.h src/Frame.cpp src/Frame.h src/Animation.cpp src/Animation.h src/Box.cpp src/Box.h src/ViewObject.cpp src/ViewObject.h src/EventView.cpp src/EventView.h)
# Link SFML graphics and audio modules privately (eg the demo cannot reference sfml without depending on it itself.
target_link_libraries(${PROJECT_NAME} PRIVATE sfml-graphics sfml-audio ${CMAKE_CURRENT_SOURCE_DIR}/lib/SpriteResourceManager-mac-arm64.o)
## DEMO EXECUTABLE
## Compile a demo project to an executable with a dependency on our library.

file(GLOB_RECURSE DEMO_SRC demo/*.cpp)

include_directories(/opt/homebrew/Cellar/sfml/2.5.1_1/include)

# Create an executable with the given sources
add_executable(demo ${DEMO_SRC} demo/src/Tester.cpp demo/src/Tester.h)
# Link the engine library (named same as project) to the demo executable
target_link_libraries(demo PUBLIC ${PROJECT_NAME})
# Add /src as a BUILD_INTERFACE which allows you to reference the headers without an absolute path (similar to if it was in the system include path)
# eg #include <LogManager.h> is valid inside the demo project.
target_include_directories(demo PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>)