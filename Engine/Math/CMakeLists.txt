# Math Library CMakeLists.txt

# Math library sources
file(GLOB MATH_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
file(GLOB MATH_HEADERS "${CMAKE_CURRENT_SOURCE_DIR}/include/*.hpp")

# Create Math static library
add_library(Math STATIC ${MATH_SOURCES} ${MATH_HEADERS})

# Math is header-only or has minimal dependencies
# No external dependencies needed

# Make include directory available to other targets
target_include_directories(Math PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Set compiler flags
if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    target_compile_options(Math PRIVATE -Wall -Wextra -Werror)
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    target_compile_options(Math PRIVATE /W4 /WX)
endif()
