/*
 * xHarbour 1.2.3 Intl. (SimpLex) (Build 20201212)
 * Generated C source code from <source\\activex\\hhtml.prg>
 * Command: -oxbp\hhtml.c -m -n -pOxbp\ -q -gc0 -Iinclude -Id:\devel\xharbour_bcc73\include source\activex\hhtml.prg 
 * Created: 2022.07.29 19:37:44 (Borland/Embarcadero C++ 7.3 (32-bit))
 */

#include "hbvmpub.h"
#include "hbinit.h"

#define __PRG_SOURCE__ "source\\activex\\hhtml.prg"

/* Forward declarations of all PRG defined Functions. */
HB_FUNC( HHTML );
HB_FUNC_STATIC( HHTML_NEW );
HB_FUNC_STATIC( HHTML_ACTIVATE );
HB_FUNC_STATIC( HHTML_RESIZE );
HB_FUNC_STATIC( HHTML_END );
HB_FUNC_EXIT( EXITOLE );
HB_FUNC_INITSTATICS();

/* Forward declarations of all externally defined Functions. */
/* Skipped DEFERRED call to: 'DIVERTCONSTRUCTORCALL' */
HB_FUNC_EXTERN( HBCLASS );
HB_FUNC_EXTERN( HBOBJECT );
HB_FUNC_EXTERN( HWGAX_DISPLAYHTMLPAGE );
HB_FUNC_EXTERN( HWGAX_DISPLAYHTMLSTR );
HB_FUNC_EXTERN( HWGAX_DOPAGEACTION );
HB_FUNC_EXTERN( __CLSACTIVE );
HB_FUNC_EXTERN( __CLSINST );
HB_FUNC_EXTERN( __OBJHASMSG );
HB_FUNC_EXTERN( HB_APARAMS );
HB_FUNC_EXTERN( PCOUNT );
HB_FUNC_EXTERN( HWGAX_OLEINITIALIZE );
HB_FUNC_EXTERN( HWG_MSGSTOP );
HB_FUNC_EXTERN( EMPTY );
HB_FUNC_EXTERN( HWGAX_EMBEDBROWSEROBJECT );
HB_FUNC_EXTERN( HWGAX_RESIZEBROWSER );
HB_FUNC_EXTERN( HWGAX_UNEMBEDBROWSEROBJECT );
HB_FUNC_EXTERN( HWGAX_OLEUNINITIALIZE );

#undef HB_PRG_PCODE_VER
#define HB_PRG_PCODE_VER 10

#include "hbapi.h"

HB_INIT_SYMBOLS_BEGIN( hb_vm_SymbolInit_HHTML )
{ "DIVERTCONSTRUCTORCALL", {HB_FS_PUBLIC | HB_FS_DEFERRED}, {NULL}, NULL },
{ "HHTML", {HB_FS_PUBLIC | HB_FS_LOCAL}, {HB_FUNCNAME( HHTML )}, &ModuleFakeDyn },
{ "NEW", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "HBCLASS", {HB_FS_PUBLIC}, {HB_FUNCNAME( HBCLASS )}, NULL },
{ "CLASSH", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "HBOBJECT", {HB_FS_PUBLIC}, {HB_FUNCNAME( HBOBJECT )}, NULL },
{ "ADDMULTIDATA", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "ADDMETHOD", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "HHTML_NEW", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( HHTML_NEW )}, &ModuleFakeDyn },
{ "ADDINLINE", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "HWGAX_DISPLAYHTMLPAGE", {HB_FS_PUBLIC}, {HB_FUNCNAME( HWGAX_DISPLAYHTMLPAGE )}, NULL },
{ "HANDLE", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "OPARENT", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "HWGAX_DISPLAYHTMLSTR", {HB_FS_PUBLIC}, {HB_FUNCNAME( HWGAX_DISPLAYHTMLSTR )}, NULL },
{ "HHTML_ACTIVATE", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( HHTML_ACTIVATE )}, &ModuleFakeDyn },
{ "HHTML_RESIZE", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( HHTML_RESIZE )}, &ModuleFakeDyn },
{ "HWGAX_DOPAGEACTION", {HB_FS_PUBLIC}, {HB_FUNCNAME( HWGAX_DOPAGEACTION )}, NULL },
{ "HHTML_END", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( HHTML_END )}, &ModuleFakeDyn },
{ "__CLSACTIVE", {HB_FS_PUBLIC}, {HB_FUNCNAME( __CLSACTIVE )}, NULL },
{ "HCLASS", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "REFRESH", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "CREATE", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "__CLSINST", {HB_FS_PUBLIC}, {HB_FUNCNAME( __CLSINST )}, NULL },
{ "__OBJHASMSG", {HB_FS_PUBLIC}, {HB_FUNCNAME( __OBJHASMSG )}, NULL },
{ "INITCLASS", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "HB_APARAMS", {HB_FS_PUBLIC}, {HB_FUNCNAME( HB_APARAMS )}, NULL },
{ "PCOUNT", {HB_FS_PUBLIC}, {HB_FUNCNAME( PCOUNT )}, NULL },
{ "HWGAX_OLEINITIALIZE", {HB_FS_PUBLIC}, {HB_FUNCNAME( HWGAX_OLEINITIALIZE )}, NULL },
{ "HWG_MSGSTOP", {HB_FS_PUBLIC}, {HB_FUNCNAME( HWG_MSGSTOP )}, NULL },
{ "_OPARENT", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "ACTIVATE", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "EMPTY", {HB_FS_PUBLIC}, {HB_FUNCNAME( EMPTY )}, NULL },
{ "_OEMBEDDED", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "HWGAX_EMBEDBROWSEROBJECT", {HB_FS_PUBLIC}, {HB_FUNCNAME( HWGAX_EMBEDBROWSEROBJECT )}, NULL },
{ "HWGAX_RESIZEBROWSER", {HB_FS_PUBLIC}, {HB_FUNCNAME( HWGAX_RESIZEBROWSER )}, NULL },
{ "HWGAX_UNEMBEDBROWSEROBJECT", {HB_FS_PUBLIC}, {HB_FUNCNAME( HWGAX_UNEMBEDBROWSEROBJECT )}, NULL },
{ "EXITOLE$", {HB_FS_EXIT | HB_FS_LOCAL}, {HB_EXIT_FUNCNAME( EXITOLE )}, &ModuleFakeDyn },
{ "HWGAX_OLEUNINITIALIZE", {HB_FS_PUBLIC}, {HB_FUNCNAME( HWGAX_OLEUNINITIALIZE )}, NULL },
{ "(_INITSTATICS00001)", {HB_FS_INITEXIT}, {hb_INITSTATICS}, &ModuleFakeDyn }
HB_INIT_SYMBOLS_EX_END( hb_vm_SymbolInit_HHTML, __PRG_SOURCE__,  0x000a )

#if defined( HB_PRAGMA_STARTUP )
   #pragma startup hb_vm_SymbolInit_HHTML
#elif defined( HB_DATASEG_STARTUP )
   #define HB_DATASEG_BODY    HB_DATASEG_FUNC( hb_vm_SymbolInit_HHTML )
   #include "hbiniseg.h"
#endif

HB_FUNC( HHTML )
{
   static const BYTE pcode[] =
   {
	13,2,255,116,38,0,126,2,1,0,95,2,73,103,
	1,0,100,8,29,242,2,48,2,0,108,3,100,12,
	0,106,6,72,72,116,109,108,0,48,4,0,108,5,
	100,12,0,112,0,4,1,0,112,2,82,1,0,133,
	23,0,48,6,0,103,1,0,100,100,95,2,106,8,
	111,80,97,114,101,110,116,0,4,1,0,9,9,112,
	6,73,134,1,48,6,0,103,1,0,100,121,95,2,
	106,7,104,97,110,100,108,101,0,4,1,0,9,9,
	112,6,73,134,2,48,6,0,103,1,0,100,93,128,
	2,95,2,106,7,110,87,105,100,116,104,0,4,1,
	0,9,9,112,6,73,134,3,48,6,0,103,1,0,
	100,93,224,1,95,2,106,8,110,72,101,105,103,104,
	116,0,4,1,0,9,9,112,6,73,134,6,48,7,
	0,103,1,0,106,4,78,101,119,0,108,8,14,95,
	2,9,112,4,73,134,7,48,9,0,103,1,0,106,
	12,68,105,115,112,108,97,121,80,97,103,101,0,89,
	30,0,2,0,0,0,95,1,73,108,10,100,48,11,
	0,48,12,0,95,1,112,0,112,0,95,2,12,2,
	6,95,2,9,112,4,73,134,8,48,9,0,103,1,
	0,106,12,68,105,115,112,108,97,121,84,101,120,116,
	0,89,30,0,2,0,0,0,95,1,73,108,13,100,
	48,11,0,48,12,0,95,1,112,0,112,0,95,2,
	12,2,6,95,2,9,112,4,73,134,9,48,7,0,
	103,1,0,106,9,65,99,116,105,118,97,116,101,0,
	108,14,14,95,2,9,112,4,73,134,10,48,7,0,
	103,1,0,106,7,82,101,115,105,122,101,0,108,15,
	14,95,2,9,112,4,73,134,11,48,9,0,103,1,
	0,106,7,71,111,66,97,99,107,0,89,29,0,1,
	0,0,0,95,1,73,108,16,100,48,11,0,48,12,
	0,95,1,112,0,112,0,121,12,2,6,95,2,9,
	112,4,73,134,12,48,9,0,103,1,0,106,10,71,
	111,70,111,114,119,97,114,100,0,89,29,0,1,0,
	0,0,95,1,73,108,16,100,48,11,0,48,12,0,
	95,1,112,0,112,0,122,12,2,6,95,2,9,112,
	4,73,134,13,48,9,0,103,1,0,106,7,71,111,
	72,111,109,101,0,89,30,0,1,0,0,0,95,1,
	73,108,16,100,48,11,0,48,12,0,95,1,112,0,
	112,0,92,2,12,2,6,95,2,9,112,4,73,134,
	14,48,9,0,103,1,0,106,7,83,101,97,114,99,
	104,0,89,30,0,1,0,0,0,95,1,73,108,16,
	100,48,11,0,48,12,0,95,1,112,0,112,0,92,
	3,12,2,6,95,2,9,112,4,73,134,15,48,9,
	0,103,1,0,106,8,82,101,102,114,101,115,104,0,
	89,30,0,1,0,0,0,95,1,73,108,16,100,48,
	11,0,48,12,0,95,1,112,0,112,0,92,4,12,
	2,6,95,2,9,112,4,73,134,16,48,9,0,103,
	1,0,106,5,83,116,111,112,0,89,30,0,1,0,
	0,0,95,1,73,108,16,100,48,11,0,48,12,0,
	95,1,112,0,112,0,92,5,12,2,6,95,2,9,
	112,4,73,134,17,48,7,0,103,1,0,106,4,69,
	110,100,0,108,17,14,95,2,9,112,4,73,48,21,
	0,103,1,0,112,0,73,108,22,100,48,19,0,103,
	1,0,112,0,12,1,80,1,108,23,100,95,1,106,
	10,73,110,105,116,67,108,97,115,115,0,12,2,28,
	32,48,24,0,95,1,108,25,100,12,0,112,1,73,
	25,17,108,22,100,48,19,0,103,1,0,112,0,12,
	1,80,1,108,26,100,12,0,121,15,28,10,103,1,
	0,108,0,14,121,178,95,1,110,7
   };

   hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HHTML_NEW )
{
   static const BYTE pcode[] =
   {
	13,1,1,102,80,2,133,45,0,108,27,100,12,0,
	31,48,134,1,108,28,100,106,16,67,97,110,39,116,
	32,111,112,101,110,32,79,76,69,33,0,106,14,72,
	72,116,109,108,40,41,58,78,101,119,40,41,0,20,
	2,134,2,100,110,7,134,5,48,29,0,95,2,95,
	1,112,1,73,134,7,48,30,0,95,2,112,0,73,
	134,9,95,2,110,7
   };

   hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HHTML_ACTIVATE )
{
   static const BYTE pcode[] =
   {
	13,1,0,102,80,1,133,58,0,108,31,100,48,11,
	0,48,12,0,95,1,112,0,112,0,12,1,31,88,
	134,1,48,32,0,48,12,0,95,1,112,0,95,1,
	112,1,73,134,2,108,33,100,48,11,0,48,12,0,
	95,1,112,0,112,0,12,1,31,50,134,3,108,28,
	100,106,23,67,97,110,39,116,32,101,109,98,101,100,
	32,73,69,32,111,98,106,101,99,116,33,0,106,14,
	72,72,116,109,108,40,41,58,78,101,119,40,41,0,
	20,2,134,6,100,110,7
   };

   hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HHTML_RESIZE )
{
   static const BYTE pcode[] =
   {
	13,1,2,102,80,3,133,69,0,108,34,100,48,11,
	0,48,12,0,95,3,112,0,112,0,95,1,95,2,
	20,3,134,1,100,110,7
   };

   hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HHTML_END )
{
   static const BYTE pcode[] =
   {
	13,1,0,102,80,1,133,74,0,108,35,100,48,11,
	0,48,12,0,95,1,112,0,112,0,20,1,134,1,
	100,110,7
   };

   hb_vmExecute( pcode, symbols );
}

HB_FUNC_EXIT( EXITOLE )
{
   static const BYTE pcode[] =
   {
	133,78,0,108,37,100,20,0,134,1,7
   };

   hb_vmExecute( pcode, symbols );
}

HB_FUNC_INITSTATICS()
{
   static const BYTE pcode[] =
   {
	117,38,0,1,0,7
   };

   hb_vmExecute( pcode, symbols );
}
