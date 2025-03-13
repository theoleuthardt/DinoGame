cmake_minimum_required(VERSION 3.30)
project(DinoGame)

set(CMAKE_CXX_STANDARD 20)

set(BASE_OUTPUT_DIR "${CMAKE_SOURCE_DIR}/build")
set(ASSETS_PATH "${CMAKE_SOURCE_DIR}/assets")

if(WIN32)
    set(OUTPUT_DIR "${BASE_OUTPUT_DIR}/windows")
    add_compile_definitions(WIN32)
elseif(UNIX AND NOT APPLE)
    set(OUTPUT_DIR "${BASE_OUTPUT_DIR}/linux")
    add_compile_definitions(LINUX)
elseif(APPLE)
    set(OUTPUT_DIR "${BASE_OUTPUT_DIR}/macos")
    add_compile_definitions(MACOS)
endif()

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${OUTPUT_DIR})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${OUTPUT_DIR})

foreach(CONFIG_TYPE ${CMAKE_CONFIGURATION_TYPES})
    string(TOUPPER ${CONFIG_TYPE} CONFIG_TYPE)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_${CONFIG_TYPE} ${OUTPUT_DIR})
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_${CONFIG_TYPE} ${OUTPUT_DIR})
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_${CONFIG_TYPE} ${OUTPUT_DIR})
endforeach()

include(FetchContent)

function(add_git_dependency libName gitURL gitTag)
    FetchContent_Declare(${libName}
            GIT_REPOSITORY ${gitURL}
            GIT_TAG        ${gitTag}
            GIT_SHALLOW    TRUE
            GIT_PROGRESS   TRUE
    )
    FetchContent_MakeAvailable(${libName})
    target_compile_options(${libName} PRIVATE "-w")
endfunction()

add_git_dependency(
        raylib
        https://github.com/raysan5/raylib.git
        5.0
)

file(GLOB_RECURSE PROJECT_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_LIST_DIR}/src/*.cpp")
set(PROJECT_INCLUDE "${CMAKE_CURRENT_LIST_DIR}/src/")

add_executable(${PROJECT_NAME})
target_sources(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCES})
target_include_directories(${PROJECT_NAME} PRIVATE ${PROJECT_INCLUDE})
target_link_libraries(${PROJECT_NAME} PRIVATE raylib)

target_compile_definitions(${PROJECT_NAME} PRIVATE RAYLIB_STATIC)

add_custom_target(copy_assets ALL
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${ASSETS_PATH} ${OUTPUT_DIR}/assets
)
add_dependencies(${PROJECT_NAME} copy_assets)
