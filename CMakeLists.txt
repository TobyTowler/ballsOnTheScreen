cmake_minimum_required(VERSION 3.14)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
project(ballsOnTheScreen)

# Generate compile_commands.json for clangd
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Add SFML include directory
include_directories(${PROJECT_SOURCE_DIR}/include) # Your project's includes
include_directories("/usr/include")                 # System includes
include_directories("/usr/include/SFML")            # Explicitly add SFML headers if needed

# Collect all source files
file(GLOB SRC_FILES ${PROJECT_SOURCE_DIR}/src/*.cpp)

# Create executable FIRST
add_executable(ballsOnTheScreen ${SRC_FILES})

# Link SFML libraries to your executable explicitly for Arch Linux
# These are the standard names on Arch
target_link_libraries(
    ballsOnTheScreen
    sfml-graphics
    sfml-window
    sfml-system
)

# --- REMOVE OR COMMENT OUT THESE DEBUG LINES ONCE IT WORKS ---
find_package(SFML 3.0 COMPONENTS Graphics Window System REQUIRED) # You can keep this to verify it finds the config, but the explicit linking below is often more robust on Arch.
message(STATUS "SFML_FOUND: ${SFML_FOUND}")
message(STATUS "SFML_VERSION: ${SFML_VERSION}")
message(STATUS "SFML_INCLUDE_DIR: ${SFML_INCLUDE_DIR}")
message(STATUS "SFML_LIBRARIES: ${SFML_LIBRARIES}")
message(STATUS "SFML_GRAPHICS_LIBRARY: ${SFML_GRAPHICS_LIBRARY}")
message(STATUS "SFML_WINDOW_LIBRARY: ${SFML_WINDOW_LIBRARY}")
message(STATUS "SFML_SYSTEM_LIBRARY: ${SFML_SYSTEM_LIBRARY}")
# --- END DEBUG LINES ---
