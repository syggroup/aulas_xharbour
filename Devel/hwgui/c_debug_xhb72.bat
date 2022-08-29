cd lib
del hwguidebug_xhb72.lib
cd..
d:\devel\xharbour_bcc7\bin\xbuild hwguiDebug.lib.xbp -NoErr
copy hwguidebug.lib lib\hwguidebug_xhb72.lib 
del hwguidebug.lib
del *.log
del xbuild.windows.ini