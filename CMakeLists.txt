cmake_minimum_required (VERSION 3.5)
project (Engine)
include_directories(include)
file(GLOB SOURCES "src/*.cpp")
add_executable(${CMAKE_PROJECT_NAME} ${SOURCES})
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(EnTT REQUIRED)
find_package(spdlog REQUIRED)
find_package(glm REQUIRED)
find_package(SDL2 REQUIRED)
target_link_libraries(
                    ${CMAKE_PROJECT_NAME}
                    PUBLIC
                     EnTT::EnTT
                     spdlog::spdlog
                     glm::glm
                     SDL2::SDL2
)
