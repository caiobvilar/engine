# InputManager Library CMakeLists.txt
cmake_minimum_required(VERSION 3.5)

# Collect all source and header files
file(GLOB INPUTMANAGER_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
file(GLOB INPUTMANAGER_HEADERS "${CMAKE_CURRENT_SOURCE_DIR}/include/*.hpp")

# Create static library
add_library(InputManager STATIC ${INPUTMANAGER_SOURCES} ${INPUTMANAGER_HEADERS})

# Find dependencies
find_package(SDL3 REQUIRED)
find_package(spdlog REQUIRED)

# Link dependencies
target_link_libraries(InputManager
    PUBLIC
        spdlog::spdlog
        /usr/local/lib/libSDL3.a
)

# Include directories
target_include_directories(InputManager PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)
