#include "scm.ch"

********************************************************************************
FUNCTION FRMcad_setor        //CADASTRO DE SETOR
********************************************************************************
PRIVATE oCadsetor
PRIVATE oFont, grpConfiguracao
PRIVATE oIcon := HIcon():AddResource(1004)
*************VARIAVEIS********************
PRIVATE LBLcod, Wcod  := 0, Ocod
PRIVATE LBLnome,Wnome := "", Onome
*************VARIAVEIS********************
dbcloseall()

IF Use_Arq("FUNCAO",,.T.,.F.,.F.)=.F.
   Return
ENDIF

SELE FUNCAO
DBGOTOP()

PREPARE FONT oFont NAME "Arial" WIDTH 0 HEIGHT -12 WEIGHT 400
INIT DIALOG OCadsetor CLIPPER NOEXIT TITLE "Cadastro de Função";
AT 0,0 SIZE 670,365;
ICON oIcon ;
FONT oFont ;   
STYLE DS_CENTER + WS_VISIBLE + WS_CAPTION + WS_SYSMENU 
   
SetColorinFocus( .t. )


@ 5,5  GROUPBOX grpConfiguracao     CAPTION "Descrição do Função"               SIZE 655,350

****INICO DOS SAYS***
@ 20,40   SAY LBLcod                CAPTION "Codigo:"                           SIZE 168,22
@ 20,70   SAY LBLnome               CAPTION "Nome:"                             SIZE 168,22
****FIM DOS SAYS***

****INCIO DOS GTES***
@ 80,40   GET Ocod  VAR Wcod        PICTURE "99999"  COLOR 255                  SIZE 50,22 STYLE WS_DISABLED;
TOOLTIP "Informe o Codigo"

@ 80,70   GET Onome VAR Wnome       PICTURE "@!"                  SIZE 560,22;
MAXLENGTH 40;
STYLE WS_TABSTOP;
TOOLTIP "Informe o Nome da Função"

****FIM DOS GTES***

@ 20,100 BROWSE oBrw DATABASE of OCadsetor SIZE 620,150 ;
         STYLE  WS_VSCROLL + WS_HSCROLL;
         ON getfocus {||DBGOTOP(),oBrw:Refresh()};
         ON CLICK {|o,key| BrowseKey4(o, key )}

oBrw:alias := aLIAS()

oBrw:bKeyDown := {|o,key| BrowseKey4(o, key ) }

@ 5,255 say "[ C ]-Cadastrar   [ A ]-Alterar   [ F1 ]-Sobre   [ F5 ]-Gera Excel   [ F9 ]-Calculadora" size 550,22;
STYLE SS_CENTER COLOR x_BLUE

   oBrw:AddColumn( HColumn():New( "Cod Nº",               FieldBlock(Fieldname(1)), "N",  6,0) )
   oBrw:AddColumn( HColumn():New( "Descrição da Função",  FieldBlock(Fieldname(2)), "C",  40,0) )

   oBrw:aColumns[1]:length := 6  // TAMANHO
   oBrw:aColumns[2]:length := 40 // TAMANHO

   oBrw:aColumns[1]:picture:="@R 999999"

oBrw:Refresh()
oBrw:SetFocus()
setfocus(obrw)

OCadsetor:bActivate := {||oBrw:SetFocus(),oBrw:Refresh()}

wNome = " "
GOTO LASTREC()
wCod  = COD+1
oNome:Refresh()
oCod:Refresh() 
DBGOTOP()

*******Buttons****
@ 210,320  BUTTON btnOk CAPTION "&Salvar"                                       SIZE 100, 28 ;
TOOLTIP "Salvar Registro";
ON CLICK {|| Grava_setor(),DBGOTOP(),oBrw:refresh()};
STYLE WS_TABSTOP

@ 320,320  BUTTON "&Limpar" SIZE 100, 28 ;
TOOLTIP "Limpar Campos";
ON CLICK {|| limpa_Var5(),oBrw:Refresh() };
STYLE WS_TABSTOP  

@ 430,320  BUTTON "&Excluir" SIZE 100, 28 ;
TOOLTIP "Sair do Modulo de Cadastro";
ON CLICK {|| Exclui_reg(),Limpa_var5(), oBrw:Refresh() };
STYLE WS_TABSTOP

@ 540,320  BUTTON "&Fechar" SIZE 100, 28 ;
TOOLTIP "Sair do Modulo de Cadastro";
ON CLICK {|| dbcloseall(),oCadsetor:Close() };
STYLE WS_TABSTOP

 WriteStatus( oTelaPrincipal,3,"Cadastro de Setor")  
   ACTIVATE DIALOG OCadsetor
 WriteStatus( oTelaPrincipal,3,"Area de Trabalho") 
  
RETURN nil
********************************************************************************
FUNCTION Altera()
********************************************************************************
SELE FUNCAO

wCod  = COD
wNome = FUNCAO
oNome:Refresh()
oCod:Refresh()
oCod:disable()
oBrw:Refresh()
oBrw:SetFocus()
setfocus(obrw)
oNome:setfocus()

RETURN
********************************************************************************
FUNCTION Grava_setor()
********************************************************************************
IF EMPTY(Wnome)
   OBRIGA()
   oNome:setfocus()
   RETURN
ENDIF

SELECT FUNCAO
DBSETORDER(1)
DBGOTOP()
DBSEEK(wCod)
IF FOUND()
   TRAVAREG()
   REPLACE FUNCAO WITH Wnome
   Limpa_var5()
ELSE
   APPEND BLANK
   REPLACE COD     WITH Wcod
   REPLACE FUNCAO  WITH Wnome
   Limpa_var5()
ENDIF
DBCOMMIT()
LIBERAREG()

RETURN

********************************************************************************
FUNCTION Limpa_var5()
********************************************************************************
SELE FUNCAO
Wnome := " "
GOTO LASTREC()
Wcod=COD+1
oNome:Refresh()
oCod:Refresh()
oBrw:Refresh()
oBrw:SetFocus()
setfocus(obrw)
oNome:SetFocus()
DBGOTOP()
RETURN

********************************************************************************
FUNCTION BrowseKey4( oBrowse, key)
********************************************************************************
DO CASE
   CASE KEY= VK_ESCAPE
        EndDialog()
   CASE KEY = VK_F1
        SOBRE()
   CASE KEY = VK_F2
        BUSCA_NOME()
   CASE KEY = VK_F9
        ShellExecute("calc")
   OTHERWISE
   IF  key=13 .OR. key=65 //A
        Altera()
   ELSEIF key=46     
        Exclui_reg()
  ELSEIF key=67    //C
        Limpa_var5() 
   ENDIF
ENDCASE

RETURN .T.

*******************
FUNCTION Exclui_reg
*******************
SELECT FUNCAO
DBGOTOP()
DBSETORDER(1)
DBSEEK(Wcod)
TRAVAREG()
dele
DBCOMMIT()
LIBERAREG()
DBGOTOP()
RETURN

