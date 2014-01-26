# set project name
set (SUBPROJECT mathmech)
# set additional cmake file
include (${SUBPROJECT}.cmake)


# additional options
option (WITH_DEBUG_MODE "Build with debug mode" OFF)

# additional targets
set (TARGETS "")
set (HEADERS "")

add_subdirectory (${SUBPROJECT_SOURCE_DIR})