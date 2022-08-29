/*
 * $Id: hgraph.prg 1615 2011-02-18 13:53:35Z mlacecilia $
 *
 * HWGUI - Harbour Linux (GTK) GUI library source code:
 * HGraph class
 *
 * Copyright 2005 Alexander S.Kresin <alex@belacy.belgorod.su>
 * www - http://kresin.belgorod.su
*/

#include "windows.ch"
#include "hbclass.ch"
#include "guilib.ch"

CLASS HGraph INHERIT HControl

   CLASS VAR winclass   INIT "STATIC"
   DATA aValues
   DATA nGraphs INIT 1
   DATA nType
   DATA lGrid   INIT .F.
   DATA scaleX, scaleY
   DATA ymaxSet
   DATA tbrush
   DATA colorCoor INIT 16777215
   DATA oPen, oPenCoor
   DATA xmax, ymax, xmin, ymin PROTECTED

   METHOD New( oWndParent,nId,aValues,nLeft,nTop,nWidth,nHeight,oFont, ;
                  bSize,ctoolt,tcolor,bcolor )
   METHOD Activate()
   METHOD onEvent( msg, wParam, lParam )
   METHOD CalcMinMax()
   METHOD Paint()
   METHOD Rebuild( aValues )

ENDCLASS

METHOD New( oWndParent,nId,aValues,nLeft,nTop,nWidth,nHeight,oFont, ;
                  bSize,ctoolt,tcolor,bcolor ) CLASS HGraph

   Super:New( oWndParent,nId,SS_OWNERDRAW,nLeft,nTop,nWidth,nHeight,oFont,, ;
                  bSize,{|o,lpdis|o:Paint(lpdis)},ctoolt, ;
                  Iif( tcolor==Nil,Vcolor("FFFFFF"),tcolor ),Iif( bcolor==Nil,0,bcolor ) )

   ::aValues := aValues
   ::nType   := 1
   ::nGraphs := 1

   ::Activate()

Return Self

METHOD Activate CLASS HGraph

   IF !Empty(::oParent:handle )
      ::handle := CreateStatic( ::oParent:handle, ::id, ;
                  ::style, ::nLeft, ::nTop, ::nWidth, ::nHeight )
      SetWindowObject( ::handle,Self )
      ::Init()
   ENDIF
Return Nil

METHOD onEvent( msg, wParam, lParam ) CLASS HGraph
   IF msg == WM_PAINT
      ::Paint()
   ENDIF
Return 0

METHOD CalcMinMax() CLASS HGraph
Local i, j, nLen
   ::xmax := ::xmin := ::ymax := ::ymin := 0
   IF ::ymaxSet != Nil .AND. ::ymaxSet != 0
      ::ymax := ::ymaxSet
   ENDIF
   FOR i := 1 TO ::nGraphs
      nLen := Len( ::aValues[i] )
      IF ::nType == 1
         FOR j := 1 TO nLen
            ::xmax := Max( ::xmax,::aValues[i,j,1] )
            ::xmin := Min( ::xmin,::aValues[i,j,1] )
            ::ymax := Max( ::ymax,::aValues[i,j,2] )
            ::ymin := Min( ::ymin,::aValues[i,j,2] )
         NEXT
      ELSEIF ::nType == 2
         FOR j := 1 TO nLen
            ::ymax := Max( ::ymax,::aValues[i,j,2]   )
            ::ymin := Min( ::ymin,::aValues[i,j,2]   )
         NEXT
         ::xmax := nLen
      ELSEIF ::nType == 3
         FOR j := 1 TO nLen
            ::ymax += ::aValues[i,j,2]
         NEXT
      ENDIF
   NEXT

Return Nil

METHOD Paint( lpdis ) CLASS HGraph
Local hDC := GetDC( ::handle )
// Local drawInfo := GetDrawItemInfo( lpdis )
// Local hDC := drawInfo[3], x1 := drawInfo[4], y1 := drawInfo[5], x2 := drawInfo[6], y2 := drawInfo[7]
Local x1 := 0, y1 := 0, x2 := ::nWidth, y2 := ::nHeight
Local i, j, nLen
Local px1, px2, py1, py2, nWidth

   IF ::xmax == Nil
      ::CalcMinMax()
   ENDIF
   i := Round( (x2-x1)/10,0 )
   x1 += i
   x2 -= i
   i := Round( (y2-y1)/10,0 )
   y1 += i
   y2 -= i

   IF ::nType < 3
      ::scaleX := (::xmax-::xmin) / (x2-x1)
      ::scaleY := (::ymax-::ymin) / (y2-y1)
   ENDIF

   IF ::oPenCoor == Nil
      ::oPenCoor := HPen():Add( PS_SOLID,1,::colorCoor )
   ENDIF
   IF ::oPen == Nil
      ::oPen := HPen():Add( PS_SOLID,2,::tcolor )
   ENDIF

   FillRect( hDC, 0, 0, ::nWidth, ::nHeight, ::brush:handle )
   IF ::nType != 3
      SelectObject( hDC, ::oPenCoor:handle )
      Drawline( hDC, x1+(0-::xmin)/::scaleX, 3, x1+(0-::xmin)/::scaleX, ::nHeight-3 )
      Drawline( hDC, 3, y2-(0-::ymin)/::scaleY, ::nWidth-3, y2-(0-::ymin)/::scaleY )
   ENDIF
   IF ::ymax == ::ymin .AND. ::ymax == 0
      Return Nil
   ENDIF

   SelectObject( hDC, ::oPen:handle )
   FOR i := 1 TO ::nGraphs
      nLen := Len( ::aValues[i] )
      IF ::nType == 1  
         FOR j := 2 TO nLen
            px1 := Round(x1+(::aValues[i,j-1,1]-::xmin)/::scaleX,0)
            py1 := Round(y2-(::aValues[i,j-1,2]-::ymin)/::scaleY,0)
            px2 := Round(x1+(::aValues[i,j,1]-::xmin)/::scaleX,0)
            py2 := Round(y2-(::aValues[i,j,2]-::ymin)/::scaleY,0)
            IF px2 != px1 .OR. py2 != py1
               Drawline( hDC, px1, py1, px2, py2 )
            ENDIF   
         NEXT
      ELSEIF ::nType == 2
         IF ::tbrush == Nil
            ::tbrush := HBrush():Add( ::tcolor )
         ENDIF
         nWidth := Round( (x2-x1) / (nLen*2+1),0 )
         FOR j := 1 TO nLen
            px1 := Round( x1+nWidth*(j*2-1),0 )
            py1 := Round( y2-(::aValues[i,j,2]-::ymin)/::scaleY,0 )
            FillRect( hDC, px1, py1, px1+nWidth, y2-2, ::tbrush:handle )
         NEXT
      ELSEIF ::nType == 3
         DrawButton( hDC,5,5,80,30,5 )
         DrawButton( hDC,5,35,80,55,6 )	 
         /*
         IF ::tbrush == Nil
            ::tbrush := HBrush():Add( ::tcolor )
         ENDIF
         SelectObject( hDC, ::oPenCoor:handle )
         SelectObject( hDC, ::tbrush:handle )
         pie( hDC, x1+10,y1+10,x2-10,y2-10, x1,round(y1+(y2-y1)/2,0),round(x1+(x2-x1)/2,0),y1 )
	 */
      ENDIF
   NEXT
   releaseDC( ::handle, hDC )
   
Return Nil

METHOD Rebuild( aValues, nType ) CLASS HGraph

   ::aValues := aValues
   IF nType != Nil
      ::nType := nType
   ENDIF
   ::CalcMinMax()
   RedrawWindow( ::handle, RDW_ERASE + RDW_INVALIDATE + RDW_INTERNALPAINT + RDW_UPDATENOW )

Return Nil
