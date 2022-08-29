#include "scm.ch"

******************************************************************************************************************************************
FUNCTION MONTA_DBF_EMAIL(cFILE, cServerIP, vPORTSMTP, cFrom, aQuem, aCC, cMsg, cSUBJECT, cUSER, cPASS, aFiles, aBCC, vEMAIL_CONF,vMOSTRA )
******************************************************************************************************************************************
LOCAL vARQ:={}
aadd( vARQ, {"SERVER",     "C",190 ,0} )
aadd( vARQ, {"PORTA",      "N", 10 ,0} )
aadd( vARQ, {"FROM",       "C",190 ,0} )
aadd( vARQ, {"ATO",        "C",190 ,0} )
aadd( vARQ, {"ACC",        "C",190 ,0} )
aadd( vARQ, {"ABCC",       "C",190 ,0} )
aadd( vARQ, {"MSG",        "M", 10 ,0} )
aadd( vARQ, {"SUBJECT",    "M", 10 ,0} )
aadd( vARQ, {"FILES",      "C",190 ,0} )
aadd( vARQ, {"USER",       "C",190 ,0} )
aadd( vARQ, {"PASS",       "C", 90 ,0} )
aadd( vARQ, {"USUARIO",    "C", 30 ,0} )
aadd( vARQ, {"CONF",       "L",  1 ,0} )
aadd( vARQ, {"MOSTRA",     "L",  1 ,0} )
DBcreate(cFILE, vARQ, eRDD_DRIVER)

IF Use_Arq(cFILE,"EMAIL",.F.,.F.,.T.,.T.)=.F.
   RETURN NIL
ENDIF

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
USUARIO        WITH WUSUARIO,;
CONF           WITH vEMAIL_CONF,;
MOSTRA         WITH vMOSTRA
IF LEN(aFiles) > 0
   For x=1 TO LEN(aFiles)
      AppRede()
      REPLACE FILES WITH aFiles[x]
   Next
ENDIF
SELE EMAIL
USE
Return

*****************
Function VAIEMAIL
*****************
PRIVATE oJanela1
PRIVATE oFont, grpConfiguracao
PRIVATE oIcon := HIcon():AddResource(1004)

PRIVATE LQuem, LSubject, LMsg1, LMsg2, LMsg3, LMsg4
PRIVATE LMsg5, LMsg6,    LMsg7, LMsg8, LMsg9, LMsg10
PRIVATE LServerIp, LFrom,LUser, LPass, LPass2

PRIVATE oQuem, oSubject, oMsg1, oMsg2, oMsg3, oMsg4
PRIVATE oMsg5, oMsg6,    oMsg7, oMsg8, oMsg9, oMsg10
PRIVATE oServerIp, oFrom,oUser, oPass, oPass2

PRIVATE wQuem    := SPACE(60)
PRIVATE wSubject := SPACE(60)
PRIVATE wMsg1    := SPACE(60)
PRIVATE wMsg2    := SPACE(60)
PRIVATE wMsg3    := SPACE(60)
PRIVATE wMsg4    := SPACE(60)
PRIVATE wMsg5    := SPACE(60)
PRIVATE wMsg6    := SPACE(60)
PRIVATE wMsg7    := SPACE(60)
PRIVATE wMsg8    := SPACE(60)
PRIVATE wMsg9    := SPACE(60)
PRIVATE wMsg10   := SPACE(60)
PRIVATE wServerIp:= SPACE(40)
PRIVATE wFrom    := SPACE(55)
PRIVATE wUser    := SPACE(40)
PRIVATE wPass    := SPACE(20)
PRIVATE wPass2   := SPACE(20)

PARA cARQ

IF Use_Arq("INSTITUI",,.T.,.T.,.F.)=.F.  // SOMENTE LEITURA
   Return
ENDIF

SELE INSTITUI
wServerIp:=lower(alltrim(server))
wFrom    :=lower(alltrim(email))
wUser    :=lower(alltrim(usuario))
wPass    :=alltrim(senha)
wPass2=Len(wPass)

IF EMPTY(wSERVERiP).OR. EMPTY(wFrom) .OR. EMPTY(wUser) .OR. EMPTY(wPass)
   MsgInfo("Os Dados dos Parametros estão Incompletos para Envio de Email, Favor Verificar no Cadastro de Instituição","Aviso do Sistema")
   RETURN
ENDIF

INIT DIALOG oJanela1 CLIPPER NOEXIT TITLE "Envio de E-mail";
FONT HFont():Add( '',0,-12,400,,,);
AT 0,0 SIZE 670,505;
ICON oIcon ;
STYLE DS_CENTER + WS_VISIBLE + WS_CAPTION + WS_SYSMENU

SetColorinFocus(.t.)
SetToolTipBalloon(.t.)

@ 5,5  GROUPBOX grpConfiguracao              CAPTION "Envio de Email"                                 SIZE 655,445
*******SAYS*******
@ 20 ,40   SAY LServerIp                     CAPTION "Nome do Servidor SMTP:"+wServerIp               SIZE 450,22
@ 20 ,70   SAY LFrom                         CAPTION "Meu E-mail........................:"+wFrom      SIZE 450,22
@ 20 ,100  SAY LUser                         CAPTION "Usuario..............................:"+wUser   SIZE 450,22
@ 20 ,130  SAY Lpass2                        CAPTION "Senha.................................:"+Replicate("*",wPass2) SIZE 400,22
@ 20 ,160  SAY LQuem                         CAPTION "Destinatario:"                     SIZE 120,22
@ 20 ,190  SAY LSubject                      CAPTION "Assunto:"                          SIZE 120,22
@ 10 ,220  SAY LMsg1                         CAPTION "Corpo da Msg:"                     SIZE 120,22
*******SAYS*******

*******GETS*******
@ 100,160    GET OQuem  VAR wQuem                                                        SIZE 460,22;
TOOLTIP "Digite aqui o e-mail do destinatario";
MAXLENGTH 60

@ 100,190    GET OSubject  VAR wSubject                                                  SIZE 460,22;
TOOLTIP "Digite aqui o Assunto do e-mail";
MAXLENGTH 60

@ 100,220    GET OMsg1   VAR wMsg1                                                       SIZE 460,22;
TOOLTIP "Digite aqui a Mensagem do corpo do e-mail";
MAXLENGTH 60

@ 100,240    GET OMsg2   VAR wMsg2                                                       SIZE 460,22;
TOOLTIP "Digite aqui a Mensagem do corpo do e-mail";
MAXLENGTH 60

@ 100,260    GET OMsg3   VAR wMsg3                                                       SIZE 460,22;
TOOLTIP "Digite aqui a Mensagem do corpo do e-mail";
MAXLENGTH 60

@ 100,280    GET OMsg4   VAR wMsg4                                                       SIZE 460,22;
TOOLTIP "Digite aqui a Mensagem do corpo do e-mail";
MAXLENGTH 60

@ 100,300    GET OMsg5   VAR wMsg5                                                       SIZE 460,22;
TOOLTIP "Digite aqui a Mensagem do corpo do e-mail";
MAXLENGTH 60

@ 100,320    GET OMsg6   VAR wMsg6                                                       SIZE 460,22;
TOOLTIP "Digite aqui a Mensagem do corpo do e-mail";
MAXLENGTH 60

@ 100,340    GET OMsg7   VAR wMsg7                                                       SIZE 460,22;
TOOLTIP "Digite aqui a Mensagem do corpo do e-mail";
MAXLENGTH 60

@ 100,360    GET OMsg8   VAR wMsg8                                                       SIZE 460,22;
TOOLTIP "Digite aqui a Mensagem do corpo do e-mail";
MAXLENGTH 60

@ 100,380    GET OMsg9   VAR wMsg9                                                       SIZE 460,22;
TOOLTIP "Digite aqui a Mensagem do corpo do e-mail";
MAXLENGTH 60

@ 100,400    GET OMsg10  VAR wMsg10    VALID {||Focaliza()}                              SIZE 460,22;
TOOLTIP "Digite aqui a Mensagem do corpo do e-mail";
MAXLENGTH 60

*******GETS*******

*******Buttons****
@ 430,465  BUTTON btnOk CAPTION "&Enviar" SIZE 100, 28 ;
TOOLTIP "Enviar o Email";
ON CLICK {|| Verefica_ENVIO() };
STYLE WS_TABSTOP

@ 557,465  BUTTON "&Fechar" SIZE 100, 28 ;
TOOLTIP "Sair do Modulo e Voltar";
ON CLICK {|| oJanela1:Close() };
STYLE WS_TABSTOP
*******Buttons****
ACTIVATE DIALOG oJanela1
RETURN nil

***********************
FUNCTION Verefica_ENVIO
***********************
IF EMPTY(wQuem)
   OBRIGA()
   OQUEM:setfocus()
   RETURN
ENDIF

IF EMIAL_VALIDO(wQuem)=.f.
   MsgInfo("Email Invalido, Favor Vereficar !!!","Aviso do Sistema")
   OQUEM:setfocus()
   RETURN
Endif

oJanela1:Close()

wQuem=lower(alltrim(wQuem))

IF EMPTY(wSubject)
   wSubject="Sem Assunto"
ENDIF

wMsg=wMsg1+HB_OsNewLine()+;
     wMsg2+HB_OsNewLine()+;
     wMsg3+HB_OsNewLine()+;
     wMsg4+HB_OsNewLine()+;
     wMsg5+HB_OsNewLine()+;
     wMsg6+HB_OsNewLine()+;
     wMsg7+HB_OsNewLine()+;
     wMsg8+HB_OsNewLine()+;
     wMsg9+HB_OsNewLine()+;
     wMsg10+HB_OsNewLine()

GERAFILE()
RenameFile( cARQ, cFILE+".TXT" )
cARQ3=cFILE+".TXT"

Envia_email(cARQ3,wSubject,wQuem,wMsg,wServerIp,wFrom,wUser,wPass)

RETURN

****************************
Function EMIAL_VALIDO(cmail)
****************************
Local oRegEx, bVal
TRY
   oRegEx := Createobject("VBScript.RegExp")
CATCH error
  RETURN .T.
END
oRegEx:Pattern :="^[\w-\.]{1,}\@([\da-zA-Z-_]{1,}\.){1,}[\da-zA-Z-_]{2,3}$"
cmail := ALLTRIM(cmail)
bVal := oRegEx:Test(cMail)
Release oRegEx
Return bVal


*****************************
Function BarraProgresso2(tReg)
****************************
@ 60,60 PROGRESSBAR oBar OF oDlg SIZE 300,200 BARWIDTH tReg QUANTITY 1
@ 60,90 say dbf()                SIZE 300,200;
COLOR x_BLUE
Return

*************************
Function INDEXA(PERGUNTA)
*************************
Private oDlg,nIni:=0,oBar
PRIVATE vTotal := 0

Private oDlgHabla:=nil
MsgRun("Aguarde Verificando Uso do sistema pela Rede...")
nSent  := 0
wTOTAL := Verefica_Uso_Exclusivo(.F.)
IF wTOTAL = 0
   Fim_Run()
   MsgStop("Impossível continuar, o Sistema esta em Uso por outra Estação, Favor Verificar","Aviso do Sistema")
   Return NIL
ENDIF
Fim_Run()

IF PERGUNTA="S"
   IF eTipo_banco="SQL"
      IF !MsgYesNo("Atenção !!! Esse Processo é Demorado, Antes de Continuar certifique, que ninguem está usando o Sistema ! Deseja Continuar ?","Aviso do Sistema")
         dbcloseall()
         Return Nil
      endif
   else
      IF !MsgYesNo("Atenção !!! Antes de Continuar certifique, que ninguem está usando o Sistema ! Deseja Continuar ?","Aviso do Sistema")
         dbcloseall()
         Return Nil
      endif
   Endif
ENDIF

PREPARE FONT oFontBtn NAME "Arial" WIDTH 0 HEIGHT -16
INIT DIALOG oDlg Clipper NOEXIT NOEXITESC TITLE "Recriando Índices do Sistema"  ;
FONT oFontBtn ;
AT 220,150;
SIZE 430,150 ;
ICON HIcon():AddResource(1004) ;
STYLE DS_CENTER + WS_VISIBLE + WS_CAPTION + WS_SYSMENU

@ 60,60 PROGRESSBAR oBar OF oDlg SIZE 300,22 BARWIDTH 10000

oDlg:Activate(.t.)

chk_indice(wTOTAL)

oDlg:Close()
Return

****************************
Function Mostra_campo(wTOTAL)
****************************
nSent=nSent+LASTREC()
IF nSent > 0
   HWG_DOEVENTS()
   oBar:Set(,(nSent/wTotal)*100)
   @ 60,90 say Str((nSent/wTotal)*100,4) + " %       " + Left(dbf(),8) SIZE 300,22;
   COLOR x_BLUE
ENDIF
Return

*********************
Function Inicia_Barra
*********************
PREPARE FONT oFontBtn NAME "Arial" WIDTH 0 HEIGHT -16
INIT DIALOG oDlg TITLE "Aguarde...Separando Dados...";
FONT oFontBtn ;
ICON HIcon():AddResource(1004) ;
AT 0,0 SIZE 300,120 NOEXIT STYLE DS_CENTER + WS_VISIBLE
@ 10,20 PROGRESSBAR oBar OF oDlg SIZE 270,30 BARWIDTH 1 QUANTITY 1
oDlg:Activate(.t.)

**************************
Function chk_indice(vCONT)
**************************
Local nInicio := timetosec(time())

DBCLOSEALL()
SET AUTOPEN OFF

IF eTipo_banco="SQL"
   #ifdef _XHBSQL_
   SR_SetFastOpen(.F.)      // HABILITA USO DE TABELAS EM MODO EXCLUSIVO
   #endif
ENDIF

IF MY_FILE("FUNCAO.DBF")
   IF Use_Arq("FUNCAO",,.F.,.F.,.F.)=.T.
      Mostra_campo(vCONT)
      IF eTipo_banco="DBF"
         __dbPack()
         deleta_cdx("FUNCAO")
      ENDIF
      IF ExistTag("1")=.F.
         index on COD    TAG 1
      ENDIF
      IF ExistTag("2")=.F.
         index on FUNCAO TAG 2
      ENDIF
      use
   ELSE
      Erro_Abrir_DBF()
      DBCLOSEALL()
      RETURN
   ENDIF
ENDIF

IF MY_FILE("ASSOCI.DBF")
   IF Use_Arq("ASSOCI",,.F.,.F.,.F.)=.T.
      Mostra_campo(vCONT)
      IF eTipo_banco="DBF"
         __dbPack()
         deleta_cdx("ASSOCI")
      ENDIF
      IF ExistTag("1")=.F.
         INDEX on CODASSOC TAG 1
      ENDIF
      IF ExistTag("2")=.F.
         INDEX on NOME     TAG 2
      ENDIF
      IF ExistTag("3")=.F.
         INDEX on CIDADE   TAG 3
      ENDIF
      IF ExistTag("4")=.F.
         INDEX on VALOR    TAG 4
      ENDIF
      use
   ELSE
      Erro_Abrir_DBF()
      DBCLOSEALL()
      RETURN
   ENDIF
ENDIF

IF MY_FILE("BANCO.DBF")
   IF Use_Arq("BANCO",,.F.,.F.,.F.)=.T.
      Mostra_campo(vCONT)
      IF eTipo_banco="DBF"
         __dbPack()
         deleta_cdx("BANCO")
      ENDIF
      IF ExistTag("1")=.F.
         INDEX on CODCXA    TAG 1
      ENDIF
      IF ExistTag("2")=.F.
         INDEX on DESCRICAO TAG 2
      ENDIF
      use
   ELSE
      Erro_Abrir_DBF()
      DBCLOSEALL()
      RETURN
   ENDIF
ENDIF

IF MY_FILE("MENSAL.DBF")
   IF Use_Arq("MENSAL",,.F.,.F.,.F.)=.T.
      Mostra_campo(vCONT)
      IF eTipo_banco="DBF"
         __dbPack()
         deleta_cdx("MENSAL")
      ENDIF
      IF ExistTag("1")=.F.
         INDEX on CODIGO         TAG 1
      ENDIF
      IF ExistTag("2")=.F.
         INDEX on DTVECTO        TAG 2
      ENDIF
      IF ExistTag("3")=.F.
         INDEX on TIPO           TAG 3
      ENDIF
      IF ExistTag("4")=.F.
         INDEX on SITUACAO       TAG 4
      ENDIF
      IF ExistTag("5")=.F.
         INDEX on DTVECTO        TAG 5 FOR(SITUACAO)="A"
      ENDIF
      IF ExistTag("6")=.F.
         INDEX on str(CODIGO)+str(PARCELA) TAG 6
      ENDIF
      IF ExistTag("7")=.F.
         INDEX on NOME           TAG 7
      ENDIF
      IF ExistTag("8")=.F.
         INDEX on NOME+SITUACAO  TAG 8
      ENDIF
      IF ExistTag("9")=.F.
         INDEX on NOME+str(CODIGO)+str(PARCELA) TAG 9
      ENDIF
      IF ExistTag("10")=.F.
         INDEX on NOME+str(CODIGO) TAG 10
      ENDIF
      IF ExistTag("11")=.F.
         INDEX on CODASS+DTVECTO   TAG 11
      ENDIF
      IF ExistTag("12")=.F.
         INDEX on CODASS           TAG 12
      ENDIF
      use
   ELSE
      Erro_Abrir_DBF()
      DBCLOSEALL()
      RETURN
   ENDIF
ENDIF

oBar:End()

Retorna_Modo_Shared()

_newAlert("A Indexação Terminou com Êxito","Aviso do Sistema")

IF eTipo_banco="SQL"
   nFim := timetosec(time())
   MSGINFO("Tempo Total de Recriação de Índice: "+sectotime(nFim-nInicio),"Aviso do Sistema")
ENDIF

DBCLOSEALL()
RETURN

***********************
Function Erro_Abrir_DBF
***********************
Retorna_Modo_Shared()

MsgInfo("A Seguinte erro aconteceu ao tentar reindexar o banco de dados,"+HB_OsNewLine()+;
        "Erro...>>>> "+ e:description + HB_OsNewLine()+;
        "certifique se não há ninguém usando o sistema na Rede.","Aviso do Sistema")
RETURN

****************************
Function Retorna_Modo_Shared
****************************
SET AUTOPEN ON
IF eTipo_banco="SQL"
   #ifdef _XHBSQL_
   SR_SetFastOpen(.T.)  // DESABILITA USO DE TABELAS EM MODO EXCLUSIVO
   #endif
ENDIF
Return

*--------------------------------------*
* Funcao p/ somar os total de registros
*--------------------------------------*
Function Verefica_Uso_Exclusivo(vZAP) // SE vZAP FOR .T. ELE APAGA OS registros
Local vCONT := 0

#ifdef _XHBCOM_
IF eTipo_banco="SQL" .and. vZAP=.F.
   cSQL := "select * from pg_stat_database where datname = '" +eDATABASE +"'"
   oSql := SR_GetConnection()
   osql:exec(cSQL ,,.t.,@aret)

   vCONT=(aret[1,3]/2)

   IF vCONT > 1  // maior que um usuario
      vCONT=0
   ENDIF
   Return(vCONT)
ENDIF
#endif

IF MY_FILE("ASSOCI.DBF")
   IF Use_Arq("ASSOCI",,.F.,.F.,.F.)=.T.
      vCONT=vCONT+LASTREC()
      IF vZAP=.T.
         ZAP
      ENDIF
      USE
   ENDIF
ENDIF

IF MY_FILE("BANCO.DBF")
   IF Use_Arq("BANCO",,.F.,.F.,.F.)=.T.
      vCONT=vCONT+LASTREC()
      IF vZAP=.T.
         ZAP
      ENDIF
      USE
   ENDIF
ENDIF

IF MY_FILE("FUNCAO.DBF")
   IF Use_Arq("FUNCAO",,.F.,.F.,.F.)=.T.
      vCONT=vCONT+LASTREC()
      IF vZAP=.T.
         ZAP
      ENDIF
      USE
   ENDIF
ENDIF

IF MY_FILE("MENSAL.DBF")
   IF Use_Arq("MENSAL",,.F.,.F.,.F.)=.T.
      vCONT=vCONT+LASTREC()
      IF vZAP=.T.
         ZAP
      ENDIF
      USE
   ENDIF
ENDIF

DBCLOSEALL()

IF vZAP=.T.
   Indexa("N")
ENDIF

RETURN(vCONT)

**************
FUNCTION Sobre
**************
PRIVATE form_sobre3

PRIVATE oGroup1, oOwnerbutton1, oLabel1, oLabel3, oLabel4, oLabel5
PRIVATE oLabel6, oLink1, oLine1, oLabel7, oOwnerbutton2, oLabel2, oLabel8
PRIVATE oLabel9, oLabel10, oLink2, oGroup2, oEditbox1, oEditbox2, oEditbox3

vEditbox1 := "Versão Do Compilador.: " + version() + " + "+ HWG_Version()

IF eTipo_banco="SQL"
   #ifdef _XHBSQL_
   PRIVATE vEditbox2 :="Banco de Dados: " +SR_GetConnectionInfo(, SQL_DBMS_NAME) +" - " +SR_GetConnectionInfo(, SQL_DBMS_VER)
   #ENDIF
ELSE
   PRIVATE vEditbox2 :="Banco de Dados : DBF(Dbase)"
ENDIF

  PREPARE FONT oFontBtn NAME "Arial" WIDTH 0 HEIGHT -12
  INIT DIALOG form_sobre3 CLIPPER NOEXIT TITLE "Informações Sobre o Sistema SCM" ;
  AT 0,0 SIZE 684,620 ;
  ICON HIcon():AddResource(1004);
  STYLE DS_CENTER + WS_VISIBLE + WS_CAPTION + WS_SYSMENU

   @ 23,212 LINE oLine1 OF oGroup1  LENGTH 639

   @ 481,22 BITMAP oOwnerbutton1  ;
        SHOW 1003 FROM RESOURCE  ;
        OF oGroup1  TRANSPARENT SIZE 173,182

   @ 20,32 SAY oLabel1 CAPTION "Sistema Desenvolvido Pela.:" OF oGroup1  SIZE 273,25    ;
   FONT HFont():Add( '',0,-19,700,,,)

   @ 20,63 SAY oLabel3 CAPTION "Sygecom Informática Ltda." OF oGroup1  SIZE 211,24  ;
   COLOR 16711680   ;
   FONT HFont():Add( '',0,-16,700,,,)

   @ 20,93 SAY oLabel4 CAPTION "Rua.: Artur Garcia, 271  - Bairro.: Bela Vista" OF oGroup1  SIZE 334,24  ;
   COLOR 16711680   ;
   FONT HFont():Add( '',0,-16,700,,,)

   @ 20,123 SAY oLabel5 CAPTION "Alvorada - RS /  Cep.: 94810-090" OF oGroup1  SIZE 255,24  ;
   COLOR 16711680   ;
   FONT HFont():Add( '',0,-16,700,,,)

   @ 19,153 SAY oLabel6 CAPTION "Telefones.: (xx51) 3442 - 2345  /  (xx51) 3442 - 3975" OF oGroup1  SIZE 386,24  ;
   COLOR 16711680   ;
   FONT HFont():Add( '',0,-16,700,,,)

   @ 21,183 SAY oLink1 CAPTION "Web Site.: www.sygecom.com.br" OF oGroup1  ;
   LINK 'www.sygecom.com.br'  SIZE 235,22 ;
   COLOR 16711680   ;
   FONT HFont():Add( '',0,-16,400,,,);
   TOOLTIP 'Clique Aqui para Visitar o Site da Sygecom Informática Ltda.'

   @ 180,210  Say "SCM Sistema de Controle de Mensalidades" SIZE 400,20
   @  20,255  Say "Sistema desenvolvido com o intuito de Gerenciar mensalidades" SIZE 450,20
   @  20,270  Say "pagas e á pagar" SIZE 400,20

   @ 10,5 GROUPBOX oGroup1 CAPTION "Informações Gerais do Sistema SCM" SIZE 665,460

   @ 15,495 GET oEditbox1 VAR VERSAOATUAL OF oGroup2  SIZE 652,22 ;
   STYLE WS_DISABLED +WS_BORDER     ;
   TOOLTIP 'Versão'

   @ 15,520 GET oEditbox2 VAR vEditbox1 OF oGroup2  SIZE 652,22 ;
   STYLE WS_DISABLED +WS_BORDER     ;
   TOOLTIP 'Versão Compilador'

   @ 15,547 GET oEditbox3 VAR vEditbox2 OF oGroup2  SIZE 652,22 ;
   FONT HFont():Add( '',0,-12,400,,,);
   STYLE WS_DISABLED +WS_BORDER     ;
   TOOLTIP 'Versão Banco de Dados'

   @ 10,475 GROUPBOX oGroup2 CAPTION "Informações Técnicas do Sistema SCM"  SIZE 665,101

   @ 574,580 BUTTONEX "&Fechar" SIZE 100,38;
   BITMAP (HBitmap():AddResource(1005)):handle  ;
   ON CLICK {|| EndDialog() } ;
   STYLE SS_CENTER

WriteStatus( oTelaPrincipal,3,"Informação sobre a SyGeCom")
   ACTIVATE DIALOG form_sobre3
WriteStatus( oTelaPrincipal,3,"Area de Trabalho")

RETURN Nil

***************
FUNCTION OBRIGA
***************
MSGINFO("OBRIGATORIO !!! Preencher este campo ou (ESC) para sair","Aviso do Sistema")
RETURN

***************
Function AVISO2
***************
Msginfo("O Sistema Não Achou o Banco de Indice e Vai Indexar !!!","Aviso do Sistema")
RETURN

***************
Function OBRIGA5
***************
Msginfo("ATENÇÃO !!! O Sistema não esta Atualizado !!!, Por Favor Tente Novamente","Aviso do Sistema")

********************************************************************************
FUNCTION Sendemail(endereco)
ShellExecute("rundll32.exe","open","url.dll,FileProtocolHandler "+ ;
             "mailto:"+endereco+"?cc=&bcc="+"&subject=Duvida Do Sistema-SCM%20:"+"&body=Duvida Do Sistema-SCM.", , 1)

********************************************************************************
********************************************************************************
************INICIO DAS FUNÇÕES PARA BACK-UP E RETORNO DE BACK-UP****************
********************************************************************************
****************
Function Back_up
****************
PRIVATE aDir0, aDir1, aDir2, vNome_zip
PRIVATE oDlgHabla:=NIL
vCopia="S"
IF eTipo_banco="DBF"
   MsgStop("Atenção Para Fazer um Back-up do Banco de Dados é Nescessario que Ninguem esteja usando o Sistema","Aviso do Sistema")

   IF MSGYESNO("Tem certeza que deseja Fazer o Back-Up Agora ?","Aviso do Sistema")
      MsgRun("Aguarde Compactando o Banco de Dados Para Back-up")
      *- Salvar o caminho
      cDir  := curdrive()+':'
      cHome := curdir()

      vNome_zip  := "Back_up_SCM.sag"
      aDir1 := curdrive()+":\"+rtrim(curdir()) + "\dados\*.dbf"
      aDir2 := curdrive()+":\"+rtrim(curdir()) + "\Back_up_SCM.sag"
      aDir0 := directory(aDir1)
      aArq:={}
      for x=1 to len(aDir0)
         aadd(aArq,curdrive()+":\"+rtrim(curdir())+"\dados\"+aDir0[x,1])
      next
      Fim_Run()

      Private m_oBar,cComplete:=Len(aDir0),m_oDlg_Prog
      Hw_IniBarraProgresso()
      Hw_BarraProgresso(40,[Backup],cComplete)
      m_oBar:Set(,cComplete,.t.)

      hb_zipfile( vNome_zip,aARQ, 9,{|cFile,nPos| eProgresso( cFile, nPos,cComplete) },.t., "senha",.F.,.F., )
        Hw_FimBarraProgresso()

      MsgInfo("Back-up Realizado com Sucesso","Aviso do Sistema")

      s2 := "*.sag"
      s1 := "Back-Up Banco de Dados - SCM " + "( " + s2 + " )"

      DO WHILE .T.
         vNome_zip2 := SaveFile(vNome_zip,s1,s2, )  // DESTINO ONDE VAI SALVAR
         vFILE=STRTRAN(vNome_zip2,vNome_zip,"")+vNome_zip
         IF FILE(vFILE)
            IF MsgYesNo("Arquivo com o mesmo Nome Localizado nesse diretorio, deseja subistituir ?","Aviso do Sistema")
               if vNome_zip2=aDir2
                  vCopia="N"
               endif
               EXIT
            ELSE
               LOOP
            Endif
         Else
            Exit
         ENDIF
      ENDDO
      IF EMPTY(vNome_zip2)
         MsgInfo("O Sistema salvou o Back-Up em...: "+ aDir2,"Aviso do Sistema")
         dbcloseall()
      ENDIF
      IF vCopia="S"
         IF !EMPTY(aDir2) .AND. !EMPTY(vNome_zip2)
            __CopyFile((lower(aDir2)),(lower(vNome_zip2)))
            FERASE(aDir2)
         ENDIF
      endif
      dbcloseall()
      Dirchange(cDir+"\"+cHome)
   ENDIF
else
   MsgInfo("O Sistema não esta preparado para Fazer Back-up de SQL")
Endif
Return Nil

**********************
FUNCTION Ret_Back_up()
**********************
PRIVATE vNome_zip, aDir1
PRIVATE oDlgHabla:=NIL
cDir  := curdrive()+':'
cHome := curdir()

vDIR_TEMP := GETENV("temp")
vCONFILE=vDIR_TEMP+"\CONFIG.SAG"

IF eTipo_banco="DBF"
   MsgStop("Atenção Para Retornar um Back-up do Banco de Dados é Nescessario que Ninguem esteja usando o Sistema","Aviso do Sistema")
   IF MSGYESNO("Atenção Esse Processo é Totalmente Irreversível !!! Tem certeza que deseja Fazer o Retorno do Back-Up Agora ? ","Aviso do Sistema")
      s2 := "*.sag"
      s1 := "Back-Up Banco de Dados - SCM " + "( " + s2 + " )"
      aDir1 := curdrive()+":\"+rtrim(curdir()) + "\dados\"

      vNome_zip := SelectFile( {s1,"Todos Arquivos"},{s2,"*.sag*"} )

      IF LOWER(vNome_zip)=vCONFILE   // configuracoes de balança eletronica
         MsgInfo("Esse Arquivo faz parte das Configurações Gerais do Sistema e não é um Back-Up Valido")
         Return Nil
      endif
      IF EMPTY(vNome_zip) .OR. LASTKEY()=27
         Return Nil
      ENDIF

      MsgRun("Aguarde...Descompactando o Banco de Dados de Back-up")

      aExtract := hb_GetFilesInZip( vNome_zip )
      HB_UNZIPFILE( vNome_zip,,.F.,"senha", aDir1, aExtract )

      Fim_Run()
      dbcloseall()
   ENDIF
else
   MsgInfo("O Sistema não esta preparado para Fazer Back-up de SQL")
Endif
dirchange(cDir+"\"+cHome)
Return Nil

************************************
Function eProgresso(vtxt,xPerc,wTot)
************************************
m_oBar:Set(vTxt,xPerc,.t.)
@ 30,70  SAY "Aguarde Compactando Banco de Dados: "+str((xPerc/wTot)*100)+" %" SIZE 420,22
return nil

***********************************
Function Hw_IniBarraProgresso(vTam)
***********************************
Local xTamJan:=150
if vTam#nil
   xTamJan:=vTam
endif
INIT DIALOG m_oDlg_Prog TITLE "Aguarde em processamento......." ;
     SIZE 450,xTamJan NOEXIT ;
     STYLE DS_CENTER + WS_VISIBLE
     m_oDlg_Prog:Activate(.t.)
return nil

*******************************
Function Hw_FimBarraProgresso()
*******************************
m_oDlg_Prog:Close()
m_oDlg_Prog:=nil
m_obar:=nil
m_xBarra:=40
return nil

**********************************************
Function Hw_BarraProgresso(xLinha,vTexto,xReg)
**********************************************
Local xTexto:=[],vLInha:=80,xObar:=m_Obar,tReg:=100
xTexto:=hb_OemtoAnsi(vTexto)
if xLinha#nil
   vLinha:=xLinha
endif
if xReg#nil
   tReg:=xReg
endif
SetWindowText(m_oDlg_Prog:Handle,xTexto)

@ 30,vLinha PROGRESSBAR m_oBar OF m_oDlg_Prog SIZE 350,100 BARWIDTH tReg QUANTITY 1
m_oBar:Set(,1,.t.)
return nil
********************************************************************************
************FIM DAS FUNÇÕES PARA BACK-UP E RETORNO DE BACK-UP*******************
********************************************************************************

Function ErroReg()
MsgINFO("Não foi possível localizar o registro, Registro não cadastrado ou excluido, Tente novamente.","Aviso do Sistema")
Return(Nil)


Function Limpa()  // função para limpar a memoria do micro
HB_GCALL()
return nil

**************************
FUNCTION MYRUN( cComando )
**************************
local oShell, RET
oShell := CreateObject( "WScript.Shell" )
RET := oShell:Run( "%comspec% /c " + cComando, 0, .T. )
oShell := NIL
return iif( RET = 0, .T., .F. )

********************************************************************************
***************INICIO DO TESTE DE CONEXÃO DE INTERNET***************************
********************************************************************************
**************************************
Function inetestaconectada( cAddress )
**************************************
LOCAL aHosts
LOCAL cName
InetInit()
IF cAddress == NIL
   cAddress := "www.google.com.br"
ENDIF
aHosts := InetGetHosts( cAddress )
IF aHosts == NIL .or. len(aHosts)=0
   InetCleanup()
   RETURN .f.
endif
InetCleanup()
RETURN .t.

********************************************************************************
***************FIM DO TESTE DE CONEXÃO DE INTERNET******************************
********************************************************************************

********************************************************************************
***************INICIO DO TESTE DE IP EXTERNO************************************
********************************************************************************
FUNCTION IP_EXTERNO()
   url := 'http://www.meuip.com.br/'
   html:= ReadPage_ler( url )
   vRET:= PegaIP_ex(html)
RETURN vRET

FUNCTION PegaIP_ex(cHtml)
   LOCAL Pos, PosF
   Pos := At('IP?', Upper(cHtml) )
   IF Pos < 1
      RETURN 0
   ENDIF
   Pos   += Len('IP?')
   cHtml := subst( cHtml, Pos )
   PosF  := At('</TITLE>',Upper(cHtml)) - 1
   cHtml := Subst(cHtml,1,PosF)
RETURN cHtml

FUNCTION ReadPage_ler( cUrl )
   LOCAL oUrl, oCli, cRes := ''
   BEGIN SEQUENCE
      oUrl = TUrl():New( cUrl )
      IF EMPTY( oUrl )
         BREAK
      ENDIF
      oCli = TIPClient():New( oUrl )
      IF EMPTY( oCli )
         BREAK
      ENDIF
      oCli:nConnTimeout = 20000
      IF !oCli:Open( oUrl )
         BREAK
      ENDIF
      cRes := oCli:Read()
      oCli:Close()
   END SEQUENCE
RETURN cRes
********************************************************************************
***************FIM DO TESTE DE IP EXTERNO***************************************
********************************************************************************

*****************FUNCOES DE IMPRESSAO***********************
#define ID_TEXTO  300
******************************
FUNCTION Edicao(cFile)   // esse aqui funciona beleza
******************************
Private oDlg_edicao
Private or_Text :=cFile
Private lText := MemoRead(cFile)
Private oFont, oEdit

Private nsizefont := -13

PREPARE FONT oFont NAME "COURIER NEW" WIDTH 0 HEIGHT 0 WEIGHT -13
Private oFont2 := HFont():Add( "Courier New",0,-10 )

INIT DIALOG oDlg_edicao TITLE "Visualização em Tela" ;
AT 0,0 SIZE HWG_GETDESKTOPWIDTH()-8,HWG_GETDESKTOPHEIGHT()-25;
FONT oFont;
ICON HIcon():AddResource(1004);
ON INIT  {|| ZOOMIMP2(oEdit,'-',nsizefont),.T.} ;
STYLE WS_POPUP+WS_CAPTION+DS_CENTER +WS_SYSMENU+WS_MINIMIZEBOX+WS_MAXIMIZEBOX+WS_VISIBLE ;

@ 100,19 RichEdit oEdit TEXT lText SIZE HWG_GETDESKTOPWIDTH()-100,HWG_GETDESKTOPHEIGHT()-100;
OF oDLG_edicao ID ID_TEXTO;
COLOR 0 BACKCOLOR 16777215 ;
ON Getfocus {|| TopoDoc(oEdit)};
STYLE WS_TABSTOP+WS_HSCROLL+WS_VSCROLL+ES_LEFT+ES_MULTILINE+ES_READONLY;
FONT oFont2

@ 6,30  BUTTONEX oButtonex1 CAPTION "-Zoom" SIZE 90,38 ;
ON CLICK {|| ZOOMIMP2(oEdit,'-',nsizefont)};
BITMAP (HBitmap():AddResource(1008)):handle  ;
FONT HFont():Add( '',0,-11,400,,,);
TOOLTIP "Clique aqui para Diminuir o Zoom"

@ 6,80  BUTTONEX oButtonex2 CAPTION "+Zoom" SIZE 90,38 ;
ON CLICK {|| ZOOMIMP2(oEdit,'+',nsizefont)};
FONT HFont():Add( '',0,-11,400,,,);
BITMAP (HBitmap():AddResource(1007)):handle  ;
TOOLTIP "Clique aqui para Aumentar o Zoom"

@ 6,130 BUTTONEX oButtonex3 CAPTION "&Imprimir" SIZE 90,38 ;
ON CLICK {|| CHAMAIMP("S",or_Text)};
BITMAP (HBitmap():AddResource(1009)):handle  ;
FONT HFont():Add( '',0,-11,400,,,);
TOOLTIP "Clique aqui para Imprimir"

@ 6,180 BUTTONEX oButtonex4 CAPTION "Gera &Pdf" SIZE 90,38 ;
ON CLICK {|| GERA_PDF(or_Text,"S")};
BITMAP (HBitmap():AddResource(1010)):handle  ;
FONT HFont():Add( '',0,-11,400,,,);
TOOLTIP "Clique aqui para Gerar arquivo PDF"

@ 6,230 BUTTONEX oButtonex5 CAPTION "Gera &Word" SIZE 90,38;
ON CLICK {|| Abre_word(or_Text)};
BITMAP (HBitmap():AddResource(1011)):handle  ;
FONT HFont():Add( '',0,-10,400,,,);
TOOLTIP "Clique aqui para Gerar arquivo WORD"

@ 6,280 BUTTONEX oButtonex6 CAPTION "Gera &Html" SIZE 90,38;
ON CLICK {|| Gera_Html(or_Text)};
BITMAP (HBitmap():AddResource(1012)):handle TRANSPARENT;
FONT HFont():Add( '',0,-10,400,,,);
TOOLTIP "Clique aqui para Gerar um arquivo HTML"

@ 6,330 BUTTONEX oButtonex6 CAPTION "Gera &Excel" SIZE 90,38 ;
ON CLICK {|| Gera_Excel_txt(or_Text)};
BITMAP (HBitmap():AddResource(1013)):handle  ;
FONT HFont():Add( '',0,-10,400,,,);
TOOLTIP "Clique aqui para Gerar um arquivo EXCEL"

@ 6,380 BUTTONEX oButtonex7 CAPTION "&E-Mail" SIZE 90,38;
ON CLICK {|| VAIEMAIL(or_Text)};
BITMAP (HBitmap():AddResource(1014)):handle  ;
FONT HFont():Add( '',0,-10,400,,,);
TOOLTIP "Clique aqui para Enviar por E-mail"

@ 6,430 BUTTONEX oButtonex8 CAPTION "&Fechar" SIZE 90,38;
ON CLICK {|| oDlg_edicao:close() };
BITMAP (HBitmap():AddResource(1005)):handle  ;
FONT HFont():Add( '',0,-11,400,,,);
STYLE WS_TABSTOP;
TOOLTIP "Clique aqui para Fechar"

ACTIVATE DIALOG oDlg_edicao //Show SW_SHOWMAXIMIZED

RETURN

***********************
FUNCTION topodoc(oEdit)
***********************
Local nPos
npos := SendMessage( oedit:handle, EM_GETSEL, 0, 0 )
keyb_event(VK_HOME,.T.)
SendMessage(oEdit:handle,EM_SETSEL,Loword(npos),Loword(npos))
return .t.

******************************
FUNCTION ZOOMIMP2(oEdit,csize)
******************************
nsizefont := nsizefont + iif(csize='-', 1 , -1)
nsizefont := iif(csize='-',min(-9,nsizefont),;
max(-25,nsizefont))
oFont2 := HFont():Add( "Courier New",0,nsizefont )
sendMessage(oEDiT:Handle,WM_SETFONT ,oFont2:handle,0 )
oEdIT:refresh()
RETURN .T.

*****************
Function CHAMAIMP
*****************
LOCAL cPrinterName, cPrinterPort, cCopias
LOCAL aPrn    := GetPrinters(.t.,.f.)
LOCAL nResult := -1
LOCAL cMsg    := ""

PARA TAM,cARQ   // S=136 N=79

IF TAM=Nil
   TAM="S"
ENDIF

If Empty(aPrn)
   OBRIGA11()
   Return
EndIf

IF !EMPTY(cARQ)
   cFILE := cARQ
ELSE
   MsgInfo("Não foi possivel Gerar arquivo de impressão, Tente Novamente.","Aviso do Sistema")
   Return
ENDIF

nPrn:=New_PRINTSETUP( @cPrinterName, @cCopias )
*nPrn:=PRINTSETUP( @cPrinterName, @cCopias )

for i=1 to len(aPrn)
   IF aPrn[i,1] = cPrinterName
      cPrinterPort = aPrn[i,2]
      exit
   ENDIF
next

IF cPrinterPort#Nil
*   IF SY_IsPrint( cPrinterName ) # "Impressora OK"  // teste usando função da fivewin
*      MsgInfo(SY_IsPrint(cPrinterName),"Aviso do Sistema")
*      Return
*   ENDIF

   IF LEFT(UPPER(cPrinterPort),3)="LPT"
      nResult := PrintFileRaw( cPrinterName, cFile, "Impressao Pelo Sistema SCM" )
      IF nResult = -1
         cMsg = "Parametros Invalido, Favor Tentar Novamente"
      ELSEIF nResult = -2
         cMsg = "Falha na chamada da Impressora, Favor Verificar a Impressora"
      ELSEIF nResult = -3
         cMsg = "Falha ao Iniciar Impressão, Favor Verificar a Impressora"
      ELSEIF nResult = -4
         cMsg = "Falha ao Iniciar a Primeira Pagina, Favor Verificar a Impressora"
      ELSEIF nResult = -5
         cMsg = "Falha de Memoria da Impressora, Favor Verificar a Impressora"
      ELSEIF nResult = -6
         cMsg = "Não foi Possivel localizar o arquivo de Impressão, Favor Tentar Novamente"
      ENDIF
      IF len(alltrim(cMsg)) > 1
         MsgInfo(cMsg,"Aviso do Sistema")
         Return
      ENDIF
   ELSE
      IF TAM="S"
         IF !EMPTY(cPrinterName)
            Imprime(cFILE,136,cPrinterName,cCopias)
         ENDIF
      ELSE
         IF !EMPTY(cPrinterName)
            Imprime(cFILE,80,cPrinterName,cCopias)
         ENDIF
      ENDIF
   ENDIF
ENDIF
RETURN NIL

#pragma BEGINDUMP
#include "windows.h"
#include "hbapi.h"

HB_FUNC( NEW_PRINTSETUP )
   {
     PRINTDLG   pd;
        LPDEVNAMES lpDevNames;
        LPDEVMODE lpDevMode;
        HWND hwnd;
  LPSTR lpPrinterName;

      // setting the handle
 // hwnd =(HWND) hb_parnl(1);

        // Initialize PRINTDLG
  ZeroMemory(&pd, sizeof(pd));

  pd.lStructSize = sizeof(pd);
  pd.hwndOwner = GetActiveWindow();
  pd.hDevMode    = NULL;
  pd.hDevNames   = NULL;
  pd.Flags       = PD_USEDEVMODECOPIESANDCOLLATE | PD_RETURNDC;
  pd.nCopies     = 1;

  if (PrintDlg(&pd)==TRUE)
  {
     lpDevMode = (LPDEVMODE) GlobalLock( pd.hDevMode );
     GlobalUnlock( pd.hDevMode );

     lpDevNames = (LPDEVNAMES) GlobalLock( pd.hDevNames );
     if( lpDevNames )
     {
        GlobalUnlock( pd.hDevNames );
        lpPrinterName = ( LPSTR ) lpDevNames + lpDevNames->wDeviceOffset;
        hb_storc( (LPSTR)lpPrinterName, 1 );
        hb_storni( lpDevMode->dmCopies, 2 );
        if (pd.hDevMode)
            GlobalFree( pd.hDevMode );
            if (pd.hDevNames)
                GlobalFree( pd.hDevNames );
     }
     else
        hb_retc( "" );
  }
  else
     hb_retc( "" );
   }
#pragma ENDDUMP

Function SY_IsPrint( QuePrinter )
   LOCAL eStatus
   DEFAULT QuePrinter := "LPT1:"
*   eStatus := PrnStatus( QuePrinter )
   if     eStatus <        1 ; return "Impressora OK"
   elseif eStatus =        1 ; return "Impressora Pausada"
   elseif eStatus =        2 ; return "Impressora com Erro"
   elseif eStatus =        4 ; return "Impressora Deletando"
   elseif eStatus =        8 ; return "Impressora em Modo Bandeja"
   elseif eStatus =       16 ; return "Impressora Sem Papel"
   elseif eStatus =       32 ; return "Impressora em Modo Manual"
   elseif eStatus =       64 ; return "Impressora com Problema no Papel"
   elseif eStatus =      128 ; return "Impressora OffLine"
   elseif eStatus =      256 ; return "Impressora com IO Ativo"
   elseif eStatus =      512 ; return "Impressora Ocupada"
   elseif eStatus =     1024 ; return "Impressora Imprimindo"
   elseif eStatus =     2048 ; return "Impressora Memoria Lotada"
   elseif eStatus =     4096 ; return "Impressora Nao Instalada"
   elseif eStatus =     8192 ; return "Impressora Aguardando"
   elseif eStatus =    16384 ; return "Impressora Processando"
   elseif eStatus =    32768 ; return "Impressora Inicializando"
   elseif eStatus =    65536 ; return "Impressora em Atencao"
   elseif eStatus =   131072 ; return "Impressora Toner Baixo"
   elseif eStatus =   262144 ; return "Impressora Sem Toner"
   elseif eStatus =   524288 ; return "Impressora PAGE_PUNT"
   elseif eStatus =  1048576 ; return "Impressora Intervencao do Usuario"
   elseif eStatus =  2097152 ; return "Impressora Sem Memoria"
   elseif eStatus =  4194304 ; return "Impressora Tampa Aberta"
   elseif eStatus =  8388608 ; return "Impressora Servidor Desconhecido"
   elseif eStatus = 16777217 ; return "Impressora POWER_SAVE"
   endif
return nil

*****************
Function OBRIGA11
*****************
IF MsgYesNo("ATENÇÃO !!! Não foi possivel localizar Nenhuma impressora Instalada no Windows, Deseja Instalar uma Agora ?","Aviso do Sistema")
   RunApplet_imp( "AddPrinter" )
Endif
Return(Nil)

**************************************************
Function Imprime( cArq, tamrel ,cPrinter, cCopias)
**************************************************
local cTexto, nLinhas, nA, cLinha, oBMP
local oPrinter := win32prn():New(cPrinter)
cText := memoread( cArq )
oPrinter:Landscape:= .F.
oPrinter:FormType:= 9
oprinter:SetPrintQuality(-1) // qualidade da impressão
oPrinter:Copies:=cCopias

IF !oPrinter:Create()
   MsgStop("ATENÇÃO !!! Não foi possivel Iniciar a Impressão, Favor Verificar se a Impressora esta Ligada.","Aviso do Sistema")
   return NIL
else
   IF !oPrinter:StartDoc("Impressao Pelo Sistema SCM")
      MsgStop("ATENÇÃO !!! Não foi possivel Iniciar a Impressão, Favor Verificar a Impressora","Aviso do Sistema")
      Return NIL
   endif

   IF File("res\logo.bmp")  // se tiver o arquivo logo.bmp dentro da mesma pasta ele vai imprimir o logo primeiro
      oBMP:= Win32BMP():new()
      oBmp:loadFile( "res\logo.bmp" )
      oBmp:Draw( oPrinter,  { 15,15,60,60 } )
      aTamlog := 9
   else
      aTamlog := 2
   endif

   FOR TT=1 TO aTamlog
      oPrinter:newline()
   NEXT
   //oPrinter:CharSet( 255 )

   IF TAMREL=80
      oPrinter:setfont('Courier New',,12,,,,255) // Normal
      nLines2 := 85
   ELSE
      oPrinter:SetFont("Courier New",13,{3,-50},0,.F.,.F.) // Comprimida
      nLines2 := 150
   ENDIF
   oPrinter:Bold(0) // Normal
*   oPrinter:newline() // Inicia nova linha

   nLines := mlcount( cText, nLines2 )
   for nA := 1 to nLines
      cLine := memoline( cText, nLines2, nA, 1, .F. )
      If Left(AllTrim(cLine),1)==Chr(12) //SALTO DA PAGINA
         oPrinter:NewPage()
         IF FILE("res\logo.bmp")  // se tiver o arquivo logo.bmp dentro da mesma pasta ele vai imprimir o logo primeiro
            oBMP:= Win32BMP():new()
            oBmp:loadFile( "res\logo.bmp" )
            oBmp:Draw( oPrinter,  { 15,15,60,60 } )
            aTamlog := 9
         else
            aTamlog := 2
         endif
      endif

      oPrinter:TextOut( cLine, .T. )
      oPrinter:Bold(0) // Normal

      if (oPrinter:MaxRow()-2 ) <= oPrinter:Prow()
         oPrinter:NewPage()
         IF FILE("res\logo.bmp")  // se tiver o arquivo logo.bmp dentro da mesma pasta ele vai imprimir o logo primeiro
            oBMP:= Win32BMP():new()
            oBmp:loadFile( "res\logo.bmp" )
            oBmp:Draw( oPrinter,  { 15,15,60,60 } )
            aTamlog := 9
         else
            aTamlog := 2
         endif

         FOR TT=1 TO aTamlog
            oPrinter:newline()
         NEXT
      endif
   next

   oPrinter:EndDoc()
   oPrinter:Destroy()
ENDIF
RETURN NIL

***********************************************************************************************************
Function Envia_email(aFiles,cSubject,aQuem,cMsg,cServerIp,cFrom,cUser,cPass,vPORTSMTP,aCC,aBCC,vEMAIL_CONF)
***********************************************************************************************************
LOCAL nBytes, nChild, nError, nStdIN, nStdOUT, nStdERR
LOCAL oOutLook,oMailItem,oRecip,oAttach
PRIVATE oDlgHabla:=NIL

MsgRun("Conectando ao Servidor e Enviando o Email,Aguarde !!!",)
IF inetestaconectada()=.T.
   HW_Atualiza_Dialogo("Aguarde...Enviando e-mail..." )
   GeraFile()
   Monta_DBF_Email(cFILE, cServerIP, vPORTSMTP, cFrom, aQuem, aCC, cMsg, cSUBJECT, cUSER, cPASS, aFiles, aBCC, vEMAIL_CONF,.T.)

   MyRun2( "envia_email " + cFILE+".dbf" )
   Fim_Run()
else
   Fim_Run()
   MsgInfo("Não foi possivel estabelecer uma conexão com a Internet, Favor verificar","Aviso do Sistema")
Endif
RETURN nil

***********************
FUNCTION MyRun2( cRun )
***********************
Local hIn, hOut, nRet //, hProc
Local hProc := HB_OpenProcess( cRun , @hIn, @hOut, @hOut )

IF hProc < 0
   FClose( hProc )
   FClose( hIn )
   FClose( hOut )
   Return(.F.)
*   msginfo("Error: " + valtoprg(FError()))
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

*****************************
Function Gera_Excel_txt(cArq)
*****************************
PRIVATE oDlgHabla:=NIL

MsgRun("Aguarde Gerando Arquivo Excel !!!",)
Private arq, arqh, txt, txt_t

TRY
   oExcel := GetActiveObject( "Excel.Application" )
CATCH
   TRY
      oExcel := CreateObject( "Excel.Application" )
   CATCH
      fim_run()
      MsgStop( "Erro! O Excel não esta Ativado ou Não instalada nesse Computador","Aviso do Sistema")
      RETURN
   END
END

cText := memoread( cArq )

GeraFile()
arq=(cFILE)+".xls"

if !file(arq)
   arqh=fcreate(arq,0)
   if !arqh>0
      Fim_Run()
      Return
   endif
   txt='<HTML><HEAD><TITLE>Visualizacao de Relatorios</TITLE>'
   txt_t=fwrite(arqh,txt + HB_OsNewLine())
   txt='<BODY><DIV ALIGN="center"> <TABLE CLASS="tmain" WIDTH="90%" CELLPADDING="4" CELLSPACING="0"> <TD>&nbsp;<BR>'
   txt_t=fwrite(arqh,txt + HB_OsNewLine())
   txt='<PRE>'
   txt_t=fwrite(arqh,txt + HB_OsNewLine())

   nLines := mlcount( cText, 150 )
   for nA := 1 to nLines
      cLinha := memoline( cText, 150, nA, 1, .F. )

      HW_Atualiza_Dialogo(cLinha)

      fwrite(arqh, cLinha + HB_OsNewLine())
   next

   txt='</PRE>'
   txt_t=fwrite(arqh,txt + HB_OsNewLine())
   txt='</TR></TABLE></TD></TR></TABLE></DIV></BODY></HTML>'
   txt_t=fwrite(arqh,txt + HB_OsNewLine())

   fclose(arqh)
endif

Fim_Run()

if !file(arq)
   MsgStop("Erro ao Abrir o Arquivo Excel, Favor verificar seu Navegador padrão","Aviso do Sistema")
   RETURN
else
   Abre_arquivo( arq )
ENDIF
RETURN

************************
Function Gera_Html(cArq)
************************
PRIVATE oDlgHabla:=NIL
MsgRun("Aguarde Gerando Arquivo HTML !!!",)
Private arq, arqh, txt, txt_t

cText := memoread( cArq )

GeraFile()
arq=(cFILE)+".html"

if !file(arq)
   arqh=fcreate(arq,0)
   if !arqh>0
      Fim_Run()
      Return
   endif
   txt='<HTML><HEAD><TITLE>Visualizacao de Relatorios</TITLE>'
   txt_t=fwrite(arqh,txt + HB_OsNewLine())
   txt='<BODY><DIV ALIGN="center"> <TABLE CLASS="tmain" WIDTH="90%" CELLPADDING="4" CELLSPACING="0"> <TD>&nbsp;<BR>'
   txt_t=fwrite(arqh,txt + HB_OsNewLine())
   txt='<PRE>'
   txt_t=fwrite(arqh,txt + HB_OsNewLine())

   nLines := mlcount( cText, 150 )
   for nA := 1 to nLines
      cLinha := memoline( cText, 150, nA, 1, .F. )

      HW_Atualiza_Dialogo(cLinha)

      fwrite(arqh, cLinha + HB_OsNewLine())
   next

   txt='</PRE>'
   txt_t=fwrite(arqh,txt + HB_OsNewLine())
   txt='</TR></TABLE></TD></TR></TABLE></DIV></BODY></HTML>'
   txt_t=fwrite(arqh,txt + HB_OsNewLine())

   fclose(arqh)
endif

Fim_Run()

if !file(arq)
   MsgStop("Erro ao Abrir o Arquivo HTML, Favor verificar seu Navegador padrão","Aviso do Sistema")
   RETURN
else
   Abre_arquivo( arq )
ENDIF
RETURN

******************************
Function Abre_Manual(cArq,IMP)
******************************
LOCAL oWord,oText,oDoc
PRIVATE oDlgHabla:=NIL
IF IMP=Nil
   IMP="N"
endif
MsgRun("Aguarde Gerando Documento de Word...")

GERAFILE()
RenameFile( cARQ, cFILE+".DOC" )
cARQ=cFILE+".DOC"

TRY
   oWord := GetActiveObject(  "Word.Application" )
CATCH
   TRY
      oWord := CreateObject( "Word.Application" )
   CATCH
      MsgStop("Não foi Possivel Achar o Word Instalado","Aviso do Sistema")
      Fim_Run()
      RETURN
   END
END

IF !FILE(cARQ)
   MsgStop("Não Foi possivel Abrir o Documento de Word")
   Fim_Run()
   RETURN
ENDIF
oDoc := oWord:Documents:Open(cARQ)  //ABRE O WORD

IF IMP="N"
   oWord:Visible := .T. //PARA VISUALIZAR OU NÃO ANTES
   oWord:WindowState := 1  // Maximize
ENDIF
IF IMP="S"
   oWord:Visible := .F. //PARA VISUALIZAR OU NÃO ANTES
   oWord:PrintOut()   //PARA IMPRIMIR DIRETO
ENDIF
Fim_Run()
RETURN

********************************************************************************
***************INICIO DA MENSAGEM RUM NA TELA***********************************
********************************************************************************
//delclara a variavel do dialogo
*Private oDlgHabla:=nil

//Mostra a tela de dialogo
*MsgRun()

//inicia a impressão a cada linha
*HW_Atualiza_Dialogo(vMENSAGEM)

//fin do relatorio
*hw_FimDialogoTemporal()

// -----------------------------------
// Rutina para un diálogo temporizado.
// -----------------------------------

**********************
FUNCTION MsgRun( cMsg )
**********************
Local vMsg:=[Aguarde em processamento....]
Local oFonte:= oFonte:= HFont():Add( "Arial"     , 0 ,-18,550,255 )
Local oBmp      := HBitmap():AddFile("res\fundo.bmp")
PRIVATE oTimHabla
if cMsg#nil
   vMsg:=cMsg
endif

INIT DIALOG oDlgHabla TITLE "Processando..." ;
SIZE 485, 100  ;
STYLE DS_CENTER + WS_VISIBLE ;
ON INIT {|| IniDlgHabla() }  ;
ON EXIT {|| CierraDialogo() };
Background Bitmap oBmp

@ 45, 20  SAY vMsg SIZE 465, 20 FONT oFonte;
BACKCOLOR Rgb(255, 255, 255)

@ 5,20 ANIMATION oAnime ;
      OF oDlgHabla ;
      SIZE 32,32;
      FILE "res\processando.avi";
      AUTOPLAY
oAnime:Play()

ACTIVATE DIALOG oDlgHabla NOMODAL

Return .T.

Function Inicia_Run()
Private oDlgHabla:=nil

// ----------------------
// Inicializar el diálogo
// ----------------------
FUNCTION IniDlgHabla()
   oDlgHabla:Center()
   SET TIMER oTimHabla OF oDlgHabla ID 9006 VALUE 2000 ACTION {|| CierraDialogo() }
Return .T.

// ---------------
// Fin del diálogo
// ---------------
FUNCTION Hw_FimDialogoTemporal(cTime)
if cTime#nil
   if oDlgHabla#nil
      oDlgHabla:close()
      oDlgHabla:=nil
   endif
endif
Return .T.

Function Fim_Run()
IF oDlgHabla#NIL
   oDlgHabla:CLOSE()
ENDIF

// ---------------
// Cerrar diálogo.
// ---------------
FUNCTION CierraDialogo()
   EndDialog()
RETURN .T.

****************************************
FUNCTION HW_Atualiza_Dialogo2(vMensagem)
****************************************
IF vMensagem=nIL
   vMensagem:="Aguarde em processamento...."
endif
HWG_DOEVENTS()
*hwg_processmessage()
oDlgHabla:ACONTROLS[1]:SETTEXT(vMensagem)
RETURN NIL

***************************************
FUNCTION HW_Atualiza_Dialogo(vMensagem)
***************************************
HWG_DOEVENTS()
*hwg_processmessage()
TRY
   IF TYPE(vMensagem)="N"
      WriteStatus( oTelaPrincipal,3, STR(vMensagem))
   ELSE
      WriteStatus( oTelaPrincipal,3, vMensagem)
   ENDIF
catch e
   Return .T.
END
RETURN .T.

********************************************************************************
***************FIM DA MENSAGEM RUM NA TELA**************************************
********************************************************************************

****************************************
Function Abre_word( cArquivo, nColunas )
****************************************
local cArqRtf, arq, arq_txt, cHandle
local cCaractere  := space( 01 )
local cLinha      := space( 01 )
local lf          := chr( 13 ) + chr( 10 )

PRIVATE oDlgHabla:=NIL
MsgRun("Aguarde Gerando Documento de Word...")

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
  fwrite( arq, cCaractere )
NEXT
cHandle  := "}"
fwrite( arq, cHandle )
fclose( arq          )
fclose( arq_txt      )

Fim_Run()
Abre_arquivo( cArqRtf )
Return( .T. )

*******************************
Function GERA_PDF(cARQ, vABRE )
*******************************
PRIVATE oDlgHabla:=NIL
MsgRun("Aguarde Gerando Documento PDF...")
cText := memoread( cArq )
nLines := mlcount( cText, 150 )

GERAFILE()
cFileToSave := cFILE+".PDF"  // nome do PDF

Private AMSG := {}, CIMG
set(105,1)
set(106,1)

vAUTOR=""
PdfNew(cFileToSave,6,842,595,1,20,,,)  // esse é o que eu uso
PdfStartPage( {vAUTOR} , .T. )
HB_SETLANDSCAPE(.T.)

for nA := 1 to nLines
   cLinha := memoline( cText, 150, nA, 1, .F. )

   Aadd(AMSG,cLinha)
next

PdfDrawPage( AMSG )
PdfEndPage()
PdfEnd()

Fim_Run()
IF vABRE="S"
   Abre_arquivo( cFileToSave )
ENDIF
Return(cFileToSave)

***************************
Function Gera_Excel(vALIAS)
***************************
PRIVATE oDlgHabla:=NIL
MsgRun("Aguarde Gerando Documento EXCEL...")

GERAFILE()
Select(vALIAS)
COPY TO (cFILE)+".xls"
cArq=cFILE+".xls"

ShellExecute(cArq)
Fim_Run()
Return

******************
FUNCTION Busca_REL
******************
PRIVATE oFRMbuscarel
PRIVATE LBLassociado, Wassociado := "", Oassociado, aItens3:={}
PRIVATE oFont :=NIL
PRIVATE oIcon := HIcon():AddResource(1004)
Wassociado:=Space(50)

PARA TIPOREL 

DBCLOSEALL()

IF Use_Arq("MENSAL",,.T.,.F.,.F.)=.F.  // COMPARTILHADO
   Return
ENDIF

IF Use_Arq("ASSOCI",,.T.,.F.,.F.)=.F.  // COMPARTILHADO
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
   INIT DIALOG oFRMbuscarel CLIPPER NOEXIT TITLE "Sistema de Busca";
   SIZE 530,120;
   FONT oFont;
   ICON oIcon;
   STYLE DS_CENTER + WS_VISIBLE + WS_CAPTION + WS_SYSMENU

   @ 5,5     GROUPBOX grpConfiguracao          CAPTION "Pesquisa Associado"     SIZE 520,115

   @  10,40  SAY LBLassociado                   CAPTION "Nome Associado:"       SIZE 168,22
   @ 110,40  GET COMBOBOX Oassociado VAR wAssociado   ITEMS aItens3 COLOR 255   SIZE 400,22 EDIT;
     TOOLTIP "Informe o Nome que Deseja Buscar";
       ON CHANGE { || Busca_dados2(Wassociado) }
 
IF TIPOREL="P"
   @  250,70 BUTTON btnOk CAPTION "Mostrar Relatorio";
   ON CLICK {||REL_PARC_ASSOCI("AP"),EndDialog()};
   SIZE 150,32 STYLE WS_TABSTOP;
   TOOLTIP "Confirma a Busca"
ELSEIF TIPOREL="A"
   @  250,70 BUTTON btnOk CAPTION "Mostrar Relatorio";
   ON CLICK {||REL_PARC_ASSOCI("AA"),EndDialog()};
   SIZE 150,32 STYLE WS_TABSTOP;
   TOOLTIP "Confirma a Busca"
ENDIF

   @ 410,70 BUTTON "Fechar";
   ON CLICK {||EndDialog()};
   SIZE 100,32;
   TOOLTIP "Fechar Janela"

   ACTIVATE DIALOG oFRMbuscarel

RETURN

*******************
Function CNPJ(FCGC)
*******************
T :=  TT :=  TTT :=  0
CCNPJ = SPACE(18)

PARTEA1 = SUBS(FCGC,1,2)  //   Divide a
PARTEA2 = SUBS(FCGC,3,3)  //   variavel
PARTEA3 = SUBS(FCGC,6,3)  //     em 5
PARTEA4 = SUBS(FCGC,9,4) //    partes
PARTEA5 = SUBS(FCGC,13,2) //    partes

CCNPJ = PARTEa1+PARTEa2+PARTEa3+PARTEa4 // Junta as 4 partes

FOR TT =  12 TO 5 STEP -1                         //
        T = T + VAL(SUBS(CCNPJ,TT,1)) * (14 - TT)  //
NEXT TT                                           //
FOR TT =  4 TO 1 STEP -1                          //
        T = T + VAL(SUBS(CCNPJ,TT,1)) * (6 - TT)   //   Processa
NEXT TT                                           //  os calculos
TT :=  T - (INT(T/11)*11)                         //     para
IF TT < 2                                         //   verificar
        TT :=  0                                  //   o primeiro
ELSE                                              //    digito
        TT :=  11 - TT                            //
ENDIF                                             //
CCNPJ =  CCNPJ + STR(TT,1) // Junta o primeiro digito com as 4 primeiras partes

T= 0 // Zera a variavel para inicio do novo calculo
FOR TT =  13 TO 6 STEP -1                         //
        T = T + VAL(SUBS(CCNPJ,TT,1)) * (15 - TT)  //
NEXT TT                                           //
FOR TT =  5 TO 1 STEP -1                          //
        T = T + VAL(SUBS(CCNPJ,TT,1)) * (7 - TT)   //    Processa
NEXT TT                                           //    o calculo
TT :=  T - (INT(T/11)*11)                         //  para verificar
IF TT < 2                                         //    o segundo
        TT :=  0                                  //     digito
ELSE                                              //
        TT :=  11 - TT                            //
ENDIF                                             //
CCNPJ =  CCNPJ + STR(TT,1) // Junta o segundo digito ao restante inicial

PARTE1 = SUBS(CCNPJ,1,2)  //
PARTE2 = SUBS(CCNPJ,3,3)  //  Divide novamente
PARTE3 = SUBS(CCNPJ,6,3)  //     a variavel
PARTE4 = SUBS(CCNPJ,9,4)  //  agora em 5 partes
PARTE5 = SUBS(CCNPJ,13,2) //
CCNPJ = PARTE1+PARTE2+PARTE3+PARTE4+PARTE5               // Monta a variavel conforme um CCNPJ verdadeiro
IF CCNPJ != PARTEa1+PARTEa2+PARTEa3+PARTEa4+PARTEa5
   MsgINFO("O Nº do CNPJ Informado esta errado !!!, Favor Colocar um Numero Valido","Validador do CNPJ")
   RETURN .F.
ENDIF
RETURN .T.

******************
Function CPF(FCPF)
******************
T :=  TT :=  TTT :=  0
CCPF :=  SPACE(11)

PARTEA1 = SUBS(FCPF,1,3)  //    Divide a variavel
PARTEA2 = SUBS(FCPF,4,3)  //          em 3
PARTEA3 = SUBS(FCPF,7,3)  //         Partes
PARTEA4 = SUBS(FCPF,10,2)  //        Partes
CCPF = PARTEA1+PARTEA2+PARTEA3 // Junta as 3 partes

FOR TT =  1 TO 9                                //
    T = T + VAL(SUBS(CCPF,TT,1)) * (11 - TT) //
NEXT TT                                         //
TT :=  T - (INT(T/11)*11)                       //  Processa os calculos
IF TT < 2                                       //     para verificar
   TT :=  0                                //    o primeiro digito
ELSE                                            //
   TT :=  11 - TT                          //
ENDIF                                           //
CCPF =  CCPF + STR(TT,1) // Junta o primeiro digito com as 3 primeiras partes

T= 0 // Zera a variavel para inicio do novo calculo
FOR TT =  2 TO 9                                //
        T = T + VAL(SUBS(CCPF,TT,1)) * (12 - TT) //
NEXT TT                                         //
T = T + VAL(SUBS(CCPF,10,1)) * 2                 //
TT :=  T - (INT(T/11)*11)                       //  Processa os calculos
IF TT < 2                                       //     para verificar
        TT :=  0                                //    o segundo digito
ELSE                                            //
        TT :=  11 - TT                          //
ENDIF                                           //
CCPF =  CCPF + STR(TT,1) // Junta o segundo digito ao restante inicial

PARTE1 = SUBS(CCPF,1,3)  //
PARTE2 = SUBS(CCPF,4,3)  // Divide novamente a variavel
PARTE3 = SUBS(CCPF,7,3)  //    agora em 4 partes
PARTE4 = SUBS(CCPF,10,2) //
CCPF = PARTE1+PARTE2+PARTE3+PARTE4         // Monta a variavel conforme um CCPF verdadeiro
IF CCPF !=PARTEA1+PARTEA2+PARTEA3+PARTEA4
   MsgINFO("O Nº do CPF Informado esta errado !!!, Favor Informar um Numero Valido","Validador de CPF")
   RETURN .F.
ENDIF
RETURN .T.

Function GERAFILE
Public cFILE := GETENV("temp")+ "\sy_temp\TEMP"+ ALLTRIM( STR( HB_RandomInt(99999) ))
RETURN cFILE

******************
Function LIMPATEMP
******************
FClose()
vTEMP_L:= GETENV("temp") + "\sy_temp"  // pasta temporaria do windows
aDir := Directory(vTEMP_L+"\*.*")
FOR I = 1 TO LEN(aDir)
   if aDir[I,5] = "RA"  // atributo como somente leitura
      SetFAttr( vTEMP_L+"\"+aDir[I,1], "32" )
   endif
   ferase( vTEMP_L+"\"+aDir[I,1] )
NEXT
RETURN

********************************************************************************
***************INCIO DA FUNCAO DE ABRIR ARQUIVOS********************************
********************************************************************************
FUNCTION Abre_arquivo( cHelpFile )
   LOCAL nRet, cPath, cFileName, cFileExt
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
********************************************************************************
***************FIM DA FUNCAO DE ABRIR ARQUIVOS**********************************
********************************************************************************

******************
FUNCTION NoSaidaF4
******************
if getkeystate(VK_F4,.F.,.T.) < 0
   RETURN .F.
ENDIF
RETURN .T.

**************
FUNCTION Aviso
**************
Local oDlg_manuten
Local oGroup1, oBitmap1, oLabel2, oLabel1, oLabel3, oLine1, oLink1 , oButtonex1

  INIT DIALOG oDlg_manuten TITLE "Modulo em Desenvolvimento" ;
  ICON HIcon():AddResource(1004)  ;
  AT 370,175 SIZE 321,488 ;
  FONT HFont():Add( '',0,-13,400,,,) CLIPPER  NOEXIT  ;
  STYLE WS_POPUP+WS_CAPTION+DS_CENTER +WS_SYSMENU+WS_MINIMIZEBOX

  Thisform := oDlg_manuten

   @ 9,395 LINE oLine1 LENGTH 303
        oLine1:Name := 'oLine1'
   @ 31,29 BITMAP oBitmap1  ;
        SHOW 1015 FROM RESOURCE  ;
        OF oGroup1  TRANSPARENT SIZE 256,256
        oBitmap1:Name := 'oBitmap1'
   @ 16,6 GROUPBOX oGroup1 CAPTION "Modulo em Desenvolvimento"  SIZE 288,297  ;
         COLOR 16711680
        oGroup1:Name := 'oGroup1'
   @ 30,339 SAY oLabel1 CAPTION "Esse Modulo esta em Desenvolvimento"  SIZE 261,20  ;
         COLOR 16711680   ;
        FONT HFont():Add( '',0,-15,400,,,)
        oLabel1:Name := 'oLabel1'
        oLabel1:AutoSize := .T.
   @ 116,309 SAY oLabel2 CAPTION "Atenção:"  SIZE 88,27  ;
         COLOR 255   ;
        FONT HFont():Add( '',0,-19,700,,,)
        oLabel2:Name := 'oLabel2'
        oLabel2:AutoSize := .T.
   @ 5,363 SAY oLabel3 CAPTION "em Breve vai esta Liberado. Por Favor Aguarde"  SIZE 311,20  ;
         COLOR 16711680   ;
        FONT HFont():Add( '',0,-15,400,,,)
        oLabel3:Name := 'oLabel3'
        oLabel3:AutoSize := .T.

   @ 104,447 BUTTONEX oButtonex1 CAPTION "&Fechar"  SIZE 98,38 ;
        STYLE WS_TABSTOP   ;
        BITMAP (HBitmap():AddResource(1005)):handle  ;
        BSTYLE 0;
        TOOLTIP 'Clique aqui para Fechar' ;
        ON CLICK {|| oDlg_manuten:close() }
        oButtonex1:Name := 'oButtonex1'

   @ 24,408 SAY oLink1 CAPTION "Clique aqui para Acompanhar Novas Funçoes"  ;
        LINK 'http://www.sygecom.com.br/forum/'  SIZE 273,22   ;
        TOOLTIP 'Clique aqui para visitar o Forum da Sygecom e acompanhar as novas funções.'
        oLink1:Name := 'oLink1'

 ACTIVATE DIALOG oDlg_manuten NOMODAL

Return Nil

********************************************************************************
***********VEREFICA O NOME DO EXECUTAVEL E O CAMINHO DO MESMO*******************
*NomeExecutavel()    // verefica o nome
*NomeExecutavel(.t.) // verefica o caminho
********************************************************************************
Function NomeExecutavel(lPath)
LOCAL nPos, cRet
If Empty(lpath)
   nPos:= RAT("\", hb_argv(0))
   cRet:= substr(hb_argv(0), nPos+1)
else
   cRet:= hb_argv(0)
endif
Return cRet
********************************************************************************
***********FIM DA ROTINA DE VEREFICAÇÃO DE EXECUTAL*****************************
********************************************************************************

****************************
Function Data_Hora_ARQ(vArq)
****************************
SET CENTURY ON
SET DATE BRITISH
SET EPOCH TO 2000

aDir  := Directory( vArq )
aRet  := Transform(DtoC(aDir[1,3]),"@d")
aRet2 := aDir[1,4]
Return( aRet + " - " + aRet2 )

Function GETFILEVERSIONINFO
Return(eVERSAO)

*********************
Function Focaliza_App
*********************
oWnd := SY_FindWindow("SCM - SISTEMA DE CONTROLE DE MENSALIDADES Vs. " + GETFILEVERSIONINFO())
SY_SwitchToThisWindow(oWnd,.f.)
SY_showWindow( oWnd, 3 )
Return Nil

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


*************************************
Function _newalert(cmensagem,ctitulo)
*************************************
PRIVATE oAlert, oEdtMensagem

INIT DIALOG oAlert  TITLE ctitulo ;
AT 0,0 SIZE 400,100 ;
STYLE DS_CENTER+WS_CAPTION+WS_POPUP ;
ON GETFOCUS {||mensagem(cMensagem),oAlert:close()};
ON INIT     {|O| FormInit(oAlert)};
COLOR RGB(255,255,255)

ACTIVATE DIALOG oAlert NOMODAL

oAlert:close()

Focaliza_App()

RETURN Nil
**************************
STATIC FUNCTION visualizar
**************************
PARA nAcao
LOCAL nInicio, nFim, nStep, nLoop1
nInicio := IIF(nAcao = 1, 10,255)
nFim    := IIF(nAcao = 1, 255,0)
nStep   := IIF(nAcao = 1, 10,-10)
FOR nloop1 = nInicio TO nFim STEP nStep
    MilliSec(50)
    SetLayeredWindowAttributes(oAlert:handle, nloop1) //0,nloop1, 2)
NEXT
RETURN Nil

************************
STATIC FUNCTION mensagem
************************
PARA cmensagem
oAlert:show() //thisform.Visible=.t.
SetLayeredWindowAttributes(oAlert:handle, 10) //0, 10, 2)

@ 5,30 SAY oEdtMensagem CAPTION cmensagem SIZE oalert:nwidth,oalert:nheight;
      BACKCOLOR Rgb(255, 255, 255);
      FONT HFont():Add( 'Verdana',0,-18,400,,,)  ;
      COLOR RGB(32,32,32)    ;
      STYLE ES_CENTER
  visualizar(1)
  MilliSec(50)
  visualizar(0)
  SetLayeredWindowAttributes(oAlert:handle, 0) //, 0, 2)
  oAlert:hide()
RETURN NIL

STATIC FUNCTION FormInit
#define WS_EX_LAYERED  524288
private oldstyle,newstyle
oAlert:hide()
oldstyle = HWG_GetWindowexSTYLE(oAlert:hANDLE)
NEWSTYLE = Hwg_BitOR( OLDstyle,WS_EX_LAYERED+WS_EX_TRANSPARENT)
HWG_SETWINDOWEXSTYLE(oAlert:hANDLE, NEWstyle)
moveWINDOW(oalert:handle,,)
SetLayeredWindowAttributes(oAlert:handle, 0) //, 0, 2)
SETTOPMOST(oAlert:Handle)
RETURN NIL

STATIC Function SetLayeredWindowAttributes
parameters hwnd,ntransp
Private nResult
#define LWA_COLORKEY 0x1
#define LWA_ALPHA 0x2

nResult := DllCall("user32.dll" ,  DC_CALL_STD , "SetLayeredWindowAttributes" , hwnd,0 , ntransp,LWA_ALPHA )
RETURN NIL

***************************
Function LESENHA(vCONF,vP2)
***************************
Private vMSG := "Senha de Manutenção"
vSEN=vCONF

Private vVALIDA := .F.
Private wSENHA:=""
Private oSENHA
Private oAUTORIZA

INIT DIALOG oFrm2 CLIPPER NOEXIT NOEXITESC TITLE vMSG;
AT 0,0 SIZE 220,120;
ICON HIcon():AddResource(1004) ;
ON EXIT {|| NoSaidaF4( ) };
STYLE DS_CENTER + WS_CAPTION

SetColorinFocus(.t.)
SetToolTipBalloon(.t.)

@ 10,10 SAY vMSG size 320,25

@ 5,30 GET oSENHA VAR wSENHA PICTURE Replicate("!",len(alltrim(vSEN))) SIZE 210,25 PASSWORD;
STYLE WS_TABSTOP;
TOOLTIP vMSG

@ 5,70 BUTTONEX btnOk CAPTION "&Entrar" SIZE 100,38;
TOOLTIP "Clique aqui para entrar";
BITMAP (HBitmap():AddResource(1006)):handle  ;
ON CLICK {|| oFrm2:Close() };
STYLE WS_TABSTOP

@ 110,70 BUTTONEX btnCancel CAPTION "&Cancela" SIZE 100,38;
TOOLTIP "Clique aqui Sair do Sistema";
BITMAP (HBitmap():AddResource(1005)):handle  ;
ON CLICK {|| wSENHA:="",oFrm2:Close() };
STYLE WS_TABSTOP

ACTIVATE DIALOG oFrm2

Return(IIF(ALLTRIM(UPPER(wSENHA))=ALLTRIM(UPPER(vSEN)),.T.,.F.))



