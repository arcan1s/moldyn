set (PROJECT mathmech)
# set directory
set (PROJECT_DOCS_DIR ${CMAKE_CURRENT_SOURCE_DIR}/docs)
install (DIRECTORY ${PROJECT_DOCS_DIR}
        DESTINATION share/doc/${PROJECT})
