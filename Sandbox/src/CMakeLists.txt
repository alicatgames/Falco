cmake_minimum_required(VERSION 3.1...3.24)

add_executable (Sandbox SandboxApp.cpp)

#target_link_libraries(Sandbox STATIC Falco)

target_include_directories(Sandbox PUBLIC
        "${PROJECT_SOURCE_DIR}/Sandbox/src"
        "${PROJECT_SOURCE_DIR}/Falco/src"
        "${PROJECT_SOURCE_DIR}/Falco/vendor/spdlog/include"
        )

target_precompile_headers(Sandbox PUBLIC ${PROJECT_SOURCE_DIR}/Falco/src/flcpch.h)