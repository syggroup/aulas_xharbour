cd lib
del hbactivex_xhb72.lib
cd..
C:\aulas_xharbour\Devel\xharbour_bcc72\bin\xbuild hbactivex.lib.xbp -NoErr
copy hbactivex.lib lib\hbactivex_xhb72.lib
del hbactivex.lib
del *.log
del xbuild.windows.ini