/* ymath.h internal header */
#ifndef _YMATH
#define _YMATH
#include <yvals.h>
_C_STD_BEGIN
_C_LIB_DECL

		/* MACROS FOR _FPP_TYPE */
#define _FPP_NONE	0	/* software emulation of FPP */
#define _FPP_X86	1	/* Intel Pentium */
#define _FPP_SPARC	2	/* Sun SPARC */
#define _FPP_MIPS	3	/* SGI MIPS */
#define _FPP_S390	4	/* IBM S/390 */
#define _FPP_PPC	5	/* Motorola PowerPC */
#define _FPP_HPPA	6	/* Hewlett-Packard PA-RISC */
#define _FPP_ALPHA	7	/* Compaq Alpha */
#define _FPP_ARM	8	/* ARM ARM */
#define _FPP_M68K	9	/* Motorola 68xxx */
#define _FPP_SH4	10	/* Hitachi SH4 */
#define _FPP_IA64	11	/* Intel IA64 */
#define _FPP_WCE	12	/* Microsoft Windows CE */

		/* MACROS FOR _Dtest RETURN (0 => ZERO) */
#define _DENORM		(-2)	/* C9X only */
#define _FINITE		(-1)
#define _INFCODE	1
#define _NANCODE	2

		/* MACROS FOR _Feraise ARGUMENT */

 #if _FPP_TYPE == _FPP_X86
  #define _FE_DIVBYZERO	0x04
  #define _FE_INEXACT	0x20
  #define _FE_INVALID	0x01
  #define _FE_OVERFLOW	0x08
  #define _FE_UNDERFLOW	0x10

 #elif _FPP_TYPE == _FPP_SPARC
  #define _FE_DIVBYZERO	0x02
  #define _FE_INEXACT	0x01
  #define _FE_INVALID	0x10
  #define _FE_OVERFLOW	0x08
  #define _FE_UNDERFLOW	0x04

 #elif _FPP_TYPE == _FPP_MIPS
  #define _FE_DIVBYZERO	0x02
  #define _FE_INEXACT	0x01
  #define _FE_INVALID	0x10
  #define _FE_OVERFLOW	0x08
  #define _FE_UNDERFLOW	0x04

 #elif _FPP_TYPE == _FPP_S390
  #define _FE_DIVBYZERO	0x08
  #define _FE_INEXACT	0x01
  #define _FE_INVALID	0x10
  #define _FE_OVERFLOW	0x04
  #define _FE_UNDERFLOW	0x02

 #elif _FPP_TYPE == _FPP_PPC
  #define _FE_DIVBYZERO	0x02
  #define _FE_INEXACT	0x01
  #define _FE_INVALID	0x10
  #define _FE_OVERFLOW	0x08
  #define _FE_UNDERFLOW	0x04

 #elif _FPP_TYPE == _FPP_HPPA
  #define _FE_DIVBYZERO	0x08
  #define _FE_INEXACT	0x01
  #define _FE_INVALID	0x10
  #define _FE_OVERFLOW	0x04
  #define _FE_UNDERFLOW	0x02

 #elif _FPP_TYPE == _FPP_ALPHA
  #define _FE_DIVBYZERO	0x02
  #define _FE_INEXACT	0x10
  #define _FE_INVALID	0x01
  #define _FE_OVERFLOW	0x04
  #define _FE_UNDERFLOW	0x08

 #elif _FPP_TYPE == _FPP_ARM
  #define _FE_DIVBYZERO	0x02
  #define _FE_INEXACT	0x10
  #define _FE_INVALID	0x01
  #define _FE_OVERFLOW	0x04
  #define _FE_UNDERFLOW	0x08

 #elif _FPP_TYPE == _FPP_M68K
  #define _FE_DIVBYZERO	0x02
  #define _FE_INEXACT	0x01
  #define _FE_INVALID	0x10
  #define _FE_OVERFLOW	0x08
  #define _FE_UNDERFLOW	0x04

 #elif _FPP_TYPE == _FPP_SH4
  #define _FE_DIVBYZERO	0x08
  #define _FE_INEXACT	0x01
  #define _FE_INVALID	0x10
  #define _FE_OVERFLOW	0x04
  #define _FE_UNDERFLOW	0x02

 #elif _FPP_TYPE == _FPP_IA64
  #define _FE_DIVBYZERO	0x04
  #define _FE_INEXACT	0x20
  #define _FE_INVALID	0x01
  #define _FE_OVERFLOW	0x08
  #define _FE_UNDERFLOW	0x10

 #elif _FPP_TYPE == _FPP_WCE
  #define _FE_DIVBYZERO	0x08
  #define _FE_INEXACT	0x01
  #define _FE_INVALID	0x10
  #define _FE_OVERFLOW	0x04
  #define _FE_UNDERFLOW	0x02

 #else /* _FPP_TYPE == _FPP_NONE or unknown */
  #undef _FPP_TYPE
  #define _FPP_TYPE	_FPP_NONE

  #define _FE_DIVBYZERO	0x04	/* dummy same as Pentium */
  #define _FE_INEXACT	0x20
  #define _FE_INVALID	0x01
  #define _FE_OVERFLOW	0x08
  #define _FE_UNDERFLOW	0x10
 #endif /* _FPP_TYPE */

		/* TYPE DEFINITIONS */
typedef union
	{	/* pun float types as integer array */
	unsigned short _Word[8];
	float _Float;
	double _Double;
	long double _Long_double;
	} _Dconst;

		/* ERROR REPORTING */
_CRTIMP2 void _Feraise(int);

		/* double DECLARATIONS */
_CRTIMP2 double _Cosh(double, double);
_CRTIMP2 short _Dtest(double *);
_CRTIMP2 short _Exp(double *, double, long);
_CRTIMP2 double _Log(double, int);
_CRTIMP2 double _Sin(double, unsigned int);
_CRTIMP2 double _Sinh(double, double);
extern _CRTIMP2 /* const */ _Dconst _Denorm, _Hugeval, _Inf,
	_Nan, _Snan;

		/* float DECLARATIONS */
_CRTIMP2 float _FCosh(float, float);
_CRTIMP2 short _FDtest(float *);
_CRTIMP2 short _FExp(float *, float, long);
_CRTIMP2 float _FLog(float, int);
_CRTIMP2 float _FSin(float, unsigned int);
_CRTIMP2 float _FSinh(float, float);
extern _CRTIMP2 /* const */ _Dconst _FDenorm, _FInf, _FNan, _FSnan;

		/* long double DECLARATIONS */
_CRTIMP2 long double _LCosh(long double, long double);
_CRTIMP2 short _LDtest(long double *);
_CRTIMP2 short _LExp(long double *, long double, long);
_CRTIMP2 long double _LLog(long double, int);
_CRTIMP2 long double _LSin(long double, unsigned int);
_CRTIMP2 long double _LSinh(long double, long double);
extern _CRTIMP2 /* const */ _Dconst _LDenorm, _LInf, _LNan, _LSnan;

 #if defined(__SUNPRO_CC)	/* compiler test */
float fmodf(float, float);
long double fmodl(long double, long double);
 #endif /* defined(__SUNPRO_CC) */

 #if defined(__CODEGEARC__)	/* compiler test */
float fmodf(float, float);
float logf(float);
 #endif /* defined(__CODEGEARC__) */

_END_C_LIB_DECL
_C_STD_END
#endif /* _YMATH */

/*
 * Copyright (c) 1992-2006 by P.J. Plauger.  ALL RIGHTS RESERVED.
 * Consult your license regarding permissions and restrictions.
V5.01:1422 */
