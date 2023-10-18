cmake_minimum_required(VERSION 3.26)
project(p_engine_2D)

set(CMAKE_CXX_STANDARD 23)
set(SFML_VERSION "2.6.0")

include(FetchContent)
FetchContent_Declare(sfml GIT_REPOSITORY "https://github.com/SFML/SFML.git" GIT_TAG "${SFML_VERSION}")

set(BUILD_SHARED_LIBS OFF)
set(SFML_BUILD_EXAMPLES OFF)
set(SFML_BUILD_DOC OFF)
set(SFML_BUILD_NETWORK OFF)
set(SFML_BUILD_AUDIO ON)
set(SFML_BUILD_GRAPHICS ON)
set(SFML_BUILD_WINDOW ON)

FetchContent_GetProperties(sfml)
if(NOT sfml_POPULATED)
    FetchContent_Populate(sfml)
    add_subdirectory(${sfml_SOURCE_DIR} ${sfml_BINARY_DIR})
endif()

add_executable(p_engine_2D src/main.cpp)
target_link_libraries(p_engine_2D PRIVATE sfml-graphics sfml-system sfml-window)

if (WIN32 AND BUILD_SHARED_LIBS)
    add_custom_command(TARGET exe POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_RUNTIME_DLLS:exe> $<TARGET_FILE_DIR:exe>
            COMMAND_EXPAND_LISTS
    )
endif()
