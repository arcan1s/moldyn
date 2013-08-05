# set directories
set (${PROJECT}_BINARY_DIR bin)
set (${PROJECT}_SOURCE_DIR src)
set (${PROJECT}_INCLUDE_DIR include)
set (${PROJECT}_LIB_DIR lib)

# include_path
include_directories (${${PROJECT}_INCLUDE_DIR}/${PROJECT}
                     ${${PROJECT}_SOURCE_DIR})
# library path
link_directories (${${PROJECT}_LIB_DIR})
# executable path
set (EXECUTABLE_OUTPUT_PATH ${${PROJECT}_BINARY_DIR})

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