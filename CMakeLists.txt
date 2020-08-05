cmake_minimum_required(VERSION 3.17)

# define project

project(InfinityScript VERSION 1.1
                 DESCRIPTION "InfinityScript Code"
                 LANGUAGES CXX)


# define sources

set(SOURCES_InfinityScript "src/main.cpp"
                            "src/lexer.cpp"
                            "src/toolbox.cpp")

# setup OS-specific options

if(UNIX AND NOT APPLE)
    set(LINUX TRUE)
endif()


# define executable

if(WIN32)
    add_executable(InfinityScript ${SOURCES_InfinityScript})
else()
    add_executable(InfinityScript ${SOURCES_InfinityScript})
endif()

set_target_properties(InfinityScript PROPERTIES
                      CXX_STANDARD 17
                      CXX_EXTENSIONS OFF)

if(MSVC)
    target_compile_options(InfinityScript PRIVATE /W4 /WX)
else()
    target_compile_options(InfinityScript PRIVATE -Wall -Wextra -Werror)
endif()

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
target_link_libraries(InfinityScript PRIVATE Threads::Threads)



# define include paths

target_include_directories(InfinityScript PRIVATE "deps/")
include_directories("${InfinityScript_SOURCE_DIR}/deps/")
