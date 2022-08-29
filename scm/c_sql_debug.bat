if exist scm_sql_debug.exe     del scm_sql_debug.exe
C:\aulas_xharbour\devel\xharbour_bcc72\bin\xbuild scm_sql_debug.exe.xbp -Noerr
if exist scm_sql_debug.exe  start C:\aulas_xharbour\devel\xharbour_bcc72\bin\debug.exe scm_sql_debug.exe