# set directories
set (SUBPROJECT_BINARY_DIR bin)
set (SUBPROJECT_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

# include_path
include_directories (${SUBPROJECT_SOURCE_DIR}
                     ${CMAKE_CURRENT_BINARY_DIR}/../)

# executable path
set (EXECUTABLE_OUTPUT_PATH ${SUBPROJECT_BINARY_DIR})
