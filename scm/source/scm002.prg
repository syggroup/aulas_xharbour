#include "scm.ch"

*IF Use_Arq("AGENDA",,.T.,.F.,.F.)=.F.  // COMPARTILHADO
*   Return
*ENDIF

*IF Use_Arq("AGENDA",,.T.,.T.,.F.)=.F.  // SOMENTE LEITURA
*   Return
*ENDIF

*IF Use_Arq("AGENDA",,.F.,.F.,.T.)=.F.  // TEMPORARIO
*   Return
*ENDIF

*IF Use_Arq("AGENDA",,.F.,.F.,.F.)=.F.  // EXCLUSIVO
*   Return
*ENDIF

*******************************************************************
FUNCTION Use_Arq(cArquivo,cAlias,iShared,iLeitura,iTemp,iabre_auto)
*******************************************************************
//--> cArquivo : Nome do Arquivo
//--> cAlias   : Nome do Apelido
//--> iShared  : .f. Exclusivo ou .t. Compartilhado
//--> iLeitura : .t. só Leitura ou .f. Leitura e Gravação
//--> iTemp    : .t. usa uma tabela temporaria ou .f. abre uma tabela normal
local lReturn  := .F.
Local cDriver  := eRDD_DRIVER

IF cAlias=Nil
   IF iShared= .T.   // SE FOR COMPARTILHADO
      IF iTemp = .F.
         IF iabre_auto=Nil
            Return
         ENDIF
      ENDIF
   ENDIF
   cAlias=cArquivo
ENDIF

if eTipo_banco="SQL" .and. iTemp = .F.
   cDriver:="SQLRDD"
ELSEIF eTipo_banco="DBF"
   IF !My_File(cArquivo+".dbf")
      Dirchange(Substr(Nomeexecutavel(.t.),1,(len(Nomeexecutavel(.t.))- len(Nomeexecutavel()))-1 ))
   ENDIF
   IF iTemp=.F.
      cArquivo:=eCAMINHO_DADOS+cArquivo
   ENDIF
endif
if iTemp = .T.
   cDriver:=eRDD_DRIVER
endif

do while .t.
   HW_Atualiza_Dialogo("Abrindo Tabelas")
   IF SELECT(cAlias)=0
      TRY
         DBSELECTAREA(0) // SELECIONA A PROXIMA AREA LIVRE
         DbUseArea(.t.,cDriver,cArquivo,cAlias,iShared,iLeitura,,)
      catch e
         vResp := MsgRetryCancel( "Erro ao Tentar Abrir a Tabela: " + cArquivo + ", Favor revisar a conexão com o Servidor !","Aviso do Sistema")
         IF vRESP
            loop
         ELSE
            Focaliza_App()
            Return .f.
         endif
      END
      IF NetErr()
         vRESP := MsgRetryCancel( "Sistema em Uso em Modo Exclusivo por Outra Estação no Momento !","Aviso do Sistema"  )
         IF vRESP
            loop
         ELSE
            Return .f.
         endif
      else
         SELECT(cAlias)
         Return .t.
      endif
   ELSE
      if eTipo_banco="SQL"
         &cAlias->(DbCloseArea())
         LOOP
      else
         SELECT(cAlias)
         LIMPA_FILTRO()
         Return .t.
      endif
   ENDIF
enddo
Return lReturn

********************
Function ConectionOK
********************
Local oSql,cSql,aret :={}
#ifdef _XHBSQL_
cSql   := "select version()"
oSql   := SR_GetConnection()                         // Obtem o objeto da conexão ativa
oSql:exec(cSql,.F.,.t.,@aret)
if len(aRet) == 0
   Return(.F.)
else
   Return(.T.)
endif
#endif
Return(.F.)

*********************
Function Limpa_Filtro
*********************
Local cAlias_ant := Alias()
if len(alltrim(cAlias_ant)) > 0
   IF eTipo_banco="DBF"
      ORDScope(0, NIL)
      ORDScope(1, NIL)
      DbClearFilter()
   ELSE
      #ifdef _XHBCOM_
      Sr_Setfilter("")
      #endif
   ENDIF
endif
Return Nil

**************************
Function deleta_cdx(cDEST)
**************************
Local vTENTATIVAS := 0
IF !MY_FILE(cDEST+".CDX")
   Return .F.
ENDIF
IF eTipo_banco="DBF"
   Ferase(cDEST+".CDX")
   Ferase(eCAMINHO_DADOS+cDEST+".CDX")
ELSE
   #ifdef _XHBSQL_
   SELE &cDEST // tem que abrir a tabela para poder excluir o indice(bug sqlrdd)
   SR_DropIndex( cDEST )
   #endif
ENDIF
Return(.T.)

FUNCTION MY_DropIndex( cIndex, nConn )
   Local cLstIDX
   Local cDropIDX
   Local oSql
   Local nErro := 0
   Local nOldConn
   #ifdef _XHBSQL_

   nOldConn := SR_GetActiveConnection()
   nConn := IIf( nConn == NIL, nOldConn, nConn )

   SR_SetActiveConnection(nConn)

   // Identifica os ¡ndices criados para a tabela no FB
   cLstIDX := "SELECT DISTINCT "
   cLstIDX += "      i.rdb$index_name INDICE "
   cLstIDX += "FROM rdb$indices i "
   cLstIDX += "WHERE "
   cLstIDX += "     i.rdb$relation_name = " + SR_CDBVALUE( cIndex )
   cLstIDX += "     and NOT i.rdb$index_name STARTING WITH 'RDB' "
   cLstIDX += "order by "
   cLstIDX += "      i.rdb$index_name "

   dbUseArea( .T.,"SQLRDD",cLstIDX, "LstIndices",  ,  ,  , ,nConn)

   LstIndices->(DBGoTop())

   If ! LstIndices->(EOF())
      cDropIDX := "DROP INDEX "

      SR_BeginTransaction()
      oSql := SR_GetConnection()

      DO WHILE ! LstIndices->(EOF())
         nErro := oSql:Exec( cDropIDX+LstIndices->INDICE )
         If nErro > 0
            Alert( "Erro ao executar SQL: " + cDropIDX+LstIndices->INDICE )
            SR_RollBackTransaction()
            Exit
         Endif
         LstIndices->(DBSkip())
      ENDDO

      If nErro == 0
         oSql:Commit()
      EndiF

      LstIndices->(DBCloseArea())

      If nErro == 0
         SR_EndTransaction()
      EndIf

      If nOldConn # nConn
         SR_SetActiveConnection(nOldConn)
      Endif
   Endif
   #endif
RETURN(nErro == 0)

**************************
FUNCTION DELETA_DBF(cDEST)
**************************
Local vTENTATIVAS := 0
Local vSALVA_PATH := curdrive()+':'+"\"+curdir()

IF !MY_FILE(cDEST+".DBF")
   Return .F.
ENDIF
IF eTipo_banco="DBF"
   Ferase(eCAMINHO_DADOS+cDEST+".DBF")
   IF FILE(eCAMINHO_DADOS+cDEST+".FPT")
      Ferase(eCAMINHO_DADOS+cDEST+".FPT")
   ENDIF
   deleta_cdx(cDEST)
ELSE
   deleta_cdx(cDEST)
   dbcloseall()
   #ifdef _XHBSQL_
   DO WHILE .T.
      HW_Atualiza_Dialogo(cDEST + " - " +Str((vTENTATIVAS/30)*100,4) +" %")
      IF vTENTATIVAS > 30
         EXIT
      ENDIF
      IF SR_DropTable( cDEST )=.T.
         IF !SR_ExistTable(cDEST)
            EXIT
         ENDIF
      ELSE
         vTENTATIVAS=vTENTATIVAS+1
         LOOP
      ENDIF
   ENDDO
   #ENDIF
ENDIF
Return

***********************
Function MY_FILE(cFILE)
***********************
IF eTipo_banco="DBF"
   IF RIGHT(UPPER(cFILE),4)=".DBF" .OR. RIGHT(UPPER(cFILE),4)=".CDX"
      IF FILE(eCAMINHO_DADOS+cFILE)
         Return .T.
      ELSE
         Return .F.
      ENDIF
   ELSE
      IF FILE(cFILE)
         Return .T.
      ELSE
         Return .F.
      ENDIF
   ENDIF
ELSE
   #ifdef _XHBSQL_
   IF RIGHT(UPPER(cFILE),4)=".DBF"
      IF SR_ExistTable(SUBSTR(cFILE, 1, LEN(cFILE)-4))
         Return .T.
      ELSE
         Return .F.
      ENDIF
   ELSEIF RIGHT(UPPER(cFILE),4)=".CDX"
      IF SR_ExistIndex(SUBSTR(cFILE, 1, LEN(cFILE)-4))
         Return .T.
      ELSE
         Return .F.
      ENDIF
   ELSE
      IF FILE(cFILE)
         Return .T.
      ELSE
         Return .F.
      ENDIF
   ENDIF
   #endif
ENDIF
Return

***********************
Function ExistTag(vTAG)
***********************
Local apcode,osql,cSql,nerr,npos,aret :={}, vTABLE:=Alias()
#ifdef _XHBSQL_
IF eTipo_banco="SQL"
   osql  := sr_getconnection()
   csql  := "select * from sr_mgmntindexes where IDXNAME_ = ?  and TAG_=?"
   apcode:= sr_sqlparse(csql,@nerr,@npos)
   cSql  := sr_sqlcodegen(apcode,{vTABLE,vTAG})
   osql:exec(cSql,,.t.,@aret)
   if len(aRet) == 0
      Return(.F.)
   else
      Return(.T.)
   endif
*vARR:=SR_ListIndex("CAG_PAP")
*MSGINFO(VALTOPRG(vARR))
ENDIF
#endif
HW_Atualiza_Dialogo(vTAG)
Return(.F.)

*****************
Function TravaArq
*****************
PRIVATE oDlgHabla:=NIL
MsgRun("Aguarde Travando Arquivo......")
do While .T.
   If Flock()
      Fim_Run()
      Return(.T.)
   Else
      Inkey(1)
      Loop
   EndIf
EndDo
Fim_Run()
Return(Nil)

******************
Function LiberaREG
******************
DBUNLOCK()
Return

****************
Function AppRede
****************
Local vCONTA := 0
DO While .T.
   vCONTA= vCONTA + 1
   if eTipo_banco="SQL"
      DbAppend()
      TravaReg("S")
      Return(.T.)
   else
      IF NetAppend(1,.f.)
         TravaReg("S")
         Return(.T.)
      ELSE
         MilliSec( 1000 )    // espera um segundo antes de tentar novamente
      ENDIF
   endif

   IF vCONTA > 10
      IF MsgYesNo("Não Foi possivel Adicionar o Registro, Deseja Tentar Novamente ?","Aviso do Sistema")
         vCONTA=0
         loop
      Else
         exit
         Return(.F.)
      Endif
   ENDIF
Enddo
Return(.F.)

**************************
Function TravaReg(xEterno)
**************************
DO While .T.
   vTentativas=0
   DO While .T.
      IF Rlock()
         Return .T.
      ElSE // TENTA DE NOVO
         Private oDlgHabla:=nil
         MsgRun("Aguarde... Tentativa de acesso.: "+str(vTentativas)+" De.: 10")
         MilliSec( 1000 )    // espera um segundo antes de voltar
         Fim_Run()

         If vTentativas=10
            IF xEterno="S"  // É OBRIGADO A TRAVAR
               vTentativas=0
               LOOP
            ELSE
               EXIT
            ENDIF
         else
            vTentativas=vTentativas+1
            Loop
         endif
      EndIf
   EndDo
   IF MsgYesNo("Não Foi possivel Travar o Registro, Deseja Tentar Novamente ?","Aviso do Sistema")
      loop
   Else
      exit
      Return .F.
   Endif
ENDDO
Return .F.

*************************
Function Abre_dados(vHAB)
*************************
Local vRet:=.F.

IF !File("SYGECOM.DBF")
   private aField[7]
   aField[1] := {"TIPO_SQL", "C", 10,  0}  // FIREBIRD, MYSQL, POSTGRE
   aField[2] := {"HOST"    , "C", 60,  0}
   aField[3] := {"PORTA"   , "C",  5,  0}
   aField[4] := {"DATABASE", "C", 40,  0}
   aField[5] := {"USUARIO" , "C", 30,  0}
   aField[6] := {"SENHA"   , "C", 30,  0}
   aField[7] := {"CHARSET" , "C", 15,  0}
   DBcreate("SYGECOM", aField, eRDD_DRIVER)
   Configura_Servidor()
ENDIF
DBCLOSEALL()

IF Use_Arq("SYGECOM",,.T.,.F.,.T.)=.F.  // COMPARTILHADO
   MsgStop("Erro ao Abrir as Configurações do sistema, Favor Revisar","Aviso do Sistema")
   SAIR2()
   Return(vRet)
ENDIF
SELE SYGECOM
dbgotop()
IF LASTREC() = 0
   Configura_Servidor()
ENDIF
public eTIPO_SQL:=ALLTRIM(TIPO_SQL)
public eHOST    :=ALLTRIM(HOST)
public ePORTA   :=ALLTRIM(PORTA)
public eDATABASE:=ALLTRIM(DATABASE)
public eCHARSET :=ALLTRIM(CHARSET)
public nCnn

vREG1=alltrim(USUARIO)
public eUSUARIO_SQL:=HB_Decrypt( vREG1, eKEY )

vREG2=alltrim(SENHA)
public eSENHA_SQL:=HB_Decrypt( vREG2, eKEY )

#ifdef _XHBSQL_
   PRIVATE oDlgHabla:=NIL
   MsgRun("Conectando ao Banco de Dados...")

   AJUSTA_CONEXAO_SQLRDD()

   vMEU_SQL="PGS="+eHost+";UID="+eUSUARIO_SQL+";PWD="+eSENHA_SQL+";DTB="+eDATABASE+";PRT="+ePORTA
   nCnn := SR_AddConnection(CONNECT_POSTGRES, vMEU_SQL)
   If nCnn < 0
      Fim_Run()
      MsgInfo("Não Conectou ao Banco de Dados, Favor revisar","Aviso do Sistema")
      IF vHAB=.F.
         SAIR2()
      ENDIF
      RETURN(vRet)
   ELSE
      RddSetDefault( "SQLRDD" )

      SR_UseDeleteds( .F. )     // NÃO MANTER REGISTROS DELETADOS NAS TABELAS
      SR_SetFastOpen(.T.)       // ABRE AS TABELAS EM MODO COMPARTILHADO
      SR_SetGoTopOnScope(.F.)   // NÃO EXECUTA O DBGOTOP() AUTOMATICO NOS ORDSCOPE
      SR_MaxRowCache( 100 )
      SR_SetBaseLang( 2 )
      SR_Msg(2) // portugues
      SR_SETSYNTHETICINDEX(.F.)
      SR_SETSYNTHETICINDEXMINIMUN(10)
      SR_SetActiveConnection( nCnn )
      vRet:=.T.
   EndIf
   //SR_StartTrace() // PARA VER OS COMANDOS SQL EM UM ALERT()
   //SR_StartLog()   // PARA SALVAR OS COMANDOS SQL EM DBF LOCAL
#endif
Fim_Run()
RETURN(vRet)

******************************
FUNCTION AJUSTA_CONEXAO_SQLRDD
******************************
#IfnDef __XHARBOUR__
   //return(.t.)
#else
   OVERRIDE METHOD CONNECTRAW IN CLASS SR_PGS WITH SYG_CONNECTRAW
#endif
//OVERRIDE METHOD CONNECTRAW IN CLASS SR_PGS WITH SYG_CONNECTRAW
//ESSE COMANDO ACIMA FAZ COM QUE A FUNÇÃO: MYCONNECTRAW() SUBISTITUA A FUNÇÃO: CONNECTRAW DENTRO DA CLASSE SR_PGS(SQLRDD)
return(.t.)


STATIC FUNCTION SYG_CONNECTRAW( cDSN, cUser, cPassword, nVersion, cOwner, nSizeMaxBuff, lTrace,;
            cConnect, nPrefetch, cTargetDB, nSelMeth, nEmptyMode, nDateMode, lCounter, lAutoCommit )
/*
ESSA FUNÇÃO É USADA PARA FAZER A CONEXÃO COM O BANCO DE DADOS NO POSTGRESQL COM O SQLRDD
*/
   local hEnv := 0, hDbc := 0
   local nret, cVersion := "", cSystemVers := "", cBuff := ""
   Local aRet := {}
   LOCAl Self := HB_QSelf()

   (cDSN)
   (cUser)
   (cPassword)
   (nVersion)
   (cOwner)
   (nSizeMaxBuff)
   (lTrace)
   (nPrefetch)
   (nSelMeth)
   (nEmptyMode)
   (nDateMode)
   (lCounter)
   (lAutoCommit)

   //DEFAULT ::cPort := 5432
   IF EMPTY(::cPort)
      ::cPort := 5432
   ENDIF
   cConnect := "host=" + ::cHost + " user=" + ::cUser + " password=" + ::cPassword + " dbname=" + ::cDTB + " port=" + str(::cPort,6)

*   IF !Empty( ::sslcert )
*      cConnect += " sslmode=prefer sslcert="+::sslcert +" sslkey="+::sslkey +" sslrootcert="+ ::sslrootcert +" sslcrl="+ ::sslcrl
*   ENDIF

   hDbc := PGSConnect( cConnect )
   nRet := PGSStatus( hDbc )

   if nRet != SQL_SUCCESS .and. nRet != SQL_SUCCESS_WITH_INFO
      ::nRetCode = nRet
      SR_MsgLogFile( "Connection Error: " + alltrim(str(PGSStatus2( hDbc ))) + " (see pgs.ch)" )
      Return Self
   else
      ::cConnect = cConnect
      ::hStmt    = NIL
      ::hDbc     = hDbc
      cTargetDB  = "PostgreSQL Native"
      ::exec( "select version()",.t.,.t.,@aRet )
      If len (aRet) > 0
         cSystemVers := aRet[1,1]
      Else
         cSystemVers= "??"
      EndIf
   EndIf

   ::cSystemName := cTargetDB
   ::cSystemVers := cSystemVers
   ::nSystemID   := SYSTEMID_POSTGR
   ::cTargetDB   := Upper( cTargetDB )

   // na linha abaixo acresenta as versões suportadas pelo SQLRDD
   If ! ("7.3" $ cSystemVers .or. ;
         "7.4" $ cSystemVers .or. ;
         "8.0" $ cSystemVers .or. ;
         "8.1" $ cSystemVers .or. ;
         "8.2" $ cSystemVers .or. ;
         "8.3" $ cSystemVers .or. ;
         "8.4" $ cSystemVers .or. ;
         "9.0" $ cSystemVers .or. ;
         "9.1" $ cSystemVers .or. ;
         "9.2" $ cSystemVers .or. ;
         "9.5" $ cSystemVers .or. ;
         "9.6" $ cSystemVers .or. ;
         "10." $ cSystemVers .or. ;
         "11." $ cSystemVers .or. ;
         "12." $ cSystemVers)

      ::End()
      ::nRetCode  := SQL_ERROR
      ::nSystemID := NIL
      SR_MsgLogFile( "Unsupported Postgres version: " + cSystemVers )
   EndIf

   ::exec( "select pg_backend_pid()", .T., .T., @aRet )

   If len( aRet ) > 0
      ::uSid := val(str(aRet[1,1],8,0))
   EndIf

return Self
