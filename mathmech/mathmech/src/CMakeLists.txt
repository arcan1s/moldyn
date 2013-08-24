set (PROJECT_VERSION_MAJOR 1)
set (PROJECT_VERSION_MINOR 0)
set (PROJECT_VERSION_PATCH 0)
set (PROJECT_VERSION ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_PATCH})

message (STATUS "${PROJECT}: Version ${PROJECT_VERSION}")

# set files
file (GLOB SOURCES *.cpp)
file (GLOB HEADERS *.h)
file (GLOB FORMS *.ui)
# set library
if (CMAKE_COMPILER_IS_GNUCXX)
  set (LIBRARIES m qwt)
else ()
  set (LIBRARIES qwt)
endif()
set (LANGUAGES
     eng
     rus)
set (RESOURCES ${PROJECT_RESOURCE_DIR}/resources.qrc)

message (STATUS "SOURCES: ${SOURCES}")
message (STATUS "HEADERS: ${HEADERS}")
message (STATUS "FORMS: ${FORMS}")


# compile
project (${PROJECT})
# include_path
include_directories (${PROJECT_INCLUDE_DIR}/${PROJECT}
                     ${PROJECT_SOURCE_DIR}
                     ${CMAKE_CURRENT_BINARY_DIR})

find_package (Qt4 REQUIRED)
include (${QT_USE_FILE})
qt4_add_resources (QRC_SOURCES ${RESOURCES})
qt4_wrap_cpp (MOC_SOURCES ${HEADERS})
qt4_wrap_ui (UI_HEADERS ${FORMS})
foreach (LANGUAGE ${LANGUAGES})
    set (TS ${PROJECT_TRANSLATION_DIR}/${LANGUAGE}.ts)
    set (QM ${PROJECT_TRANSLATION_DIR}/${LANGUAGE}.qm)
    set (TRANSLATIONS ${TRANSLATIONS} ${TS})
    set (TRANSLATIONS_BINARY ${TRANSLATIONS_BINARY} ${QM})
    add_custom_command (
        OUTPUT ${QM}
        COMMAND ${QT_LRELEASE_EXECUTABLE} ${TS}
        MAIN_DEPENDENCY ${TS})
endforeach()
add_custom_target (
    translations 
    COMMAND ${QT_LUPDATE_EXECUTABLE} ${HEADERS} ${SOURCES} -ts ${TRANSLATIONS})
add_custom_command (
    TARGET translations
    COMMAND ${QT_LRELEASE_EXECUTABLE} ${TRANSLATIONS})

source_group ("Header Files" FILES ${HEADERS})
source_group ("Source Files" FILES ${SOURCES})
source_group ("Generated Files" FILES ${MOC_SOURCES})
source_group ("Resource Files" FILES ${QRC_SOURCES})

add_executable (${PROJECT} WIN32 ${UI_HEADERS} ${HEADERS} ${SOURCES} ${MOC_SOURCES} ${QRC_SOURCES} ${TRANSLATIONS})

target_link_libraries (${PROJECT} ${LIBRARIES} ${QT_LIBRARIES} ${QT_QTMAIN_LIBRARY})

# install properties
INSTALL (TARGETS ${PROJECT} DESTINATION bin)