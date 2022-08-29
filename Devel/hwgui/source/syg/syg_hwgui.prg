
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

#define DC_CALL_STD    0x0020
#define WS_EX_LAYERED  524288
#define LWA_ALPHA      0x2

#define x_BLUE       16711680
#define x_DARKBLUE   10027008
#define x_WHITE      16777215
#define x_CYAN       16776960
#define x_BLACK             0
#define x_RED             255
#define x_GREEN         32768
#define x_GRAY        8421504
#define x_YELLOW        65535
#define x_GRAY2       8421440
#define CORPADRAO  COLOR_3DLIGHT+3

static nContaMsg       := 0
static nTempo          := 0

*#pragma /w2
*#pragma /es2

*****************
FUNCTION AVISO_10
*****************
MsgStop("Atenção !!! Você Já excedeu a quantidade de Registros permitidos na Versão Demonstração,"+ HB_OsNewLine() +;
        "Favor entrar em Contato com a Sygecom Informática para Adquirir uma licença Comercial."  + HB_OsNewLine() +;
        "Telefones para Contato: (0xx)51-3442-2345  /  (0xx)51-3442-3975")
return nil

**************
FUNCTION BARRA
**************
Local vArea_uso := Select()
BARRA_HWGUI2(&vArea_uso->(RECNO()),LASTREC())
Return(.T.)

*****************************
FUNCTION BARRA_HWGUI2(VNQ,VNT)
*****************************
HW_Atualiza_Dialogo(Str((VNQ/VNT)*100,4) +" %")
RETURN .T.

*****************************
FUNCTION BARRA_HWGUI(VNQ,VNT)
*****************************
HW_Atualiza_Dialogo2(Str((VNQ/VNT)*100,4) +" %")
RETURN .T.


FUNCTION ERROREG
ShowMsg("Não foi possível localizar o registro, " +;
        "Registro não cadastrado ou excluido, "   +;
        "Tente novamente.")
return nil

function ToTxt( uVal )
local cType := ValType( uVal )

do case
   case cType == "C" .or. cType == "M"
        return uVal

   case cType == "D"
        return DToC( uVal )

   case cType == "L"
        return If( uVal, ".T.", ".F." )

   case cType == "N"
        return AllTrim( Str( uVal ) )

   case cType == "B"
        return "{|| ... }"

   case cType == "A"
        return "{ ... }"

   case cType == "O"
        return If( __ObjHasData( uVal, "cClassName" ), uVal:cClassName, uVal:ClassName() )

   case cType == "H"
        return "{=>}"

   otherwise
        return ""
endcase
return nil

**************
FUNCTION AVISO
**************
Local oDlg_manuten
Local oGroup1, oBitmap1, oLabel2, oLabel1, oLabel3, oLine1, oLink1 , oButtonex1

  INIT DIALOG oDlg_manuten TITLE "Modulo em Desenvolvimento" ;
  ICON HIcon():AddResource(1001) ;
  AT 370,175 SIZE 321,488 ;
  FONT HFont():Add( '',0,-13,400,,,) CLIPPER  NOEXIT  ;
  STYLE WS_POPUP+WS_CAPTION+DS_CENTER +WS_SYSMENU+WS_MINIMIZEBOX

   @ 9,395 LINE oLine1 LENGTH 303
   @ 31,29 BITMAP oBitmap1  ;
   SHOW 'res\construcao.bmp' ;
   OF oGroup1  TRANSPARENT SIZE 256,256

   @ 16,6 GROUPBOX oGroup1 CAPTION "Modulo em Desenvolvimento"  SIZE 288,297  ;
   COLOR 16711680

   @ 30,339 SAY oLabel1 CAPTION "Esse Modulo esta em Desenvolvimento"  SIZE 261,20  ;
   COLOR 16711680   ;
   FONT HFont():Add( '',0,-15,400,,,)

   @ 116,309 SAY oLabel2 CAPTION "Atenção:"  SIZE 88,27  ;
   COLOR 255   ;
   FONT HFont():Add( '',0,-19,700,,,)

   @ 5,363 SAY oLabel3 CAPTION "em Breve vai esta Liberado. Por Favor Aguarde"  SIZE 311,20  ;
   COLOR 16711680   ;
   FONT HFont():Add( '',0,-15,400,,,)

   @ 104,447 BUTTONEX oButtonex1 CAPTION "&Fechar"  SIZE 98,38 ;
   STYLE WS_TABSTOP   ;
   ID IDOK;
   BITMAP (HBitmap():AddResource(1003)):handle  ;
   BSTYLE 0;
   TOOLTIP 'Clique aqui para Fechar' ;
   ON CLICK {|| oDlg_manuten:close() }

   @ 24,408 SAY oLink1 CAPTION "Clique aqui para Acompanhar Novas Funçoes"  ;
   LINK 'https://sagierp.com.br'  SIZE 273,22   TRANSPARENT;
   TOOLTIP 'Clique aqui para visitar o Forum da Sygecom e acompanhar as novas funções.'

 ACTIVATE DIALOG oDlg_manuten //NOMODAL

return Nil

******************************
FUNCTION MY_ISDIGIT( cString , lPONTOS_VIRGULA )
******************************
local i

IF lPONTOS_VIRGULA=NIL
   lPONTOS_VIRGULA:=.F.
ENDIF

for i := 1 to len( cString )

   IF lPONTOS_VIRGULA
      IF substr( cString, i, 1 )='.' .OR. substr( cString, i, 1 )=','
         LOOP
      ENDIF
   ENDIF

   if !isdigit( substr( cString, i, 1 ) )
      return .F.
   endif
next
return .T.

***************************
FUNCTION REFRESHALL( oFrm )
***************************
AEval( oFrm:GetList, {|o|o:refresh()} )
Return .T.

**********************************
FUNCTION DESABILITAALLGETS( oFrm )
**********************************
AEval( oFrm:GetList, {|o|o:disable()} )
Return .T.

**********************************
FUNCTION HABILITAALLGETS( oFrm ) // Adicionado por Christiano A. Silveira
**********************************
 AEval( oFrm:GetList, {|o|o:enable()} )
Return .T.

*******************************
FUNCTION DESABILITAGETS( ... )
*******************************
Local nI, aPARA:=HB_AParams(), cClass:=''

FOR nI:=1 TO LEN(aPARA)
   aPARA[nI]:DISABLE()
   //cClass:=UPPER(aPARA[nI]:ClassName)
NEXT
Return .T.

*******************************
FUNCTION DESABILITAGETS_LIMPA( ... )
*******************************
Local nI, aPARA:=HB_AParams(), cClass:=''

FOR nI:=1 TO LEN(aPARA)
   aPARA[nI]:DISABLE()
   cClass:=UPPER(aPARA[nI]:ClassName)

   if cClass == 'HEDIT' // SE FOR CAMPO GET
      if valtype(aPARA[nI]:varget())='N'
         aPARA[nI]:Settext(0)
      elseif valtype(aPARA[nI]:varget())='C'
         aPARA[nI]:Settext('')
      endif
   elseif cClass == 'HCHECKBUTTON'
      aPARA[nI]:setvalue(.F.)
   endif
NEXT
Return .T.

*****************************
FUNCTION HABILITAGETS( ... )
*****************************
Local nI, aPARA:=HB_AParams()

FOR nI:=1 TO LEN(aPARA)
   aPARA[nI]:ENABLE()
NEXT
Return .T.

**********************************
FUNCTION DESABLE_BUTTONS(oOBJ_DLG)
**********************************
/*
RETORNA APENAS OS BOTÃO QUE FORAM DISABILITADOS PELA ROTINA,
OS QUE JÁ ESTAVAM DESABILITADO ELE NÃO CONSIDERA
*/
LOCAL nI, aRET_DISABLE:={}

IF oOBJ_DLG<>NIL
   FOR nI:=1 TO LEN(oOBJ_DLG:ACONTROLS)
      IF UPPER(oOBJ_DLG:ACONTROLS[nI]:ClassName)='HBUTTON' .OR. UPPER(oOBJ_DLG:ACONTROLS[nI]:ClassName)='HBUTTONEX'
         IF oOBJ_DLG:ACONTROLS[nI]:IsEnabled() // SE TIVER HABILITADO AI SIM DESABILITA
            oOBJ_DLG:ACONTROLS[nI]:DISABLE()
            AADD(aRET_DISABLE,oOBJ_DLG:ACONTROLS[nI])
         ENDIF   
      ENDIF
   NEXT
ENDIF

RETURN(aRET_DISABLE) 
   
************************************
FUNCTION ENABLE_BUTTONS(aBTN_ENABLE)
*************************************
LOCAL nI

IF aBTN_ENABLE<>NIL .AND. VALTYPE(aBTN_ENABLE)='A'
   FOR nI:=1 TO LEN(aBTN_ENABLE)
      aBTN_ENABLE[nI]:ENABLE()
   NEXT
ENDIF

RETURN(.T.)   

******************
FUNCTION NOSAIDAF4
******************
if getkeystate(VK_F4,.F.,.T.) < 0
   RETURN .F.
ENDIF
RETURN .T.

****************************
FUNCTION MY_ROUND(VALOR,DEC)
****************************
DEFAULT dec := 2
dec := 7-dec
valor := substr(str(valor,20,7),1,(20-dec))
RETURN val(valor)

****************************************
FUNCTION STATUSEXE(cExecutavel,nDERRUBA)  //verefica se o EXE já está rodando, ou derruba o EXE que está rodando
****************************************
Local oScriptObj, oWmiService, oListaProcess, oProcessos, lRET:=.F.
//oWmiService=Service_WMI()
TRY
   oScriptObj=CREATEOBJECT("wbemScripting.SwbemLocator")
   oWmiService=oScriptObj:ConnectServer()
CATCH
   RETURN(lRET)
END
TRY
   oListaProcess=oWmiService:ExecQuery("select * from Win32_Process where Name='"+cExecutavel+"'")
CATCH
   RETURN(lRET)
END

FOR Each oProcessos in oListaProcess
   lRET:=.t.
   IF nDERRUBA=2
      oProcessos:Terminate()  // derruba o EXE
   ENDIF
NEXT
RETURN(lRET)

/*
********************
FUNCTION SERVICE_WMI
********************
Static oWmiService
Local oScriptObj
If oWmiService==nil
   oScriptObj=CREATEOBJECT("wbemScripting.SwbemLocator")
   oWmiService=oScriptObj:ConnectServer()
End If
Return oWmiService
*/

//nova function
FUNCTION ISWOW64
LOCAL cTEM64BITS:=GetEnv("PROCESSOR_ARCHITEW6432")
RETURN(IIF(EMPTY(cTEM64BITS),.F.,.T.))

/*
//antiga function
#pragma BEGINDUMP

#include <windows.h>
#include <hbapi.h>

typedef BOOL (WINAPI *LPFN_ISWOW64PROCESS) (HANDLE, PBOOL);

LPFN_ISWOW64PROCESS fnIsWow64Process;

HB_FUNC( ISWOW64 )
{
    BOOL bIsWow64 = FALSE;

    fnIsWow64Process = ( LPFN_ISWOW64PROCESS )
                       GetProcAddress( GetModuleHandle( TEXT( "kernel32" ) ), "IsWow64Process" );

    if( fnIsWow64Process )
        bIsWow64 = ! fnIsWow64Process( GetCurrentProcess(), &bIsWow64 );

    hb_retl( bIsWow64 );
}

#pragma ENDDUMP
*/

**************************************
FUNCTION BUSCA_CEP(cCEP,cEND,cCID,cUF,cUF_DEFAULT,cCIDADE_DEFAULT)
**************************************
Local aRet2 := {}, nR1_CEP := 1
LOCAL oFrm2_TEMP, oCEP_TEMP, oEND_TEMP, oCID_TEMP, oUF_TEMP, oRadio_CEP1, oRadio_CEP2
LOCAL cCEP_TEMP := ""
LOCAL cEND_TEMP := ""
LOCAL cCID_TEMP := cCIDADE_DEFAULT
LOCAL cUF_TEMP  := cUF_DEFAULT //eESTADO,eCIDADE

/*
IF Inetestaconectada()=.F.
   MsgStop("A Busca de Endereço pelo CEP é preciso acesso a Internet, Favor verificar sua Conexão")
   Return aRet2
ENDIF
*/

IF cCEP#Nil
   IF LEN(ALLTRIM(cCEP)) > 0
      cCEP_TEMP=cCEP
   ENDIF
ENDIF

IF cEND#Nil
   IF LEN(ALLTRIM(cEND)) > 0
      cEND_TEMP=cEND
   ENDIF
   /*
   IF AT("RUA",cEND_TEMP)>0
      cEND_TEMP:=StrTran( cEND_TEMP, "RUA", '',,1 )
   ENDIF
   IF AT("R.",cEND_TEMP)>0
      cEND_TEMP:=StrTran( cEND_TEMP, "R.", '',,1 )
   ENDIF
   IF AT("AVENIDA",cEND_TEMP)>0
      cEND_TEMP:=StrTran( cEND_TEMP, "AVENIDA", '',,1 )
   ENDIF

   IF AT("AV.",cEND_TEMP)>0
      cEND_TEMP:=StrTran( cEND_TEMP, "AV.", '',,1 )
   ENDIF

   IF AT("AV",cEND_TEMP)>0
      cEND_TEMP:=StrTran( cEND_TEMP, "AV", '',,1 )
   ENDIF
   */
   cEND_TEMP:=ALLTRIM(cEND_TEMP)
ENDIF

IF cCID#Nil
   IF LEN(ALLTRIM(cCID)) > 0
      cCID_TEMP=cCID
   ENDIF
   cCID_TEMP:=ALLTRIM(cCID_TEMP)
ENDIF

IF cUF#Nil
   IF LEN(ALLTRIM(cUF)) > 0
      cUF_TEMP=cUF
   ENDIF
ENDIF

INIT DIALOG oFrm2_TEMP CLIPPER NOEXIT TITLE "Busca de Endereço e Cep ( On-Line )";
AT 0,0 SIZE 450,215;
FONT HFont():Add( '',0,-12,400,,,);
ON INIT  {|| oEND_TEMP:disable(),oCID_TEMP:disable(),oUF_TEMP:disable(),(oFrm2_TEMP:nInitFocus := oCEP_TEMP:handle),.T.};
ICON HIcon():AddResource(1001) ;
STYLE DS_CENTER + WS_VISIBLE + WS_CAPTION + WS_SYSMENU

GET RADIOGROUP nR1_CEP
   @ 10,15 RADIOBUTTON oRadio_CEP1 caption "Pesquisa por CEP";
   SIZE 140, 22;
   STYLE WS_TABSTOP;
   ON CLICK { || oCEP_TEMP:enable(),oEND_TEMP:disable(),oCID_TEMP:disable(),oUF_TEMP:disable(),oCEP_TEMP:SetFocus() };
   TOOLTIP "Escolha essa Opção para Buscar o Endereço informando o CEP"

   @ 180,15 RADIOBUTTON oRadio_CEP2 caption "Pesquisa por Endereço" ;
   SIZE 175, 22;
   STYLE WS_TABSTOP;
   ON CLICK { || oCEP_TEMP:disable(),oEND_TEMP:enable(),oCID_TEMP:enable(),oUF_TEMP:enable(),oEND_TEMP:SetFocus() };
   TOOLTIP "Escolha essa Opção para Buscar o CEP informando o Endereço"
END RADIOGROUP

@  33,45 SAY "Cep:" size 40,25
@  70,45 GET oCEP_TEMP VAR cCEP_TEMP PICTURE "@R 99999-999" SIZE 90,25;
TOOLTIP "Informe o Nome que Deseja Buscar"

@  04,75 SAY "Endereço:" size 40,25
@  70,75 GET oEND_TEMP VAR cEND_TEMP PICTURE "@!" SIZE 365,25;
MAXLENGTH 60;
STYLE ES_AUTOHSCROLL ;
TOOLTIP "Informe o Endereço sem Numero, sem: RUA, AVENIDA, AV, TRAESSA e etc..."

@  18,105 SAY "Cidade:" size 40,25
@  70,105 GET oCID_TEMP VAR cCID_TEMP PICTURE "@!" SIZE 365,25;
MAXLENGTH 40;
STYLE ES_AUTOHSCROLL ;
TOOLTIP "Informe o Municipio"

@ 40,135  SAY "UF:" size 40,25
@ 70,135  GET COMBOBOX oUF_TEMP VAR cUF_TEMP ITEMS {"AC","AL","AP","AM","BA","CE","DF","GO","ES","MA","MT","MS","MG","PA","PB","PR","PE","PI","RN","RS","RJ","RO","RR","SC","SP","SE","TO","EX"} SIZE 50,22 TEXT;
DISPLAYCOUNT 27;
TOOLTIP "Informe o UF"

@ 225,165 BUTTONEX "&OK";
ON CLICK { || aRet2 := BUSCA_CEP3(oFrm2_TEMP,nR1_CEP,cCEP_TEMP,cEND_TEMP,cCID_TEMP,cUF_TEMP),oFrm2_TEMP:REFRESH() };
BITMAP (HBitmap():AddResource(1002)):handle  ;
SIZE 100,38 STYLE WS_TABSTOP;
TOOLTIP "Confirma a Busca"

@ 335,165 BUTTONEX "&Cancelar";
BITMAP (HBitmap():AddResource(1003)):handle  ;
ON CLICK {|| oFrm2_TEMP:Close() };
SIZE 100,38;
TOOLTIP "Fechar Janela"

ACTIVATE DIALOG oFrm2_TEMP

Return aRet2

**************************
STATIC FUNCTION BUSCA_CEP3(oFrm2_TEMP,nR1_CEP,cCEP_TEMP,cEND_TEMP,cCID_TEMP,cUF_TEMP)
**************************
Local aRet := {}, oHttp, lUSASEGUNDOLINK:=.F.
Local aRet3:= {}
LOCAL aTokens := {}
Local nMAXLEN := 0, nESCOLHA_CHOICE:=0
LOCAL I, lA1, cURL:="", cHtml:="", cRET:=''

IF STR(nR1_CEP,1)="1"
   if empty(cCEP_TEMP)
      ShowMsg("Obrigatorio informar o Cep, Favor Revisar")
      Return aRet
   endif
ELSE
   if empty(cEND_TEMP)
      ShowMsg("Obrigatorio informar o Endereço, Favor Revisar")
      Return aRet
   endif

   if empty(cCID_TEMP)
      ShowMsg("Obrigatorio informar o Municipio, Favor Revisar")
      Return aRet
   endif

   if empty(cUF_TEMP)
      ShowMsg("Obrigatorio informar a Unidade Federativa, Favor Revisar")
      Return aRet
   endif
ENDIF
/*
IF INETESTACONECTADA()=.F.
   SHOWMSG('É necessário conexão com a internet para realizar esta pesquisa, verifique...')
   RETURN NIL
ENDIF
*/

sygDialogo("Aguarde Buscando Endereço...")
//http://www.byjg.com.br/site/webservice.php/ws/cep?httpmethod=obterlogradouroauth&cep=90460110&usuario=sygecom&senha=123456
IF STR(nR1_CEP,1)="1" // busca o endereço enviando o CEP por parametro
   cURL := "http://www.byjg.com.br/site/webservice.php/ws/cep?httpmethod=obterlogradouroauth&cep="+cCEP_TEMP+"&usuario=sygecom&senha=123456"
//   cURL := "http://www.josequintas.com.br/cep.asp?cep="+cCEP_TEMP
/*
<jpacep>
   <cep>13820-000</cep>
   <logradouro></logradouro>
   <bairro></bairro>
   <cidade>Monte Alegre do Sul</cidade>
   <uf>SP</uf>
   <ibge>3531209</ibge>
   <infalt>2019/08/19 GUIA P</infalt>
   <status>E</status>
</jpacep>
*/
   ABRE_LINK_INTERNET(cURL,@cHtml,NIL,NIL,NIL,NIL,.T.)

   IF (!EMPTY(cHtml) .AND.; 
      (SUBSTR(UPPER(ALLTRIM(hb_UTF8ToStr(cHtml))),17) = "NÃO ENCONTRADO" .OR.;
      AT('<html',cHtml)>0 .AND. AT('</html>',cHtml)>0)) .OR. EMPTY(cHtml)
      
      ABRE_LINK_INTERNET("http://www.josequintas.com.br/cep.asp?cep="+cCEP_TEMP,@cHtml,NIL,NIL,NIL,NIL,.T.) // TENTA SEGUNDO LINK
   
      IF !EMPTY(cHtml) .AND. !EMPTY(PEGA_TAG_XML({'jpacep','logradouro'},cHtml))
         AADD( aRet, cCEP_TEMP )
         AADD( aRet, TIRAACENTO(UPPER(ALLTRIM( PEGA_TAG_XML({'jpacep','logradouro'},cHtml) ))) )
         AADD( aRet, TIRAACENTO(UPPER(ALLTRIM( PEGA_TAG_XML({'jpacep','bairro'},cHtml) ))) )
         AADD( aRet, TIRAACENTO(UPPER(ALLTRIM( PEGA_TAG_XML({'jpacep','cidade'},cHtml) ))) )
         AADD( aRet, TIRAACENTO(UPPER(ALLTRIM( PEGA_TAG_XML({'jpacep','uf'},cHtml) ))) )
      ELSE
         sygDialogo()
         ShowMsg("CEP não encontrado, favor revisar")
         Return aRet
      ENDIF
   ELSE
      //OK|Rua Artur Garcia - até 483/484, Bela Vista, Alvorada, RS, 4300604
      IF !EMPTY(cHtml)
         AADD( aRet, cCEP_TEMP )
         aTokens := HB_ATokens( SUBSTR(cHtml,4), ",", .F., .F. )
         FOR i := 1 TO Len( aTokens )
            AADD( aRet, TIRAACENTO(UPPER(ALLTRIM(hb_UTF8ToStr(aTokens[i])))) )
         NEXT
      ENDIF   
   ENDIF
   
   sygDialogo()
   oFrm2_TEMP:Close()
ELSE // busca o cep enviando o endereço por parametro
   cURL := STRTRAN("http://www.byjg.com.br/site/webservice.php/ws/cep?httpmethod=obtercepauth&logradouro="+LOWER(ALLTRIM(cEND_TEMP))+"&localidade="+LOWER(ALLTRIM(cCID_TEMP))+"&UF="+ALLTRIM(cUF_TEMP)+"&usuario=sygecom&senha=123456"," ","%20")
   ABRE_LINK_INTERNET(cURL,@cHtml,NIL,NIL,NIL,NIL,.T.)

   IF VALTYPE(cHtml)='C'
      IF LEN(cHtml) > 0 .AND. !(AT('<html',cHtml)>0 .OR. AT('</html>',cHtml)>0)
         IF SUBSTR(Upper(alltrim(hb_UTF8ToStr(cHtml))),6) # "LOGRADOURO NÃO ENCONTRADO"
            IF LEN(cHtml) > 0
               aRet3=HB_ATokens( SUBSTR(hb_UTF8ToStr(cHtml),6), "|")

               IF LEN(aRet3) > 0
                  IF aRET3[1,1] = ""
                     ADEL(aRET3,1,.T.)
                  ENDIF
                  AEVAL(aRet3, {|cV,nV| IF( LEN( aRet3[nV] ) > nMAXLEN,nMAXLEN := LEN( aRet3[nV] ), NIL ) })
                  nESCOLHA_CHOICE := MY_WCHOICE( aret3, "Seleciona Endereço", 15+LEN(aret3), nMAXLEN,HFont():Add( '',0,-12,400,,,) ,,,,,,)
                  IF nESCOLHA_CHOICE > 0
                     aTokens := HB_ATokens( aret3[nESCOLHA_CHOICE], ",", .F., .F. )
                     FOR i := 1 TO Len( aTokens )
                        AADD( aRet, UPPER(ALLTRIM(TiraAcento(aTokens[i]))) )
                     NEXT
                  ENDIF
               ENDIF
            ELSE
               lUSASEGUNDOLINK:=.T.
            ENDIF
         ELSE
            sygDialogo()
            ShowMsg("Logradouro Não Localizado, Favor não informar abreviaturas como (AV.),(TRAV.) ou (ROD.)" + HB_OsNewLine() + ;
                    "ou tente buscar pelo nome apenas sem (AVENIDA), (RUA), (RODOVIA) e etc..., Favor Revisar")
            Return aRet        
         ENDIF
      ELSE
         lUSASEGUNDOLINK:=.T.
      ENDIF
   ELSE
      lUSASEGUNDOLINK:=.T.
   ENDIF
ENDIF

IF lUSASEGUNDOLINK
//
ENDIF

sygDialogo()
IF len(aRet) = 0
   ShowMsg('Nenhum Resultado encontrado')
ELSE
   IF len(aRet) < 5
      cRET="Cep Não localizado - "+HB_OsNewLine()
      FOR lA1 := 1 TO Len(aRET)
          cRET=cRET+aRET[lA1]+HB_OsNewLine()
      NEXT
      ShowMsg(cRET)
      aRet:={}
   ENDIF
   oFrm2_TEMP:Close()
ENDIF
Return aRet

**************************
FUNCTION MYRUN( cComando )
**************************
local oShell
TRY
   oShell := CreateObject( "WScript.Shell" )
CATCH
   TRY
      oShell := CreateObject( "WScript.Shell" )
   CATCH
      MsgStop( "Erro! ao executar um comando externo")
      RETURN(.F.)
   END
END
TRY
  oShell:Run( "%comspec% /c " + cComando, 0, .T. )
  oShell := NIL
CATCH
  winexec(cComando,2)
END
return .T.

***********************
FUNCTION MYRUN2( cRun )
***********************
Local hIn, hOut, nRet //, hProc
Local hProc := HB_OpenProcess( cRun   , @hIn, @hOut, @hOut,.T. )
            //hb_openprocess(cComando ,     ,      ,     ,.t.) 
IF hProc < 0
   FClose( hProc )
   FClose( hIn )
   FClose( hOut )
   Return(.F.)
*   ShowMsg("Error: " + valtoprg(FError()))
ENDIF

nRet := HB_ProcessValue( hProc,.f. )
IF nRet > 0
   FClose( hProc )
   FClose( hIn )
   FClose( hOut )
   Return(.F.)
endif
FClose( hProc )
FClose( hIn )
FClose( hOut )

Return(.T.)

*********************
FUNCTION SYG_GERAFILE
*********************
Local aDir1  := GETENV("LOCALAPPDATA")+ "\sygecom\*.*"
Local aDir10 := directory(aDir1,'D'), nI_FILE
Local nTAM   := LEN(GETENV("LOCALAPPDATA") + "\sygecom\")
local cPATHARQ := GETENV("LOCALAPPDATA")+ "\sygecom\"+SYG_GENERATEGUID(.F.)

IF LEN(aDir10) > 0
   FOR nI_FILE:=1 to len(aDir10)
       IF LEFT(aDir10[nI_FILE,1],nTAM)=LEFT(cPATHARQ,nTAM) // JÁ EXISTE
          cPATHARQ:=SYG_GERAFILE()
       ENDIF
   NEXT
ENDIF

RETURN(cPATHARQ)

*****************
FUNCTION GERAFILE
*****************
Local aDir1  := GETENV("temp")+ "\sy_temp\*.*"
Local aDir10 := directory(aDir1,'D'), nI_FILE
Local nTAM   := LEN(GETENV("temp") + "\sy_temp\")
local cPATHARQ := GETENV("temp")+ "\sy_temp\"+SYG_GENERATEGUID(.F.)

Public cFILE := cPATHARQ

IF LEN(aDir10) > 0
   FOR nI_FILE:=1 to len(aDir10)
       IF LEFT(aDir10[nI_FILE,1],nTAM)=LEFT(cPATHARQ,nTAM) // JÁ EXISTE
          cPATHARQ:=GERAFILE()
       ENDIF
   NEXT
ENDIF

RETURN(cPATHARQ)

******************
FUNCTION LIMPATEMP
******************
Local nI, aDir1, cTEMP_EXL:= GETENV("temp") + "\sy_temp\"  // pasta temporaria do windows
//FClose()
aDir1 := Directory(cTEMP_EXL+"*.*",'D')
FOR nI = 1 TO LEN(aDir1)
    IF aDir1[nI,3] < DATE()
       IF aDir1[nI,5] = "RA"  // atributo como somente leitura
          SetFAttr( cTEMP_EXL+aDir1[nI,1], "32" )
       ENDIF
       FERASE( cTEMP_EXL+aDir1[nI,1] )
     ENDIF  
NEXT
RETURN .T.

***********************
FUNCTION SYG_LIMPATEMP
***********************
Local nI, aDir1, cTEMP_EXL:= GETENV("LOCALAPPDATA") + "\sygecom\"  // pasta temporaria do windows
//FClose()
aDir1 := Directory(cTEMP_EXL+"*.*",'D')
FOR nI = 1 TO LEN(aDir1)
    IF aDir1[nI,3] < DATE()
       IF aDir1[nI,5] = "RA"  // atributo como somente leitura
          SetFAttr( cTEMP_EXL+aDir1[nI,1], "32" )
       ENDIF
       FERASE( cTEMP_EXL+aDir1[nI,1] )
     ENDIF    
NEXT
RETURN .T.

*********************************
FUNCTION APAGA_DBF(cPATH1,cPATH2)
*********************************
Local cARQDBF, I
Local aDBF := DIRECTORY(cPATH2)

FOR I = 1 TO LEN(aDBF)
   cARQDBF := cPATH1+aDBF[I,1]
   HW_Atualiza_Dialogo(cARQDBF)

   Ferase(cARQDBF)
NEXT
Return Nil


FUNCTION LIMPA // função para limpar a memoria do micro
  HB_GCALL(.T.)
Return nil

********************************************************************************
***************INCIO DA FUNCAO DE ABRIR ARQUIVOS********************************
********************************************************************************
STATIC FUNCTION ABRE_ARQUIVO_LIB( cHelpFile )
   LOCAL nRet, cPath, cFileName, cFileExt
   IF !FILE(cHelpFile)
      MsgStop('Arquivo não localizado, Favor revisar')
      RETURN(0)
   ENDIF

   HB_FNameSplit( cHelpFile, @cPath, @cFileName, @cFileExt )
   nRet := _OpenHelpFile( cPath, cHelpFile )
RETURN nRet

#pragma BEGINDUMP

   #pragma comment( lib, "shell32.lib" )
   #include "hbapi.h"
   #include <windows.h>
   HB_FUNC( _OPENHELPFILE )
   {
     HINSTANCE hInst;
     LPCTSTR lpPath = (LPTSTR) hb_parc( 1 );
     LPCTSTR lpHelpFile = (LPTSTR) hb_parc( 2 );
     hInst = ShellExecute( 0, "open", lpHelpFile, 0, lpPath, SW_SHOW );
     hb_retnl( (LONG) hInst );
     return;
   }
#pragma ENDDUMP


*===============================================================================
* TRAVATEC()
*-------------------------------------------------------------------------------
* Trava/Destrava o teclado

* data        autor  historico
*-------------------------------------------------------------------------------
* 2011.09.08  amb    modificada para retornar o valor logico
* 2006        ?
*-------------------------------------------------------------------------------
*  parametro 1: lógico
*  Retorno    : .t. = Teclas travadas
*               .f. = teclas destravadas
*===============================================================================
#pragma begindump
#include "windows.h"
//#if defined( __XCC__ ) || defined(  __BORLANDC__ )
#ifdef __COMPILER_MSVC2010__
// #include "winable.h"  // esse não pode rodar com MSVC
#else
 #include "winable.h"  // esse não pode rodar com MSVC
#endif
#include "hbapi.h"

HB_FUNC( TRAVATEC ){
  BlockInput( hb_parl(1));
  hb_retnl(hb_parl(1));
}
#pragma enddump


#pragma BEGINDUMP

#include "windows.h"
#include "hbapi.h"

WINUSERAPI BOOL WINAPI GetLastInputInfo(PLASTINPUTINFO);
typedef  BOOL (WINAPI *GETLASTINPUTINFO_)(PLASTINPUTINFO);

HB_FUNC( PEGAINATIVIDADE )
{
   HINSTANCE handle= LoadLibrary("user32.dll");
   if ( handle)
   {
      GETLASTINPUTINFO_ pFunc;
      pFunc = GetProcAddress( handle,"GetLastInputInfo" );
      if (pFunc)
      {
         LASTINPUTINFO lpi;

         lpi.cbSize = sizeof(LASTINPUTINFO);

         if (!pFunc(&lpi))
         {
            hb_retni(0);
         }
         else
         {
            hb_retnd( ( DOUBLE ) ( GetTickCount() - lpi.dwTime ) * 0.001 );
         }
      }
   else
      {
         hb_retni(0);
      }
   }

   if (handle)
      {
         FreeLibrary( handle);
      }
}
#pragma ENDDUMP

********************
FUNCTION VEREFICA_IP
********************
LOCAL aHosts
Local cEstacao:=netname(.f.)
InetInit()
aHosts := InetGetHosts( cEstacao )
IF aHosts == NIL
   aHosts := InetGetAlias( cEstacao )
ENDIF
IF Empty(aHosts)
   aHosts := InetGetAlias( cEstacao )
ENDIF
InetCleanup()
RETURN(IIF(!Empty(aHosts),ahosts[1],''))  


#pragma BEGINDUMP

#include "windows.h"
#include "shlobj.h"
#include "hbapi.h"
#include "math.h"
#include "hbvm.h"
#include "hbstack.h"
#include "hbapiitm.h"
#include "hbapigt.h"

HB_FUNC ( SHOWTASKBAR )      //Habilita o botao INICIAR
{
  HWND hWnd = FindWindow("Shell_TrayWnd", "");

  ShowWindow( hWnd, 1 );
}

HB_FUNC ( HIDETASKBAR )     //Desabilita o botao Iniciar
{
  HWND hWnd = FindWindow("Shell_TrayWnd", "");

  ShowWindow( hWnd, 0 );
}

HB_FUNC ( PISCA_EXE )      // VAI PISCAR O SEU EXE NA BARRA
{
    HWND  Handle = GetForegroundWindow();

    FlashWindow(Handle,TRUE); // VAI PISCAR O SEU EXE NA BARRA

    Sleep(300);    // TEMPO DE ESPERA
}


HB_FUNC ( TIRA_X )        // DESABILITA O X da janela

{
    HMENU MenuH = GetSystemMenu(GetForegroundWindow(),FALSE);

    EnableMenuItem(MenuH,SC_CLOSE,MF_GRAYED);
}

#pragma ENDDUMP

********************************************************************************
***********VEREFICA O NOME DO EXECUTAVEL E O CAMINHO DO MESMO*******************
*NomeExecutavel()    // verefica o nome
*NomeExecutavel(.t.) // verefica o caminho
********************************************************************************
FUNCTION NOMEEXECUTAVEL(lPath)
LOCAL nPos, cRet
If Empty(lpath)
   nPos:= RAT("\", hb_argv(0))
   cRet:= substr(hb_argv(0), nPos+1)
else
   cRet:= hb_argv(0)
endif
Return cRet
********************
*Retorna o caminho do EXE
FUNCTION CAMINHO_EXE
Return(Substr(Nomeexecutavel(.t.),1,(len(Nomeexecutavel(.t.))- len(Nomeexecutavel()))-1 ))

********************************************************************************
***********FIM DA ROTINA DE VEREFICAÇÃO DE EXECUTAL*****************************
********************************************************************************

********************************************************************************
***********INICIO DA ROTINA QUE VEREFICA SE O EXE JA ESTA ABERTO****************
********************************************************************************
#pragma BEGINDUMP

#include "hbapi.h"
#include <windows.h>

VOID SY_SwitchToThisWindow(  HWND hWnd,  BOOL fAltTab );
HB_FUNC( SY_FINDCONSOLEHANDLE ) //FindConsoleHandle
{
   HWND hwnd;
 AllocConsole();
    hwnd = FindWindowA("ConsoleWindowClass",NULL);
 hb_retnl( (LONG) hwnd );
}
HB_FUNC( SY_CLOSEWINDOW )
{
   hb_retl( CloseWindow( (HWND) hb_parnl(1) ) );
}

HB_FUNC( SY_FINDWINDOW )
{
   hb_retnl((ULONG) FindWindow( (LPCSTR)
   NULL, hb_parcx(1))) ;
}

HB_FUNC( SY_GETFOREGROUNDWINDOW )
{
   HWND hwnd;
   hwnd = GetForegroundWindow();
   hb_retnl( (LONG) hwnd );
}

HB_FUNC( SY_SHOWWINDOW )
{
   hb_retl( ShowWindow(
  (HWND) hb_parnl(1), hb_parni(2) ));
}

HB_FUNC( SY_SETFOREGROUNDWINDOW )
{
   hb_retl( SetForegroundWindow(
     (HWND) hb_parnl( 1 ) ) ) ;
}

HB_FUNC( SY_SWITCHTOTHISWINDOW )
{
   HWND hWnd;
   hWnd = (HWND) hb_parnl(1);
   hb_retl(SetForegroundWindow(hWnd));
}

#pragma ENDDUMP

********************************************************************************
***********FIM    DA ROTINA QUE VEREFICA SE O EXE JA ESTA ABERTO****************
********************************************************************************

****************************
FUNCTION DATA_HORA_ARQ(vArq)
****************************
Local aDir, aRet, aRet2
SET CENTURY ON
SET DATE BRITISH
SET EPOCH TO 2000
Dirchange(CAMINHO_EXE())

aDir  := Directory( vArq )
aRet  := Transform(DtoC(aDir[1,3]),"@d")
aRet2 := aDir[1,4]
Return( aRet + " - " + aRet2 )

*************************************
FUNCTION FOCALIZA_APP(cEXE,lRestaura)
*************************************
local oWnd
IF cEXE=Nil
   RETURN NIL
ENDIF
oWnd := SY_FindWindow(cEXE)
SY_SwitchToThisWindow(oWnd,.f.)
IF lRestaura=Nil
   SY_showWindow( oWnd, 3 )
ELSE
   SY_showWindow( oWnd, 1 )
ENDIF
Return Nil

***********************
FUNCTION FOCALIZA(oOBJ)
***********************
oOBJ:setfocus()
Return .T.

***********************************
FUNCTION VALIDA_PISPASEP(nPISPASEP)
***********************************
LOCAL nTOT := 0
LOCAL cMUL := "3298765432"
LOCAL rO
LOCAL cPIS:=ALLTRIM(STR(nPISPASEP))

IF LEN(cPIS) <> 11
   RETURN (.F.)
ENDIF

FOR rO = 1 TO 10
   nTOT += VAL(SUBSTR(cPIS,rO,1)) * VAL(SUBSTR(cMUL,rO,1))
NEXT

nTOT:=MOD(nTOT,11)

IF nTOT > 0
   nTOT:=INT(11-nTOT)
ENDIF
IF nTOT = VAL(SUBSTR(cPIS,rO,1))
   RETURN (.T.)
ENDIF
RETURN (.F.)

*****************************************
FUNCTION MDI_ABERTA(cTITLE,lFOCUS,lCLOSE)
*****************************************
LOCAL oDLGSMDI    := HWindow():aWindows    // apenas janelas MDI abertas
LOCAL nHANDLE_MAIN:= oTelaPrincipal:handle // handle da janela principal
LOCAL lRET       :=.F.
LOCAL i2

IF lFOCUS=NIL
   lFOCUS:=.F.
ENDIF
IF lCLOSE=NIL
   lCLOSE:=.F.
ENDIF

FOR i2= 1 TO LEN(oDLGSMDI)
   IF i2 > 2
      IF nHANDLE_MAIN != oDLGSMDI[i2]:handle
         IF cTITLE = oDLGSMDI[i2]:TITLE
            oDLGSMDI[i2]:Restore()
            IF lFOCUS
               SetFocus(oDLGSMDI[i2]:handle)
               oDLGSMDI[i2]:SHOW()
               oDLGSMDI[i2]:MAXIMIZE()
            ENDIF
            IF lCLOSE
               oDLGSMDI[i2]:CLOSE()
            ENDIF
            lRET:=.T.
            EXIT
         ENDIF
      ENDIF
   ENDIF
NEXT

RETURN(lRET)

/*

GETDESKTOPWIDTH(),GETDESKTOPHEIGHT()

oTelaPrincipal:nWidth,oTelaPrincipal:nHeight

SHOWMSG({ HWG_GETDESKTOPWIDTH_VS(),HWG_GETDESKTOPHEIGHT_VS(),;
          HWG_GETDESKTOPWIDTH()   ,HWG_GETDESKTOPHEIGHT() })
*/
FUNCTION GETDESKTOPHEIGHT
LOCAL nRET:=0
IF HWG_GETNUMMONITORS()>1
   TRY
      nRET:=oTelaPrincipal:nHeight
   CATCH
      nRET:=HWG_GETDESKTOPHEIGHT()
   END
ELSE
   nRET:=HWG_GETDESKTOPHEIGHT()
ENDIF
RETURN(nRET)

FUNCTION GETDESKTOPWIDTH
LOCAL nRET:=0
IF HWG_GETNUMMONITORS()>1
   TRY
      nRET:=oTelaPrincipal:nWidth
   CATCH
      nRET:=HWG_GETDESKTOPWIDTH()
   END
ELSE
   nRET:=HWG_GETDESKTOPWIDTH()
ENDIF
RETURN(nRET)

***************************
FUNCTION DLG_ABERTA(cTITLE,lFOCUS)
***************************
LOCAL oDLGS    := HDIALOG():ADIALOGS        //APENAS DIALOGS
LOCAL nHANDLE_MAIN:= oTelaPrincipal:handle // handle da janela principal
LOCAL lRET       :=.F.
LOCAL i2

IF lFOCUS=NIL
   lFOCUS:=.F.
ENDIF

FOR i2= 1 TO LEN(oDLGS)
   IF cTITLE = oDLGS[i2]:TITLE
      oDLGS[i2]:Restore()
      IF lFOCUS
         SetFocus(oDLGS[i2]:handle)
      ENDIF
      lRET:=.T.
      EXIT
   ENDIF
NEXT
RETURN(lRET)

***************************************
FUNCTION FECHA_JANELAS(oWnd,lFECHATUDO)
***************************************
LOCAL oDLGS      := HDIALOG():ADIALOGS
LOCAL oDLGSMODAL := HDIALOG():aModalDialogs
LOCAL oDLGSMDI   := HWindow():aWindows
LOCAL nHANDLE    := oWnd:handle
LOCAL lRET       :=.T.
LOCAL nI, nI2

IF lFECHATUDO=NIL
   lFECHATUDO:=.F.
ENDIF

IF LEN(oDLGS)>0
   FOR nI= 1 TO LEN(oDLGS)
      IF lFECHATUDO
         oDLGS[nI]:close()
      ELSE
         lRET:=.F.
      ENDIF
   NEXT
ENDIF

IF LEN(oDLGSMODAL)>0
   FOR nI= 1 TO LEN(oDLGSMODAL)
      IF lFECHATUDO
         oDLGSMODAL[nI]:close()
      ELSE
         lRET:=.F.
      ENDIF
   NEXT
ENDIF

FOR nI2= 1 TO LEN(oDLGSMDI)
   IF nI2 > 3
      IF nHANDLE != oDLGSMDI[nI2]:handle
         lRET:=.F.
         //ShowMsg(valtoprg(oDLGSMDI[i]:handle))
         //oDLGSMDI[i2]:close()
      ENDIF
   ENDIF
NEXT
RETURN(lRET)

******************************************
FUNCTION CARACTER_PROIBIDO(cBUSCA,lEXTEND)
/*
Revisa se na string tem algum caracter que não pode ser usado
*/
******************************************
LOCAL nI, lRET:=.T., aVETOR:={'.',',','-','/','\','|','=','_','+','(',')','*','&','@','!',':','?','>','<'}

IF lEXTEND=NIL
   lEXTEND=.T.
ENDIF

IF lEXTEND
   AADD(aVETOR,';')
ENDIF
FOR nI=1 to 30
    AADD(aVETOR,CHR(nI))
NEXT

IF EMPTY(cBUSCA)
   RETURN(lRET)
ENDIF

FOR nI=1 to LEN(aVETOR)
   IF AT(aVETOR[nI],cBUSCA)>0
      ShowMsg('Nesse campo não pode haver o caracter: ( ' + aVETOR[nI] +' ), favor revisar ou redigitar o campo sem usar o CTRL+C / CTRL+V' )
      lRET:=.F.  //SE ACHAR RETORNA FALSO
   ENDIF
NEXT

RETURN(lRET)

********************************
FUNCTION REMOVE_CHR(cSTRING_TMP)
********************************
LOCAL XYZ
IF cSTRING_TMP=NIL .OR. VALTYPE(cSTRING_TMP)<>'C'
   cSTRING_TMP:=''
ENDIF   
cSTRING_TMP:=ALLTRIM(cSTRING_TMP)
FOR XYZ:=1 TO 31
   IF CHR(XYZ)$cSTRING_TMP
      cSTRING_TMP:=StrTran( cSTRING_TMP, CHR(XYZ), IF(XYZ=13,';',NIL) )
   ENDIF
NEXT
cSTRING_TMP:=TIRAACENTO(cSTRING_TMP)
RETURN(cSTRING_TMP)

FUNCTION CLEAR_CHAR(cSTR,cSUBISTITUIR)
/*
   limpa os caracteres "estranhos" de dentro da string
   Mauricio Cruz - 02/05/2011
*/
LOCAL mI:=0, cRET:=cSTR

IF cSUBISTITUIR=NIL
   cSUBISTITUIR:=''
ENDIF

FOR mI:=1 TO 31
   IF CHR(mI)$cRET
      cRET:=StrTran( cRET, CHR(mI),cSUBISTITUIR)
   ENDIF
NEXT
IF cSUBISTITUIR=NIL
   cRET:=ALLTRIM(cRET)
ENDIF
RETURN(cRET)

FUNCTION LIMPA_CARACTER_CNPJ(cSTRING)
cSTRING:=StrTran(cSTRING,',','',1 )
cSTRING:=StrTran(cSTRING,'.','',1 )
cSTRING:=StrTran(cSTRING,'-','',1 )
cSTRING:=StrTran(cSTRING,'/','',1 )
cSTRING:=StrTran(cSTRING,'\','',1 )
RETURN(cSTRING)

************************************************************
FUNCTION REMOVE_CARACTER(cSTRING,lEXTENDIDO,lREMOVE_VIRGULA)
************************************************************
IF lEXTENDIDO=NIL
   lEXTENDIDO:=.T.
ENDIF
IF lREMOVE_VIRGULA=NIL
   lREMOVE_VIRGULA:=.T.
ENDIF   
IF lREMOVE_VIRGULA
   cSTRING:=StrTran(cSTRING,',',' ',1 )
ENDIF   
cSTRING:=StrTran(cSTRING,"'",' ',1 )
cSTRING:=StrTran(cSTRING,"'",' ',1 )
cSTRING:=StrTran(cSTRING,"[",' ',1 )
cSTRING:=StrTran(cSTRING,"]",' ',1 )
IF lEXTENDIDO
   cSTRING:=StrTran(cSTRING,CHR(10),'',1 )
   cSTRING:=StrTran(cSTRING,CHR(13),'',1 )
ENDIF
RETURN(cSTRING)

**************************************************************
FUNCTION VALIDACARACTERES(cVALIDATEXTO,lEXTENDIDO)
/*
Revisa na string algum caracter que não pode ser usado
Criado por Marcos Silva - 08/07/2015 - 1654 - mySuite - Rejeição Carta de Correção
Adaptado para uso global por Silvane Patrícia em 03/10/2016 - My suite 3841/3559
*/
**************************************************************
LOCAL nI, lOk:=.F.
LOCAL aVETOR:={',','|','=','_','+','(',')','*','@','!',':','?','>','<','#','$','%',"'",'""','¬','£'}
LOCAL cAux:= ALLTRIM(cVALIDATEXTO)
LOCAL cTextLimpo:=""
LOCAL nPos:=0

IF lEXTENDIDO=NIL
 lEXTENDIDO:=.F.
ENDIF 

IF lEXTENDIDO
   AADD(aVETOR,' ')
   AADD(aVETOR,'-')
ENDIF 

FOR nI = 1 to LEN(aVETOR)
   nPos:=At(aVETOR[nI],cAux,0)
   if nPos > 0
      lOk:=.T. //Encontrou caracteres inválidos
      EXIT
   ENDIF
NEXT
RETURN (lOk)


******************************
FUNCTION RemoveAcento(__cText,lEXTD)
******************************
IF lEXTD=NIL
   lEXTD:=.T.
ENDIF
  __cText:= StrTran(__cText,"Ã","A")
  __cText:= StrTran(__cText,"Â","A")
  __cText:= StrTran(__cText,"Á","A")
  __cText:= StrTran(__cText,"Ä","A")
  __cText:= StrTran(__cText,"À","A")
  __cText:= StrTran(__cText,"ã","a")
  __cText:= StrTran(__cText,"â","a")
  __cText:= StrTran(__cText,"á","a")
  __cText:= StrTran(__cText,"ä","a")
  __cText:= StrTran(__cText,"à","a")

  __cText:= StrTran(__cText,"É","E")
  __cText:= StrTran(__cText,"Ê","E")
  __cText:= StrTran(__cText,"Ë","E")
  __cText:= StrTran(__cText,"È","E")
  __cText:= StrTran(__cText,"é","e")
  __cText:= StrTran(__cText,"ê","e")
  __cText:= StrTran(__cText,"ë","e")
  __cText:= StrTran(__cText,"è","e")
  __cText:= StrTran(__cText,"Í","I")
  __cText:= StrTran(__cText,"Î","I")
  __cText:= StrTran(__cText,"Ï","I")
  __cText:= StrTran(__cText,"Ì","I")
  __cText:= StrTran(__cText,"í","i")
  __cText:= StrTran(__cText,"î","i")
  __cText:= StrTran(__cText,"ï","i")
  __cText:= StrTran(__cText,"ì","i")
  __cText:= StrTran(__cText,"Ó","O")
  __cText:= StrTran(__cText,"Õ","O")
  __cText:= StrTran(__cText,"Ô","O")
  __cText:= StrTran(__cText,"ó","O")
  __cText:= StrTran(__cText,"Ö","O")
  __cText:= StrTran(__cText,"Ò","O")
  __cText:= StrTran(__cText,"õ","o")
  __cText:= StrTran(__cText,"ô","o")
  __cText:= StrTran(__cText,"ó","o")
  __cText:= StrTran(__cText,"ö","o")
  __cText:= StrTran(__cText,"ò","o")
  __cText:= StrTran(__cText,"º","")
  __cText:= StrTran(__cText,"ª","")
  __cText:= StrTran(__cText,"¹","")
  __cText:= StrTran(__cText,"²","")
  __cText:= StrTran(__cText,"³","")
  __cText:= StrTran(__cText,"°","")
  __cText:= StrTran(__cText,CHR(176),"")
  __cText:= StrTran(__cText,"Û","U")
  __cText:= StrTran(__cText,"Ú","U")
  __cText:= StrTran(__cText,"Ü","U")
  __cText:= StrTran(__cText,"Ù","U")
  __cText:= StrTran(__cText,"û","u")
  __cText:= StrTran(__cText,"ú","u")
  __cText:= StrTran(__cText,"ü","u")
  __cText:= StrTran(__cText,"ù","u")
  __cText:= StrTran(__cText,"Ç","C")
  __cText:= StrTran(__cText,"ç","c")
  IF lEXTD
     __cText:= StrTran(__cText,"#","-")
  ENDIF   
RETURN(__cText)

**************************
FUNCTION TIRAACENTO(cText)
**************************
cText:= StrTran(cText,"Ã","A")
cText:= StrTran(cText,"Â","A")
cText:= StrTran(cText,"Á","A")
cText:= StrTran(cText,"Ä","A")
cText:= StrTran(cText,"À","A")
cText:= StrTran(cText,"ã","a")
cText:= StrTran(cText,"â","a")
cText:= StrTran(cText,"á","a")
cText:= StrTran(cText,"ä","a")
cText:= StrTran(cText,"à","a")

cText:= StrTran(cText,"É","E")
cText:= StrTran(cText,"Ê","E")
cText:= StrTran(cText,"Ë","E")
cText:= StrTran(cText,"È","E")
cText:= StrTran(cText,"é","e")
cText:= StrTran(cText,"ê","e")
cText:= StrTran(cText,"ë","e")
cText:= StrTran(cText,"è","e")
cText:= StrTran(cText,"Í","I")

cText:= StrTran(cText,"Î","I")
cText:= StrTran(cText,"Ï","I")
cText:= StrTran(cText,"Ì","I")
cText:= StrTran(cText,"í","i")
cText:= StrTran(cText,"î","i")
cText:= StrTran(cText,"ï","i")
cText:= StrTran(cText,"ì","i")

cText:= StrTran(cText,"Ó","O")
cText:= StrTran(cText,"Õ","O")
cText:= StrTran(cText,"Ô","O")
cText:= StrTran(cText,"ó","O")
cText:= StrTran(cText,"Ö","O")
cText:= StrTran(cText,"Ò","O")
cText:= StrTran(cText,"õ","o")
cText:= StrTran(cText,"ô","o")
cText:= StrTran(cText,"ó","o")
cText:= StrTran(cText,"ö","o")
cText:= StrTran(cText,"ò","o")
cText:= StrTran(cText,"º","")
cText:= StrTran(cText,"ª","")
cText:= StrTran(cText,CHR(166),"")
cText:= StrTran(cText,CHR(167),"")
cText:= StrTran(cText,CHR(176),"")

cText:= StrTran(cText,"Û","U")
cText:= StrTran(cText,"Ú","U")
cText:= StrTran(cText,"Ü","U")
cText:= StrTran(cText,"Ù","U")
cText:= StrTran(cText,"û","u")
cText:= StrTran(cText,"ú","u")
cText:= StrTran(cText,"ü","u")
cText:= StrTran(cText,"ù","u")

cText := StrTran(cText,"Ç","C")
cText := StrTran(cText,"ç","c")

cText := StrTran(cText,">","-")
cText := StrTran(cText,"<","-")
cText := StrTran(cText,"#","-")
cText := StrTran(cText,"","-")

RETURN(cText)

/*
FUNCAO QUE MOSTRA POR EXTENSO O VALOR NUMERICO
*/
**********************************
FUNCTION EXT(valor,larg,sing,plur)
**********************************
LOCAL unidades:={"um","doIs","tres","quaTro","cinCo","seIs","seTe","oiTo","noVe"},;
      unidonze:={"onZe","doZe","treZe","quaTorZe","quinZe","deZesSeIs",;
                 "deZesSeTe","deZoiTo","deZeNoVe"},;
      decimais:={"","vinTe","trinTa","quaRenTa","cinQuenTa","sesSenTa","seTenTa",;
                 "oiTenTa","noVenTa"},;
      centos:={"cenTo","duZenTos","treZenTos","quaTroCenTos","quiNhenTos","seIsCenTos",;
               "seTeCenTos","oiToCenTos","noVeCenTos"},;
      vEXTENSO:="", cnum:=LEFT(STR(valor,12,2),9), volta:="", calex:="", compri:=0, cents:="", vez:=0, rest:=""
LOCAL nCONTAR

* cheques Milhoes
IF SUBSTR(cnum,1,1)>"0"
    vEXTENSO=centos[VAL(SUBSTR(cnum,1,1))]
ENDIF
IF vEXTENSO > " "
    IF SUBSTR(cnum,2,2) <> "00"
        vEXTENSO = vEXTENSO + " e "
    ENDIF
ENDIF

*
DO CASE
    CASE SUBSTR(cnum,2,1)>"1"
        vEXTENSO=vEXTENSO+decimais[VAL(SUBSTR(cnum,2,1))]
        IF vEXTENSO > " "
            IF SUBSTR(cnum,3,1) <> "0"
                vEXTENSO = vEXTENSO + " e "
            ENDIF
        ENDIF
        IF SUBSTR(cnum,3,1)>"0"
            vEXTENSO=vEXTENSO+unidades[VAL(SUBSTR(cnum,3,1))]
        ENDIF
        vEXTENSO=vEXTENSO+" miLhoes"

    CASE SUBSTR(cnum,2,1)="1"
       	vEXTENSO=vEXTENSO+unidonze[VAL(SUBSTR(cnum,3,1))]+" miLhoes"

    CASE SUBSTR(cnum,2,2)="00"
     	vEXTENSO=SUBSTR(vEXTENSO,1,LEN(vEXTENSO)) + " miLhoes"
        IF SUBSTR(cnum,1,1)="1"
            vEXTENSO = "cem miLhoes"
        ENDIF

    CASE SUBSTR(cnum,3,1)>" "
        vEXTENSO=vEXTENSO+unidades[VAL(SUBSTR(cnum,3,1))]+" miLhoes"

ENDCASE
IF vEXTENSO = "um miLhoes"
    vEXTENSO = "um miLhao"
ENDIF
IF SUBSTR(cnum,4,6) = "000000"
    vEXTENSO = vEXTENSO+" de"
ENDIF

* cheques de Centenas e Milhares

IF vEXTENSO > " "
    IF SUBSTR(cnum,4,3) <> "000"
        vEXTENSO = vEXTENSO+", "
    ENDIF
ENDIF

IF SUBSTR(cnum,4,1)>" "
    IF SUBSTR(cnum,4,1)<>"0"
        vEXTENSO=vEXTENSO+centos[VAL(SUBSTR(cnum,4,1))]
    ENDIF
ENDIF
IF vEXTENSO > " "
    IF SUBSTR(cnum,5,2) <> "00"
        IF RIGHT(vEXTENSO,2) = ", "
          vEXTENSO = SUBSTR(vEXTENSO,1,LEN(vEXTENSO)-2) + " e "
        ELSE
          vEXTENSO = RTRIM(vEXTENSO) + " e "
        ENDIF
    ENDIF
ENDIF

DO CASE
    CASE SUBSTR(cnum,5,1)>"1"
        vEXTENSO=vEXTENSO+decimais[VAL(SUBSTR(cnum,5,1))]
        IF vEXTENSO > " "
            IF SUBSTR(cnum,6,1) <> "0"
                vEXTENSO = vEXTENSO + " e "
            ENDIF
       	ENDIF
       	IF SUBSTR(cnum,6,1)>"0"
            vEXTENSO=vEXTENSO+unidades[VAL(SUBSTR(cnum,6,1))]
       	ENDIF
       	vEXTENSO=vEXTENSO+" mil"

    CASE SUBSTR(cnum,5,1)="1"
        IF SUBSTR(cnum,6,1)<>"0"
            vEXTENSO=vEXTENSO+unidonze[VAL(SUBSTR(cnum,6,1))]+" mil"
        ELSE
            vEXTENSO=vEXTENSO+"dez mil"
        ENDIF

    CASE SUBSTR(cnum,5,2)="00"
	IF RIGHT(vEXTENSO,2) <> "de"
            IF SUBSTR(cnum,4,3) <> "000"
             vEXTENSO=SUBSTR(vEXTENSO,1,LEN(vEXTENSO)) + " mil"
            ENDIF
       	    IF SUBSTR(cnum,4,1)="1"
                vEXTENSO = LEFT(vEXTENSO,LEN(vEXTENSO)-9)+"cem mil"
	    ENDIF
	ENDIF

    CASE SUBSTR(cnum,6,1)>" "
        vEXTENSO=vEXTENSO+unidades[VAL(SUBSTR(cnum,6,1))]+" mil"

ENDCASE

* cheques Centenas
IF vEXTENSO > " "
    IF SUBSTR(cnum,7,3) <> "000"
        vEXTENSO = vEXTENSO + ", "
    ENDIF
ENDIF
IF SUBSTR(cnum,7,1)>"0"
    vEXTENSO=vEXTENSO+centos[VAL(SUBSTR(cnum,7,1))]
ENDIF

IF SUBSTR(cnum,7,3) = "100"
    vEXTENSO = SUBSTR(vEXTENSO,1,LEN(vEXTENSO)-5) + "cem"
ENDIF

* cheques dezenas e unidades

IF vEXTENSO > " "
    IF SUBSTR(cnum,8,2) <> "00"
        IF RIGHT(vEXTENSO,2)=", "
          vEXTENSO = SUBSTR(vEXTENSO,1,LEN(vEXTENSO)-2) + " e "
        ELSE
          vEXTENSO = RTRIM(vEXTENSO) + " e "
        ENDIF
    ENDIF
ENDIF
DO CASE
    CASE SUBSTR(cnum,8,1)>"1"
        vEXTENSO=vEXTENSO+decimais[VAL(SUBSTR(cnum,8,1))]
	IF RIGHT(cnum,1)>"0"
            vEXTENSO=vEXTENSO+" e "+ unidades[VAL(RIGHT(cnum,1))]
       	ENDIF
    CASE SUBSTR(cnum,8,1)="1"
        IF RIGHT(cnum,1)<>"0"
    	    vEXTENSO=vEXTENSO+unidonze[VAL(RIGHT(cnum,1))]
        ELSE
            vEXTENSO=vEXTENSO+"dez"
        ENDIF

    CASE RIGHT(cnum,2)=" 0"
        vEXTENSO=" "

    OTHERWISE
        IF RIGHT(cnum,1)<>"0"
            vEXTENSO=vEXTENSO+unidades[VAL(RIGHT(cnum,1))]
        ENDIF
ENDCASE
IF vEXTENSO = "cem e "
    vEXTENSO = "cem"
ENDIF

*
cents=RIGHT(STR(valor,12,2),2)
vEXTENSO=RTRIM(vEXTENSO)+" "+ALLTRIM(plur)
IF vEXTENSO = "um "+ALLTRIM(plur)
    vEXTENSO = "um "+ALLTRIM(sing)
ENDIF

* cheque Centavos
IF LTRIM(vEXTENSO) = ALLTRIM(plur)
    vEXTENSO =""
ENDIF
IF cents <> "00"
    IF vEXTENSO > " "
        vEXTENSO = vEXTENSO + " e "
    ENDIF
ENDIF

DO CASE
    CASE SUBSTR(cents,1,1)>"1"
    	vEXTENSO=vEXTENSO+decimais[VAL(SUBSTR(cents,1,1))]
       	IF RIGHT(cents,1)>"0"
            vEXTENSO=vEXTENSO+" e "+ unidades[VAL(RIGHT(cents,1))]
       	ENDIF
    CASE SUBSTR(cents,1,1)="1"
        IF RIGHT(cents,1)="0"
           vEXTENSO=vEXTENSO+"dez"
        ELSE
           vEXTENSO=vEXTENSO+unidonze[VAL(RIGHT(cents,1))]
        ENDIF

    OTHERWISE
        IF RIGHT(cents,1)<>"0"
            vEXTENSO=vEXTENSO+unidades[VAL(RIGHT(cents,1))]
        ENDIF
ENDCASE
IF cents <> "00"
    vEXTENSO=vEXTENSO + " cenTaVos"
ENDIF
IF cents = "01"
    vEXTENSO=SUBSTR(vEXTENSO,1,LEN(vEXTENSO)-8) + "cenTaVo"
ENDIF

compri = LEN(vEXTENSO)

IF compri > larg
    vez:=compri/larg
    vez:=INT(IF((vez-INT(vez))>0,vez+1,vez))
    rest:=vEXTENSO
    DO WHILE vez!=0
        IF SUBSTR(rest,larg,1)<>" "
            IF ISUPPER(SUBSTR(rest,larg,1))
                calex:=SUBSTR(rest,1,larg-1)+"-"
                nCONTAR = larg
            ENDIF
        ELSE
            calex:=SUBSTR(rest,1,larg-1)+"*"
            nCONTAR = larg
        ENDIF
        IF SUBSTR(rest,larg+1,1)=" "
            calex:=SUBSTR(rest,1,larg)
            nCONTAR = larg+1
        ENDIF
        IF EMPT(calex)
            nCONTAR = larg
        ENDIF
        DO WHILE .NOT. SUBSTR(rest,nCONTAR,1)=" " .AND. EMPTY(calex)
            IF ISUPPER(SUBSTR(rest,nCONTAR,1))
                calex:=SUBSTR(rest,1,nCONTAR-1)+"-"+REPLIC("*",larg-nCONTAR)
                EXIT
            ENDIF
            nCONTAR-=1
        ENDDO
        IF EMPTY(calex)
            calex:=SUBSTR(rest,1,nCONTAR-1)+REPLI("*",larg-(nCONTAR-1))
        ENDIF
        volta+=calex
        calex:=""
        rest:=LTRIM(SUBSTR(rest,nCONTAR))
        vez-=1
        IF vez=1
            volta=volta+rest+REPLIC("*",larg-LEN(rest))
            EXIT
        ENDIF
    ENDDO
ELSE
    volta:=vEXTENSO+REPLIC("*",larg-compri)
ENDIF
RETURN(UPPER(volta))

// linhas do extenso em vetor
STATIC FUNCTION AEXT(nValor, nLargura) //--> aExtenso
local aExtenso[0]
local cExtenso

cExtenso:=EXT( nValor, nLargura, "reAl","reAIs" )

do while ! EMPTY(cExtenso)
   AADD( aExtenso, LEFT(cExtenso,nLargura) )
   cExtenso:=SUBSTR(cExtenso,nLargura+1)

enddo

return aExtenso

*********************************
FUNCTION RIGHT_NUM(nVALOR,nCASAS)
*********************************
/*
Leonardo Machado
Função para retornar os ultimos numeros de um numero inteiro
Data: 23/02/2011
*/
LOCAL nRET:=0
IF EMPTY(nVALOR)
   nVALOR=0
ENDIF

IF EMPTY(nCASAS)
   nCASAS:=0
ENDIF

IF nVALOR > 0
  IF LenNum(nVALOR) > nCASAS
     nRET:=VAL(RIGHT(ALLTRIM(STR(nVALOR)),nCASAS))
  ELSE
     nRET:=nVALOR
  ENDIF
ENDIF
RETURN(nRET)


***********************
FUNCTION CALCULO_PASCOA
***********************
/*
Leonardo Machado
Função para calcular a data da Pascoa
Fonte: http://pt.wikipedia.org/wiki/Cálculo_da_Páscoa
Data: 23/02/2011
Valido do ano de: 1900 até: 2199
*/
local a, b, c, d, e, dRET:=CTOD(SPACE(8)), nANO:=YEAR(DATE()), X:=24, Y:=5

IF nANO >= 2100 .AND. nANO <= 2199
   Y:=6
ENDIF

a=MOD(nANO,19)
b=MOD(nANO,4)
c=MOD(nANO,7)
d=MOD((19*a)+X,30)
e=MOD(((2*b)+(4*c)+(6*d)+Y),7)

if (d+e)<10
   dRET:=CTOD(ALLTRIM(STR( INT(d+e+22) ))+'/03/'+ALLTRIM(STR(nANO)))
else
   dRET:=CTOD(ALLTRIM(STR( INT(d+e-9)))+'/04/'+ALLTRIM(STR(nANO)))
endif
RETURN(dRET)

*******************************
FUNCTION CRIAR_ATALHO(cNOMESIS)
*******************************
Local error, aShortCut, oWSHShell

IF FILE(GETENV('HOMEDRIVE')+GETENV('HOMEPATH')+'\Desktop\'+cNOMESIS+".lnk")
   ShowMsg('Já existe o Icone na Area de Trabalho, Favor revisar')
   RETURN .F.
ENDIF

IF !MsgYesNo('Não foi localizado o Icone na area de Trabalho para o Sistema, Deseja Criar Agora ?')
   RETURN .F.
ENDIF

TRY
   oWSHShell:= CreateObject("WScript.Shell")
CATCH error
   ShowMsg('Não foi possivel criar o icone na area de trabalho, Favor revisar')
   RETURN .F.
END

IF IsDirectory(GETENV("HOMEDRIVE")+GETENV("HOMEPATH")+"\Desktop" ) = .F.
   Release oWSHShell
   ShowMsg('Não foi possivel criar o icone na area de trabalho, Favor revisar')
   RETURN .F.
ENDIF
aShortCut:= oWSHShell:CreateShortcut(GETENV('HOMEDRIVE')+GETENV('HOMEPATH')+'\Desktop\'+ cNOMESIS+".lnk")
aShortCut:TargetPath       := CAMINHO_EXE()+'\'+ Nomeexecutavel() //GETENV("HOMEDRIVE")+GETENV("HOMEPATH")+"\Desktop"
aShortCut:WorkingDirectory := CAMINHO_EXE()+'\'
//aShortCut:IconLocation     := "Z:\"+ Nomeexecutavel() //icone do sistema
aShortCut:Save()
Release oWSHShell
IF !FILE(GETENV('HOMEDRIVE')+GETENV('HOMEPATH')+'\Desktop\'+ cNOMESIS+'.lnk')
   ShowMsg('Não foi possivel criar o icone na area de trabalho, Favor revisar')
   Return .F.
ENDIF
Return .T.

FUNCTION COLORHEAD(oOBJ,nRED,nTOT,nHeadColor,nHeadColor_Ord)
/*
   muda a cor do titulo clicado na browse
   Mauricio Cruz - 28/04/2011
   Alterado por João Alpande 21/01/2021
*/
LOCAL mI

nHeadColor:=IF(nHeadColor=Nil,x_BLACK,nHeadColor)
nHeadColor_Ord:=IF(nHeadColor_Ord=Nil,x_RED,nHeadColor_Ord)

FOR mI:=1 TO nTOT
   IF LEN(oOBJ:aColumns) >= mI
     oOBJ:aColumns[mI]:headColor := nHeadColor
   ENDIF
NEXT
oOBJ:aColumns[nRED]:headColor := nHeadColor_Ord
oOBJ:oHeadFont := HFont():Add( '',0,-11,700,,,)
RETURN(.T.)


****************************************
FUNCTION calcula_intervalo(nfator,ctemp)
****************************************

/* Faz arrendondamento em numero sexagesimal quando minuto exceder 60 ou 90
   promovendo a correta distribuicao

   Paulo Del Pino - 08/05/2011 */

LOCAL cH1:=Space(3)  ,;
      cH2:=Space(3)  ,;
      cH3:=Space(3)  ,;
      cM1:=Space(3)  ,;
      cM2:=Space(3)  ,;
      cM3:=Space(3)  ,;
      nH1:=0         ,;
      nH2:=0         ,;
      nH3:=0         ,;
      nM1:=0         ,;
      nM2:=0         ,;
      nM3:=0

cTemp:=STRZERO(nFator)

IF(LEN(ctemp)=3,cH1:=LEFT(ctemp,1),)
IF(LEN(ctemp)=4,cH1:=LEFT(ctemp,2),)
IF(LEN(ctemp)=5,cH1:=LEFT(ctemp,3),)

cM1:=RIGHT(ctemp,2)

nH1 := VAL(ch1)
nM1 := VAL(cM1)
nH3 := VAL(cH1)

&& Recalcula caso ultrapasse 60  minutos

IF nM1 > 60 .AND. nM1 < 91
   nM3 := nM1-60
   cM3 := Alltrim(STR(nM3))
   nH3++
   ctemp:=Alltrim(STR(nH3))+Alltrim(STR(nM3))
   Return (ctemp)
End

&& Recalcula caso ultrapasse 90 minutos

IF nM1 > 91 .AND. nM1 < 121
   nM3 := 120-nM1
   cM3 := Alltrim(STR(nM3))
   nH3++
   ctemp:=Alltrim(STR(nH3))+Alltrim(STR(nM3))
End

Return Nil

FUNCTION CLEARARRAY(aARRAY)
/*
   limpa todos os registros de dentro da array
   Mauricio Cruz - 08/06/2010
*/
LOCAL mI:=0

WHILE LEN(aARRAY)>0
   ADEL(aARRAY,1,.T.)
ENDDO
FOR mI:=1 TO LEN(aARRAY)
  ADEL(aARRAY,mI,.T.)
NEXT
RETURN(.T.)

****************************
FUNCTION FWRITELINE(vP1,vP2)
****************************
FWrite( vP1, vP2 + Chr(13)+Chr(10) )
Return NIL

****************************************************************************************
FUNCTION BUSCA_MESANO(cMES,cANO,dDATAINI_TEMP,dDATAFIM_TEMP,oDATAINI_TEMP,oDATAFIM_TEMP)
****************************************************************************************
IF cMES="JANEIRO"
   dDATAINI_TEMP :=CTOD("01/01/"+cANO)
   dDATAFIM_TEMP :=CTOD("31/01/"+cANO)
ELSEIF cMES="FEVEREIRO"
   dDATAINI_TEMP :=CTOD("01/02/"+cANO)
   IF IsBisexto( VAL(cANO) )
      dDATAFIM_TEMP:=CTOD("29/02/"+cANO)
   ELSE
      dDATAFIM_TEMP:=CTOD("28/02/"+cANO)
   ENDIF
ELSEIF cMES="MARÇO"
   dDATAINI_TEMP :=CTOD("01/03/"+cANO)
   dDATAFIM_TEMP :=CTOD("31/03/"+cANO)
ELSEIF cMES="ABRIL"
   dDATAINI_TEMP :=CTOD("01/04/"+cANO)
   dDATAFIM_TEMP :=CTOD("30/04/"+cANO)
ELSEIF cMES="MAIO"
   dDATAINI_TEMP :=CTOD("01/05/"+cANO)
   dDATAFIM_TEMP :=CTOD("31/05/"+cANO)
ELSEIF cMES="JUNHO"
   dDATAINI_TEMP :=CTOD("01/06/"+cANO)
   dDATAFIM_TEMP :=CTOD("30/06/"+cANO)
ELSEIF cMES="JULHO"
   dDATAINI_TEMP :=CTOD("01/07/"+cANO)
   dDATAFIM_TEMP :=CTOD("31/07/"+cANO)
ELSEIF cMES="AGOSTO"
   dDATAINI_TEMP :=CTOD("01/08/"+cANO)
   dDATAFIM_TEMP :=CTOD("31/08/"+cANO)
ELSEIF cMES="SETEMBRO"
   dDATAINI_TEMP :=CTOD("01/09/"+cANO)
   dDATAFIM_TEMP :=CTOD("30/09/"+cANO)
ELSEIF cMES="OUTUBRO"
   dDATAINI_TEMP :=CTOD("01/10/"+cANO)
   dDATAFIM_TEMP :=CTOD("31/10/"+cANO)
ELSEIF cMES="NOVEMBRO"
   dDATAINI_TEMP :=CTOD("01/11/"+cANO)
   dDATAFIM_TEMP :=CTOD("30/11/"+cANO)
ELSEIF cMES="DEZEMBRO"
   dDATAINI_TEMP :=CTOD("01/12/"+cANO)
   dDATAFIM_TEMP :=CTOD("31/12/"+cANO)
ENDIF

IF oDATAINI_TEMP<>NIL
   oDATAINI_TEMP:SetText( dDATAINI_TEMP  )
   oDATAINI_TEMP:REFRESH()
ENDIF

IF oDATAFIM_TEMP<>NIL
   oDATAFIM_TEMP:SetText( dDATAFIM_TEMP  )
   oDATAFIM_TEMP:REFRESH()
ENDIF

Return(.T.)

*********************************
STATIC FUNCTION ISBISEXTO( nAno )
*********************************
IF EMPTY(nANO)
   nAno := Year(date())
ENDIF
Return ! Empty(Ctod("29/02/"+Str( nAno, 4 ) ) )


FUNCTION QUEBRA_LINHA(cSTR,nQBR,nTOL,cDLM)
/*
   adciona uma quebra de linha no primeiro espacamento q encontrar entre o numero informar para quebra de linha e a tolerancia
   - cSTR = string a ser tratada
   - nQBR = numero de caracter inicial e o dobro do mesmo para a quebra de linha
   - nTOL = tolerancia para a busca do espacamento para adcionar a quebra de linha
   - cDLM = Delimitador, opcional, se omitido, sera usado uma quebra de linha  chr(13)+chr(10) se nao oq for enviado por ele
*/
LOCAL nQBR2:=nQBR
LOCAL mI:=0

IF cDLM=NIL
   cDLM:=CHR(13)+CHR(10)
ENDIF
FOR mI:=1 TO LEN(cSTR)
   IF mI>=nQBR2 .AND. mI<=nQBR2+nTOL
      IF SUBSTR(cSTR,mI,1)=' '
         cSTR:=LEFT(cSTR,mI)+cDLM+SUBSTR(cSTR,mI+1,LEN(cSTR))
         nQBR2:=nQBR2+nQBR
      ENDIF
   ENDIF
NEXT

RETURN(cSTR)



FUNCTION SOMA_COLUNA(aVET,nCOL,nROUND)
/*
   Soma toda a coluna da array
   Mauricio Cruz - 31/12/2011
*/
LOCAL nTOT:=0, mI:=0

IF nROUND=NIL
   nROUND:=2
ENDIF

FOR mI:=1 TO LEN(aVET)
   nTOT+=ROUND(aVET[mI,nCOL],nROUND)
NEXT

RETURN(nTOT)

****************************************
FUNCTION ABRE_WORD( cArquivo, nColunas )
****************************************
local cArqRtf, arq, arq_txt, cHandle, nA, oWord, cText
local cCaractere  := space( 01 )
local cLinha      := space( 01 )
local lf          := chr( 13 ) + chr( 10 )

sygDialogo("Aguarde Gerando Documento de Word...")

IF !USA_SYG_CLOUD()
   TRY                                                  
      oWord := GetActiveObject( "Word.Application" )    
   CATCH                                                
      TRY                                               
         oWord := CreateObject( "Word.Application" )    
      CATCH                                             
         ABRE_TEXTO_OPENSOURCE(cArquivo)                
         sygDialogo()                                   
         RETURN Nil                                     
      END                                               
   END                                                  
   oWord :=Nil                                          
ENDIF

if ncolunas=Nil
   ncolunas=136
endif
cArqRtf  := lower( left( cArquivo, len( cArquivo ) - 4 ) + ".doc" )
arq      := fcreate( cArqRtf, 1 )
cHandle  := "{\rtf1\ansi\ansicpg1252\deff0\deflang1046{\fonttbl{\f0\fmodern\fprq1\fcharset0 Courier New;}{\f1\fswiss\fcharset0 Arial;}}" + lf
cHandle  += "\margl284\margr505\margt505\margb505" + lf

if nColunas == 136
   cHandle  += "{\*\generator Msftedit 5.41.15.1503;}\viewkind4\uc1\pard\f0\fs14 "
else
   cHandle  += "{\*\generator Msftedit 5.41.15.1503;}\viewkind4\uc1\pard\f0\fs23 "
endif
fwrite( arq, cHandle )

cText := memoread( cArquivo )
for nA := 1 to mlcount( cText, 150 )
  cCaractere := memoline( cText, 150, nA, 1, .F. )
  cCaractere  += "\par" + lf

  IF getkeystate(VK_ESCAPE,.F.,.T.) < 0
     cHandle  := "}"
     fwrite( arq, cHandle )
     fclose( arq          )
     fclose( arq_txt      )
     sygDialogo()
     RETURN .F.
  ENDIF

  fwrite( arq, cCaractere )
NEXT
cHandle  := "}"
fwrite( arq, cHandle )
fclose( arq          )
fclose( arq_txt      )

sygDialogo()
IF FILE(cArqRtf)
   ABRE_ARQUIVO_LIB( cArqRtf )
ELSE
   MsgStop("Erro ao Abrir o Arquivo WORD, Favor verificar")
ENDIF
Return( .T. )

****************************************
FUNCTION ABRE_TEXTO_OPENSOURCE(cArquivo)
****************************************
local oServiceManager,oDesktop,oDocument,oCursor, cCaractere, nA, cText

TRY
   oServiceManager := TOleAuto():New("com.sun.star.ServiceManager")
   oDesktop := oServiceManager:createInstance("com.sun.star.frame.Desktop")
CATCH
   FIM_RUN()
   MsgStop("Não foi Possivel Achar o Word ou OpenOffice Instalado")
   RETURN Nil
END
IF oDesktop = NIL
   FIM_RUN()
   MsgStop("Não foi Possivel Achar o Word ou OpenOffice Instalado")
   RETURN Nil
ENDIF
oDocument := oDesktop:loadComponentFromURL("private:factory/swriter","_blank", 0, {})

oCursor := oDocument:Text:CreateTextCursor()
oCursor:CharFontName:="Courier"
oCursor:CharHeight:=6
oCursor:CharWeight:=50

cText := memoread( cArquivo )
for nA := 1 to mlcount( cText, 150 )
  cCaractere := memoline( cText, 150, nA, 1, .F. )
  oDocument:Text:InsertString(oCursor, cCaractere+CHR(13) , .F.)

  IF getkeystate(VK_ESCAPE,.F.,.T.) < 0
     FIM_RUN()
     RETURN .F.
  ENDIF
NEXT

Fim_Run()
Return .T.

******************************
FUNCTION ABRE_MANUAL(cArq,IMP)
******************************
LOCAL oWord,oText,oDoc, oServiceManager, oDesktop, nError
Local cFILE_ARQ:=''

IF IsDirectory( GETENV("LOCALAPPDATA")+'\sygecom\' )=.F.
   nError:=Makedir( GETENV("LOCALAPPDATA")+'\sygecom\' )
   IF !(nError == 0 .or. nError == 5)
      cFILE_ARQ:=GERAFILE()
   ENDIF
ENDIF
if EMPTY(cFILE_ARQ)
   cFILE_ARQ:=SYG_GERAFILE()
ENDIF

IF IMP=Nil
   IMP="N"
endif

sygDialogo("Aguarde Gerando Documento de Word...")

RenameFile( cARQ, cFILE_ARQ+".doc" )

TRY
   oWord := GetActiveObject(  "Word.Application" )
CATCH
   TRY
      oWord := CreateObject( "Word.Application" )
   CATCH
       TRY
          oServiceManager := TOleAuto():New("com.sun.star.ServiceManager")
       CATCH
          sygDialogo()
          MsgStop("Não foi Possivel Achar o Word ou OpenOffice Instalado")
          RETURN(.F.)
       END
       oServiceManager := NIL
       sygDialogo()
       ABRE_ARQUIVO_LIB( cFILE_ARQ+".doc" )
       RETURN(.F.)
   END
END

IF !FILE(cFILE_ARQ+".doc")
   MsgStop("Não Foi possivel Abrir o Documento de Word")
   sygDialogo()
   RETURN(.F.)
ENDIF
TRY
   oDoc := oWord:Documents:Open(cFILE_ARQ+".doc")  //ABRE O WORD
CATCH
   sygDialogo()
   MsgStop("Não foi Possivel Achar o Word ou OpenOffice Instalado")
   RETURN(.F.)
END

IF IMP="N"
   oWord:Visible := .T. //PARA VISUALIZAR OU NÃO ANTES
   oWord:WindowState := 1  // Maximize
ENDIF
IF IMP="S"
   oWord:Visible := .F. //PARA VISUALIZAR OU NÃO ANTES
   oWord:PrintOut()   //PARA IMPRIMIR DIRETO
ENDIF
sygDialogo()
RETURN(.T.)

***********************************
FUNCTION ABRE_EXCEL_OPENSOURCE(oTB)
***********************************
local oServiceManager,oDesktop,oDocument,oSchedule,oSheet,oCell,oColums,oColumn, I, cCell, linha, oCol, uColData, i2
LOCAL nRecord := 0, nCount := 0

TRY
   oServiceManager := GetActiveObject(  "com.sun.star.ServiceManager" )
CATCH
   TRY
      oServiceManager := CreateObject( "com.sun.star.ServiceManager" )
   CATCH
      FIM_RUN()
      MsgStop("Não foi Possivel Achar o Excel ou OpenOffice Instalado")
      RETURN(.F.)
   END
END
TRY
   oDesktop := oServiceManager:createInstance("com.sun.star.frame.Desktop")
CATCH
   FIM_RUN()
   GERA_EXCEL_LIB(oTB,.T.) // FORÇA A GERAR MESMO NÃO TENDO EXCEL INSTALADO
   //MsgStop("Não foi Possivel Achar o Excel ou OpenOffice Instalado")
   RETURN(.T.)
END

IF oDesktop = NIL
   FIM_RUN()
   MsgStop("Não foi Possivel Achar o Excel ou OpenOffice Instalado")
   RETURN(.F.)
ENDIF
oDocument := oDesktop:loadComponentFromURL("private:factory/scalc","_blank", 0, {})
oSchedule := oDocument:GetSheets()
oSheet := oSchedule:GetByIndex(0)

FOR i := 1 TO Len(oTB:aColumns)  // COLOCA O CABEÇALHO
   cCell := oTB:aColumns[i]:heading
   IF oTB:aColumns[i]:lHide = .F.  // se a coluna tiver visivel
      oSheet:getCellByPosition( i, 0 ):SetString(cCell)
   ENDIF
NEXT

linha=2

IF oTB:Type == BRW_DATABASE
   Eval (oTB:bGoTop) // start from the top
   WHILE ! EOF() .AND. EVAL(oTB:bWhile)
      for i := 1 TO Len(oTB:aColumns)
         IF oTB:aColumns[i]:lHide = .F.  // se a coluna tiver visivel

            IF getkeystate(VK_ESCAPE,.F.,.T.) < 0
               FIM_RUN()
               Release oDesktop
               Release oServiceManager
               RETURN(.F.)
            ENDIF

            oCol := oTB:aColumns[i]:block
            uColData := Eval(oCol)

            IF ValType(uColData) == "C" .OR. ValType(uColData) == "M"
               uColData:=ALLTRIM(uColData) 
               uColData:=REMOVE_CHR(ALLTRIM(uColData))
            ENDIF
               
            do case
            case ValType(uColData) == "C" // characters
               if ! Empty(oTB:aColumns[i]:picture)
                  cCell := Transform (alltrim(uColData), oTB:aColumns[i]:picture)
               else
                  cCell := alltrim(uColData)
               endif
               //cCell="'"+cCell
            case ValType(uColData) == "N" // numbers
               cCell := uColData
            case ValType(uColData) == "L" // logicals
               cCell := if (uColData, "Sim", "Nao")
            case ValType(uColData) == "D" // dates
               cCell := dtoc(uColData)
            otherwise
               cCell := "error"
            endcase
            oSheet:getCellByPosition( i, linha ):SetString(cCell)
            HW_Atualiza_Dialogo(cCell)
         ENDIF
      NEXT

      IF EVAL(oTB:bFor)
        nCount++
      ENDIF
      linha++

      DBSKIP()
   ENDDO
   Eval (oTB:bGoTop)
ELSE
   For i2 := 1 TO (oTB:nRecords)  // quantidade de registros
      For i := 1 TO Len(oTB:aColumns)  // quantidade de colunas
         IF oTB:aColumns[i]:lHide = .F.  // se a coluna tiver visivel
            uColData :=oTB:aArray[i2,i]

            IF getkeystate(VK_ESCAPE,.F.,.T.) < 0
               FIM_RUN()
               Release oDesktop
               Release oServiceManager
               RETURN(.F.)
            ENDIF

            IF ValType(uColData) == "C" .OR. ValType(uColData) == "M"
               uColData:=ALLTRIM(uColData) 
               uColData:=REMOVE_CHR(ALLTRIM(uColData))
            ENDIF
               
            do case
            case ValType(uColData) == "C" // characters
               if ! Empty(oTB:aColumns[i]:picture)
                  cCell := Transform (alltrim(uColData), oTB:aColumns[i]:picture)
               else
                  cCell := alltrim(uColData)
               endif
               cCell="'"+cCell
            case ValType(uColData) == "N" // numbers
               cCell := uColData
            case ValType(uColData) == "L" // logicals
               cCell := if (uColData, "Sim", "Nao")
            case ValType(uColData) == "D" // dates
               cCell := dtoc(uColData)
            otherwise
               cCell := "error"
            endcase
            oSheet:getCellByPosition( i, linha ):SetString(cCell)
            HW_Atualiza_Dialogo(cCell)
         ENDIF
      NEXT

      IF EVAL(oTB:bFor)
        nCount++
      ENDIF
      linha++
   NEXT
ENDIF

FOR i := 1 TO Len(oTB:aColumns)
   cCell  := oTB:aColumns[i]:FOOTING
   *IF LEN(cCell) > 0
   *   lFOOT:=.T.
   *ENDIF
   IF oTB:aColumns[i]:lHide = .F.  // se a coluna tiver visivel
      oSheet:getCellByPosition( i, linha ):SetString(cCell)
   ENDIF
NEXT

*IF lFOOT=.T.
*   oSheet:Rows( alltrim(str(linha))+":"+alltrim(str(linha)) ):Font:bold:=.t.
*ENDIF

//oSheet:autoFormat("OEUSH-Abbucher-Bericht")

//oSheet:getCellRangeByPosition(0,1,0,1):CharWeight:=150 //NEGRITA
*oSheet:getCellRangeByPosition(1,1,1,1):HoriJustify:=3

//oSheet:Rows( "1:1" ):Font:bold:=.t.
//oSheet:Columns:AutoFit()
//oExcel:Visible := .t.

Fim_Run()
Release oDesktop
Release oServiceManager

RETURN(.T.)

/*------------------------------------------------------------------------------
  Função..........: GERA_EXCEL_LIB_CLOUD
  Objetivo........: Gera arquivo xls de forma nativa quando é acesso em nuvem
  Autor...........: João Alpande
  Data de Criacao : 12/11/2020
  Demanda.........: 78462
------------------------------------------------------------------------------*/
STATIC FUNCTION GERA_EXCEL_LIB_CLOUD(oTB,lUsa_Office365_On_Line)
LOCAL oSheet, oExcel, oCol, uColData, nError:=0
LOCAL i,linha, cCell, I2
LOCAL cText := "", cALIAS:='' ,xXls, cXlsFile:=''
LOCAL nRecord := 0, nCount := 0
LOCAL lFOOT:=.F.

IF IsDirectory( GETENV("LOCALAPPDATA")+'\sygecom\' )=.F.
   nError:=Makedir( GETENV("LOCALAPPDATA")+'\sygecom\' )
   IF !(nError == 0 .or. nError == 5)
      cXlsFile:=GERAFILE()+".xls"
   ENDIF
ENDIF
if EMPTY(cXlsFile)
   cXlsFile:=SYG_GERAFILE()+".xls"
ENDIF

sygDialogo("Aguarde Gerando Arquivo Excel !!!",)

xXls := xlsOpen( cXlsFile ) 

FOR i := 1 TO Len(oTB:aColumns)
   cCell  := oTB:aColumns[i]:heading
   IF oTB:aColumns[i]:lHide = .F.  // se a coluna tiver visivel
       xlsWrite( xXls, 1, i, cCell ) 
   ENDIF
NEXT
linha=2

IF oTB:Type == BRW_DATABASE
   cALIAS:=ALIAS()

   Eval (oTB:bGoTop) // start from the top
   WHILE ! EOF() .AND. EVAL(oTB:bWhile)
      FOR i := 1 TO LEN(oTB:aColumns)
         IF oTB:aColumns[i]:lHide = .F. // se a coluna tiver visivel
            oCol := oTB:aColumns[i]:block
            uColData := Eval(oCol)

            IF ValType(uColData) == "C" .OR. ValType(uColData) == "M"
               uColData:=ALLTRIM(uColData) 
               uColData:=REMOVE_CHR(uColData)
               uColData:=LEFT(uColData,245)               
            ENDIF
            
            IF getkeystate(VK_ESCAPE,.F.,.T.) < 0
               sygDialogo()
               RETURN .F.
            ENDIF

            DO CASE
            CASE ValType(uColData) == "C" .OR. ValType(uColData) == "M" // characters
                 IF ! EMPTY(oTB:aColumns[i]:PICTURE)
                    cCell := TRANSFORM (alltrim(uColData), oTB:aColumns[i]:PICTURE)
                 ELSE
                    cCell := ALLTRIM(uColData)
                 ENDIF
                 cCell=" "+cCell
            CASE ValType(uColData) == "N" // numbers
                 IF ! EMPTY(oTB:aColumns[i]:PICTURE)
                    cCell := TRANSFORM (uColData, oTB:aColumns[i]:PICTURE)
                 ELSE
                    cCell := ALLTRIM(STR(uColData)) 
                 ENDIF                
            CASE ValType(uColData) == "L" // logicals
                 cCell := IF (uColData, "Sim", "Nao")
            CASE ValType(uColData) == "D" // dates
                 cCell := DTOC(uColData)
            OTHERWISE
                 cCell := "error"
            ENDCASE
            
            xlsWrite( xXls, linha, i, cCell ) 
            
            HW_Atualiza_Dialogo(cCell)
         ENDIF
      NEXT

      IF EVAL(oTB:bFor)
        nCount++
      ENDIF
      linha++

      SELECT &cALIAS

      DBSKIP()
   ENDDO

   Eval (oTB:bGoTop)
ELSE
   IF LEN(oTB:aArray)>0 .AND. oTB:nRecords>0
      FOR i2 := 1 TO (oTB:nRecords)  // quantidade de registros
         FOR i := 1 TO LEN(oTB:aColumns)  // quantidade de colunas
            IF oTB:aColumns[i]:lHide = .F. // se a coluna tiver visivel
               uColData :=oTB:aArray[i2,i]
               
               IF ValType(uColData) == "C" .OR. ValType(uColData) == "M" 
                  uColData:=ALLTRIM(uColData) 
                  uColData:=REMOVE_CHR(uColData)
                  uColData:=LEFT(uColData,245)                    
               ENDIF
                
               IF getkeystate(VK_ESCAPE,.F.,.T.) < 0
                  sygDialogo()
                  RETURN .F.
               ENDIF

               DO CASE
               CASE ValType(uColData) == "C" // characters
                    IF ! EMPTY(oTB:aColumns[i]:PICTURE)
                       cCell := TRANSFORM (alltrim(uColData), oTB:aColumns[i]:PICTURE)
                    ELSE
                       cCell := ALLTRIM(uColData)
                    ENDIF
                    cCell=" "+cCell
               CASE ValType(uColData) == "N" // numbers              
                    IF ! EMPTY(oTB:aColumns[i]:picture)
                       cCell := TRANSFORM (uColData, oTB:aColumns[i]:PICTURE)
                    ELSE
                       cCell := ALLTRIM(STR(uColData)) 
                    ENDIF                   
               CASE ValType(uColData) == "L" // logicals
                    cCell := if (uColData, "Sim", "Nao")
               CASE ValType(uColData) == "D" // dates
                    cCell := DTOC(uColData)
               OTHERWISE
                    cCell := "error"
               ENDCASE
 
               xlsWrite( xXls, Linha, i, cCell ) 
                
               HW_Atualiza_Dialogo(cCell)
            ENDIF
         NEXT

         linha++
      NEXT
   ENDIF
ENDIF

FOR i := 1 TO LEN(oTB:aColumns)
   cCell  := oTB:aColumns[i]:FOOTING
   IF VALTYPE(cCell)='C'
      IF LEN(cCell) > 0
         lFOOT:=.T.
      ENDIF
      IF oTB:aColumns[i]:lHide = .F.  // se a coluna tiver visivel
         xlsWrite( xXls, Linha, i, cCell )
      ENDIF
   ENDIF   
NEXT

xlsClose( xXls )

IF FILE(cXlsFile) 
   IF !lUsa_Office365_On_Line
      SHOWMSG('Arquivo gerado com sucesso, o sistema vai baixar na sua estação agora !')
   ENDIF
   ABRE_ARQUIVO_LIB( cXlsFile) 
ENDIF
      
sygDialogo()

RETURN(.T.)  

***************************************************
FUNCTION GERA_EXCEL_LIB(oTB,lUsa_Office365_On_Line)
***************************************************
local lOPENOFFICE:=.F.
local oSheet, oExcel, oCol, uColData, nTOTREGARRAY:=0
local i,linha, cCell, I2
Local cText := ""
LOCAL nRecord := 0, nCount := 0
Local lFOOT:=.F.
LOCAL cALIAS:=''

lUsa_Office365_On_Line:=IF(lUsa_Office365_On_Line=Nil,.F.,lUsa_Office365_On_Line)

sygDialogo("Aguarde Gerando Arquivo Excel !!!",)

IF USA_SYG_CLOUD() .OR. lUsa_Office365_On_Line
   lOPENOFFICE:=GERA_EXCEL_LIB_CLOUD(oTB,lUsa_Office365_On_Line)
   sygDialogo()
   RETURN(lOPENOFFICE)
ENDIF   

TRY
   oExcel := GetActiveObject( "Excel.Application" )
   lOPENOFFICE:=.T.
CATCH
   TRY
      oExcel := CreateObject( "Excel.Application" )
      lOPENOFFICE:=.T.
   CATCH
      TRY
         oExcel := GetActiveObject( "Excel.Application.14" )
         lOPENOFFICE:=.T.
      CATCH
         TRY
            oExcel := CreateObject( "Excel.Application.14" )
            lOPENOFFICE:=.T.
         CATCH

         END
      END
   END
END

IF !lOPENOFFICE
   oExcel:=Nil
   lOPENOFFICE:=ABRE_EXCEL_OPENSOURCE(oTB)
   sygDialogo()
   RETURN(lOPENOFFICE)
ENDIF

TRY
   oExcel:WorkBooks:Add()
CATCH
   MsgStop("O Sistema não consegui Iniciar um Sessão do Excel para Fazer a Exportação, Favor Fechar todas as Janelas do Excel e tentar novamente")
   oExcel:=Nil
   sygDialogo()
   RETURN(.F.)
END

//oExcel:WorkBooks:Add()
oSheet = oExcel:ActiveSheet

FOR i := 1 TO Len(oTB:aColumns)
   cCell  := oTB:aColumns[i]:heading
   IF oTB:aColumns[i]:lHide = .F.  // se a coluna tiver visivel
      TRY
         oSheet:Cells( 1, i ):Value = cCell
      CATCH
         MsgStop("O Sistema não consegui Iniciar um Sessão do Excel para Fazer a Exportação, Favor Fechar todas as Janelas do Excel e tentar novamente")
         oExcel:=Nil
         sygDialogo()
         RETURN(.F.)
      END
   ENDIF
NEXT
linha=2

IF oTB:Type == BRW_DATABASE
   cALIAS:=ALIAS()

   Eval (oTB:bGoTop) // start from the top
   WHILE ! EOF() .AND. EVAL(oTB:bWhile)
      For i := 1 TO Len(oTB:aColumns)
         IF oTB:aColumns[i]:lHide = .F. // se a coluna tiver visivel
            oCol := oTB:aColumns[i]:block
            uColData := Eval(oCol)

            IF getkeystate(VK_ESCAPE,.F.,.T.) < 0
               oExcel:Visible := .t.
               Release oExcel
               Release oSheet
               sygDialogo()
               RETURN .F.
            ENDIF

            IF ValType(uColData) == "C" .OR. ValType(uColData) == "M"
               uColData:=ALLTRIM(uColData) 
               uColData:=REMOVE_CHR(ALLTRIM(uColData))
            ENDIF
                           
            do case
            case ValType(uColData) == "C" .OR. ValType(uColData) == "M" // characters
               if ! Empty(oTB:aColumns[i]:picture)
                  cCell := Transform (alltrim(uColData), oTB:aColumns[i]:picture)
               else
                  cCell := alltrim(uColData)
               endif
               cCell=Chr(160)+cCell
               //cCell=" "+cCell
            case ValType(uColData) == "N" // numbers
               cCell := uColData
            case ValType(uColData) == "L" // logicals
               cCell := if (uColData, "Sim", "Nao")
            case ValType(uColData) == "D" // dates
               cCell := dtoc(uColData)
            otherwise
               cCell := "error"
            endcase
            TRY
               oSheet:Cells( linha, i ):Value := cCell
            CATCH
               ShowMsg("Erro ao gerar o arquivo Excel, Favor fechar todas as janelas do Excel aberta")
               oExcel:=Nil
               Release oExcel
               Release oSheet
               sygDialogo()
               RETURN(.F.)
            END
            HW_Atualiza_Dialogo(cCell)
         ENDIF
      NEXT

      IF EVAL(oTB:bFor)
        nCount++
      ENDIF
      linha++

      SELECT &cALIAS

      DBSKIP()
   ENDDO

   Eval (oTB:bGoTop)
ELSE
   nTOTREGARRAY:=LEN(oTB:aArray)
   
   IF nTOTREGARRAY>0 .AND. oTB:nRecords>0
      For i2 := 1 TO nTOTREGARRAY  // quantidade de registros
         For i := 1 TO Len(oTB:aColumns)  // quantidade de colunas
            IF oTB:aColumns[i]:lHide = .F. // se a coluna tiver visivel
               uColData :=oTB:aArray[i2,i]

               IF getkeystate(VK_ESCAPE,.F.,.T.) < 0
                  oExcel:Visible := .t.
                  Release oExcel
                  Release oSheet
                  sygDialogo()
                  RETURN .F.
               ENDIF

               IF ValType(uColData) == "C" .OR. ValType(uColData) == "M"
                  uColData:=ALLTRIM(uColData) 
                  uColData:=REMOVE_CHR(ALLTRIM(uColData))
               ENDIF
               
               do case
               case ValType(uColData) == "C" // characters
                  if ! Empty(oTB:aColumns[i]:picture)
                     cCell := Transform(alltrim(uColData), oTB:aColumns[i]:picture)
                  else
                     cCell := alltrim(uColData)
                  endif
                  cCell=Chr(160)+cCell
                  //cCell=+" "+cCell
               case ValType(uColData) == "N" // numbers
                  cCell := uColData
               case ValType(uColData) == "L" // logicals
                  cCell := if (uColData, "Sim", "Nao")
               case ValType(uColData) == "D" // dates
                  cCell := dtoc(uColData)
               otherwise
                  cCell := "error"
               endcase
               TRY
                  oSheet:Cells( linha, i ):Value := cCell
               CATCH
                  ShowMsg("Erro ao gerar o arquivo Excel, Favor fechar todas as janelas do Excel aberta")
                  oExcel:=Nil
                  Release oExcel
                  Release oSheet
                  sygDialogo()
                  RETURN(.F.)
               END

               HW_Atualiza_Dialogo(cCell)
            ENDIF
         NEXT

      * IF EVAL(oTB:bFor)
      *   nCount++
      * ENDIF
         linha++
      NEXT
   ENDIF
ENDIF

FOR i := 1 TO Len(oTB:aColumns)
   cCell  := oTB:aColumns[i]:FOOTING
   IF VALTYPE(cCell)='C'
      IF LEN(cCell) > 0
         lFOOT:=.T.
      ENDIF
      IF oTB:aColumns[i]:lHide = .F.  // se a coluna tiver visivel
         oSheet:Cells( linha, i ):Value = cCell
      ENDIF
   ENDIF   
NEXT
IF lFOOT=.T.
   oSheet:Rows( alltrim(str(linha))+":"+alltrim(str(linha)) ):Font:bold:=.t.
ENDIF

oSheet:Rows( "1:1" ):Font:bold:=.t.
oSheet:Columns:AutoFit()
oExcel:Visible := .t.
Release oExcel
Release oSheet

sygDialogo()
Return(.T.)

/*-------------------------------------------------------------------------------
Verifica tipo da variavel e aplica o valor default, caso esteja vazia
EX: sygDef(@lTESTE,.T.,'L')
EX: sygDef(@cTESTE,'','C')
EX: sygDef(@nTESTE,0,'N')
EX: sygDef(@dTESTE,date(),'D')  
*/
function sygDef(;
  xVar ,;   // Variável **** passar preferencialmente por referencia
  xNovo,;   // Valor Defaut
  cTipo,;   // Tipo da Variavel
  bUser )   // Bloco de código com condições e atribuições

  if ValType(cTipo) <> "C"
    if Empty(xVar); return xVar:= xNovo;  endif
  else
    if !(ValType(xVar) $ Upper(cTipo)); return xVar:= xNovo;  endif

    if ValType(bUser) == "B" .and. !Eval(bUser, xVar); return xVar:=xNovo;  endif
  endif
return xVar

*===============================================================================
*  sygSeVazio
*-------------------------------------------------------------------------------
*  R: Retorna xB, caso xA esteja vazio
*-------------------------------------------------------------------------------
* 2012.08.21 amb Opção B será um array, identico a coalesce do postgres,
*                que permitirá fazer mais de uma comparação
* 2012.06.27 amb Verifica se o primeiro valor está vazio
*===============================================================================
function sygSeVazio(xA, xB)
  local I

  if ValType(xB)# "A";  xB:= {xB};  endif

  if Empty(xA)
    for I:= 1 to Len(xB)
      xA:= xB[I]
      if !Empty(xA);  return xA;  endif
    next
  endif
return xA

*===============================================================================
*  sygPagIni
*-------------------------------------------------------------------------------
*
*  R: Retorna Pagina Inicial
*
*-------------------------------------------------------------------------------
* 2011.11.10 amb   Retorna a Pagina Inicial
*===============================================================================

function sygPagIni(;
  xPag,;  // Valor preferencia passar por referencia
  nInc )  // Valor Incremental Padrão = -1

  sygDef(@xPag, "1","CN")
  sygDef(@nInc, -1 ,"N" )

  if     ValType(xPag)="C";  xPag:= Str(Val(xPag)+ nInc)
  elseif ValType(xPag)="N";  xPag:= xPag + nInc
  endif
return xPag

*===============================================================================
*  sygFaixaN
*-------------------------------------------------------------------------------
*  Verifica Faixa Numérica
*
*  R: Retorna verdadeiro se estiver dentro da faixa
*
*-------------------------------------------------------------------------------
* 2012.04.02 amb   inclusão de inversão de retorno
*                  Altera nVLR se estiver fora da FAIXA (por referência)
* 2011.11.01 amb   Alterada para retornar verdadeiro  Min e Max
*===============================================================================
function sygFaixaN(;
  nVLR,; // Valor a ser verificado
  nMIN,; // Faixa Menor
  nMAX,; // Faixa Maior
  lINV ) // Inverte o retorno, retorna VERDADEIRO se estiver fora da faixa

  local lRET

  sygDEf(@lINV,.f.,"L")

  lRET:= (nVLR >= nMin  .and. nVLR <= nMAX)

  if lINV;  lRET:= !lRET;  endif

  if nVLR < nMIN; nVLR:= nMIN; endif
  if nVLR > nMAX; nVLR:= nMAX; endif
return lRET

****************************
FUNCTION BUSCA_DATA(cTITULO)
****************************
Local oExtrato, grpConfiguracao, oButton1, oButton2
Local Ldata1, oDATA1, Ldata2, oDATA2
Local dDATA1 :=BoM(date())
Local dDATA2 :=date()
Local aRET   :={}

SET DATE BRITISH
SET EPOCH TO 2000
SET DELE ON

INIT DIALOG oExtrato CLIPPER NOEXIT TITLE cTITULO;
AT 0,0 SIZE 270,190;
ICON HIcon():AddResource(1001) ;
FONT HFont():Add( '',0,-12,400,,,);
STYLE DS_CENTER + WS_VISIBLE + WS_CAPTION + WS_SYSMENU

@ 5,5 GROUPBOX grpConfiguracao CAPTION cTITULO SIZE 260,110

@ 10 ,40 SAY Ldata1  CAPTION "Data Inicial.:" SIZE 68,22
@ 105,40 GET DATEPICKER oDATA1 VAR dDATA1 SIZE 110,22;
TOOLTIP "Informe a Data Inicial"

@ 10 ,70 SAY Ldata2 CAPTION "Data Final...:" SIZE 68,22
@ 105,70 GET DATEPICKER oDATA2 VAR dDATA2 SIZE 110,22;
TOOLTIP "Informe a Data Final"

@ 50,130 BUTTONEX oButton1 CAPTION "&OK" SIZE 100, 38 ;
TOOLTIP "Clique aqui para continuar";
BITMAP (HBitmap():AddResource(1002)):handle  ;
ON CLICK {|| AADD(aRET,{dDATA1,dDATA2}),oExtrato:Close() };
STYLE WS_TABSTOP

@ 160,130 BUTTONEX oButton2 CAPTION "&Cancelar" SIZE 100, 38 ;
TOOLTIP "Clique aqui para Cancelar";
BITMAP (HBitmap():AddResource(1003)):handle  ;
ON CLICK {|| oExtrato:Close() };
STYLE WS_TABSTOP

oExtrato:Activate()

RETURN(aRET)

*********************************************************************************************************
STATIC FUNCTION MY_WChoice( arr, cTitle, nLeft, nTop, oFont, clrT, clrB, clrTSel, clrBSel, cOk, cCancel )
*********************************************************************************************************
   LOCAL oCombo, oDlg, oBrw, nChoice := 0, lArray := .T., nField, lNewFont := .F.
   LOCAL i, aLen, nLen := 0, addX := 20, addY := 70, minWidth := 0, x1, nI_a
   LOCAL hDC, aMetr, width, height, aArea, aRect, cCOMBO:=""
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
      IF LEN(arr) > 0
         IF ValType( arr[ 1 ] ) == "A"
            FOR i := 1 TO aLen
               nLen := Max( nLen, Len( arr[ i, 1 ] ) )
            NEXT
         ELSE
            FOR i := 1 TO aLen
               nLen := Max( nLen, Len( arr[ i ] ) )
            NEXT
         ENDIF
      ELSE
         MsgStop('Erro ao tentar visualizar informações, tente novamente')
         RETURN nChoice
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
        SIZE width, height     ;
        ICON HIcon():AddResource(1001) ;
        STYLE nStyle            ;
        FONT oFont              ;
        ON INIT { | o | ResetWindowPos( o:handle ), oBrw:setfocus() }

   @ 0,20 Browse oBrw Array SIZE width-5, height-25
   oBrw:aArray := arr
   CreateArList( oBrw, arr )

*   IF ValType( arr[ 1 ] ) == "A"
*      oBrw:AddColumn( HColumn():New( , { | value, o | HB_SYMBOL_UNUSED( value ), o:aArray[ o:nCurrent, 1 ] }, "C", nLen ) )
*   ELSE
*      oBrw:AddColumn( HColumn():New( , { | value, o | HB_SYMBOL_UNUSED( value ), o:aArray[ o:nCurrent ] }, "C", nLen ) )
*   ENDIF
   FOR nI_a := 1 TO Len(oBrw:aColumns)
       IF arr#Nil
          oBrw:aColumns[nI_a]:heading := "Coluna-"+alltrim(str(nI_a))
       ENDIF
   NEXT

   oBrw:oFont  := oFont
//   oBrw:bSize  := { | o, x, y | MoveWindow( o:handle, addX / 2, 10, x - addX, y - addY ) }
   oBrw:bEnter := { | o | nChoice := o:nCurrent, EndDialog( o:oParent:handle ) }
   oBrw:bKeyDown := {|o,key|Iif(key==27,(EndDialog(oDlg:handle),.F.), BROWSEKEY_ACHOICE(o, key ) )}

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
      @ x1, height - 36 BUTTONEX cOk SIZE 80, 30 ON CLICK { || nChoice := oBrw:nCurrent, EndDialog( oDlg:handle ) }
      IF cCancel != Nil
         @ x1 + 100, height - 36 BUTTONEX cCancel SIZE 80, 30 ON CLICK { || nChoice := 0, EndDialog( oDlg:handle ) }
      ENDIF
   ENDIF

   oDlg:Activate()
   IF lNewFont
      oFont:Release()
   ENDIF

RETURN nChoice

*********************************************
STATIC FUNCTION BROWSEKEY_ACHOICE( oBrowse, key )
*********************************************
DO CASE
   CASE KEY= VK_ESCAPE
        EndDialog()
   CASE KEY = VK_F2
*        BUSCA_NOME(oBrowse)
   CASE KEY = VK_F4
*        Lista_ordem(oBrowse)
   CASE KEY = VK_F5
        GERA_EXCEL_LIB(oBrowse)
   CASE KEY = VK_F9
        ShellExecute("calc")
   otherwise
ENDCASE
Return .T.

*************************************************************************************************************************************************
FUNCTION MONTA_DBF_EMAIL(cPATHARQ, cServerIP, vPORTSMTP, cFrom, aQuem, aCC, cMsg, cSUBJECT, cUSER, cPASS, aFiles, aBCC, vEMAIL_CONF,vMOSTRA, lHTML, cUSUARIO )
*************************************************************************************************************************************************
LOCAL vARQ:={}, xI

IF vMOSTRA=NIL
   vMOSTRA=.T.
ENDIF

IF lHTML=NIL
   lHTML:=.F.
ENDIF

aadd( vARQ, {"SERVER",     "C",190 ,0} )
aadd( vARQ, {"PORTA",      "N", 10 ,0} )
aadd( vARQ, {"FROM",       "C",190 ,0} )
aadd( vARQ, {"ATO",        "C",190 ,0} )
aadd( vARQ, {"ACC",        "C",190 ,0} )
aadd( vARQ, {"ABCC",       "C",190 ,0} )
aadd( vARQ, {"MSG",        "M", 10 ,0} )
aadd( vARQ, {"SUBJECT",    "M", 10 ,0} )
aadd( vARQ, {"FILES",      "C",350 ,0} )
aadd( vARQ, {"USER",       "C",190 ,0} )
aadd( vARQ, {"PASS",       "C", 90 ,0} )
aadd( vARQ, {"USUARIO",    "C", 30 ,0} )
aadd( vARQ, {"CONF",       "L",  1 ,0} )
aadd( vARQ, {"MOSTRA",     "L",  1 ,0} )
aadd( vARQ, {"HTML",       "L",  1 ,0} )

TRY
   DBcreate(cPATHARQ, vARQ, "DBFCDX")
CATCH
   RETURN .F.
END
TRY
   DBSELECTAREA(0) // SELECIONA A PROXIMA AREA LIVRE
   DbUseArea(.T.,"DBFCDX",cPATHARQ,"EMAIL",.F.,.F.)
CATCH
   RETURN .F.
END

*IF Use_Arq(cPATHARQ,"EMAIL",.F.,.F.,.T.,.T.)=.F.
*   RETURN .F.
*ENDIF

SELE EMAIL
AppRede()
Replace SERVER WITH cServerIP,;
PORTA          WITH vPORTSMTP,;
FROM           WITH cFrom,;
ATO            WITH aQuem,;
ACC            WITH aCC,;
ABCC           WITH aBCC,;
MSG            WITH ALLTRIM(cMsg),;
SUBJECT        WITH cSUBJECT,;
USER           WITH cUSER,;
PASS           WITH cPass,;
USUARIO        WITH cUSUARIO,;
CONF           WITH vEMAIL_CONF,;
MOSTRA         WITH vMOSTRA,;
HTML           WITH lHTML
IF LEN(aFiles) > 0
   For xI=1 TO LEN(aFiles)
      AppRede()
      REPLACE FILES WITH aFiles[xI]
   NEXT
ENDIF
SELE EMAIL
USE
Return .T.

STATIC FUNCTION APPREDE
dbAppend()
if NetErr()
   return .f.
endif
return .t.

****************************
FUNCTION EMAIL_VALIDO(cMAIL)
****************************
LOCAL mI, aTokens:={}, lRET:=.T.

IF EMPTY(cMAIL)
   RETURN(.F.)
ENDIF

IF RIGHT(UPPER(ALLTRIM(cMAIL)),5)='.LTDA' .OR. RIGHT(UPPER(ALLTRIM(cMAIL)),8)='.LTDA.BR'
   RETURN(.T.)
ENDIF

aTokens := HB_ATokens( alltrim(cMAIL), ";", .F., .F. )
IF LEN(aTokens) > 0
   FOR mI:=1 TO LEN(aTokens)   //     SE PELOMENOS UM BOLETO TIVER PEDIDO DE VENDA DEIXA PASSAR SE NAO NAO PASSA.
      IF EMAIL_VALIDO2(alltrim(aTokens[mI]))=.F.
         lRET:=.F.
      ENDIF
   NEXT
ELSE
   IF EMAIL_VALIDO2(alltrim(cMAIL))=.F.
      lRET:=.F.
   ENDIF
ENDIF
RETURN(lRET)

*****************************************
STATIC FUNCTION EMAIL_VALIDO2(cMAIL_TEMP)
*****************************************
Local oRegEx, bVal
TRY
   oRegEx := Createobject("VBScript.RegExp")
CATCH
   RETURN .T.
END
oRegEx:Pattern :="^[\w-\.]{1,}\@([\da-zA-Z-_]{1,}\.){1,}[\da-zA-Z-_]{2,6}$"
cMAIL_TEMP := ALLTRIM(cMAIL_TEMP)
bVal := oRegEx:Test(cMAIL_TEMP)
Release oRegEx

Return bVal

************************
FUNCTION ABRE_LINK(cURL)
/*
Abre um link qualquer da internet no navegador padrão
e retorna se consegui abrir um navegador ou não
*/
************************
LOCAL hInstance

IF cURL=Nil
   MsgStop("Endereço de URL inválido, Favor revisar")
   RETURN(.F.)
ENDIF

IF len(alltrim(cURL))=0
   MsgStop("Endereço de URL inválido, Favor revisar")
   RETURN(.F.)
ENDIF

hInstance := SHELLEXECUTE( cURL, "open", NIL, NIL, 2 )

IF hInstance < 33
   ShowMsg('Erro ao tentar abrir o link: ' + cURL )
   RETURN(.F.)
ENDIF
RETURN(.T.)

#pragma BEGINDUMP

//#define _WIN32_WINNT 0x0500
//#define WINVER 0x0500

#include "windows.h"
#include "hbapi.h"

/*
HB_FUNC( GETINPUTSTATE )
{
LASTINPUTINFO lpi;
lpi.cbSize = sizeof(LASTINPUTINFO);
if (!GetLastInputInfo(&lpi))
{
hb_retni(0);
}
hb_retni(lpi.dwTime);
}
*/

// WINBASEAPI BOOL WINAPI SetEnvironmentVariableA( IN LPCSTR lpName, IN LPCSTR lpValue );
// SETAR UMA VARIAVEL DE AMBIENTE
HB_FUNC( SETENVIRONMENTVARIABLE )
	{
	   hb_retl( SetEnvironmentVariableA( (LPCSTR) hb_parcx(1), (LPCSTR) hb_parcx(2) ) ) ;
	}

#pragma ENDDUMP

Function MostraToolTip(cTEXT, oGET_TEMP,o)
IF cTEXT#NIL
   oGET_TEMP:SetToolTip( cTEXT )
ENDIF
ToolTipShow(o)
return .T.

Function ToolTipShow( o )
LOCAL ac
ac := GetWindowRect( o:handle )
HWG_SETCURSORPOS( ac[ 1 ] + ( ac[ 3 ] -ac[ 1 ] - 2 ), ac[ 2 ] + 1 )
return .t.

****************************
FUNCTION IsActivex(cACTIVEX)
****************************
LOCAL oOBJ
TRY
   oOBJ := GetActiveObject( cACTIVEX )
CATCH
   TRY
      oOBJ := CreateObject( cACTIVEX )
   CATCH
      RETURN(.F.)
   END
END
RETURN(.T.)

FUNCTION PICK_FOLDER(cPATH,oOBJ)
/*
   função genérica para selecionar pasta
   Mauricio Cruz - 19/04/2011
*/
LOCAL cPTHant:=CAMINHO_EXE()

cPATH:=SELECTFOLDER()

Dirchange(cPTHant)
IF oOBJ<>NIL
   oOBJ:SETTEXT(cPATH)
   oOBJ:REFRESH()
ENDIF

RETURN(.T.)

//****************************************************************
static function Modulo10(cTst)
local nTot := 0
local nAux
local i
if Len(ctST)%2 != 0
 cTst := "0"+cTst
end
for i := 1 to Len(cTst)
  nAux := Val(SubStr(cTst,i,1)) * if(i%2==0,2,1)
  if nAux >= 10
   nAux := Val(Left(Str(nAux,2),1)) + Val(Right(Str(nAux,2),1))
  end
  nTot += nAux
next
nTot := 10-(nTot%10)
return if(nTot=10, "0", Str(nTot,1))

//****************************************************************
function ValidCMC7(cCMC7)
return Modulo10(SubStr(cCMC7, 1, 7)) == SubStr(cCMC7,19,1) .and. ;
   Modulo10(SubStr(cCMC7, 9,10)) == SubStr(cCMC7, 8,1) .and. ;
   Modulo10(SubStr(cCMC7,20,10)) == SubStr(cCMC7,30,1)

/*
Dígitos Descrição
------- ---------------------------------------
1/3   Número do banco
4/7   Número da agência
8    Módulo 10 dos dígitos 9 a 18
9/11   Código de compensação
12/17  Número do cheque
18    Número fixo (5)
19    Módulo 10 dos dígitos 1 a 7
20/29  Número da conta corrente (incluindo DV)
30    Módulo 10 dos dígitos 20 a 29
*/

FUNCTION TEM_PERMISSAO_ARQUIVO(cTESTA_ARQ)
// RETORNA SE O USUARIO TEM ACESSO PARA ALTERAR O ARQUIVO OU NÃO
LOCAL lRET:=.T., nHANDLE_TEMP:=0

IF FILE(cTESTA_ARQ)
   nHANDLE_TEMP:=FOpen(cTESTA_ARQ,0) // ABRE O ARQUIVO
   IF nHANDLE_TEMP>0                 // MAIOR QUE ZERO É POR QUE CONSEGUI ABRIR O ARQUIVO
      FSeek( nHANDLE_TEMP, 0, 2 )    // VAI ATÉ O FIM DO ARQUIVO
      FWrite( nHANDLE_TEMP, ' ' )    // ESCREVE ALGO NO FIM DO ARQUIVO
      FClose( nHANDLE_TEMP )         // FECHA O ARQUIVO
   ENDIF
ENDIF

RETURN(lRET)

******************************************************
FUNCTION SET_CONFIG_INI(cNIVELINI,cCAMPOINI,uVALORINI)
******************************************************
/*
exemplo:
SET_CONFIG_INI( 'Impressao', 'tamanho_imp'     , alltrim(STR(nIMPRESSORA))    )
SET_CONFIG_INI( 'Impressao', 'forca_matricial' , iif(lFORCA_RAW,'SIM','NAO')  )
*/
LOCAL nError:=0, cARQINI:=GETENV('temp')+'\config_sygecom\sygecom.ini'

IF !IsDirectory( GETENV("temp") + "\config_sygecom" )
   nError:=Makedir( GETENV("temp") + "\config_sygecom")
   IF !(nError == 0 .or. nError == 5)
      ShowMsg('O Sistema não tem permissão para criar a pasta: CONFIG_SYGECOM dentro do caminho: ' + GETENV("temp")+', Favor abrir o sistema como ADMINISTRADOR' )
      RETURN(.F.)
   ENDIF
ENDIF

IF VALTYPE(uVALORINI)='L'
   IF uVALORINI
      uVALORINI:='SIM'
   ELSE
      uVALORINI:='NAO'
   ENDIF
ELSEIF VALTYPE(uVALORINI)='N'
   uVALORINI:=ALLTRIM(STR(uVALORINI))
ELSEIF VALTYPE(uVALORINI)='D'
   uVALORINI:=DtoC(uVALORINI)
ENDIF
Hwg_WriteIni( cNIVELINI, cCAMPOINI, uVALORINI ,cARQINI )
RETURN(.T.)

*********************************************************
FUNCTION GET_CONFIG_INI(cNIVELINI,cCAMPOINI,uCAMPOPADRAO)
*********************************************************
/*
exemplo:
GET_CONFIG_INI('Identificacao','NOME-PC','')
GET_CONFIG_INI('Impressao','tamanho_imp',1)
*/
LOCAL uRET:=''
IF FILE(GETENV('temp')+'\config_sygecom\sygecom.ini')
   uRET:=Hwg_GetIni(cNIVELINI, cCAMPOINI, , GETENV('temp')+'\config_sygecom\sygecom.ini')
   IF EMPTY(ALLTRIM(uRET))
      uRET:=uCAMPOPADRAO
   ENDIF

   IF uCAMPOPADRAO#NIL
      IF VALTYPE(uCAMPOPADRAO)#VALTYPE(uRET)
         IF VALTYPE(uCAMPOPADRAO)='N'
            uRET:=VAL(uRET)
         ELSEIF VALTYPE(uCAMPOPADRAO)='L'
            IF ALLTRIM(uRET)='SIM'
               uRET:=.T.
            ELSE
               uRET:=.F.
            ENDIF
         ELSEIF VALTYPE(uCAMPOPADRAO)='D'
            uRET:=CtoD(uRET)
         ENDIF
      ENDIF
   ENDIF
ENDIF
RETURN(uRET)

**************************************************************************************
FUNCTION ABRE_LINK_INTERNET(cURL,cRETLINK,cPOST,cSAVE_ARQ,aEXGAUGE,nTIMEOUT,lFORCEOLD)
**************************************************************************************
LOCAL cRET:='', oHttp, lRET:=.T., oUrl, nFileSize

IF EMPTY(cURL)
   RETURN(.F.)
ENDIF

IF cPOST=NIL
   cPOST:=''
ENDIF

IF lFORCEOLD=NIL
   lFORCEOLD:=.F.
ENDIF

IF EMPTY(cPOST) .AND. EMPTY(cSAVE_ARQ) .AND. !lFORCEOLD  // SE ESSES DOIS PARAMETROS TIVER VAZIO, MELHOR USAR A FUNCTION ABAIXO, POR QUE EM ALGUNS LUGAR ESTÁ CORTANDO O RETORNO DA CONSULTA
   lRET:=ABRE_LINK_INTERNET_MSXML(cURL,@cRETLINK,nTIMEOUT)
   IF lRET // SE RETORNAR CERTO, PODE VOLTAR, CASO CONTRARIO TENTA DA FORMA ANTIGA
      RETURN(lRET)
   ENDIF   
ENDIF

IF nTIMEOUT=NIL
   nTIMEOUT:=20000
ENDIF

oURL := tURL():New( cURL )
TRY
   oHttp:= TIpClientHttp():new( oURL )
CATCH
   lRET:=.F.
END
//AJUSTA_LEITURA_HTTP()
IF lRET
   IF ALLTRIM(GET_CONFIG_INI('Proxy','disable_temp',''))='FALSE'
      IF !EMPTY(ALLTRIM(GET_CONFIG_INI('Proxy','url','')))
         IF !EMPTY(ALLTRIM(GET_CONFIG_INI('Proxy','user','')))
            oHttp:SetProxy(GET_CONFIG_INI('Proxy','url',''),;
                           GET_CONFIG_INI('Proxy','porta',0),;
                           GET_CONFIG_INI('Proxy','user',''),;
                           GET_CONFIG_INI('Proxy','pass',''))
         ELSE
            oHttp:SetProxy(GET_CONFIG_INI('Proxy','url',''),;
                           GET_CONFIG_INI('Proxy','porta',0))
         ENDIF
      ENDIF
   ENDIF

   oHttp:nConnTimeout := nTIMEOUT
   IF aEXGAUGE<>NIL
      oHttp:exGauge := aEXGAUGE //{ | done, size| ShowGauge(done, size, nTAMANHO, ftpfile, oBar, oSAY ),hwg_doevents() }
   ENDIF
   IF oHttp:open(cURL)
      IF !EMPTY(cPOST)
         oHTTP:Post( cPOST )
      ENDIF
      IF cSAVE_ARQ<>NIL
         lRET:=oHttp:ReadToFile(cSAVE_ARQ,,nFileSize)
      ELSE
         cRETLINK   := oHttp:readAll()
      ENDIF
      oHttp:close()
   ELSE
      lRET:=.F.
   ENDIF
ENDIF
oHttp:=nil
oURL:=nil

IF !lRET
   IF !EMPTY(ALLTRIM(GET_CONFIG_INI('Proxy','url','')))  // SE TEM PROXY E NÃO CONSEGUI ABRIR, TENTA AGORA SEM PROXY
      IF MY_MsgYesNo("Deseja desativar o uso do Proxy até Reiniciar o sistema ?")
         SET_CONFIG_INI( 'Proxy','disable_temp' ,'TRUE')
      ENDIF
   ENDIF
ENDIF

RETURN(lRET)

*********************************************************
FUNCTION ABRE_LINK_INTERNET_MSXML(cURL,cRETLINK,nTIMEOUT)
*********************************************************
LOCAL oServerWS, cRET:='', lRET:=.T.

IF EMPTY(cURL)
   RETURN(.F.)
ENDIF

IF nTIMEOUT=NIL
   nTIMEOUT:=0
ENDIF

TRY
   oServerWS := xhb_CreateObject("MSXML2.ServerXMLHTTP.6.0")
CATCH
END

if oServerWS=nil
   //ShowMsg('Erro ao tentar realizar a consulta, favor verificar se as DLL usada para NFe está registradas')
   RETURN(.F.)
endif

IF !EMPTY(GET_CONFIG_INI('Proxy','url',''))
   TRY
      oServerWS:SetProxy( 2, GET_CONFIG_INI('Proxy','url','')+":"+ALLTRIM(STR(GET_CONFIG_INI('Proxy','porta',0))))
   CATCH
      lRET:=.F.
   END
   IF lRET
      IF !EMPTY(GET_CONFIG_INI('Proxy','user',''))
         TRY
            oServerWS:setProxyCredentials(GET_CONFIG_INI('Proxy','url','')+"\\"+GET_CONFIG_INI('Proxy','user',''), GET_CONFIG_INI('Proxy','pass',''))
         CATCH
            lRET:=.F. 
         END
      ENDIF
   ENDIF   
ENDIF

IF lRET
   //https://docs.microsoft.com/en-us/previous-versions/windows/desktop/ms760403(v%3Dvs.85)
   oServerWS:setTimeouts(1000*60, 1000*60, 0, 0)  // PARAMETRO ZERO É INFINITO    
   oServerWS:Open("GET",cURL,.F.)
   TRY
      oServerWS:Send()    
   CATCH
      lRET:=.F.
   END

   IF lRET 
      DO WHILE oServerWS:readyState <> 4
         millisec(500)
      ENDDO
      cRETLINK := oServerWS:responseText
   ENDIF
ENDIF

oServerWS:=NIL

RETURN(lRET)

*******************************
FUNCTION CLEAR_LAST_CHAR(cPATHARQ)
*******************************
/*
   Abre o arquivo em baixo nivel, e remove o ultimo caracter  (  chr(26)  ) se existir
*/
local nFile, nSize:=0, cStr:='',cLast:=''

nFile:=fOpen(cPATHARQ)
if fError() <> 0
   fClose(nFile)
   ShowMsg('Erro ao abrir o arquivo')
   RETURN(.F.)
endif

nSize:=fSeek(nFile, 0 , FS_END )
cStr := space(nSize)
fSeek(nFile, 0 , FS_SET )
fRead(nFile,@cStr,nSize)
fClose(nFile)

cLast := right(cStr,1)
//se o ultimo char for "end of file"  remove ele da string, deleta o arquivo anterior e cria arquivo novo com a nova string livre de eof
if cLast=chr(26)
   cStr:=left(cStr,len(cStr)-1)
   erase(cPATHARQ)
   nSize:=len(cStr)
   nFile:=fCreate(cPATHARQ, FC_NORMAL)
   fWrite(nFile,cStr,nSize)
   fClose(nFile)
endif
RETURN(.T.)
/*
#pragma BEGINDUMP

#if defined ( __MINGW32__ )
 #define _WIN32_WINNT 0x0500
#endif

#include <windows.h>
#include "hbapi.h"

HB_FUNC( SETTRANSPARENT )
{

 typedef BOOL (__stdcall *PFN_SETLAYEREDWINDOWATTRIBUTES) (HWND, COLORREF, BYTE, DWORD);

 PFN_SETLAYEREDWINDOWATTRIBUTES pfnSetLayeredWindowAttributes = NULL;

 HINSTANCE hLib = LoadLibrary("user32.dll");

 if (hLib != NULL)
 {
  pfnSetLayeredWindowAttributes = (PFN_SETLAYEREDWINDOWATTRIBUTES) GetProcAddress(hLib, "SetLayeredWindowAttributes");
 }

 if (pfnSetLayeredWindowAttributes)
 {
  SetWindowLong((HWND) hb_parnl (1), GWL_EXSTYLE, GetWindowLong((HWND) hb_parnl (1), GWL_EXSTYLE) | WS_EX_LAYERED);
  pfnSetLayeredWindowAttributes((HWND) hb_parnl (1), 0, hb_parni (2), LWA_ALPHA);
 }

 if (!hLib)
 {
  FreeLibrary(hLib);
 }

}

#pragma ENDDUMP
*/


* Routines to Kill a process, List all processes WITH user & domain names.
* by Vailton Renato <vailtom@gmail.com> to Public Domain.
*
* UPDATED: 16/12/2009 - 12:15
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
* FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL NORMAN WALSH OR
* ANY OTHER CONTRIBUTOR BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
* WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
* CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*
FUNCTION LISTA_PROCESSOS_WIN(cAPP)
LOCAL aProcs := {}

 WIN_GETPROCESSLIST( aProcs, "' + cApp + '" )

/*
 ? 'WIN_GETPROCESSLIST( {}, "' + cApp + '" ) ->', n

 ?
 ? 'Process Name     Process ID ParentID UserName (with Domain)'
 ? '==================== ========== ======== ======================'
  * 123456789*123456789* 123456789* 12345678 123456789*123456789*

 For i := 1 TO Len( aProcs )
   ? PADR( aProcs[i,1], 21),;
    aProcs[i,2], ;
    aProcs[i,3], ' '

   IF Empty(aProcs[i,5]) .AND. Empty( aProcs[i,4] )
    *
   ELSE
    ?? '\\' + aProcs[i,5]+'\'+ aProcs[i,4]
   End
 End
*/
RETURN(aProcs)

************************
#pragma BEGINDUMP
#include <windows.h>
#include <windef.h>
#include <tlhelp32.h>
#include <hbapi.h>
#include <hbapiitm.h>

static
BOOL GetUserAndDomainFromPID( DWORD ProcessId, PHB_ITEM pUser, PHB_ITEM pDomain )
{
 HANDLE hToken;
 HANDLE ProcessHandle;
 DWORD cbBuf;
 SID_NAME_USE snu;
 char *User = NULL;
 char *Domain = NULL;
 DWORD UserSize = 0L;
 DWORD DomainSize = 0L;
 BOOL bResult = FALSE;

 ProcessHandle = OpenProcess( PROCESS_QUERY_INFORMATION, FALSE, ProcessId );

 if (ProcessHandle)
 {
  if (OpenProcessToken(ProcessHandle, TOKEN_QUERY, &hToken))
  {
   BOOL bSuccess = FALSE;
   PTOKEN_USER ptiUser;

   if (!GetTokenInformation(hToken, TokenUser, NULL, 0, &cbBuf ))
   {
    ptiUser = (TOKEN_USER *) hb_xgrab( cbBuf );
    bSuccess = GetTokenInformation( hToken, TokenUser, (LPVOID) ptiUser, cbBuf, &cbBuf);
   }

   CloseHandle(hToken);

   if (bSuccess)
   {
    LookupAccountSid( NULL, ptiUser->User.Sid, NULL, &UserSize, NULL, &DomainSize, &snu);

    if (UserSize != 0 && DomainSize != 0)
    {
     User = (char *) hb_xgrab( UserSize );
     Domain = (char *) hb_xgrab( DomainSize );

     if (LookupAccountSid( NULL, ptiUser->User.Sid, User, &UserSize,
                 Domain, &DomainSize, &snu))
     {
      /* Result OK */
      bResult = TRUE;
     }
    }
   }

   if (ptiUser)
    hb_xfree( ptiUser );
  }
  CloseHandle(ProcessHandle);
 }

 if (!User)
   hb_itemPutC( pUser, "" );
 else
   hb_itemPutCLPtr( pUser, User, UserSize );

 if (!Domain)
   hb_itemPutC( pDomain, "" );
 else
   hb_itemPutCLPtr( pDomain, Domain, DomainSize );

 return bResult;
}

/*
* WIN_GETPROCESSLIST( aArray [, <cProcessToFind> ] ) -> nResult
* Get current process list on Windows OS. by Vailton Renato <vailtom@gmail.com>
*
* Returns:
*
* 0 - Success
* 1 - Argument error
* 2 - Unable to obtain current process list.
* 3 - Error retrieving information about processes.
*
* 15/12/2009 - 18:58:58
*/
HB_FUNC( WIN_GETPROCESSLIST )
{
 HANDLE hProcessSnap;
 PROCESSENTRY32 pe32;
 PHB_ITEM pArray = hb_param( 1, HB_IT_ARRAY );
 const char * szAppName = hb_parcx(2);
 BOOL bCanAdd = TRUE;

 if( !pArray )
 {
   hb_retni( 1 );
   return;
 }

 // Take a snapshot of all processes in the system.
 hProcessSnap = CreateToolhelp32Snapshot( TH32CS_SNAPPROCESS, 0 );

 if( hProcessSnap == INVALID_HANDLE_VALUE )
 {
  // CreateToolhelp32Snapshot (of processes)
  hb_retni( 2 );
  return;
 }

 // Set the size of the structure before using it.
 pe32.dwSize = sizeof( PROCESSENTRY32 );

 // Retrieve information about the first process,
 // and exit if unsuccessful
 if( !Process32First( hProcessSnap, &pe32 ) )
 {
  hb_retni( 3 );
  CloseHandle( hProcessSnap );     // clean the snapshot object
  return;
 }

 // Ignores a empty string on seconds argument
 if ( hb_parclen(2) < 1 )
   szAppName = NULL;

 // Now walk the snapshot of processes, and
 // display information about each process in turn
 do
 {
  PHB_ITEM pSubarray;

  if (szAppName)
   bCanAdd = ( hb_stricmp( szAppName, pe32.szExeFile ) == 0 );

  if (bCanAdd)
  {
   pSubarray = hb_itemNew( NULL );

   hb_arrayNew( pSubarray, 5 );
   hb_arraySetC  ( pSubarray, 1, pe32.szExeFile );          // Process Name
   hb_arraySetNInt ( pSubarray, 2, pe32.th32ProcessID );        // Process ID
   hb_arraySetNInt ( pSubarray, 3, pe32.th32ParentProcessID );     // Parent process ID

   GetUserAndDomainFromPID( pe32.th32ProcessID,
                hb_arrayGetItemPtr( pSubarray, 4 ),    // User
                hb_arrayGetItemPtr( pSubarray, 5 ) );   // Domain
   hb_arrayAddForward( pArray, pSubarray );
  }
 } while( Process32Next( hProcessSnap, &pe32 ) );

 CloseHandle( hProcessSnap );
 hb_retni( 0 );
 return;
}

/*
* WIN_KILLPROCESS( <nProessIDtoKill> ) -> lKilled
* Kill a process using Win32 API. by Vailton Renato <vailtom@gmail.com>
* 16/12/2009 - 00:08:48
*/
HB_FUNC( WIN_KILLPROCESS )
{
 DWORD ProcID;
 BOOL Result = FALSE;

 if (ISNUM(1))
 {
   ProcID = (DWORD) hb_parnl(1);
   Result = TerminateProcess(OpenProcess( PROCESS_TERMINATE, FALSE, ProcID ),0);
 }

 hb_retl( Result );
}

#pragma ENDDUMP

FUNCTION COPIAR_VARIOS_ARQUIVOS( cOrigen, cDestino )
LOCAL oFs

If !IsDirectory( cDestino )
   MakeDir( cDestino )
Endif

oFs   := CreateObject( "Scripting.FileSystemObject" )
// oFs:CopyFile( "z:\systems\xml\*.xml" , "r:\backups\systems\xml\", .t. ) // .t. for overwrite
oFs:CopyFile( cOrigen, cDestino, .T. ) // .t. for overwrite
//CURSORARROW()

RETURN NIL

FUNCTION MapNetworkDrive( cDrive, strLocalDrive ) 
LOCAL objNetwork, lOk:=.T.

IF cDrive=NIL
   cDrive:='F:'
ENDIF

  objNetwork := CREATEOBJECT("WScript.Network")

  Try
   objNetwork:MapNetworkDrive(cDrive, strLocalDrive)
  Catch
   lOk:=.F.
  End
 
RETURN lOk

FUNCTION RemoveNetworkDrive( cDrive ) 
LOCAL objNetwork, lOk:=.T.

IF cDrive=NIL
   cDrive:='F:'
ENDIF

  objNetwork := CREATEOBJECT("WScript.Network")

  Try
   objNetwork:RemoveNetworkDrive(cDrive, .T., .T.)
  Catch
   lOk:=.F.
  End

RETURN lOk

STATIC FUNCTION PEGA_TAG_XML(aTAG,cXML,nBACKwards,lCTe) // variavel para se for CTe - MySuite - 416 - Alexandre M.Soares
/*
   Leitura do arquivo XML das tags e subtags
   Mauricio Cruz - 29/07/2010
   - aTAG = recebe a array com as tags de busca
   - cXML = recebe o arquivo XML ja em string (NÃO enviar o caminho do arquivo no HD)
   - cSTR = retorna o valor da ultima tag recebida na array
   - nBACKwards =  o numero da TAG na array aTAG a ser procurada apartir do final do arquivo XML (ler o arquivo de baixo para cima na TAG especificada)
   ** IMPORTANTE:  enviar as tags exatamente como se le no arquivo XML
                   se recebido os conjutos de tags imcompleto ira retornar toda a string de dentro da tag EX:
                        enviando somente {'emit'}  recebera devolta:
                        '<CNPJ>00275987000157</CNPJ><xNome>RENATO BERNARDINI O COMERCIANTE ME</xNome><xFant>INCOCAL</xFant>- <enderEmit><xLgr>PROF. REGINA MARIA DA SILVA WALTRICK RAMOS</xLgr><nro>032</nro><xBairro>SERRARIA</xBairro><cMun>4216602</cMun><xMun>SAO JOSE</xMun><UF>SC</UF><CEP>88113140</CEP><cPais>1058</cPais><xPais>BRASIL</xPais><fone>5136644115</fone></enderEmit><IE>254748872</IE>'
                        enviando {'emit','CNPJ'} recebera devolta:
                        '00275987000157'
*/
LOCAL cOPEN:='',cCLOSE:='',;
      nSTART:=0,nSTOP:=0,NN:=0,;
      cSTR:=cXML

if lCTe=nil // casoe se for CTe - MySuite - 416 - Alexandre M.Soares
   lCTe=.f.
endif

IF nBACKwards=NIL
   nBACKwards:=0
ENDIF
FOR NN:=1 TO LEN(aTAG)
   if !lCTe // se não for CTe é NFe - MySuite - 416 - Alexandre M.Soares
      cOPEN :='<'+aTAG[NN]+'>'
      IF LEFT(aTAG[NN],9)=='det nItem'
         cCLOSE:='</det>'
      ELSEIF LEFT(aTAG[NN],7)=='infProt'
         IF LER_VAL_TAG_XML('infNFe versao',cXML)='2.00' .OR. LER_VAL_TAG_XML('nfeProc versao',cXML)='2.00'
            IF 'ID' $ LER_VAL_TAG_XML('infProt Id',cXML)
              cOPEN :='<infProt Id="'+LER_VAL_TAG_XML('infProt Id',cXML)+'">'
            ELSE
              cOPEN :='<'+aTAG[NN]+'>'
            ENDIF
         ENDIF
         cCLOSE:='</'+aTAG[NN]+'>'
      ELSE
         cCLOSE:='</'+aTAG[NN]+'>'
      ENDIF

      IF nBACKwards>0 .AND. nBACKwards=NN
         nSTART:=RAT(cOPEN,cSTR)
         nSTOP :=RAT(cCLOSE,cSTR)
         cSTR:=SUBSTR(cSTR,nSTART,nSTOP)
      ELSE
         IF LEN(cSTR)<=0
            RETURN('')
         ENDIF
         nSTART:=AT(cOPEN,cSTR)+LEN(cOPEN)
         nSTOP :=AT(cCLOSE,cSTR,nSTART)-nSTART

         IF nSTART-LEN(cOPEN)<=0 .OR. nSTOP<=0
            RETURN('')
         ENDIF
         cSTR:=SUBSTR(cSTR,nSTART,nSTOP)
      ENDIF
   else // se não é CTe - MySuite - 416 - Alexandre M.Soares
      cOPEN :='<'+aTAG[NN]+'>'
      do case
         case aTAG[NN]='infCteNorm'
            IF 'InfCarga'
               cOPEN :='<vCarga="'+ler_val_tag_xml('vCarga',cXML)+'">'
            ELSE
               cOPEN :='<'+aTAG[NN]+'>'
            ENDIF
         otherwise
            cCLOSE:='</'+aTAG[NN]+'>'
      endcase

      IF nBACKwards>0 .AND. nBACKwards=NN
         nSTART:=RAT(cOPEN,cSTR)
         nSTOP :=RAT(cCLOSE,cSTR)
         cSTR:=SUBSTR(cSTR,nSTART,nSTOP)
      ELSE
         IF LEN(cSTR)<=0
            RETURN('')
         ENDIF
         nSTART:=AT(cOPEN,cSTR)+LEN(cOPEN)
         nSTOP :=AT(cCLOSE,cSTR,nSTART)-nSTART

         IF nSTART-LEN(cOPEN)<=0 .OR. nSTOP<=0
            RETURN('')
         ENDIF
         cSTR:=SUBSTR(cSTR,nSTART,nSTOP)
      ENDIF
   endif
NEXT
IF aTAG[1]<>'SignedInfo'
   cSTR:=RemoveCaracter(cSTR)
ENDIF
RETURN(cSTR)


STATIC FUNCTION LER_VAL_TAG_XML(cTAG,cXML)
/*
   le o valor defenido de uma variavel em uma TAG XML
   Mauricio Cruz - 13/05/2011
*/
LOCAL cOPEN:='<'+cTAG+'="', cCLOSE:='"'
LOCAL nSTART:=AT(cOPEN,cXML)+LEN(cOPEN)
LOCAL nCLOSE:=AT(cCLOSE,cXML,nSTART)-nSTART
LOCAL cRET:=SUBSTR(cXML,nSTART,nCLOSE)
IF cTAG="infNFe id"
   nSTART:=AT('Id="NFe',cXML)+7
   nCLOSE:=AT(cCLOSE,cXML,nSTART)-nSTART
   cRET:=SUBSTR(cXML,nSTART,nCLOSE)
ENDIF

RETURN(cRET)

STATIC FUNCTION REMOVECARACTER(cSTR, cSUBST, nIgnora, nInicio, nCont, lEspaco)
/*
cSTR        - Cadeia de caracteres ou campo memo onde será efetuada a busca.
cSUBST      - É a sequência de caracteres que substituirá
nIgnora     - Caracter(es) que será ignorado no momento da substituição, ou sejá, não será removido do texto.
nIgnora deve ser um array de string, cada caracter a ser ignorado deve ser passado em uma posição do array. Exemplo: {",","-"}
nInicio     - É a primeira ocorrência a ser substituida. Caso este argumento seja omitido, o padrão é um.
nCont       - É a quantidade de ocorrências a serem substituidas. Se este argumento nao for especificado, o padrao é todos.
*/

LOCAL cProcura, cSTRLIMPO := "", i, qtd
DEFAULT cSUBST := "", nIgnora := {}, lEspaco:=.f.

qtd := LEN(nIgnora)
if !empty(cSTR)
   cProcura := {'"',"œ","€","ƒ","‰","'",",",";","!","@","#","$","%","¨","&","*","~",;
    "^","?","§","°","{","}","[","]","|","(",")","\","|","/","+","-",;
    "=",chr(0),chr(8),chr(9),chr(128),chr(141)}
   if lEspaco
      aadd(cProcura," ")
   endif

   for i := 1 to LEN(cProcura)
      if qtd > 0
         cProcura[i] = nIgnora[qtd]
         qtd -= 1
         loop
      endif
      cSTRLIMPO := STRTRAN(cSTR, cProcura[i], cSUBST, nInicio, nCont)
      cSTR := cSTRLIMPO
   next
endif
Return cSTRLIMPO

/*
EXEMPLO DE USO:
SYG_GENERATEGUID(.T.) // RETORNA TUDO EM MAIUSCULO
SYG_GENERATEGUID(.F.) // RETORNA TUDO EM MINUSCULO
*/

#pragma BEGINDUMP

#include <stdio.h>
#include <string.h>
#include <windows.h>
#include "hbapi.h"

HB_FUNC ( SYG_GENERATEGUID )
{
    GUID guid;
    char guidString[37];
    char guidStringFormat[68];
    
    if((int)hb_parl(1) == 1)
        strcpy(guidStringFormat, "%08lX-%04hX-%04hX-%02hhX%02hhX-%02hhX%02hhX%02hhX%02hhX%02hhX%02hhX");
    else
        strcpy(guidStringFormat, "%08lx-%04hx-%04hx-%02hhx%02hhx-%02hhx%02hhx%02hhx%02hhx%02hhx%02hhx");
    
    CoCreateGuid(&guid);
    
    sprintf(guidString, guidStringFormat,
      guid.Data1, guid.Data2, guid.Data3,
      guid.Data4[0], guid.Data4[1], guid.Data4[2], guid.Data4[3],
      guid.Data4[4], guid.Data4[5], guid.Data4[6], guid.Data4[7]);
      
    hb_retc(guidString);    
}

#pragma ENDDUMP

#pragma BEGINDUMP
#include <windows.h>
#include <windef.h>

VOID MoveMouse();
HB_FUNC( MOVEMOUSE )
{
  POINT Cursor;
  RECT TrayRect;
  GetWindowRect(FindWindowEx(FindWindow("Shell_TrayWnd",NULL),0,"TrayNotifyWnd",NULL),&TrayRect);

  GetCursorPos(&Cursor);

  while(TrayRect.left+11 < TrayRect.right) {
    SetCursorPos(TrayRect.left+10,TrayRect.top+12);
    Sleep(1);
    TrayRect.left += GetSystemMetrics(SM_CXSMICON)+2;
  }
  SetCursorPos(Cursor.x,Cursor.y);
}
#pragma ENDDUMP

****************************
FUNCTION ARRAY2STRPIPE(aARR,nCOLUNAS_INICIO,nFINAL_COLUNAS)
/*
TRANSFORMA UM VETOR EM STRING SEPARANDO POR PIPE
LEONARDO MACHADO - 05-05-2015
*/
****************************
LOCAL cRET:='',nI:=0, nTOTLIN:=0, mI:=0
LOCAL nCOLUNAS:=0

IF nCOLUNAS_INICIO=NIL
   nCOLUNAS_INICIO:=1
ENDIF

IF nFINAL_COLUNAS=NIL
   nFINAL_COLUNAS:=0
ENDIF

IF VALTYPE(aARR)='A'
   nTOTLIN :=LEN(aARR)
   IF nFINAL_COLUNAS>0
      nCOLUNAS:=nFINAL_COLUNAS
   ELSE
      nCOLUNAS:=QTD_DIMENCAO(aARR)
   ENDIF
   IF nTOTLIN>0
      FOR nI:=1 TO nTOTLIN
         FOR mI:=nCOLUNAS_INICIO TO nCOLUNAS
            IF VALTYPE(aARR[nI,mI])='N'
               cRET+=ALLTRIM(STR(aARR[nI,mI]))
            ELSEIF VALTYPE(aARR[nI,mI])='L'
               IF aARR[nI,mI]
                  cRET+='TRUE'
               ELSE
                  cRET+='FALSE'
               ENDIF
            ELSEIF VALTYPE(aARR[nI,mI])='D'
               cRET+=DtoS(aARR[nI,mI])
            ELSEIF VALTYPE(aARR[nI,mI])='C'
               cRET+=ALLTRIM(aARR[nI,mI])
            ELSE
               cRET+=VALTOPRG(aARR[nI,mI])
            ENDIF
            cRET+='|'
         NEXT mI
         cRET+=HB_OsNewLine()
      NEXT nI
   ENDIF
ENDIF
RETURN(cRET)

FUNCTION QTD_DIMENCAO(aVET)
/*
   retorna as dimenções de uma array
   Mauricio Cruz - 05/01/2011
*/
LOCAL mI:=0

FOR mI:=1 TO 99999999999999999999
   TRY
      IF aVET[1,mI]=NIL // SO PARA FORCAR O ERRO
      ENDIF
   CATCH
      EXIT
   END
NEXT

RETURN(mI-1)


FUNCTION LISTA_PROFILE
/*
LISTA TODAS VARIAVEIS ABERTA USADA PELO SISTEMA.
*/
local aValues := {}, n

#define HB_NO_PROFILER

__SetProfiler( .T. )

   for n := 1 TO __dynsCount()
      if __dynsIsFun( n )
         AAdd( aValues, { __dynsGetName( n ), __dynsGetPrf( n )[ 1 ], __dynsGetPrf( n )[ 2 ] } )
      endif
   next

//   MY_BROWSE(aValues)

   aValues = {}

   for n = 0 to __opCount() - 1
      AAdd( avalues, { n, __opGetPrf( n )[ 1 ], __opGetPrf( n )[ 2 ] } )
   next

//   MY_BROWSE(aValues)
__SetProfiler( .F. )
return nil

#ifdef HB_THREAD_SUPPORT
/*
FUNCTION TESTE_EXEMPLO_MT
LOCAL nID_PARAMETRO:=12

StartThread( @TESTE_EXEMPLO_MT2(), nID_PARAMETRO )
nID_PARAMETRO:=22
StartThread( @TESTE_EXEMPLO_MT2(), nID_PARAMETRO )
nID_PARAMETRO:=32
StartThread( @TESTE_EXEMPLO_MT2(), nID_PARAMETRO )
WaitForThreads()

ShowMsg('Todas rotinas já rodaram')

RETURN(.T.)

PROCEDURE TESTE_EXEMPLO_MT2( nRow )
   LOCAL nCount
   // Exit when only main thread and this thread are left
   ThreadSleep( 250 )
   nCount := 1

   DO WHILE HB_ThreadCountStacks() > 2
      //@nRow, 5 SAY "Collector loop :" + AllTrim( Str( nCount ) )
      HB_GCALL( .T. )
      ThreadSleep( 250 )
      nCount ++
   ENDDO

   //@nRow, 5 SAY "Collector loop : DONE         "

RETURN
*/
#endif

function DimensaoReduzida(lSts) // --> lsReduzirTela
static lsReduzirTela

lsReduzirTela:=if( lSts = nil, lsReduzirTela, lSts)
if lsReduzirTela = nil
   lsReduzirTela:=GetDesktopHeight() < 500
endif

return lsReduzirTela

FUNCTION TIPO_LOGRADOURO(cEND)
/*
   tenta remover do endereco o tipo do logradouro
   Mauricio Cruz - 03/05/2013
*/
LOCAL cRET:=''

cEND:=UPPER(cEND)
IF 'RUA'$cEND
   cRET:='RUA'
ELSEIF 'RODOVIA'$cEND
   cRET:='RODOVIA'
ELSEIF 'AVENIDA'$cEND
   cRET:='AVENIDA'
ELSEIF 'RUELA'$cEND
   cRET:='RUELA'
ELSEIF 'SITIO'$cEND .OR. 'SÍTIO'$cEND
   cRET:='SITIO'
ELSEIF 'TRAVESSA'$cEND
   cRET:='TRAVESSA'
ELSEIF 'VALE'$cEND
   cRET:='VALE'
ELSEIF 'VIA'$cEND
   cRET:='VIA'
ELSEIF 'VIELA'$cEND
   cRET:='VIELA'
ELSEIF 'VILA'$cEND
   cRET:='VILA'
ELSEIF 'VARGEM'$cEND
   cRET:='VARGEM'
ELSEIF 'RIO'$cEND
   cRET:='RIO'
ELSEIF 'AV. '$cEND .OR. 'AV '$cEND
   cRET:='AVENIDA'
ENDIF

RETURN(cRET)

FUNCTION DDMMAAAToDate(cDAT)
/*
   Recebe a data em string no formado DDMMAAAA e retorna em formato de data normal
   Mauricio Cruz - 08/05/2013
*/
LOCAL dRET:=CTOD(LEFT(cDAT,2)+'/'+SUBSTR(cDAT,3,2)+'/'+RIGHT(cDAT,4))
RETURN(dRET)

FUNCTION NOME_DO_MES(dDAT)
/*
   retorna o nome do mes
   Mauricio Cruz - 25/05/2013
*/
LOCAL cRET:=''
IF dDAT=NIL
   dDAT:=DATE()
ENDIF
IF VALTYPE(dDAT)<>'D'
   RETURN('Formato de Data inválida')
ENDIF

IF MONTH(dDAT)=1
   cRET:='Janeiro'
ELSEIF MONTH(dDAT)=2
   cRET:='Fevereiro'
ELSEIF MONTH(dDAT)=3
   cRET:='Março'
ELSEIF MONTH(dDAT)=4
   cRET:='Abril'
ELSEIF MONTH(dDAT)=5
   cRET:='Maio'
ELSEIF MONTH(dDAT)=6
   cRET:='Junho'
ELSEIF MONTH(dDAT)=7
   cRET:='Julho'
ELSEIF MONTH(dDAT)=8
   cRET:='Agosto'
ELSEIF MONTH(dDAT)=9
   cRET:='Setembro'
ELSEIF MONTH(dDAT)=10
   cRET:='Outubro'
ELSEIF MONTH(dDAT)=11
   cRET:='Novembro'
ELSEIF MONTH(dDAT)=12
   cRET:='Dezembro'
ENDIF
RETURN(cRET)

FUNCTION ABRE_LE_ARQUIVO(cARQ,cBUFFER)
LOCAL lRET:=.F., nHand, nSize:=0
IF FILE(cARQ)
   nHand := FOpen( cARQ, 0 )
   IF FError() <> 0
      RETURN(lRET)
   ENDIF
   nSize:=fSeek(nHand, 0 , FS_END )
   cBUFFER:=space(nSize)
   IF FREAD( nHand, @cBUFFER, nSize )>0
      lRET:=.T.
   ENDIF
   FClose( nHand )
ENDIF
RETURN(lRET)

FUNCTION DIVIDE_VALORES(nVAL,nDIV)
/*
   divide o valor em parcelas iguais
   LeonardO Machado - 04/05/2014
*/
LOCAL nMENOS:=0, nMAIS:=0, mI:=0, nPAR2:=0, aRET:={}

IF nDIV=1 .OR. nDIV=0 .OR. nVAL=0
   AADD(aRET,{mI,nVAL})
ELSE
   IF (ROUND(nVAL/nDIV,2)*nDIV) > nVAL
      nMENOS:= (ROUND(nVAL/nDIV,2)*nDIV)-nVAL
   ELSEIF (ROUND(nVAL/nDIV,2)*nDIV) < nVAL
      nMAIS:=nVAL-(ROUND(nVAL/nDIV,2)*nDIV)
   ENDIF

   FOR mI:=1 TO nDIV
      AADD(aRET,{mI,IIF(mI=1,IIF(nMENOS<>0,ROUND(nVAL/nDIV,2)-nMENOS,IIF(nMAIS<>0,ROUND(nVAL/nDIV,2)+nMAIS,ROUND(nVAL/nDIV,2))), ROUND(nVAL/nDIV,2) )} )
   NEXT
ENDIF
RETURN(aRET)

FUNCTION VER_DIF_DOIS_VALORES(nVAL1,nVAL2)
/*
   retorna a diferença entre dois valores
   LeonardO Machado - 04/05/2014
*/
LOCAL nMENOS:=0, nMAIS:=0, nRET:=0

IF nVAL1==nVAL2
   RETURN(nRET)
ELSE
   IF ROUND(nVAL1,2) > ROUND(nVAL2,2)
      nMAIS:=ROUND(nVAL1,2)-ROUND(nVAL2,2)
   ELSEIF ROUND(nVAL1,2) < ROUND(nVAL2,2)
      nMENOS:=ROUND(nVAL1,2)-ROUND(nVAL2,2)
   ENDIF
   nRET:=nMAIS+nMENOS
ENDIF
RETURN(nRET)


FUNCTION UMADIMENSAO(aARR)
/*
   Recebe uma array com duas dimensao com apenas uma coluna e retorna uma array de uma dimensao com uma coluna
   Mauricio Cruz - 03/09/2014
*/
LOCAL mI:=0
LOCAL aRET:={}

FOR mI:=1 TO LEN(aARR)
   AADD(aRET,aARR[mI,1])
NEXT

RETURN(aRET)

************************************
FUNCTION SYG_BASE64ENCODE(cCONTEUDO)
************************************
LOCAL cRET:=''
IF FILE(cCONTEUDO)
   cRET:=HB_BASE64ENCODE(MEMOREAD(cCONTEUDO),LEN(MEMOREAD(cCONTEUDO)) )
ELSE
   cRET:=hb_base64encode(cCONTEUDO,LEN(cCONTEUDO))
ENDIF
RETURN(cRET)


/*
 * Harbour Project source code:
 * HB_BASE64DECODE() function
 *
 * Based on VB code by: 1999-2004 Antonin Foller, http://www.motobit.com, http://motobit.cz
 * Converted to Clipper and optimized by Viktor Szakats (harbour.01 syenar.hu)
 * www - http://www.harbour-project.org
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this software; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 59 Temple Place, Suite 330,
 * Boston, MA 02111-1307 USA (or visit the web site http://www.gnu.org/).
 *
 * As a special exception, the Harbour Project gives permission for
 * additional uses of the text contained in its release of Harbour.
 *
 * The exception is that, if you link the Harbour libraries with other
 * files to produce an executable, this does not by itself cause the
 * resulting executable to be covered by the GNU General Public License.
 * Your use of that executable is in no way restricted on account of
 * linking the Harbour library code into it.
 *
 * This exception does not however invalidate any other reasons why
 * the executable file might be covered by the GNU General Public License.
 *
 * This exception applies only to the code released by the Harbour
 * Project under the name Harbour.  If you copy code from other
 * Harbour Project or Free Software Foundation releases into a copy of
 * Harbour, as the General Public License permits, the exception does
 * not apply to the code that you add in this way.  To avoid misleading
 * anyone as to the status of such modified files, you must delete
 * this exception notice from them.
 *
 * If you write modifications of your own for Harbour, it is your choice
 * whether to permit this exception to apply to your modifications.
 * If you do not wish that, delete this exception notice.
 *
 */

FUNCTION SYG_BASE64DECODE(cString)
RETURN(HB_BASE64DECODE(cString))

FUNCTION HB_BASE64DECODE( cString )
/*
   Copiado da internet
   Mauricio Cruz - 28/01/2014
*/
   LOCAL cResult

   LOCAL nLen
   LOCAL nGroupPos
   LOCAL nGroup
   LOCAL nCharPos
   LOCAL nDataLen
   LOCAL nData

   /* remove white spaces, If any */
   cString := StrTran( cString, Chr( 10 ) )
   cString := StrTran( cString, Chr( 13 ) )
   cString := StrTran( cString, Chr( 9 ) )
   cString := StrTran( cString, " " )

   /* The source must consists from groups with Len of 4 chars */
   IF ( nLen := Len( cString ) ) % 4 != 0
      RETURN "" /* Bad Base64 string */
   ENDIF

#if 0
   IF nLen > Int( MAXSTRINGLENGTH / 1.34 ) /* Base64 is 1/3rd larger than source text. */
      RETURN "" /* Not enough memory to decode */
   ENDIF
#endif

   cResult := ""

   /* Now decode each group: */
   FOR nGroupPos := 1 TO nLen STEP 4

      /* Each data group encodes up To 3 actual bytes */
      nDataLen := 3
      nGroup := 0

      FOR nCharPos := 0 TO 3

         /* Convert each character into 6 bits of data, And add it To
            an integer For temporary storage. If a character is a '=', there
            is one fewer data byte. (There can only be a maximum of 2 '=' In
            the whole string.) */

         nData := At( SubStr( cString, nGroupPos + nCharPos, 1 ), "=ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/" ) - 2

         DO CASE
         CASE nData >= 0
            /* Do nothing (for speed) */
         CASE nData == -1
            nData := 0
            nDataLen--
         CASE nData == -2
            RETURN "" /* Bad character In Base64 string */
         ENDCASE

         nGroup := 64 * nGroup + nData
      NEXT

      /* Convert the 24 bits to 3 characters
         and add nDataLen characters To out string */
      cResult += Left( Chr( nGroup / 65536 ) +;          /* bitwise AND 255, which is done by Chr() automatically */
                       Chr( nGroup /   256 ) +;          /* bitwise AND 255, which is done by Chr() automatically */
                       Chr( nGroup         ), nDataLen ) /* bitwise AND 255, which is done by Chr() automatically */
   NEXT

   RETURN cResult

// VE SE É UMA HORA VÁLIDA
FUNCTION TESTA_HORA(cHORA)
LOCAL nTIME:=TIMETOSEC(TRANSFORM(cHORA,"@R 99:99:99"))
   IF nTIME<0
      cHORA:='000000'
      RETURN .F.
   ENDIF

RETURN .T.

FUNCTION AJUSTA_DATA_HORA_INTERNET()
Local cWeb, cProcura, cExtrai, cHora, cData, lAjusta:=.f.
/*
If !INETESTACONECTADA()
   MsgStop("Computador não está conectado na internet.", "Sem Acesso à Internet")
   Return .f.
Endif
*/
   
   ABRE_LINK_INTERNET("http://www.horacerta.com.br/index.php?city=sao_paulo",@cWeb,NIL,NIL,NIL,NIL,.T.)
   
   cProcura:= '<input name="mostrador" type="text" size="25" value="'
   cExtrai := Subs(cWeb, At(cProcura,cWeb)+53,24)
   cData   := Alltrim(Left(alltrim(cExtrai),10))
   cHora   := Alltrim(StrZero(If(Right(cExtrai,2)=="PM" .and. Val(subs(cExtrai,14,2))<=11, 12, 0)+Val(subs(cExtrai,14,2)),2)+":"+subs(cExtrai,17,5))

   If Ctod(cData)<>Date() .and. Val(cData)<>0 .and. Subs(cHora,1,5)<>Subs(Time(),1,5) .and. Val(cHora)<>0
      If MsgYesNo("Data e hora da Internet:"+CR_LF+;
                  cData+"  -  "+cHora+CR_LF+CR_LF+;
                  "Data e hora do computador:"+CR_LF+;
                  Dtoc(Date())+"  -  "+Time()+CR_LF+CR_LF+;
                  "Deseja ajustar a data e hora?", "Data e hora do computador parecem desatualizadas.")
         lAjusta:=.t.
      Endif
   Elseif Ctod(cData)==Date() .and. Val(cData)<>0 .and. Subs(cHora,1,5)<>Subs(Time(),1,5) .and. Val(cHora)<>0
      If MsgYesNo("Hora da Internet:"+CR_LF+;
                  cHora+CR_LF+CR_LF+;
                  "Hora do computador:"+CR_LF+;
                  Time()+CR_LF+CR_LF+;
                  "Deseja ajustar a hora?", "A hora do computador está desatualizada")
         lAjusta:=.t.
      Endif
   Elseif Ctod(cData)<>Date() .and. Val(cData)<>0 .and. Subs(cHora,1,5)==Subs(Time(),1,5) .and. Val(cHora)<>0
      If MsgYesNo("Data da Internet:"+CR_LF+;
                  cData+CR_LF+CR_LF+;
                  "Data do computador:"+CR_LF+;
                  Dtoc(Date())+CR_LF+CR_LF+;
                  "Deseja ajustar a data?", "A data do computador está desatualizada")
         lAjusta:=.t.
      Endif
   Else
      MsgInfo("A data/hora do seu computador conferem com as informações da internet."+CR_LF+CR_LF+;
                 "Data: "+cData+"  -  Hora: "+cHora, "Informações da Internet")
   Endif
   If lAjusta
      MsgRun( "Ajustando data e hora.", "Aguarde...", { || fAjustaDataHora(cData, cHora) } )
      MsgInfo("Ajuste realizado com sucesso.", "Ajuste")
   Endif
Return Nil

Static Function fAjustaDataHora(cData, cHora)
   MyRun( "date "+cData )
   MyRun( "time "+cHora )
   If Ctod(cData) <> date()
      MyRun("timedate.cpl") //abre tela data e hora windows
   Endif
Return .t.

************************
FUNCTION USA_SYG_CLOUD()
************************
LOCAL cDADOS_ESTACAO:=GETENV("SYG_CLOUD")
RETURN(!EMPTY(cDADOS_ESTACAO))

************************
FUNCTION MAQUINA_SYGECOM()
************************
LOCAL cDADOS_ESTACAO:=GETENV("SYGECOM_DEVEL")
RETURN(!EMPTY(cDADOS_ESTACAO))

/*------------------------------------------------------------------------------
  Objetivo........: Funções para escrever em arquivo xls de forma nativa 
  Autor...........: João Alpande
  Data de Criacao : 05/08/2019
  Demanda.........: 33543
------------------------------------------------------------------------------*/
#define TXT_ELEMS   12 
#define TXT_OPCO1    1 
#define TXT_OPCO2    2 
#define TXT_LEN1     3 
#define TXT_LEN2     4 
#define TXT_ROW1     5 
#define TXT_ROW2     6 
#define TXT_COL1     7 
#define TXT_COL2     8 
#define TXT_RGBAT1   9 
#define TXT_RGBAT2  10 
#define TXT_RGBAT3  11 
#define TXT_LEN     12 

/*---------------------------------------------------------------- 
  Função..........: xlsOpen
  Objetivo........: Abre o arquivo xls 
-----------------------------------------------------------------*/  
FUNCTION xlsOpen( cPATHARQ ) 
LOCAL nHandle 
LOCAL cBof := Chr(  9 ) + Chr(  0 ) + Chr(  4 ) + Chr(  0 ) + ; 
              Chr(  2 ) + Chr(  0 ) + Chr( 10 ) + Chr(  0 ) 
              
nHandle := fCreate( cPATHARQ ) 
fWrite( nHandle, cBof, Len( cBof )) 
  
RETURN nHandle 

/*---------------------------------------------------------------- 
  Função..........: xlsClose
  Objetivo........: Fecha o arquivo xls 
-----------------------------------------------------------------*/  
FUNCTION xlsClose( nHandle ) 
LOCAL  cEof := Chr( 10 ) + Chr( 0 ) + Chr( 0 ) + Chr( 0 ) 

fWrite( nHandle, cEof, Len( cEof )) 
fClose( nHandle ) 
  
RETURN NIL

/*---------------------------------------------------------------- 
  Função..........: xlsWrite
  Objetivo........: Escreve a uma string na célulaF(nRow, nCol) 
-----------------------------------------------------------------*/  
FUNCTION xlsWrite( nHandle, nRow, nCol, cString ) 
LOCAL anHeader, nLen, nI 

anHeader               := Array( TXT_ELEMS ) 
anHeader[ TXT_OPCO1  ] :=  4 
anHeader[ TXT_OPCO2  ] :=  0 
anHeader[ TXT_LEN1   ] := 10 
anHeader[ TXT_LEN2   ] :=  0 
anHeader[ TXT_ROW2   ] :=  0 
anHeader[ TXT_COL2   ] :=  0 
anHeader[ TXT_RGBAT1 ] :=  0 
anHeader[ TXT_RGBAT2 ] :=  0 
anHeader[ TXT_RGBAT3 ] :=  0 
anHeader[ TXT_LEN    ] :=  2 

nLen              := Len( cString ) 

anHeader[ TXT_LEN ]    := nLen

anHeader[ TXT_LEN1 ]   := 8 + nLen 

nI                     := nRow - 1 
anHeader[ TXT_ROW1 ]   := nI   - (Int( nI / 256 ) * 256 ) 
anHeader[ TXT_ROW2 ]   := Int( nI / 256 ) 
anHeader[ TXT_COL1 ]   := nCol - 1 

Aeval( anHeader, { | v | fWrite( nHandle, Chr( v ), 1 )}) 

FOR nI:=1 TO nLen 
  fWrite( nHandle, SubStr( cString, nI, 1 ), 1 ) 
NEXT nI 
  
RETURN NIL
//------------------------------------------------------------------------------ 

#pragma BEGINDUMP

#include <hbapi.h>
#define _WIN32_IE 0x0501
#include <windows.h>

#ifndef NIF_INFO
   #define NIF_INFO        0x00000010
   #define NIIF_INFO       0x00000001
#endif
#ifndef NIIF_NOSOUND
   #define NIIF_NOSOUND    0x00000010
#endif

HB_FUNC( GETNOTIFYICONDATA )
{
   NOTIFYICONDATAA nid;

   memset( &nid, 0, sizeof( NOTIFYICONDATA ) );

   nid.cbSize = sizeof( NOTIFYICONDATA );
   #ifndef _WIN64
      nid.hWnd   = ( HWND ) hb_parnl( 1 );
   #else
      nid.hWnd   = ( HWND ) hb_parnll( 1 );
   #endif
   nid.uID    = ( UINT ) hb_parnl( 2 );
   nid.uFlags = NIF_INFO | NIF_MESSAGE | NIF_ICON | NIF_TIP ;
   nid.dwInfoFlags = NIIF_INFO | NIIF_NOSOUND;
   nid.uCallbackMessage = ( UINT ) hb_parnl( 3 );
   #ifndef _WIN64
      nid.hIcon  = ( HICON ) hb_parnl( 4 );
   #else
      nid.hIcon  = ( HICON ) hb_parnll( 4 );
   #endif
   strcpy( nid.szTip, hb_parc( 5 ) );
   strcpy( nid.szInfo, hb_parc( 5 ) );
   strcpy( nid.szInfoTitle, hb_parc( 6 ) );

   hb_retclen( ( char * ) &nid, sizeof( NOTIFYICONDATA ) );
}
  
#pragma ENDDUMP

#pragma BEGINDUMP
#include "windows.h"
#include "hbapi.h"
#include <stdio.h>
 
#define SM_SHUTTINGDOWN 0x2000
 
HB_FUNC( ISSHUTDOWN )
{
    BOOL  bRetorno = GetSystemMetrics(SM_SHUTTINGDOWN) != 0;;
    hb_retl( bRetorno );
}
#pragma ENDDUMP


/*
Tem que linkar a LIB: iphlpapi 

 ///////////////////////////////////////////////////////////////////////////////////////////
 // Pega o MAC da placa de Rede
 ///////////////////////////////////////////////////////////////////////////////
#pragma BEGINDUMP
 #include <winsock.h>
 #include <windows.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include <Iphlpapi.h>
 #include <Assert.h>
 #include "hbapi.h"
 #include "hbapiitm.h"
 
 HB_FUNC(MAC_ADDRES)
 {
 IP_ADAPTER_INFO AdapterInfo[16];       // Allocate information for up to 16 NICs
  DWORD dwBufLen = sizeof(AdapterInfo);       // Save the memory size of buffer
  unsigned char ret[ 20 ] ={0};
  DWORD dwStatus = GetAdaptersInfo(           // Call GetAdapterInfo
 AdapterInfo,                                  // [out] buffer to receive data
 &dwBufLen);                                   // [in] size of receive data buffer
  PIP_ADAPTER_INFO pAdapterInfo = AdapterInfo;// Contains pointer to current adapter info
  assert(dwStatus == ERROR_SUCCESS);            // Verify return value is valid, no buffer overflow
  sprintf(ret,"%02X-%02X-%02X-%02X-%02X-%02X",
 pAdapterInfo->Address[0], pAdapterInfo->Address[1],
 pAdapterInfo->Address[2], pAdapterInfo->Address[3],
 pAdapterInfo->Address[4], pAdapterInfo->Address[5]);
  hb_retc(ret);
  }
#pragma ENDDUMP
*/


