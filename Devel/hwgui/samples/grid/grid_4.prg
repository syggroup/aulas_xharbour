/*
 * $Id: grid_4.prg 1615 2011-02-18 13:53:35Z mlacecilia $
 *
 * HWGUI - Harbour Win32 GUI library source code:
 * HGrid class
 *
 * Copyright 2002 Alexander S.Kresin <alex@belacy.belgorod.su>
 * www - http://www.geocities.com/alkresin/
 * Copyright 2004 Rodrigo Moreno <rodrigo_moreno@yahoo.com>
 *
*/

#include "windows.ch"
#include "guilib.ch"
#include "common.ch"

Static oMain, oForm, oFont, oGrid

Function Main()
        IF File('temp.dbf')
            FErase('temp.dbf')
        END
                    
        DBCreate( "temp.dbf", {{"LINE", "C", 300, 0}} )
        
        USE temp
                        
        INIT WINDOW oMain MAIN TITLE "File Viewer" ;
             AT 0,0 ;
             SIZE GetDesktopWidth(), GetDesktopHeight() - 28

                MENU OF oMain
                        MENUITEM "&Exit" ACTION oMain:Close()
                        MENUITEM "&Open File" ACTION FileOpen()                        
                ENDMENU

        ACTIVATE WINDOW oMain
        
        oServer:Close()
        
Return Nil

Function Test()
        PREPARE FONT oFont NAME "Courier New" WIDTH 0 HEIGHT -11
        
        INIT DIALOG oForm CLIPPER NOEXIT TITLE "File Viewer";
             FONT oFont ;
             AT 0, 0 SIZE 700, 425 ;
             STYLE DS_CENTER + WS_POPUP + WS_VISIBLE + WS_CAPTION + WS_SYSMENU
             
                
             @ 10,10 GRID oGrid OF oForm SIZE 680,375;
                     ITEMCOUNT Lastrec() ;
                     ON DISPINFO {|oCtrl, nRow, nCol| OnDispInfo( oCtrl, nRow, nCol ) } ;
                     NOGRIDLINES

             ADD COLUMN TO GRID oGrid HEADER "" WIDTH  800
                                                              
             @ 620, 395 BUTTON 'Close' SIZE 75,25 ON CLICK {|| oForm:Close() }                            
             
        ACTIVATE DIALOG oForm
Return Nil

Function OnDispInfo( o, x, y )    
    Local result := ''
    
    DBGoto(x)
    
    result := field->line
Return result

Function FileOpen()
        Local fname
        fname := SelectFile( "Select File", "*.*")
    
        Zap
        APPEND FROM (fname) SDF
Return Test()

