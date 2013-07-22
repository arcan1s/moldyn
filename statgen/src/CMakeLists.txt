set ("${PROJECT}_VERSION_MAJOR" 1)
set ("${PROJECT}_VERSION_MINOR" 0)
set ("${PROJECT}_VERSION_PATCH" 1)
set ("${PROJECT}_VERSION" ${${PROJECT}_VERSION_MAJOR}.${${PROJECT}_VERSION_MINOR}.${${PROJECT}_VERSION_PATCH})

message (STATUS ${${PROJECT}_VERSION})

## set files
# main files
set (MAIN_SOURCES main)
# not public srcs
set (PRIVATE_CLASSES)
# headers only files
SET (HEADERS_ONLY)
# public srcs
set (PUBLIC_CLASSES add_main 
                    coords 
                    graph 
                    int2char 
                    messages 
                    stat_print 
                    stat_select 
                    stat_sort 
                    summary_stat)
# public headers
set (PUBLIC_HEADERS)
# shared libraries
if (CMAKE_COMPILER_IS_GNUCXX)
  set (ADDITIONAL_LIB m)
else ()
  set (ADDITIONAL_LIB)
endif()
set (SOURCES)

# append list
foreach (class ${PRIVATE_CLASSES})
  LIST (APPEND SOURCES ${class}.c)
  LIST (APPEND HEADERS ${class}.h)
endforeach ()

foreach (class ${HEADERS_ONLY})
  LIST (APPEND HEADERS ${class}.h)
endforeach ()

foreach (class ${PUBLIC_CLASSES})
  LIST (APPEND SOURCES ${class}.c)
  LIST (APPEND HEADERS ../include/${PROJECT}/${class}.h)
  LIST (APPEND PUBLIC_HEADERS ../include/${PROJECT}/${class}.h)
endforeach ()

# message
message (STATUS "SOURCES: ${SOURCES}")

# link libraries and compile
add_executable (${PROJECT} ${MAIN_SOURCES} ${SOURCES})
target_link_libraries (${PROJECT} ${ADDITIONAL_LIB})

# install properties
INSTALL (TARGETS ${PROJECT} 
         DESTINATION bin)
if (ADD_INCLUDE)
  INSTALL (FILES ${PUBLIC_HEADERS} 
           DESTINATION include/${PROJECT})
endif ()