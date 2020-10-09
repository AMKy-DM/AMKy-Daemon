
configure_file(
        src/config.hpp
        ${CMAKE_BINARY_DIR}/generated/config.hpp
)
include_directories( ${CMAKE_BINARY_DIR}/generated/ )

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
