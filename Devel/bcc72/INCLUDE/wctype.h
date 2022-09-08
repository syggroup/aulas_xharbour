/* WCTYPE.H - Most of this stuff is in TCHAR.H, so we include that */

/*
 *      C/C++ Run Time Library - Version 24.0
 *
 *      Copyright (c) 1997, 2016 by Embarcadero Technologies, Inc.
 *      All Rights Reserved.
 *
 */


/* $Revision: 24271 $ */

#ifndef __WCTYPE_H
#define __WCTYPE_H

#if !defined(__TCHAR_H)
#  include <tchar.h>
#endif

#if !defined(__CTYPE_H)
#  include <ctype.h>
#endif

#ifndef WEOF
#define WEOF (_WINT_T)(0xFFFF)   /* wide-character end of file indicator */
#endif /* WEOF */

#endif /* __WCTYPE_H */
