/*
 * xHarbour 1.2.3 Intl. (SimpLex) (Build 20201212)
 * Generated C source code from <source\\procmisc\\procs7.prg>
 * Command: -oxbp\procs7.c -m -n -pOxbp\ -q -gc0 -Iinclude -Id:\devel\xharbour_bcc73\include source\procmisc\procs7.prg 
 * Created: 2022.07.29 19:37:22 (Borland/Embarcadero C++ 7.3 (32-bit))
 */

#include "hbvmpub.h"
#include "hbinit.h"

#define __PRG_SOURCE__ "source\\procmisc\\procs7.prg"

/* Forward declarations of all PRG defined Functions. */
HB_FUNC( RDSTR );
HB_FUNC( GETNEXTVAR );
HB_FUNC( FIND_Z );
HB_FUNC( CUTEXTEN );
HB_FUNC( FILEXTEN );
HB_FUNC( FILEPATH );
HB_FUNC( CUTPATH );
HB_FUNC( NEXTITEM );
HB_FUNC_INITSTATICS();

/* Forward declarations of all externally defined Functions. */
HB_FUNC_EXTERN( AT );
HB_FUNC_EXTERN( SUBSTR );
HB_FUNC_EXTERN( FREAD );
HB_FUNC_EXTERN( RTRIM );
HB_FUNC_EXTERN( LEN );
HB_FUNC_EXTERN( EMPTY );
HB_FUNC_EXTERN( LEFT );
HB_FUNC_EXTERN( LTRIM );
HB_FUNC_EXTERN( RAT );

#undef HB_PRG_PCODE_VER
#define HB_PRG_PCODE_VER 10

#include "hbapi.h"

HB_INIT_SYMBOLS_BEGIN( hb_vm_SymbolInit_PROCS7 )
{ "RDSTR", {HB_FS_PUBLIC | HB_FS_LOCAL | HB_FS_FIRST}, {HB_FUNCNAME( RDSTR )}, &ModuleFakeDyn },
{ "AT", {HB_FS_PUBLIC}, {HB_FUNCNAME( AT )}, NULL },
{ "SUBSTR", {HB_FS_PUBLIC}, {HB_FUNCNAME( SUBSTR )}, NULL },
{ "FREAD", {HB_FS_PUBLIC}, {HB_FUNCNAME( FREAD )}, NULL },
{ "RTRIM", {HB_FS_PUBLIC}, {HB_FUNCNAME( RTRIM )}, NULL },
{ "LEN", {HB_FS_PUBLIC}, {HB_FUNCNAME( LEN )}, NULL },
{ "GETNEXTVAR", {HB_FS_PUBLIC | HB_FS_LOCAL}, {HB_FUNCNAME( GETNEXTVAR )}, &ModuleFakeDyn },
{ "EMPTY", {HB_FS_PUBLIC}, {HB_FUNCNAME( EMPTY )}, NULL },
{ "FIND_Z", {HB_FS_PUBLIC | HB_FS_LOCAL}, {HB_FUNCNAME( FIND_Z )}, &ModuleFakeDyn },
{ "LEFT", {HB_FS_PUBLIC}, {HB_FUNCNAME( LEFT )}, NULL },
{ "LTRIM", {HB_FS_PUBLIC}, {HB_FUNCNAME( LTRIM )}, NULL },
{ "CUTEXTEN", {HB_FS_PUBLIC | HB_FS_LOCAL}, {HB_FUNCNAME( CUTEXTEN )}, &ModuleFakeDyn },
{ "RAT", {HB_FS_PUBLIC}, {HB_FUNCNAME( RAT )}, NULL },
{ "FILEXTEN", {HB_FS_PUBLIC | HB_FS_LOCAL}, {HB_FUNCNAME( FILEXTEN )}, &ModuleFakeDyn },
{ "FILEPATH", {HB_FS_PUBLIC | HB_FS_LOCAL}, {HB_FUNCNAME( FILEPATH )}, &ModuleFakeDyn },
{ "CUTPATH", {HB_FS_PUBLIC | HB_FS_LOCAL}, {HB_FUNCNAME( CUTPATH )}, &ModuleFakeDyn },
{ "NEXTITEM", {HB_FS_PUBLIC | HB_FS_LOCAL}, {HB_FUNCNAME( NEXTITEM )}, &ModuleFakeDyn },
{ "(_INITSTATICS00001)", {HB_FS_INITEXIT}, {hb_INITSTATICS}, &ModuleFakeDyn }
HB_INIT_SYMBOLS_EX_END( hb_vm_SymbolInit_PROCS7, __PRG_SOURCE__,  0x000a )

#if defined( HB_PRAGMA_STARTUP )
   #pragma startup hb_vm_SymbolInit_PROCS7
#elif defined( HB_DATASEG_STARTUP )
   #define HB_DATASEG_BODY    HB_DATASEG_FUNC( hb_vm_SymbolInit_PROCS7 )
   #include "hbiniseg.h"
#endif

HB_FUNC( RDSTR )
{
   static const BYTE pcode[] =
   {
	13,4,4,133,12,0,127,5,1,0,0,134,2,95,
	3,80,7,134,3,108,1,100,106,2,10,0,108,2,
	100,95,2,95,3,12,2,12,2,80,3,134,4,95,
	3,121,5,29,171,0,134,5,95,1,100,69,28,110,
	134,6,108,2,100,95,2,95,7,12,2,167,5,134,
	7,108,3,100,95,1,96,2,0,95,4,12,3,80,
	6,134,8,95,6,121,5,28,9,134,9,106,1,0,
	110,7,134,10,95,6,95,4,35,28,26,134,11,108,
	2,100,95,2,122,95,6,12,3,106,2,10,0,72,
	106,2,13,0,72,80,2,134,13,108,1,100,106,2,
	10,0,95,2,12,2,80,3,134,14,108,2,100,95,
	2,122,95,3,12,3,167,5,25,78,134,16,108,4,
	100,108,2,100,95,2,95,7,12,2,12,1,167,5,
	134,17,95,7,108,5,100,95,5,12,1,72,80,3,
	134,18,108,5,100,95,5,12,1,121,8,28,33,134,
	19,106,1,0,110,7,134,23,108,2,100,95,2,95,
	7,95,3,12,3,167,5,134,24,95,7,128,255,255,
	167,3,134,26,173,3,134,27,108,5,100,95,5,12,
	1,80,8,134,28,9,95,8,92,2,15,28,14,73,
	95,5,130,1,0,106,3,13,10,0,24,28,41,134,
	29,95,5,95,8,128,255,255,1,106,3,13,10,0,
	24,28,6,134,30,174,8,134,32,108,2,100,95,5,
	122,95,8,128,255,255,12,3,80,5,134,34,95,5,
	110,7
   };

   hb_vmExecute( pcode, symbols );
}

HB_FUNC( GETNEXTVAR )
{
   static const BYTE pcode[] =
   {
	13,3,2,133,51,0,108,7,100,95,1,12,1,28,
	9,134,1,106,1,0,110,7,134,3,108,8,100,95,
	1,12,1,21,80,4,121,8,28,37,134,4,95,1,
	130,1,0,106,2,59,0,5,28,11,108,5,100,95,
	1,12,1,25,12,108,5,100,95,1,12,1,128,1,
	0,80,4,134,6,108,8,100,108,9,100,95,1,95,
	4,128,255,255,12,2,106,2,58,0,12,2,80,5,
	134,7,108,4,100,108,10,100,108,9,100,95,1,95,
	5,121,5,28,6,95,4,25,4,95,5,128,255,255,
	12,2,12,1,12,1,80,3,134,8,95,5,121,69,
	28,29,108,10,100,108,2,100,95,1,95,5,128,2,
	0,95,4,95,5,49,128,254,255,12,3,12,1,25,
	3,100,80,2,134,9,108,2,100,95,1,95,4,128,
	1,0,12,2,80,1,134,11,95,3,110,7
   };

   hb_vmExecute( pcode, symbols );
}

HB_FUNC( FIND_Z )
{
   static const BYTE pcode[] =
   {
	13,6,2,133,66,0,126,4,1,0,127,7,9,0,
	40,41,123,125,91,93,39,34,0,121,121,121,121,121,
	121,121,121,4,8,0,80,8,134,2,95,2,100,5,
	28,8,106,2,44,0,25,4,95,2,80,2,134,4,
	108,1,100,95,2,108,2,100,95,1,95,4,12,2,
	12,2,80,3,134,5,95,3,121,5,28,5,26,193,
	0,134,8,95,3,95,4,72,128,255,255,80,3,134,
	10,95,4,80,5,95,5,95,3,128,255,255,34,28,
	43,134,11,108,1,100,95,1,95,5,1,95,7,12,
	2,21,80,6,121,69,28,16,134,12,95,8,95,6,
	1,23,96,8,0,95,6,2,134,14,173,5,25,207,
	134,16,9,95,8,122,1,95,8,92,2,1,8,28,
	57,73,9,95,8,92,3,1,95,8,92,4,1,8,
	28,42,73,9,95,8,92,5,1,95,8,92,6,1,
	8,28,27,73,9,95,8,92,7,1,92,2,50,121,
	8,28,13,73,95,8,92,8,1,92,2,50,121,8,
	28,4,25,49,134,19,108,1,100,95,1,95,3,1,
	95,7,12,2,21,80,6,121,69,28,16,134,20,95,
	8,95,6,1,23,96,8,0,95,6,2,134,22,95,
	3,128,1,0,80,4,26,38,255,134,25,95,3,110,
	7
   };

   hb_vmExecute( pcode, symbols );
}

HB_FUNC( CUTEXTEN )
{
   static const BYTE pcode[] =
   {
	13,1,1,133,104,0,108,12,100,106,2,46,0,95,
	1,12,2,21,80,2,121,5,28,6,95,1,25,15,
	108,2,100,95,1,122,95,2,128,255,255,12,3,110,
	7
   };

   hb_vmExecute( pcode, symbols );
}

HB_FUNC( FILEXTEN )
{
   static const BYTE pcode[] =
   {
	13,1,1,133,109,0,108,12,100,106,2,46,0,95,
	1,12,2,21,80,2,121,5,28,7,106,1,0,25,
	14,108,2,100,95,1,95,2,128,1,0,12,2,110,
	7
   };

   hb_vmExecute( pcode, symbols );
}

HB_FUNC( FILEPATH )
{
   static const BYTE pcode[] =
   {
	13,1,1,133,116,0,108,12,100,106,2,92,0,95,
	1,12,2,21,80,2,121,5,28,36,108,12,100,106,
	2,47,0,95,1,12,2,21,80,2,121,5,28,7,
	106,1,0,25,22,108,9,100,95,1,95,2,12,2,
	25,11,108,9,100,95,1,95,2,12,2,110,7
   };

   hb_vmExecute( pcode, symbols );
}

HB_FUNC( CUTPATH )
{
   static const BYTE pcode[] =
   {
	13,1,1,133,123,0,108,12,100,106,2,92,0,95,
	1,12,2,21,80,2,121,5,28,38,108,12,100,106,
	2,47,0,95,1,12,2,21,80,2,121,5,28,6,
	95,1,25,28,108,2,100,95,1,95,2,128,1,0,
	12,2,25,14,108,2,100,95,1,95,2,128,1,0,
	12,2,110,7
   };

   hb_vmExecute( pcode, symbols );
}

HB_FUNC( NEXTITEM )
{
   static const BYTE pcode[] =
   {
	13,2,3,116,17,0,133,130,0,9,95,2,100,69,
	28,5,73,95,2,21,31,8,73,103,1,0,100,8,
	28,8,134,1,122,82,1,0,134,3,95,3,100,8,
	28,10,134,4,127,3,2,0,59,0,134,6,103,1,
	0,97,159,134,1,0,69,28,107,134,7,103,1,0,
	80,5,134,8,108,1,100,95,3,108,2,100,95,1,
	103,1,0,12,2,12,2,21,80,4,121,8,28,35,
	134,9,97,159,134,1,0,82,1,0,134,10,108,10,
	100,108,4,100,108,2,100,95,1,95,5,12,2,12,
	1,12,1,110,7,134,12,103,1,0,95,4,72,82,
	1,0,134,13,108,10,100,108,4,100,108,2,100,95,
	1,95,5,95,4,128,255,255,12,3,12,1,12,1,
	110,7,134,16,106,1,0,110,7
   };

   hb_vmExecute( pcode, symbols );
}

HB_FUNC_INITSTATICS()
{
   static const BYTE pcode[] =
   {
	117,17,0,1,0,7
   };

   hb_vmExecute( pcode, symbols );
}

