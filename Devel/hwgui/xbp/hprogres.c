/*
 * xHarbour 1.2.3 Intl. (SimpLex) (Build 20201212)
 * Generated C source code from <source\\hprogres.prg>
 * Command: -oxbp\hprogres.c -m -n -pOxbp\ -q -gc0 -Iinclude -Id:\devel\xharbour_bcc73\include source\hprogres.prg 
 * Created: 2022.07.29 19:37:05 (Borland/Embarcadero C++ 7.3 (32-bit))
 */

#include "hbvmpub.h"
#include "hbinit.h"

#define __PRG_SOURCE__ "source\\hprogres.prg"

/* Forward declarations of all PRG defined Functions. */
HB_FUNC( HPROGRESSBAR );
HB_FUNC_STATIC( HPROGRESSBAR_NEW );
HB_FUNC_STATIC( HPROGRESSBAR_NEWBOX );
HB_FUNC_STATIC( HPROGRESSBAR_ACTIVATE );
HB_FUNC_STATIC( HPROGRESSBAR_INIT );
HB_FUNC_STATIC( HPROGRESSBAR_STEP );
HB_FUNC_STATIC( HPROGRESSBAR_SET );
HB_FUNC_STATIC( HPROGRESSBAR_SETLABEL );
HB_FUNC_STATIC( HPROGRESSBAR_SETANIMATION );
HB_FUNC_STATIC( HPROGRESSBAR_CLOSE );
HB_FUNC_INITSTATICS();

/* Forward declarations of all externally defined Functions. */
/* Skipped DEFERRED call to: 'DIVERTCONSTRUCTORCALL' */
HB_FUNC_EXTERN( HBCLASS );
HB_FUNC_EXTERN( HCONTROL );
HB_FUNC_EXTERN( UPDATEPROGRESSBAR );
HB_FUNC_EXTERN( DESTROYWINDOW );
HB_FUNC_EXTERN( __CLSACTIVE );
HB_FUNC_EXTERN( __CLSINST );
HB_FUNC_EXTERN( __OBJHASMSG );
HB_FUNC_EXTERN( HB_APARAMS );
HB_FUNC_EXTERN( PCOUNT );
HB_FUNC_EXTERN( INT );
HB_FUNC_EXTERN( HDIALOG );
HB_FUNC_EXTERN( HSTATIC );
HB_FUNC_EXTERN( EMPTY );
HB_FUNC_EXTERN( CREATEPROGRESSBAR );
HB_FUNC_EXTERN( SENDMESSAGE );
HB_FUNC_EXTERN( LTRIM );
HB_FUNC_EXTERN( STR );
HB_FUNC_EXTERN( SETWINDOWTEXT );
HB_FUNC_EXTERN( SETPROGRESSBAR );
HB_FUNC_EXTERN( MODIFYSTYLE );
HB_FUNC_EXTERN( HWG_BITAND );
HB_FUNC_EXTERN( ENDDIALOG );

#undef HB_PRG_PCODE_VER
#define HB_PRG_PCODE_VER 10

#include "hbapi.h"

HB_INIT_SYMBOLS_BEGIN( hb_vm_SymbolInit_HPROGRES )
{ "DIVERTCONSTRUCTORCALL", {HB_FS_PUBLIC | HB_FS_DEFERRED}, {NULL}, NULL },
{ "HPROGRESSBAR", {HB_FS_PUBLIC | HB_FS_LOCAL}, {HB_FUNCNAME( HPROGRESSBAR )}, &ModuleFakeDyn },
{ "NEW", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "HBCLASS", {HB_FS_PUBLIC}, {HB_FUNCNAME( HBCLASS )}, NULL },
{ "CLASSH", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "HCONTROL", {HB_FS_PUBLIC}, {HB_FUNCNAME( HCONTROL )}, NULL },
{ "ADDMULTICLSDATA", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "ADDMULTIDATA", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "ADDMETHOD", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "HPROGRESSBAR_NEW", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( HPROGRESSBAR_NEW )}, &ModuleFakeDyn },
{ "HPROGRESSBAR_NEWBOX", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( HPROGRESSBAR_NEWBOX )}, &ModuleFakeDyn },
{ "HPROGRESSBAR_INIT", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( HPROGRESSBAR_INIT )}, &ModuleFakeDyn },
{ "HPROGRESSBAR_ACTIVATE", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( HPROGRESSBAR_ACTIVATE )}, &ModuleFakeDyn },
{ "ADDINLINE", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "UPDATEPROGRESSBAR", {HB_FS_PUBLIC}, {HB_FUNCNAME( UPDATEPROGRESSBAR )}, NULL },
{ "HANDLE", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "HPROGRESSBAR_STEP", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( HPROGRESSBAR_STEP )}, &ModuleFakeDyn },
{ "HPROGRESSBAR_SET", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( HPROGRESSBAR_SET )}, &ModuleFakeDyn },
{ "HPROGRESSBAR_SETLABEL", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( HPROGRESSBAR_SETLABEL )}, &ModuleFakeDyn },
{ "HPROGRESSBAR_SETANIMATION", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( HPROGRESSBAR_SETANIMATION )}, &ModuleFakeDyn },
{ "HPROGRESSBAR_CLOSE", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( HPROGRESSBAR_CLOSE )}, &ModuleFakeDyn },
{ "DESTROYWINDOW", {HB_FS_PUBLIC}, {HB_FUNCNAME( DESTROYWINDOW )}, NULL },
{ "__CLSACTIVE", {HB_FS_PUBLIC}, {HB_FUNCNAME( __CLSACTIVE )}, NULL },
{ "HCLASS", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "REFRESH", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "CREATE", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "__CLSINST", {HB_FS_PUBLIC}, {HB_FUNCNAME( __CLSINST )}, NULL },
{ "__OBJHASMSG", {HB_FS_PUBLIC}, {HB_FUNCNAME( __OBJHASMSG )}, NULL },
{ "INITCLASS", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "HB_APARAMS", {HB_FS_PUBLIC}, {HB_FUNCNAME( HB_APARAMS )}, NULL },
{ "PCOUNT", {HB_FS_PUBLIC}, {HB_FUNCNAME( PCOUNT )}, NULL },
{ "_STYLE", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "STYLE", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "_NANIMATION", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "HCONTROL", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "_MAXPOS", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "_LNEWBOX", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "_NRANGE", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "_NLIMIT", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "INT", {HB_FS_PUBLIC}, {HB_FUNCNAME( INT )}, NULL },
{ "NRANGE", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "MAXPOS", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "ACTIVATE", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "_NLEFT", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "_NTOP", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "_NWIDTH", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "_LPERCENT", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "_OPARENT", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "HDIALOG", {HB_FS_PUBLIC}, {HB_FUNCNAME( HDIALOG )}, NULL },
{ "_LABELBOX", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "HSTATIC", {HB_FS_PUBLIC}, {HB_FUNCNAME( HSTATIC )}, NULL },
{ "NLEFT", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "NWIDTH", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "EMPTY", {HB_FS_PUBLIC}, {HB_FUNCNAME( EMPTY )}, NULL },
{ "_NAME", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "LABELBOX", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "_BDESTROY", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "OPARENT", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "_ID", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "NEWID", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "_NHEIGHT", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "ADDCONTROL", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "_HANDLE", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "CREATEPROGRESSBAR", {HB_FS_PUBLIC}, {HB_FUNCNAME( CREATEPROGRESSBAR )}, NULL },
{ "NTOP", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "NHEIGHT", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "INIT", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "LINIT", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "NANIMATION", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "SENDMESSAGE", {HB_FS_PUBLIC}, {HB_FUNCNAME( SENDMESSAGE )}, NULL },
{ "_NCOUNT", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "NCOUNT", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "NLIMIT", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "SET", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "LPERCENT", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "_NPERCENT", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "NPERCENT", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "SETLABEL", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "LTRIM", {HB_FS_PUBLIC}, {HB_FUNCNAME( LTRIM )}, NULL },
{ "STR", {HB_FS_PUBLIC}, {HB_FUNCNAME( STR )}, NULL },
{ "SETWINDOWTEXT", {HB_FS_PUBLIC}, {HB_FUNCNAME( SETWINDOWTEXT )}, NULL },
{ "SETPROGRESSBAR", {HB_FS_PUBLIC}, {HB_FUNCNAME( SETPROGRESSBAR )}, NULL },
{ "LNEWBOX", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "SETVALUE", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "MODIFYSTYLE", {HB_FS_PUBLIC}, {HB_FUNCNAME( MODIFYSTYLE )}, NULL },
{ "HWG_BITAND", {HB_FS_PUBLIC}, {HB_FUNCNAME( HWG_BITAND )}, NULL },
{ "ENDDIALOG", {HB_FS_PUBLIC}, {HB_FUNCNAME( ENDDIALOG )}, NULL },
{ "(_INITSTATICS00001)", {HB_FS_INITEXIT}, {hb_INITSTATICS}, &ModuleFakeDyn }
HB_INIT_SYMBOLS_EX_END( hb_vm_SymbolInit_HPROGRES, __PRG_SOURCE__,  0x000a )

#if defined( HB_PRAGMA_STARTUP )
   #pragma startup hb_vm_SymbolInit_HPROGRES
#elif defined( HB_DATASEG_STARTUP )
   #define HB_DATASEG_BODY    HB_DATASEG_FUNC( hb_vm_SymbolInit_HPROGRES )
   #include "hbiniseg.h"
#endif

HB_FUNC( HPROGRESSBAR )
{
   static const BYTE pcode[] =
   {
	13,2,255,116,87,0,126,2,1,0,95,2,73,103,
	1,0,100,8,29,11,3,48,2,0,108,3,100,12,
	0,106,13,72,80,114,111,103,114,101,115,115,66,97,
	114,0,48,4,0,108,5,100,12,0,112,0,4,1,
	0,112,2,82,1,0,133,18,0,48,6,0,103,1,
	0,100,106,18,109,115,99,116,108,115,95,112,114,111,
	103,114,101,115,115,51,50,0,95,2,106,9,119,105,
	110,99,108,97,115,115,0,4,1,0,9,112,5,73,
	134,1,48,7,0,103,1,0,100,100,95,2,106,7,
	109,97,120,80,111,115,0,4,1,0,9,9,112,6,
	73,134,2,48,7,0,103,1,0,100,100,95,2,106,
	7,110,82,97,110,103,101,0,4,1,0,9,9,112,
	6,73,134,3,48,7,0,103,1,0,100,100,95,2,
	106,8,108,78,101,119,66,111,120,0,4,1,0,9,
	9,112,6,73,134,4,48,7,0,103,1,0,100,121,
	95,2,106,7,110,67,111,117,110,116,0,4,1,0,
	9,9,112,6,73,134,5,48,7,0,103,1,0,100,
	100,95,2,106,7,110,76,105,109,105,116,0,4,1,
	0,9,9,112,6,73,134,6,48,7,0,103,1,0,
	100,100,95,2,106,11,110,65,110,105,109,97,116,105,
	111,110,0,4,1,0,9,9,112,6,73,134,7,48,
	7,0,103,1,0,100,100,95,2,106,9,76,97,98,
	101,108,66,111,120,0,4,1,0,9,9,112,6,73,
	134,8,48,7,0,103,1,0,100,121,95,2,106,9,
	110,80,101,114,99,101,110,116,0,4,1,0,9,9,
	112,6,73,134,9,48,7,0,103,1,0,100,9,95,
	2,106,9,108,80,101,114,99,101,110,116,0,4,1,
	0,9,9,112,6,73,134,11,48,8,0,103,1,0,
	106,4,78,101,119,0,108,9,14,95,2,9,112,4,
	73,134,12,48,8,0,103,1,0,106,7,78,101,119,
	66,111,120,0,108,10,14,95,2,9,112,4,73,134,
	13,48,8,0,103,1,0,106,5,73,110,105,116,0,
	108,11,14,95,2,9,112,4,73,134,14,48,8,0,
	103,1,0,106,9,65,99,116,105,118,97,116,101,0,
	108,12,14,95,2,9,112,4,73,134,15,48,13,0,
	103,1,0,106,10,73,110,99,114,101,109,101,110,116,
	0,89,23,0,1,0,0,0,95,1,73,108,14,100,
	48,15,0,95,1,112,0,12,1,6,95,2,9,112,
	4,73,134,16,48,8,0,103,1,0,106,5,83,84,
	69,80,0,108,16,14,95,2,9,112,4,73,134,17,
	48,8,0,103,1,0,106,4,83,69,84,0,108,17,
	14,95,2,9,112,4,73,134,18,48,8,0,103,1,
	0,106,9,83,101,116,76,97,98,101,108,0,108,18,
	14,95,2,9,112,4,73,134,19,48,8,0,103,1,
	0,106,13,83,101,116,65,110,105,109,97,116,105,111,
	110,0,108,19,14,92,33,9,112,4,73,48,8,0,
	103,1,0,106,14,95,83,101,116,65,110,105,109,97,
	116,105,111,110,0,108,19,14,112,2,73,134,20,48,
	8,0,103,1,0,106,6,67,108,111,115,101,0,108,
	20,14,95,2,9,112,4,73,134,21,48,13,0,103,
	1,0,106,4,69,110,100,0,89,23,0,1,0,0,
	0,95,1,73,108,21,100,48,15,0,95,1,112,0,
	12,1,6,95,2,9,112,4,73,48,25,0,103,1,
	0,112,0,73,108,26,100,48,23,0,103,1,0,112,
	0,12,1,80,1,108,27,100,95,1,106,10,73,110,
	105,116,67,108,97,115,115,0,12,2,28,32,48,28,
	0,95,1,108,29,100,12,0,112,1,73,25,17,108,
	26,100,48,23,0,103,1,0,112,0,12,1,80,1,
	108,30,100,12,0,121,15,28,10,103,1,0,108,0,
	14,121,178,95,1,110,7
   };

   hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HPROGRESSBAR_NEW )
{
   static const BYTE pcode[] =
   {
	13,1,14,102,80,15,133,45,0,48,31,0,95,15,
	9,95,14,100,69,28,5,73,95,14,28,6,92,4,
	25,3,121,112,1,73,134,1,48,31,0,95,15,48,
	32,0,95,15,112,0,9,95,13,100,69,28,7,73,
	95,13,121,15,28,6,92,8,25,3,121,72,112,1,
	73,134,2,48,33,0,95,15,95,13,112,1,73,134,
	4,48,2,0,48,34,0,95,15,112,0,95,1,95,
	2,48,32,0,95,15,112,0,95,3,95,4,95,5,
	95,6,100,95,9,95,10,95,11,95,12,112,12,73,
	134,6,48,35,0,95,15,9,95,7,100,69,28,7,
	73,95,7,121,69,28,6,95,7,25,4,92,20,112,
	1,73,134,7,48,36,0,95,15,9,112,1,73,134,
	8,48,37,0,95,15,9,95,8,100,69,28,7,73,
	95,8,121,69,28,6,95,8,25,4,92,100,112,1,
	73,134,9,48,38,0,95,15,108,39,100,48,40,0,
	95,15,112,0,48,41,0,95,15,112,0,18,12,1,
	112,1,73,134,11,48,42,0,95,15,112,0,73,134,
	13,95,15,110,7
   };

   hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HPROGRESSBAR_NEWBOX )
{
   static const BYTE pcode[] =
   {
	13,1,9,102,80,10,133,63,0,48,31,0,95,10,
	97,0,0,0,80,112,1,73,134,1,95,4,100,8,
	28,7,93,220,0,25,4,95,4,80,4,134,2,95,
	5,100,8,28,6,92,55,25,4,95,5,80,5,134,
	3,95,2,100,8,28,5,121,25,4,95,2,80,2,
	134,4,95,3,100,8,28,5,121,25,4,95,3,80,
	3,134,7,48,43,0,95,10,92,20,112,1,73,134,
	8,48,44,0,95,10,92,25,112,1,73,134,9,48,
	45,0,95,10,95,4,128,216,255,112,1,73,134,10,
	48,35,0,95,10,95,6,100,8,28,6,92,20,25,
	4,95,6,112,1,73,134,11,48,36,0,95,10,120,
	112,1,73,134,12,48,37,0,95,10,9,95,7,100,
	69,28,7,73,95,7,121,69,28,6,95,7,25,4,
	92,100,112,1,73,134,13,48,38,0,95,10,95,7,
	100,69,28,24,108,39,100,48,40,0,95,10,112,0,
	48,41,0,95,10,112,0,18,12,1,25,3,122,112,
	1,73,134,14,48,46,0,95,10,95,9,112,1,73,
	134,18,48,47,0,95,10,48,2,0,108,48,100,12,
	0,92,11,159,0,0,204,144,0,0,0,0,95,3,
	121,8,28,7,93,0,8,25,3,121,72,128,2,0,
	128,128,0,95,2,95,3,95,4,95,5,95,1,100,
	100,100,100,100,100,100,100,9,100,100,9,100,100,9,
	100,100,9,9,112,26,112,1,73,134,21,48,49,0,
	95,10,48,2,0,108,50,100,12,0,100,100,122,48,
	51,0,95,10,112,0,95,3,128,5,0,48,52,0,
	95,10,112,0,92,19,108,53,100,95,9,12,1,28,
	7,106,1,0,25,6,106,2,37,0,100,100,100,100,
	100,100,100,9,100,100,100,9,112,20,112,1,73,48,
	54,0,48,55,0,95,10,112,0,106,11,58,58,76,
	97,98,101,108,66,111,120,0,112,1,73,134,23,95,
	8,100,69,28,19,134,24,48,56,0,48,57,0,95,
	10,112,0,95,8,112,1,73,134,27,48,42,0,48,
	57,0,95,10,112,0,120,100,100,9,112,4,73,134,
	29,48,58,0,95,10,48,59,0,95,10,112,0,112,
	1,73,134,30,48,60,0,95,10,121,112,1,73,134,
	31,48,42,0,95,10,112,0,73,134,32,48,61,0,
	48,57,0,95,10,112,0,95,10,112,1,73,134,34,
	95,10,110,7
   };

   hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HPROGRESSBAR_ACTIVATE )
{
   static const BYTE pcode[] =
   {
	13,1,0,102,80,1,133,101,0,108,53,100,48,15,
	0,48,57,0,95,1,112,0,112,0,12,1,31,95,
	134,2,48,62,0,95,1,108,63,100,48,15,0,48,
	57,0,95,1,112,0,112,0,48,41,0,95,1,112,
	0,48,32,0,95,1,112,0,48,51,0,95,1,112,
	0,48,64,0,95,1,112,0,48,52,0,95,1,112,
	0,48,65,0,95,1,112,0,121,5,28,5,100,25,
	9,48,65,0,95,1,112,0,12,7,112,1,73,134,
	3,48,66,0,95,1,112,0,73,134,5,100,110,7
   };

   hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HPROGRESSBAR_INIT )
{
   static const BYTE pcode[] =
   {
	13,1,0,102,80,1,133,110,0,48,67,0,95,1,
	112,0,31,68,134,1,48,66,0,48,34,0,95,1,
	112,0,112,0,73,134,2,9,48,68,0,95,1,112,
	0,100,69,28,12,73,48,68,0,95,1,112,0,121,
	15,28,27,134,3,108,69,100,48,15,0,95,1,112,
	0,93,10,4,122,48,68,0,95,1,112,0,20,4,
	134,7,100,110,7
   };

   hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HPROGRESSBAR_STEP )
{
   static const BYTE pcode[] =
   {
	13,1,1,102,80,2,133,121,0,48,70,0,95,2,
	48,71,0,95,2,112,0,23,112,1,73,134,1,48,
	71,0,95,2,112,0,48,72,0,95,2,112,0,8,
	28,120,134,2,48,70,0,95,2,121,112,1,73,134,
	3,108,14,100,48,15,0,95,2,112,0,20,1,134,
	4,48,73,0,95,2,95,1,112,1,73,134,5,108,
	53,100,48,74,0,95,2,112,0,12,1,31,62,134,
	6,48,75,0,95,2,48,76,0,95,2,112,0,48,
	41,0,95,2,112,0,72,112,1,73,134,7,48,77,
	0,95,2,108,78,100,108,79,100,48,76,0,95,2,
	112,0,92,3,12,2,12,1,106,3,32,37,0,72,
	112,1,73,134,9,120,110,7,134,12,9,110,7
   };

   hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HPROGRESSBAR_SET )
{
   static const BYTE pcode[] =
   {
	13,1,2,102,80,3,133,137,0,95,1,100,69,28,
	23,134,1,108,80,100,48,15,0,48,57,0,95,3,
	112,0,112,0,95,1,20,2,134,3,95,2,100,69,
	28,18,134,4,108,81,100,48,15,0,95,3,112,0,
	95,2,20,2,134,7,100,110,7
   };

   hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HPROGRESSBAR_SETLABEL )
{
   static const BYTE pcode[] =
   {
	13,1,1,102,80,2,133,148,0,9,95,1,100,69,
	28,10,73,48,82,0,95,2,112,0,28,19,134,1,
	48,83,0,48,55,0,95,2,112,0,95,1,112,1,
	73,134,4,100,110,7
   };

   hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HPROGRESSBAR_SETANIMATION )
{
   static const BYTE pcode[] =
   {
	13,1,1,102,80,2,133,156,0,95,1,100,69,29,
	138,0,134,1,95,1,121,34,28,59,134,2,108,69,
	100,48,15,0,95,2,112,0,93,10,4,121,100,20,
	4,134,3,108,84,100,48,15,0,95,2,112,0,92,
	8,121,20,3,134,4,108,69,100,48,15,0,95,2,
	112,0,93,2,4,121,121,20,4,25,60,134,6,108,
	85,100,48,32,0,95,2,112,0,92,8,12,2,121,
	5,28,20,134,7,108,84,100,48,15,0,95,2,112,
	0,92,8,92,8,20,3,134,9,108,69,100,48,15,
	0,95,2,112,0,93,10,4,122,95,1,20,4,134,
	11,48,33,0,95,2,95,1,112,1,73,134,13,48,
	68,0,95,2,112,0,100,69,28,11,48,68,0,95,
	2,112,0,25,3,121,110,7
   };

   hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HPROGRESSBAR_CLOSE )
{
   static const BYTE pcode[] =
   {
	13,1,0,102,80,1,133,173,0,108,21,100,48,15,
	0,95,1,112,0,20,1,134,1,48,82,0,95,1,
	112,0,28,21,134,2,108,86,100,48,15,0,48,57,
	0,95,1,112,0,112,0,20,1,134,5,100,110,7
   };

   hb_vmExecute( pcode, symbols );
}

HB_FUNC_INITSTATICS()
{
   static const BYTE pcode[] =
   {
	117,87,0,1,0,7
   };

   hb_vmExecute( pcode, symbols );
}

