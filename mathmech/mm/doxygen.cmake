# build docs
find_package (Doxygen)
if (DOXYGEN_FOUND)
  set (PROJECT_DOCS_DIR ${CMAKE_CURRENT_SOURCE_DIR}/docs/html)
  set (DOXYGEN_INPUT ${CMAKE_CURRENT_SOURCE_DIR})
  configure_file (${CMAKE_CURRENT_SOURCE_DIR}/mm.doxygen ${CMAKE_CURRENT_BINARY_DIR}/doxygen.conf)
  add_custom_target (docs COMMAND ${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/doxygen.conf)
else (DOXYGEN_FOUND)
  message (STATUS "WARNING: Doxygen not found - Reference manual will not be created")
endif ()

# instal properties
# install (DIRECTORY ${PROJECT_DOCS_DIR} DESTINATION share/doc/${PROJECT_LONG})
