#include "scm.ch"

*******************************************
Function NAVEGAR(cTITULO,vALIAS,vTIPO_PESQ)
*******************************************
LOCAL oFrm, oFont
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

PREPARE FONT oFontBtn NAME "Arial" WIDTH 0 HEIGHT -12 WEIGHT 400
        INIT DIALOG oFrm CLIPPER NOEXIT TITLE cTitulo FONT oFontBtn;
        AT 0,0;
        SIZE HWG_GETDESKTOPWIDTH()-200,HWG_GETDESKTOPHEIGHT()-200 ;
        ICON oIcon ;
        STYLE DS_CENTER + WS_VISIBLE + WS_CAPTION + WS_SYSMENU
                   

@ 10,40 BROWSE oBrw DATABASE OF oFrm SIZE HWG_GETDESKTOPWIDTH()-220, HWG_GETDESKTOPHEIGHT()-250  ;
        STYLE  WS_VSCROLL + WS_HSCROLL;
        MULTISELECT;
        ON CLICK {|o,key| BrowseKey(o, key,vALIAS ) }

oBrw:alias := aLIAS()

oBrw:bKeyDown := {|o,key| BrowseKey(o, key, vALIAS ) }
@ 5,10 say "F1 - Sobre  / F2 - Busca  / F4 - Muda Ordem  / F5 - Gera Excel  / F9 - Calculadora" size HWG_GETDESKTOPWIDTH()-250,20;
STYLE SS_CENTER COLOR x_BLUE

IF vTIPO_PESQ="PESQ_MENSAL"
   oBrw:AddColumn( HColumn():New( "Cod Nº",            FieldBlock(Fieldname(1)), "N",  6,0) )
   oBrw:AddColumn( HColumn():New( "Parc",                            FieldBlock(Fieldname(2)), "N",  3,0) )
   oBrw:AddColumn( HColumn():New( "Data Emisão",       FieldBlock(Fieldname(3)), "D", 10,0) )
   oBrw:AddColumn( HColumn():New( "Nome Associado",                  FieldBlock(Fieldname(7)), "C", 50,0) )
   oBrw:AddColumn( HColumn():New( "Valor Parcela R$:",               FieldBlock(Fieldname(8)), "N", 10,2) )
   oBrw:AddColumn( HColumn():New( "Data Vencimento",                 FieldBlock(Fieldname(09)),"D", 10,0) )
   oBrw:AddColumn( HColumn():New( "Valor Pago R$:",                  FieldBlock(Fieldname(10)),"N", 10,2) )
   oBrw:AddColumn( HColumn():New( "Data Pgto.",                      FieldBlock(Fieldname(11)),"D", 10,0) )
   oBrw:AddColumn( HColumn():New( "Valor Total R$:",                 FieldBlock(Fieldname(12)),"N", 10,2) )
   oBrw:AddColumn( HColumn():New( "Tipo",                            FieldBlock(Fieldname(14)),"C",  6,0) )
   oBrw:AddColumn( HColumn():New( "Banco",                           FieldBlock(Fieldname(16)),"C", 31,0) )

   oBrw:aColumns[4]:length := 50  // TAMANHO                  
   oBrw:aColumns[10]:length := 6  // TAMANHO

   oBrw:Freeze:=1                 // congela

   oBrw:aColumns[5]:picture:="@R 999,999,999.99"
   oBrw:aColumns[7]:picture:="@R 999,999,999.99"
   oBrw:aColumns[9]:picture:="@R 999,999,999.99"

   WriteStatus( oTelaPrincipal,3,"Pequisa de Mensalidade" )
   
ELSEIF vTIPO_PESQ="PESQ_BANCO"
   oBrw:AddColumn( HColumn():New( "Cod Caixa\Banco",   FieldBlock(Fieldname(1)), "N",  2,0) )
   oBrw:AddColumn( HColumn():New( "Descrição",         FieldBlock(Fieldname(2)), "C", 31,0) )
   oBrw:AddColumn( HColumn():New( "Agencia",                         FieldBlock(Fieldname(3)), "C",  5,0) )
   oBrw:AddColumn( HColumn():New( "Cont.Corr.",        FieldBlock(Fieldname(4)), "C", 12,0) )
   oBrw:AddColumn( HColumn():New( "Gerente",                         FieldBlock(Fieldname(16)), "C",29,0) )
   oBrw:AddColumn( HColumn():New( "CGC",                             FieldBlock(Fieldname(17)), "C",18,0) )
   oBrw:AddColumn( HColumn():New( "Data",                            FieldBlock(Fieldname(26)), "D", 8,0) )
   oBrw:AddColumn( HColumn():New( "Saldo Atual",                     FieldBlock(Fieldname(23)), "N",10,2) )

   oBrw:aColumns[2]:length := 31  // TAMANHO
   oBrw:aColumns[5]:length := 29  // TAMANHO

   oBrw:Freeze:=1                 // congela

   oBrw:aColumns[7]:picture:="@D 99/99/99"
   oBrw:aColumns[8]:picture:="@e R$ 999,999,999.99"

   WriteStatus( oTelaPrincipal,3,"Pesquisa de Banco" )

ENDIF

oFrm:Activate()
   WriteStatus( oTelaPrincipal,3,"Area de Trabalho" )

RETURN

********************************************************************************
FUNCTION BrowseKey( oBrowse, key, vALIAS)
********************************************************************************
DO CASE
   CASE KEY= VK_ESCAPE
        EndDialog()
   CASE KEY = VK_RETURN
        EndDialog()
   CASE KEY = 1
        EndDialog()
   CASE KEY = VK_F1
        Sobre()
   CASE KEY = VK_F2
        BUSCA_NOME()
   CASE KEY = VK_F4
        Lista_ordem()
   CASE KEY = VK_F5
        Gera_Excel(vALIAS)
   CASE KEY = VK_F9
        ShellExecute("calc")
   OTHERWISE
ENDCASE
RETURN .T.
********************************************************************************
*************************
FUNCTION BUSCA_NOME(oPos)
*************************
nCHAVES := LEN(aCHAVES)
IF nCHAVES <= 1
   MSGINFO("Nao há outras ordens ou chaves De Indice Ativa para fazer Busca nesse Arquivo","Aviso do Sistema")
ELSE
   PRIVATE oFrm2,chave
   PRIVATE vchave:=""
   vchave:=Space(20)

   INIT DIALOG oFrm2 CLIPPER NOEXIT TITLE "Busca Pelo Campo Indexado";
   SIZE 600,130;
   STYLE DS_CENTER + WS_VISIBLE

   @  5,10 SAY "Busca.:" size 580,25
   @  5,30 GET Chave VAR vchave PICTURE "@!" VALID {|| Focaliza()} SIZE 580,25; // STYLE WS_BORDER;
   TOOLTIP "Informe o Nome que Deseja Buscar"

   @   5,70 BUTTON btnOk CAPTION "Pesquisar";
   ON CLICK { || DBSEEK( UPPER(Chave:setGet()), .t. ) , oBrw:Refresh(), EndDialog() };
   SIZE 100,25 STYLE WS_TABSTOP;
   TOOLTIP "Confirma a Busca"

   @ 150,70 BUTTON "Fechar";
   ON CLICK {||EndDialog()};
   SIZE 100,25;
   TOOLTIP "Fechar Janela"

   ACTIVATE DIALOG oFrm2
ENDIF
RETURN .T.

**********************
FUNCTION Lista_ordem()
**********************
LOCAL oFrm3
nCHAVES := LEN(aCHAVES)
IF nCHAVES <= 1
   MSGINFO("Nao há outras ordes ou chaves De Indice Ativa de pesquisa para este Arquivo","Aviso do Sistema")
ELSE
   nOLD := INDEXORD()
   nORDEM := WChoice( aCHAVES, "Seleciona Ordem", 05+nCHAVES, 100+nMAXLEN, ,,,, )
   IF nORDEM > 0 .AND. nOLD # nORDEM
      DBSETORDER(nORDEM)
   ENDIF
ENDIF
dbGoTop()
oBrw:Refresh()
RETURN

********************************************************************************
FUNCTION NAVEGAR2(vMESSGG,vTIPO_PESQ)// Browse Tela menor...pesquisas pequenas
********************************************************************************
***                   FERRAMENTAS DE MULTI-PESQUISA AUTOMATICA               ***
aCHAVES := {}
nORD    := INDEXORD()
nCNT    := 1
nMAXLEN := 0
IF nORD # 0
   DO WHILE .T.
      IF !EMPTY( INDEXKEY(nCNT) )
         aADD(aCHAVES, " "+INDEXKEY(nCNT)+" ")
         nCNT++
      ELSE
         EXIT
      ENDIF
   ENDDO
   aEVAL(aCHAVES, {|cV,nV| IF( LEN( aCHAVES[nV] ) > nMAXLEN,;
                   nMAXLEN := LEN( aCHAVES[nV] ), NIL ) })
ENDIF
DBSETORDER(nORD)         

@ 10,220 BROWSE oBrw DATABASE OF oCadmensal SIZE 250,400  ;
        STYLE  WS_VSCROLL + WS_HSCROLL;
        ON CLICK {|o,key| BrowseKey(o, key ) }
           
oBrw:alias := aLIAS()

oBrw:bKeyDown := {|o,key| BrowseKey(o, key ) }

@ 20,190 say "F2 - Busca  / F4 - Muda Ordem" size 80,20;
STYLE SS_CENTER COLOR x_BLUE

PREPARE FONT oFont NAME "Arial" WIDTH 0 HEIGHT -16

IF vTIPO_PESQ="PESQ_MENSAL2"

   oBrw:AddColumn( HColumn():New( "Codigo",               FieldBlock(Fieldname(01)),"N",  6,0) )
   oBrw:AddColumn( HColumn():New( "Parcela",              FieldBlock(Fieldname(02)),"N",  3,0) )
   oBrw:AddColumn( HColumn():New( "Data Emição",          FieldBlock(Fieldname(03)),"D",  8,0) )
   oBrw:AddColumn( HColumn():New( "Hora Emição",          FieldBlock(Fieldname(04)),"C",  8,0) )
   oBrw:AddColumn( HColumn():New( "Nome",                 FieldBlock(Fieldname(06)),"C", 50,0) )
   oBrw:AddColumn( HColumn():New( "Valor da parcela",     FieldBlock(Fieldname(07)),"N", 10,2) )
   oBrw:AddColumn( HColumn():New( "Data do Vecto",        FieldBlock(Fieldname(08)),"D",  8,0) )
   oBrw:AddColumn( HColumn():New( "Valor Pago",           FieldBlock(Fieldname(09)),"N", 10,2) )
   oBrw:AddColumn( HColumn():New( "Data do Pagamento",    FieldBlock(Fieldname(10)),"D",  8,0) )
   oBrw:AddColumn( HColumn():New( "Valor Total",          FieldBlock(Fieldname(11)),"N", 10,2) )
   oBrw:AddColumn( HColumn():New( "Tipo(carne/Avulso)",   FieldBlock(Fieldname(13)),"C",  6,0) )

   oBrw:aColumns[3]:picture:= "@D 99/99/9999"      //MASCARA
   oBrw:aColumns[4]:picture:= "@R 99:99:99"        //MASCARA   
   oBrw:aColumns[6]:picture:= "@E 999,999,999.99"  //MASCARA
   oBrw:aColumns[7]:picture:= "@D 99/99/9999"      //MASCARA
   oBrw:aColumns[8]:picture:= "@E 999,999,999.99"  //MASCARA
   oBrw:aColumns[9]:picture:= "@D 99/99/9999"      //MASCARA
   oBrw:aColumns[10]:picture:="@E 999,999,999.99"  //MASCARA

   FOR nI := 1 TO 11
       oBrw:aColumns[nI]:nJusHead := DT_CENTER    //CENTRALIZA NO NOME DO CAMPO
       oBrw:aColumns[nI]:nJusLin  := DT_LEFT      //COLOCA PARA DIREITA A LINHA
   NEXT
   oBrw:aColumns[1]:length := 6       // TAMANHO
   oBrw:aColumns[2]:length := 3       // TAMANHO
   oBrw:aColumns[3]:length := 8       // TAMANHO   
   oBrw:aColumns[4]:length := 8       // TAMANHO   
   oBrw:aColumns[5]:length := 50      // TAMANHO 
   oBrw:aColumns[6]:length := 10      // TAMANHO   
   oBrw:aColumns[7]:length := 10      // TAMANHO
   oBrw:aColumns[8]:length := 10      // TAMANHO
   oBrw:aColumns[9]:length := 8       // TAMANHO
   oBrw:aColumns[10]:length := 10     // TAMANHO
   oBrw:aColumns[11]:length := 6      // TAMANHO                 
ENDIF

RETURN NIL

***************************
Function Pesquisa_Associado
***************************
LOCAL oFrm, oFont
Private gPes,vPes:="",keyAnt:=0
PRIVATE oIcon := HIcon():AddResource(1004)
PRIVATE oRadio1,oRadio2,oRadio3,oRadio4,r1 := 1

Dbcloseall()

IF Use_Arq("ASSOCI",,.T.,.F.,.F.)=.F.
   Return
ENDIF

IF Use_Arq("FUNCAO",,.T.,.F.,.F.)=.F.
   Return
ENDIF

SELE ASSOCI
DBGOTOP()
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

PREPARE FONT oFontBtn NAME "Arial" WIDTH 0 HEIGHT -12 WEIGHT 400
        INIT DIALOG oFrm CLIPPER NOEXIT TITLE "Pesquisa de Associação" FONT oFontBtn;
        AT 0,0;
        SIZE HWG_GETDESKTOPWIDTH(),HWG_GETDESKTOPHEIGHT()-28 ;
        ICON oIcon ;
        STYLE DS_CENTER + WS_VISIBLE + WS_CAPTION + WS_SYSMENU

@ 10,40 BROWSE oBrw DATABASE OF oFrm SIZE HWG_GETDESKTOPWIDTH()-30, HWG_GETDESKTOPHEIGHT()-250  ;
        STYLE  WS_VSCROLL + WS_HSCROLL;
        MULTISELECT;
        ON CLICK {|o,key| Cad_Associado("A"),DbSetOrder(2),oBrw:SetFocus(),oBrw:Refresh() };
        ON POSCHANGE {|| SetFocus(oBrw:handle ) }

oBrw:alias := aLIAS()

oBrw:bKeyDown := {|o,key| BrowseKey_Ass(o, key ) }
@ 5,10 say "F1 - Sobre  / F2 - Busca  / F4 - Muda Ordem  / F9 - Calculadora" size HWG_GETDESKTOPWIDTH()-250,20;
STYLE SS_CENTER COLOR x_BLUE

@ 15,HWG_GETDESKTOPHEIGHT()-100 BUTTON "&Incluir Novo" SIZE 120, 28 ;
TOOLTIP "Cadastrar um Novo Associado";
ON CLICK {|| Cad_Associado("C","N"),oBrw:Refresh() }

@ 160,HWG_GETDESKTOPHEIGHT()-100 BUTTON "&Alterar" SIZE 120, 28 ;
TOOLTIP "Alterar Fornecedor";
ON CLICK {|| Cad_Associado("A"),oBrw:Refresh() }

GET RADIOGROUP r1
@ 15,HWG_GETDESKTOPHEIGHT()-150 RADIOBUTTON oRadio1 caption "Ordem de Codigo";
SIZE 140, 22;
TOOLTIP "Escolha essa Opção para Ordenar a Pesquisa por Ordem de Codigo";
ON CLICK {|| DbsetOrder(1),oBrw:SetFocus(),oBrw:Refresh() };
COLOR x_BLUE

@ 160,HWG_GETDESKTOPHEIGHT()-150 RADIOBUTTON oRadio2 caption "Ordem de Nome";
SIZE 180, 22;
TOOLTIP "Escolha essa Opção para Ordenar a Pesquisa por Ordem de Nome";
ON CLICK {|| DbsetOrder(2),oBrw:SetFocus(),oBrw:Refresh() };
COLOR x_BLUE

@ 325,HWG_GETDESKTOPHEIGHT()-150 RADIOBUTTON oRadio3 caption "Ordem de Cidade";
SIZE 210, 22;
TOOLTIP "Escolha essa Opção para Ordenar a Pesquisa por Ordem de Cidade";
ON CLICK {|| DbsetOrder(3),oBrw:SetFocus(),oBrw:Refresh() };
COLOR x_BLUE

@ 525,HWG_GETDESKTOPHEIGHT()-150 RADIOBUTTON oRadio4 caption "Ordem de Valor";
SIZE 170, 22;
TOOLTIP "Escolha essa Opção para Ordenar a Pesquisa por Ordem de Valor";
ON CLICK {|| DbsetOrder(4),oBrw:SetFocus(),oBrw:Refresh() };
COLOR x_BLUE

END RADIOGROUP

oBrw:AddColumn( HColumn():New( "Cod Nº",                 FieldBlock(Fieldname(1)), "N",  5,0,,,,,,,,,{|| dbsetorder(1),DbGoTop(),oBrw:Refresh()}) )
oBrw:AddColumn( HColumn():New( "Nome",                   FieldBlock(Fieldname(2)), "C", 50,0,,,,,,,,,{|| dbsetorder(2),DbGoTop(),oBrw:Refresh()}) )
oBrw:AddColumn( HColumn():New( "Telefone",               FieldBlock(Fieldname(13)), "C", 12,0) )
oBrw:AddColumn( HColumn():New( "Fax",                    FieldBlock(Fieldname(14)),"C", 12,0) )
oBrw:AddColumn( HColumn():New( "Celular",                FieldBlock(Fieldname(15)),"C", 12,0) )
oBrw:AddColumn( HColumn():New( "Endereço",               FieldBlock(Fieldname(3)), "C", 50,0) )
oBrw:AddColumn( HColumn():New( "Bairro",                 FieldBlock(Fieldname(4)), "C", 20,0) )
oBrw:AddColumn( HColumn():New( "Cidade",                 FieldBlock(Fieldname(5)), "C", 20,0,,,,,,,,,{|| dbsetorder(3),DbGoTop(),oBrw:Refresh()}) )
oBrw:AddColumn( HColumn():New( "UF",                     FieldBlock(Fieldname(6)), "C",  2,0) )
oBrw:AddColumn( HColumn():New( "Cep",                    FieldBlock(Fieldname(7)), "C", 14,0) )
oBrw:AddColumn( HColumn():New( "J/F",                    FieldBlock(Fieldname(8)), "C",  1,0) )
oBrw:AddColumn( HColumn():New( "CPF",                    FieldBlock(Fieldname(9)), "C", 14,0) )
oBrw:AddColumn( HColumn():New( "RG",                     FieldBlock(Fieldname(10)),"C", 12,0) )
oBrw:AddColumn( HColumn():New( "CNPJ",                   FieldBlock(Fieldname(11)),"C", 18,0) )
oBrw:AddColumn( HColumn():New( "IE",                     FieldBlock(Fieldname(12)),"C", 15,0) )
oBrw:AddColumn( HColumn():New( "Função 01",              FieldBlock(Fieldname(17)),"C", 40,0) )
oBrw:AddColumn( HColumn():New( "Função 02",              FieldBlock(Fieldname(18)),"C", 40,0) )
oBrw:AddColumn( HColumn():New( "Email",                  FieldBlock(Fieldname(16)),"C", 50,0) )
oBrw:AddColumn( HColumn():New( "Site",                   FieldBlock(Fieldname(21)),"C", 60,0) )

oBrw:aColumns[2]:length := 50  // TAMANHO
oBrw:aColumns[6]:length := 50  // TAMANHO
oBrw:aColumns[7]:length := 20  // TAMANHO
oBrw:aColumns[8]:length := 20  // TAMANHO
oBrw:aColumns[16]:length := 40 // TAMANHO
oBrw:aColumns[17]:length := 40 // TAMANHO
oBrw:aColumns[18]:length := 50 // TAMANHO
oBrw:aColumns[19]:length := 60 // TAMANHO

oBrw:Freeze:=1                 // congela

oBrw:aColumns[3]:picture:="@R (99)9999-9999"
oBrw:aColumns[4]:picture:="@R (99)9999-9999"
oBrw:aColumns[5]:picture:="@R (99)9999-9999"

oBrw:aColumns[10]:picture:="@R !!.!!!-!!!"             //MASCARA
oBrw:aColumns[12]:picture:="@r !!!.!!!.!!!-!!"         //MASCARA
oBrw:aColumns[14]:picture:="@R !!.!!!.!!!/!!!!-!!"


WriteStatus( oTelaPrincipal,3,"Pesquisa de Associado" )

oFrm:Activate()

WriteStatus( oTelaPrincipal,3,"Area de Trabalho" )

RETURN

********************************************************************************
FUNCTION BrowseKey_Ass( oBrowse, key, vALIAS)
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
ENDCASE
RETURN(.T.)
