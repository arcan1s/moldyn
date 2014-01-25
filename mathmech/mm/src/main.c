/**
 * @file
 */
/**
 * @mainpage libmm
 * @image latex ./logo.png
 *
 * @section intro_sec Introduction
 *
 * <b>About this program</b>:
 * <ul>
 * <li>Library for mathmech
 * </ul>
 *
 * <b>Developer</b>:
 * <ul>
 * <li>Evgeniy Alekseev aka arcanis <pre><esalexeev (at) gmail (dot) com></pre>
 *</ul>
 * <b>License</b>:
 * <ul>
 * <li>GPL
 * </ul>
 * 
 * @page Install
 * 
 * @section Requirements Requirements
 * The application mmlib requires the following external stuff:
 * - cmake  >= 2.8
 * - gcc    >= 4.8
 *
 * @section How-To How to install
 *
 * @subsection Linux Linux
 * @code
 * mkdir build && cd build
 * cmake -DCMAKE_INSTALL_PREFIX=/usr -DCMAKE_BUILD_TYPE=Release ../
 * make
 * make install
 * @endcode
 * 
 * @subsection Windows Windows
 * @code
 * create project file using 'cmake'
 * compile project
 * @endcode
 * You may also download compiled executable file for Win_x86.
 *
 * @page Changelog
 * V.1.1.1 (2013-09-03)
 * <ul>
 * <li>optimization
 * </ul>
 * V.1.1.0 (2013-09-02)
 * <ul>
 * <li>added help window
 * <li>added help docs
 * <li>small bug fixes
 * </ul>
 * V.1.0.3 (2013-08-30)
 * <ul>
 * <li>bug fixes
 * </ul>
 * V.1.0.1 (2013-07-27)
 * <ul>
 * <li>initial release
 * </ul>
 */ 

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <mathmech/atom_types.h>
#include <mathmech/coords.h>
#include <mathmech/envir_search.h>
#include <mathmech/graph.h>
#include <mathmech/messages.h>
#include <mathmech/print_struct.h>
#include <mathmech/print_trj.h>
#include <mathmech/radf.h>
#include <mathmech/radf_proc.h>
#include <mathmech/read_agl.h>
#include <mathmech/read_gmx.h>
#include <mathmech/read_puma.h>
#include <mathmech/select_mol.h>
#include <mathmech/set_center.h>
#include <mathmech/stat_print.h>
#include <mathmech/stat_select.h>
#include <mathmech/stat_sort.h>
#include <mathmech/summary_stat.h>


/**
 * @fn main
 */
int main(int argc, char *argv[])
/**
 * @return 0              - exit without errors
 */
{
  return 0;
}
