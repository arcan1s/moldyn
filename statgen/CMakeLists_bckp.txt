cmake_minimum_required(VERSION 2.8)

project(statgen)

set(MY_CXX_FLAGS  "-Wall")
set(CMAKE_CXX_FLAGS "-O0 ${MY_CXX_FLAGS}")
set(CMAKE_SHARED_LINKER_FLAGS "-lm")

set(SOURCE_EXE main.c)
set(SOURCE_LIB add_main.c 
               coords.c 
               graph.c 
               int2char.c 
               messages.c 
               stat_print.c
               stat_select.c
               stat_sort.c
               summary_stat.c)

add_library(stat SHARED ${SOURCE_LIB})
add_executable(statgen ${SOURCE_EXE})

target_link_libraries(statgen stat)