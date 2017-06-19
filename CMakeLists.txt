cmake_minimum_required(VERSION 2.8.2)

configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)
execute_process(COMMAND "${CMAKE_COMMAND}" -G "${CMAKE_GENERATOR}" .
    WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/googletest-download" )
execute_process(COMMAND "${CMAKE_COMMAND}" --build .
    WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/googletest-download" )

enable_testing()
set(GTEST_LIBRARY "${CMAKE_BINARY_DIR}/googletest-build")
set(GTEST_MAIN_LIBRARY "${CMAKE_BINARY_DIR}/googletest-build")
set(GTEST_INCLUDE_DIR "${gtest_SOURCE_DIR}/include")
find_package(GTest REQUIRED)

add_subdirectory("${CMAKE_BINARY_DIR}/googletest-src"
    "${CMAKE_BINARY_DIR}/googletest-build")

include_directories("${gtest_SOURCE_DIR}/include"
    "${gmock_SOURCE_DIR}/include")

file(GLOB SRCS src/babysitter.cpp src/main.cpp)
file(GLOB TEST_SRCS src/babysitter_tests.cpp src/babysitter.cpp)

add_executable(babysitter ${SRCS})
add_executable(babysitterTest ${TEST_SRCS})
target_link_libraries(babysitterTest gtest)
add_test(babysitterTest babysitterTest)
