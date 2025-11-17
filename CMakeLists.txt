cmake_minimum_required(VERSION 3.5)

project(Workspace)

# Set policy for interprocedural optimization (LTO)
if(POLICY CMP0069)
    cmake_policy(SET CMP0069 NEW)
endif()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Add subdirectories
add_subdirectory(Engine)
add_subdirectory(Application)
add_subdirectory(ConfigurationManager)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)