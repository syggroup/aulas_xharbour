/*
 * xHarbour 1.2.3 Intl. (SimpLex) (Build 20170228)
 * Generated C source code from <demo01.prg>
 * Command: demo01.prg -n -q0 -gc -id:\devel\xharbour_bcc7\include;d:\devel\xharbour_bcc7\contrib\sqlrdd\include -p 
 * Created: 2019.12.04 14:32:07 (Borland/Embarcadero C++ 7.2 (32-bit))
 */

#include "hbvmpub.h"
#include "hbpcode.h"
#include "hbinit.h"

#define __PRG_SOURCE__ "demo01.prg"

/* Forward declarations of all PRG defined Functions. */
HB_FUNC( MAIN );
HB_FUNC( CONNECT );

/* Forward declarations of all externally defined Functions. */
HB_FUNC_EXTERN( QOUT );
HB_FUNC_EXTERN( SR_USEDELETEDS );
HB_FUNC_EXTERN( SR_SETFASTOPEN );
HB_FUNC_EXTERN( SR_SETGOTOPONSCOPE );
HB_FUNC_EXTERN( SR_MAXROWCACHE );
HB_FUNC_EXTERN( SR_SETBASELANG );
HB_FUNC_EXTERN( SR_MSG );
HB_FUNC_EXTERN( SR_SETSYNTHETICINDEX );
HB_FUNC_EXTERN( SR_SETSYNTHETICINDEXMINIMUN );
HB_FUNC_EXTERN( SETPGSOLDBEHAVIOR );
HB_FUNC_EXTERN( RDDSETDEFAULT );
HB_FUNC_EXTERN( __SETCENTURY );
HB_FUNC_EXTERN( SET );
HB_FUNC_EXTERN( SR_GETCONNECTION );
HB_FUNC_EXTERN( ALERT );
HB_FUNC_EXTERN( VALTOPRG );
HB_FUNC_EXTERN( LEN );
HB_FUNC_EXTERN( DBCLOSEALL );
HB_FUNC_EXTERN( SR_END );
HB_FUNC_EXTERN( SQLRDD );
HB_FUNC_EXTERN( SQLEX );
HB_FUNC_EXTERN( SR_ODBC );
HB_FUNC_EXTERN( SR_PGS );
HB_FUNC_EXTERN( SR_MYSQL );
HB_FUNC_EXTERN( SR_ORACLE );
HB_FUNC_EXTERN( SR_FIREBIRD );
HB_FUNC_EXTERN( DBFNTX );
HB_FUNC_EXTERN( DBFCDX );
HB_FUNC_EXTERN( DBFFPT );
HB_FUNC_EXTERN( DBFDBT );
HB_FUNC_EXTERN( __MVPUBLIC );
HB_FUNC_EXTERN( SETMODE );
HB_FUNC_EXTERN( HB_READINI );
HB_FUNC_EXTERN( __QUIT );
HB_FUNC_EXTERN( HGETKEYS );
HB_FUNC_EXTERN( SCROLL );
HB_FUNC_EXTERN( SETPOS );
HB_FUNC_EXTERN( DEVPOS );
HB_FUNC_EXTERN( DEVOUT );
HB_FUNC_EXTERN( PADC );
HB_FUNC_EXTERN( ACHOICE );
HB_FUNC_EXTERN( HGETVALUEAT );
HB_FUNC_EXTERN( DETECTDBFROMDSN );
HB_FUNC_EXTERN( SR_ADDCONNECTION );
HB_FUNC_EXTERN( VALTYPE );
HB_FUNC_EXTERN( ALLTRIM );
HB_FUNC_EXTERN( UPPER );

#undef HB_PRG_PCODE_VER
#define HB_PRG_PCODE_VER 10

#include "hbapi.h"

HB_INIT_SYMBOLS_BEGIN( hb_vm_SymbolInit_DEMO01 )
{ "MAIN", {HB_FS_PUBLIC | HB_FS_LOCAL | HB_FS_FIRST}, {HB_FUNCNAME( MAIN )}, &ModuleFakeDyn },
{ "QOUT", {HB_FS_PUBLIC}, {HB_FUNCNAME( QOUT )}, NULL },
{ "SR_USEDELETEDS", {HB_FS_PUBLIC}, {HB_FUNCNAME( SR_USEDELETEDS )}, NULL },
{ "SR_SETFASTOPEN", {HB_FS_PUBLIC}, {HB_FUNCNAME( SR_SETFASTOPEN )}, NULL },
{ "SR_SETGOTOPONSCOPE", {HB_FS_PUBLIC}, {HB_FUNCNAME( SR_SETGOTOPONSCOPE )}, NULL },
{ "SR_MAXROWCACHE", {HB_FS_PUBLIC}, {HB_FUNCNAME( SR_MAXROWCACHE )}, NULL },
{ "SR_SETBASELANG", {HB_FS_PUBLIC}, {HB_FUNCNAME( SR_SETBASELANG )}, NULL },
{ "SR_MSG", {HB_FS_PUBLIC}, {HB_FUNCNAME( SR_MSG )}, NULL },
{ "SR_SETSYNTHETICINDEX", {HB_FS_PUBLIC}, {HB_FUNCNAME( SR_SETSYNTHETICINDEX )}, NULL },
{ "SR_SETSYNTHETICINDEXMINIMUN", {HB_FS_PUBLIC}, {HB_FUNCNAME( SR_SETSYNTHETICINDEXMINIMUN )}, NULL },
{ "SETPGSOLDBEHAVIOR", {HB_FS_PUBLIC}, {HB_FUNCNAME( SETPGSOLDBEHAVIOR )}, NULL },
{ "CONNECT", {HB_FS_PUBLIC | HB_FS_LOCAL}, {HB_FUNCNAME( CONNECT )}, &ModuleFakeDyn },
{ "RDDSETDEFAULT", {HB_FS_PUBLIC}, {HB_FUNCNAME( RDDSETDEFAULT )}, NULL },
{ "__SETCENTURY", {HB_FS_PUBLIC}, {HB_FUNCNAME( __SETCENTURY )}, NULL },
{ "SET", {HB_FS_PUBLIC}, {HB_FUNCNAME( SET )}, NULL },
{ "AVETOR", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "SR_GETCONNECTION", {HB_FS_PUBLIC}, {HB_FUNCNAME( SR_GETCONNECTION )}, NULL },
{ "EXEC", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "NERR", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "ALERT", {HB_FS_PUBLIC}, {HB_FUNCNAME( ALERT )}, NULL },
{ "VALTOPRG", {HB_FS_PUBLIC}, {HB_FUNCNAME( VALTOPRG )}, NULL },
{ "LEN", {HB_FS_PUBLIC}, {HB_FUNCNAME( LEN )}, NULL },
{ "DBCLOSEALL", {HB_FS_PUBLIC}, {HB_FUNCNAME( DBCLOSEALL )}, NULL },
{ "SR_END", {HB_FS_PUBLIC}, {HB_FUNCNAME( SR_END )}, NULL },
{ "SQLRDD", {HB_FS_PUBLIC}, {HB_FUNCNAME( SQLRDD )}, NULL },
{ "SQLEX", {HB_FS_PUBLIC}, {HB_FUNCNAME( SQLEX )}, NULL },
{ "SR_ODBC", {HB_FS_PUBLIC}, {HB_FUNCNAME( SR_ODBC )}, NULL },
{ "SR_PGS", {HB_FS_PUBLIC}, {HB_FUNCNAME( SR_PGS )}, NULL },
{ "SR_MYSQL", {HB_FS_PUBLIC}, {HB_FUNCNAME( SR_MYSQL )}, NULL },
{ "SR_ORACLE", {HB_FS_PUBLIC}, {HB_FUNCNAME( SR_ORACLE )}, NULL },
{ "SR_FIREBIRD", {HB_FS_PUBLIC}, {HB_FUNCNAME( SR_FIREBIRD )}, NULL },
{ "DBFNTX", {HB_FS_PUBLIC}, {HB_FUNCNAME( DBFNTX )}, NULL },
{ "DBFCDX", {HB_FS_PUBLIC}, {HB_FUNCNAME( DBFCDX )}, NULL },
{ "DBFFPT", {HB_FS_PUBLIC}, {HB_FUNCNAME( DBFFPT )}, NULL },
{ "DBFDBT", {HB_FS_PUBLIC}, {HB_FUNCNAME( DBFDBT )}, NULL },
{ "CRDDNAME", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "__MVPUBLIC", {HB_FS_PUBLIC}, {HB_FUNCNAME( __MVPUBLIC )}, NULL },
{ "SETMODE", {HB_FS_PUBLIC}, {HB_FUNCNAME( SETMODE )}, NULL },
{ "HB_READINI", {HB_FS_PUBLIC}, {HB_FUNCNAME( HB_READINI )}, NULL },
{ "__QUIT", {HB_FS_PUBLIC}, {HB_FUNCNAME( __QUIT )}, NULL },
{ "HGETKEYS", {HB_FS_PUBLIC}, {HB_FUNCNAME( HGETKEYS )}, NULL },
{ "SCROLL", {HB_FS_PUBLIC}, {HB_FUNCNAME( SCROLL )}, NULL },
{ "SETPOS", {HB_FS_PUBLIC}, {HB_FUNCNAME( SETPOS )}, NULL },
{ "DEVPOS", {HB_FS_PUBLIC}, {HB_FUNCNAME( DEVPOS )}, NULL },
{ "DEVOUT", {HB_FS_PUBLIC}, {HB_FUNCNAME( DEVOUT )}, NULL },
{ "PADC", {HB_FS_PUBLIC}, {HB_FUNCNAME( PADC )}, NULL },
{ "ACHOICE", {HB_FS_PUBLIC}, {HB_FUNCNAME( ACHOICE )}, NULL },
{ "HGETVALUEAT", {HB_FS_PUBLIC}, {HB_FUNCNAME( HGETVALUEAT )}, NULL },
{ "DETECTDBFROMDSN", {HB_FS_PUBLIC}, {HB_FUNCNAME( DETECTDBFROMDSN )}, NULL },
{ "SR_ADDCONNECTION", {HB_FS_PUBLIC}, {HB_FUNCNAME( SR_ADDCONNECTION )}, NULL },
{ "VALTYPE", {HB_FS_PUBLIC}, {HB_FUNCNAME( VALTYPE )}, NULL },
{ "ALLTRIM", {HB_FS_PUBLIC}, {HB_FUNCNAME( ALLTRIM )}, NULL },
{ "UPPER", {HB_FS_PUBLIC}, {HB_FUNCNAME( UPPER )}, NULL },
{ "I", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "NCONNECTIONTYPE", {HB_FS_PUBLIC}, {NULL}, NULL }
HB_INIT_SYMBOLS_EX_END( hb_vm_SymbolInit_DEMO01, __PRG_SOURCE__,  0x000a )

#if defined( HB_PRAGMA_STARTUP )
   #pragma startup hb_vm_SymbolInit_DEMO01
#elif defined( HB_DATASEG_STARTUP )
   #define HB_DATASEG_BODY    HB_DATASEG_FUNC( hb_vm_SymbolInit_DEMO01 )
   #include "hbiniseg.h"
#endif

HB_FUNC( MAIN )
{
   static const BYTE pcode[] =
   {
	HB_P_FRAME, 3, 2,	/* locals, params */
/* 00003 */ HB_P_BASELINE, 19, 0,	/* 19 */
	HB_P_PUSHSYMNEAR, 1,	/* QOUT */
	HB_P_PUSHNIL,
	HB_P_PUSHSTRSHORT, 1,	/* 1 */
	0, 
	HB_P_DOSHORT, 1,
/* 00014 */ HB_P_LINEOFFSET, 1,	/* 20 */
	HB_P_PUSHSYMNEAR, 1,	/* QOUT */
	HB_P_PUSHNIL,
	HB_P_PUSHSTRSHORT, 11,	/* 11 */
	'd', 'e', 'm', 'o', '0', '1', '.', 'e', 'x', 'e', 0, 
	HB_P_DOSHORT, 1,
/* 00034 */ HB_P_LINEOFFSET, 2,	/* 21 */
	HB_P_PUSHSYMNEAR, 1,	/* QOUT */
	HB_P_PUSHNIL,
	HB_P_PUSHSTRSHORT, 1,	/* 1 */
	0, 
	HB_P_DOSHORT, 1,
/* 00044 */ HB_P_LINEOFFSET, 3,	/* 22 */
	HB_P_PUSHSYMNEAR, 1,	/* QOUT */
	HB_P_PUSHNIL,
	HB_P_PUSHSTRSHORT, 18,	/* 18 */
	'S', 'm', 'a', 'l', 'l', ' ', 'S', 'Q', 'L', 'R', 'D', 'D', ' ', 'd', 'e', 'm', 'o', 0, 
	HB_P_DOSHORT, 1,
/* 00071 */ HB_P_LINEOFFSET, 4,	/* 23 */
	HB_P_PUSHSYMNEAR, 1,	/* QOUT */
	HB_P_PUSHNIL,
	HB_P_PUSHSTRSHORT, 28,	/* 28 */
	'(', 'c', ')', ' ', '2', '0', '0', '3', ' ', '-', ' ', 'M', 'a', 'r', 'c', 'e', 'l', 'o', ' ', 'L', 'o', 'm', 'b', 'a', 'r', 'd', 'o', 0, 
	HB_P_DOSHORT, 1,
/* 00108 */ HB_P_LINEOFFSET, 5,	/* 24 */
	HB_P_PUSHSYMNEAR, 1,	/* QOUT */
	HB_P_PUSHNIL,
	HB_P_PUSHSTRSHORT, 1,	/* 1 */
	0, 
	HB_P_DOSHORT, 1,
/* 00118 */ HB_P_LINEOFFSET, 7,	/* 26 */
	HB_P_PUSHSYMNEAR, 1,	/* QOUT */
	HB_P_PUSHNIL,
	HB_P_PUSHSTRSHORT, 26,	/* 26 */
	'C', 'o', 'n', 'n', 'e', 'c', 't', 'i', 'n', 'g', ' ', 't', 'o', ' ', 'd', 'a', 't', 'a', 'b', 'a', 's', 'e', '.', '.', '.', 0, 
	HB_P_DOSHORT, 1,
/* 00153 */ HB_P_LINEOFFSET, 9,	/* 28 */
	HB_P_PUSHSYMNEAR, 2,	/* SR_USEDELETEDS */
	HB_P_PUSHNIL,
	HB_P_FALSE,
	HB_P_DOSHORT, 1,
/* 00161 */ HB_P_LINEOFFSET, 10,	/* 29 */
	HB_P_PUSHSYMNEAR, 3,	/* SR_SETFASTOPEN */
	HB_P_PUSHNIL,
	HB_P_TRUE,
	HB_P_DOSHORT, 1,
/* 00169 */ HB_P_LINEOFFSET, 11,	/* 30 */
	HB_P_PUSHSYMNEAR, 4,	/* SR_SETGOTOPONSCOPE */
	HB_P_PUSHNIL,
	HB_P_TRUE,
	HB_P_DOSHORT, 1,
/* 00177 */ HB_P_LINEOFFSET, 12,	/* 31 */
	HB_P_PUSHSYMNEAR, 5,	/* SR_MAXROWCACHE */
	HB_P_PUSHNIL,
	HB_P_PUSHBYTE, 100,	/* 100 */
	HB_P_DOSHORT, 1,
/* 00186 */ HB_P_LINEOFFSET, 13,	/* 32 */
	HB_P_PUSHSYMNEAR, 6,	/* SR_SETBASELANG */
	HB_P_PUSHNIL,
	HB_P_PUSHBYTE, 2,	/* 2 */
	HB_P_DOSHORT, 1,
/* 00195 */ HB_P_LINEOFFSET, 14,	/* 33 */
	HB_P_PUSHSYMNEAR, 7,	/* SR_MSG */
	HB_P_PUSHNIL,
	HB_P_PUSHBYTE, 2,	/* 2 */
	HB_P_DOSHORT, 1,
/* 00204 */ HB_P_LINEOFFSET, 15,	/* 34 */
	HB_P_PUSHSYMNEAR, 8,	/* SR_SETSYNTHETICINDEX */
	HB_P_PUSHNIL,
	HB_P_FALSE,
	HB_P_DOSHORT, 1,
/* 00212 */ HB_P_LINEOFFSET, 16,	/* 35 */
	HB_P_PUSHSYMNEAR, 9,	/* SR_SETSYNTHETICINDEXMINIMUN */
	HB_P_PUSHNIL,
	HB_P_PUSHBYTE, 10,	/* 10 */
	HB_P_DOSHORT, 1,
/* 00221 */ HB_P_LINEOFFSET, 17,	/* 36 */
	HB_P_PUSHSYMNEAR, 10,	/* SETPGSOLDBEHAVIOR */
	HB_P_PUSHNIL,
	HB_P_TRUE,
	HB_P_DOSHORT, 1,
/* 00229 */ HB_P_LINEOFFSET, 19,	/* 38 */
	HB_P_PUSHSYMNEAR, 11,	/* CONNECT */
	HB_P_PUSHNIL,
	HB_P_PUSHLOCALREF, 1, 0,	/* CRDD */
	HB_P_PUSHLOCALNEAR, 2,	/* CDSN */
	HB_P_PUSHNIL,
	HB_P_PUSHNIL,
	HB_P_PUSHNIL,
	HB_P_PUSHNIL,
	HB_P_PUSHNIL,
	HB_P_TRUE,
	HB_P_DOSHORT, 8,
/* 00247 */ HB_P_LINEOFFSET, 21,	/* 40 */
	HB_P_PUSHSYMNEAR, 12,	/* RDDSETDEFAULT */
	HB_P_PUSHNIL,
	HB_P_PUSHSTRSHORT, 7,	/* 7 */
	'S', 'Q', 'L', 'R', 'D', 'D', 0, 
	HB_P_DOSHORT, 1,
/* 00263 */ HB_P_LINEOFFSET, 23,	/* 42 */
	HB_P_PUSHSYMNEAR, 13,	/* __SETCENTURY */
	HB_P_PUSHNIL,
	HB_P_PUSHSTRSHORT, 3,	/* 3 */
	'O', 'N', 0, 
	HB_P_DOSHORT, 1,
/* 00275 */ HB_P_LINEOFFSET, 24,	/* 43 */
	HB_P_PUSHSYMNEAR, 14,	/* SET */
	HB_P_PUSHNIL,
	HB_P_PUSHBYTE, 26,	/* 26 */
	HB_P_PUSHSTRSHORT, 4,	/* 4 */
	'O', 'F', 'F', 0, 
	HB_P_DOSHORT, 2,
/* 00290 */ HB_P_LINEOFFSET, 25,	/* 44 */
	HB_P_PUSHSYMNEAR, 14,	/* SET */
	HB_P_PUSHNIL,
	HB_P_PUSHBYTE, 4,	/* 4 */
	HB_P_PUSHSYMNEAR, 13,	/* __SETCENTURY */
	HB_P_PUSHNIL,
	HB_P_FUNCTIONSHORT, 0,
	HB_P_JUMPFALSENEAR, 17,	/* 17 (abs: 00319) */
	HB_P_PUSHSTRSHORT, 11,	/* 11 */
	'd', 'd', '/', 'm', 'm', '/', 'y', 'y', 'y', 'y', 0, 
	HB_P_JUMPNEAR, 13,	/* 13 (abs: 00330) */
	HB_P_PUSHSTRSHORT, 9,	/* 9 */
	'd', 'd', '/', 'm', 'm', '/', 'y', 'y', 0, 
	HB_P_DOSHORT, 2,
/* 00332 */ HB_P_LINEOFFSET, 26,	/* 45 */
	HB_P_PUSHSYMNEAR, 14,	/* SET */
	HB_P_PUSHNIL,
	HB_P_PUSHBYTE, 5,	/* 5 */
	HB_P_PUSHINT, 208, 7,	/* 2000 */
	HB_P_DOSHORT, 2,
/* 00344 */ HB_P_LINEOFFSET, 27,	/* 46 */
	HB_P_PUSHSYMNEAR, 14,	/* SET */
	HB_P_PUSHNIL,
	HB_P_PUSHBYTE, 27,	/* 27 */
	HB_P_PUSHSTRSHORT, 3,	/* 3 */
	'O', 'N', 0, 
	HB_P_DOSHORT, 2,
/* 00358 */ HB_P_LINEOFFSET, 28,	/* 47 */
	HB_P_PUSHSYMNEAR, 14,	/* SET */
	HB_P_PUSHNIL,
	HB_P_PUSHBYTE, 11,	/* 11 */
	HB_P_PUSHSTRSHORT, 3,	/* 3 */
	'O', 'N', 0, 
	HB_P_DOSHORT, 2,
/* 00372 */ HB_P_LINEOFFSET, 29,	/* 48 */
	HB_P_PUSHSYMNEAR, 14,	/* SET */
	HB_P_PUSHNIL,
	HB_P_ONE,
	HB_P_PUSHSTRSHORT, 3,	/* 3 */
	'O', 'N', 0, 
	HB_P_DOSHORT, 2,
/* 00385 */ HB_P_LINEOFFSET, 30,	/* 49 */
	HB_P_PUSHSYMNEAR, 14,	/* SET */
	HB_P_PUSHNIL,
	HB_P_PUSHBYTE, 32,	/* 32 */
	HB_P_PUSHSTRSHORT, 4,	/* 4 */
	'O', 'F', 'F', 0, 
	HB_P_DOSHORT, 2,
/* 00400 */ HB_P_LINEOFFSET, 31,	/* 50 */
	HB_P_PUSHSYMNEAR, 14,	/* SET */
	HB_P_PUSHNIL,
	HB_P_PUSHBYTE, 35,	/* 35 */
	HB_P_PUSHSTRSHORT, 3,	/* 3 */
	'O', 'N', 0, 
	HB_P_DOSHORT, 2,
/* 00414 */ HB_P_LINEOFFSET, 32,	/* 51 */
	HB_P_PUSHSYMNEAR, 14,	/* SET */
	HB_P_PUSHNIL,
	HB_P_PUSHBYTE, 8,	/* 8 */
	HB_P_PUSHSTRSHORT, 4,	/* 4 */
	'O', 'F', 'F', 0, 
	HB_P_DOSHORT, 2,
/* 00429 */ HB_P_LINEOFFSET, 33,	/* 52 */
	HB_P_PUSHSYMNEAR, 14,	/* SET */
	HB_P_PUSHNIL,
	HB_P_PUSHBYTE, 45,	/* 45 */
	HB_P_PUSHSTRSHORT, 3,	/* 3 */
	'O', 'N', 0, 
	HB_P_DOSHORT, 2,
/* 00443 */ HB_P_LINEOFFSET, 34,	/* 53 */
	HB_P_PUSHSYMNEAR, 14,	/* SET */
	HB_P_PUSHNIL,
	HB_P_PUSHBYTE, 44,	/* 44 */
	HB_P_PUSHSTRSHORT, 3,	/* 3 */
	'O', 'N', 0, 
	HB_P_DOSHORT, 2,
/* 00457 */ HB_P_LINEOFFSET, 35,	/* 54 */
	HB_P_PUSHSYMNEAR, 14,	/* SET */
	HB_P_PUSHNIL,
	HB_P_PUSHBYTE, 43,	/* 43 */
	HB_P_PUSHSTRSHORT, 3,	/* 3 */
	'O', 'N', 0, 
	HB_P_DOSHORT, 2,
/* 00471 */ HB_P_LINEOFFSET, 37,	/* 56 */
	HB_P_ARRAYGEN, 0, 0,	/* 0 */
	HB_P_POPVARIABLE, 15, 0,	/* AVETOR */
/* 00479 */ HB_P_LINEOFFSET, 38,	/* 57 */
	HB_P_PUSHSYMNEAR, 16,	/* SR_GETCONNECTION */
	HB_P_PUSHNIL,
	HB_P_FUNCTIONSHORT, 0,
	HB_P_POPLOCALNEAR, 5,	/* OSQL */
/* 00488 */ HB_P_LINEOFFSET, 39,	/* 58 */
	HB_P_MESSAGE, 17, 0,	/* EXEC */
	HB_P_PUSHLOCALNEAR, 5,	/* OSQL */
	HB_P_PUSHSTRSHORT, 106,	/* 106 */
	's', 'e', 'l', 'e', 'c', 't', ' ', 'm', 'a', 'x', '(', 'f', 'c', 'f', 'o', '.', 'c', 'o', 'd', 'c', 'f', 'o', ')', ' ', 'a', 's', ' ', 'c', 'o', 'd', 'c', 'f', 'o', ' ', 'f', 'r', 'o', 'm', ' ', 'f', 'c', 'f', 'o', ' ', '(', 'n', 'o', 'l', 'o', 'c', 'k', ')', ' ', 'w', 'h', 'e', 'r', 'e', ' ', 'f', 'c', 'f', 'o', '.', 'c', 'o', 'd', 'c', 'o', 'l', 'i', 'g', 'a', 'd', 'a', ' ', '=', ' ', '0', ' ', 'a', 'n', 'd', ' ', 'f', 'c', 'f', 'o', '.', 'c', 'o', 'd', 'c', 'f', 'o', ' ', 'l', 'i', 'k', 'e', ' ', 39, '0', '%', 39, 0, 
	HB_P_PUSHSTRSHORT, 9,	/* 9 */
	'C', 'O', 'L', 'I', 'G', 'A', 'D', 'A', 0, 
	HB_P_TRUE,
	HB_P_TRUE,
	HB_P_PUSHMEMVARREF, 15, 0,	/* AVETOR */
	HB_P_PUSHNIL,
	HB_P_PUSHNIL,
	HB_P_PUSHNIL,
	HB_P_TRUE,
	HB_P_SENDSHORT, 9,
	HB_P_POPVARIABLE, 18, 0,	/* NERR */
/* 00628 */ HB_P_LINEOFFSET, 41,	/* 60 */
	HB_P_PUSHSYMNEAR, 19,	/* ALERT */
	HB_P_PUSHNIL,
	HB_P_PUSHSYMNEAR, 20,	/* VALTOPRG */
	HB_P_PUSHNIL,
	HB_P_PUSHVARIABLE, 18, 0,	/* NERR */
	HB_P_FUNCTIONSHORT, 1,
	HB_P_DOSHORT, 1,
/* 00643 */ HB_P_LINEOFFSET, 43,	/* 62 */
	HB_P_PUSHSYMNEAR, 21,	/* LEN */
	HB_P_PUSHNIL,
	HB_P_PUSHVARIABLE, 15, 0,	/* AVETOR */
	HB_P_FUNCTIONSHORT, 1,
	HB_P_ZERO,
	HB_P_GREATER,
	HB_P_JUMPFALSENEAR, 18,	/* 18 (abs: 00673) */
/* 00657 */ HB_P_LINEOFFSET, 44,	/* 63 */
	HB_P_PUSHSYMNEAR, 1,	/* QOUT */
	HB_P_PUSHNIL,
	HB_P_PUSHMEMVAR, 15, 0,	/* AVETOR */
	HB_P_ONE,
	HB_P_ARRAYPUSH,
	HB_P_ONE,
	HB_P_ARRAYPUSH,
	HB_P_DOSHORT, 1,
	HB_P_JUMPNEAR, 47,	/* 47 (abs: 00718) */
/* 00673 */ HB_P_LINEOFFSET, 46,	/* 65 */
	HB_P_PUSHSYMNEAR, 1,	/* QOUT */
	HB_P_PUSHNIL,
	HB_P_PUSHSTRSHORT, 36,	/* 36 */
	'E', 'r', 'r', 'o', ' ', 'a', 'o', ' ', 'p', 'e', 'g', 'a', 'r', ' ', 'o', ' ', 'r', 'e', 't', 'o', 'r', 'n', 'o', ' ', 'd', 'a', ' ', 'c', 'o', 'n', 's', 'u', 'l', 't', 'a', 0, 
	HB_P_DOSHORT, 1,
/* 00718 */ HB_P_LINEOFFSET, 51,	/* 70 */
	HB_P_PUSHSYMNEAR, 22,	/* DBCLOSEALL */
	HB_P_PUSHNIL,
	HB_P_DOSHORT, 0,
/* 00725 */ HB_P_LINEOFFSET, 52,	/* 71 */
	HB_P_PUSHSYMNEAR, 23,	/* SR_END */
	HB_P_PUSHNIL,
	HB_P_DOSHORT, 0,
/* 00732 */ HB_P_LINEOFFSET, 53,	/* 72 */
	HB_P_PUSHNIL,
	HB_P_RETVALUE,
	HB_P_ENDPROC
/* 00737 */
   };

   hb_vmExecute( pcode, symbols );
}

HB_FUNC( CONNECT )
{
   static const BYTE pcode[] =
   {
	HB_P_FRAME, 11, 2,	/* locals, params */
/* 00003 */ HB_P_BASELINE, 38, 0,	/* 38 */
	HB_P_PUSHSYMNEAR, 36,	/* __MVPUBLIC */
	HB_P_PUSHNIL,
	HB_P_PUSHSYMNEAR, 35,	/* CRDDNAME */
	HB_P_DOSHORT, 1,
/* 00013 */ HB_P_LINEOFFSET, 2,	/* 40 */
	HB_P_PUSHSYMNEAR, 37,	/* SETMODE */
	HB_P_PUSHNIL,
	HB_P_PUSHBYTE, 35,	/* 35 */
	HB_P_PUSHBYTE, 80,	/* 80 */
	HB_P_DOSHORT, 2,
/* 00024 */ HB_P_LINEOFFSET, 4,	/* 42 */
	HB_P_PUSHSYMNEAR, 38,	/* HB_READINI */
	HB_P_PUSHNIL,
	HB_P_PUSHSTRSHORT, 11,	/* 11 */
	's', 'q', 'l', 'r', 'd', 'd', '.', 'i', 'n', 'i', 0, 
	HB_P_FALSE,
	HB_P_PUSHNIL,
	HB_P_FALSE,
	HB_P_FUNCTIONSHORT, 4,
	HB_P_POPLOCALNEAR, 8,	/* HINIFILE */
/* 00049 */ HB_P_LINEOFFSET, 6,	/* 44 */
	HB_P_PUSHLOCALNEAR, 8,	/* HINIFILE */
	HB_P_PUSHNIL,
	HB_P_EXACTLYEQUAL,
	HB_P_JUMPFALSENEAR, 49,	/* 49 (abs: 00104) */
/* 00057 */ HB_P_LINEOFFSET, 7,	/* 45 */
	HB_P_PUSHSYMNEAR, 1,	/* QOUT */
	HB_P_PUSHNIL,
	HB_P_PUSHSTRSHORT, 31,	/* 31 */
	'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'r', 'e', 'a', 'd', ' ', 'f', 'r', 'o', 'm', ' ', 's', 'q', 'l', 'r', 'd', 'd', '.', 'i', 'n', 'i', 0, 
	HB_P_DOSHORT, 1,
/* 00097 */ HB_P_LINEOFFSET, 8,	/* 46 */
	HB_P_PUSHSYMNEAR, 39,	/* __QUIT */
	HB_P_PUSHNIL,
	HB_P_DOSHORT, 0,
/* 00104 */ HB_P_LINEOFFSET, 11,	/* 49 */
	HB_P_PUSHLOCALNEAR, 2,	/* CDATABASE */
	HB_P_PUSHNIL,
	HB_P_EXACTLYEQUAL,
	HB_P_JUMPFALSE, 78, 1,	/* 334 (abs: 00444) */
/* 00113 */ HB_P_LINEOFFSET, 12,	/* 50 */
	HB_P_PUSHSYMNEAR, 40,	/* HGETKEYS */
	HB_P_PUSHNIL,
	HB_P_PUSHLOCALNEAR, 8,	/* HINIFILE */
	HB_P_FUNCTIONSHORT, 1,
	HB_P_POPLOCALNEAR, 9,	/* AKEYS */
/* 00124 */ HB_P_LINEOFFSET, 13,	/* 51 */
	HB_P_PUSHSYMNEAR, 21,	/* LEN */
	HB_P_PUSHNIL,
	HB_P_PUSHLOCALNEAR, 9,	/* AKEYS */
	HB_P_FUNCTIONSHORT, 1,
	HB_P_ZERO,
	HB_P_EXACTLYEQUAL,
	HB_P_JUMPFALSENEAR, 60,	/* 60 (abs: 00195) */
/* 00137 */ HB_P_LINEOFFSET, 14,	/* 52 */
	HB_P_PUSHSYMNEAR, 1,	/* QOUT */
	HB_P_PUSHNIL,
	HB_P_PUSHSTRSHORT, 39,	/* 39 */
	'N', 'o', ' ', 'c', 'o', 'n', 'n', 'e', 'c', 't', 'i', 'o', 'n', 's', ' ', 'a', 'v', 'a', 'i', 'l', 'a', 'b', 'l', 'e', ' ', 'i', 'n', ' ', 's', 'q', 'l', 'r', 'd', 'd', '.', 'i', 'n', 'i', 0, 
	HB_P_DOSHORT, 1,
/* 00185 */ HB_P_LINEOFFSET, 15,	/* 53 */
	HB_P_PUSHSYMNEAR, 39,	/* __QUIT */
	HB_P_PUSHNIL,
	HB_P_DOSHORT, 0,
	HB_P_JUMP, 168, 0,	/* 168 (abs: 00360) */
/* 00195 */ HB_P_LINEOFFSET, 16,	/* 54 */
	HB_P_PUSHSYMNEAR, 21,	/* LEN */
	HB_P_PUSHNIL,
	HB_P_PUSHLOCALNEAR, 9,	/* AKEYS */
	HB_P_FUNCTIONSHORT, 1,
	HB_P_ONE,
	HB_P_EXACTLYEQUAL,
	HB_P_JUMPFALSENEAR, 11,	/* 11 (abs: 00217) */
/* 00208 */ HB_P_LINEOFFSET, 17,	/* 55 */
	HB_P_LOCALNEARSETINT, 10, 1, 0,	/* NKEY 1*/
	HB_P_JUMP, 146, 0,	/* 146 (abs: 00360) */
/* 00217 */ HB_P_LINEOFFSET, 19,	/* 57 */
	HB_P_PUSHSYMNEAR, 41,	/* SCROLL */
	HB_P_PUSHNIL,
	HB_P_DOSHORT, 0,
	HB_P_PUSHSYMNEAR, 42,	/* SETPOS */
	HB_P_PUSHNIL,
	HB_P_ZERO,
	HB_P_ZERO,
	HB_P_DOSHORT, 2,
/* 00231 */ HB_P_LINEOFFSET, 20,	/* 58 */
	HB_P_PUSHSYMNEAR, 43,	/* DEVPOS */
	HB_P_PUSHNIL,
	HB_P_PUSHBYTE, 5,	/* 5 */
	HB_P_ONE,
	HB_P_DOSHORT, 2,
	HB_P_PUSHSYMNEAR, 44,	/* DEVOUT */
	HB_P_PUSHNIL,
	HB_P_PUSHSYMNEAR, 45,	/* PADC */
	HB_P_PUSHNIL,
	HB_P_PUSHSTRSHORT, 25,	/* 25 */
	'C', 'h', 'o', 'o', 's', 'e', ' ', 'c', 'o', 'n', 'n', 'e', 'c', 't', 'i', 'o', 'n', ' ', 'o', 'p', 't', 'i', 'o', 'n', 0, 
	HB_P_PUSHBYTE, 80,	/* 80 */
	HB_P_FUNCTIONSHORT, 2,
	HB_P_DOSHORT, 1,
/* 00280 */ HB_P_LINEOFFSET, 21,	/* 59 */
	HB_P_PUSHSYMNEAR, 46,	/* ACHOICE */
	HB_P_PUSHNIL,
	HB_P_PUSHBYTE, 5,	/* 5 */
	HB_P_PUSHBYTE, 20,	/* 20 */
	HB_P_PUSHBYTE, 22,	/* 22 */
	HB_P_PUSHBYTE, 60,	/* 60 */
	HB_P_PUSHLOCALNEAR, 9,	/* AKEYS */
	HB_P_FUNCTIONSHORT, 5,
	HB_P_POPLOCALNEAR, 10,	/* NKEY */
/* 00299 */ HB_P_LINEOFFSET, 22,	/* 60 */
	HB_P_PUSHSYMNEAR, 41,	/* SCROLL */
	HB_P_PUSHNIL,
	HB_P_DOSHORT, 0,
	HB_P_PUSHSYMNEAR, 42,	/* SETPOS */
	HB_P_PUSHNIL,
	HB_P_ZERO,
	HB_P_ZERO,
	HB_P_DOSHORT, 2,
/* 00313 */ HB_P_LINEOFFSET, 24,	/* 62 */
	HB_P_PUSHLOCALNEAR, 10,	/* NKEY */
	HB_P_ZERO,
	HB_P_EXACTLYEQUAL,
	HB_P_JUMPFALSENEAR, 41,	/* 41 (abs: 00360) */
/* 00321 */ HB_P_LINEOFFSET, 25,	/* 63 */
	HB_P_PUSHSYMNEAR, 1,	/* QOUT */
	HB_P_PUSHNIL,
	HB_P_PUSHSTRSHORT, 23,	/* 23 */
	'N', 'o', ' ', 'c', 'o', 'n', 'n', 'e', 'c', 't', 'i', 'o', 'n', ' ', 's', 'e', 'l', 'e', 'c', 't', 'e', 'd', 0, 
	HB_P_DOSHORT, 1,
/* 00353 */ HB_P_LINEOFFSET, 26,	/* 64 */
	HB_P_PUSHSYMNEAR, 39,	/* __QUIT */
	HB_P_PUSHNIL,
	HB_P_DOSHORT, 0,
/* 00360 */ HB_P_LINEOFFSET, 30,	/* 68 */
	HB_P_PUSHSYMNEAR, 47,	/* HGETVALUEAT */
	HB_P_PUSHNIL,
	HB_P_PUSHLOCALNEAR, 8,	/* HINIFILE */
	HB_P_PUSHLOCALNEAR, 10,	/* NKEY */
	HB_P_FUNCTIONSHORT, 2,
	HB_P_POPLOCALNEAR, 13,	/* HDSN */
/* 00373 */ HB_P_LINEOFFSET, 32,	/* 70 */
	HB_P_PUSHSTRSHORT, 11,	/* 11 */
	'C', 'O', 'N', 'N', 'S', 'T', 'R', 'I', 'N', 'G', 0, 
	HB_P_PUSHLOCALNEAR, 13,	/* HDSN */
	HB_P_INSTRING,
	HB_P_JUMPTRUE, 196, 0,	/* 196 (abs: 00587) */
/* 00394 */ HB_P_LINEOFFSET, 33,	/* 71 */
	HB_P_PUSHSYMNEAR, 1,	/* QOUT */
	HB_P_PUSHNIL,
	HB_P_PUSHSTRSHORT, 25,	/* 25 */
	'C', 'o', 'n', 'n', 'S', 't', 'r', 'i', 'n', 'g', ' ', 'n', 'o', 't', ' ', 'f', 'o', 'u', 'n', 'd', ' ', 'i', 'n', ' ', 0, 
	HB_P_PUSHLOCALNEAR, 9,	/* AKEYS */
	HB_P_PUSHLOCALNEAR, 10,	/* NKEY */
	HB_P_ARRAYPUSH,
	HB_P_PLUS,
	HB_P_DOSHORT, 1,
/* 00434 */ HB_P_LINEOFFSET, 34,	/* 72 */
	HB_P_PUSHSYMNEAR, 39,	/* __QUIT */
	HB_P_PUSHNIL,
	HB_P_DOSHORT, 0,
	HB_P_JUMP, 146, 0,	/* 146 (abs: 00587) */
/* 00444 */ HB_P_LINEOFFSET, 37,	/* 75 */
	HB_P_PUSHLOCALNEAR, 2,	/* CDATABASE */
	HB_P_PUSHLOCALNEAR, 8,	/* HINIFILE */
	HB_P_INSTRING,
	HB_P_JUMPTRUENEAR, 63,	/* 63 (abs: 00514) */
/* 00453 */ HB_P_LINEOFFSET, 38,	/* 76 */
	HB_P_PUSHSYMNEAR, 1,	/* QOUT */
	HB_P_PUSHNIL,
	HB_P_PUSHSTRSHORT, 13,	/* 13 */
	'C', 'o', 'n', 'n', 'e', 'c', 't', 'i', 'o', 'n', ' ', '[', 0, 
	HB_P_PUSHLOCALNEAR, 2,	/* CDATABASE */
	HB_P_PLUS,
	HB_P_PUSHSTRSHORT, 26,	/* 26 */
	']', ' ', 'n', 'o', 't', ' ', 'f', 'o', 'u', 'n', 'd', ' ', 'i', 'n', ' ', 's', 'q', 'l', 'r', 'd', 'd', '.', 'i', 'n', 'i', 0, 
	HB_P_PLUS,
	HB_P_DOSHORT, 1,
/* 00507 */ HB_P_LINEOFFSET, 39,	/* 77 */
	HB_P_PUSHSYMNEAR, 39,	/* __QUIT */
	HB_P_PUSHNIL,
	HB_P_DOSHORT, 0,
/* 00514 */ HB_P_LINEOFFSET, 42,	/* 80 */
	HB_P_PUSHLOCALNEAR, 8,	/* HINIFILE */
	HB_P_PUSHLOCALNEAR, 2,	/* CDATABASE */
	HB_P_ARRAYPUSH,
	HB_P_POPLOCALNEAR, 13,	/* HDSN */
/* 00523 */ HB_P_LINEOFFSET, 44,	/* 82 */
	HB_P_PUSHSTRSHORT, 11,	/* 11 */
	'C', 'O', 'N', 'N', 'S', 'T', 'R', 'I', 'N', 'G', 0, 
	HB_P_PUSHLOCALNEAR, 13,	/* HDSN */
	HB_P_INSTRING,
	HB_P_JUMPTRUENEAR, 46,	/* 46 (abs: 00587) */
/* 00543 */ HB_P_LINEOFFSET, 45,	/* 83 */
	HB_P_PUSHSYMNEAR, 1,	/* QOUT */
	HB_P_PUSHNIL,
	HB_P_PUSHSTRSHORT, 25,	/* 25 */
	'C', 'o', 'n', 'n', 'S', 't', 'r', 'i', 'n', 'g', ' ', 'n', 'o', 't', ' ', 'f', 'o', 'u', 'n', 'd', ' ', 'i', 'n', ' ', 0, 
	HB_P_PUSHLOCALNEAR, 2,	/* CDATABASE */
	HB_P_PLUS,
	HB_P_DOSHORT, 1,
/* 00580 */ HB_P_LINEOFFSET, 46,	/* 84 */
	HB_P_PUSHSYMNEAR, 39,	/* __QUIT */
	HB_P_PUSHNIL,
	HB_P_DOSHORT, 0,
/* 00587 */ HB_P_LINEOFFSET, 51,	/* 89 */
	HB_P_PUSHLOCALNEAR, 13,	/* HDSN */
	HB_P_PUSHSTRSHORT, 11,	/* 11 */
	'C', 'O', 'N', 'N', 'S', 'T', 'R', 'I', 'N', 'G', 0, 
	HB_P_ARRAYPUSH,
	HB_P_POPLOCALNEAR, 11,	/* CCONNSTRING */
/* 00607 */ HB_P_LINEOFFSET, 52,	/* 90 */
	HB_P_PUSHSYMNEAR, 48,	/* DETECTDBFROMDSN */
	HB_P_PUSHNIL,
	HB_P_PUSHLOCALNEAR, 11,	/* CCONNSTRING */
	HB_P_FUNCTIONSHORT, 1,
	HB_P_POPLOCALNEAR, 7,	/* NDETECTED */
/* 00618 */ HB_P_LINEOFFSET, 54,	/* 92 */
	HB_P_PUSHLOCALNEAR, 7,	/* NDETECTED */
	HB_P_ZERO,
	HB_P_GREATER,
	HB_P_JUMPFALSENEAR, 43,	/* 43 (abs: 00667) */
/* 00626 */ HB_P_LINEOFFSET, 55,	/* 93 */
	HB_P_PUSHSYMNEAR, 1,	/* QOUT */
	HB_P_PUSHNIL,
	HB_P_PUSHSTRSHORT, 14,	/* 14 */
	'C', 'o', 'n', 'n', 'e', 'c', 't', 'i', 'n', 'g', ' ', 't', 'o', 0, 
	HB_P_PUSHLOCALNEAR, 11,	/* CCONNSTRING */
	HB_P_DOSHORT, 2,
/* 00651 */ HB_P_LINEOFFSET, 56,	/* 94 */
	HB_P_PUSHSYMNEAR, 49,	/* SR_ADDCONNECTION */
	HB_P_PUSHNIL,
	HB_P_PUSHLOCALNEAR, 7,	/* NDETECTED */
	HB_P_PUSHLOCALNEAR, 11,	/* CCONNSTRING */
	HB_P_FUNCTIONSHORT, 2,
	HB_P_POPLOCALNEAR, 3,	/* NCNN */
	HB_P_JUMP, 217, 0,	/* 217 (abs: 00881) */
/* 00667 */ HB_P_LINEOFFSET, 58,	/* 96 */
	HB_P_PUSHSYMNEAR, 41,	/* SCROLL */
	HB_P_PUSHNIL,
	HB_P_DOSHORT, 0,
	HB_P_PUSHSYMNEAR, 42,	/* SETPOS */
	HB_P_PUSHNIL,
	HB_P_ZERO,
	HB_P_ZERO,
	HB_P_DOSHORT, 2,
/* 00681 */ HB_P_LINEOFFSET, 59,	/* 97 */
	HB_P_PUSHSYMNEAR, 19,	/* ALERT */
	HB_P_PUSHNIL,
	HB_P_PUSHSTRSHORT, 31,	/* 31 */
	'P', 'l', 'e', 'a', 's', 'e', ',', ' ', 's', 'e', 'l', 'e', 'c', 't', ' ', 'c', 'o', 'n', 'n', 'e', 'c', 't', 'i', 'o', 'n', ' ', 't', 'y', 'p', 'e', 0, 
	HB_P_PUSHSTRSHORT, 5,	/* 5 */
	'O', 'D', 'B', 'C', 0, 
	HB_P_PUSHSTRSHORT, 9,	/* 9 */
	'P', 'o', 's', 't', 'g', 'r', 'e', 's', 0, 
	HB_P_PUSHSTRSHORT, 6,	/* 6 */
	'M', 'y', 'S', 'Q', 'L', 0, 
	HB_P_PUSHSTRSHORT, 7,	/* 7 */
	'O', 'r', 'a', 'c', 'l', 'e', 0, 
	HB_P_PUSHSTRSHORT, 9,	/* 9 */
	'F', 'i', 'r', 'e', 'b', 'i', 'r', 'd', 0, 
	HB_P_ARRAYGEN, 5, 0,	/* 5 */
	HB_P_FUNCTIONSHORT, 2,
	HB_P_POPLOCALNEAR, 6,	/* NOPT */
/* 00772 */ HB_P_LINEOFFSET, 60,	/* 98 */
	HB_P_PUSHLOCALNEAR, 6,	/* NOPT */
	HB_P_ZERO,
	HB_P_GREATER,
	HB_P_JUMPFALSENEAR, 59,	/* 59 (abs: 00837) */
/* 00780 */ HB_P_LINEOFFSET, 61,	/* 99 */
	HB_P_PUSHSYMNEAR, 49,	/* SR_ADDCONNECTION */
	HB_P_PUSHNIL,
	HB_P_PUSHLOCALNEAR, 6,	/* NOPT */
	HB_P_ONE,
	HB_P_EQUAL,
	HB_P_JUMPFALSENEAR, 5,	/* 5 (abs: 00794) */
	HB_P_ONE,
	HB_P_JUMPNEAR, 37,	/* 37 (abs: 00829) */
	HB_P_PUSHLOCALNEAR, 6,	/* NOPT */
	HB_P_PUSHBYTE, 2,	/* 2 */
	HB_P_EQUAL,
	HB_P_JUMPFALSENEAR, 6,	/* 6 (abs: 00805) */
	HB_P_PUSHBYTE, 4,	/* 4 */
	HB_P_JUMPNEAR, 26,	/* 26 (abs: 00829) */
	HB_P_PUSHLOCALNEAR, 6,	/* NOPT */
	HB_P_PUSHBYTE, 3,	/* 3 */
	HB_P_EQUAL,
	HB_P_JUMPFALSENEAR, 6,	/* 6 (abs: 00816) */
	HB_P_PUSHBYTE, 3,	/* 3 */
	HB_P_JUMPNEAR, 15,	/* 15 (abs: 00829) */
	HB_P_PUSHLOCALNEAR, 6,	/* NOPT */
	HB_P_PUSHBYTE, 4,	/* 4 */
	HB_P_EQUAL,
	HB_P_JUMPFALSENEAR, 6,	/* 6 (abs: 00827) */
	HB_P_PUSHBYTE, 5,	/* 5 */
	HB_P_JUMPNEAR, 4,	/* 4 (abs: 00829) */
	HB_P_PUSHBYTE, 6,	/* 6 */
	HB_P_PUSHLOCALNEAR, 11,	/* CCONNSTRING */
	HB_P_FUNCTIONSHORT, 2,
	HB_P_POPLOCALNEAR, 3,	/* NCNN */
	HB_P_JUMPNEAR, 46,	/* 46 (abs: 00881) */
/* 00837 */ HB_P_LINEOFFSET, 63,	/* 101 */
	HB_P_PUSHSYMNEAR, 1,	/* QOUT */
	HB_P_PUSHNIL,
	HB_P_PUSHSTRSHORT, 28,	/* 28 */
	'N', 'o', ' ', 'c', 'o', 'n', 'n', 'e', 'c', 't', 'i', 'o', 'n', ' ', 't', 'y', 'p', 'e', ' ', 's', 'e', 'l', 'e', 'c', 't', 'e', 'd', 0, 
	HB_P_DOSHORT, 1,
/* 00874 */ HB_P_LINEOFFSET, 64,	/* 102 */
	HB_P_PUSHSYMNEAR, 39,	/* __QUIT */
	HB_P_PUSHNIL,
	HB_P_DOSHORT, 0,
/* 00881 */ HB_P_LINEOFFSET, 69,	/* 107 */
	HB_P_PUSHLOCALNEAR, 3,	/* NCNN */
	HB_P_ZERO,
	HB_P_LESS,
	HB_P_JUMPFALSENEAR, 66,	/* 66 (abs: 00953) */
/* 00889 */ HB_P_LINEOFFSET, 70,	/* 108 */
	HB_P_PUSHSYMNEAR, 1,	/* QOUT */
	HB_P_PUSHNIL,
	HB_P_PUSHSTRSHORT, 48,	/* 48 */
	'C', 'o', 'n', 'n', 'e', 'c', 't', 'i', 'o', 'n', ' ', 'e', 'r', 'r', 'o', 'r', '.', ' ', 'S', 'e', 'e', ' ', 's', 'q', 'l', 'e', 'r', 'r', 'o', 'r', '.', 'l', 'o', 'g', ' ', 'f', 'o', 'r', ' ', 'd', 'e', 't', 'a', 'i', 'l', 's', '.', 0, 
	HB_P_DOSHORT, 1,
/* 00946 */ HB_P_LINEOFFSET, 71,	/* 109 */
	HB_P_PUSHSYMNEAR, 39,	/* __QUIT */
	HB_P_PUSHNIL,
	HB_P_DOSHORT, 0,
/* 00953 */ HB_P_LINEOFFSET, 74,	/* 112 */
	HB_P_PUSHSYMNEAR, 50,	/* VALTYPE */
	HB_P_PUSHNIL,
	HB_P_PUSHLOCALNEAR, 1,	/* CRDD */
	HB_P_FUNCTIONSHORT, 1,
	HB_P_PUSHSTRSHORT, 2,	/* 2 */
	'C', 0, 
	HB_P_EXACTLYEQUAL,
	HB_P_JUMPFALSENEAR, 18,	/* 18 (abs: 00985) */
/* 00969 */ HB_P_LINEOFFSET, 75,	/* 113 */
	HB_P_PUSHSYMNEAR, 51,	/* ALLTRIM */
	HB_P_PUSHNIL,
	HB_P_PUSHSYMNEAR, 52,	/* UPPER */
	HB_P_PUSHNIL,
	HB_P_PUSHLOCALNEAR, 1,	/* CRDD */
	HB_P_FUNCTIONSHORT, 1,
	HB_P_FUNCTIONSHORT, 1,
	HB_P_POPLOCALNEAR, 1,	/* CRDD */
/* 00985 */ HB_P_LINEOFFSET, 78,	/* 116 */
	HB_P_PUSHLOCALNEAR, 1,	/* CRDD */
	HB_P_PUSHNIL,
	HB_P_EXACTLYEQUAL,
	HB_P_JUMPFALSE, 193, 0,	/* 193 (abs: 01184) */
/* 00994 */ HB_P_LINEOFFSET, 79,	/* 117 */
	HB_P_PUSHSYMNEAR, 19,	/* ALERT */
	HB_P_PUSHNIL,
	HB_P_PUSHSTRSHORT, 18,	/* 18 */
	'P', 'l', 'e', 'a', 's', 'e', ' ', 's', 'e', 'l', 'e', 'c', 't', ' ', 'R', 'D', 'D', 0, 
	HB_P_PUSHSTRSHORT, 10,	/* 10 */
	'A', 'u', 't', 'o', 'm', 'a', 't', 'i', 'c', 0, 
	HB_P_PUSHSTRSHORT, 15,	/* 15 */
	'S', 'Q', 'L', 'R', 'D', 'D', ' ', 'E', 'x', 't', 'r', 'e', 'm', 'e', 0, 
	HB_P_PUSHSTRSHORT, 7,	/* 7 */
	'S', 'Q', 'L', 'R', 'D', 'D', 0, 
	HB_P_ARRAYGEN, 3, 0,	/* 3 */
	HB_P_FUNCTIONSHORT, 2,
	HB_P_POPVARIABLE, 53, 0,	/* I */
/* 01065 */ HB_P_LINEOFFSET, 80,	/* 118 */
	HB_P_FALSE,
	HB_P_PUSHVARIABLE, 53, 0,	/* I */
	HB_P_ONE,
	HB_P_EXACTLYEQUAL,
	HB_P_JUMPFALSENEAR, 15,	/* 15 (abs: 01088) */
	HB_P_POP,
	HB_P_MESSAGE, 54, 0,	/* NCONNECTIONTYPE */
	HB_P_PUSHSYMNEAR, 16,	/* SR_GETCONNECTION */
	HB_P_PUSHNIL,
	HB_P_FUNCTIONSHORT, 0,
	HB_P_SENDSHORT, 0,
	HB_P_ONE,
	HB_P_EXACTLYEQUAL,
	HB_P_JUMPFALSENEAR, 16,	/* 16 (abs: 01104) */
/* 01090 */ HB_P_LINEOFFSET, 81,	/* 119 */
	HB_P_LOCALNEARSETSTR, 1, 6, 0,	/* CRDD 6*/
	'S', 'Q', 'L', 'E', 'X', 0, 
	HB_P_JUMPNEAR, 82,	/* 82 (abs: 01184) */
/* 01104 */ HB_P_LINEOFFSET, 82,	/* 120 */
	HB_P_PUSHVARIABLE, 53, 0,	/* I */
	HB_P_ONE,
	HB_P_EXACTLYEQUAL,
	HB_P_JUMPFALSENEAR, 17,	/* 17 (abs: 01128) */
/* 01113 */ HB_P_LINEOFFSET, 83,	/* 121 */
	HB_P_LOCALNEARSETSTR, 1, 7, 0,	/* CRDD 7*/
	'S', 'Q', 'L', 'R', 'D', 'D', 0, 
	HB_P_JUMPNEAR, 58,	/* 58 (abs: 01184) */
/* 01128 */ HB_P_LINEOFFSET, 84,	/* 122 */
	HB_P_PUSHVARIABLE, 53, 0,	/* I */
	HB_P_PUSHBYTE, 2,	/* 2 */
	HB_P_EXACTLYEQUAL,
	HB_P_JUMPFALSENEAR, 16,	/* 16 (abs: 01152) */
/* 01138 */ HB_P_LINEOFFSET, 85,	/* 123 */
	HB_P_LOCALNEARSETSTR, 1, 6, 0,	/* CRDD 6*/
	'S', 'Q', 'L', 'E', 'X', 0, 
	HB_P_JUMPNEAR, 34,	/* 34 (abs: 01184) */
/* 01152 */ HB_P_LINEOFFSET, 86,	/* 124 */
	HB_P_PUSHVARIABLE, 53, 0,	/* I */
	HB_P_PUSHBYTE, 3,	/* 3 */
	HB_P_EXACTLYEQUAL,
	HB_P_JUMPFALSENEAR, 17,	/* 17 (abs: 01177) */
/* 01162 */ HB_P_LINEOFFSET, 87,	/* 125 */
	HB_P_LOCALNEARSETSTR, 1, 7, 0,	/* CRDD 7*/
	'S', 'Q', 'L', 'R', 'D', 'D', 0, 
	HB_P_JUMPNEAR, 9,	/* 9 (abs: 01184) */
/* 01177 */ HB_P_LINEOFFSET, 89,	/* 127 */
	HB_P_PUSHSYMNEAR, 39,	/* __QUIT */
	HB_P_PUSHNIL,
	HB_P_DOSHORT, 0,
/* 01184 */ HB_P_LINEOFFSET, 93,	/* 131 */
	HB_P_FALSE,
	HB_P_MESSAGE, 54, 0,	/* NCONNECTIONTYPE */
	HB_P_PUSHSYMNEAR, 16,	/* SR_GETCONNECTION */
	HB_P_PUSHNIL,
	HB_P_FUNCTIONSHORT, 0,
	HB_P_SENDSHORT, 0,
	HB_P_ONE,
	HB_P_NOTEQUAL,
	HB_P_JUMPFALSENEAR, 14,	/* 14 (abs: 01213) */
	HB_P_POP,
	HB_P_PUSHLOCALNEAR, 1,	/* CRDD */
	HB_P_PUSHSTRSHORT, 6,	/* 6 */
	'S', 'Q', 'L', 'E', 'X', 0, 
	HB_P_EXACTLYEQUAL,
	HB_P_JUMPFALSENEAR, 75,	/* 75 (abs: 01288) */
/* 01215 */ HB_P_LINEOFFSET, 94,	/* 132 */
	HB_P_PUSHSYMNEAR, 19,	/* ALERT */
	HB_P_PUSHNIL,
	HB_P_PUSHSTRSHORT, 47,	/* 47 */
	'S', 'Q', 'L', 'R', 'D', 'D', ' ', 'E', 'x', 't', 'r', 'e', 'm', 'e', ' ', 's', 'u', 'p', 'p', 'o', 'r', 't', 's', ' ', 'o', 'n', 'l', 'y', ' ', 'O', 'D', 'B', 'C', ' ', 'c', 'o', 'n', 'n', 'e', 'c', 't', 'i', 'o', 'n', 's', '.', 0, 
	HB_P_PUSHSTRSHORT, 5,	/* 5 */
	'Q', 'u', 'i', 't', 0, 
	HB_P_ARRAYGEN, 1, 0,	/* 1 */
	HB_P_DOSHORT, 2,
/* 01281 */ HB_P_LINEOFFSET, 95,	/* 133 */
	HB_P_PUSHSYMNEAR, 39,	/* __QUIT */
	HB_P_PUSHNIL,
	HB_P_DOSHORT, 0,
/* 01288 */ HB_P_LINEOFFSET, 98,	/* 136 */
	HB_P_TRUE,
	HB_P_RETVALUE,
	HB_P_ENDPROC
/* 01293 */
   };

   hb_vmExecute( pcode, symbols );
}

