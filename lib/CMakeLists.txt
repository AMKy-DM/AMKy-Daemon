
set(LIBRARY_NAME "${PROJECT_NAME}-lib")

add_library(
        "${LIBRARY_NAME}" SHARED


        src/download/DownloadItem.cpp

        src/download/DownloadManager.cpp

        src/DaemonHost.cpp
)

target_include_directories(
        "${LIBRARY_NAME}" PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}/src"
        "${CMAKE_CURRENT_SOURCE_DIR}/src/core"
        "${CMAKE_CURRENT_SOURCE_DIR}/src/lib"
)

target_compile_definitions(${LIBRARY_NAME} PUBLIC LIBRARY_VERSION=1)