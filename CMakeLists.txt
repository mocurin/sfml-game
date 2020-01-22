cmake_minimum_required(VERSION 3.2)

set(CMAKE_CXX_STANDARD 17)
string(APPEND CMAKE_CXX_FLAGS "-pthread" )

include("tools/gate/cmake/HunterGate.cmake")

HunterGate(
    URL "https://github.com/cpp-pm/hunter/archive/v0.23.244.tar.gz"
    SHA1 "2c0f491fd0b80f7b09e3d21adb97237161ef9835"
)

project(game)

hunter_add_package(SFML)
find_package(SFML COMPONENTS audio window graphics REQUIRED)

hunter_add_package(GTest)
find_package(GTest REQUIRED)

add_library(utility ${CMAKE_CURRENT_SOURCE_DIR}/sources/utility.cpp)
target_include_directories(utility PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/includes/)

add_library(core ${CMAKE_CURRENT_SOURCE_DIR}/sources/core.cpp)
target_include_directories(core PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/includes/)
target_link_libraries(core utility sfml-graphics sfml-window)

add_executable(main ${CMAKE_CURRENT_SOURCE_DIR}/sources/source.cpp)
target_include_directories(main PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/includes/)
target_link_libraries(main core)

#add_executable(utility_test ${CMAKE_CURRENT_SOURCE_DIR}/tests/utility_test.cpp)
#target_include_directories(utility_test PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/includes/)
#target_link_libraries(utility_test utility GTest::Main)
