/*
 * xHarbour 1.2.3 Intl. (SimpLex) (Build 20201212)
 * Generated C source code from <source\\activex\\h_activex.prg>
 * Command: -oxbp\h_activex.c -m -n -pOxbp\ -q -gc0 -Iinclude -Id:\devel\xharbour_bcc73\include source\activex\h_activex.prg 
 * Created: 2022.07.29 19:37:46 (Borland/Embarcadero C++ 7.3 (32-bit))
 */

#include "hbvmpub.h"
#include "hbinit.h"

#define __PRG_SOURCE__ "source\\activex\\h_activex.prg"

/* Forward declarations of all PRG defined Functions. */
HB_FUNC( HACTIVEX );
HB_FUNC_STATIC( HACTIVEX_NEW );
HB_FUNC_STATIC( HACTIVEX_RELEASE );
HB_FUNC_STATIC( HACTIVEX___ERROR );
HB_FUNC_STATIC( HACTIVEX_EVENTMAP );
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
HB_FUNC_EXTERN( HWG_CREATEACTIVEX );
HB_FUNC_EXTERN( HWG_ATLAXGETDISP );
HB_FUNC_EXTERN( ERRORBLOCK );
HB_FUNC_EXTERN( BREAK );
HB_FUNC_EXTERN( TOLEAUTO );
HB_FUNC_EXTERN( HWG_MSGINFO );
HB_FUNC_EXTERN( HWG_SETUPCONNECTIONPOINT );
HB_FUNC_EXTERN( HWG_SHUTDOWNCONNECTIONPOINT );
HB_FUNC_EXTERN( HWG_RELEASEDISPATCH );
HB_FUNC_EXTERN( __GETMESSAGE );
HB_FUNC_EXTERN( SUBSTR );
HB_FUNC_EXTERN( HB_EXECFROMARRAY );
HB_FUNC_EXTERN( ASCAN );
HB_FUNC_EXTERN( AADD );
HB_FUNC_EXTERN( LEN );

#undef HB_PRG_PCODE_VER
#define HB_PRG_PCODE_VER 10

#include "hbapi.h"

HB_INIT_SYMBOLS_BEGIN( hb_vm_SymbolInit_H_ACTIVEX )
{ "DIVERTCONSTRUCTORCALL", {HB_FS_PUBLIC | HB_FS_DEFERRED}, {NULL}, NULL },
{ "HACTIVEX", {HB_FS_PUBLIC | HB_FS_LOCAL}, {HB_FUNCNAME( HACTIVEX )}, &ModuleFakeDyn },
{ "NEW", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "HBCLASS", {HB_FS_PUBLIC}, {HB_FUNCNAME( HBCLASS )}, NULL },
{ "CLASSH", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "HCONTROL", {HB_FS_PUBLIC}, {HB_FUNCNAME( HCONTROL )}, NULL },
{ "ADDMULTICLSDATA", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "ADDMULTIDATA", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "ADDMETHOD", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "HACTIVEX_RELEASE", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( HACTIVEX_RELEASE )}, &ModuleFakeDyn },
{ "HACTIVEX_NEW", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( HACTIVEX_NEW )}, &ModuleFakeDyn },
{ "ADDDELEGATE", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "SETONERROR", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "HACTIVEX___ERROR", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( HACTIVEX___ERROR )}, &ModuleFakeDyn },
{ "HACTIVEX_EVENTMAP", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( HACTIVEX_EVENTMAP )}, &ModuleFakeDyn },
{ "__CLSACTIVE", {HB_FS_PUBLIC}, {HB_FUNCNAME( __CLSACTIVE )}, NULL },
{ "HCLASS", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "REFRESH", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "CREATE", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "__CLSINST", {HB_FS_PUBLIC}, {HB_FUNCNAME( __CLSINST )}, NULL },
{ "__OBJHASMSG", {HB_FS_PUBLIC}, {HB_FUNCNAME( __OBJHASMSG )}, NULL },
{ "INITCLASS", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "HB_APARAMS", {HB_FS_PUBLIC}, {HB_FUNCNAME( HB_APARAMS )}, NULL },
{ "PCOUNT", {HB_FS_PUBLIC}, {HB_FUNCNAME( PCOUNT )}, NULL },
{ "HCONTROL", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "_TITLE", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "_HANDLE", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "HWG_CREATEACTIVEX", {HB_FS_PUBLIC}, {HB_FUNCNAME( HWG_CREATEACTIVEX )}, NULL },
{ "STYLE", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "NLEFT", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "NTOP", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "NWIDTH", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "NHEIGHT", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "HANDLE", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "OPARENT", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "ID", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "INIT", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "_HOBJ", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "HWG_ATLAXGETDISP", {HB_FS_PUBLIC}, {HB_FUNCNAME( HWG_ATLAXGETDISP )}, NULL },
{ "ERRORBLOCK", {HB_FS_PUBLIC}, {HB_FUNCNAME( ERRORBLOCK )}, NULL },
{ "BREAK", {HB_FS_PUBLIC}, {HB_FUNCNAME( BREAK )}, NULL },
{ "_OOLE", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "TOLEAUTO", {HB_FS_PUBLIC}, {HB_FUNCNAME( TOLEAUTO )}, NULL },
{ "HOBJ", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "HWG_MSGINFO", {HB_FS_PUBLIC}, {HB_FUNCNAME( HWG_MSGINFO )}, NULL },
{ "DESCRIPTION", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "HWG_SETUPCONNECTIONPOINT", {HB_FS_PUBLIC}, {HB_FUNCNAME( HWG_SETUPCONNECTIONPOINT )}, NULL },
{ "AAXEV", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "AAXEXEC", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "_HSINK", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "HWG_SHUTDOWNCONNECTIONPOINT", {HB_FS_PUBLIC}, {HB_FUNCNAME( HWG_SHUTDOWNCONNECTIONPOINT )}, NULL },
{ "HSINK", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "HWG_RELEASEDISPATCH", {HB_FS_PUBLIC}, {HB_FUNCNAME( HWG_RELEASEDISPATCH )}, NULL },
{ "__GETMESSAGE", {HB_FS_PUBLIC}, {HB_FUNCNAME( __GETMESSAGE )}, NULL },
{ "SUBSTR", {HB_FS_PUBLIC}, {HB_FUNCNAME( SUBSTR )}, NULL },
{ "HB_EXECFROMARRAY", {HB_FS_PUBLIC}, {HB_FUNCNAME( HB_EXECFROMARRAY )}, NULL },
{ "OOLE", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "ASCAN", {HB_FS_PUBLIC}, {HB_FUNCNAME( ASCAN )}, NULL },
{ "AADD", {HB_FS_PUBLIC}, {HB_FUNCNAME( AADD )}, NULL },
{ "LEN", {HB_FS_PUBLIC}, {HB_FUNCNAME( LEN )}, NULL },
{ "(_INITSTATICS00001)", {HB_FS_INITEXIT}, {hb_INITSTATICS}, &ModuleFakeDyn }
HB_INIT_SYMBOLS_EX_END( hb_vm_SymbolInit_H_ACTIVEX, __PRG_SOURCE__,  0x000a )

#if defined( HB_PRAGMA_STARTUP )
   #pragma startup hb_vm_SymbolInit_H_ACTIVEX
#elif defined( HB_DATASEG_STARTUP )
   #define HB_DATASEG_BODY    HB_DATASEG_FUNC( hb_vm_SymbolInit_H_ACTIVEX )
   #include "hbiniseg.h"
#endif

HB_FUNC( HACTIVEX )
{
   static const BYTE pcode[] =
   {
	13,2,255,116,60,0,126,2,1,0,95,2,73,103,
	1,0,100,8,29,201,1,48,2,0,108,3,100,12,
	0,106,9,72,65,99,116,105,118,101,88,0,48,4,
	0,108,5,100,12,0,112,0,4,1,0,112,2,82,
	1,0,133,33,0,48,6,0,103,1,0,100,106,8,
	65,67,84,73,86,69,88,0,95,2,106,9,119,105,
	110,99,108,97,115,115,0,4,1,0,9,112,5,73,
	134,1,48,7,0,103,1,0,100,100,95,2,106,5,
	111,79,108,101,0,4,1,0,9,9,112,6,73,134,
	2,48,7,0,103,1,0,100,100,95,2,106,6,104,
	83,105,110,107,0,4,1,0,9,9,112,6,73,134,
	3,48,7,0,103,1,0,100,100,95,2,106,5,104,
	65,116,108,0,4,1,0,9,9,112,6,73,134,4,
	48,7,0,103,1,0,100,100,95,2,106,5,104,79,
	98,106,0,4,1,0,9,9,112,6,73,134,6,48,
	8,0,103,1,0,106,8,82,101,108,101,97,115,101,
	0,108,9,14,95,2,9,112,4,73,134,7,48,8,
	0,103,1,0,106,4,78,101,119,0,108,10,14,95,
	2,9,112,4,73,134,9,48,11,0,103,1,0,106,
	4,83,101,116,0,100,106,5,111,79,108,101,0,95,
	2,112,4,73,134,10,48,11,0,103,1,0,106,4,
	71,101,116,0,100,106,5,111,79,108,101,0,95,2,
	112,4,73,134,11,48,12,0,103,1,0,108,13,14,
	112,1,73,134,13,48,7,0,103,1,0,100,4,0,
	0,95,2,106,6,97,65,120,69,118,0,4,1,0,
	9,9,112,6,73,134,14,48,7,0,103,1,0,100,
	4,0,0,95,2,106,8,97,65,120,69,120,101,99,
	0,4,1,0,9,9,112,6,73,134,15,48,8,0,
	103,1,0,106,9,69,118,101,110,116,77,97,112,0,
	108,14,14,95,2,9,112,4,73,48,18,0,103,1,
	0,112,0,73,108,19,100,48,16,0,103,1,0,112,
	0,12,1,80,1,108,20,100,95,1,106,10,73,110,
	105,116,67,108,97,115,115,0,12,2,28,32,48,21,
	0,95,1,108,22,100,12,0,112,1,73,25,17,108,
	19,100,48,16,0,103,1,0,112,0,12,1,80,1,
	108,23,100,12,0,121,15,28,10,103,1,0,108,0,
	14,121,178,95,1,110,7
   };

   hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HACTIVEX_NEW )
{
   static const BYTE pcode[] =
   {
	13,11,7,102,80,8,133,57,0,97,0,0,0,80,
	80,9,134,1,126,10,0,0,134,2,127,11,9,0,
	65,116,108,65,120,87,105,110,0,134,4,48,2,0,
	48,24,0,95,8,112,0,95,1,100,95,9,95,4,
	95,3,95,5,95,6,112,7,73,134,5,48,25,0,
	95,8,95,2,112,1,73,134,10,48,26,0,95,8,
	108,27,100,95,10,95,11,95,2,48,28,0,95,8,
	112,0,48,29,0,95,8,112,0,48,30,0,95,8,
	112,0,48,31,0,95,8,112,0,48,32,0,95,8,
	112,0,48,33,0,48,34,0,95,8,112,0,112,0,
	48,35,0,95,8,112,0,12,10,112,1,73,134,12,
	48,36,0,95,8,112,0,73,134,14,48,37,0,95,
	8,108,38,100,48,33,0,95,8,112,0,12,1,112,
	1,73,134,17,108,39,100,89,15,0,1,0,0,0,
	108,40,100,95,1,12,1,6,12,1,80,18,162,35,
	0,0,134,19,48,41,0,95,8,48,2,0,108,42,
	100,12,0,48,43,0,95,8,112,0,112,1,112,1,
	73,163,24,0,0,164,0,0,0,80,17,134,21,108,
	44,100,48,45,0,95,17,112,0,20,1,134,23,108,
	39,100,95,18,20,1,134,36,108,46,100,48,43,0,
	95,8,112,0,96,12,0,48,47,0,95,8,112,0,
	48,48,0,95,8,112,0,20,4,134,37,48,49,0,
	95,8,95,12,112,1,73,134,39,95,8,110,7
   };

   hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HACTIVEX_RELEASE )
{
   static const BYTE pcode[] =
   {
	13,1,0,102,80,1,133,101,0,108,50,100,48,51,
	0,95,1,112,0,20,1,134,1,108,52,100,48,43,
	0,95,1,112,0,20,1,134,3,100,110,7
   };

   hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HACTIVEX___ERROR )
{
   static const BYTE pcode[] =
   {
	13,3,255,102,80,1,133,110,0,108,53,100,12,0,
	80,2,134,2,95,2,122,1,106,2,95,0,8,28,
	15,134,3,108,54,100,95,2,92,2,12,2,80,2,
	134,7,108,55,100,48,56,0,95,1,112,0,95,2,
	108,22,100,12,0,12,3,110,7
   };

   hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HACTIVEX_EVENTMAP )
{
   static const BYTE pcode[] =
   {
	13,2,3,102,80,4,133,122,0,108,57,100,48,47,
	0,95,4,112,0,95,1,12,2,80,5,134,1,95,
	5,121,8,28,53,134,2,108,58,100,48,47,0,95,
	4,112,0,95,1,20,2,134,3,108,58,100,48,48,
	0,95,4,112,0,100,100,4,2,0,20,2,134,4,
	108,59,100,48,47,0,95,4,112,0,12,1,80,5,
	134,6,95,2,95,3,4,2,0,48,48,0,95,4,
	150,95,5,2,134,7,100,110,7
   };

   hb_vmExecute( pcode, symbols );
}

HB_FUNC_INITSTATICS()
{
   static const BYTE pcode[] =
   {
	117,60,0,1,0,7
   };

   hb_vmExecute( pcode, symbols );
}
