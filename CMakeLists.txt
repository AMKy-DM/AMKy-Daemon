cmake_minimum_required(VERSION 3.15)
project(AMKy-Daemon VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(lib)
add_subdirectory(daemon)


include(CTest)

add_test("test1" "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}")