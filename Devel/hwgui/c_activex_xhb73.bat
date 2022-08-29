cd lib
del hbactivex_xhb73.lib
cd..
d:\devel\xharbour_bcc73\bin\xbuild hbactivex.lib.xbp -NoErr
copy hbactivex.lib lib\hbactivex_xhb73.lib
del hbactivex.lib
del *.log
del xbuild.windows.ini