cd lib
del hwgui_xhb72.lib 
cd..
d:\devel\xharbour_bcc7\bin\xbuild hwgui.lib.xbp -NoErr
copy hwgui.lib lib\hwgui_xhb72.lib 
del hwgui.lib
del *.log
del xbuild.windows.ini