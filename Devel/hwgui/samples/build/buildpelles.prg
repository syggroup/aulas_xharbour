/*
 *$Id: buildpelles.prg 1615 2011-02-18 13:53:35Z mlacecilia $
 *
 * HWGUI - Harbour Win32 GUI library 
 * 
 * File to Build APP using Pelles C Compiler
 * Copyright 2004 Sandro R. R. Freire <sandrorrfreire@yahoo.com.br>
 * www - http://www.lumainformatica.com.br
*/

#include "windows.ch"
#include "guilib.ch"
#DEFINE  ID_EXENAME     10001
#DEFINE  ID_LIBFOLDER   10002
#DEFINE  ID_INCFOLDER   10003
#DEFINE  ID_PRGFLAG     10004
#DEFINE  ID_CFLAG       10005
#DEFINE  ID_PRGMAIN     10006
FUNCTION Main
Local oFont
Local aBrowse1, aBrowse2, aBrowse3, aBrowse4
LOCAL oPasta  := DiskName()+":\"+CurDir()+"\"
Local vGt1:=Space(80)
Local vGt2:=Space(80)
Local vGt3:=Space(80)
Local vGt4:=Space(80)
Local vGt5:=Space(80)
Local vGt6:=Space(80)
Local aFiles1:={""}, aFiles2:={""}, aFiles3:={""}, aFiles4:={""}
Private oDirec:=DiskName()+":\"+CurDir()+"\"
If !File(oDirec+"BuildPelles.Ini")
  Hwg_WriteIni( 'Config', 'Dir_HwGUI', "C:\HwGUI", oDirec+"BuildPelles.Ini" )
  Hwg_WriteIni( 'Config', 'Dir_HARBOUR', "C:\xHARBOUR", oDirec+"BuildPelles.Ini" )
  Hwg_WriteIni( 'Config', 'Dir_PELLES', "C:\POCC", oDirec+"BuildPelles.Ini" )
EndIf
 
Private lSaved:=.F.
Private oBrowse1, oBrowse2, oBrowse3
Private oDlg
PRIVATE oButton1, oExeName, oLabel1, oLibFolder, oButton4, oLabel2, oIncFolder, oLabel3, oButton3, oPrgFlag, oLabel4, oCFlag, oLabel5, oButton2, oMainPrg, oLabel6, oTab

   PREPARE FONT oFont NAME "MS Sans Serif" WIDTH 0 HEIGHT -12
   
   INIT DIALOG oDlg CLIPPER NOEXIT TITLE "HwGUI Build For Pelles C Compiler" ;
        AT 213,195 SIZE 513,265  font oFont

   @ 14,16 TAB oTAB ITEMS {} SIZE 391,242

   BEGIN PAGE "Config" Of oTAB
      @  20,44 SAY oLabel1 CAPTION "Exe Name" SIZE 80,22  
      @ 136,44 GET oExeName VAR vGt1 ID ID_EXENAME  SIZE 206,24  

      @  20,74 SAY oLabel2 CAPTION "Lib Folder" SIZE 80,22  
      @ 136,74 GET oLibFolder  VAR vGt2 ID ID_LIBFOLDER SIZE 234,24  

      @  20,104 SAY oLabel3 CAPTION "Include Folder" SIZE 105,22  
      @ 136,104 GET oIncFolder VAR vGt3 ID ID_INCFOLDER   SIZE 234,24  

      @  20,134 SAY oLabel4 CAPTION "PRG Flags" SIZE 80,22  
      @ 136,134 GET oPrgFlag VAR vGt4 ID ID_PRGFLAG  SIZE 230,24  

      @  20,164 SAY oLabel5 CAPTION "C Flags" SIZE 80,22  
      @ 136,164 GET oCFlag VAR vGt5  ID ID_CFLAG SIZE 230,24  
 
      @  20,194 SAY oLabel6 CAPTION "Main PRG" SIZE 80,22  
      @ 136,194 GET oMainPrg VAR vGt6 ID ID_PRGMAIN  SIZE 206,24  
      @ 347,194 OWNERBUTTON    SIZE 24,24   ;
          ON CLICK {||searchFileName("xBase Files *.prg ", oMainPrg, "*.prg")};//       FLAT;
          TEXT "..." ;//BITMAP "SEARCH" FROM RESOURCE TRANSPARENT COORDINATES 0,0,0,0 ;
          TOOLTIP "Search main file" 

   END PAGE of oTAB
   BEGIN PAGE "Prg (Files)" of oTAB
      @ 21,29 BROWSE oBrowse1 ARRAY of oTAB ON CLICK {||SearchFile(oBrowse1,"*.prg")};
 	            STYLE WS_VSCROLL + WS_HSCROLL   SIZE 341,170  
      createarlist(oBrowse1,aFiles1)
      obrowse1:acolumns[1]:heading := "File Names"
      obrowse1:acolumns[1]:length := 50
      oBrowse1:bcolorSel := VColor( "800080" )
      oBrowse1:ofont := HFont():Add( 'Arial',0,-12 )
      @ 10, 205 BUTTON "Add"     SIZE 60,25  on click {||SearchFile(oBrowse1, "*.prg")}  
      @ 70, 205 BUTTON "Delete"  SIZE 60,25  on click {||Adel(oBrowse1:aArray, oBrowse1:nCurrent),oBrowse1:Refresh()}

   END PAGE of oTAB
   BEGIN PAGE "C (Files)" of oTAB
      @ 21,29 BROWSE oBrowse2 ARRAY of oTAB ON CLICK {||SearchFile(oBrowse2, "*.c")};
 	            STYLE WS_VSCROLL + WS_HSCROLL   SIZE 341,170  
      createarlist(oBrowse2,aFiles2)
      obrowse2:acolumns[1]:heading := "File Names"
      obrowse2:acolumns[1]:length := 50
      oBrowse2:bcolorSel := VColor( "800080" )
      oBrowse2:ofont := HFont():Add( 'Arial',0,-12 )
      @ 10, 205 BUTTON "Add"     SIZE 60,25  on click {||SearchFile(oBrowse2, "*.c")}  
      @ 70, 205 BUTTON "Delete"  SIZE 60,25  on click {||Adel(oBrowse1:aArray, oBrowse2:nCurrent),oBrowse2:Refresh()}
   END PAGE of oTAB
   BEGIN PAGE "Lib (Files)" of oTAB
      @ 21,29 BROWSE oBrowse3 ARRAY of oTAB ON CLICK {||SearchFile(oBrowse3, "*.lib")};
 	            STYLE WS_VSCROLL + WS_HSCROLL   SIZE 341,170  
      createarlist(oBrowse3,aFiles3)
      obrowse3:acolumns[1]:heading := "File Names"
      obrowse3:acolumns[1]:length := 50
      oBrowse3:bcolorSel := VColor( "800080" )
      oBrowse3:ofont := HFont():Add( 'Arial',0,-12 )
      @ 10, 205 BUTTON "Add"     SIZE 60,25  on click {||SearchFile(oBrowse3, "*.lib")}  
      @ 70, 205 BUTTON "Delete"  SIZE 60,25  on click {||Adel(oBrowse3:aArray, oBrowse3:nCurrent),oBrowse3:Refresh()}
   END PAGE of oTAB
   BEGIN PAGE "Resource (Files)" of oTAB
      @ 21,29 BROWSE oBrowse4 ARRAY of oTAB ON CLICK {||SearchFile(oBrowse3, "*.rc")};
 	            STYLE WS_VSCROLL + WS_HSCROLL   SIZE 341,170  
      createarlist(oBrowse4,aFiles4)
      obrowse4:acolumns[1]:heading := "File Names"
      obrowse4:acolumns[1]:length := 50
      oBrowse4:bcolorSel := VColor( "800080" )
      oBrowse4:ofont := HFont():Add( 'Arial',0,-12 )
      @ 10, 205 BUTTON "Add"     SIZE 60,25  on click {||SearchFile(oBrowse4, "*.rc")}  
      @ 70, 205 BUTTON "Delete"  SIZE 60,25  on click {||Adel(oBrowse4:aArray, oBrowse4:nCurrent),oBrowse4:Refresh()}
   END PAGE of oTAB
   
   @ 419, 20 BUTTON oButton1 CAPTION "Build" on Click {||BuildApp()} SIZE 78,52  
   @ 419, 80 BUTTON oButton2 CAPTION "Exit" on Click {||EndDialog()}  SIZE 78,52  
   @ 419,140 BUTTON oButton3 CAPTION "Open" on Click {||ReadBuildFile()}  SIZE 78,52  
   @ 419,200 BUTTON oButton4 CAPTION "Save" on Click {||SaveBuildFile()}   SIZE 78,52  

   ACTIVATE DIALOG oDlg
RETURN

Static Function SearchFile(oBrow, oFile)
Local oTotReg:={}, i
Local aSelect:=SelectMultipleFiles("xBase Files ("+oFile+")", oFile ) 
if len(aSelect) ==0
   return Nil
endif
if LEN(oBrow:aArray) == 1 .and. obrow:aArray[1]=="" 
   obrow:aArray := {}
endif
For i:=1 to Len(oBrow:aArray)
  AADD(oTotReg, oBrow:aArray[i])  
Next
For i:=1 to Len(aSelect)
  AADD(oTotReg, aSelect[i])  
Next
obrow:aArray := oTotReg
obrow:refresh()
Return Nil

Static Function SearchFileName(nName, oGet, oFile)
Local oTextAnt:=oGet:GetText()
Local fFile:=SelectFile(nName+" ("+oFile+")", oFile,,,.T. ) 
If !Empty(oTextAnt)
   fFile:=oTextAnt //
endif   
oGet:SetText(fFile)
oGet:Refresh()
Return Nil


Function ReadBuildFile()
Local oLibFiles, oBr1:={}, oBr2:={}, oBr3:={}, oBr4:={}, oSel1, oSel2, oSel3, i, oSel4
Local aPal:=""
Local oFolderFile:=SelectFile("HwGUI File Build (*.bld)", "*.bld" ) 
if empty(oFolderFile); Return Nil; Endif
   
oExeName:SetText( Hwg_GetIni( 'Config', 'ExeName' , , oFolderFile ))
oLibFolder:SetText(Hwg_GetIni( 'Config', 'LibFolder' , , oFolderFile ))
oIncFolder:SetText(Hwg_GetIni( 'Config', 'IncludeFolder' , , oFolderFile ))
oPrgFlag:SetText(Hwg_GetIni( 'Config', 'PrgFlags' , , oFolderFile ))
oCFlag:SetText(Hwg_GetIni( 'Config', 'CFlags' , , oFolderFile ))
oMainPrg:SetText(Hwg_GetIni( 'Config', 'PrgMain' , , oFolderFile ))

For i:=1 to 300
    oSel1:=Hwg_GetIni( 'FilesPRG', Alltrim(Str(i)) , , oFolderFile )
    if !empty(oSel1) //.or. oSel1#Nil
        AADD(oBr1, oSel1)
    EndIf
Next
    
  
For i:=1 to 300
    oSel2:=Hwg_GetIni( 'FilesC', Alltrim(Str(i)) , , oFolderFile )
    if !empty(oSel2) //.or. oSel2#Nil
        AADD(oBr2, oSel2)
    EndIf
Next

For i:=1 to 300
    oSel3:=Hwg_GetIni( 'FilesLIB', Alltrim(Str(i)) , , oFolderFile )
    if !empty(oSel3) //.or. oSel3#Nil
        AADD(oBr3, oSel3)
    EndIf
Next

For i:=1 to 300
    oSel4:=Hwg_GetIni( 'FilesRES', Alltrim(Str(i)) , , oFolderFile )
    if !empty(oSel4) //.or. oSel4#Nil
        AADD(oBr4, oSel4)
    EndIf
Next

oBrowse1:aArray:=oBr1  
oBrowse2:aArray:=oBr2  
oBrowse3:aArray:=oBr3  
oBrowse4:aArray:=oBr4  
oBrowse1:Refresh()
oBrowse2:Refresh()
oBrowse3:Refresh()
oBrowse4:Refresh()

Return Nil

Function SaveBuildFile()
Local oLibFiles, i, oNome, g
Local oFolderFile:=SaveFile("*.bld", "HwGUI File Build (*.bld)", "*.bld" ) 
if empty(oFolderFile); Return Nil; Endif
if file(oFolderFile)
   If(MsgYesNo("File "+oFolderFile+" EXIT ..Replace?"))
     Erase( oFolderFile )
   Else
     MsgInfo("No file SAVED.")
     Return Nil
   EndIf
EndIf     
Hwg_WriteIni( 'Config', 'ExeName'       ,oExeName:GetText(), oFolderFile )
Hwg_WriteIni( 'Config', 'LibFolder'     ,oLibFolder:GetText(), oFolderFile )
Hwg_WriteIni( 'Config', 'IncludeFolder' ,oIncFolder:GetText(), oFolderFile )
Hwg_WriteIni( 'Config', 'PrgFlags'      ,oPrgFlag:GetText(), oFolderFile )
Hwg_WriteIni( 'Config', 'CFlags'        ,oCFlag:GetText(), oFolderFile )
Hwg_WriteIni( 'Config', 'PrgMain'       ,oMainPrg:GetText(), oFolderFile )
oNome:=""

if Len(oBrowse1:aArray)>=1
   for i:=1 to Len(oBrowse1:aArray)

      if !empty(oBrowse1:aArray[i])
 
         Hwg_WriteIni( 'FilesPRG', Alltrim(Str(i)),oBrowse1:aArray[i], oFolderFile )
   
      EndIf    
      
    Next    

endif


if Len(oBrowse2:aArray)>=1
   for i:=1 to Len(oBrowse2:aArray)
      if !empty(oBrowse2:aArray[i])
         Hwg_WriteIni( 'FilesC', Alltrim(Str(i)),oBrowse2:aArray[i], oFolderFile )
     endif    
   Next     
endif

if Len(oBrowse3:aArray)>=1
   for i:=1 to Len(oBrowse3:aArray)
      if !empty(oBrowse3:aArray[i])
         Hwg_WriteIni( 'FilesLIB', Alltrim(Str(i)),oBrowse3:aArray[i], oFolderFile )
      endif   
   Next     
endif   

if Len(oBrowse4:aArray)>=1
   for i:=1 to Len(oBrowse4:aArray)
      if !empty(oBrowse4:aArray[i])
         Hwg_WriteIni( 'FilesRES', Alltrim(Str(i)),oBrowse4:aArray[i], oFolderFile )
     endif   
   Next     
endif   

Msginfo("File "+oFolderFile+" saved","HwGUI Build")
Return Nil

Function BuildApp()
If MsgYesNo("Yes Compile to BAT, No compile to PoMake")
   BuildBat()
Else
   BuildPoMake()
EndIf   

Function BuildBat()
Local voExeName, voLibFolder, voIncFolder, voPrgFlag, voCFlag, voPrgMain, voPrgFiles, voCFiles,voResFiles
Local oLibFiles, CRF:=CHR(13)+CHR(10), oName, oInc, lName, gDir
Local oArq:=fCreate("Hwg_Build.bat"),i, vHwGUI, vHarbour, vPelles
If File(oDirec+"BuildPelles.Ini")
   vHwGUI:=Hwg_GetIni( 'Config', 'DIR_HwGUI' , , oDirec+"BuildPelles.Ini" )
   vHarbour:=Hwg_GetIni( 'Config', 'DIR_HARBOUR' , , oDirec+"BuildPelles.Ini")
   vPelles:=Hwg_GetIni( 'Config', 'DIR_PELLES' , , oDirec+"BuildPelles.Ini" )
Else 
   vHwGUI:="C:\HWGUI"
   vHarbour:="C:\Harbour"
   vPelles:="C:\Pocc"   
EndIf
voExeName  :=oExeName:GetText() 
voLibFolder:=oLibFolder:GetText() 
voIncFolder:=oIncFolder:GetText()
voPrgFlag  :=oPrgFlag:GetText() 
voCFlag    :=oCFlag:GetText() 
voPrgMain  :=oMainPrg:GetText() 

voPrgFiles :=oBrowse1:aArray
voCFiles   :=oBrowse2:aArray
voLibFiles :=oBrowse3:aArray
voResFiles :=oBrowse4:aArray

fwrite(oArq,"@echo off"+CRF)

oName:=Substr(voPrgMain,1,Len(voPrgMain)-4)
lName:=""
for i:=1 to Len(oName)
   if Substr(oName, -i, 1)="\"
      Exit
   Endif
   lName+=Substr(oName, -i, 1)
Next
oName:=""
for i:=1 to Len(lName)         
   oName+=Substr(lName, -i, 1)
Next   
fwrite(oArq,"ECHO "+oName+".obj > make.tmp "+CRF)

if Len(voPrgFiles)>0 

   for i:=1 to Len(voPrgFiles)
   
      if !empty( voPrgFiles[i] )
 
         oName:=Substr(voPrgFiles[i],1,Len(voPrgFiles[i])-4)
         lName:=""
         for g:=1 to Len(oName)
            if Substr(oName, -g, 1)="\"
               Exit
            Endif
            lName+=Substr(oName, -g, 1)
         Next
         oName:=""
         for g:=1 to Len(lName)         
            oName+=Substr(lName, -g, 1)
         Next   

         fwrite(oArq,"ECHO "+oName+".obj >> make.tmp "+CRF)
         
      Endif   
      
   Next
Endif
   
//fwrite(oArq,"ECHO "+voExeName+".obj > make.tmp "+CRF)
fwrite(oArq,"echo "+vHarbour+"\lib\rtl%HB_MT%.lib  >> make.tmp"+CRF)
fwrite(oArq,"echo "+vHarbour+"\lib\vm%HB_MT%.lib  >> make.tmp"+CRF)
fwrite(oArq,"echo "+vHarbour+"\lib\gtwin.lib  >> make.tmp"+CRF)
fwrite(oArq,"echo "+vHarbour+"\lib\lang.lib  >> make.tmp"+CRF)
fwrite(oArq,"echo "+vHarbour+"\lib\codepage.lib  >> make.tmp"+CRF)
fwrite(oArq,"echo "+vHarbour+"\lib\macro%HB_MT%.lib  >> make.tmp"+CRF)
fwrite(oArq,"echo "+vHarbour+"\lib\rdd%HB_MT%.lib  >> make.tmp"+CRF)
fwrite(oArq,"echo "+vHarbour+"\lib\dbfntx%HB_MT%.lib  >> make.tmp"+CRF)
fwrite(oArq,"echo "+vHarbour+"\lib\dbfcdx%HB_MT%.lib  >> make.tmp"+CRF)
fwrite(oArq,"echo "+vHarbour+"\lib\dbfdbt%HB_MT%.lib  >> make.tmp"+CRF)
fwrite(oArq,"echo "+vHarbour+"\lib\common.lib  >> make.tmp"+CRF)
fwrite(oArq,"echo "+vHarbour+"\lib\debug.lib  >> make.tmp"+CRF)
fwrite(oArq,"echo "+vHarbour+"\lib\pp.lib  >> make.tmp"+CRF)
fwrite(oArq,"ECHO "+vHarbour+"\LIB\optcon.lib>> make.tmp"+CRF)
fwrite(oArq,"ECHO "+vHarbour+"\LIB\optgui.lib >> make.tmp"+CRF)
fwrite(oArq,"ECHO "+vHarbour+"\LIB\nulsys.lib  >> make.tmp"+CRF)
fwrite(oArq,"ECHO "+vHarbour+"\LIB\hbodbc.lib   >> make.tmp"+CRF)
fwrite(oArq,"ECHO "+vHarbour+"\LIB\samples.lib   >> make.tmp"+CRF)

fwrite(oArq,"ECHO "+vHwGUI+"\LIB\hwgui.lib >> make.tmp"+CRF)
fwrite(oArq,"ECHO "+vHwGUI+"\LIB\procmisc.lib >> make.tmp"+CRF)
fwrite(oArq,"ECHO "+vHwGUI+"\LIB\hbxml.lib >> make.tmp"+CRF)
fwrite(oArq,"ECHO "+vHwGUI+"\LIB\hwg_qhtm.lib >> make.tmp"+CRF)

fwrite(oArq,"ECHO "+vPelles+"\LIB\kernel32.lib >> make.tmp"+CRF)
fwrite(oArq,"ECHO "+vPelles+"\LIB\comctl32.lib >> make.tmp"+CRF)
fwrite(oArq,"ECHO "+vPelles+"\LIB\comdlg32.lib >> make.tmp"+CRF)
fwrite(oArq,"ECHO "+vPelles+"\LIB\delayimp.lib >> make.tmp"+CRF)
fwrite(oArq,"ECHO "+vPelles+"\LIB\ole32.lib >> make.tmp"+CRF)
fwrite(oArq,"ECHO "+vPelles+"\LIB\shell32.lib >> make.tmp"+CRF)
fwrite(oArq,"ECHO "+vPelles+"\LIB\oleaut32.lib >> make.tmp"+CRF)
fwrite(oArq,"ECHO "+vPelles+"\LIB\user32.lib >> make.tmp"+CRF)
fwrite(oArq,"ECHO "+vPelles+"\LIB\gdi32.lib >> make.tmp"+CRF)
fwrite(oArq,"ECHO "+vPelles+"\LIB\winspool.lib >> make.tmp"+CRF)
fwrite(oArq,"ECHO "+vPelles+"\LIB\uuid.lib >> make.tmp"+CRF)
fwrite(oArq,"ECHO "+vPelles+"\LIB\portio.lib >> make.tmp"+CRF)
fwrite(oArq,"IF EXIST "+voExeName+".res echo "+voExeName+".res  >> make.tmp"+CRF)

oName:=Substr(voPrgMain,1,Len(voPrgMain)-4) 

fwrite(oArq,vHarbour+"\BIN\HARBOUR "+voPrgMain+;
" -o"+oName+;
" -i"+vPelles+"\INCLUDE;"+vHarbour+"\INCLUDE;"+vHwGUI+"\INCLUDE"+iif(!empty(voIncFolder),";","")+voIncFolder+" "+voPrgFlag+" -n -q0 -es2 -gc0"+CRF)


if Len(voPrgFiles)>0 
for i:=1 to Len(voPrgFiles)
    if !empty( voPrgFiles[i] )
 
       oName:=Substr(voPrgFiles[i],1,Len(voPrgFiles[i])-4) 
       fwrite(oArq,vHarbour+"\BIN\HARBOUR "+voPrgFiles[i]+;
       " -o"+oName+;
       " -i"+vPelles+"\INCLUDE;"+vHarbour+"\INCLUDE;"+vHwGUI+"\INCLUDE"+iif(!empty(voIncFolder),";","")+voIncFolder+" "+voPrgFlag+" -n -q0 -es2 -gc0"+CRF)
   ENDIF    
Next
endif

oName:=Substr(voPrgMain,1,Len(voPrgMain)-4)
fwrite(oArq,vPelles+'\bin\pocc '+oName+'.c '+voCFlag+' /Ze /D"NEED_DUMMY_RETURN" /D"__XCC__" /I"INCLUDE" /I"'+vHarbour+'\INCLUDE" /I"'+vPelles+'\INCLUDE" /I"'+vPelles+'\INCLUDE\WIN" /I"'+vPelles+'\INCLUDE\MSVC" /D"HB_STATIC_STARTUP" /c'+CRF)


if Len(voPrgFiles)>0 
for i:=1 to Len(voPrgFiles)
   if !empty( voPrgFiles[i] )
      oName:=Substr(voPrgFiles[i],1,Len(voPrgFiles[i])-4) 
      fwrite(oArq,vPelles+'\bin\pocc '+oName+'.c '+voCFlag+' /Ze /D"NEED_DUMMY_RETURN" /D"__XCC__" /I"INCLUDE" /I"'+vHarbour+'\INCLUDE" /I"'+vPelles+'\INCLUDE" /I"'+vPelles+'\INCLUDE\WIN" /I"'+vPelles+'\INCLUDE\MSVC" /D"HB_STATIC_STARTUP" /c'+CRF)
  endif  
next
endif 

if Len(voCFiles)>0 
oInc:=""
for i:=1 to Len(voCFiles)
    if !empty(voCFiles[i])
       if !empty(oIncFolder)
          oInc:='/I"'+voIncFolder+'"'
       endif   
       fwrite(oArq,vPelles+'\bin\pocc '+voCFiles[i]+' /Ze /D"NEED_DUMMY_RETURN" /D"__XCC__" /I"INCLUDE" /I""+vHarbour+"\INCLUDE" /I""+vPelles+"\INCLUDE" /I""+vPelles+"\INCLUDE\WIN" /I"'+vPelles+'\INCLUDE\MSVC" '+oInc+' /D"HB_STATIC_STARTUP" /c'+CRF)
    endif   
Next
Endif

if Len(voResFiles)>0 
oInc:=""
for i:=1 to Len(voResFiles)
  if !Empty(voResFiles[i])
     fwrite(oArq,vPelles+'\BIN\porc -r '+voResFiles[i]+' -foobj\'+voExeName+CRF)
  EndIf   
Next
EndIf 

fwrite(oArq,vPelles+'\bin\POLINK /LIBPATH:'+vPelles+'\lib /OUT:'+voExeName+'.EXE /MACHINE:IX86 /OPT:WIN98 /SUBSYSTEM:WINDOWS /FORCE:MULTIPLE @make.tmp >error.log'+CRF)
fwrite(oArq,'DEL make.tmp'+CRF)

oName:=Substr(voPrgMain,1,Len(voPrgMain)-4) 
/*
fwrite(oArq,'Del '+oName+'.c '+CRF)
fwrite(oArq,'Del '+oName+'.map'+CRF)
fwrite(oArq,'Del '+oName+'.obj'+CRF)

for i:=1 to Len(voPrgFiles)
   if !empty( voPrgFiles[i] )
      oName:=Substr(voPrgFiles[i],1,Len(voPrgFiles[i])-4) 
      fwrite(oArq,'Del '+oName+'.c '+CRF)
      fwrite(oArq,'Del '+oName+'.map'+CRF)
      fwrite(oArq,'Del '+oName+'.obj'+CRF)
  endif  
next
*/ 
fClose(oArq)

__Run("Hwg_Build.bat>Error.log")

if file(voExeName+".exe")
   MsgInfo("File "+ voExeName+".exe Build correct")
Else 
   ShellExecute("NotePad error.log")   
Endif   
Return Nil

Function BuildPoMake()
Local voExeName, voLibFolder, voIncFolder, voPrgFlag, voCFlag, voPrgMain, voPrgFiles, voCFiles,voResFiles
Local oLibFiles, CRF:=CHR(13)+CHR(10), oName, oInc, lName, gDir
Local oArq:=fCreate("Makefile.pc"),i, vHwGUI, vHarbour, vPelles

If File(oDirec+"BuildPelles.Ini")
   vHwGUI:=Hwg_GetIni( 'Config', 'DIR_HwGUI' , , oDirec+"BuildPelles.Ini" )
   vHarbour:=Hwg_GetIni( 'Config', 'DIR_HARBOUR' , , oDirec+"BuildPelles.Ini")
   vPelles:=Hwg_GetIni( 'Config', 'DIR_PELLES' , , oDirec+"BuildPelles.Ini" )
Else 
   vHwGUI:="C:\HWGUI"
   vHarbour:="C:\Harbour"
   vPelles:="C:\Pocc"   
EndIf
 
voExeName  :=oExeName:GetText() 
voLibFolder:=oLibFolder:GetText() 
voIncFolder:=oIncFolder:GetText()
voPrgFlag  :=oPrgFlag:GetText() 
voCFlag    :=oCFlag:GetText() 
voPrgMain  :=oMainPrg:GetText() 

voPrgFiles :=oBrowse1:aArray
voCFiles   :=oBrowse2:aArray
voLibFiles :=oBrowse3:aArray
voResFiles :=oBrowse4:aArray

fwrite(oArq,"# makefile for Pelles C 32 bits"+CRF)
fwrite(oArq,"# Building of App Using Pomake"+CRF)

fwrite(oArq,"# Comment the following for HARBOUR"+CRF)
fwrite(oArq,"__XHARBOUR__ = 1"+CRF)

fwrite(oArq,"HRB_DIR = "+vHarbour+CRF)
fwrite(oArq,"POCCMAIN = "+vPelles+CRF)
fwrite(oArq,"INCLUDE_DIR = include;"+vHarbour+"\include"+;
iif(!empty(voIncFolder),";"+voIncFolder,"")+CRF)
fwrite(oArq,"OBJ_DIR = obj"+CRF)
fwrite(oArq,"LIB_DIR = "+vHwGUI+"\lib"+CRF)
fwrite(oArq,"SRC_DIR = source"+CRF+CRF)

fwrite(oArq,"HARBOUR_EXE = HARBOUR "+CRF)
fwrite(oArq,"CC_EXE = $(POCCMAIN)\BIN\POCC.EXE "+CRF)
fwrite(oArq,"LIB_EXE = $(POCCMAIN)\BIN\POLINK.EXE "+CRF)
fwrite(oArq,"HARBOURFLAGS = -i$(INCLUDE_DIR) -n1 -q0 -w -es2 -gc0"+CRF)
fwrite(oArq,'CFLAGS = /Ze /I"INCLUDE" /I"$(HRB_DIR)\INCLUDE" /I"$(POCCMAIN)\INCLUDE" /I"$(POCCMAIN)\INCLUDE\WIN" /I"$(POCCMAIN)\INCLUDE\MSVC" /D"HB_STATIC_STARTUP" /c'+CRF)

//# Please Note that /Op and /Go requires POCC version 2.80 or later
fwrite(oArq,'CFLAGS = $(CFLAGS) /Op /Go'+CRF)

fwrite(oArq,'!ifdef __XHARBOUR__ '+CRF)
fwrite(oArq,'CFLAGS = $(CFLAGS) /D"XHBCVS" '+CRF)
fwrite(oArq,'!endif '+CRF)

fwrite(oArq,'!ifndef ECHO'+CRF)
fwrite(oArq,'ECHO = echo.'+CRF)
fwrite(oArq,'!endif'+CRF)
fwrite(oArq,'!ifndef DEL'+CRF)
fwrite(oArq,'DEL = del'+CRF)
fwrite(oArq,'!endif'+CRF+CRF)

fwrite(oArq,'HWGUI_LIB = $(LIB_DIR)\hwgui.lib'+CRF)
fwrite(oArq,'PROCMISC_LIB = $(LIB_DIR)\procmisc.lib'+CRF)
fwrite(oArq,'XML_LIB = $(LIB_DIR)\hbxml.lib'+CRF)
fwrite(oArq,'QHTM_LIB = $(LIB_DIR)\hwg_qhtm.lib'+CRF+CRF)

fwrite(oArq,'all: \'+CRF)
fwrite(oArq,'   $(HWGUI_LIB) \'+CRF)
fwrite(oArq,'   $(PROCMISC_LIB) \'+CRF)
fwrite(oArq,'   $(XML_LIB) \'+CRF)
fwrite(oArq,'   $(QHTM_LIB)'+CRF+CRF)

 
fwrite(oArq,'FILE_OBJS = \'+CRF)
oName:=Substr(voPrgMain,1,Len(voPrgMain)-4)
/*lName:=""
for i:=1 to Len(oName)
   if Substr(oName, -i, 1)="\"
      Exit
   Endif
   lName+=Substr(oName, -i, 1)
Next
oName:=""
for i:=1 to Len(lName)         
   oName+=Substr(lName, -i, 1)
Next   
*/
fwrite(oArq,oName+".obj \ "+CRF)

if Len(voPrgFiles)>0 

   for i:=1 to Len(voPrgFiles)
   
      if !empty( voPrgFiles[i] )
 
         oName:=Substr(voPrgFiles[i],1,Len(voPrgFiles[i])-4)
         lName:=""
/*         for g:=1 to Len(oName)
            if Substr(oName, -g, 1)="\"
               Exit
            Endif
            lName+=Substr(oName, -g, 1)
         Next
         oName:=""
         for g:=1 to Len(lName)         
            oName+=Substr(lName, -g, 1)
         Next   

         fwrite(oArq,"$(OBJ_DIR)\"+oName+".obj ")
*/
         fwrite(oArq,oName+".obj ")

         IF i<len(voPrgFiles)
            fwrite(oArq,"\"+CRF)
         Else   
            fwrite(oArq,CRF+CRF)
         Endif
      Endif   
      
   Next
Endif

fwrite(oArq,voExeName+ ": $(FILE_OBJS)"+CRF)
fwrite(oArq,"   $(LIB_EXE) /out:$@ $** "+CRF+CRF)


oName:=Substr(voPrgMain,1,Len(voPrgMain)-4) 

fwrite(oArq,oName+".c : "+voPrgMain+CRF)
fwrite(oArq,"   $(HARBOUR_EXE) $(HARBOURFLAGS) $** -o$@"+CRF+CRF)

if Len(voPrgFiles)>0 
for i:=1 to Len(voPrgFiles)
    if !empty( voPrgFiles[i] )
 
       oName:=Substr(voPrgFiles[i],1,Len(voPrgFiles[i])-4) 
       fwrite(oArq,oName+".c : "+voPrgFiles[i]+CRF)
       fwrite(oArq,"   $(HARBOUR_EXE) $(HARBOURFLAGS) $** -o$@"+CRF+CRF)
   ENDIF    
Next
endif
oName:=Substr(voPrgMain,1,Len(voPrgMain)-4) 
fwrite(oArq,oName+".obj : "+oName+".c"+CRF)
fwrite(oArq,"   $(CC_EXE) $(CFLAGS) /Fo$@ $** "+CRF+CRF)

if Len(voPrgFiles)>0 
for i:=1 to Len(voPrgFiles)
    if !empty( voPrgFiles[i] )
       oName:=Substr(voPrgFiles[i],1,Len(voPrgFiles[i])-4) 
       fwrite(oArq,oName+".obj : "+oName+".c"+CRF)
       fwrite(oArq, "   $(CC_EXE) $(CFLAGS) /Fo$@ $** "+CRF+CRF)
   ENDIF    
Next
endif

if Len(voCFiles)>0 
oInc:=""
for i:=1 to Len(voCFiles)
    if !empty(voCFiles[i])
       if !empty(oIncFolder)
          oInc:='/I"'+voIncFolder+'"'
       endif   
       oName:=Substr(voCFiles[i],1,Len(voCFiles[i])-4) 

       fwrite(oArq,oName+".obj : "+voCFiles[i]+CRF)
       fwrite(oArq, "   $(CC_EXE) $(CFLAGS) /Fo$@ $** "+CRF)

    endif   
Next
Endif
 
fClose(oName)

Return Nil
 