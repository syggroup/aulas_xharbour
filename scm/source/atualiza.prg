#include "scm.ch"

*****************
Function ATUALSIS
*****************
vINDEXA="N"

IF IsDirectory( "dados" ) = .F.
   Makedir("dados")
ENDIF

IF IsDirectory( GETENV("temp") + "\sy_temp" )=.F.
   Makedir( GETENV("temp") + "\sy_temp")
ENDIF

IF !My_File("envia_email.exe") .or. !My_File("ie32.dll") .or. !My_File("blat.dll")
   IF MsgYesNo("Estão Faltando Arquivos para Iniciar o Sistema, Deseja Baixar as Dependencias Agora ?","Aviso do Sistema")
      DBCLOSEALL()
      fclose(janela2)
      fclose(arq)
      ferase(arq)
      Baixa_Arq(.T.)
      WinExec(NomeExecutavel()+" 2",.T.)
      __Quit()
   ELSE
      Erro_Atualizando()
   ENDIF
ENDIF
/*
IF !MY_FILE("TESTE.DBF")
   DBCreate( eCAMINHO_DADOS+"TESTE", {;
   { "CAMPOC",  "C",30, 0 },;
   { "CAMPON1", "N", 9, 0 },;
   { "CAMPON2", "N",12, 2 },;
   { "CAMPOD",  "D", 8, 0 },;
   { "CAMPOL",  "L", 1, 0 },;
   { "CAMPOM",  "M",10, 0 },;
   { "CAMPOC_NOME_LONGO_",'C',255, 0 },;
   { "CAMPOC_NOME_SUPER_LONGO_",'C',1000, 0 },;
   { "CAMPON_VARIOS_DECIMAL", "N",29, 9 } } )
   DBCLOSEALL()
   vINDEXA="S"
ENDIF
*/
IF !MY_FILE("INSTITUI.DBF")
   IF !MsgYESNO("Atenção !!! Para Continuar com essa Atualização Ninguem Pode esta Usando o Sistema...(Criação da Tabela Instituição).......Deseja Continuar ?...","Aviso do Sistema")
      DBCLOSEALL()
      SAIR2()
   ELSE
      private aField[19]
      aField[01] := {"NOME"   , "C", 50,  0}
      aField[02] := {"ENDE"   , "C", 50,  0}
      aField[03] := {"TEL"    , "C", 12,  0}
      aField[04] := {"BANCO"  , "C", 20,  0}
      aField[05] := {"AGENCIA", "C", 10,  0}
      aField[06] := {"CONTA"  , "C", 10,  0}
      aField[07] := {"BAIRRO" , "C", 20,  0}
      aField[08] := {"CIDADE" , "C", 20,  0}
      aField[09] := {"CEP"    , "C",  9,  0}
      aField[10] := {"UF"     , "C",  2,  0}
      aField[11] := {"FAX"    , "C", 12,  0}
      aField[12] := {"CEL"    , "C", 12,  0}
      aField[13] := {"CNPJ"   , "C", 18,  0}
      aField[14] := {"IE"     , "C", 15,  0}
      aField[15] := {"EMAIL"  , "C", 60,  0}
      aField[16] := {"SITE"   , "C", 60,  0}
      aField[17] := {"USUARIO", "C", 60,  0}
      aField[18] := {"SERVER" , "C", 60,  0}
      aField[19] := {"SENHA"  , "C", 60,  0}
      DBcreate(eCAMINHO_DADOS+"INSTITUI", aField)

      DBCLOSEALL()
      vINDEXA="S"
   ENDIF
ENDIF

IF !MY_FILE("ASSOCI.DBF")
   IF !MsgYESNO("Atenção !!! Para Continuar com essa Atualização Ninguem Pode esta Usando o Sistema...(Criação da Tabela Associado).......Deseja Continuar ?...","Aviso do Sistema")
      DBCLOSEALL()
      SAIR2()
   ELSE
      private aField[21]
      aField[01] := {"CODASSOC", "N",  6,  0}
      aField[02] := {"NOME"    , "C", 50,  0}
      aField[03] := {"ENDE"    , "C", 50,  0}
      aField[04] := {"BAIRRO"  , "C", 20,  0}
      aField[05] := {"CIDADE"  , "C", 20,  0}
      aField[06] := {"UF"      , "C",  2,  0}
      aField[07] := {"CEP"     , "C", 14,  0}
      aField[08] := {"TIPOJF"  , "C",  1,  0}
      aField[09] := {"CPF"     , "C", 14,  0}
      aField[10] := {"RG"      , "C", 12,  0}
      aField[11] := {"CNPJ"    , "C", 18,  0}
      aField[12] := {"IE"      , "C", 15,  0}
      aField[13] := {"TEL"     , "C", 12,  0}
      aField[14] := {"FAX"     , "C", 12,  0}
      aField[15] := {"CEL"     , "C", 12,  0}
      aField[16] := {"EMAIL"   , "C", 50,  0}
      aField[17] := {"FUNCAO1" , "C", 40,  0}
      aField[18] := {"FUNCAO2" , "C", 40,  0}
      aField[19] := {"VALOR"   , "N", 12,  2}
      aField[20] := {"VENC"    , "D",  8,  0}
      aField[21] := {"SITE"    , "C", 60,  0}
      DBcreate(eCAMINHO_DADOS+"ASSOCI", aField)
      DBCLOSEALL()

      vINDEXA="S"
   ENDIF
ENDIF

IF !MY_FILE("BANCO.DBF")
   IF !MsgYESNO("Atenção !!! Para Continuar com essa Atualização Ninguem Pode esta Usando o Sistema...(Criação da Tabela Banco).......Deseja Continuar ?...","Aviso do Sistema")
      DBCLOSEALL()
      SAIR2()
   ELSE
      private aField[28]
      aField[01] := {"CODCXA"    , "N",  2,  0}
      aField[02] := {"DESCRICAO" , "C", 40,  0}
      aField[03] := {"AGENCIA"   , "C", 15,  0}
      aField[04] := {"CC"        , "C", 15,  0}
      aField[05] := {"EMAIL"     , "C", 40,  0}
      aField[06] := {"RUA"       , "C", 47,  0}
      aField[07] := {"COMPLEM"   , "C", 10,  0}
      aField[08] := {"CIDADE"    , "C", 20,  0}
      aField[09] := {"UF"        , "C",  2,  0}
      aField[10] := {"CEP"       , "C",  9,  0}
      aField[11] := {"BAIRRO"    , "C", 19,  0}
      aField[12] := {"CEL"       , "C", 13,  0}
      aField[13] := {"TEL"       , "C", 13,  0}
      aField[14] := {"FAX"       , "C", 13,  0}
      aField[15] := {"OBS"       , "C", 68,  0}
      aField[16] := {"GERENTE"   , "C", 29,  0}
      aField[17] := {"CGC"       , "C", 18,  0}
      aField[18] := {"INSCEST"   , "C", 15,  0}
      aField[19] := {"SALDOINI"  , "N", 12,  2}
      aField[20] := {"SALDOANT"  , "N", 12,  2}
      aField[21] := {"TOTENT"    , "N", 12,  2}
      aField[22] := {"TOTSAI"    , "N", 12,  2}
      aField[23] := {"SALDOATUAL", "N", 10,  2}
      aField[24] := {"DATAINI"   , "D",  8,  0}
      aField[25] := {"DATAFIM"   , "D",  8,  0}
      aField[26] := {"DATA"      , "D",  8,  0}
      aField[27] := {"COD_BC"    , "C",  3,  0}
      aField[28] := {"CARTEIRA"  , "C",  5,  0}
      DBcreate(eCAMINHO_DADOS+"BANCO", aField)
      DBCLOSEALL()

      IF Use_Arq("BANCO",,.T.,.F.,.F.)=.F.  // COMPARTILHADO
         Return
      ENDIF

      SELE BANCO
      DBAPPEND()
      REPL CODCXA    WITH 1
      REPL DESCRICAO WITH "CAIXA DINHEIRO"
      DBCOMMIT()
      LIBERAREG()
      
      vINDEXA="S"
   ENDIF
ENDIF

IF !MY_FILE("FUNCAO.DBF")
   IF !MsgYESNO("Atenção !!! Para Continuar com essa Atualização Ninguem Pode esta Usando o Sistema...(Criação da Tabela Função).......Deseja Continuar ?...","Aviso do Sistema")
      DBCLOSEALL()
      SAIR2()
   ELSE
      private aField[2]
      aField[1] := {"COD"   , "N",  6,  0}
      aField[2] := {"FUNCAO", "C", 40,  0}
      DBcreate(eCAMINHO_DADOS+"FUNCAO", aField)
      DBCLOSEALL()

      IF Use_Arq("FUNCAO",,.T.,.F.,.F.)=.F.  // COMPARTILHADO
         Return
      ENDIF

      SELE FUNCAO
      DBAPPEND()                            
      REPL COD WITH 1,;
      FUNCAO   WITH "Nenhuma"

      DBAPPEND()
      REPL COD WITH 2,;
      FUNCAO   WITH "Diretoria"

      DBCOMMITALL()
      dbcloseall()
      vINDEXA="S"
   ENDIF
ENDIF

IF !MY_FILE("MENSAL.DBF")
   IF !MsgYESNO("Atenção !!! Para Continuar com essa Atualização Ninguem Pode esta Usando o Sistema...(Criação da Tabela Mensalidade).......Deseja Continuar ?...","Aviso do Sistema")
      DBCLOSEALL()
      SAIR2()
   ELSE                    
      private aField[23]
      aField[01] := {"CODIGO"   , "N",  6,  0}
      aField[02] := {"PARCELA"  , "N",  3,  0}
      aField[03] := {"DATAEMI"  , "D",  8,  0}
      aField[04] := {"HORAEMI"  , "C",  8,  0}
      aField[05] := {"PRAZO"    , "N",  3,  0}
      aField[06] := {"CODASS"   , "N",  5,  0}
      aField[07] := {"NOME"     , "C", 50,  0}
      aField[08] := {"VLPARC"   , "N", 16,  2}
      aField[09] := {"DTVECTO"  , "D",  8,  0}
      aField[10] := {"VLRPGTO"  , "N", 10,  2}
      aField[11] := {"DTPGTO"   , "D",  8,  0}
      aField[12] := {"VLTOTAL"  , "N", 16,  2}
      aField[13] := {"DESCRICAO", "C", 50,  0}
      aField[14] := {"TIPO"     , "C",  6,  0}
      aField[15] := {"SITUACAO" , "C",  1,  0}
      aField[16] := {"BANCO"    , "C", 40,  0}
      aField[17] := {"AGENCIA"  , "C", 15,  0}
      aField[18] := {"CC"       , "C", 15,  0}
      aField[19] := {"OBS2"     , "C", 50,  0}
      aField[20] := {"OBS3"     , "C", 50,  0}
      aField[21] := {"MULTA"    , "N",  6,  2}
      aField[22] := {"MORA"     , "N",  6,  2}
      aField[23] := {"NOSSO_NUM", "N", 20,  0}
      DBcreate(eCAMINHO_DADOS+"MENSAL", aField)

      DBCLOSEALL()
      vINDEXA="S"
   ENDIF
ENDIF

IF eTipo_banco="DBF"
   IF !MY_FILE("*.CDX")
      aviso2()
      vINDEXA="S"
   ENDIF
ENDIF

IF vINDEXA="S"
   INDEXA()
ENDIF
RETURN

*************************
Function Erro_Atualizando
*************************
_newAlert("Erro ao Atualizar o Sistema, Favor Revisar","Aviso do Sistema")
SAIR2()
Return(.T.)
