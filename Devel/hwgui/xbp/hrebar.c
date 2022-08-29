/*
 * xHarbour 1.2.3 Intl. (SimpLex) (Build 20201212)
 * Generated C source code from <source\\hrebar.prg>
 * Command: -oxbp\hrebar.c -m -n -pOxbp\ -q -gc0 -Iinclude -Id:\devel\xharbour_bcc73\include source\hrebar.prg 
 * Created: 2022.07.29 19:37:05 (Borland/Embarcadero C++ 7.3 (32-bit))
 */

#include "hbvmpub.h"
#include "hbinit.h"

#define __PRG_SOURCE__ "source\\hrebar.prg"

/* Forward declarations of all PRG defined Functions. */
HB_FUNC( HREBAR );
HB_FUNC_STATIC( HREBAR_NEW );
HB_FUNC_STATIC( HREBAR_REDEFINE );
HB_FUNC_STATIC( HREBAR_ACTIVATE );
HB_FUNC_STATIC( HREBAR_INIT );
HB_FUNC_STATIC( HREBAR_CREATEBANDS );
HB_FUNC_INITSTATICS();

/* Forward declarations of all externally defined Functions. */
/* Skipped DEFERRED call to: 'DIVERTCONSTRUCTORCALL' */
HB_FUNC_EXTERN( HBCLASS );
HB_FUNC_EXTERN( HCONTROL );
HB_FUNC_EXTERN( ADDBARCOLORS );
HB_FUNC_EXTERN( ADDBARBITMAP );
HB_FUNC_EXTERN( __CLSACTIVE );
HB_FUNC_EXTERN( __CLSINST );
HB_FUNC_EXTERN( __OBJHASMSG );
HB_FUNC_EXTERN( HB_APARAMS );
HB_FUNC_EXTERN( PCOUNT );
HB_FUNC_EXTERN( HWG_BITOR );
HB_FUNC_EXTERN( HWG_INITCOMMONCONTROLSEX );
HB_FUNC_EXTERN( EMPTY );
HB_FUNC_EXTERN( CREATEREBAR );
HB_FUNC_EXTERN( AADD );
HB_FUNC_EXTERN( LEN );
HB_FUNC_EXTERN( GETSYSCOLOR );
HB_FUNC_EXTERN( VALTYPE );

#undef HB_PRG_PCODE_VER
#define HB_PRG_PCODE_VER 10

#include "hbapi.h"

HB_INIT_SYMBOLS_BEGIN( hb_vm_SymbolInit_HREBAR )
{ "DIVERTCONSTRUCTORCALL", {HB_FS_PUBLIC | HB_FS_DEFERRED}, {NULL}, NULL },
{ "HREBAR", {HB_FS_PUBLIC | HB_FS_LOCAL}, {HB_FUNCNAME( HREBAR )}, &ModuleFakeDyn },
{ "NEW", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "HBCLASS", {HB_FS_PUBLIC}, {HB_FUNCNAME( HBCLASS )}, NULL },
{ "CLASSH", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "HCONTROL", {HB_FS_PUBLIC}, {HB_FUNCNAME( HCONTROL )}, NULL },
{ "ADDMULTIDATA", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "ADDMULTICLSDATA", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "ADDMETHOD", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "HREBAR_NEW", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( HREBAR_NEW )}, &ModuleFakeDyn },
{ "HREBAR_REDEFINE", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( HREBAR_REDEFINE )}, &ModuleFakeDyn },
{ "HREBAR_ACTIVATE", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( HREBAR_ACTIVATE )}, &ModuleFakeDyn },
{ "HREBAR_INIT", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( HREBAR_INIT )}, &ModuleFakeDyn },
{ "ADDINLINE", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "ADDBARCOLORS", {HB_FS_PUBLIC}, {HB_FUNCNAME( ADDBARCOLORS )}, NULL },
{ "HANDLE", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "ADDBARBITMAP", {HB_FS_PUBLIC}, {HB_FUNCNAME( ADDBARBITMAP )}, NULL },
{ "CREATEBANDS", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "HREBAR_CREATEBANDS", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( HREBAR_CREATEBANDS )}, &ModuleFakeDyn },
{ "__CLSACTIVE", {HB_FS_PUBLIC}, {HB_FUNCNAME( __CLSACTIVE )}, NULL },
{ "HCLASS", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "REFRESH", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "CREATE", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "__CLSINST", {HB_FS_PUBLIC}, {HB_FUNCNAME( __CLSINST )}, NULL },
{ "__OBJHASMSG", {HB_FS_PUBLIC}, {HB_FUNCNAME( __OBJHASMSG )}, NULL },
{ "INITCLASS", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "HB_APARAMS", {HB_FS_PUBLIC}, {HB_FUNCNAME( HB_APARAMS )}, NULL },
{ "PCOUNT", {HB_FS_PUBLIC}, {HB_FUNCNAME( PCOUNT )}, NULL },
{ "HWG_BITOR", {HB_FS_PUBLIC}, {HB_FUNCNAME( HWG_BITOR )}, NULL },
{ "HCONTROL", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "_TITLE", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "HWG_INITCOMMONCONTROLSEX", {HB_FS_PUBLIC}, {HB_FUNCNAME( HWG_INITCOMMONCONTROLSEX )}, NULL },
{ "ACTIVATE", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "_STYLE", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "_NLEFT", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "_NTOP", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "_NWIDTH", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "_NHEIGHT", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "EMPTY", {HB_FS_PUBLIC}, {HB_FUNCNAME( EMPTY )}, NULL },
{ "OPARENT", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "_HANDLE", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "CREATEREBAR", {HB_FS_PUBLIC}, {HB_FUNCNAME( CREATEREBAR )}, NULL },
{ "ID", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "STYLE", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "NLEFT", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "NTOP", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "NWIDTH", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "NHEIGHT", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "INIT", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "LINIT", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "AADD", {HB_FS_PUBLIC}, {HB_FUNCNAME( AADD )}, NULL },
{ "ABANDS", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "LEN", {HB_FS_PUBLIC}, {HB_FUNCNAME( LEN )}, NULL },
{ "GETSYSCOLOR", {HB_FS_PUBLIC}, {HB_FUNCNAME( GETSYSCOLOR )}, NULL },
{ "VALTYPE", {HB_FS_PUBLIC}, {HB_FUNCNAME( VALTYPE )}, NULL },
{ "_ABANDS", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "(_INITSTATICS00001)", {HB_FS_INITEXIT}, {hb_INITSTATICS}, &ModuleFakeDyn }
HB_INIT_SYMBOLS_EX_END( hb_vm_SymbolInit_HREBAR, __PRG_SOURCE__,  0x000a )

#if defined( HB_PRAGMA_STARTUP )
   #pragma startup hb_vm_SymbolInit_HREBAR
#elif defined( HB_DATASEG_STARTUP )
   #define HB_DATASEG_BODY    HB_DATASEG_FUNC( hb_vm_SymbolInit_HREBAR )
   #include "hbiniseg.h"
#endif

HB_FUNC( HREBAR )
{
   static const BYTE pcode[] =
   {
	13,2,255,116,56,0,126,2,1,0,95,2,73,103,
	1,0,100,8,29,236,2,48,2,0,108,3,100,12,
	0,106,7,104,114,101,98,97,114,0,48,4,0,108,
	5,100,12,0,112,0,4,1,0,112,2,82,1,0,
	133,21,0,48,6,0,103,1,0,100,106,14,82,101,
	66,97,114,87,105,110,100,111,119,51,50,0,95,2,
	106,9,119,105,110,99,108,97,115,115,0,4,1,0,
	9,9,112,6,73,134,1,48,6,0,103,1,0,100,
	100,95,2,106,5,84,69,88,84,0,106,3,105,100,
	0,106,5,110,84,111,112,0,106,6,110,76,101,102,
	116,0,106,7,110,119,105,100,116,104,0,106,8,110,
	104,101,105,103,104,116,0,4,6,0,9,9,112,6,
	73,134,2,48,7,0,103,1,0,100,100,95,2,128,
	64,0,106,10,111,83,101,108,101,99,116,101,100,0,
	4,1,0,9,112,5,73,134,3,48,6,0,103,1,
	0,100,100,95,2,106,8,69,120,83,116,121,108,101,
	0,4,1,0,9,9,112,6,73,134,4,48,6,0,
	103,1,0,100,100,95,2,106,7,98,67,108,105,99,
	107,0,4,1,0,9,9,112,6,73,134,5,48,6,
	0,103,1,0,100,100,95,2,106,6,108,86,101,114,
	116,0,4,1,0,9,9,112,6,73,134,6,48,6,
	0,103,1,0,100,100,95,2,106,6,104,84,111,111,
	108,0,4,1,0,9,9,112,6,73,134,7,48,6,
	0,103,1,0,100,100,95,2,106,9,109,95,110,87,
	105,100,116,104,0,106,10,109,95,110,72,101,105,103,
	104,116,0,4,2,0,9,9,112,6,73,134,8,48,
	6,0,103,1,0,100,4,0,0,95,2,106,7,97,
	66,97,110,100,115,0,4,1,0,9,9,112,6,73,
	134,11,48,8,0,103,1,0,106,4,78,101,119,0,
	108,9,14,95,2,9,112,4,73,134,13,48,8,0,
	103,1,0,106,9,82,101,100,101,102,105,110,101,0,
	108,10,14,95,2,9,112,4,73,134,15,48,8,0,
	103,1,0,106,9,65,99,116,105,118,97,116,101,0,
	108,11,14,95,2,9,112,4,73,134,16,48,8,0,
	103,1,0,106,5,73,78,73,84,0,108,12,14,95,
	2,9,112,4,73,134,17,48,13,0,103,1,0,106,
	12,65,68,68,66,65,82,67,111,108,111,114,0,89,
	33,0,6,0,0,0,95,1,73,108,14,100,48,15,
	0,95,1,112,0,95,2,95,3,95,4,95,5,95,
	6,12,6,6,95,2,9,112,4,73,134,18,48,13,
	0,103,1,0,106,13,65,68,68,66,65,82,66,73,
	84,77,65,80,0,89,31,0,5,0,0,0,95,1,
	73,108,16,100,48,15,0,95,1,112,0,95,2,95,
	3,95,4,95,5,12,5,6,95,2,9,112,4,73,
	134,19,48,13,0,103,1,0,106,13,82,101,98,97,
	114,66,97,110,100,78,101,119,0,89,30,0,7,0,
	0,0,95,1,73,48,17,0,95,1,95,2,95,3,
	95,4,95,5,95,6,95,7,112,6,6,95,2,9,
	112,4,73,134,20,48,8,0,103,1,0,106,12,67,
	114,101,97,116,101,66,97,110,100,115,0,108,18,14,
	95,2,9,112,4,73,48,22,0,103,1,0,112,0,
	73,108,23,100,48,20,0,103,1,0,112,0,12,1,
	80,1,108,24,100,95,1,106,10,73,110,105,116,67,
	108,97,115,115,0,12,2,28,32,48,25,0,95,1,
	108,26,100,12,0,112,1,73,25,17,108,23,100,48,
	20,0,103,1,0,112,0,12,1,80,1,108,27,100,
	12,0,121,15,28,10,103,1,0,108,0,14,121,178,
	95,1,110,7
   };

   hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HREBAR_NEW )
{
   static const BYTE pcode[] =
   {
	13,1,16,102,80,17,133,49,0,95,8,80,8,134,
	2,95,16,100,8,28,5,9,80,16,134,4,108,28,
	100,95,3,100,8,28,5,121,25,4,95,3,97,0,
	0,0,80,12,2,80,3,134,6,48,2,0,48,29,
	0,95,17,112,0,95,1,95,2,95,3,95,4,95,
	5,95,6,95,7,95,9,95,10,95,11,95,12,95,
	13,95,14,95,15,112,14,73,134,7,48,30,0,95,
	17,106,1,0,112,1,73,134,8,108,31,100,20,0,
	134,11,48,32,0,95,17,112,0,73,134,13,95,17,
	110,7
   };

   hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HREBAR_REDEFINE )
{
   static const BYTE pcode[] =
   {
	13,1,11,102,80,12,133,69,0,95,3,80,3,134,
	2,95,11,100,8,28,5,9,80,11,134,4,48,2,
	0,48,29,0,95,12,112,0,95,1,95,2,121,121,
	121,121,121,95,4,95,5,95,6,95,7,95,8,95,
	9,95,10,112,14,73,134,5,108,31,100,20,0,134,
	7,48,33,0,95,12,48,34,0,95,12,48,35,0,
	95,12,48,36,0,95,12,48,37,0,95,12,121,112,
	1,112,1,112,1,112,1,112,1,73,134,9,95,12,
	110,7
   };

   hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HREBAR_ACTIVATE )
{
   static const BYTE pcode[] =
   {
	13,1,0,102,80,1,133,83,0,108,38,100,48,15,
	0,48,39,0,95,1,112,0,112,0,12,1,31,81,
	134,3,48,40,0,95,1,108,41,100,48,15,0,48,
	39,0,95,1,112,0,112,0,48,42,0,95,1,112,
	0,48,43,0,95,1,112,0,48,44,0,95,1,112,
	0,48,45,0,95,1,112,0,48,46,0,95,1,112,
	0,48,47,0,95,1,112,0,12,7,112,1,73,134,
	5,48,48,0,95,1,112,0,73,134,7,100,110,7
   };

   hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HREBAR_INIT )
{
   static const BYTE pcode[] =
   {
	13,1,0,102,80,1,133,94,0,48,49,0,95,1,
	112,0,31,27,134,1,48,48,0,48,29,0,95,1,
	112,0,112,0,73,134,2,48,17,0,95,1,112,0,
	73,134,5,100,110,7
   };

   hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HREBAR_CREATEBANDS )
{
   static const BYTE pcode[] =
   {
	13,2,6,102,80,7,133,105,0,95,1,100,69,28,
	31,134,1,108,50,100,48,51,0,95,7,112,0,95,
	1,95,2,95,3,95,4,95,5,95,6,4,6,0,
	20,2,134,3,48,49,0,95,7,112,0,31,7,134,
	4,100,110,7,134,6,126,6,128,2,134,7,126,8,
	1,0,95,8,108,52,100,48,51,0,95,7,112,0,
	12,1,34,29,119,1,134,8,48,51,0,95,7,112,
	0,95,8,1,92,4,1,100,5,28,11,108,53,100,
	92,15,12,1,25,15,48,51,0,95,7,112,0,95,
	8,1,92,4,1,48,51,0,95,7,112,0,95,8,
	168,92,4,2,134,9,48,51,0,95,7,112,0,95,
	8,1,92,6,1,100,5,28,6,95,6,25,15,48,
	51,0,95,7,112,0,95,8,1,92,6,1,48,51,
	0,95,7,112,0,95,8,168,92,6,2,134,10,108,
	38,100,48,51,0,95,7,112,0,95,8,1,122,1,
	12,1,32,243,0,134,11,108,54,100,48,51,0,95,
	7,112,0,95,8,1,122,1,12,1,106,2,67,0,
	5,28,18,48,51,0,95,7,112,0,95,8,1,122,
	1,40,11,25,14,48,51,0,95,7,112,0,95,8,
	1,122,1,48,51,0,95,7,112,0,95,8,168,122,
	2,134,12,48,51,0,95,7,112,0,95,8,1,92,
	5,1,100,69,28,74,134,13,108,16,100,48,15,0,
	95,7,112,0,48,15,0,48,51,0,95,7,112,0,
	95,8,1,122,1,112,0,48,51,0,95,7,112,0,
	95,8,1,92,2,1,48,51,0,95,7,112,0,95,
	8,1,92,5,1,48,51,0,95,7,112,0,95,8,
	1,92,6,1,20,5,25,85,134,15,108,14,100,48,
	15,0,95,7,112,0,48,15,0,48,51,0,95,7,
	112,0,95,8,1,122,1,112,0,48,51,0,95,7,
	112,0,95,8,1,92,3,1,48,51,0,95,7,112,
	0,95,8,1,92,4,1,48,51,0,95,7,112,0,
	95,8,1,92,2,1,48,51,0,95,7,112,0,95,
	8,1,92,6,1,20,6,134,18,173,8,26,125,254,
	134,19,48,55,0,95,7,4,0,0,112,1,73,134,
	20,100,110,7
   };

   hb_vmExecute( pcode, symbols );
}

HB_FUNC_INITSTATICS()
{
   static const BYTE pcode[] =
   {
	117,56,0,1,0,7
   };

   hb_vmExecute( pcode, symbols );
}

