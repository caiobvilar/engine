# TextureManager Library CMakeLists.txt

# TextureManager library sources
file(GLOB TEXTUREMANAGER_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
file(GLOB TEXTUREMANAGER_HEADERS "${CMAKE_CURRENT_SOURCE_DIR}/include/*.hpp")

# Create TextureManager static library
add_library(TextureManager STATIC ${TEXTUREMANAGER_SOURCES} ${TEXTUREMANAGER_HEADERS})

# Find dependencies
find_package(SDL3 REQUIRED)
find_package(spdlog REQUIRED)

# Link dependencies
target_link_libraries(TextureManager
    PUBLIC
        /usr/local/lib/libSDL3.a
        spdlog::spdlog
)

# Make include directory available to other targets
target_include_directories(TextureManager PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Set compiler flags
if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    target_compile_options(TextureManager PRIVATE -Wall -Wextra -Werror)
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    target_compile_options(TextureManager PRIVATE /W4 /WX)
endif()
