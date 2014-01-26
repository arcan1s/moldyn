cmake_minimum_required (VERSION 2.8)

cmake_policy (SET CMP0003 OLD)
cmake_policy (SET CMP0002 OLD)
cmake_policy (SET CMP0011 NEW)
cmake_policy (SET CMP0015 NEW)

project (mathmech)
set (PROJECT_VERSION_MAJOR 1)
set (PROJECT_VERSION_MINOR 2)
set (PROJECT_VERSION_PATCH 0)
set (PROJECT_VERSION ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_PATCH})
configure_file (${CMAKE_SOURCE_DIR}/version.h.in ${CMAKE_CURRENT_BINARY_DIR}/version.h)

message (STATUS "Version ${PROJECT_VERSION}")

set (COMPS mathmech
           agl
           envir
           radf
           statgen
           trj
           trj2pdb)

# install options
set (MM_PREFIX "mm_" CACHE STRING "Prefix for mathmech tools")
option (WITH_DEBUG_MODE "Build with debug mode" OFF)
option (ADD_DOCS "Add documentation" OFF)
option (ADD_INCLUDE "Add include files" OFF)
if (CMAKE_SYSTEM_NAME MATCHES Linux)
  set (QWT_INCLUDE_PATH "/usr/include" CACHE STRING "Path to qwt include")
  set (QWT_LIBRARY_PATH "/usr/lib" CACHE STRING "Path to qwt library")
elseif (CMAKE_SYSTEM_NAME MATCHES Windows)
  set (QWT_INCLUDE_PATH "C:/Qwt-6.1.0/include" CACHE STRING "Path to qwt include")
  set (QWT_LIBRARY_PATH "C:/Qwt-6.1.0/lib" CACHE STRING "Path to qwt library")
endif ()

# verbose
set (CMAKE_VERBOSE_MAKEFILE ON)

# flags
if ( WITH_DEBUG_MODE )
  add_definitions ( -DDEBUG_MODE=1 )
endif ()
if ( CMAKE_COMPILER_IS_GNUCXX )
  set (ADD_CXX_FLAGS  "-Wall")
  set (CMAKE_CXX_FLAGS "-O0 ${ADD_CXX_FLAGS}")
  set (CMAKE_CXX_FLAGS_DEBUG "-g -O0")
  set (CMAKE_CXX_FLAGS_RELEASE "-O3 -DNDEBUG")
elseif ( MSVC )
  set (ADD_CXX_FLAGS  "/W4")
  set (CMAKE_CXX_FLAGS "${ADD_CXX_FLAGS}")
else ()
  message ("Unknown compiler")
endif ()

# set libraries
set (LIBRARIES mm)
foreach (LIBRARY ${LIBRARIES})
  add_subdirectory (${LIBRARY})
endforeach ()

foreach (COMP ${COMPS})
  add_subdirectory (${COMP})
endforeach ()

# set docs file
if (ADD_DOCS)
  include (docs.cmake)
endif ()