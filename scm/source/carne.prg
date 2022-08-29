#include "scm.ch"

********************************************************************************
FUNCTION FRMcad_mensal()         //CADASTRO DE MENSALIDADES
********************************************************************************
PRIVATE oCadmensal
PRIVATE oFont,oRadio1,oRadio2
PRIVATE oIcon := HIcon():AddResource(1004)
*************VARIAVEIS********************
PUBLIC LBLcodigo, Wcodigo := 0, Ocodigo
PUBLIC LBLparcela, Wparcela := 1, Oparcela
PUBLIC LBLdataemi, Wdataemi := date(), Odataemi
PUBLIC LBLhoraemi, Whoraemi := time(), Ohoraemi
PUBLIC LBLcodass, Wcodass := 0, Ocodass
PUBLIC LBLnome, Wnome := "", Onome ,aItens2:={}
PUBLIC LBLvlparc, Wvlparc := 0, Ovlparc
PUBLIC LBLdtvecto, Wdtvecto := date(), Odtvecto
PUBLIC LBLvlrpgto, Wvlrpgto := 0, Ovlrpgto
PUBLIC LBLdtpgto, Wdtpgto := date(), Odtpgto
PUBLIC LBLvltotal, Wvltotal := 0, Ovltotal
PUBLIC LBLdescricao, Wdescricao := "", Odescricao
PUBLIC LBLtipo, Wtipo := "", Otipo ,r1 := 2
PUBLIC LBLsituacao, Wsituacao := "A", Osituacao
PUBLIC LBLbanco, Wbanco:="", Obanco
PUBLIC LBLagencia, Wagencia:="", Oagencia, aItens3:={}
PUBLIC LBLcc, Wcc:="", Occ 
PUBLIC Lmora, Wmora:=0, Omora
PUBLIC Lmulta, Wmulta:=0, Omulta
PUBLIC Lobs2, Wobs2:="", Oobs2
PUBLIC Lobs3, Wobs3:="", Oobs3
*************VARIAVEIS********************

PARA TIPOCAD

dbcloseall()

IF Use_Arq("ASSOCI",,.T.,.F.,.F.)=.F.
   Return
ENDIF

IF Use_Arq("MENSAL",,.T.,.F.,.F.)=.F.
   Return
ENDIF

IF Use_Arq("BANCO",,.T.,.F.,.F.)=.F.
   Return
ENDIF

SELE ASSOCI
DBGOTOP()
IF EOF()
   MsgInfo("Você deve Primeiro Cadastrar um Associado","Aviso do Sistema")
ENDIF

DO WHILE !eof()
   vNOME=NOME
   aadd(aItens2,vNOME)
   dbskip()
ENDDO

SELECT BANCO
DBGOTOP()
DO WHILE !eof()
   vBANCO=DESCRICAO
   aadd(aItens3,vBANCO)
   dbskip()
ENDDO

SELECT MENSAL
DBSETORDER(1)
dbgotop()
IF TIPOCAD="C"
   goto LASTREC()
   IF DELETE()
      Wcodigo=CODIGO
   ENDIF
   IF !DELETE()
      Wcodigo=CODIGO+1
   ENDIF
ELSE
   IF TIPOCAD="P"
      DBSETORDER(2)
   else
      DBSETORDER(5)// SOMENTE O QUE TIVER EM ABERTO PARA PAGAR QUE PODE SER ALTERADO
   endif
   dbgotop()
   Wcodigo=0
   ********************************************************
   NAVEGAR("Pesquisa de Mensalidade","MENSAL","PESQ_MENSAL")
   ********************************************************
   WCodigo=CODIGO
   SELECT MENSAL
   DBSETORDER(1)
   DBSEEK(Wcodigo)
   IF found()
      wCODIGO   = CODIGO
      wPARCELA  = PARCELA
      wDATAEMI  = DATAEMI
      wHORAEMI  = HORAEMI
      wCODASS   = CODASS
      wNOME     = NOME
      wVLPARC   = VLPARC
      wDTVECTO  = DTVECTO
      wVLRPGTO  = VLRPGTO
      wDTPGTO   = DTPGTO
      wVLTOTAL  = VLTOTAL
      wDESCRICAO= DESCRICAO
      wTIPO     = TIPO
      wSITUACAO = SITUACAO
      wBANCO    = BANCO
         wAGENCIA  = AGENCIA
         wCC       = CC
         wMORA     = MORA
         wMULTA    = MULTA
         wOBS2     = OBS2
         wOBS3     = OBS3
   ELSE
      Erroreg()
      DBCLOSEALL()
      RETURN nil
   ENDIF
ENDIF
IF TIPOCAD="P"
   DBCLOSEALL()
   RETURN nil
ENDIF

IF TIPOCAD="C"
   PREPARE FONT oFont NAME "Arial" WIDTH 0 HEIGHT -12 WEIGHT 400
   INIT DIALOG oCadmensal CLIPPER NOEXIT TITLE "Cadastro de Mensalidade";
   AT 0,0 SIZE 750,300;
   ICON  oIcon ;
   FONT oFont ;
   STYLE DS_CENTER + WS_VISIBLE + WS_CAPTION + WS_SYSMENU

   SetColorinFocus( .t. )

   @ 5,5     GROUPBOX grpConfiguracao          CAPTION "Dados da Mensalidade"      SIZE 740,290

   @ 115,20  GROUPBOX grpTipo                  CAPTION "Tipo"                      SIZE 165,45

   ****INICO DOS SAYS***
   @ 10 ,40  SAY LBLcodigo                     CAPTION "Codigo:"                   SIZE 100,22
   @ 420,40  SAY LBLdataemi                    CAPTION "Data:"                     SIZE 168,22
   @ 555,40  SAY LBLhoraemi                    CAPTION "Hora:"                     SIZE 168,22 
   @ 10 ,70  SAY LBLnome                       CAPTION "Nome Associado:"           SIZE 168,22
   @ 420,70  SAY LBLbanco                      CAPTION "Banco:"                    SIZE 168,22   
   @ 10 ,100 SAY LBLvltotal                    CAPTION "Valor Total R$:"           SIZE 168,22
   @ 220,100 SAY LBLparcela                    CAPTION "Quantidade Parcelas:"      SIZE 168,22
   @ 420,100 SAY Lmora                         CAPTION "Percentual de Mora % : "   SIZE 168,22
   @ 615,100 SAY Lmulta                        CAPTION "Multa % : "   SIZE 50,22
   @ 10 ,130 SAY LBLdescricao                  CAPTION "Descrição.....:"           SIZE 168,22
   @ 10 ,160 SAY Lobs2                         CAPTION "Obs. Boleto..:"           SIZE 168,22
   @ 10 ,190 SAY Lobs2                         CAPTION "Obs. Boleto..:"           SIZE 168,22
   ****FIM DOS SAYS***

   ****INCIO DOS GETS***
   @ 60,40   GET Ocodigo VAR Wcodigo           PICTURE "99999"  COLOR 255          SIZE 50,22 STYLE WS_DISABLED;
   TOOLTIP "Informe o Codigo"

   GET RADIOGROUP r1
   @ 130,40 RADIOBUTTON oRadio1 caption "Avulso"  ;
   TOOLTIP "Selecione essa Opção para Geração de Mensalidades Avulsa";
   SIZE 60, 20;
   ON CLICK {|| wPARCELA := 1, oPARCELA:Refresh(), Oparcela:disable()}

   @ 210,40 RADIOBUTTON oRadio2 caption "Carne" ;   
   TOOLTIP "Selecione essa Opção para Geração de Mensalidades em Carne";
   SIZE 55, 20;
   ON CLICK {|| Oparcela:Enable()}
   END RADIOGROUP   

   @ 455,40  GET DATEPICKER Odataemi VAR Wdataemi                               SIZE 90,22;
   TOOLTIP "Informe a Data de Emissão"

   @ 590,40  GET Ohoraemi VAR Whoraemi      PICTURE "@T"                        SIZE 80,22;
   TOOLTIP "Informe a Hora de Emissão"

   @ 115,70  GET COMBOBOX Onome VAR Wnome   ITEMS aItens2                       SIZE 300,22 TEXT;
   TOOLTIP "Informe o Nome do Associado";
   ON CHANGE { || Busca_dados(Wnome) }

   @ 460,70  GET COMBOBOX Obanco VAR Wbanco ITEMS aItens3                       SIZE 210,22 TEXT;
   TOOLTIP "Informe o Nome do Banco";
   ON CHANGE { || Busca_banco(Wbanco) }

   @ 100,100 GET Ovltotal VAR Wvltotal      PICTURE "@e 999,999,999.99"         SIZE 100,22;
   TOOLTIP "Informe o Valor Total"

   @ 350,100 GET Oparcela VAR Wparcela      PICTURE "999"   SIZE 50,22;
   TOOLTIP "Informe a quantidade de Parcelas"

   @ 550,100 GET Omora VAR Wmora            PICTURE "@R 999.99"   SIZE 50,22;
   TOOLTIP "Informe o Percentual de Mora em Cada Boleto"

   @ 670,100 GET Omulta VAR Wmulta          PICTURE "@R 999.99"   SIZE 50,22;
   TOOLTIP "Informe o Percentual de Multa de Atraso em cada Boleto"

   @ 100,130 GET Odescricao VAR Wdescricao  PICTURE "@!"              SIZE 500,22;
   MAXLENGTH 50;
   TOOLTIP "Informe alguma descrição sobre as Parcelas"

   @ 100,160 GET Oobs2 VAR Wobs2  PICTURE "@!"              SIZE 500,22;
   MAXLENGTH 50;
   TOOLTIP "Informe alguma descrição para constar nos boletos bancario"

   @ 100,190 GET Oobs3 VAR Wobs3  PICTURE "@!"  VALID {||Focaliza()}  SIZE 500,22;
   MAXLENGTH 50;
   TOOLTIP "Informe alguma descrição para constar nos boletos bancario"
   ****FIM DOS GETS***

   @ 410,240 BUTTON btnok CAPTION "&Gerar" SIZE 100, 28 ;
   TOOLTIP "Gerar Parcelas" ;
   ON CLICK {|| Grava_mensal(),Monta_Browse() };
   STYLE WS_TABSTOP

   @ 520,240  BUTTON oBTNlimpa CAPTION "&Limpar" SIZE 100, 28 ;
   TOOLTIP "Limpar Dados Atuais";
   ON CLICK {|| limpa_var4() };
   STYLE WS_TABSTOP

   @ 630,240  BUTTON oBTNfexa CAPTION "&Fechar" SIZE 100, 28 ;
   TOOLTIP "Sair do Modulo de Cadastro";
   ON CLICK {|| dbcloseall(),oCadmensal:Close() };
   STYLE WS_TABSTOP

WriteStatus( oTelaPrincipal,3,"Cadastro de Mensalidades" )
   ACTIVATE DIALOG oCadmensal
WriteStatus( oTelaPrincipal,3,"Area de Trabalho" )   
   
ELSE
   Monta_Browse()
ENDIF

RETURN nil

********************************************************************************
FUNCTION Busca_dados(wnome)
********************************************************************************
SELECT ASSOCI
DBGOTOP()
DBSETORDER(2)
DBSEEK(wnome)
Wvltotal=valor
wDTVECTO=venc
RETURN

********************************************************************************
FUNCTION Busca_dados2(wassociado)
********************************************************************************
DBGOTOP()
DBSETORDER(2)
DBSEEK(wassociado)
RETURN

********************************************************************************
FUNCTION Busca_banco(wbanco)
********************************************************************************
SELECT BANCO
DBGOTOP()
DBSETORDER(2)
DBSEEK(wbanco)
Wagencia = AGENCIA
Wcc      = CC
RETURN

********************************************************************************
FUNCTION Grava_Mensal()
********************************************************************************
SELECT MENSAL
IF EMPTY(Wnome)
   OBRIGA()
   oNome:setfocus()
    RETURN
ENDIF

IF wVLTOTAL=0
   OBRIGA()
   Ovltotal:setfocus()
    RETURN
ENDIF

IF wParcela=0
   OBRIGA()
   Oparcela:setfocus()
    RETURN
ENDIF

IF STR(r1,1)="1"
   wTIPO="Avulso"
else
   wTIPO="Carne"
Endif

vDIF=0
wVLPARC=wVLTOTAL/Wparcela
wTOTAL2=round(wVLPARC,2)*Wparcela
vDIF=wVLTOTAL-wTOTAL2
wDATAaux=wDATAEMI+30
 
SELECT ASSOCI
DBGOTOP()
DBSETORDER(2)
DBSEEK(wNOME)
wCODASS = CODASSOC

SELECT MENSAL

FOR i := 1 TO Wparcela
    AppRede()
    REPLACE CODIGO WITH Wcodigo,;
    NOME      WITH wNOME,;   
    PARCELA   WITH i,;   
    DATAEMI   WITH wDATAEMI,;   
    HORAEMI   WITH wHORAEMI,;   
    CODASS    WITH wCODASS,;    
    VLPARC    WITH wVLPARC+vDif,;
    DTVECTO   WITH wDATAaux,;
    VLTOTAL   WITH wVLTOTAL,;
    DESCRICAO WITH wDESCRICAO,;
    TIPO      WITH wTIPO,;      
    SITUACAO  WITH wSITUACAO,;
    BANCO     WITH wBANCO,;
    AGENCIA   WITH wAGENCIA,;
    CC        WITH wCC,;
    MORA      WITH wMORA,;
    MULTA     WITH wMULTA,;
    OBS2      WITH wOBS2,;
    OBS3      WITH wOBS3

    wDATAaux=wDATAaux+LastDayoM(wDATAaux)
    vDif=0               
NEXT
DBCOMMIT()
DBUNLOCK()
Oradio1:disable()
Oradio2:disable()
Odataemi:disable()
Ohoraemi:disable()
Onome:disable()
Ovltotal:disable()
Oparcela:disable()
btnok:disable()
oBTNlimpa:disable()
oBTNfexa:disable()
oCadmensal:Close()
RETURN

***********************
FUNCTION Monta_Browse()
***********************
LOCAL oFont
Local oBrw
Local oFrm
PRIVATE oIcon := HIcon():AddResource(1004)
*** FERRAMENTAS DE MULTI-PESQUISA AUTOMATICA
aCHAVES := {}
nORD    := INDEXORD()
nCNT    := 1
nMAXLEN := 0
IF nORD # 0
   DO WHILE .T.
      IF !EMPTY( INDEXKEY(nCNT) )
         aADD(aCHAVES," "+INDEXKEY(nCNT)+" ")
         nCNT++
      ELSE
         EXIT
      ENDIF
   ENDDO
   aEVAL(aCHAVES, {|cV,nV| IF( LEN( aCHAVES[nV] ) > nMAXLEN,;
                   nMAXLEN := LEN( aCHAVES[nV] ), NIL ) })
ENDIF
DBSETORDER(nORD)

TIPOCAD="A"

PREPARE FONT oFont NAME "Arial" WIDTH 0 HEIGHT -12 WEIGHT 400

INIT DIALOG oFrm TITLE "Cadastrar / Alterar Parcelas";
AT 0,0 SIZE 750,550 CLIPPER NOEXIT ;
ICON  oIcon ;
FONT oFont ;
STYLE DS_CENTER + WS_VISIBLE + WS_CAPTION + WS_SYSMENU

SetColorinFocus( .t. )

@ 5,5     GROUPBOX grpConfiguracao          CAPTION "Dados da Mensalidade"      SIZE 740,130

@ 115,20  GROUPBOX grpTipo                  CAPTION "Tipo"                      SIZE 165,45

****INICO DOS SAYS***
   @ 10,40   SAY LBLcodigo                     CAPTION "Codigo:"                   SIZE 100,22
   @ 420,40  SAY LBLdataemi                    CAPTION "Data:"                     SIZE 168,22
   @ 555,40  SAY LBLhoraemi                    CAPTION "Hora:"                     SIZE 168,22 
   @ 10,70   SAY LBLnome                       CAPTION "Nome Associado:"           SIZE 168,22
   @ 420,70  SAY LBLbanco                      CAPTION "Banco:"                    SIZE 168,22
   @ 10,100  SAY LBLvltotal                    CAPTION "Valor Total R$:"           SIZE 168,22
   @ 220,100 SAY LBLparcela                    CAPTION "Quantidade Parcelas:"      SIZE 168,22
****FIM DOS SAYS***

****INICIO GETS****
   @ 60,40   GET Ocodigo  VAR Wcodigo       PICTURE "99999"  COLOR 255          SIZE 50,22  STYLE WS_DISABLED
   @ 160,40  GET Otipo    VAR Wtipo         COLOR 255                           SIZE 60,22  STYLE WS_DISABLED
   @ 455,40  GET Odataemi VAR Wdataemi      PICTURE "@D"                        SIZE 80,22  STYLE WS_DISABLED
   @ 590,40  GET Ohoraemi VAR Whoraemi      PICTURE "@T"                        SIZE 80,22  STYLE WS_DISABLED
   @ 115,70  GET Onome    VAR Wnome         COLOR 255                           SIZE 300,22 STYLE WS_DISABLED
   @ 460,70  GET Obanco   VAR Wbanco        COLOR 255                           SIZE 210,22 STYLE WS_DISABLED
   @ 100,100 GET Ovltotal VAR Wvltotal      PICTURE "@e 999,999,999.99"         SIZE 100,22 STYLE WS_DISABLED
   @ 350,100 GET Oparcela VAR Wparcela      PICTURE "999"                       SIZE 50,22  STYLE WS_DISABLED
****FIM GETS******* 

***INICIO DOS BOTOES***
@ 410,100 BUTTON oButton1 CAPTION "&Gerar" SIZE 100, 28 ;
TOOLTIP "Gerar Parcelas" ;
STYLE WS_DISABLED

@ 520,100  BUTTON oButton2 CAPTION "&Limpar" SIZE 100, 28 ;
TOOLTIP "Limpar Dados Atuais";
STYLE WS_DISABLED

@ 630,100  BUTTON oButton3 CAPTION "&Fechar" SIZE 100, 28 ;
TOOLTIP "Sair do Modulo de Cadastro";
STYLE WS_DISABLED

@ 20,470  BUTTON btnOk CAPTION "&Incluir" SIZE 100, 28 ;
TOOLTIP "Incluir Nova Parcela";
ON CLICK {|| TELA2("C"),oBrw:Refresh() };
STYLE WS_TABSTOP

@ 130,470  BUTTON "&Alterar" SIZE 100, 28 ;
TOOLTIP "Alterar Parcela";
ON CLICK {|| TELA2("A"),oBrw:Refresh(),ovltotal:refresh() };
STYLE WS_TABSTOP

@ 240,470  BUTTON "&Excluir" SIZE 100, 28 ;
TOOLTIP "Excluir Parcela";
ON CLICK {|| Tela2("D"),oBrw:Refresh() };
STYLE WS_TABSTOP

@ 350,470  BUTTON "&Receber" SIZE 100, 28 ;
TOOLTIP "Receber Parcela";
ON CLICK {|| Tela3(),oBrw:Refresh() };
STYLE WS_TABSTOP

@ 460,470  BUTTON "&Imprimir Carne" SIZE 130, 28 ;
TOOLTIP "Imprime todas as parcelas do Carne";
ON CLICK {||Reimprime(), oFrm:Close() };
STYLE WS_TABSTOP

@ 630,470  BUTTON "&Fechar" SIZE 100, 28 ;
TOOLTIP "Sair do Modulo de Cadastro";
ON CLICK {|| dbcloseall(),oFrm:Close() };
STYLE WS_TABSTOP
***FIM DOS BOTOES***

***INICIO DO FILTRO***
Atual_filtro()
***FIM DO FILTRO***

@ 10,150 BROWSE oBrw DATABASE of oFrm SIZE 730,310 ;
         STYLE  WS_VSCROLL + WS_HSCROLL;
         MULTISELECT;
         ON CLICK {|o,key| BrowseKey2(o, key ) }
//         ON getfocus {|| oBrw:Refresh(),DBGOTOP() };

oBrw:alias := aLIAS()                                

oBrw:bKeyDown := {|o,key| BrowseKey2(o, key ) }

@ 5,510 say "[ C ] - Cadastrar  [ A ] - Alterar  [ DEL ] - Excluir  [ F1 ] - Sobre  [ F5 ] - Gera Excel  [ F9 ] - Calculadora" size 740,22;
STYLE SS_CENTER COLOR x_BLUE          
                                               
   oBrw:AddColumn( HColumn():New( "Cod Nº",         FieldBlock(Fieldname(1)),"N",   6,0) )
   oBrw:AddColumn( HColumn():New( "Parc",           FieldBlock(Fieldname(2)),"N",   3,0) )
   oBrw:AddColumn( HColumn():New( "Nome Associado", FieldBlock(Fieldname(7)),"C",  50,0) )
   oBrw:AddColumn( HColumn():New( "Parcela R$:",    FieldBlock(Fieldname(8)),"N",  10,2) )
   oBrw:AddColumn( HColumn():New( "Vencimento",     FieldBlock(Fieldname(9)),"D",  10,0) )
   oBrw:AddColumn( HColumn():New( "Pago R$:",       FieldBlock(Fieldname(10)),"N", 10,2) )
   oBrw:AddColumn( HColumn():New( "Data Pgto.",     FieldBlock(Fieldname(11)),"D", 10,0) )
   oBrw:AddColumn( HColumn():New( "Total R$:",      FieldBlock(Fieldname(12)),"N", 10,2) )
   oBrw:AddColumn( HColumn():New( "Tipo",           FieldBlock(Fieldname(14)),"C",  6,0) )
   oBrw:AddColumn( HColumn():New( "Banco",          FieldBlock(Fieldname(16)),"C", 31,0) )
   oBrw:AddColumn( HColumn():New( "Agencia",        FieldBlock(Fieldname(17)),"C",  5,0) )
   oBrw:AddColumn( HColumn():New( "Conta",          FieldBlock(Fieldname(18)),"C", 12,0) )
   oBrw:AddColumn( HColumn():New( "Descrição",      FieldBlock(Fieldname(13)),"C", 50,0) )

   oBrw:aColumns[3]:length := 50 // TAMANHO
   oBrw:aColumns[9]:length := 6  // TAMANHO
   oBrw:aColumns[10]:length:= 55 // TAMANHO

   oBrw:Freeze:=2                // CONGELA

   oBrw:aColumns[4]:picture:="@R 999,999,999.99"
   oBrw:aColumns[6]:picture:="@R 999,999,999.99"
   oBrw:aColumns[8]:picture:="@R 999,999,999.99"

   FOR nI := 1 TO 13
       oBrw:aColumns[nI]:bColorBlock := {|| IF(MENSAL->VLRPGTO > 0, {x_BLUE,  x_WHITE, x_CYAN, x_DARKBLUE} ,;
                                            IF(MENSAL->VLRPGTO = 0, {x_RED ,  x_WHITE, x_CYAN, x_DARKBLUE} , {x_BLACK, x_WHITE , x_WHITE, x_DARKBLUE } ) ) }
   NEXT

oBrw:Refresh()
oBrw:SetFocus()
setfocus(obrw)

oFrm:bActivate := {||oBrw:SetFocus(),Atual_filtro()}

WriteStatus( oTelaPrincipal,3,"Alteração de Mensalidades" )
oFrm:Activate()
WriteStatus( oTelaPrincipal,3,"Area de Trabalho" )

RETURN nil

*********************
FUNCTION Atual_filtro
*********************
SELE MENSAL
dbsetorder(1)
ORDScope(0, Wcodigo)
ORDScope(1, Wcodigo)
dbgotop()
COUNT FOR CODIGO=Wcodigo TO Wparcela
SUM ALL VLPARC to TTOT for codigo=Wcodigo

wVLTOTAL:= TTOT
oVLTOTAL:Refresh()
oVLTOTAL:setfocus()
Ovltotal:disable()
dbgotop()

RETURN

********************************************************************************
FUNCTION BrowseKey2( oBrowse, key)
********************************************************************************
DO CASE
   CASE KEY= VK_ESCAPE
        EndDialog()
   CASE KEY = VK_F1
        Sobre()
   CASE KEY = VK_F2
        BUSCA_NOME()
   CASE KEY = VK_F4
        Lista_ordem()
   CASE KEY = VK_F9
        ShellExecute("calc")
   OTHERWISE
   if  key=13 .OR. key=65
       Tela2("A")
   elseif key=46
       Tela2("D")
   elseif key=67
       Tela2("C")
   ENDIF
ENDCASE

RETURN .T.

********************************************************************************
FUNCTION BrowseKey3( oBrowse, key)
********************************************************************************
DO CASE
   CASE KEY= VK_ESCAPE
        EndDialog()
   CASE KEY = VK_F1
        Sobre()
   CASE KEY = VK_F2
        BUSCA_NOME()
   CASE KEY = VK_F9
        ShellExecute("calc")
ENDCASE

RETURN .T.

****************
FUNCTION Tela2()
****************
PRIVATE oAltParc
PRIVATE LBLtipo2
PRIVATE LBLvlparcela, Wvlparcela := 0,  Ovlparcela
PRIVATE LBLnumparc,   Wnumparc := 0,    Onumparc
PRIVATE LBLvenc2,     Wvenc2 := date(), Ovenc2
PRIVATE LBLdescricao, Wdescricao := "", Odescricao

PARA TIPO_CAD

IF TIPO_CAD="A" .OR. TIPO_CAD="D"
   Wvlparcela=Vlparc
   Wnumparc=PARCELA
   Wvenc2=DTVECTO
   Wdescricao=descricao
   Wsituacao=situacao
   if Wsituacao="P"
      MsgInfo("O Sistema não aceita Alteração de Parcela Quitada","Aviso do Sistema")
      Return nil
   endif
   IF Wnumparc=0
      Return Nil
   ENDIF
ENDIF

PREPARE FONT oFont NAME "Arial" WIDTH 0 HEIGHT -12 WEIGHT 400
INIT DIALOG oAltParc CLIPPER NOEXIT TITLE "Alteração de Parcela";
AT 0,0 SIZE 600,300;
ICON  oIcon ;
FONT oFont ;
STYLE DS_CENTER + WS_VISIBLE + WS_CAPTION + WS_SYSMENU

*********
COUNT FOR CODIGO=Wcodigo TO Wparcela
@ 10,40   SAY LBLcodigo                     CAPTION "Codigo:"                   SIZE 100,22
@ 130,40  SAY LBLtipo2                      CAPTION "Tipo:"                     SIZE 100,22
@ 290,40  SAY LBLdataemi                    CAPTION "Data:"                     SIZE 168,22
@ 420,40  SAY LBLhoraemi                    CAPTION "Hora:"                     SIZE 168,22
@ 10,70   SAY LBLnome                       CAPTION "Nome Associado:"           SIZE 168,22
@ 10,100  SAY LBLparcela                    CAPTION "Total Parcelas:"           SIZE 168,22
@ 10,130  SAY LBLnumparc                    CAPTION "Numero da Parcela.:"       SIZE 168,22
@ 10,160  SAY LBLbanco                      CAPTION "Banco.:"                   SIZE 168,22
@ 280,160 SAY LBLagencia                    CAPTION "Agencia.:"                 SIZE 168,22
@ 410,160 SAY LBLcc                         CAPTION "C.C.:"                     SIZE 168,22             
@ 10,190  SAY LBLvenc2                      CAPTION "Data De Vencimento:"       SIZE 168,22
@ 260,190 SAY LBLvlparcela                  CAPTION "Valor Da Parcela R$:"      SIZE 168,22
@ 10,220  SAY LBLdescricao                  CAPTION "Descrição / Obs...:"       SIZE 168,22
*********
@ 60,40   GET Ocodigo  VAR Wcodigo          PICTURE "999999"  COLOR 255         SIZE 50,22  STYLE WS_DISABLED
@ 160,40  GET Otipo    VAR Wtipo            COLOR 255                           SIZE 60,22  STYLE WS_DISABLED
@ 330,40  GET Odataemi VAR Wdataemi         PICTURE "@D"                        SIZE 80,22  STYLE WS_DISABLED
@ 460,40  GET Ohoraemi VAR Whoraemi         PICTURE "@T"                        SIZE 80,22  STYLE WS_DISABLED
@ 115,70  GET Onome    VAR Wnome            COLOR 255                           SIZE 300,22 STYLE WS_DISABLED
@ 115,100 GET Oparcela VAR Wparcela         PICTURE "999"                       SIZE 50,22  STYLE WS_DISABLED
@ 130,130 GET Onumparc VAR Wnumparc         PICTURE "999"                       SIZE 50,22  STYLE WS_DISABLED
@ 60,160  GET Obanco   VAR Wbanco           COLOR 255                           SIZE 210,22 STYLE WS_DISABLED
@ 340,160 GET Oagencia VAR Wagencia         PICTURE "@R"                        SIZE 60,22  STYLE WS_DISABLED
@ 440,160 GET Occ      VAR Wcc              PICTURE "@R"                        SIZE 60,22  STYLE WS_DISABLED

IF TIPO_CAD="A" .OR. TIPO_CAD="C"
   @ 130,190 GET DATEPICKER Ovenc2 VAR Wvenc2                                   SIZE 100,22;
   TOOLTIP "Informe a Data de Vencimento"

   @ 380,190 GET Ovlparcela VAR Wvlparcela     PICTURE "@e 999,999.99"          SIZE 100,22;
   TOOLTIP "Informe o Valor da Parcela"

   @ 130,220 GET Odescricao VAR Wdescricao     PICTURE Replicate("X",50) VALID {||Focaliza()} SIZE 450,22;
   TOOLTIP "Informe alguma Observação"

   @ 100,250 BUTTON btnOk CAPTION "&Salvar"   ;
   TOOLTIP "Salvar Parcela";
   SIZE 100,32 ON CLICK {||Grava_Parc()} STYLE WS_TABSTOP
ELSE
   @ 130,190 GET DATEPICKER Ovenc2 VAR Wvenc2                                   SIZE 100,22 STYLE WS_DISABLED
   @ 380,190 GET Ovlparcela VAR Wvlparcela     PICTURE "@e 999,999.99"          SIZE 100,22 STYLE WS_DISABLED
   @ 130,220 GET Odescricao VAR Wdescricao     PICTURE Replicate("X",50)        SIZE 450,22 STYLE WS_DISABLED

   @ 100,250 BUTTON btnOk CAPTION "&Excluir"   ;
   TOOLTIP "Excluir Parcela";
   SIZE 100,32 ON CLICK {||Grava_Parc() } STYLE WS_TABSTOP
ENDIF
*********
@ 400,250 BUTTON OBTN2 CAPTION "&Voltar"   ;
TOOLTIP "Voltar Sem Salvar a Parcela";
SIZE 100,32 ON CLICK {||oAltParc:close()} STYLE WS_TABSTOP

WriteStatus( oTelaPrincipal,3,"Alteração de Parcela" )
oAltParc:Activate()
WriteStatus( oTelaPrincipal,3,"Area de Trabalho" )

RETURN nil

*********************
FUNCTION Grava_Parc()
*********************
SELE MENSAL
IF TIPO_CAD="C"
   IF Wvlparcela=0
      OBRIGA()
      Ovlparcela:setfocus()
       RETURN
   ENDIF

   Apprede()
   REPL CODIGO WITH Wcodigo,;
   NOME        WITH wNOME,;
   PARCELA     WITH Wparcela+1,;
   DATAEMI     WITH DATE(),;
   HORAEMI     WITH TIME(),;
   CODASS      WITH wCODASS,;
   VLPARC      WITH Wvlparcela,;
   DTVECTO     WITH Wvenc2,;
   VLTOTAL     WITH wVLTOTAL,;
   DESCRICAO   WITH wDESCRICAO,;
   TIPO        WITH wTIPO,;
   BANCO       WITH wBANCO,;
   AGENCIA     WITH wAGENCIA,;
   CC          WITH wCC,;
   SITUACAO    WITH "A"
   DBCOMMIT()
   DBUNLOCK()
ELSEIF TIPO_CAD="A"
   MSGINFO(str(Wcodigo)+str(Wnumparc))
   SELE MENSAL
   DBSETORDER(1)
   ORDScope(0,Wcodigo)
   ORDScope(1,Wcodigo)

   LOCATE FOR CODIGO=Wcodigo .AND. PARCELA=Wnumparc
   IF FOUND()
      TRAVAREG()
      REPL DTVECTO WITH Wvenc2,;
      VLPARC       WITH Wvlparcela,;
      DESCRICAO    WITH Wdescricao
      DBCOMMIT()
      LIBERAREG()
   ELSE
      MSGINFO("PROBLEMA")
   ENDIF
ELSEIF TIPO_CAD="D"
   DBGOTOP()
   DBSETORDER(6)
   DBSEEK(str(Wcodigo)+str(Wnumparc))
   TRAVAREG()
   dele
   LIBERAREG()
ENDIF

DBGOTOP()
SUM ALL VLPARC to TTOT for codigo=Wcodigo
DBSETORDER(1)
DBSEEK(Wcodigo)
IF FLOCK()
   REPL ALL VLTOTAL WITH TTOT
   DBUNLOCK()
   DBCOMMIT()
ENDIF

Atual_filtro()
oAltParc:close()

RETURN


********************************************************************************
FUNCTION Filtro_REC()
***********************
SELE MENSAL
dbsetorder(4)
ORDScope(0,"P")
ORDScope(1,"P")
dbgotop()
COUNT FOR SITUACAO="P" TO vCont

RETURN

********************************************************************************
FUNCTION Filtro_aREC()
***********************
SELE MENSAL
dbsetorder(4)
ORDScope(0,"A")
ORDScope(1,"A")
dbgotop()
COUNT FOR SITUACAO="A" TO vCont

RETURN

***************************************************************************
FUNCTION Grava_Pgto()
********************************************************************************
IF wVLPGTO > Wvlparcela
   MSGINFO("Valor Maior que o Total da Parcela","Aviso do Sistema")
   oAltParc:close()
   Monta_Browse()
ELSEIF  wVLPGTO < Wvlparcela
   MSGINFO("Valor Menor que o Total da Parcela","Aviso do Sistema")
   oAltParc:close()
     Monta_Browse()
ELSE
SELECT MENSAL
   DBGOTOP()
   DBSETORDER(6)
   DBSEEK(str(Wcodigo)+str(Wnumparc))
   TRAVAREG()
   REPLACE DTVECTO   WITH Wvenc2
   REPLACE VLRPGTO   WITH Wvlpgto
   REPLACE DTPGTO    WITH Wdtpgto
   REPLACE SITUACAO  WITH Wsituacao
   DBCOMMIT()
   DBUNLOCK()
   DBGOTOP()
   TTOT:= VLTOTAL - Wvlpgto

SUM ALL VLPARC to TTOT for CODIGO = Wcodigo
DBSETORDER(1)
DBSEEK(Wcodigo)
   IF FLOCK()
      REPLACE ALL VLTOTAL WITH TTOT
      DBUNLOCK()
      DBCOMMIT()
   ENDIF
Atual_filtro()
oAltParc:close()
ENDIF
RETURN

*******************************************************************************
FUNCTION Tela3()  //Tela de Pagamento
********************************************************************************
PRIVATE oAltParc
PRIVATE LBLtipo2, Wtipo, Otipo
PRIVATE LBLvlparcela, Wvlparcela := 0, Ovlparcela
PRIVATE LBLnumparc, Wnumparc := 0, Onumparc
PRIVATE LBLvenc2, Wvenc2 := date(), Ovenc2
PRIVATE LBLdescricao, Wdescricao := "", Odescricao
PRIVATE LBLdtpgto, Wdtpgto :=date(), Odtpgto
PRIVATE LBLvlpgto, Wvlpgto :=0, Ovlpgto
PRIVATE LBLbanco, Wbanco:="", Obanco
PRIVATE LBLagencia, Wagencia:=0, Oagencia
PRIVATE LBLcc, Wcc:=0, Occ
    
Wvlparcela = VLPARC
Wnumparc   = PARCELA
Wvenc2     = DTVECTO
Wdescricao = DESCRICAO
Wsituacao  = SITUACAO
Wcodigo    = CODIGO
Wdataemi   = DATAEMI
Whoraemi   = HORAEMI
Wnome      = NOME
Wvltotal   = VLTOTAL
Wvlparcela = VLPARC
Wdtpgto    = DTPGTO
Wvlgto     = VLRPGTO
Wbanco     = BANCO
Wagencia   = AGENCIA
Wcc        = CC

IF Wsituacao="P"
   MsgInfo("O Sistema não aceita Alteração de Parcela Quitada","Aviso do Sistema")
   RETURN nil 
ENDIF

PREPARE FONT oFont NAME "Arial" WIDTH 0 HEIGHT -12 WEIGHT 400
INIT DIALOG oAltParc CLIPPER NOEXIT TITLE "Quitação de Parcela";
AT 0,0 SIZE 600,330;
ICON  oIcon ;
FONT oFont ;
STYLE DS_CENTER + WS_VISIBLE + WS_CAPTION + WS_SYSMENU

COUNT FOR CODIGO=Wcodigo TO Wparcela       
Wsituacao:="P"
*********SAY's**********
@ 10,40   SAY LBLcodigo                     CAPTION "Codigo:"                   SIZE 100,22
@ 130,40  SAY LBLtipo2                      CAPTION "Tipo:"                     SIZE 100,22
@ 290,40  SAY LBLdataemi                    CAPTION "Data:"                     SIZE 168,22
@ 420,40  SAY LBLhoraemi                    CAPTION "Hora:"                     SIZE 168,22
@ 10,70   SAY LBLnome                       CAPTION "Nome Associado:"           SIZE 168,22
@ 10,100  SAY LBLvltotal                    CAPTION "Valor Total R$:"           SIZE 168,22
@ 220,100 SAY LBLparcela                    CAPTION "Quantidade Total de Parcelas:"  SIZE 168,22
@ 10,130  SAY LBLnumparc                    CAPTION "Numero da Parcela.:"       SIZE 168,22
@ 10,160  SAY LBLvenc2                      CAPTION "Data De Vencimento:"       SIZE 168,22
@ 260,160 SAY LBLvlparcela                  CAPTION "Valor Da Parcela R$:"      SIZE 168,22
@ 10,220  SAY LBLdescricao                  CAPTION "Descrição / Obs...:"       SIZE 168,22
@ 10,190  SAY LBLbanco                      CAPTION "Banco.:"                   SIZE 168,22
@ 280,190 SAY LBLagencia                    CAPTION "Agencia.:"                 SIZE 168,22
@ 410,190 SAY LBLcc                         CAPTION "C.C.:"                     SIZE 168,22             
@ 10,250  SAY LBLdtpgto                     CAPTION "Data do Pagamento:"        SIZE 168,22
@ 260,250 SAY LBLvlpgto                     CAPTION "Valor do pagamento:"       SIZE 168,22

**********GET's*********
@ 60,40   GET Ocodigo    VAR Wcodigo          PICTURE "99999"  COLOR 255        SIZE 50,22  STYLE WS_DISABLED
@ 160,40  GET Otipo      VAR Wtipo            COLOR 255                         SIZE 60,22  STYLE WS_DISABLED
@ 330,40  GET Odataemi   VAR Wdataemi         PICTURE "@D"                      SIZE 80,22  STYLE WS_DISABLED
@ 460,40  GET Ohoraemi   VAR Whoraemi         PICTURE "@T"                      SIZE 80,22  STYLE WS_DISABLED
@ 115,70  GET Onome      VAR Wnome            COLOR 255                         SIZE 300,22 STYLE WS_DISABLED
@ 100,100 GET Ovltotal   VAR Wvltotal         PICTURE "@e 999,999,999.99"       SIZE 100,22 STYLE WS_DISABLED
@ 400,100 GET Oparcela   VAR Wparcela         PICTURE "999"                     SIZE 50,22  STYLE WS_DISABLED
@ 130,130 GET Onumparc   VAR Wnumparc         PICTURE "999"                     SIZE 50,22  STYLE WS_DISABLED
@ 130,160 GET DATEPICKER Ovenc2 VAR Wvenc2                                      SIZE 100,22 STYLE WS_DISABLED
@ 380,160 GET Ovlparcela VAR Wvlparcela       PICTURE "@e 999,999.99"           SIZE 100,22 STYLE WS_DISABLED
@ 60,190  GET Obanco   VAR Wbanco           COLOR 255                           SIZE 210,22 STYLE WS_DISABLED
@ 340,190 GET Oagencia VAR Wagencia         PICTURE "@R"                        SIZE 60,22  STYLE WS_DISABLED
@ 440,190 GET Occ      VAR Wcc              PICTURE "@R"                        SIZE 60,22  STYLE WS_DISABLED
@ 130,220 GET Odescricao VAR Wdescricao       PICTURE Replicate("X",50)         SIZE 450,22 
@ 130,250 GET DATEPICKER Odtpagto   VAR Wdtpgto                                 SIZE 100,22
@ 380,250 GET Ovlpgto    VAR Wvlpgto          PICTURE "@e 999,999.99"           SIZE 100,22

@ 100,280 BUTTON btnOk CAPTION "&Receber"   ;
TOOLTIP "Receber Parcela";
SIZE 100,32 ON CLICK {||Grava_Pgto() } STYLE WS_TABSTOP

@ 400,280 BUTTON OBTN2 CAPTION "&Voltar"   ;
TOOLTIP "Voltar Sem Salvar a Parcela";
SIZE 100,32 ON CLICK {||oAltParc:close()} STYLE WS_TABSTOP

WriteStatus( oTelaPrincipal,3,"Quitação de Parcela" )
oAltParc:Activate()
WriteStatus( oTelaPrincipal,3,"Busca Parcela a Receber" )

RETURN nil


********************************************************************************
FUNCTION Limpa_Var4()
********************************************************************************
wPARCELA := 1
wDATAEMI := DATE()
wHORAEMI := TIME()
wNOME  :=""
wVLTOTAL := 0
r1 := 2
wMORA  :=0
wMULTA :=0
wOBS2  :=""
wOBS3  :=""

oPARCELA:Refresh()
oDATAEMI:Refresh()
oHORAEMI:Refresh()
oNOME:Refresh()
oVLTOTAL:Refresh()
oMORA:Refresh()
oMULTA:Refresh()
oOBS2:Refresh()
oOBS3:Refresh()
RETURN
********************************************************************************
********************************************************************************
FUNCTION Busca_parcASS()
********************************************************************************
PRIVATE oFRMparcass
PRIVATE LBLassociado, Wassociado := "", Oassociado, aItens3:={}
PRIVATE oFont :=NIL
PRIVATE oIcon := HIcon():AddResource(1004)
Wassociado:=Space(50)

DBCLOSEALL()

IF Use_Arq("MENSAL",,.T.,.F.,.F.)=.F.
   Return
ENDIF

IF Use_Arq("ASSOCI",,.T.,.F.,.F.)=.F.
   Return
ENDIF

SELECT ASSOCI
DBGOTOP()
do while !eof()
   vNOME=NOME
   aadd(aItens3,vNOME)
   dbskip()
Enddo

   PREPARE FONT oFont NAME "Arial" WIDTH 0 HEIGHT -12 WEIGHT 400 
   INIT DIALOG oFRMparcass CLIPPER NOEXIT TITLE "Sistema de Busca";
   SIZE 530,120;
   FONT oFont;
   ICON oIcon;
   STYLE DS_CENTER + WS_VISIBLE + WS_CAPTION + WS_SYSMENU

   @ 5,5     GROUPBOX grpConfiguracao          CAPTION "Pesquisa Associado"     SIZE 520,115

   @  10,40  SAY LBLassociado                   CAPTION "Nome Associado:"       SIZE 168,22
   @ 110,40  GET COMBOBOX Oassociado VAR wAssociado   ITEMS aItens3 COLOR 255   SIZE 400,22 EDIT;
   TOOLTIP "Informe o Nome que Deseja Buscar";
   ON CHANGE { || Busca_dados2(Wassociado) }


   @  300,70 BUTTON btnOk CAPTION "Pesquisar";
   ON CLICK {||Busca_assitua("PGTO"),EndDialog()};
   SIZE 100,32 STYLE WS_TABSTOP;
   TOOLTIP "Confirma a Busca"

   @ 410,70 BUTTON "Fechar";
   ON CLICK {||EndDialog()};
   SIZE 100,32;
   TOOLTIP "Fechar Janela"

WriteStatus( oTelaPrincipal,3,"Sistema de Busca" )
   ACTIVATE DIALOG oFRMparcass
WriteStatus( oTelaPrincipal,3,"Area de Trabalho" )

RETURN 

********************************************************************************
FUNCTION Busca_assitua()
********************************************************************************
LOCAL oFont
Local oBrw
Local oFrm
PRIVATE oIcon := HIcon():AddResource(1004)
PRIVATE LBLcodigo

PARA TIPOBUSCA

//---------------------Filtro

SELECT MENSAL
dbsetorder(7)
ORDScope(0, Wassociado)
ORDScope(1, Wassociado)
dbgotop()
COUNT FOR NOME=Wassociado TO vASSOCI
SUM ALL VLPARC to TTOT for NOME=Wassociado
//------------------------------------------

PREPARE FONT oFont NAME "Arial" WIDTH 0 HEIGHT -12 WEIGHT 400
INIT DIALOG oFrm TITLE "Receber Parcela";
AT 0,0 SIZE 750,550 CLIPPER NOEXIT ;
ICON  oIcon ;
FONT oFont ;
STYLE DS_CENTER + WS_VISIBLE + WS_CAPTION + WS_SYSMENU

SetColorinFocus( .t. )

@ 10,10 BROWSE oBrw DATABASE of oFrm SIZE 730,310 ;
         STYLE  WS_VSCROLL + WS_HSCROLL;
         ON getfocus {|| oBrw:Refresh(),DBGOTOP() };
         ON CLICK {|o,key| BrowseKey3(o, key ) }

oBrw:alias := aLIAS()                                

oBrw:bKeyDown := {|o,key| BrowseKey3(o, key ) }

@ 5,510 say "[ F1 ]-Sobre  [ F5 ]-Gera Excel  [ F9 ]-Calculadora" size 740,22;
STYLE SS_CENTER COLOR x_BLUE          
                                               
   oBrw:AddColumn( HColumn():New( "Cod Nº",          FieldBlock(Fieldname(1)),"N",  6,0) )
   oBrw:AddColumn( HColumn():New( "Parc",            FieldBlock(Fieldname(2)),"N",  3,0) )
   oBrw:AddColumn( HColumn():New( "Nome Associado",  FieldBlock(Fieldname(7)),"C", 50,0) )
   oBrw:AddColumn( HColumn():New( "Parcela R$:",     FieldBlock(Fieldname(8)),"N", 10,2) )
   oBrw:AddColumn( HColumn():New( "Vencimento",      FieldBlock(Fieldname(9)),"D", 10,0) )
   oBrw:AddColumn( HColumn():New( "Pago R$:",        FieldBlock(Fieldname(10)),"N",10,2) )
   oBrw:AddColumn( HColumn():New( "Data Pgto.",      FieldBlock(Fieldname(11)),"D",10,0) )
   oBrw:AddColumn( HColumn():New( "Total R$:",       FieldBlock(Fieldname(12)),"N",10,2) )
   oBrw:AddColumn( HColumn():New( "Tipo",            FieldBlock(Fieldname(14)),"C", 6,0) )
   oBrw:AddColumn( HColumn():New( "Banco",           FieldBlock(Fieldname(16)),"C",31,0) )
   oBrw:AddColumn( HColumn():New( "Agencia",         FieldBlock(Fieldname(17)),"C", 5,0) )
   oBrw:AddColumn( HColumn():New( "Conta",           FieldBlock(Fieldname(18)),"C",12,0) )
   oBrw:AddColumn( HColumn():New( "Descrição",       FieldBlock(Fieldname(13)),"C",50,0) )

   oBrw:aColumns[3]:length := 50 // TAMANHO
   oBrw:aColumns[9]:length := 6  // TAMANHO
   oBrw:aColumns[10]:length:= 55 // TAMANHO

   oBrw:Freeze:=2                // CONGELA

   oBrw:aColumns[4]:picture:="@R 999,999,999.99"
   oBrw:aColumns[6]:picture:="@R 999,999,999.99"
   oBrw:aColumns[8]:picture:="@R 999,999,999.99"

   FOR nI := 1 TO 13
       oBrw:aColumns[nI]:bColorBlock := {|| IF(MENSAL->VLRPGTO > 0, {x_BLUE,  x_WHITE, x_CYAN, x_DARKBLUE} ,;
                                            IF(MENSAL->VLRPGTO = 0, {x_RED ,  x_WHITE, x_CYAN, x_DARKBLUE} , {x_BLACK, x_WHITE , x_WHITE, x_DARKBLUE } ) ) }
   NEXT

oBrw:Refresh()
oBrw:SetFocus()
setfocus(obrw)

oFrm:bActivate := {||oBrw:SetFocus()}

IF TIPOBUSCA="PGTO"
   @ 20,470  BUTTON "&Receber" SIZE 100, 28 ;
   TOOLTIP "Receber Parcela";
   ON CLICK {|| TELA3(),oBrw:Refresh() };
   STYLE WS_TABSTOP

   WriteStatus( oTelaPrincipal,3,"Busca Parcela a Receber" )

ELSEIF TIPOBUSCA="REIMP"

   @ 20,470  BUTTON "&Receber" SIZE 100, 28 ;
   TOOLTIP "Receber Parcela";
   ON CLICK {|| TELA3(),oFrm:Close()};
   STYLE WS_DISABLED

   @ 130,470  BUTTON "&Reimprimir Carne" SIZE 130, 28 ;
   TOOLTIP "Reimprime todas as parcelas de um Carne";
   ON CLICK {||Reimprime("CARNE"), oFrm:Close() };
   STYLE WS_TABSTOP

   @ 270,470  BUTTON "&Reimprimir Parcela" SIZE 130, 28 ;
   TOOLTIP "Reimprime a parcela selecionada na grade";
   ON CLICK {||Reimprime("PARCELA"), oFrm:Close() };
   STYLE WS_TABSTOP

   WriteStatus(oTelaPrincipal,3,"Reimpressão de Mensalidades")

ENDIF

@ 630,470  BUTTON "&Fechar" SIZE 100, 28 ;
TOOLTIP "Sair do Modulo de Cadastro";
ON CLICK {||oFrm:Close() };
STYLE WS_TABSTOP


oFrm:Activate()
WriteStatus( oTelaPrincipal,3,"Area de Trabalho" )

RETURN

********************************************************************************
****************
FUNCTION Faturas
****************
LOCAL oFont
LOCAL oBrw
LOCAL oFRMfat
LOCAL LBLrec, LBLarec, GRPcontrole
PRIVATE vTOTALPG :=0, VLTOTAL:=0, VLTOTALAPG:=0  
PRIVATE oIcon := HIcon():AddResource(1004)
*** FERRAMENTAS DE MULTI-PESQUISA AUTOMATICA

PARA TIPOCAD

aCHAVES := {}
nORD    := INDEXORD()
nCNT    := 1
nMAXLEN := 0
IF nORD # 0
   DO WHILE .T.
      IF !EMPTY( INDEXKEY(nCNT) )
         aADD(aCHAVES," "+INDEXKEY(nCNT)+" ")
         nCNT++
      ELSE
         EXIT
      ENDIF
   ENDDO
   aEVAL(aCHAVES, {|cV,nV| IF( LEN( aCHAVES[nV] ) > nMAXLEN,;
                   nMAXLEN := LEN( aCHAVES[nV] ), NIL ) })
ENDIF

DBCLOSEALL()

IF Use_Arq("MENSAL",,.T.,.F.,.F.)=.F.
   Return
ENDIF

SELE MENSAL
SUM ALL VLPARC TO vTOTAL
SUM ALL VLRPGTO TO vTOTALPG FOR SITUACAO="P"
vTOTALAPG := vTOTAL - vTOTALPG

PREPARE FONT oFont NAME "Arial" WIDTH 0 HEIGHT -12 WEIGHT 400

INIT DIALOG oFRMfat CLIPPER NOEXIT TITLE "Controle das Parcelas";
AT 0,0 SIZE 750,520 ;
ICON  oIcon ;
FONT oFont ;
STYLE DS_CENTER + WS_VISIBLE + WS_CAPTION + WS_SYSMENU

***************FILTRO***********************************************************

IF TIPOCAD="A" 
   @ 5,370  GROUPBOX GRPcontrole   CAPTION "Valor Á Receber"  SIZE 740,100
   Filtro_aREC()//FILTRA MENSALIDADES A RECEBER
   @ 10,410 SAY LBLarec  CAPTION "A Receber : R$"+STR(vTOTALAPG) COLOR x_RED  SIZE 200,22
ELSEIF TIPOCAD="P"
   @ 5,370  GROUPBOX GRPcontrole   CAPTION "Valor Recebido"  SIZE 740,100
   Filtro_REC()//FILTRA MENSALIDADES RECEBIDAS
   @ 10,410 SAY LBLrec   CAPTION "Recebidas : R$"+STR(vTOTALPG) COLOR x_BLUE SIZE 200,22
ELSE
   @ 5,370  GROUPBOX GRPcontrole   CAPTION "Valor Recebido  x  A Receber"  SIZE 740,100
   @ 10,410 SAY LBLarec  CAPTION "A Receber : R$"+STR(vTOTALAPG) COLOR x_RED  SIZE 200,22
   @ 10,430 SAY LBLrec   CAPTION "Recebidas : R$"+STR(vTOTALPG) COLOR x_BLUE SIZE 200,22
ENDIF   
*******************************************

@ 10,20 BROWSE oBrw DATABASE of oFRMfat SIZE 730,310;
         STYLE  WS_VSCROLL + WS_HSCROLL;
         MULTISELECT;
         ON getfocus {|| oBrw:Refresh(),DBGOTOP() };
         ON CLICK {|o,key| BrowseKey3(o, key ) }

oBrw:alias := aLIAS()                                

oBrw:bKeyDown := {|o,key| BrowseKey3(o, key ) }

@ 5,340 say "[ F1 ]-Sobre  [ F5 ]-Gera Excel  [ F9 ]-Calculadora" size 740,22;
STYLE SS_CENTER COLOR x_BLUE
                                               
   oBrw:AddColumn( HColumn():New( "Cod Nº",          FieldBlock(Fieldname(1)), "N",  6,0) )
   oBrw:AddColumn( HColumn():New( "Parc",            FieldBlock(Fieldname(2)), "N",  3,0) )
   oBrw:AddColumn( HColumn():New( "Nome Associado",  FieldBlock(Fieldname(7)), "C", 50,0) )
   oBrw:AddColumn( HColumn():New( "Parcela R$:",     FieldBlock(Fieldname(8)),"N", 10,2) )
   oBrw:AddColumn( HColumn():New( "Vencimento",      FieldBlock(Fieldname(9)),"D", 10,0) )
   oBrw:AddColumn( HColumn():New( "Pago R$:",        FieldBlock(Fieldname(10)), "N", 10,2) )
   oBrw:AddColumn( HColumn():New( "Data Pgto.",      FieldBlock(Fieldname(11)),"D", 10,0) )
   oBrw:AddColumn( HColumn():New( "Total R$:",       FieldBlock(Fieldname(12)),"N", 10,2) )
   oBrw:AddColumn( HColumn():New( "Tipo",            FieldBlock(Fieldname(14)),"C",  6,0) )
   oBrw:AddColumn( HColumn():New( "Banco",           FieldBlock(Fieldname(16)),"C", 31,0) )
   oBrw:AddColumn( HColumn():New( "Descrição",       FieldBlock(Fieldname(13)),"C", 50,0) )

   oBrw:aColumns[3]:length := 50 // TAMANHO
   oBrw:aColumns[9]:length := 6  // TAMANHO
   oBrw:aColumns[10]:length:= 55 // TAMANH
   
   oBrw:Freeze:=2                // CONGELA

   oBrw:aColumns[4]:picture:="@R 999,999,999.99"
   oBrw:aColumns[6]:picture:="@R 999,999,999.99"
   oBrw:aColumns[8]:picture:="@R 999,999,999.99"

   FOR nI := 1 TO 10
       oBrw:aColumns[nI]:bColorBlock := {|| IF(MENSAL->VLRPGTO > 0, {x_BLUE,  x_WHITE, x_CYAN, x_DARKBLUE} ,;
                                            IF(MENSAL->VLRPGTO = 0, {x_RED ,  x_WHITE, x_CYAN, x_DARKBLUE} , {x_BLACK, x_WHITE , x_WHITE, x_DARKBLUE } ) ) }
   NEXT

oBrw:Refresh()
oBrw:SetFocus()
setfocus(obrw)

oFRMfat:bActivate := {||oBrw:SetFocus()}

   @ 310,480  BUTTON oBTNok CAPTION "&OK" SIZE 100, 28 ;
   TOOLTIP "Finaliza Visualização";
   ON CLICK {|| dbcloseall(),oFRMfat:Close() };
   STYLE WS_TABSTOP
   
WriteStatus( oTelaPrincipal,3,"Controle de Parcelas" )
oFRMfat:Activate() 
WriteStatus( oTelaPrincipal,3,"Area de Trabalho" )

RETURN nil
********************************************************************************
FUNCTION Reimp_carne()
********************************************************************************
PRIVATE oFRMreimp
PRIVATE LBLassociado, Wassociado := "", Oassociado, aItens3:={}
PRIVATE oFont :=NIL
PRIVATE oIcon := HIcon():AddResource(1004)
Wassociado:=Space(50)

DBCLOSEALL()

IF Use_Arq("MENSAL",,.T.,.F.,.F.)=.F.
   Return
ENDIF

IF Use_Arq("ASSOCI",,.T.,.F.,.F.)=.F.
   Return
ENDIF

SELE ASSOCI
DBGOTOP()
do while !eof()
   vNOME=NOME
   aadd(aItens3,vNOME)
   dbskip()
Enddo

   PREPARE FONT oFont NAME "Arial" WIDTH 0 HEIGHT -12 WEIGHT 400 
   INIT DIALOG oFRMreimp CLIPPER NOEXIT TITLE "Sistema de Busca";
   SIZE 530,120;
   FONT oFont;
   ICON oIcon;
   STYLE DS_CENTER + WS_VISIBLE + WS_CAPTION + WS_SYSMENU

   @   5,5   GROUPBOX grpConfiguracao          CAPTION "Pesquisa Associado"     SIZE 520,115

   @  10,40  SAY LBLassociado                   CAPTION "Nome Associado:"       SIZE 168,22
   @ 110,40  GET COMBOBOX Oassociado VAR wAssociado   ITEMS aItens3 COLOR 255   SIZE 400,22 EDIT;
     TOOLTIP "Informe o Nome que Deseja Buscar";
       ON CHANGE { || Busca_dados2(Wassociado) }


   @  300,70 BUTTON btnOk CAPTION "Pesquisar";
   ON CLICK {||Busca_assitua("REIMP"),EndDialog()};
   SIZE 100,32 STYLE WS_TABSTOP;
   TOOLTIP "Confirma a Busca"

   @ 410,70 BUTTON "Fechar";
   ON CLICK {||EndDialog()};
   SIZE 100,32;
   TOOLTIP "Fechar Janela"

WriteStatus( oTelaPrincipal,3,"Sistema de Busca" )
   ACTIVATE DIALOG oFRMreimp
WriteStatus( oTelaPrincipal,3,"Area de Trabalho" )

RETURN  

************************
FUNCTION Filtro_reimp()
************************
Wcodigo  = CODIGO
Wparcela = PARCELA

   dbsetorder(9)
   ORDScope(0,Wassociado+str(Wcodigo)+str(Wparcela))
   ORDScope(1,Wassociado+str(Wcodigo)+str(Wparcela))
   dbgotop()
   COUNT FOR NOME=Wassociado .AND. CODIGO=Wcodigo .AND. PARCELA=Wparcela TO Vcont

RETURN   

******************
FUNCTION Pesq_data
******************
PRIVATE oFRMpesqdata
PRIVATE oFont :=NIL
PRIVATE oIcon := HIcon():AddResource(1004)
PUBLIC LBLdata, Wdata := date(), Odata
PUBLIC LBLdata1, Wdata1 := date(), Odata1

DBCLOSEALL()

IF Use_Arq("MENSAL",,.T.,.F.,.F.)=.F.
   Return
ENDIF

   PREPARE FONT oFont NAME "Arial" WIDTH 0 HEIGHT -12 WEIGHT 400
   INIT DIALOG oFRMpesqdata CLIPPER NOEXIT TITLE "Sistema de Busca";
   SIZE 360,135;
   FONT oFont;
   ICON oIcon;
   STYLE DS_CENTER + WS_VISIBLE + WS_CAPTION + WS_SYSMENU

   @  5,5   GROUPBOX grpConfiguracao          CAPTION "Pesquisa Periodo"       SIZE 200,115

   @  10,40 SAY LBLdata                   CAPTION "Data Inicial:"               SIZE 168,22
   @  80,40 GET DATEPICKER oData  VAR Wdata                                     SIZE 100,22;
   TOOLTIP "Informe o Data Inicial da Pesquisa"
   @  10,70 SAY LBLdata1                   CAPTION "Data Final:"                SIZE 168,22
   @  80,70 GET DATEPICKER oData1  VAR Wdata1                                   SIZE 100,22;
   TOOLTIP "Informe o Data Final da Pesquisa"

   @  230,50 BUTTON btnOk CAPTION "Pesquisar";
   ON CLICK {||REL_REUNIAO()};
   SIZE 100,32 STYLE WS_TABSTOP;
   TOOLTIP "Confirma a Busca"

   @  230,90 BUTTON "Fechar";
   ON CLICK {||EndDialog()};
   SIZE 100,32;
   TOOLTIP "Fechar Janela"

WriteStatus( oTelaPrincipal,3,"Pesquisa Data" )
ACTIVATE DIALOG oFRMpesqdata
WriteStatus( oTelaPrincipal,3,"Area de Trabalho" )

RETURN(.T.)
