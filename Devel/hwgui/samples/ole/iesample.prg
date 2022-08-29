/*
 *$Id: iesample.prg 1615 2011-02-18 13:53:35Z mlacecilia $
 *
 * HWGUI - Harbour Win32 and Linux (GTK) GUI library
 * iesample.prg - sample of ActiveX container for the IE browser object
 *
 * Copyright 2006 Alexander S.Kresin <alex@belacy.belgorod.su>
 * www - http://kresin.belgorod.su
 */

#include "hwgui.ch"

Function Main
Local oMainWnd, oPanelTool, oPanelIE, oFont
Local oEdit, cUrl, oIE

   PREPARE FONT oFont NAME "Times New Roman" WIDTH 0 HEIGHT -15
   INIT WINDOW oMainWnd TITLE "Example" AT 200,0 SIZE 500,400 FONT oFont

   MENU OF oMainWnd
      MENU TITLE "File"
         MENUITEM "&Open file" ACTION OpenFile(oIE,oEdit)
         SEPARATOR
         MENUITEM "E&xit" ACTION oMainWnd:Close()
      ENDMENU
   ENDMENU

    @ 0,0 PANEL oPanelTool SIZE 500,32

    @ 5,4 EDITBOX oEdit CAPTION "http://kresin.belgorod.su" OF oPanelTool SIZE 400,24
    @ 405,4 BUTTON "Go!" OF oPanelTool SIZE 30,24 ;
        ON CLICK {||Iif(!Empty(cUrl:=GetEditText(oEdit:oParent:handle,oEdit:id)),oIE:DisplayPage(cUrl),.T.)}
    @ 435,4 BUTTON "Search" OF oPanelTool SIZE 55,24 ;
        ON CLICK {||Iif(!Empty(cUrl:=GetEditText(oEdit:oParent:handle,oEdit:id)),FindInGoogle(cUrl,oIE,oEdit),.T.)}

    @ 0,34 PANEL oPanelIE SIZE 500,366 ON SIZE {|o,x,y|o:Move(,,x,y-34)}

    oIE := HHtml():New( oPanelIE )

    ACTIVATE WINDOW oMainWnd

Return

Static Function OpenFile( oIE,oEdit )
Local mypath := "\" + Curdir() + Iif( Empty( Curdir() ), "", "\" )
Local fname := SelectFile( "HTML files", "*.htm;*.html", mypath )

   IF !Empty( fname )
      oEdit:SetText( fname )
      oIE:DisplayPage( fname )
   ENDIF

Return

Static Function FindInGoogle( cQuery,oIE,oEdit )
Local cUrl := "http://www.google.com/search?q=", cItem

   IF !Empty( cItem := NextItem( cQuery,.T.,' ' ) )
      cUrl += cItem
      DO WHILE !Empty( cItem := NextItem( cQuery,,' ' ) )
         cUrl += '+' + cItem
      ENDDO
      oEdit:SetText( cUrl )
      oIE:DisplayPage( cUrl )
   ENDIF
Return Nil
