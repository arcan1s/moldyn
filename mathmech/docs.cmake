# standart documentation
set (PROJECT_DOCS_DIR ${CMAKE_CURRENT_SOURCE_DIR}/docs/)
install (DIRECTORY ${PROJECT_DOCS_DIR} DESTINATION share/doc/${PROJECT_NAME})

# doxygen documentation
find_package (Doxygen)
  if (DOXYGEN_FOUND)
    set (DOXYGEN_INPUT ${CMAKE_SOURCE_DIR})
    configure_file (${CMAKE_SOURCE_DIR}/doxygen.conf.in ${CMAKE_CURRENT_BINARY_DIR}/doxygen.conf)
    add_custom_target (oxygen-docs ALL COMMAND ${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/doxygen.conf)
    install (DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/docs/html DESTINATION share/doc/${PROJECT_NAME})
    install (DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/docs/man DESTINATION share/)
  else (DOXYGEN_FOUND)
    message (STATUS "WARNING: Doxygen not found - Reference manual will not be created")
endif ()
