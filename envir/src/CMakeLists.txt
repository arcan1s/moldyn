set ("${PROJECT}_VERSION_MAJOR" 1)
set ("${PROJECT}_VERSION_MINOR" 0)
set ("${PROJECT}_VERSION_PATCH" 1)
set ("${PROJECT}_VERSION" ${${PROJECT}_VERSION_MAJOR}.${${PROJECT}_VERSION_MINOR}.${${PROJECT}_VERSION_PATCH})

message (STATUS "${PROJECT}: Version ${${PROJECT}_VERSION}")

# set files
aux_source_directory (. SOURCES)

# set library
if (CMAKE_COMPILER_IS_GNUCXX)
  set (ADDITIONAL_LIB m)
else ()
  set (ADDITIONAL_LIB)
endif()

# message
message (STATUS "SOURCES: ${SOURCES}")

# link libraries and compile
add_executable (${PROJECT} ${SOURCES})
target_link_libraries (${PROJECT} ${ADDITIONAL_LIB})

# install properties
INSTALL (TARGETS ${PROJECT} DESTINATION bin)
if (ADD_INCLUDE)
  INSTALL (FILES ${PUBLIC_HEADERS} DESTINATION include/${PROJECT})
endif ()