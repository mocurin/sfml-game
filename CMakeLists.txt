cmake_minimum_required(VERSION 3.2)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_FLAGS "-pthread")

include("tools/hunter/HunterGate.cmake")

HunterGate(
    URL "https://github.com/cpp-pm/hunter/archive/v0.23.244.tar.gz"
    SHA1 "2c0f491fd0b80f7b09e3d21adb97237161ef9835"
)

project(game)

hunter_add_package(SFML)
find_package(SFML COMPONENTS audio graphics REQUIRED)

hunter_add_package(GTest)
find_package(GTest REQUIRED)

add_executable(main ${CMAKE_CURRENT_SOURCE_DIR}/sources/source.cpp)
target_include_directories(main PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/includes/)
target_link_libraries(main sfml-graphics)

add_executable(tests ${CMAKE_CURRENT_SOURCE_DIR}/tests/test.cpp)
target_include_directories(tests PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/includes/)
target_link_libraries(tests GTest::Main)






