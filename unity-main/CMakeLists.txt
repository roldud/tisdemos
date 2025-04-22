cmake_minimum_required(VERSION 3.12)
project(increment-demo
        LANGUAGES C
        DESCRIPTION "Functional and runtime testing of code")

add_executable(increment
    Unity/src/unity.c
    increment.c
    test_driver.c
)
target_include_directories(increment PUBLIC . Unity/src)
target_compile_definitions(increment PRIVATE UNITY_INCLUDE_CONFIG_H)

enable_testing()
add_test(NAME main-test COMMAND increment)