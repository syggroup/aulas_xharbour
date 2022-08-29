/*
 * xHarbour 1.2.3 Intl. (SimpLex) (Build 20201212)
 * Generated C source code from <source\\hnice.prg>
 * Command: -oxbp\hnice.c -m -n -pOxbp\ -q -gc0 -Iinclude -Id:\devel\xharbour_bcc73\include source\hnice.prg 
 * Created: 2022.07.29 19:37:03 (Borland/Embarcadero C++ 7.3 (32-bit))
 */

#include "hbvmpub.h"
#include "hbinit.h"

#define __PRG_SOURCE__ "source\\hnice.prg"

/* Forward declarations of all PRG defined Functions. */
HB_FUNC( HNICEBUTTON );
HB_FUNC_STATIC( HNICEBUTTON_NEW );
HB_FUNC_STATIC( HNICEBUTTON_REDEFINE );
HB_FUNC_STATIC( HNICEBUTTON_ACTIVATE );
HB_FUNC_STATIC( HNICEBUTTON_INIT );
HB_FUNC( NICEBUTTPROC );
HB_FUNC_STATIC( HNICEBUTTON_CREATE );
HB_FUNC_STATIC( HNICEBUTTON_SIZE );
HB_FUNC_STATIC( HNICEBUTTON_MOVING );
HB_FUNC_STATIC( HNICEBUTTON_MOUSEMOVE );
HB_FUNC_STATIC( HNICEBUTTON_MUP );
HB_FUNC_STATIC( HNICEBUTTON_MDOWN );
HB_FUNC_STATIC( HNICEBUTTON_PAINT );
HB_FUNC_STATIC( HNICEBUTTON_END );
HB_FUNC_STATIC( HNICEBUTTON_RELEASE );
HB_FUNC( SETNICEBTNSELECTED );
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
HB_FUNC_EXTERN( LEN );
HB_FUNC_EXTERN( HWG_REGNICE );
HB_FUNC_EXTERN( EMPTY );
HB_FUNC_EXTERN( CREATENICEBTN );
HB_FUNC_EXTERN( ASCAN );
HB_FUNC_EXTERN( FINDSELF );
HB_FUNC_EXTERN( GETCLIENTRECT );
HB_FUNC_EXTERN( CREATEROUNDRECTRGN );
HB_FUNC_EXTERN( SETWINDOWRGN );
HB_FUNC_EXTERN( INVALIDATERECT );
HB_FUNC_EXTERN( POSTMESSAGE );
HB_FUNC_EXTERN( DEFINEPAINTSTRU );
HB_FUNC_EXTERN( BEGINPAINT );
HB_FUNC_EXTERN( GETWINDOWTEXT );
HB_FUNC_EXTERN( GETTEXTSIZE );
HB_FUNC_EXTERN( DRAW_GRADIENT );
HB_FUNC_EXTERN( SETBKMODE );
HB_FUNC_EXTERN( SETTEXTCOLOR );
HB_FUNC_EXTERN( VCOLOR );
HB_FUNC_EXTERN( TEXTOUT );
HB_FUNC_EXTERN( ENDPAINT );

#undef HB_PRG_PCODE_VER
#define HB_PRG_PCODE_VER 10

#include "hbapi.h"

HB_INIT_SYMBOLS_BEGIN( hb_vm_SymbolInit_HNICE )
{ "DIVERTCONSTRUCTORCALL", {HB_FS_PUBLIC | HB_FS_DEFERRED}, {NULL}, NULL },
{ "HNICEBUTTON", {HB_FS_PUBLIC | HB_FS_LOCAL}, {HB_FUNCNAME( HNICEBUTTON )}, &ModuleFakeDyn },
{ "NEW", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "HBCLASS", {HB_FS_PUBLIC}, {HB_FUNCNAME( HBCLASS )}, NULL },
{ "CLASSH", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "HCONTROL", {HB_FS_PUBLIC}, {HB_FUNCNAME( HCONTROL )}, NULL },
{ "ADDMULTIDATA", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "ADDMULTICLSDATA", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "ADDMETHOD", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "HNICEBUTTON_NEW", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( HNICEBUTTON_NEW )}, &ModuleFakeDyn },
{ "HNICEBUTTON_REDEFINE", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( HNICEBUTTON_REDEFINE )}, &ModuleFakeDyn },
{ "HNICEBUTTON_ACTIVATE", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( HNICEBUTTON_ACTIVATE )}, &ModuleFakeDyn },
{ "HNICEBUTTON_INIT", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( HNICEBUTTON_INIT )}, &ModuleFakeDyn },
{ "HNICEBUTTON_CREATE", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( HNICEBUTTON_CREATE )}, &ModuleFakeDyn },
{ "HNICEBUTTON_SIZE", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( HNICEBUTTON_SIZE )}, &ModuleFakeDyn },
{ "HNICEBUTTON_MOVING", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( HNICEBUTTON_MOVING )}, &ModuleFakeDyn },
{ "HNICEBUTTON_PAINT", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( HNICEBUTTON_PAINT )}, &ModuleFakeDyn },
{ "HNICEBUTTON_MOUSEMOVE", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( HNICEBUTTON_MOUSEMOVE )}, &ModuleFakeDyn },
{ "HNICEBUTTON_MDOWN", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( HNICEBUTTON_MDOWN )}, &ModuleFakeDyn },
{ "HNICEBUTTON_MUP", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( HNICEBUTTON_MUP )}, &ModuleFakeDyn },
{ "ADDINLINE", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "_LPRESS", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "MDOWN", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "HNICEBUTTON_RELEASE", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( HNICEBUTTON_RELEASE )}, &ModuleFakeDyn },
{ "HNICEBUTTON_END", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( HNICEBUTTON_END )}, &ModuleFakeDyn },
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
{ "G", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "B", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "R", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "_LFLAT", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "_BCLICK", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "_NORDER", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "LEN", {HB_FS_PUBLIC}, {HB_FUNCNAME( LEN )}, NULL },
{ "ACONTROLS", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "_EXSTYLE", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "_TEXT", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "_R", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "_G", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "_B", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "_NTOP", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "_NLEFT", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "_NWIDTH", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "_NHEIGHT", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "HWG_REGNICE", {HB_FS_PUBLIC}, {HB_FUNCNAME( HWG_REGNICE )}, NULL },
{ "ACTIVATE", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "EMPTY", {HB_FS_PUBLIC}, {HB_FUNCNAME( EMPTY )}, NULL },
{ "HANDLE", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "OPARENT", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "_HANDLE", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "CREATENICEBTN", {HB_FS_PUBLIC}, {HB_FUNCNAME( CREATENICEBTN )}, NULL },
{ "ID", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "STYLE", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "NLEFT", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "NTOP", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "NWIDTH", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "NHEIGHT", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "EXSTYLE", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "TEXT", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "INIT", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "LINIT", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "NICEBUTTPROC", {HB_FS_PUBLIC | HB_FS_LOCAL | HB_FS_FIRST}, {HB_FUNCNAME( NICEBUTTPROC )}, &ModuleFakeDyn },
{ "ASCAN", {HB_FS_PUBLIC}, {HB_FUNCNAME( ASCAN )}, NULL },
{ "FINDSELF", {HB_FS_PUBLIC}, {HB_FUNCNAME( FINDSELF )}, NULL },
{ "PAINT", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "MUP", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "MOUSEMOVE", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "SIZE", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "END", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "GETCLIENTRECT", {HB_FS_PUBLIC}, {HB_FUNCNAME( GETCLIENTRECT )}, NULL },
{ "CREATEROUNDRECTRGN", {HB_FS_PUBLIC}, {HB_FUNCNAME( CREATEROUNDRECTRGN )}, NULL },
{ "SETWINDOWRGN", {HB_FS_PUBLIC}, {HB_FUNCNAME( SETWINDOWRGN )}, NULL },
{ "INVALIDATERECT", {HB_FS_PUBLIC}, {HB_FUNCNAME( INVALIDATERECT )}, NULL },
{ "_STATE", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "LFLAT", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "STATE", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "SETNICEBTNSELECTED", {HB_FS_PUBLIC | HB_FS_LOCAL}, {HB_FUNCNAME( SETNICEBTNSELECTED )}, &ModuleFakeDyn },
{ "LPRESS", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "POSTMESSAGE", {HB_FS_PUBLIC}, {HB_FUNCNAME( POSTMESSAGE )}, NULL },
{ "BCLICK", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "EVAL", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "DEFINEPAINTSTRU", {HB_FS_PUBLIC}, {HB_FUNCNAME( DEFINEPAINTSTRU )}, NULL },
{ "BEGINPAINT", {HB_FS_PUBLIC}, {HB_FUNCNAME( BEGINPAINT )}, NULL },
{ "GETWINDOWTEXT", {HB_FS_PUBLIC}, {HB_FUNCNAME( GETWINDOWTEXT )}, NULL },
{ "GETTEXTSIZE", {HB_FS_PUBLIC}, {HB_FUNCNAME( GETTEXTSIZE )}, NULL },
{ "DRAW_GRADIENT", {HB_FS_PUBLIC}, {HB_FUNCNAME( DRAW_GRADIENT )}, NULL },
{ "SETBKMODE", {HB_FS_PUBLIC}, {HB_FUNCNAME( SETBKMODE )}, NULL },
{ "SETTEXTCOLOR", {HB_FS_PUBLIC}, {HB_FUNCNAME( SETTEXTCOLOR )}, NULL },
{ "VCOLOR", {HB_FS_PUBLIC}, {HB_FUNCNAME( VCOLOR )}, NULL },
{ "TEXTOUT", {HB_FS_PUBLIC}, {HB_FUNCNAME( TEXTOUT )}, NULL },
{ "ENDPAINT", {HB_FS_PUBLIC}, {HB_FUNCNAME( ENDPAINT )}, NULL },
{ "OSELECTED", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "_OSELECTED", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "(_INITSTATICS00001)", {HB_FS_INITEXIT}, {hb_INITSTATICS}, &ModuleFakeDyn }
HB_INIT_SYMBOLS_EX_END( hb_vm_SymbolInit_HNICE, __PRG_SOURCE__,  0x000a )

#if defined( HB_PRAGMA_STARTUP )
   #pragma startup hb_vm_SymbolInit_HNICE
#elif defined( HB_DATASEG_STARTUP )
   #define HB_DATASEG_BODY    HB_DATASEG_FUNC( hb_vm_SymbolInit_HNICE )
   #include "hbiniseg.h"
#endif

HB_FUNC( HNICEBUTTON )
{
   static const BYTE pcode[] =
   {
	13,2,255,116,101,0,126,2,1,0,95,2,73,103,
	1,0,100,8,29,116,3,48,2,0,108,3,100,12,
	0,106,12,72,78,105,99,101,66,117,116,116,111,110,
	0,48,4,0,108,5,100,12,0,112,0,4,1,0,
	112,2,82,1,0,133,21,0,48,6,0,103,1,0,
	100,106,9,78,73,67,69,66,85,84,84,0,95,2,
	106,9,119,105,110,99,108,97,115,115,0,4,1,0,
	9,9,112,6,73,134,1,48,6,0,103,1,0,100,
	100,95,2,106,5,84,69,88,84,0,106,3,105,100,
	0,106,5,110,84,111,112,0,106,6,110,76,101,102,
	116,0,106,7,110,119,105,100,116,104,0,106,8,110,
	104,101,105,103,104,116,0,4,6,0,9,9,112,6,
	73,134,2,48,7,0,103,1,0,100,100,95,2,128,
	64,0,106,10,111,83,101,108,101,99,116,101,100,0,
	4,1,0,9,112,5,73,134,3,48,6,0,103,1,
	0,100,121,95,2,106,6,83,116,97,116,101,0,4,
	1,0,9,9,112,6,73,134,4,48,6,0,103,1,
	0,100,100,95,2,106,8,69,120,83,116,121,108,101,
	0,4,1,0,9,9,112,6,73,134,5,48,6,0,
	103,1,0,100,100,95,2,106,7,98,67,108,105,99,
	107,0,106,9,99,84,111,111,108,116,105,112,0,4,
	2,0,9,9,112,6,73,134,7,48,6,0,103,1,
	0,100,9,95,2,106,7,108,80,114,101,115,115,0,
	4,1,0,9,9,112,6,73,134,8,48,6,0,103,
	1,0,100,92,30,95,2,106,2,114,0,4,1,0,
	9,9,112,6,73,134,9,48,6,0,103,1,0,100,
	92,90,95,2,106,2,103,0,4,1,0,9,9,112,
	6,73,134,10,48,6,0,103,1,0,100,92,90,95,
	2,106,2,98,0,4,1,0,9,9,112,6,73,134,
	11,48,6,0,103,1,0,100,100,95,2,106,6,108,
	70,108,97,116,0,4,1,0,9,9,112,6,73,134,
	12,48,6,0,103,1,0,100,100,95,2,106,7,110,
	79,114,100,101,114,0,4,1,0,9,9,112,6,73,
	134,16,48,8,0,103,1,0,106,4,78,101,119,0,
	108,9,14,95,2,9,112,4,73,134,20,48,8,0,
	103,1,0,106,9,82,101,100,101,102,105,110,101,0,
	108,10,14,95,2,9,112,4,73,134,22,48,8,0,
	103,1,0,106,9,65,99,116,105,118,97,116,101,0,
	108,11,14,95,2,9,112,4,73,134,23,48,8,0,
	103,1,0,106,5,73,78,73,84,0,108,12,14,95,
	2,9,112,4,73,134,24,48,8,0,103,1,0,106,
	7,67,114,101,97,116,101,0,108,13,14,95,2,9,
	112,4,73,134,25,48,8,0,103,1,0,106,5,83,
	105,122,101,0,108,14,14,95,2,9,112,4,73,134,
	26,48,8,0,103,1,0,106,7,77,111,118,105,110,
	103,0,108,15,14,95,2,9,112,4,73,134,27,48,
	8,0,103,1,0,106,6,80,97,105,110,116,0,108,
	16,14,95,2,9,112,4,73,134,28,48,8,0,103,
	1,0,106,10,77,111,117,115,101,77,111,118,101,0,
	108,17,14,95,2,9,112,4,73,134,29,48,8,0,
	103,1,0,106,6,77,68,111,119,110,0,108,18,14,
	95,2,9,112,4,73,134,30,48,8,0,103,1,0,
	106,4,77,85,112,0,108,19,14,95,2,9,112,4,
	73,134,31,48,20,0,103,1,0,106,6,80,114,101,
	115,115,0,89,27,0,1,0,0,0,95,1,73,48,
	21,0,95,1,120,112,1,73,48,22,0,95,1,112,
	0,6,95,2,9,112,4,73,134,32,48,8,0,103,
	1,0,106,8,82,69,76,69,65,83,69,0,108,23,
	14,95,2,9,112,4,73,134,33,48,8,0,103,1,
	0,106,4,69,78,68,0,108,24,14,95,2,9,112,
	4,73,48,28,0,103,1,0,112,0,73,108,29,100,
	48,26,0,103,1,0,112,0,12,1,80,1,108,30,
	100,95,1,106,10,73,110,105,116,67,108,97,115,115,
	0,12,2,28,32,48,31,0,95,1,108,32,100,12,
	0,112,1,73,25,17,108,29,100,48,26,0,103,1,
	0,112,0,12,1,80,1,108,33,100,12,0,121,15,
	28,10,103,1,0,108,0,14,121,178,95,1,110,7
   };

   hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HNICEBUTTON_NEW )
{
   static const BYTE pcode[] =
   {
	13,1,15,102,80,16,133,62,0,48,2,0,48,34,
	0,95,16,112,0,95,1,95,2,95,3,95,5,95,
	6,95,7,95,8,100,95,9,100,100,95,12,112,12,
	73,134,1,95,14,100,8,28,11,48,35,0,95,16,
	112,0,25,4,95,14,80,14,95,15,100,8,28,11,
	48,36,0,95,16,112,0,25,4,95,15,80,15,95,
	13,100,8,28,11,48,37,0,95,16,112,0,25,4,
	95,13,80,13,48,38,0,95,16,120,112,1,73,134,
	6,48,39,0,95,16,95,10,112,1,73,134,7,48,
	40,0,95,16,95,1,100,8,28,5,121,25,14,108,
	41,100,48,42,0,95,1,112,0,12,1,112,1,73,
	134,9,48,43,0,95,16,95,4,112,1,73,134,10,
	48,44,0,95,16,95,11,112,1,73,134,11,48,45,
	0,95,16,95,13,112,1,73,134,12,48,46,0,95,
	16,95,14,112,1,73,134,13,48,47,0,95,16,95,
	15,112,1,73,134,14,48,48,0,95,16,95,6,112,
	1,73,134,15,48,49,0,95,16,95,5,112,1,73,
	134,16,48,50,0,95,16,95,7,112,1,73,134,17,
	48,51,0,95,16,95,8,112,1,73,134,19,108,52,
	100,20,0,134,20,48,53,0,95,16,112,0,73,134,
	22,95,16,110,7
   };

   hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HNICEBUTTON_REDEFINE )
{
   static const BYTE pcode[] =
   {
	13,1,10,102,80,11,133,91,0,48,2,0,48,34,
	0,95,11,112,0,95,1,95,2,121,121,121,121,121,
	100,95,4,100,100,95,7,112,12,73,134,2,95,9,
	100,8,28,11,48,35,0,95,11,112,0,25,4,95,
	9,80,9,95,10,100,8,28,11,48,36,0,95,11,
	112,0,25,4,95,10,80,10,95,8,100,8,28,11,
	48,37,0,95,11,112,0,25,4,95,8,80,8,48,
	38,0,95,11,120,112,1,73,134,8,48,39,0,95,
	11,95,5,112,1,73,134,10,48,43,0,95,11,95,
	3,112,1,73,134,11,48,44,0,95,11,95,6,112,
	1,73,134,12,48,45,0,95,11,95,8,112,1,73,
	134,13,48,46,0,95,11,95,9,112,1,73,134,14,
	48,47,0,95,11,95,10,112,1,73,134,16,108,52,
	100,20,0,134,18,95,11,110,7
   };

   hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HNICEBUTTON_ACTIVATE )
{
   static const BYTE pcode[] =
   {
	13,1,0,102,80,1,133,113,0,108,54,100,48,55,
	0,48,56,0,95,1,112,0,112,0,12,1,31,95,
	134,2,48,57,0,95,1,108,58,100,48,55,0,48,
	56,0,95,1,112,0,112,0,48,59,0,95,1,112,
	0,48,60,0,95,1,112,0,48,61,0,95,1,112,
	0,48,62,0,95,1,112,0,48,63,0,95,1,112,
	0,48,64,0,95,1,112,0,48,65,0,95,1,112,
	0,48,66,0,95,1,112,0,12,9,112,1,73,134,
	3,48,67,0,95,1,112,0,73,134,5,100,110,7
   };

   hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HNICEBUTTON_INIT )
{
   static const BYTE pcode[] =
   {
	13,1,0,102,80,1,133,122,0,48,68,0,95,1,
	112,0,31,27,134,1,48,67,0,48,34,0,95,1,
	112,0,112,0,73,134,2,48,28,0,95,1,112,0,
	73,134,4,100,110,7
   };

   hb_vmExecute( pcode, symbols );
}

HB_FUNC( NICEBUTTPROC )
{
   static const BYTE pcode[] =
   {
	13,1,4,133,131,0,95,2,122,69,29,198,0,134,
	1,108,70,100,93,0,2,92,15,93,1,2,93,2,
	2,93,3,2,92,2,93,22,2,92,5,4,8,0,
	95,2,12,2,121,15,29,160,0,134,2,108,71,100,
	95,1,12,1,21,80,5,100,8,28,7,134,3,9,
	110,7,134,6,95,2,92,15,8,28,14,134,7,48,
	72,0,95,5,112,0,73,25,117,134,8,95,2,93,
	2,2,8,28,14,134,9,48,73,0,95,5,112,0,
	73,25,95,134,10,95,2,93,1,2,8,28,14,134,
	11,48,22,0,95,5,112,0,73,25,73,134,12,95,
	2,93,0,2,8,28,18,134,13,48,74,0,95,5,
	95,3,95,4,112,2,73,25,47,134,14,95,2,92,
	5,8,28,14,134,15,48,75,0,95,5,112,0,73,
	25,26,134,17,95,2,92,2,8,28,17,134,18,48,
	76,0,95,5,112,0,73,134,19,120,110,7,134,24,
	9,110,7
   };

   hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HNICEBUTTON_CREATE )
{
   static const BYTE pcode[] =
   {
	13,5,0,102,80,1,133,164,0,108,77,100,48,55,
	0,95,1,112,0,12,1,80,3,134,1,95,3,92,
	3,1,95,3,122,1,49,80,4,134,2,95,3,92,
	4,1,95,3,92,2,1,49,80,5,134,3,108,78,
	100,121,121,95,4,95,5,95,5,101,205,204,204,204,
	204,204,236,63,10,2,65,95,5,101,205,204,204,204,
	204,204,236,63,10,2,65,12,6,80,2,134,4,108,
	79,100,48,55,0,95,1,112,0,95,2,120,20,3,
	134,5,108,80,100,48,55,0,95,1,112,0,121,121,
	20,3,134,7,95,1,110,7
   };

   hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HNICEBUTTON_SIZE )
{
   static const BYTE pcode[] =
   {
	13,1,0,102,80,1,133,175,0,48,81,0,95,1,
	122,112,1,73,134,1,108,80,100,48,55,0,95,1,
	112,0,121,121,20,3,134,3,95,1,110,7
   };

   hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HNICEBUTTON_MOVING )
{
   static const BYTE pcode[] =
   {
	13,1,0,102,80,1,133,182,0,48,81,0,95,1,
	9,112,1,73,134,1,108,80,100,48,55,0,95,1,
	112,0,121,121,20,3,134,3,95,1,110,7
   };

   hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HNICEBUTTON_MOUSEMOVE )
{
   static const BYTE pcode[] =
   {
	13,2,2,102,80,3,133,191,0,95,1,80,1,134,
	1,95,2,80,2,134,3,9,48,82,0,95,3,112,
	0,28,12,73,48,83,0,95,3,112,0,121,69,29,
	170,0,134,4,108,84,100,12,0,80,4,134,6,9,
	95,4,100,69,28,30,73,9,48,59,0,95,4,112,
	0,48,59,0,95,3,112,0,69,28,11,73,48,85,
	0,95,4,112,0,68,28,54,134,7,48,81,0,95,
	4,122,112,1,73,134,8,108,80,100,48,55,0,95,
	4,112,0,121,20,2,134,9,108,86,100,48,55,0,
	95,4,112,0,92,15,121,121,20,4,134,10,108,84,
	100,100,20,1,134,13,48,83,0,95,3,112,0,122,
	8,28,56,134,14,48,81,0,95,3,92,2,112,1,
	73,134,17,108,80,100,48,55,0,95,3,112,0,121,
	20,2,134,18,108,86,100,48,55,0,95,3,112,0,
	92,15,121,121,20,4,134,19,108,84,100,95,3,20,
	1,134,23,95,3,110,7
   };

   hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HNICEBUTTON_MUP )
{
   static const BYTE pcode[] =
   {
	13,1,0,102,80,1,133,218,0,48,83,0,95,1,
	112,0,92,3,8,29,132,0,134,1,48,85,0,95,
	1,112,0,31,59,134,2,48,81,0,95,1,48,82,
	0,95,1,112,0,28,6,92,2,25,3,122,112,1,
	73,134,3,108,80,100,48,55,0,95,1,112,0,121,
	20,2,134,4,108,86,100,48,55,0,95,1,112,0,
	92,15,121,121,20,4,134,6,48,82,0,95,1,112,
	0,31,10,134,7,108,84,100,100,20,1,134,9,48,
	87,0,95,1,112,0,100,69,28,31,134,10,48,88,
	0,48,87,0,95,1,112,0,48,56,0,95,1,112,
	0,48,59,0,95,1,112,0,112,2,73,134,14,95,
	1,110,7
   };

   hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HNICEBUTTON_MDOWN )
{
   static const BYTE pcode[] =
   {
	13,1,0,102,80,1,133,236,0,48,83,0,95,1,
	112,0,92,3,69,28,57,134,1,48,81,0,95,1,
	92,3,112,1,73,134,3,108,80,100,48,55,0,95,
	1,112,0,121,121,20,3,134,4,108,86,100,48,55,
	0,95,1,112,0,92,15,121,121,20,4,134,5,108,
	84,100,95,1,20,1,134,8,95,1,110,7
   };

   hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HNICEBUTTON_PAINT )
{
   static const BYTE pcode[] =
   {
	13,12,0,102,80,1,133,248,0,108,89,100,12,0,
	80,2,134,1,108,90,100,48,55,0,95,1,112,0,
	95,2,12,2,80,3,134,13,108,77,100,48,55,0,
	95,1,112,0,12,1,80,4,134,14,95,4,122,1,
	80,9,134,15,95,4,92,2,1,80,10,134,16,95,
	4,92,3,1,95,4,122,1,49,80,11,134,17,95,
	4,92,4,1,95,4,92,2,1,49,80,12,134,18,
	95,4,122,1,95,4,92,3,1,72,92,2,18,80,
	7,134,19,95,4,92,2,1,95,4,92,4,1,72,
	92,2,18,80,8,134,20,108,91,100,48,55,0,95,
	1,112,0,12,1,80,6,134,25,48,83,0,95,1,
	112,0,121,8,28,13,134,26,48,81,0,95,1,122,
	112,1,73,134,29,108,92,100,95,3,95,6,12,2,
	80,5,134,31,108,93,100,95,3,95,9,95,10,95,
	11,95,12,48,37,0,95,1,112,0,48,35,0,95,
	1,112,0,48,36,0,95,1,112,0,20,8,134,32,
	108,94,100,95,3,122,20,2,134,34,48,83,0,95,
	1,112,0,92,2,8,28,65,134,35,108,95,100,95,
	3,108,96,100,106,7,70,70,48,48,48,48,0,12,
	1,20,2,134,36,108,97,100,95,3,95,7,95,5,
	122,1,92,2,18,49,128,1,0,95,8,95,5,92,
	2,1,92,2,18,49,128,1,0,95,6,20,4,25,
	57,134,38,108,95,100,95,3,108,96,100,106,7,48,
	48,48,48,70,70,0,12,1,20,2,134,39,108,97,
	100,95,3,95,7,95,5,122,1,92,2,18,49,95,
	8,95,5,92,2,1,92,2,18,49,95,6,20,4,
	134,42,108,98,100,48,55,0,95,1,112,0,95,2,
	20,2,134,44,95,1,110,7
   };

   hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HNICEBUTTON_END )
{
   static const BYTE pcode[] =
   {
	13,1,0,102,80,1,133,40,1,100,110,7
   };

   hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HNICEBUTTON_RELEASE )
{
   static const BYTE pcode[] =
   {
	13,1,0,102,80,1,133,44,1,48,21,0,95,1,
	9,112,1,73,134,1,48,81,0,95,1,122,112,1,
	73,134,2,108,80,100,48,55,0,95,1,112,0,121,
	20,2,134,3,108,86,100,48,55,0,95,1,112,0,
	92,15,121,121,20,4,134,5,100,110,7
   };

   hb_vmExecute( pcode, symbols );
}

HB_FUNC( SETNICEBTNSELECTED )
{
   static const BYTE pcode[] =
   {
	13,1,1,133,53,1,48,99,0,108,1,100,12,0,
	112,0,80,2,134,2,108,33,100,12,0,121,15,28,
	17,134,3,48,100,0,108,1,100,12,0,95,1,112,
	1,73,134,6,95,2,110,7
   };

   hb_vmExecute( pcode, symbols );
}

HB_FUNC_INITSTATICS()
{
   static const BYTE pcode[] =
   {
	117,101,0,1,0,7
   };

   hb_vmExecute( pcode, symbols );
}

