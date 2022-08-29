/*
 * xHarbour 1.2.3 Intl. (SimpLex) (Build 20201212)
 * Generated C source code from <source\\hipedit.prg>
 * Command: -oxbp\hipedit.c -m -n -pOxbp\ -q -gc0 -Iinclude -Id:\devel\xharbour_bcc73\include source\hipedit.prg 
 * Created: 2022.07.29 19:37:02 (Borland/Embarcadero C++ 7.3 (32-bit))
 */

#include "hbvmpub.h"
#include "hbinit.h"

#define __PRG_SOURCE__ "source\\hipedit.prg"

/* Forward declarations of all PRG defined Functions. */
HB_FUNC( HIPEDIT );
HB_FUNC_STATIC( HIPEDIT_NEW );
HB_FUNC_STATIC( HIPEDIT_ACTIVATE );
HB_FUNC_STATIC( HIPEDIT_INIT );
HB_FUNC_STATIC( HIPEDIT_SETVALUE );
HB_FUNC_STATIC( HIPEDIT_GETVALUE );
HB_FUNC_STATIC( HIPEDIT_CLEAR );
HB_FUNC_STATIC( HIPEDIT_END );
HB_FUNC_STATIC( __GETFOCUS );
HB_FUNC_STATIC( __KILLFOCUS );
HB_FUNC_INITSTATICS();

/* Forward declarations of all externally defined Functions. */
/* Skipped DEFERRED call to: 'DIVERTCONSTRUCTORCALL' */
HB_FUNC_EXTERN( HBCLASS );
HB_FUNC_EXTERN( HCONTROL );
HB_FUNC_EXTERN( __CLSACTIVE );
HB_FUNC_EXTERN( __CLSINST );
HB_FUNC_EXTERN( __OBJHASMSG );
HB_FUNC_EXTERN( HB_APARAMS );
HB_FUNC_EXTERN( PCOUNT );
HB_FUNC_EXTERN( HWG_BITOR );
HB_FUNC_EXTERN( HWG_INITCOMMONCONTROLSEX );
HB_FUNC_EXTERN( EMPTY );
HB_FUNC_EXTERN( INITIPADDRESS );
HB_FUNC_EXTERN( SETIPADDRESS );
HB_FUNC_EXTERN( GETIPADDRESS );
HB_FUNC_EXTERN( CLEARIPADDRESS );
HB_FUNC_EXTERN( CHECKFOCUS );
HB_FUNC_EXTERN( VALTYPE );

#undef HB_PRG_PCODE_VER
#define HB_PRG_PCODE_VER 10

#include "hbapi.h"

HB_INIT_SYMBOLS_BEGIN( hb_vm_SymbolInit_HIPEDIT )
{ "DIVERTCONSTRUCTORCALL", {HB_FS_PUBLIC | HB_FS_DEFERRED}, {NULL}, NULL },
{ "HIPEDIT", {HB_FS_PUBLIC | HB_FS_LOCAL}, {HB_FUNCNAME( HIPEDIT )}, &ModuleFakeDyn },
{ "NEW", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "HBCLASS", {HB_FS_PUBLIC}, {HB_FUNCNAME( HBCLASS )}, NULL },
{ "CLASSH", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "HCONTROL", {HB_FS_PUBLIC}, {HB_FUNCNAME( HCONTROL )}, NULL },
{ "ADDMULTICLSDATA", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "ADDMULTIDATA", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "ADDMETHOD", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "HIPEDIT_NEW", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( HIPEDIT_NEW )}, &ModuleFakeDyn },
{ "HIPEDIT_ACTIVATE", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( HIPEDIT_ACTIVATE )}, &ModuleFakeDyn },
{ "HIPEDIT_INIT", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( HIPEDIT_INIT )}, &ModuleFakeDyn },
{ "HIPEDIT_SETVALUE", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( HIPEDIT_SETVALUE )}, &ModuleFakeDyn },
{ "HIPEDIT_GETVALUE", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( HIPEDIT_GETVALUE )}, &ModuleFakeDyn },
{ "HIPEDIT_CLEAR", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( HIPEDIT_CLEAR )}, &ModuleFakeDyn },
{ "HIPEDIT_END", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( HIPEDIT_END )}, &ModuleFakeDyn },
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
{ "_BSETGET", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "_AVALUE", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "_BGETFOCUS", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "_BKILLFOCUS", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "HWG_INITCOMMONCONTROLSEX", {HB_FS_PUBLIC}, {HB_FUNCNAME( HWG_INITCOMMONCONTROLSEX )}, NULL },
{ "ACTIVATE", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "_LNOVALID", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "ADDEVENT", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "OPARENT", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "BKILLFOCUS", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "__GETFOCUS", {HB_FS_STATIC | HB_FS_LOCAL | HB_FS_FIRST}, {HB_FUNCNAME( __GETFOCUS )}, &ModuleFakeDyn },
{ "FINDCONTROL", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "__KILLFOCUS", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( __KILLFOCUS )}, &ModuleFakeDyn },
{ "EMPTY", {HB_FS_PUBLIC}, {HB_FUNCNAME( EMPTY )}, NULL },
{ "HANDLE", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "_HANDLE", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "INITIPADDRESS", {HB_FS_PUBLIC}, {HB_FUNCNAME( INITIPADDRESS )}, NULL },
{ "ID", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "STYLE", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "NLEFT", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "NTOP", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "NWIDTH", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "NHEIGHT", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "INIT", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "LINIT", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "SETVALUE", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "AVALUE", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "_LINIT", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "SETIPADDRESS", {HB_FS_PUBLIC}, {HB_FUNCNAME( SETIPADDRESS )}, NULL },
{ "GETIPADDRESS", {HB_FS_PUBLIC}, {HB_FUNCNAME( GETIPADDRESS )}, NULL },
{ "CLEARIPADDRESS", {HB_FS_PUBLIC}, {HB_FUNCNAME( CLEARIPADDRESS )}, NULL },
{ "END", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "CHECKFOCUS", {HB_FS_PUBLIC}, {HB_FUNCNAME( CHECKFOCUS )}, NULL },
{ "VALTYPE", {HB_FS_PUBLIC}, {HB_FUNCNAME( VALTYPE )}, NULL },
{ "BGETFOCUS", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "_LSUSPENDMSGSHANDLING", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "EVAL", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "LNOVALID", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "(_INITSTATICS00001)", {HB_FS_INITEXIT}, {hb_INITSTATICS}, &ModuleFakeDyn }
HB_INIT_SYMBOLS_EX_END( hb_vm_SymbolInit_HIPEDIT, __PRG_SOURCE__,  0x000a )

#if defined( HB_PRAGMA_STARTUP )
   #pragma startup hb_vm_SymbolInit_HIPEDIT
#elif defined( HB_DATASEG_STARTUP )
   #define HB_DATASEG_BODY    HB_DATASEG_FUNC( hb_vm_SymbolInit_HIPEDIT )
   #include "hbiniseg.h"
#endif

HB_FUNC( HIPEDIT )
{
   static const BYTE pcode[] =
   {
	13,2,255,116,66,0,126,2,1,0,95,2,73,103,
	1,0,100,8,29,5,2,48,2,0,108,3,100,12,
	0,106,8,72,73,80,101,100,105,116,0,48,4,0,
	108,5,100,12,0,112,0,4,1,0,112,2,82,1,
	0,133,21,0,48,6,0,103,1,0,100,106,15,83,
	121,115,73,80,65,100,100,114,101,115,115,51,50,0,
	95,2,106,9,119,105,110,99,108,97,115,115,0,4,
	1,0,9,112,5,73,134,1,48,7,0,103,1,0,
	100,100,95,2,106,8,98,83,101,116,71,101,116,0,
	4,1,0,9,9,112,6,73,134,2,48,7,0,103,
	1,0,100,100,95,2,106,8,98,67,104,97,110,103,
	101,0,4,1,0,9,9,112,6,73,134,3,48,7,
	0,103,1,0,100,100,95,2,106,11,98,75,105,108,
	108,70,111,99,117,115,0,4,1,0,9,9,112,6,
	73,134,4,48,7,0,103,1,0,100,100,95,2,106,
	10,98,71,101,116,70,111,99,117,115,0,4,1,0,
	9,9,112,6,73,134,5,48,7,0,103,1,0,100,
	9,95,2,106,9,108,110,111,86,97,108,105,100,0,
	4,1,0,9,9,112,6,73,134,8,48,8,0,103,
	1,0,106,4,78,101,119,0,108,9,14,95,2,9,
	112,4,73,134,9,48,8,0,103,1,0,106,9,65,
	99,116,105,118,97,116,101,0,108,10,14,95,2,9,
	112,4,73,134,10,48,8,0,103,1,0,106,5,73,
	110,105,116,0,108,11,14,95,2,9,112,4,73,134,
	11,48,8,0,103,1,0,106,9,83,101,116,86,97,
	108,117,101,0,108,12,14,95,2,9,112,4,73,134,
	12,48,8,0,103,1,0,106,9,71,101,116,86,97,
	108,117,101,0,108,13,14,95,2,9,112,4,73,134,
	13,48,8,0,103,1,0,106,6,67,108,101,97,114,
	0,108,14,14,95,2,9,112,4,73,134,14,48,8,
	0,103,1,0,106,4,69,78,68,0,108,15,14,95,
	2,9,112,4,73,126,2,8,0,95,2,73,134,17,
	48,7,0,103,1,0,100,100,95,2,106,7,97,86,
	97,108,117,101,0,4,1,0,9,9,112,6,73,48,
	19,0,103,1,0,112,0,73,108,20,100,48,17,0,
	103,1,0,112,0,12,1,80,1,108,21,100,95,1,
	106,10,73,110,105,116,67,108,97,115,115,0,12,2,
	28,32,48,22,0,95,1,108,23,100,12,0,112,1,
	73,25,17,108,20,100,48,17,0,103,1,0,112,0,
	12,1,80,1,108,24,100,12,0,121,15,28,10,103,
	1,0,108,0,14,121,178,95,1,110,7
   };

   hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HIPEDIT_NEW )
{
   static const BYTE pcode[] =
   {
	13,1,12,102,80,13,133,45,0,108,25,100,95,5,
	100,8,28,5,121,25,4,95,5,97,0,0,1,0,
	12,2,80,5,134,1,48,2,0,48,26,0,95,13,
	112,0,95,1,95,2,95,5,95,6,95,7,95,8,
	95,9,95,10,112,8,73,134,3,48,27,0,95,13,
	106,1,0,112,1,73,134,5,48,28,0,95,13,95,
	4,112,1,73,134,6,95,3,100,8,28,11,121,121,
	121,121,4,4,0,25,4,95,3,80,3,48,29,0,
	95,13,95,3,112,1,73,134,8,48,30,0,95,13,
	95,11,112,1,73,134,9,48,31,0,95,13,95,12,
	112,1,73,134,11,108,32,100,20,0,134,12,48,33,
	0,95,13,112,0,73,134,24,95,11,100,69,28,13,
	134,25,48,34,0,95,13,120,112,1,73,134,28,95,
	12,100,69,28,47,134,30,48,35,0,48,36,0,95,
	13,112,0,159,164,252,255,255,0,0,0,0,95,13,
	48,37,0,95,13,112,0,120,106,9,111,110,67,104,
	97,110,103,101,0,112,5,73,134,36,48,35,0,48,
	36,0,95,13,112,0,93,0,1,95,13,89,22,0,
	2,0,0,0,108,38,100,48,39,0,95,1,95,2,
	112,1,12,1,6,100,106,11,111,110,71,111,116,70,
	111,99,117,115,0,112,5,73,134,37,48,35,0,48,
	36,0,95,13,112,0,93,0,2,95,13,89,22,0,
	2,0,0,0,108,40,100,48,39,0,95,1,95,2,
	112,1,12,1,6,100,106,12,111,110,76,111,115,116,
	70,111,99,117,115,0,112,5,73,134,40,95,13,110,
	7
   };

   hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HIPEDIT_ACTIVATE )
{
   static const BYTE pcode[] =
   {
	13,1,0,102,80,1,133,88,0,108,41,100,48,42,
	0,48,36,0,95,1,112,0,112,0,12,1,31,81,
	134,2,48,43,0,95,1,108,44,100,48,42,0,48,
	36,0,95,1,112,0,112,0,48,45,0,95,1,112,
	0,48,46,0,95,1,112,0,48,47,0,95,1,112,
	0,48,48,0,95,1,112,0,48,49,0,95,1,112,
	0,48,50,0,95,1,112,0,12,7,112,1,73,134,
	3,48,51,0,95,1,112,0,73,134,5,100,110,7
   };

   hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HIPEDIT_INIT )
{
   static const BYTE pcode[] =
   {
	13,1,0,102,80,1,133,97,0,48,52,0,95,1,
	112,0,31,45,134,1,48,51,0,48,26,0,95,1,
	112,0,112,0,73,134,2,48,53,0,95,1,48,54,
	0,95,1,112,0,112,1,73,134,3,48,55,0,95,
	1,120,112,1,73,134,6,100,110,7
   };

   hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HIPEDIT_SETVALUE )
{
   static const BYTE pcode[] =
   {
	13,1,1,102,80,2,133,106,0,108,56,100,48,42,
	0,95,2,112,0,95,1,122,1,95,1,92,2,1,
	95,1,92,3,1,95,1,92,4,1,20,5,134,1,
	48,29,0,95,2,95,1,112,1,73,134,2,100,110,
	7
   };

   hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HIPEDIT_GETVALUE )
{
   static const BYTE pcode[] =
   {
	13,1,0,102,80,1,133,112,0,48,29,0,95,1,
	108,57,100,48,42,0,95,1,112,0,12,1,112,1,
	73,134,1,48,54,0,95,1,112,0,110,7
   };

   hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HIPEDIT_CLEAR )
{
   static const BYTE pcode[] =
   {
	13,1,0,102,80,1,133,116,0,108,58,100,48,42,
	0,95,1,112,0,20,1,134,1,48,29,0,95,1,
	121,121,121,121,4,4,0,112,1,73,134,2,48,54,
	0,95,1,112,0,110,7
   };

   hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HIPEDIT_END )
{
   static const BYTE pcode[] =
   {
	13,1,0,102,80,1,133,124,0,48,59,0,48,26,
	0,95,1,112,0,112,0,73,134,2,100,110,7
   };

   hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( __GETFOCUS )
{
   static const BYTE pcode[] =
   {
	13,1,1,133,132,0,108,60,100,95,1,9,12,2,
	31,7,134,1,120,110,7,134,4,108,61,100,48,62,
	0,95,1,112,0,12,1,106,2,66,0,8,28,75,
	134,5,48,63,0,48,36,0,95,1,112,0,120,112,
	1,73,134,6,48,34,0,95,1,120,112,1,73,134,
	7,48,64,0,48,62,0,95,1,112,0,95,1,112,
	1,80,2,134,8,48,63,0,48,36,0,95,1,112,
	0,9,112,1,73,134,9,48,34,0,95,1,95,2,
	112,1,73,134,12,95,2,110,7
   };

   hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( __KILLFOCUS )
{
   static const BYTE pcode[] =
   {
	13,1,1,133,150,0,108,60,100,95,1,120,12,2,
	68,21,31,10,73,48,65,0,95,1,112,0,28,7,
	134,1,120,110,7,134,4,108,61,100,48,37,0,95,
	1,112,0,12,1,106,2,66,0,8,28,52,134,5,
	48,63,0,48,36,0,95,1,112,0,120,112,1,73,
	134,6,48,64,0,48,37,0,95,1,112,0,95,1,
	112,1,80,2,134,7,48,63,0,48,36,0,95,1,
	112,0,9,112,1,73,134,10,95,2,110,7
   };

   hb_vmExecute( pcode, symbols );
}

HB_FUNC_INITSTATICS()
{
   static const BYTE pcode[] =
   {
	117,66,0,1,0,7
   };

   hb_vmExecute( pcode, symbols );
}

