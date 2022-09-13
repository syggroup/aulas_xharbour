@echo off

set HB_INSTALL=C:\aulas_xharbour\Devel\xharbour_bcc72
set SQLRDD_INSTALL=C:\aulas_xharbour\Devel\xharbour_bcc72\contrib\sqlrdd

set INCLUDE_PATH=%HB_INSTALL%\include;%SQLRDD_INSTALL%\include
set LIB_PATH=%HB_INSTALL%\lib\bc72;%HB_INSTALL%\lib;%SQLRDD_INSTALL%\lib\bc72%XHB_VERSION%;%SQLRDD_INSTALL%\lib\bc72
set HB_LIBLIST= common.lib debug.lib vm.lib rtl.lib pcrepos.lib gtwin.lib lang.lib rdd.lib macro.lib pp.lib dbffpt.lib dbfntx.lib dbfcdx.lib hsx.lib hbsix.lib ct.lib tip.lib sql.lib oci.lib fbclient_bc.lib libpq.lib odbccp32.lib libmysql.lib odbc32.lib

%HB_INSTALL%\bin\xharbour_bcc72 %1.prg -n -q0 -gc -i%INCLUDE_PATH% -p

bcc32 -O2 -d -I%INCLUDE_PATH% -L%LIB_PATH% %1.c %HB_LIBLIST%

