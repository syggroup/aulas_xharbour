cd lib
del hwgui_xhb72.lib 
cd..
c:\aulas_xharbour\devel\xharbour_bcc72\bin\xbuild hwgui.lib.xbp -NoErr
copy hwgui.lib lib\hwgui_xhb72.lib 
del hwgui.lib
del *.log
del xbuild.windows.ini