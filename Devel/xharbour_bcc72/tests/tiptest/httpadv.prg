/******************************************
* TIP test
* HTTP Advanced operations Test
*
* $Id: httpadv.prg 9279 2011-02-14 18:06:32Z druzus $
*****/

PROCEDURE MAIN(  )
   LOCAL oCon, oUrl, i

   cURL :="https://ptax.bcb.gov.br/ptax_internet/consultaBoletim.do?method=gerarCSVFechamentoMoedaNoPeriodo&ChkMoeda=61&DATAINI=01/05/2017&DATAFIM=01/06/2017"
   cHtml:=''

   oUrl := tURL():New( cUrl )
//   oCon := TipClientHttp():New( oUrl,.T. )

   oHttp:=TipClientHttp():new( oUrl )
   IF .NOT. oHttp:open()
      showmsg("Connection error:", oHttp1:lastErrorMessage())
   ENDIF

   cHtml:= oHttp:readAll()
   oHttp:close()

ShowMsg({cHtml})
/*

   oUrl := tURL():New( cUrl )
   IF Empty( oUrl )
      ? "Invalid url " + cUrl
      ?
      QUIT
   ENDIF

   IF oUrl:cProto != "http"
      ? 'This is a header test for http.'
      ? 'Use an http address.'
      ?
      QUIT
   END

   oCon := TipClientHttp():New( oUrl,.T. )
   oCon:nConnTimeout := 20000
   ? "Connecting with", oUrl:cServer
   IF oCon:Open( cUrl )
      ? "Connection eshtablished"
      ? "Retreiving", oUrl:cPath, oUrl:cFile, oUrl:cQuery

      IF oCon:Get( oUrl:cPath )
         ? "Get Sucessful"
         FOR i := 1 to Len( oCon:hHeaders )
            ? HGetkeyAt( oCon:hHeaders, i ) +":", HGetValueAt( oCon:hHeaders, i )
         NEXT
      ELSE
         ? "Get failure (server reply:", oCon:cReply , ")"
      ENDIF
      oCon:Close()
   ELSE
      ? "Can't connect with", oUrl:cServer
      IF oCon:SocketCon == NIL
         ? "Connection not initiated"
      ELSEIF InetErrorCode( oCon:SocketCon ) == 0
         ? "Server sayed:", oCon:cReply
      ELSE
         ? "Error in connection:", InetErrorDesc( oCon:SocketCon )
      ENDIF
   END

   ? "Done"
   ?
*/
RETURN

FUNC IMPRIME_DANF
RETURN

FUNC GERA_EXCEL
RETURN
