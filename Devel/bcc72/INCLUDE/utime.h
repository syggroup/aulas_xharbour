/*  utime.h

    Definitions for utime() function.

*/

/*
 *      C/C++ Run Time Library - Version 24.0
 *
 *      Copyright (c) 1991, 2016 by Embarcadero Technologies, Inc.
 *      All Rights Reserved.
 *
 */

/* $Revision: 25922 $ */

#ifndef __UTIME_H
#define __UTIME_H

#include <_stddef.h>
#include <sys\types.h>

#if !defined(RC_INVOKED)

#if defined(__STDC__)
#pragma warn -nak
#endif

#pragma pack(push, 1)

#endif  /* !RC_INVOKED */

/* Structure passed to utime containing file times
 */
struct utimbuf
{
        _TIME_T  actime;         /* access time (used on NTFS) */
        _TIME_T  modtime;        /* modification time */
};

#ifdef __cplusplus
extern "C" {
#endif

int    _RTLENTRY _EXPFUNC _utime(const char * __path,
                                 const struct utimbuf *__times);
int    _RTLENTRY _EXPFUNC _wutime(const wchar_t * __path,
                                  const struct utimbuf *__times);

#if !defined(__STDC__)
int    _RTLENTRY _EXPFUNC utime(const char * __path,
                                const struct utimbuf *__times);
#endif

int _RTLENTRY _EXPFUNC _futime(int __fd, const struct utimbuf *__times);

#ifdef __cplusplus
}
#endif


#if !defined(RC_INVOKED)

#pragma pack(pop)       /* restore default packing */

#if defined(__STDC__)
#pragma warn .nak
#endif

#endif  /* !RC_INVOKED */


#endif  /* __UTIME_H */
