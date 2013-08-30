cmake_minimum_required (VERSION 2.8)

cmake_policy(SET CMP0003 OLD)
cmake_policy(SET CMP0011 NEW)
cmake_policy(SET CMP0015 NEW)

# set project name
set (PROJECT mathmech)
# set additional cmake file
include (${PROJECT}.cmake)


# additional options
OPTION (WITH_DEBUG_MODE "Build with debug mode" OFF)

# set libraries
set (LIBRARIES)
  foreach (LIBRARY ${LIBRARIES})
    find_library ("${LIBRARY}_FOUND" ${LIBRARY})
      message (STATUS "Check the ${LIBRARY} is installed: " ${${LIBRARY}_FOUND})
      if ("${${LIBRARY}_FOUND}" STREQUAL "${LIBRARY}_FOUND-NOTFOUND")
        message (STATUS "Adding library sources")
        add_subdirectory (../${LIBRARY} lib/${LIBRARY})
      endif ()
  endforeach ()

# additional targets
set (TARGETS "")
set (HEADERS "")

add_subdirectory (${PROJECT_SOURCE_DIR})