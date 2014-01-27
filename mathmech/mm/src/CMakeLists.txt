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
add_library (${SUBPROJECT} SHARED ${SOURCES} ${HEADERS})
set_target_properties (${SUBPROJECT} PROPERTIES SOVERSION ${PROJECT_VERSION})
target_link_libraries (${SUBPROJECT} ${ADDITIONAL_LIB})

# install properties
install (TARGETS ${SUBPROJECT} DESTINATION lib)
if (ADD_INCLUDE)
  install (DIRECTORY ${SUBPROJECT_INCLUDE_DIR}/ DESTINATION include/)
endif ()
