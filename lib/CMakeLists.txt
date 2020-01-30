
set(LIBRARY_NAME "${PROJECT_NAME}-lib")

add_library(
        "${LIBRARY_NAME}" SHARED

        src/lib/type-definitions.hpp
        src/lib/String.hpp
        src/lib/String.cpp
        src/lib/Buffer.hpp
        src/lib/Buffer.cpp

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

target_include_directories(
        "${LIBRARY_NAME}" PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}/src"
        "${CMAKE_CURRENT_SOURCE_DIR}/src/lib"
)

target_compile_definitions(${LIBRARY_NAME} PUBLIC LIBRARY_VERSION=1)