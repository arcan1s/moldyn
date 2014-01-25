# set project name
set (PROJECT mm)
# set additional cmake file
include (${PROJECT}.cmake)
if (ADD_DOCS)
  include (doxygen.cmake)
endif ()

# additional targets
set (TARGETS "")
set (HEADERS "")

add_subdirectory (${PROJECT_SOURCE_DIR})