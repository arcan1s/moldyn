cmake_minimum_required (VERSION 2.6)

set (PROJECT mathmech)

# additional options
OPTION (WITH_DEBUG_MODE "Build with debug mode" OFF)
OPTION (ADD_INCLUDE "Add include files" OFF)

# executable path
set (EXECUTABLE_OUTPUT_PATH ${${PROJECT}_BINARY_DIR})

# verbose
set (CMAKE_VERBOSE_MAKEFILE ON)

# flags
if ( WITH_DEBUG_MODE )
  add_definitions ( -DDEBUG_MODE=1 )
endif ()
if ( CMAKE_COMPILER_IS_GNUCXX )
  set (ADD_CXX_FLAGS  "-Wall")
  set (CMAKE_CXX_FLAGS "-O0 ${ADD_CXX_FLAGS}")
  set (CMAKE_CXX_FLAGS_DEBUG "-g -O0")
  set (CMAKE_CXX_FLAGS_RELEASE "-O3 -DNDEBUG")
elseif ( MSVC )
  set (ADD_CXX_FLAGS  "/W4")
  set (CMAKE_CXX_FLAGS "${ADD_CXX_FLAGS}")
else ()
  message ("Unknown compiler")
endif ()

# set directories
set (${PROJECT}_BINARY_DIR ../bin)
set (${PROJECT}_RESOURCE_DIR ../resources)
set (${PROJECT}_TRANSLATION_DIR ${${PROJECT}_RESOURCE_DIR}/translations)

# set files
set (HEADERS 
     ../aboutwindow.h
     ../aglallwindow.h
     ../agglwindow.h
     ../atomtypeswindow.h
     ../clear_items.h
     ../errorwindow.h
     ../mainwindow.h
     ../settingswindow.h
     ../start_events.h
     ../statgengraphwindow.h
     ../update_fields.h)
set (SOURCES 
     ../aboutwindow.cpp
     ../aglallwindow.cpp
     ../agglwindow.cpp
     ../atomtypeswindow.cpp
     ../clear_items.cpp
     ../errorwindow.cpp
     ../main.cpp
     ../mainwindow.cpp
     ../settingswindow.cpp
     ../start_events.cpp
     ../statgengraphwindow.cpp
     ../update_fields.cpp)
set (FORMS
     ../aboutwindow.ui
     ../agglwindow.ui
     ../aglallwindow.ui
     ../atomtypeswindow.ui
     ../errorwindow.ui
     ../mainwindow.ui
     ../settingswindow.ui
     ../statgengraphwindow.ui)
# set library
if (CMAKE_COMPILER_IS_GNUCXX)
  set (LIBRARIES m)
else ()
  set (LIBRARIES)
endif()
set (LANGUAGES
     eng
     rus)
set (RESOURCES
     ${${PROJECT}_RESOURCE_DIR}/resources.qrc)


# compile
project (${PROJECT})
include_directories (../
                     ${CMAKE_CURRENT_BINARY_DIR})

find_package (Qt4 REQUIRED)
include (${QT_USE_FILE})
qt4_add_resources (QRC_SOURCES ${RESOURCES})
qt4_wrap_cpp (MOC_SOURCES ${HEADERS})
qt4_wrap_ui (UI_HEADERS ${FORMS})
foreach (LANGUAGE ${LANGUAGES})
    set (TS ${${PROJECT}_TRANSLATION_DIR}/${LANGUAGE}.ts)
    set (QM ${${PROJECT}_TRANSLATION_DIR}/${LANGUAGE}.qm)
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
