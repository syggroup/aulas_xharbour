/*
 * $Id: hexplorer.prg 1615 2012-02-22 13:53:35Z lfbasso $
 *
 * HWGUI - Harbour Win32 GUI library source code:
 *
 *
 * Copyright 2012 Luis Fernando Basso
 * www - http://
*/

// Class TExplorerBar

#include "windows.ch"
#include "guilib.ch"
#include "common.ch"
#include "hbclass.ch"


#define COLOR_BTNFACE    15
#define TRANSPARENT 1
#define TME_LEAVE         2
#define WM_MOUSELEAVE   675

//Bitmap Array Columns
#define BMP_HANDLE    1
#define BMP_BRIGHT    2
#define BMP_HASALPHA  3
#define BMP_WIDTH     4
#define BMP_HEIGHT    5

//Bitmap Array position
#define BMPDEFAULT       0
#define BMPEXPAND        1
#define BMPCOLLAP        2

#define GWL_STYLE     (-16)
#define D_HEIGHT        13

#define SM_CYSMCAPTION	51

//----------------------------------------------------------------------------//

CLASS HExplorerBar FROM HPanel

   DATA aPanels         INIT {}
   DATA nTopColor       INIT RGB( 122, 161, 230 )
   DATA nBottomColor    INIT RGB( 99, 117, 214 )
   DATA oVScroll
   DATA nVPos
   DATA nVirtualHeight
   DATA nVirtualTop
   DATA lSBVisible
   DATA lDrag
   DATA oBitMap, oSplit

   METHOD New( oWndParent, nId, nStyle, nLeft,nTop, nWidth, nHeight, bInit ,bSize,bPaint, bcolor ) CONSTRUCTOR
   METHOD AddPanel( cName, cBmpName )
   METHOD DeletePanel( nPanel ) INLINE ::aPanels[ nPanel ]:Delete()
   METHOD CheckScroll( oPanel )
   METHOD onEvent( msg, wParam, lParam )
   METHOD Paint( )
   METHOD REFRESH() INLINE REDRAWWINDOW( ::handle, 5 )
   METHOD Init()
   METHOD CoorsUpdate()
   METHOD ReSize( nWidth, nHeight )
   METHOD ShowPanel( nPanel ) INLINE ::aPanels[ nPanel ]:Show()
   METHOD HidePanel( nPanel ) INLINE ::aPanels[ nPanel ]:Hide()
   METHOD Reposition( nIndex )
   METHOD Close() INLINE ::oSplit:Release(), ::Release() //, SENDMESSAGE( ::handle, WM_CLOSE, 0, 0 )
   
ENDCLASS

//----------------------------------------------------------------------------//

METHOD New( oWndParent, nId, nStyle, nLeft,nTop, nWidth, nHeight, bInit, bSize, ;
                        bPaint, bcolor, oBitmap  )  CLASS HExplorerBar

   oWndParent := IIF( oWndParent = Nil, ::oDefaultParent, oWndParent )
   nStyle := Hwg_BitOr( IIF( nStyle == Nil, 0, nStyle ), WS_CLIPSIBLINGS + WS_CLIPCHILDREN + WS_TABSTOP + WS_VSCROLL )

   bSize := { | o | .T. }

   nTop    := IIF( nTop == Nil, 28, nTop )
   nLeft   := IIF( nLeft == Nil, 0, nLeft )
   nHeight := IIF( nHeight == Nil, oWndParent:nHeight - nTop, nHeight )
   nWidth  := IIF( nWidth == Nil, 350 , nWidth )
   IF __ObjHasMsg( oWndParent, "AOFFSET" ) .AND. oWndParent:TYPE <= WND_MDI
       nTop    := oWndParent:aOffset[ 2 ]+35
       nHeight := GetSystemMetrics( SM_CYMENU ) + GETSYSTEMMETRICS( SM_CYCAPTION ) + GETSYSTEMMETRICS( SM_CYSMCAPTION )
       nHeight := oWndParent:nHeight - ( oWndParent:aOffset[ 2 ] + oWndParent:aOffset[ 4 ] ) - nHeight +30
      * msginfo(str(nHeight)+str(ntop))
   ENDIF
   ::nVirtualTop    := 0
   ::nVirtualHeight := 0
   ::oBitmap := oBitmap

   SUPER:New( oWndParent, nId, nStyle, nLeft, nTop, nWidth, nHeight, ;
                          bInit, bSize, bPaint, bcolor )

   ::lDrag  := .F.

   ::oSplit := HSplitter():New( oWndParent, , nLeft + nWidth + 1, nTop, 10, nHeight, ;
                           , , , , { Self }, {}, .T., .T. )

   ::Anchor := 7
   ::oSplit:Anchor := 5
   RETURN Self


METHOD Init() CLASS HExplorerBar

   IF !::lInit
      Super:Init()
      ::ReSize( )
   ENDIF
   RETURN Nil

METHOD onEvent( msg, wParam, lParam ) CLASS HExplorerBar
   LOCAL aCoors, nret

   IF msg == WM_PAINT
      ::Paint()
   ELSEIF msg == WM_ERASEBKGND
      IF ::backstyle = TRANSPARENT
         SETTRANSPARENTMODE( wParam, .T. )
      ENDIF
      RETURN - 1
   ELSEIF msg == WM_SIZE
      IF ::oEmbedded != Nil
         ::oEmbedded:Resize( LoWord( lParam ), HiWord( lParam ) )
      ENDIF
      ::CoorsUpdate()
      ::RedefineScrollbars()
      ::Resize( LoWord( lParam ), HiWord( lParam ) )
      Super:Resize()
      RETURN - 1

    ELSEIF msg == WM_HSCROLL .OR. msg == WM_VSCROLL .or. msg == WM_MOUSEWHEEL
         // writelog( 'EXP-'+str(msg) + str(wParam) + str(loword(wParam))+str(hiword(wParam))+chr(13))
         IF ::nScrollBars != -1 .AND. ::bScroll = Nil
             ::ScrollHV( Self,msg,wParam,lParam )
             ::CoorsUpdate(.T.)
             IF  msg == WM_MOUSEWHEEL
                 RETURN 0
             ENDIF
         ENDIF
         onTrackScroll( Self,msg,wParam,lParam )
         RETURN - 1
   ENDIF
   IF ::bOther != Nil
      IF Valtype( nRet := Eval( ::bOther,Self,msg,wParam,lParam ) ) != "N"
         nRet := IIF( VALTYPE( nRet ) = "L" .AND. ! nRet, 0, -1 )
      ENDIF
      IF nRet >= 0
		   RETURN -1
      ENDIF
   ENDIF
   RETURN Super:onEvent( msg, wParam, lParam )


METHOD AddPanel( cName, cBmpName, nBodyHeight ) CLASS HExplorerBar
   LOCAL oPanel

   oPanel := AAdd( ::aPanels, HTaskPanel():New( Self, cName, , Len( ::aPanels ), cBmpName, nBodyHeight ) )
   ::CheckScroll( )

   RETURN oPanel


METHOD CheckScroll() CLASS HExplorerBar
   LOCAL nLastRow
   LOCAL oLastItem
   LOCAL nPos

   IF EMPTY( ::aPanels )
      RETURN Nil
   ENDIF
   ::RedefineScrollbars()
   ::Resize()

   oLastItem := ATail( ::aPanels )

   nLastRow := oLastItem:nTop + oLastItem:nHeight + ::nVirtualTop

   IF nLastRow > ::nHeight
      ::nVirtualHeight := nLastRow
      IF  (::nVirtualHeight - ::nVirtualTop) < ::nHeight
         ::nVirtualTop := ::nVirtualHeight - ::nHeight
      ENDIF
      ::lSBVisible := .T.
   ELSE
      ::nVirtualTop := 0
      ::nVirtualHeight := ::nHeight
      ::lSBVisible := .F.
   ENDIF
   RETURN nil

METHOD Paint() CLASS HExplorerBar
   LOCAL pps, hDC, aCoors, oBmpPanel
   LOCAL n

   IF ::bPaint != Nil
      Eval( ::bPaint,Self )
      RETURN Nil
   ENDIF

   pps    := DefinePaintStru()
   hDC    := BeginPaint( ::handle, pps )
   aCoors := GetClientRect( ::handle )
   
   IF ::backstyle = OPAQUE
      Gradient( hDC, aCoors[ 1 ], aCoors[ 2 ], aCoors[ 3 ], aCoors[ 4 ] -  aCoors[ 2 ], ;
                     ::nTopColor, ::nBottomColor, 1 )
   ENDIF
   DrawEdge( hDC,  aCoors[ 3 ], aCoors[ 2 ], aCoors[ 3 ], aCoors[ 4 ], BDR_RAISED + BDR_RAISEDOUTER, BF_LEFT + BF_TOP + BF_RIGHT + BF_BOTTOM)
    /*
   IF ValType( ::bPainted ) == "B"
      Eval( ::bPainted, ::hDC, ::cPS, Self )
   ENDIF
    */

   EndPaint( ::handle, pps )
   RETURN 0

//----------------------------------------------------------------------------//

METHOD  CoorsUpdate(L) CLASS HExplorerBar
   LOCAL oPanel, aCoors

   FOR Each oPanel IN ::aPanels
       aCoors := GetWindowRect( oPanel:handle )
       aCoors := ScreenToClient( ::oParent:handle, aCoors )
       oPanel:nTop :=  acoors[ 2 ] - ::nTop
   NEXT
   RETURN Nil


METHOD ReSize( x, y  ) CLASS HExplorerBar
   LOCAL oPanel, aCoors

   aCoors := GetClientRect( ::handle )
   IF LEN( ::aPanels ) = 0
     //AEVAL( ::aControls, {| o | o:Move( ,, ::nwidth, ,1 ) })
      RETURN Nil
   ENDIF
   ::CoorsUpdate()

   IF ::nHeight > ::nVirtualHeight .OR. x != Nil
      ::nVirtualHeight := ::nHeight
      ::nVirtualTop := 0

      FOR each oPanel IN ::aPanels
         IF ! oPanel:lHide
           oPanel:nWidth :=  acoors[ 3 ] - 24 //::nWidth - oPanel:nLeftMargin - ;
                                           // oPanel:nRightMargin // - GetSysMetrics( 2 )
           oPanel:nTop += ::nVirtualTop
        //   msginfo(str( oPanel:nTop) )
           oPanel:Move( , oPanel:nTop, oPanel:nWidth, , 1 )
           IF acoors[4] > ::nHeight .AND. oPanel:nTop + oPanel:nHeight > ::nHeight
               InvalidateRect( oPanel:Handle, 1 )
           ENDIF
           oPanel:UpdateRegion()
           IF x != Nil
              oPanel:Resize( x, y )
           ENDIF
         ELSE
           ::nVirtualTop -= oPanel:nHeight + oPanel:nTopMargin
         ENDIF
      NEXT
      ::nVirtualTop := 0
   ELSE
      IF GetScrollPos( ::handle, SB_VERT ) = 0
         ::nVirtualTop := 0
         ::nVirtualHeight := 0
      ENDIF
      /*
      IF x != Nil
      FOR each oPanel IN ::aPanels
         //oPanel:Resize( x, y )
       *  oPanel:Move( , , x - 24 , , 0 )
         //invalidaterect( oPanel:handle, 1 )
      NEXT
      ENDIF
      */
   ENDIF
   RETURN Nil

METHOD Reposition( nIndex ) CLASS HExplorerBar
   LOCAL oPanel ,n

   nIndex := IIF( nIndex = Nil, 1, nIndex )
   nTop :=  ::aPanels[ nIndex ]:nTop //Margin + ::aPanels[ nIndex ]:nTotalHeight
   FOR n := nIndex + 1 TO LEN ( ::aPanels )
      oPanel := ::aPanels[ n ]
      oPanel:nIndex := n - 1
      IF ! oPanel:lHide
         oPanel:nTop := nTop + ::nVirtualTop
         oPanel:Move( ,oPanel:nTop, oPanel:nWidth, , 1 )
         nTop += oPanel:nHeight + oPanel:nTopMargin
         oPanel:UpdateRegion()
      ELSE
         ::nVirtualTop -= oPanel:nHeight + oPanel:nTopMargin
      ENDIF
   NEXT
   RETURN NIL

//----------------------------------------------------------------------------//

CLASS HTaskPanel FROM HPanel

   DATA   cTitle, nIndex
   DATA   nTopMargin, nLeftMargin, nRightMargin INIT 16
   DATA   nTitleHeight     INIT 25
   DATA   nBodyHeight      //INIT 50
   DATA   lSpecial         INIT .F.
   DATA   lCollapsed       INIT .F.
   DATA   lOverTitle       INIT .F.
   DATA   lHasAlpha        INIT .F.
   DATA   aLinks           INIT {}
   DATA   nClrTextSpecial  INIT RGB( 255, 255,255 )
   DATA   nClrHover        INIT RGB( 66, 117, 220 )
   DATA   hRegion
   DATA   aBitmaps
   DATA   oBmpPanel
   DATA   oFontTitle
   DATA   nHeightHide, nTopMarginHide

   METHOD New( cTitle, oWnd, nIndex, cBmpPanel, nBodyHeight )
   METHOD Init()
   METHOD AddLink( cPrompt, bAction, cBitmap )
   METHOD AddTree()
   METHOD Delete( )
   METHOD Destroy()
//   METHOD End()       INLINE ::Destroy()
   METHOD Paint()
   METHOD onEvent( msg, wParam, lParam )
   METHOD nTotalHeight() INLINE ::nTitleHeight + ::nBodyHeight
  // METHOD KeyDown( nKey, nFlags )
   METHOD LButtonUp( nRow, nCol, nFlags )
   METHOD LoadBitmaps()
   METHOD MouseMove( nRow, nCol, nFlags )
   METHOD MouseLeave( nRow, nCol, nFlags )
   METHOD UpdateRegion()
   METHOD SetPanelBitmap( cnBmp )
   METHOD Expand( ) INLINE ::Collapsed( .T. )
   METHOD Collapsed( )
   METHOD Show( )
   METHOD Hide( )
   
ENDCLASS


METHOD New(  oParent, cTitle, nStyle, nIndex, cBmpPanel, nBodyHeight ) CLASS HTaskPanel
   LOCAL n

   DEFAULT nBodyHeight := 50

   ::cTitle  := cTitle
   ::nTop    := ::nTopMargin
   ::nBodyHeight := nBodyHeight

   IF nIndex > 0
      aEval( oParent:aPanels, { | p | ::nTop += IIF( ! p:lHide,  p:nTotalHeight + ::nTopMargin , 0 ) } )
      //::nTop += oParent:aPanels[ nIndex ]:nTop + oParent:aPanels[ nIndex ]:nTotalHeight //+ ;
               // oParent:aPanels[ nIndex ]:nTopMargin
   ENDIF
   ::nIndex := nIndex + 1
   ::nLeft   := 12 //::nLeftMargin
   ::bColor  := RGB( 214, 223, 247 )
   ::tColor  := RGB( 33, 93, 198 )

   ::LoadBitmaps()

   nStyle := Hwg_BitOr( IIF( nStyle == Nil, 0, nStyle ),  WS_CLIPSIBLINGS  + WS_TABSTOP  )
   ::nHeight := ::nTotalHeight()
   ::nWidth  := oParent:nWidth - ( ::nRightMargin + ::nLeftMargin ) + 8

   SUPER:New( oParent,, nStyle, ::nLeft, ::nTop, ::nWidth, ::nHeight, , {|| .T. }, ,::bcolor )

   ::oFont      := HFont():Add( 'Tahoma', 0, -11, 400 , , , )
   ::oFontTitle := HFont():Add( 'Tahoma', 0, -11, 600 , , , )

   ::UpdateRegion()
   ::SetPanelBitmap( cBmpPanel )

   RETURN Self

METHOD Init() CLASS HTaskPanel

   IF !::lInit
      Super:Init()
   ENDIF
   RETURN Nil

//----------------------------------------------------------------------------//

METHOD AddLink( cPrompt, bAction, cBitmap, cToolTip ) CLASS HTaskPanel
   LOCAL nTop := ::nTitleHeight + 10, n, oUrlLink , hbitmap

   IF ! Empty( ::aControls )
      FOR n := 1 to Len( ::aControls )
         nTop +=  ::aControls[ n ]:nHeight + IIF( ::aControls[ n ]:winclass = "STATIC", 3, 5 )
      NEXT
   ENDIF
   IF !EMPTY( cBitmap )
      IF ValType( cBitMap )  == "C" .AND. At(".", cBitmap) != 0 .AND. File( cBitmap )
         hbitmap := ( HBitmap():AddFile( cBitMap ) ):Handle
      ELSE
         hbitmap := ( HBitmap():AddResource( cBitMap ) ):Handle
         //hbitmap := (HBitmap():AddFile("ExpBar_rc\publicar.BMP")):handle
      ENDIF
   ENDIF
   aTxtSize := TxtRect( "V", Self )
   cLinkColor := ::nClrHover  //IIF( ::lSpecial, ::nClrTextSpecial,  ::nClrHover )
   oUrlLink := HStaticLink():New( Self ,, WS_TABSTOP, 10, nTop, ::nWidth - ::nRightMargin   , aTxtSize[ 2 ] * 1.5, ;
      cPrompt, ::oFont, ,,, ctooltip, cLinkColor ,::bColor , .T., "", , cLinkColor , ::tcolor , hbitmap )

   oUrlLink:bClick := bAction
   
   IF oUrlLink:nTop + oUrlLink:nHeight > ::nHeight
      ::nHeight := oUrlLink:nTop + oUrlLink:nHeight + 6
      ::nBodyHeight := ::nHeight - ::nTitleHeight
      ::Move( , ::nTop , , ::nheight, 1 )
      ::UpdateRegion()
   ENDIF
   *oUrlLink:bSize  := {| o, x ,y | o:Resize( x - ::nRightMargin, y ) }
   //oUrlLink:bSize  := {| o, x ,y | o:Resize( ) }
   RETURN nil

METHOD AddTree( nHeight, bAction, aBitmaps ) CLASS HTaskPanel
   LOCAL nTop := ::nTitleHeight + 10, n, oUrlLink , hbitmap
   LOCAL nHeightFull

   IF ! Empty( ::aControls )
      FOR n := 1 to Len( ::aControls )
         nTop += ::aControls[ n ]:nHeight + IIF( ::aControls[ n ]:winclass = "STATIC", 3, 5 )
      NEXT
   ENDIF
  // nHeightFull := ::nBodyHeight - ::nTitleHeight - ::nTopMargin
  // nHeight := IIF( nHeight = Nil,  nHeightFull, MIN( nheight, nHeightFull ) )
  // MSGINFO( STR( NHEIGHTFULL))
   /*
   IF !EMPTY( cBitmap )
      IF File( cBitmap )
         hbitmap := ( HBitmap():AddFile( cBitMap ) ):Handle
      ELSE
         hbitmap := ( HBitmap():AddResource( cBitMap ) ):Handle
       //  hbitmap := (HBitmap():AddFile("ExpBar_rc\nuevofolder.BMP")):handle
      ENDIF
   ENDIF
   */


   //cLinkColor := ::nClrHover  //IIF( ::lSpecial, ::nClrTextSpecial,  ::nClrHover )
  * METHOD New( oWndParent, nId, nStyle, nLeft, nTop, nWidth, nHeight, oFont, bInit, bSize, color, bcolor, ;
  *          aImages, lResour, lEditLabels, bAction, nBC, bRClick, bDblClick, lcheckbox,  bCheck, lDragDrop, bDrag, bDrop, bOther ) CLASS HTree

   IF nTop + nHeight > ::nHeight
      ::nHeight := nTop + nHeight + ::nTopMargin / 2
      ::nBodyHeight := ::nHeight - ::nTitleHeight
      ::Move( , ::nTop , , ::nheight, 1 )
      //oTree:Move( , , , ::nheight - ::nTopMargin , 1 )
      ::UpdateRegion()
   ENDIF

   oTree := HTree():New( Self ,, WS_TABSTOP, ::nLeftMargin / 2, nTop, ::nWidth - ::nRightMargin, nHeight, ::oFont, , ;
                        , ::tColor,  , aBitmaps, .t., , ,  , )  //::bcolor
   oTree:bAction := bAction
   OTREE:BACKSTYLE := 2
   __objAddMethod( oTree, "Resize", @TreeResize() )
                       /*
   IF oTree:nTop + oTree:nHeight > ::nHeight
      ::nHeight := oTree:nTop + oTree:nHeight + 16
      ::nBodyHeight := ::nHeight - ::nTitleHeight
      ::Move( , ::nTop , , ::nheight, 1 )
      //oTree:Move( , , , ::nheight - ::nTopMargin , 1 )
      ::UpdateRegion()
   ENDIF
      */

   *oTree:bSize   := {| o, x ,y | o:Move( , , x - ::nRightMargin , y - ::nTitleHeight - ::nTopMargin  , 0 ) }
   oTree:bSize   := {| o, x ,y | o:Move( , , x - ::nRightMargin ,  , 0 ) }
                            */
   RETURN oTree

METHOD Delete( ) CLASS HTaskPanel
   LOCAL nTop := 0 , n, oPanel
   
   ::lHide := .T.
   ::oParent:Reposition( ::nIndex )
   Aeval( ::aControls,{ | o | SendMessage( o:Handle, WM_CLOSE, 0, 0 ) }    )
   SendMessage( ::Handle, WM_CLOSE, 0, 0 )
   Adel( ::oParent:aPanels, ::nIndex )
   Asize( ::oParent:aPanels, Len( ::oParent:aPanels ) - 1 )
   ::oParent:nVirtualHeight -= ::nHeight
   ::lHide := .F.
   ::oParent:CheckScroll()

   RETURN NIL

METHOD Show( ) CLASS HTaskPanel
   LOCAL oPanel ,n
   
   IF ! ::lHide
      RETURN NIL
   ENDIF
   ::nHeight := ::nHeightHide
   ::nTopMargin := ::nTopMarginHide
   nTop :=  ::nTopMargin
   Super:Show()
   
   //AEVAL( ::oParent:aPanels, { | oPanel | nTop += IIF( ! oPanel:lHide, oPanel:nTop + oPanel:nHeight ,0 ) }, 1, ::nIndex - 1 )
   //::nTop := 0
   nTop += ::oParent:aPanels[ ::nIndex ]:nTop + ::oParent:aPanels[ ::nIndex ]:nTotalHeight
   FOR n := ::nIndex + 1 TO LEN ( ::oParent:aPanels )
      oPanel := ::oParent:aPanels[ n ]
      IF ! oPanel:lHide
         oPanel:nTop := nTop + ::oParent:nVirtualTop
         oPanel:Move( ,oPanel:nTop, oPanel:nWidth, , 1 )
         nTop += oPanel:nHeight + oPanel:nTopMargin
       *-  oPanel:CoorsUpdate()
         oPanel:UpdateRegion()
      ELSE
         ::oParent:nVirtualTop -= oPanel:nHeight + oPanel:nTopMargin
      ENDIF
   NEXT
   AEval( ::oParent:aPanels, { | o | InvalidateRect( o:handle, 0, o:nWidth - 1, o:nTitleHeight - 1 ) } )

   ::oParent:CheckScroll()
   RETURN NIL

METHOD Hide( ) CLASS HTaskPanel

   ::nHeightHide    := ::nHeight
   ::nTopMarginHide := ::nTopMargin
   Super:Hide()
   ::oParent:nVirtualHeight -= ::nHeight
   ::oParent:Resize()
   ::nHeight := 0
   ::nTopMargin := 0
   ::oParent:CheckScroll()
   RETURN Nil

METHOD Collapsed( lExpand ) CLASS HTaskPanel
   LOCAL n

   lExpand := IIF( lExpand = Nil, .F., lExpand )
   IF ::lCollapsed .AND. !lExpand
      RETURN Nil
   ENDIF
   ::lCollapsed := ! lExpand

   IF ::lCollapsed
      ::nHeight := ::nTitleHeight
      ::Move( ,  , , ::nheight, 1 )
      For n := ::nIndex  + 1 To Len( ::oParent:aPanels )
         IF ! ::lHide
            ::oParent:aPanels[ n ]:nTop -= ::nBodyHeight
            ::oParent:aPanels[ n ]:Move( , ::oParent:aPanels[ n ]:nTop , , , 1 )
         ENDIF
      NEXT
   ELSE
      ::nHeight := ::nTotalHeight()
      ::Move( , , , ::nheight, 1 )
      For n := ::nIndex  + 1 To Len( ::oParent:aPanels )
         IF ! ::lHide
            ::oParent:aPanels[ n ]:nTop += ::nBodyHeight
            ::oParent:aPanels[ n ]:move( , ::oParent:aPanels[ n ]:nTop , , , 1 )
         ENDIF
      NEXT
   ENDIF
   RETURN ::lCollapsed


//----------------------------------------------------------------------------//

METHOD Destroy() CLASS HTaskPanel

   AEval( ::aBitmaps,;
          { | aItem | DeleteObject( aItem[ BMP_HANDLE ] ),;
                      DeleteObject( aItem[ BMP_BRIGHT ] ) } )

   DeleteObject( ::hBmpPanel )
   DeleteObject( ::hRegion )

   RETURN NIL //Super:Destroy()

//----------------------------------------------------------------------------//

METHOD OnEvent( msg, wParam, lParam ) CLASS  HTaskPanel

   IF msg == WM_PAINT  //.AND. ! ::oParent:lSuspendMsgsHandling
      ::Paint()
      RETURN -1
   ELSEIF msg == WM_ERASEBKGND
    //   RETURN  0
   ELSEIF Msg == WM_MOUSEMOVE
       ::MouseMove(  HiWord( lParam ), LoWord( lParam ), wParam )
   ELSEIF Msg == WM_MOUSELEAVE
      RETURN ::MouseLeave( HiWord( lParam ), LoWord( lParam ), wParam )
   ELSEIF msg == WM_LBUTTONDOWN
      //::ButtonDown( lParam )

   ELSEIF msg == WM_LBUTTONUP
      ::LButtonUp(  HiWord( lParam ), LoWord( lParam ), wParam )
   ELSEIF msg == WM_SIZE
      // RETURN -1
   ENDIF

   RETURN Super:onEvent( Msg, wParam, lParam )

//----------------------------------------------------------------------------//

/*
METHOD KeyDown( nKey, nFlags ) CLASS HTaskPanel

   IF nKey == VK_TAB
      IF GetKeyState( VK_SHIFT )
         ::oWnd:GoPrevCtrl()
      ELSE
         ::oWnd:GoNextCtrl()
      ENDIF
      SysRefresh()
      ::Refresh()
      IF GetParent( GetFocus() ) == ::oWnd:hWnd
         oWndFromHwnd( GetFocus() ):Refresh()
      ENDIF
   ENDIF

RETURN nil
   */

METHOD LButtonUp( nRow, nCol, wParam ) CLASS HTaskPanel
   LOCAL n, hWndFocus, ntop

   IF nRow < ::nTitleHeight
      IF ( ::lCollapsed := ::nHeight > ::nTitleHeight )
         ::nHeight := ::nTitleHeight
         ::move( ,  , , ::nheight, 1 )
         FOR n := ::nIndex  + 1 to Len( ::oParent:aPanels )
            IF ! ::lHide
               ::oParent:aPanels[ n ]:nTop -= ::nBodyHeight
               ::oParent:aPanels[ n ]:move( , ::oParent:aPanels[ n ]:nTop , , , 1 )
            ENDIF
         NEXT
      ELSE
         ::nHeight := ::nTotalHeight()
         ::move( , , , ::nheight, 1 )
         FOR n := ::nIndex  + 1 to Len( ::oParent:aPanels )
            IF ! ::lHide
               ::oParent:aPanels[ n ]:nTop += ::nBodyHeight
               ::oParent:aPanels[ n ]:move( , ::oParent:aPanels[ n ]:nTop , , , 1 )
               InvalidateRect( :: oParent:aPanels[ n ]:handle, 1 )
            ENDIF
         NEXT
      ENDIF
      IF SelfFocus( ::handle )
         ::SetFocus( )
      ENDIF
     // AEval( ::oParent:aPanels, { | o | InvalidateRect( o:handle, 1 ,::nWidth - 1, ::nTitleHeight - 1 ) }, ::nIndex + 1 )
      ::oParent:CheckScroll()
   ENDIF
   RETURN nil


METHOD LoadBitmaps( nType, cnBitmap ) CLASS HTaskPanel
   LOCAL nWidth, nHeight, lHasAlpha
   LOCAL oBitmap

   DEFAULT nType := BMPDEFAULT

   IF nType > BMPCOLLAP .OR. nType < BMPDEFAULT
      RETURN nil
   ENDIF

   IF nType == BMPDEFAULT

      ::aBitmaps = {}
      oBitmap := HBitmap():AddStandard( OBM_UPARROW )
      *-hBitmap = BmpEBExpanded()               //HasAlpha( hBitmap:handle )
      AAdd( ::aBitmaps, { oBitmap:handle, 0, .F., oBitmap:nWidth, oBitmap:nHeight } )
                      ::aBitmaps[ BMPEXPAND ][ BMP_BRIGHT ] := oBitmap:handle //BrightImg( ::hDC, hBitmap, 90 )
      //hBitmap = BmpEBCollapsed()
      oBitmap := HBitmap():AddStandard( OBM_DNARROW )
      AAdd( ::aBitmaps, { oBitmap:handle, 0, .F., oBitmap:nWidth, oBitmap:nHeight } )
                       ::aBitmaps[ BMPCOLLAP ][ BMP_BRIGHT ] := oBitmap:handle //BrightImg( ::hDC, hBitmap, 90 )
   ELSE
      IF File( cnBitmap )
         //hBitmap = ReadBitmap( 0, cnBitmap )
         oBitmap := HBitmap():AddFile( cnBitmap )
      ELSE
        // hBitmap = LoadBitmap( GetResources(), cnBitmap )
        oBitmap := HBitmap():AddResource( cnBitmap )
      ENDIF
      hBitmap := oBitmap:handle
      nWidth  := oBitmap:nWidth
      nHeight := oBitmap:nHeight
      lHasAlpha := .F. //HasAlpha( hBitmap )
      DeleteObject( ::aBitmaps[ nType ][ BMP_HANDLE ] )
      DeleteObject( ::aBitmaps[ nType ][ BMP_BRIGHT ] )
      ::aBitmaps[ nType ] = { hBitmap, , lHasAlpha, nWidth, nHeight }
      //::aBitmaps[ nType ][ BMP_BRIGHT ] = BrightImg( ::hDC, hBitmap, 2 )
   ENDIF

   RETURN nil

METHOD MouseLeave( nRow, nCol, wParam ) CLASS HTaskPanel

   ::lOverTitle := .F.
   InvalidateRect( ::handle, 1 , 1, 1, ::nWidth - 1, ::nTitleHeight - 1 )

   RETURN 0

METHOD MouseMove( nRow, nCol, wParam ) CLASS HTaskPanel
   LOCAL lOverTitle := ::lOverTitle
   
   IF ( ::lOverTitle := nRow < ::nTitleHeight )
     // CursorHand()
      downCursor := LoadCursor( IDC_HAND )
      Hwg_SetCursor( downCursor )
      IF lOverTitle != ::lOverTitle
         InvalidateRect( ::handle, 1 , 1, 1, ::nWidth - 1 , ::nTitleHeight - 1 )
      ENDIF
   ELSE
     // CursorArrow()
      arrowCursor := LoadCursor( IDC_ARROW )
      Hwg_SetCursor( arrowCursor )
   ENDIF
   TRACKMOUSEVENT( ::handle,  TME_LEAVE ) //TME_HOVER

   RETURN 0

//----------------------------------------------------------------------------//

METHOD Paint( ) CLASS HTaskPanel
   LOCAL pps, hDC, aCoors
   LOCAL oItem, n, brush

   pps := DefinePaintStru()
   hDC := BeginPaint( ::handle, pps )
   aCoors := GetClientRect( ::handle )

   Gradient( hDC, ::nLeft , ::nTop, ::nWidth - 1, ::nTitleHeight , ;
                IIF( ::lSpecial, RGB( 0, 73, 181 ), Rgb( 255, 255, 255 ) ), ;
                IIF( ::lSpecial, RGB( 41, 93, 206 ), RGB( 198, 211, 247 ) ), , 0 )

   /*
   IF !Empty( ::oBmpPanel )
      //ABPaint(hDC, Left, Top, hBitmap, nTranspLevel)
      IF ::lHasAlpha
         DrawBitmap( hDC, ::oBmpPanel:handle, ,  ;
                  - ::oBmpPanel:nWidth / 3,;
                  - ::oBmpPanel:nHeight / 3, , , 255 )
      ELSE
         DrawTransparentBitMap( hDC, ::oBmpPanel:handle,;
                                   - ::oBmpPanel:nWidth / 3 , ;
                                   - ::oBmpPanel:nHeight / 3 , 255 )
      ENDIF
   ENDIF
   */

   SetBkMode( hDc, TRANSPARENT )
   SetTextColor( hDC, IIF( ::lSpecial, IIF( ::lOverTitle, ::nClrHover, ::nClrTextSpecial ), ;
                      IIF( ::lOverTitle,::nClrHover, ::tColor )) )
   SelectObject( hDC, ::oFonttitle:handle )
   dwText := DT_LEFT + DT_SINGLELINE
   DrawText( hDc, ::cTiTle, { 15, 6, ::nWidth - ::aBitmaps[ BMPEXPAND ][ BMP_WIDTH ] - ::nRightMargin +  2 , ::nTitleHeight } ,dwtext )
   SelectObject( hDC, ::oFont:handle )

 //  IF Empty( ::oBmpPanel )
   brush := IIF( ::lSpecial, HBrush():Add( RGB( 239,243,255 ) ), ::Brush )
   FillRect( hDC, 0, ::nTitleHeight, ::nWidth - 1, ::nTitleHeight + ::nBodyHeight + 1 ,;
                      Brush:handle )
 //  ENDIF

   IF ::lCollapsed
          * DrawBitmap( hDC, hBitmap, style, x, y, width, height )
          * DrawTransparentBitmap( hDC, hBitmap, x, y [,trColor] )
      IF ::aBitmaps[ BMPEXPAND ][ BMP_HASALPHA ]
         DrawBitMap( hDC, [::aBitmaps[ BMPEXPAND ][ IIF( ! ::lOverTitle, BMP_HANDLE, BMP_BRIGHT ) ],,;
                     ::nWidth - ::aBitmaps[ BMPEXPAND ][ BMP_WIDTH ] * 1.35, 4,;
                    ::aBitmaps[ BMPEXPAND ][ BMP_WIDTH ],::aBitmaps[BMPEXPAND ][ BMP_HEIGHT ], 255)

      ELSE
         DrawTransparentBitMap( hDC, ::aBitmaps[ BMPEXPAND ][ IIF( ! ::lOverTitle, BMP_HANDLE, BMP_BRIGHT ) ],;
                                ::nWidth - ::aBitmaps[ BMPEXPAND ][ BMP_WIDTH ] * 1.35, 4, 255 )
      ENDIF
   ELSE
      IF ::aBitmaps[ BMPCOLLAP ][ BMP_HASALPHA ]
         DrawBitMap( hDC, ::aBitmaps[ BMPCOLLAP ][ IIF( ! ::lOverTitle, BMP_HANDLE, BMP_BRIGHT ) ],, ;
                   ::nWidth - ::aBitmaps[ BMPCOLLAP ][ BMP_WIDTH ] * 1.35, 4, ;
                   ::aBitmaps[ BMPCOLLAP ][ BMP_WIDTH ],::aBitmaps[ BMPCOLLAP ][ BMP_HEIGHT ],255)
      ELSE
         DrawTransparentBitMap( hDC, ::aBitmaps[ BMPCOLLAP ][ iIF( ! ::lOverTitle, BMP_HANDLE, BMP_BRIGHT ) ],;
                          ::nWidth - ::aBitmaps[ BMPCOLLAP ][ BMP_WIDTH ] * 1.35, 4 , 255)
      ENDIF
    ENDIF
    IF !Empty( ::oBmpPanel )
      //ABPaint(hDC, Left, Top, hBitmap, nTranspLevel)
       IF ::lHasAlpha
          DrawBitmap( hDC, ::oBmpPanel:handle, ,  ;
                     ::oBmpPanel:nWidth -  ::oBmpPanel:nWidth / 3,;
                     ::oBmpPanel:nHeight -  ::oBmpPanel:nHeight / 3  )
       ELSE
          DrawTransparentBitMap( hDC, ::oBmpPanel:handle,;
                               ::oBmpPanel:nWidth - ::oBmpPanel:nWidth / 3 , ;
                               ::oBmpPanel:nHeight - ::oBmpPanel:nHeight / 3 , 255 )
      ENDIF
   ENDIF
   IF ! Empty( ::aControls )
      AEval( ::aControls, { | oControl | oControl:Refresh() } )
   ENDIF

   EndPaint( ::handle, pps )

   RETURN 1

//----------------------------------------------------------------------------//

METHOD SetPanelBitmap( cnBitmap ) CLASS HTaskPanel


//   ::hBmpPanel = fnAddBitmap( cnBitmap, hInstance )
   IF !EMPTY( cnBitMap )
      IF File( cnBitmap )
        ::oBmpPanel := HBitmap():AddFile( cnBitmap )
      ELSE
        ::oBmpPanel := HBitmap():AddResource( cnBitmap )
      ENDIF
      ::lHasAlpha := .t. // HasAlpha( ::oBmpPanel:handle )
   ENDIF
   RETURN Nil


METHOD UpdateRegion() CLASS HTaskPanel

   IF ! Empty( ::hRegion )
      DeleteObject( ::hRegion )
      ::hRegion = nil
   ENDIF
   ::hRegion = CreateRoundRectRgn( 0, 0, ::nWidth, ::nTitleHeight + ::nBodyHeight + 14,;
                                     6, 6 )
   SetWindowRgn( ::handle, ::hRegion )
   RETURN nil

STATIC FUNCTION TreeResize
   RETURN Nil
