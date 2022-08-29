
/*
Funções genéricas Hwgui
*/

#IfnDef __XHARBOUR__
   #require "hbssl"
   #require "hbtip"

   REQUEST __HBEXTERN__HBSSL__

   #include "hwgcompat.ch"
   #include "hwg_extctrl.ch"
   #include "hbcompat.ch"
#ENDIF
#include "hwgui.ch"

#include 'dbstruct.ch'
#include 'directry.ch'
#include 'error.ch'
#include 'inkey.ch'
#include 'fileio.ch'
#include 'dbinfo.ch'
#include 'hbclass.ch'
#include 'ord.ch'
#include "DbInfo.ch"

static nContaMsg       := 0
static nTempo          := 0

***************************************
FUNCTION ALERT(_cMSG,_cTIT,_cNAOTRADUZ)
// Ana Brock - Acelerato 52026 - 03/03/2020
***************************************
IF _cTIT=NIL
   _cTIT:='Aviso do Sistema'
ENDIF
_cTIT := HWG_TRANSLATOR( Alltrim(_cTIT), 'TITULO ALERT' )
_cMSG := HWG_TRANSLATOR( Alltrim(_cMSG), 'ALERT' )
_cMSG := Alltrim(_cMSG)+If(_cNAOTRADUZ<>NIL,Hb_OsNewLine()+Alltrim(_cNAOTRADUZ),'')
HWG_MSGINFO(_cMSG,_cTIT)
RETURN(.T.)

*****************************************
FUNCTION MSGINFO(_cMSG,_cTIT,_cNAOTRADUZ)
// Ana Brock - Acelerato 52026 - 03/03/2020
*****************************************
IF _cTIT=NIL
   _cTIT:='Aviso do Sistema'
ENDIF
_cTIT := HWG_TRANSLATOR( Alltrim(_cTIT), 'TITULO MSGINFO' )
_cMSG := HWG_TRANSLATOR( Alltrim(_cMSG), 'MSGINFO' )
_cMSG := Alltrim(_cMSG)+If(_cNAOTRADUZ<>NIL,Hb_OsNewLine()+Alltrim(_cNAOTRADUZ),'')
HWG_MSGINFO(_cMSG,_cTIT)
RETURN(.T.)

*****************************************
FUNCTION MsgStop(_cMSG,_cTIT,_cNAOTRADUZ)
// Ana Brock - Acelerato 52026 - 03/03/2020
*****************************************
IF _cTIT=NIL
   _cTIT:='Aviso do Sistema'
ENDIF
_cTIT := HWG_TRANSLATOR( Alltrim(_cTIT), 'TITULO MSGSTOP' )
_cMSG := HWG_TRANSLATOR( Alltrim(_cMSG), 'MSGSTOP' )
_cMSG := Alltrim(_cMSG)+If(_cNAOTRADUZ<>NIL,Hb_OsNewLine()+Alltrim(_cNAOTRADUZ),'')
HWG_MSGSTOP(_cMSG,_cTIT)
RETURN(.T.)

******************************************
FUNCTION MsgNoYes(_cMSG,_cTIT,_cNAOTRADUZ)
// Ana Brock - Acelerato 52026 - 03/03/2020
******************************************
IF _cTIT=NIL
   _cTIT:='Aviso do Sistema'
ENDIF
_cTIT := HWG_TRANSLATOR( Alltrim(_cTIT), 'TITULO MSGNOYES' )
_cMSG := HWG_TRANSLATOR( Alltrim(_cMSG), 'MSGNOYES' )
_cMSG := Alltrim(_cMSG)+If(_cNAOTRADUZ<>NIL,Hb_OsNewLine()+Alltrim(_cNAOTRADUZ),'')
RETURN(HWG_MsgNoYes(_cMSG,_cTIT))

******************************************
FUNCTION MsgYesNo(_cMSG,_cTIT,_cNAOTRADUZ)
// Ana Brock - Acelerato 52026 - 03/03/2020
******************************************
IF _cTIT=NIL
   _cTIT:='Aviso do Sistema'
ENDIF
IF VALTYPE(_cTIT)='N'
   _cTIT:='Aviso do Sistema'
ENDIF
_cTIT := HWG_TRANSLATOR( Alltrim(_cTIT), 'TITULO MSGYESNO' )
_cMSG := HWG_TRANSLATOR( Alltrim(_cMSG), 'MSGYESNO' )
_cMSG := Alltrim(_cMSG)+If(_cNAOTRADUZ<>NIL,Hb_OsNewLine()+Alltrim(_cNAOTRADUZ),'')
RETURN(HWG_MsgYesNo(_cMSG,_cTIT))

************************************************
FUNCTION MSGRETRYCANCEL(_cMSG,_cTIT,_cNAOTRADUZ)
// Ana Brock - Acelerato 52026 - 03/03/2020
************************************************
LOCAL nRET:=0
IF _cTIT=NIL
   _cTIT:='Aviso do Sistema'
ENDIF
_cTIT := HWG_TRANSLATOR( Alltrim(_cTIT), 'TITULO MSGRETRYCANCEL' )
_cMSG := HWG_TRANSLATOR( Alltrim(_cMSG), 'MSGRETRYCANCEL' )
_cMSG := Alltrim(_cMSG)+If(_cNAOTRADUZ<>NIL,Hb_OsNewLine()+Alltrim(_cNAOTRADUZ),'')
nRET:=HWG_MSGRETRYCANCEL(_cMSG,_cTIT)
RETURN(IIF(nRET=4,.T.,.F.))

*********************************************
FUNCTION MSGOKCANCEL(_cMSG,_cTIT,_cNAOTRADUZ)
// Ana Brock - Acelerato 52026 - 03/03/2020
*********************************************
IF _cTIT=NIL
   _cTIT:='Aviso do Sistema'
ENDIF
_cTIT := HWG_TRANSLATOR( Alltrim(_cTIT), 'TITULO MSGOKCANCEL' )
_cMSG := HWG_TRANSLATOR( Alltrim(_cMSG), 'MSGOKCANCEL' )
_cMSG := Alltrim(_cMSG)+If(_cNAOTRADUZ<>NIL,Hb_OsNewLine()+Alltrim(_cNAOTRADUZ),'')
RETURN(HWG_MSGOKCANCEL(_cMSG,_cTIT))

************************************************
FUNCTION MSGYESNOCANCEL(_cMSG,_cTIT,_cNAOTRADUZ)
// Ana Brock - Acelerato 52026 - 03/03/2020
************************************************
IF _cTIT=NIL
   _cTIT:='Aviso do Sistema'
ENDIF
_cTIT := HWG_TRANSLATOR( Alltrim(_cTIT), 'TITULO MSGYESNOCANCEL' )
_cMSG := HWG_TRANSLATOR( Alltrim(_cMSG), 'MSGYESNOCANCEL' )
_cMSG := Alltrim(_cMSG)+If(_cNAOTRADUZ<>NIL,Hb_OsNewLine()+Alltrim(_cNAOTRADUZ),'')
RETURN(HWG_MSGYESNOCANCEL(_cMSG,_cTIT))

************************************************
FUNCTION MSGEXCLAMATION(_cMSG,_cTIT,_cNAOTRADUZ)
// Ana Brock - Acelerato 52026 - 03/03/2020
************************************************
IF _cTIT=NIL
   _cTIT:='Aviso do Sistema'
ENDIF
_cTIT := HWG_TRANSLATOR( Alltrim(_cTIT), 'TITULO MSGEXCLAMATION' )
_cMSG := HWG_TRANSLATOR( Alltrim(_cMSG), 'MSGEXCLAMATION' )
_cMSG := Alltrim(_cMSG)+If(_cNAOTRADUZ<>NIL,Hb_OsNewLine()+Alltrim(_cNAOTRADUZ),'')
RETURN(HWG_MSGEXCLAMATION(_cMSG,_cTIT))

******************************************************************
FUNCTION MY_SHOWMSG(_cMSG,nTEMPO_PAR,_cTIT,_cNAOTRADUZ,nLeft, nTop)
// Ana Brock - Acelerato 52026 - 10/03/2020
******************************************************************
local oSay, oDLG_SHOWMSG
local oButton1
local oButton2
local oTime_MSG 

nTop :=IF(nTop=Nil,0,nTop)
nLeft:=IF(nLeft=Nil,0,nLeft)

if nTempo <> 0
   nTempo:= 0
endif

if nTEMPO_PAR =  nil
   nTEMPO_PAR:=10
endif

If _cTIT=NIL
   _cTIT:="Aviso do Sistema"
Endif

_cTIT := HWG_TRANSLATOR( Alltrim(_cTIT), 'TITULO MY_SHOWMSG' )
_cMSG := HWG_TRANSLATOR( Alltrim(_cMSG), 'MY_SHOWMSG' )
_cMSG := _cMSG+If(_cNAOTRADUZ<>NIL,Hb_OsNewLine()+Alltrim(_cNAOTRADUZ),'')

Init DIALOG oDLG_SHOWMSG Title _cTIT NOEXIT NOEXITESC AT nLeft,nTop;
   Size 400,165 Icon HIcon():AddResource(1001) ;
   On Exit {|| NoSaidaF4() };
   Style IF(nTop=0 .AND. nLeft=0, DS_CENTER+WS_VISIBLE , WS_VISIBLE)

@ 150,100 BUTTONEX oButton1 Caption "&OK" ID IDOK;
   ON CLICK {|| oDLG_SHOWMSG:oTime_MSG:interval:=0,oDLG_SHOWMSG:oTime_MSG:end(), oDLG_SHOWMSG:Close() };
   SIZE 60,28 STYLE WS_TABSTOP ;
   FONT HFont():Add( '',0,-13,400,,,);
   TOOLTIP "Clique Aqui Para Proseguir"

@ -1,0 GET oSAY VAR _cMSG SIZE 400,95 ;
   FONT HFont():Add( '',0,-12,700,,,);
   STYLE ES_AUTOVSCROLL+ES_CENTER+ES_MULTILINE+ES_READONLY;
   TOOLTIP ''

SET TIMER oTIME_MSG OF oDLG_SHOWMSG ID HB_RandomInt(99999); //9007;
   Value 1000 ;
   Action {|| ATUALIZA_TIMER(nTEMPO_PAR,oDLG_SHOWMSG) }

Activate DIALOG oDLG_SHOWMSG

Return nil

*******************************************************
STATIC FUNCTION ATUALIZA_TIMER(nTEMPO_PAR,oDLG_SHOWMSG)
// Ana Brock - Acelerato 52026 - 10/03/2020
*******************************************************
  ntempo++
  if ntempo>=nTEMPO_PAR
     oDLG_SHOWMSG:otime_msg:End()
     oDLG_SHOWMSG:close()
  endif
  //hwg_doevents()
  oDLG_SHOWMSG:oButton1:SetText("&OK-"+AllTrim(Str(nTEMPO_PAR-ntempo)) )
  oDLG_SHOWMSG:oButton1:Refresh()
Return(.T.)

********************************************************************************
***************INICIO DA MENSAGEM RUM NA TELA***********************************
********************************************************************************
FUNCTION MsgRun( cMsg, bEval )
// Ana Brock - Acelerato 52026 - 10/03/2020
// Esta função NÃO PODE TRADUZIR os textos
******************************

IF bEval#NIL
   IF ValType(bEval) = 'B'

      PRIVATE oDlgHabla:=NIL
      MsgRun2(cMsg)
      HW_Atualiza_Dialogo2(cMsg)

      EVAL( bEval )
      Fim_Run()
   ENDIF
ELSE
   MsgRun2(cMsg)
   HW_Atualiza_Dialogo2(cMsg)
ENDIF
Return NIL

**********************
FUNCTION MsgRun2(cMsg)
// Ana Brock - Acelerato 52026 - 10/03/2020
// Esta função NÃO PODE TRADUZIR os textos
**********************
Local oTimHabla

if cMsg=Nil
   cMsg:="Aguarde em processamento...."
endif

INIT DIALOG oDlgHabla TITLE "Processando..." NOEXIT NOEXITESC ;//NOCLOSABLE;
   AT 0,0 SIZE 385,60 NAOTRADUZ;
   ON EXIT {|| NoSaidaF4() };
   STYLE WS_POPUP+WS_SYSMENU+WS_SIZEBOX+DS_CENTER;
   COLOR Rgb(255, 255, 255)

//STYLE DS_CENTER +WS_VISIBLE;

@ 10,25 SAY oTimHabla CAPTION cMsg SIZE 365,20 NAOTRADUZ;
   FONT HFont():Add( '',0,-11,400,,,);
   BACKCOLOR Rgb(255, 255, 255)

/*
@ 5,20 ANIMATION oAnime ;
       OF oDlgHabla ;
       SIZE 32,32;
       FILE "res\processando.avi";
       AUTOPLAY

oAnime:Play()
*/

ACTIVATE DIALOG oDlgHabla NOMODAL

Return Nil

****************
FUNCTION FIM_RUN
****************
sygDialogo()
TRY
   IF oDlgHabla # NIL
      oDlgHabla:CLOSE()
   ENDIF
CATCH
END
Return Nil

****************************************
FUNCTION HW_ATUALIZA_DIALOGO2(cMENSAGEM)
// Ana Brock - Acelerato 52026 - 10/03/2020
// Esta função NÃO PODE TRADUZIR os textos
****************************************

IF cMENSAGEM=nIL
   cMENSAGEM:="Aguarde em processamento...."
ENDIF

nCONTAMSG++
IF nCONTAMSG = 250
   HWG_DOEVENTS()
   SLEEP(60)
   nCONTAMSG:=0
ENDIF

TRY
   //oDlgHabla:SetFocus()
   oDlgHabla:ACONTROLS[1]:SETTEXT(cMENSAGEM)
//   oDlgHabla:ACONTROLS[1]:REFRESH()
catch
//   HWG_DOEVENTS()
END
RETURN NIL

***************************************
FUNCTION HW_ATUALIZA_DIALOGO(vMensagem)
// Ana Brock - Acelerato 52026 - 10/03/2020
// Esta função NÃO PODE TRADUZIR os textos
***************************************
LOCAL oWnd

TRY
   oWnd:=oTelaPrincipal
CATCH
END

nCONTAMSG++
IF nCONTAMSG = 250
   HWG_DOEVENTS()
   SLEEP(80)
   nCONTAMSG:=0
ENDIF

TRY
   IF TYPE(vMensagem)="N"
      WriteStatus( oWnd,2, STR(vMensagem))
   ELSE
      WriteStatus( oWnd,2, vMensagem)
   ENDIF
catch
//   HWG_DOEVENTS()
END
RETURN(.T.)

****************************************
FUNCTION SHOWMSG(cMSG,_cNAOTRADUZ,_cTIT)
// Ana Brock - Acelerato 52026 - 10/03/2020
****************************************

If _cTIT=NIL
   _cTIT:="Aviso do Sistema"
Endif

If VALTYPE(cMSG) = 'C'
   cMSG:=STRTRAN(cMSG, ';', CHR(13) )
ElseIf VALTYPE(cMSG) = 'N'
   cMSG:=ALLTRIM(STR(cMSG))
ElseIf VALTYPE(cMSG) = 'L'
   If cMSG
      cMSG:='True'
   Else
      cMSG:='False'
   Endif
ElseIf VALTYPE(cMSG) = 'D'
   cMSG:=Transform(cMSG,'@D')
ElseIf VALTYPE(cMSG) = 'B' .OR. VALTYPE(cMSG) = 'A' .OR. VALTYPE(cMSG) = 'H'
   cMSG:=VALTOPRG(cMSG)
Endif
If _cNAOTRADUZ<>NIL
   If VALTYPE(_cNAOTRADUZ) = 'C'
      _cNAOTRADUZ:=STRTRAN(_cNAOTRADUZ, ';', CHR(13) )
   ElseIf VALTYPE(_cNAOTRADUZ) = 'N'
      _cNAOTRADUZ:=ALLTRIM(STR(_cNAOTRADUZ))
   ElseIf VALTYPE(_cNAOTRADUZ) = 'L'
      If _cNAOTRADUZ
         _cNAOTRADUZ:='True'
      Else
         _cNAOTRADUZ:='False'
      Endif
   ElseIf VALTYPE(_cNAOTRADUZ) = 'D'
      _cNAOTRADUZ:=Transform(_cNAOTRADUZ,'@D')
   ElseIf VALTYPE(_cNAOTRADUZ) = 'B' .OR. VALTYPE(_cNAOTRADUZ) = 'A' .OR. VALTYPE(_cNAOTRADUZ) = 'H'
      _cNAOTRADUZ:=VALTOPRG(_cNAOTRADUZ)
   Endif
Endif

_cTIT := HWG_TRANSLATOR( Alltrim(_cTIT), 'TITULO SHOWMSG' )
_cMSG := HWG_TRANSLATOR( Alltrim(cMSG) , 'SHOWMSG' )
_cMSG := _cMSG+If(_cNAOTRADUZ<>NIL,Hb_OsNewLine()+Alltrim(_cNAOTRADUZ),'')

HWG_MsgInfo(_cMSG,_cTIT)
RETURN(.T.)

********************************************************
FUNCTION MY_MSGYESNO(_cMSG,nTEMPO_PAR,_cTIT,_cNAOTRADUZ)
// Ana Brock - Acelerato 52026 - 10/03/2020
********************************************************
Local oSAY, oButton1, oButton2
Local lRET:=.T., aJUSTIFICA:={}, nI
Local oTime_MSG, oDLG_YESNO

PRIVATE nTempo := 0

IF nTEMPO_PAR=Nil
   nTEMPO_PAR=20
ELSEIF VALTYPE(nTEMPO_PAR)#'N'
   nTEMPO_PAR=20
ENDIF

If _cTIT=NIL
   _cTIT:="Aviso do Sistema"
Endif

_cMSG := HWG_TRANSLATOR( Alltrim(_cMSG) , 'MY_MSGYESNO' )
_cMSG := _cMSG+If(_cNAOTRADUZ<>NIL,Hb_OsNewLine()+Alltrim(_cNAOTRADUZ),'')

INIT DIALOG oDLG_YESNO TITLE _cTIT NOEXIT NOEXITESC ;
   AT 0,0 SIZE 400,160 ;
   ICON HIcon():AddResource(1001) ;
   ON EXIT {|| NoSaidaF4() };
   STYLE DS_CENTER +WS_VISIBLE

@ 220,100 BUTTONEX oButton1 Caption "&Sim" ON CLICK {|| (oTime_MSG:end()), lRET:=.T. ,oDLG_YESNO:Close() };
   SIZE 80,24 STYLE WS_TABSTOP ;
   ID IDOK;
   FONT HFont():Add( '',0,-12,400,,,);
   TOOLTIP "Clique Aqui Para Proseguir"

@ 310,100 BUTTONEX oButton2 Caption "&Não" ON CLICK {|| (oTime_MSG:end()), lRET:=.F. ,oDLG_YESNO:Close() };
   SIZE 80,24 STYLE WS_TABSTOP ;
   FONT HFont():Add( '',0,-12,400,,,);
   TOOLTIP "Clique Aqui Para Voltar ou Cancelar"

@ -1,0 GET oSAY VAR _cMSG SIZE 400,95 NAOTRADUZ;
   FONT HFont():Add( '',0,-12,400,,,);
   STYLE ES_AUTOVSCROLL+ES_CENTER+ES_MULTILINE+ES_READONLY;
   TOOLTIP ' '

SET TIMER oTime_MSG OF oDLG_YESNO ID 90007 VALUE 1000 ACTION {|| ATUALIZA_TIMER_MSGYESNO(nTEMPO_PAR,oButton1,oDLG_YESNO,oTime_MSG) }

ACTIVATE DIALOG oDLG_YESNO

Return(lRET)

***************************************************************************
STATIC FUNCTION ATUALIZA_TIMER_MSGYESNO(nTEMPO_PAR,oButton1,oDlg,oTime_MSG)
***************************************************************************
nTempo++
IF nTempo=nTEMPO_PAR
   oTime_MSG:end()
   oDlg:Close()
ENDIF
HWG_DOEVENTS()
oButton1:SETTEXT("&Sim-"+alltrim(str(nTEMPO_PAR-nTempo)) )
RETURN(.T.)

****************************************
FUNCTION SN(cMSG,cBTN,_cTIT,_cNAOTRADUZ)
// Ana Brock - Acelerato 52026 - 10/03/2020
//** NÃO PRECISA TRADUZIR POIS VAI TRADUZIR NAS FUNÇÔES CHAMADAS ABAIXO
****************************************
/* msg sim ou nao,
      cMSG-> MENSAGEM A EXIBIR
      cBTN->  'S' OU 'N'  FOCO NO BOTAO
   RETORNO .T. SE SIM, .F. SE NAO */
LOCAL lRET:=.T.

IF cBTN=NIL
   cBTN:='S'
ENDIF
if VALTYPE(cMSG) = 'C'
   cMSG:=STRTRAN(cMSG, ';', CHR(13) )
endif

IF cBTN='S'
   lRET:=MSGYESNO(cMSG,_cTIT,_cNAOTRADUZ) // VAI TRADUZIR DENTRO DESTA
ELSE
   lRET:=MSGNOYES(cMSG,_cTIT,_cNAOTRADUZ) // VAI TRADUZIR DENTRO DESTA
ENDIF

RETURN(lRET)

*************************************************************************
FUNCTION MY_MSGGET(cTitle,cText,vINI,cMask,nMAXLE,lPASSWORD,cNaoTraduz )
// Ana Brock - Acelerato 52026 - 10/03/2020
*************************************************************************
Local oDlg, oRES,cText1:=''
Local cRes := IIF(vINI=Nil,"",vINI)

cMask := IIF(cMask=Nil,"@!",cMask)
lPASSWORD:= IIF(lPASSWORD=NIL,.F.,lPASSWORD)

nMAXLE:= IIF(nMAXLE=NIL,0,nMAXLE)
IF VALTYPE(nMAXLE)<>'N'
   nMAXLE:=0
ENDIF

cText  := HWG_TRANSLATOR( Alltrim(cText) , 'MY_MSGGET' )
If cNaoTraduz<>NIL .And. Valtype(cNaoTraduz)<>'D'
   cText1 := Alltrim(cNaoTraduz)
Endif

INIT DIALOG oDlg TITLE cTitle At 0,0 CLIPPER NOEXIT SIZE 300,If(!Empty(cText1),180,140);
   ICON HIcon():AddResource(1001) ;
   FONT HFont():Add( "MS Sans Serif", 0, - 13 );
   STYLE DS_CENTER +WS_SYSMENU+WS_VISIBLE

   @ 20, 10 SAY cText SIZE 260,22 NAOTRADUZ
   If !Empty(cText1)
      @ 20, 30 SAY cText1 SIZE 260,22 NAOTRADUZ
   Endif
   IF cMask="@D" .OR. cMask="@d"
      @ 20,If(!Empty(cText1),65,35) GET DATEPICKER oRES;
         VAR cRes  SIZE 260, 24;
         TOOLTIP 'Informe a Data';
         STYLE 0  + WS_TABSTOP
   ELSE
      IF lPASSWORD
         @ 20,If(!Empty(cText1),65,35) GET oRES VAR cRes SIZE 260, 24;
            PICTURE cMask PASSWORD;
            TOOLTIP cText;
            STYLE WS_TABSTOP + ES_AUTOHSCROLL
      ELSEIF nMAXLE >0
         @ 20,If(!Empty(cText1),65,35) GET oRES VAR cRes  SIZE 260, 24 MAXLENGTH nMAXLE;
            PICTURE cMask ;
            TOOLTIP cText;
            STYLE WS_TABSTOP + ES_AUTOHSCROLL
      ELSE
         @ 20,If(!Empty(cText1),65,35) GET oRES VAR cRes  SIZE 260, 24;
            PICTURE cMask ;
            TOOLTIP cText;
            STYLE WS_TABSTOP + ES_AUTOHSCROLL
      ENDIF
   ENDIF

   @ 020,If(!Empty(cText1),95,65) BUTTONEX "Ok";
      SIZE 110, 38;
      TOOLTIP 'Clique aqui para Continuar';
      STYLE WS_TABSTOP;
      BITMAP (HBitmap():AddResource(1002)):handle;
      ON CLICK {|| oDlg:CLOSE() }

   @ 170,If(!Empty(cText1),95,65) BUTTONEX "Cancelar";
      SIZE 110, 38;
      TOOLTIP 'Clique aqui para Cancelar';
      STYLE WS_TABSTOP;
      BITMAP (HBitmap():AddResource(1003)):handle;
      ON CLICK {|| cRes:="",oDlg:CLOSE() }

oDlg:Activate()

RETURN(cRes)


*===============================================================================
* sygDialogo
*-------------------------------------------------------------------------------
* Mostra mensagem de diálogo para o usuario
*  cMsg // Mensagem a ser apresentada
*  bBlc // Bloco ... em construçao versão posterior
*===============================================================================
******************************
Function SYGDIALOGO(cMsg,bBlc)
// Ana Brock - Acelerato 52026 - 10/03/2020
// Esta função NÃO PODE TRADUZIR os textos
******************************
Static oDlgHab

IF cMsg=nil
   cMsg=''
ENDIF

* Destrói o objeto da memória
*______________________________________
if Empty(cMsg)
   if oDlgHab <> nil
      oDlgHab:Close()
      oDlgHab:= nil
   endif
   return nil
endif

if oDlgHab == nil
   oDlgHab:= CriaObjDialogo()
endif

AtualizaDialogo(cMsg, @oDlgHab)

IF bBlc#NIL
   IF ValType(bBlc) = 'B'
      EVAL( bBlc )
      if oDlgHab <> nil
         oDlgHab:Close()
         oDlgHab:= nil
      endif
   ENDIF
ENDIF
Return nil

*===============================================================================
* sygCriaObjDialogo(cMsg, oDlg )
*===============================================================================
********************************
Static function CriaObjDialogo()
// Ana Brock - Acelerato 52026 - 10/03/2020
// Esta função NÃO PODE TRADUZIR os textos
********************************
Local oBox
Local oTimHabla

INIT DIALOG oBox TITLE "Processando..." NOEXIT NOEXITESC ;//NOCLOSABLE;
   AT 0,0 SIZE 385,60 NAOTRADUZ;
   ON EXIT {|| NOSAIDAF4() };
   STYLE WS_POPUP+WS_SYSMENU+WS_SIZEBOX+DS_CENTER;
   COLOR Rgb(255, 255, 255)

  @ 10,26 SAY oTimHabla CAPTION "Aguarde, em processamento." SIZE 365,20 NAOTRADUZ;
      FONT HFont():Add( '',0,-11,400,,,);
      BACKCOLOR Rgb(255, 255, 255)
/*
  if file("res\processando.avi")
     @  5,20 ANIMATION oAnime ;
     OF oBox ;
     Size 32,32;
     File "res\processando.avi";
     AUTOPLAY

     oAnime:Play()
  endif
*/

ACTIVATE DIALOG oBox NOMODAL

Return(oBox)

************************************************
Static Function AtualizaDialogo(cMsg, oDLG_SYGD)
// Ana Brock - Acelerato 52026 - 10/03/2020
// Esta função NÃO PODE TRADUZIR os textos
************************************************
IF EMPTY(cMsg) .or. VALTYPE(cMsg)#'C'
   cMsg:="Aguarde, em processamento..."
ENDIF

nCONTAMSG++
IF nCONTAMSG = 250
   HWG_DOEVENTS()
   SLEEP(60)
   nCONTAMSG:=0
ENDIF

try
  oDLG_SYGD:ACONTROLS[1]:SETTEXT(cMsg)
catch
  // HWG_DOEVENTS()
end
Return nil
