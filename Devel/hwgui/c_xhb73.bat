cd lib
del hwgui_xhb73.lib 
cd..
d:\devel\xharbour_bcc73\bin\xbuild hwgui.lib.xbp -NoErr
copy hwgui.lib lib\hwgui_xhb73.lib 
del hwgui.lib
del *.log
del xbuild.windows.ini