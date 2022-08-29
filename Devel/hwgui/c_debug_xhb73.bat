cd lib
del hwguidebug_xhb73.lib
cd..
d:\devel\xharbour_bcc73\bin\xbuild hwguiDebug.lib.xbp -NoErr
copy hwguidebug.lib lib\hwguidebug_xhb73.lib 
del hwguidebug.lib
del *.log
del xbuild.windows.ini