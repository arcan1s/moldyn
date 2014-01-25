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
message (STATUS "${PROJECT} SOURCES: ${SOURCES}")
message (STATUS "${PROJECT} HEADERS: ${HEADERS}")

# link libraries and compile
add_library (${PROJECT} SHARED ${SOURCES} ${HEADERS})
target_link_libraries (${PROJECT} ${ADDITIONAL_LIB})

# install properties
install (TARGETS ${PROJECT} DESTINATION lib)
