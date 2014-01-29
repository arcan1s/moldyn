# set project name
set (SUBPROJECT agl)
# set additional cmake file
include (${SUBPROJECT}.cmake)

# set libraries
set (LIBRARIES mm)
foreach (LIBRARY ${LIBRARIES})
  include_directories (${CMAKE_CURRENT_SOURCE_DIR}/../${LIBRARY}/include/)
  if (CMAKE_COMPILER_IS_GNUCXX)
    link_directories (${LIBRARY}/src/lib)
  elseif (CMAKE_COMPILER_IS_MSVC)
    link_directories (${LIBRARY}/src/Release)
  endif ()
endforeach ()

# additional targets
set (TARGETS "")
set (HEADERS "")

add_subdirectory (${SUBPROJECT_SOURCE_DIR})