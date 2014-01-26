# set directories
set (SUBPROJECT_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set (SUBPROJECT_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)

# include_path
include_directories (${SUBPROJECT_INCLUDE_DIR}
                     ${SUBPROJECT_SOURCE_DIR})
