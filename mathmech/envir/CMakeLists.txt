# set project name
set (PROJECT envir)
# set additional cmake file
include (${PROJECT}.cmake)

# set libraries
set (LIBRARIES "")
foreach (LIBRARY ${LIBRARIES})
  add_subdirectory (../${LIBRARY} bin/${LIBRARY})
  include_directories (${CMAKE_CURRENT_SOURCE_DIR}/../${LIBRARY}/include/)
endforeach ()

# additional targets
set (TARGETS "")
set (HEADERS "")

add_subdirectory (${PROJECT_SOURCE_DIR})