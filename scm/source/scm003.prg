#include "scm.ch"

**************************
Function alterar_registros
**************************
SET DELETED OFF
#ifdef _XHBSQL_
SR_UseDeleteds( .T. )     // NÃO MANTER REGISTROS DELETADOS NAS TABELAS
#endif

DbCloseall()
alterar_registros2()
DBCLOSEALL()

#ifdef _XHBSQL_
SR_UseDeleteds( .F. )     // NÃO MANTER REGISTROS DELETADOS NAS TABELAS
#endif
SET DELETED ON
Return

***************************
Function alterar_registros2
***************************
Local oFrm, oFont
Local aArq:={}
Local vESCOLHA := 0
Local aCAMPOS  := {}
PRIVATE vFILE  := ""

PRIVATE oDlgHabla:=NIL
MsgRun("Aguarde Listando Arquivos")

IF eTipo_banco="DBF"
   vSALVA_PATH := curdrive()+':'+"\"+curdir()  // SALVA O PATH ATUAL PARA RESTAURAR DEPOIS
   aDir1 := curdrive()+":\"+rtrim(curdir()) + "\" + eCAMINHO_DADOS +"*.dbf"
   aDir0 := directory(aDir1)

   for x=1 to len(aDir0)
       if Upper(Left(aDir0[x,1],5)) # "ATUAL"
          aadd(aArq,aDir0[x,1])
       ENDIF
   next
ELSE
   #ifdef _XHBSQL_
   aArq:=SR_ListTables()
   #endif
   For nI:=1 to len(aArq)
       if Upper(Left(aArq[nI],5)) = "ATUAL" .or. Upper(Left(aArq[nI],2)) = "SR"
          aArq[nI] := "NÃO USAR"
       ENDIF
   Next
ENDIF

IF LEN(aArq) > 0
   Fim_Run()
   vESCOLHA :=  MY_WChoice( aArq, "Seleciona uma Tabela", 15+LEN(aArq), 200,HFont():Add( '',0,-12,400,,,) ,,,,,,)
ELSE
   Fim_Run()
   MsgStop("Não foi selecionado nenhuma tabela, Favor revisar","Aviso do Sistema")
   Return
ENDIF

IF vESCOLHA > 0
   vFILE:=aArq[vESCOLHA]
   IF vFILE="NÃO USAR"
      Fim_Run()
      MsgStop("Essa Tabela não pode ser alterada, Favor revisar","Aviso do Sistema")
      Return
   ENDIF
ELSE
   Fim_Run()
   MsgStop("Não foi selecionado nenhuma tabela, Favor revisar","Aviso do Sistema")
   Return
endif
Fim_Run()

vFILE=ALLTRIM(vFILE)
IF eTipo_banco="DBF"
   vFILE:=SUBSTR(vFILE, 1,LEN(vFILE)-4)
ENDIF

DBCLOSEALL()
IF Use_Arq(vFILE,,.T.,.F.,.F.)=.F.  // COMPARTILHADO
   Return Nil
ENDIF

SELE &vFILE
IF eTipo_banco="DBF"
   aStruct := DbStruct()
ELSE
   #ifdef _XHBSQL_
   aStruct := sr_dbStruct()
   #endif
ENDIF

FOR nI := 1 TO Len(aStruct)
    AADD(aCAMPOS ,aStruct[nI,1] )
NEXT

PREPARE FONT oFontBtn NAME "Arial" WIDTH 0 HEIGHT -14
        INIT DIALOG oFrm TITLE "Alteração de Registros na Tabela: " + vFILE CLIPPER FONT oFontBtn;
        AT 0,0;
        SIZE HWG_GETDESKTOPWIDTH(),HWG_GETDESKTOPHEIGHT()-50 ;
        ICON HIcon():AddResource(1004) ;
        STYLE WS_POPUP+WS_CAPTION+DS_CENTER +WS_SYSMENU+WS_MINIMIZEBOX+WS_MAXIMIZEBOX+WS_VISIBLE

@ HWG_GETDESKTOPWIDTH()-110,HWG_GETDESKTOPHEIGHT()-100  BUTTONEX "&Fechar" SIZE 100, 38 ;
TOOLTIP "Sair do Modulo e Voltar aos Menus";
ON CLICK {|| oFrm:Close() };
BITMAP (HBitmap():AddResource(1005)):handle  ;
STYLE WS_TABSTOP

@ 10,HWG_GETDESKTOPHEIGHT()-150  BUTTONEX "&Add Novo" SIZE 100, 38 ;
TOOLTIP "Clique aqui para Adicionar um novo registro";
ON CLICK {|| add_reg_novo() };
FONT HFont():Add( '',0,-12,400,,,);
BITMAP (HBitmap():AddResource(1040)):handle  ;
STYLE WS_TABSTOP

@ 120,HWG_GETDESKTOPHEIGHT()-150  BUTTONEX "&Excluir / Restaurar" SIZE 150, 38 ;
TOOLTIP "Clique aqui para Excluir ou Restaurar um Registro";
ON CLICK {|| Del_registro() };
FONT HFont():Add( '',0,-12,400,,,);
BITMAP (HBitmap():AddResource(1039)):handle  ;
STYLE WS_TABSTOP

@ 280,HWG_GETDESKTOPHEIGHT()-150  BUTTONEX "&Atualizar" SIZE 100, 38 ;
TOOLTIP "Clique aqui para Atualizar a Tela de Registros";
ON CLICK {|| My_Refresh() };
FONT HFont():Add( '',0,-12,400,,,);
BITMAP (HBitmap():AddResource(1037)):handle  ;
STYLE WS_TABSTOP

@ 390,HWG_GETDESKTOPHEIGHT()-150  BUTTONEX "&Filtro" SIZE 80, 38 ;
TOOLTIP "Clique aqui para Realizar um Filtro";
ON CLICK {|| Executa_Filtro() };
FONT HFont():Add( '',0,-12,400,,,);
BITMAP (HBitmap():AddResource(1006)):handle  ;
STYLE WS_TABSTOP

IF eTipo_banco="SQL"
   @ 480,HWG_GETDESKTOPHEIGHT()-150  BUTTONEX "&Excluir Tabela" SIZE 130, 38 ;
   TOOLTIP "Clique aqui para Selecionar e Excluir uma tabela";
   ON CLICK {|| Excluir_tabela_sql() };
   FONT HFont():Add( '',0,-12,400,,,);
   BITMAP (HBitmap():AddResource(1039)):handle  ;
   STYLE WS_TABSTOP

   @ 620,HWG_GETDESKTOPHEIGHT()-150  BUTTONEX "&Excluir Indice" SIZE 130, 38 ;
   TOOLTIP "Clique aqui para Selecionar e Excluir um Indice";
   ON CLICK {|| Excluir_indice_sql() };
   FONT HFont():Add( '',0,-12,400,,,);
   BITMAP (HBitmap():AddResource(1039)):handle  ;
   STYLE WS_TABSTOP
ENDIF

@ 10,40 BROWSE oBrw DATABASE OF oFrm SIZE HWG_GETDESKTOPWIDTH()-30, HWG_GETDESKTOPHEIGHT()-200 ;
        STYLE  WS_VSCROLL + WS_HSCROLL;
        FONT HFont():Add( '',0,-12,400,,,);
        ON POSCHANGE {|| SetFocus(oBrw:handle ) }

oBrw:alias := ALIAS()

oBrw:bKeyDown := {|o,key| BrowseKey_alt(o, key ) }

@ 5,10 say "F1 - Sobre  / F2 - Busca  / F4 - Muda Ordem  / F5 - Gera Excel  / F9 - Calculadora" size HWG_GETDESKTOPWIDTH()-20,20;
STYLE SS_CENTER COLOR x_BLUE

aEVAL(aCAMPOS,;
{|cVAL,nIND| oBrw:addcolumn(HColumn():New( aCAMPOS[nIND], FieldBlock(aCAMPOS[nIND]) ,,,,.T.,0,0,,,,,,)) })

FOR nI := 1 TO Len(oBrw:aColumns)
    oBrw:aColumns[nI]:lEditable := .T.
    oBrw:aColumns[nI]:nJusHead := DT_CENTER    //CENTRALIZA NO NOME DO CAMPO
    oBrw:aColumns[nI]:nJusLin  := DT_LEFT     //COLOCA PARA DIREITA A LINHA

   oBrw:aColumns[nI]:bColorBlock := {|| IF(Deleted() ,{x_RED ,  x_WHITE, x_GREEN, x_CYAN} ,;
                                        IF(!Deleted(),{x_BLUE,  x_WHITE, x_GREEN, x_CYAN} , {x_BLACK, x_WHITE , x_GREEN, x_CYAN } ) ) }
NEXT

oBrw:Refresh()
oBrw:SetFocus()
setfocus(obrw)

ACTIVATE DIALOG oFrm //Show SW_SHOWMAXIMIZED

Return

*********************************************
Static Function BrowseKey_alt( oBrowse, key )
*********************************************
DO CASE
   CASE KEY= VK_ESCAPE
        EndDialog()
   CASE KEY = VK_F1
        Sobre()
   CASE KEY = VK_F2
        BUSCA_NOME(oBrowse)
   CASE KEY = VK_F4
        Lista_ordem(oBrowse)
   CASE KEY = VK_F5
        Gera_Excel(oBrowse)
   CASE KEY = VK_F9
        ShellExecute("calc")
   otherwise
   if key=46           // tecla "DEL"
      Del_registro()
   endif
ENDCASE
Return .T.

***************************
Function Excluir_indice_sql
***************************
Local aArq:={}
#ifdef _XHBSQL_
aArq:=SR_ListTables()
#endif
For nI:=1 to len(aArq)
    if Upper(Left(aArq[nI],5)) = "ATUAL" .or. Upper(Left(aArq[nI],2)) = "SR"
       aArq[nI] := "NÃO USAR"
    ENDIF
Next

IF LEN(aArq) > 0
   vESCOLHA :=  MY_WChoice( aArq, "Seleciona uma Tabela", 5+LEN(aArq), 200,HFont():Add( '',0,-12,400,,,) ,,,,,,)
ELSE
   MsgStop("Não foi selecionado nenhuma tabela, Favor revisar","Aviso do Sistema")
   Return
ENDIF

IF vESCOLHA > 0
   IF aArq[vESCOLHA]="NÃO USAR"
      Fim_Run()
      MsgStop("Essa Tabela não pode ser Uasada, Favor revisar","Aviso do Sistema")
      Return
   ENDIF
ELSE
   MsgStop("Não foi selecionado nenhuma tabela, Favor revisar","Aviso do Sistema")
   Return
endif
IF MsgYesNo("Deseja realmente Excluir o Indice da Tabela: " + aArq[vESCOLHA],"Aviso do Sistema")
   deleta_cdx(aArq[vESCOLHA])
ENDIF
Return

***************************
Function Excluir_tabela_sql
***************************
Local aArq:={}
#ifdef _XHBSQL_
aArq:=SR_ListTables()
#endif
For nI:=1 to len(aArq)
    if Upper(Left(aArq[nI],5)) = "ATUAL" .or. Upper(Left(aArq[nI],2)) = "SR"
       aArq[nI] := "NÃO USAR"
    ENDIF
Next

IF LEN(aArq) > 0
   vESCOLHA :=  MY_WChoice( aArq, "Seleciona uma Tabela", 5+LEN(aArq), 200,HFont():Add( '',0,-12,400,,,) ,,,,,,)
ELSE
   MsgStop("Não foi selecionado nenhuma tabela, Favor revisar","Aviso do Sistema")
   Return
ENDIF

IF vESCOLHA > 0
   IF aArq[vESCOLHA]="NÃO USAR"
      Fim_Run()
      MsgStop("Essa Tabela não pode ser Excluida, Favor revisar","Aviso do Sistema")
      Return
   ENDIF
ELSE
   MsgStop("Não foi selecionado nenhuma tabela, Favor revisar","Aviso do Sistema")
   Return
endif
IF MsgYesNo("Deseja realmente Excluir a tabela: " + aArq[vESCOLHA],"Aviso do Sistema")
   deleta_dbf(aArq[vESCOLHA])
ENDIF
Return

***********************
Function Executa_Filtro
***********************
Local lcbusca:=MY_MSGGET("Filtro em Tabela.","Informe o Filtro:",DbFilter())

IF EMPTY(lcbusca)
   Limpa_Filtro()
ELSE
   IF eTipo_banco="DBF"
      Set filter to &lcbusca
   ELSE
      #ifdef _XHBCOM_
      Sr_Setfilter(lcbusca)
      #endif
   ENDIF
ENDIF
My_Refresh()
Return

*******************
Function My_Refresh
*******************
#ifdef _XHBCOM_
SR_dbRefresh()
#endif
oBrw:Bottom()
oBrw:SetFocus()
oBrw:Refresh()
Return

*********************
Function add_reg_novo
*********************
SELE &vFILE
AppRede()
DBCOMMIT()
LIBERAREG()

oBrw:Refresh()
oBrw:SetFocus()
setfocus(obrw)
Return

**********************
Function Del_registro
**********************
IF LASTREC() = 0
   ERROREG()
   RETURN
ENDIF
vREG=RECNO()
DBGOTO(vREG)
IF EOF()
   ERROREG()
   RETURN .T.
ELSE
   IF !Deleted()
      IF MsgYesNo("Deseja Realmente Excluir esse Registro ?" ,"Aviso do Sistema")
         #ifdef _XHBCOM_
         SR_begintransaction()
         #endif
         DBGOTO(vREG)
         TRAVAREG("S")
         DELE
         DBCOMMIT()
         LIBERAREG()
         #ifdef _XHBCOM_
         SR_EndTransaction()
         #endif
      ENDIF
   ELSE
      IF MsgYesNo("Deseja Realmente Retornar esse Registro ?" ,"Aviso do Sistema")
         #ifdef _XHBCOM_
         SR_begintransaction()
         #endif
         DBGOTO(vREG)
         TRAVAREG("S")
         DbRecall()
         DBCOMMIT()
         LIBERAREG()
         #ifdef _XHBCOM_
         SR_EndTransaction()
         #endif
      ENDIF
   ENDIF
ENDIF
Return .T.

************************************************
FUNCTION MY_MSGGET( cTitle, cText, vINI ,cMask )
************************************************
   Local oDlg, oRES
   Local cRes := IIF(vINI=Nil,"",vINI)
   cMask := IIF(cMask=Nil,"@!",cMask)

   INIT DIALOG oDlg TITLE cTitle At 0,0 CLIPPER NOEXIT SIZE 300, 180 ;
   ICON HIcon():AddResource(1004) ;
   FONT HFont():Add( "MS Sans Serif", 0, - 13 );
   STYLE DS_CENTER +WS_SYSMENU+WS_VISIBLE

   @ 20, 10 SAY cText SIZE 260, 22
   IF cMask="@D" .OR. cMask="@d"
      @ 20,35 GET DATEPICKER oRES VAR cRes  SIZE 260, 26;
      TOOLTIP 'Informe a Data';
      STYLE 0  + WS_TABSTOP
   ELSE
      @ 20,35 GET oRES VAR cRes  SIZE 260, 26;
      PICTURE cMask ;
      TOOLTIP '';
      STYLE WS_TABSTOP
   ENDIF

   @ 20, 95  BUTTONEX "Ok" SIZE 100, 38;
   TOOLTIP 'Clique aqui para Continuar';
   STYLE WS_TABSTOP;
   BITMAP (HBitmap():AddResource(1006)):handle  ;
   ON CLICK {|| oDlg:CLOSE() }

   @ 180, 95 BUTTONEX "Cancelar" SIZE 100, 38;
   TOOLTIP 'Clique aqui para Cancelar';
   STYLE WS_TABSTOP;
   BITMAP (HBitmap():AddResource(1005)):handle  ;
   ON CLICK {|| cRes:="",oDlg:CLOSE() }

   oDlg:Activate()

RETURN(cRes)

**************************************************************************************************
FUNCTION MY_WChoice( arr, cTitle, nLeft, nTop, oFont, clrT, clrB, clrTSel, clrBSel, cOk, cCancel )
**************************************************************************************************
   LOCAL oDlg, oBrw, nChoice := 0, lArray := .T., nField, lNewFont := .F.
   LOCAL i, aLen, nLen := 0, addX := 20, addY := 20, minWidth := 0, x1
   LOCAL hDC, aMetr, width, height, aArea, aRect
   LOCAL nStyle := WS_POPUP + WS_VISIBLE + WS_CAPTION + WS_SYSMENU + WS_SIZEBOX +DS_CENTER

   IF cTitle == Nil ; cTitle := "" ; ENDIF
   IF nLeft == Nil .AND. nTop == Nil ; nStyle += DS_CENTER ; ENDIF
   IF nLeft == Nil ; nLeft := 0 ; ENDIF
   IF nTop == Nil ; nTop := 0 ; ENDIF
   IF oFont == Nil
      oFont := HFont():Add( "MS Sans Serif", 0, - 13 )
      lNewFont := .T.
   ENDIF
   IF cOk != Nil
      minWidth += 120
      IF cCancel != Nil
         minWidth += 100
      ENDIF
      addY += 30
   ENDIF

   IF ValType( arr ) == "C"
      lArray := .F.
      aLen := RecCount()
      IF ( nField := FieldPos( arr ) ) == 0
         RETURN 0
      ENDIF
      nLen := dbFieldInfo( 3, nField )
   ELSE
      aLen := Len( arr )
      IF ValType( arr[ 1 ] ) == "A"
         FOR i := 1 TO aLen
            nLen := Max( nLen, Len( arr[ i, 1 ] ) )
         NEXT
      ELSE
         FOR i := 1 TO aLen
            nLen := Max( nLen, Len( arr[ i ] ) )
         NEXT
      ENDIF
   ENDIF

   hDC := GetDC( GetActiveWindow() )
   SelectObject( hDC, oFont:handle )
   aMetr := GetTextMetric( hDC )
   aArea := GetDeviceArea( hDC )
   aRect := GetWindowRect( GetActiveWindow() )
   ReleaseDC( GetActiveWindow(), hDC )
   height := ( aMetr[ 1 ] + 1 ) * aLen + 4 + addY + 8
   IF height > aArea[ 2 ] - aRect[ 2 ] - nTop - 60
      height := aArea[ 2 ] - aRect[ 2 ] - nTop - 60
   ENDIF
   width := Max( aMetr[ 2 ] * 2 * nLen + addX, minWidth )

   if height <= 0
      height=440
   endif

   if width < 240
      width=240
   endif

   INIT DIALOG oDlg TITLE cTitle ;
        At 0,0  ;
        SIZE width, height       ;
        ICON HIcon():AddResource(1004) ;
        STYLE nStyle            ;
        FONT oFont              ;
        ON INIT { | o | ResetWindowPos( o:handle ), oBrw:setfocus() }

   IF lArray
      @ 0, 0 Browse oBrw Array
      oBrw:aArray := arr
      IF ValType( arr[ 1 ] ) == "A"
         oBrw:AddColumn( HColumn():New( , { | value, o | HB_SYMBOL_UNUSED( value ), o:aArray[ o:nCurrent, 1 ] }, "C", nLen ) )
      ELSE
         oBrw:AddColumn( HColumn():New( , { | value, o | HB_SYMBOL_UNUSED( value ), o:aArray[ o:nCurrent ] }, "C", nLen ) )
      ENDIF
   ELSE
      @ 0, 0 Browse oBrw DATABASE
      oBrw:AddColumn( HColumn():New( , { | value, o | HB_SYMBOL_UNUSED( value ), ( o:Alias ) ->( FieldGet( nField ) ) }, "C", nLen ) )
   ENDIF

   oBrw:oFont  := oFont
   oBrw:bSize  := { | o, x, y | MoveWindow( o:handle, addX / 2, 10, x - addX, y - addY ) }
   oBrw:bEnter := { | o | nChoice := o:nCurrent, EndDialog( o:oParent:handle ) }
   oBrw:bKeyDown := {|o,key|Iif(key==27,(EndDialog(oDlg:handle),.F.),.T.)}

   oBrw:lDispHead := .F.
   IF clrT != Nil
      oBrw:tcolor := clrT
   ENDIF
   IF clrB != Nil
      oBrw:bcolor := clrB
   ENDIF
   IF clrTSel != Nil
      oBrw:tcolorSel := clrTSel
   ENDIF
   IF clrBSel != Nil
      oBrw:bcolorSel := clrBSel
   ENDIF

   IF cOk != Nil
      x1 := Int( width / 2 ) - IIf( cCancel != Nil, 90, 40 )
      @ x1, height - 36 BUTTON cOk SIZE 80, 30 ON CLICK { || nChoice := oBrw:nCurrent, EndDialog( oDlg:handle ) }
      IF cCancel != Nil
         @ x1 + 100, height - 36 BUTTON cCancel SIZE 80, 30 ON CLICK { || nChoice := 0, EndDialog( oDlg:handle ) }
      ENDIF
   ENDIF

   oDlg:Activate()
   IF lNewFont
      oFont:Release()
   ENDIF

RETURN nChoice

