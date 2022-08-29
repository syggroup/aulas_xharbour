/*
 * xHarbour 1.2.3 Intl. (SimpLex) (Build 20170228)
 * Generated C source code from <mail.prg>
 * Command: -oxbp\mail.c -m -n -pOxbp\ -q -gc0 -ID:\devel\OpenSSLWin32\include -Id:\devel\xharbour_bcc7\include mail.prg 
 * Created: 2019.02.28 20:28:39 (Borland/Embarcadero C++ 7.2 (32-bit))
 */

#include "hbvmpub.h"
#include "hbinit.h"

#define __PRG_SOURCE__ "mail.prg"

/* Forward declarations of all PRG defined Functions. */
HB_FUNC( TIPMAIL );
HB_FUNC_STATIC( TIPMAIL_NEW );
HB_FUNC_STATIC( TIPMAIL_SETENCODER );
HB_FUNC_STATIC( TIPMAIL_SETBODY );
HB_FUNC_STATIC( TIPMAIL_GETBODY );
HB_FUNC_STATIC( TIPMAIL_GETFIELDPART );
HB_FUNC_STATIC( TIPMAIL_GETFIELDOPTION );
HB_FUNC_STATIC( TIPMAIL_SETFIELDPART );
HB_FUNC_STATIC( TIPMAIL_SETFIELDOPTION );
HB_FUNC_STATIC( TIPMAIL_ATTACH );
HB_FUNC_STATIC( TIPMAIL_NEXTATTACHMENT );
HB_FUNC_STATIC( TIPMAIL_GETATTACHMENT );
HB_FUNC_STATIC( TIPMAIL_TOSTRING );
HB_FUNC_STATIC( TIPMAIL_FROMSTRING );
HB_FUNC_STATIC( TIPMAIL_MAKEBOUNDARY );
HB_FUNC_STATIC( TIPMAIL_SETHEADER );
HB_FUNC_STATIC( TIPMAIL_ATTACHFILE );
HB_FUNC_STATIC( TIPMAIL_DETACHFILE );
HB_FUNC_STATIC( TIPMAIL_GETFILENAME );
HB_FUNC_STATIC( TIPMAIL_ISMULTIPART );
HB_FUNC_STATIC( TIPMAIL_GETMULTIPARTS );
HB_FUNC_INITSTATICS();

/* Forward declarations of all externally defined Functions. */
/* Skipped DEFERRED call to: 'DIVERTCONSTRUCTORCALL' */
HB_FUNC_EXTERN( HBCLASS );
HB_FUNC_EXTERN( HBOBJECT );
HB_FUNC_EXTERN( LEN );
HB_FUNC_EXTERN( __CLSACTIVE );
HB_FUNC_EXTERN( __CLSINST );
HB_FUNC_EXTERN( __OBJHASMSG );
HB_FUNC_EXTERN( HB_APARAMS );
HB_FUNC_EXTERN( PCOUNT );
HB_FUNC_EXTERN( HSETCASEMATCH );
HB_FUNC_EXTERN( HB_ISSTRING );
HB_FUNC_EXTERN( HB_ISOBJECT );
HB_FUNC_EXTERN( LTRIM );
HB_FUNC_EXTERN( STR );
HB_FUNC_EXTERN( TIP_GETENCODER );
HB_FUNC_EXTERN( HGETPOS );
HB_FUNC_EXTERN( HGETVALUEAT );
HB_FUNC_EXTERN( AT );
HB_FUNC_EXTERN( SUBSTR );
HB_FUNC_EXTERN( HB_REGEX );
HB_FUNC_EXTERN( EMPTY );
HB_FUNC_EXTERN( LOWER );
HB_FUNC_EXTERN( AADD );
HB_FUNC_EXTERN( ALERT );
HB_FUNC_EXTERN( HGETKEYAT );
HB_FUNC_EXTERN( VALTYPE );
HB_FUNC_EXTERN( MAX );
HB_FUNC_EXTERN( SPACE );
HB_FUNC_EXTERN( CHR );
HB_FUNC_EXTERN( HB_RANDOM );
HB_FUNC_EXTERN( ASC );
HB_FUNC_EXTERN( STRTRAN );
HB_FUNC_EXTERN( DTOC );
HB_FUNC_EXTERN( DATE );
HB_FUNC_EXTERN( TIME );
HB_FUNC_EXTERN( HB_ISARRAY );
HB_FUNC_EXTERN( INETCRLF );
HB_FUNC_EXTERN( MEMOREAD );
HB_FUNC_EXTERN( HB_OSPATHSEPARATOR );
HB_FUNC_EXTERN( HB_FNAMESPLIT );
HB_FUNC_EXTERN( HB_SETMIMETYPE );
HB_FUNC_EXTERN( RAT );
HB_FUNC_EXTERN( FCREATE );
HB_FUNC_EXTERN( FERROR );
HB_FUNC_EXTERN( FWRITE );
HB_FUNC_EXTERN( FCLOSE );

#undef HB_PRG_PCODE_VER
#define HB_PRG_PCODE_VER 10

#include "hbapi.h"

HB_INIT_SYMBOLS_BEGIN( hb_vm_SymbolInit_MAIL )
{ "DIVERTCONSTRUCTORCALL", {HB_FS_PUBLIC | HB_FS_DEFERRED}, {NULL}, NULL },
{ "TIPMAIL", {HB_FS_PUBLIC | HB_FS_LOCAL}, {HB_FUNCNAME( TIPMAIL )}, &ModuleFakeDyn },
{ "NEW", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "HBCLASS", {HB_FS_PUBLIC}, {HB_FUNCNAME( HBCLASS )}, NULL },
{ "CLASSH", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "HBOBJECT", {HB_FS_PUBLIC}, {HB_FUNCNAME( HBOBJECT )}, NULL },
{ "ADDMULTIDATA", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "ADDMETHOD", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "TIPMAIL_NEW", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( TIPMAIL_NEW )}, &ModuleFakeDyn },
{ "TIPMAIL_SETBODY", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( TIPMAIL_SETBODY )}, &ModuleFakeDyn },
{ "TIPMAIL_GETBODY", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( TIPMAIL_GETBODY )}, &ModuleFakeDyn },
{ "ADDINLINE", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "CBODY", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "TIPMAIL_SETENCODER", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( TIPMAIL_SETENCODER )}, &ModuleFakeDyn },
{ "TIPMAIL_FROMSTRING", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( TIPMAIL_FROMSTRING )}, &ModuleFakeDyn },
{ "TIPMAIL_TOSTRING", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( TIPMAIL_TOSTRING )}, &ModuleFakeDyn },
{ "TIPMAIL_GETFIELDPART", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( TIPMAIL_GETFIELDPART )}, &ModuleFakeDyn },
{ "TIPMAIL_GETFIELDOPTION", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( TIPMAIL_GETFIELDOPTION )}, &ModuleFakeDyn },
{ "TIPMAIL_SETFIELDPART", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( TIPMAIL_SETFIELDPART )}, &ModuleFakeDyn },
{ "TIPMAIL_SETFIELDOPTION", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( TIPMAIL_SETFIELDOPTION )}, &ModuleFakeDyn },
{ "GETFIELDPART", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "GETFIELDOPTION", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "TIPMAIL_ATTACH", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( TIPMAIL_ATTACH )}, &ModuleFakeDyn },
{ "TIPMAIL_NEXTATTACHMENT", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( TIPMAIL_NEXTATTACHMENT )}, &ModuleFakeDyn },
{ "LEN", {HB_FS_PUBLIC}, {HB_FUNCNAME( LEN )}, NULL },
{ "AATTACHMENTS", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "TIPMAIL_GETATTACHMENT", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( TIPMAIL_GETATTACHMENT )}, &ModuleFakeDyn },
{ "_NATTACHPOS", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "TIPMAIL_MAKEBOUNDARY", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( TIPMAIL_MAKEBOUNDARY )}, &ModuleFakeDyn },
{ "TIPMAIL_ISMULTIPART", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( TIPMAIL_ISMULTIPART )}, &ModuleFakeDyn },
{ "TIPMAIL_GETMULTIPARTS", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( TIPMAIL_GETMULTIPARTS )}, &ModuleFakeDyn },
{ "TIPMAIL_SETHEADER", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( TIPMAIL_SETHEADER )}, &ModuleFakeDyn },
{ "TIPMAIL_ATTACHFILE", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( TIPMAIL_ATTACHFILE )}, &ModuleFakeDyn },
{ "TIPMAIL_DETACHFILE", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( TIPMAIL_DETACHFILE )}, &ModuleFakeDyn },
{ "TIPMAIL_GETFILENAME", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( TIPMAIL_GETFILENAME )}, &ModuleFakeDyn },
{ "__CLSACTIVE", {HB_FS_PUBLIC}, {HB_FUNCNAME( __CLSACTIVE )}, NULL },
{ "HCLASS", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "REFRESH", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "CREATE", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "__CLSINST", {HB_FS_PUBLIC}, {HB_FUNCNAME( __CLSINST )}, NULL },
{ "__OBJHASMSG", {HB_FS_PUBLIC}, {HB_FUNCNAME( __OBJHASMSG )}, NULL },
{ "INITCLASS", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "HB_APARAMS", {HB_FS_PUBLIC}, {HB_FUNCNAME( HB_APARAMS )}, NULL },
{ "PCOUNT", {HB_FS_PUBLIC}, {HB_FUNCNAME( PCOUNT )}, NULL },
{ "_HHEADERS", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "HSETCASEMATCH", {HB_FS_PUBLIC}, {HB_FUNCNAME( HSETCASEMATCH )}, NULL },
{ "_AATTACHMENTS", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "HB_ISSTRING", {HB_FS_PUBLIC}, {HB_FUNCNAME( HB_ISSTRING )}, NULL },
{ "HB_ISOBJECT", {HB_FS_PUBLIC}, {HB_FUNCNAME( HB_ISOBJECT )}, NULL },
{ "SETENCODER", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "OENCODER", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "_CBODY", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "ENCODE", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "CNAME", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "HHEADERS", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "LTRIM", {HB_FS_PUBLIC}, {HB_FUNCNAME( LTRIM )}, NULL },
{ "STR", {HB_FS_PUBLIC}, {HB_FUNCNAME( STR )}, NULL },
{ "_OENCODER", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "TIP_GETENCODER", {HB_FS_PUBLIC}, {HB_FUNCNAME( TIP_GETENCODER )}, NULL },
{ "_LBODYENCODED", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "DECODE", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "HGETPOS", {HB_FS_PUBLIC}, {HB_FUNCNAME( HGETPOS )}, NULL },
{ "HGETVALUEAT", {HB_FS_PUBLIC}, {HB_FUNCNAME( HGETVALUEAT )}, NULL },
{ "AT", {HB_FS_PUBLIC}, {HB_FUNCNAME( AT )}, NULL },
{ "SUBSTR", {HB_FS_PUBLIC}, {HB_FUNCNAME( SUBSTR )}, NULL },
{ "HB_REGEX", {HB_FS_PUBLIC}, {HB_FUNCNAME( HB_REGEX )}, NULL },
{ "EMPTY", {HB_FS_PUBLIC}, {HB_FUNCNAME( EMPTY )}, NULL },
{ "CLASSNAME", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "LOWER", {HB_FS_PUBLIC}, {HB_FUNCNAME( LOWER )}, NULL },
{ "AADD", {HB_FS_PUBLIC}, {HB_FUNCNAME( AADD )}, NULL },
{ "ALERT", {HB_FS_PUBLIC}, {HB_FUNCNAME( ALERT )}, NULL },
{ "NATTACHPOS", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "MAKEBOUNDARY", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "SETFIELDOPTION", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "ARECEIVED", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "HGETKEYAT", {HB_FS_PUBLIC}, {HB_FUNCNAME( HGETKEYAT )}, NULL },
{ "LBODYENCODED", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "TOSTRING", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "_ARECEIVED", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "VALTYPE", {HB_FS_PUBLIC}, {HB_FUNCNAME( VALTYPE )}, NULL },
{ "EVAL", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "FROMSTRING", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "MAX", {HB_FS_PUBLIC}, {HB_FUNCNAME( MAX )}, NULL },
{ "SPACE", {HB_FS_PUBLIC}, {HB_FUNCNAME( SPACE )}, NULL },
{ "CHR", {HB_FS_PUBLIC}, {HB_FUNCNAME( CHR )}, NULL },
{ "HB_RANDOM", {HB_FS_PUBLIC}, {HB_FUNCNAME( HB_RANDOM )}, NULL },
{ "ASC", {HB_FS_PUBLIC}, {HB_FUNCNAME( ASC )}, NULL },
{ "STRTRAN", {HB_FS_PUBLIC}, {HB_FUNCNAME( STRTRAN )}, NULL },
{ "DTOC", {HB_FS_PUBLIC}, {HB_FUNCNAME( DTOC )}, NULL },
{ "DATE", {HB_FS_PUBLIC}, {HB_FUNCNAME( DATE )}, NULL },
{ "TIME", {HB_FS_PUBLIC}, {HB_FUNCNAME( TIME )}, NULL },
{ "HB_ISARRAY", {HB_FS_PUBLIC}, {HB_FUNCNAME( HB_ISARRAY )}, NULL },
{ "SETFIELDPART", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "INETCRLF", {HB_FS_PUBLIC}, {HB_FUNCNAME( INETCRLF )}, NULL },
{ "MEMOREAD", {HB_FS_PUBLIC}, {HB_FUNCNAME( MEMOREAD )}, NULL },
{ "HB_OSPATHSEPARATOR", {HB_FS_PUBLIC}, {HB_FUNCNAME( HB_OSPATHSEPARATOR )}, NULL },
{ "HB_FNAMESPLIT", {HB_FS_PUBLIC}, {HB_FUNCNAME( HB_FNAMESPLIT )}, NULL },
{ "HB_SETMIMETYPE", {HB_FS_PUBLIC}, {HB_FUNCNAME( HB_SETMIMETYPE )}, NULL },
{ "RAT", {HB_FS_PUBLIC}, {HB_FUNCNAME( RAT )}, NULL },
{ "ATTACH", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "GETBODY", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "GETFILENAME", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "FCREATE", {HB_FS_PUBLIC}, {HB_FUNCNAME( FCREATE )}, NULL },
{ "FERROR", {HB_FS_PUBLIC}, {HB_FUNCNAME( FERROR )}, NULL },
{ "FWRITE", {HB_FS_PUBLIC}, {HB_FUNCNAME( FWRITE )}, NULL },
{ "FCLOSE", {HB_FS_PUBLIC}, {HB_FUNCNAME( FCLOSE )}, NULL },
{ "RESETATTACHMENT", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "NEXTATTACHMENT", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "COUNTATTACHMENTS", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "GETMULTIPARTS", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "(_INITSTATICS00001)", {HB_FS_INITEXIT}, {hb_INITSTATICS}, &ModuleFakeDyn }
HB_INIT_SYMBOLS_EX_END( hb_vm_SymbolInit_MAIL, __PRG_SOURCE__,  0x000a )

#if defined( HB_PRAGMA_STARTUP )
   #pragma startup hb_vm_SymbolInit_MAIL
#elif defined( HB_DATASEG_STARTUP )
   #define HB_DATASEG_BODY    HB_DATASEG_FUNC( hb_vm_SymbolInit_MAIL )
   #include "hbiniseg.h"
#endif

HB_FUNC( TIPMAIL )
{
   static const BYTE pcode[] =
   {
	13,2,255,116,110,0,126,2,1,0,95,2,73,103,
	1,0,100,8,29,211,4,48,2,0,108,3,100,12,
	0,106,8,84,105,112,77,97,105,108,0,48,4,0,
	108,5,100,12,0,112,0,4,1,0,112,2,82,1,
	0,133,67,0,48,6,0,103,1,0,100,100,95,2,
	106,9,104,72,101,97,100,101,114,115,0,4,1,0,
	9,9,112,6,73,134,1,48,6,0,103,1,0,100,
	4,0,0,95,2,106,10,97,82,101,99,101,105,118,
	101,100,0,4,1,0,9,9,112,6,73,134,3,48,
	7,0,103,1,0,106,4,78,101,119,0,108,8,14,
	95,2,128,16,0,9,112,4,73,134,4,48,7,0,
	103,1,0,106,8,83,101,116,66,111,100,121,0,108,
	9,14,95,2,9,112,4,73,134,5,48,7,0,103,
	1,0,106,8,71,101,116,66,111,100,121,0,108,10,
	14,95,2,9,112,4,73,134,6,48,11,0,103,1,
	0,106,11,71,101,116,82,97,119,66,111,100,121,0,
	89,18,0,1,0,0,0,95,1,73,48,12,0,95,
	1,112,0,6,95,2,9,112,4,73,134,7,48,7,
	0,103,1,0,106,11,83,101,116,69,110,99,111,100,
	101,114,0,108,13,14,95,2,9,112,4,73,134,9,
	48,7,0,103,1,0,106,11,70,114,111,109,83,116,
	114,105,110,103,0,108,14,14,95,2,9,112,4,73,
	134,10,48,7,0,103,1,0,106,9,84,111,83,116,
	114,105,110,103,0,108,15,14,95,2,9,112,4,73,
	134,12,48,7,0,103,1,0,106,13,71,101,116,70,
	105,101,108,100,80,97,114,116,0,108,16,14,95,2,
	9,112,4,73,134,13,48,7,0,103,1,0,106,15,
	71,101,116,70,105,101,108,100,79,112,116,105,111,110,
	0,108,17,14,95,2,9,112,4,73,134,14,48,7,
	0,103,1,0,106,13,83,101,116,70,105,101,108,100,
	80,97,114,116,0,108,18,14,95,2,9,112,4,73,
	134,15,48,7,0,103,1,0,106,15,83,101,116,70,
	105,101,108,100,79,112,116,105,111,110,0,108,19,14,
	95,2,9,112,4,73,134,17,48,11,0,103,1,0,
	106,15,71,101,116,67,111,110,116,101,110,116,84,121,
	112,101,0,89,33,0,1,0,0,0,95,1,73,48,
	20,0,95,1,106,13,67,111,110,116,101,110,116,45,
	84,121,112,101,0,112,1,6,95,2,9,112,4,73,
	134,18,48,11,0,103,1,0,106,16,71,101,116,67,
	104,97,114,69,110,99,111,100,105,110,103,0,89,44,
	0,1,0,0,0,95,1,73,48,21,0,95,1,106,
	13,67,111,110,116,101,110,116,45,84,121,112,101,0,
	106,9,101,110,99,111,100,105,110,103,0,112,2,6,
	95,2,9,112,4,73,134,20,48,7,0,103,1,0,
	106,7,65,116,116,97,99,104,0,108,22,14,95,2,
	9,112,4,73,134,21,48,7,0,103,1,0,106,15,
	78,101,120,116,65,116,116,97,99,104,109,101,110,116,
	0,108,23,14,95,2,9,112,4,73,134,22,48,11,
	0,103,1,0,106,17,67,111,117,110,116,65,116,116,
	97,99,104,109,101,110,116,115,0,89,23,0,1,0,
	0,0,95,1,73,108,24,100,48,25,0,95,1,112,
	0,12,1,6,95,2,9,112,4,73,134,23,48,7,
	0,103,1,0,106,14,71,101,116,65,116,116,97,99,
	104,109,101,110,116,0,108,26,14,95,2,9,112,4,
	73,134,24,48,11,0,103,1,0,106,16,82,101,115,
	101,116,65,116,116,97,99,104,109,101,110,116,0,89,
	19,0,1,0,0,0,95,1,73,48,27,0,95,1,
	122,112,1,6,95,2,9,112,4,73,134,26,48,7,
	0,103,1,0,106,13,77,97,107,101,66,111,117,110,
	100,97,114,121,0,108,28,14,95,2,9,112,4,73,
	134,28,48,7,0,103,1,0,106,12,105,115,77,117,
	108,116,105,80,97,114,116,0,108,29,14,95,2,9,
	112,4,73,134,29,48,7,0,103,1,0,106,14,103,
	101,116,77,117,108,116,105,80,97,114,116,115,0,108,
	30,14,95,2,9,112,4,73,134,31,48,7,0,103,
	1,0,106,10,115,101,116,72,101,97,100,101,114,0,
	108,31,14,95,2,9,112,4,73,134,32,48,7,0,
	103,1,0,106,11,97,116,116,97,99,104,70,105,108,
	101,0,108,32,14,95,2,9,112,4,73,134,33,48,
	7,0,103,1,0,106,11,100,101,116,97,99,104,70,
	105,108,101,0,108,33,14,95,2,9,112,4,73,134,
	34,48,7,0,103,1,0,106,12,103,101,116,70,105,
	108,101,78,97,109,101,0,108,34,14,95,2,9,112,
	4,73,126,2,8,0,95,2,73,134,36,48,6,0,
	103,1,0,100,100,95,2,106,6,99,66,111,100,121,
	0,4,1,0,9,9,112,6,73,134,37,48,6,0,
	103,1,0,100,9,95,2,106,13,108,66,111,100,121,
	69,110,99,111,100,101,100,0,4,1,0,9,9,112,
	6,73,134,38,48,6,0,103,1,0,100,100,95,2,
	106,9,111,69,110,99,111,100,101,114,0,4,1,0,
	9,9,112,6,73,134,39,48,6,0,103,1,0,100,
	100,95,2,106,13,97,65,116,116,97,99,104,109,101,
	110,116,115,0,4,1,0,9,9,112,6,73,134,40,
	48,6,0,103,1,0,100,122,95,2,106,11,110,65,
	116,116,97,99,104,80,111,115,0,4,1,0,9,9,
	112,6,73,48,38,0,103,1,0,112,0,73,108,39,
	100,48,36,0,103,1,0,112,0,12,1,80,1,108,
	40,100,95,1,106,10,73,110,105,116,67,108,97,115,
	115,0,12,2,28,32,48,41,0,95,1,108,42,100,
	12,0,112,1,73,25,17,108,39,100,48,36,0,103,
	1,0,112,0,12,1,80,1,108,43,100,12,0,121,
	15,28,10,103,1,0,108,0,14,121,178,95,1,110,
	7
   };

   hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( TIPMAIL_NEW )
{
   static const BYTE pcode[] =
   {
	13,1,2,102,80,3,133,114,0,48,44,0,95,3,
	108,45,100,172,0,0,9,12,2,112,1,73,134,1,
	48,46,0,95,3,4,0,0,112,1,73,134,3,108,
	47,100,95,2,12,1,21,31,10,73,108,48,100,95,
	2,12,1,28,14,134,4,48,49,0,95,3,95,2,
	112,1,73,134,7,95,1,100,69,29,151,0,134,8,
	48,50,0,95,3,112,0,100,69,28,77,134,9,48,
	51,0,95,3,48,52,0,48,50,0,95,3,112,0,
	95,1,112,1,112,1,73,134,10,48,53,0,48,50,
	0,95,3,112,0,112,0,48,54,0,95,3,150,106,
	26,67,111,110,116,101,110,116,45,84,114,97,110,115,
	102,101,114,45,69,110,99,111,100,105,110,103,0,2,
	25,14,134,12,48,51,0,95,3,95,1,112,1,73,
	134,14,108,55,100,108,56,100,108,24,100,48,12,0,
	95,3,112,0,12,1,12,1,12,1,48,54,0,95,
	3,150,106,15,67,111,110,116,101,110,116,45,76,101,
	110,103,116,104,0,2,134,17,95,3,110,7
   };

   hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( TIPMAIL_SETENCODER )
{
   static const BYTE pcode[] =
   {
	13,1,1,102,80,2,133,135,0,108,47,100,95,1,
	12,1,28,21,134,1,48,57,0,95,2,108,58,100,
	95,1,12,1,112,1,73,25,14,134,3,48,57,0,
	95,2,95,1,112,1,73,134,5,48,53,0,48,50,
	0,95,2,112,0,112,0,48,54,0,95,2,150,106,
	26,67,111,110,116,101,110,116,45,116,114,97,110,115,
	102,101,114,45,101,110,99,111,100,105,110,103,0,2,
	134,6,120,110,7
   };

   hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( TIPMAIL_SETBODY )
{
   static const BYTE pcode[] =
   {
	13,1,1,102,80,2,133,145,0,48,50,0,95,2,
	112,0,100,69,28,39,134,1,48,51,0,95,2,48,
	52,0,48,50,0,95,2,112,0,95,1,112,1,112,
	1,73,134,2,48,59,0,95,2,120,112,1,73,25,
	14,134,4,48,51,0,95,2,95,1,112,1,73,134,
	7,120,110,7
   };

   hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( TIPMAIL_GETBODY )
{
   static const BYTE pcode[] =
   {
	13,1,0,102,80,1,133,156,0,48,12,0,95,1,
	112,0,100,8,28,7,134,1,100,110,7,134,2,48,
	50,0,95,1,112,0,100,69,28,25,134,3,48,60,
	0,48,50,0,95,1,112,0,48,12,0,95,1,112,
	0,112,1,110,7,134,5,48,12,0,95,1,112,0,
	110,7
   };

   hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( TIPMAIL_GETFIELDPART )
{
   static const BYTE pcode[] =
   {
	13,3,1,102,80,2,133,167,0,108,61,100,48,54,
	0,95,2,112,0,95,1,12,2,80,3,134,1,95,
	3,121,8,28,9,134,2,106,1,0,110,7,134,4,
	108,62,100,48,54,0,95,2,112,0,95,3,12,2,
	80,4,134,5,108,63,100,106,2,59,0,95,4,12,
	2,80,3,134,6,95,3,121,69,28,19,134,7,108,
	64,100,95,4,122,95,3,128,255,255,12,3,80,4,
	134,11,95,4,110,7
   };

   hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( TIPMAIL_GETFIELDOPTION )
{
   static const BYTE pcode[] =
   {
	13,4,2,102,80,3,133,185,0,108,61,100,48,54,
	0,95,3,112,0,95,1,12,2,80,4,134,1,95,
	4,121,8,28,9,134,2,106,1,0,110,7,134,4,
	108,62,100,48,54,0,95,3,112,0,95,4,12,2,
	80,6,134,6,108,65,100,106,5,59,92,115,42,0,
	95,2,72,106,15,92,115,42,61,92,115,42,40,91,
	94,59,93,42,41,0,72,95,6,9,12,3,80,5,
	134,7,95,5,100,69,28,13,134,8,95,5,92,2,
	1,80,6,25,9,134,10,106,1,0,110,7,134,13,
	95,6,110,7
   };

   hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( TIPMAIL_SETFIELDPART )
{
   static const BYTE pcode[] =
   {
	13,3,2,102,80,3,133,204,0,108,61,100,48,54,
	0,95,3,112,0,95,1,12,2,80,4,134,1,95,
	4,121,8,28,17,134,2,95,2,48,54,0,95,3,
	150,95,1,2,25,81,134,4,108,62,100,48,54,0,
	95,3,112,0,95,4,12,2,80,5,134,5,108,63,
	100,106,2,59,0,95,5,12,2,80,4,134,6,95,
	4,121,8,28,17,134,7,95,2,48,54,0,95,3,
	150,95,1,2,25,25,134,9,95,2,108,64,100,95,
	5,95,4,12,2,72,48,54,0,95,3,150,95,1,
	2,134,13,120,110,7
   };

   hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( TIPMAIL_SETFIELDOPTION )
{
   static const BYTE pcode[] =
   {
	13,4,3,102,80,4,133,224,0,108,61,100,48,54,
	0,95,4,112,0,95,1,12,2,80,5,134,1,95,
	5,121,8,28,7,134,2,9,110,7,134,4,108,62,
	100,48,54,0,95,4,112,0,95,5,12,2,80,7,
	134,5,108,65,100,106,10,40,46,42,63,59,92,115,
	42,41,0,95,2,72,106,15,92,115,42,61,91,94,
	59,93,42,40,46,42,41,63,0,72,95,7,9,12,
	3,80,6,134,6,108,66,100,95,6,12,1,28,41,
	134,7,106,3,59,32,0,95,2,72,106,3,61,34,
	0,72,95,3,72,106,2,34,0,72,167,7,95,7,
	48,54,0,95,4,150,95,1,2,25,41,134,10,95,
	6,92,2,1,95,2,72,106,3,61,34,0,72,95,
	3,72,106,2,34,0,72,95,6,92,3,1,72,48,
	54,0,95,4,150,95,1,2,134,14,120,110,7
   };

   hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( TIPMAIL_ATTACH )
{
   static const BYTE pcode[] =
   {
	13,1,1,102,80,2,133,243,0,9,108,48,100,95,
	1,12,1,28,21,73,48,67,0,95,1,112,0,106,
	8,84,73,80,77,65,73,76,0,8,28,116,134,2,
	108,63,100,106,11,109,117,108,116,105,112,97,114,116,
	47,0,108,68,100,48,20,0,95,2,106,13,67,111,
	110,116,101,110,116,45,84,121,112,101,0,112,1,12,
	1,12,2,121,8,28,44,134,3,106,16,109,117,108,
	116,105,112,97,114,116,47,109,105,120,101,100,0,48,
	54,0,95,2,150,106,13,67,111,110,116,101,110,116,
	45,84,121,112,101,0,2,134,6,108,69,100,48,25,
	0,95,2,112,0,95,1,20,2,134,7,120,110,7,
	134,9,108,70,100,106,60,84,105,112,77,97,105,108,
	58,65,116,116,97,99,104,40,41,32,109,117,115,116,
	32,98,101,32,99,97,108,108,101,100,32,119,105,116,
	104,32,97,110,111,116,104,101,114,32,84,105,112,77,
	97,105,108,32,111,98,106,101,99,116,0,20,1,134,
	12,9,110,7
   };

   hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( TIPMAIL_NEXTATTACHMENT )
{
   static const BYTE pcode[] =
   {
	13,1,0,102,80,1,133,4,1,48,71,0,95,1,
	112,0,108,24,100,48,25,0,95,1,112,0,12,1,
	15,28,7,134,1,100,110,7,134,3,48,27,0,95,
	1,48,71,0,95,1,112,0,23,112,1,73,134,6,
	48,25,0,95,1,112,0,48,71,0,95,1,112,0,
	128,255,255,1,110,7
   };

   hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( TIPMAIL_GETATTACHMENT )
{
   static const BYTE pcode[] =
   {
	13,1,0,102,80,1,133,15,1,48,71,0,95,1,
	112,0,108,24,100,48,25,0,95,1,112,0,12,1,
	15,28,7,134,1,100,110,7,134,4,48,25,0,95,
	1,112,0,48,71,0,95,1,112,0,1,110,7
   };

   hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( TIPMAIL_TOSTRING )
{
   static const BYTE pcode[] =
   {
	13,5,0,102,80,1,133,24,1,127,5,1,0,0,
	134,2,108,24,100,48,25,0,95,1,112,0,12,1,
	121,15,28,32,134,3,106,4,49,46,48,0,48,54,
	0,95,1,150,106,13,77,105,109,101,45,86,101,114,
	115,105,111,110,0,2,134,6,108,24,100,48,25,0,
	95,1,112,0,12,1,121,15,29,0,1,134,8,108,
	63,100,106,11,109,117,108,116,105,112,97,114,116,47,
	0,108,68,100,48,20,0,95,1,106,13,67,111,110,
	116,101,110,116,45,84,121,112,101,0,112,1,12,1,
	12,2,121,8,28,44,134,9,106,16,109,117,108,116,
	105,112,97,114,116,47,109,105,120,101,100,0,48,54,
	0,95,1,150,106,13,67,111,110,116,101,110,116,45,
	84,121,112,101,0,2,134,13,48,21,0,95,1,106,
	13,67,111,110,116,101,110,116,45,84,121,112,101,0,
	106,9,66,111,117,110,100,97,114,121,0,112,2,80,
	2,134,14,108,66,100,95,2,12,1,28,114,134,15,
	48,72,0,95,1,112,0,80,2,134,16,48,73,0,
	95,1,106,13,67,111,110,116,101,110,116,45,84,121,
	112,101,0,106,9,66,111,117,110,100,97,114,121,0,
	95,2,112,3,31,64,134,18,106,28,109,117,108,116,
	105,112,97,114,116,47,109,105,120,101,100,59,32,98,
	111,117,110,100,97,114,121,61,34,0,95,2,72,106,
	2,34,0,72,48,54,0,95,1,150,106,13,67,111,
	110,116,101,110,116,45,84,121,112,101,0,2,134,25,
	106,12,82,101,116,117,114,110,45,80,97,116,104,0,
	48,54,0,95,1,112,0,24,28,51,134,26,106,14,
	82,101,116,117,114,110,45,80,97,116,104,58,32,0,
	48,54,0,95,1,112,0,106,12,82,101,116,117,114,
	110,45,80,97,116,104,0,1,72,106,3,13,10,0,
	72,167,5,134,28,106,13,68,101,108,105,118,101,114,
	101,100,45,84,111,0,48,54,0,95,1,112,0,24,
	28,53,134,29,106,15,68,101,108,105,118,101,114,101,
	100,45,84,111,58,32,0,48,54,0,95,1,112,0,
	106,13,68,101,108,105,118,101,114,101,100,45,84,111,
	0,1,72,106,3,13,10,0,72,167,5,134,31,96,
	3,0,48,74,0,95,1,112,0,139,140,28,32,134,
	32,106,11,82,101,99,101,105,118,101,100,58,32,0,
	95,3,72,106,3,13,10,0,72,167,5,134,33,25,
	225,141,134,34,106,5,68,97,116,101,0,48,54,0,
	95,1,112,0,24,28,37,134,35,106,7,68,97,116,
	101,58,32,0,48,54,0,95,1,112,0,106,5,68,
	97,116,101,0,1,72,106,3,13,10,0,72,167,5,
	134,37,106,5,70,114,111,109,0,48,54,0,95,1,
	112,0,24,28,37,134,38,106,7,70,114,111,109,58,
	32,0,48,54,0,95,1,112,0,106,5,70,114,111,
	109,0,1,72,106,3,13,10,0,72,167,5,134,40,
	106,3,84,111,0,48,54,0,95,1,112,0,24,28,
	33,134,41,106,5,84,111,58,32,0,48,54,0,95,
	1,112,0,106,3,84,111,0,1,72,106,3,13,10,
	0,72,167,5,134,43,106,8,83,117,98,106,101,99,
	116,0,48,54,0,95,1,112,0,24,28,43,134,44,
	106,10,83,117,98,106,101,99,116,58,32,0,48,54,
	0,95,1,112,0,106,8,83,117,98,106,101,99,116,
	0,1,72,106,3,13,10,0,72,167,5,134,46,108,
	24,100,48,25,0,95,1,112,0,12,1,121,15,28,
	52,134,47,106,14,77,105,109,101,45,86,101,114,115,
	105,111,110,58,0,48,54,0,95,1,112,0,106,13,
	77,105,109,101,45,86,101,114,115,105,111,110,0,1,
	72,106,3,13,10,0,72,167,5,134,50,126,4,1,
	0,95,4,108,24,100,48,54,0,95,1,112,0,12,
	1,34,29,201,0,134,51,108,68,100,108,75,100,48,
	54,0,95,1,112,0,95,4,12,2,12,1,80,3,
	134,58,9,95,3,106,12,114,101,116,117,114,110,45,
	112,97,116,104,0,8,31,101,73,9,95,3,106,13,
	100,101,108,105,118,101,114,101,100,45,116,111,0,8,
	31,79,73,9,95,3,106,5,100,97,116,101,0,8,
	31,65,73,9,95,3,106,5,102,114,111,109,0,8,
	31,51,73,9,95,3,106,3,116,111,0,8,31,39,
	73,9,95,3,106,8,115,117,98,106,101,99,116,0,
	8,31,22,73,95,3,106,13,109,105,109,101,45,118,
	101,114,115,105,111,110,0,8,68,28,47,134,60,108,
	75,100,48,54,0,95,1,112,0,95,4,12,2,106,
	3,58,32,0,72,108,62,100,48,54,0,95,1,112,
	0,95,4,12,2,72,106,3,13,10,0,72,167,5,
	134,62,173,4,26,43,255,134,65,106,3,13,10,0,
	167,5,134,68,108,66,100,48,12,0,95,1,112,0,
	12,1,32,234,0,134,69,108,66,100,48,25,0,95,
	1,112,0,12,1,28,36,134,71,48,12,0,95,1,
	112,0,48,76,0,95,1,112,0,28,7,106,1,0,
	25,7,106,3,13,10,0,72,167,5,26,184,0,134,
	74,106,3,45,45,0,95,2,72,106,3,13,10,0,
	72,167,5,134,75,106,62,67,111,110,116,101,110,116,
	45,84,121,112,101,58,32,116,101,120,116,47,112,108,
	97,105,110,59,32,99,104,97,114,115,101,116,61,73,
	83,79,45,56,56,53,57,45,49,59,32,102,111,114,
	109,97,116,61,102,108,111,119,101,100,13,10,0,167,
	5,134,76,106,34,67,111,110,116,101,110,116,45,84,
	114,97,110,115,102,101,114,45,69,110,99,111,100,105,
	110,103,58,32,55,98,105,116,13,10,0,167,5,134,
	77,106,32,67,111,110,116,101,110,116,45,68,105,115,
	112,111,115,105,116,105,111,110,58,32,105,110,108,105,
	110,101,13,10,13,10,0,167,5,134,78,48,12,0,
	95,1,112,0,106,3,13,10,0,72,167,5,134,83,
	108,66,100,48,25,0,95,1,112,0,12,1,31,92,
	134,85,126,4,1,0,95,4,108,24,100,48,25,0,
	95,1,112,0,12,1,34,28,45,134,86,106,3,45,
	45,0,95,2,72,106,3,13,10,0,72,167,5,134,
	87,48,77,0,48,25,0,95,1,112,0,95,4,1,
	112,0,167,5,134,88,173,4,25,198,134,89,106,3,
	45,45,0,95,2,72,106,3,45,45,0,72,106,3,
	13,10,0,72,167,5,134,92,95,5,110,7
   };

   hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( TIPMAIL_FROMSTRING )
{
   static const BYTE pcode[] =
   {
	13,9,4,102,80,5,133,125,1,108,24,100,48,25,
	0,95,5,112,0,12,1,121,15,28,15,134,1,48,
	46,0,95,5,4,0,0,112,1,73,134,4,108,24,
	100,48,54,0,95,5,112,0,12,1,121,15,28,21,
	134,5,48,44,0,95,5,108,45,100,172,0,0,9,
	12,2,112,1,73,134,8,108,24,100,48,74,0,95,
	5,112,0,12,1,121,15,28,15,134,9,48,78,0,
	95,5,4,0,0,112,1,73,134,13,95,3,100,8,
	28,8,134,14,126,3,1,0,134,17,95,1,100,8,
	28,9,134,18,127,1,1,0,0,134,21,108,24,100,
	95,1,12,1,80,13,134,22,108,63,100,106,3,13,
	10,0,95,1,95,3,12,3,80,8,134,23,95,8,
	95,3,15,29,95,1,134,26,9,95,1,95,3,1,
	106,2,32,0,8,21,31,13,73,95,1,95,3,1,
	106,2,9,0,8,28,7,73,95,12,100,69,28,99,
	134,27,108,55,100,108,64,100,95,1,95,3,95,8,
	95,3,49,12,3,12,1,80,11,134,28,108,68,100,
	95,12,12,1,106,9,114,101,99,101,105,118,101,100,
	0,8,28,33,134,29,106,2,32,0,95,11,72,48,
	74,0,95,5,150,108,24,100,48,74,0,95,5,112,
	0,12,1,169,26,141,0,134,31,106,2,32,0,95,
	11,72,48,54,0,95,5,150,95,12,169,25,120,134,
	35,108,63,100,106,2,58,0,95,1,95,3,12,3,
	80,9,134,36,108,64,100,95,1,95,3,95,9,95,
	3,49,12,3,80,12,134,37,108,55,100,108,64,100,
	95,1,95,9,128,1,0,95,8,95,9,49,128,255,
	255,12,3,12,1,80,11,134,38,108,68,100,95,12,
	12,1,106,9,114,101,99,101,105,118,101,100,0,8,
	28,20,134,39,108,69,100,48,74,0,95,5,112,0,
	95,11,20,2,25,15,134,41,95,11,48,54,0,95,
	5,150,95,12,2,134,45,95,8,128,2,0,80,3,
	134,46,108,63,100,106,3,13,10,0,95,1,95,3,
	12,3,80,8,134,48,9,95,2,100,69,28,22,73,
	108,63,100,106,3,45,45,0,95,2,72,95,1,95,
	3,12,3,122,8,28,7,134,49,121,110,7,134,52,
	108,79,100,95,4,12,1,106,2,66,0,8,29,174,
	254,134,53,48,80,0,95,4,95,3,95,13,112,2,
	73,26,157,254,134,62,106,26,67,111,110,116,101,110,
	116,45,84,114,97,110,115,102,101,114,45,69,110,99,
	111,100,105,110,103,0,48,54,0,95,5,112,0,24,
	28,53,134,63,48,57,0,95,5,108,58,100,48,54,
	0,95,5,112,0,106,26,67,111,110,116,101,110,116,
	45,84,114,97,110,115,102,101,114,45,69,110,99,111,
	100,105,110,103,0,1,12,1,112,1,73,134,67,108,
	63,100,106,11,109,117,108,116,105,112,97,114,116,47,
	0,108,68,100,48,20,0,95,5,106,13,67,111,110,
	116,101,110,116,45,84,121,112,101,0,112,1,12,1,
	12,2,121,15,28,75,134,68,48,21,0,95,5,106,
	13,67,111,110,116,101,110,116,45,84,121,112,101,0,
	106,9,66,111,117,110,100,97,114,121,0,112,2,80,
	7,134,70,95,7,122,1,106,2,34,0,8,28,25,
	134,71,108,64,100,95,7,92,2,108,24,100,95,7,
	12,1,128,254,255,12,3,80,7,134,75,95,8,128,
	2,0,80,3,134,76,95,3,80,10,134,77,108,63,
	100,106,3,13,10,0,95,1,95,3,12,3,80,8,
	134,79,95,8,95,3,16,29,138,1,134,81,95,8,
	95,3,8,28,28,134,82,125,3,2,0,134,83,108,
	63,100,106,3,13,10,0,95,1,95,3,12,3,80,
	8,25,213,134,88,9,95,2,100,69,28,23,73,108,
	63,100,106,3,45,45,0,95,2,72,95,1,95,3,
	12,3,95,3,8,28,5,26,68,1,134,94,9,95,
	7,100,69,28,23,73,108,63,100,106,3,45,45,0,
	95,7,72,95,1,95,3,12,3,95,3,8,29,142,
	0,134,97,108,63,100,106,3,45,45,0,95,1,95,
	3,108,24,100,95,7,12,1,72,128,2,0,95,8,
	12,4,121,15,28,5,26,255,0,134,102,95,10,121,
	15,28,32,134,103,48,51,0,95,5,108,64,100,95,
	1,95,10,95,3,95,10,49,12,3,112,1,73,134,
	104,126,10,0,0,134,108,48,2,0,108,1,100,12,
	0,112,0,80,6,134,109,48,81,0,95,6,95,1,
	95,7,95,8,128,2,0,112,3,80,3,134,111,95,
	3,121,15,28,20,134,112,108,69,100,48,25,0,95,
	5,112,0,95,6,20,2,25,104,134,114,121,110,7,
	134,125,108,66,100,95,7,12,1,31,35,134,126,108,
	82,100,95,8,128,2,0,108,63,100,106,3,45,45,
	0,95,7,72,95,1,95,3,12,3,12,2,80,3,
	25,55,134,127,108,66,100,95,2,12,1,31,35,134,
	128,108,82,100,95,8,128,2,0,108,63,100,106,3,
	45,45,0,95,2,72,95,1,95,3,12,3,12,2,
	80,3,25,11,134,130,95,8,128,2,0,80,3,134,
	134,108,63,100,106,3,13,10,0,95,1,95,3,12,
	3,80,8,134,136,108,79,100,95,4,12,1,106,2,
	66,0,8,29,131,254,134,137,48,80,0,95,4,95,
	3,95,13,112,2,73,26,114,254,134,142,95,10,121,
	15,28,26,134,143,48,51,0,95,5,108,64,100,95,
	1,95,10,95,3,95,10,49,12,3,112,1,73,134,
	147,95,3,110,7
   };

   hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( TIPMAIL_MAKEBOUNDARY )
{
   static const BYTE pcode[] =
   {
	13,3,0,102,80,1,133,20,2,106,4,61,95,48,
	0,108,83,100,92,17,12,1,72,80,2,134,3,126,
	3,4,0,95,3,92,20,34,28,39,134,4,108,84,
	100,108,85,100,121,92,25,12,2,108,86,100,106,2,
	65,0,12,1,72,12,1,96,2,0,95,3,2,134,
	5,173,3,25,214,134,7,106,6,95,84,73,80,95,
	0,108,87,100,108,88,100,108,89,100,12,0,12,1,
	106,2,47,0,106,1,0,12,3,72,106,2,95,0,
	72,108,87,100,108,90,100,12,0,106,2,58,0,106,
	1,0,12,3,72,167,2,134,9,95,2,110,7
   };

   hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( TIPMAIL_SETHEADER )
{
   static const BYTE pcode[] =
   {
	13,6,5,102,80,6,133,35,2,108,47,100,95,1,
	12,1,31,9,134,1,127,1,1,0,0,134,4,108,
	47,100,95,2,12,1,31,7,134,5,9,110,7,134,
	8,108,47,100,95,3,12,1,28,13,134,9,95,3,
	4,1,0,80,7,25,19,134,10,108,91,100,95,3,
	12,1,28,8,134,11,95,3,80,7,134,14,108,47,
	100,95,4,12,1,28,13,134,15,95,4,4,1,0,
	80,8,25,19,134,16,108,91,100,95,4,12,1,28,
	8,134,17,95,4,80,8,134,20,108,47,100,95,5,
	12,1,28,13,134,21,95,5,4,1,0,80,9,25,
	19,134,22,108,91,100,95,5,12,1,28,8,134,23,
	95,5,80,9,134,26,95,7,100,8,28,7,134,27,
	9,110,7,134,30,48,92,0,95,6,106,8,83,117,
	98,106,101,99,116,0,95,1,112,2,31,7,134,31,
	9,110,7,134,34,48,92,0,95,6,106,5,70,114,
	111,109,0,95,2,112,2,31,7,134,35,9,110,7,
	134,38,95,7,122,1,80,3,134,39,108,24,100,95,
	7,12,1,80,11,134,40,126,10,2,0,95,10,95,
	11,34,28,33,134,41,106,2,44,0,108,93,100,12,
	0,72,106,2,9,0,72,95,7,95,10,1,72,167,
	3,134,42,173,10,25,220,134,44,48,92,0,95,6,
	106,3,84,111,0,95,3,112,2,31,7,134,45,9,
	110,7,134,48,95,8,100,69,28,88,134,49,95,8,
	122,1,80,4,134,50,108,24,100,95,8,12,1,80,
	11,134,51,126,10,2,0,95,10,95,11,34,28,33,
	134,52,106,2,44,0,108,93,100,12,0,72,106,2,
	9,0,72,95,8,95,10,1,72,167,4,134,53,173,
	10,25,220,134,55,48,92,0,95,6,106,3,67,99,
	0,95,4,112,2,31,7,134,56,9,110,7,134,60,
	95,9,100,69,28,89,134,61,95,9,122,1,80,5,
	134,62,108,24,100,95,9,12,1,80,11,134,63,126,
	10,2,0,95,10,95,11,34,28,33,134,64,106,2,
	44,0,108,93,100,12,0,72,106,2,9,0,72,95,
	9,95,10,1,72,167,5,134,65,173,10,25,220,134,
	67,48,92,0,95,6,106,4,66,99,99,0,95,5,
	112,2,31,7,134,68,9,110,7,134,72,120,110,7
   };

   hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( TIPMAIL_ATTACHFILE )
{
   static const BYTE pcode[] =
   {
	13,7,1,102,80,2,133,111,2,108,94,100,95,1,
	12,1,80,3,134,3,108,95,100,12,0,80,7,134,
	6,108,66,100,95,3,12,1,28,7,134,7,9,110,
	7,134,10,108,96,100,95,1,100,96,4,0,96,5,
	0,20,4,134,11,108,97,100,95,1,95,4,95,5,
	12,3,80,6,134,13,106,6,46,104,116,109,108,0,
	108,68,100,95,5,12,1,24,21,31,18,73,106,5,
	46,104,116,109,0,108,68,100,95,5,12,1,24,28,
	29,134,14,106,21,59,32,99,104,97,114,115,101,116,
	61,73,83,79,45,56,56,53,57,45,49,0,167,6,
	134,17,106,6,46,104,116,109,108,0,108,68,100,95,
	5,12,1,24,21,31,37,73,106,5,46,104,116,109,
	0,108,68,100,95,5,12,1,24,21,31,18,73,106,
	5,46,116,120,116,0,108,68,100,95,5,12,1,24,
	28,27,134,18,48,2,0,108,1,100,12,0,95,3,
	106,5,55,98,105,116,0,112,2,80,8,25,27,134,
	20,48,2,0,108,1,100,12,0,95,3,106,7,98,
	97,115,101,54,52,0,112,2,80,8,134,23,108,64,
	100,95,1,108,98,100,95,1,95,7,12,2,128,1,
	0,12,2,80,1,134,25,48,92,0,95,8,106,13,
	67,111,110,116,101,110,116,45,84,121,112,101,0,95,
	6,112,2,73,134,26,48,73,0,95,8,106,13,67,
	111,110,116,101,110,116,45,84,121,112,101,0,106,5,
	110,97,109,101,0,95,4,95,5,72,112,3,73,134,
	28,108,68,100,95,5,12,1,106,5,46,112,110,103,
	0,24,21,31,38,73,108,68,100,95,5,12,1,106,
	5,46,106,112,103,0,24,21,31,19,73,108,68,100,
	95,5,12,1,106,6,46,106,112,101,103,0,24,28,
	30,134,29,48,92,0,95,8,106,11,67,111,110,116,
	101,110,116,45,73,100,0,95,4,95,5,72,112,2,
	73,134,32,48,92,0,95,8,106,20,67,111,110,116,
	101,110,116,45,68,105,115,112,111,115,105,116,105,111,
	110,0,106,11,97,116,116,97,99,104,109,101,110,116,
	0,112,2,73,134,33,48,73,0,95,8,106,20,67,
	111,110,116,101,110,116,45,68,105,115,112,111,115,105,
	116,105,111,110,0,106,9,102,105,108,101,110,97,109,
	101,0,95,4,95,5,72,112,3,73,134,35,48,99,
	0,95,2,95,8,112,1,110,7
   };

   hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( TIPMAIL_DETACHFILE )
{
   static const BYTE pcode[] =
   {
	13,5,1,102,80,2,133,150,2,48,100,0,95,2,
	112,0,80,3,134,1,48,101,0,95,2,112,0,80,
	4,134,2,108,95,100,12,0,80,5,134,5,108,66,
	100,95,4,12,1,28,7,134,6,9,110,7,134,9,
	108,47,100,95,1,12,1,28,26,134,10,108,87,100,
	95,1,95,5,72,95,4,72,95,5,95,5,72,95,
	5,12,3,80,4,134,13,108,102,100,95,4,12,1,
	80,6,134,14,108,103,100,12,0,121,69,28,7,134,
	15,9,110,7,134,18,108,104,100,95,6,95,3,20,
	2,134,20,108,105,100,95,6,20,1,134,21,108,103,
	100,12,0,121,8,110,7
   };

   hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( TIPMAIL_GETFILENAME )
{
   static const BYTE pcode[] =
   {
	13,2,0,102,80,1,133,177,2,106,11,97,116,116,
	97,99,104,109,101,110,116,0,108,68,100,48,20,0,
	95,1,106,20,67,111,110,116,101,110,116,45,68,105,
	115,112,111,115,105,116,105,111,110,0,112,1,12,1,
	24,28,48,134,1,48,21,0,95,1,106,20,67,111,
	110,116,101,110,116,45,68,105,115,112,111,115,105,116,
	105,111,110,0,106,9,102,105,108,101,110,97,109,101,
	0,112,2,80,2,25,35,134,3,48,21,0,95,1,
	106,13,67,111,110,116,101,110,116,45,84,121,112,101,
	0,106,5,110,97,109,101,0,112,2,80,2,134,6,
	108,87,100,95,2,106,2,34,0,106,1,0,12,3,
	110,7
   };

   hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( TIPMAIL_ISMULTIPART )
{
   static const BYTE pcode[] =
   {
	13,1,0,102,80,1,133,186,2,106,11,109,117,108,
	116,105,112,97,114,116,47,0,108,68,100,48,20,0,
	95,1,106,13,67,111,110,116,101,110,116,45,84,121,
	112,101,0,112,1,12,1,24,110,7
   };

   hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( TIPMAIL_GETMULTIPARTS )
{
   static const BYTE pcode[] =
   {
	13,3,1,102,80,2,133,190,2,9,80,4,134,2,
	48,106,0,95,2,112,0,73,134,4,95,1,100,8,
	28,9,134,5,4,0,0,80,1,134,8,48,107,0,
	95,2,112,0,21,80,3,100,69,28,45,134,9,120,
	80,4,134,10,108,69,100,95,1,95,3,20,2,134,
	11,48,108,0,95,3,112,0,121,15,28,213,134,12,
	48,109,0,95,3,95,1,112,1,73,25,199,134,16,
	95,4,28,12,134,17,48,106,0,95,2,112,0,73,
	134,19,95,1,110,7
   };

   hb_vmExecute( pcode, symbols );
}

HB_FUNC_INITSTATICS()
{
   static const BYTE pcode[] =
   {
	117,110,0,1,0,7
   };

   hb_vmExecute( pcode, symbols );
}
