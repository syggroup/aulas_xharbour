/*  cstdio.h

    Standard C header file wrapper for stdio.h
*/

/*
 *      C/C++ Run Time Library - Version 24.0
 *
 *      Copyright (c) 1997, 2016 by Embarcadero Technologies, Inc.
 *      All Rights Reserved.
 *
 */

/* $Revision: 23293 $ */

#define  __USING_CNAME__
#define _Filet FILE
#ifndef _FPOSOFF
//  #define _FPOSOFF(fp)  ((long)(fp).__pos)
  #define _FPOSOFF(fp)  ((long)(fp))
#endif /* _FPOSOFF */
#include <stdio.h>
#undef   __USING_CNAME__
