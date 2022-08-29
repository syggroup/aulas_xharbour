#include "scm.ch"

**************************
FUNCTION Dados_Instituicao
**************************
PRIVATE oCadInst
PRIVATE oFont, grpConfiguracao
PRIVATE oIcon := HIcon():AddResource(1004)
**********variaveis***********************
PRIVATE LBLnome, Wnome := "", Onome
PRIVATE LBLend, Wend := "", Oend
PRIVATE LBLbairro, Wbairro := "", Obairro
PRIVATE LBLcidade, Wcidade := "", Ocidade
PRIVATE LBLuf, CBOuf, Wuf :="",aItens1 := {"AC","AL","AP","AM","BA","CE","DF","GO","ES","MA","MT","MS","MG","PA","PB","PR","PE","PI","RJ","RN","RS","RO","RR","SP","SC","SE","TO"}
PRIVATE LBLcep, Wcep := "", Ocep
PRIVATE LBLcnpj, Wcnpj := "", Ocnpj
PRIVATE LBLie, Wie := "", Oie
PRIVATE LBLfone, Wfone := "", Ofone
PRIVATE LBLfax, Wfax := "", Ofax
PRIVATE LBLcel, Wcel := "", Ocel
PRIVATE LBLemail, Wemail := "", Oemail
PRIVATE LBLsite, Wsite  := "", Osite
PRIVATE LBLbc, Wbc  := "", Obc
PRIVATE LBLag, Wag  := "", Oag
PRIVATE LBLcc, Wcc  := "", Occ
PRIVATE LBLusuario, wUSUARIO, oUSUARIO
PRIVATE LBLusuario, wUSUARIO, oUSUARIO
PRIVATE LBLserver,  wSERVER,  oSENHA
**********variaveis***********************
DBCLOSEALL()

IF Use_Arq("INSTITUI",,.T.,.F.,.F.)=.F.
   Return
ENDIF

SELE INSTITUI
dbgotop()
Wnome     = NOME
Wend      = ENDE
Wbairro   = BAIRRO
Wcidade   = CIDADE
Wuf       = UF
Wcep      = CEP
Wcnpj     = CNPJ
Wie       = IE
Wfone     = TEL
Wfax      = FAX
Wcel      = CEL
Wemail    = EMAIL
Wsite     = SITE
Wbc       = BANCO
Wag       = AGENCIA
Wcc       = CONTA
wUSUARIO  = USUARIO
wSERVER   = SERVER
wSENHA    = SENHA

INIT DIALOG oCadInst CLIPPER NOEXIT TITLE "Dados da Instituição";
FONT HFont():Add( '',0,-13,400,,,);
AT 0,0 SIZE 670,470;
ICON oIcon ;
STYLE DS_CENTER + WS_VISIBLE + WS_CAPTION + WS_SYSMENU 

SetColorinFocus( .t. )

@ 5,5  GROUPBOX grpConfiguracao             CAPTION "Dados da Instituição"      SIZE 655,385
*******SAYS*******
@ 20 ,40   SAY LBLnome                       CAPTION "Nome:"                     SIZE 168,22
@ 20 ,70   SAY LBLend                        CAPTION "Endereço:"                 SIZE 168,22
@ 400,70   SAY LBLbairro                     CAPTION "Bairro:"                   SIZE 168,22
@ 20 ,100  SAY LBLcidade                     CAPTION "Cidade:"                   SIZE 168,22
@ 300,100  SAY LBLuf                         CAPTION "UF:"                       SIZE 168,22
@ 400,100  SAY LBLcep                        CAPTION "CEP:"                      SIZE 168,22
@ 20 ,130  SAY LBLcnpj                       CAPTION "CNPJ:"                     SIZE 168,22
@ 220,130  SAY LBLie                         CAPTION "IE.:"                      SIZE 168,22
@ 20 ,160  SAY LBLfone                       CAPTION "Fone:"                     SIZE 168,22
@ 220,160  SAY LBLfax                        CAPTION "Fax:"                      SIZE 168,22
@ 390,160  SAY LBLcel                        CAPTION "Celular:"                  SIZE 168,22
@ 20 ,190  SAY LBLemail                      CAPTION "Email:"                    SIZE 168,22
@ 20 ,220  SAY LBLusuario                    CAPTION "Usuario:"                  SIZE 168,22
@ 20 ,250  SAY LBLserver                     CAPTION "Servidor"                  SIZE 168,22
@ 20 ,280  SAY LBLsenha                      CAPTION "Senha..:"                  SIZE 168,22
@ 20 ,310  SAY LBLsite                       CAPTION "Web-Site:"                 SIZE 168,22
@ 20 ,340  SAY LBLbc                         CAPTION "Banco:"                    SIZE 168,22
@ 240,340  SAY LBLag                         CAPTION "Agencia:"                  SIZE 168,22
@ 460,340  SAY LBLcc                         CAPTION "C/C.:"                     SIZE 168,22
*******SAYS*******

*******GETS*******
@ 80,40    GET Onome VAR Wnome                                        SIZE 560,22;
MAXLENGTH 50;
STYLE WS_TABSTOP;
TOOLTIP "Informe o Nome da Instituição"

@ 80,70    GET Oend VAR Wend                                          SIZE 300,22;
MAXLENGTH 50;
STYLE WS_TABSTOP;
TOOLTIP "Informe o Endereço da Instituição"

@ 440,70   GET Obairro VAR Wbairro                                    SIZE 200,22;
MAXLENGTH 20;
STYLE WS_TABSTOP;
TOOLTIP "Informe o Bairro da Instituição"

@ 80,100   GET Ocidade VAR Wcidade                                    SIZE 200,22;
MAXLENGTH 20;
STYLE WS_TABSTOP;
TOOLTIP "Informe a Cidade da Instituição"

@ 330,100  GET COMBOBOX CBOuf VAR Wuf      ITEMS aItens1                        SIZE 50,22 TEXT;
STYLE WS_TABSTOP;
TOOLTIP "Informe a Unidade Federativa da Instituição"

@ 440,100  GET Ocep VAR Wcep               PICTURE "@R 99999-999"               SIZE 130,22;
STYLE WS_TABSTOP;
TOOLTIP "Informe o CEP"

@ 80,130   GET Ocnpj VAR Wcnpj             PICTURE "@R 99.999.999/9999-99"      SIZE 130,22;
STYLE WS_TABSTOP;
TOOLTIP "Informe o CNPJ"

@ 250,130  GET Oie  VAR Wie                PICTURE "@R 99999999999999999"       SIZE 130,22;
STYLE WS_TABSTOP;
TOOLTIP "Informe a Inscrção Estadual"

@ 80,160   GET Ofone VAR Wfone             PICTURE "@R (99)9999-9999"           SIZE 130,22;
STYLE WS_TABSTOP;
TOOLTIP "Informe o Telefone"

@ 250,160  GET Ofax VAR Wfax               PICTURE "@R (99)9999-9999"           SIZE 130,22;
STYLE WS_TABSTOP;
TOOLTIP "Informe o Telefone de Fax"

@ 440,160  GET Ocel VAR Wcel               PICTURE "@R (99)9999-9999"           SIZE 130,22;
STYLE WS_TABSTOP;
TOOLTIP "Informe o Telefone de Celular"

@ 80,190   GET Oemail VAR Wemail                                    SIZE 560,22;
MAXLENGTH 60;
STYLE WS_TABSTOP;
TOOLTIP "Informe o Emial"

@ 80,220   GET Ousuario VAR Wusuario                                SIZE 560,22;
MAXLENGTH 60;
STYLE WS_TABSTOP;
TOOLTIP "Informe o Usuario usado para Envio de email"

@ 80,250   GET Oserver  VAR Wserver                                   SIZE 560,22;
MAXLENGTH 60;
STYLE WS_TABSTOP;
TOOLTIP "Informe o Servidor SMTP para envio de Emails"

@ 80,280   GET Osenha   VAR Wsenha                     SIZE 560,22 PASSWORD;
Style WS_TABSTOP;
TOOLTIP "Informe a Senha Especial"

@ 80 ,310  GET Osite VAR Wsite                                        SIZE 560,22;
MAXLENGTH 60;
STYLE WS_TABSTOP;
TOOLTIP "Informe o Endereço do Web Site"

@ 80 ,340  GET Obc VAR Wbc                                            SIZE 150,22;
MAXLENGTH 20;
STYLE WS_TABSTOP;
TOOLTIP "Informe o Nome do Banco"

@ 290,340  GET Oag VAR Wag                                           SIZE 150,22;
MAXLENGTH 10;
STYLE WS_TABSTOP;
TOOLTIP "Informe o Numero da Agencia"

@ 490,340  GET Occ VAR Wcc                 PICTURE "" VALID {||Focaliza()}      SIZE 150,22;
MAXLENGTH 10;
STYLE WS_TABSTOP;
TOOLTIP "Informe o Numero da Conta Corrente"

*******GETS*******

*******Buttons****
@ 320,410 BUTTON btnOk CAPTION "&Salvar" SIZE 100, 28 ;
TOOLTIP "Salvar Registro";
ON CLICK {|| Grava_inst() };
STYLE WS_TABSTOP

@ 430,410  BUTTON "&Limpar" SIZE 100, 28 ;
TOOLTIP "Limpar Campos";
ON CLICK {|| limpa_Var() };
STYLE WS_TABSTOP

@ 540,410  BUTTON "&Fechar" SIZE 100, 28 ;
TOOLTIP "Sair do Modulo de Cadastro";
ON CLICK {|| oCadInst:Close() };
STYLE WS_TABSTOP
*******Buttons****

ACTIVATE DIALOG oCadInst

DBCLOSEALL()
RETURN nil

Function Focaliza()
btnOk:setfocus()
Return .T.

*********************
FUNCTION Grava_Inst()
*********************
IF EMPTY(Wnome)
   OBRIGA()
   oNome:setfocus()
   RETURN
ENDIF

IF EMPTY(wuf)
   OBRIGA()
   CBOuf:setfocus()
   RETURN
ENDIF

SELECT INSTITUI
dbgotop()
IF lastrec() =0
   DBAPPEND()
else
   TRAVAREG()
ENDIF
REPLACE  NOME  WITH Wnome,;
ENDE         WITH Wend,;
BAIRRO       WITH Wbairro,;
CIDADE       WITH Wcidade,;
UF           WITH Wuf,;
CEP          WITH Wcep,;
CNPJ         WITH Wcnpj,;
IE           WITH Wie,;
TEL          WITH Wfone,;
FAX          WITH Wfax,;
CEL          WITH Wcel,;
EMAIL        WITH Wemail,;
SITE         WITH WSITE,;
BANCO        WITH Wbc,;
AGENCIA      WITH Wag,;
CONTA        WITH Wcc,;
USUARIO      WITH wUSUARIO,;
SERVER       WITH wSERVER,;
SENHA        WITH wSENHA
DBCOMMIT()
DBUNLOCK()
oCadInst:Close()
RETURN

********************
FUNCTION Limpa_var()
********************
Wnome := ""
Wend := ""
Wbairro := ""
Wcidade := ""
Wuf := ""
Wcep := ""
Wcnpj := ""
Wie := ""
Wfone := ""
Wfax := ""
Wcel := ""
Wemail := ""
Wsite  := ""
Wbc:= ""
Wag:= ""
Wcc:= ""

oNome:Refresh()
Oend:Refresh()
Obairro:Refresh()
Ocidade:Refresh()
CBOuf:Refresh()
Ocep:Refresh()
Ocnpj:Refresh()
Ofone:Refresh()
Ofax:Refresh()
Ocel:Refresh()
Oemail:Refresh()
Osite:Refresh()
Oie:Refresh()
Obc:Refresh()
Oag:Refresh()
Occ:Refresh()
oNome:SetFocus()
Return

**********************
FUNCTION Cad_Associado
**********************
PRIVATE oCadAss
PRIVATE oFont
PRIVATE oIcon := HIcon():AddResource(1004)
*************VARIAVEIS********************
PRIVATE LBLnome, Wnome := "", Onome
PRIVATE LBLend, Wend := "", Oend
PRIVATE LBLbairro, Wbairro := "", Obairro
PRIVATE LBLcidade, Wcidade := "", Ocidade
PRIVATE LBLuf, CBOuf, Wuf := "",aItens:= {"AC","AL","AP","AM","BA","CE","DF","GO","ES","MA","MT","MS","MG","PA","PB","PR","PE","PI","RJ","RN","RS","RO","RR","SP","SC","SE","TO"}
PRIVATE LBLCBnome, CBOnome, WCBnome := "",aItensCBnome := {}
PRIVATE LBLcep, Wcep := "", Ocep
PRIVATE LBLfone, Wfone := "", Ofone
PRIVATE LBLfax, Wfax := "", Ofax
PRIVATE LBLcel, Wcel := "", Ocel
PRIVATE LBLemail, Wemail := "", Omail
PRIVATE wInicio :=.T., wNovo := .F.
PRIVATE LBLcodigo, Wcodigo := "", Ocodigo, LBLmostcodigo   
PRIVATE LBLfunc1, Wfunc1 := "", Ofunc1,aItens1:= {}
PRIVATE LBLfunc2, Wfunc2 := "", Ofunc2,aItens2:= {}
PRIVATE LBLvalor, Wvalor := 0 , Ovalor
PRIVATE LBLvenc, Wvenc := date(), Ovenc
PRIVATE LTIPOJF, WTIPOJF := space(1), OTIPOJF, oRadio1,oRadio2,r1 := 1
PRIVATE LCNPJ_CPF  , LRG_IE     , cPicture
PRIVATE oCNPJ_CPF  , oRG_IE     , oObj1      , oObj2
PRIVATE wCNPJ_CPF   := Space(18)
PRIVATE wCNPJ       := Space(18)
PRIVATE wCPF        := Space(14)
PRIVATE wRG_IE      := Space(14)
PRIVATE wRG         := Space(14)
PRIVATE wIE         := Space(14)

*************VARIAVEIS********************
PARA TIPOCAD,Abre_Dbf

IF TIPOCAD="C"
   IF Abre_Dbf="S"
      Dbcloseall()
      IF Use_Arq("ASSOCI",,.T.,.F.,.F.)=.F.
         Return
      ENDIF

      IF Use_Arq("FUNCAO",,.T.,.F.,.F.)=.F.
         Return
      ENDIF
   ENDIF
ENDIF

SELE FUNCAO
DBGOTOP()
do while !eof()
   vFUNC=FUNCAO
   aadd(aItens1,vFUNC)
   aadd(aItens2,vFUNC)
   dbskip()
Enddo

IF TIPOCAD="C"
   SELE ASSOCI
   DBSETORDER(1)
   DbGoBottom()
   Wcodigo=CODASSOC+1
ELSE
   SELE ASSOCI
   wCodigo = CODASSOC
   DBSETORDER(1)
   DBSEEK(wCodigo)
   IF FOUND()
      IF TRAVAREG()=.F.
         RETURN
      ENDIF
      WCodigo   = CODASSOC
      Wnome     = NOME
      Wend      = ENDE
      Wbairro   = BAIRRO
      Wcidade   = CIDADE
      Wuf       = UF
      Wcep      = CEP
      wTIPOJF   = TIPOJF
      Wcpf      = CPF
      wRG       = RG
      wCNPJ     = CNPJ
      wIE       = IE
      Wfone     = TEL
      Wfax      = FAX
      Wcel      = CEL
      Wemail    = EMAIL
      Wfunc1    = FUNCAO1
      Wfunc2    = FUNCAO2
      Wvalor    = VALOR
      Wvenc     = VENC
   ELSE
      Erroreg()
      RETURN nil
   ENDIF
   IF wTIPOJF="F"
      r1 := 1
      wCNPJ_CPF=wCPF
      wRG_IE=wRG
   else
      r1 := 2
      wCNPJ_CPF=wCNPJ
      wRG_IE=wIE
   endif
ENDIF

PREPARE FONT oFont NAME "Arial" WIDTH 0 HEIGHT -12 WEIGHT 400
INIT DIALOG oCadAss CLIPPER NOEXIT TITLE "Cadastro de Associados";
AT 0,0 SIZE 670,410;
ICON  oIcon ;
FONT oFont ;   
STYLE DS_CENTER + WS_VISIBLE + WS_CAPTION + WS_SYSMENU;
ON INIT  {||iif(r1=1,Muda_texto(oCNPJ_CPF , "CPF :", oRG_IE , "RG :" ),Muda_texto(oCNPJ_CPF , "CNPJ :", oRG_IE , "INSC :")),.T.}

SetColorinFocus( .t. )
                                                                            
@ 5,5  GROUPBOX grpConfiguracao             CAPTION "Dados do Associado"      SIZE 655,335

****INICO DOS SAYS***
@ 20 ,40   SAY LBLcodigo                     CAPTION "Codigo:"                 SIZE 168,22
@ 20 ,70   SAY LBLnome                       CAPTION "Nome:"                   SIZE 168,22
@ 20 ,100  SAY LBLend                        CAPTION "Endereço:"               SIZE 168,22
@ 400,100  SAY LBLbairro                     CAPTION "Bairro:"                 SIZE 168,22
@ 20 ,130  SAY LBLcidade                     CAPTION "Cidade:"                 SIZE 168,22
@ 300,130  SAY LBLuf                         CAPTION "UF:"                     SIZE 168,22
@ 400,130  SAY LBLcep                        CAPTION "CEP:"                    SIZE 168,22
@ 20 ,160  SAY LCNPJ_CPF                     CAPTION "CPF:"                    SIZE 50 ,22
@ 300,160  SAY LRG_IE                        CAPTION "RG:"                     SIZE 40 ,22
@ 10 ,190  SAY LBLfunc1                      CAPTION "Função 01:"              SIZE 168,22
@ 300,190  SAY LBLfunc2                      CAPTION "Função 02:"              SIZE 168,22
@ 20 ,220  SAY LBLfone                       CAPTION "Fone:"                   SIZE 168,22
@ 210,220  SAY LBLfax                        CAPTION "Fax:"                    SIZE 168,22
@ 390,220  SAY LBLcel                        CAPTION "Celular:"                SIZE 168,22
@ 20 ,250  SAY LBLemail                      CAPTION "Email:"                  SIZE 168,22
@ 20 ,280  SAY LBLvalor                      CAPTION "Valor Mensalidade R$:"   SIZE 168,22
@ 270,280  SAY LBLvenc                       CAPTION "Data de Vencimento:"     SIZE 168,22
****FIM DOS SAYS***

****INCIO DOS GTES***
GET RADIOGROUP r1
@ 150,40 RADIOBUTTON oRadio1 caption "Pessoa Fisica";
SIZE 120, 22;
TOOLTIP "Escolha essa Opção para Pessoa Fisica";
ON CLICK {||Muda_texto(oCNPJ_CPF , "CPF :", oRG_IE , "RG :")}

@ 280,40 RADIOBUTTON oRadio2 caption "Pessoa Jurídica" ;
SIZE 120, 22;
TOOLTIP "Escolha essa Opção para Pessoa Juridica";
ON CLICK {||Muda_texto(oCNPJ_CPF , "CNPJ :", oRG_IE , "INSC :")}
END RADIOGROUP

@ 80,40   GET Ocodigo VAR Wcodigo           PICTURE "999999"  COLOR 255        SIZE 50,22 STYLE WS_DISABLED;
TOOLTIP "Informe o Codigo"

@ 80,70   GET Onome VAR Wnome                                           SIZE 560,22;
MAXLENGTH 50;
STYLE WS_TABSTOP;
TOOLTIP "Informe o Nome do Associado"

@ 80,100  GET Oend VAR Wend                                         SIZE 300,22;
MAXLENGTH 50;
STYLE WS_TABSTOP + ES_AUTOHSCROLL;
TOOLTIP "Informe o Endereço do Associado"

@ 440,100 GET Obairro VAR Wbairro                                  SIZE 200,22;
MAXLENGTH 20;
STYLE WS_TABSTOP + ES_AUTOHSCROLL;
TOOLTIP "Informe o Bairro"

@ 80,130  GET Ocidade VAR Wcidade                                SIZE 200,22;
MAXLENGTH 20;
STYLE WS_TABSTOP + ES_AUTOHSCROLL;
TOOLTIP "Informe a Cidade"

@ 330,130 GET COMBOBOX CBOuf VAR Wuf     ITEMS aItens                      SIZE 50,22 TEXT;
STYLE WS_TABSTOP;
TOOLTIP "Informe a Unidade Federativa"

@ 440,130 GET Ocep VAR Wcep                 PICTURE "@R 99999-999"            SIZE 120,22;
STYLE WS_TABSTOP;
TOOLTIP "Informe o CEP"

@ 80,160  GET oCNPJ_CPF    VAR wCNPJ_CPF      PICTURE cPicture                         SIZE 150,22;
STYLE WS_TABSTOP;
MAXLENGTH 18;
TOOLTIP "Informe o Cpf ou Cnpj"

@ 343,160   GET oRG_IE      VAR wRG_IE                                                SIZE 120,22;
STYLE WS_TABSTOP;
MAXLENGTH 15;
TOOLTIP "Informe o RG ou Inscrição Estadual"

@ 80,190 GET COMBOBOX Ofunc1 VAR Wfunc1 ITEMS aItens1                     SIZE 200,22 TEXT;
STYLE WS_TABSTOP;
TOOLTIP "Informe a Primeira Função"

@ 390,190 GET COMBOBOX Ofunc2 VAR Wfunc2 ITEMS aItens1                     SIZE 200,22 TEXT;
STYLE WS_TABSTOP;
TOOLTIP "Informe a Segunda Função"

@ 80,220  GET Ofone  VAR Wfone              PICTURE "@R (99)9999-9999"        SIZE 120,22;
STYLE WS_TABSTOP;
TOOLTIP "Informe o Telefone"

@ 250,220 GET Ofax   VAR Wfax               PICTURE "@R (99)9999-9999"        SIZE 120,22;
STYLE WS_TABSTOP;
TOOLTIP "Informe o Telefone de Fax"

@ 440,220 GET Ocel   VAR Wcel               PICTURE "@R (99)9999-9999"        SIZE 120,22;
STYLE WS_TABSTOP;
TOOLTIP "Informe o Telefone Celular"

@ 80,250  GET Oemail VAR Wemail                                    SIZE 560,22;
MAXLENGTH 50;
STYLE WS_TABSTOP + ES_AUTOHSCROLL;
TOOLTIP "Informe o Email"

@ 150,280 GET Ovalor VAR Wvalor             PICTURE "@E 999,999,999.99"       SIZE 100,22;
STYLE WS_TABSTOP;
TOOLTIP "Informe o Valor da Mensalidade"

@ 390,280 GET DATEPICKER Ovenc  VAR Wvenc  SIZE 100,22;
STYLE WS_TABSTOP;
TOOLTIP "Informe a Data de Vencimento"
****FIM DOS GTES***

*******Buttons****
@ 320,350  BUTTON btnOk CAPTION "&Salvar" SIZE 100, 28 ;
TOOLTIP "Salvar Registro";
ON CLICK {|| Grava_Assoc() };
STYLE WS_TABSTOP

@ 430,350  BUTTON "&Limpar" SIZE 100, 28 ;
TOOLTIP "Limpar Campos";
ON CLICK {|| limpa_Var2() };
STYLE WS_TABSTOP  

@ 540,350  BUTTON "&Fechar" SIZE 100, 28 ;
TOOLTIP "Sair do Modulo de Cadastro";
ON CLICK {|| oCadAss:Close() };
STYLE WS_TABSTOP

WriteStatus( oTelaPrincipal,3,"Cadastro de Assiados" )//BARRA DE STATUS
ACTIVATE DIALOG oCadAss
WriteStatus( oTelaPrincipal,3,"Area de Trabalho" )
     
RETURN nil
****************************************************
Function Muda_texto(oObj1, cTexto1, oObj2, cTexto2 )
****************************************************
LCNPJ_CPF:settext(hb_oemtoansi(cTexto1))
LRG_IE   :settext(hb_oemtoansi(cTexto2))

if cTexto1 = "CNPJ"
   cPicture ="@R 99.999.999/9999-99"
else
   cPicture ="@R 999.999.999-99"
endif
oObj1:ParsePict(cPicture,oObj1:title)
oobj1:refresh()
Return .T.

********************
FUNCTION Grava_assoc
********************
IF EMPTY(Wnome)
   OBRIGA()
   oNome:setfocus()
   RETURN
ENDIF

IF EMPTY(wuf)
   OBRIGA()
   CBOuf:setfocus()
   RETURN
Endif

IF STR(r1,1)="1"
   wTIPOJF="F"
else
   wTIPOJF="J"
Endif

IF wTIPOJF="J"
   FCGC=wCNPJ_CPF
   IF CNPJ()=.F.
      IF MsgYesNo("Deseja Alterar o CNPJ agora ?","Aviso do Sistema")
         OCNPJ_CPF:setfocus()
         Return
      endif
   ENDIF
ELSE
   FCPF=wCNPJ_CPF
   IF CPF()=.F.
      IF MsgYesNo("Deseja Alterar o CPF agora ?","Aviso do Sistema")
         OCNPJ_CPF:setfocus()
         Return
      endif
   ENDIF
ENDIF

SELE ASSOCI
IF TIPOCAD="C"
   SELE ASSOCI
   DBGOTOP()
   Dbsetorder(2)
   Dbseek(wNome)

   IF FOUND()
      MsgInfo("Nome de Associado Já cadastrado com esse Nome, Favor Vereficar !!!","Aviso do Sistema")
      oNome:setfocus()
      Return
   ENDIF

   wVerifica = wCodigo
   DO WHILE .T.
      SELE ASSOCI
      DBGOTOP()
      Dbsetorder(1)
      Dbseek(wCodigo)

      IF FOUND()
         wCodigo = wCodigo+1
         LOOP
      ELSE
         EXIT
      ENDIF
   ENDDO
   AppRede()
ELSE
   wVerifica = wCodigo
ENDIF
TRAVAREG("S")
REPL CODASSOC WITH Wcodigo,;
NOME         WITH Wnome ,;
ENDE         WITH Wend,;
BAIRRO       WITH Wbairro,;
CIDADE       WITH Wcidade,;
UF           WITH Wuf,;
CEP          WITH Wcep,;
TEL          WITH Wfone,;
FAX          WITH Wfax,;
CEL          WITH Wcel,;
EMAIL        WITH Wemail,;
FUNCAO1      WITH Wfunc1,;
FUNCAO2      WITH Wfunc2,;
VALOR        WITH Wvalor,;
VENC         WITH Wvenc,;
TIPOJF       WITH wTIPOJF
IF wTIPOJF="J"
   REPL CNPJ WITH wCNPJ_CPF
   REPL IE   WITH wRG_IE
ELSE
   REPL RG   WITH wRG_IE
   REPL CPF  WITH wCNPJ_CPF
ENDIF
DBCOMMIT()
LIBERAREG()

IF wVerifica #wCodigo
   oCodigo :Refresh()
   MsgInfo("O Numero do Cadastro do Associado Mudou Para o Nº. : "+str(wCodigo),"Aviso do Sistema")
ENDIF

oCadAss:Close()

IF TIPOCAD="C" .AND. Abre_Dbf="S"
   Dbcloseall()
ENDIF
Return

*******************
Function Limpa_var2
*******************
Wnome := ""
Wend := ""
Wbairro := ""
Wcidade := ""
wCNPJ_CPF := ""
Wcep := ""
wRG_IE := ""
Wfone := ""
Wfax := ""
Wcel := ""
Wemail := ""
Wfunc1 := ""
Wfunc2 := ""
Wvalor := 0
Wvenc  := DATE()

oNome:Refresh()
Ocodigo:Refresh()
Oend:Refresh()
Obairro:Refresh()
Ocidade:Refresh()
CBOuf:Refresh()
Ocep:Refresh()
OCNPJ_CPF:Refresh()
oRG_IE:Refresh()
Ofone:Refresh()
Ofax:Refresh()
Ocel:Refresh()
Oemail:Refresh()
Ovalor:Refresh()
Ovenc:Refresh()
Ofunc1:Refresh()
Ofunc2:Refresh()
oNome:SetFocus()
Return

******************
Function Cad_banco
******************
PRIVATE oCadBanco
PRIVATE oFont
PRIVATE LBLncb, Wncb := 0, Oncb, LBLmostncb
PRIVATE LBLdesc, Wdesc := "", Odesc
PRIVATE LBLdtconta, Wdtconta := date(), Odtconta
PRIVATE LBLagencia, Wagencia := "", Oagencia
PRIVATE LBLcc, Wcc := "", Occ
PRIVATE LBLsaldoini, Wsaldoini := 0, Osaldoini     
PRIVATE LBLend, Wend := "", Oend
PRIVATE LBLbairro, Wbairro := "", Obairro
PRIVATE LBLcomp, Wcomp := "", Ocomp
PRIVATE LBLcidade, Wcidade := "", Ocidade
PRIVATE LBLuf, CBOuf, Wuf := "",aItens1 := {"AC","AL","AP","AM","BA","CE","DF","GO","ES","MA","MT","MS","MG","PA","PB","PR","PE","PI","RJ","RN","RS","RO","RR","SP","SC","SE","TO"}
PRIVATE LBLcep, Wcep := "", Ocep, aItens :={"001","237","341"}
PRIVATE LBLemail, Wemail := "", Omail, aItens2 :={"17","18","19"}
PRIVATE LBLfone, Wfone := "", Ofone
PRIVATE LBLgerente, Wgerente := "", Ogerente
PRIVATE LBLfax, Wfax := "", Ofax
PRIVATE LBLinscest, Winscest := "", Oinscest
PRIVATE LBLobs, Wobs := "", Oobs
PRIVATE oIcon := HIcon():AddResource(1004)
PRIVATE wInicio :=.T., wNovo := .F.
PRIVATE Lcod_bc, Wcod_bc := "", Ocod_bc
PRIVATE Lcarteira, Wcarteira := "", Ocarteira

DBCLOSEALL()

PARA TIPOCAD

IF Use_Arq("BANCO",,.T.,.F.,.F.)=.F.
   Return
ENDIF

SELE BANCO
IF TIPOCAD="C"
   DBSETORDER(1)
   DbGoBottom()
   Wncb=CODCXA+1
ELSE
   DBSETORDER(2)
   dbgotop()
   Wnbc=0
   **********************************************************
   NAVEGAR("Pesquisa de Caixa\Banco","BANCO","PESQ_BANCO")
   ***********************************************************
   Wncb=CODCXA
   SELECT BANCO
   DBSETORDER(1)
   DBSEEK(Wncb)
   IF found()      
      Wncb      = CODCXA
      Wdesc     = DESCRICAO
      Wagencia  = AGENCIA
      Wcc       = CC
      Wemail    = EMAIL
      Wend      = RUA
      Wcomp     = COMPLEM 
      Wcidade   = CIDADE
      Wuf       = UF
      Wcep      = CEP
      Wbairro   = BAIRRO
      Wfone     = TEL
      Wfax      = FAX
      Wobs      = OBS
      Wgerente  = GERENTE
      Winscest  = INSCEST
      Wsaldoini = SALDOINI
      wcod_bc   = cod_bc
      wcarteira = ALLTRIM(carteira)
   else
      erroreg()
      DBCLOSEALL()
      RETURN nil
   ENDIF
   IF Wncb=1
      MsgStop("O Sistema, não aceita alteração Desse Registro","Aviso do Sistema")
      DBCLOSEALL()
      RETURN nil
   ENDIF
ENDIF
IF TIPOCAD="P"
   DBCLOSEALL()
   RETURN nil
ENDIF
   
PREPARE FONT oFont NAME "Arial" WIDTH 0 HEIGHT -12 WEIGHT 400
INIT DIALOG oCadBanco CLIPPER NOEXIT TITLE "Cadastro de Caixa/Banco";
AT 0,0 SIZE 670,460;
ICON  oIcon ;
FONT oFont ;   
STYLE DS_CENTER + WS_VISIBLE + WS_CAPTION + WS_SYSMENU    

SetColorinFocus( .t. )

@ 5,5   GROUPBOX grpConfiguracao           CAPTION "Dados do Caixa / Banco"     SIZE 655,155
@ 5,160 GROUPBOX grpConfiguracao           CAPTION "Dados Complementares"       SIZE 655,290

****INCIO DOS SAYS***
@ 20,40   SAY LBLncb                       CAPTION "N° do Caixa/Banco:"         SIZE 168,22
@ 20,70   SAY LBLdesc                      CAPTION "Descrição:"                 SIZE 168,22
@ 20,100  SAY LBLagencia                   CAPTION "Agencia..:"                 SIZE 168,22
@ 210,100 SAY LBLcc                        CAPTION "N° C/C:"                    SIZE 168,22
@ 385,100 SAY LBLdtconta                   CAPTION "Data Abertura da Conta:"    SIZE 168,22
@ 20,130  SAY LBLsaldoini                  CAPTION "Saldo Inicial:"             SIZE 168,22
@ 210,130 SAY Lcod_bc                      CAPTION "Codigo Banco.:"             SIZE 168,22
@ 385,130 SAY Lcarteira                    CAPTION "Carteira Tipo :"            SIZE 168,22
@ 20,195  SAY LBLend                       CAPTION "Endereço:"                  SIZE 168,22
@ 20,225  SAY LBLbairro                    CAPTION "Bairro:"                    SIZE 168,22
@ 245,225 SAY LBLbcomp                     CAPTION "Complemento:"               SIZE 168,22
@ 20,255  SAY LBLcidade                    CAPTION "Cidade:"                    SIZE 168,22
@ 300,255 SAY LBLuf                        CAPTION "UF:"                        SIZE 168,22
@ 290,285 SAY LBLcep                       CAPTION "Cep:"                       SIZE 168,22
@ 20,285  SAY LBLemail                     CAPTION "Email:"                     SIZE 168,22
@ 285,315 SAY LBLfone                      CAPTION "Fone:"                      SIZE 168,22
@ 20,315  SAY LBLgerente                   CAPTION "Gerente:"                   SIZE 168,22
@ 290,345 SAY LBLfax                       CAPTION "Fax:"                       SIZE 168,22
@ 20,345  SAY LBLinscest                   CAPTION "Insc. Est.:"                SIZE 168,22
@ 20,375  SAY LBLobs                       CAPTION "OBS:"                       SIZE 168,22
****FIM DOS SAYS***

****INCIO DOS GTES***
@ 130,40  GET Oncb VAR Wncb                 PICTURE "99999"  COLOR 255          SIZE 50,22 STYLE WS_DISABLED;
TOOLTIP "Informe o Codigo"

@ 80,70   GET Odesc VAR Wdesc                                         SIZE 560,22;
MAXLENGTH 40;
STYLE WS_TABSTOP;
TOOLTIP "Informe a Descrição do Banco"

@ 80,100  GET Obagencia VAR Wagencia        PICTURE "999999999999999"                  SIZE 120,22;
MAXLENGTH 15;
STYLE WS_TABSTOP;
TOOLTIP "Informe a Agencia"

@ 255,100 GET Occ VAR Wcc                   PICTURE "999999999999999"                   SIZE 120,22;
MAXLENGTH 15;
STYLE WS_TABSTOP;
TOOLTIP "Informe a Conta Corrente"

@ 540,100 GET DATEPICKER Odtconta VAR Wdtconta                                  SIZE 90,22;
STYLE WS_TABSTOP;
TOOLTIP "Informe a Data de Abertura da Conta"

@ 95,130  GET Osaldoini VAR Wsaldoini       PICTURE "@e 999,999.99"             SIZE 105,22;
STYLE WS_TABSTOP;
TOOLTIP "Informe o Saldo Inicial"

@ 300,130 GET COMBOBOX ocod_bc VAR wcod_bc  ITEMS aItens                       SIZE 60,22 TEXT;
STYLE WS_TABSTOP;
TOOLTIP "Informe o CODIGO do BANCO"

@ 470,130 GET COMBOBOX ocarteira VAR wcarteira  ITEMS aItens2                       SIZE 60,22 TEXT;
STYLE WS_TABSTOP;
TOOLTIP "Informe o Tipo de Carteira para Boleto Bancario"

@ 80,195  GET Oend VAR Wend                                           SIZE 400,22;
MAXLENGTH 47;
STYLE WS_TABSTOP;
TOOLTIP "Informe o Endereço"

@ 80,225  GET Obairro VAR Wbairro                                    SIZE 150,22;
MAXLENGTH 19;
STYLE WS_TABSTOP;
TOOLTIP "Informe o Bairro"

@ 330,225 GET Ocomp VAR Wcomp                                        SIZE 150,22;
MAXLENGTH 10;
STYLE WS_TABSTOP;
TOOLTIP "Informe o Complemento"

@ 80,255  GET Ocidade VAR Wcidade                                    SIZE 150,22;
MAXLENGTH 10;
STYLE WS_TABSTOP;
TOOLTIP "Informe a Cidade"

@ 330,255 GET COMBOBOX CBOuf VAR Wuf     ITEMS aItens1                SIZE 50,22 TEXT;
STYLE WS_TABSTOP;
TOOLTIP "Informe a Unidade Federativa"

@ 330,285 GET Ocep     VAR Wcep             PICTURE "@R 99999-999"              SIZE 150,22;
STYLE WS_TABSTOP;
TOOLTIP "Informe o CEP"

@ 80,285  GET Oemail   VAR Wemail                                     SIZE 150,22;
MAXLENGTH 40;
STYLE WS_TABSTOP;
TOOLTIP "Informe a Cidade"

@ 330,315 GET Ofone    VAR Wfone            PICTURE "@R (99)9999-9999"          SIZE 150,22;
STYLE WS_TABSTOP;
TOOLTIP "Informe o Telefone"

@ 80,315  GET Ogerente VAR Wgerente                                  SIZE 150,22;
MAXLENGTH 29;
STYLE WS_TABSTOP;
TOOLTIP "Informe o Nome de Gerente"

@ 330,345 GET Ofax     VAR Wfax             PICTURE "@R (99)9999-9999"          SIZE 150,22;
STYLE WS_TABSTOP;
TOOLTIP "Informe o Fax"

@ 80,345  GET Oinscest VAR Winscest         PICTURE ""                          SIZE 150,22;
MAXLENGTH 15;
STYLE WS_TABSTOP;
TOOLTIP "Informe a Inscrição Estadual"

@ 80,375  GET Oobs     VAR Wobs             PICTURE ""  VALID {||Focaliza()}    SIZE 400,22;
MAXLENGTH 68;
STYLE WS_TABSTOP;
TOOLTIP "Informe alguma Observação"

****FIM DOS GETS***

****INICIO DOS BUTTON*****
@ 320,410  BUTTON btnOk CAPTION "&Salvar" SIZE 100, 28 ;
TOOLTIP "Salvar Registro";
ON CLICK {||Grava_banco(), oCadBanco:Close() };
STYLE WS_TABSTOP

@ 430,410  BUTTON "&Limpar" SIZE 100, 28 ;
TOOLTIP "Limpar Campos";
ON CLICK {|| Limpa_var3() };
STYLE WS_TABSTOP  

@ 540,410  BUTTON "&Fechar" SIZE 100, 28 ;
TOOLTIP "Sair do Modulo de Cadastro de Banco";
ON CLICK {||DBCLOSEALL(), oCadBanco:Close()};
STYLE WS_TABSTOP
****FIM DOS BUTTON*****

WriteStatus( oTelaPrincipal,3,"Cadastro de Bancos" )//BARRA DE STATUS
ACTIVATE DIALOG oCadBanco
WriteStatus( oTelaPrincipal,3,"Area de Trabalho" )

RETURN nil
********************************************************************************
FUNCTION Grava_banco() //GRAVA ASSOCIADO

IF EMPTY(Wdesc)
   OBRIGA()
   odesc:setfocus()
    RETURN
ENDIF

IF EMPTY(wuf)
   OBRIGA()
   CBOuf:setfocus()
   RETURN
endif

IF EMPTY(Wgerente)
   OBRIGA()
   Ogerente:setfocus()
   RETURN
endif

SELE BANCO
IF TIPOCAD="C"
   APPEND BLANK
   REPLACE CODCXA  WITH Wncb
ELSE
   DBGOTOP()
   DBSETORDER(1)
   DBSEEK(Wncb)
ENDIF
TRAVAREG()
REPLACE CODCXA WITH Wncb,;
DESCRICAO      WITH Wdesc,;
AGENCIA        WITH Wagencia,;
CC             WITH Wcc,;
EMAIL          WITH Wemail,;
RUA            WITH Wend,;
COMPLEM        WITH Wcomp,;
CIDADE         WITH Wcidade,;
UF             WITH Wuf,;
CEP            WITH Wcep,;
BAIRRO         WITH Wbairro,;
TEL            WITH Wfone,;
FAX            WITH Wfax,;
OBS            WITH Wobs,;
GERENTE        WITH Wgerente,;
INSCEST        WITH Winscest,;
SALDOINI       WITH Wsaldoini,;
COD_BC         WITH wCOD_BC,;
CARTEIRA       WITH wCARTEIRA
DBCOMMIT()
DBUNLOCK()

IF TIPOCAD="C"
   Cad_banco("C")
ENDIF
RETURN

********************************************************************************
FUNCTION Limpa_var3()
********************************************************************************
Wdesc := ""
Wdtconta := ""
Wagencia := ""
Wcc := ""
Wsaldoini := 0
Wend := ""
Wuf := ""
Wcomp := ""
Wcep := ""
Wemail := ""
Wfone := ""
Wgerente := ""
Wfax := ""
Winscest := ""
Wobs := ""

Oncb:Refresh()
Odesc:Refresh()
Odtconta:Refresh()
Obagencia:Refresh()
Obairro:Refresh()
Ocidade:Refresh()
CBOuf:Refresh()
Occ:Refresh()
Osaldoini:Refresh()
Oend:Refresh()
Ocomp:Refresh()
Ocep:Refresh()
Oemail:Refresh()
Ofone:Refresh()
Ogerente:Refresh()
Ofax:Refresh()
Oinscest:Refresh()
Oobs:Refresh()
Odesc:SetFocus()
Return
********************************************************************************

FUNCTION MSGPROX()
MSGINFO("Area em Desenvolvimento","Aviso do Sistema")
WriteStatus( oTelaPrincipal,3,"Area em Construção" )//BARRA DE STATUS
RETURN nil
