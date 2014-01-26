# set project name
set (SUBPROJECT mathmech)
# set additional cmake file
include (${SUBPROJECT}.cmake)

# additional targets
set (TARGETS "")
set (HEADERS "")

add_subdirectory (${SUBPROJECT_SOURCE_DIR})
