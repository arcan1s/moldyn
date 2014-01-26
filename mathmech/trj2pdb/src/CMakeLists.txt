# set files
file (GLOB SOURCES *.c)
file (GLOB HEADERS *.h)

# set library
if (CMAKE_COMPILER_IS_GNUCXX)
  set (ADDITIONAL_LIB m)
else ()
  set (ADDITIONAL_LIB)
endif ()

# message
message (STATUS "${SUBPROJECT} SOURCES: ${SOURCES}")
message (STATUS "${SUBPROJECT} HEADERS: ${HEADERS}")

# link libraries and compile
add_executable (${MM_PREFIX}${SUBPROJECT} ${SOURCES} ${HEADERS})
target_link_libraries (${MM_PREFIX}${SUBPROJECT} ${ADDITIONAL_LIB} ${LIBRARIES})

# install properties
install (TARGETS ${MM_PREFIX}${SUBPROJECT} DESTINATION bin)
