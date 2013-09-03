# set files
aux_source_directory (. SOURCES)

# set library
if (CMAKE_COMPILER_IS_GNUCXX)
  set (ADDITIONAL_LIB m)
else ()
  set (ADDITIONAL_LIB)
endif ()

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
if (ADD_DOCS)
  INSTALL (FILES ${PROJECT_SOURCE_DIR}/../${_PROJECT}.pdf DESTINATION share/doc/mathmech)
endif ()
