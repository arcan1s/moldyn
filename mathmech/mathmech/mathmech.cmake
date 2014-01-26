# set directories
set (SUBPROJECT_BINARY_DIR bin)
set (SUBPROJECT_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set (SUBPROJECT_RESOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/resources)
set (SUBPROJECT_TRANSLATION_DIR ${SUBPROJECT_RESOURCE_DIR}/translations)

# executable path
set (EXECUTABLE_OUTPUT_PATH ${SUBPROJECT_BINARY_DIR})

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