#include "scm.ch"

REQUEST DBFCDX
REQUEST DBFFPT

FUNCTION Main(SESSAO)
PRIVATE  oIcon := HIcon():AddResource(1004)

SetColorinFocus(.T., x_BLACK, RGB(240,255,144))
SetToolTipBalloon(.T.)   // MOSTRA OS TOOLTIP EM FORMATO DE BALÃO
SetDisableBackColor(.T.) // USA OS CAMPOS DESABILITADOS COM FUNDO BRANCO

PRIVATE oTelaPrincipal, ;
        oBmpLogo2  := HBitmap():AddFile("res\SAVE.bmp"),;
        oBmpLogo3  := HBitmap():AddFile("res\CALC.bmp"),;
        oBmpLogo4  := HBitmap():AddFile("res\AGENDA.bmp"),;
        oBmpLogo5  := HBitmap():AddFile("res\info.bmp"),;
        oBmpLogo9  := HBitmap():AddFile("res\NOVO.bmp"),;
        oBmpLogo7  := HBitmap():AddFile("res\REINDEX.bmp"),;
        oBmpLogo8  := HBitmap():AddFile("res\CONTATO.bmp"),;
        oBmpLogo12 := HBitmap():AddFile("res\NOVO2.bmp"),;
        oBmpLogo11 := HBitmap():AddFile("res\SCM.bmp"),;
        oBmpLogo13 := HBitmap():AddFile("res\ajuda.bmp")

IF eTipo_banco="DBF"
   IF Os_IsWin9X()=.F.  // se não for Windows 95 ou 98
      IF UnidadeCorrente()=.F.
         MsgStop("Não é possivel iniciar o Sistema apartir dessa Unidade, Favor revisar a instalação do sistema","Aviso do Sistema")
         Return
      ENDIF
   ENDIF
ENDIF

PUBLIC VERSAOATUAL:="Data da Ultima Atualização.: "+Data_Hora_ARQ(NomeExecutavel())+" Versão.:"+ GETFILEVERSIONINFO()
Public xEMP       :="Sem Nome da Instituição"

IF eTipo_banco="DBF"
   Public eRDD_DRIVER := "DBFCDX"
ELSEIF eTipo_banco="SQL"
   Public eRDD_DRIVER := "DBFCDX"

   IF SESSAO="-CONF" .OR. SESSAO="-conf" // ABRE AS CONFIGURAÇÕES DE ACESSO AO SQL
      IF !File("SYGECOM.DBF")
         private aField[7]
         aField[1] := {"TIPO_SQL", "C", 10,  0}  // FIREBIRD, MYSQL, POSTGRESQL
         aField[2] := {"HOST"    , "C", 60,  0}
         aField[3] := {"PORTA"   , "C",  5,  0}
         aField[4] := {"DATABASE", "C", 40,  0}
         aField[5] := {"USUARIO" , "C", 30,  0}
         aField[6] := {"SENHA"   , "C", 30,  0}
         aField[7] := {"CHARSET" , "C", 15,  0}
         DBcreate("SYGECOM", aField, eRDD_DRIVER)
      ENDIF

      Configura_Servidor()
      SAIR2()
      Return
   ENDIF
ENDIF

IF eTipo_banco="DBF"
   RddSetDefault(eRDD_DRIVER)
   DBSETDRIVER(eRDD_DRIVER)

   Public eCAMINHO_DADOS := "DADOS\"
ELSEIF eTipo_banco="SQL"
   #ifdef _XHBSQL_
      Abre_dados(.F.)
   #else
      MsgStop("Somente usando a Versão Comercial do xHarbour","Aviso do Sistema")
      SAIR2()
   #endif
   Public eCAMINHO_DADOS := ""
ENDIF

IF SESSAO="-DBU" .OR. SESSAO="-dbu" // ABRE UM EDITOR DE REGISTROS PROPRIOS

   Alterar_Registros()

   SAIR2()
   Return
ENDIF

REQUEST HB_CODEPAGE_PTISO
REQUEST HB_LANG_PT

HB_SETCODEPAGE( 'PTISO' )
HB_LANGSELECT( 'PT' )

SET CENTURY ON
SET BELL OFF
SET DATE BRITISH
SET EPOCH TO 2000
SET CONFIRM ON
SET DELETED ON
SET EXACT ON
SET SCOREBOARD OFF
SET WRAP ON
SET EXCLUSIVE OFF
SET AUTOPEN ON
SET OPTIMIZE ON
SET STRICTREAD ON

IF SESSAO=Nil
   IF ( hWnd := Hwg_FindWindow( oTelaPrincipal,"SCM - SISTEMA DE CONTROLE DE MENSALIDADES Vs. " + GETFILEVERSIONINFO() ) ) != 0
      Focaliza_App()
      Return
   ENDIF
ENDIF

SetToolTipBalloon(.t.)
SetColorinFocus(.t.)

//ATUALSIS()

IF Use_Arq("INSTITUI",,.T.,.T.,.F.)=.F.  // COMPARTILHADO
   Return
ENDIF

SELE INSTITUI
DBGOTOP()
public xEMP     :=ALLTRIM(NOME)
public eFONE    :=TEL
public eCGC     :=CNPJ
public eENDE    :=ENDE
public ebairro  :=BAIRRO
public eIE      :=IE
public eCEP     :=CEP
public eCIDADE  :=CIDADE
public eESTADO  :=UF
public eEMAIL   :=EMAIL
public eSERVER  :=SERVER
public eUSUARIO :=USUARIO
public eSENHA   :=SENHA
public eBANCO   :=BANCO
public eAGENCIA :=AGENCIA
public eCONTA   :=CONTA

  INIT WINDOW oTelaPrincipal;
  MAIN ;
  TITLE "SCM - SISTEMA DE CONTROLE DE MENSALIDADES Vs. " + GETFILEVERSIONINFO();
  SIZE HWG_GetDesktopWidth(), HWG_GetDesktopHeight() ;
  ICON oIcon ;
  ON EXIT {|| sair() }

*****INCIO DOS MENUS*****
MENU OF oTelaPrincipal
     MENU TITLE "&Cadastro" 
          MENU TITLE "Cadastro &Associados"
               MENUITEM "Cadastra Associados"   ACTION Cad_Associado("C","S");
               ACCELERATOR "F8", VK_F8
               MENUITEM "Altera Associados"     ACTION Pesquisa_Associado()
               MENUITEM "Pesquisa Associado"    ACTION Pesquisa_Associado()
               SEPARATOR
               MENU TITLE "&Relatorio"
                    MENUITEM "Relatorio por Nome"  ACTION REL_ASSOCIADO("NOME")
                    SEPARATOR
                    MENUITEM "Relatorio por Codigo" ACTION REL_ASSOCIADO("CODIGO")
               ENDMENU
		        ENDMENU
          SEPARATOR
    		    MENU TITLE "Cadastro &Bancario"
     	 		   MENUITEM "Cadastra Banco"           ACTION Cad_banco("C")
               MENUITEM "Altera Banco"          ACTION Cad_banco("A")
               MENUITEM "Pesquisa Banco"        ACTION Cad_banco("P")
     		   ENDMENU
  		      SEPARATOR
  		      MENUITEM "&Cadastro Setor"  ACTION FRMcad_setor ("C")
  		      SEPARATOR
  		      MENUITEM "&Sair"    ACTION EndWindow()
     ENDMENU
     
 	  MENU TITLE "&Mensalidades"
          MENUITEM "&Gerar Mensalidade" ACTION FRMcad_mensal("C")
			   SEPARATOR
          MENUITEM "&Alterar Mensalidade"   ACTION FRMcad_mensal("A")
            SEPARATOR
          MENUITEM "&Pesquisa Mensalidade"  ACTION FRMcad_mensal("P")
      	    SEPARATOR
           MENUITEM "Receber Parcela"       ACTION Busca_parcASS()      	  
             SEPARATOR
      	  MENUITEM "&Reimprimir"           ACTION Reimp_carne()  	        
			    SEPARATOR
      	  MENU TITLE "&Controle de Mensalidade"
    		       MENUITEM "Faturas a Receber"        ACTION Faturas("A")
    		       SEPARATOR
    		       MENUITEM "Faturas Recebidas"        ACTION Faturas("P")
    		       SEPARATOR
    		       MENUITEM "Controle Geral"           ACTION Faturas()
      	  ENDMENU
        ENDMENU

  	  MENU TITLE "&Relatorios"
          MENU TITLE "&Mensalidades Recebidas"
               MENUITEM "Geral"             ACTION REL_PARC_GERAL ("P")
               SEPARATOR
               MENUITEM "Total do Associado" ACTION Busca_REL("P")
          ENDMENU
          SEPARATOR
          MENU TITLE "&Mensalidades a Receber"
               MENUITEM "Geral"             ACTION REL_PARC_GERAL ("A")
               SEPARATOR
               MENUITEM "Total do Associado" ACTION Busca_REL("A")          
          ENDMENU
          SEPARATOR
          MENU TITLE "Outros Relatorios"
               MENUITEM "Relatorio Mensal para Reunião de Diretoria" ACTION Pesq_data()
          ENDMENU
	  ENDMENU
                   
     MENU TITLE "&Uteis"
          MENUITEM "&Dados da Instituição"       ACTION Dados_Instituicao()
          SEPARATOR
          MENUITEM "&Reindexar Banco de Dados"  ACTION INDEXA()
          SEPARATOR
          MENU TITLE "&Copia de Segurança"
               MENUITEM "&Fazer Back-Up"        ACTION Back_up()
               SEPARATOR
               MENUITEM "&Retornar Back-Up"     ACTION Ret_Back_up()
          ENDMENU
          SEPARATOR
          MENUITEM "&Calculadora"               ACTION ShellExecute("calc")
          SEPARATOR
          MENUITEM "&Enviar email"              ACTION Sendemail("suporte@sygecom.com.br",1)
          SEPARATOR
          MENUITEM "Imprime Capa"               ACTION AVISO()
			 SEPARATOR
			 MENU TITLE "Configurar Impressoras"
	            MENUITEM "Ver Impressoras Instaladas"                    ACTION RunApplet_imp( "PrintersFolder" )
               MENUITEM "Adicionar Impressoras"                         ACTION RunApplet_imp( "AddPrinter" )
			 ENDMENU
			 SEPARATOR
          MENU TITLE "&Painel de Controle Windows XP"
               MENUITEM "Opções de acessibilidade"                      ACTION RunApplet( "access.cpl" )
               MENUITEM "Adicionar ou remover programas"                ACTION RunApplet( "appwiz.cpl" )
               MENUITEM "Propriedades de Vídeo"                         ACTION RunApplet( "desk.cpl" )
               MENUITEM "Propriedades do fax"                           ACTION RunApplet( "fax.cpl" )
               MENUITEM "Assistente para adicionar ou remover hardware" ACTION RunApplet( "hdwwiz.cpl" )
               MENUITEM "Propriedades de Internet"                      ACTION RunApplet( "inetcpl.cpl" )
               MENUITEM "Opções regionais"                              ACTION RunApplet( "intl.cpl" )
               MENUITEM "Opções de jogos"                               ACTION RunApplet( "joy.cpl" )
               MENUITEM "Propriedades de Sons e multimídia"             ACTION RunApplet( "mmsys.cpl" )
               MENUITEM "Conexões dial-up e de rede"                    ACTION RunApplet( "ncpa.cpl" )
               MENUITEM "ODBC Data Source Administrator"                ACTION RunApplet( "odbccp32.cpl" )
               MENUITEM "Propriedades de Opções de energia"             ACTION RunApplet( "powercfg.cpl" )
               MENUITEM "Propriedades de Scanners e câmeras"            ACTION RunApplet( "sticpl.cpl" )
               MENUITEM "Propriedades do sistema"                       ACTION RunApplet( "sysdm.cpl" )
               MENUITEM "Opções de telefone e modem"                    ACTION RunApplet( "telephon.cpl" )
               MENUITEM "Propriedades de Data e hora"                   ACTION RunApplet( "timedate.cpl" )
               MENUITEM "Atualizações automáticas"                      ACTION RunApplet( "wuaucpl.cpl" )
			      SEPARATOR
			      MENUITEM "Gerenciador de Dispositivos"                   ACTION ShellExecute("taskmgr.exe","open")		      
			 ENDMENU
	  ENDMENU
	  MENU TITLE "Ajuda"
	       MENUITEM "Ajuda"            ACTION  Ajuda_SCM()
	       SEPARATOR
	       MENUITEM "&Sobre a SyGeCom" ACTION sobre()               
     ENDMENU
ENDMENU
*****FIM DOS MENUS*****

CENTER WINDOW oTelaPrincipal

nCenterWidth := ( ( oTelaPrincipal:nWidth - oBmpLogo11:nWidth ) /2)
nCenterHeight := ( ( oTelaPrincipal:nHeight - oBmpLogo11:nHeight ) /3)

@ nCenterWidth, nCenterHeight BITMAP oBmpLogo11 SHOW "res\SCM.bmp" ;
OF oTelaPrincipal ;
SIZE oBmpLogo11:nWidth, oBmpLogo11:nHeight

************************INICIO DO TOOLBAR***************************************
@ 0,0 PANEL oPanel OF oTelaPrincipal SIZE 0,37
vPosicao=0

@ vPosicao,2 OWNERBUTTON OF oPanel;
ON CLICK {|| Cad_Associado("C","S") } ;
SIZE 36,36 ;
FLAT;
BITMAP oBmpLogo9 FROM RESOURCE TRANSPARENT;
TOOLTIP "Cadastro de Associado"

vPosicao=vPosicao+39
@ vPosicao,2 OWNERBUTTON OF oPanel;
ON CLICK {|| FRMcad_mensal("C") } ;
SIZE 36,36 ;
FLAT;
BITMAP oBmpLogo12 FROM RESOURCE TRANSPARENT;
TOOLTIP "Cadastro de Mensalidade"

vPosicao=vPosicao+39
@ vPosicao,2 OWNERBUTTON OF oPanel;
ON CLICK {|| ShellExecute("calc") } ;
SIZE 36,36 ;
FLAT;
BITMAP oBmpLogo3 FROM RESOURCE TRANSPARENT;
TOOLTIP "Calculadora"

vPosicao=vPosicao+39
@ vPosicao,2 OWNERBUTTON OF oPanel;
ON CLICK {|| indexa() } ;
SIZE 36,36 ;
FLAT;
BITMAP oBmpLogo7 FROM RESOURCE TRANSPARENT;
TOOLTIP "Reindexa o Banco de Dados"

vPosicao=vPosicao+39
@ vPosicao,2 OWNERBUTTON OF oPanel;
ON CLICK {|| Back_up() } ;
SIZE 36,36 ;
FLAT;
BITMAP oBmpLogo2 FROM RESOURCE TRANSPARENT;
TOOLTIP "Realizar Back-Up do Banco de Dados"

vPosicao=vPosicao+39
@ vPosicao,2 OWNERBUTTON OF oPanel;
ON CLICK {|| Sendemail("suporte@sygecom.com.br",1) } ;
SIZE 36,36 ;
FLAT;
BITMAP oBmpLogo8 FROM RESOURCE TRANSPARENT;
TOOLTIP "Suporte On-Line"

vPosicao=vPosicao+39
@ vPosicao,2 OWNERBUTTON OF oPanel;
ON CLICK {|| sobre() } ;
SIZE 36,36 ;
FLAT;
BITMAP oBmpLogo5 FROM RESOURCE TRANSPARENT;
TOOLTIP "Informações Sobre a Sygecom Informática"

vPosicao=vPosicao+39
@ vPosicao,2 OWNERBUTTON OF oPanel;
ON CLICK {|| Ajuda_SCM() } ;
SIZE 36,36 ;
FLAT;
BITMAP oBmpLogo13 FROM RESOURCE TRANSPARENT;
TOOLTIP "Informações Sobre o SCM"

vPosicao=vPosicao+39
@ vPosicao,2 OWNERBUTTON OF oPanel;
ON CLICK {|| Sair() } ;
SIZE 36,36 ;
FLAT;
BITMAP 1005 FROM RESOURCE TRANSPARENT;
TOOLTIP "Sair do Sistema"
*********************************FIM DO TOOLBAR*********************************

*********************************BARRA DE STATUS********************************
ADD STATUS oStatus TO oTelaPrincipal PARTS 220 , 350 , 180
 WriteStatus( oTelaPrincipal,1,"Sistema de Controle de Mensalidades" )
 WriteStatus( oTelaPrincipal,2, VERSAOATUAL )
 WriteStatus( oTelaPrincipal,3,"Area de Trabalho" )
********************************************************************************

SET TIMER oTime1 OF oTelaPrincipal ID 9008 VALUE 500 ACTION {|| Verefica_Login() }

ACTIVATE WINDOW oTelaPrincipal MAXIMIZED

RETURN nil

***********************
Function Verefica_Login
***********************
oTime1:end()

IF EMPTY(XEMP) .OR. EMPTY(eCGC) .OR. EMPTY(eENDE) .OR. EMPTY(ebairro) .OR. EMPTY(eCEP) .OR. EMPTY(eCIDADE) .OR. EMPTY(eESTADO)
   MsgInfo("Os Dados da Instituição estão Incompletos, Favor Revisar !!!","Aviso do Sistema")
   Dados_Instituicao()
ENDIF

Return

*************
FUNCTION SAIR
*************
dbcloseall()
IF MSGNOYES("Deseja Realmente Sair do Programa ?","Aviso do Sistema")
   LIMPATEMP()
   IF eTipo_banco="SQL"
      #ifdef _XHBCOM_
          SR_End()
      #endif
   ENDIF
   PostQuitMessage(0)
  	__Quit()
ELSE
   RETURN .F.
ENDIF
Return

**************
FUNCTION SAIR2
**************
dbcloseall()
LIMPATEMP()
IF eTipo_banco="SQL"
   #ifdef _XHBCOM_
   SR_End()
   #endif
ENDIF
HB_GCALL()
Release All
PostQuitMessage(0)
__Quit()
Return

******************
FUNCTION Ajuda_Scm
******************
LOCAL oAjuda, oFont := HFont():Add( "MS Sans Serif",0,-13 )
LOCAL oTree, oSplit, oSay

INIT DIALOG oAjuda TITLE "Sistema de Ajuda do SCM" CLIPPER ;
   AT 0,0 SIZE HWG_GETDESKTOPWIDTH(),HWG_GETDESKTOPHEIGHT()-28 ;
   FONT oFont;
   ICON oIcon ;
   ON INIT {||BuildTree(oAjuda,oTree,oSay)} ;
   STYLE WS_POPUP+WS_CAPTION+DS_CENTER +WS_SYSMENU+WS_MINIMIZEBOX+WS_MAXIMIZEBOX+WS_VISIBLE

   @ 10,10 TREE oTree OF oAjuda SIZE 200,280 ;
   BITMAP { "res\PASTAF.bmp","res\PASTAA.bmp" } ;
   ON SIZE {|o,x,y|o:Move(,,,y-20)}

   @ 214,10 SAY oSay CAPTION "" SIZE 206,280 //STYLE WS_BORDER ;
   *ON SIZE {|o,x,y|o:Move(,,x-oSplit:nLeft-oSplit:nWidth-20,y-10)}

   @ 210,10 SPLITTER oSplit SIZE 4,260 ;
   DIVIDE {oTree} FROM {oSay} ;
   ON SIZE {|o,x,y|o:Move(,,,y-20)}

   oSplit:bEndDrag := {||RedrawWindow( oSay:handle,RDW_ERASE+RDW_INVALIDATE+RDW_INTERNALPAINT+RDW_UPDATENOW)}
   
   WriteStatus( oTelaPrincipal,3,"Sistema de Ajuda ao Usuario" )

ACTIVATE DIALOG oAjuda //Show SW_SHOWMAXIMIZED

   oFont:Release()

   WriteStatus( oTelaPrincipal,3,"Area de Trabalho" )

Return Nil

***************************************
FUNCTION BuildTree( oAjuda,oTree,oSay )
***************************************
LOCAL oNode, oNodeCAD, oNodeCADASS, oNodeRELASS, oNodeCADBAN, oNodeCADSET, oNodeAGEN
LOCAL oNodeMENS, oNodeGERAMENS, oNodeCONTROLAMENS
LOCAL oNodeREL, oNodeRELPG, oNodeRELAPG 
LOCAL oNodeUTE

INSERT NODE oNode CAPTION "SCM" TO oTree  ON CLICK {||NodeOut(1,oSay)}
     INSERT NODE oNodeCAD CAPTION "Cadastro" TO oNode  BITMAP {"res\BOOK.bmp","res\BOOKOPEN.bmp"}  ON CLICK {||NodeOut(2,oSay)}
          INSERT NODE oNodeCADASS CAPTION "Cadastro de Associados" TO oNodeCAD BITMAP {"res\BOOK.bmp","res\BOOKOPEN.bmp"} ON CLICK {||NodeOut(3,oSay)}
               INSERT NODE "Cadastra Associados"  TO oNodeCADASS BITMAP {"res\FILE.bmp"} ON CLICK {||NodeOut(4,oSay)}
               INSERT NODE "Altera Associados"    TO oNodeCADASS BITMAP {"res\FILE.bmp"} ON CLICK {||NodeOut(5,oSay)}
               INSERT NODE "Pesquisa Associados"  TO oNodeCADASS BITMAP {"res\FILE.bmp"} ON CLICK {||NodeOut(6,oSay)}
					INSERT NODE oNodeRELASS CAPTION "Relatorios"  TO oNodeCADASS BITMAP {"res\BOOK.bmp","res\BOOKOPEN.bmp"} ON CLICK {||NodeOut(7,oSay)}
						  INSERT NODE "Relatorio Por Nome" TO oNodeRELASS BITMAP {"res\FILE.bmp"} ON CLICK {||NodeOut(8,oSay)}
                    INSERT NODE "Relatorio Por Nome" TO oNodeRELASS BITMAP {"res\FILE.bmp"} ON CLICK {||NodeOut(9,oSay)}
			 INSERT NODE oNodeCADBAN CAPTION "Cadastro Bancario" TO oNodeCAD BITMAP {"res\BOOK.bmp","res\BOOKOPEN.bmp"} ON CLICK {||NodeOut(10,oSay)}
					INSERT NODE "Cadastra Banco" TO oNodeCADBAN BITMAP {"res\FILE.bmp"} ON CLICK {||NodeOut(11,oSay)}
               INSERT NODE "Altera Banco"   TO oNodeCADBAN BITMAP {"res\FILE.bmp"} ON CLICK {||NodeOut(12,oSay)}
               INSERT NODE "Pesquisa Banco" TO oNodeCADBAN BITMAP {"res\FILE.bmp"} ON CLICK {||NodeOut(13,oSay)}
			 INSERT NODE oNodeCADSET CAPTION "Cadastro de Setor" TO oNodeCAD BITMAP {"res\FILE.bmp"} ON CLICK {||NodeOut(14,oSay)}
     INSERT NODE oNodeMENS CAPTION "Mensalidade"  TO oNode BITMAP {"res\BOOK.bmp","res\BOOKOPEN.bmp"} ON CLICK {||NodeOut(16,oSay)}
          INSERT NODE oNodeGERAMENS CAPTION "Gera Mensalidade" TO oNodeMENS BITMAP {"res\BOOK.bmp","res\BOOKOPEN.bmp"} ON CLICK {||NodeOut(17,oSay)}
					INSERT NODE "Lança Mensalidade" TO oNodeGERAMENS BITMAP {"res\FILE.bmp"} ON CLICK {||NodeOut(18,oSay)}
               INSERT NODE "Altera Mensalidade" TO oNodeGERAMENS BITMAP {"res\FILE.bmp"} ON CLICK {||NodeOut(19,oSay)}
               INSERT NODE "Pesquisa Mensalidade" TO oNodeGERAMENS BITMAP {"res\FILE.bmp"} ON CLICK {||NodeOut(20,oSay)}
               INSERT NODE "Reimprime Mensalidade" TO oNodeGERAMENS BITMAP {"res\FILE.bmp"} ON CLICK {||NodeOut(21,oSay)}
			 INSERT NODE "Paga Mensalidade" TO oNodeMENS BITMAP {"res\FILE.bmp"} ON CLICK {||NodeOut(22,oSay)}
          INSERT NODE oNodeCONTROLAMENS CAPTION "Controle de Mensalidade" TO oNodeMENS BITMAP {"res\BOOK.bmp","res\BOOKOPEN.bmp"} ON CLICK {||NodeOut(23,oSay)}
					INSERT NODE "Faturas a Pagar" TO oNodeCONTROLAMENS BITMAP {"res\FILE.bmp"} ON CLICK {||NodeOut(24,oSay)}
					INSERT NODE "Faturas Recebidas" TO oNodeCONTROLAMENS BITMAP {"res\FILE.bmp"} ON CLICK {||NodeOut(25,oSay)}
     INSERT NODE oNodeREL CAPTION "Relatorios" TO oNode BITMAP {"res\BOOK.bmp","res\BOOKOPEN.bmp"} ON CLICK {||NodeOut(26,oSay)}
          INSERT NODE oNodeRELPG CAPTION "Relatorio de Mensalidade Pagas" TO oNodeREL BITMAP {"res\BOOK.bmp","res\BOOKOPEN.bmp"} ON CLICK {||NodeOut(27,oSay)}
					INSERT NODE "Mensalidades Pagas Geral" TO oNodeRELPG BITMAP {"res\FILE.bmp"} ON CLICK {||NodeOut(28,oSay)}
               INSERT NODE "Mensalidades Pagas Total do Associado" TO oNodeRELPG BITMAP {"res\FILE.bmp"} ON CLICK {||NodeOut(29,oSay)}
          INSERT NODE oNodeRELAPG CAPTION "Relatorio de Mensalidade A Pagar" TO oNodeREL BITMAP {"res\BOOK.bmp","res\BOOKOPEN.bmp"} ON CLICK {||NodeOut(30,oSay)}
					INSERT NODE "Mensalidades A Pagar Geral" TO oNodeRELAPG BITMAP {"res\FILE.bmp"} ON CLICK {||NodeOut(31,oSay)}
               INSERT NODE "Mensalidades A Pagar Total do Associado" TO oNodeRELAPG BITMAP {"res\FILE.bmp"} ON CLICK {||NodeOut(32,oSay)}
     INSERT NODE oNodeUTE CAPTION "Uteis"  TO oNode BITMAP {"res\BOOK.bmp","res\BOOKOPEN.bmp"} ON CLICK {||NodeOut(33,oSay)}
          INSERT NODE "Dados da Instituição" TO oNodeUTE BITMAP {"res\FILE.bmp"} ON CLICK {||NodeOut(34,oSay)}
          INSERT NODE "Reindexa Banco de Dados" TO oNodeUTE BITMAP {"res\FILE.bmp"} ON CLICK {||NodeOut(35,oSay)}
          INSERT NODE "Copia de Segurança" TO oNodeUTE BITMAP {"res\FILE.bmp"} ON CLICK {||NodeOut(36,oSay)}
          INSERT NODE "Calculadora" TO oNodeUTE BITMAP {"res\FILE.bmp"} ON CLICK {||NodeOut(37,oSay)}
          INSERT NODE "Envia Email" TO oNodeUTE BITMAP {"res\FILE.bmp"} ON CLICK {||NodeOut(38,oSay)}
     INSERT NODE "Sobre"        TO oNode BITMAP {"res\BOOK.bmp","res\BOOKOPEN.bmp"} ON CLICK {||NodeOut(39,oSay)}
INSERT NODE "SyGeCom"           TO oTree  ON CLICK {||NodeOut(0,oSay), Sobre()}

   oTree:bExpand := {||.T.}

RETURN Nil 

***********************************
STATIC FUNCTION NodeOut( n, oSay )
***********************************

LOCAL aText := { ;
"Saiba mais Sobre o SCM (Sistema de Controle de Mensalidades)", ;
   "Modulo de Cadastro: Onde se pode realizar os Cadastros, Alteraçôes e Pesquisas de Associados, Banco e Função.", ;  
	    "Cadastro de Associado: Cadastra, Altera e Pesquisa Associado.", ;
	          "Cadastra Associado: Cria um novo Registro Apartir dos dados de um Associado.", ;
	          "Altera Associado: Modifica os dados ja cadastrados de um Associado.", ;
	          "Pesquisa Associado: Sistema de Busca de um Associado; Retorna os dados completos do associado pesquisado.", ;
		   	 "Relatorios de associados organizados por Nome ou pelo Codigo.", ;
		            "Relatorio por Nome: Gera um relatorio de todos os Associados, organizados por ordem Alfabetica.", ;
                  "Relatorio por Codigo: Gera um relatorio de todos os Associados, organizados por ordem crescente de Codigo.", ;           		    		       
		 "Cadastro Bancario: Cadastra, Altera e Pesquisa Banco.", ;		       
				 "Cadastra Banco: Cadastra os dados Bancarios de um ou mais bancos da Instituição.", ;
				 "Altera Banco: Modifica os dados do Banco pesquisado.", ; 
				 "Pesquisa Banco: Pesquisa e mostra na tela os dados de um Banco.", ;
		 "Cadastro de Setor: Cadastra o Setor e a função da Instituição.", ;
		 "Sistema de Agenda: Agenda de telefones de Associados, Serviços diverços entre outros.", ;
	"Modulo de Mensalidades: Gera e Controla Mensalidades.", ;
		 "Gera Mensalidade: Modulo de Cadastro de Mensalidades.", ;
				 "Gera Mensalidade: Gera uma Mensalidade para um Associado", ; 
				 "Altera Mansalidade: Altera os dados da Parcela de uma Mensalidade, desde que esta Parcela não tenha cido Recebida", ;
				 "Pesquisa Mensalidade: Pesquisa uma mensalidade e mostra as parcelas da mesma", ;
				 "Reimprime Mensalidade: Opção para reimprimir uma Parcela de uma Mensalidade ou Reimpreção de todo o Carne.", ;
		 "Baixa de Mensalidade: Controla o Recebimento de uma parcela da Mensalidade Pesquisada.", ; 
		 "Controle de Mensalidade: Controle de Todas as Mensalidades e Parcelas, Recebidas e A Receber.", ;
				 "Faturas A Receber: Relação de todas as Parcelas de Todos os Carnes que ainda não foram Recebidas.", ;
				 "Faturas Recebidas: Relação de todas as Parcelas de Todos os Carnes que ja foram Recebidas.", ;
	"Relatorios: Todos os Tipos de Relatorios Relacionados as Mensalidades.", ;
		 "Relatorios Mensalidades recebidas: Relação de Todas As Parcelas Recebidas.", ;
				 "Relatorio Mensalidades Recebidas em Geral.", ;
				 "Relatorio Mensalidades Recebidas de Um Associado.", ;
		 "Relatorios Mensalidades A Receber: Relação de Todas As Parcelas que não forão Recebidas.", ;
				 "Relatorio Mensalidades A Receber em Geral.", ;
				 "Relatorio Mensalidades A Receber de Um Associado.", ;
	"Uteis: Modulo Reservado para de Manutenção Geral do SCM.", ;
	    "Dados Da Instituição: Armazena todos os dados Da Instituição.", ;
		 "Reindexa Banco de Dados: Cria novamente Todos os Indices que facilitam e viabilizão todas as Pesquisas do Sistema SCM.", ;
		 "Copia de Segurança: Cria um BackUp dos Bancos de dados do sistema SCM.", ;
		 "Calculadora: Atalho que facilita o acesso a calculadora do Sistema Operacional Utilizado.", ;
		 "Enviar Email: Atalho para facilitar o envio de email para a SyGeCom Informatica, no caso de Alguma duvida ou Eventual Bug que ocorra na Utilização do SCM.", ;
	"Sobre: Informações Uteis Sobre a SyGeCom Informatica. Empresa que desenvolveu o Sistema SCM, (Sistema de Controle de Mensalidades).", ;
"Sygecom Informatica - www.SyGeComInformatica.com.br", ;
               }

IF n == 0
   oSay:SetValue("")
ELSE
   oSay:SetValue(aText[n])
ENDIF

RETURN Nil
*************************************************************************
FUNCTION RunApplet( cApplet )

// Função: RunApplet
// Esta função recebe como parâmetro o nome do 'applet' e
// utilizando a função ShellExecute, executa o utilitário
// RUNDLL32.EXE para mostrar a opção do Painel de Controle.

// ShellExecute( cFile, cOperation, cParams, cDir, nFlag ) 
// ShellExecute( "rundll32.exe",,"shell32.dll,Control_RunDLL cApplet,,5" )

 ShellExecute("rundll32.exe","open","shell32.dll, Control_RunDLL "+cApplet,"5")
 
RETURN Nil
********************************************************************************

FUNCTION RunApplet_imp( cApplet ) //CONFIGURA IMPRESSORA NO WINDOWS
 ShellExecute("rundll32.exe","open","shell32.dll, SHHelpShortcuts_RunDLL "+cApplet,"2")
RETURN Nil
********************************************************************************

function MY_SHOWMSG()
return nil


function SYG_TRANSLATOR(c1)
return(c1)   
