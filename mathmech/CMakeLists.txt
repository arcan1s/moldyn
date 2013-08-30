set ("PROJECT_VERSION_MAJOR" 1)
set ("PROJECT_VERSION_MINOR" 0)
set ("PROJECT_VERSION_PATCH" 3)
set ("PROJECT_VERSION" ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_PATCH})

message (STATUS "Version ${PROJECT_VERSION}")

set (COMPS mathmech
           mm_agl
           mm_envir
           mm_radf
           mm_statgen
           mm_trj
           mm_trj2pdb)

# install options
set (MM_PREFIX "mm_" CACHE STRING "Prefix for mathmech tools")
OPTION (WITH_DEBUG_MODE "Build with debug mode" OFF)
OPTION (ADD_INCLUDE "Add include files" OFF)
OPTION (ADD_DOCS "Add documentation" OFF)
if (CMAKE_SYSTEM_NAME MATCHES Linux)
  set (QWT_INCLUDE_PATH "/usr/include" CACHE STRING "Path to qwt include")
  set (QWT_LIBRARY_PATH "/usr/lib" CACHE STRING "Path to qwt library")
elseif (CMAKE_SYSTEM_NAME MATCHES Windows)
  set (QWT_INCLUDE_PATH "C:/Qwt-6.1.0/include" CACHE STRING "Path to qwt include")
  set (QWT_LIBRARY_PATH "C:/Qwt-6.1.0/lib" CACHE STRING "Path to qwt library")
endif()

foreach (COMP ${COMPS})
  add_subdirectory (${COMP})
endforeach()