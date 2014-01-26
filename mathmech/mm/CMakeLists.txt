# set project name
set (SUBPROJECT mm)
# set additional cmake file
include (${SUBPROJECT}.cmake)

# additional targets
set (TARGETS "")
set (HEADERS "")

add_subdirectory (${SUBPROJECT_SOURCE_DIR})