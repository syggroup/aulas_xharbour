/*
 * $Id: hxmldoc.prg 1844 2012-06-06 11:11:24Z alkresin $
 *
 * Harbour XML Library
 * HXmlDoc class
 *
 * Copyright 2003 Alexander S.Kresin <alex@belacy.belgorod.su>
 * www - http://kresin.belgorod.su
*/

#include "hbclass.ch"
#include "fileio.ch"
#include "hxml.ch"

/*
 *  CLASS DEFINITION
 *  HXMLNode
 */

CLASS HXMLNode

   CLASS VAR nLastErr SHARED
   DATA title
   DATA type
   DATA aItems  INIT {}
   DATA aAttr   INIT {}
   DATA cargo

   METHOD New( cTitle, type, aAttr )
   METHOD Add( xItem )
   METHOD GetAttribute( cName )
   METHOD SetAttribute( cName,cValue )
   METHOD DelAttribute( cName )
   METHOD Save( handle,level )
   METHOD Find( cTitle,nStart )
ENDCLASS

METHOD New( cTitle, type, aAttr, cValue ) CLASS HXMLNode

   IF cTitle != Nil ; ::title := cTitle ; ENDIF
   IF aAttr  != Nil ; ::aAttr := aAttr  ; ENDIF
   ::type := Iif( type != Nil , type, HBXML_TYPE_TAG )
   IF cValue != Nil
      ::Add( cValue )
   ENDIF
Return Self

METHOD Add( xItem ) CLASS HXMLNode

   Aadd( ::aItems, xItem )
Return xItem

METHOD GetAttribute( cName ) CLASS HXMLNode
Local i := Ascan( ::aAttr,{|a|a[1]==cName} )

Return Iif( i==0, Nil, ::aAttr[ i,2 ] )

METHOD SetAttribute( cName,cValue ) CLASS HXMLNode
Local i := Ascan( ::aAttr,{|a|a[1]==cName} )

   IF i == 0
      Aadd( ::aAttr,{ cName,cValue } )
   ELSE
      ::aAttr[ i,2 ] := cValue
   ENDIF

Return .T.

METHOD DelAttribute( cName ) CLASS HXMLNode
Local i := Ascan( ::aAttr,{|a|a[1]==cName} )

   IF i != 0
      Adel( ::aAttr, i )
      Asize( ::aAttr, Len( ::aAttr ) - 1 )
   ENDIF
Return .T.

METHOD Save( handle,level ) CLASS HXMLNode
Local i, s := Space(level*2)+'<', lNewLine

   IF !__mvExist( "HXML_NEWLINE" )
      __mvPrivate( "HXML_NEWLINE" )
      __mvPut( "HXML_NEWLINE", .T. )
   ENDIF
   lNewLine := m->hxml_newline
   IF ::type == HBXML_TYPE_COMMENT
      s += '!--'
   ELSEIF ::type == HBXML_TYPE_CDATA
      s += '![CDATA['
   ELSEIF ::type == HBXML_TYPE_PI
      s += '?' + ::title
   ELSE
      s += ::title
   ENDIF
   IF ::type == HBXML_TYPE_TAG .OR. ::type == HBXML_TYPE_SINGLE
      FOR i := 1 TO Len( ::aAttr )
         s += ' ' + ::aAttr[i,1] + '="' + HBXML_Transform(::aAttr[i,2]) + '"'
      NEXT
   ENDIF
   IF ::type == HBXML_TYPE_PI
      s += '?>' + Chr(10)
      m->hxml_newline := .T.
   ELSEIF ::type == HBXML_TYPE_SINGLE
      s += '/>' + Chr(10)
      m->hxml_newline := .T.
   ELSEIF ::type == HBXML_TYPE_TAG
      s += '>'
      IF Empty( ::aItems ) .OR. ( Len(::aItems) == 1 .AND. ;
            Valtype(::aItems[1]) == "C" .AND. Len(::aItems[1]) + Len(s) < 80 )
         lNewLine := m->hxml_newline := .F.
      ELSE
         s += Chr(10)
         lNewLine := m->hxml_newline := .T.
      ENDIF
   ENDIF
   IF handle >= 0
      FWrite( handle,s )
   ENDIF

   FOR i := 1 TO Len( ::aItems )
      IF Valtype( ::aItems[i] ) == "C"
        IF handle >= 0
           IF ::type == HBXML_TYPE_CDATA .OR. ::type == HBXML_TYPE_COMMENT
              FWrite( handle, ::aItems[i] )
           ELSE
              FWrite( handle, HBXML_Transform( ::aItems[i] ) )
           ENDIF
           IF lNewLine
              FWrite( handle, Chr(10) )
           ENDIF
        ELSE
           IF ::type == HBXML_TYPE_CDATA .OR. ::type == HBXML_TYPE_COMMENT
              s += ::aItems[i]
           ELSE
              s += HBXML_Transform( ::aItems[i] )
           ENDIF
           IF lNewLine
              s += Chr(10)
           ENDIF
        ENDIF
        m->hxml_newline := .F.
      ELSE
        s += ::aItems[i]:Save( handle, level+1 )
      ENDIF
   NEXT
   m->hxml_newline := .T.
   IF handle >= 0
      IF ::type == HBXML_TYPE_TAG
         FWrite( handle, Iif(lNewLine,Space(level*2),"") + '</' + ::title + '>' + Chr(10 ) )
      ELSEIF ::type == HBXML_TYPE_CDATA
         FWrite( handle, ']]>' + Chr(10) )
      ELSEIF ::type == HBXML_TYPE_COMMENT
         FWrite( handle, '-->' + Chr(10) )
      ENDIF
   ELSE
      IF ::type == HBXML_TYPE_TAG
         s += Iif(lNewLine,Space(level*2),"") + '</' + ::title + '>' + Chr(10 )
      ELSEIF ::type == HBXML_TYPE_CDATA
         s += ']]>' + Chr(10)
      ELSEIF ::type == HBXML_TYPE_COMMENT
         s += '-->' + Chr(10)
      ENDIF
      Return s
   ENDIF
Return ""

METHOD Find( cTitle,nStart,block ) CLASS HXMLNode
Local i

   IF nStart == Nil
      nStart := 1
   ENDIF
   DO WHILE .T.
      i := Ascan( ::aItems,{|a|Valtype(a)!="C".AND.a:title==cTitle},nStart )
      IF i == 0
         EXIT
      ELSE
         nStart := i
         IF block == Nil .OR. Eval( block,::aItems[i] )
            Return ::aItems[i]
         ELSE
            nStart ++
         ENDIF
      ENDIF
   ENDDO

Return Nil


/*
 *  CLASS DEFINITION
 *  HXMLDoc
 */

CLASS HXMLDoc INHERIT HXMLNode

   METHOD New( encoding )
   METHOD Read( fname )
   METHOD ReadString( buffer )  INLINE ::Read( ,buffer )
   METHOD Save( fname,lNoHeader )
   METHOD Save2String()  INLINE ::Save()
ENDCLASS

METHOD New( encoding ) CLASS HXMLDoc

   IF encoding != Nil
      Aadd( ::aAttr, { "version","1.0" } )
      Aadd( ::aAttr, { "encoding",encoding } )
   ENDIF

Return Self

METHOD Read( fname,buffer ) CLASS HXMLDoc
Local han

   IF fname != Nil
      han := FOpen( fname, FO_READ )
      IF han != -1
         ::nLastErr := hbxml_GetDoc( Self,han )
         FClose( han )
      ENDIF
   ELSEIF buffer != Nil
      ::nLastErr := hbxml_GetDoc( Self,buffer )
   ELSE
      Return Nil
   ENDIF
Return Iif( ::nLastErr == 0, Self, Nil )

METHOD Save( fname,lNoHeader ) CLASS HXMLDoc
Local handle := -2
Local cEncod, i, s

   IF fname != Nil
      handle := FCreate( fname )
   ENDIF
   IF handle != -1
      IF lNoHeader == Nil .OR. !lNoHeader
         IF ( cEncod := ::GetAttribute( "encoding" ) ) == Nil
            cEncod := "UTF-8"
         ENDIF
         s := '<?xml version="1.0" encoding="'+cEncod+'"?>'+Chr(10 )
         IF fname != Nil
            FWrite( handle, s )
         ENDIF
      ELSE
         s := ""
      ENDIF
      FOR i := 1 TO Len( ::aItems )
         s += ::aItems[i]:Save( handle, 0 )
      NEXT
      IF fname != Nil
         FClose( handle )
      ELSE
         Return s
      ENDIF
   ENDIF
Return .T.
