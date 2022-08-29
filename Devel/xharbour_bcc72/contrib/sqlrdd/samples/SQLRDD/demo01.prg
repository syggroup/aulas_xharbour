/*
* SQLRDD Test
* Copyright (c) 2003 - Marcelo Lombardo  <marcelo@xharbour.com.br>
* All Rights Reserved
*/

#include "sqlrdd.ch"

#define RECORDS_IN_TEST                   1000
#define SQL_DBMS_NAME                       17
#define SQL_DBMS_VER                        18

/*------------------------------------------------------------------------*/

Function Main( cRDD, cDSN )

   local nCnn, i, oSql

   ? ""
   ? "demo01.exe"
   ? ""
   ? "Small SQLRDD demo"
   ? "(c) 2003 - Marcelo Lombardo"
   ? ""

   ? "Connecting to database..."

   SR_UseDeleteds( .F. )           // NÃO MANTER REGISTROS DELETADOS NAS TABELAS
   SR_SetFastOpen(.T.)             // ABRE AS TABELAS EM MODO COMPARTILHADO
   SR_SetGoTopOnScope(.T.)         // NÃO EXECUTA O DBGOTOP() AUTOMATICO NOS ORDSCOPE
   SR_MaxRowCache( 100 )           // Quantidade máxima de linhas matidas em cache em tabelas do SQLRDD. O Default é 1000.
   SR_SetBaseLang( 2 )             // linguagem portugues
   SR_Msg(2)                       // portugues
   SR_SETSYNTHETICINDEX(.F.)       // vale o que for configurado pela função SR_SetSyntheticIndexMinimun().
   SR_SETSYNTHETICINDEXMINIMUN(10) // Quantidade mínima de colunas na chave de índice para criá-lo como Sintético. Os valores aceitos são entre 0 e 10.
   SETPGSOLDBEHAVIOR(.T.)          // CONSIDERAR CAMPOS NULL COMO VAZIO

   Connect( @cRDD, cDSN, nil, nil, nil, nil, nil, .t.  )    // see connect.prg

   RddSetDefault( "SQLRDD" )

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

   aVetor:={}
   oSql  := SR_GetConnection()
   nErr:= oSql:exec("select max(fcfo.codcfo) as codcfo from fcfo (nolock) where fcfo.codcoligada = 0 and fcfo.codcfo like '0%'","COLIGADA",.t.,.t.,@aVetor,,,,.t.)          // Executa a query no banco e armazena em VETOR

   ALERT(VALTOPRG(nErr))

   if len(aVetor)>0
      ? aVetor[1,1]
   else
      ? 'Erro ao pegar o retorno da consulta'
   endif   
    
*   alert('agora vai trancar')

   DBCLOSEALL()
   SR_END()
Return NIL

/*------------------------------------------------------------------------*/

#include "connect.prg"

/*------------------------------------------------------------------------*/
