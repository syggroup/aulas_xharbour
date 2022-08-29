
#define _NO_HWGUI_

#include "scm.ch"

**********************
FUNCTION REL_ASSOCIADO
**********************
SET DELE ON
PARA TIPOREL

DBCLOSEALL()
IF Use_Arq("ASSOCI",,.T.,.T.,.F.)=.F.
   Return
ENDIF

vCONT=LASTREC()

GERAFILE()

SET printer to (cFILE)
SET DEVICE TO PRINT

@ PROW()+1,0 SAY " "

RELASS()

SELE ASSOCI
IF TIPOREL="NOME"
   DBSETORDER(2)
ELSE
   DBSETORDER(1)
ENDIF
DBGOTOP()
DO WHILE .NOT. EOF()
   SELE ASSOCI
   @ prow()+1,01      say "COD.:"
   @ prow(),PCOL()+1  say CODASSOC
   @ prow(),PCOL()+3  say "Nome.:"
   @ prow(),PCOL()+1  say NOME
   @ prow()+1,01      say "End.:"
   @ prow(),PCOL()+1  say ENDE
   @ prow(),PCOL()+3  say "Bairro.:"
   @ prow(),PCOL()+1  say BAIRRO
   @ prow()+1,01      say "Cidade.:"
   @ prow(),PCOL()+1  say CIDADE
   @ prow(),PCOL()+2  say "UF.:"
   @ prow(),PCOL()+1  say UF
   @ prow()+1,01      say "Tel.:"
   @ prow(),PCOL()+1  say TEL
   @ prow(),PCOL()+5  say "Fax.:"
   @ prow(),PCOL()+1  say FAX
   @ prow(),PCOL()+4  say "Tel.:"
   @ prow(),PCOL()+1  say CEL
   @ prow()+1,01      say "CPF.:"
   @ prow(),PCOL()+1  say CPF

   @ PROW()+1,000 SAY REPLICATE("-",79)

   SELE ASSOCI
   DBSKIP(+1)
enddo

   @ PROW()+2,00 SAY "TOTAL DE ASSOCIADOS...:"
   @ prow(),PCOL()+1 SAY vCONT
   @ PROW()+1,000 SAY REPLICATE("=",79)

SET PRINTER TO
set device to screen

EDICAO(cFILE+".PRN")

DBCLOSEALL()
RETURN

*****************
FUNCTION RELASS
*****************
meio=(79-len(xemp))/2
@ 01,meio SAY xemp
@ PROW()+1,000 SAY REPLICATE("=",79)
IF TIPOREL="NOME"
   @ PROW()+1,00     SAY "Relação de Associados Por Ordem de Nome:"
ELSEIF TIPOREL="CODIGO"
   @ PROW()+1,00     SAY "Relação de Associados Por Ordem de Codigo:"
ENDIF
   @ PROW()+1,000 SAY REPLICATE("=",79)
RETURN

********************************************************************************
FUNCTION REL_PARC_GERAL
********************************************************************************
SET DELE ON

PARA TIPOREL

DBCLOSEALL()
IF Use_Arq("MENSAL",,.T.,.T.,.F.)=.F.
   Return
ENDIF

GERAFILE()

SET printer to (cFILE)
SET DEVICE TO PRINT

@ PROW()+1,0 SAY " "

RELPARC()
vCONT=0
   
SELE MENSAL

IF TIPOREL="P"
   Filtro_REC()
ELSEIF TIPOREL="A"
   Filtro_aREC()
ENDIF

DBGOTOP()

DO WHILE .NOT. EOF()
   SELE MENSAL
   @ PROW()+2,01      say  "Cod. Carne:"
   @ PROW(),PCOL()+1  say  CODIGO
   @ PROW(),PCOL()+3  say  "Tipo.:"
   @ PROW(),PCOL()+1  say  TIPO
   @ PROW(),PCOL()+3  say  "Data.:"
   @ PROW(),PCOL()+1  say  DATAEMI
   @ PROW(),PCOL()+3  say  "Hora.:"
   @ PROW(),PCOL()+1  say  HORAEMI
   @ PROW()+2,01      say  "Nome.:"
   @ PROW(),PCOL()+1  say  NOME
   @ PROW()+2,01      say  "Valor Total.:"
   @ PROW(),PCOL()+1  say  "R$"+transform(VLTOTAL,"@e 999,999.99")
   @ PROW()+2,01      say  "N° Parcela.:"
   @ PROW(),PCOL()+1  say  PARCELA    
   @ PROW()+2,01      say  "Data Vencimento.:"
   @ PROW(),PCOL()+1  say  DTVECTO 
   @ PROW(),PCOL()+3  say  "Valor da Parcela.:"
   @ PROW(),PCOL()+1  say  "R$"+transform(VLPARC,"@e 999,999.99")
   @ PROW()+2,01      say  "Banco.:"
   @ PROW(),PCOL()+1  say  BANCO
   @ PROW(),PCOL()+3  say  "Agencia.:"
   @ PROW(),PCOL()+1  say  AGENCIA
   @ PROW(),PCOL()+3  say  "N° Conta.:"
   @ PROW(),PCOL()+1  say  CC
   @ PROW()+2,01      say  "Descrição.:"
   @ PROW(),PCOL()+1  say  DESCRICAO
   @ PROW()+2,00      say  REPLICATE("-",73)
   SELE MENSAL
   DBSKIP(+1)
ENDDO

   @ PROW()+2,00 SAY "TOTAL DE PARCELAS...:"
   @ prow(),PCOL()+1 SAY vCONT
   @ PROW()+1,000 SAY REPLICATE("=",79)

SET PRINTER TO
set device to screen

EDICAO(cFILE+".PRN")

DBCLOSEALL()
RETURN 

*****************
FUNCTION RELPARC
*****************
meio=(79-len(xemp))/2
@ 01,meio SAY xemp
@ PROW()+1,000 SAY REPLICATE("=",79)
IF TIPOREL="P"
   @ PROW()+1,00     SAY "RELAÇÃO DE PARCELAS RECEBIDAS"
ELSEIF TIPOREL="A"
   @ PROW()+1,00     SAY "RELAÇÃO DE PARCELAS À RECEBER"
ENDIF
   @ PROW()+1,000 SAY REPLICATE("=",79)
RETURN

********************************************************************************
FUNCTION REL_PARC_ASSOCI()
********************************************************************************
SET DATE BRIT
SET CENT ON
SET DELE ON

PARA TIPOREL

DBCLOSEALL()

IF Use_Arq("MENSAL",,.T.,.T.,.F.)=.F.
   Return
ENDIF

IF Use_Arq("ASSOCI",,.T.,.T.,.F.)=.F.
   Return
ENDIF

GERAFILE()

SET printer to (cFILE)
SET DEVICE TO PRINT
@ PROW()+1,0 SAY " "

RELPARC()
vCONT=0
   
SELE MENSAL

IF TIPOREL="AP"
   Filtro_AP()
ELSEIF TIPOREL="AA"
   Filtro_AA()
ENDIF

DBGOTOP()

DO WHILE .NOT. EOF()
   SELE MENSAL
   @ PROW()+2,01      say  "Cod. Carne:"
   @ PROW(),PCOL()+1  say  CODIGO
   @ PROW(),PCOL()+3  say  "Tipo.:"
   @ PROW(),PCOL()+1  say  TIPO
   @ PROW(),PCOL()+3  say  "Data.:"
   @ PROW(),PCOL()+1  say  DATAEMI
   @ PROW(),PCOL()+3  say  "Hora.:"
   @ PROW(),PCOL()+1  say  HORAEMI
   @ PROW()+2,01      say  "Nome.:"
   @ PROW(),PCOL()+1  say  NOME
   @ PROW()+2,01      say  "Valor Total.:"
   @ PROW(),PCOL()+1  say  "R$"+transform(VLTOTAL,"@e 999,999.99")
   @ PROW()+2,01      say  "N° Parcela.:"
   @ PROW(),PCOL()+1  say  PARCELA    
   @ PROW()+2,01      say  "Data Vencimento.:"
   @ PROW(),PCOL()+1  say  DTVECTO 
   @ PROW(),PCOL()+3  say  "Valor da Parcela.:"
   @ PROW(),PCOL()+1  say  "R$"+transform(VLPARC,"@e 999,999.99")
   @ PROW()+2,01      say  "Banco.:"
   @ PROW(),PCOL()+1  say  BANCO
   @ PROW(),PCOL()+3  say  "Agencia.:"
   @ PROW(),PCOL()+1  say  AGENCIA
   @ PROW(),PCOL()+3  say  "N° Conta.:"
   @ PROW(),PCOL()+1  say  CC
   @ PROW()+2,01      say  "Descrição.:"
   @ PROW(),PCOL()+1  say  DESCRICAO
   @ PROW()+2,00      say  REPLICATE("-",73)
   SELE MENSAL
   DBSKIP(+1)
ENDDO

   @ PROW()+2,00 SAY "TOTAL DE PARCELAS...:"
   @ prow(),PCOL()+1 SAY Vcont
   @ PROW()+1,000 SAY REPLICATE("=",79)

SET PRINTER TO
set device to screen

EDICAO(cFILE+".PRN")

DBCLOSEALL()
RETURN
********************************************************************************
FUNCTION Filtro_AP()
***********************
SELE MENSAL
dbsetorder(8)
ORDScope(0,Wassociado+"P")
ORDScope(1,Wassociado+"P")
dbgotop()
COUNT FOR SITUACAO="P" TO Vcont
RETURN
***********************
FUNCTION Filtro_AA()
***********************
SELE MENSAL
dbsetorder(8)
ORDScope(0,Wassociado+"A")
ORDScope(1,Wassociado+"A")
dbgotop()
COUNT FOR SITUACAO="A" TO Vcont
RETURN

********************************************************************************
******************
Function Reimprime
******************
SET DELE ON

PARA TIPOREL

GERAFILE()

SET printer to (cFILE)
SET DEVICE TO PRINT

@ PROW()+1,0 SAY " "
@ PROW()+2,00      say  REPLICATE("-",118)
vCONT=0

IF TIPOREL="CARNE"  // QUANDO FOR UM CARNE INTEIRO
   SELE MENSAL
   vCOD=CODIGO
   dbsetorder(10)
   ORDScope(0,Wassociado+STR(vCOD))
   ORDScope(1,Wassociado+STR(vCOD))
   dbgotop()
   COUNT FOR NOME=Wassociado .AND. CODIGO=vCOD TO Vcont
ELSEIF TIPOREL="PARCELA"
   Filtro_reimp()
ENDIF

DBGOTOP()

DO WHILE .NOT. EOF()
   @ PROW()+2,01      say  "Cod. Carne.:  |"
   @ PROW(),PCOL()+3  say  "Cod. Carne:"
   @ PROW(),PCOL()+3  say  CODIGO
   @ PROW(),PCOL()+3  say  "N° Parcela.:"
   @ PROW(),PCOL()+1  say  PARCELA  
   @ PROW(),PCOL()+3  say  "Data de Emissão.:"
   @ PROW(),PCOL()+1  say  DATAEMI
   @ PROW(),PCOL()+3  say  "Hora de Emissão.:"
   @ PROW(),PCOL()+1  say  HORAEMI   
     @ PROW()+1,01      say  CODIGO
   @ PROW(),PCOL()+8  SAY  "|"
   
   @ PROW()+1,01      say  "N° Parcela.:  |"
   @ PROW(),PCOL()+3  say  "Nome.:"
   @ PROW(),PCOL()+1  say  NOME
   @ PROW()+1,01      say  PARCELA
   @ PROW(),PCOL()+11 SAY  "|"

   @ PROW()+1,01      say  "Valor Total:  |"
   @ PROW(),PCOL()+3  say  "Valor Total:"
   @ PROW(),PCOL()+1  say  "R$"+transform(VLTOTAL,"@e 999,999.99")
   @ PROW(),PCOL()+3  say  "Data Vencimento.:"
   @ PROW(),PCOL()+1  say  DTVECTO 
   @ PROW(),PCOL()+3  say  "Valor da Parcela.:"
   @ PROW(),PCOL()+1  say  "R$"+transform(VLPARC,"@e 999,999.99")
   @ PROW()+1,01      say  "R$"+transform(VLTOTAL,"@e 999,999.99")
   @ PROW(),PCOL()+2  say  "|"

   @ PROW()+1,01      say  "Vl Parcela.:  |"
   @ PROW(),PCOL()+3  say  "Banco.:"
   @ PROW(),PCOL()+1  say  BANCO
   @ PROW(),PCOL()+3  say  "Agencia.:"
   @ PROW(),PCOL()+1  say  AGENCIA
   @ PROW(),PCOL()+3  say  "N° Conta.:"
   @ PROW(),PCOL()+1  say  CC
   @ PROW()+1,01      say  "R$"+transform(VLPARC,"@e 999,999.99")
   @ PROW(),PCOL()+2  say  "|"

   @ PROW()+1,01      say  "Data Venc..:  |"
     @ PROW(),PCOL()+3  say  "Descrição.:"
   @ PROW(),PCOL()+1  say  DESCRICAO
   @ PROW()+1,01      say  DTVECTO 
   @ PROW(),PCOL()+4  SAY  "|"

   @ PROW()+2,00      say  REPLICATE("-",118)
   DBSKIP(+1)
ENDDO

SET PRINTER TO
set device to screen

EDICAO(cFILE+".PRN")

DBCLOSEALL()
RETURN  

********************************************************************************
FUNCTION REL_REUNIAO    //Relatório de Prestação de Contas Mensais para Reunião de Diretoria
********************************************************************************
PRIVATE vTOTALPG :=0, VLTOTAL:=0, VLTOTALAPG:=0
PRIVATE vSOMAPG :=0, vSOMAAPG:=0
PRIVATE vNOME :=""

SET DELE ON

DBCLOSEALL()

IF Use_Arq("MENSAL",,.T.,.T.,.F.)=.F.
   Return
ENDIF

SELE MENSAL
GERAFILE()
private aField[1]
aField[01] := {"COD" , "n", 6,  0}
DBcreate(cFILE, aField)

SELECT 2
USE (cFILE) ALIAS Temporario EXCL
INDEX on COD tag 1 to (cFILE)
DBSETINDEX(cFILE)

SELE MENSAL
DBGOTOP()
DO WHILE !eof()
   vCOD = CODASS

   SELE Temporario
   DBSEEK (vCOD)
   IF !FOUND()
      APPEND BLANK
      REPLACE COD WITH vCOD
   ENDIF

   SELE MENSAL
   DBSKIP()
ENDDO

GERAFILE()

SET printer to (cFILE)
SET DEVICE TO PRINT

@ PROW()+1,0 SAY " "

RELREUNI()

SELE Temporario
DBGOTOP()
DO WHILE !eof()
   vTOTALPG=0
   vTOTALAPG=0
   vCOD2 = COD

   SELE MENSAL
   DBSETORDER (11)
   ORDScope(0, vCOD2+wData)
   ORDScope(1, vCOD2+wData1)
   SUM ALL VLPARC TO vTOTAL FOR CODASS = vCOD2                    //Valor Total
   SUM ALL VLRPGTO TO vTOTALPG FOR SITUACAO="P" .and. CODASS = vCOD2//Valor total Pago
   vTOTALAPG := vTOTAL - vTOTALPG               //Valor restante a pagar

   DBSETORDER(12)
   DBSEEK(vCOD2)
   IF FOUND()
      vNOME = NOME
   ENDIF

   @ prow()+1,01      SAY "Nome.:"
   @ prow(),PCOL()+1  SAY vNOME
   @ prow()+1,01      SAY "Valor Pago.:"
   @ prow(),PCOL()+1  SAY "R$"+transform(vTOTALPG,"@e 999,999.99")
   @ prow(),PCOL()+3  SAY "Valor a Pagar.:"
   @ prow(),PCOL()+1  SAY "R$"+transform(vTOTALAPG,"@e 999,999.99")

   @ PROW()+1,000 SAY REPLICATE("_",79)

   vSOMAPG  := vSOMAPG + vTOTALPG
   vSOMAAPG := vSOMAAPG + vTOTALAPG

   ORDScope(0, NIL)
   ORDScope(1, NIL)

   SELE  Temporario
   DBSKIP()
ENDDO

   @ PROW()+2,00 SAY "TOTAL RECEBIDO....:"
   @ prow(),PCOL()+1  say "R$"+transform(vSOMAPG,"@e 999,999.99")
   @ PROW()+1,00 SAY "TOTAL A RECEBER...:"
   @ prow(),PCOL()+1  say "R$"+transform(vSOMAAPG,"@e 999,999.99")
   @ PROW()+1,000 SAY REPLICATE("=",79)

SET PRINTER TO
set device to screen

EDICAO(cFILE+".PRN")

DBCLOSEALL()
RETURN


*****************
FUNCTION RELREUNI
*****************
meio=(79-len(xemp))/2
@ 01,meio SAY xemp
@ PROW()+1,000 SAY REPLICATE("=",79)
@ PROW()+1,000 SAY "RELATORIO DE PRESTAÇÃO DE CONTAS MENSAIS PARA REUNIÃO DA DIRETORIA"
@ PROW()+1,000 SAY REPLICATE("=",79)
RETURN
