# Application executable CMakeLists.txt

# Create Application executable
add_executable(Application ${CMAKE_CURRENT_SOURCE_DIR}/src/Application.cpp)

# Add include directory
target_include_directories(Application PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

# Link against EngineLib (which provides all includes via PUBLIC interface)
target_link_libraries(Application PRIVATE EngineLib)

# Set compiler flags to treat all warnings as errors
if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    target_compile_options(Application PRIVATE -Wall -Wextra -Werror)
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    target_compile_options(Application PRIVATE /W4 /WX)
endif()
