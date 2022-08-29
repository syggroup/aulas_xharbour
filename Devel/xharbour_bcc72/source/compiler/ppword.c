/*
 * $Id: ppgen.c 9965 2013-06-21 17:28:43Z ronpinkas $
 */

/*
 * Harbour Project source code:
 *    Word list which should not be used as variable names.
 *
 * Copyright 2012 Andi Jahja <andi.jahja@yahoo.co.id>
 * www - http://www.harbour-project.org
 *
 * This file is generated automatically by Harbour preprocessor
 * and is covered by the same license as Harbour PP
*/

#include "hbapi.h"
#include "hbcomp.h"

static const char * s_szReservedName[] = {
   "HIDDEN",
   "EXPORT",
   "METHOD",
   "ASSIGN",
   "ACCESS",
   "DESTRUCTOR",
   "CLASSMETHOD",
   "CONSTRUCTOR",
   "CLASSDATA",
   "DATA",
   "CLASS",
   "CLASSVAR",
   "VAR",
   "DECLSUPERN",
   "_DFSET",
   "HB_SET_XHB_COUNT",
   "HB_SET_XHB_BASE",
   "_SET_WORKAREAS_SHARED",
   "_SET_TRACESTACK",
   "_SET_TRACEFILE",
   "_SET_TIMEFORMAT",
   "_SET_PRINTERJOB",
   "_SET_OUTPUTSAFETY",
   "_SET_MACROBLOCKVARS",
   "_SET_ERRORLOOP",
   "_SET_ERRORLOG",
   "_SET_BACKGROUNDTICK",
   "_SET_BACKGROUNDTASKS",
   "HB_SET_COUNT",
   "HB_SET_BASE",
   "_SET_OSCODEPAGE",
   "_SET_CODEPAGE",
   "_SET_TRIMFILENAME",
   "_SET_EOL",
   "_SET_DEFEXTENSIONS",
   "_SET_DBFLOCKSCHEME",
   "_SET_FORCEOPT",
   "_SET_HARDCOMMIT",
   "_SET_EOF",
   "_SET_DIRSEPARATOR",
   "_SET_DIRCASE",
   "_SET_FILECASE",
   "_SET_IDLEREPEAT",
   "_SET_LANGUAGE",
   "_SET_COUNT",
   "_SET_AUTOSHARE",
   "_SET_AUTORDER",
   "_SET_AUTOPEN",
   "_SET_OPTIMIZE",
   "_SET_STRICTREAD",
   "_SET_MFILEEXT",
   "_SET_MBLOCKSIZE",
   "_SET_VIDEOMODE",
   "_SET_EVENTMASK",
   "_SET_SCROLLBREAK",
   "_SET_MCENTER",
   "_SET_MESSAGE",
   "_SET_WRAP",
   "_SET_DELIMCHARS",
   "_SET_DELIMITERS",
   "_SET_SCOREBOARD",
   "_SET_INTENSITY",
   "_SET_EXIT",
   "_SET_INSERT",
   "_SET_ESCAPE",
   "_SET_CONFIRM",
   "_SET_BELL",
   "_SET_MARGIN",
   "_SET_PRINTFILE",
   "_SET_EXTRAFILE",
   "_SET_DEVICE",
   "_SET_ALTFILE",
   "_SET_ALTERNATE",
   "_SET_CONSOLE",
   "_SET_CURSOR",
   "_SET_COLOR",
   "_SET_TYPEAHEAD",
   "_SET_DEBUG",
   "_SET_CANCEL",
   "_SET_DELETED",
   "_SET_UNIQUE",
   "_SET_SOFTSEEK",
   "_SET_EXCLUSIVE",
   "_SET_DEFAULT",
   "_SET_PATH",
   "_SET_EPOCH",
   "_SET_DATEFORMAT",
   "_SET_DECIMALS",
   "_SET_FIXED",
   "_SET_EXACT",
   "_SET_CH",
   "HB_STD_CH_",
   "HB_VER_CVSID",
   "HB_VER_BUILDDATE",
   "HB_VER_CHLCVS",
   "HB_VER_LENTRY",
   "__OPEN_XNS",
   "FOR",
   "WITH",
   "USING",
   "SET",
   "READ",
   "CLEAR",
   "RESET",
   "REINDEX",
   "INDEX",
   "DELETE",
   "LABEL",
   "REPORT",
   "DISPLAY",
   "LIST",
   "AVERAGE",
   "SUM",
   "COUNT",
   "JOIN",
   "UPDATE",
   "TOTAL",
   "SORT",
   "APPEND",
   "COPY",
   "CREATE",
   "RECALL",
   "REPLACE",
   "LOCATE",
   "SEEK",
   "CONTINUE",
   "FIND",
   "SKIP",
   "GO",
   "GOTO",
   "COMMIT",
   "UNLOCK",
   "ZAP",
   "PACK",
   "USE",
   "SELECT",
   "CLOSE",
   "RUN",
   "QUIT",
   "CANCEL",
   "REQUEST",
   "TYPE",
   "DIR",
   "RENAME",
   "ERASE",
   "SAVE",
   "RESTORE",
   "RELEASE",
   "KEYBOARD",
   "INPUT",
   "ACCEPT",
   "WAIT",
   "MENU",
   "CLS",
   "TEXTBLOCK",
   "EJECT",
   "STORE",
   "CALL",
   "DO",
   "NEXT",
   "ENDFOR",
   "ENDCASE",
   "ENDIF",
   "ENDDO",
   "ENDSEQUENCE",
   "IF"
};

#define RESERVED_NAMES sizeof( s_szReservedName ) / sizeof( char * )

BOOL hb_compReservedPPName( char * szName )
{
   UINT  wNum   = 0;
   int   iFound = 1;
   int   iLen   = ( int ) strlen( szName );

   while( wNum < RESERVED_NAMES && iFound )
   {
      int u = ( int ) strlen( s_szReservedName[ wNum ] ) ;

      if ( iLen == u )
      {
         int i, j = 0;

         for ( i = 0; i < u; i ++ )
         {
            if ( szName[ i ] == s_szReservedName[ wNum ] [ i ] )
               j ++;
            else
               break;
         }

         if ( j == u )
            iFound = 0;
      }

      ++wNum;
   }

   return ( iFound == 0 );
}
