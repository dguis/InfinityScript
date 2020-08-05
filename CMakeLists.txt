
cmake_minimum_required(VERSION 3.17)

# define project

project(Base VERSION 1.1
                 DESCRIPTION "Base Code"
                 LANGUAGES CXX)


# define sources

set(SOURCES_BASE "src/main.cpp"
                 "src/imgui_impl_sdl.cpp"
                 "src/imgui_impl_opengl3.cpp")

# setup OS-specific options

if(UNIX AND NOT APPLE)
    set(LINUX TRUE)
endif()

if(APPLE)
	set(CMAKE_EXE_LINKER_FLAGS "-framework AppKit")
	find_package(SDL2 REQUIRED)
	include_directories(${SDL2_INCLUDE_DIRS}/..)
	include_directories(${SDL2_INCLUDE_DIRS})
	link_directories(${SDL2_LIBRARY_DIRS})
	add_definitions(${SDL2_CFLAGS_OTHER})
endif()

if(LINUX)
    find_package(PkgConfig REQUIRED)
    pkg_check_modules(SDL2 REQUIRED sdl2)
    include_directories(${SDL2_INCLUDE_DIRS})
    link_directories(${SDL2_LIBRARY_DIRS})
    add_definitions(${SDL2_CFLAGS_OTHER})
endif()







# define executable

if(WIN32)
    add_executable(Base WIN32 ${SOURCES_BASE})
else()
    add_executable(Base ${SOURCES_BASE})
endif()

set_target_properties(Base PROPERTIES
                      CXX_STANDARD 17
                      CXX_EXTENSIONS OFF)

if(MSVC)
    target_compile_options(Base PRIVATE /W4 /WX)
else()
    target_compile_options(Base PRIVATE -Wall -Wextra -Werror)
endif()

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
target_link_libraries(Base PRIVATE Threads::Threads)



# define include paths

target_include_directories(Base PRIVATE "deps/")
include_directories("${BASE_SOURCE_DIR}/deps/")




# build dependencies

add_subdirectory("deps/imgui/")
add_subdirectory("deps/glad/")



# link libraries 

if(WIN32)
    target_include_directories(Base PRIVATE "deps/win")
    add_definitions(-DWIN32_LEAN_AND_MEAN)
    if(MSVC)
        set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /IGNORE:4098 /IGNORE:4099")
    endif()
    target_link_libraries(Base PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/deps/win/SDL2/SDL2main.lib")
    target_link_libraries(Base PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/deps/win/SDL2/SDL2.lib")
    target_link_libraries(Base PRIVATE Winmm)
    target_link_libraries(Base PRIVATE Version)
    target_link_libraries(Base PRIVATE Setupapi)
    target_link_libraries(Base PRIVATE Shcore)
endif()

if(LINUX)
    target_link_libraries(Base PRIVATE SDL2)
endif()

if(APPLE)
	target_link_libraries(Base PRIVATE ${SDL2_LIBRARIES})
endif()

target_link_libraries(Base PRIVATE imgui)
target_link_libraries(Base PRIVATE glad)
