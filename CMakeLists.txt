cmake_minimum_required (VERSION 3.5)
project (Engine)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
include_directories(${PROJECT_SOURCE_DIR}/include
                    ${PROJECT_SOURCE_DIR}/bindings
)
find_package(EnTT REQUIRED)
find_package(spdlog REQUIRED)
find_package(glm REQUIRED)
find_package(SDL2 REQUIRED)
find_package(imgui REQUIRED)
file(GLOB SOURCES "src/*.cpp", "iclude/*.hpp")
file(GLOB IMGUI_BINDINGS_FILES ${PROJECT_SOURCE_DIR}/bindings/*.cpp)
add_executable(${CMAKE_PROJECT_NAME} ${SOURCES} ${IMGUI_BINDINGS_FILES})


target_link_libraries(
                    ${CMAKE_PROJECT_NAME}
                    PUBLIC
                     EnTT::EnTT
                     spdlog::spdlog
                     glm::glm
                     SDL2::SDL2
                     imgui::imgui
)

# Set compiler flags to treat all warnings as errors
if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    target_compile_options(${CMAKE_PROJECT_NAME} PRIVATE -Wall -Wextra -Werror)
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    target_compile_options(${CMAKE_PROJECT_NAME} PRIVATE /W4 /WX)
endif()