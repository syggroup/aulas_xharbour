/*
 * $Id: hpdf_conf.h 9634 2012-08-06 21:58:36Z andijahja $
 */
/*
 * << Haru Free PDF Library >> -- hpdf_conf.h
 *
 * URL: http://libharu.org
 *
 * Copyright (c) 1999-2006 Takeshi Kanno <takeshi_kanno@est.hi-ho.ne.jp>
 * Copyright (c) 2007-2009 Antony Dovgal <tony@daylessday.org>
 *
 * Permission to use, copy, modify, distribute and sell this software
 * and its documentation for any purpose is hereby granted without fee,
 * provided that the above copyright notice appear in all copies and
 * that both that copyright notice and this permission notice appear
 * in supporting documentation.
 * It is provided "as is" without express or implied warranty.
 *
 */

#ifndef _HPDF_CONF_H
#define _HPDF_CONF_H

#include <stdlib.h>
#include <stdio.h>
#if defined(_MSC_VER)
#define _USE_MATH_DEFINES 1
#endif
#define __USE_XOPEN /* for M_PI */
#include <math.h>

#if defined( __BORLANDC__ )
   #pragma warn -aus
   #pragma warn -ccc
   #pragma warn -rch
   #pragma warn -csu
   #pragma warn -par
#elif defined( __WATCOMC__ )
   #pragma disable_message ( 136 )
   #pragma disable_message ( 124 )
   #pragma disable_message ( 202 )
#elif defined( __POCC__ )
   #pragma warn(push)
   #pragma warn(disable:2130)
   #pragma warn(disable:2154)
   #pragma warn(disable:2135)
   #pragma warn(disable:2231)   
#endif

/*----------------------------------------------------------------------------*/
/*----- standard C library functions -----------------------------------------*/

#define HPDF_FOPEN                  fopen
#define HPDF_FCLOSE                 fclose
#define HPDF_FREAD                  fread
#define HPDF_FWRITE                 fwrite
#define HPDF_FFLUSH                 fflush
#define HPDF_FSEEK                  fseek
#define HPDF_FTELL                  ftell
#define HPDF_FEOF                   feof
#define HPDF_FERROR                 ferror
#define HPDF_MALLOC                 malloc
#define HPDF_FREE                   free
#define HPDF_FILEP                  FILE*
#define HPDF_TIME                   time
#define HPDF_PRINTF                 printf
#define HPDF_SIN                    sin
#define HPDF_COS                    cos

/*----------------------------------------------------------------------------*/
/*----- parameters in relation to performance --------------------------------*/

/* default buffer size of memory-stream-object */
#define HPDF_STREAM_BUF_SIZ         4096

/* default array size of list-object */
#define HPDF_DEF_ITEMS_PER_BLOCK    20

/* default array size of cross-reference-table */
#define HPDF_DEFALUT_XREF_ENTRY_NUM 1024

/* default array size of widths-table of cid-fontdef */
#define HPDF_DEF_CHAR_WIDTHS_NUM    128

/* default array size of page-list-tablef */
#define HPDF_DEF_PAGE_LIST_NUM      256

/* default array size of range-table of cid-fontdef */
#define HPDF_DEF_RANGE_TBL_NUM      128

/* default buffer size of memory-pool-object */
#define HPDF_MPOOL_BUF_SIZ          8192
#define HPDF_MIN_MPOOL_BUF_SIZ      256
#define HPDF_MAX_MPOOL_BUF_SIZ      1048576

/* alignment size of memory-pool-object
 */
#define HPDF_ALIGN_SIZ              sizeof int;


#endif /* _HPDF_CONF_H */

