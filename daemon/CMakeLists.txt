
add_executable(
        "${PROJECT_NAME}"
        src/main.cpp
        src/command-line/CommandLineParser.hpp
        src/command-line/CommandLineParser.cpp
)

target_link_libraries("${PROJECT_NAME}" PRIVATE "${PROJECT_NAME}-lib")
