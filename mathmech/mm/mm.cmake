# set directories
set (SUBPROJECT_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set (SUBPROJECT_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)

# include_path
include_directories (${SUBPROJECT_INCLUDE_DIR}
                     ${SUBPROJECT_SOURCE_DIR})

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