/*
 *$Id: hcontrol.prg 1615 2011-02-18 13:53:35Z mlacecilia $
 *
 * HWGUI - Harbour Linux (GTK) GUI library source code:
 * HControl, HStatus, HStatic, HButton, HGroup, HLine classes 
 *
 * Copyright 2004 Alexander S.Kresin <alex@belacy.belgorod.su>
 * www - http://kresin.belgorod.su
 *
 * ButtonEx class
 *
 * Copyright 2008 Luiz Rafael Culik Guimaraes <luiz at xharbour.com.br >
 * www - http://sites.uol.com.br/culikr/
 
*/

#include "windows.ch"
#include "hbclass.ch"
#include "guilib.ch"

REQUEST ENDWINDOW

#define  CONTROL_FIRST_ID   34000

//- HControl

CLASS HControl INHERIT HCustomWindow

   DATA id
   DATA tooltip
   DATA lInit    INIT .F.
   DATA name
   DATA Anchor          INIT 0
   DATA   xName           HIDDEN
   ACCESS Name            INLINE ::xName
   ASSIGN Name( cName )   INLINE ::AddName( cName ) 


   METHOD New( oWndParent,nId,nStyle,nLeft,nTop,nWidth,nHeight,oFont,bInit, ;
                  bSize,bPaint,ctoolt,tcolor,bcolor )
   METHOD Init()
   METHOD AddName( cName ) HIDDEN
   METHOD SetColor( tcolor,bcolor,lRepaint )
   METHOD NewId()

   METHOD Disable()	INLINE EnableWindow( ::handle, .F. )
   METHOD Enable()	INLINE EnableWindow( ::handle, .T. )
   METHOD IsEnabled()   INLINE IsWindowEnabled( ::Handle )
   METHOD SetFocus()	INLINE EnableWindow( ::handle, .T. )
   METHOD Move( x1,y1,width,height )
   /*
   METHOD GetText()     INLINE GetWindowText(::handle)
   METHOD SetText( c )  INLINE SetWindowText( ::Handle, c )
   */
   METHOD onAnchor( x, y, w, h )
   METHOD End()

ENDCLASS

METHOD New( oWndParent,nId,nStyle,nLeft,nTop,nWidth,nHeight,oFont,bInit, ;
                  bSize,bPaint,ctoolt,tcolor,bcolor ) CLASS HControl

   ::oParent := Iif( oWndParent==Nil, ::oDefaultParent, oWndParent )
   ::id      := Iif( nId==Nil,::NewId(), nId )
   ::style   := Hwg_BitOr( Iif( nStyle==Nil,0,nStyle ),WS_VISIBLE+WS_CHILD )
   ::oFont   := oFont
   ::nLeft   := nLeft
   ::nTop    := nTop
   ::nWidth  := nWidth
   ::nHeight := nHeight
   ::bInit   := bInit
   ::bSize   := bSize
   ::bPaint  := bPaint
   ::tooltip := ctoolt
   ::SetColor( tcolor,bcolor )

   ::oParent:AddControl( Self )

Return Self

METHOD NewId() CLASS HControl
Local nId := CONTROL_FIRST_ID + Len( ::oParent:aControls )

   IF Ascan( ::oParent:aControls, {|o|o:id==nId} ) != 0
      nId --
      DO WHILE nId >= CONTROL_FIRST_ID .AND. Ascan( ::oParent:aControls, {|o|o:id==nId} ) != 0
         nId --
      ENDDO
   ENDIF
Return nId

METHOD AddName( cName ) CLASS HControl

   IF !EMPTY( cName ) .AND. VALTYPE( cName) == "C" .AND. ! ":" $ cName .AND. ! "[" $ cName
      ::xName := cName
			__objAddData( ::oParent, cName )
	    ::oParent: & ( cName ) := Self
   ENDIF	    
   
RETURN Nil

METHOD INIT CLASS HControl
Local o

   IF !::lInit
      AddToolTip( ::oParent:handle, ::handle, ::tooltip )
      IF ::oFont != Nil
         hwg_SetCtrlFont( ::handle, ::oFont:handle )
      ELSEIF ::oParent:oFont != Nil
         hwg_SetCtrlFont( ::handle, ::oParent:oFont:handle )
      ENDIF
      IF ISBLOCK(::bInit)
         Eval( ::bInit, Self )
      ENDIF
      o := ::oParent
      DO WHILE o != Nil .AND. !__ObjHasMsg( o,"LACTIVATED")
         o := o:oParent
      ENDDO
      if ::tcolor != nil          
            SETFGCOLOR(::handle,::tcolor)
      endif	    
      
      
      IF o != Nil .AND. o:lActivated
         hwg_ShowAll( o:handle )
      ENDIF
      ::lInit := .T.
   ENDIF
RETURN Nil

METHOD SetColor( tcolor,bcolor,lRepaint ) CLASS HControl

   IF tcolor != Nil
      ::tcolor  := tcolor
      IF bColor == Nil .AND. ::bColor == Nil
         // bColor := GetSysColor( COLOR_3DFACE )
      ENDIF
   ENDIF

   IF bcolor != Nil
      ::bcolor  := bcolor
      IF ::brush != Nil
         ::brush:Release()
      ENDIF
      ::brush := HBrush():Add( bcolor )
   ENDIF

   IF lRepaint != Nil .AND. lRepaint
      RedrawWindow( ::handle, RDW_ERASE + RDW_INVALIDATE )
   ENDIF

Return Nil

METHOD Move( x1,y1,width,height,lMoveParent )  CLASS HControl
Local lMove := .F., lSize := .F.

   IF x1 != Nil .AND. x1 != ::nLeft
      ::nLeft := x1
      lMove := .T.
   ENDIF   
   IF y1 != Nil .AND. y1 != ::nTop
      ::nTop := y1
      lMove := .T.
   ENDIF
   IF width != Nil .AND. width != ::nWidth
      ::nWidth := width
      lSize := .T.
   ENDIF   
   IF height != Nil .AND. height != ::nHeight
      ::nHeight := height
      lSize := .T.
   ENDIF
   IF lMove .OR. lSize
      hwg_MoveWidget( ::handle, Iif(lMove,::nLeft,Nil), Iif(lMove,::nTop,Nil), ;
          Iif(lSize,::nWidth,Nil), Iif(lSize,::nHeight,Nil), lMoveParent )
   ENDIF
Return Nil

METHOD End() CLASS HControl

   Super:End()
   IF ::tooltip != Nil
      // DelToolTip( ::oParent:handle,::handle )
      ::tooltip := Nil
   ENDIF
Return Nil

METHOD onAnchor( x, y, w, h ) CLASS HControl
   LOCAL nAnchor, nXincRelative, nYincRelative, nXincAbsolute, nYincAbsolute
   LOCAL x1, y1, w1, h1, x9, y9, w9, h9

   nAnchor := ::anchor
   x9 := ::nLeft
   y9 := ::nTop
   w9 := ::nWidth
   h9 := ::nHeight

   x1 := ::nLeft
   y1 := ::nTop
   w1 := ::nWidth
   h1 := ::nHeight
  *- calculo relativo
   nXincRelative :=  w / x
   nYincRelative :=  h / y
    *- calculo ABSOLUTE
   nXincAbsolute := ( w - x )
   nYincAbsolute := ( h - y )

   IF nAnchor >= ANCHOR_VERTFIX
    *- vertical fixed center
      nAnchor := nAnchor - ANCHOR_VERTFIX
      y1 := y9 + Int( ( h - y ) * ( ( y9 + h9 / 2 ) / y ) )
   ENDIF                             
   IF nAnchor >= ANCHOR_HORFIX
    *- horizontal fixed center
      nAnchor := nAnchor - ANCHOR_HORFIX
      x1 := x9 + Int( ( w - x ) * ( ( x9 + w9 / 2 ) / x ) )
   ENDIF
   IF nAnchor >= ANCHOR_RIGHTREL
      && relative - RIGHT RELATIVE
      nAnchor := nAnchor - ANCHOR_RIGHTREL
      x1 := w - Int( ( x - x9 - w9 ) * nXincRelative ) - w9
   ENDIF
   IF nAnchor >= ANCHOR_BOTTOMREL
      && relative - BOTTOM RELATIVE
      nAnchor := nAnchor - ANCHOR_BOTTOMREL
      y1 := h - Int( ( y - y9 - h9 ) * nYincRelative ) - h9
   ENDIF
   IF nAnchor >= ANCHOR_LEFTREL
      && relative - LEFT RELATIVE
      nAnchor := nAnchor - ANCHOR_LEFTREL
      IF x1 != x9
         w1 := x1 - ( Int( x9 * nXincRelative ) ) + w9
      ENDIF
      x1 := Int( x9 * nXincRelative )
   ENDIF
   IF nAnchor >= ANCHOR_TOPREL
      && relative  - TOP RELATIVE
      nAnchor := nAnchor - ANCHOR_TOPREL
      IF y1 != y9
         h1 := y1 - ( Int( y9 * nYincRelative ) ) + h9
      ENDIF
      y1 := Int( y9 * nYincRelative )
   ENDIF
   IF nAnchor >= ANCHOR_RIGHTABS
      && Absolute - RIGHT ABSOLUTE
      nAnchor := nAnchor - ANCHOR_RIGHTABS
      IF x1 != x9
         w1 := x1 - ( x9 +  Int( nXincAbsolute ) ) + w9
      ENDIF
      x1 := x9 +  Int( nXincAbsolute )
   ENDIF
   IF nAnchor >= ANCHOR_BOTTOMABS
      && Absolute - BOTTOM ABSOLUTE
      nAnchor := nAnchor - ANCHOR_BOTTOMABS
      IF y1 != y9
         h1 := y1 - ( y9 +  Int( nYincAbsolute ) ) + h9
      ENDIF
      y1 := y9 +  Int( nYincAbsolute )
   ENDIF
   IF nAnchor >= ANCHOR_LEFTABS
      && Absolute - LEFT ABSOLUTE
      nAnchor := nAnchor - ANCHOR_LEFTABS
      IF x1 != x9
         w1 := x1 - x9 + w9
      ENDIF
      x1 := x9
   ENDIF
   IF nAnchor >= ANCHOR_TOPABS
      && Absolute - TOP ABSOLUTE
      //nAnchor := nAnchor - 1
      IF y1 != y9
         h1 := y1 - y9 + h9
      ENDIF
      y1 := y9
   ENDIF
   InvalidateRect( ::oParent:handle, 1, ::nLeft, ::nTop, ::nWidth, ::nHeight )
   ::Move( ::handle, x1, y1, w1, h1 )
   ::nLeft := x1
   ::nTop := y1
   ::nWidth := w1
   ::nHeight := h1
   RedrawWindow( ::handle, RDW_ERASE + RDW_INVALIDATE )

   RETURN Nil



//- HStatus
CLASS HStatus INHERIT HControl

   CLASS VAR winclass   INIT "msctls_statusbar32"
   DATA aParts
   METHOD New( oWndParent,nId,nStyle,oFont,aParts,bInit,bSize,bPaint )
   METHOD Activate()
   METHOD Init()
   method SetText(t,n) inline  STATUSBARSETTEXT(::handle,n,t)

ENDCLASS

METHOD New( oWndParent,nId,nStyle,oFont,aParts,bInit,bSize,bPaint ) CLASS HStatus

   bSize := Iif( bSize!=Nil, bSize, {|o,x,y|MoveWindow(o:handle,0,y-20,x,y)} )
   nStyle := Hwg_BitOr( Iif( nStyle==Nil,0,nStyle ), WS_CHILD+WS_VISIBLE+WS_OVERLAPPED+WS_CLIPSIBLINGS )
   Super:New( oWndParent,nId,nStyle,0,0,0,0,oFont,bInit,bSize,bPaint )

   ::aParts  := aParts
   ::Activate()

Return Self

METHOD Activate CLASS HStatus
Local aCoors

   IF !Empty(::oParent:handle )

      ::handle := CreateStatusWindow( ::oParent:handle, ::id )

      ::Init()
//      IF __ObjHasMsg( ::oParent,"AOFFSET" )
//         aCoors := GetWindowRect( ::handle )
//         ::oParent:aOffset[4] := aCoors[4] - aCoors[2]
//      ENDIF
   ENDIF
Return Nil

METHOD Init CLASS HStatus
   IF !::lInit
      Super:Init()
   ENDIF
Return  NIL

//- HStatic

CLASS HStatic INHERIT HControl

   CLASS VAR winclass   INIT "STATIC"

   METHOD New( oWndParent,nId,nStyle,nLeft,nTop,nWidth,nHeight,cCaption,oFont,bInit, ;
                  bSize,bPaint,ctoolt,tcolor,bcolor,lTransp )
   METHOD Activate()
   METHOD SetValue(value) INLINE hwg_static_SetText( ::handle,value )
   METHOD SetText(value) INLINE hwg_static_SetText( ::handle,value )
ENDCLASS

METHOD New( oWndParent,nId,nStyle,nLeft,nTop,nWidth,nHeight,cCaption,oFont,bInit, ;
                  bSize,bPaint,ctoolt,tcolor,bcolor,lTransp ) CLASS HStatic

   Super:New( oWndParent,nId,nStyle,nLeft,nTop,nWidth,nHeight,oFont,bInit, ;
                  bSize,bPaint,ctoolt,tcolor,bcolor )

   ::title   := cCaption
   IF lTransp != Nil .AND. lTransp
      ::extStyle += WS_EX_TRANSPARENT
   ENDIF

   ::Activate()

Return Self

METHOD Activate CLASS HStatic
   IF !Empty(::oParent:handle )
      ::handle := CreateStatic( ::oParent:handle, ::id, ;
                  ::style, ::nLeft, ::nTop, ::nWidth, ::nHeight, ::extStyle, ::title )
      ::Init()
   ENDIF
Return Nil

//- HButton

CLASS HButton INHERIT HControl

   CLASS VAR winclass   INIT "BUTTON"
   DATA  bClick
   
   METHOD New( oWndParent,nId,nStyle,nLeft,nTop,nWidth,nHeight,cCaption,oFont, ;
                  bInit,bSize,bPaint,bClick,ctoolt,tcolor,bcolor )
   METHOD Activate()
   METHOD onEvent( msg, wParam, lParam )
ENDCLASS

METHOD New( oWndParent,nId,nStyle,nLeft,nTop,nWidth,nHeight,cCaption,oFont, ;
                  bInit,bSize,bPaint,bClick,ctoolt,tcolor,bcolor ) CLASS HButton

   nStyle := Hwg_BitOr( Iif( nStyle==Nil,0,nStyle ), BS_PUSHBUTTON )
   Super:New( oWndParent,nId,nStyle,nLeft,nTop,Iif( nWidth==Nil,90,nWidth ),;
              Iif( nHeight==Nil,30,nHeight ),oFont,bInit, ;
              bSize,bPaint,ctoolt,tcolor,bcolor )

   ::title   := cCaption
   ::Activate()

   IF ::id == IDOK
      bClick := {||::oParent:lResult:=.T.,::oParent:Close()}
   ELSEIF ::id == IDCANCEL
      bClick := {||::oParent:Close()}
   ENDIF
   IF bClick != Nil
      // ::oParent:AddEvent( 0,::id,bClick )
      ::bClick := bClick
      hwg_SetSignal( ::handle,"clicked",WM_LBUTTONUP,0,0 )
   ENDIF

Return Self

METHOD Activate CLASS HButton
   IF !Empty(::oParent:handle )
      ::handle := CreateButton( ::oParent:handle, ::id, ;
                  ::style, ::nLeft, ::nTop, ::nWidth, ::nHeight, ::title )
      SetWindowObject( ::handle,Self )
      ::Init()
   ENDIF
Return Nil

METHOD onEvent( msg, wParam, lParam )  CLASS HButton

   IF msg == WM_LBUTTONUP
      IF ::bClick != Nil
         Eval( ::bClick,Self )
      ENDIF
   ENDIF
Return  NIL

CLASS HButtonEX INHERIT HButton

   Data hBitmap
   DATA hIcon

   METHOD New( oWndParent, nId, nStyle, nLeft, nTop, nWidth, nHeight, ;
   cCaption, oFont, bInit, bSize, bPaint, cTooltip, tcolor, ;
   bColor, lTransp, hBitmap,hIcon )

METHOD Activate
END CLASS

METHOD New( oWndParent, nId, nStyle, nLeft, nTop, nWidth, nHeight, ;
               cCaption, oFont, bInit, bSize, bPaint, bClick, cTooltip, ;
               tcolor, bColor, hBitmap, iStyle,hicon,Transp ) CLASS HButtonEx


   ::hBitmap                            := hBitmap
   ::hIcon                              := hIcon

   ::super:New( oWndParent, nId, nStyle, nLeft, nTop, nWidth, nHeight, ;
                cCaption, oFont, bInit, bSize, bPaint, bClick, cTooltip, ;
                tcolor, bColor )

RETURN Self

METHOD Activate CLASS HButtonEX
   IF !Empty(::oParent:handle )
      if !empty(::hBitmap)
      ::handle := CreateButton( ::oParent:handle, ::id, ;
                  ::style, ::nLeft, ::nTop, ::nWidth, ::nHeight, ::title,::hBitmap) 
      elseif !empty(::hIcon)     
            ::handle := CreateButton( ::oParent:handle, ::id, ;
                  ::style, ::nLeft, ::nTop, ::nWidth, ::nHeight, ::title,::hIcon) 
      else
            ::handle := CreateButton( ::oParent:handle, ::id, ;
                  ::style, ::nLeft, ::nTop, ::nWidth, ::nHeight, ::title,nil) 
      endif		  
      SetWindowObject( ::handle,Self )
      ::Init()
   ENDIF
Return Nil

//- HGroup

CLASS HGroup INHERIT HControl

   CLASS VAR winclass   INIT "BUTTON"
   METHOD New( oWndParent,nId,nStyle,nLeft,nTop,nWidth,nHeight,cCaption, ;
                  oFont,bInit,bSize,bPaint,tcolor,bcolor )
   METHOD Activate()

ENDCLASS

METHOD New( oWndParent,nId,nStyle,nLeft,nTop,nWidth,nHeight,cCaption, ;
                  oFont,bInit,bSize,bPaint,tcolor,bcolor ) CLASS HGroup

   nStyle := Hwg_BitOr( Iif( nStyle==Nil,0,nStyle ), BS_GROUPBOX )
   Super:New( oWndParent,nId,nStyle,nLeft,nTop,nWidth,nHeight,oFont,bInit, ;
                  bSize,bPaint,,tcolor,bcolor )

   ::title   := cCaption
   ::Activate()

Return Self

METHOD Activate CLASS HGroup
   IF !Empty(::oParent:handle )
      ::handle := CreateButton( ::oParent:handle, ::id, ;
                  ::style, ::nLeft, ::nTop, ::nWidth, ::nHeight, ::title )
      ::Init()
   ENDIF
Return Nil

// hline

CLASS HLine INHERIT HControl

   CLASS VAR winclass   INIT "STATIC"
   DATA lVert

   METHOD New( oWndParent,nId,lVert,nLeft,nTop,nLength,bSize )
   METHOD Activate()

ENDCLASS


METHOD New( oWndParent,nId,lVert,nLeft,nTop,nLength,bSize ) CLASS hline

   Super:New( oWndParent,nId,SS_OWNERDRAW,nLeft,nTop,,,,,bSize,{|o,lp|o:Paint(lp)} )

   ::title := ""
   ::lVert := Iif( lVert==Nil, .F., lVert )
   IF ::lVert
      ::nWidth  := 10
      ::nHeight := Iif( nLength==Nil,20,nLength )
   ELSE
      ::nWidth  := Iif( nLength==Nil,20,nLength )
      ::nHeight := 10
   ENDIF

   ::Activate()

Return Self

METHOD Activate CLASS hline
   IF !Empty(::oParent:handle )
      ::handle := hwg_CreateSep( ::oParent:handle, ::lVert, ::nLeft, ::nTop, ;
                                 ::nWidth,::nHeight )
      ::Init()
   ENDIF
Return Nil
