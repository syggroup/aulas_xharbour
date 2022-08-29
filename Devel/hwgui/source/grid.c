 /*
  * $Id: grid.c 1908 2012-11-27 16:16:25Z ptsarenko $
  *
  * HWGUI - Harbour Win32 GUI library source code:
  * HGrid class
  *
  * Copyright 2002 Alexander S.Kresin <alex@belacy.belgorod.su>
  * www - http://www.geocities.com/alkresin/
  * Copyright 2004 Rodrigo Moreno <rodrigo_moreno@yahoo.com>
  *
  * Extended function Copyright 2006 Luiz Rafael Culik Guimaraes <luiz@xharbour.com.br>
  */

#include "hwingui.h"
#include <commctrl.h>
#if defined(__POCC__) || defined(__XCC__)
#include <unknwn.h>
#endif
#include <shlobj.h>
#if defined(__DMC__)
#include "missing.h"
#endif
#include "hbapiitm.h"

#if defined(__MINGW32__) && !defined(CDRF_NOTIFYSUBITEMDRAW)
#define CDRF_NOTIFYSUBITEMDRAW  0x00000020
#endif

#ifndef LVM_SORTITEMSEX
#define LVM_SORTITEMSEX          (LVM_FIRST + 81)
#endif

#ifndef ListView_SortItemsEx
#define ListView_SortItemsEx(hwndLV, _pfnCompare, _lPrm) \
  (BOOL)SNDMSG((hwndLV), LVM_SORTITEMSEX, (WPARAM)(LPARAM)(_lPrm), (LPARAM)(PFNLVCOMPARE)(_pfnCompare))
#endif

//static HWND hListSort=NULL;

typedef struct tagSortInfo
{
   HWND pListControl;
   int nColumnNo;
   BOOL nAscendingSortOrder;
} SortInfo, *PSORTINFO;

LRESULT ProcessCustomDraw( LPARAM lParam, PHB_ITEM pColor );

HB_FUNC( LISTVIEW_CREATE )
{
   HWND hwnd = ( HWND ) HB_PARHANDLE( 1 );
   HWND handle;
   int style = LVS_SHOWSELALWAYS | hb_parni( 7 );

   if( hb_parl( 8 ) )
   {
      style = style | LVS_NOCOLUMNHEADER;
   }

   if( hb_parl( 9 ) )
   {
      style = style | LVS_NOSCROLL;
   }

   handle = CreateWindowEx( WS_EX_CLIENTEDGE, WC_LISTVIEW, NULL,
         style,
         hb_parni( 3 ), hb_parni( 4 ), hb_parni( 5 ), hb_parni( 6 ),
         hwnd, ( HMENU ) hb_parni( 2 ), GetModuleHandle( NULL ), NULL );

   HB_RETHANDLE( handle );
}

HB_FUNC( LISTVIEW_INIT )
{
   int style = 0;

   if( !hb_parl( 3 ) )
   {
      style = style | LVS_EX_GRIDLINES;
   }

   SendMessage( ( HWND ) HB_PARHANDLE( 1 ),
                LVM_SETEXTENDEDLISTVIEWSTYLE, 0,
                LVS_EX_FULLROWSELECT |
                LVS_EX_HEADERDRAGDROP | LVS_EX_FLATSB | style );

   ListView_SetItemCount( ( HWND ) HB_PARHANDLE( 1 ), hb_parnl( 2 ) );
}

HB_FUNC( LISTVIEW_SETITEMCOUNT )
{
   ListView_SetItemCount( ( HWND ) HB_PARHANDLE( 1 ), hb_parni( 2 ) );
}

HB_FUNC( LISTVIEW_ADDCOLUMN )
{
   LV_COLUMN COL;
   int iImage = hb_parni( 6 );
   void * hText;

   COL.mask = LVCF_WIDTH | LVCF_TEXT | LVCF_FMT | LVCF_SUBITEM;
   COL.cx = hb_parni( 3 );
   COL.pszText = ( LPTSTR ) HB_PARSTRDEF( 4, &hText, NULL );
   COL.iSubItem = hb_parni( 2 ) - 1;
   COL.fmt = hb_parni( 5 );
   if( iImage > 0 )
   {
      COL.mask = COL.mask | LVCF_IMAGE;
      COL.iImage = hb_parni( 2 ) - 1;
   }
   else
      COL.iImage = -1 ;

   ListView_InsertColumn( ( HWND ) HB_PARHANDLE( 1 ), hb_parni( 2 ) - 1, &COL );

   RedrawWindow( ( HWND ) HB_PARHANDLE( 1 ), NULL, NULL,
                 RDW_ERASE | RDW_INVALIDATE | RDW_ALLCHILDREN | RDW_ERASENOW |
                 RDW_UPDATENOW );
   hb_strfree( hText );
}

HB_FUNC( LISTVIEW_DELETECOLUMN )
{
   ListView_DeleteColumn( ( HWND ) HB_PARHANDLE( 1 ), hb_parni( 2 ) - 1 );
   RedrawWindow( ( HWND ) HB_PARHANDLE( 1 ), NULL, NULL,
                 RDW_ERASE | RDW_INVALIDATE | RDW_ALLCHILDREN | RDW_ERASENOW |
                 RDW_UPDATENOW );
}

HB_FUNC( LISTVIEW_SETBKCOLOR )
{
   ListView_SetBkColor( ( HWND ) HB_PARHANDLE( 1 ),
                        ( COLORREF ) hb_parni( 2 ) );
}

HB_FUNC( LISTVIEW_SETTEXTBKCOLOR )
{
   ListView_SetTextBkColor( ( HWND ) HB_PARHANDLE( 1 ),
                            ( COLORREF ) hb_parni( 2 ) );
}

HB_FUNC( LISTVIEW_SETTEXTCOLOR )
{
   ListView_SetTextColor( ( HWND ) HB_PARHANDLE( 1 ),
                          ( COLORREF ) hb_parni( 2 ) );
}

HB_FUNC( LISTVIEW_GETFIRSTITEM )        // Current Line
{
   hb_retni( ListView_GetNextItem( ( HWND ) HB_PARHANDLE( 1 ), -1,
                                   LVNI_ALL | LVNI_SELECTED ) + 1 );
}

HB_FUNC( LISTVIEW_GETDISPINFO )
{
   LV_DISPINFO *pDispInfo = ( LV_DISPINFO * ) HB_PARHANDLE( 1 );

   int iItem = pDispInfo->item.iItem;
   int iSubItem = pDispInfo->item.iSubItem;

   hb_reta( 2 );
   hb_storvni( iItem + 1, -1, 1 );
   hb_storvni( iSubItem + 1, -1, 2 );
}

HB_FUNC( LISTVIEW_SETDISPINFO )
{
   LV_DISPINFO *pDispInfo = ( LV_DISPINFO * ) HB_PARHANDLE( 1 );

   if( pDispInfo->item.mask & LVIF_TEXT )
   {
      HB_ITEMCOPYSTR( hb_param( 2, HB_IT_ANY ), pDispInfo->item.pszText,
                      pDispInfo->item.cchTextMax );
      pDispInfo->item.pszText[ pDispInfo->item.cchTextMax - 1 ] = 0;
   }
   // it seems these lines below are not strictly necessary for text cells
   // since we don't get a LVIF_STATE message !
   if( pDispInfo->item.iSubItem == 0 )
      pDispInfo->item.state = 2;
}

HB_FUNC( LISTVIEW_GETGRIDKEY )
{
#define pnm ((LV_KEYDOWN *) HB_PARHANDLE(1) )

   hb_retnl( ( LPARAM ) ( pnm->wVKey ) );

#undef pnm
}

HB_FUNC( LISTVIEW_GETTOPINDEX )
{
   hb_retnl( ListView_GetTopIndex( ( HWND ) HB_PARHANDLE( 1 ) ) );
}

HB_FUNC( LISTVIEW_REDRAWITEMS )
{
   hb_retnl( ListView_RedrawItems( ( HWND ) HB_PARHANDLE( 1 ), hb_parni( 2 ),
               hb_parni( 3 ) ) );
}

HB_FUNC( LISTVIEW_GETCOUNTPERPAGE )
{
   hb_retnl( ListView_GetCountPerPage( ( HWND ) HB_PARHANDLE( 1 ) ) );
}

HB_FUNC( LISTVIEW_UPDATE )
{
   ListView_Update( ( HWND ) HB_PARHANDLE( 1 ), hb_parni( 2 ) - 1 );

}

HB_FUNC( LISTVIEW_SCROLL )
{
   ListView_Scroll( ( HWND ) HB_PARHANDLE( 1 ), hb_parni( 2 ) - 1,
         hb_parni( 3 ) - 1 );
}

HB_FUNC( LISTVIEW_HITTEST )
{
   POINT point;
   LVHITTESTINFO lvhti;

   point.y = hb_parni( 2 );
   point.x = hb_parni( 3 );

   lvhti.pt = point;

   ListView_SubItemHitTest( ( HWND ) HB_PARHANDLE( 1 ), &lvhti );

   if( lvhti.flags & LVHT_ONITEM )
   {
      hb_reta( 2 );
      hb_storvni( lvhti.iItem + 1, -1, 1 );
      hb_storvni( lvhti.iSubItem + 1, -1, 2 );
   }
   else
   {
      hb_reta( 2 );
      hb_storvni( 0, -1, 1 );
      hb_storvni( 0, -1, 2 );
   }
}

HB_FUNC( GETWINDOWROW )
{
   RECT rect;
   int y;

   GetWindowRect( ( HWND ) HB_PARHANDLE( 1 ), &rect );
   y = rect.top;

   hb_retni( y );
}

HB_FUNC( GETWINDOWCOL )
{
   RECT rect;
   int x;

   GetWindowRect( ( HWND ) HB_PARHANDLE( 1 ), &rect );
   x = rect.left;

   hb_retni( x );
}

HB_FUNC( GETCURSORROW )
{
   POINT pt;

   GetCursorPos( &pt );

   hb_retni( pt.y );
}

HB_FUNC( GETCURSORCOL )
{
   POINT pt;

   GetCursorPos( &pt );

   hb_retni( pt.x );
}

HB_FUNC( LISTVIEW_SETIMAGELIST )
{
   HWND hList = ( HWND ) HB_PARHANDLE( 1 );
   HIMAGELIST p = ( HIMAGELIST ) HB_PARHANDLE( 2 );

// #ifdef __BORLANDC__
#if 1
   SendMessage( hList, LVM_SETIMAGELIST, ( WPARAM ) p,
         ( LPARAM ) LVSIL_NORMAL );
   SendMessage( hList, LVM_SETIMAGELIST, ( WPARAM ) p,
         ( LPARAM ) LVSIL_SMALL );
#else
   ListView_SetImageList( hList, ( HIMAGELIST ) p, LVSIL_NORMAL );
   ListView_SetImageList( hList, ( HIMAGELIST ) p, LVSIL_SMALL );
#endif
}

HB_FUNC( LISTVIEW_SETVIEW )
{
   HWND hWndListView = ( HWND ) HB_PARHANDLE( 1 );
   DWORD dwView = hb_parnl( 2 );

   DWORD dwStyle = GetWindowLong( hWndListView, GWL_STYLE );

   // Only set the window style if the view bits have changed.
   if( ( dwStyle & LVS_TYPEMASK ) != dwView )
   {
      SetWindowLongPtr( hWndListView,
            GWL_STYLE, ( dwStyle & ~LVS_TYPEMASK ) | dwView );
      //  RedrawWindow( (HWND) HB_PARHANDLE( 1 ), NULL , NULL , RDW_ERASE | RDW_INVALIDATE | RDW_ALLCHILDREN | RDW_ERASENOW | RDW_UPDATENOW ) ;
   }
}

HB_FUNC( LISTVIEW_ADDCOLUMNEX )
{
   HWND hwndListView = ( HWND ) HB_PARHANDLE( 1 );
   LONG lCol = hb_parnl( 2 ) - 1;
   void * hText;
   int iImage = hb_parni( 6 );
   LVCOLUMN lvcolumn;
   int iResult;

   memset( &lvcolumn, 0, sizeof( lvcolumn ) );

   if( iImage > 0 )
      lvcolumn.mask =
            LVCF_FMT | LVCF_TEXT | LVCF_SUBITEM | LVCF_IMAGE | LVCF_WIDTH;
   else
      lvcolumn.mask = LVCF_FMT | LVCF_TEXT | LVCF_SUBITEM | LVCF_WIDTH;

   lvcolumn.pszText = ( LPTSTR ) HB_PARSTR( 3, &hText, NULL );
   lvcolumn.iSubItem = lCol;
   lvcolumn.cx = hb_parni( 4 );
   lvcolumn.fmt = hb_parni( 5 );
   lvcolumn.iImage = iImage > 0 ? lCol : -1;

   if( SendMessage( ( HWND ) hwndListView, ( UINT ) LVM_INSERTCOLUMN,
               ( WPARAM ) ( int ) lCol, ( LPARAM ) & lvcolumn ) == -1 )
      iResult = 0;
   else
      iResult = 1;

   RedrawWindow( hwndListView, NULL, NULL,
                 RDW_ERASE | RDW_INVALIDATE | RDW_ALLCHILDREN | RDW_ERASENOW |
                 RDW_UPDATENOW );

   hb_retnl( iResult );
   hb_strfree( hText );
}

HB_FUNC( LISTVIEW_INSERTITEMEX )
{
   HWND hwndListView = ( HWND ) HB_PARHANDLE( 1 );
   LONG lLin = hb_parnl( 2 ) - 1;
   LONG lCol = hb_parnl( 3 ) - 1;
   int iSubItemYesNo = lCol == 0 ? 0 : 1;
   void * hText;
   int iBitMap = hb_parni( 5 );
   LVITEM lvi;
   int iResult = 0;
   RECT rect;

   GetClientRect( hwndListView, &rect );

   memset( &lvi, 0, sizeof( lvi ) );

   if( iBitMap >= 0 )
      lvi.mask = LVIF_TEXT | LVIF_IMAGE | LVIF_STATE;
   else
      lvi.mask = LVIF_TEXT | LVIF_STATE;

   lvi.iImage = iBitMap >= 0 ? lCol : -1;
   lvi.state = 0;
   lvi.stateMask = 0;
   lvi.pszText = ( LPTSTR ) HB_PARSTR( 4, &hText, NULL );
   lvi.iItem = lLin;
   lvi.iSubItem = lCol;

   switch ( iSubItemYesNo )
   {
      case 0:
         if( SendMessage( ( HWND ) hwndListView, ( UINT ) LVM_INSERTITEM,
                          ( WPARAM ) 0, ( LPARAM ) & lvi ) == -1 )
            iResult = 0;
         else
            iResult = 1;
         break;

      case 1:
         if( SendMessage( ( HWND ) hwndListView, ( UINT ) LVM_SETITEM,
                          ( WPARAM ) 0, ( LPARAM ) & lvi ) == FALSE )
            iResult = 0;
         else
            iResult = 1;
         break;
   }

// RedrawWindow( hwndListView, NULL , NULL , RDW_ERASE | RDW_INVALIDATE | RDW_ALLCHILDREN | RDW_ERASENOW | RDW_UPDATENOW ) ;
   InvalidateRect( hwndListView, &rect, TRUE );
   hb_retni( iResult );
   hb_strfree( hText );
}

HB_FUNC( LISTVIEWSELECTALL )
{
   HWND hList = ( HWND ) HB_PARHANDLE( 1 );

   ListView_SetItemState( hList, -1, 0, LVIS_SELECTED );
   SendMessage( hList, LVM_ENSUREVISIBLE, ( WPARAM ) - 1, FALSE );
   ListView_SetItemState( hList, -1, LVIS_SELECTED, LVIS_SELECTED );
   hb_retl( 1 );
}

HB_FUNC( LISTVIEWSELECTLASTITEM )
{
   HWND hList = ( HWND ) HB_PARHANDLE( 1 );
   int items;

   items = SendMessage( hList, LVM_GETITEMCOUNT, ( WPARAM ) 0, ( LPARAM ) 0 );
   items--;
   ListView_SetItemState( hList, -1, 0, LVIS_SELECTED );
   SendMessage( hList, LVM_ENSUREVISIBLE, ( WPARAM ) items, FALSE );
   ListView_SetItemState( hList, items, LVIS_SELECTED, LVIS_SELECTED );
   ListView_SetItemState( hList, items, LVIS_FOCUSED, LVIS_FOCUSED );
   hb_retl( 1 );
}

LRESULT ProcessCustomDraw( LPARAM lParam, PHB_ITEM pArray )
{
   LPNMLVCUSTOMDRAW lplvcd = ( LPNMLVCUSTOMDRAW ) lParam;
   PHB_ITEM pColor;

   switch ( lplvcd->nmcd.dwDrawStage )
   {
      case CDDS_PREPAINT:
      {
         return CDRF_NOTIFYITEMDRAW;
      }

      case CDDS_ITEMPREPAINT:
      {
         return CDRF_NOTIFYSUBITEMDRAW;
      }

      case CDDS_SUBITEM | CDDS_ITEMPREPAINT:
      {
         // LONG ptemp ;
         COLORREF ColorText;
         COLORREF ColorBack;

         pColor = hb_arrayGetItemPtr( pArray, lplvcd->iSubItem + 1 );
         ColorText = ( COLORREF ) hb_arrayGetNL( pColor, 1 );
         ColorBack = ( COLORREF ) hb_arrayGetNL( pColor, 2 );
         lplvcd->clrText = ColorText;
         lplvcd->clrTextBk = ColorBack;

         return CDRF_NEWFONT;
      }
   }
   return CDRF_DODEFAULT;
}

HB_FUNC( PROCESSCUSTU )
{
   /* HWND hWnd = ( HWND ) HB_PARHANDLE( 1 ) ; */
   LPARAM lParam = ( LPARAM ) HB_PARHANDLE( 2 );
   PHB_ITEM pColor = hb_param( 3, HB_IT_ARRAY );

   hb_retnl( ( LONG ) ProcessCustomDraw( lParam, pColor ) );
}

HB_FUNC( LISTVIEWGETITEM )
{
   HWND hList = ( HWND ) HB_PARHANDLE( 1 );
   int Index = hb_parni( 2 );
   int Index2 = hb_parni( 3 );
   LVITEM Item;
   TCHAR Buffer[ 256 ] = { 0 };

   memset( &Item, '\0', sizeof( Item ) );

   Item.mask = LVIF_TEXT | LVIF_PARAM;
   Item.iItem = Index;
   Item.iSubItem = Index2;
   Item.pszText = Buffer;
   Item.cchTextMax = HB_SIZEOFARRAY( Buffer );

   if( ListView_GetItem( hList, &Item ) )
      HB_RETSTR( Buffer );
   else
      hb_retc( NULL );
}

int CALLBACK CompareFunc( LPARAM lParam1, LPARAM lParam2, LPARAM lParamSort )
{
   PSORTINFO pSortInfo = ( PSORTINFO ) lParamSort;
   //int nResult      = 0;
   int nColumnNo = pSortInfo->nColumnNo;
   HWND pListControl = pSortInfo->pListControl;
   BOOL nAscendingSortOrder = pSortInfo->nAscendingSortOrder;
   TCHAR szA[256] = { 0 };
   TCHAR szB[256] = { 0 };
   int rc;

   ListView_GetItemText( pListControl, ( INT ) lParam1, nColumnNo, szA, HB_SIZEOFARRAY( szA ) );
   ListView_GetItemText( pListControl, ( INT ) lParam2, nColumnNo, szB, HB_SIZEOFARRAY( szB ) );

   rc = lstrcmp( szA, szB );
   if( !nAscendingSortOrder )
      rc = -rc;

   return rc;
}

HB_FUNC( LISTVIEWSORTINFONEW )
{
   //PSORTINFO p = (PSORTINFO) hb_xgrab(sizeof(SortInfo));
   //LPNMLISTVIEW phdNotify = ( LPNMLISTVIEW ) hb_parnl( 1 ) ;
   PSORTINFO p;

   if( HB_ISPOINTER( 2 ) )
   {
      return;
   }

   p = ( PSORTINFO ) hb_xgrab( sizeof( SortInfo ) );

   if( p )
   {
      p->pListControl = NULL;
      p->nColumnNo = -1;
      p->nAscendingSortOrder = FALSE;
   }
   hb_retptr( ( void * ) p );
}

HB_FUNC( LISTVIEWSORTINFOFREE )
{
   PSORTINFO p = ( PSORTINFO ) hb_parptr( 3 );

   if( p )
      hb_xfree( p );
}

HB_FUNC( LISTVIEWSORT )
{
   PSORTINFO p = ( PSORTINFO ) hb_parptr( 3 );
   LPNMLISTVIEW phdNotify = ( LPNMLISTVIEW ) HB_PARHANDLE( 2 );

   if( phdNotify->iSubItem == p->nColumnNo )
      p->nAscendingSortOrder = !p->nAscendingSortOrder;
   else
      p->nAscendingSortOrder = TRUE;

// p->nColumnNo = phdNotify->iItem;
   p->nColumnNo = phdNotify->iSubItem;
   p->pListControl = ( HWND ) HB_PARHANDLE( 1 );
   ListView_SortItemsEx( ( HWND ) HB_PARHANDLE( 1 ), CompareFunc, p );
}
