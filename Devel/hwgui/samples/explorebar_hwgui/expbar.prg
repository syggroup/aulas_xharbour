REQUEST HB_LANG_PT
#include "hbclass.ch"
#include "HWGUI.CH"

#xcommand MENU [ OF <oWnd> ] [ ID <nId> ] [ TITLE <cTitle> ] [ COLOR <bcolor> ] [ BMPSIZE <nWidthBmp>, <nHeighBmp> ] ;
          => ;
          Hwg_BeginMenu( <oWnd>, <nId>, <cTitle>, <bcolor>, <nWidthBmp>,<nHeighBmp> )

Function Main
  LOCAL oMenu1, oToolbar, oToolbutton1, oToolbutton2, oToolbutton3, oToolbutton4, oToolbutton5 ;
        , oToolbutton6, oToolbutton7, oToolbutton8, oStatusBar,vCombo1,   nRefr := 0


         /* teste explore panel*/
   INIT WINDOW frmMain MAIN MDI TITLE "Sistema" HELP "hwgui.chm";
        AT 0,0 SIZE 800,600   MENUPOS 1 COLOR 16777215; //14155775 ;
        FONT HFont():Add( 'Arial',0,-12,400,,,)

   MENU OF frmMain COLOR 15527167 BMPSIZE 24, 24
     MENU TITLE '&Paineis' ID 32000
       MENUITEM 'Trocar cor Painel' + CHR(VK_TAB) + 'Ctrl+p' ID 32005  ACTION ( PaineL( oexp )) ; //( sairdosistema(.F.),  )  ;
       BITMAP "smedit" FROM RESOURCE  ACCELERATOR FCONTROL,'X'
       SEPARATOR
       MENUITEM 'Hide Painel 2' + CHR(VK_TAB) + '' ID 32006  ACTION ( oexp:HidePanel( 2 ) )
       MENUITEM 'Show Painel 2' + CHR(VK_TAB) + '' ID 32007  ACTION ( oExp:SHOWPanel( 2 ) )
      SEPARATOR
      MENUITEM 'Adicionar Link Painel 4' + CHR(VK_TAB) + 'Ctrl+p' ID 32008  ACTION ( NovoLink( oexp, 4 ) )
      SEPARATOR
       MENUITEM 'Reduz Painel 3' + CHR(VK_TAB) + '' ID 32018  ACTION ( oexp:apanels[ 3 ]:collapsed() )
      MENUITEM 'Expand Painel 3' + CHR(VK_TAB) + 'p' ID 32019  ACTION ( oExp:apanels[ 3 ]:Expand() )
     SEPARATOR
     MENUITEM 'Adicionar Link Painel 4' + CHR(VK_TAB) + '' ID 32008  ACTION ( NovoLink( oexp, 4 ) )
       SEPARATOR
       MENUITEM 'Sair do Sistema' + CHR(VK_TAB) + 'Ctrl+X' ID 32010  ACTION (frmmain:close()) ; //( sairdosistema(.F.),  )  ;
       BITMAP "smexit3" FROM RESOURCE  ACCELERATOR FCONTROL,'X'
      ENDMENU
      MENU TITLE '&Childs' ID 32001
       MENUITEM 'Novo' + CHR(VK_TAB) + 'Ctrl+N' ID 32020  ACTION ( criarmdichild()) ; //( sairdosistema(.F.),  )  ;
       BITMAP "smnew" FROM RESOURCE  ACCELERATOR FCONTROL,'N'

     ENDMENU
   ENDMENU

   @ 0,0 PANEL oPanel OF frmMain SIZE 0,76;
   STYLE WS_VSCROLL + WS_HSCROLL

   ADD STATUS oStatusBar TO frmMain HEIGHT 25 ;
   PARTS 500, 500 ;
   ON INIT {|This| this:settextpanel(1,"Versão do Sistema:") }
   oStatusBar:brclick := {|| msginfo("righ click")}
   oStatusBar:seticonpanel(2,"linecol",16,16)

   bClick := {|o| MsgInfo( o:TITLE ) }
   oexp := HExplorerBar():New()

   oPanel21 := oexp:AddPanel("Areas de Imagens" )
   oPanel21:lSpecial := .T.
   oPanel21:AddLink("Ver como una presentacion", bClick ,"ExpBar_rc\presentacion.bmp")
   oPanel21:AddLink("Pedir copias fotograficas en lineas",bClick,"ExpBar_rc\copiamundo.bmp")
   oPanel21:AddLink("Imprimir imagenes",bClick,"ExpBar_rc\impriimagen.bmp")
   oPanel21:AddLink("Copiar todos los elementos a un CD",bClick,"copiacd")

  oPanel21 := oExp:AddPanel("Tareas de archivo y carpeta" )
  oPanel21:AddLink("Crear nueva carpeta",bClick,"nuevofolder")
  oPanel21:AddLink("Publicar esta carpeta en web",bClick,"publicar")
  oPanel21:AddLink("Compartir esta carpeta",bClick,"compartir")

  oPanel := oExp:AddPanel("Otros sitios" )
  oPanel:AddLink("Imagenes compartidas",bClick,"folderimg")
  oPanel:AddLink("Mi PC",bClick,"mipc")
  oPanel:AddLink("Mis sitios de red",bClick,"sitiosred")

  oPanel := oExp:AddPanel("Detalles" )

   ACTIVATE WINDOW frmMain  MAXIMIZED
   
 RETURN NIL


FUNCTION CriarMdiChild()

  INIT WINDOW  oMdi MDICHILD  TITLE "FORM " + time(); //DIALOG oDlg TITLE "Form1" ;
    AT 0,0 SIZE 450,250 CLIPPER  ;
     STYLE WS_CHILD + WS_CAPTION+WS_SYSMENU+WS_SIZEBOX + WS_MAXIMIZEBOX //+DS_CENTER

  ACTIVATE WINDOW oMdi

FUNCTION PAINEL( oexp )

   oexp:nTopColor := RGB( 255,255,255 )
   oexp:nBottomColor := RGB( 255,255,255 ) //RGB( 19, 117, 24 )
   oexp:REFRESH()
RETURN NIL


FUNCTION NovoLink( oexp, N )
   oExp:aPanels[ n ]:AddLink("Novo Link",{|| msginfo( "novo link")},"ExpBar_rc\impriimagen.bmp")

  RETURN NIL
  
