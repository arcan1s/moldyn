set (COMPS mathmech
           mm_agl
           mm_envir
           mm_radf
           mm_statgen
           mm_trj
           mm_trj2pdb)

# install options
set (MM_PREFIX "mm_" CACHE STRING "Prefix for mathmech tools")
if (CMAKE_COMPILER_IS_GNUCXX)
  set (QWT_INCLUDE_PATH "/usr/include" CACHE STRING "Path to qwt include")
  set (QWT_LIBRARY_PATH "/usr/lib" CACHE STRING "Path to qwt library")
else ()
  set (QWT_INCLUDE_PATH "C:/Qwt-6.1.0/include" CACHE STRING "Path to qwt include")
  set (QWT_LIBRARY_PATH "C:/Qwt-6.1.0/lib" CACHE STRING "Path to qwt library")
endif()

foreach (COMP ${COMPS})
  add_subdirectory (${COMP})
endforeach()