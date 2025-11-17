cmake_minimum_required(VERSION 3.5)

project(Workspace)

# Set policy for interprocedural optimization (LTO)
if(POLICY CMP0069)
    cmake_policy(SET CMP0069 NEW)
endif()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Enable static linking
set(BUILD_SHARED_LIBS OFF)
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -static-libgcc -static-libstdc++")
set(CMAKE_FIND_LIBRARY_SUFFIXES ".a")
set(CMAKE_LINK_SEARCH_START_STATIC ON)
set(CMAKE_LINK_SEARCH_END_STATIC ON)

# Add subdirectories
add_subdirectory(Engine)
add_subdirectory(Application)
add_subdirectory(ConfigurationManager)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)