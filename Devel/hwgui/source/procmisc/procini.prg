/*
 * $Id: procini.prg 1615 2011-02-18 13:53:35Z mlacecilia $
 *
 * Common procedures
 * Ini files reading
 *
 * Author: Alexander S.Kresin <alex@belacy.belgorod.su>
 *         www - http://www.geocities.com/alkresin/
*/

/*
 Function Rdini scans file line by line, creates variables ( if they doesn't
 declared yet ) as Public and asiignes them values.
 File format:
      ...
      [SECTION1_NAME]
      ...
      [SECTION2_NAME]
      ...
 Function reads variables from beginning of file until first section
 and from sections, named in function call.
 Comments must have symbol ';' in the first position of a line.
 Symbol '&' indicate continue on the next line.
 Variables may be logical:

    var_name=On
    var_name=Off
    var_name=

  character:

    var_name="stroka"

  numeric:

    var_name=999

  codeblock:

    var_name={|| ... }

  array of any structure, including all types of variables:

    var_name={ ... { ... } ... }

 Syntax: Rdini ( ini_file_name, [section1_name], [section2_name],;
                 [section3_name], [section4_name] ),
   where ini_file_name - name of .ini - file you want to read,
   section1_name, ..., section4_name - names of sections in .ini - file
    which you want to read.
*/

#include "fileio.ch"
#define STR_BUFLEN  1024

FUNCTION RDINI( fname, prm1, prm2, prm3, prm4 )

LOCAL han, stroka, strfull, kolstr, rez, poz1, vname, i, prblo, lTruncAr
LOCAL lWinIni  := ( VALTYPE( prm1 ) == "A" )
LOCAL strbuf := Space(STR_BUFLEN), poz := STR_BUFLEN+1
LOCAL iniDbf := ( Upper( FilExten( fname ) ) == "DBF" )

   kolstr := 0
   prblo  := .T.
   IF iniDbf
      USE (fname) NEW
      han := Iif( NetErr(), -1, 0 )
   ELSE
      han    := FOPEN( fname, FO_READ + FO_SHARED )
   ENDIF
   IF han <> - 1
      strfull := ""
      DO WHILE .T.
         kolstr ++
         stroka := Iif( iniDbf, RDSTRDBF(), RDSTR( han,@strbuf,@poz,STR_BUFLEN ) )
         IF LEN( stroka ) = 0
            EXIT
         ENDIF
         IF Right( stroka,2 ) == '&&'
            strfull += Left( stroka,Len(stroka)-2 )
            LOOP
         ELSEIF Right( stroka,1 ) == '&'
            strfull += Left( stroka,Len(stroka)-1 )
            LOOP
         ELSE
            IF !Empty( strfull )
               stroka := strfull + stroka
            ENDIF
            strfull := ""
         ENDIF
         //
         IF Left( stroka,1 ) = "["
            stroka := UPPER( SUBSTR( stroka, 2, AT( "]", stroka ) - 2 ) )
            IF lWinIni
               AADD( prm1, { UPPER( stroka ), {} } )
            ELSE
               prblo := .F.
               SET EXACT ON
               IF stroka = prm1 .OR. stroka = prm2 .OR. stroka = prm3 .OR. stroka = prm4
                  prblo := .T.
               ENDIF
               SET EXACT OFF
            ENDIF
         ELSEIF ( prblo .OR. lWinIni ) .AND. Left( stroka,1 ) <> ";"
            poz1 := AT( "=", stroka )
            IF poz1 <> 0
               lTruncAr := IIF( SUBSTR( stroka, poz1 - 1, 1 ) == '+', .F., .T. )
               vname    := RTRIM( SUBSTR( stroka, 1, IIF( lTruncAr, poz1 - 1, poz1 - 2 ) ) )
               stroka   := ALLTRIM( SUBSTR( stroka, poz1 + 1 ) )
               IF lWinIni
                  AADD( prm1[ LEN( prm1 ), 2 ], { UPPER( vname ), stroka } )
               ELSE
                  IF TYPE( vname ) = "U"
                     IF ASC( stroka ) = 123                 // {
                        IF ASC( vname ) = 35                // #
                           vname := SUBSTR( vname, 2 )
                           PRIVATE &vname := {}
                        ELSE
                           PUBLIC &vname := {}
                        ENDIF
                     ELSE
                        IF ASC( vname ) = 35                // #
                           vname := SUBSTR( vname, 2 )
                           PRIVATE &vname
                        ELSE
                           PUBLIC &vname
                        ENDIF
                     ENDIF
                  ELSE
                     IF lTruncAr .AND. ASC( stroka ) = 123 .AND. LEN( &vname ) > 0
                        ASIZE( &vname, 0 )
                     ENDIF
                  ENDIF
                  DO CASE
                  CASE stroka = "on" .OR. stroka = "ON" .OR. stroka = "On"
                     &vname := .T.
                  CASE stroka = "off" .OR. stroka = "OFF" .OR. stroka = "Off" .OR. EMPTY( stroka )
                     &vname := .F.
                  CASE ASC( stroka ) = 123 .AND. SUBSTR( stroka, 2, 1 ) <> "|"  // {
                     RDARR( vname, stroka )
                  OTHERWISE
                     &vname := RDZNACH( stroka )
                  ENDCASE
               ENDIF
            ENDIF
            //
         ENDIF
      ENDDO
      FCLOSE( han )
   ELSE
      RETURN 0
   ENDIF
   IF iniDbf
      USE
   ENDIF
RETURN kolstr

STATIC FUNCTION RDZNACH( ps )

LOCAL poz, znc
   ps := ALLTRIM( ps )
   IF ASC( ps ) = 34
      poz := AT( CHR( 34 ), SUBSTR( ps, 2 ) )
      IF poz <> 0
         znc := SUBSTR( ps, 2, poz - 1 )
      ENDIF
   ELSE
      znc := &ps
   ENDIF
RETURN znc

STATIC FUNCTION RDARR( vname, stroka )

LOCAL poz1, i := 0, lenm, len1, strv, newname
   poz1 := FIND_Z( SUBSTR( stroka, 2 ), "}" )
   IF poz1 <> 0
      stroka := SUBSTR( stroka, 2, poz1 - 1 )
      lenm   := LEN( &vname )
      DO WHILE poz1 <> 0
         IF EMPTY( stroka )
            EXIT
         ELSE
            i ++
            poz1 := FIND_Z( stroka )
            strv := LTRIM( SUBSTR( stroka, 1, IIF( poz1 = 0, 9999, poz1 - 1 ) ) )
            IF ASC( strv ) = 123 .AND. SUBSTR( strv, 2, 1 ) <> "|"              // {
               AADD( &vname, {} )
               len1    := LEN( &vname )
               newname := vname + "[" + LTRIM( STR( len1, 3 ) ) + "]"
               RDARR( newname, strv )
            ELSE
               AADD( &vname, RDZNACH( strv ) )
            ENDIF
            stroka := SUBSTR( stroka, poz1 + 1 )
         ENDIF
      ENDDO
   ENDIF
RETURN Nil

STATIC FUNCTION RDSTRDBF
LOCAL stroka
FIELD INICOND, INITEXT
   IF Eof()
      Return ""
   ENDIF
   stroka := IIF( Empty( INICOND ) .OR. &( INICOND ), Trim(INITEXT), "" )
   SKIP
RETURN stroka
