/*
 * $Id: ppgen.c 9965 2013-06-21 17:28:43Z ronpinkas $
 */

/*
 * Harbour Project source code:
 *    Build in preprocessor rules.
 *
 * Copyright 2006 Przemyslaw Czerpak <druzus / at / priv.onet.pl>
 * www - http://www.harbour-project.org
 *
 * This file is generated automatically by Harbour preprocessor
 * and is covered by the same license as Harbour PP
 */

#define _HB_PP_INTERNAL
#include "hbpp.h"

static HB_PP_TOKEN s_dm001[ 6 ] = {
   { s_dm001 + 1, NULL       , "_DFSET",             6, 1, 0xc015, 0 },
   { s_dm001 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_dm001 + 3, NULL       , "x",                  1, 0, 0xc001, 1 },
   { s_dm001 + 4, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_dm001 + 5, NULL       , "y",                  1, 1, 0xc001, 2 },
   { NULL       , NULL       , ")",                  1, 0, 0xc033, 0 }
};
static HB_PP_TOKEN s_dr001[ 15 ] = {
   { s_dr001 + 1, NULL       , "Set",                3, 1, 0xc015, 0 },
   { s_dr001 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_dr001 + 3, NULL       , "_SET_DATEFORMAT",   15, 1, 0xc015, 0 },
   { s_dr001 + 4, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_dr001 + 5, NULL       , "if",                 2, 1, 0xc015, 0 },
   { s_dr001 + 6, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_dr001 + 7, NULL       , "__SetCentury",      12, 0, 0xc015, 0 },
   { s_dr001 + 8, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_dr001 + 9, NULL       , ")",                  1, 0, 0xc033, 0 },
   { s_dr001 +10, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_dr001 +11, NULL       , "x",                  1, 1, 0xc00b, 1 },
   { s_dr001 +12, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_dr001 +13, NULL       , "y",                  1, 1, 0xc00b, 2 },
   { s_dr001 +14, NULL       , ")",                  1, 0, 0xc033, 0 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_dm002[ 1 ] = {
   { NULL       , NULL       , "HB_SET_XHB_COUNT",  16, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_dr002[ 1 ] = {
   { NULL       , NULL       , "12",                 2, 6, 0xc02a, 0 }
};
static HB_PP_TOKEN s_dm003[ 1 ] = {
   { NULL       , NULL       , "HB_SET_XHB_BASE",   15, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_dr003[ 1 ] = {
   { NULL       , NULL       , "200",                3, 7, 0xc02a, 0 }
};
static HB_PP_TOKEN s_dm004[ 1 ] = {
   { NULL       , NULL       , "_SET_WORKAREAS_SHARED",  21, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_dr004[ 1 ] = {
   { NULL       , NULL       , "211",                3, 1, 0xc02a, 0 }
};
static HB_PP_TOKEN s_dm005[ 1 ] = {
   { NULL       , NULL       , "_SET_TRACESTACK",   15, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_dr005[ 1 ] = {
   { NULL       , NULL       , "210",                3, 7, 0xc02a, 0 }
};
static HB_PP_TOKEN s_dm006[ 1 ] = {
   { NULL       , NULL       , "_SET_TRACEFILE",    14, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_dr006[ 1 ] = {
   { NULL       , NULL       , "209",                3, 8, 0xc02a, 0 }
};
static HB_PP_TOKEN s_dm007[ 1 ] = {
   { NULL       , NULL       , "_SET_TRACE",        10, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_dr007[ 1 ] = {
   { NULL       , NULL       , "208",                3,12, 0xc02a, 0 }
};
static HB_PP_TOKEN s_dm008[ 1 ] = {
   { NULL       , NULL       , "_SET_TIMEFORMAT",   15, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_dr008[ 1 ] = {
   { NULL       , NULL       , "207",                3, 7, 0xc02a, 0 }
};
static HB_PP_TOKEN s_dm009[ 1 ] = {
   { NULL       , NULL       , "_SET_PRINTERJOB",   15, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_dr009[ 1 ] = {
   { NULL       , NULL       , "206",                3, 7, 0xc02a, 0 }
};
static HB_PP_TOKEN s_dm010[ 1 ] = {
   { NULL       , NULL       , "_SET_OUTPUTSAFETY",  17, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_dr010[ 1 ] = {
   { NULL       , NULL       , "205",                3, 5, 0xc02a, 0 }
};
static HB_PP_TOKEN s_dm011[ 1 ] = {
   { NULL       , NULL       , "_SET_MACROBLOCKVARS",  19, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_dr011[ 1 ] = {
   { NULL       , NULL       , "204",                3, 3, 0xc02a, 0 }
};
static HB_PP_TOKEN s_dm012[ 1 ] = {
   { NULL       , NULL       , "_SET_ERRORLOOP",    14, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_dr012[ 1 ] = {
   { NULL       , NULL       , "203",                3, 8, 0xc02a, 0 }
};
static HB_PP_TOKEN s_dm013[ 1 ] = {
   { NULL       , NULL       , "_SET_ERRORLOG",     13, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_dr013[ 1 ] = {
   { NULL       , NULL       , "202",                3, 9, 0xc02a, 0 }
};
static HB_PP_TOKEN s_dm014[ 1 ] = {
   { NULL       , NULL       , "_SET_BACKGROUNDTICK",  19, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_dr014[ 1 ] = {
   { NULL       , NULL       , "201",                3, 3, 0xc02a, 0 }
};
static HB_PP_TOKEN s_dm015[ 1 ] = {
   { NULL       , NULL       , "_SET_BACKGROUNDTASKS",  20, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_dr015[ 1 ] = {
   { NULL       , NULL       , "200",                3, 2, 0xc02a, 0 }
};
static HB_PP_TOKEN s_dm016[ 1 ] = {
   { NULL       , NULL       , "HB_SET_COUNT",      12, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_dr016[ 1 ] = {
   { NULL       , NULL       , "14",                 2,10, 0xc02a, 0 }
};
static HB_PP_TOKEN s_dm017[ 1 ] = {
   { NULL       , NULL       , "HB_SET_BASE",       11, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_dr017[ 1 ] = {
   { NULL       , NULL       , "100",                3,11, 0xc02a, 0 }
};
static HB_PP_TOKEN s_dm018[ 1 ] = {
   { NULL       , NULL       , "_SET_OSCODEPAGE",   15, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_dr018[ 1 ] = {
   { NULL       , NULL       , "113",                3, 7, 0xc02a, 0 }
};
static HB_PP_TOKEN s_dm019[ 1 ] = {
   { NULL       , NULL       , "_SET_CODEPAGE",     13, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_dr019[ 1 ] = {
   { NULL       , NULL       , "112",                3, 9, 0xc02a, 0 }
};
static HB_PP_TOKEN s_dm020[ 1 ] = {
   { NULL       , NULL       , "_SET_TRIMFILENAME",  17, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_dr020[ 1 ] = {
   { NULL       , NULL       , "111",                3, 5, 0xc02a, 0 }
};
static HB_PP_TOKEN s_dm021[ 1 ] = {
   { NULL       , NULL       , "_SET_EOL",           8, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_dr021[ 1 ] = {
   { NULL       , NULL       , "110",                3,14, 0xc02a, 0 }
};
static HB_PP_TOKEN s_dm022[ 1 ] = {
   { NULL       , NULL       , "_SET_DEFEXTENSIONS",  18, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_dr022[ 1 ] = {
   { NULL       , NULL       , "109",                3, 4, 0xc02a, 0 }
};
static HB_PP_TOKEN s_dm023[ 1 ] = {
   { NULL       , NULL       , "_SET_DBFLOCKSCHEME",  18, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_dr023[ 1 ] = {
   { NULL       , NULL       , "108",                3, 4, 0xc02a, 0 }
};
static HB_PP_TOKEN s_dm024[ 1 ] = {
   { NULL       , NULL       , "_SET_FORCEOPT",     13, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_dr024[ 1 ] = {
   { NULL       , NULL       , "107",                3, 9, 0xc02a, 0 }
};
static HB_PP_TOKEN s_dm025[ 1 ] = {
   { NULL       , NULL       , "_SET_HARDCOMMIT",   15, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_dr025[ 1 ] = {
   { NULL       , NULL       , "106",                3, 7, 0xc02a, 0 }
};
static HB_PP_TOKEN s_dm026[ 1 ] = {
   { NULL       , NULL       , "_SET_EOF",           8, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_dr026[ 1 ] = {
   { NULL       , NULL       , "105",                3,14, 0xc02a, 0 }
};
static HB_PP_TOKEN s_dm027[ 1 ] = {
   { NULL       , NULL       , "_SET_DIRSEPARATOR",  17, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_dr027[ 1 ] = {
   { NULL       , NULL       , "104",                3, 5, 0xc02a, 0 }
};
static HB_PP_TOKEN s_dm028[ 1 ] = {
   { NULL       , NULL       , "_SET_DIRCASE",      12, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_dr028[ 1 ] = {
   { NULL       , NULL       , "103",                3,10, 0xc02a, 0 }
};
static HB_PP_TOKEN s_dm029[ 1 ] = {
   { NULL       , NULL       , "_SET_FILECASE",     13, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_dr029[ 1 ] = {
   { NULL       , NULL       , "102",                3, 9, 0xc02a, 0 }
};
static HB_PP_TOKEN s_dm030[ 1 ] = {
   { NULL       , NULL       , "_SET_IDLEREPEAT",   15, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_dr030[ 1 ] = {
   { NULL       , NULL       , "101",                3, 7, 0xc02a, 0 }
};
static HB_PP_TOKEN s_dm031[ 1 ] = {
   { NULL       , NULL       , "_SET_LANGUAGE",     13, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_dr031[ 1 ] = {
   { NULL       , NULL       , "100",                3, 9, 0xc02a, 0 }
};
static HB_PP_TOKEN s_dm032[ 1 ] = {
   { NULL       , NULL       , "_SET_COUNT",        10, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_dr032[ 1 ] = {
   { NULL       , NULL       , "47",                 2,12, 0xc02a, 0 }
};
static HB_PP_TOKEN s_dm033[ 1 ] = {
   { NULL       , NULL       , "_SET_AUTOSHARE",    14, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_dr033[ 1 ] = {
   { NULL       , NULL       , "47",                 2, 8, 0xc02a, 0 }
};
static HB_PP_TOKEN s_dm034[ 1 ] = {
   { NULL       , NULL       , "_SET_AUTORDER",     13, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_dr034[ 1 ] = {
   { NULL       , NULL       , "46",                 2, 9, 0xc02a, 0 }
};
static HB_PP_TOKEN s_dm035[ 1 ] = {
   { NULL       , NULL       , "_SET_AUTOPEN",      12, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_dr035[ 1 ] = {
   { NULL       , NULL       , "45",                 2,10, 0xc02a, 0 }
};
static HB_PP_TOKEN s_dm036[ 1 ] = {
   { NULL       , NULL       , "_SET_OPTIMIZE",     13, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_dr036[ 1 ] = {
   { NULL       , NULL       , "44",                 2, 9, 0xc02a, 0 }
};
static HB_PP_TOKEN s_dm037[ 1 ] = {
   { NULL       , NULL       , "_SET_STRICTREAD",   15, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_dr037[ 1 ] = {
   { NULL       , NULL       , "43",                 2, 7, 0xc02a, 0 }
};
static HB_PP_TOKEN s_dm038[ 1 ] = {
   { NULL       , NULL       , "_SET_MFILEEXT",     13, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_dr038[ 1 ] = {
   { NULL       , NULL       , "42",                 2, 9, 0xc02a, 0 }
};
static HB_PP_TOKEN s_dm039[ 1 ] = {
   { NULL       , NULL       , "_SET_MBLOCKSIZE",   15, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_dr039[ 1 ] = {
   { NULL       , NULL       , "41",                 2, 7, 0xc02a, 0 }
};
static HB_PP_TOKEN s_dm040[ 1 ] = {
   { NULL       , NULL       , "_SET_VIDEOMODE",    14, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_dr040[ 1 ] = {
   { NULL       , NULL       , "40",                 2, 8, 0xc02a, 0 }
};
static HB_PP_TOKEN s_dm041[ 1 ] = {
   { NULL       , NULL       , "_SET_EVENTMASK",    14, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_dr041[ 1 ] = {
   { NULL       , NULL       , "39",                 2, 8, 0xc02a, 0 }
};
static HB_PP_TOKEN s_dm042[ 1 ] = {
   { NULL       , NULL       , "_SET_SCROLLBREAK",  16, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_dr042[ 1 ] = {
   { NULL       , NULL       , "38",                 2, 6, 0xc02a, 0 }
};
static HB_PP_TOKEN s_dm043[ 1 ] = {
   { NULL       , NULL       , "_SET_MCENTER",      12, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_dr043[ 1 ] = {
   { NULL       , NULL       , "37",                 2,10, 0xc02a, 0 }
};
static HB_PP_TOKEN s_dm044[ 1 ] = {
   { NULL       , NULL       , "_SET_MESSAGE",      12, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_dr044[ 1 ] = {
   { NULL       , NULL       , "36",                 2,10, 0xc02a, 0 }
};
static HB_PP_TOKEN s_dm045[ 1 ] = {
   { NULL       , NULL       , "_SET_WRAP",          9, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_dr045[ 1 ] = {
   { NULL       , NULL       , "35",                 2,13, 0xc02a, 0 }
};
static HB_PP_TOKEN s_dm046[ 1 ] = {
   { NULL       , NULL       , "_SET_DELIMCHARS",   15, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_dr046[ 1 ] = {
   { NULL       , NULL       , "34",                 2, 7, 0xc02a, 0 }
};
static HB_PP_TOKEN s_dm047[ 1 ] = {
   { NULL       , NULL       , "_SET_DELIMITERS",   15, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_dr047[ 1 ] = {
   { NULL       , NULL       , "33",                 2, 7, 0xc02a, 0 }
};
static HB_PP_TOKEN s_dm048[ 1 ] = {
   { NULL       , NULL       , "_SET_SCOREBOARD",   15, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_dr048[ 1 ] = {
   { NULL       , NULL       , "32",                 2, 7, 0xc02a, 0 }
};
static HB_PP_TOKEN s_dm049[ 1 ] = {
   { NULL       , NULL       , "_SET_INTENSITY",    14, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_dr049[ 1 ] = {
   { NULL       , NULL       , "31",                 2, 8, 0xc02a, 0 }
};
static HB_PP_TOKEN s_dm050[ 1 ] = {
   { NULL       , NULL       , "_SET_EXIT",          9, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_dr050[ 1 ] = {
   { NULL       , NULL       , "30",                 2,13, 0xc02a, 0 }
};
static HB_PP_TOKEN s_dm051[ 1 ] = {
   { NULL       , NULL       , "_SET_INSERT",       11, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_dr051[ 1 ] = {
   { NULL       , NULL       , "29",                 2,11, 0xc02a, 0 }
};
static HB_PP_TOKEN s_dm052[ 1 ] = {
   { NULL       , NULL       , "_SET_ESCAPE",       11, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_dr052[ 1 ] = {
   { NULL       , NULL       , "28",                 2,11, 0xc02a, 0 }
};
static HB_PP_TOKEN s_dm053[ 1 ] = {
   { NULL       , NULL       , "_SET_CONFIRM",      12, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_dr053[ 1 ] = {
   { NULL       , NULL       , "27",                 2,10, 0xc02a, 0 }
};
static HB_PP_TOKEN s_dm054[ 1 ] = {
   { NULL       , NULL       , "_SET_BELL",          9, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_dr054[ 1 ] = {
   { NULL       , NULL       , "26",                 2,13, 0xc02a, 0 }
};
static HB_PP_TOKEN s_dm055[ 1 ] = {
   { NULL       , NULL       , "_SET_MARGIN",       11, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_dr055[ 1 ] = {
   { NULL       , NULL       , "25",                 2,11, 0xc02a, 0 }
};
static HB_PP_TOKEN s_dm056[ 1 ] = {
   { NULL       , NULL       , "_SET_PRINTFILE",    14, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_dr056[ 1 ] = {
   { NULL       , NULL       , "24",                 2, 8, 0xc02a, 0 }
};
static HB_PP_TOKEN s_dm057[ 1 ] = {
   { NULL       , NULL       , "_SET_PRINTER",      12, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_dr057[ 1 ] = {
   { NULL       , NULL       , "23",                 2,10, 0xc02a, 0 }
};
static HB_PP_TOKEN s_dm058[ 1 ] = {
   { NULL       , NULL       , "_SET_EXTRAFILE",    14, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_dr058[ 1 ] = {
   { NULL       , NULL       , "22",                 2, 8, 0xc02a, 0 }
};
static HB_PP_TOKEN s_dm059[ 1 ] = {
   { NULL       , NULL       , "_SET_EXTRA",        10, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_dr059[ 1 ] = {
   { NULL       , NULL       , "21",                 2,12, 0xc02a, 0 }
};
static HB_PP_TOKEN s_dm060[ 1 ] = {
   { NULL       , NULL       , "_SET_DEVICE",       11, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_dr060[ 1 ] = {
   { NULL       , NULL       , "20",                 2,11, 0xc02a, 0 }
};
static HB_PP_TOKEN s_dm061[ 1 ] = {
   { NULL       , NULL       , "_SET_ALTFILE",      12, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_dr061[ 1 ] = {
   { NULL       , NULL       , "19",                 2,10, 0xc02a, 0 }
};
static HB_PP_TOKEN s_dm062[ 1 ] = {
   { NULL       , NULL       , "_SET_ALTERNATE",    14, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_dr062[ 1 ] = {
   { NULL       , NULL       , "18",                 2, 8, 0xc02a, 0 }
};
static HB_PP_TOKEN s_dm063[ 1 ] = {
   { NULL       , NULL       , "_SET_CONSOLE",      12, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_dr063[ 1 ] = {
   { NULL       , NULL       , "17",                 2,10, 0xc02a, 0 }
};
static HB_PP_TOKEN s_dm064[ 1 ] = {
   { NULL       , NULL       , "_SET_CURSOR",       11, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_dr064[ 1 ] = {
   { NULL       , NULL       , "16",                 2,11, 0xc02a, 0 }
};
static HB_PP_TOKEN s_dm065[ 1 ] = {
   { NULL       , NULL       , "_SET_COLOR",        10, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_dr065[ 1 ] = {
   { NULL       , NULL       , "15",                 2,12, 0xc02a, 0 }
};
static HB_PP_TOKEN s_dm066[ 1 ] = {
   { NULL       , NULL       , "_SET_TYPEAHEAD",    14, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_dr066[ 1 ] = {
   { NULL       , NULL       , "14",                 2, 8, 0xc02a, 0 }
};
static HB_PP_TOKEN s_dm067[ 1 ] = {
   { NULL       , NULL       , "_SET_DEBUG",        10, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_dr067[ 1 ] = {
   { NULL       , NULL       , "13",                 2,12, 0xc02a, 0 }
};
static HB_PP_TOKEN s_dm068[ 1 ] = {
   { NULL       , NULL       , "_SET_CANCEL",       11, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_dr068[ 1 ] = {
   { NULL       , NULL       , "12",                 2,11, 0xc02a, 0 }
};
static HB_PP_TOKEN s_dm069[ 1 ] = {
   { NULL       , NULL       , "_SET_DELETED",      12, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_dr069[ 1 ] = {
   { NULL       , NULL       , "11",                 2,10, 0xc02a, 0 }
};
static HB_PP_TOKEN s_dm070[ 1 ] = {
   { NULL       , NULL       , "_SET_UNIQUE",       11, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_dr070[ 1 ] = {
   { NULL       , NULL       , "10",                 2,11, 0xc02a, 0 }
};
static HB_PP_TOKEN s_dm071[ 1 ] = {
   { NULL       , NULL       , "_SET_SOFTSEEK",     13, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_dr071[ 1 ] = {
   { NULL       , NULL       , "9",                  1, 9, 0xc02a, 0 }
};
static HB_PP_TOKEN s_dm072[ 1 ] = {
   { NULL       , NULL       , "_SET_EXCLUSIVE",    14, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_dr072[ 1 ] = {
   { NULL       , NULL       , "8",                  1, 8, 0xc02a, 0 }
};
static HB_PP_TOKEN s_dm073[ 1 ] = {
   { NULL       , NULL       , "_SET_DEFAULT",      12, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_dr073[ 1 ] = {
   { NULL       , NULL       , "7",                  1,10, 0xc02a, 0 }
};
static HB_PP_TOKEN s_dm074[ 1 ] = {
   { NULL       , NULL       , "_SET_PATH",          9, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_dr074[ 1 ] = {
   { NULL       , NULL       , "6",                  1,13, 0xc02a, 0 }
};
static HB_PP_TOKEN s_dm075[ 1 ] = {
   { NULL       , NULL       , "_SET_EPOCH",        10, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_dr075[ 1 ] = {
   { NULL       , NULL       , "5",                  1,12, 0xc02a, 0 }
};
static HB_PP_TOKEN s_dm076[ 1 ] = {
   { NULL       , NULL       , "_SET_DATEFORMAT",   15, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_dr076[ 1 ] = {
   { NULL       , NULL       , "4",                  1, 7, 0xc02a, 0 }
};
static HB_PP_TOKEN s_dm077[ 1 ] = {
   { NULL       , NULL       , "_SET_DECIMALS",     13, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_dr077[ 1 ] = {
   { NULL       , NULL       , "3",                  1, 9, 0xc02a, 0 }
};
static HB_PP_TOKEN s_dm078[ 1 ] = {
   { NULL       , NULL       , "_SET_FIXED",        10, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_dr078[ 1 ] = {
   { NULL       , NULL       , "2",                  1,12, 0xc02a, 0 }
};
static HB_PP_TOKEN s_dm079[ 1 ] = {
   { NULL       , NULL       , "_SET_EXACT",        10, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_dr079[ 1 ] = {
   { NULL       , NULL       , "1",                  1,12, 0xc02a, 0 }
};
static HB_PP_TOKEN s_dm080[ 1 ] = {
   { NULL       , NULL       , "_SET_CH",            7, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_dm081[ 1 ] = {
   { NULL       , NULL       , "HB_STD_CH_",        10, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_dm082[ 1 ] = {
   { NULL       , NULL       , "HB_VER_CVSID",      12, 0, 0xc015, 0 }
};
static HB_PP_TOKEN s_dr082[ 1 ] = {
   { NULL       , NULL       , "10191",              5, 0, 0xc02a, 0 }
};
static HB_PP_TOKEN s_dm083[ 1 ] = {
   { NULL       , NULL       , "HB_VER_BUILDDATE",  16, 0, 0xc015, 0 }
};
static HB_PP_TOKEN s_dr083[ 1 ] = {
   { NULL       , NULL       , "20170228",           8, 0, 0xc02a, 0 }
};
static HB_PP_TOKEN s_dm084[ 1 ] = {
   { NULL       , NULL       , "HB_VER_CHLCVS",     13, 0, 0xc015, 0 }
};
static HB_PP_TOKEN s_dr084[ 1 ] = {
   { NULL       , NULL       , "ChangeLog 10191 2017-02-28 20:00:20Z lculik",  43, 0, 0xc029, 0 }
};
static HB_PP_TOKEN s_dm085[ 1 ] = {
   { NULL       , NULL       , "HB_VER_LENTRY",     13, 0, 0xc015, 0 }
};
static HB_PP_TOKEN s_dr085[ 1 ] = {
   { NULL       , NULL       , "2017-02-28 17:00    UTC-0300 Luiz Rafael Culik <luiz@xharbour.com.br>",  69, 0, 0xc029, 0 }
};
static const HB_PP_DEFRULE s_def[ 85 ] = {
   { s_dm001, s_dr001, 3, 2, 0x0000 },
   { s_dm002, s_dr002, 3, 0, 0x0000 },
   { s_dm003, s_dr003, 3, 0, 0x0000 },
   { s_dm004, s_dr004, 3, 0, 0x0000 },
   { s_dm005, s_dr005, 3, 0, 0x0000 },
   { s_dm006, s_dr006, 3, 0, 0x0000 },
   { s_dm007, s_dr007, 3, 0, 0x0000 },
   { s_dm008, s_dr008, 3, 0, 0x0000 },
   { s_dm009, s_dr009, 3, 0, 0x0000 },
   { s_dm010, s_dr010, 3, 0, 0x0000 },
   { s_dm011, s_dr011, 3, 0, 0x0000 },
   { s_dm012, s_dr012, 3, 0, 0x0000 },
   { s_dm013, s_dr013, 3, 0, 0x0000 },
   { s_dm014, s_dr014, 3, 0, 0x0000 },
   { s_dm015, s_dr015, 3, 0, 0x0000 },
   { s_dm016, s_dr016, 3, 0, 0x0000 },
   { s_dm017, s_dr017, 3, 0, 0x0000 },
   { s_dm018, s_dr018, 3, 0, 0x0000 },
   { s_dm019, s_dr019, 3, 0, 0x0000 },
   { s_dm020, s_dr020, 3, 0, 0x0000 },
   { s_dm021, s_dr021, 3, 0, 0x0000 },
   { s_dm022, s_dr022, 3, 0, 0x0000 },
   { s_dm023, s_dr023, 3, 0, 0x0000 },
   { s_dm024, s_dr024, 3, 0, 0x0000 },
   { s_dm025, s_dr025, 3, 0, 0x0000 },
   { s_dm026, s_dr026, 3, 0, 0x0000 },
   { s_dm027, s_dr027, 3, 0, 0x0000 },
   { s_dm028, s_dr028, 3, 0, 0x0000 },
   { s_dm029, s_dr029, 3, 0, 0x0000 },
   { s_dm030, s_dr030, 3, 0, 0x0000 },
   { s_dm031, s_dr031, 3, 0, 0x0000 },
   { s_dm032, s_dr032, 3, 0, 0x0000 },
   { s_dm033, s_dr033, 3, 0, 0x0000 },
   { s_dm034, s_dr034, 3, 0, 0x0000 },
   { s_dm035, s_dr035, 3, 0, 0x0000 },
   { s_dm036, s_dr036, 3, 0, 0x0000 },
   { s_dm037, s_dr037, 3, 0, 0x0000 },
   { s_dm038, s_dr038, 3, 0, 0x0000 },
   { s_dm039, s_dr039, 3, 0, 0x0000 },
   { s_dm040, s_dr040, 3, 0, 0x0000 },
   { s_dm041, s_dr041, 3, 0, 0x0000 },
   { s_dm042, s_dr042, 3, 0, 0x0000 },
   { s_dm043, s_dr043, 3, 0, 0x0000 },
   { s_dm044, s_dr044, 3, 0, 0x0000 },
   { s_dm045, s_dr045, 3, 0, 0x0000 },
   { s_dm046, s_dr046, 3, 0, 0x0000 },
   { s_dm047, s_dr047, 3, 0, 0x0000 },
   { s_dm048, s_dr048, 3, 0, 0x0000 },
   { s_dm049, s_dr049, 3, 0, 0x0000 },
   { s_dm050, s_dr050, 3, 0, 0x0000 },
   { s_dm051, s_dr051, 3, 0, 0x0000 },
   { s_dm052, s_dr052, 3, 0, 0x0000 },
   { s_dm053, s_dr053, 3, 0, 0x0000 },
   { s_dm054, s_dr054, 3, 0, 0x0000 },
   { s_dm055, s_dr055, 3, 0, 0x0000 },
   { s_dm056, s_dr056, 3, 0, 0x0000 },
   { s_dm057, s_dr057, 3, 0, 0x0000 },
   { s_dm058, s_dr058, 3, 0, 0x0000 },
   { s_dm059, s_dr059, 3, 0, 0x0000 },
   { s_dm060, s_dr060, 3, 0, 0x0000 },
   { s_dm061, s_dr061, 3, 0, 0x0000 },
   { s_dm062, s_dr062, 3, 0, 0x0000 },
   { s_dm063, s_dr063, 3, 0, 0x0000 },
   { s_dm064, s_dr064, 3, 0, 0x0000 },
   { s_dm065, s_dr065, 3, 0, 0x0000 },
   { s_dm066, s_dr066, 3, 0, 0x0000 },
   { s_dm067, s_dr067, 3, 0, 0x0000 },
   { s_dm068, s_dr068, 3, 0, 0x0000 },
   { s_dm069, s_dr069, 3, 0, 0x0000 },
   { s_dm070, s_dr070, 3, 0, 0x0000 },
   { s_dm071, s_dr071, 3, 0, 0x0000 },
   { s_dm072, s_dr072, 3, 0, 0x0000 },
   { s_dm073, s_dr073, 3, 0, 0x0000 },
   { s_dm074, s_dr074, 3, 0, 0x0000 },
   { s_dm075, s_dr075, 3, 0, 0x0000 },
   { s_dm076, s_dr076, 3, 0, 0x0000 },
   { s_dm077, s_dr077, 3, 0, 0x0000 },
   { s_dm078, s_dr078, 3, 0, 0x0000 },
   { s_dm079, s_dr079, 3, 0, 0x0000 },
   { s_dm080, NULL   , 3, 0, 0x0000 },
   { s_dm081, NULL   , 3, 0, 0x0000 },
   { s_dm082, s_dr082, 3, 0, 0x0000 },
   { s_dm083, s_dr083, 3, 0, 0x0000 },
   { s_dm084, s_dr084, 3, 0, 0x0000 },
   { s_dm085, s_dr085, 3, 0, 0x0000 }
};

static HB_PP_TOKEN s_tm001[ 2 ] = {
   { s_tm001 + 1, NULL       , "__OPEN_XNS",        10, 1, 0xc015, 0 },
   { NULL       , NULL       , "NSX",                3, 0, 0xe001, 1 }
};
static HB_PP_TOKEN s_tr001[ 3 ] = {
   { s_tr001 + 1, NULL       , "#",                  1, 1, 0xc020, 0 },
   { s_tr001 + 2, NULL       , "include",            7, 0, 0xc015, 0 },
   { NULL       , NULL       , "NSX",                3, 1, 0xc00c, 1 }
};
static const HB_PP_DEFRULE s_trs[ 1 ] = {
   { s_tm001, s_tr001, 1, 1, 0x0000 }
};

static HB_PP_TOKEN s_cm001[ 12 ] = {
   { s_cm001 + 1, NULL       , "FOR",                3, 1, 0xc015, 0 },
   { s_cm001 + 2, NULL       , "EACH",               4, 1, 0xc015, 0 },
   { s_cm001 + 3, NULL       , "e1",                 2, 0, 0xe001, 1 },
   { s_cm001 + 6, s_cm001 + 4, "[",                  1, 1, 0xe007, 0 },
   { s_cm001 + 5, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { NULL       , NULL       , "eN",                 2, 0, 0xe001, 2 },
   { s_cm001 + 7, NULL       , "IN",                 2, 1, 0xc015, 0 },
   { s_cm001 + 8, NULL       , "c1",                 2, 0, 0xe001, 3 },
   { s_cm001 +11, s_cm001 + 9, "[",                  1, 1, 0xe007, 0 },
   { s_cm001 +10, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { NULL       , NULL       , "cN",                 2, 0, 0xe001, 4 },
   { NULL       , NULL       , "DESCEND",            7, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_cr001[ 215 ] = {
   { s_cr001 + 1, NULL       , "HB_SetWith",        10, 1, 0xc015, 0 },
   { s_cr001 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr001 + 3, NULL       , "{",                  1, 1, 0xc036, 0 },
   { s_cr001 + 4, NULL       , "-",                  1, 1, 0xc051, 0 },
   { s_cr001 + 5, NULL       , "1",                  1, 0, 0xc02a, 0 },
   { s_cr001 + 6, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr001 + 7, NULL       , ".F.",                3, 1, 0xc02c, 0 },
   { s_cr001 + 8, NULL       , "}",                  1, 1, 0xc037, 0 },
   { s_cr001 + 9, NULL       , ")",                  1, 1, 0xc033, 0 },
   { s_cr001 +10, NULL       , ";",                  1, 1, 0xc01e, 0 },
   { s_cr001 +11, NULL       , "FOR",                3, 1, 0xc015, 0 },
   { s_cr001 +12, NULL       , "HB_QWith",           8, 1, 0xc015, 0 },
   { s_cr001 +13, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr001 +14, NULL       , ")",                  1, 0, 0xc033, 0 },
   { s_cr001 +15, NULL       , "[",                  1, 0, 0xc034, 0 },
   { s_cr001 +16, NULL       , "1",                  1, 0, 0xc02a, 0 },
   { s_cr001 +17, NULL       , "]",                  1, 0, 0xc035, 0 },
   { s_cr001 +18, NULL       , ":=",                 2, 1, 0xc03c, 0 },
   { s_cr001 +19, NULL       , "-",                  1, 1, 0xc051, 0 },
   { s_cr001 +20, NULL       , "1",                  1, 0, 0xc02a, 0 },
   { s_cr001 +21, NULL       , "TO",                 2, 1, 0xc015, 0 },
   { s_cr001 +22, NULL       , "(",                  1, 1, 0xc032, 0 },
   { s_cr001 +23, NULL       , "-",                  1, 1, 0xc051, 0 },
   { s_cr001 +24, NULL       , "0xFFFFFFF",          9, 1, 0xc02a, 0 },
   { s_cr001 +25, NULL       , ")",                  1, 1, 0xc033, 0 },
   { s_cr001 +26, NULL       , "STEP",               4, 1, 0xc015, 0 },
   { s_cr001 +27, NULL       , "-",                  1, 1, 0xc051, 0 },
   { s_cr001 +28, NULL       , "1",                  1, 0, 0xc02a, 0 },
   { s_cr001 +29, NULL       , ";",                  1, 1, 0xc01e, 0 },
   { s_cr001 +30, NULL       , "e1",                 2, 1, 0xc00b, 1 },
   { s_cr001 +31, NULL       , ":=",                 2, 1, 0xc03c, 0 },
   { s_cr001 +32, NULL       , "(",                  1, 1, 0xc032, 0 },
   { s_cr001 +33, NULL       , "@",                  1, 1, 0xc038, 0 },
   { s_cr001 +34, NULL       , "e1",                 2, 0, 0xc00b, 1 },
   { s_cr001 +35, NULL       , ")",                  1, 1, 0xc033, 0 },
   { s_cr001 +36, NULL       , ";",                  1, 1, 0xc01e, 0 },
   { s_cr001 +44, s_cr001 +37, "[",                  1, 0, 0xc012, 0 },
   { s_cr001 +38, NULL       , "eN",                 2, 1, 0xc00b, 2 },
   { s_cr001 +39, NULL       , ":=",                 2, 1, 0xc03c, 0 },
   { s_cr001 +40, NULL       , "(",                  1, 1, 0xc032, 0 },
   { s_cr001 +41, NULL       , "@",                  1, 1, 0xc038, 0 },
   { s_cr001 +42, NULL       , "eN",                 2, 0, 0xc00b, 2 },
   { s_cr001 +43, NULL       , ")",                  1, 1, 0xc033, 0 },
   { NULL       , NULL       , ";",                  1, 0, 0xc01e, 0 },
   { s_cr001 +45, NULL       , ";",                  1, 1, 0xc01e, 0 },
   { s_cr001 +46, NULL       , "WHILE",              5, 1, 0xc015, 0 },
   { s_cr001 +47, NULL       , ".T.",                3, 1, 0xc02c, 0 },
   { s_cr001 +48, NULL       , ";",                  1, 1, 0xc01e, 0 },
   { s_cr001 +49, NULL       , "IF",                 2, 1, 0xc015, 0 },
   { s_cr001 +50, NULL       , "(",                  1, 1, 0xc032, 0 },
   { s_cr001 +51, NULL       , "-",                  1, 1, 0xc051, 0 },
   { s_cr001 +52, NULL       , "HB_QWith",           8, 1, 0xc015, 0 },
   { s_cr001 +53, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr001 +54, NULL       , ")",                  1, 0, 0xc033, 0 },
   { s_cr001 +55, NULL       , "[",                  1, 0, 0xc034, 0 },
   { s_cr001 +56, NULL       , "1",                  1, 0, 0xc02a, 0 },
   { s_cr001 +57, NULL       , "]",                  1, 0, 0xc035, 0 },
   { s_cr001 +58, NULL       , ")",                  1, 1, 0xc033, 0 },
   { s_cr001 +59, NULL       , "<=",                 2, 1, 0xc04c, 0 },
   { s_cr001 +60, NULL       , "Len",                3, 1, 0xc015, 0 },
   { s_cr001 +61, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr001 +62, NULL       , "c1",                 2, 1, 0xc00b, 3 },
   { s_cr001 +63, NULL       , ")",                  1, 1, 0xc033, 0 },
   { s_cr001 +64, NULL       , ";",                  1, 1, 0xc01e, 0 },
   { s_cr001 +65, NULL       , "e1",                 2, 1, 0xc00b, 1 },
   { s_cr001 +66, NULL       , ":=",                 2, 1, 0xc03c, 0 },
   { s_cr001 +67, NULL       , "(",                  1, 1, 0xc032, 0 },
   { s_cr001 +68, NULL       , "@",                  1, 1, 0xc038, 0 },
   { s_cr001 +69, NULL       , "c1",                 2, 0, 0xc00b, 3 },
   { s_cr001 +70, NULL       , "[",                  1, 0, 0xc034, 0 },
   { s_cr001 +71, NULL       , "HB_QWith",           8, 1, 0xc015, 0 },
   { s_cr001 +72, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr001 +73, NULL       , ")",                  1, 0, 0xc033, 0 },
   { s_cr001 +74, NULL       , "[",                  1, 0, 0xc034, 0 },
   { s_cr001 +75, NULL       , "1",                  1, 0, 0xc02a, 0 },
   { s_cr001 +76, NULL       , "]",                  1, 0, 0xc035, 0 },
   { s_cr001 +77, NULL       , "]",                  1, 1, 0xc035, 0 },
   { s_cr001 +78, NULL       , ")",                  1, 1, 0xc033, 0 },
   { s_cr001 +79, NULL       , ";",                  1, 1, 0xc01e, 0 },
   { s_cr001 +80, NULL       , "ELSE",               4, 1, 0xc015, 0 },
   { s_cr001 +81, NULL       , ";",                  1, 1, 0xc01e, 0 },
   { s_cr001 +82, NULL       , "HB_QWith",           8, 1, 0xc015, 0 },
   { s_cr001 +83, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr001 +84, NULL       , ")",                  1, 0, 0xc033, 0 },
   { s_cr001 +85, NULL       , "[",                  1, 0, 0xc034, 0 },
   { s_cr001 +86, NULL       , "2",                  1, 0, 0xc02a, 0 },
   { s_cr001 +87, NULL       , "]",                  1, 0, 0xc035, 0 },
   { s_cr001 +88, NULL       , ":=",                 2, 1, 0xc03c, 0 },
   { s_cr001 +89, NULL       , ".T.",                3, 1, 0xc02c, 0 },
   { s_cr001 +90, NULL       , ";",                  1, 1, 0xc01e, 0 },
   { s_cr001 +91, NULL       , "EXIT",               4, 1, 0xc015, 0 },
   { s_cr001 +92, NULL       , ";",                  1, 1, 0xc01e, 0 },
   { s_cr001 +93, NULL       , "ENDIF",              5, 1, 0xc015, 0 },
   { s_cr001 +94, NULL       , ";",                  1, 1, 0xc01e, 0 },
   { s_cr001 +142, s_cr001 +95, "[",                  1, 0, 0xc012, 0 },
   { s_cr001 +96, NULL       , ";",                  1, 1, 0xc01e, 0 },
   { s_cr001 +97, NULL       , "IF",                 2, 1, 0xc015, 0 },
   { s_cr001 +98, NULL       , "(",                  1, 1, 0xc032, 0 },
   { s_cr001 +99, NULL       , "-",                  1, 1, 0xc051, 0 },
   { s_cr001 +100, NULL       , "HB_QWith",           8, 1, 0xc015, 0 },
   { s_cr001 +101, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr001 +102, NULL       , ")",                  1, 0, 0xc033, 0 },
   { s_cr001 +103, NULL       , "[",                  1, 0, 0xc034, 0 },
   { s_cr001 +104, NULL       , "1",                  1, 0, 0xc02a, 0 },
   { s_cr001 +105, NULL       , "]",                  1, 0, 0xc035, 0 },
   { s_cr001 +106, NULL       , ")",                  1, 1, 0xc033, 0 },
   { s_cr001 +107, NULL       , "<=",                 2, 1, 0xc04c, 0 },
   { s_cr001 +108, NULL       , "Len",                3, 1, 0xc015, 0 },
   { s_cr001 +109, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr001 +110, NULL       , "cN",                 2, 1, 0xc00b, 4 },
   { s_cr001 +111, NULL       , ")",                  1, 1, 0xc033, 0 },
   { s_cr001 +112, NULL       , ";",                  1, 1, 0xc01e, 0 },
   { s_cr001 +113, NULL       , "eN",                 2, 1, 0xc00b, 2 },
   { s_cr001 +114, NULL       , ":=",                 2, 1, 0xc03c, 0 },
   { s_cr001 +115, NULL       , "(",                  1, 1, 0xc032, 0 },
   { s_cr001 +116, NULL       , "@",                  1, 1, 0xc038, 0 },
   { s_cr001 +117, NULL       , "cN",                 2, 0, 0xc00b, 4 },
   { s_cr001 +118, NULL       , "[",                  1, 0, 0xc034, 0 },
   { s_cr001 +119, NULL       , "HB_QWith",           8, 1, 0xc015, 0 },
   { s_cr001 +120, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr001 +121, NULL       , ")",                  1, 0, 0xc033, 0 },
   { s_cr001 +122, NULL       , "[",                  1, 0, 0xc034, 0 },
   { s_cr001 +123, NULL       , "1",                  1, 0, 0xc02a, 0 },
   { s_cr001 +124, NULL       , "]",                  1, 0, 0xc035, 0 },
   { s_cr001 +125, NULL       , "]",                  1, 1, 0xc035, 0 },
   { s_cr001 +126, NULL       , ")",                  1, 1, 0xc033, 0 },
   { s_cr001 +127, NULL       , ";",                  1, 1, 0xc01e, 0 },
   { s_cr001 +128, NULL       , "ELSE",               4, 1, 0xc015, 0 },
   { s_cr001 +129, NULL       , ";",                  1, 1, 0xc01e, 0 },
   { s_cr001 +130, NULL       , "HB_QWith",           8, 1, 0xc015, 0 },
   { s_cr001 +131, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr001 +132, NULL       , ")",                  1, 0, 0xc033, 0 },
   { s_cr001 +133, NULL       , "[",                  1, 0, 0xc034, 0 },
   { s_cr001 +134, NULL       , "2",                  1, 0, 0xc02a, 0 },
   { s_cr001 +135, NULL       , "]",                  1, 0, 0xc035, 0 },
   { s_cr001 +136, NULL       , ":=",                 2, 1, 0xc03c, 0 },
   { s_cr001 +137, NULL       , ".T.",                3, 1, 0xc02c, 0 },
   { s_cr001 +138, NULL       , ";",                  1, 1, 0xc01e, 0 },
   { s_cr001 +139, NULL       , "EXIT",               4, 1, 0xc015, 0 },
   { s_cr001 +140, NULL       , ";",                  1, 1, 0xc01e, 0 },
   { s_cr001 +141, NULL       , "ENDIF",              5, 1, 0xc015, 0 },
   { NULL       , NULL       , ";",                  1, 1, 0xc01e, 0 },
   { s_cr001 +143, NULL       , ";",                  1, 1, 0xc01e, 0 },
   { s_cr001 +144, NULL       , "EXIT",               4, 1, 0xc015, 0 },
   { s_cr001 +145, NULL       , ";",                  1, 1, 0xc01e, 0 },
   { s_cr001 +146, NULL       , "END",                3, 1, 0xc015, 0 },
   { s_cr001 +147, NULL       , ";",                  1, 1, 0xc01e, 0 },
   { s_cr001 +148, NULL       , "IF",                 2, 1, 0xc015, 0 },
   { s_cr001 +149, NULL       , "HB_QWith",           8, 1, 0xc015, 0 },
   { s_cr001 +150, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr001 +151, NULL       , ")",                  1, 0, 0xc033, 0 },
   { s_cr001 +152, NULL       , "[",                  1, 0, 0xc034, 0 },
   { s_cr001 +153, NULL       , "2",                  1, 0, 0xc02a, 0 },
   { s_cr001 +154, NULL       , "]",                  1, 0, 0xc035, 0 },
   { s_cr001 +155, NULL       , ";",                  1, 1, 0xc01e, 0 },
   { s_cr001 +156, NULL       , "e1",                 2, 1, 0xc00b, 1 },
   { s_cr001 +157, NULL       , ":=",                 2, 1, 0xc03c, 0 },
   { s_cr001 +158, NULL       , "(",                  1, 1, 0xc032, 0 },
   { s_cr001 +159, NULL       , "@",                  1, 1, 0xc038, 0 },
   { s_cr001 +160, NULL       , "e1",                 2, 0, 0xc00b, 1 },
   { s_cr001 +161, NULL       , ")",                  1, 1, 0xc033, 0 },
   { s_cr001 +162, NULL       , ";",                  1, 1, 0xc01e, 0 },
   { s_cr001 +170, s_cr001 +163, "[",                  1, 0, 0xc012, 0 },
   { s_cr001 +164, NULL       , "eN",                 2, 1, 0xc00b, 2 },
   { s_cr001 +165, NULL       , ":=",                 2, 1, 0xc03c, 0 },
   { s_cr001 +166, NULL       , "(",                  1, 1, 0xc032, 0 },
   { s_cr001 +167, NULL       , "@",                  1, 1, 0xc038, 0 },
   { s_cr001 +168, NULL       , "eN",                 2, 0, 0xc00b, 2 },
   { s_cr001 +169, NULL       , ")",                  1, 1, 0xc033, 0 },
   { NULL       , NULL       , ";",                  1, 0, 0xc01e, 0 },
   { s_cr001 +171, NULL       , ";",                  1, 1, 0xc01e, 0 },
   { s_cr001 +172, NULL       , "HB_SetWith",        10, 1, 0xc015, 0 },
   { s_cr001 +173, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr001 +174, NULL       , ")",                  1, 0, 0xc033, 0 },
   { s_cr001 +175, NULL       , ";",                  1, 1, 0xc01e, 0 },
   { s_cr001 +176, NULL       , "EXIT",               4, 1, 0xc015, 0 },
   { s_cr001 +177, NULL       , ";",                  1, 1, 0xc01e, 0 },
   { s_cr001 +178, NULL       , "ENDIF",              5, 1, 0xc015, 0 },
   { s_cr001 +179, NULL       , ";",                  1, 1, 0xc01e, 0 },
   { s_cr001 +180, NULL       , "#",                  1, 1, 0xc020, 0 },
   { s_cr001 +181, NULL       , "xtranslate",        10, 0, 0xc015, 0 },
   { s_cr001 +182, NULL       , "e1",                 2, 1, 0xc00b, 1 },
   { s_cr001 +183, NULL       , ":",                  1, 0, 0xc03a, 0 },
   { s_cr001 +184, NULL       , "__EnumIndex",       11, 0, 0xc015, 0 },
   { s_cr001 +185, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr001 +186, NULL       , ")",                  1, 0, 0xc033, 0 },
   { s_cr001 +187, NULL       , "=",                  1, 1, 0xc049, 0 },
   { s_cr001 +188, NULL       , ">",                  1, 0, 0xc04b, 0 },
   { s_cr001 +189, NULL       , "HB_QWith",           8, 1, 0xc015, 0 },
   { s_cr001 +190, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr001 +191, NULL       , ")",                  1, 0, 0xc033, 0 },
   { s_cr001 +192, NULL       , "\\",                  1, 0, 0xc01a, 0 },
   { s_cr001 +193, NULL       , "[",                  1, 0, 0xc034, 0 },
   { s_cr001 +194, NULL       , "1",                  1, 0, 0xc02a, 0 },
   { s_cr001 +195, NULL       , "\\",                  1, 0, 0xc01a, 0 },
   { s_cr001 +196, NULL       , "]",                  1, 0, 0xc035, 0 },
   { s_cr001 +197, NULL       , ";",                  1, 1, 0xc01e, 0 },
   { NULL       , s_cr001 +198, "[",                  1, 0, 0xc012, 0 },
   { s_cr001 +199, NULL       , "#",                  1, 0, 0xc020, 0 },
   { s_cr001 +200, NULL       , "xtranslate",        10, 0, 0xc015, 0 },
   { s_cr001 +201, NULL       , "eN",                 2, 1, 0xc00b, 2 },
   { s_cr001 +202, NULL       , ":",                  1, 0, 0xc03a, 0 },
   { s_cr001 +203, NULL       , "__EnumIndex",       11, 0, 0xc015, 0 },
   { s_cr001 +204, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr001 +205, NULL       , ")",                  1, 0, 0xc033, 0 },
   { s_cr001 +206, NULL       , "=",                  1, 1, 0xc049, 0 },
   { s_cr001 +207, NULL       , ">",                  1, 0, 0xc04b, 0 },
   { s_cr001 +208, NULL       , "HB_QWith",           8, 1, 0xc015, 0 },
   { s_cr001 +209, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr001 +210, NULL       , ")",                  1, 0, 0xc033, 0 },
   { s_cr001 +211, NULL       , "\\",                  1, 0, 0xc01a, 0 },
   { s_cr001 +212, NULL       , "[",                  1, 0, 0xc034, 0 },
   { s_cr001 +213, NULL       , "1",                  1, 0, 0xc02a, 0 },
   { s_cr001 +214, NULL       , "\\",                  1, 0, 0xc01a, 0 },
   { NULL       , NULL       , "]",                  1, 0, 0xc035, 0 }
};
static HB_PP_TOKEN s_cm002[ 15 ] = {
   { s_cm002 + 1, NULL       , "FOR",                3, 1, 0xc015, 0 },
   { s_cm002 + 2, NULL       , "EACH",               4, 1, 0xc015, 0 },
   { s_cm002 + 3, NULL       , "e1",                 2, 0, 0xe001, 1 },
   { s_cm002 + 4, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cm002 + 5, NULL       , "e2",                 2, 0, 0xe001, 3 },
   { s_cm002 + 8, s_cm002 + 6, "[",                  1, 1, 0xe007, 0 },
   { s_cm002 + 7, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { NULL       , NULL       , "eN",                 2, 0, 0xe001, 4 },
   { s_cm002 + 9, NULL       , "IN",                 2, 1, 0xc015, 0 },
   { s_cm002 +10, NULL       , "c1",                 2, 0, 0xe001, 2 },
   { s_cm002 +11, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cm002 +12, NULL       , "c2",                 2, 0, 0xe001, 5 },
   { NULL       , s_cm002 +13, "[",                  1, 1, 0xe007, 0 },
   { s_cm002 +14, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { NULL       , NULL       , "cN",                 2, 0, 0xe001, 6 }
};
static HB_PP_TOKEN s_cr002[ 127 ] = {
   { s_cr002 + 1, NULL       , "FOR",                3, 1, 0xc015, 0 },
   { s_cr002 + 2, NULL       , "EACH",               4, 1, 0xc015, 0 },
   { s_cr002 + 3, NULL       , "e1",                 2, 1, 0xc00b, 1 },
   { s_cr002 + 4, NULL       , "IN",                 2, 1, 0xc015, 0 },
   { s_cr002 + 5, NULL       , "c1",                 2, 1, 0xc00b, 2 },
   { s_cr002 + 6, NULL       , ";",                  1, 1, 0xc01e, 0 },
   { s_cr002 + 7, NULL       , "e2",                 2, 1, 0xc00b, 3 },
   { s_cr002 + 8, NULL       , ":=",                 2, 1, 0xc03c, 0 },
   { s_cr002 + 9, NULL       , "(",                  1, 1, 0xc032, 0 },
   { s_cr002 +10, NULL       , "@",                  1, 1, 0xc038, 0 },
   { s_cr002 +11, NULL       , "e2",                 2, 0, 0xc00b, 3 },
   { s_cr002 +12, NULL       , ")",                  1, 1, 0xc033, 0 },
   { s_cr002 +13, NULL       , ";",                  1, 1, 0xc01e, 0 },
   { s_cr002 +21, s_cr002 +14, "[",                  1, 0, 0xc012, 0 },
   { s_cr002 +15, NULL       , "eN",                 2, 1, 0xc00b, 4 },
   { s_cr002 +16, NULL       , ":=",                 2, 1, 0xc03c, 0 },
   { s_cr002 +17, NULL       , "(",                  1, 1, 0xc032, 0 },
   { s_cr002 +18, NULL       , "@",                  1, 1, 0xc038, 0 },
   { s_cr002 +19, NULL       , "eN",                 2, 0, 0xc00b, 4 },
   { s_cr002 +20, NULL       , ")",                  1, 1, 0xc033, 0 },
   { NULL       , NULL       , ";",                  1, 0, 0xc01e, 0 },
   { s_cr002 +22, NULL       , ";",                  1, 1, 0xc01e, 0 },
   { s_cr002 +23, NULL       , "WHILE",              5, 1, 0xc015, 0 },
   { s_cr002 +24, NULL       , ".T.",                3, 1, 0xc02c, 0 },
   { s_cr002 +25, NULL       , ";",                  1, 1, 0xc01e, 0 },
   { s_cr002 +26, NULL       , "IF",                 2, 1, 0xc015, 0 },
   { s_cr002 +27, NULL       , "HB_EnumIndex",      12, 1, 0xc015, 0 },
   { s_cr002 +28, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr002 +29, NULL       , ")",                  1, 0, 0xc033, 0 },
   { s_cr002 +30, NULL       , "<=",                 2, 1, 0xc04c, 0 },
   { s_cr002 +31, NULL       , "Len",                3, 1, 0xc015, 0 },
   { s_cr002 +32, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr002 +33, NULL       , "c2",                 2, 1, 0xc00b, 5 },
   { s_cr002 +34, NULL       , ")",                  1, 1, 0xc033, 0 },
   { s_cr002 +35, NULL       , ";",                  1, 1, 0xc01e, 0 },
   { s_cr002 +36, NULL       , "e2",                 2, 1, 0xc00b, 3 },
   { s_cr002 +37, NULL       , ":=",                 2, 1, 0xc03c, 0 },
   { s_cr002 +38, NULL       , "(",                  1, 1, 0xc032, 0 },
   { s_cr002 +39, NULL       , "@",                  1, 1, 0xc038, 0 },
   { s_cr002 +40, NULL       , "c2",                 2, 0, 0xc00b, 5 },
   { s_cr002 +41, NULL       , "[",                  1, 0, 0xc034, 0 },
   { s_cr002 +42, NULL       , "HB_EnumIndex",      12, 1, 0xc015, 0 },
   { s_cr002 +43, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr002 +44, NULL       , ")",                  1, 0, 0xc033, 0 },
   { s_cr002 +45, NULL       , "]",                  1, 1, 0xc035, 0 },
   { s_cr002 +46, NULL       , ")",                  1, 1, 0xc033, 0 },
   { s_cr002 +47, NULL       , ";",                  1, 1, 0xc01e, 0 },
   { s_cr002 +48, NULL       , "ELSE",               4, 1, 0xc015, 0 },
   { s_cr002 +49, NULL       , ";",                  1, 1, 0xc01e, 0 },
   { s_cr002 +50, NULL       , "EXIT",               4, 1, 0xc015, 0 },
   { s_cr002 +51, NULL       , ";",                  1, 1, 0xc01e, 0 },
   { s_cr002 +52, NULL       , "ENDIF",              5, 1, 0xc015, 0 },
   { s_cr002 +53, NULL       , ";",                  1, 1, 0xc01e, 0 },
   { s_cr002 +83, s_cr002 +54, "[",                  1, 0, 0xc012, 0 },
   { s_cr002 +55, NULL       , ";",                  1, 1, 0xc01e, 0 },
   { s_cr002 +56, NULL       , "IF",                 2, 1, 0xc015, 0 },
   { s_cr002 +57, NULL       , "HB_EnumIndex",      12, 1, 0xc015, 0 },
   { s_cr002 +58, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr002 +59, NULL       , ")",                  1, 0, 0xc033, 0 },
   { s_cr002 +60, NULL       , "<=",                 2, 1, 0xc04c, 0 },
   { s_cr002 +61, NULL       , "Len",                3, 1, 0xc015, 0 },
   { s_cr002 +62, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr002 +63, NULL       , "cN",                 2, 1, 0xc00b, 6 },
   { s_cr002 +64, NULL       , ")",                  1, 1, 0xc033, 0 },
   { s_cr002 +65, NULL       , ";",                  1, 1, 0xc01e, 0 },
   { s_cr002 +66, NULL       , "eN",                 2, 1, 0xc00b, 4 },
   { s_cr002 +67, NULL       , ":=",                 2, 1, 0xc03c, 0 },
   { s_cr002 +68, NULL       , "(",                  1, 1, 0xc032, 0 },
   { s_cr002 +69, NULL       , "@",                  1, 1, 0xc038, 0 },
   { s_cr002 +70, NULL       , "cN",                 2, 0, 0xc00b, 6 },
   { s_cr002 +71, NULL       , "[",                  1, 0, 0xc034, 0 },
   { s_cr002 +72, NULL       , "HB_EnumIndex",      12, 1, 0xc015, 0 },
   { s_cr002 +73, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr002 +74, NULL       , ")",                  1, 0, 0xc033, 0 },
   { s_cr002 +75, NULL       , "]",                  1, 1, 0xc035, 0 },
   { s_cr002 +76, NULL       , ")",                  1, 1, 0xc033, 0 },
   { s_cr002 +77, NULL       , ";",                  1, 1, 0xc01e, 0 },
   { s_cr002 +78, NULL       , "ELSE",               4, 1, 0xc015, 0 },
   { s_cr002 +79, NULL       , ";",                  1, 1, 0xc01e, 0 },
   { s_cr002 +80, NULL       , "EXIT",               4, 1, 0xc015, 0 },
   { s_cr002 +81, NULL       , ";",                  1, 1, 0xc01e, 0 },
   { s_cr002 +82, NULL       , "ENDIF",              5, 1, 0xc015, 0 },
   { NULL       , NULL       , ";",                  1, 1, 0xc01e, 0 },
   { s_cr002 +84, NULL       , ";",                  1, 1, 0xc01e, 0 },
   { s_cr002 +85, NULL       , "EXIT",               4, 1, 0xc015, 0 },
   { s_cr002 +86, NULL       , ";",                  1, 1, 0xc01e, 0 },
   { s_cr002 +87, NULL       , "END",                3, 1, 0xc015, 0 },
   { s_cr002 +88, NULL       , ";",                  1, 1, 0xc01e, 0 },
   { s_cr002 +89, NULL       , "#",                  1, 1, 0xc020, 0 },
   { s_cr002 +90, NULL       , "xtranslate",        10, 0, 0xc015, 0 },
   { s_cr002 +91, NULL       , "e1",                 2, 1, 0xc00b, 1 },
   { s_cr002 +92, NULL       , ":",                  1, 0, 0xc03a, 0 },
   { s_cr002 +93, NULL       , "__EnumIndex",       11, 0, 0xc015, 0 },
   { s_cr002 +94, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr002 +95, NULL       , ")",                  1, 0, 0xc033, 0 },
   { s_cr002 +96, NULL       , "=",                  1, 1, 0xc049, 0 },
   { s_cr002 +97, NULL       , ">",                  1, 0, 0xc04b, 0 },
   { s_cr002 +98, NULL       , "HB_EnumIndex",      12, 1, 0xc015, 0 },
   { s_cr002 +99, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr002 +100, NULL       , ")",                  1, 0, 0xc033, 0 },
   { s_cr002 +101, NULL       , ";",                  1, 1, 0xc01e, 0 },
   { s_cr002 +102, NULL       , "#",                  1, 1, 0xc020, 0 },
   { s_cr002 +103, NULL       , "xtranslate",        10, 0, 0xc015, 0 },
   { s_cr002 +104, NULL       , "e2",                 2, 1, 0xc00b, 3 },
   { s_cr002 +105, NULL       , ":",                  1, 0, 0xc03a, 0 },
   { s_cr002 +106, NULL       , "__EnumIndex",       11, 0, 0xc015, 0 },
   { s_cr002 +107, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr002 +108, NULL       , ")",                  1, 0, 0xc033, 0 },
   { s_cr002 +109, NULL       , "=",                  1, 1, 0xc049, 0 },
   { s_cr002 +110, NULL       , ">",                  1, 0, 0xc04b, 0 },
   { s_cr002 +111, NULL       , "HB_EnumIndex",      12, 1, 0xc015, 0 },
   { s_cr002 +112, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr002 +113, NULL       , ")",                  1, 0, 0xc033, 0 },
   { s_cr002 +114, NULL       , ";",                  1, 1, 0xc01e, 0 },
   { NULL       , s_cr002 +115, "[",                  1, 0, 0xc012, 0 },
   { s_cr002 +116, NULL       , "#",                  1, 0, 0xc020, 0 },
   { s_cr002 +117, NULL       , "xtranslate",        10, 0, 0xc015, 0 },
   { s_cr002 +118, NULL       , "eN",                 2, 1, 0xc00b, 4 },
   { s_cr002 +119, NULL       , ":",                  1, 0, 0xc03a, 0 },
   { s_cr002 +120, NULL       , "__EnumIndex",       11, 0, 0xc015, 0 },
   { s_cr002 +121, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr002 +122, NULL       , ")",                  1, 0, 0xc033, 0 },
   { s_cr002 +123, NULL       , "=",                  1, 1, 0xc049, 0 },
   { s_cr002 +124, NULL       , ">",                  1, 0, 0xc04b, 0 },
   { s_cr002 +125, NULL       , "HB_EnumIndex",      12, 1, 0xc015, 0 },
   { s_cr002 +126, NULL       , "(",                  1, 0, 0xc032, 0 },
   { NULL       , NULL       , ")",                  1, 0, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm003[ 3 ] = {
   { s_cm003 + 1, NULL       , "WITH",               4, 1, 0xc015, 0 },
   { s_cm003 + 2, NULL       , "NAMESPACE",          9, 1, 0xc015, 0 },
   { NULL       , NULL       , "Global",             6, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_cr003[ 4 ] = {
   { s_cr003 + 1, NULL       , "WITH",               4, 1, 0xc015, 0 },
   { s_cr003 + 2, NULL       , "NAMESPACE",          9, 1, 0xc015, 0 },
   { s_cr003 + 3, NULL       , "PATH",               4, 1, 0xc015, 0 },
   { NULL       , NULL       , "Global",             6, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_cm004[ 7 ] = {
   { s_cm004 + 1, NULL       , "WITH",               4, 1, 0xc015, 0 },
   { s_cm004 + 2, NULL       , "NAMESPACE",          9, 1, 0xc015, 0 },
   { s_cm004 + 3, NULL       , "Name",               4, 0, 0xe001, 1 },
   { s_cm004 + 6, s_cm004 + 4, "[",                  1, 1, 0xe007, 0 },
   { s_cm004 + 5, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { NULL       , NULL       , "SubName",            7, 0, 0xe001, 2 },
   { NULL       , NULL       , "EXPANDED",           8, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_cr004[ 19 ] = {
   { s_cr004 + 1, NULL       , "__OPEN_XNS",        10, 1, 0xc015, 0 },
   { s_cr004 + 2, NULL       , "Name",               4, 1, 0xc00b, 1 },
   { s_cr004 + 3, NULL       , ".",                  1, 0, 0xc01c, 0 },
   { s_cr004 + 4, NULL       , "xns",                3, 0, 0xc015, 0 },
   { s_cr004 + 5, NULL       , ";",                  1, 1, 0xc01e, 0 },
   { s_cr004 + 6, NULL       , "WITH",               4, 1, 0xc015, 0 },
   { s_cr004 + 7, NULL       , "NAMESPACE",          9, 1, 0xc015, 0 },
   { s_cr004 + 8, NULL       , "PATH",               4, 1, 0xc015, 0 },
   { s_cr004 + 9, NULL       , "Name",               4, 1, 0xc00b, 1 },
   { s_cr004 +12, s_cr004 +10, "[",                  1, 1, 0xc012, 0 },
   { s_cr004 +11, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { NULL       , NULL       , "SubName",            7, 1, 0xc00b, 2 },
   { s_cr004 +13, NULL       , ";",                  1, 1, 0xc01e, 0 },
   { s_cr004 +14, NULL       , "#",                  1, 1, 0xc020, 0 },
   { s_cr004 +15, NULL       , "xuntranslate",      12, 0, 0xc015, 0 },
   { s_cr004 +16, NULL       , ".",                  1, 1, 0xc01c, 0 },
   { s_cr004 +17, NULL       , "<",                  1, 1, 0xc04a, 0 },
   { s_cr004 +18, NULL       , "Part",               4, 0, 0xc015, 0 },
   { NULL       , NULL       , ">",                  1, 0, 0xc04b, 0 }
};
static HB_PP_TOKEN s_cm005[ 3 ] = {
   { s_cm005 + 1, NULL       , "WITH",               4, 1, 0xc015, 0 },
   { s_cm005 + 2, NULL       , "NAMESPACE",          9, 1, 0xc015, 0 },
   { NULL       , NULL       , "Path",               4, 0, 0xe001, 1 }
};
static HB_PP_TOKEN s_cr005[ 17 ] = {
   { s_cr005 + 1, NULL       , "#",                  1, 1, 0xc020, 0 },
   { s_cr005 + 2, NULL       , "xtranslate",        10, 0, 0xc015, 0 },
   { s_cr005 + 3, NULL       , ".",                  1, 1, 0xc01c, 0 },
   { s_cr005 + 4, NULL       , "<",                  1, 1, 0xc04a, 0 },
   { s_cr005 + 5, NULL       , "Part",               4, 0, 0xc015, 0 },
   { s_cr005 + 6, NULL       , ">",                  1, 0, 0xc04b, 0 },
   { s_cr005 + 7, NULL       , "=",                  1, 1, 0xc049, 0 },
   { s_cr005 + 8, NULL       , ">",                  1, 0, 0xc04b, 0 },
   { s_cr005 + 9, NULL       , ",",                  1, 1, 0xc01d, 0 },
   { s_cr005 +10, NULL       , "<",                  1, 1, 0xc04a, 0 },
   { s_cr005 +11, NULL       , "Part",               4, 0, 0xc015, 0 },
   { s_cr005 +12, NULL       , ">",                  1, 0, 0xc04b, 0 },
   { s_cr005 +13, NULL       , ";",                  1, 1, 0xc01e, 0 },
   { s_cr005 +14, NULL       , "WITH",               4, 1, 0xc015, 0 },
   { s_cr005 +15, NULL       , "NAMESPACE",          9, 1, 0xc015, 0 },
   { s_cr005 +16, NULL       , "Path",               4, 1, 0xc00b, 1 },
   { NULL       , NULL       , "EXPANDED",           8, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_cm006[ 7 ] = {
   { s_cm006 + 1, NULL       , "USING",              5, 1, 0xc015, 0 },
   { s_cm006 + 2, NULL       , "NAMESPACE",          9, 1, 0xc015, 0 },
   { s_cm006 + 3, NULL       , "Name",               4, 0, 0xe001, 1 },
   { s_cm006 + 6, s_cm006 + 4, "[",                  1, 1, 0xe007, 0 },
   { s_cm006 + 5, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { NULL       , NULL       , "SubName",            7, 0, 0xe001, 2 },
   { NULL       , NULL       , "EXPANDED",           8, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_cr006[ 19 ] = {
   { s_cr006 + 1, NULL       , "__OPEN_XNS",        10, 1, 0xc015, 0 },
   { s_cr006 + 2, NULL       , "Name",               4, 1, 0xc00b, 1 },
   { s_cr006 + 3, NULL       , ".",                  1, 0, 0xc01c, 0 },
   { s_cr006 + 4, NULL       , "xns",                3, 0, 0xc015, 0 },
   { s_cr006 + 5, NULL       , ";",                  1, 1, 0xc01e, 0 },
   { s_cr006 + 6, NULL       , "USING",              5, 1, 0xc015, 0 },
   { s_cr006 + 7, NULL       , "NAMESPACE",          9, 1, 0xc015, 0 },
   { s_cr006 + 8, NULL       , "PATH",               4, 1, 0xc015, 0 },
   { s_cr006 + 9, NULL       , "Name",               4, 1, 0xc00b, 1 },
   { s_cr006 +12, s_cr006 +10, "[",                  1, 1, 0xc012, 0 },
   { s_cr006 +11, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { NULL       , NULL       , "SubName",            7, 1, 0xc00b, 2 },
   { s_cr006 +13, NULL       , ";",                  1, 1, 0xc01e, 0 },
   { s_cr006 +14, NULL       , "#",                  1, 1, 0xc020, 0 },
   { s_cr006 +15, NULL       , "xuntranslate",      12, 0, 0xc015, 0 },
   { s_cr006 +16, NULL       , ".",                  1, 1, 0xc01c, 0 },
   { s_cr006 +17, NULL       , "<",                  1, 1, 0xc04a, 0 },
   { s_cr006 +18, NULL       , "Part",               4, 0, 0xc015, 0 },
   { NULL       , NULL       , ">",                  1, 0, 0xc04b, 0 }
};
static HB_PP_TOKEN s_cm007[ 3 ] = {
   { s_cm007 + 1, NULL       , "USING",              5, 1, 0xc015, 0 },
   { s_cm007 + 2, NULL       , "NAMESPACE",          9, 1, 0xc015, 0 },
   { NULL       , NULL       , "Path",               4, 0, 0xe001, 1 }
};
static HB_PP_TOKEN s_cr007[ 17 ] = {
   { s_cr007 + 1, NULL       , "#",                  1, 1, 0xc020, 0 },
   { s_cr007 + 2, NULL       , "xtranslate",        10, 0, 0xc015, 0 },
   { s_cr007 + 3, NULL       , ".",                  1, 1, 0xc01c, 0 },
   { s_cr007 + 4, NULL       , "<",                  1, 1, 0xc04a, 0 },
   { s_cr007 + 5, NULL       , "Part",               4, 0, 0xc015, 0 },
   { s_cr007 + 6, NULL       , ">",                  1, 0, 0xc04b, 0 },
   { s_cr007 + 7, NULL       , "=",                  1, 1, 0xc049, 0 },
   { s_cr007 + 8, NULL       , ">",                  1, 0, 0xc04b, 0 },
   { s_cr007 + 9, NULL       , ",",                  1, 1, 0xc01d, 0 },
   { s_cr007 +10, NULL       , "<",                  1, 1, 0xc04a, 0 },
   { s_cr007 +11, NULL       , "Part",               4, 0, 0xc015, 0 },
   { s_cr007 +12, NULL       , ">",                  1, 0, 0xc04b, 0 },
   { s_cr007 +13, NULL       , ";",                  1, 1, 0xc01e, 0 },
   { s_cr007 +14, NULL       , "USING",              5, 1, 0xc015, 0 },
   { s_cr007 +15, NULL       , "NAMESPACE",          9, 1, 0xc015, 0 },
   { s_cr007 +16, NULL       , "Path",               4, 1, 0xc00b, 1 },
   { NULL       , NULL       , "EXPANDED",           8, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_cm008[ 5 ] = {
   { s_cm008 + 1, NULL       , "SET",                3, 1, 0xc015, 0 },
   { s_cm008 + 2, NULL       , "WORKAREAS",          9, 1, 0xc015, 0 },
   { s_cm008 + 3, NULL       , "(",                  1, 1, 0xc032, 0 },
   { s_cm008 + 4, NULL       , "x",                  1, 0, 0xe001, 1 },
   { NULL       , NULL       , ")",                  1, 0, 0xc033, 0 }
};
static HB_PP_TOKEN s_cr008[ 6 ] = {
   { s_cr008 + 1, NULL       , "Set",                3, 1, 0xc015, 0 },
   { s_cr008 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr008 + 3, NULL       , "_SET_WORKAREAS_SHARED",  21, 1, 0xc015, 0 },
   { s_cr008 + 4, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr008 + 5, NULL       , "x",                  1, 1, 0xc00b, 1 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm009[ 3 ] = {
   { s_cm009 + 1, NULL       , "SET",                3, 1, 0xc015, 0 },
   { s_cm009 + 2, NULL       , "WORKAREAS",          9, 1, 0xc015, 0 },
   { NULL       , NULL       , "PRIVATE",            7, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_cr009[ 6 ] = {
   { s_cr009 + 1, NULL       , "Set",                3, 1, 0xc015, 0 },
   { s_cr009 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr009 + 3, NULL       , "_SET_WORKAREAS_SHARED",  21, 1, 0xc015, 0 },
   { s_cr009 + 4, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr009 + 5, NULL       , ".F.",                3, 1, 0xc02c, 0 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm010[ 3 ] = {
   { s_cm010 + 1, NULL       , "SET",                3, 1, 0xc015, 0 },
   { s_cm010 + 2, NULL       , "WORKAREAS",          9, 1, 0xc015, 0 },
   { NULL       , NULL       , "SHARED",             6, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_cr010[ 6 ] = {
   { s_cr010 + 1, NULL       , "Set",                3, 1, 0xc015, 0 },
   { s_cr010 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr010 + 3, NULL       , "_SET_WORKAREAS_SHARED",  21, 1, 0xc015, 0 },
   { s_cr010 + 4, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr010 + 5, NULL       , ".T.",                3, 1, 0xc02c, 0 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm011[ 9 ] = {
   { s_cm011 + 1, NULL       , "SET",                3, 1, 0xc015, 0 },
   { s_cm011 + 2, NULL       , "WORKAREAS",          9, 1, 0xc015, 0 },
   { s_cm011 + 3, NULL       , "SHARED",             6, 1, 0xc015, 0 },
   { NULL       , s_cm011 + 4, "x",                  1, 0, 0xc003, 1 },
   { s_cm011 + 5, NULL       , "ON",                 2, 0, 0xc015, 0 },
   { s_cm011 + 6, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cm011 + 7, NULL       , "OFF",                3, 0, 0xc015, 0 },
   { s_cm011 + 8, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { NULL       , NULL       , "&",                  1, 0, 0xc039, 0 }
};
static HB_PP_TOKEN s_cr011[ 6 ] = {
   { s_cr011 + 1, NULL       , "Set",                3, 1, 0xc015, 0 },
   { s_cr011 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr011 + 3, NULL       , "_SET_WORKAREAS_SHARED",  21, 1, 0xc015, 0 },
   { s_cr011 + 4, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr011 + 5, NULL       , "x",                  1, 1, 0xc00e, 1 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm012[ 7 ] = {
   { s_cm012 + 1, NULL       , "SET",                3, 1, 0xc015, 0 },
   { s_cm012 + 2, NULL       , "MACRO",              5, 1, 0xc015, 0 },
   { s_cm012 + 3, NULL       , "BLOCK",              5, 1, 0xc015, 0 },
   { s_cm012 + 4, NULL       , "VARS",               4, 1, 0xc015, 0 },
   { s_cm012 + 5, NULL       , "(",                  1, 1, 0xc032, 0 },
   { s_cm012 + 6, NULL       , "x",                  1, 0, 0xe001, 1 },
   { NULL       , NULL       , ")",                  1, 0, 0xc033, 0 }
};
static HB_PP_TOKEN s_cr012[ 6 ] = {
   { s_cr012 + 1, NULL       , "Set",                3, 1, 0xc015, 0 },
   { s_cr012 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr012 + 3, NULL       , "_SET_MACROBLOCKVARS",  19, 1, 0xc015, 0 },
   { s_cr012 + 4, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr012 + 5, NULL       , "x",                  1, 1, 0xc00b, 1 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm013[ 5 ] = {
   { s_cm013 + 1, NULL       , "SET",                3, 1, 0xc015, 0 },
   { s_cm013 + 2, NULL       , "MACRO",              5, 1, 0xc015, 0 },
   { s_cm013 + 3, NULL       , "BLOCK",              5, 1, 0xc015, 0 },
   { s_cm013 + 4, NULL       , "VARS",               4, 1, 0xc015, 0 },
   { NULL       , NULL       , "CLIPPER",            7, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_cr013[ 6 ] = {
   { s_cr013 + 1, NULL       , "Set",                3, 1, 0xc015, 0 },
   { s_cr013 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr013 + 3, NULL       , "_SET_MACROBLOCKVARS",  19, 1, 0xc015, 0 },
   { s_cr013 + 4, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr013 + 5, NULL       , ".F.",                3, 1, 0xc02c, 0 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm014[ 5 ] = {
   { s_cm014 + 1, NULL       , "SET",                3, 1, 0xc015, 0 },
   { s_cm014 + 2, NULL       , "MACRO",              5, 1, 0xc015, 0 },
   { s_cm014 + 3, NULL       , "BLOCK",              5, 1, 0xc015, 0 },
   { s_cm014 + 4, NULL       , "VARS",               4, 1, 0xc015, 0 },
   { NULL       , NULL       , "XHARBOUR",           8, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_cr014[ 6 ] = {
   { s_cr014 + 1, NULL       , "Set",                3, 1, 0xc015, 0 },
   { s_cr014 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr014 + 3, NULL       , "_SET_MACROBLOCKVARS",  19, 1, 0xc015, 0 },
   { s_cr014 + 4, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr014 + 5, NULL       , ".T.",                3, 1, 0xc02c, 0 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm015[ 10 ] = {
   { s_cm015 + 1, NULL       , "SET",                3, 1, 0xc015, 0 },
   { s_cm015 + 2, NULL       , "MACRO",              5, 1, 0xc015, 0 },
   { s_cm015 + 3, NULL       , "BLOCK",              5, 1, 0xc015, 0 },
   { s_cm015 + 4, NULL       , "VARS",               4, 1, 0xc015, 0 },
   { NULL       , s_cm015 + 5, "x",                  1, 0, 0xc003, 1 },
   { s_cm015 + 6, NULL       , "ON",                 2, 0, 0xc015, 0 },
   { s_cm015 + 7, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cm015 + 8, NULL       , "OFF",                3, 0, 0xc015, 0 },
   { s_cm015 + 9, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { NULL       , NULL       , "&",                  1, 0, 0xc039, 0 }
};
static HB_PP_TOKEN s_cr015[ 6 ] = {
   { s_cr015 + 1, NULL       , "Set",                3, 1, 0xc015, 0 },
   { s_cr015 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr015 + 3, NULL       , "_SET_MACROBLOCKVARS",  19, 1, 0xc015, 0 },
   { s_cr015 + 4, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr015 + 5, NULL       , "x",                  1, 1, 0xc00e, 1 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm016[ 6 ] = {
   { s_cm016 + 1, NULL       , "SET",                3, 1, 0xc015, 0 },
   { s_cm016 + 2, NULL       , "TIME",               4, 1, 0xc015, 0 },
   { s_cm016 + 3, NULL       , "FORMAT",             6, 1, 0xc015, 0 },
   { s_cm016 + 5, s_cm016 + 4, "[",                  1, 1, 0xe007, 0 },
   { NULL       , NULL       , "TO",                 2, 0, 0xc015, 0 },
   { NULL       , NULL       , "f",                  1, 0, 0xe001, 1 }
};
static HB_PP_TOKEN s_cr016[ 6 ] = {
   { s_cr016 + 1, NULL       , "Set",                3, 1, 0xc015, 0 },
   { s_cr016 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr016 + 3, NULL       , "_SET_TIMEFORMAT",   15, 1, 0xc015, 0 },
   { s_cr016 + 4, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr016 + 5, NULL       , "f",                  1, 1, 0xc00b, 1 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm017[ 8 ] = {
   { s_cm017 + 1, NULL       , "SET",                3, 1, 0xc015, 0 },
   { s_cm017 + 2, NULL       , "ERRORLOG",           8, 1, 0xc015, 0 },
   { s_cm017 + 3, NULL       , "TO",                 2, 1, 0xc015, 0 },
   { s_cm017 + 6, s_cm017 + 4, "[",                  1, 1, 0xe007, 0 },
   { NULL       , s_cm017 + 5, "additive",           8, 0, 0xc003, 2 },
   { NULL       , NULL       , "ADDITIVE",           8, 1, 0xc015, 0 },
   { NULL       , s_cm017 + 7, "[",                  1, 1, 0xe007, 0 },
   { NULL       , NULL       , "filename",           8, 0, 0xe005, 1 }
};
static HB_PP_TOKEN s_cr017[ 8 ] = {
   { s_cr017 + 1, NULL       , "Set",                3, 1, 0xc015, 0 },
   { s_cr017 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr017 + 3, NULL       , "_SET_ERRORLOG",     13, 1, 0xc015, 0 },
   { s_cr017 + 4, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr017 + 5, NULL       , "filename",           8, 1, 0xc00e, 1 },
   { s_cr017 + 6, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr017 + 7, NULL       , "additive",           8, 1, 0xc010, 2 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm018[ 3 ] = {
   { s_cm018 + 1, NULL       , "SET",                3, 1, 0xc015, 0 },
   { s_cm018 + 2, NULL       , "BACKGROUNDTICK",    14, 1, 0xc015, 0 },
   { NULL       , NULL       , "x",                  1, 0, 0xe001, 1 }
};
static HB_PP_TOKEN s_cr018[ 6 ] = {
   { s_cr018 + 1, NULL       , "Set",                3, 1, 0xc015, 0 },
   { s_cr018 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr018 + 3, NULL       , "_SET_BACKGROUNDTICK",  19, 1, 0xc015, 0 },
   { s_cr018 + 4, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr018 + 5, NULL       , "x",                  1, 1, 0xc00b, 1 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm019[ 6 ] = {
   { s_cm019 + 1, NULL       , "SET",                3, 1, 0xc015, 0 },
   { s_cm019 + 2, NULL       , "BACKGROUND",        10, 1, 0xc015, 0 },
   { s_cm019 + 3, NULL       , "TASKS",              5, 1, 0xc015, 0 },
   { s_cm019 + 4, NULL       , "(",                  1, 1, 0xc032, 0 },
   { s_cm019 + 5, NULL       , "x",                  1, 0, 0xe001, 1 },
   { NULL       , NULL       , ")",                  1, 0, 0xc033, 0 }
};
static HB_PP_TOKEN s_cr019[ 6 ] = {
   { s_cr019 + 1, NULL       , "Set",                3, 1, 0xc015, 0 },
   { s_cr019 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr019 + 3, NULL       , "_SET_BACKGROUNDTASKS",  20, 1, 0xc015, 0 },
   { s_cr019 + 4, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr019 + 5, NULL       , "x",                  1, 1, 0xc00b, 1 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm020[ 9 ] = {
   { s_cm020 + 1, NULL       , "SET",                3, 1, 0xc015, 0 },
   { s_cm020 + 2, NULL       , "BACKGROUND",        10, 1, 0xc015, 0 },
   { s_cm020 + 3, NULL       , "TASKS",              5, 1, 0xc015, 0 },
   { NULL       , s_cm020 + 4, "x",                  1, 0, 0xc003, 1 },
   { s_cm020 + 5, NULL       , "ON",                 2, 0, 0xc015, 0 },
   { s_cm020 + 6, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cm020 + 7, NULL       , "OFF",                3, 0, 0xc015, 0 },
   { s_cm020 + 8, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { NULL       , NULL       , "&",                  1, 0, 0xc039, 0 }
};
static HB_PP_TOKEN s_cr020[ 6 ] = {
   { s_cr020 + 1, NULL       , "Set",                3, 1, 0xc015, 0 },
   { s_cr020 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr020 + 3, NULL       , "_SET_BACKGROUNDTASKS",  20, 1, 0xc015, 0 },
   { s_cr020 + 4, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr020 + 5, NULL       , "x",                  1, 1, 0xc00e, 1 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm021[ 5 ] = {
   { s_cm021 + 1, NULL       , "SET",                3, 1, 0xc015, 0 },
   { s_cm021 + 2, NULL       , "TRACE",              5, 1, 0xc015, 0 },
   { s_cm021 + 3, NULL       , "(",                  1, 1, 0xc032, 0 },
   { s_cm021 + 4, NULL       , "x",                  1, 0, 0xe001, 1 },
   { NULL       , NULL       , ")",                  1, 0, 0xc033, 0 }
};
static HB_PP_TOKEN s_cr021[ 6 ] = {
   { s_cr021 + 1, NULL       , "Set",                3, 1, 0xc015, 0 },
   { s_cr021 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr021 + 3, NULL       , "_SET_TRACE",        10, 1, 0xc015, 0 },
   { s_cr021 + 4, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr021 + 5, NULL       , "x",                  1, 1, 0xc00b, 1 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm022[ 8 ] = {
   { s_cm022 + 1, NULL       , "SET",                3, 1, 0xc015, 0 },
   { s_cm022 + 2, NULL       , "TRACE",              5, 1, 0xc015, 0 },
   { NULL       , s_cm022 + 3, "x",                  1, 0, 0xc003, 1 },
   { s_cm022 + 4, NULL       , "ON",                 2, 0, 0xc015, 0 },
   { s_cm022 + 5, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cm022 + 6, NULL       , "OFF",                3, 0, 0xc015, 0 },
   { s_cm022 + 7, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { NULL       , NULL       , "&",                  1, 0, 0xc039, 0 }
};
static HB_PP_TOKEN s_cr022[ 6 ] = {
   { s_cr022 + 1, NULL       , "Set",                3, 1, 0xc015, 0 },
   { s_cr022 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr022 + 3, NULL       , "_SET_TRACE",        10, 1, 0xc015, 0 },
   { s_cr022 + 4, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr022 + 5, NULL       , "x",                  1, 1, 0xc00e, 1 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm023[ 5 ] = {
   { s_cm023 + 1, NULL       , "SET",                3, 1, 0xc015, 0 },
   { s_cm023 + 2, NULL       , "HARDCOMMIT",        10, 1, 0xc015, 0 },
   { s_cm023 + 3, NULL       , "(",                  1, 1, 0xc032, 0 },
   { s_cm023 + 4, NULL       , "x",                  1, 0, 0xe001, 1 },
   { NULL       , NULL       , ")",                  1, 0, 0xc033, 0 }
};
static HB_PP_TOKEN s_cr023[ 6 ] = {
   { s_cr023 + 1, NULL       , "Set",                3, 1, 0xc015, 0 },
   { s_cr023 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr023 + 3, NULL       , "_SET_HARDCOMMIT",   15, 1, 0xc015, 0 },
   { s_cr023 + 4, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr023 + 5, NULL       , "x",                  1, 1, 0xc00b, 1 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm024[ 8 ] = {
   { s_cm024 + 1, NULL       , "SET",                3, 1, 0xc015, 0 },
   { s_cm024 + 2, NULL       , "HARDCOMMIT",        10, 1, 0xc015, 0 },
   { NULL       , s_cm024 + 3, "x",                  1, 0, 0xc003, 1 },
   { s_cm024 + 4, NULL       , "ON",                 2, 0, 0xc015, 0 },
   { s_cm024 + 5, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cm024 + 6, NULL       , "OFF",                3, 0, 0xc015, 0 },
   { s_cm024 + 7, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { NULL       , NULL       , "&",                  1, 0, 0xc039, 0 }
};
static HB_PP_TOKEN s_cr024[ 6 ] = {
   { s_cr024 + 1, NULL       , "Set",                3, 1, 0xc015, 0 },
   { s_cr024 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr024 + 3, NULL       , "_SET_HARDCOMMIT",   15, 1, 0xc015, 0 },
   { s_cr024 + 4, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr024 + 5, NULL       , "x",                  1, 1, 0xc00e, 1 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm025[ 3 ] = {
   { s_cm025 + 1, NULL       , "SET",                3, 1, 0xc015, 0 },
   { s_cm025 + 2, NULL       , "DBFLOCKSCHEME",     13, 1, 0xc015, 0 },
   { NULL       , NULL       , "TO",                 2, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_cr025[ 6 ] = {
   { s_cr025 + 1, NULL       , "Set",                3, 1, 0xc015, 0 },
   { s_cr025 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr025 + 3, NULL       , "_SET_DBFLOCKSCHEME",  18, 1, 0xc015, 0 },
   { s_cr025 + 4, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr025 + 5, NULL       , "0",                  1, 1, 0xc02a, 0 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm026[ 4 ] = {
   { s_cm026 + 1, NULL       , "SET",                3, 1, 0xc015, 0 },
   { s_cm026 + 2, NULL       , "DBFLOCKSCHEME",     13, 1, 0xc015, 0 },
   { s_cm026 + 3, NULL       , "TO",                 2, 1, 0xc015, 0 },
   { NULL       , NULL       , "x",                  1, 0, 0xe001, 1 }
};
static HB_PP_TOKEN s_cr026[ 6 ] = {
   { s_cr026 + 1, NULL       , "Set",                3, 1, 0xc015, 0 },
   { s_cr026 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr026 + 3, NULL       , "_SET_DBFLOCKSCHEME",  18, 1, 0xc015, 0 },
   { s_cr026 + 4, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr026 + 5, NULL       , "x",                  1, 1, 0xc00b, 1 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm027[ 6 ] = {
   { s_cm027 + 1, NULL       , "SET",                3, 1, 0xc015, 0 },
   { s_cm027 + 2, NULL       , "OUTPUT",             6, 1, 0xc015, 0 },
   { s_cm027 + 3, NULL       , "SAFETY",             6, 1, 0xc015, 0 },
   { s_cm027 + 4, NULL       , "(",                  1, 1, 0xc032, 0 },
   { s_cm027 + 5, NULL       , "x",                  1, 0, 0xe001, 1 },
   { NULL       , NULL       , ")",                  1, 0, 0xc033, 0 }
};
static HB_PP_TOKEN s_cr027[ 6 ] = {
   { s_cr027 + 1, NULL       , "Set",                3, 1, 0xc015, 0 },
   { s_cr027 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr027 + 3, NULL       , "_SET_OUTPUTSAFETY",  17, 1, 0xc015, 0 },
   { s_cr027 + 4, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr027 + 5, NULL       , "x",                  1, 1, 0xc00b, 1 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm028[ 9 ] = {
   { s_cm028 + 1, NULL       , "SET",                3, 1, 0xc015, 0 },
   { s_cm028 + 2, NULL       , "OUTPUT",             6, 1, 0xc015, 0 },
   { s_cm028 + 3, NULL       , "SAFETY",             6, 1, 0xc015, 0 },
   { NULL       , s_cm028 + 4, "x",                  1, 0, 0xc003, 1 },
   { s_cm028 + 5, NULL       , "ON",                 2, 0, 0xc015, 0 },
   { s_cm028 + 6, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cm028 + 7, NULL       , "OFF",                3, 0, 0xc015, 0 },
   { s_cm028 + 8, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { NULL       , NULL       , "&",                  1, 0, 0xc039, 0 }
};
static HB_PP_TOKEN s_cr028[ 6 ] = {
   { s_cr028 + 1, NULL       , "Set",                3, 1, 0xc015, 0 },
   { s_cr028 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr028 + 3, NULL       , "_SET_OUTPUTSAFETY",  17, 1, 0xc015, 0 },
   { s_cr028 + 4, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr028 + 5, NULL       , "x",                  1, 1, 0xc00e, 1 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm029[ 8 ] = {
   { s_cm029 + 1, NULL       , "SET",                3, 1, 0xc015, 0 },
   { s_cm029 + 2, NULL       , "TRIMFILENAME",      12, 1, 0xc015, 0 },
   { NULL       , s_cm029 + 3, "x",                  1, 0, 0xc003, 1 },
   { s_cm029 + 4, NULL       , "ON",                 2, 0, 0xc015, 0 },
   { s_cm029 + 5, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cm029 + 6, NULL       , "OFF",                3, 0, 0xc015, 0 },
   { s_cm029 + 7, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { NULL       , NULL       , "&",                  1, 0, 0xc039, 0 }
};
static HB_PP_TOKEN s_cr029[ 6 ] = {
   { s_cr029 + 1, NULL       , "Set",                3, 1, 0xc015, 0 },
   { s_cr029 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr029 + 3, NULL       , "_SET_TRIMFILENAME",  17, 1, 0xc015, 0 },
   { s_cr029 + 4, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr029 + 5, NULL       , "x",                  1, 1, 0xc00e, 1 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm030[ 3 ] = {
   { s_cm030 + 1, NULL       , "SET",                3, 1, 0xc015, 0 },
   { s_cm030 + 2, NULL       , "DIRSEPARATOR",      12, 1, 0xc015, 0 },
   { NULL       , NULL       , "x",                  1, 0, 0xe001, 1 }
};
static HB_PP_TOKEN s_cr030[ 6 ] = {
   { s_cr030 + 1, NULL       , "Set",                3, 1, 0xc015, 0 },
   { s_cr030 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr030 + 3, NULL       , "_SET_DIRSEPARATOR",  17, 1, 0xc015, 0 },
   { s_cr030 + 4, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr030 + 5, NULL       , "x",                  1, 1, 0xc00b, 1 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm031[ 5 ] = {
   { s_cm031 + 1, NULL       , "SET",                3, 1, 0xc015, 0 },
   { s_cm031 + 2, NULL       , "DIRCASE",            7, 1, 0xc015, 0 },
   { s_cm031 + 3, NULL       , "(",                  1, 1, 0xc032, 0 },
   { s_cm031 + 4, NULL       , "x",                  1, 0, 0xe001, 1 },
   { NULL       , NULL       , ")",                  1, 0, 0xc033, 0 }
};
static HB_PP_TOKEN s_cr031[ 6 ] = {
   { s_cr031 + 1, NULL       , "Set",                3, 1, 0xc015, 0 },
   { s_cr031 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr031 + 3, NULL       , "_SET_DIRCASE",      12, 1, 0xc015, 0 },
   { s_cr031 + 4, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr031 + 5, NULL       , "x",                  1, 1, 0xc00b, 1 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm032[ 3 ] = {
   { s_cm032 + 1, NULL       , "SET",                3, 1, 0xc015, 0 },
   { s_cm032 + 2, NULL       , "DIRCASE",            7, 1, 0xc015, 0 },
   { NULL       , NULL       , "x",                  1, 0, 0xe005, 1 }
};
static HB_PP_TOKEN s_cr032[ 6 ] = {
   { s_cr032 + 1, NULL       , "Set",                3, 1, 0xc015, 0 },
   { s_cr032 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr032 + 3, NULL       , "_SET_DIRCASE",      12, 1, 0xc015, 0 },
   { s_cr032 + 4, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr032 + 5, NULL       , "x",                  1, 1, 0xc00e, 1 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm033[ 5 ] = {
   { s_cm033 + 1, NULL       , "SET",                3, 1, 0xc015, 0 },
   { s_cm033 + 2, NULL       , "FILECASE",           8, 1, 0xc015, 0 },
   { s_cm033 + 3, NULL       , "(",                  1, 1, 0xc032, 0 },
   { s_cm033 + 4, NULL       , "x",                  1, 0, 0xe001, 1 },
   { NULL       , NULL       , ")",                  1, 0, 0xc033, 0 }
};
static HB_PP_TOKEN s_cr033[ 6 ] = {
   { s_cr033 + 1, NULL       , "Set",                3, 1, 0xc015, 0 },
   { s_cr033 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr033 + 3, NULL       , "_SET_FILECASE",     13, 1, 0xc015, 0 },
   { s_cr033 + 4, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr033 + 5, NULL       , "x",                  1, 1, 0xc00b, 1 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm034[ 3 ] = {
   { s_cm034 + 1, NULL       , "SET",                3, 1, 0xc015, 0 },
   { s_cm034 + 2, NULL       , "FILECASE",           8, 1, 0xc015, 0 },
   { NULL       , NULL       , "x",                  1, 0, 0xe005, 1 }
};
static HB_PP_TOKEN s_cr034[ 6 ] = {
   { s_cr034 + 1, NULL       , "Set",                3, 1, 0xc015, 0 },
   { s_cr034 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr034 + 3, NULL       , "_SET_FILECASE",     13, 1, 0xc015, 0 },
   { s_cr034 + 4, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr034 + 5, NULL       , "x",                  1, 1, 0xc00e, 1 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm035[ 29 ] = {
   { s_cm035 + 1, NULL       , "@",                  1, 1, 0xc038, 0 },
   { s_cm035 + 2, NULL       , "top",                3, 0, 0xe001, 1 },
   { s_cm035 + 3, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cm035 + 4, NULL       , "left",               4, 0, 0xe001, 2 },
   { s_cm035 + 5, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cm035 + 6, NULL       , "bottom",             6, 0, 0xe001, 7 },
   { s_cm035 + 7, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cm035 + 8, NULL       , "right",              5, 0, 0xe001, 8 },
   { s_cm035 + 9, NULL       , "GET",                3, 1, 0xc015, 0 },
   { s_cm035 +10, NULL       , "v",                  1, 0, 0xe001, 3 },
   { s_cm035 +11, NULL       , "TBROWSE",            7, 1, 0xc015, 0 },
   { s_cm035 +12, NULL       , "oBrowse",            7, 0, 0xe001, 6 },
   { s_cm035 +13, NULL       , "ALIAS",              5, 2, 0xc015, 0 },
   { s_cm035 +14, NULL       , "a",                  1, 0, 0xe001, 9 },
   { s_cm035 +17, s_cm035 +15, "[",                  1, 1, 0xe007, 0 },
   { s_cm035 +16, NULL       , "VALID",              5, 0, 0xc015, 0 },
   { NULL       , NULL       , "valid",              5, 0, 0xe001, 4 },
   { s_cm035 +20, s_cm035 +18, "[",                  1, 1, 0xe007, 0 },
   { s_cm035 +19, NULL       , "WHEN",               4, 0, 0xc015, 0 },
   { NULL       , NULL       , "when",               4, 0, 0xe001, 5 },
   { s_cm035 +23, s_cm035 +21, "[",                  1, 1, 0xe007, 0 },
   { s_cm035 +22, NULL       , "MESSAGE",            7, 0, 0xc015, 0 },
   { NULL       , NULL       , "msg",                3, 0, 0xe001, 10 },
   { s_cm035 +26, s_cm035 +24, "[",                  1, 1, 0xe007, 0 },
   { s_cm035 +25, NULL       , "SEND",               4, 0, 0xc015, 0 },
   { NULL       , NULL       , "snd",                3, 0, 0xe001, 11 },
   { NULL       , s_cm035 +27, "[",                  1, 1, 0xe007, 0 },
   { s_cm035 +28, NULL       , "GUISEND",            7, 0, 0xc015, 0 },
   { NULL       , NULL       , "gsnd",               4, 0, 0xe001, 12 }
};
static HB_PP_TOKEN s_cr035[ 136 ] = {
   { s_cr035 + 1, NULL       , "SetPos",             6, 1, 0xc015, 0 },
   { s_cr035 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr035 + 3, NULL       , "top",                3, 1, 0xc00b, 1 },
   { s_cr035 + 4, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr035 + 5, NULL       , "left",               4, 1, 0xc00b, 2 },
   { s_cr035 + 6, NULL       , ")",                  1, 1, 0xc033, 0 },
   { s_cr035 + 7, NULL       , ";",                  1, 1, 0xc01e, 0 },
   { s_cr035 + 8, NULL       , "AAdd",               4, 1, 0xc015, 0 },
   { s_cr035 + 9, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr035 +10, NULL       , "GetList",            7, 1, 0xc015, 0 },
   { s_cr035 +11, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr035 +12, NULL       , "_GET_",              5, 1, 0xc015, 0 },
   { s_cr035 +13, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr035 +14, NULL       , "v",                  1, 1, 0xc00b, 3 },
   { s_cr035 +15, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr035 +16, NULL       , "v",                  1, 1, 0xc00e, 3 },
   { s_cr035 +17, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr035 +18, NULL       , "NIL",                3, 1, 0xc015, 0 },
   { s_cr035 +19, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr035 +20, NULL       , "valid",              5, 1, 0xc00f, 4 },
   { s_cr035 +21, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr035 +22, NULL       , "when",               4, 1, 0xc00f, 5 },
   { s_cr035 +23, NULL       , ")",                  1, 1, 0xc033, 0 },
   { s_cr035 +24, NULL       , ")",                  1, 1, 0xc033, 0 },
   { s_cr035 +25, NULL       , ";",                  1, 1, 0xc01e, 0 },
   { s_cr035 +26, NULL       , "oBrowse",            7, 1, 0xc00b, 6 },
   { s_cr035 +27, NULL       , ":",                  1, 0, 0xc03a, 0 },
   { s_cr035 +28, NULL       , "ntop",               4, 0, 0xc015, 0 },
   { s_cr035 +29, NULL       , ":=",                 2, 1, 0xc03c, 0 },
   { s_cr035 +30, NULL       , "ATail",              5, 1, 0xc015, 0 },
   { s_cr035 +31, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr035 +32, NULL       , "Getlist",            7, 0, 0xc015, 0 },
   { s_cr035 +33, NULL       , ")",                  1, 0, 0xc033, 0 },
   { s_cr035 +34, NULL       , ":",                  1, 0, 0xc03a, 0 },
   { s_cr035 +35, NULL       , "row",                3, 0, 0xc015, 0 },
   { s_cr035 +36, NULL       , ";",                  1, 1, 0xc01e, 0 },
   { s_cr035 +37, NULL       , "oBrowse",            7, 1, 0xc00b, 6 },
   { s_cr035 +38, NULL       , ":",                  1, 0, 0xc03a, 0 },
   { s_cr035 +39, NULL       , "nleft",              5, 0, 0xc015, 0 },
   { s_cr035 +40, NULL       , ":=",                 2, 1, 0xc03c, 0 },
   { s_cr035 +41, NULL       , "ATail",              5, 1, 0xc015, 0 },
   { s_cr035 +42, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr035 +43, NULL       , "Getlist",            7, 0, 0xc015, 0 },
   { s_cr035 +44, NULL       , ")",                  1, 0, 0xc033, 0 },
   { s_cr035 +45, NULL       , ":",                  1, 0, 0xc03a, 0 },
   { s_cr035 +46, NULL       , "col",                3, 0, 0xc015, 0 },
   { s_cr035 +47, NULL       , ";",                  1, 1, 0xc01e, 0 },
   { s_cr035 +48, NULL       , "oBrowse",            7, 1, 0xc00b, 6 },
   { s_cr035 +49, NULL       , ":",                  1, 0, 0xc03a, 0 },
   { s_cr035 +50, NULL       , "nbottom",            7, 0, 0xc015, 0 },
   { s_cr035 +51, NULL       , ":=",                 2, 1, 0xc03c, 0 },
   { s_cr035 +52, NULL       , "bottom",             6, 1, 0xc00b, 7 },
   { s_cr035 +53, NULL       , ";",                  1, 1, 0xc01e, 0 },
   { s_cr035 +54, NULL       , "oBrowse",            7, 1, 0xc00b, 6 },
   { s_cr035 +55, NULL       , ":",                  1, 0, 0xc03a, 0 },
   { s_cr035 +56, NULL       , "nright",             6, 0, 0xc015, 0 },
   { s_cr035 +57, NULL       , ":=",                 2, 1, 0xc03c, 0 },
   { s_cr035 +58, NULL       , "right",              5, 1, 0xc00b, 8 },
   { s_cr035 +59, NULL       , ";",                  1, 1, 0xc01e, 0 },
   { s_cr035 +60, NULL       , "oBrowse",            7, 1, 0xc00b, 6 },
   { s_cr035 +61, NULL       , ":",                  1, 0, 0xc03a, 0 },
   { s_cr035 +62, NULL       , "Configure",          9, 0, 0xc015, 0 },
   { s_cr035 +63, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr035 +64, NULL       , ")",                  1, 0, 0xc033, 0 },
   { s_cr035 +65, NULL       , ";",                  1, 1, 0xc01e, 0 },
   { s_cr035 +66, NULL       , "ATail",              5, 1, 0xc015, 0 },
   { s_cr035 +67, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr035 +68, NULL       , "GetList",            7, 0, 0xc015, 0 },
   { s_cr035 +69, NULL       , ")",                  1, 0, 0xc033, 0 },
   { s_cr035 +70, NULL       , ":",                  1, 0, 0xc03a, 0 },
   { s_cr035 +71, NULL       , "Control",            7, 0, 0xc015, 0 },
   { s_cr035 +72, NULL       , ":=",                 2, 1, 0xc03c, 0 },
   { s_cr035 +73, NULL       , "oBrowse",            7, 1, 0xc00b, 6 },
   { s_cr035 +74, NULL       , ";",                  1, 1, 0xc01e, 0 },
   { s_cr035 +75, NULL       , "ATail",              5, 1, 0xc015, 0 },
   { s_cr035 +76, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr035 +77, NULL       , "GetList",            7, 0, 0xc015, 0 },
   { s_cr035 +78, NULL       , ")",                  1, 0, 0xc033, 0 },
   { s_cr035 +79, NULL       , ":",                  1, 0, 0xc03a, 0 },
   { s_cr035 +80, NULL       , "reader",             6, 0, 0xc015, 0 },
   { s_cr035 +81, NULL       , ":=",                 2, 1, 0xc03c, 0 },
   { s_cr035 +82, NULL       , "{",                  1, 1, 0xc036, 0 },
   { s_cr035 +83, NULL       , "|",                  1, 1, 0xc01b, 0 },
   { s_cr035 +84, NULL       , "a",                  1, 1, 0xc015, 0 },
   { s_cr035 +85, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr035 +86, NULL       , "b",                  1, 1, 0xc015, 0 },
   { s_cr035 +87, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr035 +88, NULL       , "c",                  1, 1, 0xc015, 0 },
   { s_cr035 +89, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr035 +90, NULL       , "d",                  1, 1, 0xc015, 0 },
   { s_cr035 +91, NULL       , "|",                  1, 1, 0xc01b, 0 },
   { s_cr035 +92, NULL       , "a",                  1, 1, 0xc00b, 9 },
   { s_cr035 +93, NULL       , "->",                 2, 0, 0xc03b, 0 },
   { s_cr035 +94, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr035 +95, NULL       , "TBReader",           8, 1, 0xc015, 0 },
   { s_cr035 +96, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr035 +97, NULL       , "a",                  1, 1, 0xc015, 0 },
   { s_cr035 +98, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr035 +99, NULL       , "b",                  1, 1, 0xc015, 0 },
   { s_cr035 +100, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr035 +101, NULL       , "c",                  1, 1, 0xc015, 0 },
   { s_cr035 +102, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr035 +103, NULL       , "d",                  1, 1, 0xc015, 0 },
   { s_cr035 +104, NULL       , ")",                  1, 1, 0xc033, 0 },
   { s_cr035 +105, NULL       , ")",                  1, 1, 0xc033, 0 },
   { s_cr035 +106, NULL       , "}",                  1, 1, 0xc037, 0 },
   { s_cr035 +118, s_cr035 +107, "[",                  1, 1, 0xc012, 0 },
   { s_cr035 +108, NULL       , ";",                  1, 1, 0xc01e, 0 },
   { s_cr035 +109, NULL       , "ATail",              5, 1, 0xc015, 0 },
   { s_cr035 +110, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr035 +111, NULL       , "GetList",            7, 0, 0xc015, 0 },
   { s_cr035 +112, NULL       , ")",                  1, 0, 0xc033, 0 },
   { s_cr035 +113, NULL       , ":",                  1, 0, 0xc03a, 0 },
   { s_cr035 +114, NULL       , "Control",            7, 0, 0xc015, 0 },
   { s_cr035 +115, NULL       , ":",                  1, 0, 0xc03a, 0 },
   { s_cr035 +116, NULL       , "Message",            7, 0, 0xc015, 0 },
   { s_cr035 +117, NULL       , ":=",                 2, 1, 0xc03c, 0 },
   { NULL       , NULL       , "msg",                3, 1, 0xc00b, 10 },
   { s_cr035 +126, s_cr035 +119, "[",                  1, 1, 0xc012, 0 },
   { s_cr035 +120, NULL       , ";",                  1, 1, 0xc01e, 0 },
   { s_cr035 +121, NULL       , "ATail",              5, 1, 0xc015, 0 },
   { s_cr035 +122, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr035 +123, NULL       , "GetList",            7, 0, 0xc015, 0 },
   { s_cr035 +124, NULL       , ")",                  1, 0, 0xc033, 0 },
   { s_cr035 +125, NULL       , ":",                  1, 0, 0xc03a, 0 },
   { NULL       , NULL       , "snd",                3, 0, 0xc00b, 11 },
   { NULL       , s_cr035 +127, "[",                  1, 1, 0xc012, 0 },
   { s_cr035 +128, NULL       , ";",                  1, 1, 0xc01e, 0 },
   { s_cr035 +129, NULL       , "ATail",              5, 1, 0xc015, 0 },
   { s_cr035 +130, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr035 +131, NULL       , "GetList",            7, 0, 0xc015, 0 },
   { s_cr035 +132, NULL       , ")",                  1, 0, 0xc033, 0 },
   { s_cr035 +133, NULL       , ":",                  1, 0, 0xc03a, 0 },
   { s_cr035 +134, NULL       , "Control",            7, 0, 0xc015, 0 },
   { s_cr035 +135, NULL       , ":",                  1, 0, 0xc03a, 0 },
   { NULL       , NULL       , "gsnd",               4, 0, 0xc00b, 12 }
};
static HB_PP_TOKEN s_cm036[ 27 ] = {
   { s_cm036 + 1, NULL       , "@",                  1, 1, 0xc038, 0 },
   { s_cm036 + 2, NULL       , "top",                3, 0, 0xe001, 1 },
   { s_cm036 + 3, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cm036 + 4, NULL       , "left",               4, 0, 0xe001, 2 },
   { s_cm036 + 5, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cm036 + 6, NULL       , "bottom",             6, 0, 0xe001, 7 },
   { s_cm036 + 7, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cm036 + 8, NULL       , "right",              5, 0, 0xe001, 8 },
   { s_cm036 + 9, NULL       , "GET",                3, 1, 0xc015, 0 },
   { s_cm036 +10, NULL       , "v",                  1, 0, 0xe001, 3 },
   { s_cm036 +11, NULL       , "TBROWSE",            7, 1, 0xc015, 0 },
   { s_cm036 +12, NULL       , "oBrowse",            7, 0, 0xe001, 6 },
   { s_cm036 +15, s_cm036 +13, "[",                  1, 1, 0xe007, 0 },
   { s_cm036 +14, NULL       , "VALID",              5, 0, 0xc015, 0 },
   { NULL       , NULL       , "valid",              5, 0, 0xe001, 4 },
   { s_cm036 +18, s_cm036 +16, "[",                  1, 1, 0xe007, 0 },
   { s_cm036 +17, NULL       , "WHEN",               4, 0, 0xc015, 0 },
   { NULL       , NULL       , "when",               4, 0, 0xe001, 5 },
   { s_cm036 +21, s_cm036 +19, "[",                  1, 1, 0xe007, 0 },
   { s_cm036 +20, NULL       , "MESSAGE",            7, 0, 0xc015, 0 },
   { NULL       , NULL       , "msg",                3, 0, 0xe001, 9 },
   { s_cm036 +24, s_cm036 +22, "[",                  1, 1, 0xe007, 0 },
   { s_cm036 +23, NULL       , "SEND",               4, 0, 0xc015, 0 },
   { NULL       , NULL       , "snd",                3, 0, 0xe001, 10 },
   { NULL       , s_cm036 +25, "[",                  1, 1, 0xe007, 0 },
   { s_cm036 +26, NULL       , "GUISEND",            7, 0, 0xc015, 0 },
   { NULL       , NULL       , "gsnd",               4, 0, 0xe001, 11 }
};
static HB_PP_TOKEN s_cr036[ 132 ] = {
   { s_cr036 + 1, NULL       , "SetPos",             6, 1, 0xc015, 0 },
   { s_cr036 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr036 + 3, NULL       , "top",                3, 1, 0xc00b, 1 },
   { s_cr036 + 4, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr036 + 5, NULL       , "left",               4, 1, 0xc00b, 2 },
   { s_cr036 + 6, NULL       , ")",                  1, 1, 0xc033, 0 },
   { s_cr036 + 7, NULL       , ";",                  1, 1, 0xc01e, 0 },
   { s_cr036 + 8, NULL       , "AAdd",               4, 1, 0xc015, 0 },
   { s_cr036 + 9, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr036 +10, NULL       , "GetList",            7, 1, 0xc015, 0 },
   { s_cr036 +11, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr036 +12, NULL       , "_GET_",              5, 1, 0xc015, 0 },
   { s_cr036 +13, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr036 +14, NULL       , "v",                  1, 1, 0xc00b, 3 },
   { s_cr036 +15, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr036 +16, NULL       , "v",                  1, 1, 0xc00e, 3 },
   { s_cr036 +17, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr036 +18, NULL       , "NIL",                3, 1, 0xc015, 0 },
   { s_cr036 +19, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr036 +20, NULL       , "valid",              5, 1, 0xc00f, 4 },
   { s_cr036 +21, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr036 +22, NULL       , "when",               4, 1, 0xc00f, 5 },
   { s_cr036 +23, NULL       , ")",                  1, 1, 0xc033, 0 },
   { s_cr036 +24, NULL       , ")",                  1, 1, 0xc033, 0 },
   { s_cr036 +25, NULL       , ";",                  1, 1, 0xc01e, 0 },
   { s_cr036 +26, NULL       , "oBrowse",            7, 1, 0xc00b, 6 },
   { s_cr036 +27, NULL       , ":",                  1, 0, 0xc03a, 0 },
   { s_cr036 +28, NULL       , "ntop",               4, 0, 0xc015, 0 },
   { s_cr036 +29, NULL       , ":=",                 2, 1, 0xc03c, 0 },
   { s_cr036 +30, NULL       , "ATail",              5, 1, 0xc015, 0 },
   { s_cr036 +31, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr036 +32, NULL       , "Getlist",            7, 0, 0xc015, 0 },
   { s_cr036 +33, NULL       , ")",                  1, 0, 0xc033, 0 },
   { s_cr036 +34, NULL       , ":",                  1, 0, 0xc03a, 0 },
   { s_cr036 +35, NULL       , "row",                3, 0, 0xc015, 0 },
   { s_cr036 +36, NULL       , ";",                  1, 1, 0xc01e, 0 },
   { s_cr036 +37, NULL       , "oBrowse",            7, 1, 0xc00b, 6 },
   { s_cr036 +38, NULL       , ":",                  1, 0, 0xc03a, 0 },
   { s_cr036 +39, NULL       , "nleft",              5, 0, 0xc015, 0 },
   { s_cr036 +40, NULL       , ":=",                 2, 1, 0xc03c, 0 },
   { s_cr036 +41, NULL       , "ATail",              5, 1, 0xc015, 0 },
   { s_cr036 +42, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr036 +43, NULL       , "Getlist",            7, 0, 0xc015, 0 },
   { s_cr036 +44, NULL       , ")",                  1, 0, 0xc033, 0 },
   { s_cr036 +45, NULL       , ":",                  1, 0, 0xc03a, 0 },
   { s_cr036 +46, NULL       , "col",                3, 0, 0xc015, 0 },
   { s_cr036 +47, NULL       , ";",                  1, 1, 0xc01e, 0 },
   { s_cr036 +48, NULL       , "oBrowse",            7, 1, 0xc00b, 6 },
   { s_cr036 +49, NULL       , ":",                  1, 0, 0xc03a, 0 },
   { s_cr036 +50, NULL       , "nbottom",            7, 0, 0xc015, 0 },
   { s_cr036 +51, NULL       , ":=",                 2, 1, 0xc03c, 0 },
   { s_cr036 +52, NULL       , "bottom",             6, 1, 0xc00b, 7 },
   { s_cr036 +53, NULL       , ";",                  1, 1, 0xc01e, 0 },
   { s_cr036 +54, NULL       , "oBrowse",            7, 1, 0xc00b, 6 },
   { s_cr036 +55, NULL       , ":",                  1, 0, 0xc03a, 0 },
   { s_cr036 +56, NULL       , "nright",             6, 0, 0xc015, 0 },
   { s_cr036 +57, NULL       , ":=",                 2, 1, 0xc03c, 0 },
   { s_cr036 +58, NULL       , "right",              5, 1, 0xc00b, 8 },
   { s_cr036 +59, NULL       , ";",                  1, 1, 0xc01e, 0 },
   { s_cr036 +60, NULL       , "oBrowse",            7, 1, 0xc00b, 6 },
   { s_cr036 +61, NULL       , ":",                  1, 0, 0xc03a, 0 },
   { s_cr036 +62, NULL       , "Configure",          9, 0, 0xc015, 0 },
   { s_cr036 +63, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr036 +64, NULL       , ")",                  1, 0, 0xc033, 0 },
   { s_cr036 +65, NULL       , ";",                  1, 1, 0xc01e, 0 },
   { s_cr036 +66, NULL       , "ATail",              5, 1, 0xc015, 0 },
   { s_cr036 +67, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr036 +68, NULL       , "GetList",            7, 0, 0xc015, 0 },
   { s_cr036 +69, NULL       , ")",                  1, 0, 0xc033, 0 },
   { s_cr036 +70, NULL       , ":",                  1, 0, 0xc03a, 0 },
   { s_cr036 +71, NULL       , "Control",            7, 0, 0xc015, 0 },
   { s_cr036 +72, NULL       , ":=",                 2, 1, 0xc03c, 0 },
   { s_cr036 +73, NULL       , "oBrowse",            7, 1, 0xc00b, 6 },
   { s_cr036 +74, NULL       , ";",                  1, 1, 0xc01e, 0 },
   { s_cr036 +75, NULL       , "ATail",              5, 1, 0xc015, 0 },
   { s_cr036 +76, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr036 +77, NULL       , "GetList",            7, 0, 0xc015, 0 },
   { s_cr036 +78, NULL       , ")",                  1, 0, 0xc033, 0 },
   { s_cr036 +79, NULL       , ":",                  1, 0, 0xc03a, 0 },
   { s_cr036 +80, NULL       , "reader",             6, 0, 0xc015, 0 },
   { s_cr036 +81, NULL       , ":=",                 2, 1, 0xc03c, 0 },
   { s_cr036 +82, NULL       , "{",                  1, 1, 0xc036, 0 },
   { s_cr036 +83, NULL       , "|",                  1, 1, 0xc01b, 0 },
   { s_cr036 +84, NULL       , "a",                  1, 1, 0xc015, 0 },
   { s_cr036 +85, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr036 +86, NULL       , "b",                  1, 1, 0xc015, 0 },
   { s_cr036 +87, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr036 +88, NULL       , "c",                  1, 1, 0xc015, 0 },
   { s_cr036 +89, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr036 +90, NULL       , "d",                  1, 1, 0xc015, 0 },
   { s_cr036 +91, NULL       , "|",                  1, 1, 0xc01b, 0 },
   { s_cr036 +92, NULL       , "TBReader",           8, 1, 0xc015, 0 },
   { s_cr036 +93, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr036 +94, NULL       , "a",                  1, 1, 0xc015, 0 },
   { s_cr036 +95, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr036 +96, NULL       , "b",                  1, 1, 0xc015, 0 },
   { s_cr036 +97, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr036 +98, NULL       , "c",                  1, 1, 0xc015, 0 },
   { s_cr036 +99, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr036 +100, NULL       , "d",                  1, 1, 0xc015, 0 },
   { s_cr036 +101, NULL       , ")",                  1, 1, 0xc033, 0 },
   { s_cr036 +102, NULL       , "}",                  1, 1, 0xc037, 0 },
   { s_cr036 +114, s_cr036 +103, "[",                  1, 1, 0xc012, 0 },
   { s_cr036 +104, NULL       , ";",                  1, 1, 0xc01e, 0 },
   { s_cr036 +105, NULL       , "ATail",              5, 1, 0xc015, 0 },
   { s_cr036 +106, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr036 +107, NULL       , "GetList",            7, 0, 0xc015, 0 },
   { s_cr036 +108, NULL       , ")",                  1, 0, 0xc033, 0 },
   { s_cr036 +109, NULL       , ":",                  1, 0, 0xc03a, 0 },
   { s_cr036 +110, NULL       , "Control",            7, 0, 0xc015, 0 },
   { s_cr036 +111, NULL       , ":",                  1, 0, 0xc03a, 0 },
   { s_cr036 +112, NULL       , "Message",            7, 0, 0xc015, 0 },
   { s_cr036 +113, NULL       , ":=",                 2, 1, 0xc03c, 0 },
   { NULL       , NULL       , "msg",                3, 1, 0xc00b, 9 },
   { s_cr036 +122, s_cr036 +115, "[",                  1, 1, 0xc012, 0 },
   { s_cr036 +116, NULL       , ";",                  1, 1, 0xc01e, 0 },
   { s_cr036 +117, NULL       , "ATail",              5, 1, 0xc015, 0 },
   { s_cr036 +118, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr036 +119, NULL       , "GetList",            7, 0, 0xc015, 0 },
   { s_cr036 +120, NULL       , ")",                  1, 0, 0xc033, 0 },
   { s_cr036 +121, NULL       , ":",                  1, 0, 0xc03a, 0 },
   { NULL       , NULL       , "snd",                3, 0, 0xc00b, 10 },
   { NULL       , s_cr036 +123, "[",                  1, 1, 0xc012, 0 },
   { s_cr036 +124, NULL       , ";",                  1, 1, 0xc01e, 0 },
   { s_cr036 +125, NULL       , "ATail",              5, 1, 0xc015, 0 },
   { s_cr036 +126, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr036 +127, NULL       , "GetList",            7, 0, 0xc015, 0 },
   { s_cr036 +128, NULL       , ")",                  1, 0, 0xc033, 0 },
   { s_cr036 +129, NULL       , ":",                  1, 0, 0xc03a, 0 },
   { s_cr036 +130, NULL       , "Control",            7, 0, 0xc015, 0 },
   { s_cr036 +131, NULL       , ":",                  1, 0, 0xc03a, 0 },
   { NULL       , NULL       , "gsnd",               4, 0, 0xc00b, 11 }
};
static HB_PP_TOKEN s_cm037[ 39 ] = {
   { s_cm037 + 1, NULL       , "@",                  1, 1, 0xc038, 0 },
   { s_cm037 + 2, NULL       , "top",                3, 0, 0xe001, 1 },
   { s_cm037 + 3, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cm037 + 4, NULL       , "left",               4, 0, 0xe001, 2 },
   { s_cm037 + 5, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cm037 + 6, NULL       , "bottom",             6, 0, 0xe001, 6 },
   { s_cm037 + 7, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cm037 + 8, NULL       , "right",              5, 0, 0xe001, 7 },
   { s_cm037 + 9, NULL       , "GET",                3, 1, 0xc015, 0 },
   { s_cm037 +10, NULL       , "v",                  1, 0, 0xe001, 3 },
   { s_cm037 +11, NULL       , "RADIOGROUP",        10, 1, 0xc015, 0 },
   { s_cm037 +12, NULL       , "buttons",            7, 0, 0xe001, 8 },
   { s_cm037 +15, s_cm037 +13, "[",                  1, 1, 0xe007, 0 },
   { s_cm037 +14, NULL       , "VALID",              5, 0, 0xc015, 0 },
   { NULL       , NULL       , "valid",              5, 0, 0xe001, 4 },
   { s_cm037 +18, s_cm037 +16, "[",                  1, 1, 0xe007, 0 },
   { s_cm037 +17, NULL       , "WHEN",               4, 0, 0xc015, 0 },
   { NULL       , NULL       , "when",               4, 0, 0xe001, 5 },
   { s_cm037 +21, s_cm037 +19, "[",                  1, 1, 0xe007, 0 },
   { s_cm037 +20, NULL       , "CAPTION",            7, 0, 0xc015, 0 },
   { NULL       , NULL       , "cap",                3, 0, 0xe001, 9 },
   { s_cm037 +24, s_cm037 +22, "[",                  1, 1, 0xe007, 0 },
   { s_cm037 +23, NULL       , "MESSAGE",            7, 0, 0xc015, 0 },
   { NULL       , NULL       , "msg",                3, 0, 0xe001, 10 },
   { s_cm037 +27, s_cm037 +25, "[",                  1, 1, 0xe007, 0 },
   { s_cm037 +26, NULL       , "COLOR",              5, 0, 0xc015, 0 },
   { NULL       , NULL       , "clr",                3, 0, 0xe001, 11 },
   { s_cm037 +30, s_cm037 +28, "[",                  1, 1, 0xe007, 0 },
   { s_cm037 +29, NULL       , "FOCUS",              5, 0, 0xc015, 0 },
   { NULL       , NULL       , "fb",                 2, 0, 0xe001, 12 },
   { s_cm037 +33, s_cm037 +31, "[",                  1, 1, 0xe007, 0 },
   { s_cm037 +32, NULL       , "STYLE",              5, 0, 0xc015, 0 },
   { NULL       , NULL       , "stl",                3, 0, 0xe001, 13 },
   { s_cm037 +36, s_cm037 +34, "[",                  1, 1, 0xe007, 0 },
   { s_cm037 +35, NULL       , "SEND",               4, 0, 0xc015, 0 },
   { NULL       , NULL       , "snd",                3, 0, 0xe001, 14 },
   { NULL       , s_cm037 +37, "[",                  1, 1, 0xe007, 0 },
   { s_cm037 +38, NULL       , "GUISEND",            7, 0, 0xc015, 0 },
   { NULL       , NULL       , "gsnd",               4, 0, 0xe001, 15 }
};
static HB_PP_TOKEN s_cr037[ 124 ] = {
   { s_cr037 + 1, NULL       , "SetPos",             6, 1, 0xc015, 0 },
   { s_cr037 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr037 + 3, NULL       , "top",                3, 1, 0xc00b, 1 },
   { s_cr037 + 4, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr037 + 5, NULL       , "left",               4, 1, 0xc00b, 2 },
   { s_cr037 + 6, NULL       , ")",                  1, 1, 0xc033, 0 },
   { s_cr037 + 7, NULL       , ";",                  1, 1, 0xc01e, 0 },
   { s_cr037 + 8, NULL       , "AAdd",               4, 1, 0xc015, 0 },
   { s_cr037 + 9, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr037 +10, NULL       , "GetList",            7, 1, 0xc015, 0 },
   { s_cr037 +11, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr037 +12, NULL       , "_GET_",              5, 1, 0xc015, 0 },
   { s_cr037 +13, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr037 +14, NULL       , "v",                  1, 1, 0xc00b, 3 },
   { s_cr037 +15, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr037 +16, NULL       , "v",                  1, 1, 0xc00e, 3 },
   { s_cr037 +17, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr037 +18, NULL       , "NIL",                3, 1, 0xc015, 0 },
   { s_cr037 +19, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr037 +20, NULL       , "valid",              5, 1, 0xc00f, 4 },
   { s_cr037 +21, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr037 +22, NULL       , "when",               4, 1, 0xc00f, 5 },
   { s_cr037 +23, NULL       , ")",                  1, 1, 0xc033, 0 },
   { s_cr037 +24, NULL       , ")",                  1, 1, 0xc033, 0 },
   { s_cr037 +25, NULL       , ";",                  1, 1, 0xc01e, 0 },
   { s_cr037 +26, NULL       , "ATail",              5, 1, 0xc015, 0 },
   { s_cr037 +27, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr037 +28, NULL       , "GetList",            7, 0, 0xc015, 0 },
   { s_cr037 +29, NULL       , ")",                  1, 0, 0xc033, 0 },
   { s_cr037 +30, NULL       , ":",                  1, 0, 0xc03a, 0 },
   { s_cr037 +31, NULL       , "Control",            7, 0, 0xc015, 0 },
   { s_cr037 +32, NULL       , ":=",                 2, 1, 0xc03c, 0 },
   { s_cr037 +33, NULL       , "_RadioGrp_",        10, 1, 0xc015, 0 },
   { s_cr037 +34, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr037 +35, NULL       , "ATail",              5, 1, 0xc015, 0 },
   { s_cr037 +36, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr037 +37, NULL       , "Getlist",            7, 0, 0xc015, 0 },
   { s_cr037 +38, NULL       , ")",                  1, 0, 0xc033, 0 },
   { s_cr037 +39, NULL       , ":",                  1, 0, 0xc03a, 0 },
   { s_cr037 +40, NULL       , "row",                3, 0, 0xc015, 0 },
   { s_cr037 +41, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr037 +42, NULL       , "ATail",              5, 1, 0xc015, 0 },
   { s_cr037 +43, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr037 +44, NULL       , "Getlist",            7, 0, 0xc015, 0 },
   { s_cr037 +45, NULL       , ")",                  1, 0, 0xc033, 0 },
   { s_cr037 +46, NULL       , ":",                  1, 0, 0xc03a, 0 },
   { s_cr037 +47, NULL       , "col",                3, 0, 0xc015, 0 },
   { s_cr037 +48, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr037 +49, NULL       , "bottom",             6, 1, 0xc00b, 6 },
   { s_cr037 +50, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr037 +51, NULL       , "right",              5, 1, 0xc00b, 7 },
   { s_cr037 +52, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr037 +53, NULL       , "v",                  1, 1, 0xc00b, 3 },
   { s_cr037 +54, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr037 +55, NULL       , "buttons",            7, 1, 0xc00b, 8 },
   { s_cr037 +56, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr037 +57, NULL       , "cap",                3, 1, 0xc00b, 9 },
   { s_cr037 +58, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr037 +59, NULL       , "msg",                3, 1, 0xc00b, 10 },
   { s_cr037 +60, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr037 +61, NULL       , "clr",                3, 1, 0xc00b, 11 },
   { s_cr037 +62, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr037 +63, NULL       , "fb",                 2, 1, 0xc00f, 12 },
   { s_cr037 +64, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr037 +65, NULL       , "stl",                3, 1, 0xc00b, 13 },
   { s_cr037 +66, NULL       , ")",                  1, 1, 0xc033, 0 },
   { s_cr037 +67, NULL       , ";",                  1, 1, 0xc01e, 0 },
   { s_cr037 +68, NULL       , "ATail",              5, 1, 0xc015, 0 },
   { s_cr037 +69, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr037 +70, NULL       , "GetList",            7, 0, 0xc015, 0 },
   { s_cr037 +71, NULL       , ")",                  1, 0, 0xc033, 0 },
   { s_cr037 +72, NULL       , ":",                  1, 0, 0xc03a, 0 },
   { s_cr037 +73, NULL       , "reader",             6, 0, 0xc015, 0 },
   { s_cr037 +74, NULL       , ":=",                 2, 1, 0xc03c, 0 },
   { s_cr037 +75, NULL       , "{",                  1, 1, 0xc036, 0 },
   { s_cr037 +76, NULL       , "|",                  1, 1, 0xc01b, 0 },
   { s_cr037 +77, NULL       , "a",                  1, 1, 0xc015, 0 },
   { s_cr037 +78, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr037 +79, NULL       , "b",                  1, 1, 0xc015, 0 },
   { s_cr037 +80, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr037 +81, NULL       , "c",                  1, 1, 0xc015, 0 },
   { s_cr037 +82, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr037 +83, NULL       , "d",                  1, 1, 0xc015, 0 },
   { s_cr037 +84, NULL       , "|",                  1, 1, 0xc01b, 0 },
   { s_cr037 +85, NULL       , "GuiReader",          9, 1, 0xc015, 0 },
   { s_cr037 +86, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr037 +87, NULL       , "a",                  1, 1, 0xc015, 0 },
   { s_cr037 +88, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr037 +89, NULL       , "b",                  1, 1, 0xc015, 0 },
   { s_cr037 +90, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr037 +91, NULL       , "c",                  1, 1, 0xc015, 0 },
   { s_cr037 +92, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr037 +93, NULL       , "d",                  1, 1, 0xc015, 0 },
   { s_cr037 +94, NULL       , ")",                  1, 1, 0xc033, 0 },
   { s_cr037 +95, NULL       , "}",                  1, 1, 0xc037, 0 },
   { s_cr037 +96, NULL       , ";",                  1, 1, 0xc01e, 0 },
   { s_cr037 +104, s_cr037 +97, "[",                  1, 1, 0xc012, 0 },
   { s_cr037 +98, NULL       , "ATail",              5, 1, 0xc015, 0 },
   { s_cr037 +99, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr037 +100, NULL       , "GetList",            7, 0, 0xc015, 0 },
   { s_cr037 +101, NULL       , ")",                  1, 0, 0xc033, 0 },
   { s_cr037 +102, NULL       , ":",                  1, 0, 0xc03a, 0 },
   { s_cr037 +103, NULL       , "snd",                3, 0, 0xc00b, 14 },
   { NULL       , NULL       , ";",                  1, 1, 0xc01e, 0 },
   { s_cr037 +114, s_cr037 +105, "[",                  1, 1, 0xc012, 0 },
   { s_cr037 +106, NULL       , "ATail",              5, 1, 0xc015, 0 },
   { s_cr037 +107, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr037 +108, NULL       , "GetList",            7, 0, 0xc015, 0 },
   { s_cr037 +109, NULL       , ")",                  1, 0, 0xc033, 0 },
   { s_cr037 +110, NULL       , ":",                  1, 0, 0xc03a, 0 },
   { s_cr037 +111, NULL       , "Control",            7, 0, 0xc015, 0 },
   { s_cr037 +112, NULL       , ":",                  1, 0, 0xc03a, 0 },
   { s_cr037 +113, NULL       , "gsnd",               4, 0, 0xc00b, 15 },
   { NULL       , NULL       , ";",                  1, 1, 0xc01e, 0 },
   { s_cr037 +115, NULL       , "ATail",              5, 1, 0xc015, 0 },
   { s_cr037 +116, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr037 +117, NULL       , "GetList",            7, 0, 0xc015, 0 },
   { s_cr037 +118, NULL       , ")",                  1, 0, 0xc033, 0 },
   { s_cr037 +119, NULL       , ":",                  1, 0, 0xc03a, 0 },
   { s_cr037 +120, NULL       , "Control",            7, 0, 0xc015, 0 },
   { s_cr037 +121, NULL       , ":",                  1, 0, 0xc03a, 0 },
   { s_cr037 +122, NULL       , "Display",            7, 0, 0xc015, 0 },
   { s_cr037 +123, NULL       , "(",                  1, 0, 0xc032, 0 },
   { NULL       , NULL       , ")",                  1, 0, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm038[ 58 ] = {
   { s_cm038 + 1, NULL       , "@",                  1, 1, 0xc038, 0 },
   { s_cm038 + 2, NULL       , "row",                3, 0, 0xe001, 1 },
   { s_cm038 + 3, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cm038 + 4, NULL       , "col",                3, 0, 0xe001, 2 },
   { s_cm038 + 5, NULL       , "GET",                3, 1, 0xc015, 0 },
   { s_cm038 + 6, NULL       , "v",                  1, 0, 0xe001, 3 },
   { s_cm038 + 7, NULL       , "PUSHBUTTON",        10, 1, 0xc015, 0 },
   { s_cm038 +10, s_cm038 + 8, "[",                  1, 1, 0xe007, 0 },
   { s_cm038 + 9, NULL       , "VALID",              5, 0, 0xc015, 0 },
   { NULL       , NULL       , "valid",              5, 0, 0xe001, 4 },
   { s_cm038 +13, s_cm038 +11, "[",                  1, 1, 0xe007, 0 },
   { s_cm038 +12, NULL       , "WHEN",               4, 0, 0xc015, 0 },
   { NULL       , NULL       , "when",               4, 0, 0xe001, 5 },
   { s_cm038 +16, s_cm038 +14, "[",                  1, 1, 0xe007, 0 },
   { s_cm038 +15, NULL       , "CAPTION",            7, 0, 0xc015, 0 },
   { NULL       , NULL       , "cap",                3, 0, 0xe001, 6 },
   { s_cm038 +19, s_cm038 +17, "[",                  1, 1, 0xe007, 0 },
   { s_cm038 +18, NULL       , "MESSAGE",            7, 0, 0xc015, 0 },
   { NULL       , NULL       , "msg",                3, 0, 0xe001, 7 },
   { s_cm038 +22, s_cm038 +20, "[",                  1, 1, 0xe007, 0 },
   { s_cm038 +21, NULL       , "COLOR",              5, 0, 0xc015, 0 },
   { NULL       , NULL       , "clr",                3, 0, 0xe001, 8 },
   { s_cm038 +25, s_cm038 +23, "[",                  1, 1, 0xe007, 0 },
   { s_cm038 +24, NULL       , "FOCUS",              5, 0, 0xc015, 0 },
   { NULL       , NULL       , "fb",                 2, 0, 0xe001, 9 },
   { s_cm038 +28, s_cm038 +26, "[",                  1, 1, 0xe007, 0 },
   { s_cm038 +27, NULL       , "STATE",              5, 0, 0xc015, 0 },
   { NULL       , NULL       , "sb",                 2, 0, 0xe001, 10 },
   { s_cm038 +31, s_cm038 +29, "[",                  1, 1, 0xe007, 0 },
   { s_cm038 +30, NULL       , "STYLE",              5, 0, 0xc015, 0 },
   { NULL       , NULL       , "stl",                3, 0, 0xe001, 11 },
   { s_cm038 +34, s_cm038 +32, "[",                  1, 1, 0xe007, 0 },
   { s_cm038 +33, NULL       , "SEND",               4, 0, 0xc015, 0 },
   { NULL       , NULL       , "snd",                3, 0, 0xe001, 19 },
   { s_cm038 +37, s_cm038 +35, "[",                  1, 1, 0xe007, 0 },
   { s_cm038 +36, NULL       , "GUISEND",            7, 0, 0xc015, 0 },
   { NULL       , NULL       , "gsnd",               4, 0, 0xe001, 20 },
   { s_cm038 +40, s_cm038 +38, "[",                  1, 1, 0xe007, 0 },
   { s_cm038 +39, NULL       , "BITMAP",             6, 0, 0xc015, 0 },
   { NULL       , NULL       , "bmap",               4, 0, 0xe001, 16 },
   { s_cm038 +46, s_cm038 +41, "[",                  1, 1, 0xe007, 0 },
   { s_cm038 +42, NULL       , "SIZE",               4, 0, 0xc015, 0 },
   { s_cm038 +43, NULL       , "X",                  1, 1, 0xc015, 0 },
   { s_cm038 +44, NULL       , "sX",                 2, 0, 0xe001, 12 },
   { s_cm038 +45, NULL       , "Y",                  1, 1, 0xc015, 0 },
   { NULL       , NULL       , "sY",                 2, 0, 0xe001, 13 },
   { s_cm038 +52, s_cm038 +47, "[",                  1, 1, 0xe007, 0 },
   { s_cm038 +48, NULL       , "CAPOFF",             6, 0, 0xc015, 0 },
   { s_cm038 +49, NULL       , "X",                  1, 1, 0xc015, 0 },
   { s_cm038 +50, NULL       , "cX",                 2, 0, 0xe001, 14 },
   { s_cm038 +51, NULL       , "Y",                  1, 1, 0xc015, 0 },
   { NULL       , NULL       , "cY",                 2, 0, 0xe001, 15 },
   { NULL       , s_cm038 +53, "[",                  1, 1, 0xe007, 0 },
   { s_cm038 +54, NULL       , "BMPOFF",             6, 0, 0xc015, 0 },
   { s_cm038 +55, NULL       , "X",                  1, 1, 0xc015, 0 },
   { s_cm038 +56, NULL       , "bX",                 2, 0, 0xe001, 17 },
   { s_cm038 +57, NULL       , "Y",                  1, 1, 0xc015, 0 },
   { NULL       , NULL       , "bY",                 2, 0, 0xe001, 18 }
};
static HB_PP_TOKEN s_cr038[ 118 ] = {
   { s_cr038 + 1, NULL       , "SetPos",             6, 1, 0xc015, 0 },
   { s_cr038 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr038 + 3, NULL       , "row",                3, 1, 0xc00b, 1 },
   { s_cr038 + 4, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr038 + 5, NULL       , "col",                3, 1, 0xc00b, 2 },
   { s_cr038 + 6, NULL       , ")",                  1, 1, 0xc033, 0 },
   { s_cr038 + 7, NULL       , ";",                  1, 1, 0xc01e, 0 },
   { s_cr038 + 8, NULL       , "AAdd",               4, 1, 0xc015, 0 },
   { s_cr038 + 9, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr038 +10, NULL       , "GetList",            7, 1, 0xc015, 0 },
   { s_cr038 +11, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr038 +12, NULL       , "_GET_",              5, 1, 0xc015, 0 },
   { s_cr038 +13, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr038 +14, NULL       , "v",                  1, 1, 0xc00b, 3 },
   { s_cr038 +15, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr038 +16, NULL       , "v",                  1, 1, 0xc00e, 3 },
   { s_cr038 +17, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr038 +18, NULL       , "NIL",                3, 1, 0xc015, 0 },
   { s_cr038 +19, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr038 +20, NULL       , "valid",              5, 1, 0xc00f, 4 },
   { s_cr038 +21, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr038 +22, NULL       , "when",               4, 1, 0xc00f, 5 },
   { s_cr038 +23, NULL       , ")",                  1, 1, 0xc033, 0 },
   { s_cr038 +24, NULL       , ")",                  1, 1, 0xc033, 0 },
   { s_cr038 +25, NULL       , ";",                  1, 1, 0xc01e, 0 },
   { s_cr038 +26, NULL       , "ATail",              5, 1, 0xc015, 0 },
   { s_cr038 +27, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr038 +28, NULL       , "GetList",            7, 0, 0xc015, 0 },
   { s_cr038 +29, NULL       , ")",                  1, 0, 0xc033, 0 },
   { s_cr038 +30, NULL       , ":",                  1, 0, 0xc03a, 0 },
   { s_cr038 +31, NULL       , "Control",            7, 0, 0xc015, 0 },
   { s_cr038 +32, NULL       , ":=",                 2, 1, 0xc03c, 0 },
   { s_cr038 +33, NULL       , "_PushButt_",        10, 1, 0xc015, 0 },
   { s_cr038 +34, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr038 +35, NULL       , "cap",                3, 1, 0xc00b, 6 },
   { s_cr038 +36, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr038 +37, NULL       , "msg",                3, 1, 0xc00b, 7 },
   { s_cr038 +38, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr038 +39, NULL       , "clr",                3, 1, 0xc00b, 8 },
   { s_cr038 +40, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr038 +41, NULL       , "fb",                 2, 1, 0xc00f, 9 },
   { s_cr038 +42, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr038 +43, NULL       , "sb",                 2, 1, 0xc00f, 10 },
   { s_cr038 +44, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr038 +45, NULL       , "stl",                3, 1, 0xc00b, 11 },
   { s_cr038 +46, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr038 +47, NULL       , "sX",                 2, 1, 0xc00b, 12 },
   { s_cr038 +48, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr038 +49, NULL       , "sY",                 2, 1, 0xc00b, 13 },
   { s_cr038 +50, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr038 +51, NULL       , "cX",                 2, 1, 0xc00b, 14 },
   { s_cr038 +52, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr038 +53, NULL       , "cY",                 2, 1, 0xc00b, 15 },
   { s_cr038 +54, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr038 +55, NULL       , "bmap",               4, 1, 0xc00b, 16 },
   { s_cr038 +56, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr038 +57, NULL       , "bX",                 2, 1, 0xc00b, 17 },
   { s_cr038 +58, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr038 +59, NULL       , "bY",                 2, 1, 0xc00b, 18 },
   { s_cr038 +60, NULL       , ")",                  1, 1, 0xc033, 0 },
   { s_cr038 +61, NULL       , ";",                  1, 1, 0xc01e, 0 },
   { s_cr038 +62, NULL       , "ATail",              5, 1, 0xc015, 0 },
   { s_cr038 +63, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr038 +64, NULL       , "GetList",            7, 0, 0xc015, 0 },
   { s_cr038 +65, NULL       , ")",                  1, 0, 0xc033, 0 },
   { s_cr038 +66, NULL       , ":",                  1, 0, 0xc03a, 0 },
   { s_cr038 +67, NULL       , "reader",             6, 0, 0xc015, 0 },
   { s_cr038 +68, NULL       , ":=",                 2, 1, 0xc03c, 0 },
   { s_cr038 +69, NULL       , "{",                  1, 1, 0xc036, 0 },
   { s_cr038 +70, NULL       , "|",                  1, 1, 0xc01b, 0 },
   { s_cr038 +71, NULL       , "a",                  1, 1, 0xc015, 0 },
   { s_cr038 +72, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr038 +73, NULL       , "b",                  1, 1, 0xc015, 0 },
   { s_cr038 +74, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr038 +75, NULL       , "c",                  1, 1, 0xc015, 0 },
   { s_cr038 +76, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr038 +77, NULL       , "d",                  1, 1, 0xc015, 0 },
   { s_cr038 +78, NULL       , "|",                  1, 1, 0xc01b, 0 },
   { s_cr038 +79, NULL       , "GuiReader",          9, 1, 0xc015, 0 },
   { s_cr038 +80, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr038 +81, NULL       , "a",                  1, 1, 0xc015, 0 },
   { s_cr038 +82, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr038 +83, NULL       , "b",                  1, 1, 0xc015, 0 },
   { s_cr038 +84, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr038 +85, NULL       , "c",                  1, 1, 0xc015, 0 },
   { s_cr038 +86, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr038 +87, NULL       , "d",                  1, 1, 0xc015, 0 },
   { s_cr038 +88, NULL       , ")",                  1, 1, 0xc033, 0 },
   { s_cr038 +89, NULL       , "}",                  1, 1, 0xc037, 0 },
   { s_cr038 +90, NULL       , ";",                  1, 1, 0xc01e, 0 },
   { s_cr038 +98, s_cr038 +91, "[",                  1, 1, 0xc012, 0 },
   { s_cr038 +92, NULL       , "ATail",              5, 1, 0xc015, 0 },
   { s_cr038 +93, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr038 +94, NULL       , "GetList",            7, 0, 0xc015, 0 },
   { s_cr038 +95, NULL       , ")",                  1, 0, 0xc033, 0 },
   { s_cr038 +96, NULL       , ":",                  1, 0, 0xc03a, 0 },
   { s_cr038 +97, NULL       , "snd",                3, 0, 0xc00b, 19 },
   { NULL       , NULL       , ";",                  1, 1, 0xc01e, 0 },
   { s_cr038 +108, s_cr038 +99, "[",                  1, 1, 0xc012, 0 },
   { s_cr038 +100, NULL       , "ATail",              5, 1, 0xc015, 0 },
   { s_cr038 +101, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr038 +102, NULL       , "GetList",            7, 0, 0xc015, 0 },
   { s_cr038 +103, NULL       , ")",                  1, 0, 0xc033, 0 },
   { s_cr038 +104, NULL       , ":",                  1, 0, 0xc03a, 0 },
   { s_cr038 +105, NULL       , "Control",            7, 0, 0xc015, 0 },
   { s_cr038 +106, NULL       , ":",                  1, 0, 0xc03a, 0 },
   { s_cr038 +107, NULL       , "gsnd",               4, 0, 0xc00b, 20 },
   { NULL       , NULL       , ";",                  1, 1, 0xc01e, 0 },
   { s_cr038 +109, NULL       , "ATail",              5, 1, 0xc015, 0 },
   { s_cr038 +110, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr038 +111, NULL       , "GetList",            7, 0, 0xc015, 0 },
   { s_cr038 +112, NULL       , ")",                  1, 0, 0xc033, 0 },
   { s_cr038 +113, NULL       , ":",                  1, 0, 0xc03a, 0 },
   { s_cr038 +114, NULL       , "Control",            7, 0, 0xc015, 0 },
   { s_cr038 +115, NULL       , ":",                  1, 0, 0xc03a, 0 },
   { s_cr038 +116, NULL       , "Display",            7, 0, 0xc015, 0 },
   { s_cr038 +117, NULL       , "(",                  1, 0, 0xc032, 0 },
   { NULL       , NULL       , ")",                  1, 0, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm039[ 48 ] = {
   { s_cm039 + 1, NULL       , "@",                  1, 1, 0xc038, 0 },
   { s_cm039 + 2, NULL       , "top",                3, 0, 0xe001, 1 },
   { s_cm039 + 3, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cm039 + 4, NULL       , "left",               4, 0, 0xe001, 2 },
   { s_cm039 + 5, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cm039 + 6, NULL       , "bottom",             6, 0, 0xe001, 6 },
   { s_cm039 + 7, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cm039 + 8, NULL       , "right",              5, 0, 0xe001, 7 },
   { s_cm039 + 9, NULL       , "GET",                3, 1, 0xc015, 0 },
   { s_cm039 +10, NULL       , "v",                  1, 0, 0xe001, 3 },
   { s_cm039 +11, NULL       , "LISTBOX",            7, 1, 0xc015, 0 },
   { s_cm039 +12, NULL       , "items",              5, 0, 0xe001, 8 },
   { s_cm039 +15, s_cm039 +13, "[",                  1, 1, 0xe007, 0 },
   { s_cm039 +14, NULL       , "VALID",              5, 0, 0xc015, 0 },
   { NULL       , NULL       , "valid",              5, 0, 0xe001, 4 },
   { s_cm039 +18, s_cm039 +16, "[",                  1, 1, 0xe007, 0 },
   { s_cm039 +17, NULL       , "WHEN",               4, 0, 0xc015, 0 },
   { NULL       , NULL       , "when",               4, 0, 0xe001, 5 },
   { s_cm039 +21, s_cm039 +19, "[",                  1, 1, 0xe007, 0 },
   { s_cm039 +20, NULL       , "CAPTION",            7, 0, 0xc015, 0 },
   { NULL       , NULL       , "cap",                3, 0, 0xe001, 9 },
   { s_cm039 +24, s_cm039 +22, "[",                  1, 1, 0xe007, 0 },
   { s_cm039 +23, NULL       , "MESSAGE",            7, 0, 0xc015, 0 },
   { NULL       , NULL       , "msg",                3, 0, 0xe001, 10 },
   { s_cm039 +27, s_cm039 +25, "[",                  1, 1, 0xe007, 0 },
   { s_cm039 +26, NULL       , "COLOR",              5, 0, 0xc015, 0 },
   { NULL       , NULL       , "clr",                3, 0, 0xe001, 11 },
   { s_cm039 +30, s_cm039 +28, "[",                  1, 1, 0xe007, 0 },
   { s_cm039 +29, NULL       , "FOCUS",              5, 0, 0xc015, 0 },
   { NULL       , NULL       , "fb",                 2, 0, 0xe001, 12 },
   { s_cm039 +33, s_cm039 +31, "[",                  1, 1, 0xe007, 0 },
   { s_cm039 +32, NULL       , "STATE",              5, 0, 0xc015, 0 },
   { NULL       , NULL       , "sb",                 2, 0, 0xe001, 13 },
   { s_cm039 +36, s_cm039 +34, "[",                  1, 1, 0xe007, 0 },
   { NULL       , s_cm039 +35, "dd",                 2, 0, 0xc003, 14 },
   { NULL       , NULL       , "DROPDOWN",           8, 0, 0xc015, 0 },
   { s_cm039 +39, s_cm039 +37, "[",                  1, 1, 0xe007, 0 },
   { NULL       , s_cm039 +38, "sbar",               4, 0, 0xc003, 15 },
   { NULL       , NULL       , "SCROLLBAR",          9, 0, 0xc015, 0 },
   { s_cm039 +42, s_cm039 +40, "[",                  1, 1, 0xe007, 0 },
   { s_cm039 +41, NULL       , "SEND",               4, 0, 0xc015, 0 },
   { NULL       , NULL       , "snd",                3, 0, 0xe001, 17 },
   { s_cm039 +45, s_cm039 +43, "[",                  1, 1, 0xe007, 0 },
   { s_cm039 +44, NULL       , "GUISEND",            7, 0, 0xc015, 0 },
   { NULL       , NULL       , "gsnd",               4, 0, 0xe001, 18 },
   { NULL       , s_cm039 +46, "[",                  1, 1, 0xe007, 0 },
   { s_cm039 +47, NULL       , "BITMAP",             6, 0, 0xc015, 0 },
   { NULL       , NULL       , "bmap",               4, 0, 0xe001, 16 }
};
static HB_PP_TOKEN s_cr039[ 130 ] = {
   { s_cr039 + 1, NULL       , "SetPos",             6, 1, 0xc015, 0 },
   { s_cr039 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr039 + 3, NULL       , "top",                3, 1, 0xc00b, 1 },
   { s_cr039 + 4, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr039 + 5, NULL       , "left",               4, 1, 0xc00b, 2 },
   { s_cr039 + 6, NULL       , ")",                  1, 1, 0xc033, 0 },
   { s_cr039 + 7, NULL       , ";",                  1, 1, 0xc01e, 0 },
   { s_cr039 + 8, NULL       , "AAdd",               4, 1, 0xc015, 0 },
   { s_cr039 + 9, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr039 +10, NULL       , "GetList",            7, 1, 0xc015, 0 },
   { s_cr039 +11, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr039 +12, NULL       , "_GET_",              5, 1, 0xc015, 0 },
   { s_cr039 +13, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr039 +14, NULL       , "v",                  1, 1, 0xc00b, 3 },
   { s_cr039 +15, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr039 +16, NULL       , "v",                  1, 1, 0xc00e, 3 },
   { s_cr039 +17, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr039 +18, NULL       , "NIL",                3, 1, 0xc015, 0 },
   { s_cr039 +19, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr039 +20, NULL       , "valid",              5, 1, 0xc00f, 4 },
   { s_cr039 +21, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr039 +22, NULL       , "when",               4, 1, 0xc00f, 5 },
   { s_cr039 +23, NULL       , ")",                  1, 1, 0xc033, 0 },
   { s_cr039 +24, NULL       , ")",                  1, 1, 0xc033, 0 },
   { s_cr039 +25, NULL       , ";",                  1, 1, 0xc01e, 0 },
   { s_cr039 +26, NULL       , "ATail",              5, 1, 0xc015, 0 },
   { s_cr039 +27, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr039 +28, NULL       , "GetList",            7, 0, 0xc015, 0 },
   { s_cr039 +29, NULL       , ")",                  1, 0, 0xc033, 0 },
   { s_cr039 +30, NULL       , ":",                  1, 0, 0xc03a, 0 },
   { s_cr039 +31, NULL       , "Control",            7, 0, 0xc015, 0 },
   { s_cr039 +32, NULL       , ":=",                 2, 1, 0xc03c, 0 },
   { s_cr039 +33, NULL       , "_ListBox_",          9, 1, 0xc015, 0 },
   { s_cr039 +34, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr039 +35, NULL       , "ATail",              5, 1, 0xc015, 0 },
   { s_cr039 +36, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr039 +37, NULL       , "Getlist",            7, 0, 0xc015, 0 },
   { s_cr039 +38, NULL       , ")",                  1, 0, 0xc033, 0 },
   { s_cr039 +39, NULL       , ":",                  1, 0, 0xc03a, 0 },
   { s_cr039 +40, NULL       , "row",                3, 0, 0xc015, 0 },
   { s_cr039 +41, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr039 +42, NULL       , "ATail",              5, 1, 0xc015, 0 },
   { s_cr039 +43, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr039 +44, NULL       , "Getlist",            7, 0, 0xc015, 0 },
   { s_cr039 +45, NULL       , ")",                  1, 0, 0xc033, 0 },
   { s_cr039 +46, NULL       , ":",                  1, 0, 0xc03a, 0 },
   { s_cr039 +47, NULL       , "col",                3, 0, 0xc015, 0 },
   { s_cr039 +48, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr039 +49, NULL       , "bottom",             6, 1, 0xc00b, 6 },
   { s_cr039 +50, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr039 +51, NULL       , "right",              5, 1, 0xc00b, 7 },
   { s_cr039 +52, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr039 +53, NULL       , "v",                  1, 1, 0xc00b, 3 },
   { s_cr039 +54, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr039 +55, NULL       , "items",              5, 1, 0xc00b, 8 },
   { s_cr039 +56, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr039 +57, NULL       , "cap",                3, 1, 0xc00b, 9 },
   { s_cr039 +58, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr039 +59, NULL       , "msg",                3, 1, 0xc00b, 10 },
   { s_cr039 +60, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr039 +61, NULL       , "clr",                3, 1, 0xc00b, 11 },
   { s_cr039 +62, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr039 +63, NULL       , "fb",                 2, 1, 0xc00f, 12 },
   { s_cr039 +64, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr039 +65, NULL       , "sb",                 2, 1, 0xc00f, 13 },
   { s_cr039 +66, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr039 +67, NULL       , "dd",                 2, 1, 0xc010, 14 },
   { s_cr039 +68, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr039 +69, NULL       , "sbar",               4, 1, 0xc010, 15 },
   { s_cr039 +70, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr039 +71, NULL       , "bmap",               4, 1, 0xc00b, 16 },
   { s_cr039 +72, NULL       , ")",                  1, 1, 0xc033, 0 },
   { s_cr039 +73, NULL       , ";",                  1, 1, 0xc01e, 0 },
   { s_cr039 +74, NULL       , "ATail",              5, 1, 0xc015, 0 },
   { s_cr039 +75, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr039 +76, NULL       , "GetList",            7, 0, 0xc015, 0 },
   { s_cr039 +77, NULL       , ")",                  1, 0, 0xc033, 0 },
   { s_cr039 +78, NULL       , ":",                  1, 0, 0xc03a, 0 },
   { s_cr039 +79, NULL       , "reader",             6, 0, 0xc015, 0 },
   { s_cr039 +80, NULL       , ":=",                 2, 1, 0xc03c, 0 },
   { s_cr039 +81, NULL       , "{",                  1, 1, 0xc036, 0 },
   { s_cr039 +82, NULL       , "|",                  1, 1, 0xc01b, 0 },
   { s_cr039 +83, NULL       , "a",                  1, 1, 0xc015, 0 },
   { s_cr039 +84, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr039 +85, NULL       , "b",                  1, 1, 0xc015, 0 },
   { s_cr039 +86, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr039 +87, NULL       , "c",                  1, 1, 0xc015, 0 },
   { s_cr039 +88, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr039 +89, NULL       , "d",                  1, 1, 0xc015, 0 },
   { s_cr039 +90, NULL       , "|",                  1, 1, 0xc01b, 0 },
   { s_cr039 +91, NULL       , "GuiReader",          9, 1, 0xc015, 0 },
   { s_cr039 +92, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr039 +93, NULL       , "a",                  1, 1, 0xc015, 0 },
   { s_cr039 +94, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr039 +95, NULL       , "b",                  1, 1, 0xc015, 0 },
   { s_cr039 +96, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr039 +97, NULL       , "c",                  1, 1, 0xc015, 0 },
   { s_cr039 +98, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr039 +99, NULL       , "d",                  1, 1, 0xc015, 0 },
   { s_cr039 +100, NULL       , ")",                  1, 1, 0xc033, 0 },
   { s_cr039 +101, NULL       , "}",                  1, 1, 0xc037, 0 },
   { s_cr039 +102, NULL       , ";",                  1, 1, 0xc01e, 0 },
   { s_cr039 +110, s_cr039 +103, "[",                  1, 1, 0xc012, 0 },
   { s_cr039 +104, NULL       , "ATail",              5, 1, 0xc015, 0 },
   { s_cr039 +105, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr039 +106, NULL       , "GetList",            7, 0, 0xc015, 0 },
   { s_cr039 +107, NULL       , ")",                  1, 0, 0xc033, 0 },
   { s_cr039 +108, NULL       , ":",                  1, 0, 0xc03a, 0 },
   { s_cr039 +109, NULL       , "snd",                3, 0, 0xc00b, 17 },
   { NULL       , NULL       , ";",                  1, 1, 0xc01e, 0 },
   { s_cr039 +120, s_cr039 +111, "[",                  1, 1, 0xc012, 0 },
   { s_cr039 +112, NULL       , "ATail",              5, 1, 0xc015, 0 },
   { s_cr039 +113, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr039 +114, NULL       , "GetList",            7, 0, 0xc015, 0 },
   { s_cr039 +115, NULL       , ")",                  1, 0, 0xc033, 0 },
   { s_cr039 +116, NULL       , ":",                  1, 0, 0xc03a, 0 },
   { s_cr039 +117, NULL       , "Control",            7, 0, 0xc015, 0 },
   { s_cr039 +118, NULL       , ":",                  1, 0, 0xc03a, 0 },
   { s_cr039 +119, NULL       , "gsnd",               4, 0, 0xc00b, 18 },
   { NULL       , NULL       , ";",                  1, 1, 0xc01e, 0 },
   { s_cr039 +121, NULL       , "ATail",              5, 1, 0xc015, 0 },
   { s_cr039 +122, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr039 +123, NULL       , "GetList",            7, 0, 0xc015, 0 },
   { s_cr039 +124, NULL       , ")",                  1, 0, 0xc033, 0 },
   { s_cr039 +125, NULL       , ":",                  1, 0, 0xc03a, 0 },
   { s_cr039 +126, NULL       , "Control",            7, 0, 0xc015, 0 },
   { s_cr039 +127, NULL       , ":",                  1, 0, 0xc03a, 0 },
   { s_cr039 +128, NULL       , "Display",            7, 0, 0xc015, 0 },
   { s_cr039 +129, NULL       , "(",                  1, 0, 0xc032, 0 },
   { NULL       , NULL       , ")",                  1, 0, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm040[ 40 ] = {
   { s_cm040 + 1, NULL       , "@",                  1, 1, 0xc038, 0 },
   { s_cm040 + 2, NULL       , "row",                3, 0, 0xe001, 1 },
   { s_cm040 + 3, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cm040 + 4, NULL       , "col",                3, 0, 0xe001, 2 },
   { s_cm040 + 5, NULL       , "GET",                3, 1, 0xc015, 0 },
   { s_cm040 + 6, NULL       , "v",                  1, 0, 0xe001, 3 },
   { s_cm040 + 7, NULL       , "CHECKBOX",           8, 1, 0xc015, 0 },
   { s_cm040 +10, s_cm040 + 8, "[",                  1, 1, 0xe007, 0 },
   { s_cm040 + 9, NULL       , "VALID",              5, 0, 0xc015, 0 },
   { NULL       , NULL       , "valid",              5, 0, 0xe001, 4 },
   { s_cm040 +13, s_cm040 +11, "[",                  1, 1, 0xe007, 0 },
   { s_cm040 +12, NULL       , "WHEN",               4, 0, 0xc015, 0 },
   { NULL       , NULL       , "when",               4, 0, 0xe001, 5 },
   { s_cm040 +16, s_cm040 +14, "[",                  1, 1, 0xe007, 0 },
   { s_cm040 +15, NULL       , "CAPTION",            7, 0, 0xc015, 0 },
   { NULL       , NULL       , "cap",                3, 0, 0xe001, 6 },
   { s_cm040 +19, s_cm040 +17, "[",                  1, 1, 0xe007, 0 },
   { s_cm040 +18, NULL       , "MESSAGE",            7, 0, 0xc015, 0 },
   { NULL       , NULL       , "msg",                3, 0, 0xe001, 7 },
   { s_cm040 +22, s_cm040 +20, "[",                  1, 1, 0xe007, 0 },
   { s_cm040 +21, NULL       , "COLOR",              5, 0, 0xc015, 0 },
   { NULL       , NULL       , "clr",                3, 0, 0xe001, 8 },
   { s_cm040 +25, s_cm040 +23, "[",                  1, 1, 0xe007, 0 },
   { s_cm040 +24, NULL       , "FOCUS",              5, 0, 0xc015, 0 },
   { NULL       , NULL       , "fb",                 2, 0, 0xe001, 9 },
   { s_cm040 +28, s_cm040 +26, "[",                  1, 1, 0xe007, 0 },
   { s_cm040 +27, NULL       , "STATE",              5, 0, 0xc015, 0 },
   { NULL       , NULL       , "sb",                 2, 0, 0xe001, 10 },
   { s_cm040 +31, s_cm040 +29, "[",                  1, 1, 0xe007, 0 },
   { s_cm040 +30, NULL       , "STYLE",              5, 0, 0xc015, 0 },
   { NULL       , NULL       , "stl",                3, 0, 0xe001, 11 },
   { s_cm040 +34, s_cm040 +32, "[",                  1, 1, 0xe007, 0 },
   { s_cm040 +33, NULL       , "SEND",               4, 0, 0xc015, 0 },
   { NULL       , NULL       , "snd",                3, 0, 0xe001, 13 },
   { s_cm040 +37, s_cm040 +35, "[",                  1, 1, 0xe007, 0 },
   { s_cm040 +36, NULL       , "GUISEND",            7, 0, 0xc015, 0 },
   { NULL       , NULL       , "gsnd",               4, 0, 0xe001, 14 },
   { NULL       , s_cm040 +38, "[",                  1, 1, 0xe007, 0 },
   { s_cm040 +39, NULL       , "BITMAPS",            7, 0, 0xc015, 0 },
   { NULL       , NULL       , "bmaps",              5, 0, 0xe001, 12 }
};
static HB_PP_TOKEN s_cr040[ 108 ] = {
   { s_cr040 + 1, NULL       , "SetPos",             6, 1, 0xc015, 0 },
   { s_cr040 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr040 + 3, NULL       , "row",                3, 1, 0xc00b, 1 },
   { s_cr040 + 4, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr040 + 5, NULL       , "col",                3, 1, 0xc00b, 2 },
   { s_cr040 + 6, NULL       , ")",                  1, 1, 0xc033, 0 },
   { s_cr040 + 7, NULL       , ";",                  1, 1, 0xc01e, 0 },
   { s_cr040 + 8, NULL       , "AAdd",               4, 1, 0xc015, 0 },
   { s_cr040 + 9, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr040 +10, NULL       , "GetList",            7, 1, 0xc015, 0 },
   { s_cr040 +11, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr040 +12, NULL       , "_GET_",              5, 1, 0xc015, 0 },
   { s_cr040 +13, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr040 +14, NULL       , "v",                  1, 1, 0xc00b, 3 },
   { s_cr040 +15, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr040 +16, NULL       , "v",                  1, 1, 0xc00e, 3 },
   { s_cr040 +17, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr040 +18, NULL       , "NIL",                3, 1, 0xc015, 0 },
   { s_cr040 +19, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr040 +20, NULL       , "valid",              5, 1, 0xc00f, 4 },
   { s_cr040 +21, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr040 +22, NULL       , "when",               4, 1, 0xc00f, 5 },
   { s_cr040 +23, NULL       , ")",                  1, 1, 0xc033, 0 },
   { s_cr040 +24, NULL       , ")",                  1, 1, 0xc033, 0 },
   { s_cr040 +25, NULL       , ";",                  1, 1, 0xc01e, 0 },
   { s_cr040 +26, NULL       , "ATail",              5, 1, 0xc015, 0 },
   { s_cr040 +27, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr040 +28, NULL       , "GetList",            7, 0, 0xc015, 0 },
   { s_cr040 +29, NULL       , ")",                  1, 0, 0xc033, 0 },
   { s_cr040 +30, NULL       , ":",                  1, 0, 0xc03a, 0 },
   { s_cr040 +31, NULL       , "Control",            7, 0, 0xc015, 0 },
   { s_cr040 +32, NULL       , ":=",                 2, 1, 0xc03c, 0 },
   { s_cr040 +33, NULL       , "_CheckBox_",        10, 1, 0xc015, 0 },
   { s_cr040 +34, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr040 +35, NULL       , "v",                  1, 1, 0xc00b, 3 },
   { s_cr040 +36, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr040 +37, NULL       , "cap",                3, 1, 0xc00b, 6 },
   { s_cr040 +38, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr040 +39, NULL       , "msg",                3, 1, 0xc00b, 7 },
   { s_cr040 +40, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr040 +41, NULL       , "clr",                3, 1, 0xc00b, 8 },
   { s_cr040 +42, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr040 +43, NULL       , "fb",                 2, 1, 0xc00f, 9 },
   { s_cr040 +44, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr040 +45, NULL       , "sb",                 2, 1, 0xc00f, 10 },
   { s_cr040 +46, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr040 +47, NULL       , "stl",                3, 1, 0xc00b, 11 },
   { s_cr040 +48, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr040 +49, NULL       , "bmaps",              5, 1, 0xc00b, 12 },
   { s_cr040 +50, NULL       , ")",                  1, 1, 0xc033, 0 },
   { s_cr040 +51, NULL       , ";",                  1, 1, 0xc01e, 0 },
   { s_cr040 +52, NULL       , "ATail",              5, 1, 0xc015, 0 },
   { s_cr040 +53, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr040 +54, NULL       , "GetList",            7, 0, 0xc015, 0 },
   { s_cr040 +55, NULL       , ")",                  1, 0, 0xc033, 0 },
   { s_cr040 +56, NULL       , ":",                  1, 0, 0xc03a, 0 },
   { s_cr040 +57, NULL       , "reader",             6, 0, 0xc015, 0 },
   { s_cr040 +58, NULL       , ":=",                 2, 1, 0xc03c, 0 },
   { s_cr040 +59, NULL       , "{",                  1, 1, 0xc036, 0 },
   { s_cr040 +60, NULL       , "|",                  1, 1, 0xc01b, 0 },
   { s_cr040 +61, NULL       , "a",                  1, 1, 0xc015, 0 },
   { s_cr040 +62, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr040 +63, NULL       , "b",                  1, 1, 0xc015, 0 },
   { s_cr040 +64, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr040 +65, NULL       , "c",                  1, 1, 0xc015, 0 },
   { s_cr040 +66, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr040 +67, NULL       , "d",                  1, 1, 0xc015, 0 },
   { s_cr040 +68, NULL       , "|",                  1, 1, 0xc01b, 0 },
   { s_cr040 +69, NULL       , "GuiReader",          9, 1, 0xc015, 0 },
   { s_cr040 +70, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr040 +71, NULL       , "a",                  1, 1, 0xc015, 0 },
   { s_cr040 +72, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr040 +73, NULL       , "b",                  1, 1, 0xc015, 0 },
   { s_cr040 +74, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr040 +75, NULL       , "c",                  1, 1, 0xc015, 0 },
   { s_cr040 +76, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr040 +77, NULL       , "d",                  1, 1, 0xc015, 0 },
   { s_cr040 +78, NULL       , ")",                  1, 1, 0xc033, 0 },
   { s_cr040 +79, NULL       , "}",                  1, 1, 0xc037, 0 },
   { s_cr040 +80, NULL       , ";",                  1, 1, 0xc01e, 0 },
   { s_cr040 +88, s_cr040 +81, "[",                  1, 1, 0xc012, 0 },
   { s_cr040 +82, NULL       , "ATail",              5, 1, 0xc015, 0 },
   { s_cr040 +83, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr040 +84, NULL       , "GetList",            7, 0, 0xc015, 0 },
   { s_cr040 +85, NULL       , ")",                  1, 0, 0xc033, 0 },
   { s_cr040 +86, NULL       , ":",                  1, 0, 0xc03a, 0 },
   { s_cr040 +87, NULL       , "snd",                3, 0, 0xc00b, 13 },
   { NULL       , NULL       , ";",                  1, 1, 0xc01e, 0 },
   { s_cr040 +98, s_cr040 +89, "[",                  1, 1, 0xc012, 0 },
   { s_cr040 +90, NULL       , "ATail",              5, 1, 0xc015, 0 },
   { s_cr040 +91, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr040 +92, NULL       , "GetList",            7, 0, 0xc015, 0 },
   { s_cr040 +93, NULL       , ")",                  1, 0, 0xc033, 0 },
   { s_cr040 +94, NULL       , ":",                  1, 0, 0xc03a, 0 },
   { s_cr040 +95, NULL       , "Control",            7, 0, 0xc015, 0 },
   { s_cr040 +96, NULL       , ":",                  1, 0, 0xc03a, 0 },
   { s_cr040 +97, NULL       , "gsnd",               4, 0, 0xc00b, 14 },
   { NULL       , NULL       , ";",                  1, 1, 0xc01e, 0 },
   { s_cr040 +99, NULL       , "ATail",              5, 1, 0xc015, 0 },
   { s_cr040 +100, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr040 +101, NULL       , "GetList",            7, 0, 0xc015, 0 },
   { s_cr040 +102, NULL       , ")",                  1, 0, 0xc033, 0 },
   { s_cr040 +103, NULL       , ":",                  1, 0, 0xc03a, 0 },
   { s_cr040 +104, NULL       , "Control",            7, 0, 0xc015, 0 },
   { s_cr040 +105, NULL       , ":",                  1, 0, 0xc03a, 0 },
   { s_cr040 +106, NULL       , "Display",            7, 0, 0xc015, 0 },
   { s_cr040 +107, NULL       , "(",                  1, 0, 0xc032, 0 },
   { NULL       , NULL       , ")",                  1, 0, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm041[ 24 ] = {
   { s_cm041 + 1, NULL       , "@",                  1, 1, 0xc038, 0 },
   { s_cm041 + 2, NULL       , "row",                3, 0, 0xe001, 1 },
   { s_cm041 + 3, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cm041 + 4, NULL       , "col",                3, 0, 0xe001, 2 },
   { s_cm041 + 5, NULL       , "GET",                3, 1, 0xc015, 0 },
   { s_cm041 + 6, NULL       , "v",                  1, 0, 0xe001, 3 },
   { s_cm041 + 9, s_cm041 + 7, "[",                  1, 1, 0xe007, 0 },
   { s_cm041 + 8, NULL       , "PICTURE",            7, 0, 0xc015, 0 },
   { NULL       , NULL       , "pic",                3, 0, 0xe001, 4 },
   { s_cm041 +12, s_cm041 +10, "[",                  1, 1, 0xe007, 0 },
   { s_cm041 +11, NULL       , "VALID",              5, 0, 0xc015, 0 },
   { NULL       , NULL       , "valid",              5, 0, 0xe001, 5 },
   { s_cm041 +15, s_cm041 +13, "[",                  1, 1, 0xe007, 0 },
   { s_cm041 +14, NULL       , "WHEN",               4, 0, 0xc015, 0 },
   { NULL       , NULL       , "when",               4, 0, 0xe001, 6 },
   { s_cm041 +18, s_cm041 +16, "[",                  1, 1, 0xe007, 0 },
   { s_cm041 +17, NULL       , "SEND",               4, 0, 0xc015, 0 },
   { NULL       , NULL       , "snd",                3, 0, 0xe001, 9 },
   { s_cm041 +21, s_cm041 +19, "[",                  1, 1, 0xe007, 0 },
   { s_cm041 +20, NULL       , "CAPTION",            7, 0, 0xc015, 0 },
   { NULL       , NULL       , "cap",                3, 0, 0xe001, 7 },
   { NULL       , s_cm041 +22, "[",                  1, 1, 0xe007, 0 },
   { s_cm041 +23, NULL       , "MESSAGE",            7, 0, 0xc015, 0 },
   { NULL       , NULL       , "msg",                3, 0, 0xe001, 8 }
};
static HB_PP_TOKEN s_cr041[ 96 ] = {
   { s_cr041 + 1, NULL       , "SetPos",             6, 1, 0xc015, 0 },
   { s_cr041 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr041 + 3, NULL       , "row",                3, 1, 0xc00b, 1 },
   { s_cr041 + 4, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr041 + 5, NULL       , "col",                3, 1, 0xc00b, 2 },
   { s_cr041 + 6, NULL       , ")",                  1, 1, 0xc033, 0 },
   { s_cr041 + 7, NULL       , ";",                  1, 1, 0xc01e, 0 },
   { s_cr041 + 8, NULL       , "AAdd",               4, 1, 0xc015, 0 },
   { s_cr041 + 9, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr041 +10, NULL       , "GetList",            7, 1, 0xc015, 0 },
   { s_cr041 +11, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr041 +12, NULL       , "_GET_",              5, 1, 0xc015, 0 },
   { s_cr041 +13, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr041 +14, NULL       , "v",                  1, 1, 0xc00b, 3 },
   { s_cr041 +15, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr041 +16, NULL       , "v",                  1, 1, 0xc00d, 3 },
   { s_cr041 +17, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr041 +18, NULL       , "pic",                3, 1, 0xc00b, 4 },
   { s_cr041 +19, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr041 +20, NULL       , "valid",              5, 1, 0xc00f, 5 },
   { s_cr041 +21, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr041 +22, NULL       , "when",               4, 1, 0xc00f, 6 },
   { s_cr041 +23, NULL       , ")",                  1, 1, 0xc033, 0 },
   { s_cr041 +24, NULL       , ")",                  1, 1, 0xc033, 0 },
   { s_cr041 +25, NULL       , ";",                  1, 1, 0xc01e, 0 },
   { s_cr041 +70, s_cr041 +26, "[",                  1, 1, 0xc012, 0 },
   { s_cr041 +27, NULL       , "ATail",              5, 1, 0xc015, 0 },
   { s_cr041 +28, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr041 +29, NULL       , "GetList",            7, 0, 0xc015, 0 },
   { s_cr041 +30, NULL       , ")",                  1, 0, 0xc033, 0 },
   { s_cr041 +31, NULL       , ":",                  1, 0, 0xc03a, 0 },
   { s_cr041 +32, NULL       , "Caption",            7, 0, 0xc015, 0 },
   { s_cr041 +33, NULL       , ":=",                 2, 1, 0xc03c, 0 },
   { s_cr041 +34, NULL       , "cap",                3, 1, 0xc00b, 7 },
   { s_cr041 +35, NULL       , ";",                  1, 1, 0xc01e, 0 },
   { s_cr041 +36, NULL       , "ATail",              5, 1, 0xc015, 0 },
   { s_cr041 +37, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr041 +38, NULL       , "GetList",            7, 0, 0xc015, 0 },
   { s_cr041 +39, NULL       , ")",                  1, 0, 0xc033, 0 },
   { s_cr041 +40, NULL       , ":",                  1, 0, 0xc03a, 0 },
   { s_cr041 +41, NULL       , "CapRow",             6, 0, 0xc015, 0 },
   { s_cr041 +42, NULL       , ":=",                 2, 1, 0xc03c, 0 },
   { s_cr041 +43, NULL       , "ATail",              5, 1, 0xc015, 0 },
   { s_cr041 +44, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr041 +45, NULL       , "Getlist",            7, 0, 0xc015, 0 },
   { s_cr041 +46, NULL       , ")",                  1, 0, 0xc033, 0 },
   { s_cr041 +47, NULL       , ":",                  1, 0, 0xc03a, 0 },
   { s_cr041 +48, NULL       , "row",                3, 0, 0xc015, 0 },
   { s_cr041 +49, NULL       , ";",                  1, 1, 0xc01e, 0 },
   { s_cr041 +50, NULL       , "ATail",              5, 1, 0xc015, 0 },
   { s_cr041 +51, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr041 +52, NULL       , "GetList",            7, 0, 0xc015, 0 },
   { s_cr041 +53, NULL       , ")",                  1, 0, 0xc033, 0 },
   { s_cr041 +54, NULL       , ":",                  1, 0, 0xc03a, 0 },
   { s_cr041 +55, NULL       , "CapCol",             6, 0, 0xc015, 0 },
   { s_cr041 +56, NULL       , ":=",                 2, 1, 0xc03c, 0 },
   { s_cr041 +57, NULL       , "ATail",              5, 1, 0xc015, 0 },
   { s_cr041 +58, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr041 +59, NULL       , "Getlist",            7, 0, 0xc015, 0 },
   { s_cr041 +60, NULL       , ")",                  1, 0, 0xc033, 0 },
   { s_cr041 +61, NULL       , ":",                  1, 0, 0xc03a, 0 },
   { s_cr041 +62, NULL       , "col",                3, 0, 0xc015, 0 },
   { s_cr041 +63, NULL       , "-",                  1, 1, 0xc051, 0 },
   { s_cr041 +64, NULL       , "__CapLength",       11, 1, 0xc015, 0 },
   { s_cr041 +65, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr041 +66, NULL       , "cap",                3, 0, 0xc00b, 7 },
   { s_cr041 +67, NULL       , ")",                  1, 0, 0xc033, 0 },
   { s_cr041 +68, NULL       , "-",                  1, 1, 0xc051, 0 },
   { s_cr041 +69, NULL       , "1",                  1, 1, 0xc02a, 0 },
   { NULL       , NULL       , ";",                  1, 1, 0xc01e, 0 },
   { s_cr041 +80, s_cr041 +71, "[",                  1, 1, 0xc012, 0 },
   { s_cr041 +72, NULL       , "ATail",              5, 1, 0xc015, 0 },
   { s_cr041 +73, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr041 +74, NULL       , "GetList",            7, 0, 0xc015, 0 },
   { s_cr041 +75, NULL       , ")",                  1, 0, 0xc033, 0 },
   { s_cr041 +76, NULL       , ":",                  1, 0, 0xc03a, 0 },
   { s_cr041 +77, NULL       , "message",            7, 0, 0xc015, 0 },
   { s_cr041 +78, NULL       , ":=",                 2, 1, 0xc03c, 0 },
   { s_cr041 +79, NULL       , "msg",                3, 1, 0xc00b, 8 },
   { NULL       , NULL       , ";",                  1, 1, 0xc01e, 0 },
   { s_cr041 +88, s_cr041 +81, "[",                  1, 1, 0xc012, 0 },
   { s_cr041 +82, NULL       , "ATail",              5, 1, 0xc015, 0 },
   { s_cr041 +83, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr041 +84, NULL       , "GetList",            7, 0, 0xc015, 0 },
   { s_cr041 +85, NULL       , ")",                  1, 0, 0xc033, 0 },
   { s_cr041 +86, NULL       , ":",                  1, 0, 0xc03a, 0 },
   { s_cr041 +87, NULL       , "snd",                3, 0, 0xc00b, 9 },
   { NULL       , NULL       , ";",                  1, 1, 0xc01e, 0 },
   { s_cr041 +89, NULL       , "ATail",              5, 1, 0xc015, 0 },
   { s_cr041 +90, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr041 +91, NULL       , "GetList",            7, 0, 0xc015, 0 },
   { s_cr041 +92, NULL       , ")",                  1, 0, 0xc033, 0 },
   { s_cr041 +93, NULL       , ":",                  1, 0, 0xc03a, 0 },
   { s_cr041 +94, NULL       , "Display",            7, 0, 0xc015, 0 },
   { s_cr041 +95, NULL       , "(",                  1, 0, 0xc032, 0 },
   { NULL       , NULL       , ")",                  1, 0, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm042[ 17 ] = {
   { s_cm042 + 1, NULL       , "READ",               4, 1, 0xc015, 0 },
   { s_cm042 + 2, NULL       , "SAVE",               4, 1, 0xc015, 0 },
   { s_cm042 + 5, s_cm042 + 3, "[",                  1, 1, 0xe007, 0 },
   { s_cm042 + 4, NULL       , "MENU",               4, 0, 0xc015, 0 },
   { NULL       , NULL       , "oMenu",              5, 0, 0xe001, 1 },
   { NULL       , s_cm042 + 6, "[",                  1, 1, 0xe007, 0 },
   { s_cm042 + 7, NULL       , "MSG",                3, 0, 0xc015, 0 },
   { s_cm042 + 8, NULL       , "AT",                 2, 1, 0xc015, 0 },
   { s_cm042 + 9, NULL       , "row",                3, 0, 0xe001, 2 },
   { s_cm042 +10, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cm042 +11, NULL       , "left",               4, 0, 0xe001, 3 },
   { s_cm042 +12, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cm042 +13, NULL       , "right",              5, 0, 0xe001, 4 },
   { NULL       , s_cm042 +14, "[",                  1, 1, 0xe007, 0 },
   { s_cm042 +15, NULL       , "MSG",                3, 0, 0xc015, 0 },
   { s_cm042 +16, NULL       , "COLOR",              5, 1, 0xc015, 0 },
   { NULL       , NULL       , "color",              5, 0, 0xe001, 5 }
};
static HB_PP_TOKEN s_cr042[ 16 ] = {
   { s_cr042 + 1, NULL       , "ReadModal",          9, 1, 0xc015, 0 },
   { s_cr042 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr042 + 3, NULL       , "GetList",            7, 1, 0xc015, 0 },
   { s_cr042 + 4, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr042 + 5, NULL       , "NIL",                3, 1, 0xc015, 0 },
   { s_cr042 + 6, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr042 + 7, NULL       , "oMenu",              5, 1, 0xc00b, 1 },
   { s_cr042 + 8, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr042 + 9, NULL       , "row",                3, 1, 0xc00b, 2 },
   { s_cr042 +10, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr042 +11, NULL       , "left",               4, 1, 0xc00b, 3 },
   { s_cr042 +12, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr042 +13, NULL       , "right",              5, 1, 0xc00b, 4 },
   { s_cr042 +14, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr042 +15, NULL       , "color",              5, 1, 0xc00b, 5 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm043[ 16 ] = {
   { s_cm043 + 1, NULL       , "READ",               4, 1, 0xc015, 0 },
   { s_cm043 + 4, s_cm043 + 2, "[",                  1, 1, 0xe007, 0 },
   { s_cm043 + 3, NULL       , "MENU",               4, 0, 0xc015, 0 },
   { NULL       , NULL       , "oMenu",              5, 0, 0xe001, 1 },
   { NULL       , s_cm043 + 5, "[",                  1, 1, 0xe007, 0 },
   { s_cm043 + 6, NULL       , "MSG",                3, 0, 0xc015, 0 },
   { s_cm043 + 7, NULL       , "AT",                 2, 1, 0xc015, 0 },
   { s_cm043 + 8, NULL       , "row",                3, 0, 0xe001, 2 },
   { s_cm043 + 9, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cm043 +10, NULL       , "left",               4, 0, 0xe001, 3 },
   { s_cm043 +11, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cm043 +12, NULL       , "right",              5, 0, 0xe001, 4 },
   { NULL       , s_cm043 +13, "[",                  1, 1, 0xe007, 0 },
   { s_cm043 +14, NULL       , "MSG",                3, 0, 0xc015, 0 },
   { s_cm043 +15, NULL       , "COLOR",              5, 1, 0xc015, 0 },
   { NULL       , NULL       , "color",              5, 0, 0xe001, 5 }
};
static HB_PP_TOKEN s_cr043[ 25 ] = {
   { s_cr043 + 1, NULL       , "ReadModal",          9, 1, 0xc015, 0 },
   { s_cr043 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr043 + 3, NULL       , "GetList",            7, 1, 0xc015, 0 },
   { s_cr043 + 4, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr043 + 5, NULL       , "NIL",                3, 1, 0xc015, 0 },
   { s_cr043 + 6, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr043 + 7, NULL       , "oMenu",              5, 1, 0xc00b, 1 },
   { s_cr043 + 8, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr043 + 9, NULL       , "row",                3, 1, 0xc00b, 2 },
   { s_cr043 +10, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr043 +11, NULL       , "left",               4, 1, 0xc00b, 3 },
   { s_cr043 +12, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr043 +13, NULL       , "right",              5, 1, 0xc00b, 4 },
   { s_cr043 +14, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr043 +15, NULL       , "color",              5, 1, 0xc00b, 5 },
   { s_cr043 +16, NULL       , ")",                  1, 1, 0xc033, 0 },
   { s_cr043 +17, NULL       , ";",                  1, 1, 0xc01e, 0 },
   { s_cr043 +18, NULL       , "GetList",            7, 1, 0xc015, 0 },
   { s_cr043 +19, NULL       , ":=",                 2, 1, 0xc03c, 0 },
   { s_cr043 +20, NULL       , "{",                  1, 1, 0xc036, 0 },
   { s_cr043 +21, NULL       , "}",                  1, 0, 0xc037, 0 },
   { s_cr043 +22, NULL       , ";",                  1, 1, 0xc01e, 0 },
   { s_cr043 +23, NULL       , "(",                  1, 1, 0xc032, 0 },
   { s_cr043 +24, NULL       , "GetList",            7, 1, 0xc015, 0 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm044[ 12 ] = {
   { s_cm044 + 1, NULL       , "@",                  1, 1, 0xc038, 0 },
   { s_cm044 + 2, NULL       , "row",                3, 0, 0xe001, 1 },
   { s_cm044 + 3, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cm044 + 4, NULL       , "col",                3, 0, 0xe001, 2 },
   { s_cm044 + 5, NULL       , "GET",                3, 1, 0xc015, 0 },
   { s_cm044 + 6, NULL       , "v",                  1, 0, 0xe001, 3 },
   { s_cm044 + 8, s_cm044 + 7, "[",                  1, 1, 0xe007, 0 },
   { NULL       , NULL       , "exp",                3, 0, 0xe002, 4 },
   { s_cm044 + 9, NULL       , "COLOR",              5, 1, 0xc015, 0 },
   { s_cm044 +10, NULL       , "clr",                3, 0, 0xe001, 5 },
   { NULL       , s_cm044 +11, "[",                  1, 1, 0xe007, 0 },
   { NULL       , NULL       , "nextexp",            7, 0, 0xe002, 6 }
};
static HB_PP_TOKEN s_cr044[ 15 ] = {
   { s_cr044 + 1, NULL       , "@",                  1, 1, 0xc038, 0 },
   { s_cr044 + 2, NULL       , "row",                3, 1, 0xc00b, 1 },
   { s_cr044 + 3, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr044 + 4, NULL       , "col",                3, 1, 0xc00b, 2 },
   { s_cr044 + 5, NULL       , "GET",                3, 1, 0xc015, 0 },
   { s_cr044 + 6, NULL       , "v",                  1, 1, 0xc00b, 3 },
   { s_cr044 + 8, s_cr044 + 7, "[",                  1, 1, 0xc012, 0 },
   { NULL       , NULL       , "exp",                3, 1, 0xc00b, 4 },
   { s_cr044 + 9, NULL       , "SEND",               4, 1, 0xc015, 0 },
   { s_cr044 +10, NULL       , "colorDisp",          9, 1, 0xc015, 0 },
   { s_cr044 +11, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr044 +12, NULL       , "clr",                3, 0, 0xc00b, 5 },
   { s_cr044 +13, NULL       , ")",                  1, 0, 0xc033, 0 },
   { NULL       , s_cr044 +14, "[",                  1, 1, 0xc012, 0 },
   { NULL       , NULL       , "nextexp",            7, 1, 0xc00b, 6 }
};
static HB_PP_TOKEN s_cm045[ 14 ] = {
   { s_cm045 + 1, NULL       , "@",                  1, 1, 0xc038, 0 },
   { s_cm045 + 2, NULL       , "row",                3, 0, 0xe001, 1 },
   { s_cm045 + 3, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cm045 + 4, NULL       , "col",                3, 0, 0xe001, 2 },
   { s_cm045 + 5, NULL       , "GET",                3, 1, 0xc015, 0 },
   { s_cm045 + 6, NULL       , "v",                  1, 0, 0xe001, 3 },
   { s_cm045 + 8, s_cm045 + 7, "[",                  1, 1, 0xe007, 0 },
   { NULL       , NULL       , "exp",                3, 0, 0xe002, 4 },
   { s_cm045 + 9, NULL       , "RANGE",              5, 1, 0xc015, 0 },
   { s_cm045 +10, NULL       , "l",                  1, 0, 0xe001, 5 },
   { s_cm045 +11, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cm045 +12, NULL       , "h",                  1, 0, 0xe001, 6 },
   { NULL       , s_cm045 +13, "[",                  1, 1, 0xe007, 0 },
   { NULL       , NULL       , "nextexp",            7, 0, 0xe002, 7 }
};
static HB_PP_TOKEN s_cr045[ 25 ] = {
   { s_cr045 + 1, NULL       , "@",                  1, 1, 0xc038, 0 },
   { s_cr045 + 2, NULL       , "row",                3, 1, 0xc00b, 1 },
   { s_cr045 + 3, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr045 + 4, NULL       , "col",                3, 1, 0xc00b, 2 },
   { s_cr045 + 5, NULL       , "GET",                3, 1, 0xc015, 0 },
   { s_cr045 + 6, NULL       , "v",                  1, 1, 0xc00b, 3 },
   { s_cr045 + 8, s_cr045 + 7, "[",                  1, 1, 0xc012, 0 },
   { NULL       , NULL       , "exp",                3, 1, 0xc00b, 4 },
   { s_cr045 + 9, NULL       , "VALID",              5, 1, 0xc015, 0 },
   { s_cr045 +10, NULL       , "{",                  1, 1, 0xc036, 0 },
   { s_cr045 +11, NULL       , "|",                  1, 1, 0xc01b, 0 },
   { s_cr045 +12, NULL       , "_1",                 2, 0, 0xc015, 0 },
   { s_cr045 +13, NULL       , "|",                  1, 0, 0xc01b, 0 },
   { s_cr045 +14, NULL       , "RangeCheck",        10, 1, 0xc015, 0 },
   { s_cr045 +15, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr045 +16, NULL       , "_1",                 2, 1, 0xc015, 0 },
   { s_cr045 +17, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr045 +18, NULL       , ",",                  1, 1, 0xc01d, 0 },
   { s_cr045 +19, NULL       , "l",                  1, 1, 0xc00b, 5 },
   { s_cr045 +20, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr045 +21, NULL       , "h",                  1, 1, 0xc00b, 6 },
   { s_cr045 +22, NULL       , ")",                  1, 1, 0xc033, 0 },
   { s_cr045 +23, NULL       , "}",                  1, 1, 0xc037, 0 },
   { NULL       , s_cr045 +24, "[",                  1, 1, 0xc012, 0 },
   { NULL       , NULL       , "nextexp",            7, 1, 0xc00b, 7 }
};
static HB_PP_TOKEN s_cm046[ 12 ] = {
   { s_cm046 + 1, NULL       , "@",                  1, 1, 0xc038, 0 },
   { s_cm046 + 2, NULL       , "row",                3, 0, 0xe001, 1 },
   { s_cm046 + 3, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cm046 + 4, NULL       , "col",                3, 0, 0xe001, 2 },
   { s_cm046 + 5, NULL       , "SAY",                3, 1, 0xc015, 0 },
   { s_cm046 + 6, NULL       , "say",                3, 0, 0xe001, 3 },
   { s_cm046 + 8, s_cm046 + 7, "[",                  1, 1, 0xe007, 0 },
   { NULL       , NULL       , "sayexp",             6, 0, 0xe002, 4 },
   { s_cm046 + 9, NULL       , "GET",                3, 1, 0xc015, 0 },
   { s_cm046 +10, NULL       , "get",                3, 0, 0xe001, 5 },
   { NULL       , s_cm046 +11, "[",                  1, 1, 0xe007, 0 },
   { NULL       , NULL       , "getexp",             6, 0, 0xe002, 6 }
};
static HB_PP_TOKEN s_cr046[ 23 ] = {
   { s_cr046 + 1, NULL       , "@",                  1, 1, 0xc038, 0 },
   { s_cr046 + 2, NULL       , "row",                3, 1, 0xc00b, 1 },
   { s_cr046 + 3, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr046 + 4, NULL       , "col",                3, 1, 0xc00b, 2 },
   { s_cr046 + 5, NULL       , "SAY",                3, 1, 0xc015, 0 },
   { s_cr046 + 6, NULL       , "say",                3, 1, 0xc00b, 3 },
   { s_cr046 + 8, s_cr046 + 7, "[",                  1, 1, 0xc012, 0 },
   { NULL       , NULL       , "sayexp",             6, 1, 0xc00b, 4 },
   { s_cr046 + 9, NULL       , ";",                  1, 1, 0xc01e, 0 },
   { s_cr046 +10, NULL       , "@",                  1, 1, 0xc038, 0 },
   { s_cr046 +11, NULL       , "Row",                3, 1, 0xc015, 0 },
   { s_cr046 +12, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr046 +13, NULL       , ")",                  1, 0, 0xc033, 0 },
   { s_cr046 +14, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr046 +15, NULL       , "Col",                3, 1, 0xc015, 0 },
   { s_cr046 +16, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr046 +17, NULL       , ")",                  1, 0, 0xc033, 0 },
   { s_cr046 +18, NULL       , "+",                  1, 1, 0xc050, 0 },
   { s_cr046 +19, NULL       , "1",                  1, 1, 0xc02a, 0 },
   { s_cr046 +20, NULL       , "GET",                3, 1, 0xc015, 0 },
   { s_cr046 +21, NULL       , "get",                3, 1, 0xc00b, 5 },
   { NULL       , s_cr046 +22, "[",                  1, 1, 0xc012, 0 },
   { NULL       , NULL       , "getexp",             6, 1, 0xc00b, 6 }
};
static HB_PP_TOKEN s_cm047[ 6 ] = {
   { s_cm047 + 1, NULL       , "@",                  1, 1, 0xc038, 0 },
   { s_cm047 + 3, s_cm047 + 2, "[",                  1, 1, 0xe007, 0 },
   { NULL       , NULL       , "exp",                3, 0, 0xe002, 1 },
   { s_cm047 + 4, NULL       , "COLOUR",             6, 1, 0xc015, 0 },
   { NULL       , s_cm047 + 5, "[",                  1, 1, 0xe007, 0 },
   { NULL       , NULL       , "nextexp",            7, 0, 0xe002, 2 }
};
static HB_PP_TOKEN s_cr047[ 6 ] = {
   { s_cr047 + 1, NULL       , "@",                  1, 1, 0xc038, 0 },
   { s_cr047 + 3, s_cr047 + 2, "[",                  1, 1, 0xc012, 0 },
   { NULL       , NULL       , "exp",                3, 1, 0xc00b, 1 },
   { s_cr047 + 4, NULL       , "COLOR",              5, 1, 0xc015, 0 },
   { NULL       , s_cr047 + 5, "[",                  1, 1, 0xc012, 0 },
   { NULL       , NULL       , "nextexp",            7, 1, 0xc00b, 2 }
};
static HB_PP_TOKEN s_cm048[ 2 ] = {
   { s_cm048 + 1, NULL       , "CLEAR",              5, 1, 0xc015, 0 },
   { NULL       , NULL       , "GETS",               4, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_cr048[ 13 ] = {
   { s_cr048 + 1, NULL       , "ReadKill",           8, 1, 0xc015, 0 },
   { s_cr048 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr048 + 3, NULL       , ".T.",                3, 0, 0xc02c, 0 },
   { s_cr048 + 4, NULL       , ")",                  1, 0, 0xc033, 0 },
   { s_cr048 + 5, NULL       , ";",                  1, 1, 0xc01e, 0 },
   { s_cr048 + 6, NULL       , "GetList",            7, 1, 0xc015, 0 },
   { s_cr048 + 7, NULL       , ":=",                 2, 1, 0xc03c, 0 },
   { s_cr048 + 8, NULL       , "{",                  1, 1, 0xc036, 0 },
   { s_cr048 + 9, NULL       , "}",                  1, 0, 0xc037, 0 },
   { s_cr048 +10, NULL       , ";",                  1, 1, 0xc01e, 0 },
   { s_cr048 +11, NULL       , "(",                  1, 1, 0xc032, 0 },
   { s_cr048 +12, NULL       , "GetList",            7, 1, 0xc015, 0 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm049[ 2 ] = {
   { s_cm049 + 1, NULL       , "READ",               4, 1, 0xc015, 0 },
   { NULL       , NULL       , "SAVE",               4, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_cr049[ 4 ] = {
   { s_cr049 + 1, NULL       , "ReadModal",          9, 1, 0xc015, 0 },
   { s_cr049 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr049 + 3, NULL       , "GetList",            7, 0, 0xc015, 0 },
   { NULL       , NULL       , ")",                  1, 0, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm050[ 1 ] = {
   { NULL       , NULL       , "READ",               4, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_cr050[ 13 ] = {
   { s_cr050 + 1, NULL       , "ReadModal",          9, 1, 0xc015, 0 },
   { s_cr050 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr050 + 3, NULL       , "GetList",            7, 0, 0xc015, 0 },
   { s_cr050 + 4, NULL       , ")",                  1, 0, 0xc033, 0 },
   { s_cr050 + 5, NULL       , ";",                  1, 1, 0xc01e, 0 },
   { s_cr050 + 6, NULL       , "GetList",            7, 1, 0xc015, 0 },
   { s_cr050 + 7, NULL       , ":=",                 2, 1, 0xc03c, 0 },
   { s_cr050 + 8, NULL       , "{",                  1, 1, 0xc036, 0 },
   { s_cr050 + 9, NULL       , "}",                  1, 0, 0xc037, 0 },
   { s_cr050 +10, NULL       , ";",                  1, 1, 0xc01e, 0 },
   { s_cr050 +11, NULL       , "(",                  1, 1, 0xc032, 0 },
   { s_cr050 +12, NULL       , "GetList",            7, 1, 0xc015, 0 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm051[ 4 ] = {
   { s_cm051 + 1, NULL       , "RESET",              5, 1, 0xc015, 0 },
   { NULL       , s_cm051 + 2, "[",                  1, 1, 0xe007, 0 },
   { s_cm051 + 3, NULL       , "IN",                 2, 0, 0xc015, 0 },
   { NULL       , NULL       , "ualias",             6, 0, 0xe001, 1 }
};
static HB_PP_TOKEN s_cr051[ 13 ] = {
   { s_cr051 + 5, s_cr051 + 1, "[",                  1, 1, 0xc012, 0 },
   { s_cr051 + 2, NULL       , "(",                  1, 1, 0xc032, 0 },
   { s_cr051 + 3, NULL       , "ualias",             6, 1, 0xc00b, 1 },
   { s_cr051 + 4, NULL       , ")",                  1, 1, 0xc033, 0 },
   { NULL       , NULL       , "->",                 2, 0, 0xc03b, 0 },
   { s_cr051 + 6, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr051 + 7, NULL       , "DbInfo",             6, 0, 0xc015, 0 },
   { s_cr051 + 8, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr051 + 9, NULL       , "DBI_TTS_INCOMPLETE",  18, 1, 0xc015, 0 },
   { s_cr051 +10, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr051 +11, NULL       , ".F.",                3, 1, 0xc02c, 0 },
   { s_cr051 +12, NULL       , ")",                  1, 1, 0xc033, 0 },
   { NULL       , NULL       , ")",                  1, 0, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm052[ 1 ] = {
   { NULL       , NULL       , "REINDEX",            7, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_cr052[ 3 ] = {
   { s_cr052 + 1, NULL       , "ordListRebuild",    14, 1, 0xc015, 0 },
   { s_cr052 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { NULL       , NULL       , ")",                  1, 0, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm053[ 10 ] = {
   { s_cm053 + 1, NULL       , "REINDEX",            7, 1, 0xc015, 0 },
   { s_cm053 + 4, s_cm053 + 2, "[",                  1, 1, 0xe007, 0 },
   { s_cm053 + 3, NULL       , "EVAL",               4, 0, 0xc015, 0 },
   { NULL       , NULL       , "eval",               4, 0, 0xe001, 1 },
   { s_cm053 + 7, s_cm053 + 5, "[",                  1, 1, 0xe007, 0 },
   { s_cm053 + 6, NULL       , "EVERY",              5, 0, 0xc015, 0 },
   { NULL       , NULL       , "every",              5, 0, 0xe001, 2 },
   { NULL       , s_cm053 + 8, "[",                  1, 1, 0xe007, 0 },
   { NULL       , s_cm053 + 9, "lNoOpt",             6, 0, 0xc003, 3 },
   { NULL       , NULL       , "NOOPTIMIZE",        10, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_cr053[ 25 ] = {
   { s_cr053 + 1, NULL       , "ordCondSet",        10, 1, 0xc015, 0 },
   { s_cr053 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr053 + 3, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr053 + 4, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr053 + 5, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr053 + 6, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr053 + 7, NULL       , "eval",               4, 1, 0xc00f, 1 },
   { s_cr053 + 8, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr053 + 9, NULL       , "every",              5, 1, 0xc00b, 2 },
   { s_cr053 +10, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr053 +11, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr053 +12, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr053 +13, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr053 +14, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr053 +15, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr053 +16, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr053 +17, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr053 +18, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr053 +19, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr053 +20, NULL       , "lNoOpt",             6, 1, 0xc010, 3 },
   { s_cr053 +21, NULL       , ")",                  1, 0, 0xc033, 0 },
   { s_cr053 +22, NULL       , ";",                  1, 1, 0xc01e, 0 },
   { s_cr053 +23, NULL       , "ordListRebuild",    14, 1, 0xc015, 0 },
   { s_cr053 +24, NULL       , "(",                  1, 0, 0xc032, 0 },
   { NULL       , NULL       , ")",                  1, 0, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm054[ 8 ] = {
   { s_cm054 + 1, NULL       , "INDEX",              5, 1, 0xc015, 0 },
   { s_cm054 + 2, NULL       , "ON",                 2, 1, 0xc015, 0 },
   { s_cm054 + 3, NULL       , "key",                3, 0, 0xe001, 2 },
   { s_cm054 + 4, NULL       , "TO",                 2, 1, 0xc015, 0 },
   { s_cm054 + 5, NULL       , "file",               4, 0, 0xe005, 1 },
   { NULL       , s_cm054 + 6, "[",                  1, 1, 0xe007, 0 },
   { NULL       , s_cm054 + 7, "u",                  1, 0, 0xc003, 3 },
   { NULL       , NULL       , "UNIQUE",             6, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_cr054[ 17 ] = {
   { s_cr054 + 1, NULL       , "dbCreateIndex",     13, 1, 0xc015, 0 },
   { s_cr054 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr054 + 3, NULL       , "file",               4, 1, 0xc00e, 1 },
   { s_cr054 + 4, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr054 + 5, NULL       , "key",                3, 1, 0xc00d, 2 },
   { s_cr054 + 6, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr054 + 7, NULL       , "key",                3, 1, 0xc00f, 2 },
   { s_cr054 + 8, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr054 + 9, NULL       , "if",                 2, 1, 0xc015, 0 },
   { s_cr054 +10, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr054 +11, NULL       , "u",                  1, 1, 0xc010, 3 },
   { s_cr054 +12, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr054 +13, NULL       , ".T.",                3, 1, 0xc02c, 0 },
   { s_cr054 +14, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr054 +15, NULL       , "NIL",                3, 1, 0xc015, 0 },
   { s_cr054 +16, NULL       , ")",                  1, 1, 0xc033, 0 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm055[ 73 ] = {
   { s_cm055 + 1, NULL       , "INDEX",              5, 1, 0xc015, 0 },
   { s_cm055 + 2, NULL       , "ON",                 2, 1, 0xc015, 0 },
   { s_cm055 + 3, NULL       , "key",                3, 0, 0xe001, 19 },
   { s_cm055 + 4, NULL       , "TAG",                3, 1, 0xc015, 0 },
   { s_cm055 + 5, NULL       , "tag",                3, 0, 0xe005, 18 },
   { s_cm055 + 8, s_cm055 + 6, "[",                  1, 1, 0xe007, 0 },
   { s_cm055 + 7, NULL       , "TO",                 2, 0, 0xc015, 0 },
   { NULL       , NULL       , "bag",                3, 0, 0xe005, 17 },
   { s_cm055 +11, s_cm055 + 9, "[",                  1, 1, 0xe007, 0 },
   { s_cm055 +10, NULL       , "FOR",                3, 0, 0xc015, 0 },
   { NULL       , NULL       , "for",                3, 0, 0xe001, 1 },
   { s_cm055 +14, s_cm055 +12, "[",                  1, 1, 0xe007, 0 },
   { s_cm055 +13, NULL       , "WHILE",              5, 0, 0xc015, 0 },
   { NULL       , NULL       , "while",              5, 0, 0xe001, 3 },
   { s_cm055 +17, s_cm055 +15, "[",                  1, 1, 0xe007, 0 },
   { s_cm055 +16, NULL       , "NEXT",               4, 0, 0xc015, 0 },
   { NULL       , NULL       , "next",               4, 0, 0xe001, 6 },
   { s_cm055 +20, s_cm055 +18, "[",                  1, 1, 0xe007, 0 },
   { s_cm055 +19, NULL       , "RECORD",             6, 0, 0xc015, 0 },
   { NULL       , NULL       , "rec",                3, 0, 0xe001, 7 },
   { s_cm055 +23, s_cm055 +21, "[",                  1, 1, 0xe007, 0 },
   { NULL       , s_cm055 +22, "rest",               4, 0, 0xc003, 8 },
   { NULL       , NULL       , "REST",               4, 0, 0xc015, 0 },
   { s_cm055 +26, s_cm055 +24, "[",                  1, 1, 0xe007, 0 },
   { NULL       , s_cm055 +25, "all",                3, 0, 0xc003, 2 },
   { NULL       , NULL       , "ALL",                3, 0, 0xc015, 0 },
   { s_cm055 +29, s_cm055 +27, "[",                  1, 1, 0xe007, 0 },
   { s_cm055 +28, NULL       , "EVAL",               4, 0, 0xc015, 0 },
   { NULL       , NULL       , "eval",               4, 0, 0xe001, 4 },
   { s_cm055 +32, s_cm055 +30, "[",                  1, 1, 0xe007, 0 },
   { s_cm055 +31, NULL       , "EVERY",              5, 0, 0xc015, 0 },
   { NULL       , NULL       , "every",              5, 0, 0xe001, 5 },
   { s_cm055 +35, s_cm055 +33, "[",                  1, 1, 0xe007, 0 },
   { NULL       , s_cm055 +34, "unique",             6, 0, 0xc003, 20 },
   { NULL       , NULL       , "UNIQUE",             6, 1, 0xc015, 0 },
   { s_cm055 +38, s_cm055 +36, "[",                  1, 1, 0xe007, 0 },
   { NULL       , s_cm055 +37, "ascend",             6, 0, 0xc003, 0 },
   { NULL       , NULL       , "ASCENDING",          9, 1, 0xc015, 0 },
   { s_cm055 +41, s_cm055 +39, "[",                  1, 1, 0xe007, 0 },
   { NULL       , s_cm055 +40, "descend",            7, 0, 0xc003, 9 },
   { NULL       , NULL       , "DESCENDING",        10, 1, 0xc015, 0 },
   { s_cm055 +44, s_cm055 +42, "[",                  1, 1, 0xe007, 0 },
   { NULL       , s_cm055 +43, "add",                3, 0, 0xc003, 10 },
   { NULL       , NULL       , "ADDITIVE",           8, 1, 0xc015, 0 },
   { s_cm055 +47, s_cm055 +45, "[",                  1, 1, 0xe007, 0 },
   { NULL       , s_cm055 +46, "cur",                3, 0, 0xc003, 11 },
   { NULL       , NULL       , "USECURRENT",        10, 1, 0xc015, 0 },
   { s_cm055 +50, s_cm055 +48, "[",                  1, 1, 0xe007, 0 },
   { NULL       , s_cm055 +49, "cust",               4, 0, 0xc003, 12 },
   { NULL       , NULL       , "CUSTOM",             6, 1, 0xc015, 0 },
   { s_cm055 +53, s_cm055 +51, "[",                  1, 1, 0xe007, 0 },
   { NULL       , s_cm055 +52, "noopt",              5, 0, 0xc003, 13 },
   { NULL       , NULL       , "NOOPTIMIZE",        10, 1, 0xc015, 0 },
   { s_cm055 +58, s_cm055 +54, "[",                  1, 1, 0xe007, 0 },
   { NULL       , s_cm055 +55, "mem",                3, 0, 0xc003, 14 },
   { s_cm055 +56, NULL       , "MEMORY",             6, 1, 0xc015, 0 },
   { s_cm055 +57, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { NULL       , NULL       , "TEMPORARY",          9, 1, 0xc015, 0 },
   { s_cm055 +61, s_cm055 +59, "[",                  1, 1, 0xe007, 0 },
   { NULL       , s_cm055 +60, "filter",             6, 0, 0xc003, 15 },
   { NULL       , NULL       , "USEFILTER",          9, 1, 0xc015, 0 },
   { s_cm055 +64, s_cm055 +62, "[",                  1, 1, 0xe007, 0 },
   { NULL       , s_cm055 +63, "ex",                 2, 0, 0xc003, 16 },
   { NULL       , NULL       , "EXCLUSIVE",          9, 1, 0xc015, 0 },
   { s_cm055 +67, s_cm055 +65, "[",                  1, 1, 0xe007, 0 },
   { s_cm055 +66, NULL       , "CONSTRAINT",        10, 0, 0xc015, 0 },
   { NULL       , NULL       , "cons",               4, 0, 0xe005, 21 },
   { s_cm055 +70, s_cm055 +68, "[",                  1, 1, 0xe007, 0 },
   { s_cm055 +69, NULL       , "TARGET",             6, 0, 0xc015, 0 },
   { NULL       , NULL       , "targ",               4, 0, 0xe005, 22 },
   { NULL       , s_cm055 +71, "[",                  1, 1, 0xe007, 0 },
   { s_cm055 +72, NULL       , "KEY",                3, 0, 0xc015, 0 },
   { NULL       , NULL       , "kkey",               4, 0, 0xe001, 23 }
};
static HB_PP_TOKEN s_cr055[ 75 ] = {
   { s_cr055 + 1, NULL       , "ordCondSet",        10, 1, 0xc015, 0 },
   { s_cr055 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr055 + 3, NULL       , "for",                3, 1, 0xc00d, 1 },
   { s_cr055 + 4, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr055 + 5, NULL       , "for",                3, 1, 0xc00f, 1 },
   { s_cr055 + 6, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr055 + 8, s_cr055 + 7, "[",                  1, 1, 0xc012, 0 },
   { NULL       , NULL       , "all",                3, 1, 0xc010, 2 },
   { s_cr055 + 9, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr055 +10, NULL       , "while",              5, 1, 0xc00f, 3 },
   { s_cr055 +11, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr055 +12, NULL       , "eval",               4, 1, 0xc00f, 4 },
   { s_cr055 +13, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr055 +14, NULL       , "every",              5, 1, 0xc00b, 5 },
   { s_cr055 +15, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr055 +16, NULL       , "RECNO",              5, 1, 0xc015, 0 },
   { s_cr055 +17, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr055 +18, NULL       , ")",                  1, 0, 0xc033, 0 },
   { s_cr055 +19, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr055 +20, NULL       , "next",               4, 1, 0xc00b, 6 },
   { s_cr055 +21, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr055 +22, NULL       , "rec",                3, 1, 0xc00b, 7 },
   { s_cr055 +23, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr055 +25, s_cr055 +24, "[",                  1, 1, 0xc012, 0 },
   { NULL       , NULL       , "rest",               4, 1, 0xc010, 8 },
   { s_cr055 +26, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr055 +28, s_cr055 +27, "[",                  1, 1, 0xc012, 0 },
   { NULL       , NULL       , "descend",            7, 1, 0xc010, 9 },
   { s_cr055 +29, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr055 +30, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr055 +32, s_cr055 +31, "[",                  1, 1, 0xc012, 0 },
   { NULL       , NULL       , "add",                3, 1, 0xc010, 10 },
   { s_cr055 +33, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr055 +35, s_cr055 +34, "[",                  1, 1, 0xc012, 0 },
   { NULL       , NULL       , "cur",                3, 1, 0xc010, 11 },
   { s_cr055 +36, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr055 +38, s_cr055 +37, "[",                  1, 1, 0xc012, 0 },
   { NULL       , NULL       , "cust",               4, 1, 0xc010, 12 },
   { s_cr055 +39, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr055 +41, s_cr055 +40, "[",                  1, 1, 0xc012, 0 },
   { NULL       , NULL       , "noopt",              5, 1, 0xc010, 13 },
   { s_cr055 +42, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr055 +43, NULL       , "while",              5, 1, 0xc00d, 3 },
   { s_cr055 +44, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr055 +46, s_cr055 +45, "[",                  1, 1, 0xc012, 0 },
   { NULL       , NULL       , "mem",                3, 1, 0xc010, 14 },
   { s_cr055 +47, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr055 +49, s_cr055 +48, "[",                  1, 1, 0xc012, 0 },
   { NULL       , NULL       , "filter",             6, 1, 0xc010, 15 },
   { s_cr055 +50, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr055 +52, s_cr055 +51, "[",                  1, 1, 0xc012, 0 },
   { NULL       , NULL       , "ex",                 2, 1, 0xc010, 16 },
   { s_cr055 +53, NULL       , ")",                  1, 1, 0xc033, 0 },
   { s_cr055 +54, NULL       , ";",                  1, 1, 0xc01e, 0 },
   { s_cr055 +55, NULL       , "ordCreate",          9, 1, 0xc015, 0 },
   { s_cr055 +56, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr055 +57, NULL       , "bag",                3, 1, 0xc00e, 17 },
   { s_cr055 +58, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr055 +59, NULL       , "tag",                3, 1, 0xc00e, 18 },
   { s_cr055 +60, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr055 +61, NULL       , "key",                3, 1, 0xc00d, 19 },
   { s_cr055 +62, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr055 +63, NULL       , "key",                3, 1, 0xc00f, 19 },
   { s_cr055 +64, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr055 +66, s_cr055 +65, "[",                  1, 1, 0xc012, 0 },
   { NULL       , NULL       , "unique",             6, 1, 0xc010, 20 },
   { s_cr055 +67, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr055 +68, NULL       , "cons",               4, 0, 0xc00e, 21 },
   { s_cr055 +69, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr055 +70, NULL       , "targ",               4, 0, 0xc00e, 22 },
   { s_cr055 +71, NULL       , ",",                  1, 1, 0xc01d, 0 },
   { s_cr055 +72, NULL       , "{",                  1, 0, 0xc036, 0 },
   { s_cr055 +73, NULL       , "kkey",               4, 0, 0xc00e, 23 },
   { s_cr055 +74, NULL       , "}",                  1, 0, 0xc037, 0 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm056[ 73 ] = {
   { s_cm056 + 1, NULL       , "INDEX",              5, 1, 0xc015, 0 },
   { s_cm056 + 2, NULL       , "ON",                 2, 1, 0xc015, 0 },
   { s_cm056 + 3, NULL       , "key",                3, 0, 0xe001, 19 },
   { s_cm056 + 6, s_cm056 + 4, "[",                  1, 1, 0xe007, 0 },
   { s_cm056 + 5, NULL       , "TAG",                3, 0, 0xc015, 0 },
   { NULL       , NULL       , "tag",                3, 0, 0xe005, 18 },
   { s_cm056 + 7, NULL       , "TO",                 2, 1, 0xc015, 0 },
   { s_cm056 + 8, NULL       , "bag",                3, 0, 0xe005, 17 },
   { s_cm056 +11, s_cm056 + 9, "[",                  1, 1, 0xe007, 0 },
   { s_cm056 +10, NULL       , "FOR",                3, 0, 0xc015, 0 },
   { NULL       , NULL       , "for",                3, 0, 0xe001, 1 },
   { s_cm056 +14, s_cm056 +12, "[",                  1, 1, 0xe007, 0 },
   { s_cm056 +13, NULL       , "WHILE",              5, 0, 0xc015, 0 },
   { NULL       , NULL       , "while",              5, 0, 0xe001, 3 },
   { s_cm056 +17, s_cm056 +15, "[",                  1, 1, 0xe007, 0 },
   { s_cm056 +16, NULL       , "NEXT",               4, 0, 0xc015, 0 },
   { NULL       , NULL       , "next",               4, 0, 0xe001, 6 },
   { s_cm056 +20, s_cm056 +18, "[",                  1, 1, 0xe007, 0 },
   { s_cm056 +19, NULL       , "RECORD",             6, 0, 0xc015, 0 },
   { NULL       , NULL       , "rec",                3, 0, 0xe001, 7 },
   { s_cm056 +23, s_cm056 +21, "[",                  1, 1, 0xe007, 0 },
   { NULL       , s_cm056 +22, "rest",               4, 0, 0xc003, 8 },
   { NULL       , NULL       , "REST",               4, 0, 0xc015, 0 },
   { s_cm056 +26, s_cm056 +24, "[",                  1, 1, 0xe007, 0 },
   { NULL       , s_cm056 +25, "all",                3, 0, 0xc003, 2 },
   { NULL       , NULL       , "ALL",                3, 0, 0xc015, 0 },
   { s_cm056 +29, s_cm056 +27, "[",                  1, 1, 0xe007, 0 },
   { s_cm056 +28, NULL       , "EVAL",               4, 0, 0xc015, 0 },
   { NULL       , NULL       , "eval",               4, 0, 0xe001, 4 },
   { s_cm056 +32, s_cm056 +30, "[",                  1, 1, 0xe007, 0 },
   { s_cm056 +31, NULL       , "EVERY",              5, 0, 0xc015, 0 },
   { NULL       , NULL       , "every",              5, 0, 0xe001, 5 },
   { s_cm056 +35, s_cm056 +33, "[",                  1, 1, 0xe007, 0 },
   { NULL       , s_cm056 +34, "unique",             6, 0, 0xc003, 20 },
   { NULL       , NULL       , "UNIQUE",             6, 1, 0xc015, 0 },
   { s_cm056 +38, s_cm056 +36, "[",                  1, 1, 0xe007, 0 },
   { NULL       , s_cm056 +37, "ascend",             6, 0, 0xc003, 0 },
   { NULL       , NULL       , "ASCENDING",          9, 1, 0xc015, 0 },
   { s_cm056 +41, s_cm056 +39, "[",                  1, 1, 0xe007, 0 },
   { NULL       , s_cm056 +40, "descend",            7, 0, 0xc003, 9 },
   { NULL       , NULL       , "DESCENDING",        10, 1, 0xc015, 0 },
   { s_cm056 +44, s_cm056 +42, "[",                  1, 1, 0xe007, 0 },
   { NULL       , s_cm056 +43, "add",                3, 0, 0xc003, 10 },
   { NULL       , NULL       , "ADDITIVE",           8, 1, 0xc015, 0 },
   { s_cm056 +47, s_cm056 +45, "[",                  1, 1, 0xe007, 0 },
   { NULL       , s_cm056 +46, "cur",                3, 0, 0xc003, 11 },
   { NULL       , NULL       , "USECURRENT",        10, 1, 0xc015, 0 },
   { s_cm056 +50, s_cm056 +48, "[",                  1, 1, 0xe007, 0 },
   { NULL       , s_cm056 +49, "cust",               4, 0, 0xc003, 12 },
   { NULL       , NULL       , "CUSTOM",             6, 1, 0xc015, 0 },
   { s_cm056 +53, s_cm056 +51, "[",                  1, 1, 0xe007, 0 },
   { NULL       , s_cm056 +52, "noopt",              5, 0, 0xc003, 13 },
   { NULL       , NULL       , "NOOPTIMIZE",        10, 1, 0xc015, 0 },
   { s_cm056 +58, s_cm056 +54, "[",                  1, 1, 0xe007, 0 },
   { NULL       , s_cm056 +55, "mem",                3, 0, 0xc003, 14 },
   { s_cm056 +56, NULL       , "MEMORY",             6, 1, 0xc015, 0 },
   { s_cm056 +57, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { NULL       , NULL       , "TEMPORARY",          9, 1, 0xc015, 0 },
   { s_cm056 +61, s_cm056 +59, "[",                  1, 1, 0xe007, 0 },
   { NULL       , s_cm056 +60, "filter",             6, 0, 0xc003, 15 },
   { NULL       , NULL       , "USEFILTER",          9, 1, 0xc015, 0 },
   { s_cm056 +64, s_cm056 +62, "[",                  1, 1, 0xe007, 0 },
   { NULL       , s_cm056 +63, "ex",                 2, 0, 0xc003, 16 },
   { NULL       , NULL       , "EXCLUSIVE",          9, 1, 0xc015, 0 },
   { s_cm056 +67, s_cm056 +65, "[",                  1, 1, 0xe007, 0 },
   { s_cm056 +66, NULL       , "CONSTRAINT",        10, 0, 0xc015, 0 },
   { NULL       , NULL       , "cons",               4, 0, 0xe005, 21 },
   { s_cm056 +70, s_cm056 +68, "[",                  1, 1, 0xe007, 0 },
   { s_cm056 +69, NULL       , "TARGET",             6, 0, 0xc015, 0 },
   { NULL       , NULL       , "targ",               4, 0, 0xe005, 22 },
   { NULL       , s_cm056 +71, "[",                  1, 1, 0xe007, 0 },
   { s_cm056 +72, NULL       , "KEY",                3, 0, 0xc015, 0 },
   { NULL       , NULL       , "kkey",               4, 0, 0xe001, 23 }
};
static HB_PP_TOKEN s_cr056[ 75 ] = {
   { s_cr056 + 1, NULL       , "ordCondSet",        10, 1, 0xc015, 0 },
   { s_cr056 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr056 + 3, NULL       , "for",                3, 1, 0xc00d, 1 },
   { s_cr056 + 4, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr056 + 5, NULL       , "for",                3, 1, 0xc00f, 1 },
   { s_cr056 + 6, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr056 + 8, s_cr056 + 7, "[",                  1, 1, 0xc012, 0 },
   { NULL       , NULL       , "all",                3, 1, 0xc010, 2 },
   { s_cr056 + 9, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr056 +10, NULL       , "while",              5, 1, 0xc00f, 3 },
   { s_cr056 +11, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr056 +12, NULL       , "eval",               4, 1, 0xc00f, 4 },
   { s_cr056 +13, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr056 +14, NULL       , "every",              5, 1, 0xc00b, 5 },
   { s_cr056 +15, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr056 +16, NULL       , "RECNO",              5, 1, 0xc015, 0 },
   { s_cr056 +17, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr056 +18, NULL       , ")",                  1, 0, 0xc033, 0 },
   { s_cr056 +19, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr056 +20, NULL       , "next",               4, 1, 0xc00b, 6 },
   { s_cr056 +21, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr056 +22, NULL       , "rec",                3, 1, 0xc00b, 7 },
   { s_cr056 +23, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr056 +25, s_cr056 +24, "[",                  1, 1, 0xc012, 0 },
   { NULL       , NULL       , "rest",               4, 1, 0xc010, 8 },
   { s_cr056 +26, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr056 +28, s_cr056 +27, "[",                  1, 1, 0xc012, 0 },
   { NULL       , NULL       , "descend",            7, 1, 0xc010, 9 },
   { s_cr056 +29, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr056 +30, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr056 +32, s_cr056 +31, "[",                  1, 1, 0xc012, 0 },
   { NULL       , NULL       , "add",                3, 1, 0xc010, 10 },
   { s_cr056 +33, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr056 +35, s_cr056 +34, "[",                  1, 1, 0xc012, 0 },
   { NULL       , NULL       , "cur",                3, 1, 0xc010, 11 },
   { s_cr056 +36, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr056 +38, s_cr056 +37, "[",                  1, 1, 0xc012, 0 },
   { NULL       , NULL       , "cust",               4, 1, 0xc010, 12 },
   { s_cr056 +39, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr056 +41, s_cr056 +40, "[",                  1, 1, 0xc012, 0 },
   { NULL       , NULL       , "noopt",              5, 1, 0xc010, 13 },
   { s_cr056 +42, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr056 +43, NULL       , "while",              5, 1, 0xc00d, 3 },
   { s_cr056 +44, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr056 +46, s_cr056 +45, "[",                  1, 1, 0xc012, 0 },
   { NULL       , NULL       , "mem",                3, 1, 0xc010, 14 },
   { s_cr056 +47, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr056 +49, s_cr056 +48, "[",                  1, 1, 0xc012, 0 },
   { NULL       , NULL       , "filter",             6, 1, 0xc010, 15 },
   { s_cr056 +50, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr056 +52, s_cr056 +51, "[",                  1, 1, 0xc012, 0 },
   { NULL       , NULL       , "ex",                 2, 1, 0xc010, 16 },
   { s_cr056 +53, NULL       , ")",                  1, 1, 0xc033, 0 },
   { s_cr056 +54, NULL       , ";",                  1, 1, 0xc01e, 0 },
   { s_cr056 +55, NULL       , "ordCreate",          9, 1, 0xc015, 0 },
   { s_cr056 +56, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr056 +57, NULL       , "bag",                3, 1, 0xc00e, 17 },
   { s_cr056 +58, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr056 +59, NULL       , "tag",                3, 1, 0xc00e, 18 },
   { s_cr056 +60, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr056 +61, NULL       , "key",                3, 1, 0xc00d, 19 },
   { s_cr056 +62, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr056 +63, NULL       , "key",                3, 1, 0xc00f, 19 },
   { s_cr056 +64, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr056 +66, s_cr056 +65, "[",                  1, 1, 0xc012, 0 },
   { NULL       , NULL       , "unique",             6, 1, 0xc010, 20 },
   { s_cr056 +67, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr056 +68, NULL       , "cons",               4, 0, 0xc00e, 21 },
   { s_cr056 +69, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr056 +70, NULL       , "targ",               4, 0, 0xc00e, 22 },
   { s_cr056 +71, NULL       , ",",                  1, 1, 0xc01d, 0 },
   { s_cr056 +72, NULL       , "{",                  1, 0, 0xc036, 0 },
   { s_cr056 +73, NULL       , "kkey",               4, 0, 0xc00e, 23 },
   { s_cr056 +74, NULL       , "}",                  1, 0, 0xc037, 0 },
   { NULL       , NULL       , ")",                  1, 0, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm057[ 12 ] = {
   { s_cm057 + 1, NULL       , "DELETE",             6, 1, 0xc015, 0 },
   { s_cm057 + 2, NULL       , "TAG",                3, 1, 0xc015, 0 },
   { s_cm057 + 3, NULL       , "tag1",               4, 0, 0xe005, 1 },
   { s_cm057 + 6, s_cm057 + 4, "[",                  1, 1, 0xe007, 0 },
   { s_cm057 + 5, NULL       , "IN",                 2, 0, 0xc015, 0 },
   { NULL       , NULL       , "bag1",               4, 0, 0xe005, 2 },
   { NULL       , s_cm057 + 7, "[",                  1, 1, 0xe007, 0 },
   { s_cm057 + 8, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cm057 + 9, NULL       , "tagN",               4, 0, 0xe005, 3 },
   { NULL       , s_cm057 +10, "[",                  1, 1, 0xe007, 0 },
   { s_cm057 +11, NULL       , "IN",                 2, 0, 0xc015, 0 },
   { NULL       , NULL       , "bagN",               4, 0, 0xe005, 4 }
};
static HB_PP_TOKEN s_cr057[ 14 ] = {
   { s_cr057 + 1, NULL       , "ordDestroy",        10, 1, 0xc015, 0 },
   { s_cr057 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr057 + 3, NULL       , "tag1",               4, 1, 0xc00e, 1 },
   { s_cr057 + 4, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr057 + 5, NULL       , "bag1",               4, 1, 0xc00e, 2 },
   { s_cr057 + 6, NULL       , ")",                  1, 1, 0xc033, 0 },
   { NULL       , s_cr057 + 7, "[",                  1, 0, 0xc012, 0 },
   { s_cr057 + 8, NULL       , ";",                  1, 1, 0xc01e, 0 },
   { s_cr057 + 9, NULL       , "ordDestroy",        10, 1, 0xc015, 0 },
   { s_cr057 +10, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr057 +11, NULL       , "tagN",               4, 1, 0xc00e, 3 },
   { s_cr057 +12, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr057 +13, NULL       , "bagN",               4, 1, 0xc00e, 4 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm058[ 34 ] = {
   { s_cm058 + 1, NULL       , "LABEL",              5, 1, 0xc015, 0 },
   { s_cm058 + 2, NULL       , "FORM",               4, 1, 0xc015, 0 },
   { s_cm058 + 3, NULL       , "lbl",                3, 0, 0xe001, 1 },
   { s_cm058 + 6, s_cm058 + 4, "[",                  1, 1, 0xe007, 0 },
   { NULL       , s_cm058 + 5, "smp",                3, 0, 0xc003, 10 },
   { NULL       , NULL       , "SAMPLE",             6, 0, 0xc015, 0 },
   { s_cm058 + 9, s_cm058 + 7, "[",                  1, 1, 0xe007, 0 },
   { NULL       , s_cm058 + 8, "nocon",              5, 0, 0xc003, 4 },
   { NULL       , NULL       , "NOCONSOLE",          9, 0, 0xc015, 0 },
   { s_cm058 +13, s_cm058 +10, "[",                  1, 1, 0xe007, 0 },
   { NULL       , s_cm058 +11, "prn",                3, 0, 0xc003, 2 },
   { s_cm058 +12, NULL       , "TO",                 2, 0, 0xc015, 0 },
   { NULL       , NULL       , "PRINTER",            7, 1, 0xc015, 0 },
   { s_cm058 +17, s_cm058 +14, "[",                  1, 1, 0xe007, 0 },
   { s_cm058 +15, NULL       , "TO",                 2, 0, 0xc015, 0 },
   { s_cm058 +16, NULL       , "FILE",               4, 1, 0xc015, 0 },
   { NULL       , NULL       , "f",                  1, 0, 0xe005, 3 },
   { s_cm058 +20, s_cm058 +18, "[",                  1, 1, 0xe007, 0 },
   { s_cm058 +19, NULL       , "FOR",                3, 0, 0xc015, 0 },
   { NULL       , NULL       , "for",                3, 0, 0xe001, 5 },
   { s_cm058 +23, s_cm058 +21, "[",                  1, 1, 0xe007, 0 },
   { s_cm058 +22, NULL       , "WHILE",              5, 0, 0xc015, 0 },
   { NULL       , NULL       , "while",              5, 0, 0xe001, 6 },
   { s_cm058 +26, s_cm058 +24, "[",                  1, 1, 0xe007, 0 },
   { s_cm058 +25, NULL       , "NEXT",               4, 0, 0xc015, 0 },
   { NULL       , NULL       , "next",               4, 0, 0xe001, 7 },
   { s_cm058 +29, s_cm058 +27, "[",                  1, 1, 0xe007, 0 },
   { s_cm058 +28, NULL       , "RECORD",             6, 0, 0xc015, 0 },
   { NULL       , NULL       , "rec",                3, 0, 0xe001, 8 },
   { s_cm058 +32, s_cm058 +30, "[",                  1, 1, 0xe007, 0 },
   { NULL       , s_cm058 +31, "rest",               4, 0, 0xc003, 9 },
   { NULL       , NULL       , "REST",               4, 0, 0xc015, 0 },
   { NULL       , s_cm058 +33, "[",                  1, 1, 0xe007, 0 },
   { NULL       , NULL       , "ALL",                3, 0, 0xc015, 0 }
};
static HB_PP_TOKEN s_cr058[ 22 ] = {
   { s_cr058 + 1, NULL       , "__LabelForm",       11, 1, 0xc015, 0 },
   { s_cr058 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr058 + 3, NULL       , "lbl",                3, 1, 0xc00e, 1 },
   { s_cr058 + 4, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr058 + 5, NULL       , "prn",                3, 1, 0xc010, 2 },
   { s_cr058 + 6, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr058 + 7, NULL       , "f",                  1, 1, 0xc00e, 3 },
   { s_cr058 + 8, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr058 + 9, NULL       , "nocon",              5, 1, 0xc010, 4 },
   { s_cr058 +10, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr058 +11, NULL       , "for",                3, 1, 0xc00f, 5 },
   { s_cr058 +12, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr058 +13, NULL       , "while",              5, 1, 0xc00f, 6 },
   { s_cr058 +14, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr058 +15, NULL       , "next",               4, 1, 0xc00b, 7 },
   { s_cr058 +16, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr058 +17, NULL       , "rec",                3, 1, 0xc00b, 8 },
   { s_cr058 +18, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr058 +19, NULL       , "rest",               4, 1, 0xc010, 9 },
   { s_cr058 +20, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr058 +21, NULL       , "smp",                3, 1, 0xc010, 10 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm059[ 43 ] = {
   { s_cm059 + 1, NULL       , "REPORT",             6, 1, 0xc015, 0 },
   { s_cm059 + 2, NULL       , "FORM",               4, 1, 0xc015, 0 },
   { s_cm059 + 3, NULL       , "frm",                3, 0, 0xe001, 1 },
   { s_cm059 + 6, s_cm059 + 4, "[",                  1, 1, 0xe007, 0 },
   { s_cm059 + 5, NULL       , "HEADING",            7, 0, 0xc015, 0 },
   { NULL       , NULL       , "head",               4, 0, 0xe001, 11 },
   { s_cm059 + 9, s_cm059 + 7, "[",                  1, 1, 0xe007, 0 },
   { NULL       , s_cm059 + 8, "plain",              5, 0, 0xc003, 10 },
   { NULL       , NULL       , "PLAIN",              5, 0, 0xc015, 0 },
   { s_cm059 +12, s_cm059 +10, "[",                  1, 1, 0xe007, 0 },
   { NULL       , s_cm059 +11, "noej",               4, 0, 0xc003, 12 },
   { NULL       , NULL       , "NOEJECT",            7, 0, 0xc015, 0 },
   { s_cm059 +15, s_cm059 +13, "[",                  1, 1, 0xe007, 0 },
   { NULL       , s_cm059 +14, "sum",                3, 0, 0xc003, 13 },
   { NULL       , NULL       , "SUMMARY",            7, 0, 0xc015, 0 },
   { s_cm059 +18, s_cm059 +16, "[",                  1, 1, 0xe007, 0 },
   { NULL       , s_cm059 +17, "nocon",              5, 0, 0xc003, 4 },
   { NULL       , NULL       , "NOCONSOLE",          9, 0, 0xc015, 0 },
   { s_cm059 +22, s_cm059 +19, "[",                  1, 1, 0xe007, 0 },
   { NULL       , s_cm059 +20, "prn",                3, 0, 0xc003, 2 },
   { s_cm059 +21, NULL       , "TO",                 2, 0, 0xc015, 0 },
   { NULL       , NULL       , "PRINTER",            7, 1, 0xc015, 0 },
   { s_cm059 +26, s_cm059 +23, "[",                  1, 1, 0xe007, 0 },
   { s_cm059 +24, NULL       , "TO",                 2, 0, 0xc015, 0 },
   { s_cm059 +25, NULL       , "FILE",               4, 1, 0xc015, 0 },
   { NULL       , NULL       , "f",                  1, 0, 0xe005, 3 },
   { s_cm059 +29, s_cm059 +27, "[",                  1, 1, 0xe007, 0 },
   { s_cm059 +28, NULL       , "FOR",                3, 0, 0xc015, 0 },
   { NULL       , NULL       , "for",                3, 0, 0xe001, 5 },
   { s_cm059 +32, s_cm059 +30, "[",                  1, 1, 0xe007, 0 },
   { s_cm059 +31, NULL       , "WHILE",              5, 0, 0xc015, 0 },
   { NULL       , NULL       , "while",              5, 0, 0xe001, 6 },
   { s_cm059 +35, s_cm059 +33, "[",                  1, 1, 0xe007, 0 },
   { s_cm059 +34, NULL       , "NEXT",               4, 0, 0xc015, 0 },
   { NULL       , NULL       , "next",               4, 0, 0xe001, 7 },
   { s_cm059 +38, s_cm059 +36, "[",                  1, 1, 0xe007, 0 },
   { s_cm059 +37, NULL       , "RECORD",             6, 0, 0xc015, 0 },
   { NULL       , NULL       , "rec",                3, 0, 0xe001, 8 },
   { s_cm059 +41, s_cm059 +39, "[",                  1, 1, 0xe007, 0 },
   { NULL       , s_cm059 +40, "rest",               4, 0, 0xc003, 9 },
   { NULL       , NULL       , "REST",               4, 0, 0xc015, 0 },
   { NULL       , s_cm059 +42, "[",                  1, 1, 0xe007, 0 },
   { NULL       , NULL       , "ALL",                3, 0, 0xc015, 0 }
};
static HB_PP_TOKEN s_cr059[ 28 ] = {
   { s_cr059 + 1, NULL       , "__ReportForm",      12, 1, 0xc015, 0 },
   { s_cr059 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr059 + 3, NULL       , "frm",                3, 1, 0xc00e, 1 },
   { s_cr059 + 4, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr059 + 5, NULL       , "prn",                3, 1, 0xc010, 2 },
   { s_cr059 + 6, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr059 + 7, NULL       , "f",                  1, 1, 0xc00e, 3 },
   { s_cr059 + 8, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr059 + 9, NULL       , "nocon",              5, 1, 0xc010, 4 },
   { s_cr059 +10, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr059 +11, NULL       , "for",                3, 1, 0xc00f, 5 },
   { s_cr059 +12, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr059 +13, NULL       , "while",              5, 1, 0xc00f, 6 },
   { s_cr059 +14, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr059 +15, NULL       , "next",               4, 1, 0xc00b, 7 },
   { s_cr059 +16, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr059 +17, NULL       , "rec",                3, 1, 0xc00b, 8 },
   { s_cr059 +18, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr059 +19, NULL       , "rest",               4, 1, 0xc010, 9 },
   { s_cr059 +20, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr059 +21, NULL       , "plain",              5, 1, 0xc010, 10 },
   { s_cr059 +22, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr059 +23, NULL       , "head",               4, 1, 0xc00b, 11 },
   { s_cr059 +24, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr059 +25, NULL       , "noej",               4, 1, 0xc010, 12 },
   { s_cr059 +26, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr059 +27, NULL       , "sum",                3, 1, 0xc010, 13 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm060[ 32 ] = {
   { s_cm060 + 1, NULL       , "DISPLAY",            7, 1, 0xc015, 0 },
   { s_cm060 + 4, s_cm060 + 2, "[",                  1, 1, 0xe007, 0 },
   { NULL       , s_cm060 + 3, "off",                3, 0, 0xc003, 1 },
   { NULL       , NULL       , "OFF",                3, 0, 0xc015, 0 },
   { s_cm060 + 8, s_cm060 + 5, "[",                  1, 1, 0xe007, 0 },
   { NULL       , s_cm060 + 6, "prn",                3, 0, 0xc003, 9 },
   { s_cm060 + 7, NULL       , "TO",                 2, 0, 0xc015, 0 },
   { NULL       , NULL       , "PRINTER",            7, 1, 0xc015, 0 },
   { s_cm060 +12, s_cm060 + 9, "[",                  1, 1, 0xe007, 0 },
   { s_cm060 +10, NULL       , "TO",                 2, 0, 0xc015, 0 },
   { s_cm060 +11, NULL       , "FILE",               4, 1, 0xc015, 0 },
   { NULL       , NULL       , "f",                  1, 0, 0xe005, 10 },
   { s_cm060 +15, s_cm060 +13, "[",                  1, 1, 0xe007, 0 },
   { s_cm060 +14, NULL       , "FOR",                3, 0, 0xc015, 0 },
   { NULL       , NULL       , "for",                3, 0, 0xe001, 4 },
   { s_cm060 +18, s_cm060 +16, "[",                  1, 1, 0xe007, 0 },
   { s_cm060 +17, NULL       , "WHILE",              5, 0, 0xc015, 0 },
   { NULL       , NULL       , "while",              5, 0, 0xe001, 5 },
   { s_cm060 +21, s_cm060 +19, "[",                  1, 1, 0xe007, 0 },
   { s_cm060 +20, NULL       , "NEXT",               4, 0, 0xc015, 0 },
   { NULL       , NULL       , "next",               4, 0, 0xe001, 6 },
   { s_cm060 +24, s_cm060 +22, "[",                  1, 1, 0xe007, 0 },
   { s_cm060 +23, NULL       , "RECORD",             6, 0, 0xc015, 0 },
   { NULL       , NULL       , "rec",                3, 0, 0xe001, 7 },
   { s_cm060 +27, s_cm060 +25, "[",                  1, 1, 0xe007, 0 },
   { NULL       , s_cm060 +26, "rest",               4, 0, 0xc003, 8 },
   { NULL       , NULL       , "REST",               4, 0, 0xc015, 0 },
   { s_cm060 +30, s_cm060 +28, "[",                  1, 1, 0xe007, 0 },
   { NULL       , s_cm060 +29, "all",                3, 0, 0xc003, 3 },
   { NULL       , NULL       , "ALL",                3, 0, 0xc015, 0 },
   { NULL       , s_cm060 +31, "[",                  1, 1, 0xe007, 0 },
   { NULL       , NULL       , "v",                  1, 0, 0xe002, 2 }
};
static HB_PP_TOKEN s_cr060[ 24 ] = {
   { s_cr060 + 1, NULL       , "__dbList",           8, 1, 0xc015, 0 },
   { s_cr060 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr060 + 3, NULL       , "off",                3, 1, 0xc010, 1 },
   { s_cr060 + 4, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr060 + 5, NULL       , "{",                  1, 1, 0xc036, 0 },
   { s_cr060 + 6, NULL       , "v",                  1, 1, 0xc00f, 2 },
   { s_cr060 + 7, NULL       , "}",                  1, 1, 0xc037, 0 },
   { s_cr060 + 8, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr060 + 9, NULL       , "all",                3, 1, 0xc010, 3 },
   { s_cr060 +10, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr060 +11, NULL       , "for",                3, 1, 0xc00f, 4 },
   { s_cr060 +12, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr060 +13, NULL       , "while",              5, 1, 0xc00f, 5 },
   { s_cr060 +14, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr060 +15, NULL       , "next",               4, 1, 0xc00b, 6 },
   { s_cr060 +16, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr060 +17, NULL       , "rec",                3, 1, 0xc00b, 7 },
   { s_cr060 +18, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr060 +19, NULL       , "rest",               4, 1, 0xc010, 8 },
   { s_cr060 +20, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr060 +21, NULL       , "prn",                3, 1, 0xc010, 9 },
   { s_cr060 +22, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr060 +23, NULL       , "f",                  1, 1, 0xc00e, 10 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm061[ 31 ] = {
   { s_cm061 + 1, NULL       , "LIST",               4, 1, 0xc015, 0 },
   { s_cm061 + 4, s_cm061 + 2, "[",                  1, 1, 0xe007, 0 },
   { NULL       , s_cm061 + 3, "off",                3, 0, 0xc003, 1 },
   { NULL       , NULL       , "OFF",                3, 0, 0xc015, 0 },
   { s_cm061 + 8, s_cm061 + 5, "[",                  1, 1, 0xe007, 0 },
   { NULL       , s_cm061 + 6, "prn",                3, 0, 0xc003, 8 },
   { s_cm061 + 7, NULL       , "TO",                 2, 0, 0xc015, 0 },
   { NULL       , NULL       , "PRINTER",            7, 1, 0xc015, 0 },
   { s_cm061 +12, s_cm061 + 9, "[",                  1, 1, 0xe007, 0 },
   { s_cm061 +10, NULL       , "TO",                 2, 0, 0xc015, 0 },
   { s_cm061 +11, NULL       , "FILE",               4, 1, 0xc015, 0 },
   { NULL       , NULL       , "f",                  1, 0, 0xe005, 9 },
   { s_cm061 +15, s_cm061 +13, "[",                  1, 1, 0xe007, 0 },
   { s_cm061 +14, NULL       , "FOR",                3, 0, 0xc015, 0 },
   { NULL       , NULL       , "for",                3, 0, 0xe001, 3 },
   { s_cm061 +18, s_cm061 +16, "[",                  1, 1, 0xe007, 0 },
   { s_cm061 +17, NULL       , "WHILE",              5, 0, 0xc015, 0 },
   { NULL       , NULL       , "while",              5, 0, 0xe001, 4 },
   { s_cm061 +21, s_cm061 +19, "[",                  1, 1, 0xe007, 0 },
   { s_cm061 +20, NULL       , "NEXT",               4, 0, 0xc015, 0 },
   { NULL       , NULL       , "next",               4, 0, 0xe001, 5 },
   { s_cm061 +24, s_cm061 +22, "[",                  1, 1, 0xe007, 0 },
   { s_cm061 +23, NULL       , "RECORD",             6, 0, 0xc015, 0 },
   { NULL       , NULL       , "rec",                3, 0, 0xe001, 6 },
   { s_cm061 +27, s_cm061 +25, "[",                  1, 1, 0xe007, 0 },
   { NULL       , s_cm061 +26, "rest",               4, 0, 0xc003, 7 },
   { NULL       , NULL       , "REST",               4, 0, 0xc015, 0 },
   { s_cm061 +29, s_cm061 +28, "[",                  1, 1, 0xe007, 0 },
   { NULL       , NULL       , "ALL",                3, 0, 0xc015, 0 },
   { NULL       , s_cm061 +30, "[",                  1, 1, 0xe007, 0 },
   { NULL       , NULL       , "v",                  1, 0, 0xe002, 2 }
};
static HB_PP_TOKEN s_cr061[ 24 ] = {
   { s_cr061 + 1, NULL       , "__dbList",           8, 1, 0xc015, 0 },
   { s_cr061 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr061 + 3, NULL       , "off",                3, 1, 0xc010, 1 },
   { s_cr061 + 4, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr061 + 5, NULL       , "{",                  1, 1, 0xc036, 0 },
   { s_cr061 + 6, NULL       , "v",                  1, 1, 0xc00f, 2 },
   { s_cr061 + 7, NULL       , "}",                  1, 1, 0xc037, 0 },
   { s_cr061 + 8, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr061 + 9, NULL       , ".T.",                3, 1, 0xc02c, 0 },
   { s_cr061 +10, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr061 +11, NULL       , "for",                3, 1, 0xc00f, 3 },
   { s_cr061 +12, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr061 +13, NULL       , "while",              5, 1, 0xc00f, 4 },
   { s_cr061 +14, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr061 +15, NULL       , "next",               4, 1, 0xc00b, 5 },
   { s_cr061 +16, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr061 +17, NULL       , "rec",                3, 1, 0xc00b, 6 },
   { s_cr061 +18, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr061 +19, NULL       , "rest",               4, 1, 0xc010, 7 },
   { s_cr061 +20, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr061 +21, NULL       , "prn",                3, 1, 0xc010, 8 },
   { s_cr061 +22, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr061 +23, NULL       , "f",                  1, 1, 0xc00e, 9 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm062[ 28 ] = {
   { s_cm062 + 1, NULL       , "AVERAGE",            7, 1, 0xc015, 0 },
   { s_cm062 +11, s_cm062 + 2, "[",                  1, 1, 0xe007, 0 },
   { s_cm062 + 3, NULL       , "x1",                 2, 0, 0xe001, 3 },
   { s_cm062 + 6, s_cm062 + 4, "[",                  1, 1, 0xe007, 0 },
   { s_cm062 + 5, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { NULL       , NULL       , "xN",                 2, 0, 0xe001, 4 },
   { s_cm062 + 7, NULL       , "TO",                 2, 2, 0xc015, 0 },
   { s_cm062 + 8, NULL       , "v1",                 2, 0, 0xe001, 1 },
   { NULL       , s_cm062 + 9, "[",                  1, 1, 0xe007, 0 },
   { s_cm062 +10, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { NULL       , NULL       , "vN",                 2, 0, 0xe001, 2 },
   { s_cm062 +14, s_cm062 +12, "[",                  1, 1, 0xe007, 0 },
   { s_cm062 +13, NULL       , "FOR",                3, 0, 0xc015, 0 },
   { NULL       , NULL       , "for",                3, 0, 0xe001, 5 },
   { s_cm062 +17, s_cm062 +15, "[",                  1, 1, 0xe007, 0 },
   { s_cm062 +16, NULL       , "WHILE",              5, 0, 0xc015, 0 },
   { NULL       , NULL       , "while",              5, 0, 0xe001, 6 },
   { s_cm062 +20, s_cm062 +18, "[",                  1, 1, 0xe007, 0 },
   { s_cm062 +19, NULL       , "NEXT",               4, 0, 0xc015, 0 },
   { NULL       , NULL       , "next",               4, 0, 0xe001, 7 },
   { s_cm062 +23, s_cm062 +21, "[",                  1, 1, 0xe007, 0 },
   { s_cm062 +22, NULL       , "RECORD",             6, 0, 0xc015, 0 },
   { NULL       , NULL       , "rec",                3, 0, 0xe001, 8 },
   { s_cm062 +26, s_cm062 +24, "[",                  1, 1, 0xe007, 0 },
   { NULL       , s_cm062 +25, "rest",               4, 0, 0xc003, 9 },
   { NULL       , NULL       , "REST",               4, 0, 0xc015, 0 },
   { NULL       , s_cm062 +27, "[",                  1, 1, 0xe007, 0 },
   { NULL       , NULL       , "ALL",                3, 0, 0xc015, 0 }
};
static HB_PP_TOKEN s_cr062[ 67 ] = {
   { s_cr062 + 1, NULL       , "M",                  1, 1, 0xc015, 0 },
   { s_cr062 + 2, NULL       , "->",                 2, 0, 0xc03b, 0 },
   { s_cr062 + 3, NULL       , "__Avg",              5, 0, 0xc015, 0 },
   { s_cr062 + 4, NULL       , ":=",                 2, 1, 0xc03c, 0 },
   { s_cr062 + 5, NULL       , "v1",                 2, 1, 0xc00b, 1 },
   { s_cr062 + 6, NULL       , ":=",                 2, 1, 0xc03c, 0 },
   { s_cr062 + 9, s_cr062 + 7, "[",                  1, 1, 0xc012, 0 },
   { s_cr062 + 8, NULL       , "vN",                 2, 1, 0xc00b, 2 },
   { NULL       , NULL       , ":=",                 2, 1, 0xc03c, 0 },
   { s_cr062 +10, NULL       , "0",                  1, 1, 0xc02a, 0 },
   { s_cr062 +11, NULL       , ";",                  1, 1, 0xc01e, 0 },
   { s_cr062 +12, NULL       , "DBEval",             6, 1, 0xc015, 0 },
   { s_cr062 +13, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr062 +14, NULL       , "{",                  1, 1, 0xc036, 0 },
   { s_cr062 +15, NULL       , "|",                  1, 0, 0xc01b, 0 },
   { s_cr062 +16, NULL       , "|",                  1, 0, 0xc01b, 0 },
   { s_cr062 +17, NULL       , "M",                  1, 1, 0xc015, 0 },
   { s_cr062 +18, NULL       , "->",                 2, 0, 0xc03b, 0 },
   { s_cr062 +19, NULL       , "__Avg",              5, 0, 0xc015, 0 },
   { s_cr062 +20, NULL       , ":=",                 2, 1, 0xc03c, 0 },
   { s_cr062 +21, NULL       , "M",                  1, 1, 0xc015, 0 },
   { s_cr062 +22, NULL       , "->",                 2, 0, 0xc03b, 0 },
   { s_cr062 +23, NULL       , "__Avg",              5, 0, 0xc015, 0 },
   { s_cr062 +24, NULL       , "+",                  1, 1, 0xc050, 0 },
   { s_cr062 +25, NULL       , "1",                  1, 1, 0xc02a, 0 },
   { s_cr062 +26, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr062 +27, NULL       , "v1",                 2, 1, 0xc00b, 1 },
   { s_cr062 +28, NULL       , ":=",                 2, 1, 0xc03c, 0 },
   { s_cr062 +29, NULL       , "v1",                 2, 1, 0xc00b, 1 },
   { s_cr062 +30, NULL       , "+",                  1, 1, 0xc050, 0 },
   { s_cr062 +31, NULL       , "x1",                 2, 1, 0xc00b, 3 },
   { s_cr062 +38, s_cr062 +32, "[",                  1, 1, 0xc012, 0 },
   { s_cr062 +33, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr062 +34, NULL       , "vN",                 2, 1, 0xc00b, 2 },
   { s_cr062 +35, NULL       , ":=",                 2, 1, 0xc03c, 0 },
   { s_cr062 +36, NULL       , "vN",                 2, 1, 0xc00b, 2 },
   { s_cr062 +37, NULL       , "+",                  1, 1, 0xc050, 0 },
   { NULL       , NULL       , "xN",                 2, 1, 0xc00b, 4 },
   { s_cr062 +39, NULL       , "}",                  1, 1, 0xc037, 0 },
   { s_cr062 +40, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr062 +41, NULL       , "for",                3, 1, 0xc00f, 5 },
   { s_cr062 +42, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr062 +43, NULL       , "while",              5, 1, 0xc00f, 6 },
   { s_cr062 +44, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr062 +45, NULL       , "next",               4, 1, 0xc00b, 7 },
   { s_cr062 +46, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr062 +47, NULL       , "rec",                3, 1, 0xc00b, 8 },
   { s_cr062 +48, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr062 +49, NULL       , "rest",               4, 1, 0xc010, 9 },
   { s_cr062 +50, NULL       , ")",                  1, 1, 0xc033, 0 },
   { s_cr062 +51, NULL       , ";",                  1, 1, 0xc01e, 0 },
   { s_cr062 +52, NULL       , "v1",                 2, 1, 0xc00b, 1 },
   { s_cr062 +53, NULL       , ":=",                 2, 1, 0xc03c, 0 },
   { s_cr062 +54, NULL       , "v1",                 2, 1, 0xc00b, 1 },
   { s_cr062 +55, NULL       , "/",                  1, 1, 0xc053, 0 },
   { s_cr062 +56, NULL       , "M",                  1, 1, 0xc015, 0 },
   { s_cr062 +57, NULL       , "->",                 2, 0, 0xc03b, 0 },
   { s_cr062 +58, NULL       , "__Avg",              5, 0, 0xc015, 0 },
   { NULL       , s_cr062 +59, "[",                  1, 1, 0xc012, 0 },
   { s_cr062 +60, NULL       , ";",                  1, 1, 0xc01e, 0 },
   { s_cr062 +61, NULL       , "vN",                 2, 1, 0xc00b, 2 },
   { s_cr062 +62, NULL       , ":=",                 2, 1, 0xc03c, 0 },
   { s_cr062 +63, NULL       , "vN",                 2, 1, 0xc00b, 2 },
   { s_cr062 +64, NULL       , "/",                  1, 1, 0xc053, 0 },
   { s_cr062 +65, NULL       , "M",                  1, 1, 0xc015, 0 },
   { s_cr062 +66, NULL       , "->",                 2, 0, 0xc03b, 0 },
   { NULL       , NULL       , "__Avg",              5, 0, 0xc015, 0 }
};
static HB_PP_TOKEN s_cm063[ 28 ] = {
   { s_cm063 + 1, NULL       , "SUM",                3, 1, 0xc015, 0 },
   { s_cm063 +11, s_cm063 + 2, "[",                  1, 1, 0xe007, 0 },
   { s_cm063 + 3, NULL       , "x1",                 2, 0, 0xe001, 3 },
   { s_cm063 + 6, s_cm063 + 4, "[",                  1, 1, 0xe007, 0 },
   { s_cm063 + 5, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { NULL       , NULL       , "xN",                 2, 0, 0xe001, 4 },
   { s_cm063 + 7, NULL       , "TO",                 2, 2, 0xc015, 0 },
   { s_cm063 + 8, NULL       , "v1",                 2, 0, 0xe001, 1 },
   { NULL       , s_cm063 + 9, "[",                  1, 1, 0xe007, 0 },
   { s_cm063 +10, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { NULL       , NULL       , "vN",                 2, 0, 0xe001, 2 },
   { s_cm063 +14, s_cm063 +12, "[",                  1, 1, 0xe007, 0 },
   { s_cm063 +13, NULL       , "FOR",                3, 0, 0xc015, 0 },
   { NULL       , NULL       , "for",                3, 0, 0xe001, 5 },
   { s_cm063 +17, s_cm063 +15, "[",                  1, 1, 0xe007, 0 },
   { s_cm063 +16, NULL       , "WHILE",              5, 0, 0xc015, 0 },
   { NULL       , NULL       , "while",              5, 0, 0xe001, 6 },
   { s_cm063 +20, s_cm063 +18, "[",                  1, 1, 0xe007, 0 },
   { s_cm063 +19, NULL       , "NEXT",               4, 0, 0xc015, 0 },
   { NULL       , NULL       , "next",               4, 0, 0xe001, 7 },
   { s_cm063 +23, s_cm063 +21, "[",                  1, 1, 0xe007, 0 },
   { s_cm063 +22, NULL       , "RECORD",             6, 0, 0xc015, 0 },
   { NULL       , NULL       , "rec",                3, 0, 0xe001, 8 },
   { s_cm063 +26, s_cm063 +24, "[",                  1, 1, 0xe007, 0 },
   { NULL       , s_cm063 +25, "rest",               4, 0, 0xc003, 9 },
   { NULL       , NULL       , "REST",               4, 0, 0xc015, 0 },
   { NULL       , s_cm063 +27, "[",                  1, 1, 0xe007, 0 },
   { NULL       , NULL       , "ALL",                3, 0, 0xc015, 0 }
};
static HB_PP_TOKEN s_cr063[ 36 ] = {
   { s_cr063 + 1, NULL       , "v1",                 2, 1, 0xc00b, 1 },
   { s_cr063 + 2, NULL       , ":=",                 2, 1, 0xc03c, 0 },
   { s_cr063 + 5, s_cr063 + 3, "[",                  1, 1, 0xc012, 0 },
   { s_cr063 + 4, NULL       , "vN",                 2, 1, 0xc00b, 2 },
   { NULL       , NULL       , ":=",                 2, 1, 0xc03c, 0 },
   { s_cr063 + 6, NULL       , "0",                  1, 1, 0xc02a, 0 },
   { s_cr063 + 7, NULL       , ";",                  1, 1, 0xc01e, 0 },
   { s_cr063 + 8, NULL       , "DBEval",             6, 1, 0xc015, 0 },
   { s_cr063 + 9, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr063 +10, NULL       , "{",                  1, 1, 0xc036, 0 },
   { s_cr063 +11, NULL       , "|",                  1, 0, 0xc01b, 0 },
   { s_cr063 +12, NULL       , "|",                  1, 0, 0xc01b, 0 },
   { s_cr063 +13, NULL       , "v1",                 2, 1, 0xc00b, 1 },
   { s_cr063 +14, NULL       , ":=",                 2, 1, 0xc03c, 0 },
   { s_cr063 +15, NULL       , "v1",                 2, 1, 0xc00b, 1 },
   { s_cr063 +16, NULL       , "+",                  1, 1, 0xc050, 0 },
   { s_cr063 +17, NULL       , "x1",                 2, 1, 0xc00b, 3 },
   { s_cr063 +24, s_cr063 +18, "[",                  1, 1, 0xc012, 0 },
   { s_cr063 +19, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr063 +20, NULL       , "vN",                 2, 1, 0xc00b, 2 },
   { s_cr063 +21, NULL       , ":=",                 2, 1, 0xc03c, 0 },
   { s_cr063 +22, NULL       , "vN",                 2, 1, 0xc00b, 2 },
   { s_cr063 +23, NULL       , "+",                  1, 1, 0xc050, 0 },
   { NULL       , NULL       , "xN",                 2, 1, 0xc00b, 4 },
   { s_cr063 +25, NULL       , "}",                  1, 0, 0xc037, 0 },
   { s_cr063 +26, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr063 +27, NULL       , "for",                3, 1, 0xc00f, 5 },
   { s_cr063 +28, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr063 +29, NULL       , "while",              5, 1, 0xc00f, 6 },
   { s_cr063 +30, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr063 +31, NULL       , "next",               4, 1, 0xc00b, 7 },
   { s_cr063 +32, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr063 +33, NULL       , "rec",                3, 1, 0xc00b, 8 },
   { s_cr063 +34, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr063 +35, NULL       , "rest",               4, 1, 0xc010, 9 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm064[ 21 ] = {
   { s_cm064 + 1, NULL       , "COUNT",              5, 1, 0xc015, 0 },
   { s_cm064 + 4, s_cm064 + 2, "[",                  1, 1, 0xe007, 0 },
   { s_cm064 + 3, NULL       , "TO",                 2, 0, 0xc015, 0 },
   { NULL       , NULL       , "v",                  1, 0, 0xe001, 1 },
   { s_cm064 + 7, s_cm064 + 5, "[",                  1, 1, 0xe007, 0 },
   { s_cm064 + 6, NULL       , "FOR",                3, 0, 0xc015, 0 },
   { NULL       , NULL       , "for",                3, 0, 0xe001, 2 },
   { s_cm064 +10, s_cm064 + 8, "[",                  1, 1, 0xe007, 0 },
   { s_cm064 + 9, NULL       , "WHILE",              5, 0, 0xc015, 0 },
   { NULL       , NULL       , "while",              5, 0, 0xe001, 3 },
   { s_cm064 +13, s_cm064 +11, "[",                  1, 1, 0xe007, 0 },
   { s_cm064 +12, NULL       , "NEXT",               4, 0, 0xc015, 0 },
   { NULL       , NULL       , "next",               4, 0, 0xe001, 4 },
   { s_cm064 +16, s_cm064 +14, "[",                  1, 1, 0xe007, 0 },
   { s_cm064 +15, NULL       , "RECORD",             6, 0, 0xc015, 0 },
   { NULL       , NULL       , "rec",                3, 0, 0xe001, 5 },
   { s_cm064 +19, s_cm064 +17, "[",                  1, 1, 0xe007, 0 },
   { NULL       , s_cm064 +18, "rest",               4, 0, 0xc003, 6 },
   { NULL       , NULL       , "REST",               4, 0, 0xc015, 0 },
   { NULL       , s_cm064 +20, "[",                  1, 1, 0xe007, 0 },
   { NULL       , NULL       , "ALL",                3, 0, 0xc015, 0 }
};
static HB_PP_TOKEN s_cr064[ 26 ] = {
   { s_cr064 + 1, NULL       , "v",                  1, 1, 0xc00b, 1 },
   { s_cr064 + 2, NULL       , ":=",                 2, 1, 0xc03c, 0 },
   { s_cr064 + 3, NULL       , "0",                  1, 1, 0xc02a, 0 },
   { s_cr064 + 4, NULL       , ";",                  1, 1, 0xc01e, 0 },
   { s_cr064 + 5, NULL       , "DBEval",             6, 1, 0xc015, 0 },
   { s_cr064 + 6, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr064 + 7, NULL       , "{",                  1, 1, 0xc036, 0 },
   { s_cr064 + 8, NULL       , "|",                  1, 0, 0xc01b, 0 },
   { s_cr064 + 9, NULL       , "|",                  1, 0, 0xc01b, 0 },
   { s_cr064 +10, NULL       , "v",                  1, 1, 0xc00b, 1 },
   { s_cr064 +11, NULL       , ":=",                 2, 1, 0xc03c, 0 },
   { s_cr064 +12, NULL       , "v",                  1, 1, 0xc00b, 1 },
   { s_cr064 +13, NULL       , "+",                  1, 1, 0xc050, 0 },
   { s_cr064 +14, NULL       , "1",                  1, 1, 0xc02a, 0 },
   { s_cr064 +15, NULL       , "}",                  1, 0, 0xc037, 0 },
   { s_cr064 +16, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr064 +17, NULL       , "for",                3, 1, 0xc00f, 2 },
   { s_cr064 +18, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr064 +19, NULL       , "while",              5, 1, 0xc00f, 3 },
   { s_cr064 +20, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr064 +21, NULL       , "next",               4, 1, 0xc00b, 4 },
   { s_cr064 +22, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr064 +23, NULL       , "rec",                3, 1, 0xc00b, 5 },
   { s_cr064 +24, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr064 +25, NULL       , "rest",               4, 1, 0xc010, 6 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm065[ 13 ] = {
   { s_cm065 + 1, NULL       , "JOIN",               4, 1, 0xc015, 0 },
   { s_cm065 + 4, s_cm065 + 2, "[",                  1, 1, 0xe007, 0 },
   { s_cm065 + 3, NULL       , "WITH",               4, 0, 0xc015, 0 },
   { NULL       , NULL       , "alias",              5, 0, 0xe005, 1 },
   { s_cm065 + 7, s_cm065 + 5, "[",                  1, 1, 0xe007, 0 },
   { s_cm065 + 6, NULL       , "TO",                 2, 0, 0xc015, 0 },
   { NULL       , NULL       , "f",                  1, 0, 0xe001, 2 },
   { s_cm065 +10, s_cm065 + 8, "[",                  1, 1, 0xe007, 0 },
   { s_cm065 + 9, NULL       , "FIELDS",             6, 0, 0xc015, 0 },
   { NULL       , NULL       , "fields",             6, 0, 0xe002, 3 },
   { NULL       , s_cm065 +11, "[",                  1, 1, 0xe007, 0 },
   { s_cm065 +12, NULL       , "FOR",                3, 0, 0xc015, 0 },
   { NULL       , NULL       , "for",                3, 0, 0xe001, 4 }
};
static HB_PP_TOKEN s_cr065[ 26 ] = {
   { s_cr065 + 1, NULL       , "__dbJoin",           8, 1, 0xc015, 0 },
   { s_cr065 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr065 + 3, NULL       , "alias",              5, 1, 0xc00e, 1 },
   { s_cr065 + 4, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr065 + 5, NULL       , "f",                  1, 1, 0xc00e, 2 },
   { s_cr065 + 6, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr065 + 7, NULL       , "{",                  1, 1, 0xc036, 0 },
   { s_cr065 + 8, NULL       , "fields",             6, 1, 0xc00e, 3 },
   { s_cr065 + 9, NULL       , "}",                  1, 1, 0xc037, 0 },
   { s_cr065 +10, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr065 +11, NULL       , "if",                 2, 1, 0xc015, 0 },
   { s_cr065 +12, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr065 +13, NULL       , "EMPTY",              5, 0, 0xc015, 0 },
   { s_cr065 +14, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr065 +15, NULL       , "for",                3, 0, 0xc00c, 4 },
   { s_cr065 +16, NULL       , ")",                  1, 0, 0xc033, 0 },
   { s_cr065 +17, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr065 +18, NULL       , "{",                  1, 1, 0xc036, 0 },
   { s_cr065 +19, NULL       , "|",                  1, 1, 0xc01b, 0 },
   { s_cr065 +20, NULL       , "|",                  1, 0, 0xc01b, 0 },
   { s_cr065 +21, NULL       , ".T.",                3, 1, 0xc02c, 0 },
   { s_cr065 +22, NULL       , "}",                  1, 1, 0xc037, 0 },
   { s_cr065 +23, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr065 +24, NULL       , "for",                3, 1, 0xc00f, 4 },
   { s_cr065 +25, NULL       , ")",                  1, 1, 0xc033, 0 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm066[ 20 ] = {
   { s_cm066 + 1, NULL       , "UPDATE",             6, 1, 0xc015, 0 },
   { s_cm066 + 4, s_cm066 + 2, "[",                  1, 1, 0xe007, 0 },
   { s_cm066 + 3, NULL       , "FROM",               4, 0, 0xc015, 0 },
   { NULL       , NULL       , "alias",              5, 0, 0xe005, 1 },
   { s_cm066 + 7, s_cm066 + 5, "[",                  1, 1, 0xe007, 0 },
   { s_cm066 + 6, NULL       , "ON",                 2, 0, 0xc015, 0 },
   { NULL       , NULL       , "key",                3, 0, 0xe001, 2 },
   { s_cm066 +10, s_cm066 + 8, "[",                  1, 1, 0xe007, 0 },
   { NULL       , s_cm066 + 9, "rand",               4, 0, 0xc003, 3 },
   { NULL       , NULL       , "RANDOM",             6, 0, 0xc015, 0 },
   { NULL       , s_cm066 +11, "[",                  1, 1, 0xe007, 0 },
   { s_cm066 +12, NULL       , "REPLACE",            7, 0, 0xc015, 0 },
   { s_cm066 +13, NULL       , "f1",                 2, 0, 0xe001, 4 },
   { s_cm066 +14, NULL       , "WITH",               4, 1, 0xc015, 0 },
   { s_cm066 +15, NULL       , "x1",                 2, 0, 0xe001, 5 },
   { NULL       , s_cm066 +16, "[",                  1, 1, 0xe007, 0 },
   { s_cm066 +17, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cm066 +18, NULL       , "fN",                 2, 0, 0xe001, 6 },
   { s_cm066 +19, NULL       , "WITH",               4, 1, 0xc015, 0 },
   { NULL       , NULL       , "xN",                 2, 0, 0xe001, 7 }
};
static HB_PP_TOKEN s_cr066[ 25 ] = {
   { s_cr066 + 1, NULL       , "__dbUpdate",        10, 1, 0xc015, 0 },
   { s_cr066 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr066 + 3, NULL       , "alias",              5, 1, 0xc00e, 1 },
   { s_cr066 + 4, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr066 + 5, NULL       , "key",                3, 1, 0xc00f, 2 },
   { s_cr066 + 6, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr066 + 7, NULL       , "rand",               4, 1, 0xc010, 3 },
   { s_cr066 + 8, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr066 + 9, NULL       , "{",                  1, 1, 0xc036, 0 },
   { s_cr066 +10, NULL       , "|",                  1, 0, 0xc01b, 0 },
   { s_cr066 +11, NULL       , "|",                  1, 0, 0xc01b, 0 },
   { s_cr066 +12, NULL       , "_FIELD",             6, 1, 0xc015, 0 },
   { s_cr066 +13, NULL       , "->",                 2, 0, 0xc03b, 0 },
   { s_cr066 +14, NULL       , "f1",                 2, 0, 0xc00b, 4 },
   { s_cr066 +15, NULL       , ":=",                 2, 1, 0xc03c, 0 },
   { s_cr066 +16, NULL       , "x1",                 2, 1, 0xc00b, 5 },
   { s_cr066 +23, s_cr066 +17, "[",                  1, 1, 0xc012, 0 },
   { s_cr066 +18, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr066 +19, NULL       , "_FIELD",             6, 1, 0xc015, 0 },
   { s_cr066 +20, NULL       , "->",                 2, 0, 0xc03b, 0 },
   { s_cr066 +21, NULL       , "fN",                 2, 0, 0xc00b, 6 },
   { s_cr066 +22, NULL       , ":=",                 2, 1, 0xc03c, 0 },
   { NULL       , NULL       , "xN",                 2, 1, 0xc00b, 7 },
   { s_cr066 +24, NULL       , "}",                  1, 0, 0xc037, 0 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm067[ 33 ] = {
   { s_cm067 + 1, NULL       , "TOTAL",              5, 1, 0xc015, 0 },
   { s_cm067 + 4, s_cm067 + 2, "[",                  1, 1, 0xe007, 0 },
   { s_cm067 + 3, NULL       , "TO",                 2, 0, 0xc015, 0 },
   { NULL       , NULL       , "f",                  1, 0, 0xe005, 1 },
   { s_cm067 + 7, s_cm067 + 5, "[",                  1, 1, 0xe007, 0 },
   { s_cm067 + 6, NULL       , "ON",                 2, 0, 0xc015, 0 },
   { NULL       , NULL       , "key",                3, 0, 0xe001, 2 },
   { s_cm067 +10, s_cm067 + 8, "[",                  1, 1, 0xe007, 0 },
   { s_cm067 + 9, NULL       , "FIELDS",             6, 0, 0xc015, 0 },
   { NULL       , NULL       , "fields",             6, 0, 0xe002, 3 },
   { s_cm067 +13, s_cm067 +11, "[",                  1, 1, 0xe007, 0 },
   { s_cm067 +12, NULL       , "FOR",                3, 0, 0xc015, 0 },
   { NULL       , NULL       , "for",                3, 0, 0xe001, 4 },
   { s_cm067 +16, s_cm067 +14, "[",                  1, 1, 0xe007, 0 },
   { s_cm067 +15, NULL       , "WHILE",              5, 0, 0xc015, 0 },
   { NULL       , NULL       , "while",              5, 0, 0xe001, 5 },
   { s_cm067 +19, s_cm067 +17, "[",                  1, 1, 0xe007, 0 },
   { s_cm067 +18, NULL       , "NEXT",               4, 0, 0xc015, 0 },
   { NULL       , NULL       , "next",               4, 0, 0xe001, 6 },
   { s_cm067 +22, s_cm067 +20, "[",                  1, 1, 0xe007, 0 },
   { s_cm067 +21, NULL       , "RECORD",             6, 0, 0xc015, 0 },
   { NULL       , NULL       , "rec",                3, 0, 0xe001, 7 },
   { s_cm067 +25, s_cm067 +23, "[",                  1, 1, 0xe007, 0 },
   { NULL       , s_cm067 +24, "rest",               4, 0, 0xc003, 8 },
   { NULL       , NULL       , "REST",               4, 0, 0xc015, 0 },
   { s_cm067 +27, s_cm067 +26, "[",                  1, 1, 0xe007, 0 },
   { NULL       , NULL       , "ALL",                3, 0, 0xc015, 0 },
   { s_cm067 +30, s_cm067 +28, "[",                  1, 1, 0xe007, 0 },
   { s_cm067 +29, NULL       , "CODEPAGE",           8, 0, 0xc015, 0 },
   { NULL       , NULL       , "cp",                 2, 0, 0xe001, 10 },
   { NULL       , s_cm067 +31, "[",                  1, 1, 0xe007, 0 },
   { s_cm067 +32, NULL       , "CONNECTION",        10, 0, 0xc015, 0 },
   { NULL       , NULL       , "conn",               4, 0, 0xe001, 9 }
};
static HB_PP_TOKEN s_cr067[ 24 ] = {
   { s_cr067 + 1, NULL       , "__dbTotal",          9, 1, 0xc015, 0 },
   { s_cr067 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr067 + 3, NULL       , "f",                  1, 1, 0xc00e, 1 },
   { s_cr067 + 4, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr067 + 5, NULL       , "key",                3, 1, 0xc00f, 2 },
   { s_cr067 + 6, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr067 + 7, NULL       , "{",                  1, 1, 0xc036, 0 },
   { s_cr067 + 8, NULL       , "fields",             6, 1, 0xc00e, 3 },
   { s_cr067 + 9, NULL       , "}",                  1, 1, 0xc037, 0 },
   { s_cr067 +10, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr067 +11, NULL       , "for",                3, 1, 0xc00f, 4 },
   { s_cr067 +12, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr067 +13, NULL       , "while",              5, 1, 0xc00f, 5 },
   { s_cr067 +14, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr067 +15, NULL       , "next",               4, 1, 0xc00b, 6 },
   { s_cr067 +16, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr067 +17, NULL       , "rec",                3, 1, 0xc00b, 7 },
   { s_cr067 +18, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr067 +19, NULL       , "rest",               4, 1, 0xc010, 8 },
   { s_cr067 +20, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr067 +21, NULL       , "conn",               4, 1, 0xc00b, 9 },
   { s_cr067 +22, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr067 +23, NULL       , "cp",                 2, 1, 0xc00b, 10 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm068[ 33 ] = {
   { s_cm068 + 1, NULL       , "SORT",               4, 1, 0xc015, 0 },
   { s_cm068 + 4, s_cm068 + 2, "[",                  1, 1, 0xe007, 0 },
   { s_cm068 + 3, NULL       , "TO",                 2, 0, 0xc015, 0 },
   { NULL       , NULL       , "f",                  1, 0, 0xe005, 1 },
   { s_cm068 + 7, s_cm068 + 5, "[",                  1, 1, 0xe007, 0 },
   { s_cm068 + 6, NULL       , "ON",                 2, 0, 0xc015, 0 },
   { NULL       , NULL       , "fields",             6, 0, 0xe002, 2 },
   { s_cm068 +10, s_cm068 + 8, "[",                  1, 1, 0xe007, 0 },
   { s_cm068 + 9, NULL       , "FOR",                3, 0, 0xc015, 0 },
   { NULL       , NULL       , "for",                3, 0, 0xe001, 3 },
   { s_cm068 +13, s_cm068 +11, "[",                  1, 1, 0xe007, 0 },
   { s_cm068 +12, NULL       , "WHILE",              5, 0, 0xc015, 0 },
   { NULL       , NULL       , "while",              5, 0, 0xe001, 4 },
   { s_cm068 +16, s_cm068 +14, "[",                  1, 1, 0xe007, 0 },
   { s_cm068 +15, NULL       , "NEXT",               4, 0, 0xc015, 0 },
   { NULL       , NULL       , "next",               4, 0, 0xe001, 5 },
   { s_cm068 +19, s_cm068 +17, "[",                  1, 1, 0xe007, 0 },
   { s_cm068 +18, NULL       , "RECORD",             6, 0, 0xc015, 0 },
   { NULL       , NULL       , "rec",                3, 0, 0xe001, 6 },
   { s_cm068 +22, s_cm068 +20, "[",                  1, 1, 0xe007, 0 },
   { NULL       , s_cm068 +21, "rest",               4, 0, 0xc003, 7 },
   { NULL       , NULL       , "REST",               4, 0, 0xc015, 0 },
   { s_cm068 +24, s_cm068 +23, "[",                  1, 1, 0xe007, 0 },
   { NULL       , NULL       , "ALL",                3, 0, 0xc015, 0 },
   { s_cm068 +27, s_cm068 +25, "[",                  1, 1, 0xe007, 0 },
   { s_cm068 +26, NULL       , "CODEPAGE",           8, 0, 0xc015, 0 },
   { NULL       , NULL       , "cp",                 2, 0, 0xe001, 10 },
   { s_cm068 +30, s_cm068 +28, "[",                  1, 1, 0xe007, 0 },
   { s_cm068 +29, NULL       , "CONNECTION",        10, 0, 0xc015, 0 },
   { NULL       , NULL       , "conn",               4, 0, 0xe001, 9 },
   { NULL       , s_cm068 +31, "[",                  1, 1, 0xe007, 0 },
   { s_cm068 +32, NULL       , "VIA",                3, 0, 0xc015, 0 },
   { NULL       , NULL       , "rdd",                3, 0, 0xe001, 8 }
};
static HB_PP_TOKEN s_cr068[ 24 ] = {
   { s_cr068 + 1, NULL       , "__dbSort",           8, 1, 0xc015, 0 },
   { s_cr068 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr068 + 3, NULL       , "f",                  1, 1, 0xc00e, 1 },
   { s_cr068 + 4, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr068 + 5, NULL       , "{",                  1, 1, 0xc036, 0 },
   { s_cr068 + 6, NULL       , "fields",             6, 1, 0xc00e, 2 },
   { s_cr068 + 7, NULL       , "}",                  1, 1, 0xc037, 0 },
   { s_cr068 + 8, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr068 + 9, NULL       , "for",                3, 1, 0xc00f, 3 },
   { s_cr068 +10, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr068 +11, NULL       , "while",              5, 1, 0xc00f, 4 },
   { s_cr068 +12, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr068 +13, NULL       , "next",               4, 1, 0xc00b, 5 },
   { s_cr068 +14, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr068 +15, NULL       , "rec",                3, 1, 0xc00b, 6 },
   { s_cr068 +16, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr068 +17, NULL       , "rest",               4, 1, 0xc010, 7 },
   { s_cr068 +18, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr068 +19, NULL       , "rdd",                3, 0, 0xc00b, 8 },
   { s_cr068 +20, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr068 +21, NULL       , "conn",               4, 1, 0xc00b, 9 },
   { s_cr068 +22, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr068 +23, NULL       , "cp",                 2, 1, 0xc00b, 10 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm069[ 33 ] = {
   { s_cm069 + 1, NULL       , "APPEND",             6, 1, 0xc015, 0 },
   { s_cm069 + 4, s_cm069 + 2, "[",                  1, 1, 0xe007, 0 },
   { s_cm069 + 3, NULL       , "FROM",               4, 0, 0xc015, 0 },
   { NULL       , NULL       , "f",                  1, 0, 0xe005, 1 },
   { s_cm069 + 7, s_cm069 + 5, "[",                  1, 1, 0xe007, 0 },
   { s_cm069 + 6, NULL       , "FIELDS",             6, 0, 0xc015, 0 },
   { NULL       , NULL       , "fields",             6, 0, 0xe002, 2 },
   { s_cm069 +10, s_cm069 + 8, "[",                  1, 1, 0xe007, 0 },
   { s_cm069 + 9, NULL       , "FOR",                3, 0, 0xc015, 0 },
   { NULL       , NULL       , "for",                3, 0, 0xe001, 3 },
   { s_cm069 +13, s_cm069 +11, "[",                  1, 1, 0xe007, 0 },
   { s_cm069 +12, NULL       , "WHILE",              5, 0, 0xc015, 0 },
   { NULL       , NULL       , "while",              5, 0, 0xe001, 4 },
   { s_cm069 +16, s_cm069 +14, "[",                  1, 1, 0xe007, 0 },
   { s_cm069 +15, NULL       , "NEXT",               4, 0, 0xc015, 0 },
   { NULL       , NULL       , "next",               4, 0, 0xe001, 5 },
   { s_cm069 +19, s_cm069 +17, "[",                  1, 1, 0xe007, 0 },
   { s_cm069 +18, NULL       , "RECORD",             6, 0, 0xc015, 0 },
   { NULL       , NULL       , "rec",                3, 0, 0xe001, 6 },
   { s_cm069 +22, s_cm069 +20, "[",                  1, 1, 0xe007, 0 },
   { NULL       , s_cm069 +21, "rest",               4, 0, 0xc003, 7 },
   { NULL       , NULL       , "REST",               4, 0, 0xc015, 0 },
   { s_cm069 +24, s_cm069 +23, "[",                  1, 1, 0xe007, 0 },
   { NULL       , NULL       , "ALL",                3, 0, 0xc015, 0 },
   { s_cm069 +27, s_cm069 +25, "[",                  1, 1, 0xe007, 0 },
   { s_cm069 +26, NULL       , "VIA",                3, 0, 0xc015, 0 },
   { NULL       , NULL       , "rdd",                3, 0, 0xe001, 8 },
   { s_cm069 +30, s_cm069 +28, "[",                  1, 1, 0xe007, 0 },
   { s_cm069 +29, NULL       , "CODEPAGE",           8, 0, 0xc015, 0 },
   { NULL       , NULL       , "cp",                 2, 0, 0xe001, 10 },
   { NULL       , s_cm069 +31, "[",                  1, 1, 0xe007, 0 },
   { s_cm069 +32, NULL       , "CONNECTION",        10, 0, 0xc015, 0 },
   { NULL       , NULL       , "conn",               4, 0, 0xe001, 9 }
};
static HB_PP_TOKEN s_cr069[ 24 ] = {
   { s_cr069 + 1, NULL       , "__dbApp",            7, 1, 0xc015, 0 },
   { s_cr069 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr069 + 3, NULL       , "f",                  1, 1, 0xc00e, 1 },
   { s_cr069 + 4, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr069 + 5, NULL       , "{",                  1, 1, 0xc036, 0 },
   { s_cr069 + 6, NULL       , "fields",             6, 1, 0xc00e, 2 },
   { s_cr069 + 7, NULL       , "}",                  1, 1, 0xc037, 0 },
   { s_cr069 + 8, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr069 + 9, NULL       , "for",                3, 1, 0xc00f, 3 },
   { s_cr069 +10, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr069 +11, NULL       , "while",              5, 1, 0xc00f, 4 },
   { s_cr069 +12, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr069 +13, NULL       , "next",               4, 1, 0xc00b, 5 },
   { s_cr069 +14, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr069 +15, NULL       , "rec",                3, 1, 0xc00b, 6 },
   { s_cr069 +16, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr069 +17, NULL       , "rest",               4, 1, 0xc010, 7 },
   { s_cr069 +18, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr069 +19, NULL       , "rdd",                3, 1, 0xc00b, 8 },
   { s_cr069 +20, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr069 +21, NULL       , "conn",               4, 1, 0xc00b, 9 },
   { s_cr069 +22, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr069 +23, NULL       , "cp",                 2, 1, 0xc00b, 10 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm070[ 29 ] = {
   { s_cm070 + 1, NULL       , "APPEND",             6, 1, 0xc015, 0 },
   { s_cm070 + 4, s_cm070 + 2, "[",                  1, 1, 0xe007, 0 },
   { s_cm070 + 3, NULL       , "FROM",               4, 0, 0xc015, 0 },
   { NULL       , NULL       , "f",                  1, 0, 0xe005, 1 },
   { s_cm070 + 6, s_cm070 + 5, "[",                  1, 1, 0xe007, 0 },
   { NULL       , NULL       , "SDF",                3, 0, 0xc015, 0 },
   { s_cm070 + 9, s_cm070 + 7, "[",                  1, 1, 0xe007, 0 },
   { s_cm070 + 8, NULL       , "FIELDS",             6, 0, 0xc015, 0 },
   { NULL       , NULL       , "fields",             6, 0, 0xe002, 2 },
   { s_cm070 +12, s_cm070 +10, "[",                  1, 1, 0xe007, 0 },
   { s_cm070 +11, NULL       , "FOR",                3, 0, 0xc015, 0 },
   { NULL       , NULL       , "for",                3, 0, 0xe001, 3 },
   { s_cm070 +15, s_cm070 +13, "[",                  1, 1, 0xe007, 0 },
   { s_cm070 +14, NULL       , "WHILE",              5, 0, 0xc015, 0 },
   { NULL       , NULL       , "while",              5, 0, 0xe001, 4 },
   { s_cm070 +18, s_cm070 +16, "[",                  1, 1, 0xe007, 0 },
   { s_cm070 +17, NULL       , "NEXT",               4, 0, 0xc015, 0 },
   { NULL       , NULL       , "next",               4, 0, 0xe001, 5 },
   { s_cm070 +21, s_cm070 +19, "[",                  1, 1, 0xe007, 0 },
   { s_cm070 +20, NULL       , "RECORD",             6, 0, 0xc015, 0 },
   { NULL       , NULL       , "rec",                3, 0, 0xe001, 6 },
   { s_cm070 +24, s_cm070 +22, "[",                  1, 1, 0xe007, 0 },
   { NULL       , s_cm070 +23, "rest",               4, 0, 0xc003, 7 },
   { NULL       , NULL       , "REST",               4, 0, 0xc015, 0 },
   { s_cm070 +26, s_cm070 +25, "[",                  1, 1, 0xe007, 0 },
   { NULL       , NULL       , "ALL",                3, 0, 0xc015, 0 },
   { NULL       , s_cm070 +27, "[",                  1, 1, 0xe007, 0 },
   { s_cm070 +28, NULL       , "CODEPAGE",           8, 0, 0xc015, 0 },
   { NULL       , NULL       , "cp",                 2, 0, 0xe001, 8 }
};
static HB_PP_TOKEN s_cr070[ 22 ] = {
   { s_cr070 + 1, NULL       , "__dbSDF",            7, 1, 0xc015, 0 },
   { s_cr070 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr070 + 3, NULL       , ".F.",                3, 1, 0xc02c, 0 },
   { s_cr070 + 4, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr070 + 5, NULL       , "f",                  1, 1, 0xc00e, 1 },
   { s_cr070 + 6, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr070 + 7, NULL       , "{",                  1, 1, 0xc036, 0 },
   { s_cr070 + 8, NULL       , "fields",             6, 1, 0xc00e, 2 },
   { s_cr070 + 9, NULL       , "}",                  1, 1, 0xc037, 0 },
   { s_cr070 +10, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr070 +11, NULL       , "for",                3, 1, 0xc00f, 3 },
   { s_cr070 +12, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr070 +13, NULL       , "while",              5, 1, 0xc00f, 4 },
   { s_cr070 +14, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr070 +15, NULL       , "next",               4, 1, 0xc00b, 5 },
   { s_cr070 +16, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr070 +17, NULL       , "rec",                3, 1, 0xc00b, 6 },
   { s_cr070 +18, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr070 +19, NULL       , "rest",               4, 1, 0xc010, 7 },
   { s_cr070 +20, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr070 +21, NULL       , "cp",                 2, 1, 0xc00b, 8 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm071[ 32 ] = {
   { s_cm071 + 1, NULL       , "APPEND",             6, 1, 0xc015, 0 },
   { s_cm071 + 4, s_cm071 + 2, "[",                  1, 1, 0xe007, 0 },
   { s_cm071 + 3, NULL       , "FROM",               4, 0, 0xc015, 0 },
   { NULL       , NULL       , "f",                  1, 0, 0xe005, 1 },
   { s_cm071 + 7, s_cm071 + 5, "[",                  1, 1, 0xe007, 0 },
   { s_cm071 + 6, NULL       , "FIELDS",             6, 0, 0xc015, 0 },
   { NULL       , NULL       , "fields",             6, 0, 0xe002, 3 },
   { s_cm071 +10, s_cm071 + 8, "[",                  1, 1, 0xe007, 0 },
   { s_cm071 + 9, NULL       , "FOR",                3, 0, 0xc015, 0 },
   { NULL       , NULL       , "for",                3, 0, 0xe001, 4 },
   { s_cm071 +13, s_cm071 +11, "[",                  1, 1, 0xe007, 0 },
   { s_cm071 +12, NULL       , "WHILE",              5, 0, 0xc015, 0 },
   { NULL       , NULL       , "while",              5, 0, 0xe001, 5 },
   { s_cm071 +16, s_cm071 +14, "[",                  1, 1, 0xe007, 0 },
   { s_cm071 +15, NULL       , "NEXT",               4, 0, 0xc015, 0 },
   { NULL       , NULL       , "next",               4, 0, 0xe001, 6 },
   { s_cm071 +19, s_cm071 +17, "[",                  1, 1, 0xe007, 0 },
   { s_cm071 +18, NULL       , "RECORD",             6, 0, 0xc015, 0 },
   { NULL       , NULL       , "rec",                3, 0, 0xe001, 7 },
   { s_cm071 +22, s_cm071 +20, "[",                  1, 1, 0xe007, 0 },
   { NULL       , s_cm071 +21, "rest",               4, 0, 0xc003, 8 },
   { NULL       , NULL       , "REST",               4, 0, 0xc015, 0 },
   { s_cm071 +24, s_cm071 +23, "[",                  1, 1, 0xe007, 0 },
   { NULL       , NULL       , "ALL",                3, 0, 0xc015, 0 },
   { s_cm071 +29, s_cm071 +25, "[",                  1, 1, 0xe007, 0 },
   { s_cm071 +26, NULL       , "DELIMITED",          9, 0, 0xc015, 0 },
   { NULL       , s_cm071 +27, "[",                  1, 1, 0xe007, 0 },
   { s_cm071 +28, NULL       , "WITH",               4, 0, 0xc015, 0 },
   { NULL       , NULL       , "delim",              5, 0, 0xe004, 2 },
   { NULL       , s_cm071 +30, "[",                  1, 1, 0xe007, 0 },
   { s_cm071 +31, NULL       , "CODEPAGE",           8, 0, 0xc015, 0 },
   { NULL       , NULL       , "cp",                 2, 0, 0xe001, 9 }
};
static HB_PP_TOKEN s_cr071[ 24 ] = {
   { s_cr071 + 1, NULL       , "__dbDelim",          9, 1, 0xc015, 0 },
   { s_cr071 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr071 + 3, NULL       , ".F.",                3, 1, 0xc02c, 0 },
   { s_cr071 + 4, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr071 + 5, NULL       , "f",                  1, 1, 0xc00e, 1 },
   { s_cr071 + 6, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr071 + 7, NULL       , "delim",              5, 1, 0xc00e, 2 },
   { s_cr071 + 8, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr071 + 9, NULL       , "{",                  1, 1, 0xc036, 0 },
   { s_cr071 +10, NULL       , "fields",             6, 1, 0xc00e, 3 },
   { s_cr071 +11, NULL       , "}",                  1, 1, 0xc037, 0 },
   { s_cr071 +12, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr071 +13, NULL       , "for",                3, 1, 0xc00f, 4 },
   { s_cr071 +14, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr071 +15, NULL       , "while",              5, 1, 0xc00f, 5 },
   { s_cr071 +16, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr071 +17, NULL       , "next",               4, 1, 0xc00b, 6 },
   { s_cr071 +18, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr071 +19, NULL       , "rec",                3, 1, 0xc00b, 7 },
   { s_cr071 +20, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr071 +21, NULL       , "rest",               4, 1, 0xc010, 8 },
   { s_cr071 +22, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr071 +23, NULL       , "cp",                 2, 1, 0xc00b, 9 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm072[ 33 ] = {
   { s_cm072 + 1, NULL       , "COPY",               4, 1, 0xc015, 0 },
   { s_cm072 + 4, s_cm072 + 2, "[",                  1, 1, 0xe007, 0 },
   { s_cm072 + 3, NULL       , "TO",                 2, 0, 0xc015, 0 },
   { NULL       , NULL       , "f",                  1, 0, 0xe005, 1 },
   { s_cm072 + 7, s_cm072 + 5, "[",                  1, 1, 0xe007, 0 },
   { s_cm072 + 6, NULL       , "FIELDS",             6, 0, 0xc015, 0 },
   { NULL       , NULL       , "fields",             6, 0, 0xe002, 2 },
   { s_cm072 +10, s_cm072 + 8, "[",                  1, 1, 0xe007, 0 },
   { s_cm072 + 9, NULL       , "FOR",                3, 0, 0xc015, 0 },
   { NULL       , NULL       , "for",                3, 0, 0xe001, 3 },
   { s_cm072 +13, s_cm072 +11, "[",                  1, 1, 0xe007, 0 },
   { s_cm072 +12, NULL       , "WHILE",              5, 0, 0xc015, 0 },
   { NULL       , NULL       , "while",              5, 0, 0xe001, 4 },
   { s_cm072 +16, s_cm072 +14, "[",                  1, 1, 0xe007, 0 },
   { s_cm072 +15, NULL       , "NEXT",               4, 0, 0xc015, 0 },
   { NULL       , NULL       , "next",               4, 0, 0xe001, 5 },
   { s_cm072 +19, s_cm072 +17, "[",                  1, 1, 0xe007, 0 },
   { s_cm072 +18, NULL       , "RECORD",             6, 0, 0xc015, 0 },
   { NULL       , NULL       , "rec",                3, 0, 0xe001, 6 },
   { s_cm072 +22, s_cm072 +20, "[",                  1, 1, 0xe007, 0 },
   { NULL       , s_cm072 +21, "rest",               4, 0, 0xc003, 7 },
   { NULL       , NULL       , "REST",               4, 0, 0xc015, 0 },
   { s_cm072 +24, s_cm072 +23, "[",                  1, 1, 0xe007, 0 },
   { NULL       , NULL       , "ALL",                3, 0, 0xc015, 0 },
   { s_cm072 +27, s_cm072 +25, "[",                  1, 1, 0xe007, 0 },
   { s_cm072 +26, NULL       , "VIA",                3, 0, 0xc015, 0 },
   { NULL       , NULL       , "rdd",                3, 0, 0xe001, 8 },
   { s_cm072 +30, s_cm072 +28, "[",                  1, 1, 0xe007, 0 },
   { s_cm072 +29, NULL       , "CODEPAGE",           8, 0, 0xc015, 0 },
   { NULL       , NULL       , "cp",                 2, 0, 0xe001, 10 },
   { NULL       , s_cm072 +31, "[",                  1, 1, 0xe007, 0 },
   { s_cm072 +32, NULL       , "CONNECTION",        10, 0, 0xc015, 0 },
   { NULL       , NULL       , "conn",               4, 0, 0xe001, 9 }
};
static HB_PP_TOKEN s_cr072[ 24 ] = {
   { s_cr072 + 1, NULL       , "__dbCopy",           8, 1, 0xc015, 0 },
   { s_cr072 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr072 + 3, NULL       , "f",                  1, 1, 0xc00e, 1 },
   { s_cr072 + 4, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr072 + 5, NULL       , "{",                  1, 1, 0xc036, 0 },
   { s_cr072 + 6, NULL       , "fields",             6, 1, 0xc00e, 2 },
   { s_cr072 + 7, NULL       , "}",                  1, 1, 0xc037, 0 },
   { s_cr072 + 8, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr072 + 9, NULL       , "for",                3, 1, 0xc00f, 3 },
   { s_cr072 +10, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr072 +11, NULL       , "while",              5, 1, 0xc00f, 4 },
   { s_cr072 +12, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr072 +13, NULL       , "next",               4, 1, 0xc00b, 5 },
   { s_cr072 +14, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr072 +15, NULL       , "rec",                3, 1, 0xc00b, 6 },
   { s_cr072 +16, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr072 +17, NULL       , "rest",               4, 1, 0xc010, 7 },
   { s_cr072 +18, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr072 +19, NULL       , "rdd",                3, 1, 0xc00b, 8 },
   { s_cr072 +20, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr072 +21, NULL       , "conn",               4, 1, 0xc00b, 9 },
   { s_cr072 +22, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr072 +23, NULL       , "cp",                 2, 1, 0xc00b, 10 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm073[ 29 ] = {
   { s_cm073 + 1, NULL       , "COPY",               4, 1, 0xc015, 0 },
   { s_cm073 + 4, s_cm073 + 2, "[",                  1, 1, 0xe007, 0 },
   { s_cm073 + 3, NULL       , "TO",                 2, 0, 0xc015, 0 },
   { NULL       , NULL       , "f",                  1, 0, 0xe005, 1 },
   { s_cm073 + 6, s_cm073 + 5, "[",                  1, 1, 0xe007, 0 },
   { NULL       , NULL       , "SDF",                3, 0, 0xc015, 0 },
   { s_cm073 + 9, s_cm073 + 7, "[",                  1, 1, 0xe007, 0 },
   { s_cm073 + 8, NULL       , "FIELDS",             6, 0, 0xc015, 0 },
   { NULL       , NULL       , "fields",             6, 0, 0xe002, 2 },
   { s_cm073 +12, s_cm073 +10, "[",                  1, 1, 0xe007, 0 },
   { s_cm073 +11, NULL       , "FOR",                3, 0, 0xc015, 0 },
   { NULL       , NULL       , "for",                3, 0, 0xe001, 3 },
   { s_cm073 +15, s_cm073 +13, "[",                  1, 1, 0xe007, 0 },
   { s_cm073 +14, NULL       , "WHILE",              5, 0, 0xc015, 0 },
   { NULL       , NULL       , "while",              5, 0, 0xe001, 4 },
   { s_cm073 +18, s_cm073 +16, "[",                  1, 1, 0xe007, 0 },
   { s_cm073 +17, NULL       , "NEXT",               4, 0, 0xc015, 0 },
   { NULL       , NULL       , "next",               4, 0, 0xe001, 5 },
   { s_cm073 +21, s_cm073 +19, "[",                  1, 1, 0xe007, 0 },
   { s_cm073 +20, NULL       , "RECORD",             6, 0, 0xc015, 0 },
   { NULL       , NULL       , "rec",                3, 0, 0xe001, 6 },
   { s_cm073 +24, s_cm073 +22, "[",                  1, 1, 0xe007, 0 },
   { NULL       , s_cm073 +23, "rest",               4, 0, 0xc003, 7 },
   { NULL       , NULL       , "REST",               4, 0, 0xc015, 0 },
   { s_cm073 +26, s_cm073 +25, "[",                  1, 1, 0xe007, 0 },
   { NULL       , NULL       , "ALL",                3, 0, 0xc015, 0 },
   { NULL       , s_cm073 +27, "[",                  1, 1, 0xe007, 0 },
   { s_cm073 +28, NULL       , "CODEPAGE",           8, 0, 0xc015, 0 },
   { NULL       , NULL       , "cp",                 2, 0, 0xe001, 8 }
};
static HB_PP_TOKEN s_cr073[ 22 ] = {
   { s_cr073 + 1, NULL       , "__dbSDF",            7, 1, 0xc015, 0 },
   { s_cr073 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr073 + 3, NULL       , ".T.",                3, 1, 0xc02c, 0 },
   { s_cr073 + 4, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr073 + 5, NULL       , "f",                  1, 1, 0xc00e, 1 },
   { s_cr073 + 6, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr073 + 7, NULL       , "{",                  1, 1, 0xc036, 0 },
   { s_cr073 + 8, NULL       , "fields",             6, 1, 0xc00e, 2 },
   { s_cr073 + 9, NULL       , "}",                  1, 1, 0xc037, 0 },
   { s_cr073 +10, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr073 +11, NULL       , "for",                3, 1, 0xc00f, 3 },
   { s_cr073 +12, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr073 +13, NULL       , "while",              5, 1, 0xc00f, 4 },
   { s_cr073 +14, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr073 +15, NULL       , "next",               4, 1, 0xc00b, 5 },
   { s_cr073 +16, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr073 +17, NULL       , "rec",                3, 1, 0xc00b, 6 },
   { s_cr073 +18, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr073 +19, NULL       , "rest",               4, 1, 0xc010, 7 },
   { s_cr073 +20, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr073 +21, NULL       , "cp",                 2, 1, 0xc00b, 8 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm074[ 32 ] = {
   { s_cm074 + 1, NULL       , "COPY",               4, 1, 0xc015, 0 },
   { s_cm074 + 4, s_cm074 + 2, "[",                  1, 1, 0xe007, 0 },
   { s_cm074 + 3, NULL       , "TO",                 2, 0, 0xc015, 0 },
   { NULL       , NULL       , "f",                  1, 0, 0xe005, 1 },
   { s_cm074 + 7, s_cm074 + 5, "[",                  1, 1, 0xe007, 0 },
   { s_cm074 + 6, NULL       , "FIELDS",             6, 0, 0xc015, 0 },
   { NULL       , NULL       , "fields",             6, 0, 0xe002, 3 },
   { s_cm074 +10, s_cm074 + 8, "[",                  1, 1, 0xe007, 0 },
   { s_cm074 + 9, NULL       , "FOR",                3, 0, 0xc015, 0 },
   { NULL       , NULL       , "for",                3, 0, 0xe001, 4 },
   { s_cm074 +13, s_cm074 +11, "[",                  1, 1, 0xe007, 0 },
   { s_cm074 +12, NULL       , "WHILE",              5, 0, 0xc015, 0 },
   { NULL       , NULL       , "while",              5, 0, 0xe001, 5 },
   { s_cm074 +16, s_cm074 +14, "[",                  1, 1, 0xe007, 0 },
   { s_cm074 +15, NULL       , "NEXT",               4, 0, 0xc015, 0 },
   { NULL       , NULL       , "next",               4, 0, 0xe001, 6 },
   { s_cm074 +19, s_cm074 +17, "[",                  1, 1, 0xe007, 0 },
   { s_cm074 +18, NULL       , "RECORD",             6, 0, 0xc015, 0 },
   { NULL       , NULL       , "rec",                3, 0, 0xe001, 7 },
   { s_cm074 +22, s_cm074 +20, "[",                  1, 1, 0xe007, 0 },
   { NULL       , s_cm074 +21, "rest",               4, 0, 0xc003, 8 },
   { NULL       , NULL       , "REST",               4, 0, 0xc015, 0 },
   { s_cm074 +24, s_cm074 +23, "[",                  1, 1, 0xe007, 0 },
   { NULL       , NULL       , "ALL",                3, 0, 0xc015, 0 },
   { s_cm074 +29, s_cm074 +25, "[",                  1, 1, 0xe007, 0 },
   { s_cm074 +26, NULL       , "DELIMITED",          9, 0, 0xc015, 0 },
   { NULL       , s_cm074 +27, "[",                  1, 1, 0xe007, 0 },
   { s_cm074 +28, NULL       , "WITH",               4, 0, 0xc015, 0 },
   { NULL       , NULL       , "delim",              5, 0, 0xe004, 2 },
   { NULL       , s_cm074 +30, "[",                  1, 1, 0xe007, 0 },
   { s_cm074 +31, NULL       , "CODEPAGE",           8, 0, 0xc015, 0 },
   { NULL       , NULL       , "cp",                 2, 0, 0xe001, 9 }
};
static HB_PP_TOKEN s_cr074[ 24 ] = {
   { s_cr074 + 1, NULL       , "__dbDelim",          9, 1, 0xc015, 0 },
   { s_cr074 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr074 + 3, NULL       , ".T.",                3, 1, 0xc02c, 0 },
   { s_cr074 + 4, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr074 + 5, NULL       , "f",                  1, 1, 0xc00e, 1 },
   { s_cr074 + 6, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr074 + 7, NULL       , "delim",              5, 1, 0xc00e, 2 },
   { s_cr074 + 8, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr074 + 9, NULL       , "{",                  1, 1, 0xc036, 0 },
   { s_cr074 +10, NULL       , "fields",             6, 1, 0xc00e, 3 },
   { s_cr074 +11, NULL       , "}",                  1, 1, 0xc037, 0 },
   { s_cr074 +12, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr074 +13, NULL       , "for",                3, 1, 0xc00f, 4 },
   { s_cr074 +14, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr074 +15, NULL       , "while",              5, 1, 0xc00f, 5 },
   { s_cr074 +16, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr074 +17, NULL       , "next",               4, 1, 0xc00b, 6 },
   { s_cr074 +18, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr074 +19, NULL       , "rec",                3, 1, 0xc00b, 7 },
   { s_cr074 +20, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr074 +21, NULL       , "rest",               4, 1, 0xc010, 8 },
   { s_cr074 +22, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr074 +23, NULL       , "cp",                 2, 1, 0xc00b, 9 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm075[ 9 ] = {
   { s_cm075 + 1, NULL       , "COPY",               4, 1, 0xc015, 0 },
   { s_cm075 + 3, s_cm075 + 2, "[",                  1, 1, 0xe007, 0 },
   { NULL       , NULL       , "STRUCTURE",          9, 0, 0xc015, 0 },
   { s_cm075 + 6, s_cm075 + 4, "[",                  1, 1, 0xe007, 0 },
   { s_cm075 + 5, NULL       , "TO",                 2, 0, 0xc015, 0 },
   { NULL       , NULL       , "f",                  1, 0, 0xe005, 1 },
   { NULL       , s_cm075 + 7, "[",                  1, 1, 0xe007, 0 },
   { s_cm075 + 8, NULL       , "FIELDS",             6, 0, 0xc015, 0 },
   { NULL       , NULL       , "fields",             6, 0, 0xe002, 2 }
};
static HB_PP_TOKEN s_cr075[ 8 ] = {
   { s_cr075 + 1, NULL       , "__dbCopyStruct",    14, 1, 0xc015, 0 },
   { s_cr075 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr075 + 3, NULL       , "f",                  1, 1, 0xc00e, 1 },
   { s_cr075 + 4, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr075 + 5, NULL       , "{",                  1, 1, 0xc036, 0 },
   { s_cr075 + 6, NULL       , "fields",             6, 1, 0xc00e, 2 },
   { s_cr075 + 7, NULL       , "}",                  1, 1, 0xc037, 0 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm076[ 8 ] = {
   { s_cm076 + 1, NULL       , "COPY",               4, 1, 0xc015, 0 },
   { s_cm076 + 3, s_cm076 + 2, "[",                  1, 1, 0xe007, 0 },
   { NULL       , NULL       , "STRUCTURE",          9, 0, 0xc015, 0 },
   { s_cm076 + 5, s_cm076 + 4, "[",                  1, 1, 0xe007, 0 },
   { NULL       , NULL       , "EXTENDED",           8, 0, 0xc015, 0 },
   { NULL       , s_cm076 + 6, "[",                  1, 1, 0xe007, 0 },
   { s_cm076 + 7, NULL       , "TO",                 2, 0, 0xc015, 0 },
   { NULL       , NULL       , "f",                  1, 0, 0xe005, 1 }
};
static HB_PP_TOKEN s_cr076[ 4 ] = {
   { s_cr076 + 1, NULL       , "__dbCopyXStruct",   15, 1, 0xc015, 0 },
   { s_cr076 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr076 + 3, NULL       , "f",                  1, 1, 0xc00e, 1 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm077[ 20 ] = {
   { s_cm077 + 1, NULL       , "CREATE",             6, 1, 0xc015, 0 },
   { s_cm077 + 2, NULL       , "db",                 2, 0, 0xe005, 1 },
   { s_cm077 + 5, s_cm077 + 3, "[",                  1, 1, 0xe007, 0 },
   { s_cm077 + 4, NULL       , "FROM",               4, 0, 0xc015, 0 },
   { NULL       , NULL       , "src",                3, 0, 0xe005, 2 },
   { s_cm077 + 8, s_cm077 + 6, "[",                  1, 1, 0xe007, 0 },
   { s_cm077 + 7, NULL       , "VIA",                3, 0, 0xc015, 0 },
   { NULL       , NULL       , "rdd",                3, 0, 0xe001, 3 },
   { s_cm077 +11, s_cm077 + 9, "[",                  1, 1, 0xe007, 0 },
   { s_cm077 +10, NULL       , "ALIAS",              5, 0, 0xc015, 0 },
   { NULL       , NULL       , "a",                  1, 0, 0xe001, 5 },
   { s_cm077 +14, s_cm077 +12, "[",                  1, 1, 0xe007, 0 },
   { NULL       , s_cm077 +13, "new",                3, 0, 0xc003, 4 },
   { NULL       , NULL       , "NEW",                3, 1, 0xc015, 0 },
   { s_cm077 +17, s_cm077 +15, "[",                  1, 1, 0xe007, 0 },
   { s_cm077 +16, NULL       , "CODEPAGE",           8, 0, 0xc015, 0 },
   { NULL       , NULL       , "cp",                 2, 0, 0xe001, 6 },
   { NULL       , s_cm077 +18, "[",                  1, 1, 0xe007, 0 },
   { s_cm077 +19, NULL       , "CONNECTION",        10, 0, 0xc015, 0 },
   { NULL       , NULL       , "conn",               4, 0, 0xe001, 7 }
};
static HB_PP_TOKEN s_cr077[ 16 ] = {
   { s_cr077 + 1, NULL       , "__dbCreate",        10, 1, 0xc015, 0 },
   { s_cr077 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr077 + 3, NULL       , "db",                 2, 1, 0xc00e, 1 },
   { s_cr077 + 4, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr077 + 5, NULL       , "src",                3, 1, 0xc00e, 2 },
   { s_cr077 + 6, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr077 + 7, NULL       , "rdd",                3, 1, 0xc00b, 3 },
   { s_cr077 + 8, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr077 + 9, NULL       , "new",                3, 1, 0xc010, 4 },
   { s_cr077 +10, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr077 +11, NULL       , "a",                  1, 1, 0xc00e, 5 },
   { s_cr077 +12, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr077 +13, NULL       , "cp",                 2, 1, 0xc00b, 6 },
   { s_cr077 +14, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr077 +15, NULL       , "conn",               4, 1, 0xc00b, 7 },
   { NULL       , NULL       , ")",                  1, 0, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm078[ 1 ] = {
   { NULL       , NULL       , "RECALL",             6, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_cr078[ 3 ] = {
   { s_cr078 + 1, NULL       , "dbRecall",           8, 1, 0xc015, 0 },
   { s_cr078 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { NULL       , NULL       , ")",                  1, 0, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm079[ 18 ] = {
   { s_cm079 + 1, NULL       , "RECALL",             6, 1, 0xc015, 0 },
   { s_cm079 + 4, s_cm079 + 2, "[",                  1, 1, 0xe007, 0 },
   { s_cm079 + 3, NULL       , "FOR",                3, 0, 0xc015, 0 },
   { NULL       , NULL       , "for",                3, 0, 0xe001, 1 },
   { s_cm079 + 7, s_cm079 + 5, "[",                  1, 1, 0xe007, 0 },
   { s_cm079 + 6, NULL       , "WHILE",              5, 0, 0xc015, 0 },
   { NULL       , NULL       , "while",              5, 0, 0xe001, 2 },
   { s_cm079 +10, s_cm079 + 8, "[",                  1, 1, 0xe007, 0 },
   { s_cm079 + 9, NULL       , "NEXT",               4, 0, 0xc015, 0 },
   { NULL       , NULL       , "next",               4, 0, 0xe001, 3 },
   { s_cm079 +13, s_cm079 +11, "[",                  1, 1, 0xe007, 0 },
   { s_cm079 +12, NULL       , "RECORD",             6, 0, 0xc015, 0 },
   { NULL       , NULL       , "rec",                3, 0, 0xe001, 4 },
   { s_cm079 +16, s_cm079 +14, "[",                  1, 1, 0xe007, 0 },
   { NULL       , s_cm079 +15, "rest",               4, 0, 0xc003, 5 },
   { NULL       , NULL       , "REST",               4, 0, 0xc015, 0 },
   { NULL       , s_cm079 +17, "[",                  1, 1, 0xe007, 0 },
   { NULL       , NULL       , "ALL",                3, 0, 0xc015, 0 }
};
static HB_PP_TOKEN s_cr079[ 20 ] = {
   { s_cr079 + 1, NULL       , "DBEval",             6, 1, 0xc015, 0 },
   { s_cr079 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr079 + 3, NULL       , "{",                  1, 1, 0xc036, 0 },
   { s_cr079 + 4, NULL       , "|",                  1, 0, 0xc01b, 0 },
   { s_cr079 + 5, NULL       , "|",                  1, 0, 0xc01b, 0 },
   { s_cr079 + 6, NULL       , "dbRecall",           8, 1, 0xc015, 0 },
   { s_cr079 + 7, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr079 + 8, NULL       , ")",                  1, 0, 0xc033, 0 },
   { s_cr079 + 9, NULL       , "}",                  1, 0, 0xc037, 0 },
   { s_cr079 +10, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr079 +11, NULL       , "for",                3, 1, 0xc00f, 1 },
   { s_cr079 +12, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr079 +13, NULL       , "while",              5, 1, 0xc00f, 2 },
   { s_cr079 +14, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr079 +15, NULL       , "next",               4, 1, 0xc00b, 3 },
   { s_cr079 +16, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr079 +17, NULL       , "rec",                3, 1, 0xc00b, 4 },
   { s_cr079 +18, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr079 +19, NULL       , "rest",               4, 1, 0xc010, 5 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm080[ 1 ] = {
   { NULL       , NULL       , "DELETE",             6, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_cr080[ 3 ] = {
   { s_cr080 + 1, NULL       , "dbDelete",           8, 1, 0xc015, 0 },
   { s_cr080 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { NULL       , NULL       , ")",                  1, 0, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm081[ 18 ] = {
   { s_cm081 + 1, NULL       , "DELETE",             6, 1, 0xc015, 0 },
   { s_cm081 + 4, s_cm081 + 2, "[",                  1, 1, 0xe007, 0 },
   { s_cm081 + 3, NULL       , "FOR",                3, 0, 0xc015, 0 },
   { NULL       , NULL       , "for",                3, 0, 0xe001, 1 },
   { s_cm081 + 7, s_cm081 + 5, "[",                  1, 1, 0xe007, 0 },
   { s_cm081 + 6, NULL       , "WHILE",              5, 0, 0xc015, 0 },
   { NULL       , NULL       , "while",              5, 0, 0xe001, 2 },
   { s_cm081 +10, s_cm081 + 8, "[",                  1, 1, 0xe007, 0 },
   { s_cm081 + 9, NULL       , "NEXT",               4, 0, 0xc015, 0 },
   { NULL       , NULL       , "next",               4, 0, 0xe001, 3 },
   { s_cm081 +13, s_cm081 +11, "[",                  1, 1, 0xe007, 0 },
   { s_cm081 +12, NULL       , "RECORD",             6, 0, 0xc015, 0 },
   { NULL       , NULL       , "rec",                3, 0, 0xe001, 4 },
   { s_cm081 +16, s_cm081 +14, "[",                  1, 1, 0xe007, 0 },
   { NULL       , s_cm081 +15, "rest",               4, 0, 0xc003, 5 },
   { NULL       , NULL       , "REST",               4, 0, 0xc015, 0 },
   { NULL       , s_cm081 +17, "[",                  1, 1, 0xe007, 0 },
   { NULL       , NULL       , "ALL",                3, 0, 0xc015, 0 }
};
static HB_PP_TOKEN s_cr081[ 20 ] = {
   { s_cr081 + 1, NULL       , "DBEval",             6, 1, 0xc015, 0 },
   { s_cr081 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr081 + 3, NULL       , "{",                  1, 1, 0xc036, 0 },
   { s_cr081 + 4, NULL       , "|",                  1, 0, 0xc01b, 0 },
   { s_cr081 + 5, NULL       , "|",                  1, 0, 0xc01b, 0 },
   { s_cr081 + 6, NULL       , "dbDelete",           8, 1, 0xc015, 0 },
   { s_cr081 + 7, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr081 + 8, NULL       , ")",                  1, 0, 0xc033, 0 },
   { s_cr081 + 9, NULL       , "}",                  1, 0, 0xc037, 0 },
   { s_cr081 +10, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr081 +11, NULL       , "for",                3, 1, 0xc00f, 1 },
   { s_cr081 +12, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr081 +13, NULL       , "while",              5, 1, 0xc00f, 2 },
   { s_cr081 +14, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr081 +15, NULL       , "next",               4, 1, 0xc00b, 3 },
   { s_cr081 +16, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr081 +17, NULL       , "rec",                3, 1, 0xc00b, 4 },
   { s_cr081 +18, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr081 +19, NULL       , "rest",               4, 1, 0xc010, 5 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm082[ 9 ] = {
   { s_cm082 + 1, NULL       , "REPLACE",            7, 1, 0xc015, 0 },
   { s_cm082 + 2, NULL       , "f1",                 2, 0, 0xe001, 1 },
   { s_cm082 + 3, NULL       , "WITH",               4, 1, 0xc015, 0 },
   { s_cm082 + 4, NULL       , "v1",                 2, 0, 0xe001, 2 },
   { NULL       , s_cm082 + 5, "[",                  1, 1, 0xe007, 0 },
   { s_cm082 + 6, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cm082 + 7, NULL       , "fN",                 2, 0, 0xe001, 3 },
   { s_cm082 + 8, NULL       , "WITH",               4, 1, 0xc015, 0 },
   { NULL       , NULL       , "vN",                 2, 0, 0xe001, 4 }
};
static HB_PP_TOKEN s_cr082[ 12 ] = {
   { s_cr082 + 1, NULL       , "_FIELD",             6, 1, 0xc015, 0 },
   { s_cr082 + 2, NULL       , "->",                 2, 0, 0xc03b, 0 },
   { s_cr082 + 3, NULL       , "f1",                 2, 0, 0xc00b, 1 },
   { s_cr082 + 4, NULL       , ":=",                 2, 1, 0xc03c, 0 },
   { s_cr082 + 5, NULL       , "v1",                 2, 1, 0xc00b, 2 },
   { NULL       , s_cr082 + 6, "[",                  1, 1, 0xc012, 0 },
   { s_cr082 + 7, NULL       , ";",                  1, 1, 0xc01e, 0 },
   { s_cr082 + 8, NULL       , "_FIELD",             6, 1, 0xc015, 0 },
   { s_cr082 + 9, NULL       , "->",                 2, 0, 0xc03b, 0 },
   { s_cr082 +10, NULL       , "fN",                 2, 0, 0xc00b, 3 },
   { s_cr082 +11, NULL       , ":=",                 2, 1, 0xc03c, 0 },
   { NULL       , NULL       , "vN",                 2, 1, 0xc00b, 4 }
};
static HB_PP_TOKEN s_cm083[ 27 ] = {
   { s_cm083 + 1, NULL       , "REPLACE",            7, 1, 0xc015, 0 },
   { s_cm083 +10, s_cm083 + 2, "[",                  1, 1, 0xe007, 0 },
   { s_cm083 + 3, NULL       , "f1",                 2, 0, 0xe001, 1 },
   { s_cm083 + 4, NULL       , "WITH",               4, 1, 0xc015, 0 },
   { s_cm083 + 5, NULL       , "x1",                 2, 0, 0xe001, 2 },
   { NULL       , s_cm083 + 6, "[",                  1, 1, 0xe007, 0 },
   { s_cm083 + 7, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cm083 + 8, NULL       , "fN",                 2, 0, 0xe001, 3 },
   { s_cm083 + 9, NULL       , "WITH",               4, 1, 0xc015, 0 },
   { NULL       , NULL       , "xN",                 2, 0, 0xe001, 4 },
   { s_cm083 +13, s_cm083 +11, "[",                  1, 1, 0xe007, 0 },
   { s_cm083 +12, NULL       , "FOR",                3, 0, 0xc015, 0 },
   { NULL       , NULL       , "for",                3, 0, 0xe001, 5 },
   { s_cm083 +16, s_cm083 +14, "[",                  1, 1, 0xe007, 0 },
   { s_cm083 +15, NULL       , "WHILE",              5, 0, 0xc015, 0 },
   { NULL       , NULL       , "while",              5, 0, 0xe001, 6 },
   { s_cm083 +19, s_cm083 +17, "[",                  1, 1, 0xe007, 0 },
   { s_cm083 +18, NULL       , "NEXT",               4, 0, 0xc015, 0 },
   { NULL       , NULL       , "next",               4, 0, 0xe001, 7 },
   { s_cm083 +22, s_cm083 +20, "[",                  1, 1, 0xe007, 0 },
   { s_cm083 +21, NULL       , "RECORD",             6, 0, 0xc015, 0 },
   { NULL       , NULL       , "rec",                3, 0, 0xe001, 8 },
   { s_cm083 +25, s_cm083 +23, "[",                  1, 1, 0xe007, 0 },
   { NULL       , s_cm083 +24, "rest",               4, 0, 0xc003, 9 },
   { NULL       , NULL       , "REST",               4, 0, 0xc015, 0 },
   { NULL       , s_cm083 +26, "[",                  1, 1, 0xe007, 0 },
   { NULL       , NULL       , "ALL",                3, 0, 0xc015, 0 }
};
static HB_PP_TOKEN s_cr083[ 29 ] = {
   { s_cr083 + 1, NULL       , "DBEval",             6, 1, 0xc015, 0 },
   { s_cr083 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr083 + 3, NULL       , "{",                  1, 1, 0xc036, 0 },
   { s_cr083 + 4, NULL       , "|",                  1, 0, 0xc01b, 0 },
   { s_cr083 + 5, NULL       , "|",                  1, 0, 0xc01b, 0 },
   { s_cr083 + 6, NULL       , "_FIELD",             6, 1, 0xc015, 0 },
   { s_cr083 + 7, NULL       , "->",                 2, 0, 0xc03b, 0 },
   { s_cr083 + 8, NULL       , "f1",                 2, 0, 0xc00b, 1 },
   { s_cr083 + 9, NULL       , ":=",                 2, 1, 0xc03c, 0 },
   { s_cr083 +10, NULL       , "x1",                 2, 1, 0xc00b, 2 },
   { s_cr083 +17, s_cr083 +11, "[",                  1, 1, 0xc012, 0 },
   { s_cr083 +12, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr083 +13, NULL       , "_FIELD",             6, 1, 0xc015, 0 },
   { s_cr083 +14, NULL       , "->",                 2, 0, 0xc03b, 0 },
   { s_cr083 +15, NULL       , "fN",                 2, 0, 0xc00b, 3 },
   { s_cr083 +16, NULL       , ":=",                 2, 1, 0xc03c, 0 },
   { NULL       , NULL       , "xN",                 2, 1, 0xc00b, 4 },
   { s_cr083 +18, NULL       , "}",                  1, 0, 0xc037, 0 },
   { s_cr083 +19, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr083 +20, NULL       , "for",                3, 1, 0xc00f, 5 },
   { s_cr083 +21, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr083 +22, NULL       , "while",              5, 1, 0xc00f, 6 },
   { s_cr083 +23, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr083 +24, NULL       , "next",               4, 1, 0xc00b, 7 },
   { s_cr083 +25, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr083 +26, NULL       , "rec",                3, 1, 0xc00b, 8 },
   { s_cr083 +27, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr083 +28, NULL       , "rest",               4, 1, 0xc010, 9 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm084[ 5 ] = {
   { s_cm084 + 1, NULL       , "SET",                3, 1, 0xc015, 0 },
   { s_cm084 + 2, NULL       , "FILTER",             6, 1, 0xc015, 0 },
   { s_cm084 + 3, NULL       , "TO",                 2, 1, 0xc015, 0 },
   { NULL       , s_cm084 + 4, "x",                  1, 0, 0xc003, 1 },
   { NULL       , NULL       , "&",                  1, 0, 0xc039, 0 }
};
static HB_PP_TOKEN s_cr084[ 22 ] = {
   { s_cr084 + 1, NULL       , "if",                 2, 1, 0xc015, 0 },
   { s_cr084 + 2, NULL       , "(",                  1, 1, 0xc032, 0 },
   { s_cr084 + 3, NULL       , "Empty",              5, 1, 0xc015, 0 },
   { s_cr084 + 4, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr084 + 5, NULL       , "x",                  1, 0, 0xc00e, 1 },
   { s_cr084 + 6, NULL       , ")",                  1, 0, 0xc033, 0 },
   { s_cr084 + 7, NULL       , ")",                  1, 1, 0xc033, 0 },
   { s_cr084 + 8, NULL       , ";",                  1, 1, 0xc01e, 0 },
   { s_cr084 + 9, NULL       , "dbClearFilter",     13, 1, 0xc015, 0 },
   { s_cr084 +10, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr084 +11, NULL       , ")",                  1, 0, 0xc033, 0 },
   { s_cr084 +12, NULL       , ";",                  1, 1, 0xc01e, 0 },
   { s_cr084 +13, NULL       , "else",               4, 1, 0xc015, 0 },
   { s_cr084 +14, NULL       , ";",                  1, 1, 0xc01e, 0 },
   { s_cr084 +15, NULL       , "dbSetFilter",       11, 1, 0xc015, 0 },
   { s_cr084 +16, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr084 +17, NULL       , "x",                  1, 1, 0xc00f, 1 },
   { s_cr084 +18, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr084 +19, NULL       , "x",                  1, 1, 0xc00e, 1 },
   { s_cr084 +20, NULL       , ")",                  1, 1, 0xc033, 0 },
   { s_cr084 +21, NULL       , ";",                  1, 1, 0xc01e, 0 },
   { NULL       , NULL       , "end",                3, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_cm085[ 4 ] = {
   { s_cm085 + 1, NULL       , "SET",                3, 1, 0xc015, 0 },
   { s_cm085 + 2, NULL       , "FILTER",             6, 1, 0xc015, 0 },
   { s_cm085 + 3, NULL       , "TO",                 2, 1, 0xc015, 0 },
   { NULL       , NULL       , "exp",                3, 0, 0xe001, 1 }
};
static HB_PP_TOKEN s_cr085[ 6 ] = {
   { s_cr085 + 1, NULL       , "dbSetFilter",       11, 1, 0xc015, 0 },
   { s_cr085 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr085 + 3, NULL       , "exp",                3, 1, 0xc00f, 1 },
   { s_cr085 + 4, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr085 + 5, NULL       , "exp",                3, 1, 0xc00d, 1 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm086[ 3 ] = {
   { s_cm086 + 1, NULL       , "SET",                3, 1, 0xc015, 0 },
   { s_cm086 + 2, NULL       , "FILTER",             6, 1, 0xc015, 0 },
   { NULL       , NULL       , "TO",                 2, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_cr086[ 4 ] = {
   { s_cr086 + 1, NULL       , "dbClearFilter",     13, 1, 0xc015, 0 },
   { s_cr086 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr086 + 3, NULL       , "NIL",                3, 0, 0xc015, 0 },
   { NULL       , NULL       , ")",                  1, 0, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm087[ 23 ] = {
   { s_cm087 + 1, NULL       , "SET",                3, 1, 0xc015, 0 },
   { s_cm087 + 2, NULL       , "RELATION",           8, 1, 0xc015, 0 },
   { s_cm087 + 5, s_cm087 + 3, "[",                  1, 1, 0xe007, 0 },
   { NULL       , s_cm087 + 4, "add",                3, 0, 0xc003, 1 },
   { NULL       , NULL       , "ADDITIVE",           8, 0, 0xc015, 0 },
   { NULL       , s_cm087 + 6, "[",                  1, 1, 0xe007, 0 },
   { s_cm087 + 7, NULL       , "TO",                 2, 0, 0xc015, 0 },
   { s_cm087 + 8, NULL       , "exp1",               4, 0, 0xe001, 3 },
   { s_cm087 + 9, NULL       , "INTO",               4, 1, 0xc015, 0 },
   { s_cm087 +10, NULL       , "alias1",             6, 0, 0xe005, 2 },
   { s_cm087 +13, s_cm087 +11, "[",                  1, 1, 0xe007, 0 },
   { NULL       , s_cm087 +12, "scp1",               4, 0, 0xc003, 4 },
   { NULL       , NULL       , "SCOPED",             6, 0, 0xc015, 0 },
   { NULL       , s_cm087 +14, "[",                  1, 1, 0xe007, 0 },
   { s_cm087 +15, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cm087 +17, s_cm087 +16, "[",                  1, 1, 0xe007, 0 },
   { NULL       , NULL       , "TO",                 2, 0, 0xc015, 0 },
   { s_cm087 +18, NULL       , "expN",               4, 0, 0xe001, 6 },
   { s_cm087 +19, NULL       , "INTO",               4, 1, 0xc015, 0 },
   { s_cm087 +20, NULL       , "aliasN",             6, 0, 0xe005, 5 },
   { NULL       , s_cm087 +21, "[",                  1, 1, 0xe007, 0 },
   { NULL       , s_cm087 +22, "scpN",               4, 0, 0xc003, 7 },
   { NULL       , NULL       , "SCOPED",             6, 0, 0xc015, 0 }
};
static HB_PP_TOKEN s_cr087[ 34 ] = {
   { s_cr087 + 1, NULL       , "if",                 2, 1, 0xc015, 0 },
   { s_cr087 + 2, NULL       , "(",                  1, 1, 0xc032, 0 },
   { s_cr087 + 3, NULL       , "!",                  1, 1, 0xc045, 0 },
   { s_cr087 + 4, NULL       , "add",                3, 0, 0xc010, 1 },
   { s_cr087 + 5, NULL       , ")",                  1, 1, 0xc033, 0 },
   { s_cr087 + 6, NULL       , ";",                  1, 1, 0xc01e, 0 },
   { s_cr087 + 7, NULL       , "dbClearRelation",   15, 1, 0xc015, 0 },
   { s_cr087 + 8, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr087 + 9, NULL       , ")",                  1, 0, 0xc033, 0 },
   { s_cr087 +10, NULL       , ";",                  1, 1, 0xc01e, 0 },
   { s_cr087 +11, NULL       , "end",                3, 1, 0xc015, 0 },
   { s_cr087 +12, NULL       , ";",                  1, 1, 0xc01e, 0 },
   { s_cr087 +13, NULL       , "dbSetRelation",     13, 1, 0xc015, 0 },
   { s_cr087 +14, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr087 +15, NULL       , "alias1",             6, 1, 0xc00e, 2 },
   { s_cr087 +16, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr087 +17, NULL       , "exp1",               4, 1, 0xc00f, 3 },
   { s_cr087 +18, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr087 +19, NULL       , "exp1",               4, 1, 0xc00d, 3 },
   { s_cr087 +20, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr087 +21, NULL       , "scp1",               4, 1, 0xc010, 4 },
   { s_cr087 +22, NULL       , ")",                  1, 1, 0xc033, 0 },
   { NULL       , s_cr087 +23, "[",                  1, 1, 0xc012, 0 },
   { s_cr087 +24, NULL       , ";",                  1, 1, 0xc01e, 0 },
   { s_cr087 +25, NULL       , "dbSetRelation",     13, 1, 0xc015, 0 },
   { s_cr087 +26, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr087 +27, NULL       , "aliasN",             6, 1, 0xc00e, 5 },
   { s_cr087 +28, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr087 +29, NULL       , "expN",               4, 1, 0xc00f, 6 },
   { s_cr087 +30, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr087 +31, NULL       , "expN",               4, 1, 0xc00d, 6 },
   { s_cr087 +32, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr087 +33, NULL       , "scpN",               4, 1, 0xc010, 7 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm088[ 3 ] = {
   { s_cm088 + 1, NULL       , "SET",                3, 1, 0xc015, 0 },
   { s_cm088 + 2, NULL       , "RELATION",           8, 1, 0xc015, 0 },
   { NULL       , NULL       , "TO",                 2, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_cr088[ 3 ] = {
   { s_cr088 + 1, NULL       , "dbClearRelation",   15, 1, 0xc015, 0 },
   { s_cr088 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { NULL       , NULL       , ")",                  1, 0, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm089[ 18 ] = {
   { s_cm089 + 1, NULL       , "LOCATE",             6, 1, 0xc015, 0 },
   { s_cm089 + 4, s_cm089 + 2, "[",                  1, 1, 0xe007, 0 },
   { s_cm089 + 3, NULL       , "FOR",                3, 0, 0xc015, 0 },
   { NULL       , NULL       , "for",                3, 0, 0xe001, 1 },
   { s_cm089 + 7, s_cm089 + 5, "[",                  1, 1, 0xe007, 0 },
   { s_cm089 + 6, NULL       , "WHILE",              5, 0, 0xc015, 0 },
   { NULL       , NULL       , "while",              5, 0, 0xe001, 2 },
   { s_cm089 +10, s_cm089 + 8, "[",                  1, 1, 0xe007, 0 },
   { s_cm089 + 9, NULL       , "NEXT",               4, 0, 0xc015, 0 },
   { NULL       , NULL       , "next",               4, 0, 0xe001, 3 },
   { s_cm089 +13, s_cm089 +11, "[",                  1, 1, 0xe007, 0 },
   { s_cm089 +12, NULL       , "RECORD",             6, 0, 0xc015, 0 },
   { NULL       , NULL       , "rec",                3, 0, 0xe001, 4 },
   { s_cm089 +16, s_cm089 +14, "[",                  1, 1, 0xe007, 0 },
   { NULL       , s_cm089 +15, "rest",               4, 0, 0xc003, 5 },
   { NULL       , NULL       , "REST",               4, 0, 0xc015, 0 },
   { NULL       , s_cm089 +17, "[",                  1, 1, 0xe007, 0 },
   { NULL       , NULL       , "ALL",                3, 0, 0xc015, 0 }
};
static HB_PP_TOKEN s_cr089[ 12 ] = {
   { s_cr089 + 1, NULL       , "__dbLocate",        10, 1, 0xc015, 0 },
   { s_cr089 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr089 + 3, NULL       , "for",                3, 1, 0xc00f, 1 },
   { s_cr089 + 4, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr089 + 5, NULL       , "while",              5, 1, 0xc00f, 2 },
   { s_cr089 + 6, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr089 + 7, NULL       , "next",               4, 1, 0xc00b, 3 },
   { s_cr089 + 8, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr089 + 9, NULL       , "rec",                3, 1, 0xc00b, 4 },
   { s_cr089 +10, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr089 +11, NULL       , "rest",               4, 1, 0xc010, 5 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm090[ 8 ] = {
   { s_cm090 + 1, NULL       , "SEEK",               4, 1, 0xc015, 0 },
   { s_cm090 + 2, NULL       , "exp",                3, 0, 0xe001, 1 },
   { s_cm090 + 5, s_cm090 + 3, "[",                  1, 1, 0xe007, 0 },
   { NULL       , s_cm090 + 4, "soft",               4, 0, 0xc003, 2 },
   { NULL       , NULL       , "SOFTSEEK",           8, 1, 0xc015, 0 },
   { NULL       , s_cm090 + 6, "[",                  1, 1, 0xe007, 0 },
   { NULL       , s_cm090 + 7, "last",               4, 0, 0xc003, 3 },
   { NULL       , NULL       , "LAST",               4, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_cr090[ 22 ] = {
   { s_cr090 + 1, NULL       , "dbSeek",             6, 1, 0xc015, 0 },
   { s_cr090 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr090 + 3, NULL       , "exp",                3, 1, 0xc00b, 1 },
   { s_cr090 + 4, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr090 + 5, NULL       , "if",                 2, 1, 0xc015, 0 },
   { s_cr090 + 6, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr090 + 7, NULL       , "soft",               4, 1, 0xc010, 2 },
   { s_cr090 + 8, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr090 + 9, NULL       , ".T.",                3, 1, 0xc02c, 0 },
   { s_cr090 +10, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr090 +11, NULL       , "NIL",                3, 1, 0xc015, 0 },
   { s_cr090 +12, NULL       , ")",                  1, 1, 0xc033, 0 },
   { s_cr090 +13, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr090 +14, NULL       , "if",                 2, 1, 0xc015, 0 },
   { s_cr090 +15, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr090 +16, NULL       , "last",               4, 1, 0xc010, 3 },
   { s_cr090 +17, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr090 +18, NULL       , ".T.",                3, 1, 0xc02c, 0 },
   { s_cr090 +19, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr090 +20, NULL       , "NIL",                3, 1, 0xc015, 0 },
   { s_cr090 +21, NULL       , ")",                  1, 1, 0xc033, 0 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm091[ 1 ] = {
   { NULL       , NULL       , "CONTINUE",           8, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_cr091[ 3 ] = {
   { s_cr091 + 1, NULL       , "__dbContinue",      12, 1, 0xc015, 0 },
   { s_cr091 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { NULL       , NULL       , ")",                  1, 0, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm092[ 3 ] = {
   { s_cm092 + 1, NULL       , "FIND",               4, 1, 0xc015, 0 },
   { s_cm092 + 2, NULL       , "=",                  1, 1, 0xc049, 0 },
   { NULL       , NULL       , "xpr",                3, 0, 0xe001, 1 }
};
static HB_PP_TOKEN s_cr092[ 5 ] = {
   { s_cr092 + 1, NULL       , "(",                  1, 1, 0xc032, 0 },
   { s_cr092 + 2, NULL       , "find",               4, 1, 0xc015, 0 },
   { s_cr092 + 3, NULL       , ":=",                 2, 1, 0xc03c, 0 },
   { s_cr092 + 4, NULL       , "xpr",                3, 1, 0xc00b, 1 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm093[ 3 ] = {
   { s_cm093 + 1, NULL       , "FIND",               4, 1, 0xc015, 0 },
   { s_cm093 + 2, NULL       , ":=",                 2, 1, 0xc03c, 0 },
   { NULL       , NULL       , "xpr",                3, 0, 0xe001, 1 }
};
static HB_PP_TOKEN s_cr093[ 5 ] = {
   { s_cr093 + 1, NULL       , "(",                  1, 1, 0xc032, 0 },
   { s_cr093 + 2, NULL       , "find",               4, 1, 0xc015, 0 },
   { s_cr093 + 3, NULL       , ":=",                 2, 1, 0xc03c, 0 },
   { s_cr093 + 4, NULL       , "xpr",                3, 1, 0xc00b, 1 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm094[ 2 ] = {
   { s_cm094 + 1, NULL       , "FIND",               4, 1, 0xc015, 0 },
   { NULL       , NULL       , "text",               4, 0, 0xe004, 1 }
};
static HB_PP_TOKEN s_cr094[ 4 ] = {
   { s_cr094 + 1, NULL       , "dbSeek",             6, 1, 0xc015, 0 },
   { s_cr094 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr094 + 3, NULL       , "text",               4, 1, 0xc00e, 1 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm095[ 4 ] = {
   { s_cm095 + 1, NULL       , "SKIP",               4, 1, 0xc015, 0 },
   { s_cm095 + 2, NULL       , "x",                  1, 0, 0xe001, 2 },
   { s_cm095 + 3, NULL       , "ALIAS",              5, 1, 0xc015, 0 },
   { NULL       , NULL       , "a",                  1, 0, 0xe001, 1 }
};
static HB_PP_TOKEN s_cr095[ 8 ] = {
   { s_cr095 + 1, NULL       , "a",                  1, 1, 0xc00b, 1 },
   { s_cr095 + 2, NULL       , "->",                 2, 0, 0xc03b, 0 },
   { s_cr095 + 3, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr095 + 4, NULL       , "dbSkip",             6, 1, 0xc015, 0 },
   { s_cr095 + 5, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr095 + 6, NULL       , "x",                  1, 0, 0xc00b, 2 },
   { s_cr095 + 7, NULL       , ")",                  1, 0, 0xc033, 0 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm096[ 3 ] = {
   { s_cm096 + 1, NULL       , "SKIP",               4, 1, 0xc015, 0 },
   { s_cm096 + 2, NULL       , "ALIAS",              5, 1, 0xc015, 0 },
   { NULL       , NULL       , "a",                  1, 0, 0xe001, 1 }
};
static HB_PP_TOKEN s_cr096[ 8 ] = {
   { s_cr096 + 1, NULL       , "a",                  1, 1, 0xc00b, 1 },
   { s_cr096 + 2, NULL       , "->",                 2, 0, 0xc03b, 0 },
   { s_cr096 + 3, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr096 + 4, NULL       , "dbSkip",             6, 1, 0xc015, 0 },
   { s_cr096 + 5, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr096 + 6, NULL       , "1",                  1, 0, 0xc02a, 0 },
   { s_cr096 + 7, NULL       , ")",                  1, 0, 0xc033, 0 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm097[ 2 ] = {
   { s_cm097 + 1, NULL       , "SKIP",               4, 1, 0xc015, 0 },
   { NULL       , NULL       , "x",                  1, 0, 0xe001, 1 }
};
static HB_PP_TOKEN s_cr097[ 4 ] = {
   { s_cr097 + 1, NULL       , "dbSkip",             6, 1, 0xc015, 0 },
   { s_cr097 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr097 + 3, NULL       , "x",                  1, 1, 0xc00b, 1 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm098[ 1 ] = {
   { NULL       , NULL       , "SKIP",               4, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_cr098[ 4 ] = {
   { s_cr098 + 1, NULL       , "dbSkip",             6, 1, 0xc015, 0 },
   { s_cr098 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr098 + 3, NULL       , "1",                  1, 0, 0xc02a, 0 },
   { NULL       , NULL       , ")",                  1, 0, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm099[ 2 ] = {
   { s_cm099 + 1, NULL       , "GO",                 2, 1, 0xc015, 0 },
   { NULL       , NULL       , "BOTTOM",             6, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_cr099[ 3 ] = {
   { s_cr099 + 1, NULL       , "dbGoBottom",        10, 1, 0xc015, 0 },
   { s_cr099 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { NULL       , NULL       , ")",                  1, 0, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm100[ 2 ] = {
   { s_cm100 + 1, NULL       , "GOTO",               4, 1, 0xc015, 0 },
   { NULL       , NULL       , "BOTTOM",             6, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_cr100[ 3 ] = {
   { s_cr100 + 1, NULL       , "dbGoBottom",        10, 1, 0xc015, 0 },
   { s_cr100 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { NULL       , NULL       , ")",                  1, 0, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm101[ 2 ] = {
   { s_cm101 + 1, NULL       , "GO",                 2, 1, 0xc015, 0 },
   { NULL       , NULL       , "TOP",                3, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_cr101[ 3 ] = {
   { s_cr101 + 1, NULL       , "dbGoTop",            7, 1, 0xc015, 0 },
   { s_cr101 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { NULL       , NULL       , ")",                  1, 0, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm102[ 2 ] = {
   { s_cm102 + 1, NULL       , "GOTO",               4, 1, 0xc015, 0 },
   { NULL       , NULL       , "TOP",                3, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_cr102[ 3 ] = {
   { s_cr102 + 1, NULL       , "dbGoTop",            7, 1, 0xc015, 0 },
   { s_cr102 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { NULL       , NULL       , ")",                  1, 0, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm103[ 2 ] = {
   { s_cm103 + 1, NULL       , "GO",                 2, 1, 0xc015, 0 },
   { NULL       , NULL       , "x",                  1, 0, 0xe001, 1 }
};
static HB_PP_TOKEN s_cr103[ 4 ] = {
   { s_cr103 + 1, NULL       , "dbGoto",             6, 1, 0xc015, 0 },
   { s_cr103 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr103 + 3, NULL       , "x",                  1, 0, 0xc00b, 1 },
   { NULL       , NULL       , ")",                  1, 0, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm104[ 2 ] = {
   { s_cm104 + 1, NULL       , "GOTO",               4, 1, 0xc015, 0 },
   { NULL       , NULL       , "x",                  1, 0, 0xe001, 1 }
};
static HB_PP_TOKEN s_cr104[ 4 ] = {
   { s_cr104 + 1, NULL       , "dbGoto",             6, 1, 0xc015, 0 },
   { s_cr104 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr104 + 3, NULL       , "x",                  1, 0, 0xc00b, 1 },
   { NULL       , NULL       , ")",                  1, 0, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm105[ 1 ] = {
   { NULL       , NULL       , "COMMIT",             6, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_cr105[ 3 ] = {
   { s_cr105 + 1, NULL       , "dbCommitAll",       11, 1, 0xc015, 0 },
   { s_cr105 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { NULL       , NULL       , ")",                  1, 0, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm106[ 2 ] = {
   { s_cm106 + 1, NULL       , "UNLOCK",             6, 1, 0xc015, 0 },
   { NULL       , NULL       , "ALL",                3, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_cr106[ 3 ] = {
   { s_cr106 + 1, NULL       , "dbUnlockAll",       11, 1, 0xc015, 0 },
   { s_cr106 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { NULL       , NULL       , ")",                  1, 0, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm107[ 1 ] = {
   { NULL       , NULL       , "UNLOCK",             6, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_cr107[ 3 ] = {
   { s_cr107 + 1, NULL       , "dbUnlock",           8, 1, 0xc015, 0 },
   { s_cr107 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { NULL       , NULL       , ")",                  1, 0, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm108[ 1 ] = {
   { NULL       , NULL       , "ZAP",                3, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_cr108[ 3 ] = {
   { s_cr108 + 1, NULL       , "__dbZap",            7, 1, 0xc015, 0 },
   { s_cr108 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { NULL       , NULL       , ")",                  1, 0, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm109[ 1 ] = {
   { NULL       , NULL       , "PACK",               4, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_cr109[ 3 ] = {
   { s_cr109 + 1, NULL       , "__dbPack",           8, 1, 0xc015, 0 },
   { s_cr109 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { NULL       , NULL       , ")",                  1, 0, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm110[ 2 ] = {
   { s_cm110 + 1, NULL       , "APPEND",             6, 1, 0xc015, 0 },
   { NULL       , NULL       , "BLANK",              5, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_cr110[ 3 ] = {
   { s_cr110 + 1, NULL       , "dbAppend",           8, 1, 0xc015, 0 },
   { s_cr110 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { NULL       , NULL       , ")",                  1, 0, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm111[ 32 ] = {
   { s_cm111 + 1, NULL       , "USE",                3, 1, 0xc015, 0 },
   { s_cm111 + 2, NULL       , "db",                 2, 0, 0xe005, 3 },
   { s_cm111 + 5, s_cm111 + 3, "[",                  1, 1, 0xe007, 0 },
   { s_cm111 + 4, NULL       , "VIA",                3, 0, 0xc015, 0 },
   { NULL       , NULL       , "rdd",                3, 0, 0xe001, 2 },
   { s_cm111 + 8, s_cm111 + 6, "[",                  1, 1, 0xe007, 0 },
   { s_cm111 + 7, NULL       , "ALIAS",              5, 0, 0xc015, 0 },
   { NULL       , NULL       , "a",                  1, 0, 0xe001, 4 },
   { s_cm111 +11, s_cm111 + 9, "[",                  1, 1, 0xe007, 0 },
   { NULL       , s_cm111 +10, "nw",                 2, 0, 0xc003, 1 },
   { NULL       , NULL       , "NEW",                3, 1, 0xc015, 0 },
   { s_cm111 +14, s_cm111 +12, "[",                  1, 1, 0xe007, 0 },
   { NULL       , s_cm111 +13, "ex",                 2, 0, 0xc003, 6 },
   { NULL       , NULL       , "EXCLUSIVE",          9, 1, 0xc015, 0 },
   { s_cm111 +17, s_cm111 +15, "[",                  1, 1, 0xe007, 0 },
   { NULL       , s_cm111 +16, "sh",                 2, 0, 0xc003, 5 },
   { NULL       , NULL       , "SHARED",             6, 1, 0xc015, 0 },
   { s_cm111 +20, s_cm111 +18, "[",                  1, 1, 0xe007, 0 },
   { NULL       , s_cm111 +19, "ro",                 2, 0, 0xc003, 7 },
   { NULL       , NULL       , "READONLY",           8, 1, 0xc015, 0 },
   { s_cm111 +23, s_cm111 +21, "[",                  1, 1, 0xe007, 0 },
   { s_cm111 +22, NULL       , "CODEPAGE",           8, 0, 0xc015, 0 },
   { NULL       , NULL       , "cp",                 2, 0, 0xe001, 8 },
   { s_cm111 +26, s_cm111 +24, "[",                  1, 1, 0xe007, 0 },
   { s_cm111 +25, NULL       , "CONNECTION",        10, 0, 0xc015, 0 },
   { NULL       , NULL       , "nConn",              5, 0, 0xe001, 9 },
   { NULL       , s_cm111 +27, "[",                  1, 1, 0xe007, 0 },
   { s_cm111 +28, NULL       , "INDEX",              5, 0, 0xc015, 0 },
   { s_cm111 +29, NULL       , "index1",             6, 0, 0xe005, 10 },
   { NULL       , s_cm111 +30, "[",                  1, 1, 0xe007, 0 },
   { s_cm111 +31, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { NULL       , NULL       , "indexN",             6, 0, 0xe005, 11 }
};
static HB_PP_TOKEN s_cr111[ 42 ] = {
   { s_cr111 + 1, NULL       , "dbUseArea",          9, 1, 0xc015, 0 },
   { s_cr111 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr111 + 3, NULL       , "nw",                 2, 1, 0xc010, 1 },
   { s_cr111 + 4, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr111 + 5, NULL       , "rdd",                3, 1, 0xc00b, 2 },
   { s_cr111 + 6, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr111 + 7, NULL       , "db",                 2, 1, 0xc00e, 3 },
   { s_cr111 + 8, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr111 + 9, NULL       , "a",                  1, 1, 0xc00e, 4 },
   { s_cr111 +10, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr111 +11, NULL       , "if",                 2, 1, 0xc015, 0 },
   { s_cr111 +12, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr111 +13, NULL       , "sh",                 2, 0, 0xc010, 5 },
   { s_cr111 +14, NULL       , ".OR.",               4, 1, 0xc046, 0 },
   { s_cr111 +15, NULL       , "ex",                 2, 1, 0xc010, 6 },
   { s_cr111 +16, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr111 +17, NULL       , "!",                  1, 1, 0xc045, 0 },
   { s_cr111 +18, NULL       , "ex",                 2, 0, 0xc010, 6 },
   { s_cr111 +19, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr111 +20, NULL       , "NIL",                3, 1, 0xc015, 0 },
   { s_cr111 +21, NULL       , ")",                  1, 0, 0xc033, 0 },
   { s_cr111 +22, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr111 +23, NULL       , "ro",                 2, 1, 0xc010, 7 },
   { s_cr111 +24, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr111 +26, s_cr111 +25, "[",                  1, 1, 0xc012, 0 },
   { NULL       , NULL       , "cp",                 2, 1, 0xc00b, 8 },
   { s_cr111 +27, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr111 +29, s_cr111 +28, "[",                  1, 1, 0xc012, 0 },
   { NULL       , NULL       , "nConn",              5, 1, 0xc00b, 9 },
   { s_cr111 +30, NULL       , ")",                  1, 1, 0xc033, 0 },
   { s_cr111 +36, s_cr111 +31, "[",                  1, 1, 0xc012, 0 },
   { s_cr111 +32, NULL       , ";",                  1, 1, 0xc01e, 0 },
   { s_cr111 +33, NULL       , "dbSetIndex",        10, 1, 0xc015, 0 },
   { s_cr111 +34, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr111 +35, NULL       , "index1",             6, 1, 0xc00e, 10 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 },
   { NULL       , s_cr111 +37, "[",                  1, 1, 0xc012, 0 },
   { s_cr111 +38, NULL       , ";",                  1, 1, 0xc01e, 0 },
   { s_cr111 +39, NULL       , "dbSetIndex",        10, 1, 0xc015, 0 },
   { s_cr111 +40, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr111 +41, NULL       , "indexN",             6, 1, 0xc00e, 11 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm112[ 1 ] = {
   { NULL       , NULL       , "USE",                3, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_cr112[ 3 ] = {
   { s_cr112 + 1, NULL       , "dbCloseArea",       11, 1, 0xc015, 0 },
   { s_cr112 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { NULL       , NULL       , ")",                  1, 0, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm113[ 6 ] = {
   { s_cm113 + 1, NULL       , "SELECT",             6, 1, 0xc015, 0 },
   { s_cm113 + 2, NULL       , "f",                  1, 0, 0xe001, 1 },
   { s_cm113 + 3, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cm113 + 5, s_cm113 + 4, "[",                  1, 0, 0xe007, 0 },
   { NULL       , NULL       , "p",                  1, 0, 0xe002, 2 },
   { NULL       , NULL       , ")",                  1, 0, 0xc033, 0 }
};
static HB_PP_TOKEN s_cr113[ 7 ] = {
   { s_cr113 + 1, NULL       , "dbSelectArea",      12, 1, 0xc015, 0 },
   { s_cr113 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr113 + 3, NULL       , "f",                  1, 1, 0xc00b, 1 },
   { s_cr113 + 4, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr113 + 5, NULL       , "p",                  1, 0, 0xc00b, 2 },
   { s_cr113 + 6, NULL       , ")",                  1, 0, 0xc033, 0 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm114[ 2 ] = {
   { s_cm114 + 1, NULL       , "SELECT",             6, 1, 0xc015, 0 },
   { NULL       , NULL       , "area",               4, 0, 0xe001, 1 }
};
static HB_PP_TOKEN s_cr114[ 4 ] = {
   { s_cr114 + 1, NULL       , "dbSelectArea",      12, 1, 0xc015, 0 },
   { s_cr114 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr114 + 3, NULL       , "area",               4, 1, 0xc00e, 1 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm115[ 2 ] = {
   { s_cm115 + 1, NULL       , "CLEAR",              5, 1, 0xc015, 0 },
   { NULL       , NULL       , "ALL",                3, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_cr115[ 19 ] = {
   { s_cr115 + 1, NULL       , "CLOSE",              5, 1, 0xc015, 0 },
   { s_cr115 + 2, NULL       , "DATABASES",          9, 1, 0xc015, 0 },
   { s_cr115 + 3, NULL       , ";",                  1, 1, 0xc01e, 0 },
   { s_cr115 + 4, NULL       , "CLOSE",              5, 1, 0xc015, 0 },
   { s_cr115 + 5, NULL       , "FORMAT",             6, 1, 0xc015, 0 },
   { s_cr115 + 6, NULL       , ";",                  1, 1, 0xc01e, 0 },
   { s_cr115 + 7, NULL       , "CLEAR",              5, 1, 0xc015, 0 },
   { s_cr115 + 8, NULL       , "MEMORY",             6, 1, 0xc015, 0 },
   { s_cr115 + 9, NULL       , ";",                  1, 1, 0xc01e, 0 },
   { s_cr115 +10, NULL       , "CLEAR",              5, 1, 0xc015, 0 },
   { s_cr115 +11, NULL       , "GETS",               4, 1, 0xc015, 0 },
   { s_cr115 +12, NULL       , ";",                  1, 1, 0xc01e, 0 },
   { s_cr115 +13, NULL       , "SET",                3, 1, 0xc015, 0 },
   { s_cr115 +14, NULL       , "ALTERNATE",          9, 1, 0xc015, 0 },
   { s_cr115 +15, NULL       , "OFF",                3, 1, 0xc015, 0 },
   { s_cr115 +16, NULL       , ";",                  1, 1, 0xc01e, 0 },
   { s_cr115 +17, NULL       , "SET",                3, 1, 0xc015, 0 },
   { s_cr115 +18, NULL       , "ALTERNATE",          9, 1, 0xc015, 0 },
   { NULL       , NULL       , "TO",                 2, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_cm116[ 1 ] = {
   { NULL       , NULL       , "CLEAR",              5, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_cr116[ 5 ] = {
   { s_cr116 + 1, NULL       , "CLEAR",              5, 1, 0xc015, 0 },
   { s_cr116 + 2, NULL       , "SCREEN",             6, 1, 0xc015, 0 },
   { s_cr116 + 3, NULL       , ";",                  1, 1, 0xc01e, 0 },
   { s_cr116 + 4, NULL       , "CLEAR",              5, 1, 0xc015, 0 },
   { NULL       , NULL       , "GETS",               4, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_cm117[ 2 ] = {
   { s_cm117 + 1, NULL       , "CLOSE",              5, 1, 0xc015, 0 },
   { NULL       , NULL       , "ALL",                3, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_cr117[ 8 ] = {
   { s_cr117 + 1, NULL       , "CLOSE",              5, 1, 0xc015, 0 },
   { s_cr117 + 2, NULL       , "DATABASES",          9, 1, 0xc015, 0 },
   { s_cr117 + 3, NULL       , ";",                  1, 1, 0xc01e, 0 },
   { s_cr117 + 4, NULL       , "SELECT",             6, 1, 0xc015, 0 },
   { s_cr117 + 5, NULL       , "1",                  1, 1, 0xc02a, 0 },
   { s_cr117 + 6, NULL       , ";",                  1, 1, 0xc01e, 0 },
   { s_cr117 + 7, NULL       , "CLOSE",              5, 1, 0xc015, 0 },
   { NULL       , NULL       , "FORMAT",             6, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_cm118[ 2 ] = {
   { s_cm118 + 1, NULL       , "CLOSE",              5, 1, 0xc015, 0 },
   { NULL       , NULL       , "PROCEDURE",          9, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_cm119[ 2 ] = {
   { s_cm119 + 1, NULL       , "CLOSE",              5, 1, 0xc015, 0 },
   { NULL       , NULL       , "INDEXES",            7, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_cr119[ 3 ] = {
   { s_cr119 + 1, NULL       , "dbClearIndex",      12, 1, 0xc015, 0 },
   { s_cr119 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { NULL       , NULL       , ")",                  1, 0, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm120[ 2 ] = {
   { s_cm120 + 1, NULL       , "CLOSE",              5, 1, 0xc015, 0 },
   { NULL       , NULL       , "FORMAT",             6, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_cr120[ 4 ] = {
   { s_cr120 + 1, NULL       , "__SetFormat",       11, 1, 0xc015, 0 },
   { s_cr120 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr120 + 3, NULL       , "NIL",                3, 0, 0xc015, 0 },
   { NULL       , NULL       , ")",                  1, 0, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm121[ 2 ] = {
   { s_cm121 + 1, NULL       , "CLOSE",              5, 1, 0xc015, 0 },
   { NULL       , NULL       , "ALTERNATE",          9, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_cr121[ 6 ] = {
   { s_cr121 + 1, NULL       , "Set",                3, 1, 0xc015, 0 },
   { s_cr121 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr121 + 3, NULL       , "_SET_ALTFILE",      12, 0, 0xc015, 0 },
   { s_cr121 + 4, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr121 + 5, NULL       , "",                   0, 1, 0xc029, 0 },
   { NULL       , NULL       , ")",                  1, 0, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm122[ 2 ] = {
   { s_cm122 + 1, NULL       , "CLOSE",              5, 1, 0xc015, 0 },
   { NULL       , NULL       , "DATABASES",          9, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_cr122[ 3 ] = {
   { s_cr122 + 1, NULL       , "dbCloseAll",        10, 1, 0xc015, 0 },
   { s_cr122 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { NULL       , NULL       , ")",                  1, 0, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm123[ 1 ] = {
   { NULL       , NULL       , "CLOSE",              5, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_cr123[ 3 ] = {
   { s_cr123 + 1, NULL       , "dbCloseArea",       11, 1, 0xc015, 0 },
   { s_cr123 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { NULL       , NULL       , ")",                  1, 0, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm124[ 2 ] = {
   { s_cm124 + 1, NULL       , "CLOSE",              5, 1, 0xc015, 0 },
   { NULL       , NULL       , "a",                  1, 0, 0xe001, 1 }
};
static HB_PP_TOKEN s_cr124[ 7 ] = {
   { s_cr124 + 1, NULL       , "a",                  1, 1, 0xc00b, 1 },
   { s_cr124 + 2, NULL       , "->",                 2, 0, 0xc03b, 0 },
   { s_cr124 + 3, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr124 + 4, NULL       , "dbCloseArea",       11, 1, 0xc015, 0 },
   { s_cr124 + 5, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr124 + 6, NULL       , ")",                  1, 0, 0xc033, 0 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm125[ 3 ] = {
   { s_cm125 + 1, NULL       , "RUN",                3, 1, 0xc015, 0 },
   { s_cm125 + 2, NULL       , ":=",                 2, 1, 0xc03c, 0 },
   { NULL       , NULL       , "xpr",                3, 0, 0xe001, 1 }
};
static HB_PP_TOKEN s_cr125[ 5 ] = {
   { s_cr125 + 1, NULL       , "(",                  1, 1, 0xc032, 0 },
   { s_cr125 + 2, NULL       , "run",                3, 1, 0xc015, 0 },
   { s_cr125 + 3, NULL       , ":=",                 2, 1, 0xc03c, 0 },
   { s_cr125 + 4, NULL       , "xpr",                3, 1, 0xc00b, 1 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm126[ 3 ] = {
   { s_cm126 + 1, NULL       , "RUN",                3, 1, 0xc015, 0 },
   { s_cm126 + 2, NULL       , "=",                  1, 1, 0xc049, 0 },
   { NULL       , NULL       , "xpr",                3, 0, 0xe001, 1 }
};
static HB_PP_TOKEN s_cr126[ 5 ] = {
   { s_cr126 + 1, NULL       , "(",                  1, 1, 0xc032, 0 },
   { s_cr126 + 2, NULL       , "run",                3, 1, 0xc015, 0 },
   { s_cr126 + 3, NULL       , ":=",                 2, 1, 0xc03c, 0 },
   { s_cr126 + 4, NULL       , "xpr",                3, 1, 0xc00b, 1 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm127[ 2 ] = {
   { s_cm127 + 1, NULL       , "!",                  1, 1, 0xc045, 0 },
   { NULL       , NULL       , "cmd",                3, 0, 0xe004, 1 }
};
static HB_PP_TOKEN s_cr127[ 2 ] = {
   { s_cr127 + 1, NULL       , "RUN",                3, 1, 0xc015, 0 },
   { NULL       , NULL       , "cmd",                3, 1, 0xc00b, 1 }
};
static HB_PP_TOKEN s_cm128[ 4 ] = {
   { s_cm128 + 1, NULL       , "RUN",                3, 1, 0xc015, 0 },
   { s_cm128 + 2, NULL       , "(",                  1, 1, 0xc032, 0 },
   { s_cm128 + 3, NULL       , "cmd",                3, 0, 0xe001, 1 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cr128[ 4 ] = {
   { s_cr128 + 1, NULL       , "__Run",              5, 1, 0xc015, 0 },
   { s_cr128 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr128 + 3, NULL       , "cmd",                3, 1, 0xc00b, 1 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm129[ 2 ] = {
   { s_cm129 + 1, NULL       , "RUN",                3, 1, 0xc015, 0 },
   { NULL       , NULL       , "cmd",                3, 0, 0xe004, 1 }
};
static HB_PP_TOKEN s_cr129[ 4 ] = {
   { s_cr129 + 1, NULL       , "__Run",              5, 1, 0xc015, 0 },
   { s_cr129 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr129 + 3, NULL       , "cmd",                3, 1, 0xc00c, 1 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm130[ 1 ] = {
   { NULL       , NULL       , "QUIT",               4, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_cr130[ 3 ] = {
   { s_cr130 + 1, NULL       , "__Quit",             6, 1, 0xc015, 0 },
   { s_cr130 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { NULL       , NULL       , ")",                  1, 0, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm131[ 1 ] = {
   { NULL       , NULL       , "CANCEL",             6, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_cr131[ 3 ] = {
   { s_cr131 + 1, NULL       , "__Quit",             6, 1, 0xc015, 0 },
   { s_cr131 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { NULL       , NULL       , ")",                  1, 0, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm132[ 2 ] = {
   { s_cm132 + 1, NULL       , "REQUEST",            7, 1, 0xc015, 0 },
   { NULL       , NULL       , "func",               4, 0, 0xe002, 1 }
};
static HB_PP_TOKEN s_cr132[ 2 ] = {
   { s_cr132 + 1, NULL       , "EXTERNAL",           8, 1, 0xc015, 0 },
   { NULL       , NULL       , "func",               4, 1, 0xc00b, 1 }
};
static HB_PP_TOKEN s_cm133[ 6 ] = {
   { s_cm133 + 1, NULL       , "TYPE",               4, 1, 0xc015, 0 },
   { s_cm133 + 2, NULL       , "f",                  1, 0, 0xe005, 1 },
   { NULL       , s_cm133 + 3, "[",                  1, 1, 0xe007, 0 },
   { NULL       , s_cm133 + 4, "prn",                3, 0, 0xc003, 2 },
   { s_cm133 + 5, NULL       , "TO",                 2, 0, 0xc015, 0 },
   { NULL       , NULL       , "PRINTER",            7, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_cr133[ 6 ] = {
   { s_cr133 + 1, NULL       , "__TypeFile",        10, 1, 0xc015, 0 },
   { s_cr133 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr133 + 3, NULL       , "f",                  1, 1, 0xc00e, 1 },
   { s_cr133 + 4, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr133 + 5, NULL       , "prn",                3, 1, 0xc010, 2 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm134[ 10 ] = {
   { s_cm134 + 1, NULL       , "TYPE",               4, 1, 0xc015, 0 },
   { s_cm134 + 2, NULL       , "f",                  1, 0, 0xe005, 1 },
   { s_cm134 + 6, s_cm134 + 3, "[",                  1, 1, 0xe007, 0 },
   { NULL       , s_cm134 + 4, "prn",                3, 0, 0xc003, 2 },
   { s_cm134 + 5, NULL       , "TO",                 2, 0, 0xc015, 0 },
   { NULL       , NULL       , "PRINTER",            7, 1, 0xc015, 0 },
   { NULL       , s_cm134 + 7, "[",                  1, 1, 0xe007, 0 },
   { s_cm134 + 8, NULL       , "TO",                 2, 0, 0xc015, 0 },
   { s_cm134 + 9, NULL       , "FILE",               4, 1, 0xc015, 0 },
   { NULL       , NULL       , "dst",                3, 0, 0xe005, 3 }
};
static HB_PP_TOKEN s_cr134[ 13 ] = {
   { s_cr134 + 1, NULL       , "__TypeFile",        10, 1, 0xc015, 0 },
   { s_cr134 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr134 + 3, NULL       , "f",                  1, 1, 0xc00e, 1 },
   { s_cr134 + 4, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr134 + 5, NULL       , "prn",                3, 1, 0xc010, 2 },
   { s_cr134 + 6, NULL       , ")",                  1, 1, 0xc033, 0 },
   { NULL       , s_cr134 + 7, "[",                  1, 1, 0xc012, 0 },
   { s_cr134 + 8, NULL       , ";",                  1, 1, 0xc01e, 0 },
   { s_cr134 + 9, NULL       , "COPY",               4, 1, 0xc015, 0 },
   { s_cr134 +10, NULL       , "FILE",               4, 1, 0xc015, 0 },
   { s_cr134 +11, NULL       , "f",                  1, 1, 0xc00e, 1 },
   { s_cr134 +12, NULL       , "TO",                 2, 1, 0xc015, 0 },
   { NULL       , NULL       , "dst",                3, 1, 0xc00e, 3 }
};
static HB_PP_TOKEN s_cm135[ 3 ] = {
   { s_cm135 + 1, NULL       , "DIR",                3, 1, 0xc015, 0 },
   { NULL       , s_cm135 + 2, "[",                  1, 1, 0xe007, 0 },
   { NULL       , NULL       , "mask",               4, 0, 0xe005, 1 }
};
static HB_PP_TOKEN s_cr135[ 4 ] = {
   { s_cr135 + 1, NULL       , "__Dir",              5, 1, 0xc015, 0 },
   { s_cr135 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr135 + 3, NULL       , "mask",               4, 1, 0xc00e, 1 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm136[ 5 ] = {
   { s_cm136 + 1, NULL       , "COPY",               4, 1, 0xc015, 0 },
   { s_cm136 + 2, NULL       , "FILE",               4, 1, 0xc015, 0 },
   { s_cm136 + 3, NULL       , "src",                3, 0, 0xe005, 1 },
   { s_cm136 + 4, NULL       , "TO",                 2, 1, 0xc015, 0 },
   { NULL       , NULL       , "dst",                3, 0, 0xe005, 2 }
};
static HB_PP_TOKEN s_cr136[ 6 ] = {
   { s_cr136 + 1, NULL       , "__CopyFile",        10, 1, 0xc015, 0 },
   { s_cr136 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr136 + 3, NULL       , "src",                3, 1, 0xc00e, 1 },
   { s_cr136 + 4, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr136 + 5, NULL       , "dst",                3, 1, 0xc00e, 2 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm137[ 4 ] = {
   { s_cm137 + 1, NULL       , "RENAME",             6, 1, 0xc015, 0 },
   { s_cm137 + 2, NULL       , "old",                3, 0, 0xe005, 1 },
   { s_cm137 + 3, NULL       , "TO",                 2, 1, 0xc015, 0 },
   { NULL       , NULL       , "new",                3, 0, 0xe005, 2 }
};
static HB_PP_TOKEN s_cr137[ 6 ] = {
   { s_cr137 + 1, NULL       , "FRename",            7, 1, 0xc015, 0 },
   { s_cr137 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr137 + 3, NULL       , "old",                3, 1, 0xc00e, 1 },
   { s_cr137 + 4, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr137 + 5, NULL       , "new",                3, 1, 0xc00e, 2 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm138[ 3 ] = {
   { s_cm138 + 1, NULL       , "DELETE",             6, 1, 0xc015, 0 },
   { s_cm138 + 2, NULL       , "FILE",               4, 1, 0xc015, 0 },
   { NULL       , NULL       , "f",                  1, 0, 0xe005, 1 }
};
static HB_PP_TOKEN s_cr138[ 4 ] = {
   { s_cr138 + 1, NULL       , "FErase",             6, 1, 0xc015, 0 },
   { s_cr138 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr138 + 3, NULL       , "f",                  1, 1, 0xc00e, 1 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm139[ 2 ] = {
   { s_cm139 + 1, NULL       , "ERASE",              5, 1, 0xc015, 0 },
   { NULL       , NULL       , "f",                  1, 0, 0xe005, 1 }
};
static HB_PP_TOKEN s_cr139[ 4 ] = {
   { s_cr139 + 1, NULL       , "FErase",             6, 1, 0xc015, 0 },
   { s_cr139 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr139 + 3, NULL       , "f",                  1, 1, 0xc00e, 1 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm140[ 9 ] = {
   { s_cm140 + 1, NULL       , "SAVE",               4, 1, 0xc015, 0 },
   { s_cm140 + 4, s_cm140 + 2, "[",                  1, 1, 0xe007, 0 },
   { s_cm140 + 3, NULL       , "TO",                 2, 0, 0xc015, 0 },
   { NULL       , NULL       , "f",                  1, 0, 0xe005, 1 },
   { s_cm140 + 6, s_cm140 + 5, "[",                  1, 1, 0xe007, 0 },
   { NULL       , NULL       , "ALL",                3, 0, 0xc015, 0 },
   { NULL       , s_cm140 + 7, "[",                  1, 1, 0xe007, 0 },
   { NULL       , s_cm140 + 8, "b",                  1, 0, 0xc003, 2 },
   { NULL       , NULL       , "EXTENDED",           8, 0, 0xc015, 0 }
};
static HB_PP_TOKEN s_cr140[ 10 ] = {
   { s_cr140 + 1, NULL       , "__MVSave",           8, 1, 0xc015, 0 },
   { s_cr140 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr140 + 3, NULL       , "f",                  1, 1, 0xc00e, 1 },
   { s_cr140 + 4, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr140 + 5, NULL       , "*",                  1, 1, 0xc029, 0 },
   { s_cr140 + 6, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr140 + 7, NULL       , ".T.",                3, 1, 0xc02c, 0 },
   { s_cr140 + 8, NULL       , ",",                  1, 1, 0xc01d, 0 },
   { s_cr140 + 9, NULL       , "b",                  1, 0, 0xc010, 2 },
   { NULL       , NULL       , ")",                  1, 0, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm141[ 9 ] = {
   { s_cm141 + 1, NULL       , "SAVE",               4, 1, 0xc015, 0 },
   { s_cm141 + 2, NULL       , "TO",                 2, 1, 0xc015, 0 },
   { s_cm141 + 3, NULL       , "f",                  1, 0, 0xe005, 1 },
   { s_cm141 + 6, s_cm141 + 4, "[",                  1, 1, 0xe007, 0 },
   { NULL       , s_cm141 + 5, "b",                  1, 0, 0xc003, 3 },
   { NULL       , NULL       , "EXTENDED",           8, 0, 0xc015, 0 },
   { s_cm141 + 7, NULL       , "ALL",                3, 3, 0xc015, 0 },
   { s_cm141 + 8, NULL       , "EXCEPT",             6, 1, 0xc015, 0 },
   { NULL       , NULL       , "p",                  1, 0, 0xe005, 2 }
};
static HB_PP_TOKEN s_cr141[ 10 ] = {
   { s_cr141 + 1, NULL       , "__MVSave",           8, 1, 0xc015, 0 },
   { s_cr141 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr141 + 3, NULL       , "f",                  1, 1, 0xc00e, 1 },
   { s_cr141 + 4, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr141 + 5, NULL       , "p",                  1, 1, 0xc00e, 2 },
   { s_cr141 + 6, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr141 + 7, NULL       , ".F.",                3, 1, 0xc02c, 0 },
   { s_cr141 + 8, NULL       , ",",                  1, 1, 0xc01d, 0 },
   { s_cr141 + 9, NULL       , "b",                  1, 0, 0xc010, 3 },
   { NULL       , NULL       , ")",                  1, 0, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm142[ 9 ] = {
   { s_cm142 + 1, NULL       , "SAVE",               4, 1, 0xc015, 0 },
   { s_cm142 + 2, NULL       , "ALL",                3, 1, 0xc015, 0 },
   { s_cm142 + 3, NULL       , "EXCEPT",             6, 1, 0xc015, 0 },
   { s_cm142 + 4, NULL       , "p",                  1, 0, 0xe005, 2 },
   { s_cm142 + 5, NULL       , "TO",                 2, 1, 0xc015, 0 },
   { s_cm142 + 6, NULL       , "f",                  1, 0, 0xe005, 1 },
   { NULL       , s_cm142 + 7, "[",                  1, 1, 0xe007, 0 },
   { NULL       , s_cm142 + 8, "b",                  1, 0, 0xc003, 3 },
   { NULL       , NULL       , "EXTENDED",           8, 0, 0xc015, 0 }
};
static HB_PP_TOKEN s_cr142[ 10 ] = {
   { s_cr142 + 1, NULL       , "__MVSave",           8, 1, 0xc015, 0 },
   { s_cr142 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr142 + 3, NULL       , "f",                  1, 1, 0xc00e, 1 },
   { s_cr142 + 4, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr142 + 5, NULL       , "p",                  1, 1, 0xc00e, 2 },
   { s_cr142 + 6, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr142 + 7, NULL       , ".F.",                3, 1, 0xc02c, 0 },
   { s_cr142 + 8, NULL       , ",",                  1, 1, 0xc01d, 0 },
   { s_cr142 + 9, NULL       , "b",                  1, 0, 0xc010, 3 },
   { NULL       , NULL       , ")",                  1, 0, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm143[ 9 ] = {
   { s_cm143 + 1, NULL       , "SAVE",               4, 1, 0xc015, 0 },
   { s_cm143 + 2, NULL       , "ALL",                3, 1, 0xc015, 0 },
   { s_cm143 + 3, NULL       , "LIKE",               4, 1, 0xc015, 0 },
   { s_cm143 + 4, NULL       , "p",                  1, 0, 0xe005, 2 },
   { s_cm143 + 5, NULL       , "TO",                 2, 1, 0xc015, 0 },
   { s_cm143 + 6, NULL       , "f",                  1, 0, 0xe005, 1 },
   { NULL       , s_cm143 + 7, "[",                  1, 1, 0xe007, 0 },
   { NULL       , s_cm143 + 8, "b",                  1, 0, 0xc003, 3 },
   { NULL       , NULL       , "EXTENDED",           8, 0, 0xc015, 0 }
};
static HB_PP_TOKEN s_cr143[ 10 ] = {
   { s_cr143 + 1, NULL       , "__MVSave",           8, 1, 0xc015, 0 },
   { s_cr143 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr143 + 3, NULL       , "f",                  1, 1, 0xc00e, 1 },
   { s_cr143 + 4, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr143 + 5, NULL       , "p",                  1, 1, 0xc00e, 2 },
   { s_cr143 + 6, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr143 + 7, NULL       , ".T.",                3, 1, 0xc02c, 0 },
   { s_cr143 + 8, NULL       , ",",                  1, 1, 0xc01d, 0 },
   { s_cr143 + 9, NULL       , "b",                  1, 0, 0xc010, 3 },
   { NULL       , NULL       , ")",                  1, 0, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm144[ 9 ] = {
   { s_cm144 + 1, NULL       , "SAVE",               4, 1, 0xc015, 0 },
   { s_cm144 + 2, NULL       , "TO",                 2, 1, 0xc015, 0 },
   { s_cm144 + 3, NULL       , "f",                  1, 0, 0xe005, 1 },
   { s_cm144 + 6, s_cm144 + 4, "[",                  1, 1, 0xe007, 0 },
   { NULL       , s_cm144 + 5, "b",                  1, 0, 0xc003, 3 },
   { NULL       , NULL       , "EXTENDED",           8, 0, 0xc015, 0 },
   { s_cm144 + 7, NULL       , "ALL",                3, 3, 0xc015, 0 },
   { s_cm144 + 8, NULL       , "LIKE",               4, 1, 0xc015, 0 },
   { NULL       , NULL       , "p",                  1, 0, 0xe005, 2 }
};
static HB_PP_TOKEN s_cr144[ 10 ] = {
   { s_cr144 + 1, NULL       , "__MVSave",           8, 1, 0xc015, 0 },
   { s_cr144 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr144 + 3, NULL       , "f",                  1, 1, 0xc00e, 1 },
   { s_cr144 + 4, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr144 + 5, NULL       , "p",                  1, 1, 0xc00e, 2 },
   { s_cr144 + 6, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr144 + 7, NULL       , ".T.",                3, 1, 0xc02c, 0 },
   { s_cr144 + 8, NULL       , ",",                  1, 1, 0xc01d, 0 },
   { s_cr144 + 9, NULL       , "b",                  1, 0, 0xc010, 3 },
   { NULL       , NULL       , ")",                  1, 0, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm145[ 9 ] = {
   { s_cm145 + 1, NULL       , "SAVE",               4, 1, 0xc015, 0 },
   { s_cm145 + 2, NULL       , "TO",                 2, 1, 0xc015, 0 },
   { s_cm145 + 3, NULL       , "f",                  1, 0, 0xe005, 1 },
   { s_cm145 + 4, NULL       , "ALL",                3, 1, 0xc015, 0 },
   { s_cm145 + 5, NULL       , "LIKE",               4, 1, 0xc015, 0 },
   { s_cm145 + 6, NULL       , "p",                  1, 0, 0xe005, 2 },
   { NULL       , s_cm145 + 7, "[",                  1, 1, 0xe007, 0 },
   { NULL       , s_cm145 + 8, "b",                  1, 0, 0xc003, 3 },
   { NULL       , NULL       , "EXTENDED",           8, 0, 0xc015, 0 }
};
static HB_PP_TOKEN s_cr145[ 10 ] = {
   { s_cr145 + 1, NULL       , "__MVSave",           8, 1, 0xc015, 0 },
   { s_cr145 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr145 + 3, NULL       , "f",                  1, 1, 0xc00e, 1 },
   { s_cr145 + 4, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr145 + 5, NULL       , "p",                  1, 1, 0xc00e, 2 },
   { s_cr145 + 6, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr145 + 7, NULL       , ".T.",                3, 1, 0xc02c, 0 },
   { s_cr145 + 8, NULL       , ",",                  1, 1, 0xc01d, 0 },
   { s_cr145 + 9, NULL       , "b",                  1, 0, 0xc010, 3 },
   { NULL       , NULL       , ")",                  1, 0, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm146[ 10 ] = {
   { s_cm146 + 1, NULL       , "RESTORE",            7, 1, 0xc015, 0 },
   { s_cm146 + 4, s_cm146 + 2, "[",                  1, 1, 0xe007, 0 },
   { s_cm146 + 3, NULL       , "FROM",               4, 0, 0xc015, 0 },
   { NULL       , NULL       , "f",                  1, 0, 0xe005, 1 },
   { s_cm146 + 7, s_cm146 + 5, "[",                  1, 1, 0xe007, 0 },
   { NULL       , s_cm146 + 6, "a",                  1, 0, 0xc003, 2 },
   { NULL       , NULL       , "ADDITIVE",           8, 0, 0xc015, 0 },
   { NULL       , s_cm146 + 8, "[",                  1, 1, 0xe007, 0 },
   { NULL       , s_cm146 + 9, "b",                  1, 0, 0xc003, 3 },
   { NULL       , NULL       , "EXTENDED",           8, 0, 0xc015, 0 }
};
static HB_PP_TOKEN s_cr146[ 8 ] = {
   { s_cr146 + 1, NULL       , "__MVRestore",       11, 1, 0xc015, 0 },
   { s_cr146 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr146 + 3, NULL       , "f",                  1, 1, 0xc00e, 1 },
   { s_cr146 + 4, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr146 + 5, NULL       , "a",                  1, 1, 0xc010, 2 },
   { s_cr146 + 6, NULL       , ",",                  1, 1, 0xc01d, 0 },
   { s_cr146 + 7, NULL       , "b",                  1, 0, 0xc010, 3 },
   { NULL       , NULL       , ")",                  1, 0, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm147[ 4 ] = {
   { s_cm147 + 1, NULL       , "RELEASE",            7, 1, 0xc015, 0 },
   { s_cm147 + 2, NULL       , "ALL",                3, 1, 0xc015, 0 },
   { s_cm147 + 3, NULL       , "EXCEPT",             6, 1, 0xc015, 0 },
   { NULL       , NULL       , "p",                  1, 0, 0xe001, 1 }
};
static HB_PP_TOKEN s_cr147[ 6 ] = {
   { s_cr147 + 1, NULL       , "__MVRelease",       11, 1, 0xc015, 0 },
   { s_cr147 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr147 + 3, NULL       , "p",                  1, 1, 0xc00c, 1 },
   { s_cr147 + 4, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr147 + 5, NULL       , ".F.",                3, 1, 0xc02c, 0 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm148[ 4 ] = {
   { s_cm148 + 1, NULL       , "RELEASE",            7, 1, 0xc015, 0 },
   { s_cm148 + 2, NULL       , "ALL",                3, 1, 0xc015, 0 },
   { s_cm148 + 3, NULL       , "LIKE",               4, 1, 0xc015, 0 },
   { NULL       , NULL       , "p",                  1, 0, 0xe001, 1 }
};
static HB_PP_TOKEN s_cr148[ 6 ] = {
   { s_cr148 + 1, NULL       , "__MVRelease",       11, 1, 0xc015, 0 },
   { s_cr148 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr148 + 3, NULL       , "p",                  1, 1, 0xc00c, 1 },
   { s_cr148 + 4, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr148 + 5, NULL       , ".T.",                3, 1, 0xc02c, 0 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm149[ 2 ] = {
   { s_cm149 + 1, NULL       , "RELEASE",            7, 1, 0xc015, 0 },
   { NULL       , NULL       , "ALL",                3, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_cr149[ 6 ] = {
   { s_cr149 + 1, NULL       , "__MVRelease",       11, 1, 0xc015, 0 },
   { s_cr149 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr149 + 3, NULL       , "*",                  1, 1, 0xc029, 0 },
   { s_cr149 + 4, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr149 + 5, NULL       , ".T.",                3, 1, 0xc02c, 0 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm150[ 2 ] = {
   { s_cm150 + 1, NULL       , "RELEASE",            7, 1, 0xc015, 0 },
   { NULL       , NULL       , "v",                  1, 0, 0xe002, 1 }
};
static HB_PP_TOKEN s_cr150[ 4 ] = {
   { s_cr150 + 1, NULL       , "__MVXRelease",      12, 1, 0xc015, 0 },
   { s_cr150 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr150 + 3, NULL       , "v",                  1, 1, 0xc00d, 1 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm151[ 2 ] = {
   { s_cm151 + 1, NULL       , "CLEAR",              5, 1, 0xc015, 0 },
   { NULL       , NULL       , "MEMORY",             6, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_cr151[ 3 ] = {
   { s_cr151 + 1, NULL       , "__MVClear",          9, 1, 0xc015, 0 },
   { s_cr151 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { NULL       , NULL       , ")",                  1, 0, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm152[ 2 ] = {
   { s_cm152 + 1, NULL       , "CLEAR",              5, 1, 0xc015, 0 },
   { NULL       , NULL       , "TYPEAHEAD",          9, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_cr152[ 3 ] = {
   { s_cr152 + 1, NULL       , "__Keyboard",        10, 1, 0xc015, 0 },
   { s_cr152 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { NULL       , NULL       , ")",                  1, 0, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm153[ 2 ] = {
   { s_cm153 + 1, NULL       , "KEYBOARD",           8, 1, 0xc015, 0 },
   { NULL       , NULL       , "x",                  1, 0, 0xe001, 1 }
};
static HB_PP_TOKEN s_cr153[ 4 ] = {
   { s_cr153 + 1, NULL       , "__Keyboard",        10, 1, 0xc015, 0 },
   { s_cr153 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr153 + 3, NULL       , "x",                  1, 1, 0xc00b, 1 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm154[ 5 ] = {
   { s_cm154 + 1, NULL       , "INPUT",              5, 1, 0xc015, 0 },
   { s_cm154 + 3, s_cm154 + 2, "[",                  1, 1, 0xe007, 0 },
   { NULL       , NULL       , "msg",                3, 0, 0xe001, 1 },
   { s_cm154 + 4, NULL       , "TO",                 2, 1, 0xc015, 0 },
   { NULL       , NULL       , "v",                  1, 0, 0xe001, 2 }
};
static HB_PP_TOKEN s_cr154[ 22 ] = {
   { s_cr154 + 1, NULL       , "if",                 2, 1, 0xc015, 0 },
   { s_cr154 + 2, NULL       , "(",                  1, 1, 0xc032, 0 },
   { s_cr154 + 3, NULL       , "!",                  1, 1, 0xc045, 0 },
   { s_cr154 + 4, NULL       , "Empty",              5, 0, 0xc015, 0 },
   { s_cr154 + 5, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr154 + 6, NULL       , "__Accept",           8, 0, 0xc015, 0 },
   { s_cr154 + 7, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr154 + 8, NULL       , "msg",                3, 0, 0xc00b, 1 },
   { s_cr154 + 9, NULL       , ")",                  1, 0, 0xc033, 0 },
   { s_cr154 +10, NULL       , ")",                  1, 0, 0xc033, 0 },
   { s_cr154 +11, NULL       , ")",                  1, 1, 0xc033, 0 },
   { s_cr154 +12, NULL       , ";",                  1, 1, 0xc01e, 0 },
   { s_cr154 +13, NULL       , "v",                  1, 1, 0xc00b, 2 },
   { s_cr154 +14, NULL       , ":=",                 2, 1, 0xc03c, 0 },
   { s_cr154 +15, NULL       , "&",                  1, 1, 0xc039, 0 },
   { s_cr154 +16, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr154 +17, NULL       , "__AcceptStr",       11, 1, 0xc015, 0 },
   { s_cr154 +18, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr154 +19, NULL       , ")",                  1, 0, 0xc033, 0 },
   { s_cr154 +20, NULL       , ")",                  1, 1, 0xc033, 0 },
   { s_cr154 +21, NULL       , ";",                  1, 1, 0xc01e, 0 },
   { NULL       , NULL       , "end",                3, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_cm155[ 5 ] = {
   { s_cm155 + 1, NULL       , "ACCEPT",             6, 1, 0xc015, 0 },
   { s_cm155 + 3, s_cm155 + 2, "[",                  1, 1, 0xe007, 0 },
   { NULL       , NULL       , "msg",                3, 0, 0xe001, 2 },
   { s_cm155 + 4, NULL       , "TO",                 2, 1, 0xc015, 0 },
   { NULL       , NULL       , "v",                  1, 0, 0xe001, 1 }
};
static HB_PP_TOKEN s_cr155[ 6 ] = {
   { s_cr155 + 1, NULL       , "v",                  1, 1, 0xc00b, 1 },
   { s_cr155 + 2, NULL       , ":=",                 2, 1, 0xc03c, 0 },
   { s_cr155 + 3, NULL       , "__Accept",           8, 1, 0xc015, 0 },
   { s_cr155 + 4, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr155 + 5, NULL       , "msg",                3, 1, 0xc00b, 2 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm156[ 5 ] = {
   { s_cm156 + 1, NULL       , "WAIT",               4, 1, 0xc015, 0 },
   { s_cm156 + 3, s_cm156 + 2, "[",                  1, 1, 0xe007, 0 },
   { NULL       , NULL       , "msg",                3, 0, 0xe001, 2 },
   { s_cm156 + 4, NULL       , "TO",                 2, 1, 0xc015, 0 },
   { NULL       , NULL       , "v",                  1, 0, 0xe001, 1 }
};
static HB_PP_TOKEN s_cr156[ 6 ] = {
   { s_cr156 + 1, NULL       , "v",                  1, 1, 0xc00b, 1 },
   { s_cr156 + 2, NULL       , ":=",                 2, 1, 0xc03c, 0 },
   { s_cr156 + 3, NULL       , "__Wait",             6, 1, 0xc015, 0 },
   { s_cr156 + 4, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr156 + 5, NULL       , "msg",                3, 1, 0xc00b, 2 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm157[ 3 ] = {
   { s_cm157 + 1, NULL       , "WAIT",               4, 1, 0xc015, 0 },
   { NULL       , s_cm157 + 2, "[",                  1, 1, 0xe007, 0 },
   { NULL       , NULL       , "msg",                3, 0, 0xe001, 1 }
};
static HB_PP_TOKEN s_cr157[ 4 ] = {
   { s_cr157 + 1, NULL       , "__Wait",             6, 1, 0xc015, 0 },
   { s_cr157 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr157 + 3, NULL       , "msg",                3, 1, 0xc00b, 1 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm158[ 3 ] = {
   { s_cm158 + 1, NULL       , "MENU",               4, 1, 0xc015, 0 },
   { s_cm158 + 2, NULL       , "TO",                 2, 1, 0xc015, 0 },
   { NULL       , NULL       , "v",                  1, 0, 0xe001, 1 }
};
static HB_PP_TOKEN s_cr158[ 26 ] = {
   { s_cr158 + 1, NULL       , "v",                  1, 1, 0xc00b, 1 },
   { s_cr158 + 2, NULL       , ":=",                 2, 1, 0xc03c, 0 },
   { s_cr158 + 3, NULL       , "__MenuTo",           8, 1, 0xc015, 0 },
   { s_cr158 + 4, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr158 + 5, NULL       , "{",                  1, 1, 0xc036, 0 },
   { s_cr158 + 6, NULL       , "|",                  1, 0, 0xc01b, 0 },
   { s_cr158 + 7, NULL       , "_1",                 2, 0, 0xc015, 0 },
   { s_cr158 + 8, NULL       , "|",                  1, 0, 0xc01b, 0 },
   { s_cr158 + 9, NULL       , "if",                 2, 1, 0xc015, 0 },
   { s_cr158 +10, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr158 +11, NULL       , "PCount",             6, 0, 0xc015, 0 },
   { s_cr158 +12, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr158 +13, NULL       , ")",                  1, 0, 0xc033, 0 },
   { s_cr158 +14, NULL       , "==",                 2, 1, 0xc048, 0 },
   { s_cr158 +15, NULL       , "0",                  1, 1, 0xc02a, 0 },
   { s_cr158 +16, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr158 +17, NULL       , "v",                  1, 1, 0xc00b, 1 },
   { s_cr158 +18, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr158 +19, NULL       , "v",                  1, 1, 0xc00b, 1 },
   { s_cr158 +20, NULL       , ":=",                 2, 1, 0xc03c, 0 },
   { s_cr158 +21, NULL       , "_1",                 2, 1, 0xc015, 0 },
   { s_cr158 +22, NULL       , ")",                  1, 0, 0xc033, 0 },
   { s_cr158 +23, NULL       , "}",                  1, 0, 0xc037, 0 },
   { s_cr158 +24, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr158 +25, NULL       , "v",                  1, 1, 0xc00c, 1 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm159[ 12 ] = {
   { s_cm159 + 1, NULL       , "@",                  1, 1, 0xc038, 0 },
   { s_cm159 + 2, NULL       , "row",                3, 0, 0xe001, 1 },
   { s_cm159 + 3, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cm159 + 4, NULL       , "col",                3, 0, 0xe001, 2 },
   { s_cm159 + 5, NULL       , "PROMPT",             6, 1, 0xc015, 0 },
   { s_cm159 + 6, NULL       , "prompt",             6, 0, 0xe001, 3 },
   { s_cm159 + 9, s_cm159 + 7, "[",                  1, 1, 0xe007, 0 },
   { s_cm159 + 8, NULL       , "MESSAGE",            7, 0, 0xc015, 0 },
   { NULL       , NULL       , "msg",                3, 0, 0xe001, 4 },
   { NULL       , s_cm159 +10, "[",                  1, 1, 0xe007, 0 },
   { s_cm159 +11, NULL       , "COLOR",              5, 1, 0xc015, 0 },
   { NULL       , NULL       , "color",              5, 0, 0xe001, 5 }
};
static HB_PP_TOKEN s_cr159[ 12 ] = {
   { s_cr159 + 1, NULL       , "__AtPrompt",        10, 1, 0xc015, 0 },
   { s_cr159 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr159 + 3, NULL       , "row",                3, 1, 0xc00b, 1 },
   { s_cr159 + 4, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr159 + 5, NULL       , "col",                3, 1, 0xc00b, 2 },
   { s_cr159 + 6, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr159 + 7, NULL       , "prompt",             6, 1, 0xc00b, 3 },
   { s_cr159 + 8, NULL       , ",",                  1, 1, 0xc01d, 0 },
   { s_cr159 + 9, NULL       , "msg",                3, 1, 0xc00b, 4 },
   { s_cr159 +10, NULL       , ",",                  1, 1, 0xc01d, 0 },
   { s_cr159 +11, NULL       , "color",              5, 1, 0xc00b, 5 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm160[ 9 ] = {
   { s_cm160 + 1, NULL       , "@",                  1, 1, 0xc038, 0 },
   { s_cm160 + 2, NULL       , "row",                3, 0, 0xe001, 1 },
   { s_cm160 + 3, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cm160 + 4, NULL       , "col",                3, 0, 0xe001, 2 },
   { s_cm160 + 5, NULL       , "SAY",                3, 1, 0xc015, 0 },
   { s_cm160 + 6, NULL       , "exp",                3, 0, 0xe001, 3 },
   { NULL       , s_cm160 + 7, "[",                  1, 1, 0xe007, 0 },
   { s_cm160 + 8, NULL       , "COLOR",              5, 0, 0xc015, 0 },
   { NULL       , NULL       , "clr",                3, 0, 0xe001, 4 }
};
static HB_PP_TOKEN s_cr160[ 14 ] = {
   { s_cr160 + 1, NULL       , "DevPos",             6, 1, 0xc015, 0 },
   { s_cr160 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr160 + 3, NULL       , "row",                3, 1, 0xc00b, 1 },
   { s_cr160 + 4, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr160 + 5, NULL       , "col",                3, 1, 0xc00b, 2 },
   { s_cr160 + 6, NULL       , ")",                  1, 1, 0xc033, 0 },
   { s_cr160 + 7, NULL       , ";",                  1, 1, 0xc01e, 0 },
   { s_cr160 + 8, NULL       , "DevOut",             6, 1, 0xc015, 0 },
   { s_cr160 + 9, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr160 +10, NULL       , "exp",                3, 1, 0xc00b, 3 },
   { s_cr160 +13, s_cr160 +11, "[",                  1, 1, 0xc012, 0 },
   { s_cr160 +12, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { NULL       , NULL       , "clr",                3, 1, 0xc00b, 4 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm161[ 12 ] = {
   { s_cm161 + 1, NULL       , "@",                  1, 1, 0xc038, 0 },
   { s_cm161 + 2, NULL       , "row",                3, 0, 0xe001, 1 },
   { s_cm161 + 3, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cm161 + 4, NULL       , "col",                3, 0, 0xe001, 2 },
   { s_cm161 + 5, NULL       , "SAY",                3, 1, 0xc015, 0 },
   { s_cm161 + 6, NULL       , "exp",                3, 0, 0xe001, 3 },
   { s_cm161 + 9, s_cm161 + 7, "[",                  1, 1, 0xe007, 0 },
   { s_cm161 + 8, NULL       , "PICTURE",            7, 0, 0xc015, 0 },
   { NULL       , NULL       , "pic",                3, 0, 0xe001, 4 },
   { NULL       , s_cm161 +10, "[",                  1, 1, 0xe007, 0 },
   { s_cm161 +11, NULL       , "COLOR",              5, 0, 0xc015, 0 },
   { NULL       , NULL       , "clr",                3, 0, 0xe001, 5 }
};
static HB_PP_TOKEN s_cr161[ 16 ] = {
   { s_cr161 + 1, NULL       , "DevPos",             6, 1, 0xc015, 0 },
   { s_cr161 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr161 + 3, NULL       , "row",                3, 1, 0xc00b, 1 },
   { s_cr161 + 4, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr161 + 5, NULL       , "col",                3, 1, 0xc00b, 2 },
   { s_cr161 + 6, NULL       , ")",                  1, 1, 0xc033, 0 },
   { s_cr161 + 7, NULL       , ";",                  1, 1, 0xc01e, 0 },
   { s_cr161 + 8, NULL       , "DevOutPict",        10, 1, 0xc015, 0 },
   { s_cr161 + 9, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr161 +10, NULL       , "exp",                3, 1, 0xc00b, 3 },
   { s_cr161 +11, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr161 +12, NULL       , "pic",                3, 1, 0xc00b, 4 },
   { s_cr161 +15, s_cr161 +13, "[",                  1, 1, 0xc012, 0 },
   { s_cr161 +14, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { NULL       , NULL       , "clr",                3, 1, 0xc00b, 5 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm162[ 11 ] = {
   { s_cm162 + 1, NULL       , "@",                  1, 1, 0xc038, 0 },
   { s_cm162 + 2, NULL       , "top",                3, 0, 0xe001, 1 },
   { s_cm162 + 3, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cm162 + 4, NULL       , "left",               4, 0, 0xe001, 2 },
   { s_cm162 + 5, NULL       , "TO",                 2, 1, 0xc015, 0 },
   { s_cm162 + 6, NULL       , "bottom",             6, 0, 0xe001, 3 },
   { s_cm162 + 7, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cm162 + 8, NULL       , "right",              5, 0, 0xe001, 4 },
   { NULL       , s_cm162 + 9, "[",                  1, 1, 0xe007, 0 },
   { s_cm162 +10, NULL       , "COLOR",              5, 0, 0xc015, 0 },
   { NULL       , NULL       , "clr",                3, 0, 0xe001, 5 }
};
static HB_PP_TOKEN s_cr162[ 15 ] = {
   { s_cr162 + 1, NULL       , "DispBox",            7, 1, 0xc015, 0 },
   { s_cr162 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr162 + 3, NULL       , "top",                3, 1, 0xc00b, 1 },
   { s_cr162 + 4, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr162 + 5, NULL       , "left",               4, 1, 0xc00b, 2 },
   { s_cr162 + 6, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr162 + 7, NULL       , "bottom",             6, 1, 0xc00b, 3 },
   { s_cr162 + 8, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr162 + 9, NULL       , "right",              5, 1, 0xc00b, 4 },
   { s_cr162 +10, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr162 +11, NULL       , "1",                  1, 1, 0xc02a, 0 },
   { s_cr162 +14, s_cr162 +12, "[",                  1, 1, 0xc012, 0 },
   { s_cr162 +13, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { NULL       , NULL       , "clr",                3, 1, 0xc00b, 5 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm163[ 13 ] = {
   { s_cm163 + 1, NULL       , "@",                  1, 1, 0xc038, 0 },
   { s_cm163 + 2, NULL       , "top",                3, 0, 0xe001, 1 },
   { s_cm163 + 3, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cm163 + 4, NULL       , "left",               4, 0, 0xe001, 2 },
   { s_cm163 + 5, NULL       , "TO",                 2, 1, 0xc015, 0 },
   { s_cm163 + 6, NULL       , "bottom",             6, 0, 0xe001, 3 },
   { s_cm163 + 7, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cm163 + 8, NULL       , "right",              5, 0, 0xe001, 4 },
   { s_cm163 +10, s_cm163 + 9, "[",                  1, 1, 0xe007, 0 },
   { NULL       , NULL       , "DOUBLE",             6, 0, 0xc015, 0 },
   { NULL       , s_cm163 +11, "[",                  1, 1, 0xe007, 0 },
   { s_cm163 +12, NULL       , "COLOR",              5, 0, 0xc015, 0 },
   { NULL       , NULL       , "clr",                3, 0, 0xe001, 5 }
};
static HB_PP_TOKEN s_cr163[ 15 ] = {
   { s_cr163 + 1, NULL       , "DispBox",            7, 1, 0xc015, 0 },
   { s_cr163 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr163 + 3, NULL       , "top",                3, 1, 0xc00b, 1 },
   { s_cr163 + 4, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr163 + 5, NULL       , "left",               4, 1, 0xc00b, 2 },
   { s_cr163 + 6, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr163 + 7, NULL       , "bottom",             6, 1, 0xc00b, 3 },
   { s_cr163 + 8, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr163 + 9, NULL       , "right",              5, 1, 0xc00b, 4 },
   { s_cr163 +10, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr163 +11, NULL       , "2",                  1, 1, 0xc02a, 0 },
   { s_cr163 +14, s_cr163 +12, "[",                  1, 1, 0xc012, 0 },
   { s_cr163 +13, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { NULL       , NULL       , "clr",                3, 1, 0xc00b, 5 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm164[ 13 ] = {
   { s_cm164 + 1, NULL       , "@",                  1, 1, 0xc038, 0 },
   { s_cm164 + 2, NULL       , "top",                3, 0, 0xe001, 1 },
   { s_cm164 + 3, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cm164 + 4, NULL       , "left",               4, 0, 0xe001, 2 },
   { s_cm164 + 5, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cm164 + 6, NULL       , "bottom",             6, 0, 0xe001, 3 },
   { s_cm164 + 7, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cm164 + 8, NULL       , "right",              5, 0, 0xe001, 4 },
   { s_cm164 + 9, NULL       , "BOX",                3, 1, 0xc015, 0 },
   { s_cm164 +10, NULL       , "string",             6, 0, 0xe001, 5 },
   { NULL       , s_cm164 +11, "[",                  1, 1, 0xe007, 0 },
   { s_cm164 +12, NULL       , "COLOR",              5, 0, 0xc015, 0 },
   { NULL       , NULL       , "clr",                3, 0, 0xe001, 6 }
};
static HB_PP_TOKEN s_cr164[ 15 ] = {
   { s_cr164 + 1, NULL       , "DispBox",            7, 1, 0xc015, 0 },
   { s_cr164 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr164 + 3, NULL       , "top",                3, 1, 0xc00b, 1 },
   { s_cr164 + 4, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr164 + 5, NULL       , "left",               4, 1, 0xc00b, 2 },
   { s_cr164 + 6, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr164 + 7, NULL       , "bottom",             6, 1, 0xc00b, 3 },
   { s_cr164 + 8, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr164 + 9, NULL       , "right",              5, 1, 0xc00b, 4 },
   { s_cr164 +10, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr164 +11, NULL       , "string",             6, 1, 0xc00b, 5 },
   { s_cr164 +14, s_cr164 +12, "[",                  1, 1, 0xc012, 0 },
   { s_cr164 +13, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { NULL       , NULL       , "clr",                3, 1, 0xc00b, 6 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm165[ 9 ] = {
   { s_cm165 + 1, NULL       , "@",                  1, 1, 0xc038, 0 },
   { s_cm165 + 2, NULL       , "top",                3, 0, 0xe001, 1 },
   { s_cm165 + 3, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cm165 + 4, NULL       , "left",               4, 0, 0xe001, 2 },
   { s_cm165 + 5, NULL       , "CLEAR",              5, 1, 0xc015, 0 },
   { s_cm165 + 6, NULL       , "TO",                 2, 1, 0xc015, 0 },
   { s_cm165 + 7, NULL       , "bottom",             6, 0, 0xe001, 3 },
   { s_cm165 + 8, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { NULL       , NULL       , "right",              5, 0, 0xe001, 4 }
};
static HB_PP_TOKEN s_cr165[ 17 ] = {
   { s_cr165 + 1, NULL       , "Scroll",             6, 1, 0xc015, 0 },
   { s_cr165 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr165 + 3, NULL       , "top",                3, 1, 0xc00b, 1 },
   { s_cr165 + 4, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr165 + 5, NULL       , "left",               4, 1, 0xc00b, 2 },
   { s_cr165 + 6, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr165 + 7, NULL       , "bottom",             6, 1, 0xc00b, 3 },
   { s_cr165 + 8, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr165 + 9, NULL       , "right",              5, 1, 0xc00b, 4 },
   { s_cr165 +10, NULL       , ")",                  1, 1, 0xc033, 0 },
   { s_cr165 +11, NULL       , ";",                  1, 1, 0xc01e, 0 },
   { s_cr165 +12, NULL       , "SetPos",             6, 1, 0xc015, 0 },
   { s_cr165 +13, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr165 +14, NULL       , "top",                3, 1, 0xc00b, 1 },
   { s_cr165 +15, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr165 +16, NULL       , "left",               4, 1, 0xc00b, 2 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm166[ 5 ] = {
   { s_cm166 + 1, NULL       , "@",                  1, 1, 0xc038, 0 },
   { s_cm166 + 2, NULL       , "top",                3, 0, 0xe001, 1 },
   { s_cm166 + 3, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cm166 + 4, NULL       , "left",               4, 0, 0xe001, 2 },
   { NULL       , NULL       , "CLEAR",              5, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_cr166[ 13 ] = {
   { s_cr166 + 1, NULL       , "Scroll",             6, 1, 0xc015, 0 },
   { s_cr166 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr166 + 3, NULL       , "top",                3, 1, 0xc00b, 1 },
   { s_cr166 + 4, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr166 + 5, NULL       , "left",               4, 1, 0xc00b, 2 },
   { s_cr166 + 6, NULL       , ")",                  1, 1, 0xc033, 0 },
   { s_cr166 + 7, NULL       , ";",                  1, 1, 0xc01e, 0 },
   { s_cr166 + 8, NULL       , "SetPos",             6, 1, 0xc015, 0 },
   { s_cr166 + 9, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr166 +10, NULL       , "top",                3, 1, 0xc00b, 1 },
   { s_cr166 +11, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr166 +12, NULL       , "left",               4, 1, 0xc00b, 2 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm167[ 4 ] = {
   { s_cm167 + 1, NULL       , "@",                  1, 1, 0xc038, 0 },
   { s_cm167 + 2, NULL       , "row",                3, 0, 0xe001, 1 },
   { s_cm167 + 3, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { NULL       , NULL       , "col",                3, 0, 0xe001, 2 }
};
static HB_PP_TOKEN s_cr167[ 15 ] = {
   { s_cr167 + 1, NULL       , "Scroll",             6, 1, 0xc015, 0 },
   { s_cr167 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr167 + 3, NULL       , "row",                3, 1, 0xc00b, 1 },
   { s_cr167 + 4, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr167 + 5, NULL       , "col",                3, 1, 0xc00b, 2 },
   { s_cr167 + 6, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr167 + 7, NULL       , "row",                3, 1, 0xc00b, 1 },
   { s_cr167 + 8, NULL       , ")",                  1, 1, 0xc033, 0 },
   { s_cr167 + 9, NULL       , ";",                  1, 1, 0xc01e, 0 },
   { s_cr167 +10, NULL       , "SetPos",             6, 1, 0xc015, 0 },
   { s_cr167 +11, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr167 +12, NULL       , "row",                3, 1, 0xc00b, 1 },
   { s_cr167 +13, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr167 +14, NULL       , "col",                3, 1, 0xc00b, 2 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm168[ 4 ] = {
   { s_cm168 + 1, NULL       , "RESTORE",            7, 1, 0xc015, 0 },
   { s_cm168 + 2, NULL       , "SCREEN",             6, 1, 0xc015, 0 },
   { s_cm168 + 3, NULL       , "FROM",               4, 1, 0xc015, 0 },
   { NULL       , NULL       , "v",                  1, 0, 0xe001, 1 }
};
static HB_PP_TOKEN s_cr168[ 16 ] = {
   { s_cr168 + 1, NULL       , "RestScreen",        10, 1, 0xc015, 0 },
   { s_cr168 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr168 + 3, NULL       , "0",                  1, 1, 0xc02a, 0 },
   { s_cr168 + 4, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr168 + 5, NULL       , "0",                  1, 1, 0xc02a, 0 },
   { s_cr168 + 6, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr168 + 7, NULL       , "Maxrow",             6, 1, 0xc015, 0 },
   { s_cr168 + 8, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr168 + 9, NULL       , ")",                  1, 0, 0xc033, 0 },
   { s_cr168 +10, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr168 +11, NULL       , "Maxcol",             6, 1, 0xc015, 0 },
   { s_cr168 +12, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr168 +13, NULL       , ")",                  1, 0, 0xc033, 0 },
   { s_cr168 +14, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr168 +15, NULL       , "v",                  1, 1, 0xc00b, 1 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm169[ 4 ] = {
   { s_cm169 + 1, NULL       , "SAVE",               4, 1, 0xc015, 0 },
   { s_cm169 + 2, NULL       , "SCREEN",             6, 1, 0xc015, 0 },
   { s_cm169 + 3, NULL       , "TO",                 2, 1, 0xc015, 0 },
   { NULL       , NULL       , "v",                  1, 0, 0xe001, 1 }
};
static HB_PP_TOKEN s_cr169[ 16 ] = {
   { s_cr169 + 1, NULL       , "v",                  1, 1, 0xc00b, 1 },
   { s_cr169 + 2, NULL       , ":=",                 2, 1, 0xc03c, 0 },
   { s_cr169 + 3, NULL       , "SaveScreen",        10, 1, 0xc015, 0 },
   { s_cr169 + 4, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr169 + 5, NULL       , "0",                  1, 1, 0xc02a, 0 },
   { s_cr169 + 6, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr169 + 7, NULL       , "0",                  1, 1, 0xc02a, 0 },
   { s_cr169 + 8, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr169 + 9, NULL       , "Maxrow",             6, 1, 0xc015, 0 },
   { s_cr169 +10, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr169 +11, NULL       , ")",                  1, 0, 0xc033, 0 },
   { s_cr169 +12, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr169 +13, NULL       , "Maxcol",             6, 1, 0xc015, 0 },
   { s_cr169 +14, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr169 +15, NULL       , ")",                  1, 0, 0xc033, 0 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm170[ 2 ] = {
   { s_cm170 + 1, NULL       , "RESTORE",            7, 1, 0xc015, 0 },
   { NULL       , NULL       , "SCREEN",             6, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_cr170[ 3 ] = {
   { s_cr170 + 1, NULL       , "__XRestScreen",     13, 1, 0xc015, 0 },
   { s_cr170 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { NULL       , NULL       , ")",                  1, 0, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm171[ 2 ] = {
   { s_cm171 + 1, NULL       , "SAVE",               4, 1, 0xc015, 0 },
   { NULL       , NULL       , "SCREEN",             6, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_cr171[ 3 ] = {
   { s_cr171 + 1, NULL       , "__XSaveScreen",     13, 1, 0xc015, 0 },
   { s_cr171 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { NULL       , NULL       , ")",                  1, 0, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm172[ 2 ] = {
   { s_cm172 + 1, NULL       , "CLEAR",              5, 1, 0xc015, 0 },
   { NULL       , NULL       , "SCREEN",             6, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_cr172[ 1 ] = {
   { NULL       , NULL       , "CLS",                3, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_cm173[ 1 ] = {
   { NULL       , NULL       , "CLS",                3, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_cr173[ 10 ] = {
   { s_cr173 + 1, NULL       , "Scroll",             6, 1, 0xc015, 0 },
   { s_cr173 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr173 + 3, NULL       , ")",                  1, 0, 0xc033, 0 },
   { s_cr173 + 4, NULL       , ";",                  1, 1, 0xc01e, 0 },
   { s_cr173 + 5, NULL       , "SetPos",             6, 1, 0xc015, 0 },
   { s_cr173 + 6, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr173 + 7, NULL       , "0",                  1, 0, 0xc02a, 0 },
   { s_cr173 + 8, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr173 + 9, NULL       , "0",                  1, 0, 0xc02a, 0 },
   { NULL       , NULL       , ")",                  1, 0, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm174[ 2 ] = {
   { s_cm174 + 1, NULL       , "TEXTBLOCK",          9, 1, 0xc015, 0 },
   { NULL       , NULL       , "cText",              5, 0, 0xe004, 0 }
};
static HB_PP_TOKEN s_cm175[ 3 ] = {
   { s_cm175 + 1, NULL       , "TEXT",               4, 1, 0xc015, 0 },
   { s_cm175 + 2, NULL       , "INTO",               4, 1, 0xc015, 0 },
   { NULL       , NULL       , "lValue",             6, 0, 0xe001, 1 }
};
static HB_PP_TOKEN s_cr175[ 20 ] = {
   { s_cr175 + 1, NULL       , "lValue",             6, 1, 0xc00b, 1 },
   { s_cr175 + 2, NULL       , ":=",                 2, 1, 0xc03c, 0 },
   { s_cr175 + 3, NULL       , "",                   0, 1, 0xc029, 0 },
   { s_cr175 + 4, NULL       , ";",                  1, 1, 0xc01e, 0 },
   { s_cr175 + 5, NULL       , "hb_setwith",        10, 1, 0xc015, 0 },
   { s_cr175 + 6, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr175 + 7, NULL       , "{",                  1, 1, 0xc036, 0 },
   { s_cr175 + 8, NULL       , "|",                  1, 0, 0xc01b, 0 },
   { s_cr175 + 9, NULL       , "_1",                 2, 0, 0xc015, 0 },
   { s_cr175 +10, NULL       , "|",                  1, 0, 0xc01b, 0 },
   { s_cr175 +11, NULL       , "lValue",             6, 1, 0xc00b, 1 },
   { s_cr175 +12, NULL       , "+=",                 2, 1, 0xc03d, 0 },
   { s_cr175 +13, NULL       , "_1",                 2, 1, 0xc015, 0 },
   { s_cr175 +14, NULL       , "}",                  1, 1, 0xc037, 0 },
   { s_cr175 +15, NULL       , ")",                  1, 1, 0xc033, 0 },
   { s_cr175 +16, NULL       , ";",                  1, 0, 0xc01e, 0 },
   { s_cr175 +17, NULL       , "text",               4, 1, 0xc015, 0 },
   { s_cr175 +18, NULL       , "__TextInto",        10, 1, 0xc015, 0 },
   { s_cr175 +19, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { NULL       , NULL       , "hb_SetWith",        10, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_cm176[ 3 ] = {
   { s_cm176 + 1, NULL       , "TEXT",               4, 1, 0xc015, 0 },
   { s_cm176 + 2, NULL       , "TO",                 2, 1, 0xc015, 0 },
   { NULL       , NULL       , "PRINTER",            7, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_cr176[ 9 ] = {
   { s_cr176 + 1, NULL       , "__TextSave",        10, 1, 0xc015, 0 },
   { s_cr176 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr176 + 3, NULL       , "PRINTER",            7, 1, 0xc029, 0 },
   { s_cr176 + 4, NULL       , ")",                  1, 1, 0xc033, 0 },
   { s_cr176 + 5, NULL       , ";",                  1, 1, 0xc01e, 0 },
   { s_cr176 + 6, NULL       , "text",               4, 1, 0xc015, 0 },
   { s_cr176 + 7, NULL       , "QOut",               4, 1, 0xc015, 0 },
   { s_cr176 + 8, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { NULL       , NULL       , "__TextRestore",     13, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_cm177[ 4 ] = {
   { s_cm177 + 1, NULL       , "TEXT",               4, 1, 0xc015, 0 },
   { s_cm177 + 2, NULL       , "TO",                 2, 1, 0xc015, 0 },
   { s_cm177 + 3, NULL       , "FILE",               4, 1, 0xc015, 0 },
   { NULL       , NULL       , "f",                  1, 0, 0xe005, 1 }
};
static HB_PP_TOKEN s_cr177[ 9 ] = {
   { s_cr177 + 1, NULL       , "__TextSave",        10, 1, 0xc015, 0 },
   { s_cr177 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr177 + 3, NULL       , "f",                  1, 1, 0xc00e, 1 },
   { s_cr177 + 4, NULL       , ")",                  1, 1, 0xc033, 0 },
   { s_cr177 + 5, NULL       , ";",                  1, 1, 0xc01e, 0 },
   { s_cr177 + 6, NULL       , "text",               4, 1, 0xc015, 0 },
   { s_cr177 + 7, NULL       , "QOut",               4, 1, 0xc015, 0 },
   { s_cr177 + 8, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { NULL       , NULL       , "__TextRestore",     13, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_cm178[ 1 ] = {
   { NULL       , NULL       , "TEXT",               4, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_cr178[ 4 ] = {
   { s_cr178 + 1, NULL       , "text",               4, 1, 0xc015, 0 },
   { s_cr178 + 2, NULL       , "QOut",               4, 1, 0xc015, 0 },
   { s_cr178 + 3, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { NULL       , NULL       , "QQOut",              5, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_cm179[ 1 ] = {
   { NULL       , NULL       , "EJECT",              5, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_cr179[ 3 ] = {
   { s_cr179 + 1, NULL       , "__Eject",            7, 1, 0xc015, 0 },
   { s_cr179 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { NULL       , NULL       , ")",                  1, 0, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm180[ 4 ] = {
   { s_cm180 + 1, NULL       , "?",                  1, 1, 0xc019, 0 },
   { s_cm180 + 2, NULL       , "?",                  1, 0, 0xc019, 0 },
   { NULL       , s_cm180 + 3, "[",                  1, 1, 0xe007, 0 },
   { NULL       , NULL       , "explist",            7, 0, 0xe002, 1 }
};
static HB_PP_TOKEN s_cr180[ 4 ] = {
   { s_cr180 + 1, NULL       , "QQOut",              5, 1, 0xc015, 0 },
   { s_cr180 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr180 + 3, NULL       , "explist",            7, 1, 0xc00b, 1 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm181[ 3 ] = {
   { s_cm181 + 1, NULL       , "?",                  1, 1, 0xc019, 0 },
   { NULL       , s_cm181 + 2, "[",                  1, 1, 0xe007, 0 },
   { NULL       , NULL       , "explist",            7, 0, 0xe002, 1 }
};
static HB_PP_TOKEN s_cr181[ 4 ] = {
   { s_cr181 + 1, NULL       , "QOut",               4, 1, 0xc015, 0 },
   { s_cr181 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr181 + 3, NULL       , "explist",            7, 1, 0xc00b, 1 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm182[ 5 ] = {
   { s_cm182 + 1, NULL       , "SET",                3, 1, 0xc015, 0 },
   { s_cm182 + 2, NULL       , "AUTOPEN",            7, 1, 0xc015, 0 },
   { s_cm182 + 3, NULL       , "(",                  1, 1, 0xc032, 0 },
   { s_cm182 + 4, NULL       , "x",                  1, 0, 0xe001, 1 },
   { NULL       , NULL       , ")",                  1, 0, 0xc033, 0 }
};
static HB_PP_TOKEN s_cr182[ 6 ] = {
   { s_cr182 + 1, NULL       , "Set",                3, 1, 0xc015, 0 },
   { s_cr182 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr182 + 3, NULL       , "_SET_AUTOPEN",      12, 1, 0xc015, 0 },
   { s_cr182 + 4, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr182 + 5, NULL       , "x",                  1, 1, 0xc00b, 1 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm183[ 8 ] = {
   { s_cm183 + 1, NULL       , "SET",                3, 1, 0xc015, 0 },
   { s_cm183 + 2, NULL       , "AUTOPEN",            7, 1, 0xc015, 0 },
   { NULL       , s_cm183 + 3, "x",                  1, 0, 0xc003, 1 },
   { s_cm183 + 4, NULL       , "ON",                 2, 0, 0xc015, 0 },
   { s_cm183 + 5, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cm183 + 6, NULL       , "OFF",                3, 0, 0xc015, 0 },
   { s_cm183 + 7, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { NULL       , NULL       , "&",                  1, 0, 0xc039, 0 }
};
static HB_PP_TOKEN s_cr183[ 6 ] = {
   { s_cr183 + 1, NULL       , "Set",                3, 1, 0xc015, 0 },
   { s_cr183 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr183 + 3, NULL       , "_SET_AUTOPEN",      12, 1, 0xc015, 0 },
   { s_cr183 + 4, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr183 + 5, NULL       , "x",                  1, 1, 0xc00e, 1 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm184[ 5 ] = {
   { s_cm184 + 1, NULL       , "SET",                3, 1, 0xc015, 0 },
   { s_cm184 + 2, NULL       , "OPTIMIZE",           8, 1, 0xc015, 0 },
   { s_cm184 + 3, NULL       , "(",                  1, 1, 0xc032, 0 },
   { s_cm184 + 4, NULL       , "x",                  1, 0, 0xe001, 1 },
   { NULL       , NULL       , ")",                  1, 0, 0xc033, 0 }
};
static HB_PP_TOKEN s_cr184[ 6 ] = {
   { s_cr184 + 1, NULL       , "Set",                3, 1, 0xc015, 0 },
   { s_cr184 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr184 + 3, NULL       , "_SET_OPTIMIZE",     13, 1, 0xc015, 0 },
   { s_cr184 + 4, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr184 + 5, NULL       , "x",                  1, 1, 0xc00b, 1 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm185[ 8 ] = {
   { s_cm185 + 1, NULL       , "SET",                3, 1, 0xc015, 0 },
   { s_cm185 + 2, NULL       , "OPTIMIZE",           8, 1, 0xc015, 0 },
   { NULL       , s_cm185 + 3, "x",                  1, 0, 0xc003, 1 },
   { s_cm185 + 4, NULL       , "ON",                 2, 0, 0xc015, 0 },
   { s_cm185 + 5, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cm185 + 6, NULL       , "OFF",                3, 0, 0xc015, 0 },
   { s_cm185 + 7, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { NULL       , NULL       , "&",                  1, 0, 0xc039, 0 }
};
static HB_PP_TOKEN s_cr185[ 6 ] = {
   { s_cr185 + 1, NULL       , "Set",                3, 1, 0xc015, 0 },
   { s_cr185 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr185 + 3, NULL       , "_SET_OPTIMIZE",     13, 1, 0xc015, 0 },
   { s_cr185 + 4, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr185 + 5, NULL       , "x",                  1, 1, 0xc00e, 1 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm186[ 5 ] = {
   { s_cm186 + 1, NULL       , "SET",                3, 1, 0xc015, 0 },
   { s_cm186 + 2, NULL       , "STRICTREAD",        10, 1, 0xc015, 0 },
   { s_cm186 + 3, NULL       , "(",                  1, 1, 0xc032, 0 },
   { s_cm186 + 4, NULL       , "x",                  1, 0, 0xe001, 1 },
   { NULL       , NULL       , ")",                  1, 0, 0xc033, 0 }
};
static HB_PP_TOKEN s_cr186[ 6 ] = {
   { s_cr186 + 1, NULL       , "Set",                3, 1, 0xc015, 0 },
   { s_cr186 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr186 + 3, NULL       , "_SET_STRICTREAD",   15, 1, 0xc015, 0 },
   { s_cr186 + 4, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr186 + 5, NULL       , "x",                  1, 1, 0xc00b, 1 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm187[ 8 ] = {
   { s_cm187 + 1, NULL       , "SET",                3, 1, 0xc015, 0 },
   { s_cm187 + 2, NULL       , "STRICTREAD",        10, 1, 0xc015, 0 },
   { NULL       , s_cm187 + 3, "x",                  1, 0, 0xc003, 1 },
   { s_cm187 + 4, NULL       , "ON",                 2, 0, 0xc015, 0 },
   { s_cm187 + 5, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cm187 + 6, NULL       , "OFF",                3, 0, 0xc015, 0 },
   { s_cm187 + 7, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { NULL       , NULL       , "&",                  1, 0, 0xc039, 0 }
};
static HB_PP_TOKEN s_cr187[ 6 ] = {
   { s_cr187 + 1, NULL       , "Set",                3, 1, 0xc015, 0 },
   { s_cr187 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr187 + 3, NULL       , "_SET_STRICTREAD",   15, 1, 0xc015, 0 },
   { s_cr187 + 4, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr187 + 5, NULL       , "x",                  1, 1, 0xc00e, 1 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm188[ 4 ] = {
   { s_cm188 + 1, NULL       , "SET",                3, 1, 0xc015, 0 },
   { s_cm188 + 2, NULL       , "MFILEEXT",           8, 1, 0xc015, 0 },
   { s_cm188 + 3, NULL       , "TO",                 2, 1, 0xc015, 0 },
   { NULL       , NULL       , "x",                  1, 0, 0xe001, 1 }
};
static HB_PP_TOKEN s_cr188[ 6 ] = {
   { s_cr188 + 1, NULL       , "Set",                3, 1, 0xc015, 0 },
   { s_cr188 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr188 + 3, NULL       , "_SET_MFILEEXT",     13, 1, 0xc015, 0 },
   { s_cr188 + 4, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr188 + 5, NULL       , "x",                  1, 1, 0xc00b, 1 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm189[ 4 ] = {
   { s_cm189 + 1, NULL       , "SET",                3, 1, 0xc015, 0 },
   { s_cm189 + 2, NULL       , "MEMOBLOCK",          9, 1, 0xc015, 0 },
   { s_cm189 + 3, NULL       , "TO",                 2, 1, 0xc015, 0 },
   { NULL       , NULL       , "x",                  1, 0, 0xe001, 1 }
};
static HB_PP_TOKEN s_cr189[ 6 ] = {
   { s_cr189 + 1, NULL       , "Set",                3, 1, 0xc015, 0 },
   { s_cr189 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr189 + 3, NULL       , "_SET_MBLOCKSIZE",   15, 1, 0xc015, 0 },
   { s_cr189 + 4, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr189 + 5, NULL       , "x",                  1, 1, 0xc00b, 1 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm190[ 4 ] = {
   { s_cm190 + 1, NULL       , "SET",                3, 1, 0xc015, 0 },
   { s_cm190 + 2, NULL       , "MBLOCKSIZE",        10, 1, 0xc015, 0 },
   { s_cm190 + 3, NULL       , "TO",                 2, 1, 0xc015, 0 },
   { NULL       , NULL       , "x",                  1, 0, 0xe001, 1 }
};
static HB_PP_TOKEN s_cr190[ 6 ] = {
   { s_cr190 + 1, NULL       , "Set",                3, 1, 0xc015, 0 },
   { s_cr190 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr190 + 3, NULL       , "_SET_MBLOCKSIZE",   15, 1, 0xc015, 0 },
   { s_cr190 + 4, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr190 + 5, NULL       , "x",                  1, 1, 0xc00b, 1 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm191[ 4 ] = {
   { s_cm191 + 1, NULL       , "SET",                3, 1, 0xc015, 0 },
   { s_cm191 + 2, NULL       , "AUTOSHARE",          9, 1, 0xc015, 0 },
   { s_cm191 + 3, NULL       , "TO",                 2, 1, 0xc015, 0 },
   { NULL       , NULL       , "x",                  1, 0, 0xe001, 1 }
};
static HB_PP_TOKEN s_cr191[ 6 ] = {
   { s_cr191 + 1, NULL       , "Set",                3, 1, 0xc015, 0 },
   { s_cr191 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr191 + 3, NULL       , "_SET_AUTOSHARE",    14, 1, 0xc015, 0 },
   { s_cr191 + 4, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr191 + 5, NULL       , "x",                  1, 1, 0xc00b, 1 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm192[ 3 ] = {
   { s_cm192 + 1, NULL       , "SET",                3, 1, 0xc015, 0 },
   { s_cm192 + 2, NULL       , "AUTOSHARE",          9, 1, 0xc015, 0 },
   { NULL       , NULL       , "TO",                 2, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_cr192[ 6 ] = {
   { s_cr192 + 1, NULL       , "Set",                3, 1, 0xc015, 0 },
   { s_cr192 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr192 + 3, NULL       , "_SET_AUTOSHARE",    14, 1, 0xc015, 0 },
   { s_cr192 + 4, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr192 + 5, NULL       , "0",                  1, 1, 0xc02a, 0 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm193[ 4 ] = {
   { s_cm193 + 1, NULL       , "SET",                3, 1, 0xc015, 0 },
   { s_cm193 + 2, NULL       , "AUTORDER",           8, 1, 0xc015, 0 },
   { s_cm193 + 3, NULL       , "TO",                 2, 1, 0xc015, 0 },
   { NULL       , NULL       , "x",                  1, 0, 0xe001, 1 }
};
static HB_PP_TOKEN s_cr193[ 6 ] = {
   { s_cr193 + 1, NULL       , "Set",                3, 1, 0xc015, 0 },
   { s_cr193 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr193 + 3, NULL       , "_SET_AUTORDER",     13, 1, 0xc015, 0 },
   { s_cr193 + 4, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr193 + 5, NULL       , "x",                  1, 1, 0xc00b, 1 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm194[ 3 ] = {
   { s_cm194 + 1, NULL       , "SET",                3, 1, 0xc015, 0 },
   { s_cm194 + 2, NULL       , "AUTORDER",           8, 1, 0xc015, 0 },
   { NULL       , NULL       , "TO",                 2, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_cr194[ 6 ] = {
   { s_cr194 + 1, NULL       , "Set",                3, 1, 0xc015, 0 },
   { s_cr194 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr194 + 3, NULL       , "_SET_AUTORDER",     13, 1, 0xc015, 0 },
   { s_cr194 + 4, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr194 + 5, NULL       , "0",                  1, 1, 0xc02a, 0 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm195[ 3 ] = {
   { s_cm195 + 1, NULL       , "SET",                3, 1, 0xc015, 0 },
   { s_cm195 + 2, NULL       , "DESCENDING",        10, 1, 0xc015, 0 },
   { NULL       , NULL       , "OFF",                3, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_cr195[ 6 ] = {
   { s_cr195 + 1, NULL       , "ordDescend",        10, 1, 0xc015, 0 },
   { s_cr195 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr195 + 3, NULL       , ",",                  1, 1, 0xc01d, 0 },
   { s_cr195 + 4, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr195 + 5, NULL       , ".F.",                3, 1, 0xc02c, 0 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm196[ 3 ] = {
   { s_cm196 + 1, NULL       , "SET",                3, 1, 0xc015, 0 },
   { s_cm196 + 2, NULL       , "DESCENDING",        10, 1, 0xc015, 0 },
   { NULL       , NULL       , "ON",                 2, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_cr196[ 6 ] = {
   { s_cr196 + 1, NULL       , "ordDescend",        10, 1, 0xc015, 0 },
   { s_cr196 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr196 + 3, NULL       , ",",                  1, 1, 0xc01d, 0 },
   { s_cr196 + 4, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr196 + 5, NULL       , ".T.",                3, 1, 0xc02c, 0 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm197[ 3 ] = {
   { s_cm197 + 1, NULL       , "SET",                3, 1, 0xc015, 0 },
   { s_cm197 + 2, NULL       , "ORDER",              5, 1, 0xc015, 0 },
   { NULL       , NULL       , "TO",                 2, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_cr197[ 4 ] = {
   { s_cr197 + 1, NULL       , "ordSetFocus",       11, 1, 0xc015, 0 },
   { s_cr197 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr197 + 3, NULL       , "0",                  1, 1, 0xc02a, 0 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm198[ 5 ] = {
   { s_cm198 + 1, NULL       , "SET",                3, 1, 0xc015, 0 },
   { s_cm198 + 2, NULL       , "SCOPE",              5, 1, 0xc015, 0 },
   { s_cm198 + 3, NULL       , "TO",                 2, 1, 0xc015, 0 },
   { s_cm198 + 4, NULL       , ",",                  1, 1, 0xc01d, 0 },
   { NULL       , NULL       , "x",                  1, 0, 0xe001, 1 }
};
static HB_PP_TOKEN s_cr198[ 6 ] = {
   { s_cr198 + 1, NULL       , "ordScope",           8, 1, 0xc015, 0 },
   { s_cr198 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr198 + 3, NULL       , "1",                  1, 1, 0xc02a, 0 },
   { s_cr198 + 4, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr198 + 5, NULL       , "x",                  1, 1, 0xc00b, 1 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm199[ 4 ] = {
   { s_cm199 + 1, NULL       , "SET",                3, 1, 0xc015, 0 },
   { s_cm199 + 2, NULL       , "SCOPE",              5, 1, 0xc015, 0 },
   { s_cm199 + 3, NULL       , "TO",                 2, 1, 0xc015, 0 },
   { NULL       , NULL       , "x",                  1, 0, 0xe001, 1 }
};
static HB_PP_TOKEN s_cr199[ 13 ] = {
   { s_cr199 + 1, NULL       , "ordScope",           8, 1, 0xc015, 0 },
   { s_cr199 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr199 + 3, NULL       , "0",                  1, 1, 0xc02a, 0 },
   { s_cr199 + 4, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr199 + 5, NULL       , "x",                  1, 1, 0xc00b, 1 },
   { s_cr199 + 6, NULL       , ")",                  1, 1, 0xc033, 0 },
   { s_cr199 + 7, NULL       , ";",                  1, 1, 0xc01e, 0 },
   { s_cr199 + 8, NULL       , "ordScope",           8, 1, 0xc015, 0 },
   { s_cr199 + 9, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr199 +10, NULL       , "1",                  1, 1, 0xc02a, 0 },
   { s_cr199 +11, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr199 +12, NULL       , "x",                  1, 1, 0xc00b, 1 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm200[ 6 ] = {
   { s_cm200 + 1, NULL       , "SET",                3, 1, 0xc015, 0 },
   { s_cm200 + 2, NULL       , "SCOPE",              5, 1, 0xc015, 0 },
   { s_cm200 + 3, NULL       , "TO",                 2, 1, 0xc015, 0 },
   { s_cm200 + 4, NULL       , "x",                  1, 0, 0xe001, 1 },
   { s_cm200 + 5, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { NULL       , NULL       , "y",                  1, 0, 0xe001, 2 }
};
static HB_PP_TOKEN s_cr200[ 13 ] = {
   { s_cr200 + 1, NULL       , "ordScope",           8, 1, 0xc015, 0 },
   { s_cr200 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr200 + 3, NULL       , "0",                  1, 1, 0xc02a, 0 },
   { s_cr200 + 4, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr200 + 5, NULL       , "x",                  1, 1, 0xc00b, 1 },
   { s_cr200 + 6, NULL       , ")",                  1, 1, 0xc033, 0 },
   { s_cr200 + 7, NULL       , ";",                  1, 1, 0xc01e, 0 },
   { s_cr200 + 8, NULL       , "ordScope",           8, 1, 0xc015, 0 },
   { s_cr200 + 9, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr200 +10, NULL       , "1",                  1, 1, 0xc02a, 0 },
   { s_cr200 +11, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr200 +12, NULL       , "y",                  1, 1, 0xc00b, 2 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm201[ 3 ] = {
   { s_cm201 + 1, NULL       , "SET",                3, 1, 0xc015, 0 },
   { s_cm201 + 2, NULL       , "SCOPE",              5, 1, 0xc015, 0 },
   { NULL       , NULL       , "TO",                 2, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_cr201[ 13 ] = {
   { s_cr201 + 1, NULL       , "ordScope",           8, 1, 0xc015, 0 },
   { s_cr201 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr201 + 3, NULL       , "0",                  1, 1, 0xc02a, 0 },
   { s_cr201 + 4, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr201 + 5, NULL       , "nil",                3, 1, 0xc015, 0 },
   { s_cr201 + 6, NULL       , ")",                  1, 1, 0xc033, 0 },
   { s_cr201 + 7, NULL       , ";",                  1, 1, 0xc01e, 0 },
   { s_cr201 + 8, NULL       , "ordScope",           8, 1, 0xc015, 0 },
   { s_cr201 + 9, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr201 +10, NULL       , "1",                  1, 1, 0xc02a, 0 },
   { s_cr201 +11, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr201 +12, NULL       , "nil",                3, 1, 0xc015, 0 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm202[ 4 ] = {
   { s_cm202 + 1, NULL       , "SET",                3, 1, 0xc015, 0 },
   { s_cm202 + 2, NULL       , "SCOPEBOTTOM",       11, 1, 0xc015, 0 },
   { s_cm202 + 3, NULL       , "TO",                 2, 1, 0xc015, 0 },
   { NULL       , NULL       , "x",                  1, 0, 0xe001, 1 }
};
static HB_PP_TOKEN s_cr202[ 6 ] = {
   { s_cr202 + 1, NULL       , "ordScope",           8, 1, 0xc015, 0 },
   { s_cr202 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr202 + 3, NULL       , "1",                  1, 1, 0xc02a, 0 },
   { s_cr202 + 4, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr202 + 5, NULL       , "x",                  1, 1, 0xc00b, 1 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm203[ 3 ] = {
   { s_cm203 + 1, NULL       , "SET",                3, 1, 0xc015, 0 },
   { s_cm203 + 2, NULL       , "SCOPEBOTTOM",       11, 1, 0xc015, 0 },
   { NULL       , NULL       , "TO",                 2, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_cr203[ 6 ] = {
   { s_cr203 + 1, NULL       , "ordScope",           8, 1, 0xc015, 0 },
   { s_cr203 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr203 + 3, NULL       , "1",                  1, 1, 0xc02a, 0 },
   { s_cr203 + 4, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr203 + 5, NULL       , "nil",                3, 1, 0xc015, 0 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm204[ 4 ] = {
   { s_cm204 + 1, NULL       , "SET",                3, 1, 0xc015, 0 },
   { s_cm204 + 2, NULL       , "SCOPETOP",           8, 1, 0xc015, 0 },
   { s_cm204 + 3, NULL       , "TO",                 2, 1, 0xc015, 0 },
   { NULL       , NULL       , "x",                  1, 0, 0xe001, 1 }
};
static HB_PP_TOKEN s_cr204[ 6 ] = {
   { s_cr204 + 1, NULL       , "ordScope",           8, 1, 0xc015, 0 },
   { s_cr204 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr204 + 3, NULL       , "0",                  1, 1, 0xc02a, 0 },
   { s_cr204 + 4, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr204 + 5, NULL       , "x",                  1, 1, 0xc00b, 1 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm205[ 3 ] = {
   { s_cm205 + 1, NULL       , "SET",                3, 1, 0xc015, 0 },
   { s_cm205 + 2, NULL       , "SCOPETOP",           8, 1, 0xc015, 0 },
   { NULL       , NULL       , "TO",                 2, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_cr205[ 6 ] = {
   { s_cr205 + 1, NULL       , "ordScope",           8, 1, 0xc015, 0 },
   { s_cr205 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr205 + 3, NULL       , "0",                  1, 1, 0xc02a, 0 },
   { s_cr205 + 4, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr205 + 5, NULL       , "nil",                3, 1, 0xc015, 0 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm206[ 4 ] = {
   { s_cm206 + 1, NULL       , "SET",                3, 1, 0xc015, 0 },
   { s_cm206 + 2, NULL       , "VIDEOMODE",          9, 1, 0xc015, 0 },
   { s_cm206 + 3, NULL       , "TO",                 2, 1, 0xc015, 0 },
   { NULL       , NULL       , "x",                  1, 0, 0xe001, 1 }
};
static HB_PP_TOKEN s_cr206[ 6 ] = {
   { s_cr206 + 1, NULL       , "Set",                3, 1, 0xc015, 0 },
   { s_cr206 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr206 + 3, NULL       , "_SET_VIDEOMODE",    14, 1, 0xc015, 0 },
   { s_cr206 + 4, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr206 + 5, NULL       , "x",                  1, 1, 0xc00b, 1 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm207[ 4 ] = {
   { s_cm207 + 1, NULL       , "SET",                3, 1, 0xc015, 0 },
   { s_cm207 + 2, NULL       , "EVENTMASK",          9, 1, 0xc015, 0 },
   { s_cm207 + 3, NULL       , "TO",                 2, 1, 0xc015, 0 },
   { NULL       , NULL       , "x",                  1, 0, 0xe001, 1 }
};
static HB_PP_TOKEN s_cr207[ 6 ] = {
   { s_cr207 + 1, NULL       , "Set",                3, 1, 0xc015, 0 },
   { s_cr207 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr207 + 3, NULL       , "_SET_EVENTMASK",    14, 1, 0xc015, 0 },
   { s_cr207 + 4, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr207 + 5, NULL       , "x",                  1, 1, 0xc00b, 1 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm208[ 7 ] = {
   { s_cm208 + 1, NULL       , "SET",                3, 1, 0xc015, 0 },
   { s_cm208 + 2, NULL       , "FUNCTION",           8, 1, 0xc015, 0 },
   { s_cm208 + 3, NULL       , "n",                  1, 0, 0xe001, 1 },
   { s_cm208 + 5, s_cm208 + 4, "[",                  1, 1, 0xe007, 0 },
   { NULL       , NULL       , "TO",                 2, 0, 0xc015, 0 },
   { NULL       , s_cm208 + 6, "[",                  1, 1, 0xe007, 0 },
   { NULL       , NULL       , "f",                  1, 0, 0xe001, 2 }
};
static HB_PP_TOKEN s_cr208[ 6 ] = {
   { s_cr208 + 1, NULL       , "__SetFunction",     13, 1, 0xc015, 0 },
   { s_cr208 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr208 + 3, NULL       , "n",                  1, 1, 0xc00b, 1 },
   { s_cr208 + 4, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr208 + 5, NULL       , "f",                  1, 1, 0xc00b, 2 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm209[ 5 ] = {
   { s_cm209 + 1, NULL       , "SET",                3, 1, 0xc015, 0 },
   { s_cm209 + 2, NULL       , "KEY",                3, 1, 0xc015, 0 },
   { s_cm209 + 3, NULL       , "n",                  1, 0, 0xe001, 1 },
   { NULL       , s_cm209 + 4, "[",                  1, 1, 0xe007, 0 },
   { NULL       , NULL       , "TO",                 2, 0, 0xc015, 0 }
};
static HB_PP_TOKEN s_cr209[ 6 ] = {
   { s_cr209 + 1, NULL       , "SetKey",             6, 1, 0xc015, 0 },
   { s_cr209 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr209 + 3, NULL       , "n",                  1, 1, 0xc00b, 1 },
   { s_cr209 + 4, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr209 + 5, NULL       , "NIL",                3, 1, 0xc015, 0 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm210[ 6 ] = {
   { s_cm210 + 1, NULL       , "SET",                3, 1, 0xc015, 0 },
   { s_cm210 + 2, NULL       , "KEY",                3, 1, 0xc015, 0 },
   { s_cm210 + 3, NULL       , "n",                  1, 0, 0xe001, 2 },
   { s_cm210 + 4, NULL       , "TO",                 2, 1, 0xc015, 0 },
   { NULL       , s_cm210 + 5, "f",                  1, 0, 0xc003, 1 },
   { NULL       , NULL       , "&",                  1, 0, 0xc039, 0 }
};
static HB_PP_TOKEN s_cr210[ 41 ] = {
   { s_cr210 + 1, NULL       , "if",                 2, 1, 0xc015, 0 },
   { s_cr210 + 2, NULL       , "(",                  1, 1, 0xc032, 0 },
   { s_cr210 + 3, NULL       , "Empty",              5, 1, 0xc015, 0 },
   { s_cr210 + 4, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr210 + 5, NULL       , "f",                  1, 0, 0xc00e, 1 },
   { s_cr210 + 6, NULL       , ")",                  1, 0, 0xc033, 0 },
   { s_cr210 + 7, NULL       , ")",                  1, 1, 0xc033, 0 },
   { s_cr210 + 8, NULL       , ";",                  1, 1, 0xc01e, 0 },
   { s_cr210 + 9, NULL       , "SetKey",             6, 1, 0xc015, 0 },
   { s_cr210 +10, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr210 +11, NULL       , "n",                  1, 1, 0xc00b, 2 },
   { s_cr210 +12, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr210 +13, NULL       , "NIL",                3, 1, 0xc015, 0 },
   { s_cr210 +14, NULL       , ")",                  1, 1, 0xc033, 0 },
   { s_cr210 +15, NULL       , ";",                  1, 1, 0xc01e, 0 },
   { s_cr210 +16, NULL       , "else",               4, 1, 0xc015, 0 },
   { s_cr210 +17, NULL       , ";",                  1, 1, 0xc01e, 0 },
   { s_cr210 +18, NULL       , "SetKey",             6, 1, 0xc015, 0 },
   { s_cr210 +19, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr210 +20, NULL       , "n",                  1, 1, 0xc00b, 2 },
   { s_cr210 +21, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr210 +22, NULL       , "{",                  1, 1, 0xc036, 0 },
   { s_cr210 +23, NULL       , "|",                  1, 0, 0xc01b, 0 },
   { s_cr210 +24, NULL       , "p",                  1, 0, 0xc015, 0 },
   { s_cr210 +25, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr210 +26, NULL       , "l",                  1, 1, 0xc015, 0 },
   { s_cr210 +27, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr210 +28, NULL       , "v",                  1, 1, 0xc015, 0 },
   { s_cr210 +29, NULL       , "|",                  1, 0, 0xc01b, 0 },
   { s_cr210 +30, NULL       , "f",                  1, 1, 0xc00b, 1 },
   { s_cr210 +31, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr210 +32, NULL       , "p",                  1, 0, 0xc015, 0 },
   { s_cr210 +33, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr210 +34, NULL       , "l",                  1, 1, 0xc015, 0 },
   { s_cr210 +35, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr210 +36, NULL       , "v",                  1, 1, 0xc015, 0 },
   { s_cr210 +37, NULL       , ")",                  1, 0, 0xc033, 0 },
   { s_cr210 +38, NULL       , "}",                  1, 0, 0xc037, 0 },
   { s_cr210 +39, NULL       , ")",                  1, 1, 0xc033, 0 },
   { s_cr210 +40, NULL       , ";",                  1, 1, 0xc01e, 0 },
   { NULL       , NULL       , "end",                3, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_cm211[ 9 ] = {
   { s_cm211 + 1, NULL       , "SET",                3, 1, 0xc015, 0 },
   { s_cm211 + 2, NULL       , "KEY",                3, 1, 0xc015, 0 },
   { s_cm211 + 3, NULL       , "n",                  1, 0, 0xe001, 1 },
   { s_cm211 + 4, NULL       , "TO",                 2, 1, 0xc015, 0 },
   { s_cm211 + 5, NULL       , "f",                  1, 0, 0xe001, 2 },
   { s_cm211 + 6, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cm211 + 8, s_cm211 + 7, "[",                  1, 0, 0xe007, 0 },
   { NULL       , NULL       , "p",                  1, 0, 0xe002, 0 },
   { NULL       , NULL       , ")",                  1, 0, 0xc033, 0 }
};
static HB_PP_TOKEN s_cr211[ 5 ] = {
   { s_cr211 + 1, NULL       , "SET",                3, 1, 0xc015, 0 },
   { s_cr211 + 2, NULL       , "KEY",                3, 1, 0xc015, 0 },
   { s_cr211 + 3, NULL       , "n",                  1, 1, 0xc00b, 1 },
   { s_cr211 + 4, NULL       , "TO",                 2, 1, 0xc015, 0 },
   { NULL       , NULL       , "f",                  1, 1, 0xc00b, 2 }
};
static HB_PP_TOKEN s_cm212[ 5 ] = {
   { s_cm212 + 1, NULL       , "SET",                3, 1, 0xc015, 0 },
   { s_cm212 + 2, NULL       , "KEY",                3, 1, 0xc015, 0 },
   { s_cm212 + 3, NULL       , "n",                  1, 0, 0xe001, 1 },
   { s_cm212 + 4, NULL       , "TO",                 2, 1, 0xc015, 0 },
   { NULL       , NULL       , "f",                  1, 0, 0xe001, 2 }
};
static HB_PP_TOKEN s_cr212[ 22 ] = {
   { s_cr212 + 1, NULL       , "SetKey",             6, 1, 0xc015, 0 },
   { s_cr212 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr212 + 3, NULL       , "n",                  1, 1, 0xc00b, 1 },
   { s_cr212 + 4, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr212 + 5, NULL       , "{",                  1, 1, 0xc036, 0 },
   { s_cr212 + 6, NULL       , "|",                  1, 0, 0xc01b, 0 },
   { s_cr212 + 7, NULL       , "p",                  1, 0, 0xc015, 0 },
   { s_cr212 + 8, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr212 + 9, NULL       , "l",                  1, 1, 0xc015, 0 },
   { s_cr212 +10, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr212 +11, NULL       , "v",                  1, 1, 0xc015, 0 },
   { s_cr212 +12, NULL       , "|",                  1, 0, 0xc01b, 0 },
   { s_cr212 +13, NULL       , "f",                  1, 1, 0xc00b, 2 },
   { s_cr212 +14, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr212 +15, NULL       , "p",                  1, 0, 0xc015, 0 },
   { s_cr212 +16, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr212 +17, NULL       , "l",                  1, 1, 0xc015, 0 },
   { s_cr212 +18, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr212 +19, NULL       , "v",                  1, 1, 0xc015, 0 },
   { s_cr212 +20, NULL       , ")",                  1, 0, 0xc033, 0 },
   { s_cr212 +21, NULL       , "}",                  1, 0, 0xc037, 0 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm213[ 4 ] = {
   { s_cm213 + 1, NULL       , "SET",                3, 1, 0xc015, 0 },
   { s_cm213 + 2, NULL       , "TYPEAHEAD",          9, 1, 0xc015, 0 },
   { s_cm213 + 3, NULL       , "TO",                 2, 1, 0xc015, 0 },
   { NULL       , NULL       , "x",                  1, 0, 0xe001, 1 }
};
static HB_PP_TOKEN s_cr213[ 6 ] = {
   { s_cr213 + 1, NULL       , "Set",                3, 1, 0xc015, 0 },
   { s_cr213 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr213 + 3, NULL       , "_SET_TYPEAHEAD",    14, 1, 0xc015, 0 },
   { s_cr213 + 4, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr213 + 5, NULL       , "x",                  1, 1, 0xc00b, 1 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm214[ 3 ] = {
   { s_cm214 + 1, NULL       , "SET",                3, 1, 0xc015, 0 },
   { s_cm214 + 2, NULL       , "MESSAGE",            7, 1, 0xc015, 0 },
   { NULL       , NULL       , "TO",                 2, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_cr214[ 13 ] = {
   { s_cr214 + 1, NULL       , "Set",                3, 1, 0xc015, 0 },
   { s_cr214 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr214 + 3, NULL       , "_SET_MESSAGE",      12, 1, 0xc015, 0 },
   { s_cr214 + 4, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr214 + 5, NULL       , "0",                  1, 1, 0xc02a, 0 },
   { s_cr214 + 6, NULL       , ")",                  1, 1, 0xc033, 0 },
   { s_cr214 + 7, NULL       , ";",                  1, 1, 0xc01e, 0 },
   { s_cr214 + 8, NULL       , "Set",                3, 1, 0xc015, 0 },
   { s_cr214 + 9, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr214 +10, NULL       , "_SET_MCENTER",      12, 1, 0xc015, 0 },
   { s_cr214 +11, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr214 +12, NULL       , ".F.",                3, 1, 0xc02c, 0 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm215[ 9 ] = {
   { s_cm215 + 1, NULL       , "SET",                3, 1, 0xc015, 0 },
   { s_cm215 + 2, NULL       , "MESSAGE",            7, 1, 0xc015, 0 },
   { s_cm215 + 3, NULL       , "TO",                 2, 1, 0xc015, 0 },
   { s_cm215 + 4, NULL       , "n",                  1, 0, 0xe001, 1 },
   { NULL       , s_cm215 + 5, "[",                  1, 1, 0xe007, 0 },
   { NULL       , s_cm215 + 6, "cent",               4, 0, 0xc003, 2 },
   { s_cm215 + 7, NULL       , "CENTER",             6, 1, 0xc015, 0 },
   { s_cm215 + 8, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { NULL       , NULL       , "CENTRE",             6, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_cr215[ 13 ] = {
   { s_cr215 + 1, NULL       , "Set",                3, 1, 0xc015, 0 },
   { s_cr215 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr215 + 3, NULL       , "_SET_MESSAGE",      12, 1, 0xc015, 0 },
   { s_cr215 + 4, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr215 + 5, NULL       , "n",                  1, 1, 0xc00b, 1 },
   { s_cr215 + 6, NULL       , ")",                  1, 1, 0xc033, 0 },
   { s_cr215 + 7, NULL       , ";",                  1, 1, 0xc01e, 0 },
   { s_cr215 + 8, NULL       , "Set",                3, 1, 0xc015, 0 },
   { s_cr215 + 9, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr215 +10, NULL       , "_SET_MCENTER",      12, 1, 0xc015, 0 },
   { s_cr215 +11, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr215 +12, NULL       , "cent",               4, 1, 0xc010, 2 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm216[ 11 ] = {
   { s_cm216 + 1, NULL       , "SET",                3, 1, 0xc015, 0 },
   { s_cm216 + 2, NULL       , "INDEX",              5, 1, 0xc015, 0 },
   { s_cm216 + 3, NULL       , "TO",                 2, 1, 0xc015, 0 },
   { s_cm216 + 6, s_cm216 + 4, "[",                  1, 1, 0xe007, 0 },
   { NULL       , s_cm216 + 5, "add",                3, 0, 0xc003, 1 },
   { NULL       , NULL       , "ADDITIVE",           8, 1, 0xc015, 0 },
   { NULL       , s_cm216 + 7, "[",                  1, 1, 0xe007, 0 },
   { s_cm216 + 8, NULL       , "i1",                 2, 0, 0xe005, 2 },
   { NULL       , s_cm216 + 9, "[",                  1, 1, 0xe007, 0 },
   { s_cm216 +10, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { NULL       , NULL       , "iN",                 2, 0, 0xe005, 3 }
};
static HB_PP_TOKEN s_cr216[ 21 ] = {
   { s_cr216 + 1, NULL       , "if",                 2, 1, 0xc015, 0 },
   { s_cr216 + 2, NULL       , "!",                  1, 1, 0xc045, 0 },
   { s_cr216 + 3, NULL       , "add",                3, 0, 0xc010, 1 },
   { s_cr216 + 4, NULL       , ";",                  1, 1, 0xc01e, 0 },
   { s_cr216 + 5, NULL       , "ordListClear",      12, 1, 0xc015, 0 },
   { s_cr216 + 6, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr216 + 7, NULL       , ")",                  1, 0, 0xc033, 0 },
   { s_cr216 + 8, NULL       , ";",                  1, 1, 0xc01e, 0 },
   { s_cr216 + 9, NULL       , "end",                3, 1, 0xc015, 0 },
   { s_cr216 +15, s_cr216 +10, "[",                  1, 1, 0xc012, 0 },
   { s_cr216 +11, NULL       , ";",                  1, 1, 0xc01e, 0 },
   { s_cr216 +12, NULL       , "ordListAdd",        10, 1, 0xc015, 0 },
   { s_cr216 +13, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr216 +14, NULL       , "i1",                 2, 1, 0xc00e, 2 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 },
   { NULL       , s_cr216 +16, "[",                  1, 1, 0xc012, 0 },
   { s_cr216 +17, NULL       , ";",                  1, 1, 0xc01e, 0 },
   { s_cr216 +18, NULL       , "ordListAdd",        10, 1, 0xc015, 0 },
   { s_cr216 +19, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr216 +20, NULL       , "iN",                 2, 1, 0xc00e, 3 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm217[ 8 ] = {
   { s_cm217 + 1, NULL       , "SET",                3, 1, 0xc015, 0 },
   { s_cm217 + 2, NULL       , "ORDER",              5, 1, 0xc015, 0 },
   { s_cm217 + 3, NULL       , "TO",                 2, 1, 0xc015, 0 },
   { s_cm217 + 4, NULL       , "TAG",                3, 1, 0xc015, 0 },
   { s_cm217 + 5, NULL       , "tg",                 2, 0, 0xe005, 1 },
   { NULL       , s_cm217 + 6, "[",                  1, 1, 0xe007, 0 },
   { s_cm217 + 7, NULL       , "IN",                 2, 0, 0xc015, 0 },
   { NULL       , NULL       , "bg",                 2, 0, 0xe005, 2 }
};
static HB_PP_TOKEN s_cr217[ 7 ] = {
   { s_cr217 + 1, NULL       , "ordSetFocus",       11, 1, 0xc015, 0 },
   { s_cr217 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr217 + 3, NULL       , "tg",                 2, 1, 0xc00e, 1 },
   { s_cr217 + 6, s_cr217 + 4, "[",                  1, 1, 0xc012, 0 },
   { s_cr217 + 5, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { NULL       , NULL       , "bg",                 2, 1, 0xc00e, 2 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm218[ 7 ] = {
   { s_cm218 + 1, NULL       , "SET",                3, 1, 0xc015, 0 },
   { s_cm218 + 2, NULL       , "ORDER",              5, 1, 0xc015, 0 },
   { s_cm218 + 3, NULL       , "TO",                 2, 1, 0xc015, 0 },
   { s_cm218 + 4, NULL       , "tg",                 2, 0, 0xe001, 1 },
   { NULL       , s_cm218 + 5, "[",                  1, 1, 0xe007, 0 },
   { s_cm218 + 6, NULL       , "IN",                 2, 0, 0xc015, 0 },
   { NULL       , NULL       , "bg",                 2, 0, 0xe005, 2 }
};
static HB_PP_TOKEN s_cr218[ 7 ] = {
   { s_cr218 + 1, NULL       , "ordSetFocus",       11, 1, 0xc015, 0 },
   { s_cr218 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr218 + 3, NULL       , "tg",                 2, 1, 0xc00b, 1 },
   { s_cr218 + 6, s_cr218 + 4, "[",                  1, 1, 0xc012, 0 },
   { s_cr218 + 5, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { NULL       , NULL       , "bg",                 2, 1, 0xc00e, 2 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm219[ 5 ] = {
   { s_cm219 + 1, NULL       , "SET",                3, 1, 0xc015, 0 },
   { s_cm219 + 2, NULL       , "COLOUR",             6, 1, 0xc015, 0 },
   { s_cm219 + 3, NULL       , "TO",                 2, 1, 0xc015, 0 },
   { NULL       , s_cm219 + 4, "[",                  1, 1, 0xe007, 0 },
   { NULL       , NULL       , "c",                  1, 0, 0xe004, 1 }
};
static HB_PP_TOKEN s_cr219[ 5 ] = {
   { s_cr219 + 1, NULL       , "SET",                3, 1, 0xc015, 0 },
   { s_cr219 + 2, NULL       , "COLOR",              5, 1, 0xc015, 0 },
   { s_cr219 + 3, NULL       , "TO",                 2, 1, 0xc015, 0 },
   { NULL       , s_cr219 + 4, "[",                  1, 1, 0xc012, 0 },
   { NULL       , NULL       , "c",                  1, 1, 0xc00b, 1 }
};
static HB_PP_TOKEN s_cm220[ 6 ] = {
   { s_cm220 + 1, NULL       , "SET",                3, 1, 0xc015, 0 },
   { s_cm220 + 2, NULL       , "COLOR",              5, 1, 0xc015, 0 },
   { s_cm220 + 3, NULL       , "TO",                 2, 1, 0xc015, 0 },
   { s_cm220 + 4, NULL       , "(",                  1, 1, 0xc032, 0 },
   { s_cm220 + 5, NULL       , "c",                  1, 0, 0xe001, 1 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cr220[ 4 ] = {
   { s_cr220 + 1, NULL       , "SetColor",           8, 1, 0xc015, 0 },
   { s_cr220 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr220 + 3, NULL       , "c",                  1, 1, 0xc00b, 1 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm221[ 5 ] = {
   { s_cm221 + 1, NULL       , "SET",                3, 1, 0xc015, 0 },
   { s_cm221 + 2, NULL       , "COLOR",              5, 1, 0xc015, 0 },
   { s_cm221 + 3, NULL       , "TO",                 2, 1, 0xc015, 0 },
   { NULL       , s_cm221 + 4, "[",                  1, 1, 0xe007, 0 },
   { NULL       , NULL       , "c",                  1, 0, 0xe004, 1 }
};
static HB_PP_TOKEN s_cr221[ 4 ] = {
   { s_cr221 + 1, NULL       , "SetColor",           8, 1, 0xc015, 0 },
   { s_cr221 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr221 + 3, NULL       , "c",                  1, 1, 0xc00c, 1 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm222[ 4 ] = {
   { s_cm222 + 1, NULL       , "SET",                3, 1, 0xc015, 0 },
   { s_cm222 + 2, NULL       , "DEVICE",             6, 1, 0xc015, 0 },
   { s_cm222 + 3, NULL       , "TO",                 2, 1, 0xc015, 0 },
   { NULL       , NULL       , "PRINTER",            7, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_cr222[ 6 ] = {
   { s_cr222 + 1, NULL       , "Set",                3, 1, 0xc015, 0 },
   { s_cr222 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr222 + 3, NULL       , "_SET_DEVICE",       11, 1, 0xc015, 0 },
   { s_cr222 + 4, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr222 + 5, NULL       , "PRINTER",            7, 1, 0xc029, 0 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm223[ 4 ] = {
   { s_cm223 + 1, NULL       , "SET",                3, 1, 0xc015, 0 },
   { s_cm223 + 2, NULL       , "DEVICE",             6, 1, 0xc015, 0 },
   { s_cm223 + 3, NULL       , "TO",                 2, 1, 0xc015, 0 },
   { NULL       , NULL       , "SCREEN",             6, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_cr223[ 6 ] = {
   { s_cr223 + 1, NULL       , "Set",                3, 1, 0xc015, 0 },
   { s_cr223 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr223 + 3, NULL       , "_SET_DEVICE",       11, 1, 0xc015, 0 },
   { s_cr223 + 4, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr223 + 5, NULL       , "SCREEN",             6, 1, 0xc029, 0 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm224[ 3 ] = {
   { s_cm224 + 1, NULL       , "SET",                3, 1, 0xc015, 0 },
   { s_cm224 + 2, NULL       , "MARGIN",             6, 1, 0xc015, 0 },
   { NULL       , NULL       , "TO",                 2, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_cr224[ 6 ] = {
   { s_cr224 + 1, NULL       , "Set",                3, 1, 0xc015, 0 },
   { s_cr224 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr224 + 3, NULL       , "_SET_MARGIN",       11, 1, 0xc015, 0 },
   { s_cr224 + 4, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr224 + 5, NULL       , "0",                  1, 1, 0xc02a, 0 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm225[ 4 ] = {
   { s_cm225 + 1, NULL       , "SET",                3, 1, 0xc015, 0 },
   { s_cm225 + 2, NULL       , "MARGIN",             6, 1, 0xc015, 0 },
   { s_cm225 + 3, NULL       , "TO",                 2, 1, 0xc015, 0 },
   { NULL       , NULL       , "x",                  1, 0, 0xe001, 1 }
};
static HB_PP_TOKEN s_cr225[ 6 ] = {
   { s_cr225 + 1, NULL       , "Set",                3, 1, 0xc015, 0 },
   { s_cr225 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr225 + 3, NULL       , "_SET_MARGIN",       11, 1, 0xc015, 0 },
   { s_cr225 + 4, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr225 + 5, NULL       , "x",                  1, 1, 0xc00b, 1 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm226[ 5 ] = {
   { s_cm226 + 1, NULL       , "SET",                3, 1, 0xc015, 0 },
   { s_cm226 + 2, NULL       , "CURSOR",             6, 1, 0xc015, 0 },
   { s_cm226 + 3, NULL       , "(",                  1, 1, 0xc032, 0 },
   { s_cm226 + 4, NULL       , "x",                  1, 0, 0xe001, 1 },
   { NULL       , NULL       , ")",                  1, 0, 0xc033, 0 }
};
static HB_PP_TOKEN s_cr226[ 11 ] = {
   { s_cr226 + 1, NULL       , "SetCursor",          9, 1, 0xc015, 0 },
   { s_cr226 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr226 + 3, NULL       , "if",                 2, 1, 0xc015, 0 },
   { s_cr226 + 4, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr226 + 5, NULL       , "x",                  1, 0, 0xc00b, 1 },
   { s_cr226 + 6, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr226 + 7, NULL       , "1",                  1, 1, 0xc02a, 0 },
   { s_cr226 + 8, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr226 + 9, NULL       , "0",                  1, 1, 0xc02a, 0 },
   { s_cr226 +10, NULL       , ")",                  1, 0, 0xc033, 0 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm227[ 8 ] = {
   { s_cm227 + 1, NULL       , "SET",                3, 1, 0xc015, 0 },
   { s_cm227 + 2, NULL       , "CURSOR",             6, 1, 0xc015, 0 },
   { NULL       , s_cm227 + 3, "x",                  1, 0, 0xc003, 1 },
   { s_cm227 + 4, NULL       , "ON",                 2, 0, 0xc015, 0 },
   { s_cm227 + 5, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cm227 + 6, NULL       , "OFF",                3, 0, 0xc015, 0 },
   { s_cm227 + 7, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { NULL       , NULL       , "&",                  1, 0, 0xc039, 0 }
};
static HB_PP_TOKEN s_cr227[ 16 ] = {
   { s_cr227 + 1, NULL       , "SetCursor",          9, 1, 0xc015, 0 },
   { s_cr227 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr227 + 3, NULL       , "if",                 2, 1, 0xc015, 0 },
   { s_cr227 + 4, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr227 + 5, NULL       , "Upper",              5, 0, 0xc015, 0 },
   { s_cr227 + 6, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr227 + 7, NULL       , "x",                  1, 0, 0xc00e, 1 },
   { s_cr227 + 8, NULL       , ")",                  1, 0, 0xc033, 0 },
   { s_cr227 + 9, NULL       , "==",                 2, 1, 0xc048, 0 },
   { s_cr227 +10, NULL       , "ON",                 2, 1, 0xc029, 0 },
   { s_cr227 +11, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr227 +12, NULL       , "1",                  1, 1, 0xc02a, 0 },
   { s_cr227 +13, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr227 +14, NULL       , "0",                  1, 1, 0xc02a, 0 },
   { s_cr227 +15, NULL       , ")",                  1, 0, 0xc033, 0 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm228[ 7 ] = {
   { s_cm228 + 1, NULL       , "SET",                3, 1, 0xc015, 0 },
   { s_cm228 + 2, NULL       , "PRINTER",            7, 1, 0xc015, 0 },
   { s_cm228 + 3, NULL       , "TO",                 2, 1, 0xc015, 0 },
   { s_cm228 + 4, NULL       , "file",               4, 0, 0xe005, 1 },
   { NULL       , s_cm228 + 5, "[",                  1, 1, 0xe007, 0 },
   { NULL       , s_cm228 + 6, "add",                3, 0, 0xc003, 2 },
   { NULL       , NULL       , "ADDITIVE",           8, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_cr228[ 8 ] = {
   { s_cr228 + 1, NULL       , "Set",                3, 1, 0xc015, 0 },
   { s_cr228 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr228 + 3, NULL       , "_SET_PRINTFILE",    14, 1, 0xc015, 0 },
   { s_cr228 + 4, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr228 + 5, NULL       , "file",               4, 1, 0xc00e, 1 },
   { s_cr228 + 6, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr228 + 7, NULL       , "add",                3, 1, 0xc010, 2 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm229[ 3 ] = {
   { s_cm229 + 1, NULL       , "SET",                3, 1, 0xc015, 0 },
   { s_cm229 + 2, NULL       , "PRINTER",            7, 1, 0xc015, 0 },
   { NULL       , NULL       , "TO",                 2, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_cr229[ 6 ] = {
   { s_cr229 + 1, NULL       , "Set",                3, 1, 0xc015, 0 },
   { s_cr229 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr229 + 3, NULL       , "_SET_PRINTFILE",    14, 1, 0xc015, 0 },
   { s_cr229 + 4, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr229 + 5, NULL       , "",                   0, 1, 0xc029, 0 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm230[ 5 ] = {
   { s_cm230 + 1, NULL       , "SET",                3, 1, 0xc015, 0 },
   { s_cm230 + 2, NULL       , "PRINTER",            7, 1, 0xc015, 0 },
   { s_cm230 + 3, NULL       , "(",                  1, 1, 0xc032, 0 },
   { s_cm230 + 4, NULL       , "x",                  1, 0, 0xe001, 1 },
   { NULL       , NULL       , ")",                  1, 0, 0xc033, 0 }
};
static HB_PP_TOKEN s_cr230[ 6 ] = {
   { s_cr230 + 1, NULL       , "Set",                3, 1, 0xc015, 0 },
   { s_cr230 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr230 + 3, NULL       , "_SET_PRINTER",      12, 1, 0xc015, 0 },
   { s_cr230 + 4, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr230 + 5, NULL       , "x",                  1, 1, 0xc00b, 1 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm231[ 8 ] = {
   { s_cm231 + 1, NULL       , "SET",                3, 1, 0xc015, 0 },
   { s_cm231 + 2, NULL       , "PRINTER",            7, 1, 0xc015, 0 },
   { NULL       , s_cm231 + 3, "x",                  1, 0, 0xc003, 1 },
   { s_cm231 + 4, NULL       , "ON",                 2, 0, 0xc015, 0 },
   { s_cm231 + 5, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cm231 + 6, NULL       , "OFF",                3, 0, 0xc015, 0 },
   { s_cm231 + 7, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { NULL       , NULL       , "&",                  1, 0, 0xc039, 0 }
};
static HB_PP_TOKEN s_cr231[ 6 ] = {
   { s_cr231 + 1, NULL       , "Set",                3, 1, 0xc015, 0 },
   { s_cr231 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr231 + 3, NULL       , "_SET_PRINTER",      12, 1, 0xc015, 0 },
   { s_cr231 + 4, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr231 + 5, NULL       , "x",                  1, 1, 0xc00e, 1 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm232[ 7 ] = {
   { s_cm232 + 1, NULL       , "SET",                3, 1, 0xc015, 0 },
   { s_cm232 + 2, NULL       , "ALTERNATE",          9, 1, 0xc015, 0 },
   { s_cm232 + 3, NULL       , "TO",                 2, 1, 0xc015, 0 },
   { s_cm232 + 4, NULL       , "file",               4, 0, 0xe005, 1 },
   { NULL       , s_cm232 + 5, "[",                  1, 1, 0xe007, 0 },
   { NULL       , s_cm232 + 6, "add",                3, 0, 0xc003, 2 },
   { NULL       , NULL       , "ADDITIVE",           8, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_cr232[ 8 ] = {
   { s_cr232 + 1, NULL       , "Set",                3, 1, 0xc015, 0 },
   { s_cr232 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr232 + 3, NULL       , "_SET_ALTFILE",      12, 1, 0xc015, 0 },
   { s_cr232 + 4, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr232 + 5, NULL       , "file",               4, 1, 0xc00e, 1 },
   { s_cr232 + 6, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr232 + 7, NULL       , "add",                3, 1, 0xc010, 2 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm233[ 3 ] = {
   { s_cm233 + 1, NULL       , "SET",                3, 1, 0xc015, 0 },
   { s_cm233 + 2, NULL       , "ALTERNATE",          9, 1, 0xc015, 0 },
   { NULL       , NULL       , "TO",                 2, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_cr233[ 6 ] = {
   { s_cr233 + 1, NULL       , "Set",                3, 1, 0xc015, 0 },
   { s_cr233 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr233 + 3, NULL       , "_SET_ALTFILE",      12, 1, 0xc015, 0 },
   { s_cr233 + 4, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr233 + 5, NULL       , "",                   0, 1, 0xc029, 0 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm234[ 5 ] = {
   { s_cm234 + 1, NULL       , "SET",                3, 1, 0xc015, 0 },
   { s_cm234 + 2, NULL       , "ALTERNATE",          9, 1, 0xc015, 0 },
   { s_cm234 + 3, NULL       , "(",                  1, 1, 0xc032, 0 },
   { s_cm234 + 4, NULL       , "x",                  1, 0, 0xe001, 1 },
   { NULL       , NULL       , ")",                  1, 0, 0xc033, 0 }
};
static HB_PP_TOKEN s_cr234[ 6 ] = {
   { s_cr234 + 1, NULL       , "Set",                3, 1, 0xc015, 0 },
   { s_cr234 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr234 + 3, NULL       , "_SET_ALTERNATE",    14, 1, 0xc015, 0 },
   { s_cr234 + 4, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr234 + 5, NULL       , "x",                  1, 1, 0xc00b, 1 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm235[ 8 ] = {
   { s_cm235 + 1, NULL       , "SET",                3, 1, 0xc015, 0 },
   { s_cm235 + 2, NULL       , "ALTERNATE",          9, 1, 0xc015, 0 },
   { NULL       , s_cm235 + 3, "x",                  1, 0, 0xc003, 1 },
   { s_cm235 + 4, NULL       , "ON",                 2, 0, 0xc015, 0 },
   { s_cm235 + 5, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cm235 + 6, NULL       , "OFF",                3, 0, 0xc015, 0 },
   { s_cm235 + 7, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { NULL       , NULL       , "&",                  1, 0, 0xc039, 0 }
};
static HB_PP_TOKEN s_cr235[ 6 ] = {
   { s_cr235 + 1, NULL       , "Set",                3, 1, 0xc015, 0 },
   { s_cr235 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr235 + 3, NULL       , "_SET_ALTERNATE",    14, 1, 0xc015, 0 },
   { s_cr235 + 4, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr235 + 5, NULL       , "x",                  1, 1, 0xc00e, 1 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm236[ 5 ] = {
   { s_cm236 + 1, NULL       , "SET",                3, 1, 0xc015, 0 },
   { s_cm236 + 2, NULL       , "DELIMITERS",        10, 1, 0xc015, 0 },
   { s_cm236 + 3, NULL       , "TO",                 2, 1, 0xc015, 0 },
   { NULL       , s_cm236 + 4, "[",                  1, 1, 0xe007, 0 },
   { NULL       , NULL       , "DEFAULT",            7, 0, 0xc015, 0 }
};
static HB_PP_TOKEN s_cr236[ 6 ] = {
   { s_cr236 + 1, NULL       , "Set",                3, 1, 0xc015, 0 },
   { s_cr236 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr236 + 3, NULL       , "_SET_DELIMCHARS",   15, 1, 0xc015, 0 },
   { s_cr236 + 4, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr236 + 5, NULL       , "::",                 2, 1, 0xc029, 0 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm237[ 4 ] = {
   { s_cm237 + 1, NULL       , "SET",                3, 1, 0xc015, 0 },
   { s_cm237 + 2, NULL       , "DELIMITERS",        10, 1, 0xc015, 0 },
   { s_cm237 + 3, NULL       , "TO",                 2, 1, 0xc015, 0 },
   { NULL       , NULL       , "c",                  1, 0, 0xe001, 1 }
};
static HB_PP_TOKEN s_cr237[ 6 ] = {
   { s_cr237 + 1, NULL       , "Set",                3, 1, 0xc015, 0 },
   { s_cr237 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr237 + 3, NULL       , "_SET_DELIMCHARS",   15, 1, 0xc015, 0 },
   { s_cr237 + 4, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr237 + 5, NULL       , "c",                  1, 1, 0xc00b, 1 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm238[ 5 ] = {
   { s_cm238 + 1, NULL       , "SET",                3, 1, 0xc015, 0 },
   { s_cm238 + 2, NULL       , "DELIMITERS",        10, 1, 0xc015, 0 },
   { s_cm238 + 3, NULL       , "(",                  1, 1, 0xc032, 0 },
   { s_cm238 + 4, NULL       , "x",                  1, 0, 0xe001, 1 },
   { NULL       , NULL       , ")",                  1, 0, 0xc033, 0 }
};
static HB_PP_TOKEN s_cr238[ 6 ] = {
   { s_cr238 + 1, NULL       , "Set",                3, 1, 0xc015, 0 },
   { s_cr238 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr238 + 3, NULL       , "_SET_DELIMITERS",   15, 1, 0xc015, 0 },
   { s_cr238 + 4, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr238 + 5, NULL       , "x",                  1, 1, 0xc00b, 1 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm239[ 8 ] = {
   { s_cm239 + 1, NULL       , "SET",                3, 1, 0xc015, 0 },
   { s_cm239 + 2, NULL       , "DELIMITERS",        10, 1, 0xc015, 0 },
   { NULL       , s_cm239 + 3, "x",                  1, 0, 0xc003, 1 },
   { s_cm239 + 4, NULL       , "ON",                 2, 0, 0xc015, 0 },
   { s_cm239 + 5, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cm239 + 6, NULL       , "OFF",                3, 0, 0xc015, 0 },
   { s_cm239 + 7, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { NULL       , NULL       , "&",                  1, 0, 0xc039, 0 }
};
static HB_PP_TOKEN s_cr239[ 6 ] = {
   { s_cr239 + 1, NULL       , "Set",                3, 1, 0xc015, 0 },
   { s_cr239 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr239 + 3, NULL       , "_SET_DELIMITERS",   15, 1, 0xc015, 0 },
   { s_cr239 + 4, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr239 + 5, NULL       , "x",                  1, 1, 0xc00e, 1 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm240[ 5 ] = {
   { s_cm240 + 1, NULL       , "SET",                3, 1, 0xc015, 0 },
   { s_cm240 + 2, NULL       , "WRAP",               4, 1, 0xc015, 0 },
   { s_cm240 + 3, NULL       , "(",                  1, 1, 0xc032, 0 },
   { s_cm240 + 4, NULL       , "x",                  1, 0, 0xe001, 1 },
   { NULL       , NULL       , ")",                  1, 0, 0xc033, 0 }
};
static HB_PP_TOKEN s_cr240[ 6 ] = {
   { s_cr240 + 1, NULL       , "Set",                3, 1, 0xc015, 0 },
   { s_cr240 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr240 + 3, NULL       , "_SET_WRAP",          9, 1, 0xc015, 0 },
   { s_cr240 + 4, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr240 + 5, NULL       , "x",                  1, 1, 0xc00b, 1 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm241[ 8 ] = {
   { s_cm241 + 1, NULL       , "SET",                3, 1, 0xc015, 0 },
   { s_cm241 + 2, NULL       , "WRAP",               4, 1, 0xc015, 0 },
   { NULL       , s_cm241 + 3, "x",                  1, 0, 0xc003, 1 },
   { s_cm241 + 4, NULL       , "ON",                 2, 0, 0xc015, 0 },
   { s_cm241 + 5, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cm241 + 6, NULL       , "OFF",                3, 0, 0xc015, 0 },
   { s_cm241 + 7, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { NULL       , NULL       , "&",                  1, 0, 0xc039, 0 }
};
static HB_PP_TOKEN s_cr241[ 6 ] = {
   { s_cr241 + 1, NULL       , "Set",                3, 1, 0xc015, 0 },
   { s_cr241 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr241 + 3, NULL       , "_SET_WRAP",          9, 1, 0xc015, 0 },
   { s_cr241 + 4, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr241 + 5, NULL       , "x",                  1, 1, 0xc00e, 1 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm242[ 5 ] = {
   { s_cm242 + 1, NULL       , "SET",                3, 1, 0xc015, 0 },
   { s_cm242 + 2, NULL       , "SCOREBOARD",        10, 1, 0xc015, 0 },
   { s_cm242 + 3, NULL       , "(",                  1, 1, 0xc032, 0 },
   { s_cm242 + 4, NULL       , "x",                  1, 0, 0xe001, 1 },
   { NULL       , NULL       , ")",                  1, 0, 0xc033, 0 }
};
static HB_PP_TOKEN s_cr242[ 6 ] = {
   { s_cr242 + 1, NULL       , "Set",                3, 1, 0xc015, 0 },
   { s_cr242 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr242 + 3, NULL       , "_SET_SCOREBOARD",   15, 1, 0xc015, 0 },
   { s_cr242 + 4, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr242 + 5, NULL       , "x",                  1, 1, 0xc00b, 1 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm243[ 8 ] = {
   { s_cm243 + 1, NULL       , "SET",                3, 1, 0xc015, 0 },
   { s_cm243 + 2, NULL       , "SCOREBOARD",        10, 1, 0xc015, 0 },
   { NULL       , s_cm243 + 3, "x",                  1, 0, 0xc003, 1 },
   { s_cm243 + 4, NULL       , "ON",                 2, 0, 0xc015, 0 },
   { s_cm243 + 5, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cm243 + 6, NULL       , "OFF",                3, 0, 0xc015, 0 },
   { s_cm243 + 7, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { NULL       , NULL       , "&",                  1, 0, 0xc039, 0 }
};
static HB_PP_TOKEN s_cr243[ 6 ] = {
   { s_cr243 + 1, NULL       , "Set",                3, 1, 0xc015, 0 },
   { s_cr243 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr243 + 3, NULL       , "_SET_SCOREBOARD",   15, 1, 0xc015, 0 },
   { s_cr243 + 4, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr243 + 5, NULL       , "x",                  1, 1, 0xc00e, 1 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm244[ 5 ] = {
   { s_cm244 + 1, NULL       , "SET",                3, 1, 0xc015, 0 },
   { s_cm244 + 2, NULL       , "INTENSITY",          9, 1, 0xc015, 0 },
   { s_cm244 + 3, NULL       , "(",                  1, 1, 0xc032, 0 },
   { s_cm244 + 4, NULL       , "x",                  1, 0, 0xe001, 1 },
   { NULL       , NULL       , ")",                  1, 0, 0xc033, 0 }
};
static HB_PP_TOKEN s_cr244[ 6 ] = {
   { s_cr244 + 1, NULL       , "Set",                3, 1, 0xc015, 0 },
   { s_cr244 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr244 + 3, NULL       , "_SET_INTENSITY",    14, 1, 0xc015, 0 },
   { s_cr244 + 4, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr244 + 5, NULL       , "x",                  1, 1, 0xc00b, 1 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm245[ 8 ] = {
   { s_cm245 + 1, NULL       , "SET",                3, 1, 0xc015, 0 },
   { s_cm245 + 2, NULL       , "INTENSITY",          9, 1, 0xc015, 0 },
   { NULL       , s_cm245 + 3, "x",                  1, 0, 0xc003, 1 },
   { s_cm245 + 4, NULL       , "ON",                 2, 0, 0xc015, 0 },
   { s_cm245 + 5, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cm245 + 6, NULL       , "OFF",                3, 0, 0xc015, 0 },
   { s_cm245 + 7, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { NULL       , NULL       , "&",                  1, 0, 0xc039, 0 }
};
static HB_PP_TOKEN s_cr245[ 6 ] = {
   { s_cr245 + 1, NULL       , "Set",                3, 1, 0xc015, 0 },
   { s_cr245 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr245 + 3, NULL       , "_SET_INTENSITY",    14, 1, 0xc015, 0 },
   { s_cr245 + 4, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr245 + 5, NULL       , "x",                  1, 1, 0xc00e, 1 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm246[ 5 ] = {
   { s_cm246 + 1, NULL       , "SET",                3, 1, 0xc015, 0 },
   { s_cm246 + 2, NULL       , "ESCAPE",             6, 1, 0xc015, 0 },
   { s_cm246 + 3, NULL       , "(",                  1, 1, 0xc032, 0 },
   { s_cm246 + 4, NULL       , "x",                  1, 0, 0xe001, 1 },
   { NULL       , NULL       , ")",                  1, 0, 0xc033, 0 }
};
static HB_PP_TOKEN s_cr246[ 6 ] = {
   { s_cr246 + 1, NULL       , "Set",                3, 1, 0xc015, 0 },
   { s_cr246 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr246 + 3, NULL       , "_SET_ESCAPE",       11, 1, 0xc015, 0 },
   { s_cr246 + 4, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr246 + 5, NULL       , "x",                  1, 1, 0xc00b, 1 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm247[ 8 ] = {
   { s_cm247 + 1, NULL       , "SET",                3, 1, 0xc015, 0 },
   { s_cm247 + 2, NULL       , "ESCAPE",             6, 1, 0xc015, 0 },
   { NULL       , s_cm247 + 3, "x",                  1, 0, 0xc003, 1 },
   { s_cm247 + 4, NULL       , "ON",                 2, 0, 0xc015, 0 },
   { s_cm247 + 5, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cm247 + 6, NULL       , "OFF",                3, 0, 0xc015, 0 },
   { s_cm247 + 7, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { NULL       , NULL       , "&",                  1, 0, 0xc039, 0 }
};
static HB_PP_TOKEN s_cr247[ 6 ] = {
   { s_cr247 + 1, NULL       , "Set",                3, 1, 0xc015, 0 },
   { s_cr247 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr247 + 3, NULL       , "_SET_ESCAPE",       11, 1, 0xc015, 0 },
   { s_cr247 + 4, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr247 + 5, NULL       , "x",                  1, 1, 0xc00e, 1 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm248[ 5 ] = {
   { s_cm248 + 1, NULL       , "SET",                3, 1, 0xc015, 0 },
   { s_cm248 + 2, NULL       , "CONFIRM",            7, 1, 0xc015, 0 },
   { s_cm248 + 3, NULL       , "(",                  1, 1, 0xc032, 0 },
   { s_cm248 + 4, NULL       , "x",                  1, 0, 0xe001, 1 },
   { NULL       , NULL       , ")",                  1, 0, 0xc033, 0 }
};
static HB_PP_TOKEN s_cr248[ 6 ] = {
   { s_cr248 + 1, NULL       , "Set",                3, 1, 0xc015, 0 },
   { s_cr248 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr248 + 3, NULL       , "_SET_CONFIRM",      12, 1, 0xc015, 0 },
   { s_cr248 + 4, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr248 + 5, NULL       , "x",                  1, 1, 0xc00b, 1 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm249[ 8 ] = {
   { s_cm249 + 1, NULL       , "SET",                3, 1, 0xc015, 0 },
   { s_cm249 + 2, NULL       , "CONFIRM",            7, 1, 0xc015, 0 },
   { NULL       , s_cm249 + 3, "x",                  1, 0, 0xc003, 1 },
   { s_cm249 + 4, NULL       , "ON",                 2, 0, 0xc015, 0 },
   { s_cm249 + 5, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cm249 + 6, NULL       , "OFF",                3, 0, 0xc015, 0 },
   { s_cm249 + 7, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { NULL       , NULL       , "&",                  1, 0, 0xc039, 0 }
};
static HB_PP_TOKEN s_cr249[ 6 ] = {
   { s_cr249 + 1, NULL       , "Set",                3, 1, 0xc015, 0 },
   { s_cr249 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr249 + 3, NULL       , "_SET_CONFIRM",      12, 1, 0xc015, 0 },
   { s_cr249 + 4, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr249 + 5, NULL       , "x",                  1, 1, 0xc00e, 1 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm250[ 5 ] = {
   { s_cm250 + 1, NULL       , "SET",                3, 1, 0xc015, 0 },
   { s_cm250 + 2, NULL       , "BELL",               4, 1, 0xc015, 0 },
   { s_cm250 + 3, NULL       , "(",                  1, 1, 0xc032, 0 },
   { s_cm250 + 4, NULL       , "x",                  1, 0, 0xe001, 1 },
   { NULL       , NULL       , ")",                  1, 0, 0xc033, 0 }
};
static HB_PP_TOKEN s_cr250[ 6 ] = {
   { s_cr250 + 1, NULL       , "Set",                3, 1, 0xc015, 0 },
   { s_cr250 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr250 + 3, NULL       , "_SET_BELL",          9, 1, 0xc015, 0 },
   { s_cr250 + 4, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr250 + 5, NULL       , "x",                  1, 1, 0xc00b, 1 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm251[ 8 ] = {
   { s_cm251 + 1, NULL       , "SET",                3, 1, 0xc015, 0 },
   { s_cm251 + 2, NULL       , "BELL",               4, 1, 0xc015, 0 },
   { NULL       , s_cm251 + 3, "x",                  1, 0, 0xc003, 1 },
   { s_cm251 + 4, NULL       , "ON",                 2, 0, 0xc015, 0 },
   { s_cm251 + 5, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cm251 + 6, NULL       , "OFF",                3, 0, 0xc015, 0 },
   { s_cm251 + 7, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { NULL       , NULL       , "&",                  1, 0, 0xc039, 0 }
};
static HB_PP_TOKEN s_cr251[ 6 ] = {
   { s_cr251 + 1, NULL       , "Set",                3, 1, 0xc015, 0 },
   { s_cr251 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr251 + 3, NULL       , "_SET_BELL",          9, 1, 0xc015, 0 },
   { s_cr251 + 4, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr251 + 5, NULL       , "x",                  1, 1, 0xc00e, 1 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm252[ 5 ] = {
   { s_cm252 + 1, NULL       , "SET",                3, 1, 0xc015, 0 },
   { s_cm252 + 2, NULL       , "CONSOLE",            7, 1, 0xc015, 0 },
   { s_cm252 + 3, NULL       , "(",                  1, 1, 0xc032, 0 },
   { s_cm252 + 4, NULL       , "x",                  1, 0, 0xe001, 1 },
   { NULL       , NULL       , ")",                  1, 0, 0xc033, 0 }
};
static HB_PP_TOKEN s_cr252[ 6 ] = {
   { s_cr252 + 1, NULL       , "Set",                3, 1, 0xc015, 0 },
   { s_cr252 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr252 + 3, NULL       , "_SET_CONSOLE",      12, 1, 0xc015, 0 },
   { s_cr252 + 4, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr252 + 5, NULL       , "x",                  1, 1, 0xc00b, 1 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm253[ 8 ] = {
   { s_cm253 + 1, NULL       , "SET",                3, 1, 0xc015, 0 },
   { s_cm253 + 2, NULL       , "CONSOLE",            7, 1, 0xc015, 0 },
   { NULL       , s_cm253 + 3, "x",                  1, 0, 0xc003, 1 },
   { s_cm253 + 4, NULL       , "ON",                 2, 0, 0xc015, 0 },
   { s_cm253 + 5, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cm253 + 6, NULL       , "OFF",                3, 0, 0xc015, 0 },
   { s_cm253 + 7, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { NULL       , NULL       , "&",                  1, 0, 0xc039, 0 }
};
static HB_PP_TOKEN s_cr253[ 6 ] = {
   { s_cr253 + 1, NULL       , "Set",                3, 1, 0xc015, 0 },
   { s_cr253 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr253 + 3, NULL       , "_SET_CONSOLE",      12, 1, 0xc015, 0 },
   { s_cr253 + 4, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr253 + 5, NULL       , "x",                  1, 1, 0xc00e, 1 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm254[ 5 ] = {
   { s_cm254 + 1, NULL       , "SET",                3, 1, 0xc015, 0 },
   { s_cm254 + 2, NULL       , "DELETED",            7, 1, 0xc015, 0 },
   { s_cm254 + 3, NULL       , "(",                  1, 1, 0xc032, 0 },
   { s_cm254 + 4, NULL       , "x",                  1, 0, 0xe001, 1 },
   { NULL       , NULL       , ")",                  1, 0, 0xc033, 0 }
};
static HB_PP_TOKEN s_cr254[ 6 ] = {
   { s_cr254 + 1, NULL       , "Set",                3, 1, 0xc015, 0 },
   { s_cr254 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr254 + 3, NULL       , "_SET_DELETED",      12, 1, 0xc015, 0 },
   { s_cr254 + 4, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr254 + 5, NULL       , "x",                  1, 1, 0xc00b, 1 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm255[ 8 ] = {
   { s_cm255 + 1, NULL       , "SET",                3, 1, 0xc015, 0 },
   { s_cm255 + 2, NULL       , "DELETED",            7, 1, 0xc015, 0 },
   { NULL       , s_cm255 + 3, "x",                  1, 0, 0xc003, 1 },
   { s_cm255 + 4, NULL       , "ON",                 2, 0, 0xc015, 0 },
   { s_cm255 + 5, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cm255 + 6, NULL       , "OFF",                3, 0, 0xc015, 0 },
   { s_cm255 + 7, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { NULL       , NULL       , "&",                  1, 0, 0xc039, 0 }
};
static HB_PP_TOKEN s_cr255[ 6 ] = {
   { s_cr255 + 1, NULL       , "Set",                3, 1, 0xc015, 0 },
   { s_cr255 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr255 + 3, NULL       , "_SET_DELETED",      12, 1, 0xc015, 0 },
   { s_cr255 + 4, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr255 + 5, NULL       , "x",                  1, 1, 0xc00e, 1 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm256[ 5 ] = {
   { s_cm256 + 1, NULL       , "SET",                3, 1, 0xc015, 0 },
   { s_cm256 + 2, NULL       , "UNIQUE",             6, 1, 0xc015, 0 },
   { s_cm256 + 3, NULL       , "(",                  1, 1, 0xc032, 0 },
   { s_cm256 + 4, NULL       , "x",                  1, 0, 0xe001, 1 },
   { NULL       , NULL       , ")",                  1, 0, 0xc033, 0 }
};
static HB_PP_TOKEN s_cr256[ 6 ] = {
   { s_cr256 + 1, NULL       , "Set",                3, 1, 0xc015, 0 },
   { s_cr256 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr256 + 3, NULL       , "_SET_UNIQUE",       11, 1, 0xc015, 0 },
   { s_cr256 + 4, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr256 + 5, NULL       , "x",                  1, 1, 0xc00b, 1 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm257[ 8 ] = {
   { s_cm257 + 1, NULL       , "SET",                3, 1, 0xc015, 0 },
   { s_cm257 + 2, NULL       , "UNIQUE",             6, 1, 0xc015, 0 },
   { NULL       , s_cm257 + 3, "x",                  1, 0, 0xc003, 1 },
   { s_cm257 + 4, NULL       , "ON",                 2, 0, 0xc015, 0 },
   { s_cm257 + 5, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cm257 + 6, NULL       , "OFF",                3, 0, 0xc015, 0 },
   { s_cm257 + 7, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { NULL       , NULL       , "&",                  1, 0, 0xc039, 0 }
};
static HB_PP_TOKEN s_cr257[ 6 ] = {
   { s_cr257 + 1, NULL       , "Set",                3, 1, 0xc015, 0 },
   { s_cr257 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr257 + 3, NULL       , "_SET_UNIQUE",       11, 1, 0xc015, 0 },
   { s_cr257 + 4, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr257 + 5, NULL       , "x",                  1, 1, 0xc00e, 1 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm258[ 5 ] = {
   { s_cm258 + 1, NULL       , "SET",                3, 1, 0xc015, 0 },
   { s_cm258 + 2, NULL       , "SOFTSEEK",           8, 1, 0xc015, 0 },
   { s_cm258 + 3, NULL       , "(",                  1, 1, 0xc032, 0 },
   { s_cm258 + 4, NULL       , "x",                  1, 0, 0xe001, 1 },
   { NULL       , NULL       , ")",                  1, 0, 0xc033, 0 }
};
static HB_PP_TOKEN s_cr258[ 6 ] = {
   { s_cr258 + 1, NULL       , "Set",                3, 1, 0xc015, 0 },
   { s_cr258 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr258 + 3, NULL       , "_SET_SOFTSEEK",     13, 1, 0xc015, 0 },
   { s_cr258 + 4, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr258 + 5, NULL       , "x",                  1, 1, 0xc00b, 1 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm259[ 8 ] = {
   { s_cm259 + 1, NULL       , "SET",                3, 1, 0xc015, 0 },
   { s_cm259 + 2, NULL       , "SOFTSEEK",           8, 1, 0xc015, 0 },
   { NULL       , s_cm259 + 3, "x",                  1, 0, 0xc003, 1 },
   { s_cm259 + 4, NULL       , "ON",                 2, 0, 0xc015, 0 },
   { s_cm259 + 5, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cm259 + 6, NULL       , "OFF",                3, 0, 0xc015, 0 },
   { s_cm259 + 7, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { NULL       , NULL       , "&",                  1, 0, 0xc039, 0 }
};
static HB_PP_TOKEN s_cr259[ 6 ] = {
   { s_cr259 + 1, NULL       , "Set",                3, 1, 0xc015, 0 },
   { s_cr259 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr259 + 3, NULL       , "_SET_SOFTSEEK",     13, 1, 0xc015, 0 },
   { s_cr259 + 4, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr259 + 5, NULL       , "x",                  1, 1, 0xc00e, 1 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm260[ 5 ] = {
   { s_cm260 + 1, NULL       , "SET",                3, 1, 0xc015, 0 },
   { s_cm260 + 2, NULL       , "EXCLUSIVE",          9, 1, 0xc015, 0 },
   { s_cm260 + 3, NULL       , "(",                  1, 1, 0xc032, 0 },
   { s_cm260 + 4, NULL       , "x",                  1, 0, 0xe001, 1 },
   { NULL       , NULL       , ")",                  1, 0, 0xc033, 0 }
};
static HB_PP_TOKEN s_cr260[ 6 ] = {
   { s_cr260 + 1, NULL       , "Set",                3, 1, 0xc015, 0 },
   { s_cr260 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr260 + 3, NULL       , "_SET_EXCLUSIVE",    14, 1, 0xc015, 0 },
   { s_cr260 + 4, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr260 + 5, NULL       , "x",                  1, 1, 0xc00b, 1 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm261[ 8 ] = {
   { s_cm261 + 1, NULL       , "SET",                3, 1, 0xc015, 0 },
   { s_cm261 + 2, NULL       , "EXCLUSIVE",          9, 1, 0xc015, 0 },
   { NULL       , s_cm261 + 3, "x",                  1, 0, 0xc003, 1 },
   { s_cm261 + 4, NULL       , "ON",                 2, 0, 0xc015, 0 },
   { s_cm261 + 5, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cm261 + 6, NULL       , "OFF",                3, 0, 0xc015, 0 },
   { s_cm261 + 7, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { NULL       , NULL       , "&",                  1, 0, 0xc039, 0 }
};
static HB_PP_TOKEN s_cr261[ 6 ] = {
   { s_cr261 + 1, NULL       , "Set",                3, 1, 0xc015, 0 },
   { s_cr261 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr261 + 3, NULL       , "_SET_EXCLUSIVE",    14, 1, 0xc015, 0 },
   { s_cr261 + 4, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr261 + 5, NULL       , "x",                  1, 1, 0xc00e, 1 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm262[ 5 ] = {
   { s_cm262 + 1, NULL       , "SET",                3, 1, 0xc015, 0 },
   { s_cm262 + 2, NULL       , "FIXED",              5, 1, 0xc015, 0 },
   { s_cm262 + 3, NULL       , "(",                  1, 1, 0xc032, 0 },
   { s_cm262 + 4, NULL       , "x",                  1, 0, 0xe001, 1 },
   { NULL       , NULL       , ")",                  1, 0, 0xc033, 0 }
};
static HB_PP_TOKEN s_cr262[ 6 ] = {
   { s_cr262 + 1, NULL       , "Set",                3, 1, 0xc015, 0 },
   { s_cr262 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr262 + 3, NULL       , "_SET_FIXED",        10, 1, 0xc015, 0 },
   { s_cr262 + 4, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr262 + 5, NULL       , "x",                  1, 1, 0xc00b, 1 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm263[ 8 ] = {
   { s_cm263 + 1, NULL       , "SET",                3, 1, 0xc015, 0 },
   { s_cm263 + 2, NULL       , "FIXED",              5, 1, 0xc015, 0 },
   { NULL       , s_cm263 + 3, "x",                  1, 0, 0xc003, 1 },
   { s_cm263 + 4, NULL       , "ON",                 2, 0, 0xc015, 0 },
   { s_cm263 + 5, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cm263 + 6, NULL       , "OFF",                3, 0, 0xc015, 0 },
   { s_cm263 + 7, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { NULL       , NULL       , "&",                  1, 0, 0xc039, 0 }
};
static HB_PP_TOKEN s_cr263[ 6 ] = {
   { s_cr263 + 1, NULL       , "Set",                3, 1, 0xc015, 0 },
   { s_cr263 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr263 + 3, NULL       , "_SET_FIXED",        10, 1, 0xc015, 0 },
   { s_cr263 + 4, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr263 + 5, NULL       , "x",                  1, 1, 0xc00e, 1 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm264[ 5 ] = {
   { s_cm264 + 1, NULL       , "SET",                3, 1, 0xc015, 0 },
   { s_cm264 + 2, NULL       , "EXACT",              5, 1, 0xc015, 0 },
   { s_cm264 + 3, NULL       , "(",                  1, 1, 0xc032, 0 },
   { s_cm264 + 4, NULL       , "x",                  1, 0, 0xe001, 1 },
   { NULL       , NULL       , ")",                  1, 0, 0xc033, 0 }
};
static HB_PP_TOKEN s_cr264[ 6 ] = {
   { s_cr264 + 1, NULL       , "Set",                3, 1, 0xc015, 0 },
   { s_cr264 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr264 + 3, NULL       , "_SET_EXACT",        10, 1, 0xc015, 0 },
   { s_cr264 + 4, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr264 + 5, NULL       , "x",                  1, 1, 0xc00b, 1 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm265[ 8 ] = {
   { s_cm265 + 1, NULL       , "SET",                3, 1, 0xc015, 0 },
   { s_cm265 + 2, NULL       , "EXACT",              5, 1, 0xc015, 0 },
   { NULL       , s_cm265 + 3, "x",                  1, 0, 0xc003, 1 },
   { s_cm265 + 4, NULL       , "ON",                 2, 0, 0xc015, 0 },
   { s_cm265 + 5, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cm265 + 6, NULL       , "OFF",                3, 0, 0xc015, 0 },
   { s_cm265 + 7, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { NULL       , NULL       , "&",                  1, 0, 0xc039, 0 }
};
static HB_PP_TOKEN s_cr265[ 6 ] = {
   { s_cr265 + 1, NULL       , "Set",                3, 1, 0xc015, 0 },
   { s_cr265 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr265 + 3, NULL       , "_SET_EXACT",        10, 1, 0xc015, 0 },
   { s_cr265 + 4, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr265 + 5, NULL       , "x",                  1, 1, 0xc00e, 1 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm266[ 3 ] = {
   { s_cm266 + 1, NULL       , "SET",                3, 1, 0xc015, 0 },
   { s_cm266 + 2, NULL       , "PATH",               4, 1, 0xc015, 0 },
   { NULL       , NULL       , "TO",                 2, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_cr266[ 6 ] = {
   { s_cr266 + 1, NULL       , "Set",                3, 1, 0xc015, 0 },
   { s_cr266 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr266 + 3, NULL       , "_SET_PATH",          9, 1, 0xc015, 0 },
   { s_cr266 + 4, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr266 + 5, NULL       , "",                   0, 1, 0xc029, 0 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm267[ 4 ] = {
   { s_cm267 + 1, NULL       , "SET",                3, 1, 0xc015, 0 },
   { s_cm267 + 2, NULL       , "PATH",               4, 1, 0xc015, 0 },
   { s_cm267 + 3, NULL       , "TO",                 2, 1, 0xc015, 0 },
   { NULL       , NULL       , "pth",                3, 0, 0xe004, 1 }
};
static HB_PP_TOKEN s_cr267[ 6 ] = {
   { s_cr267 + 1, NULL       , "Set",                3, 1, 0xc015, 0 },
   { s_cr267 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr267 + 3, NULL       , "_SET_PATH",          9, 1, 0xc015, 0 },
   { s_cr267 + 4, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr267 + 5, NULL       , "pth",                3, 1, 0xc00e, 1 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm268[ 3 ] = {
   { s_cm268 + 1, NULL       , "SET",                3, 1, 0xc015, 0 },
   { s_cm268 + 2, NULL       , "DEFAULT",            7, 1, 0xc015, 0 },
   { NULL       , NULL       , "TO",                 2, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_cr268[ 6 ] = {
   { s_cr268 + 1, NULL       , "Set",                3, 1, 0xc015, 0 },
   { s_cr268 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr268 + 3, NULL       , "_SET_DEFAULT",      12, 1, 0xc015, 0 },
   { s_cr268 + 4, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr268 + 5, NULL       , "",                   0, 1, 0xc029, 0 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm269[ 4 ] = {
   { s_cm269 + 1, NULL       , "SET",                3, 1, 0xc015, 0 },
   { s_cm269 + 2, NULL       , "DEFAULT",            7, 1, 0xc015, 0 },
   { s_cm269 + 3, NULL       , "TO",                 2, 1, 0xc015, 0 },
   { NULL       , NULL       , "path",               4, 0, 0xe005, 1 }
};
static HB_PP_TOKEN s_cr269[ 6 ] = {
   { s_cr269 + 1, NULL       , "Set",                3, 1, 0xc015, 0 },
   { s_cr269 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr269 + 3, NULL       , "_SET_DEFAULT",      12, 1, 0xc015, 0 },
   { s_cr269 + 4, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr269 + 5, NULL       , "path",               4, 1, 0xc00e, 1 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm270[ 3 ] = {
   { s_cm270 + 1, NULL       , "SET",                3, 1, 0xc015, 0 },
   { s_cm270 + 2, NULL       , "DECIMALS",           8, 1, 0xc015, 0 },
   { NULL       , NULL       , "TO",                 2, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_cr270[ 6 ] = {
   { s_cr270 + 1, NULL       , "Set",                3, 1, 0xc015, 0 },
   { s_cr270 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr270 + 3, NULL       , "_SET_DECIMALS",     13, 1, 0xc015, 0 },
   { s_cr270 + 4, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr270 + 5, NULL       , "0",                  1, 1, 0xc02a, 0 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm271[ 4 ] = {
   { s_cm271 + 1, NULL       , "SET",                3, 1, 0xc015, 0 },
   { s_cm271 + 2, NULL       , "DECIMALS",           8, 1, 0xc015, 0 },
   { s_cm271 + 3, NULL       , "TO",                 2, 1, 0xc015, 0 },
   { NULL       , NULL       , "x",                  1, 0, 0xe001, 1 }
};
static HB_PP_TOKEN s_cr271[ 6 ] = {
   { s_cr271 + 1, NULL       , "Set",                3, 1, 0xc015, 0 },
   { s_cr271 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr271 + 3, NULL       , "_SET_DECIMALS",     13, 1, 0xc015, 0 },
   { s_cr271 + 4, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr271 + 5, NULL       , "x",                  1, 1, 0xc00b, 1 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm272[ 4 ] = {
   { s_cm272 + 1, NULL       , "SET",                3, 1, 0xc015, 0 },
   { s_cm272 + 2, NULL       , "EPOCH",              5, 1, 0xc015, 0 },
   { s_cm272 + 3, NULL       , "TO",                 2, 1, 0xc015, 0 },
   { NULL       , NULL       , "y",                  1, 0, 0xe001, 1 }
};
static HB_PP_TOKEN s_cr272[ 6 ] = {
   { s_cr272 + 1, NULL       , "Set",                3, 1, 0xc015, 0 },
   { s_cr272 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr272 + 3, NULL       , "_SET_EPOCH",        10, 1, 0xc015, 0 },
   { s_cr272 + 4, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr272 + 5, NULL       , "y",                  1, 1, 0xc00b, 1 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm273[ 4 ] = {
   { s_cm273 + 1, NULL       , "SET",                3, 1, 0xc015, 0 },
   { s_cm273 + 2, NULL       , "EOL",                3, 1, 0xc015, 0 },
   { s_cm273 + 3, NULL       , "TO",                 2, 3, 0xc015, 0 },
   { NULL       , NULL       , "y",                  1, 0, 0xe001, 1 }
};
static HB_PP_TOKEN s_cr273[ 6 ] = {
   { s_cr273 + 1, NULL       , "Set",                3, 1, 0xc015, 0 },
   { s_cr273 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr273 + 3, NULL       , "_SET_EOL",           8, 1, 0xc015, 0 },
   { s_cr273 + 4, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr273 + 5, NULL       , "y",                  1, 1, 0xc00b, 1 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm274[ 6 ] = {
   { s_cm274 + 1, NULL       , "SET",                3, 1, 0xc015, 0 },
   { s_cm274 + 2, NULL       , "DATE",               4, 1, 0xc015, 0 },
   { s_cm274 + 3, NULL       , "FORMAT",             6, 1, 0xc015, 0 },
   { s_cm274 + 5, s_cm274 + 4, "[",                  1, 1, 0xe007, 0 },
   { NULL       , NULL       , "TO",                 2, 0, 0xc015, 0 },
   { NULL       , NULL       , "f",                  1, 0, 0xe001, 1 }
};
static HB_PP_TOKEN s_cr274[ 6 ] = {
   { s_cr274 + 1, NULL       , "Set",                3, 1, 0xc015, 0 },
   { s_cr274 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr274 + 3, NULL       , "_SET_DATEFORMAT",   15, 1, 0xc015, 0 },
   { s_cr274 + 4, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr274 + 5, NULL       , "f",                  1, 1, 0xc00b, 1 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm275[ 5 ] = {
   { s_cm275 + 1, NULL       , "SET",                3, 1, 0xc015, 0 },
   { s_cm275 + 2, NULL       , "CENTURY",            7, 1, 0xc015, 0 },
   { s_cm275 + 3, NULL       , "(",                  1, 1, 0xc032, 0 },
   { s_cm275 + 4, NULL       , "x",                  1, 0, 0xe001, 1 },
   { NULL       , NULL       , ")",                  1, 0, 0xc033, 0 }
};
static HB_PP_TOKEN s_cr275[ 4 ] = {
   { s_cr275 + 1, NULL       , "__SetCentury",      12, 1, 0xc015, 0 },
   { s_cr275 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr275 + 3, NULL       , "x",                  1, 1, 0xc00b, 1 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm276[ 8 ] = {
   { s_cm276 + 1, NULL       , "SET",                3, 1, 0xc015, 0 },
   { s_cm276 + 2, NULL       , "CENTURY",            7, 1, 0xc015, 0 },
   { NULL       , s_cm276 + 3, "x",                  1, 0, 0xc003, 1 },
   { s_cm276 + 4, NULL       , "ON",                 2, 0, 0xc015, 0 },
   { s_cm276 + 5, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cm276 + 6, NULL       , "OFF",                3, 0, 0xc015, 0 },
   { s_cm276 + 7, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { NULL       , NULL       , "&",                  1, 0, 0xc039, 0 }
};
static HB_PP_TOKEN s_cr276[ 4 ] = {
   { s_cr276 + 1, NULL       , "__SetCentury",      12, 1, 0xc015, 0 },
   { s_cr276 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr276 + 3, NULL       , "x",                  1, 1, 0xc00e, 1 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm277[ 5 ] = {
   { s_cm277 + 1, NULL       , "SET",                3, 1, 0xc015, 0 },
   { s_cm277 + 2, NULL       , "DATE",               4, 1, 0xc015, 0 },
   { s_cm277 + 4, s_cm277 + 3, "[",                  1, 1, 0xe007, 0 },
   { NULL       , NULL       , "TO",                 2, 0, 0xc015, 0 },
   { NULL       , NULL       , "USA",                3, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_cr277[ 6 ] = {
   { s_cr277 + 1, NULL       , "_DFSET",             6, 1, 0xc015, 0 },
   { s_cr277 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr277 + 3, NULL       , "mm-dd-yyyy",        10, 1, 0xc029, 0 },
   { s_cr277 + 4, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr277 + 5, NULL       , "mm-dd-yy",           8, 1, 0xc029, 0 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm278[ 5 ] = {
   { s_cm278 + 1, NULL       , "SET",                3, 1, 0xc015, 0 },
   { s_cm278 + 2, NULL       , "DATE",               4, 1, 0xc015, 0 },
   { s_cm278 + 4, s_cm278 + 3, "[",                  1, 1, 0xe007, 0 },
   { NULL       , NULL       , "TO",                 2, 0, 0xc015, 0 },
   { NULL       , NULL       , "JAPANESE",           8, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_cr278[ 6 ] = {
   { s_cr278 + 1, NULL       , "_DFSET",             6, 1, 0xc015, 0 },
   { s_cr278 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr278 + 3, NULL       , "yyyy/mm/dd",        10, 1, 0xc029, 0 },
   { s_cr278 + 4, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr278 + 5, NULL       , "yy/mm/dd",           8, 1, 0xc029, 0 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm279[ 5 ] = {
   { s_cm279 + 1, NULL       , "SET",                3, 1, 0xc015, 0 },
   { s_cm279 + 2, NULL       , "DATE",               4, 1, 0xc015, 0 },
   { s_cm279 + 4, s_cm279 + 3, "[",                  1, 1, 0xe007, 0 },
   { NULL       , NULL       , "TO",                 2, 0, 0xc015, 0 },
   { NULL       , NULL       , "ITALIAN",            7, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_cr279[ 6 ] = {
   { s_cr279 + 1, NULL       , "_DFSET",             6, 1, 0xc015, 0 },
   { s_cr279 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr279 + 3, NULL       , "dd-mm-yyyy",        10, 1, 0xc029, 0 },
   { s_cr279 + 4, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr279 + 5, NULL       , "dd-mm-yy",           8, 1, 0xc029, 0 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm280[ 5 ] = {
   { s_cm280 + 1, NULL       , "SET",                3, 1, 0xc015, 0 },
   { s_cm280 + 2, NULL       , "DATE",               4, 1, 0xc015, 0 },
   { s_cm280 + 4, s_cm280 + 3, "[",                  1, 1, 0xe007, 0 },
   { NULL       , NULL       , "TO",                 2, 0, 0xc015, 0 },
   { NULL       , NULL       , "GERMAN",             6, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_cr280[ 6 ] = {
   { s_cr280 + 1, NULL       , "_DFSET",             6, 1, 0xc015, 0 },
   { s_cr280 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr280 + 3, NULL       , "dd.mm.yyyy",        10, 1, 0xc029, 0 },
   { s_cr280 + 4, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr280 + 5, NULL       , "dd.mm.yy",           8, 1, 0xc029, 0 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm281[ 5 ] = {
   { s_cm281 + 1, NULL       , "SET",                3, 1, 0xc015, 0 },
   { s_cm281 + 2, NULL       , "DATE",               4, 1, 0xc015, 0 },
   { s_cm281 + 4, s_cm281 + 3, "[",                  1, 1, 0xe007, 0 },
   { NULL       , NULL       , "TO",                 2, 0, 0xc015, 0 },
   { NULL       , NULL       , "FRENCH",             6, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_cr281[ 6 ] = {
   { s_cr281 + 1, NULL       , "_DFSET",             6, 1, 0xc015, 0 },
   { s_cr281 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr281 + 3, NULL       , "dd/mm/yyyy",        10, 1, 0xc029, 0 },
   { s_cr281 + 4, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr281 + 5, NULL       , "dd/mm/yy",           8, 1, 0xc029, 0 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm282[ 5 ] = {
   { s_cm282 + 1, NULL       , "SET",                3, 1, 0xc015, 0 },
   { s_cm282 + 2, NULL       , "DATE",               4, 1, 0xc015, 0 },
   { s_cm282 + 4, s_cm282 + 3, "[",                  1, 1, 0xe007, 0 },
   { NULL       , NULL       , "TO",                 2, 0, 0xc015, 0 },
   { NULL       , NULL       , "BRITISH",            7, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_cr282[ 6 ] = {
   { s_cr282 + 1, NULL       , "_DFSET",             6, 1, 0xc015, 0 },
   { s_cr282 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr282 + 3, NULL       , "dd/mm/yyyy",        10, 1, 0xc029, 0 },
   { s_cr282 + 4, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr282 + 5, NULL       , "dd/mm/yy",           8, 1, 0xc029, 0 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm283[ 5 ] = {
   { s_cm283 + 1, NULL       , "SET",                3, 1, 0xc015, 0 },
   { s_cm283 + 2, NULL       , "DATE",               4, 1, 0xc015, 0 },
   { s_cm283 + 4, s_cm283 + 3, "[",                  1, 1, 0xe007, 0 },
   { NULL       , NULL       , "TO",                 2, 0, 0xc015, 0 },
   { NULL       , NULL       , "ANSI",               4, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_cr283[ 6 ] = {
   { s_cr283 + 1, NULL       , "_DFSET",             6, 1, 0xc015, 0 },
   { s_cr283 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr283 + 3, NULL       , "yyyy.mm.dd",        10, 1, 0xc029, 0 },
   { s_cr283 + 4, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr283 + 5, NULL       , "yy.mm.dd",           8, 1, 0xc029, 0 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm284[ 5 ] = {
   { s_cm284 + 1, NULL       , "SET",                3, 1, 0xc015, 0 },
   { s_cm284 + 2, NULL       , "DATE",               4, 1, 0xc015, 0 },
   { s_cm284 + 4, s_cm284 + 3, "[",                  1, 1, 0xe007, 0 },
   { NULL       , NULL       , "TO",                 2, 0, 0xc015, 0 },
   { NULL       , NULL       , "AMERICAN",           8, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_cr284[ 6 ] = {
   { s_cr284 + 1, NULL       , "_DFSET",             6, 1, 0xc015, 0 },
   { s_cr284 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr284 + 3, NULL       , "mm/dd/yyyy",        10, 1, 0xc029, 0 },
   { s_cr284 + 4, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr284 + 5, NULL       , "mm/dd/yy",           8, 1, 0xc029, 0 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm285[ 3 ] = {
   { s_cm285 + 1, NULL       , "SET",                3, 1, 0xc015, 0 },
   { s_cm285 + 2, NULL       , "FORMAT",             6, 1, 0xc015, 0 },
   { NULL       , NULL       , "TO",                 2, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_cr285[ 3 ] = {
   { s_cr285 + 1, NULL       , "__SetFormat",       11, 1, 0xc015, 0 },
   { s_cr285 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { NULL       , NULL       , ")",                  1, 0, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm286[ 5 ] = {
   { s_cm286 + 1, NULL       , "SET",                3, 1, 0xc015, 0 },
   { s_cm286 + 2, NULL       , "FORMAT",             6, 1, 0xc015, 0 },
   { s_cm286 + 3, NULL       , "TO",                 2, 1, 0xc015, 0 },
   { NULL       , s_cm286 + 4, "id",                 2, 0, 0xc003, 1 },
   { NULL       , NULL       , "&",                  1, 0, 0xc039, 0 }
};
static HB_PP_TOKEN s_cr286[ 27 ] = {
   { s_cr286 + 1, NULL       , "if",                 2, 1, 0xc015, 0 },
   { s_cr286 + 2, NULL       , "(",                  1, 1, 0xc032, 0 },
   { s_cr286 + 3, NULL       , "Empty",              5, 1, 0xc015, 0 },
   { s_cr286 + 4, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr286 + 5, NULL       , "id",                 2, 0, 0xc00e, 1 },
   { s_cr286 + 6, NULL       , ")",                  1, 0, 0xc033, 0 },
   { s_cr286 + 7, NULL       , ")",                  1, 1, 0xc033, 0 },
   { s_cr286 + 8, NULL       , ";",                  1, 1, 0xc01e, 0 },
   { s_cr286 + 9, NULL       , "SET",                3, 1, 0xc015, 0 },
   { s_cr286 +10, NULL       , "FORMAT",             6, 1, 0xc015, 0 },
   { s_cr286 +11, NULL       , "TO",                 2, 1, 0xc015, 0 },
   { s_cr286 +12, NULL       , ";",                  1, 1, 0xc01e, 0 },
   { s_cr286 +13, NULL       , "else",               4, 1, 0xc015, 0 },
   { s_cr286 +14, NULL       , ";",                  1, 1, 0xc01e, 0 },
   { s_cr286 +15, NULL       , "__SetFormat",       11, 1, 0xc015, 0 },
   { s_cr286 +16, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr286 +17, NULL       , "&",                  1, 1, 0xc039, 0 },
   { s_cr286 +18, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr286 +19, NULL       , "{||",                3, 0, 0xc029, 0 },
   { s_cr286 +20, NULL       , "+",                  1, 1, 0xc050, 0 },
   { s_cr286 +21, NULL       , "id",                 2, 1, 0xc00e, 1 },
   { s_cr286 +22, NULL       , "+",                  1, 1, 0xc050, 0 },
   { s_cr286 +23, NULL       , "()}",                3, 1, 0xc029, 0 },
   { s_cr286 +24, NULL       , ")",                  1, 0, 0xc033, 0 },
   { s_cr286 +25, NULL       , ")",                  1, 1, 0xc033, 0 },
   { s_cr286 +26, NULL       , ";",                  1, 1, 0xc01e, 0 },
   { NULL       , NULL       , "end",                3, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_cm287[ 6 ] = {
   { s_cm287 + 1, NULL       , "SET",                3, 1, 0xc015, 0 },
   { s_cm287 + 2, NULL       , "FORMAT",             6, 1, 0xc015, 0 },
   { s_cm287 + 3, NULL       , "TO",                 2, 1, 0xc015, 0 },
   { s_cm287 + 4, NULL       , "id",                 2, 0, 0xe001, 1 },
   { s_cm287 + 5, NULL       , ".",                  1, 0, 0xc01c, 0 },
   { NULL       , NULL       , "ext",                3, 0, 0xe001, 2 }
};
static HB_PP_TOKEN s_cr287[ 19 ] = {
   { s_cr287 + 1, NULL       , "_ProcReq_",          9, 1, 0xc015, 0 },
   { s_cr287 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr287 + 3, NULL       , "id",                 2, 1, 0xc00e, 1 },
   { s_cr287 + 4, NULL       , "+",                  1, 1, 0xc050, 0 },
   { s_cr287 + 5, NULL       , ".",                  1, 1, 0xc029, 0 },
   { s_cr287 + 6, NULL       , "+",                  1, 1, 0xc050, 0 },
   { s_cr287 + 7, NULL       , "ext",                3, 1, 0xc00e, 2 },
   { s_cr287 + 8, NULL       , ")",                  1, 1, 0xc033, 0 },
   { s_cr287 + 9, NULL       , ";",                  1, 1, 0xc01e, 0 },
   { s_cr287 +10, NULL       , "__SetFormat",       11, 1, 0xc015, 0 },
   { s_cr287 +11, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr287 +12, NULL       , "{",                  1, 1, 0xc036, 0 },
   { s_cr287 +13, NULL       , "|",                  1, 0, 0xc01b, 0 },
   { s_cr287 +14, NULL       , "|",                  1, 0, 0xc01b, 0 },
   { s_cr287 +15, NULL       , "id",                 2, 1, 0xc00b, 1 },
   { s_cr287 +16, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr287 +17, NULL       , ")",                  1, 0, 0xc033, 0 },
   { s_cr287 +18, NULL       , "}",                  1, 0, 0xc037, 0 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm288[ 4 ] = {
   { s_cm288 + 1, NULL       , "SET",                3, 1, 0xc015, 0 },
   { s_cm288 + 2, NULL       , "FORMAT",             6, 1, 0xc015, 0 },
   { s_cm288 + 3, NULL       , "TO",                 2, 1, 0xc015, 0 },
   { NULL       , NULL       , "id",                 2, 0, 0xe001, 1 }
};
static HB_PP_TOKEN s_cr288[ 17 ] = {
   { s_cr288 + 1, NULL       , "_ProcReq_",          9, 1, 0xc015, 0 },
   { s_cr288 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr288 + 3, NULL       , "id",                 2, 1, 0xc00e, 1 },
   { s_cr288 + 4, NULL       , "+",                  1, 1, 0xc050, 0 },
   { s_cr288 + 5, NULL       , ".fmt",               4, 1, 0xc029, 0 },
   { s_cr288 + 6, NULL       , ")",                  1, 1, 0xc033, 0 },
   { s_cr288 + 7, NULL       , ";",                  1, 1, 0xc01e, 0 },
   { s_cr288 + 8, NULL       , "__SetFormat",       11, 1, 0xc015, 0 },
   { s_cr288 + 9, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr288 +10, NULL       , "{",                  1, 1, 0xc036, 0 },
   { s_cr288 +11, NULL       , "|",                  1, 0, 0xc01b, 0 },
   { s_cr288 +12, NULL       , "|",                  1, 0, 0xc01b, 0 },
   { s_cr288 +13, NULL       , "id",                 2, 1, 0xc00b, 1 },
   { s_cr288 +14, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr288 +15, NULL       , ")",                  1, 0, 0xc033, 0 },
   { s_cr288 +16, NULL       , "}",                  1, 0, 0xc037, 0 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm289[ 4 ] = {
   { s_cm289 + 1, NULL       , "SET",                3, 1, 0xc015, 0 },
   { s_cm289 + 2, NULL       , "PROCEDURE",          9, 1, 0xc015, 0 },
   { s_cm289 + 3, NULL       , "TO",                 2, 1, 0xc015, 0 },
   { NULL       , NULL       , "f",                  1, 0, 0xe001, 1 }
};
static HB_PP_TOKEN s_cr289[ 4 ] = {
   { s_cr289 + 1, NULL       , "_ProcReq_",          9, 1, 0xc015, 0 },
   { s_cr289 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr289 + 3, NULL       , "f",                  1, 1, 0xc00e, 1 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cm290[ 3 ] = {
   { s_cm290 + 1, NULL       , "SET",                3, 1, 0xc015, 0 },
   { s_cm290 + 2, NULL       , "PROCEDURE",          9, 1, 0xc015, 0 },
   { NULL       , NULL       , "TO",                 2, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_cm291[ 3 ] = {
   { s_cm291 + 1, NULL       , "SET",                3, 1, 0xc015, 0 },
   { s_cm291 + 2, NULL       , "TALK",               4, 1, 0xc015, 0 },
   { NULL       , NULL       , "x",                  1, 0, 0xe004, 0 }
};
static HB_PP_TOKEN s_cm292[ 3 ] = {
   { s_cm292 + 1, NULL       , "SET",                3, 1, 0xc015, 0 },
   { s_cm292 + 2, NULL       , "SAFETY",             6, 1, 0xc015, 0 },
   { NULL       , NULL       , "x",                  1, 0, 0xe004, 0 }
};
static HB_PP_TOKEN s_cm293[ 3 ] = {
   { s_cm293 + 1, NULL       , "SET",                3, 1, 0xc015, 0 },
   { s_cm293 + 2, NULL       , "STEP",               4, 1, 0xc015, 0 },
   { NULL       , NULL       , "x",                  1, 0, 0xe004, 0 }
};
static HB_PP_TOKEN s_cm294[ 3 ] = {
   { s_cm294 + 1, NULL       , "SET",                3, 1, 0xc015, 0 },
   { s_cm294 + 2, NULL       , "STATUS",             6, 1, 0xc015, 0 },
   { NULL       , NULL       , "x",                  1, 0, 0xe004, 0 }
};
static HB_PP_TOKEN s_cm295[ 3 ] = {
   { s_cm295 + 1, NULL       , "SET",                3, 1, 0xc015, 0 },
   { s_cm295 + 2, NULL       , "MENU",               4, 1, 0xc015, 0 },
   { NULL       , NULL       , "x",                  1, 0, 0xe004, 0 }
};
static HB_PP_TOKEN s_cm296[ 3 ] = {
   { s_cm296 + 1, NULL       , "SET",                3, 1, 0xc015, 0 },
   { s_cm296 + 2, NULL       , "HEADING",            7, 1, 0xc015, 0 },
   { NULL       , NULL       , "x",                  1, 0, 0xe004, 0 }
};
static HB_PP_TOKEN s_cm297[ 3 ] = {
   { s_cm297 + 1, NULL       , "SET",                3, 1, 0xc015, 0 },
   { s_cm297 + 2, NULL       , "ECHO",               4, 1, 0xc015, 0 },
   { NULL       , NULL       , "x",                  1, 0, 0xe004, 0 }
};
static HB_PP_TOKEN s_cm298[ 7 ] = {
   { s_cm298 + 1, NULL       , "STORE",              5, 1, 0xc015, 0 },
   { s_cm298 + 2, NULL       , "v",                  1, 0, 0xe001, 3 },
   { s_cm298 + 3, NULL       , "TO",                 2, 1, 0xc015, 0 },
   { s_cm298 + 4, NULL       , "v1",                 2, 0, 0xe001, 1 },
   { NULL       , s_cm298 + 5, "[",                  1, 1, 0xe007, 0 },
   { s_cm298 + 6, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { NULL       , NULL       , "vN",                 2, 0, 0xe001, 2 }
};
static HB_PP_TOKEN s_cr298[ 6 ] = {
   { s_cr298 + 1, NULL       , "v1",                 2, 1, 0xc00b, 1 },
   { s_cr298 + 2, NULL       , ":=",                 2, 1, 0xc03c, 0 },
   { s_cr298 + 5, s_cr298 + 3, "[",                  1, 1, 0xc012, 0 },
   { s_cr298 + 4, NULL       , "vN",                 2, 1, 0xc00b, 2 },
   { NULL       , NULL       , ":=",                 2, 1, 0xc03c, 0 },
   { NULL       , NULL       , "v",                  1, 1, 0xc00b, 3 }
};
static HB_PP_TOKEN s_cm299[ 7 ] = {
   { s_cm299 + 1, NULL       , "CALL",               4, 1, 0xc015, 0 },
   { s_cm299 + 2, NULL       , "proc",               4, 0, 0xe001, 1 },
   { s_cm299 + 3, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cm299 + 4, NULL       , ")",                  1, 0, 0xc033, 0 },
   { NULL       , s_cm299 + 5, "[",                  1, 1, 0xe007, 0 },
   { s_cm299 + 6, NULL       , "WITH",               4, 0, 0xc015, 0 },
   { NULL       , NULL       , "p",                  1, 0, 0xe002, 2 }
};
static HB_PP_TOKEN s_cr299[ 5 ] = {
   { s_cr299 + 1, NULL       , "call",               4, 1, 0xc015, 0 },
   { s_cr299 + 2, NULL       , "proc",               4, 1, 0xc00b, 1 },
   { NULL       , s_cr299 + 3, "[",                  1, 1, 0xc012, 0 },
   { s_cr299 + 4, NULL       , "WITH",               4, 1, 0xc015, 0 },
   { NULL       , NULL       , "p",                  1, 1, 0xc00b, 2 }
};
static HB_PP_TOKEN s_cm300[ 7 ] = {
   { s_cm300 + 1, NULL       , "DO",                 2, 1, 0xc015, 0 },
   { s_cm300 + 2, NULL       , "proc",               4, 0, 0xe001, 1 },
   { s_cm300 + 3, NULL       , ".",                  1, 0, 0xc01c, 0 },
   { s_cm300 + 4, NULL       , "prg",                3, 0, 0xc015, 0 },
   { NULL       , s_cm300 + 5, "[",                  1, 1, 0xe007, 0 },
   { s_cm300 + 6, NULL       , "WITH",               4, 0, 0xc015, 0 },
   { NULL       , NULL       , "p",                  1, 0, 0xe002, 2 }
};
static HB_PP_TOKEN s_cr300[ 5 ] = {
   { s_cr300 + 1, NULL       , "do",                 2, 1, 0xc015, 0 },
   { s_cr300 + 2, NULL       , "proc",               4, 1, 0xc00b, 1 },
   { NULL       , s_cr300 + 3, "[",                  1, 1, 0xc012, 0 },
   { s_cr300 + 4, NULL       , "WITH",               4, 1, 0xc015, 0 },
   { NULL       , NULL       , "p",                  1, 1, 0xc00b, 2 }
};
static HB_PP_TOKEN s_cm301[ 8 ] = {
   { s_cm301 + 1, NULL       , "NEXT",               4, 1, 0xc015, 0 },
   { s_cm301 + 2, NULL       , "v",                  1, 0, 0xe001, 0 },
   { s_cm301 + 5, s_cm301 + 3, "[",                  1, 1, 0xe007, 0 },
   { s_cm301 + 4, NULL       , "TO",                 2, 0, 0xc015, 0 },
   { NULL       , NULL       , "x",                  1, 0, 0xe001, 0 },
   { NULL       , s_cm301 + 6, "[",                  1, 1, 0xe007, 0 },
   { s_cm301 + 7, NULL       , "STEP",               4, 0, 0xc015, 0 },
   { NULL       , NULL       , "s",                  1, 0, 0xe001, 0 }
};
static HB_PP_TOKEN s_cr301[ 1 ] = {
   { NULL       , NULL       , "next",               4, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_cm302[ 3 ] = {
   { s_cm302 + 1, NULL       , "ENDFOR",             6, 1, 0xc015, 0 },
   { NULL       , s_cm302 + 2, "[",                  1, 1, 0xe007, 0 },
   { NULL       , NULL       , "any",                3, 0, 0xe002, 0 }
};
static HB_PP_TOKEN s_cr302[ 1 ] = {
   { NULL       , NULL       , "nExT",               4, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_cm303[ 4 ] = {
   { s_cm303 + 1, NULL       , "ENDCASE",            7, 1, 0xc015, 0 },
   { s_cm303 + 2, NULL       , "any",                3, 0, 0xe002, 0 },
   { NULL       , s_cm303 + 3, "[",                  1, 1, 0xe007, 0 },
   { NULL       , NULL       , "anymore",            7, 0, 0xe002, 0 }
};
static HB_PP_TOKEN s_cr303[ 1 ] = {
   { NULL       , NULL       , "eNdcasE",            7, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_cm304[ 4 ] = {
   { s_cm304 + 1, NULL       , "ENDIF",              5, 1, 0xc015, 0 },
   { s_cm304 + 2, NULL       , "any",                3, 0, 0xe002, 0 },
   { NULL       , s_cm304 + 3, "[",                  1, 1, 0xe007, 0 },
   { NULL       , NULL       , "anymore",            7, 0, 0xe002, 0 }
};
static HB_PP_TOKEN s_cr304[ 1 ] = {
   { NULL       , NULL       , "eNdiF",              5, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_cm305[ 4 ] = {
   { s_cm305 + 1, NULL       , "ENDDO",              5, 1, 0xc015, 0 },
   { s_cm305 + 2, NULL       , "any",                3, 0, 0xe002, 0 },
   { NULL       , s_cm305 + 3, "[",                  1, 1, 0xe007, 0 },
   { NULL       , NULL       , "anymore",            7, 0, 0xe002, 0 }
};
static HB_PP_TOKEN s_cr305[ 1 ] = {
   { NULL       , NULL       , "eNddO",              5, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_cm306[ 1 ] = {
   { NULL       , NULL       , "ENDSEQUENCE",       11, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_cr306[ 1 ] = {
   { NULL       , NULL       , "end",                3, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_cm307[ 2 ] = {
   { s_cm307 + 1, NULL       , "END",                3, 1, 0xc015, 0 },
   { NULL       , NULL       , "SEQUENCE",           8, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_cr307[ 1 ] = {
   { NULL       , NULL       , "end",                3, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_cm308[ 2 ] = {
   { s_cm308 + 1, NULL       , "END",                3, 1, 0xc015, 0 },
   { NULL       , NULL       , "x",                  1, 0, 0xe001, 0 }
};
static HB_PP_TOKEN s_cr308[ 1 ] = {
   { NULL       , NULL       , "end",                3, 1, 0xc015, 0 }
};
static HB_PP_TOKEN s_cm309[ 3 ] = {
   { s_cm309 + 1, NULL       , "DO",                 2, 1, 0xc015, 0 },
   { s_cm309 + 2, NULL       , "WHILE",              5, 1, 0xc015, 0 },
   { NULL       , NULL       , "exp",                3, 0, 0xe001, 1 }
};
static HB_PP_TOKEN s_cr309[ 2 ] = {
   { s_cr309 + 1, NULL       , "while",              5, 1, 0xc015, 0 },
   { NULL       , NULL       , "exp",                3, 1, 0xc00b, 1 }
};
static HB_PP_TOKEN s_cm310[ 10 ] = {
   { s_cm310 + 1, NULL       , "IF",                 2, 1, 0xc015, 0 },
   { s_cm310 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cm310 + 3, NULL       , "exp1",               4, 0, 0xe001, 1 },
   { s_cm310 + 4, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cm310 + 6, s_cm310 + 5, "[",                  1, 1, 0xe007, 0 },
   { NULL       , NULL       , "exp2",               4, 0, 0xe001, 2 },
   { s_cm310 + 7, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cm310 + 9, s_cm310 + 8, "[",                  1, 1, 0xe007, 0 },
   { NULL       , NULL       , "exp3",               4, 0, 0xe001, 3 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static HB_PP_TOKEN s_cr310[ 8 ] = {
   { s_cr310 + 1, NULL       , "IIF",                3, 1, 0xc015, 0 },
   { s_cr310 + 2, NULL       , "(",                  1, 0, 0xc032, 0 },
   { s_cr310 + 3, NULL       , "exp1",               4, 1, 0xc00b, 1 },
   { s_cr310 + 4, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr310 + 5, NULL       , "exp2",               4, 1, 0xc00b, 2 },
   { s_cr310 + 6, NULL       , ",",                  1, 0, 0xc01d, 0 },
   { s_cr310 + 7, NULL       , "exp3",               4, 1, 0xc00b, 3 },
   { NULL       , NULL       , ")",                  1, 1, 0xc033, 0 }
};
static const HB_PP_DEFRULE s_cmd[ 310 ] = {
   { s_cm001, s_cr001, 1, 4, 0x000a },
   { s_cm002, s_cr002, 1, 6, 0x0028 },
   { s_cm003, s_cr003, 1, 0, 0x0000 },
   { s_cm004, s_cr004, 1, 2, 0x0002 },
   { s_cm005, s_cr005, 1, 1, 0x0000 },
   { s_cm006, s_cr006, 1, 2, 0x0002 },
   { s_cm007, s_cr007, 1, 1, 0x0000 },
   { s_cm008, s_cr008, 2, 1, 0x0000 },
   { s_cm009, s_cr009, 2, 0, 0x0000 },
   { s_cm010, s_cr010, 2, 0, 0x0000 },
   { s_cm011, s_cr011, 2, 1, 0x0000 },
   { s_cm012, s_cr012, 2, 1, 0x0000 },
   { s_cm013, s_cr013, 2, 0, 0x0000 },
   { s_cm014, s_cr014, 2, 0, 0x0000 },
   { s_cm015, s_cr015, 2, 1, 0x0000 },
   { s_cm016, s_cr016, 2, 1, 0x0000 },
   { s_cm017, s_cr017, 2, 2, 0x0000 },
   { s_cm018, s_cr018, 2, 1, 0x0000 },
   { s_cm019, s_cr019, 2, 1, 0x0000 },
   { s_cm020, s_cr020, 2, 1, 0x0000 },
   { s_cm021, s_cr021, 2, 1, 0x0000 },
   { s_cm022, s_cr022, 2, 1, 0x0000 },
   { s_cm023, s_cr023, 2, 1, 0x0000 },
   { s_cm024, s_cr024, 2, 1, 0x0000 },
   { s_cm025, s_cr025, 2, 0, 0x0000 },
   { s_cm026, s_cr026, 2, 1, 0x0000 },
   { s_cm027, s_cr027, 2, 1, 0x0000 },
   { s_cm028, s_cr028, 2, 1, 0x0000 },
   { s_cm029, s_cr029, 2, 1, 0x0000 },
   { s_cm030, s_cr030, 2, 1, 0x0000 },
   { s_cm031, s_cr031, 2, 1, 0x0000 },
   { s_cm032, s_cr032, 2, 1, 0x0000 },
   { s_cm033, s_cr033, 2, 1, 0x0000 },
   { s_cm034, s_cr034, 2, 1, 0x0000 },
   { s_cm035, s_cr035, 2,12, 0x0e00 },
   { s_cm036, s_cr036, 2,11, 0x0700 },
   { s_cm037, s_cr037, 2,15, 0x6000 },
   { s_cm038, s_cr038, 2,20, 0xc0000 },
   { s_cm039, s_cr039, 2,18, 0x30000 },
   { s_cm040, s_cr040, 2,14, 0x3000 },
   { s_cm041, s_cr041, 2, 9, 0x01c0 },
   { s_cm042, s_cr042, 2, 5, 0x0000 },
   { s_cm043, s_cr043, 2, 5, 0x0000 },
   { s_cm044, s_cr044, 2, 6, 0x0028 },
   { s_cm045, s_cr045, 2, 7, 0x0048 },
   { s_cm046, s_cr046, 2, 6, 0x0028 },
   { s_cm047, s_cr047, 1, 2, 0x0003 },
   { s_cm048, s_cr048, 2, 0, 0x0000 },
   { s_cm049, s_cr049, 2, 0, 0x0000 },
   { s_cm050, s_cr050, 2, 0, 0x0000 },
   { s_cm051, s_cr051, 2, 1, 0x0001 },
   { s_cm052, s_cr052, 2, 0, 0x0000 },
   { s_cm053, s_cr053, 2, 3, 0x0000 },
   { s_cm054, s_cr054, 2, 3, 0x0000 },
   { s_cm055, s_cr055, 2,23, 0x8ff82 },
   { s_cm056, s_cr056, 2,23, 0x8ff82 },
   { s_cm057, s_cr057, 2, 4, 0x000c },
   { s_cm058, s_cr058, 2,10, 0x0000 },
   { s_cm059, s_cr059, 2,13, 0x0000 },
   { s_cm060, s_cr060, 2,10, 0x0000 },
   { s_cm061, s_cr061, 2, 9, 0x0000 },
   { s_cm062, s_cr062, 2, 9, 0x000a },
   { s_cm063, s_cr063, 2, 9, 0x000a },
   { s_cm064, s_cr064, 2, 6, 0x0000 },
   { s_cm065, s_cr065, 2, 4, 0x0000 },
   { s_cm066, s_cr066, 2, 7, 0x0060 },
   { s_cm067, s_cr067, 2,10, 0x0000 },
   { s_cm068, s_cr068, 2,10, 0x0000 },
   { s_cm069, s_cr069, 2,10, 0x0000 },
   { s_cm070, s_cr070, 2, 8, 0x0000 },
   { s_cm071, s_cr071, 2, 9, 0x0000 },
   { s_cm072, s_cr072, 2,10, 0x0000 },
   { s_cm073, s_cr073, 2, 8, 0x0000 },
   { s_cm074, s_cr074, 2, 9, 0x0000 },
   { s_cm075, s_cr075, 2, 2, 0x0000 },
   { s_cm076, s_cr076, 2, 1, 0x0000 },
   { s_cm077, s_cr077, 2, 7, 0x0000 },
   { s_cm078, s_cr078, 2, 0, 0x0000 },
   { s_cm079, s_cr079, 2, 5, 0x0000 },
   { s_cm080, s_cr080, 2, 0, 0x0000 },
   { s_cm081, s_cr081, 2, 5, 0x0000 },
   { s_cm082, s_cr082, 2, 4, 0x000c },
   { s_cm083, s_cr083, 2, 9, 0x000c },
   { s_cm084, s_cr084, 2, 1, 0x0000 },
   { s_cm085, s_cr085, 2, 1, 0x0000 },
   { s_cm086, s_cr086, 2, 0, 0x0000 },
   { s_cm087, s_cr087, 2, 7, 0x0070 },
   { s_cm088, s_cr088, 2, 0, 0x0000 },
   { s_cm089, s_cr089, 2, 5, 0x0000 },
   { s_cm090, s_cr090, 2, 3, 0x0000 },
   { s_cm091, s_cr091, 2, 0, 0x0000 },
   { s_cm092, s_cr092, 2, 1, 0x0000 },
   { s_cm093, s_cr093, 2, 1, 0x0000 },
   { s_cm094, s_cr094, 2, 1, 0x0000 },
   { s_cm095, s_cr095, 2, 2, 0x0000 },
   { s_cm096, s_cr096, 2, 1, 0x0000 },
   { s_cm097, s_cr097, 2, 1, 0x0000 },
   { s_cm098, s_cr098, 2, 0, 0x0000 },
   { s_cm099, s_cr099, 2, 0, 0x0000 },
   { s_cm100, s_cr100, 2, 0, 0x0000 },
   { s_cm101, s_cr101, 2, 0, 0x0000 },
   { s_cm102, s_cr102, 2, 0, 0x0000 },
   { s_cm103, s_cr103, 2, 1, 0x0000 },
   { s_cm104, s_cr104, 2, 1, 0x0000 },
   { s_cm105, s_cr105, 2, 0, 0x0000 },
   { s_cm106, s_cr106, 2, 0, 0x0000 },
   { s_cm107, s_cr107, 2, 0, 0x0000 },
   { s_cm108, s_cr108, 2, 0, 0x0000 },
   { s_cm109, s_cr109, 2, 0, 0x0000 },
   { s_cm110, s_cr110, 2, 0, 0x0000 },
   { s_cm111, s_cr111, 2,11, 0x0780 },
   { s_cm112, s_cr112, 2, 0, 0x0000 },
   { s_cm113, s_cr113, 2, 2, 0x0000 },
   { s_cm114, s_cr114, 2, 1, 0x0000 },
   { s_cm115, s_cr115, 2, 0, 0x0000 },
   { s_cm116, s_cr116, 2, 0, 0x0000 },
   { s_cm117, s_cr117, 2, 0, 0x0000 },
   { s_cm118, NULL   , 2, 0, 0x0000 },
   { s_cm119, s_cr119, 2, 0, 0x0000 },
   { s_cm120, s_cr120, 2, 0, 0x0000 },
   { s_cm121, s_cr121, 2, 0, 0x0000 },
   { s_cm122, s_cr122, 2, 0, 0x0000 },
   { s_cm123, s_cr123, 2, 0, 0x0000 },
   { s_cm124, s_cr124, 2, 1, 0x0000 },
   { s_cm125, s_cr125, 2, 1, 0x0000 },
   { s_cm126, s_cr126, 2, 1, 0x0000 },
   { s_cm127, s_cr127, 2, 1, 0x0000 },
   { s_cm128, s_cr128, 2, 1, 0x0000 },
   { s_cm129, s_cr129, 2, 1, 0x0000 },
   { s_cm130, s_cr130, 2, 0, 0x0000 },
   { s_cm131, s_cr131, 2, 0, 0x0000 },
   { s_cm132, s_cr132, 2, 1, 0x0000 },
   { s_cm133, s_cr133, 2, 2, 0x0000 },
   { s_cm134, s_cr134, 2, 3, 0x0004 },
   { s_cm135, s_cr135, 2, 1, 0x0000 },
   { s_cm136, s_cr136, 2, 2, 0x0000 },
   { s_cm137, s_cr137, 2, 2, 0x0000 },
   { s_cm138, s_cr138, 2, 1, 0x0000 },
   { s_cm139, s_cr139, 2, 1, 0x0000 },
   { s_cm140, s_cr140, 2, 2, 0x0000 },
   { s_cm141, s_cr141, 2, 3, 0x0000 },
   { s_cm142, s_cr142, 2, 3, 0x0000 },
   { s_cm143, s_cr143, 2, 3, 0x0000 },
   { s_cm144, s_cr144, 2, 3, 0x0000 },
   { s_cm145, s_cr145, 2, 3, 0x0000 },
   { s_cm146, s_cr146, 2, 3, 0x0000 },
   { s_cm147, s_cr147, 2, 1, 0x0000 },
   { s_cm148, s_cr148, 2, 1, 0x0000 },
   { s_cm149, s_cr149, 2, 0, 0x0000 },
   { s_cm150, s_cr150, 2, 1, 0x0000 },
   { s_cm151, s_cr151, 2, 0, 0x0000 },
   { s_cm152, s_cr152, 2, 0, 0x0000 },
   { s_cm153, s_cr153, 2, 1, 0x0000 },
   { s_cm154, s_cr154, 2, 2, 0x0000 },
   { s_cm155, s_cr155, 2, 2, 0x0000 },
   { s_cm156, s_cr156, 2, 2, 0x0000 },
   { s_cm157, s_cr157, 2, 1, 0x0000 },
   { s_cm158, s_cr158, 2, 1, 0x0000 },
   { s_cm159, s_cr159, 2, 5, 0x0000 },
   { s_cm160, s_cr160, 2, 4, 0x0008 },
   { s_cm161, s_cr161, 2, 5, 0x0010 },
   { s_cm162, s_cr162, 2, 5, 0x0010 },
   { s_cm163, s_cr163, 2, 5, 0x0010 },
   { s_cm164, s_cr164, 2, 6, 0x0020 },
   { s_cm165, s_cr165, 2, 4, 0x0000 },
   { s_cm166, s_cr166, 2, 2, 0x0000 },
   { s_cm167, s_cr167, 2, 2, 0x0000 },
   { s_cm168, s_cr168, 2, 1, 0x0000 },
   { s_cm169, s_cr169, 2, 1, 0x0000 },
   { s_cm170, s_cr170, 2, 0, 0x0000 },
   { s_cm171, s_cr171, 2, 0, 0x0000 },
   { s_cm172, s_cr172, 2, 0, 0x0000 },
   { s_cm173, s_cr173, 2, 0, 0x0000 },
   { s_cm174, NULL   , 1, 0, 0x0000 },
   { s_cm175, s_cr175, 2, 1, 0x0000 },
   { s_cm176, s_cr176, 2, 0, 0x0000 },
   { s_cm177, s_cr177, 2, 1, 0x0000 },
   { s_cm178, s_cr178, 2, 0, 0x0000 },
   { s_cm179, s_cr179, 2, 0, 0x0000 },
   { s_cm180, s_cr180, 2, 1, 0x0000 },
   { s_cm181, s_cr181, 2, 1, 0x0000 },
   { s_cm182, s_cr182, 2, 1, 0x0000 },
   { s_cm183, s_cr183, 2, 1, 0x0000 },
   { s_cm184, s_cr184, 2, 1, 0x0000 },
   { s_cm185, s_cr185, 2, 1, 0x0000 },
   { s_cm186, s_cr186, 2, 1, 0x0000 },
   { s_cm187, s_cr187, 2, 1, 0x0000 },
   { s_cm188, s_cr188, 2, 1, 0x0000 },
   { s_cm189, s_cr189, 2, 1, 0x0000 },
   { s_cm190, s_cr190, 2, 1, 0x0000 },
   { s_cm191, s_cr191, 2, 1, 0x0000 },
   { s_cm192, s_cr192, 2, 0, 0x0000 },
   { s_cm193, s_cr193, 2, 1, 0x0000 },
   { s_cm194, s_cr194, 2, 0, 0x0000 },
   { s_cm195, s_cr195, 2, 0, 0x0000 },
   { s_cm196, s_cr196, 2, 0, 0x0000 },
   { s_cm197, s_cr197, 2, 0, 0x0000 },
   { s_cm198, s_cr198, 2, 1, 0x0000 },
   { s_cm199, s_cr199, 2, 1, 0x0000 },
   { s_cm200, s_cr200, 2, 2, 0x0000 },
   { s_cm201, s_cr201, 2, 0, 0x0000 },
   { s_cm202, s_cr202, 2, 1, 0x0000 },
   { s_cm203, s_cr203, 2, 0, 0x0000 },
   { s_cm204, s_cr204, 2, 1, 0x0000 },
   { s_cm205, s_cr205, 2, 0, 0x0000 },
   { s_cm206, s_cr206, 2, 1, 0x0000 },
   { s_cm207, s_cr207, 2, 1, 0x0000 },
   { s_cm208, s_cr208, 2, 2, 0x0000 },
   { s_cm209, s_cr209, 2, 1, 0x0000 },
   { s_cm210, s_cr210, 2, 2, 0x0000 },
   { s_cm211, s_cr211, 2, 2, 0x0000 },
   { s_cm212, s_cr212, 2, 2, 0x0000 },
   { s_cm213, s_cr213, 2, 1, 0x0000 },
   { s_cm214, s_cr214, 2, 0, 0x0000 },
   { s_cm215, s_cr215, 2, 2, 0x0000 },
   { s_cm216, s_cr216, 2, 3, 0x0006 },
   { s_cm217, s_cr217, 2, 2, 0x0002 },
   { s_cm218, s_cr218, 2, 2, 0x0002 },
   { s_cm219, s_cr219, 2, 1, 0x0001 },
   { s_cm220, s_cr220, 2, 1, 0x0000 },
   { s_cm221, s_cr221, 2, 1, 0x0000 },
   { s_cm222, s_cr222, 2, 0, 0x0000 },
   { s_cm223, s_cr223, 2, 0, 0x0000 },
   { s_cm224, s_cr224, 2, 0, 0x0000 },
   { s_cm225, s_cr225, 2, 1, 0x0000 },
   { s_cm226, s_cr226, 2, 1, 0x0000 },
   { s_cm227, s_cr227, 2, 1, 0x0000 },
   { s_cm228, s_cr228, 2, 2, 0x0000 },
   { s_cm229, s_cr229, 2, 0, 0x0000 },
   { s_cm230, s_cr230, 2, 1, 0x0000 },
   { s_cm231, s_cr231, 2, 1, 0x0000 },
   { s_cm232, s_cr232, 2, 2, 0x0000 },
   { s_cm233, s_cr233, 2, 0, 0x0000 },
   { s_cm234, s_cr234, 2, 1, 0x0000 },
   { s_cm235, s_cr235, 2, 1, 0x0000 },
   { s_cm236, s_cr236, 2, 0, 0x0000 },
   { s_cm237, s_cr237, 2, 1, 0x0000 },
   { s_cm238, s_cr238, 2, 1, 0x0000 },
   { s_cm239, s_cr239, 2, 1, 0x0000 },
   { s_cm240, s_cr240, 2, 1, 0x0000 },
   { s_cm241, s_cr241, 2, 1, 0x0000 },
   { s_cm242, s_cr242, 2, 1, 0x0000 },
   { s_cm243, s_cr243, 2, 1, 0x0000 },
   { s_cm244, s_cr244, 2, 1, 0x0000 },
   { s_cm245, s_cr245, 2, 1, 0x0000 },
   { s_cm246, s_cr246, 2, 1, 0x0000 },
   { s_cm247, s_cr247, 2, 1, 0x0000 },
   { s_cm248, s_cr248, 2, 1, 0x0000 },
   { s_cm249, s_cr249, 2, 1, 0x0000 },
   { s_cm250, s_cr250, 2, 1, 0x0000 },
   { s_cm251, s_cr251, 2, 1, 0x0000 },
   { s_cm252, s_cr252, 2, 1, 0x0000 },
   { s_cm253, s_cr253, 2, 1, 0x0000 },
   { s_cm254, s_cr254, 2, 1, 0x0000 },
   { s_cm255, s_cr255, 2, 1, 0x0000 },
   { s_cm256, s_cr256, 2, 1, 0x0000 },
   { s_cm257, s_cr257, 2, 1, 0x0000 },
   { s_cm258, s_cr258, 2, 1, 0x0000 },
   { s_cm259, s_cr259, 2, 1, 0x0000 },
   { s_cm260, s_cr260, 2, 1, 0x0000 },
   { s_cm261, s_cr261, 2, 1, 0x0000 },
   { s_cm262, s_cr262, 2, 1, 0x0000 },
   { s_cm263, s_cr263, 2, 1, 0x0000 },
   { s_cm264, s_cr264, 2, 1, 0x0000 },
   { s_cm265, s_cr265, 2, 1, 0x0000 },
   { s_cm266, s_cr266, 2, 0, 0x0000 },
   { s_cm267, s_cr267, 2, 1, 0x0000 },
   { s_cm268, s_cr268, 2, 0, 0x0000 },
   { s_cm269, s_cr269, 2, 1, 0x0000 },
   { s_cm270, s_cr270, 2, 0, 0x0000 },
   { s_cm271, s_cr271, 2, 1, 0x0000 },
   { s_cm272, s_cr272, 2, 1, 0x0000 },
   { s_cm273, s_cr273, 2, 1, 0x0000 },
   { s_cm274, s_cr274, 2, 1, 0x0000 },
   { s_cm275, s_cr275, 2, 1, 0x0000 },
   { s_cm276, s_cr276, 2, 1, 0x0000 },
   { s_cm277, s_cr277, 2, 0, 0x0000 },
   { s_cm278, s_cr278, 2, 0, 0x0000 },
   { s_cm279, s_cr279, 2, 0, 0x0000 },
   { s_cm280, s_cr280, 2, 0, 0x0000 },
   { s_cm281, s_cr281, 2, 0, 0x0000 },
   { s_cm282, s_cr282, 2, 0, 0x0000 },
   { s_cm283, s_cr283, 2, 0, 0x0000 },
   { s_cm284, s_cr284, 2, 0, 0x0000 },
   { s_cm285, s_cr285, 2, 0, 0x0000 },
   { s_cm286, s_cr286, 2, 1, 0x0000 },
   { s_cm287, s_cr287, 2, 2, 0x0000 },
   { s_cm288, s_cr288, 2, 1, 0x0000 },
   { s_cm289, s_cr289, 2, 1, 0x0000 },
   { s_cm290, NULL   , 2, 0, 0x0000 },
   { s_cm291, NULL   , 2, 0, 0x0000 },
   { s_cm292, NULL   , 2, 0, 0x0000 },
   { s_cm293, NULL   , 2, 0, 0x0000 },
   { s_cm294, NULL   , 2, 0, 0x0000 },
   { s_cm295, NULL   , 2, 0, 0x0000 },
   { s_cm296, NULL   , 2, 0, 0x0000 },
   { s_cm297, NULL   , 2, 0, 0x0000 },
   { s_cm298, s_cr298, 2, 3, 0x0002 },
   { s_cm299, s_cr299, 2, 2, 0x0002 },
   { s_cm300, s_cr300, 2, 2, 0x0002 },
   { s_cm301, s_cr301, 2, 0, 0x0000 },
   { s_cm302, s_cr302, 2, 0, 0x0000 },
   { s_cm303, s_cr303, 2, 0, 0x0000 },
   { s_cm304, s_cr304, 2, 0, 0x0000 },
   { s_cm305, s_cr305, 2, 0, 0x0000 },
   { s_cm306, s_cr306, 2, 0, 0x0000 },
   { s_cm307, s_cr307, 2, 0, 0x0000 },
   { s_cm308, s_cr308, 2, 0, 0x0000 },
   { s_cm309, s_cr309, 2, 1, 0x0000 },
   { s_cm310, s_cr310, 2, 3, 0x0000 }
};


void hb_pp_setStdRules( PHB_PP_STATE pState )
{
   hb_pp_initRules( &pState->pDefinitions, &pState->iDefinitions, s_def, 85 );
   hb_pp_initRules( &pState->pTranslations, &pState->iTranslations, s_trs, 1 );
   hb_pp_initRules( &pState->pCommands, &pState->iCommands, s_cmd, 310 );
}
