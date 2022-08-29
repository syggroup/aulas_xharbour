#include "scm.ch"

************************
Function UnidadeCorrente
************************
Local vRET := .T.
IF TipoUnidade(GetDriveType(DiskName()+":")) ="DRIVE_NO_ROOT_DIR"
   MsgStop("É Altamente recomendavel Utilizar o Mapeando de Unidade para Utilizar o sistema em Rede, Favor revisar","Aviso do Sistema")
ELSEIF TipoUnidade(GetDriveType(DiskName()+":")) ="DRIVE_CDROM"
   vRET := .F.
ELSEIF TipoUnidade(GetDriveType(DiskName()+":")) ="DRIVE_RAMDISK"
   MsgStop("É Altamente recomendavel Utilizar Discos Fixos para utilização e instalação do Sistema, Favor revisar","Aviso do Sistema")
   vRET := .F.
ELSEIF TipoUnidade(GetDriveType(DiskName()+":")) ="DRIVE_REMOVABLE"
   MsgStop("É Altamente recomendavel Utilizar Discos Fixos para utilização e instalação do Sistema, Favor revisar","Aviso do Sistema")
   vRET := .F.
ENDIF
Return(vRET)

// Função TipoUnidade:
// Obtém a descrição do tipo da unidade, à partir do valor obtido
// com a função GetDriveType.
*************************************
Function TipoUnidade ( nTipo )
*************************************
   Local cTipo := ""

   Do Case
   Case nTipo == DRIVE_UNKNOWN     ; cTipo := "DRIVE_UNKNOWN"
   Case nTipo == DRIVE_NO_ROOT_DIR ; cTipo := "DRIVE_NO_ROOT_DIR" // REDE NÃO MAPEADA
   Case nTipo == DRIVE_REMOVABLE   ; cTipo := "DRIVE_REMOVABLE"   // DISCO REMOVIVEL
   Case nTipo == DRIVE_FIXED       ; cTipo := "DRIVE_FIXED"       // FIXO
   Case nTipo == DRIVE_REMOTE      ; cTipo := "DRIVE_REMOTE"      // REDE MAPEADA
   Case nTipo == DRIVE_CDROM       ; cTipo := "DRIVE_CDROM"       // LEITOR DE CD-ROOM
   Case nTipo == DRIVE_RAMDISK     ; cTipo := "DRIVE_RAMDISK"     // PEN-DRIVER
   EndCase
Return cTipo

#pragma BEGINDUMP

#include <windows.h>
#include <hbapi.h>

HB_FUNC ( GETLOGICALDRIVES )
{
   hb_retnl( (DWORD) GetLogicalDrives() );
}

HB_FUNC ( GETDRIVETYPE )
{
   hb_retni( (UINT) GetDriveType(hb_parc(1)) );
}
#pragma ENDDUMP

****************************
Function Baixa_Arq(Essencial)
****************************
Local vSALVA_PATH := curdrive()+':'+"\"+curdir()

IF TipoUnidade(GetDriveType(DiskName()+":")) ="DRIVE_NO_ROOT_DIR"
   MsgStop("É Altamente recomendavel Utilizar o Mapeando de Unidade para poder Atualizar o sistema em Rede, Favor revisar","Aviso do Sistema")
   Return Nil
ELSEIF TipoUnidade(GetDriveType(DiskName()+":")) ="DRIVE_CDROM"
   MsgStop("Não é possivel atualizar o sistema apartir de uma Unidade de CD-ROM, Favor instalar o sistema em uma unidade Fixa","Aviso do Sistema")
   Return Nil
ELSEIF TipoUnidade(GetDriveType(DiskName()+":")) ="DRIVE_RAMDISK"
   MsgStop("É Altamente recomendavel Utilizar Discos Fixos para utilização e atualização do Sistema, Favor revisar","Aviso do Sistema")
   Return Nil
ELSEIF TipoUnidade(GetDriveType(DiskName()+":")) ="DRIVE_REMOVABLE"
   MsgStop("É Altamente recomendavel Utilizar Discos Fixos para utilização e atualização do Sistema, Favor revisar","Aviso do Sistema")
   Return Nil
ENDIF

IF Essencial=.F.
   IF !MsgYesNo("Atenção !!! Para continuar com essa opção Ninguem pode esta usando o Sistema, Deseja Continuar ?","Aviso do Sistema")
      Return Nil
   ENDIF

   Private oDlgHabla:=nil
   MsgRun("Aguarde Verificando Uso do sistema pela Rede...")
   IF Verefica_Uso_Exclusivo(.F.)= 0
      Fim_Run()
      MsgStop("Impossível continuar, o Sistema esta em Uso por outra Estação, Favor Verificar","Aviso do Sistema")
      Return NIL
   ENDIF
   Fim_Run()
ENDIF
DBCLOSEALL()

Baixa_Arq2()

Return NIL

*******************
Function Baixa_Arq2
*******************
Local arq, arqh, txt, txt_t

SET DATE BRITISH
SET EPOCH TO 2000

Private oDlgHabla:=nil
MsgRun("Aguarde Verificando conexão com a Internet..." )

IF Inetestaconectada()=.T.
   Fim_Run()
   IF !FILE("res\processando.avi")
      Donwload_File("/atualiza/res","processando.avi","res\processando.avi")
   Endif
   IF !FILE("res\WindowsXP.Manifest")
      Donwload_File("/atualiza/res","WindowsXP.Manifest","res\WindowsXP.Manifest")
   Endif
   if !FILE("ie32.dll")
      Donwload_File("/atualiza/bin","ie32.dll","ie32.dll")
   endif
   if !FILE("blat.dll")
      Donwload_File("/atualiza/bin","blat.dll","blat.dll")
   endif
   if !FILE("envia_email.exe")
      Donwload_File("/atualiza/bin","envia_email.exe","envia_email.exe")
   endif
   if !My_File("comerr32.dll")
      Donwload_File("/atualiza/bin","comerr32.dll","comerr32.dll")
   endif
   if !My_File("fbclient.dll")
      Donwload_File("/atualiza/bin","fbclient.dll","fbclient.dll")
   endif
   if !My_File("gssapi32.dll")
      Donwload_File("/atualiza/bin","gssapi32.dll","gssapi32.dll")
   endif
   if !My_File("k5sprt32.dll")
      Donwload_File("/atualiza/bin","k5sprt32.dll","k5sprt32.dll")
   endif
   if !My_File("krb5_32.dll")
      Donwload_File("/atualiza/bin","krb5_32.dll","krb5_32.dll")
   endif
   if !My_File("libeay32.dll")
      Donwload_File("/atualiza/bin","libeay32.dll","libeay32.dll")
   endif
   if !My_File("libiconv-2.dll")
      Donwload_File("/atualiza/bin","libiconv-2.dll","libiconv-2.dll")
   endif
   if !My_File("libintl-8.dll")
      Donwload_File("/atualiza/bin","libintl-8.dll","libintl-8.dll")
   endif
   if !My_File("libmysql.dll")
      Donwload_File("/atualiza/bin","libmysql.dll","libmysql.dll")
   endif
   if !My_File("libpq.dll")
      Donwload_File("/atualiza/bin","libpq.dll","libpq.dll")
   endif
   if !My_File("msvcr71.dll")
      Donwload_File("/atualiza/bin","msvcr71.dll","msvcr71.dll")
   endif
   if !My_File("ssleay32.dll")
      Donwload_File("/atualiza/bin","ssleay32.dll","ssleay32.dll")
   endif

   IF eTipo_banco="SQL"
      if !MY_FILE("zlib1.dll")
         Donwload_File("/atualiza/bin","zlib1.dll","zlib1.dll")
      endif
      if !MY_FILE("pg_dump.exe")
         Donwload_File("/atualiza/bin","pg_dump.exe","pg_dump.exe")
      endif
      if !MY_FILE("psql.exe")
         Donwload_File("/atualiza/bin","psql.exe","psql.exe")
      endif
   ENDIF
else
   Fim_Run()
   MsgStop("Não foi possível estabelecer uma conexão com o Servidor,Favor verificar sua Conexão com a Internet ou tente mais tarde.","Aviso do Sistema")
Endif
Return

************************************************
PROCEDURE Donwload_File(ftpdir,ftpfile,fdestino)
************************************************
Local cURL, cSaveAs, nFileSize
Local janela1, janela2, janela3
Local vBaixa :="N"
Private oBar,oDlg,oFont,nSize, oConn

cURL := "http://update.sygecom.com.br"+ftpdir+"/"+ftpfile

IF MsgYesNo("Há uma Nova Atualização Disponivel, deseja Atualizar Agora ?","Atualização do Sistema")

   Aguarde("Baixando Atualizações do sistema SCM Vs. " + GETFILEVERSIONINFO(),"Aguarde Baixando arquivos...")
   cTamanho := Get_File_Size(ftpdir+"/"+ftpfile)

   TRY
     oConn := TipClientHttp():New(TURL():New(cURL))
     oConn:nConnTimeout := 10000
     oConn:exGauge := { | done, size| ShowGauge(done, size, cTamanho, ftpfile ) }

     IF oConn:Open(cURL)
        oConn:ReadToFile(fdestino,,nFileSize)
        oConn:Close()
     ENDIF
   CATCH
     MsgStop("Erro ao Tentar baixar a atualização, Favor tente mais tarde","Aviso do Sistema")
   END

   oDlg:Close()
ENDIF
Fim_Run()
RETURN

Procedure ShowGauge( nSent, nSize, wTotal, ftpfile )
IF nSent > 0
   hwg_processmessage()
   eval( {||oBar:Set(,(nSent/wTotal)*100),.t.} )
   @ 50,120 say "Arquivo...: " +ftpfile+" "+ STR(nSent)+" Byts de: " + str(wTotal)+ " Byts "+str((nSent/wTotal)*100,4) +" %" SIZE 500,22;
   COLOR x_BLUE
ENDIF
RETURN

*****************************
Procedure Aguarde(vTIT,vMENS)
*****************************
PREPARE FONT oFont NAME "MS Sans Serif" WIDTH 0 HEIGHT -20
INIT DIALOG oDlg TITLE vTIT AT 45,30 SIZE 600,210 NOEXIT STYLE DS_CENTER + WS_VISIBLE
@ 50,20 say vMENS  size 300,40 Font oFont
@ 50,60 PROGRESSBAR oBar OF oDlg SIZE 510,50 BARWIDTH 10000
oDlg:Activate(.t.)

************************************
FUNCTION GET_FILE_SIZE(cCAMINHO_URL)
************************************
LOCAL nRET_BYTS:=0
LOCAL nHANDLE_OLD := getactivewindow()
LOCAL oHttp, cHtml:=''

//http://www.sygecom.com.br/update/tamanhoArquivo.php?caminho=atualiza/sagi/bin/200/sagi.zip

IF LEFT(cCAMINHO_URL,1)='/' .OR. LEFT(cCAMINHO_URL,1)='\'
   cCAMINHO_URL:=substr(cCAMINHO_URL,2,len(cCAMINHO_URL)) // tira a primeira barra por que não precisa
ENDIF

IF Empty( cCAMINHO_URL )
   HWG_BRINGWINDOWTOTOP(nHANDLE_OLD) // restaura o handle da janela anterior
   Return(nRET_BYTS)
ENDIF

TRY
   oHttp:= TIpClientHttp():new( "http://www.sygecom.com.br/update/tamanhoArquivo.php?caminho="+alltrim(cCAMINHO_URL))
CATCH
   HWG_BRINGWINDOWTOTOP(nHANDLE_OLD) // restaura o handle da janela anterior
   Return(nRET_BYTS)
END
IF oHttp:open()
   cHtml   := oHttp:readAll()

   IF !EMPTY(cHtml)
      IF LEN(cHTML) > 0 .AND. LEN(cHTML) < 20
         nRET_BYTS:=VAL(alltrim(cHTML))
      ENDIF
   ENDIF
ENDIF
oHttp:close()
HWG_BRINGWINDOWTOTOP(nHANDLE_OLD) // restaura o handle da janela anterior
RETURN(nRET_BYTS)
