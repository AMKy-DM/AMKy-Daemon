
#configure_file(${CMAKE_SOURCE_DIR}/cmake/config.h.cmake ${CMAKE_CURRENT_BINARY_DIR}/config.hpp)

include_directories(
        "${CMAKE_CURRENT_SOURCE_DIR}/src"
)

add_executable(
        "${PROJECT_NAME}"
        
        src/command-line/CommandLineParser.cpp
        src/command-line/CommandDispatcher.cpp

        src/main.cpp
)

target_link_libraries("${PROJECT_NAME}" PRIVATE "${PROJECT_NAME}-lib")
