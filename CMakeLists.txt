cmake_minimum_required(VERSION 3.16)

project(MyCppApp)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(my_app src/main.cpp)

option(BUILD_TESTS "Build unit tests" OFF)

if(BUILD_TESTS)
    find_package(GTest REQUIRED)

    add_executable(my_test tests/test.cpp)

    target_link_libraries(
        my_test
        GTest::gtest
    )

    enable_testing()

    add_test(NAME MyTest COMMAND my_test)
endif()

