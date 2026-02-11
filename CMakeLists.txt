cmake_minimum_required(VERSION 3.10)
project(PrimeOps)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${CMAKE_SOURCE_DIR}/include)
include_directories(${CMAKE_SOURCE_DIR}/tests)

add_executable(prime_main
    src/main.cpp
    src/prime.cpp
)

add_executable(prime_tests
    tests/test.cpp
    src/prime.cpp
)

target_link_libraries(prime_main stdc++)
target_link_libraries(prime_tests stdc++)

enable_testing()
add_test(NAME prime_tests COMMAND prime_tests)