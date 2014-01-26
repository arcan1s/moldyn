# set files
file (GLOB SOURCES *.cpp)
file (GLOB HEADERS *.h)
file (GLOB FORMS *.ui)
if (CMAKE_SYSTEM_NAME MATCHES Windows)
  set (SOURCES ${SOURCES} ${SUBPROJECT_RESOURCE_DIR}/res_icon.rc)
endif ()
# set library
if (CMAKE_COMPILER_IS_GNUCXX)
  set (LIBRARIES m qwt)
else ()
  set (LIBRARIES qwt)
endif ()
set (LANGUAGES
     eng
     rus)
set (RESOURCES ${SUBPROJECT_RESOURCE_DIR}/resources.qrc)

message (STATUS "${SUBPROJECT} SOURCES: ${SOURCES}")
message (STATUS "${SUBPROJECT} HEADERS: ${HEADERS}")
message (STATUS "${SUBPROJECT} FORMS: ${FORMS}")


# compile
project (${SUBPROJECT})
# include_path
link_directories (${QWT_LIBRARY_PATH})
include_directories (${SUBPROJECT_SOURCE_DIR}
                     ${CMAKE_CURRENT_BINARY_DIR}
                     ${QWT_INCLUDE_PATH})

find_package (Qt4 REQUIRED)
include (${QT_USE_FILE})
qt4_add_resources (QRC_SOURCES ${RESOURCES})
qt4_wrap_cpp (MOC_SOURCES ${HEADERS})
qt4_wrap_ui (UI_HEADERS ${FORMS})
foreach (LANGUAGE ${LANGUAGES})
    set (TS ${SUBPROJECT_TRANSLATION_DIR}/${LANGUAGE}.ts)
    set (QM ${SUBPROJECT_TRANSLATION_DIR}/${LANGUAGE}.qm)
    set (TRANSLATIONS ${TRANSLATIONS} ${TS})
    set (TRANSLATIONS_BINARY ${TRANSLATIONS_BINARY} ${QM})
    add_custom_command (
        OUTPUT ${QM}
        COMMAND ${QT_LRELEASE_EXECUTABLE} ${TS}
        MAIN_DEPENDENCY ${TS})
endforeach ()
add_custom_target (
    translations 
    COMMAND ${QT_LUPDATE_EXECUTABLE} ${HEADERS} ${SOURCES} ${UI_HEADERS} -ts ${TRANSLATIONS})
add_custom_command (
    TARGET translations
    COMMAND ${QT_LRELEASE_EXECUTABLE} ${TRANSLATIONS})
message (STATUS "${SUBPROJECT} TRANSLATIONS: ${TRANSLATIONS_BINARY}")

source_group ("Header Files" FILES ${HEADERS})
source_group ("Source Files" FILES ${SOURCES})
source_group ("Generated Files" FILES ${MOC_SOURCES})
source_group ("Resource Files" FILES ${QRC_SOURCES})

add_executable (${SUBPROJECT} WIN32 ${UI_HEADERS} ${HEADERS} ${SOURCES} ${MOC_SOURCES} ${QRC_SOURCES} ${TRANSLATIONS})
target_link_libraries (${SUBPROJECT} ${LIBRARIES} ${QT_LIBRARIES} ${QT_QTMAIN_LIBRARY})

# install properties
install (TARGETS ${SUBPROJECT} DESTINATION bin)
if (CMAKE_SYSTEM_NAME MATCHES Linux)
  install (FILES ../mathmech.desktop DESTINATION share/applications/)
  install (FILES ../mathmech-logo.png DESTINATION share/pixmaps/)
  install (FILES ../mathmech.png DESTINATION share/icons/hicolor/32x32/apps/)
endif ()
