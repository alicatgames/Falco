cmake_minimum_required(VERSION 3.1...3.24)

# Not ideal to use this global variable, but necessary to make sure
# that tooling and projects use the same version
set(CMAKE_CXX_STANDARD 20)

# strongly encouraged to enable this globally to avoid conflicts between
# -Wpedantic being enabled and -std=c++20 and -std=gnu++20 for example
# when compiling with PCH enabled
set(CMAKE_CXX_EXTENSIONS ON)

include(FetchContent)
# Note: by default ENABLE_DEVELOPER_MODE is True
# This means that all analysis (sanitizers, static analysis)
# is enabled and all warnings are treated as errors
# if you want to switch this behavior, change TRUE to FALSE
set(ENABLE_DEVELOPER_MODE
        TRUE
        CACHE BOOL "Enable 'developer mode'")

# Change this to false if you want to disable warnings_as_errors in developer mode
set(OPT_WARNINGS_AS_ERRORS_DEVELOPER_DEFAULT TRUE)

# Add project_options v0.17.0
# https://github.com/cpp-best-practices/project_options
FetchContent_Declare(_project_options
        URL https://github.com/cpp-best-practices/project_options/archive/refs/tags/v0.17.0.zip)
FetchContent_MakeAvailable(_project_options)
include(${_project_options_SOURCE_DIR}/Index.cmake)


# Set the project name and language
project(
        Falco
        VERSION 0.0.1
        DESCRIPTION ""
        HOMEPAGE_URL "https://github.com/alicatgames/falco"
        LANGUAGES CXX C)


#set(CMAKE_AUTORCC)
#set(CMAKE_AUTOMOC)
set(CMAKE_CXX_STANDARD 20)

configure_file(Config.h.in Config.h)

add_library(Falco SHARED "${PROJECT_SOURCE_DIR}/Falco")
#set_target_properties(Falco PROPERTIES LINKER_LANGUAGE CXX)
set_target_properties(Falco PROPERTIES LINKER_LANGUAGE CXX
        FRAMEWORK TRUE
        FRAMEWORK_VERSION CXX
        MACOSX_BUNDLE ON
        MACOSX_FRAMEWORK_IDENTIFIER com.cmake.Falco

        #        MACOSX_FRAMEWORK_INFO_PLIST Info.plist
        # "current version" in semantic format in Mach-O binary file
        VERSION 1.0.0
        # "compatibility version" in semantic format in Mach-O binary file
        SOVERSION 1.0.0
        #        PUBLIC_HEADER Falco.h
        )
add_subdirectory(Falco)
add_subdirectory(Sandbox)

target_include_directories(Falco PUBLIC
        "${PROJECT_SOURCE_DIR}/Sandbox/src"
        "${PROJECT_SOURCE_DIR}/Falco/src"
        "${PROJECT_SOURCE_DIR}/Falco/vendor/spdlog/include"
        )

target_precompile_headers(Falco PUBLIC ${PROJECT_SOURCE_DIR}/Falco/src/flcpch.h)