# set project name
set (SUBPROJECT radf)
# set additional cmake file
include (${SUBPROJECT}.cmake)

# set libraries
set (LIBRARIES mm)
foreach (LIBRARY ${LIBRARIES})
  include_directories (${CMAKE_CURRENT_SOURCE_DIR}/../${LIBRARY}/include/)
  link_directories (${LIBRARY}/src/lib)
endforeach ()

# additional targets
set (TARGETS "")
set (HEADERS "")

add_subdirectory (${SUBPROJECT_SOURCE_DIR})