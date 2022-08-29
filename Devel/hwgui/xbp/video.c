/*
 * xHarbour 1.2.3 Intl. (SimpLex) (Build 20201212)
 * Generated C source code from <source\\video.prg>
 * Command: -oxbp\video.c -m -n -pOxbp\ -q -gc0 -Iinclude -Id:\devel\xharbour_bcc73\include source\video.prg 
 * Created: 2022.07.29 19:37:20 (Borland/Embarcadero C++ 7.3 (32-bit))
 */

#include "hbvmpub.h"
#include "hbinit.h"

#define __PRG_SOURCE__ "source\\video.prg"

/* Forward declarations of all PRG defined Functions. */
HB_FUNC( TVIDEO );
HB_FUNC_STATIC( TVIDEO_NEW );
HB_FUNC_STATIC( TVIDEO_REDEFINE );
HB_FUNC_STATIC( TVIDEO_INITIATE );
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
HB_FUNC_EXTERN( TMCI );
HB_FUNC_EXTERN( EMPTY );

#undef HB_PRG_PCODE_VER
#define HB_PRG_PCODE_VER 10

#include "hbapi.h"

HB_INIT_SYMBOLS_BEGIN( hb_vm_SymbolInit_VIDEO )
{ "DIVERTCONSTRUCTORCALL", {HB_FS_PUBLIC | HB_FS_DEFERRED}, {NULL}, NULL },
{ "TVIDEO", {HB_FS_PUBLIC | HB_FS_LOCAL}, {HB_FUNCNAME( TVIDEO )}, &ModuleFakeDyn },
{ "NEW", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "HBCLASS", {HB_FS_PUBLIC}, {HB_FUNCNAME( HBCLASS )}, NULL },
{ "CLASSH", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "HCONTROL", {HB_FS_PUBLIC}, {HB_FUNCNAME( HCONTROL )}, NULL },
{ "ADDMULTIDATA", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "ADDMETHOD", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "TVIDEO_NEW", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( TVIDEO_NEW )}, &ModuleFakeDyn },
{ "TVIDEO_REDEFINE", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( TVIDEO_REDEFINE )}, &ModuleFakeDyn },
{ "TVIDEO_INITIATE", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( TVIDEO_INITIATE )}, &ModuleFakeDyn },
{ "ADDINLINE", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "PLAY", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "OMCI", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "HANDLE", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "OPARENT", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "__CLSACTIVE", {HB_FS_PUBLIC}, {HB_FUNCNAME( __CLSACTIVE )}, NULL },
{ "HCLASS", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "REFRESH", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "CREATE", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "__CLSINST", {HB_FS_PUBLIC}, {HB_FUNCNAME( __CLSINST )}, NULL },
{ "__OBJHASMSG", {HB_FS_PUBLIC}, {HB_FUNCNAME( __OBJHASMSG )}, NULL },
{ "INITCLASS", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "HB_APARAMS", {HB_FS_PUBLIC}, {HB_FUNCNAME( HB_APARAMS )}, NULL },
{ "PCOUNT", {HB_FS_PUBLIC}, {HB_FUNCNAME( PCOUNT )}, NULL },
{ "_NTOP", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "_NLEFT", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "_NHEIGHT", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "NTOP", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "_NWIDTH", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "NLEFT", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "_STYLE", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "HWG_BITOR", {HB_FS_PUBLIC}, {HB_FUNCNAME( HWG_BITOR )}, NULL },
{ "_OPARENT", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "ODEFAULTPARENT", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "_ID", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "NEWID", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "_CAVIFILE", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "_OMCI", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "TMCI", {HB_FS_PUBLIC}, {HB_FUNCNAME( TMCI )}, NULL },
{ "INITIATE", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "EMPTY", {HB_FS_PUBLIC}, {HB_FUNCNAME( EMPTY )}, NULL },
{ "LOPEN", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "SETWINDOW", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "ADDCONTROL", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "_NID", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "_BWHEN", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "_BVALID", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "_OWND", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "INIT", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "HCONTROL", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "(_INITSTATICS00001)", {HB_FS_INITEXIT}, {hb_INITSTATICS}, &ModuleFakeDyn }
HB_INIT_SYMBOLS_EX_END( hb_vm_SymbolInit_VIDEO, __PRG_SOURCE__,  0x000a )

#if defined( HB_PRAGMA_STARTUP )
   #pragma startup hb_vm_SymbolInit_VIDEO
#elif defined( HB_DATASEG_STARTUP )
   #define HB_DATASEG_BODY    HB_DATASEG_FUNC( hb_vm_SymbolInit_VIDEO )
   #include "hbiniseg.h"
#endif

HB_FUNC( TVIDEO )
{
   static const BYTE pcode[] =
   {
	13,2,255,116,51,0,126,2,1,0,95,2,73,103,
	1,0,100,8,29,46,1,48,2,0,108,3,100,12,
	0,106,7,84,86,105,100,101,111,0,48,4,0,108,
	5,100,12,0,112,0,4,1,0,112,2,82,1,0,
	133,22,0,48,6,0,103,1,0,100,100,95,2,106,
	5,111,77,99,105,0,4,1,0,9,9,112,6,73,
	134,1,48,6,0,103,1,0,100,100,95,2,106,9,
	99,65,118,105,70,105,108,101,0,4,1,0,9,9,
	112,6,73,134,4,48,7,0,103,1,0,106,4,78,
	101,119,0,108,8,14,95,2,128,16,0,9,112,4,
	73,134,6,48,7,0,103,1,0,106,9,82,101,68,
	101,102,105,110,101,0,108,9,14,95,2,128,16,0,
	9,112,4,73,134,8,48,7,0,103,1,0,106,9,
	73,110,105,116,105,97,116,101,0,108,10,14,95,2,
	9,112,4,73,134,10,48,11,0,103,1,0,106,5,
	80,108,97,121,0,89,39,0,3,0,0,0,95,1,
	73,48,12,0,48,13,0,95,1,112,0,95,2,95,
	3,48,14,0,48,15,0,95,1,112,0,112,0,112,
	3,6,95,2,9,112,4,73,48,19,0,103,1,0,
	112,0,73,108,20,100,48,17,0,103,1,0,112,0,
	12,1,80,1,108,21,100,95,1,106,10,73,110,105,
	116,67,108,97,115,115,0,12,2,28,32,48,22,0,
	95,1,108,23,100,12,0,112,1,73,25,17,108,20,
	100,48,17,0,103,1,0,112,0,12,1,80,1,108,
	24,100,12,0,121,15,28,10,103,1,0,108,0,14,
	121,178,95,1,110,7
   };

   hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( TVIDEO_NEW )
{
   static const BYTE pcode[] =
   {
	13,1,8,102,80,9,133,41,0,95,3,100,8,28,
	6,126,3,200,0,95,4,100,8,28,6,126,4,200,
	0,95,5,100,8,28,7,127,5,1,0,0,95,7,
	100,8,28,5,9,80,7,134,2,48,25,0,95,9,
	95,1,92,14,65,112,1,73,134,3,48,26,0,95,
	9,95,2,92,8,65,112,1,73,134,4,48,27,0,
	95,9,48,28,0,95,9,112,0,95,4,72,128,255,
	255,112,1,73,134,5,48,29,0,95,9,48,30,0,
	95,9,112,0,95,3,72,128,1,0,112,1,73,134,
	6,48,31,0,95,9,108,32,100,97,0,0,1,80,
	95,7,31,9,97,0,0,128,0,25,3,121,12,2,
	112,1,73,134,8,48,33,0,95,9,95,6,100,8,
	28,11,48,34,0,95,9,112,0,25,4,95,6,112,
	1,73,134,9,48,35,0,95,9,95,8,100,8,28,
	11,48,36,0,95,9,112,0,25,4,95,8,112,1,
	73,134,10,48,37,0,95,9,95,5,112,1,73,134,
	11,48,38,0,95,9,48,2,0,108,39,100,12,0,
	106,9,97,118,105,118,105,100,101,111,0,95,5,112,
	2,112,1,73,134,12,48,40,0,95,9,112,0,73,
	134,14,108,41,100,48,14,0,48,15,0,95,9,112,
	0,112,0,12,1,31,36,134,15,48,42,0,48,13,
	0,95,9,112,0,112,0,73,134,16,48,43,0,48,
	13,0,95,9,112,0,95,9,112,1,73,25,19,134,
	18,48,44,0,48,15,0,95,9,112,0,95,9,112,
	1,73,134,21,95,9,110,7
   };

   hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( TVIDEO_REDEFINE )
{
   static const BYTE pcode[] =
   {
	13,1,5,102,80,6,133,68,0,48,45,0,95,6,
	95,1,112,1,73,134,1,48,37,0,95,6,95,2,
	112,1,73,134,2,48,46,0,95,6,95,4,112,1,
	73,134,3,48,47,0,95,6,95,5,112,1,73,134,
	4,48,48,0,95,6,95,3,112,1,73,134,5,48,
	38,0,95,6,48,2,0,108,39,100,12,0,106,9,
	97,118,105,118,105,100,101,111,0,95,2,112,2,112,
	1,73,134,7,48,44,0,95,3,95,6,112,1,73,
	134,9,95,6,110,7
   };

   hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( TVIDEO_INITIATE )
{
   static const BYTE pcode[] =
   {
	13,1,0,102,80,1,133,83,0,48,49,0,48,50,
	0,95,1,112,0,112,0,73,134,1,48,42,0,48,
	13,0,95,1,112,0,112,0,73,134,2,48,43,0,
	48,13,0,95,1,112,0,95,1,112,1,73,134,4,
	100,110,7
   };

   hb_vmExecute( pcode, symbols );
}

HB_FUNC_INITSTATICS()
{
   static const BYTE pcode[] =
   {
	117,51,0,1,0,7
   };

   hb_vmExecute( pcode, symbols );
}

