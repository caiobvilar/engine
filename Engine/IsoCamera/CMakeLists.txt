# IsoCamera Library CMakeLists.txt

# IsoCamera library sources
file(GLOB ISOCAMERA_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
file(GLOB ISOCAMERA_HEADERS "${CMAKE_CURRENT_SOURCE_DIR}/include/*.hpp")

# Create IsoCamera static library
add_library(IsoCamera STATIC ${ISOCAMERA_SOURCES} ${ISOCAMERA_HEADERS})

# Find SDL3
find_package(SDL3 REQUIRED)

# Link dependencies
target_link_libraries(IsoCamera
    PUBLIC
        /usr/local/lib/libSDL3.a
)

# Make include directory available to other targets
target_include_directories(IsoCamera PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Set compiler flags
if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    target_compile_options(IsoCamera PRIVATE -Wall -Wextra -Werror)
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    target_compile_options(IsoCamera PRIVATE /W4 /WX)
endif()
