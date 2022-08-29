/*
 * $Id: hhyper.prg 1876 2012-08-30 19:06:41Z lfbasso $
 *
 * HWGUI - Harbour Win32 GUI library source code:
 * HStaticLink class
 *
*/

#include "hbclass.ch"
#include "common.ch"
#include "hwgui.ch"

#define _HYPERLINK_EVENT   WM_USER + 101
#define LBL_INIT           0
#define LBL_NORMAL         1
#define LBL_VISITED        2
#define LBL_MOUSEOVER      3
#define TRANSPARENT        1

*+��������������������������������������������������������������������
*+
*+    Class HStaticLink
*+
*+��������������������������������������������������������������������
*+
CLASS HStaticLink FROM HSTATIC

   DATA state, bClick
   DATA m_bFireChild INIT .F.

   DATA m_hHyperCursor INIT LoadCursor( 32649 )

   DATA m_bMouseOver INIT .F.
   DATA m_bVisited INIT .F.

   DATA m_oTextFont
   DATA m_csUrl
   DATA dc

   DATA m_sHoverColor
   DATA m_sLinkColor
   DATA m_sVisitedColor
   
   DATA allMouseOver INIT .F.
   DATA hBitmap
   DATA iStyle         INIT ST_ALIGN_HORIZ  //ST_ALIGN_HORIZ_RIGHT
   DATA lAllUnderline  INIT .T.
   DATA oFontUnder
   DATA llost INIT .F.
   DATA lOverTitle    INIT .F.
   DATA nWidthOver


CLASS VAR winclass INIT "STATIC"

   METHOD New( oWndParent, nId, nStyle, nLeft, nTop, nWidth, nHeight, cCaption, oFont, bInit, ;
               bSize, bPaint, ctooltip, tcolor, bcolor, lTransp, cLink, vColor, lColor, hColor, hbitmap, bClick )
   METHOD Redefine( oWndParent, nId, cCaption, oFont, bInit, ;
                    bSize, bPaint, ctooltip, tcolor, bcolor, lTransp, cLink, vColor, lColor, hColor )
   METHOD INIT()
   METHOD onEvent( msg, wParam, lParam )
   METHOD GoToLinkUrl( csLink )
   METHOD GetLinkText()
   METHOD SetLinkUrl( csUrl )
   METHOD GetLinkUrl()
   METHOD SetVisitedColor( sVisitedColor )
   METHOD SetHoverColor( cHoverColor )
   METHOD SetFireChild( lFlag )  INLINE ::m_bFireChild := lFlag
   METHOD OnClicked()
   METHOD OnSetCursor( pWnd, nHitTest, message )
   METHOD SetLinkText( csLinkText )
   METHOD SetLinkColor( sLinkColor )
   METHOD PAint( lpDis ) 
   METHOD OnMouseMove( nFlags, lParam )
   METHOD Resize( x, y )

ENDCLASS

METHOD New( oWndParent, nId, nStyle, nLeft, nTop, nWidth, nHeight, cCaption, oFont, bInit, ;
            bSize, bPaint, ctooltip, tcolor, bcolor, lTransp, cLink, vColor, lColor, hColor, hbitmap, bClick ) CLASS HStaticLink
   LOCAL oPrevFont
   
   nStyle := Hwg_BitOR( nStyle, SS_NOTIFY + SS_RIGHT  )
   ::lAllUnderline := IIF( EMPTY( cLink ), .F., ::lAllUnderline )
   ::title := IIF(cCaption != Nil,cCaption ,"Sygecom Home Page")
   ::hbitmap := hbitmap

   Super:New( oWndParent, nId, nStyle, nLeft, nTop, nWidth, nHeight, cCaption, oFont, bInit, ;
              bSize, bPaint, ctooltip, tcolor, bcolor, lTransp, bClick )

   DEFAULT vColor TO RGB( 5, 34, 143 )
   DEFAULT lColor TO RGB( 0, 0, 255 )
   DEFAULT hColor TO RGB( 255, 0, 0 )
   ::m_csUrl := cLink
   ::m_sHoverColor   := hColor
   ::m_sLinkColor    := lColor
   ::m_sVisitedColor := vColor

   ::state := LBL_INIT
   ::title := IIf( cCaption == Nil, "", cCaption )
   ::bClick  := bClick

   // Test The Font the underline must be 1
   IF ::oFont == NIL
      IF ::oParent:oFont != NIL
         ::oFont := HFONT():Add( ::oParent:oFont:name, ::oParent:oFont:width, ::oParent:oFont:height, ;
                                 ::oParent:oFont:weight, ::oParent:oFont:charset, ::oParent:oFont:italic, 1, ::oParent:oFont:StrikeOut )
      ELSE
         ::oFont := HFONT():Add( "Arial", 0, - 12, , , , IIF( ::lAllUnderline, 1, ), )
      ENDIF
   ELSE
      IF ::oFont:Underline  == 0 .AND. ::lAllUnderline
         oPrevFont := ::oFont
         ::oFont:Release()
         ::oFont := HFONT():Add( oPrevFont:name, oPrevFont:width, oPrevFont:height, ;
                                 oPrevFont:weight, oPrevFont:charset, oPrevFont:italic, 1, oPrevFont:StrikeOut )
      ENDIF
   ENDIF
   ::oFontUnder := HFONT():Add( ::oFont:Name, 0, ::oFont:Height, , , , 1 )
   ::nWidthOver := nWidth
   IF lTransp != NIL .AND. lTransp
      //::extStyle += WS_EX_TRANSPARENT
      ::backstyle := TRANSPARENT
   ENDIF

   ::Activate()

   RETURN Self

METHOD Redefine( oWndParent, nId, cCaption, oFont, bInit, ;
                 bSize, bPaint, ctooltip, tcolor, bcolor, lTransp, cLink, vColor, lColor, hColor )  CLASS HStaticLink
   LOCAL oPrevFont

   Super:New( oWndParent, nId, 0, 0, 0, 0, 0, oFont, bInit, ;
              bSize, bPaint, ctooltip, tcolor, bcolor )

   DEFAULT vColor TO RGB( 5, 34, 143 )
   DEFAULT lColor TO RGB( 0, 0, 255 )
   DEFAULT hColor TO RGB( 255, 0, 0 )
   ::state := LBL_INIT
   ::m_csUrl := cLink
   ::m_sHoverColor   := hColor
   ::m_sLinkColor    := lColor
   ::m_sVisitedColor := vColor

   IF ::oFont == NIL
      IF ::oParent:oFont != NIL
         ::oFont := HFONT():Add( ::oParent:oFont:name, ::oParent:oFont:width, ::oParent:oFont:height, ;
                                 ::oParent:oFont:weight, ::oParent:oFont:charset, ::oParent:oFont:italic, 1, ::oParent:oFont:StrikeOut )
      ENDIF
   ELSE
      IF ::oFont:Underline  == 0
         oPrevFont := ::oFont
         ::oFont:Release()
         ::oFont := HFONT():Add( oPrevFont:name, oPrevFont:width, oPrevFont:height, ;
                                 oPrevFont:weight, oPrevFont:charset, oPrevFont:italic, 1, oPrevFont:StrikeOut )
      ENDIF
   ENDIF

   ::title   := cCaption
   ::style   := ::nLeft := ::nTop := ::nWidth := ::nHeight := 0
   ::bClick  := bClick

   IF lTransp != NIL .AND. lTransp
      //::extStyle += WS_EX_TRANSPARENT
      ::backstyle := TRANSPARENT
   ENDIF

   //::oParent:AddEvent( STN_CLICKED, Self, { || ::onClick() } )

   RETURN Self

METHOD INIT() CLASS HStaticLink

   IF ! ::lInit

      /*
      IF ::GetParentForm():Type <= WND_MDICHILD .OR. ::TYPE = NIL
         ::nHolder := 1
         SetWindowObject( ::handle, Self )
       *  Hwg_InitWinCtrl( ::handle )
         HWG_INITSTATICPROC( ::handle )
      ENDIF
      */
      ::Resize( )
      Super:init()
      IF ::Title != NIL
         SETWINDOWTEXT( ::handle, ::title )
      ENDIF

   ENDIF

   RETURN NIL

METHOD onEvent( msg, wParam, lParam ) CLASS HStaticLink

   IF msg == WM_PAINT
      //::PAint( )
      
   ELSEIF msg == WM_MOUSEMOVE
      hwg_SetCursor( ::m_hHyperCursor )
     ::OnMouseMove( wParam, lParam )
        /*
         IF ::state != LBL_MOUSEOVER
            //::allMouseOver := .T.
      *      ::state := LBL_MOUSEOVER
            TRACKMOUSEVENT( ::handle )
          ELSE
            TRACKMOUSEVENT( ::handle, TME_HOVER + TME_LEAVE  )
         ENDIF
        */
   ELSEIF ( msg = WM_MOUSELEAVE .OR. msg = WM_NCMOUSELEAVE )
        ::state := LBL_NORMAL
   ELSEIF msg =  WM_MOUSEHOVER
   ELSEIF msg == WM_SETCURSOR
      ::OnSetCursor( msg, wParam, lParam )

   ELSEIF msg == WM_LBUTTONDOWN
      hwg_SetCursor( ::m_hHyperCursor )
      ::OnClicked()
   ELSEIF msg == WM_SIZE

   ENDIF

   RETURN - 1

METHOD GoToLinkUrl( csLink ) CLASS HStaticLink

   LOCAL hInstance := 0
   IF UPPER(alltrim(csLink))!='NOLINK'
      hInstance := SHELLEXECUTE( csLink, "open", NIL, NIL, 2 )
   ENDIF

   IF hInstance < 33
      RETURN .f.
   ENDIF

   RETURN .t.

METHOD GetLinkText() CLASS HStaticLink

   IF ( Empty( ::Title ) )
      RETURN ""
   ENDIF

   RETURN ::Title

METHOD SetLinkUrl( csUrl ) CLASS HStaticLink

   ::m_csUrl := csUrl

   RETURN NIL

METHOD GetLinkUrl() CLASS HStaticLink

   RETURN ::m_csUrl

METHOD SetVisitedColor( sVisitedColor ) CLASS HStaticLink

   ::m_sVisitedColor := sVisitedColor
   RETURN NIL

METHOD SetHoverColor( cHoverColor ) CLASS HStaticLink

   ::m_sHoverColor := cHoverColor

   RETURN NIL

METHOD OnClicked() CLASS HStaticLink
   LOCAL nCtrlID

   IF ISBLOCK( ::bClick )
      ::state := LBL_NORMAL

   ELSEIF !EMPTY( ::m_csUrl)
      IF ( ::m_bFireChild )
         nCtrlID := ::id
         ::SendMessage( ::oparent:Handle, _HYPERLINK_EVENT, nCtrlID, 0 )
      ELSE
         ::GoToLinkUrl( ::m_csUrl )
      ENDIF
      ::m_bVisited := .T.
   ENDIF
   ::state := LBL_NORMAL
   InvalidateRect( ::handle, 0 )

   RedrawWindow( ::oParent:Handle, RDW_ERASE + RDW_INVALIDATE + RDW_INTERNALPAINT  , ::nLeft, ::nTop, ::nWidth, ::nHeight )
   ::SetFocus( )

   RETURN NIL

METHOD OnSetCursor( pWnd, nHitTest, message ) CLASS HStaticLink

   HB_SYMBOL_UNUSED( pWnd )
   HB_SYMBOL_UNUSED( nHitTest )
   HB_SYMBOL_UNUSED( message )

   hwg_SetCursor( ::m_hHyperCursor )

   RETURN .t.

METHOD SetLinkText( csLinkText ) CLASS HStaticLink

   ::Title := csLinkText
   ::SetText( csLinkText )

   RETURN NIL

METHOD SetLinkColor( sLinkColor ) CLASS HStaticLink

   ::m_sLinkColor := sLinkColor

   RETURN NIL

METHOD OnMouseMove( nFlags, lParam ) CLASS HStaticLink

   LOCAL xPos
   LOCAL yPos
   LOCAL res  := .f.

   HB_SYMBOL_UNUSED( nFlags )

   IF ::state != LBL_INIT
      xPos := LOWORD( lParam )
      yPos := HIWORD( lParam )
      IF (  ! PtInRect( { 0, 0, ::nWidthOver , ::nHeight }, { xPos, yPos } ) ) .AND. ::state != LBL_MOUSEOVER
          res := .T.
      ELSE
        hwg_SetCursor( ::m_hHyperCursor )
        IF ( !  PtInRect( { 4, 4, ::nWidthover - 6, ::nHeight - 6 }, { xPos, yPos } ) )
           //ReleaseCapture()
           res := .T.
        ENDIF
      ENDIF
      IF ( res .AND. ! ::m_bVisited ) .or. ( res .AND. ::m_bVisited )
         ::state := LBL_NORMAL
         InvalidateRect( ::handle, 0 )
         RedrawWindow( ::oParent:Handle, RDW_ERASE + RDW_INVALIDATE + RDW_INTERNALPAINT , ::nLeft, ::nTop, ::nWidth, ::nHeight )
      ENDIF
      IF ( ::state == LBL_NORMAL .AND. ! res ) .or. ;
         ( ::state == LBL_NORMAL .AND. ! res .and. ::m_bVisited )
         ::state := LBL_MOUSEOVER
         InvalidateRect( ::handle, 0 )
    	    RedrawWindow( ::oParent:Handle, RDW_ERASE + RDW_INVALIDATE + RDW_INTERNALPAINT , ::nLeft, ::nTop, ::nWidth, ::nHeight )
      ENDIF

   ENDIF

   RETURN NIL

METHOD PAint( lpDis ) CLASS HStaticLink
   LOCAL drawInfo := GetDrawItemInfo( lpDis )
   LOCAL dc := drawInfo[ 3 ]
   LOCAL strtext    := ::Title
//   LOCAL nOldBkMode
   LOCAL dwFlags
//   LOCAL clrOldText
   LOCAL rcClient
//   LOCAL POLDFONT
//   LOCAL DWSTYLE
   LOCAL bHasTitle
   LOCAL aBmpSize    := IIF( ! EMPTY( ::hbitmap ), GetBitmapSize( ::hbitmap ),{0,0} )
   LOCAL itemRect    := copyrect( { drawInfo[ 4 ], drawInfo[ 5 ], drawInfo[ 6 ], drawInfo[ 7 ] } )
   LOCAL captionRect := { drawInfo[ 4 ]  , drawInfo[ 5 ], drawInfo[ 6 ] , drawInfo[ 7 ]  }
   LOCAL bmpRect
   
   IF ::state == LBL_INIT
      ::State := LBL_NORMAL
   ENDIF
   rcClient   := CopyRect( { drawInfo[ 4 ] , drawInfo[ 5 ], drawInfo[ 6 ], drawInfo[ 7 ] } )
   
   IF  ValType( ::hbitmap ) == "N"
      bHasTitle := ValType( strtext ) == "C" .and. ! Empty( strtext )
      itemRect[ 4 ] := aBmpSize[ 2 ] + 1
      bmpRect := PrepareImageRect( ::handle, dc, bHasTitle, @itemRect, @captionRect, , , ::hbitmap, ::iStyle )
      itemRect[ 4 ] := drawInfo[ 7 ]
      IF ::backstyle = TRANSPARENT
         DrawTransparentBitmap( dc, ::hbitmap, bmpRect[ 1 ], bmpRect[ 2 ] )
      ELSE
         DrawBitmap( dc, ::hbitmap, , bmpRect[ 1 ], bmpRect[ 2 ] )
      ENDIF
      rcclient[ 1 ] +=  IIF( ::iStyle = ST_ALIGN_HORIZ, aBmpSize[ 1 ] + 8, 1 )
   ENDIF
   SetBkMode( DC, ::backstyle )
   IF ::backstyle != TRANSPARENT
       SetBkColor( DC,  IIF( ::bColor = NIL, GetSysColor( COLOR_3DFACE ), ::bcolor ) )
       FillRect( dc, rcclient[ 1 ], rcclient[ 2 ], rcclient[ 3 ], rcclient[ 4 ] ) //, ::brush:handle )
   ENDIF
   dwFlags    := DT_LEFT + DT_WORDBREAK
   //dwstyle    := ::style
   dwFlags  += ( DT_VCENTER + DT_END_ELLIPSIS )
   
   //::dc:SelectObject( ::oFont:handle )
   SelectObject( dc, ::oFont:handle )
   IF ::state == LBL_NORMAL
      IF ::m_bVisited
         //::dc:SetTextColor( ::m_sVisitedColor )
         SetTextColor( DC,::m_sVisitedColor )
      ELSE
         //::dc:SetTextColor( ::m_sLinkColor )
         SetTextColor( DC, ::m_sLinkColor )
      ENDIF
   ELSEIF ::state == LBL_MOUSEOVER
      //::dc:SetTextColor( ::m_sHoverColor )
      SetTextColor( DC,::m_sHoverColor )
   ENDIF

   //::dc:DrawText( strtext, rcClient, dwFlags )
   IF ::state = LBL_MOUSEOVER .AND. ! ::lAllUnderline
      SelectObject( DC, ::oFontUnder:handle )
      DrawText( dc, strText, rcClient, dwFlags )
      SelectObject( DC, ::oFont:handle )
   ELSE
      DrawText( dc, strText, rcClient, dwFlags )
   ENDIF

  // ::dc:END()

  RETURN NIL

METHOD Resize( x, y ) CLASS HStaticLink
   //LOCAL aCoors := GetClientRect( ::handle )
   LOCAL aBmpSize, aTxtSize
   LOCAL nHeight := ::nHeight
   
   IF x != Nil .AND. x + y = 0
      RETURN Nil
   ENDIF

   x := iif( x == Nil, 0, x - ::nWidth + 1 )
   aBmpSize := IIF( ! EMPTY( ::hbitmap ), GetBitmapSize( ::hbitmap ), { 0,0 } )
   aBmpSize[ 1 ] += IIF( aBmpSize[ 1 ] > 0, 6, 0 )
   ::Move( , , ::nWidth + x , , 0 )
   aTxtSize := TxtRect( ::Title, Self )
   aTxtSize[ 2 ] += IIF( ::lAllUnderline, 0, 3 )
   IF aTxtSize[ 1 ] + 1  <  ::nWidth - aBmpSize[ 1 ] //tava 20
      ::nHeight := aTxtSize[ 2 ] + 2
   ELSE
      ::nHeight := aTxtSize[ 2 ] * 2 + 1
   ENDIF
   ::nWidthOver  := MIN( aTxtSize[ 1 ] + 1 + aBmpSize[ 1 ], ::nWidth )
   ::nHeight := MAX( ::nHeight, aTxtSize[ 2 ] )
   ::nHeight := MAX( ::nHeight, aBmpSize[ 2 ] + 4 )

   IF nHeight != ::nHeight
      ::Move( , , , ::nHeight , 0 )
      Invalidaterect( ::Handle, 0 )
   ENDIF

   RETURN Nil
