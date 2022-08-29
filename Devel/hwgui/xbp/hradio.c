/*
 * xHarbour 1.2.3 Intl. (SimpLex) (Build 20201212)
 * Generated C source code from <source\\hradio.prg>
 * Command: -oxbp\hradio.c -m -n -pOxbp\ -q -gc0 -Iinclude -Id:\devel\xharbour_bcc73\include source\hradio.prg 
 * Created: 2022.07.29 19:37:05 (Borland/Embarcadero C++ 7.3 (32-bit))
 */

#include "hbvmpub.h"
#include "hbinit.h"

#define __PRG_SOURCE__ "source\\hradio.prg"

/* Forward declarations of all PRG defined Functions. */
HB_FUNC( HRADIOGROUP );
HB_FUNC_STATIC( HRADIOGROUP_NEW );
HB_FUNC_STATIC( HRADIOGROUP_NEWRG );
HB_FUNC_STATIC( HRADIOGROUP_ENDGROUP );
HB_FUNC_STATIC( HRADIOGROUP_INIT );
HB_FUNC_STATIC( HRADIOGROUP_SETVALUE );
HB_FUNC_STATIC( HRADIOGROUP_VALUE );
HB_FUNC_STATIC( HRADIOGROUP_REFRESH );
HB_FUNC_STATIC( HRADIOGROUP_ENABLE );
HB_FUNC_STATIC( HRADIOGROUP_DISABLE );
HB_FUNC( HRADIOBUTTON );
HB_FUNC_STATIC( HRADIOBUTTON_NEW );
HB_FUNC_STATIC( HRADIOBUTTON_ACTIVATE );
HB_FUNC_STATIC( HRADIOBUTTON_INIT );
HB_FUNC_STATIC( HRADIOBUTTON_REDEFINE );
HB_FUNC_STATIC( HRADIOBUTTON_ONEVENT );
HB_FUNC_STATIC( HRADIOBUTTON_ONGOTFOCUS );
HB_FUNC_STATIC( HRADIOBUTTON_ONCLICK );
HB_FUNC_STATIC( HRADIOBUTTON_WHEN );
HB_FUNC_STATIC( HRADIOBUTTON_VALID );
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
HB_FUNC_EXTERN( HWINDOW );
HB_FUNC_EXTERN( HWG_BITAND );
HB_FUNC_EXTERN( VALTYPE );
HB_FUNC_EXTERN( HGROUP );
HB_FUNC_EXTERN( LEN );
HB_FUNC_EXTERN( CHECKRADIOBUTTON );
HB_FUNC_EXTERN( LTRIM );
HB_FUNC_EXTERN( STR );
HB_FUNC_EXTERN( EMPTY );
HB_FUNC_EXTERN( SENDMESSAGE );
HB_FUNC_EXTERN( HWG_TRANSLATOR );
HB_FUNC_EXTERN( HWG_BITOR );
HB_FUNC_EXTERN( CHECKFOCUS );
HB_FUNC_EXTERN( AADD );
HB_FUNC_EXTERN( CREATEBUTTON );
HB_FUNC_EXTERN( SETWINDOWOBJECT );
HB_FUNC_EXTERN( HWG_INITBUTTONPROC );
HB_FUNC_EXTERN( PROCOKCANCEL );
HB_FUNC_EXTERN( GETDLGMESSAGE );
HB_FUNC_EXTERN( GETSKIP );
HB_FUNC_EXTERN( ISCTRLSHIFT );
HB_FUNC_EXTERN( PROCKEYLIST );
HB_FUNC_EXTERN( GETKEYSTATE );
HB_FUNC_EXTERN( WHENSETFOCUS );
HB_FUNC_EXTERN( ASCAN );
HB_FUNC_EXTERN( GETFOCUS );
HB_FUNC_EXTERN( SELFFOCUS );

#undef HB_PRG_PCODE_VER
#define HB_PRG_PCODE_VER 10

#include "hbapi.h"

HB_INIT_SYMBOLS_BEGIN( hb_vm_SymbolInit_HRADIO )
{ "DIVERTCONSTRUCTORCALL", {HB_FS_PUBLIC | HB_FS_DEFERRED}, {NULL}, NULL },
{ "HRADIOGROUP", {HB_FS_PUBLIC | HB_FS_LOCAL}, {HB_FUNCNAME( HRADIOGROUP )}, &ModuleFakeDyn },
{ "NEW", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "HBCLASS", {HB_FS_PUBLIC}, {HB_FUNCNAME( HBCLASS )}, NULL },
{ "CLASSH", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "HCONTROL", {HB_FS_PUBLIC}, {HB_FUNCNAME( HCONTROL )}, NULL },
{ "ADDMULTICLSDATA", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "ADDMULTIDATA", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "ADDMETHOD", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "HRADIOGROUP_NEW", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( HRADIOGROUP_NEW )}, &ModuleFakeDyn },
{ "HRADIOGROUP_NEWRG", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( HRADIOGROUP_NEWRG )}, &ModuleFakeDyn },
{ "HRADIOGROUP_ENDGROUP", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( HRADIOGROUP_ENDGROUP )}, &ModuleFakeDyn },
{ "HRADIOGROUP_SETVALUE", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( HRADIOGROUP_SETVALUE )}, &ModuleFakeDyn },
{ "ADDINLINE", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "NVALUE", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "HRADIOGROUP_VALUE", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( HRADIOGROUP_VALUE )}, &ModuleFakeDyn },
{ "HRADIOGROUP_REFRESH", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( HRADIOGROUP_REFRESH )}, &ModuleFakeDyn },
{ "HRADIOGROUP_ENABLE", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( HRADIOGROUP_ENABLE )}, &ModuleFakeDyn },
{ "HRADIOGROUP_DISABLE", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( HRADIOGROUP_DISABLE )}, &ModuleFakeDyn },
{ "HRADIOGROUP_INIT", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( HRADIOGROUP_INIT )}, &ModuleFakeDyn },
{ "ADDVIRTUAL", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "__CLSACTIVE", {HB_FS_PUBLIC}, {HB_FUNCNAME( __CLSACTIVE )}, NULL },
{ "HCLASS", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "REFRESH", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "CREATE", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "__CLSINST", {HB_FS_PUBLIC}, {HB_FUNCNAME( __CLSINST )}, NULL },
{ "__OBJHASMSG", {HB_FS_PUBLIC}, {HB_FUNCNAME( __OBJHASMSG )}, NULL },
{ "INITCLASS", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "HB_APARAMS", {HB_FS_PUBLIC}, {HB_FUNCNAME( HB_APARAMS )}, NULL },
{ "PCOUNT", {HB_FS_PUBLIC}, {HB_FUNCNAME( PCOUNT )}, NULL },
{ "_OGROUPCURRENT", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "_ABUTTONS", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "_OPARENT", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "GETMAIN", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "HWINDOW", {HB_FS_PUBLIC}, {HB_FUNCNAME( HWINDOW )}, NULL },
{ "ODEFAULTPARENT", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "_LENABLED", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "HWG_BITAND", {HB_FS_PUBLIC}, {HB_FUNCNAME( HWG_BITAND )}, NULL },
{ "HCONTROL", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "OPARENT", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "_BINIT", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "_BCLICK", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "_BGETFOCUS", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "VALTYPE", {HB_FS_PUBLIC}, {HB_FUNCNAME( VALTYPE )}, NULL },
{ "_NVALUE", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "_BSETGET", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "_OHGROUP", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "HGROUP", {HB_FS_PUBLIC}, {HB_FUNCNAME( HGROUP )}, NULL },
{ "_LINIT", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "OGROUPCURRENT", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "LEN", {HB_FS_PUBLIC}, {HB_FUNCNAME( LEN )}, NULL },
{ "ABUTTONS", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "HANDLE", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "CHECKRADIOBUTTON", {HB_FS_PUBLIC}, {HB_FUNCNAME( CHECKRADIOBUTTON )}, NULL },
{ "ID", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "LTRIM", {HB_FS_PUBLIC}, {HB_FUNCNAME( LTRIM )}, NULL },
{ "STR", {HB_FS_PUBLIC}, {HB_FUNCNAME( STR )}, NULL },
{ "EMPTY", {HB_FS_PUBLIC}, {HB_FUNCNAME( EMPTY )}, NULL },
{ "LINIT", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "INIT", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "BSETGET", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "EVAL", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "SETVALUE", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "ENABLE", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "DISABLE", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "HRADIOBUTTON", {HB_FS_PUBLIC | HB_FS_LOCAL}, {HB_FUNCNAME( HRADIOBUTTON )}, &ModuleFakeDyn },
{ "HRADIOBUTTON_NEW", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( HRADIOBUTTON_NEW )}, &ModuleFakeDyn },
{ "HRADIOBUTTON_ACTIVATE", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( HRADIOBUTTON_ACTIVATE )}, &ModuleFakeDyn },
{ "HRADIOBUTTON_INIT", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( HRADIOBUTTON_INIT )}, &ModuleFakeDyn },
{ "HRADIOBUTTON_REDEFINE", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( HRADIOBUTTON_REDEFINE )}, &ModuleFakeDyn },
{ "SENDMESSAGE", {HB_FS_PUBLIC}, {HB_FUNCNAME( SENDMESSAGE )}, NULL },
{ "HRADIOBUTTON_ONEVENT", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( HRADIOBUTTON_ONEVENT )}, &ModuleFakeDyn },
{ "HRADIOBUTTON_ONGOTFOCUS", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( HRADIOBUTTON_ONGOTFOCUS )}, &ModuleFakeDyn },
{ "HRADIOBUTTON_ONCLICK", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( HRADIOBUTTON_ONCLICK )}, &ModuleFakeDyn },
{ "HRADIOBUTTON_VALID", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( HRADIOBUTTON_VALID )}, &ModuleFakeDyn },
{ "HRADIOBUTTON_WHEN", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( HRADIOBUTTON_WHEN )}, &ModuleFakeDyn },
{ "_ID", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "NEWID", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "_LNAOTRADUZ", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "LNAOTRADUZ", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "_TITLE", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "HWG_TRANSLATOR", {HB_FS_PUBLIC}, {HB_FUNCNAME( HWG_TRANSLATOR )}, NULL },
{ "_OGROUP", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "_ENABLED", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "_STYLE", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "HWG_BITOR", {HB_FS_PUBLIC}, {HB_FUNCNAME( HWG_BITOR )}, NULL },
{ "OGROUP", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "STYLE", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "_BACKSTYLE", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "ACTIVATE", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "BCLICK", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "BGETFOCUS", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "_BLOSTFOCUS", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "ADDEVENT", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "WHEN", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "FINDCONTROL", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "_LNOVALID", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "CHECKFOCUS", {HB_FS_PUBLIC}, {HB_FUNCNAME( CHECKFOCUS )}, NULL },
{ "AADD", {HB_FS_PUBLIC}, {HB_FUNCNAME( AADD )}, NULL },
{ "ONCLICK", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "_HANDLE", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "CREATEBUTTON", {HB_FS_PUBLIC}, {HB_FUNCNAME( CREATEBUTTON )}, NULL },
{ "NLEFT", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "NTOP", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "NWIDTH", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "NHEIGHT", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "TITLE", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "_NHOLDER", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "SETWINDOWOBJECT", {HB_FS_PUBLIC}, {HB_FUNCNAME( SETWINDOWOBJECT )}, NULL },
{ "HWG_INITBUTTONPROC", {HB_FS_PUBLIC}, {HB_FUNCNAME( HWG_INITBUTTONPROC )}, NULL },
{ "LENABLED", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "ENABLED", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "_NLEFT", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "_NTOP", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "_NWIDTH", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "_NHEIGHT", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "_OFONT", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "_BSIZE", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "_BPAINT", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "_TOOLTIP", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "SETCOLOR", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "ADDCONTROL", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "BOTHER", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "PROCOKCANCEL", {HB_FS_PUBLIC}, {HB_FUNCNAME( PROCOKCANCEL )}, NULL },
{ "TYPE", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "GETPARENTFORM", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "ISENABLED", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "GETDLGMESSAGE", {HB_FS_PUBLIC}, {HB_FUNCNAME( GETDLGMESSAGE )}, NULL },
{ "VALID", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "GETSKIP", {HB_FS_PUBLIC}, {HB_FUNCNAME( GETSKIP )}, NULL },
{ "ISCTRLSHIFT", {HB_FS_PUBLIC}, {HB_FUNCNAME( ISCTRLSHIFT )}, NULL },
{ "PROCKEYLIST", {HB_FS_PUBLIC}, {HB_FUNCNAME( PROCKEYLIST )}, NULL },
{ "_LWHEN", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "GETKEYSTATE", {HB_FS_PUBLIC}, {HB_FUNCNAME( GETKEYSTATE )}, NULL },
{ "_LSUSPENDMSGSHANDLING", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "WHENSETFOCUS", {HB_FS_PUBLIC}, {HB_FUNCNAME( WHENSETFOCUS )}, NULL },
{ "SETFOCUS", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "LNOVALID", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "LWHEN", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "ASCAN", {HB_FS_PUBLIC}, {HB_FUNCNAME( ASCAN )}, NULL },
{ "GETVALUE", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "GETFOCUS", {HB_FS_PUBLIC}, {HB_FUNCNAME( GETFOCUS )}, NULL },
{ "BLOSTFOCUS", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "SELFFOCUS", {HB_FS_PUBLIC}, {HB_FUNCNAME( SELFFOCUS )}, NULL },
{ "(_INITSTATICS00002)", {HB_FS_INITEXIT}, {hb_INITSTATICS}, &ModuleFakeDyn }
HB_INIT_SYMBOLS_EX_END( hb_vm_SymbolInit_HRADIO, __PRG_SOURCE__,  0x000a )

#if defined( HB_PRAGMA_STARTUP )
   #pragma startup hb_vm_SymbolInit_HRADIO
#elif defined( HB_DATASEG_STARTUP )
   #define HB_DATASEG_BODY    HB_DATASEG_FUNC( hb_vm_SymbolInit_HRADIO )
   #include "hbiniseg.h"
#endif

HB_FUNC( HRADIOGROUP )
{
   static const BYTE pcode[] =
   {
	13,2,255,116,144,0,126,2,1,0,95,2,73,103,
	1,0,100,8,29,238,2,48,2,0,108,3,100,12,
	0,106,12,72,82,97,100,105,111,71,114,111,117,112,
	0,48,4,0,108,5,100,12,0,112,0,4,1,0,
	112,2,82,1,0,133,18,0,48,6,0,103,1,0,
	100,106,7,83,84,65,84,73,67,0,95,2,106,9,
	119,105,110,99,108,97,115,115,0,4,1,0,9,112,
	5,73,134,1,48,6,0,103,1,0,100,100,95,2,
	106,14,111,71,114,111,117,112,67,117,114,114,101,110,
	116,0,4,1,0,9,112,5,73,134,2,48,7,0,
	103,1,0,100,100,95,2,106,9,97,66,117,116,116,
	111,110,115,0,4,1,0,9,9,112,6,73,134,3,
	48,7,0,103,1,0,100,122,95,2,106,7,110,86,
	97,108,117,101,0,4,1,0,9,9,112,6,73,134,
	4,48,7,0,103,1,0,100,100,95,2,106,8,98,
	83,101,116,71,101,116,0,4,1,0,9,9,112,6,
	73,134,5,48,7,0,103,1,0,100,100,95,2,106,
	8,111,72,71,114,111,117,112,0,4,1,0,9,9,
	112,6,73,134,6,48,7,0,103,1,0,100,120,95,
	2,106,9,108,69,110,97,98,108,101,100,0,4,1,
	0,9,9,112,6,73,134,7,48,7,0,103,1,0,
	100,100,95,2,106,7,98,67,108,105,99,107,0,4,
	1,0,9,9,112,6,73,134,8,48,7,0,103,1,
	0,100,9,95,2,106,11,108,78,65,79,84,114,97,
	100,117,122,0,4,1,0,9,9,112,6,73,134,10,
	48,8,0,103,1,0,106,4,78,101,119,0,108,9,
	14,95,2,9,112,4,73,134,13,48,8,0,103,1,
	0,106,6,78,101,119,114,103,0,108,10,14,95,2,
	9,112,4,73,134,14,48,8,0,103,1,0,106,9,
	69,110,100,71,114,111,117,112,0,108,11,14,95,2,
	9,112,4,73,134,15,48,8,0,103,1,0,106,9,
	83,101,116,86,97,108,117,101,0,108,12,14,95,2,
	9,112,4,73,134,16,48,13,0,103,1,0,106,9,
	71,101,116,86,97,108,117,101,0,89,18,0,1,0,
	0,0,95,1,73,48,14,0,95,1,112,0,6,95,
	2,9,112,4,73,134,17,48,13,0,103,1,0,106,
	7,86,65,82,71,69,84,0,89,18,0,1,0,0,
	0,95,1,73,48,14,0,95,1,112,0,6,95,2,
	9,112,4,73,134,18,48,8,0,103,1,0,106,6,
	86,97,108,117,101,0,108,15,14,92,33,9,112,4,
	73,48,8,0,103,1,0,106,7,95,86,97,108,117,
	101,0,108,15,14,112,2,73,134,19,48,8,0,103,
	1,0,106,8,82,101,102,114,101,115,104,0,108,16,
	14,95,2,9,112,4,73,134,21,48,8,0,103,1,
	0,106,7,69,110,97,98,108,101,0,108,17,14,95,
	2,9,112,4,73,134,22,48,8,0,103,1,0,106,
	8,68,105,115,97,98,108,101,0,108,18,14,95,2,
	9,112,4,73,134,24,48,8,0,103,1,0,106,5,
	73,110,105,116,0,108,19,14,95,2,9,112,4,73,
	134,25,48,20,0,103,1,0,106,9,65,99,116,105,
	118,97,116,101,0,112,1,73,48,24,0,103,1,0,
	112,0,73,108,25,100,48,22,0,103,1,0,112,0,
	12,1,80,1,108,26,100,95,1,106,10,73,110,105,
	116,67,108,97,115,115,0,12,2,28,32,48,27,0,
	95,1,108,28,100,12,0,112,1,73,25,17,108,25,
	100,48,22,0,103,1,0,112,0,12,1,80,1,108,
	29,100,12,0,121,15,28,10,103,1,0,108,0,14,
	121,178,95,1,110,7
   };

   hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HRADIOGROUP_NEW )
{
   static const BYTE pcode[] =
   {
	13,1,6,102,80,7,133,49,0,48,30,0,95,7,
	95,7,112,1,73,134,1,48,31,0,95,7,4,0,
	0,112,1,73,134,2,48,32,0,95,7,48,33,0,
	108,34,100,12,0,112,0,100,69,28,19,48,35,0,
	48,33,0,108,34,100,12,0,112,0,112,0,25,3,
	100,112,1,73,134,4,48,36,0,95,7,108,37,100,
	95,6,97,0,0,0,8,12,2,121,15,68,112,1,
	73,134,6,48,2,0,48,38,0,95,7,112,0,48,
	39,0,95,7,112,0,100,100,100,100,100,100,100,95,
	3,112,9,73,134,8,48,40,0,95,7,95,3,112,
	1,73,134,9,48,41,0,95,7,95,4,112,1,73,
	134,10,48,42,0,95,7,95,5,112,1,73,134,13,
	95,1,100,69,28,30,134,14,108,43,100,95,1,12,
	1,106,2,78,0,8,28,14,134,15,48,44,0,95,
	7,95,1,112,1,73,134,19,48,45,0,95,7,95,
	2,112,1,73,134,21,95,7,110,7
   };

   hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HRADIOGROUP_NEWRG )
{
   static const BYTE pcode[] =
   {
	13,1,19,102,80,20,133,76,0,48,30,0,95,20,
	95,20,112,1,73,134,1,48,31,0,95,20,4,0,
	0,112,1,73,134,2,48,36,0,95,20,108,37,100,
	95,3,97,0,0,0,8,12,2,121,15,68,112,1,
	73,134,4,48,2,0,48,38,0,95,20,112,0,48,
	39,0,95,20,112,0,100,100,95,6,95,7,95,8,
	95,9,95,11,95,12,112,9,73,134,6,48,46,0,
	95,20,48,2,0,108,47,100,12,0,95,1,95,2,
	95,3,95,6,95,7,95,8,95,9,95,10,95,11,
	95,12,95,13,100,95,14,95,15,95,18,95,20,95,
	19,112,17,112,1,73,134,8,48,48,0,95,20,120,
	112,1,73,134,9,48,40,0,95,20,95,12,112,1,
	73,134,10,48,41,0,95,20,95,16,112,1,73,134,
	11,48,42,0,95,20,95,17,112,1,73,134,13,95,
	4,100,69,28,30,134,14,108,43,100,95,4,12,1,
	106,2,78,0,8,28,14,134,15,48,44,0,95,20,
	95,4,112,1,73,134,18,48,45,0,95,20,95,5,
	112,1,73,134,20,95,20,110,7
   };

   hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HRADIOGROUP_ENDGROUP )
{
   static const BYTE pcode[] =
   {
	13,2,1,102,80,2,133,102,0,9,48,49,0,95,
	2,112,0,100,69,28,25,73,108,50,100,48,51,0,
	48,49,0,95,2,112,0,112,0,12,1,21,80,3,
	121,15,29,148,1,134,3,9,95,1,100,69,28,16,
	73,9,95,1,95,3,34,28,7,73,95,1,121,15,
	28,6,95,1,25,14,48,14,0,48,49,0,95,2,
	112,0,112,0,80,1,134,4,9,95,1,121,69,28,
	8,73,95,1,95,3,34,29,41,1,134,5,48,52,
	0,48,51,0,48,49,0,95,2,112,0,112,0,95,
	3,1,112,0,121,15,28,96,134,9,108,53,100,48,
	52,0,48,39,0,48,51,0,48,49,0,95,2,112,
	0,112,0,95,3,1,112,0,112,0,48,54,0,48,
	51,0,48,49,0,95,2,112,0,112,0,122,1,112,
	0,48,54,0,48,51,0,48,49,0,95,2,112,0,
	112,0,95,3,1,112,0,48,54,0,48,51,0,48,
	49,0,95,2,112,0,112,0,95,1,1,112,0,20,
	4,26,177,0,134,15,48,40,0,48,51,0,48,49,
	0,95,2,112,0,112,0,95,3,1,106,39,123,124,
	111,124,67,104,101,99,107,82,97,100,105,111,66,117,
	116,116,111,110,40,111,58,111,80,97,114,101,110,116,
	58,104,97,110,100,108,101,44,0,108,55,100,108,56,
	100,48,54,0,48,51,0,48,49,0,95,2,112,0,
	112,0,122,1,112,0,12,1,12,1,72,106,2,44,
	0,72,108,55,100,108,56,100,48,54,0,48,51,0,
	48,49,0,95,2,112,0,112,0,95,3,1,112,0,
	12,1,12,1,72,106,2,44,0,72,108,55,100,108,
	56,100,48,54,0,48,51,0,48,49,0,95,2,112,
	0,112,0,95,1,1,112,0,12,1,12,1,72,106,
	3,41,125,0,72,40,11,112,1,73,134,18,108,57,
	100,48,39,0,95,2,112,0,12,1,28,32,134,19,
	48,32,0,95,2,48,39,0,48,51,0,48,49,0,
	95,2,112,0,112,0,95,3,1,112,0,112,1,73,
	134,23,48,30,0,95,2,100,112,1,73,134,24,100,
	110,7
   };

   hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HRADIOGROUP_INIT )
{
   static const BYTE pcode[] =
   {
	13,1,0,102,80,1,133,130,0,48,58,0,95,1,
	112,0,31,17,134,7,48,59,0,48,38,0,95,1,
	112,0,112,0,73,134,9,100,110,7
   };

   hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HRADIOGROUP_SETVALUE )
{
   static const BYTE pcode[] =
   {
	13,2,1,102,80,2,133,144,0,9,108,50,100,48,
	51,0,95,2,112,0,12,1,21,80,3,121,15,28,
	16,73,9,95,1,121,15,28,8,73,95,1,95,3,
	34,28,122,134,4,108,53,100,48,52,0,48,39,0,
	48,51,0,95,2,112,0,95,3,1,112,0,112,0,
	48,54,0,48,51,0,95,2,112,0,122,1,112,0,
	48,54,0,48,51,0,95,2,112,0,95,3,1,112,
	0,48,54,0,48,51,0,95,2,112,0,95,1,1,
	112,0,20,4,134,5,48,44,0,95,2,95,1,112,
	1,73,134,6,48,60,0,95,2,112,0,100,69,28,
	91,134,7,48,61,0,48,60,0,95,2,112,0,48,
	14,0,95,2,112,0,112,1,73,25,67,134,9,95,
	3,121,15,28,59,134,13,108,53,100,48,52,0,48,
	39,0,48,51,0,95,2,112,0,95,3,1,112,0,
	112,0,48,54,0,48,51,0,95,2,112,0,122,1,
	112,0,48,54,0,48,51,0,95,2,112,0,95,3,
	1,112,0,121,20,4,134,15,100,110,7
   };

   hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HRADIOGROUP_VALUE )
{
   static const BYTE pcode[] =
   {
	13,1,1,102,80,2,133,163,0,95,1,100,69,28,
	14,134,1,48,62,0,95,2,95,1,112,1,73,134,
	3,48,14,0,95,2,112,0,110,7
   };

   hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HRADIOGROUP_REFRESH )
{
   static const BYTE pcode[] =
   {
	13,2,0,102,80,1,133,172,0,48,60,0,95,1,
	112,0,100,69,28,68,134,1,48,61,0,48,60,0,
	95,1,112,0,100,95,1,112,2,80,2,134,2,95,
	2,100,5,21,31,15,73,108,43,100,95,2,12,1,
	106,2,78,0,69,28,13,134,3,48,14,0,95,1,
	112,0,80,2,134,5,48,62,0,95,1,95,2,112,
	1,73,134,7,100,110,7
   };

   hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HRADIOGROUP_ENABLE )
{
   static const BYTE pcode[] =
   {
	13,3,0,102,80,1,133,182,0,108,50,100,48,51,
	0,95,1,112,0,12,1,80,3,134,2,126,2,1,
	0,95,2,95,3,34,28,26,134,3,48,63,0,48,
	51,0,95,1,112,0,95,2,1,112,0,73,134,4,
	173,2,25,227,134,5,100,110,7
   };

   hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HRADIOGROUP_DISABLE )
{
   static const BYTE pcode[] =
   {
	13,3,0,102,80,1,133,190,0,108,50,100,48,51,
	0,95,1,112,0,12,1,80,3,134,2,126,2,1,
	0,95,2,95,3,34,28,26,134,3,48,64,0,48,
	51,0,95,1,112,0,95,2,1,112,0,73,134,4,
	173,2,25,227,134,5,100,110,7
   };

   hb_vmExecute( pcode, symbols );
}

HB_FUNC( HRADIOBUTTON )
{
   static const BYTE pcode[] =
   {
	13,2,255,116,144,0,126,2,1,0,95,2,73,103,
	2,0,100,8,29,12,2,48,2,0,108,3,100,12,
	0,106,13,72,82,97,100,105,111,66,117,116,116,111,
	110,0,48,4,0,108,5,100,12,0,112,0,4,1,
	0,112,2,82,2,0,133,201,0,48,6,0,103,2,
	0,100,106,7,66,85,84,84,79,78,0,95,2,106,
	9,119,105,110,99,108,97,115,115,0,4,1,0,9,
	112,5,73,134,1,48,7,0,103,2,0,100,100,95,
	2,106,7,111,71,114,111,117,112,0,4,1,0,9,
	9,112,6,73,134,2,48,7,0,103,2,0,100,9,
	95,2,106,6,108,87,104,101,110,0,4,1,0,9,
	9,112,6,73,134,3,48,7,0,103,2,0,100,9,
	95,2,106,11,108,78,65,79,84,114,97,100,117,122,
	0,4,1,0,9,9,112,6,73,134,6,48,8,0,
	103,2,0,106,4,78,101,119,0,108,66,14,95,2,
	9,112,4,73,134,7,48,8,0,103,2,0,106,9,
	65,99,116,105,118,97,116,101,0,108,67,14,95,2,
	9,112,4,73,134,8,48,8,0,103,2,0,106,5,
	73,110,105,116,0,108,68,14,95,2,9,112,4,73,
	134,9,48,8,0,103,2,0,106,9,82,101,100,101,
	102,105,110,101,0,108,69,14,95,2,9,112,4,73,
	134,10,48,13,0,103,2,0,106,9,71,101,116,86,
	97,108,117,101,0,89,30,0,1,0,0,0,95,1,
	73,108,70,100,48,52,0,95,1,112,0,93,240,0,
	121,121,12,4,122,8,6,95,2,9,112,4,73,134,
	12,48,8,0,103,2,0,106,8,111,110,101,118,101,
	110,116,0,108,71,14,95,2,9,112,4,73,134,13,
	48,8,0,103,2,0,106,11,111,110,71,111,116,70,
	111,99,117,115,0,108,72,14,95,2,9,112,4,73,
	134,14,48,8,0,103,2,0,106,8,111,110,67,108,
	105,99,107,0,108,73,14,95,2,9,112,4,73,134,
	15,48,8,0,103,2,0,106,6,86,97,108,105,100,
	0,108,74,14,95,2,9,112,4,73,134,16,48,8,
	0,103,2,0,106,5,87,104,101,110,0,108,75,14,
	95,2,9,112,4,73,48,24,0,103,2,0,112,0,
	73,108,25,100,48,22,0,103,2,0,112,0,12,1,
	80,1,108,26,100,95,1,106,10,73,110,105,116,67,
	108,97,115,115,0,12,2,28,32,48,27,0,95,1,
	108,28,100,12,0,112,1,73,25,17,108,25,100,48,
	22,0,103,2,0,112,0,12,1,80,1,108,29,100,
	12,0,121,15,28,10,103,2,0,108,0,14,121,178,
	95,1,110,7
   };

   hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HRADIOBUTTON_NEW )
{
   static const BYTE pcode[] =
   {
	13,1,19,102,80,20,133,225,0,48,32,0,95,20,
	95,1,100,8,28,11,48,35,0,95,20,112,0,25,
	4,95,1,112,1,73,134,2,48,76,0,95,20,95,
	2,100,8,28,11,48,77,0,95,20,112,0,25,4,
	95,2,112,1,73,134,5,48,78,0,95,20,95,19,
	100,8,28,5,9,25,4,95,19,112,1,73,134,8,
	48,79,0,95,20,112,0,28,22,134,9,48,80,0,
	95,20,95,8,112,1,73,134,10,95,14,80,14,25,
	68,134,12,48,80,0,95,20,108,81,100,95,8,106,
	12,82,65,68,73,79,66,85,84,84,79,78,0,12,
	2,112,1,73,134,15,108,81,100,95,14,106,22,82,
	65,68,73,79,66,85,84,84,79,78,32,47,32,84,
	79,79,76,84,73,80,0,12,2,80,14,134,18,48,
	82,0,95,20,48,49,0,108,1,100,12,0,112,0,
	112,1,73,134,19,48,83,0,95,20,108,37,100,95,
	3,97,0,0,0,8,12,2,121,15,68,112,1,73,
	134,22,48,84,0,95,20,108,85,100,95,3,100,8,
	28,5,121,25,4,95,3,93,4,64,9,48,86,0,
	95,20,112,0,100,69,28,20,73,108,57,100,48,51,
	0,48,86,0,95,20,112,0,112,0,12,1,28,9,
	97,0,0,2,0,25,3,121,72,12,2,112,1,73,
	134,25,48,2,0,48,38,0,95,20,112,0,95,1,
	95,2,48,87,0,95,20,112,0,95,4,95,5,95,
	6,95,7,95,9,95,10,95,11,95,12,95,14,95,
	15,95,16,112,14,73,134,27,48,88,0,95,20,9,
	95,18,100,69,28,5,73,95,18,28,5,122,25,4,
	92,2,112,1,73,134,29,48,89,0,95,20,112,0,
	73,134,34,48,86,0,95,20,112,0,100,69,28,54,
	134,35,95,13,100,69,28,6,95,13,25,14,48,90,
	0,48,86,0,95,20,112,0,112,0,80,13,134,36,
	95,17,100,69,28,6,95,17,25,14,48,91,0,48,
	86,0,95,20,112,0,112,0,80,17,134,38,9,95,
	13,100,69,28,30,73,48,86,0,95,20,112,0,100,
	8,21,31,17,73,48,60,0,48,86,0,95,20,112,
	0,112,0,100,8,28,14,134,39,48,92,0,95,20,
	95,13,112,1,73,134,41,48,42,0,95,20,95,17,
	112,1,73,134,42,95,17,100,69,28,72,134,43,48,
	93,0,48,39,0,95,20,112,0,92,6,95,20,89,
	26,0,2,0,1,0,20,0,48,94,0,95,255,48,
	95,0,95,1,95,2,112,1,112,1,6,100,106,11,
	111,110,71,111,116,70,111,99,117,115,0,112,5,73,
	134,45,48,96,0,95,20,120,112,1,73,134,48,48,
	93,0,48,39,0,95,20,112,0,92,7,95,20,89,
	18,0,1,0,1,0,20,0,108,97,100,95,255,120,
	12,2,6,112,3,73,134,50,48,86,0,95,20,112,
	0,100,69,28,81,134,51,108,98,100,48,51,0,48,
	86,0,95,20,112,0,112,0,95,20,20,2,134,53,
	48,92,0,95,20,95,13,112,1,73,134,55,48,93,
	0,48,39,0,95,20,112,0,121,95,20,89,17,0,
	1,0,1,0,20,0,48,99,0,95,255,112,0,6,
	100,106,8,111,110,67,108,105,99,107,0,112,5,73,
	134,59,95,20,110,7
   };

   hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HRADIOBUTTON_ACTIVATE )
{
   static const BYTE pcode[] =
   {
	13,1,0,102,80,1,133,31,1,108,57,100,48,52,
	0,48,39,0,95,1,112,0,112,0,12,1,31,88,
	134,2,48,100,0,95,1,108,101,100,48,52,0,48,
	39,0,95,1,112,0,112,0,48,54,0,95,1,112,
	0,48,87,0,95,1,112,0,48,102,0,95,1,112,
	0,48,103,0,95,1,112,0,48,104,0,95,1,112,
	0,48,105,0,95,1,112,0,48,106,0,95,1,112,
	0,12,8,112,1,73,134,3,48,59,0,95,1,112,
	0,73,134,5,100,110,7
   };

   hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HRADIOBUTTON_INIT )
{
   static const BYTE pcode[] =
   {
	13,1,0,102,80,1,133,39,1,48,58,0,95,1,
	112,0,31,91,134,1,48,107,0,95,1,122,112,1,
	73,134,2,108,108,100,48,52,0,95,1,112,0,95,
	1,20,2,134,3,108,109,100,48,52,0,95,1,112,
	0,20,1,134,4,48,83,0,95,1,9,48,110,0,
	48,86,0,95,1,112,0,112,0,28,10,73,48,111,
	0,95,1,112,0,112,1,73,134,5,48,59,0,48,
	38,0,95,1,112,0,112,0,73,134,7,100,110,7
   };

   hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HRADIOBUTTON_REDEFINE )
{
   static const BYTE pcode[] =
   {
	13,1,12,102,80,13,133,49,1,48,32,0,95,13,
	95,1,100,8,28,11,48,35,0,95,13,112,0,25,
	4,95,1,112,1,73,134,1,48,76,0,95,13,95,
	2,112,1,73,134,2,48,82,0,95,13,48,49,0,
	108,1,100,12,0,112,0,112,1,73,134,3,48,84,
	0,95,13,48,112,0,95,13,48,113,0,95,13,48,
	114,0,95,13,48,115,0,95,13,121,112,1,112,1,
	112,1,112,1,112,1,73,134,4,48,116,0,95,13,
	95,3,112,1,73,134,5,48,40,0,95,13,95,4,
	112,1,73,134,6,48,117,0,95,13,95,5,112,1,
	73,134,7,48,118,0,95,13,95,6,112,1,73,134,
	8,48,119,0,95,13,95,8,112,1,73,134,15,48,
	88,0,95,13,9,95,12,100,69,28,5,73,95,12,
	28,5,122,25,4,92,2,112,1,73,134,16,48,120,
	0,95,13,95,9,95,10,120,112,3,73,134,17,48,
	121,0,48,39,0,95,13,112,0,95,13,112,1,73,
	134,19,48,121,0,48,39,0,95,13,112,0,95,13,
	112,1,73,134,21,9,95,7,100,69,28,30,73,48,
	86,0,95,13,112,0,100,8,21,31,17,73,48,60,
	0,48,86,0,95,13,112,0,112,0,100,8,28,14,
	134,23,48,92,0,95,13,95,7,112,1,73,134,26,
	48,42,0,95,13,95,11,112,1,73,134,27,95,11,
	100,69,28,72,134,28,48,93,0,48,39,0,95,13,
	112,0,92,6,95,13,89,26,0,2,0,1,0,13,
	0,48,94,0,95,255,48,95,0,95,1,95,2,112,
	1,112,1,6,100,106,11,111,110,71,111,116,70,111,
	99,117,115,0,112,5,73,134,29,48,96,0,95,13,
	120,112,1,73,134,32,48,93,0,48,39,0,95,13,
	112,0,92,7,95,13,89,18,0,1,0,1,0,13,
	0,108,97,100,95,255,120,12,2,6,112,3,73,134,
	33,48,86,0,95,13,112,0,100,69,28,81,134,34,
	108,98,100,48,51,0,48,86,0,95,13,112,0,112,
	0,95,13,20,2,134,36,48,92,0,95,13,95,7,
	112,1,73,134,38,48,93,0,48,39,0,95,13,112,
	0,121,95,13,89,17,0,1,0,1,0,13,0,48,
	99,0,95,255,112,0,6,100,106,8,111,110,67,108,
	105,99,107,0,112,5,73,134,41,95,13,110,7
   };

   hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HRADIOBUTTON_ONEVENT )
{
   static const BYTE pcode[] =
   {
	13,2,3,102,80,4,133,95,1,48,122,0,95,4,
	112,0,100,69,28,34,134,1,48,61,0,48,122,0,
	95,4,112,0,95,4,95,1,95,2,95,3,112,4,
	92,255,69,28,7,134,2,121,110,7,134,5,95,1,
	93,135,0,5,29,196,0,134,6,9,95,2,92,13,
	5,28,27,73,108,123,100,95,4,95,2,48,124,0,
	48,125,0,95,4,112,0,112,0,92,10,16,12,3,
	28,7,134,7,121,110,7,134,9,9,95,2,92,27,
	5,28,34,73,9,48,95,0,48,125,0,95,4,112,
	0,92,2,112,1,21,80,5,100,69,28,11,73,48,
	126,0,95,5,112,0,68,28,8,134,10,92,4,110,
	7,134,12,9,95,2,92,9,69,28,14,73,108,127,
	100,95,3,12,1,93,2,1,5,21,31,23,73,108,
	127,100,95,3,12,1,93,6,1,5,21,31,8,73,
	95,2,92,27,5,28,8,134,13,92,255,110,7,134,
	14,9,108,127,100,95,3,12,1,93,0,1,5,28,
	8,73,95,2,92,13,5,28,19,134,15,48,128,0,
	95,4,92,13,112,1,73,134,16,122,110,7,134,18,
	92,4,110,7,134,19,95,1,93,0,1,5,29,172,
	0,134,21,95,2,92,37,5,21,31,8,73,95,2,
	92,38,5,28,31,134,22,108,129,100,48,39,0,95,
	4,112,0,48,52,0,95,4,112,0,100,92,255,20,
	4,134,23,121,110,7,134,24,95,2,92,39,5,21,
	31,8,73,95,2,92,40,5,28,30,134,25,108,129,
	100,48,39,0,95,4,112,0,48,52,0,95,4,112,
	0,100,122,20,4,134,26,121,110,7,134,27,95,2,
	92,9,5,28,43,134,28,108,129,100,48,39,0,95,
	4,112,0,48,52,0,95,4,112,0,100,108,130,100,
	9,120,12,2,28,6,92,255,25,3,122,20,4,134,
	29,121,110,7,134,31,95,2,92,13,8,28,62,134,
	32,48,128,0,95,4,92,13,112,1,73,134,33,121,
	110,7,134,35,95,1,93,1,1,8,28,27,134,36,
	108,131,100,95,4,95,2,20,2,134,37,95,2,92,
	13,8,28,15,134,38,121,110,7,134,40,95,1,92,
	78,8,73,134,43,92,255,110,7
   };

   hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HRADIOBUTTON_ONGOTFOCUS )
{
   static const BYTE pcode[] =
   {
	13,1,0,102,80,1,133,173,1,48,94,0,95,1,
	112,0,110,7
   };

   hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HRADIOBUTTON_ONCLICK )
{
   static const BYTE pcode[] =
   {
	13,1,0,102,80,1,133,176,1,48,132,0,95,1,
	9,112,1,73,134,1,48,96,0,95,1,9,112,1,
	73,134,2,48,128,0,95,1,121,112,1,110,7
   };

   hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HRADIOBUTTON_WHEN )
{
   static const BYTE pcode[] =
   {
	13,3,0,102,80,1,133,181,1,120,80,2,134,2,
	108,97,100,95,1,9,12,2,31,7,134,3,120,110,
	7,134,5,108,133,100,92,38,12,1,121,35,21,31,
	25,73,9,108,133,100,92,9,12,1,121,35,28,12,
	73,108,133,100,92,16,12,1,121,35,28,6,92,255,
	25,3,122,80,3,134,6,48,132,0,95,1,108,133,
	100,92,38,12,1,108,133,100,92,40,12,1,72,108,
	133,100,92,13,12,1,72,108,133,100,92,9,12,1,
	72,121,35,112,1,73,134,7,48,91,0,95,1,112,
	0,100,69,28,117,134,8,48,96,0,95,1,120,112,
	1,73,134,9,48,134,0,48,39,0,95,1,112,0,
	120,112,1,73,134,10,48,61,0,48,91,0,95,1,
	112,0,48,14,0,48,86,0,95,1,112,0,112,0,
	95,1,112,2,80,2,134,11,48,96,0,95,1,95,
	2,68,112,1,73,134,12,48,134,0,48,39,0,95,
	1,112,0,9,112,1,73,134,13,95,2,31,15,134,
	14,108,135,100,95,1,95,3,20,2,25,12,134,16,
	48,136,0,95,1,112,0,73,134,19,95,2,110,7
   };

   hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HRADIOBUTTON_VALID )
{
   static const BYTE pcode[] =
   {
	13,4,1,102,80,2,133,204,1,95,1,100,5,28,
	5,122,25,4,95,1,80,3,134,4,48,137,0,95,
	2,112,0,21,31,68,73,108,133,100,92,37,12,1,
	108,133,100,92,39,12,1,72,108,133,100,92,38,12,
	1,72,108,133,100,92,40,12,1,72,108,133,100,92,
	9,12,1,72,121,35,21,31,23,73,48,86,0,95,
	2,112,0,100,5,21,31,10,73,48,138,0,95,2,
	112,0,28,18,134,5,48,132,0,95,2,9,112,1,
	73,134,6,120,110,7,134,8,48,134,0,48,39,0,
	95,2,112,0,120,112,1,73,134,9,108,139,100,48,
	51,0,48,86,0,95,2,112,0,112,0,89,25,0,
	1,0,1,0,2,0,48,54,0,95,1,112,0,48,
	54,0,95,255,112,0,8,6,12,2,80,5,134,10,
	95,3,92,13,5,28,71,134,12,48,140,0,95,2,
	112,0,32,177,0,134,13,48,44,0,48,86,0,95,
	2,112,0,95,5,112,1,73,134,14,48,62,0,48,
	86,0,95,2,112,0,48,14,0,48,86,0,95,2,
	112,0,112,0,112,1,73,134,15,48,136,0,95,2,
	120,112,1,73,25,119,134,17,9,95,3,121,5,28,
	13,73,108,133,100,92,13,12,1,121,35,68,28,97,
	134,18,48,140,0,95,2,112,0,31,86,134,19,48,
	44,0,48,86,0,95,2,112,0,108,139,100,48,51,
	0,48,86,0,95,2,112,0,112,0,89,25,0,1,
	0,1,0,2,0,48,54,0,95,1,112,0,48,54,
	0,95,255,112,0,8,6,12,2,112,1,73,134,20,
	48,62,0,48,86,0,95,2,112,0,48,14,0,48,
	86,0,95,2,112,0,112,0,112,1,73,134,24,48,
	60,0,48,86,0,95,2,112,0,112,0,100,69,28,
	34,134,25,48,61,0,48,60,0,48,86,0,95,2,
	112,0,112,0,48,14,0,48,86,0,95,2,112,0,
	112,0,112,1,73,134,27,108,141,100,12,0,80,4,
	134,28,9,48,142,0,95,2,112,0,100,69,28,31,
	73,95,3,121,5,21,31,23,73,95,5,108,50,100,
	48,51,0,48,86,0,95,2,112,0,112,0,12,1,
	5,28,31,134,29,48,61,0,48,142,0,95,2,112,
	0,95,2,48,14,0,48,86,0,95,2,112,0,112,
	0,112,2,73,134,31,9,95,3,92,13,5,28,10,
	73,108,143,100,95,4,12,1,28,20,134,32,108,129,
	100,48,39,0,95,2,112,0,95,4,100,122,20,4,
	134,34,48,134,0,48,39,0,95,2,112,0,9,112,
	1,73,134,36,120,110,7
   };

   hb_vmExecute( pcode, symbols );
}

HB_FUNC_INITSTATICS()
{
   static const BYTE pcode[] =
   {
	117,144,0,2,0,7
   };

   hb_vmExecute( pcode, symbols );
}
