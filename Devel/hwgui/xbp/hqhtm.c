/*
 * xHarbour 1.2.3 Intl. (SimpLex) (Build 20170228)
 * Generated C source code from <source\\qhtm\\hqhtm.prg>
 * Command: -oxbp\hqhtm.c -m -n -pOxbp\ -q -gc0 -Iinclude -Id:\devel\xharbour_bcc7\include source\qhtm\hqhtm.prg 
 * Created: 2022.09.08 13:51:10 (Borland/Embarcadero C++ 7.2 (32-bit))
 */

#include "hbvmpub.h"
#include "hbinit.h"

#define __PRG_SOURCE__ "source\\qhtm\\hqhtm.prg"

/* Forward declarations of all PRG defined Functions. */
HB_FUNC( HQHTM );
HB_FUNC_STATIC( HQHTM_NEW );
HB_FUNC_STATIC( HQHTM_ACTIVATE );
HB_FUNC_STATIC( HQHTM_REDEFINE );
HB_FUNC_STATIC( HQHTM_INIT );
HB_FUNC_STATIC( HQHTM_NOTIFY );
HB_FUNC( QHTMFORMPROC );
HB_FUNC( HQHTMBUTTON );
HB_FUNC_STATIC( HQHTMBUTTON_NEW );
HB_FUNC_STATIC( HQHTMBUTTON_REDEFINE );
HB_FUNC_STATIC( HQHTMBUTTON_INIT );
HB_FUNC_EXIT( FREEQHTM );
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
HB_FUNC_EXTERN( CREATEQHTM );
HB_FUNC_EXTERN( QHTM_INIT );
HB_FUNC_EXTERN( EMPTY );
HB_FUNC_EXTERN( SETWINDOWTEXT );
HB_FUNC_EXTERN( QHTM_LOADFILE );
HB_FUNC_EXTERN( QHTM_LOADRES );
HB_FUNC_EXTERN( QHTM_FORMCALLBACK );
HB_FUNC_EXTERN( QHTM_GETNOTIFY );
HB_FUNC_EXTERN( FILE );
HB_FUNC_EXTERN( MSGSTOP );
HB_FUNC_EXTERN( QHTM_SETRETURNVALUE );
HB_FUNC_EXTERN( FINDSELF );
HB_FUNC_EXTERN( HBUTTON );
HB_FUNC_EXTERN( SETCTRLFONT );
HB_FUNC_EXTERN( GETSTOCKOBJECT );
HB_FUNC_EXTERN( QHTM_SETHTMLBUTTON );
HB_FUNC_EXTERN( QHTM_END );

#undef HB_PRG_PCODE_VER
#define HB_PRG_PCODE_VER 10

#include "hbapi.h"

HB_INIT_SYMBOLS_BEGIN( hb_vm_SymbolInit_HQHTM )
{ "DIVERTCONSTRUCTORCALL", {HB_FS_PUBLIC | HB_FS_DEFERRED}, {NULL}, NULL },
{ "HQHTM", {HB_FS_PUBLIC | HB_FS_LOCAL}, {HB_FUNCNAME( HQHTM )}, &ModuleFakeDyn },
{ "NEW", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "HBCLASS", {HB_FS_PUBLIC}, {HB_FUNCNAME( HBCLASS )}, NULL },
{ "CLASSH", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "HCONTROL", {HB_FS_PUBLIC}, {HB_FUNCNAME( HCONTROL )}, NULL },
{ "ADDMULTIDATA", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "ADDMETHOD", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "HQHTM_NEW", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( HQHTM_NEW )}, &ModuleFakeDyn },
{ "HQHTM_ACTIVATE", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( HQHTM_ACTIVATE )}, &ModuleFakeDyn },
{ "HQHTM_REDEFINE", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( HQHTM_REDEFINE )}, &ModuleFakeDyn },
{ "HQHTM_INIT", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( HQHTM_INIT )}, &ModuleFakeDyn },
{ "HQHTM_NOTIFY", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( HQHTM_NOTIFY )}, &ModuleFakeDyn },
{ "__CLSACTIVE", {HB_FS_PUBLIC}, {HB_FUNCNAME( __CLSACTIVE )}, NULL },
{ "HCLASS", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "REFRESH", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "CREATE", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "__CLSINST", {HB_FS_PUBLIC}, {HB_FUNCNAME( __CLSINST )}, NULL },
{ "__OBJHASMSG", {HB_FS_PUBLIC}, {HB_FUNCNAME( __OBJHASMSG )}, NULL },
{ "INITCLASS", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "HB_APARAMS", {HB_FS_PUBLIC}, {HB_FUNCNAME( HB_APARAMS )}, NULL },
{ "PCOUNT", {HB_FS_PUBLIC}, {HB_FUNCNAME( PCOUNT )}, NULL },
{ "_OPARENT", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "ODEFAULTPARENT", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "_ID", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "NEWID", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "_STYLE", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "HWG_BITOR", {HB_FS_PUBLIC}, {HB_FUNCNAME( HWG_BITOR )}, NULL },
{ "_NLEFT", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "_NTOP", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "_NWIDTH", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "_NHEIGHT", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "_BINIT", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "_BSIZE", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "_BLINK", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "_BSUBMIT", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "_CTEXT", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "_FILENAME", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "_RESNAME", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "ADDCONTROL", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "OPARENT", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "ACTIVATE", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "HANDLE", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "_HANDLE", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "CREATEQHTM", {HB_FS_PUBLIC}, {HB_FUNCNAME( CREATEQHTM )}, NULL },
{ "ID", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "STYLE", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "NLEFT", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "NTOP", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "NWIDTH", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "NHEIGHT", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "INIT", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "QHTM_INIT", {HB_FS_PUBLIC}, {HB_FUNCNAME( QHTM_INIT )}, NULL },
{ "LINIT", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "HCONTROL", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "EMPTY", {HB_FS_PUBLIC}, {HB_FUNCNAME( EMPTY )}, NULL },
{ "CTEXT", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "SETWINDOWTEXT", {HB_FS_PUBLIC}, {HB_FUNCNAME( SETWINDOWTEXT )}, NULL },
{ "FILENAME", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "QHTM_LOADFILE", {HB_FS_PUBLIC}, {HB_FUNCNAME( QHTM_LOADFILE )}, NULL },
{ "RESNAME", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "QHTM_LOADRES", {HB_FS_PUBLIC}, {HB_FUNCNAME( QHTM_LOADRES )}, NULL },
{ "QHTM_FORMCALLBACK", {HB_FS_PUBLIC}, {HB_FUNCNAME( QHTM_FORMCALLBACK )}, NULL },
{ "QHTM_GETNOTIFY", {HB_FS_PUBLIC}, {HB_FUNCNAME( QHTM_GETNOTIFY )}, NULL },
{ "BLINK", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "EVAL", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "FILE", {HB_FS_PUBLIC}, {HB_FUNCNAME( FILE )}, NULL },
{ "MSGSTOP", {HB_FS_PUBLIC}, {HB_FUNCNAME( MSGSTOP )}, NULL },
{ "QHTM_SETRETURNVALUE", {HB_FS_PUBLIC}, {HB_FUNCNAME( QHTM_SETRETURNVALUE )}, NULL },
{ "QHTMFORMPROC", {HB_FS_PUBLIC | HB_FS_LOCAL | HB_FS_FIRST}, {HB_FUNCNAME( QHTMFORMPROC )}, &ModuleFakeDyn },
{ "FINDSELF", {HB_FS_PUBLIC}, {HB_FUNCNAME( FINDSELF )}, NULL },
{ "BSUBMIT", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "HQHTMBUTTON", {HB_FS_PUBLIC | HB_FS_LOCAL}, {HB_FUNCNAME( HQHTMBUTTON )}, &ModuleFakeDyn },
{ "HBUTTON", {HB_FS_PUBLIC}, {HB_FUNCNAME( HBUTTON )}, NULL },
{ "ADDMULTICLSDATA", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "HQHTMBUTTON_NEW", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( HQHTMBUTTON_NEW )}, &ModuleFakeDyn },
{ "HQHTMBUTTON_REDEFINE", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( HQHTMBUTTON_REDEFINE )}, &ModuleFakeDyn },
{ "HQHTMBUTTON_INIT", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( HQHTMBUTTON_INIT )}, &ModuleFakeDyn },
{ "_CHTML", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "HBUTTON", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "REDEFINE", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "OFONT", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "SETCTRLFONT", {HB_FS_PUBLIC}, {HB_FUNCNAME( SETCTRLFONT )}, NULL },
{ "GETSTOCKOBJECT", {HB_FS_PUBLIC}, {HB_FUNCNAME( GETSTOCKOBJECT )}, NULL },
{ "CHTML", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "QHTM_SETHTMLBUTTON", {HB_FS_PUBLIC}, {HB_FUNCNAME( QHTM_SETHTMLBUTTON )}, NULL },
{ "FREEQHTM$", {HB_FS_EXIT | HB_FS_LOCAL}, {HB_EXIT_FUNCNAME( FREEQHTM )}, &ModuleFakeDyn },
{ "QHTM_END", {HB_FS_PUBLIC}, {HB_FUNCNAME( QHTM_END )}, NULL },
{ "(_INITSTATICS00002)", {HB_FS_INITEXIT}, {hb_INITSTATICS}, &ModuleFakeDyn }
HB_INIT_SYMBOLS_EX_END( hb_vm_SymbolInit_HQHTM, __PRG_SOURCE__,  0x000a )

#if defined( HB_PRAGMA_STARTUP )
   #pragma startup hb_vm_SymbolInit_HQHTM
#elif defined( HB_DATASEG_STARTUP )
   #define HB_DATASEG_BODY    HB_DATASEG_FUNC( hb_vm_SymbolInit_HQHTM )
   #include "hbiniseg.h"
#endif

HB_FUNC( HQHTM )
{
   static const BYTE pcode[] =
   {
	13,2,255,116,88,0,126,2,1,0,95,2,73,103,
	1,0,100,8,29,158,1,48,2,0,108,3,100,12,
	0,106,6,72,81,104,116,109,0,48,4,0,108,5,
	100,12,0,112,0,4,1,0,112,2,82,1,0,133,
	17,0,48,6,0,103,1,0,100,106,22,81,72,84,
	77,95,87,105,110,100,111,119,95,67,108,97,115,115,
	95,48,48,49,0,95,2,106,9,119,105,110,99,108,
	97,115,115,0,4,1,0,9,9,112,6,73,134,1,
	48,6,0,103,1,0,100,106,1,0,95,2,106,6,
	99,84,101,120,116,0,4,1,0,9,9,112,6,73,
	134,2,48,6,0,103,1,0,100,106,1,0,95,2,
	106,9,102,105,108,101,110,97,109,101,0,4,1,0,
	9,9,112,6,73,134,3,48,6,0,103,1,0,100,
	106,1,0,95,2,106,8,114,101,115,110,97,109,101,
	0,4,1,0,9,9,112,6,73,134,4,48,6,0,
	103,1,0,100,100,95,2,106,6,98,76,105,110,107,
	0,106,8,98,83,117,98,109,105,116,0,4,2,0,
	9,9,112,6,73,134,7,48,7,0,103,1,0,106,
	4,78,101,119,0,108,8,14,95,2,9,112,4,73,
	134,8,48,7,0,103,1,0,106,9,65,99,116,105,
	118,97,116,101,0,108,9,14,95,2,9,112,4,73,
	134,9,48,7,0,103,1,0,106,9,82,101,100,101,
	102,105,110,101,0,108,10,14,95,2,9,112,4,73,
	134,10,48,7,0,103,1,0,106,5,73,110,105,116,
	0,108,11,14,95,2,9,112,4,73,134,11,48,7,
	0,103,1,0,106,7,78,111,116,105,102,121,0,108,
	12,14,95,2,9,112,4,73,48,16,0,103,1,0,
	112,0,73,108,17,100,48,14,0,103,1,0,112,0,
	12,1,80,1,108,18,100,95,1,106,10,73,110,105,
	116,67,108,97,115,115,0,12,2,28,32,48,19,0,
	95,1,108,20,100,12,0,112,1,73,25,17,108,17,
	100,48,14,0,103,1,0,112,0,12,1,80,1,108,
	21,100,12,0,121,15,28,10,103,1,0,108,0,14,
	121,178,95,1,110,7
   };

   hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HQHTM_NEW )
{
   static const BYTE pcode[] =
   {
	13,1,14,102,80,15,133,37,0,48,22,0,95,15,
	95,1,100,8,28,11,48,23,0,95,15,112,0,25,
	4,95,1,112,1,73,134,1,48,24,0,95,15,95,
	2,100,8,28,11,48,25,0,95,15,112,0,25,4,
	95,2,112,1,73,134,2,48,26,0,95,15,108,27,
	100,95,3,100,8,28,5,121,25,4,95,3,97,0,
	0,0,80,12,2,112,1,73,134,3,48,28,0,95,
	15,95,4,112,1,73,134,4,48,29,0,95,15,95,
	5,112,1,73,134,5,48,30,0,95,15,95,6,112,
	1,73,134,6,48,31,0,95,15,95,7,112,1,73,
	134,7,48,32,0,95,15,95,9,112,1,73,134,8,
	48,33,0,95,15,95,10,112,1,73,134,9,48,34,
	0,95,15,95,11,112,1,73,134,10,48,35,0,95,
	15,95,12,112,1,73,134,11,95,8,100,69,28,16,
	134,12,48,36,0,95,15,95,8,112,1,73,25,44,
	134,13,95,13,100,69,28,16,134,14,48,37,0,95,
	15,95,13,112,1,73,25,22,134,15,95,14,100,69,
	28,14,134,16,48,38,0,95,15,95,14,112,1,73,
	134,19,48,39,0,48,40,0,95,15,112,0,95,15,
	112,1,73,134,20,48,41,0,95,15,112,0,73,134,
	22,95,15,110,7
   };

   hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HQHTM_ACTIVATE )
{
   static const BYTE pcode[] =
   {
	13,1,0,102,80,1,133,62,0,48,42,0,48,40,
	0,95,1,112,0,112,0,121,69,28,83,134,2,48,
	43,0,95,1,108,44,100,48,42,0,48,40,0,95,
	1,112,0,112,0,48,45,0,95,1,112,0,48,46,
	0,95,1,112,0,48,47,0,95,1,112,0,48,48,
	0,95,1,112,0,48,49,0,95,1,112,0,48,50,
	0,95,1,112,0,12,7,112,1,73,134,3,48,51,
	0,95,1,112,0,73,25,9,134,5,108,52,100,20,
	0,134,7,100,110,7
   };

   hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HQHTM_REDEFINE )
{
   static const BYTE pcode[] =
   {
	13,1,9,102,80,10,133,73,0,48,22,0,95,10,
	95,1,100,8,28,11,48,23,0,95,10,112,0,25,
	4,95,1,112,1,73,134,1,48,24,0,95,10,95,
	2,112,1,73,134,2,48,26,0,95,10,48,28,0,
	95,10,48,29,0,95,10,48,30,0,95,10,48,31,
	0,95,10,121,112,1,112,1,112,1,112,1,112,1,
	73,134,3,48,32,0,95,10,95,4,112,1,73,134,
	4,48,33,0,95,10,95,5,112,1,73,134,5,48,
	34,0,95,10,95,6,112,1,73,134,6,48,35,0,
	95,10,95,7,112,1,73,134,7,95,3,100,69,28,
	16,134,8,48,36,0,95,10,95,3,112,1,73,25,
	44,134,9,95,8,100,69,28,16,134,10,48,37,0,
	95,10,95,8,112,1,73,25,22,134,11,95,9,100,
	69,28,14,134,12,48,38,0,95,10,95,9,112,1,
	73,134,15,48,39,0,48,40,0,95,10,112,0,95,
	10,112,1,73,134,16,108,52,100,20,0,134,18,95,
	10,110,7
   };

   hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HQHTM_INIT )
{
   static const BYTE pcode[] =
   {
	13,1,0,102,80,1,133,95,0,48,53,0,95,1,
	112,0,32,147,0,134,1,48,51,0,48,54,0,95,
	1,112,0,112,0,73,134,2,108,55,100,48,56,0,
	95,1,112,0,12,1,31,25,134,3,108,57,100,48,
	42,0,95,1,112,0,48,56,0,95,1,112,0,20,
	2,25,78,134,4,108,55,100,48,58,0,95,1,112,
	0,12,1,31,25,134,5,108,59,100,48,42,0,95,
	1,112,0,48,58,0,95,1,112,0,20,2,25,39,
	134,6,108,55,100,48,60,0,95,1,112,0,12,1,
	31,23,134,7,108,61,100,48,42,0,95,1,112,0,
	48,60,0,95,1,112,0,20,2,134,9,108,62,100,
	48,42,0,95,1,112,0,20,1,134,12,100,110,7
   };

   hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HQHTM_NOTIFY )
{
   static const BYTE pcode[] =
   {
	13,2,1,102,80,2,133,110,0,108,63,100,95,1,
	12,1,80,3,134,2,48,64,0,95,2,112,0,100,
	8,21,31,20,73,48,65,0,48,64,0,95,2,112,
	0,95,2,95,3,112,2,68,28,77,134,3,106,6,
	116,112,58,47,47,0,95,3,24,28,7,134,4,121,
	110,7,134,6,108,66,100,95,3,12,1,28,20,134,
	7,108,59,100,48,42,0,95,2,112,0,95,3,20,
	2,25,28,134,9,108,67,100,95,3,106,15,70,105,
	108,101,32,110,111,116,32,102,111,117,110,100,0,20,
	2,134,13,108,68,100,95,1,9,20,2,134,14,121,
	110,7
   };

   hb_vmExecute( pcode, symbols );
}

HB_FUNC( QHTMFORMPROC )
{
   static const BYTE pcode[] =
   {
	13,1,5,133,127,0,108,70,100,95,1,12,1,80,
	6,134,2,95,6,100,69,28,40,134,3,48,71,0,
	95,6,112,0,100,69,28,27,134,4,48,65,0,48,
	71,0,95,6,112,0,95,6,95,2,95,3,95,4,
	95,5,112,5,73,134,8,121,110,7
   };

   hb_vmExecute( pcode, symbols );
}

HB_FUNC( HQHTMBUTTON )
{
   static const BYTE pcode[] =
   {
	13,2,255,116,88,0,126,2,1,0,95,2,73,103,
	2,0,100,8,29,245,0,48,2,0,108,3,100,12,
	0,106,12,72,81,104,116,109,66,117,116,116,111,110,
	0,48,4,0,108,73,100,12,0,112,0,4,1,0,
	112,2,82,2,0,133,141,0,48,74,0,103,2,0,
	100,106,7,66,85,84,84,79,78,0,95,2,106,9,
	119,105,110,99,108,97,115,115,0,4,1,0,9,112,
	5,73,134,1,48,6,0,103,2,0,100,100,95,2,
	106,6,99,72,116,109,108,0,4,1,0,9,9,112,
	6,73,134,3,48,7,0,103,2,0,106,4,78,101,
	119,0,108,75,14,95,2,9,112,4,73,134,4,48,
	7,0,103,2,0,106,9,82,101,100,101,102,105,110,
	101,0,108,76,14,95,2,9,112,4,73,134,5,48,
	7,0,103,2,0,106,5,73,110,105,116,0,108,77,
	14,95,2,9,112,4,73,48,16,0,103,2,0,112,
	0,73,108,17,100,48,14,0,103,2,0,112,0,12,
	1,80,1,108,18,100,95,1,106,10,73,110,105,116,
	67,108,97,115,115,0,12,2,28,32,48,19,0,95,
	1,108,20,100,12,0,112,1,73,25,17,108,17,100,
	48,14,0,103,2,0,112,0,12,1,80,1,108,21,
	100,12,0,121,15,28,10,103,2,0,108,0,14,121,
	178,95,1,110,7
   };

   hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HQHTMBUTTON_NEW )
{
   static const BYTE pcode[] =
   {
	13,1,13,102,80,14,133,153,0,48,78,0,95,14,
	95,8,112,1,73,134,2,48,2,0,48,79,0,95,
	14,112,0,95,1,95,2,95,3,95,4,95,5,95,
	6,95,7,106,1,0,100,95,10,95,11,100,95,12,
	95,13,112,14,73,134,5,95,14,110,7
   };

   hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HQHTMBUTTON_REDEFINE )
{
   static const BYTE pcode[] =
   {
	13,1,8,102,80,9,133,162,0,48,78,0,95,9,
	95,3,112,1,73,134,1,48,80,0,48,79,0,95,
	9,112,0,95,1,95,2,100,95,5,95,6,100,95,
	7,95,8,112,8,73,134,4,95,9,110,7
   };

   hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HQHTMBUTTON_INIT )
{
   static const BYTE pcode[] =
   {
	13,1,0,102,80,1,133,170,0,48,51,0,48,79,
	0,95,1,112,0,112,0,73,134,1,9,48,81,0,
	95,1,112,0,100,8,28,17,73,48,81,0,48,40,
	0,95,1,112,0,112,0,100,8,28,35,134,2,108,
	82,100,48,42,0,48,40,0,95,1,112,0,112,0,
	48,45,0,95,1,112,0,108,83,100,92,13,12,1,
	20,3,134,4,108,57,100,48,42,0,95,1,112,0,
	48,84,0,95,1,112,0,20,2,134,5,108,85,100,
	48,42,0,95,1,112,0,20,1,134,7,100,110,7
   };

   hb_vmExecute( pcode, symbols );
}

HB_FUNC_EXIT( FREEQHTM )
{
   static const BYTE pcode[] =
   {
	133,180,0,108,87,100,20,0,134,1,7
   };

   hb_vmExecute( pcode, symbols );
}

HB_FUNC_INITSTATICS()
{
   static const BYTE pcode[] =
   {
	117,88,0,2,0,7
   };

   hb_vmExecute( pcode, symbols );
}

