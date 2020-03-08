cmake_minimum_required(VERSION 3.15.3)
project(virtual_on_test)

add_library(alphabet STATIC concrete.cpp)
target_compile_definitions(alphabet PUBLIC VIRTUAL_ON_TEST=)

add_library(alphabet_ut STATIC concrete.cpp)
target_compile_definitions(alphabet_ut PUBLIC VIRTUAL_ON_TEST=virtual)

enable_testing()
find_package(GTest REQUIRED)
find_package(GMock REQUIRED)

add_executable(test_concrete concrete_tests.cpp)
target_include_directories(test_concrete PUBLIC ${GTEST_INCLUDE_DIRS} ${GMOCK_INCLUDE_DIRS})
target_link_libraries(test_concrete alphabet_ut GTest::GTest GTest::Main ${GMOCK_BOTH_LIBRARIES})

add_test(test_all, test_concrete)
