
set(LIBRARY_NAME "${PROJECT_NAME}-lib")

add_subdirectory(src/lib)

add_library(
        "${LIBRARY_NAME}" SHARED

        src/type-definitions.hpp

        src/exceptions/AMKyException.hpp
        src/exceptions/AMKyException.cpp

        src/http/HttpStream.hpp
        src/http/HttpStream.cpp

        src/http/HttpClient.hpp
        src/http/HttpClient.nix.cpp
        src/http/HttpClient.win.cpp

        src/download/DownloadManager.hpp
        src/download/DownloadManager.cpp

        src/upnp/UPNPGatewayManager.hpp
        src/upnp/UPNPGatewayManager.cpp

        src/DaemonHost.hpp
        src/DaemonHost.cpp
)

target_link_libraries("${LIBRARY_NAME}" CppLib)

target_include_directories(
        "${LIBRARY_NAME}" PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}/src"
        "${CMAKE_CURRENT_SOURCE_DIR}/src/lib"
)

target_compile_definitions(${LIBRARY_NAME} PUBLIC LIBRARY_VERSION=1)