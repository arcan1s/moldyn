set (COMPS mathmech
           mm_agl
           mm_envir
           mm_radf
           mm_statgen
           mm_trj
           mm_trj2pdb)

foreach (COMP ${COMPS})
  add_subdirectory (${COMP})
endforeach()