# Engine Library CMakeLists.txt

# Add ConfigurationManager subdirectory first
add_subdirectory(ConfigurationManager)
add_subdirectory(IsoCamera)
add_subdirectory(TextureManager)

# Include directories for Engine
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/Core/include
                    ${CMAKE_CURRENT_SOURCE_DIR}/Map/include
                    ${CMAKE_CURRENT_SOURCE_DIR}/IsoCamera/include
                    ${CMAKE_CURRENT_SOURCE_DIR}/TextureManager/include
                    ${CMAKE_CURRENT_SOURCE_DIR}/ConfigurationManager/include
                    ${CMAKE_CURRENT_SOURCE_DIR}/bindings
                    /usr/local/include/imgui
)
find_package(EnTT REQUIRED)
find_package(spdlog REQUIRED)
find_package(glm REQUIRED)

# Find SDL3 - we'll manually link the static version
find_package(SDL3 REQUIRED)

# ImGui doesn't have a CMake package, we'll handle it manually
# Engine library sources
file(GLOB ENGINE_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/Core/src/*.cpp")
file(GLOB ENGINE_HEADERS "${CMAKE_CURRENT_SOURCE_DIR}/Core/include/*.hpp")
# Map module sources
file(GLOB MAP_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/Map/src/*.cpp")
file(GLOB MAP_HEADERS "${CMAKE_CURRENT_SOURCE_DIR}/Map/include/*.hpp")
# ImGui source files (using SDL3 backends from /usr/local/include/imgui/)
file(GLOB IMGUI_SOURCES 
    "/usr/local/include/imgui/imgui.cpp"
    "/usr/local/include/imgui/imgui_draw.cpp"
    "/usr/local/include/imgui/imgui_tables.cpp"
    "/usr/local/include/imgui/imgui_widgets.cpp"
    "/usr/local/include/imgui/imgui_impl_sdl3.cpp"
    "/usr/local/include/imgui/imgui_impl_sdlrenderer3.cpp"
)

# Create engine static library
add_library(EngineLib STATIC ${ENGINE_SOURCES} ${ENGINE_HEADERS} ${MAP_SOURCES} ${MAP_HEADERS} ${IMGUI_SOURCES})

# Link static SDL3 library directly
target_link_libraries(EngineLib
                    PUBLIC
                     ConfigurationManager
                     IsoCamera
                     TextureManager
                     EnTT::EnTT
                     spdlog::spdlog
                     glm::glm
                     /usr/local/lib/libSDL3.a
                     # SDL3 dependencies
                     m
                     pthread
                     dl
)

# Make include directory available to other targets
target_include_directories(EngineLib PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/Core/include
    ${CMAKE_CURRENT_SOURCE_DIR}/Map/include
    ${CMAKE_CURRENT_SOURCE_DIR}/IsoCamera/include
    ${CMAKE_CURRENT_SOURCE_DIR}/TextureManager/include
    ${CMAKE_CURRENT_SOURCE_DIR}/ConfigurationManager/include
    ${CMAKE_CURRENT_SOURCE_DIR}/bindings
    /usr/local/include/imgui
)

# Set compiler flags for EngineLib
if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    target_compile_options(EngineLib PRIVATE -Wall -Wextra -Werror)
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    target_compile_options(EngineLib PRIVATE /W4 /WX)
endif()