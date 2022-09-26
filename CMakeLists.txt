cmake_minimum_required(VERSION 3.1...3.24)

project(Falco
        VERSION 1.0
        LANGUAGES CXX)

configure_file(Config.h.in Config.h)

#add_executable(FalcoEngine Falco)

#add_library(Falco STATIC "${PROJECT_SOURCE_DIR}/Falco/src")
#set_target_properties(Falco PROPERTIES LINKER_LANGUAGE CXX)

add_subdirectory(Falco)
add_subdirectory(Sandbox)