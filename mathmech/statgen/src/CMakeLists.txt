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
add_executable (${SUBPROJECT} ${SOURCES} ${HEADERS})
set_target_properties (${SUBPROJECT} PROPERTIES OUTPUT_NAME ${MM_PREFIX}${SUBPROJECT})
add_dependencies (${SUBPROJECT} ${LIBRARIES})
target_link_libraries (${SUBPROJECT} ${ADDITIONAL_LIB} ${LIBRARIES})

# install properties
install (TARGETS ${SUBPROJECT} DESTINATION bin)
