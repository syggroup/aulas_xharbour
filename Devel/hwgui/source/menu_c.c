/*
 * $Id: menu_c.c 1819 2011-12-26 11:17:03Z LFBASSO $
 *
 * HWGUI - Harbour Win32 GUI library source code:
 * C level menu functions
 *
 * Copyright 2001 Alexander S.Kresin <alex@belacy.belgorod.su>
 * www - http://kresin.belgorod.su
*/

#define OEMRESOURCE
#include "hwingui.h"
#include <commctrl.h>
#ifdef __DMC__
  #define MIIM_BITMAP     0x00000080
#endif
#include "hbapiitm.h"
#include "hbvm.h"
#include "hbstack.h"

#define  FLAG_DISABLED   1

/*
 *  CreateMenu() --> hMenu
 */
HB_FUNC( HWG__CREATEMENU )
{
   HMENU hMenu = CreateMenu();
   HB_RETHANDLE( hMenu );
}

HB_FUNC( HWG__CREATEPOPUPMENU )
{
   HMENU hMenu = CreatePopupMenu();
   HB_RETHANDLE( hMenu );
}

/*
 *  AddMenuItem( hMenu,cCaption,nPos,fByPosition,nId,fState,lSubMenu ) --> lResult
 */

HB_FUNC( HWG__ADDMENUITEM )
{
   UINT uFlags = MF_BYPOSITION;
   void * hNewItem;
   LPCTSTR lpNewItem;
   int nPos;
   MENUITEMINFO mii;


   if( !HB_ISNIL( 6 ) && ( hb_parni( 6 ) & FLAG_DISABLED ) )
   {
      uFlags |= MFS_DISABLED;
   }

   lpNewItem = HB_PARSTR( 2, &hNewItem, NULL );
   if( lpNewItem )
   {
      BOOL lString = 0;
      LPCTSTR ptr = lpNewItem;

      while( *ptr )
      {
         if( *ptr != ' ' && *ptr != '-' )
         {
            lString = 1;
            break;
         }
         ptr++;
      }
      uFlags |= ( lString ) ? MF_STRING : MF_SEPARATOR;
   }
   else
      uFlags |= MF_SEPARATOR;

   if( hb_parl( 7 ) )
   {
      HMENU hSubMenu = CreateMenu();

      uFlags |= MF_POPUP;
      InsertMenu( ( HMENU ) HB_PARHANDLE( 1 ), hb_parni( 3 ), uFlags,   // menu item flags
                  ( UINT ) hSubMenu,  // menu item identifier or handle of drop-down menu or submenu
                  lpNewItem           // menu item content
                );
      HB_RETHANDLE( hSubMenu );

      // Code to set the ID of submenus, the API seems to assume that you wouldn't really want to,
      // but if you are used to getting help via IDs for popups in 16bit, then this will help you.
      nPos = GetMenuItemCount( ( HMENU ) HB_PARHANDLE( 1 ) );
      mii.cbSize = sizeof( MENUITEMINFO );
      mii.fMask = MIIM_ID;
      if( GetMenuItemInfo( ( HMENU ) HB_PARHANDLE( 1 ), nPos - 1, TRUE,
                  &mii ) )
      {
         mii.wID = hb_parni( 5 );
         SetMenuItemInfo( ( HMENU ) HB_PARHANDLE( 1 ), nPos - 1, TRUE, &mii );
      }
   }
   else
   {
      InsertMenu( ( HMENU ) HB_PARHANDLE( 1 ), hb_parni( 3 ), uFlags,   // menu item flags
                  hb_parni( 5 ),      // menu item identifier or handle of drop-down menu or submenu
                  lpNewItem           // menu item content
                );
      hb_retnl( 0 );
   }
   hb_strfree( hNewItem );
}

/*
HB_FUNC( HWG__ADDMENUITEM )
{

   MENUITEMINFO mii;
   BOOL fByPosition = ( HB_ISNIL(4) )? 0:(BOOL) hb_parl(4);
   void * hData;

   mii.cbSize = sizeof( MENUITEMINFO );
   mii.fMask = MIIM_TYPE | MIIM_STATE | MIIM_ID;
   mii.fState = ( HB_ISNIL(6) || hb_parl( 6 ) )? 0:MFS_DISABLED;
   mii.wID = hb_parni( 5 );
   if( HB_ISCHAR( 2 ) )
   {
      mii.dwTypeData = ( LPTSTR ) HB_PARSTR( 2, &hData, NULL );
      mii.cch = strlen( mii.dwTypeData );
      mii.fType = MFT_STRING;
   }
   else
      mii.fType = MFT_SEPARATOR;

   hb_retl( InsertMenuItem( ( HMENU ) HB_PARHANDLE( 1 ),
                            hb_parni( 3 ), fByPosition, &mii
                          ) );
   hb_strfree( hData );
}
*/

/*
 *  CreateSubMenu( hMenu, nMenuId ) --> hSubMenu
 */
HB_FUNC( HWG__CREATESUBMENU )
{

   MENUITEMINFO mii;
   HMENU hSubMenu = CreateMenu();

   mii.cbSize = sizeof( MENUITEMINFO );
   mii.fMask = MIIM_SUBMENU;
   mii.hSubMenu = hSubMenu;

   if( SetMenuItemInfo( ( HMENU ) HB_PARHANDLE( 1 ), hb_parni( 2 ), 0,
               &mii ) )
      HB_RETHANDLE( hSubMenu );
   else
      HB_RETHANDLE( NULL );
}

/*
 *  SetMenu( hWnd, hMenu ) --> lResult
 */
HB_FUNC( HWG__SETMENU )
{
   hb_retl( SetMenu( ( HWND ) HB_PARHANDLE( 1 ),
               ( HMENU ) HB_PARHANDLE( 2 ) ) );
}

HB_FUNC( GETMENUHANDLE )
{
   HWND handle = ( hb_pcount() > 0 &&
         !HB_ISNIL( 1 ) ) ? ( HWND ) HB_PARHANDLE( 1 ) : aWindows[0];
   HB_RETHANDLE( GetMenu( handle ) );
}

HB_FUNC( CHECKMENUITEM )
{
   HMENU hMenu;
   UINT uCheck = ( hb_pcount() < 3 || !HB_ISLOG( 3 ) ||
         hb_parl( 3 ) ) ? MF_CHECKED : MF_UNCHECKED;

   if( HB_ISOBJECT( 1 ) )
   {
      PHB_ITEM pObject = hb_param( 1, HB_IT_OBJECT );
      hMenu = ( HMENU ) HB_GETHANDLE( GetObjectVar( pObject, "HANDLE" ) );
   }
   else
   {
      HWND handle = ( hb_pcount() > 0 &&
            !HB_ISNIL( 1 ) ) ? ( ( HWND ) HB_PARHANDLE( 1 ) ) : aWindows[0];
      hMenu = GetMenu( handle );
   }
   if( !hMenu )
      hMenu = ( HMENU ) HB_PARHANDLE( 1 );

   if( !hMenu )
      MessageBox( GetActiveWindow(), TEXT( "" ), TEXT( "No Menu!" ),
                  MB_OK | MB_ICONINFORMATION );
   else
   {
      CheckMenuItem( hMenu,     // handle to menu
            hb_parni( 2 ),      // menu item to check or uncheck
            MF_BYCOMMAND | uCheck       // menu item flags
             );
   }
}

HB_FUNC( ISCHECKEDMENUITEM )
{
   HMENU hMenu;
   UINT uCheck;

   if( HB_ISOBJECT( 1 ) )
   {
      PHB_ITEM pObject = hb_param( 1, HB_IT_OBJECT );
      hMenu = ( HMENU ) HB_GETHANDLE( GetObjectVar( pObject, "HANDLE" ) );
   }
   else
   {
      HWND handle = ( hb_pcount() > 0 &&
            !HB_ISNIL( 1 ) ) ? ( ( HWND ) HB_PARHANDLE( 1 ) ) : aWindows[0];
      hMenu = GetMenu( handle );
   }
   if( !hMenu )
      hMenu = ( HMENU ) HB_PARHANDLE( 1 );

   if( !hMenu )
      hb_retl( 0 );
   else
   {
      uCheck = GetMenuState( hMenu,     // handle to menu
            hb_parni( 2 ),      // menu item to check or uncheck
            MF_BYCOMMAND        // menu item flags
             );
      hb_retl( uCheck & MF_CHECKED );
   }
}

HB_FUNC( ENABLEMENUITEM )
{
   HMENU hMenu;                 // = ( hb_pcount()>0 && !HB_ISNIL(1) )? (( HMENU ) HB_PARHANDLE(1)) : GetMenu(aWindows[0]);
   UINT uEnable = ( hb_pcount() < 3 || !HB_ISLOG( 3 ) ||
         hb_parl( 3 ) ) ? MF_ENABLED : MF_GRAYED;
   UINT uFlag = ( hb_pcount() < 4 || !HB_ISLOG( 4 ) ||
         hb_parl( 4 ) ) ? MF_BYCOMMAND : MF_BYPOSITION;

   if( HB_ISOBJECT( 1 ) )
   {
      PHB_ITEM pObject = hb_param( 1, HB_IT_OBJECT );
      hMenu = ( HMENU ) HB_GETHANDLE( GetObjectVar( pObject, "HANDLE" ) );
   }
   else
   {
      HWND handle = ( hb_pcount() > 0 &&
            !HB_ISNIL( 1 ) ) ? ( ( HWND ) HB_PARHANDLE( 1 ) ) : aWindows[0];
      hMenu = GetMenu( handle );
   }
   if( !hMenu )
      hMenu = ( HMENU ) HB_PARHANDLE( 1 );

   if( !hMenu )
   {
      MessageBox( GetActiveWindow(), TEXT( "" ), TEXT( "No Menu!" ),
                  MB_OK | MB_ICONINFORMATION );
      HB_RETHANDLE( NULL );
   }
   else
   {
      HB_RETHANDLE( EnableMenuItem( hMenu,      // handle to menu
                  hb_parni( 2 ),        // menu item to check or uncheck
                  uFlag | uEnable       // menu item flags
             ) );
   }
}

HB_FUNC( ISENABLEDMENUITEM )
{
   HMENU hMenu;                 // = ( hb_pcount()>0 && !HB_ISNIL(1) )? (( HMENU ) HB_PARHANDLE(1)):GetMenu(aWindows[0]);
   UINT uCheck;
   UINT uFlag = ( hb_pcount() < 3 || !HB_ISLOG( 3 ) ||
         hb_parl( 3 ) ) ? MF_BYCOMMAND : MF_BYPOSITION;

   if( HB_ISOBJECT( 1 ) )
   {
      PHB_ITEM pObject = hb_param( 1, HB_IT_OBJECT );
      hMenu = ( HMENU ) HB_GETHANDLE( GetObjectVar( pObject, "HANDLE" ) );
   }
   else
   {
      HWND handle = ( hb_pcount() > 0 &&
            !HB_ISNIL( 1 ) ) ? ( ( HWND ) HB_PARHANDLE( 1 ) ) : aWindows[0];
      hMenu = GetMenu( handle );
   }
   if( !hMenu )
      hMenu = ( HMENU ) HB_PARHANDLE( 1 );

   if( !hMenu )
      hb_retl( 0 );
   else
   {
      uCheck = GetMenuState( hMenu,     // handle to menu
            hb_parni( 2 ),      // menu item to check or uncheck
            uFlag               // menu item flags
             );
      hb_retl( !( uCheck & MF_GRAYED ) );
   }
}

HB_FUNC( HWG_DELETEMENU )
{
   HMENU hMenu = ( hb_pcount() > 0 &&
         !HB_ISNIL( 1 ) ) ? ( ( HMENU ) HB_PARHANDLE( 1 ) ) :
         GetMenu( aWindows[0] );

   if( hMenu )
   {
      DeleteMenu( hMenu,        // handle to menu
            hb_parni( 2 ),      // menu item id to delete
            MF_BYCOMMAND        // menu item flags
             );
   }
}

HB_FUNC( HWG_TRACKMENU )
{
   HWND hWnd = ( HWND ) HB_PARHANDLE( 4 );
   SetForegroundWindow( hWnd );
   hb_retl( TrackPopupMenu( ( HMENU ) HB_PARHANDLE( 1 ),        // handle of shortcut menu
               HB_ISNIL( 5 ) ? TPM_RIGHTALIGN : hb_parni( 5 ),     // screen-position and mouse-button flags
               hb_parni( 2 ),   // horizontal position, in screen coordinates
               hb_parni( 3 ),   // vertical position, in screen coordinates
               0,               // reserved, must be zero
               hWnd,            // handle of owner window
               NULL ) );
   PostMessage( hWnd, 0, 0, 0 );

}

HB_FUNC( HWG_DESTROYMENU )
{
   hb_retl( DestroyMenu( ( HMENU ) HB_PARHANDLE( 1 ) ) );
}

/*
 * CreateAcceleratorTable( _aAccel )
 */
HB_FUNC( CREATEACCELERATORTABLE )
{
   PHB_ITEM pArray = hb_param( 1, HB_IT_ARRAY ), pSubArr;
   LPACCEL lpaccl;
   ULONG ul, ulEntries = hb_arrayLen( pArray );
   HACCEL h;

   lpaccl = ( LPACCEL ) hb_xgrab( sizeof( ACCEL ) * ulEntries );

   for( ul = 1; ul <= ulEntries; ul++ )
   {
      pSubArr = hb_arrayGetItemPtr( pArray, ul );
      lpaccl[ul - 1].fVirt =
            ( BYTE ) hb_arrayGetNL( pSubArr, 1 ) | FNOINVERT | FVIRTKEY;
      lpaccl[ul - 1].key = ( WORD ) hb_arrayGetNL( pSubArr, 2 );
      lpaccl[ul - 1].cmd = ( WORD ) hb_arrayGetNL( pSubArr, 3 );
   }
   h = CreateAcceleratorTable( lpaccl, ( int ) ulEntries );

   hb_xfree( lpaccl );
   HB_RETHANDLE( h );
}

/*
 * DestroyAcceleratorTable( hAccel )
 */
HB_FUNC( DESTROYACCELERATORTABLE )
{
   hb_retl( DestroyAcceleratorTable( ( HACCEL ) hb_parnl( 1 ) ) );
}

HB_FUNC( DRAWMENUBAR )
{
   hb_retl( ( BOOL ) DrawMenuBar( ( HWND ) HB_PARHANDLE( 1 ) ) );
}

/*
 *  GetMenuCaption( hWnd | oWnd, nMenuId )
 */

HB_FUNC( GETMENUCAPTION )
{
   HMENU hMenu;

   if( HB_ISOBJECT( 1 ) )
   {
      PHB_ITEM pObject = hb_param( 1, HB_IT_OBJECT );
      hMenu = ( HMENU ) HB_GETHANDLE( GetObjectVar( pObject, "HANDLE" ) );
   }
   else
   {
      HWND handle = ( hb_pcount() > 0 &&
            !HB_ISNIL( 1 ) ) ? ( ( HWND ) HB_PARHANDLE( 1 ) ) : aWindows[0];
      hMenu = GetMenu( handle );
   }
   if( !hMenu )
      hMenu = ( HMENU ) HB_PARHANDLE( 1 );

   if( !hMenu )
   {
      MessageBox( GetActiveWindow(), TEXT( "" ), TEXT( "No Menu!" ),
                  MB_OK | MB_ICONINFORMATION );
      hb_retl( 0 );
   }
   else
   {
      MENUITEMINFO mii;
      LPTSTR lpBuffer;

      memset( &mii.cbSize, 0, sizeof( MENUITEMINFO ) );
      mii.cbSize = sizeof( MENUITEMINFO );
      mii.fMask = MIIM_TYPE;
      mii.fType = MFT_STRING;
      GetMenuItemInfo( hMenu, hb_parni( 2 ), 0, &mii );
      mii.cch++;
      lpBuffer = ( LPTSTR ) hb_xgrab( mii.cch * sizeof( TCHAR ) );
      lpBuffer[ 0 ] = '\0';
      mii.dwTypeData = lpBuffer;
      if( GetMenuItemInfo( hMenu, hb_parni( 2 ), 0, &mii ) )
         HB_RETSTR( mii.dwTypeData );
      else
         hb_retc( "Error" );
      hb_xfree( lpBuffer );
   }
}

/*
 *  SetMenuCaption( hWnd | oWnd, nMenuId, cCaption )
 */
HB_FUNC( SETMENUCAPTION )
{
   HMENU hMenu;

   if( HB_ISOBJECT( 1 ) )
   {
      PHB_ITEM pObject = hb_param( 1, HB_IT_OBJECT );
      hMenu = ( HMENU ) HB_GETHANDLE( GetObjectVar( pObject, "HANDLE" ) );
   }
   else
   {
      HWND handle = ( hb_pcount() > 0 &&
            !HB_ISNIL( 1 ) ) ? ( ( HWND ) HB_PARHANDLE( 1 ) ) : aWindows[0];
      hMenu = GetMenu( handle );
   }
   if( !hMenu )
      hMenu = ( HMENU ) HB_PARHANDLE( 1 );

   if( !hMenu )
   {
      MessageBox( GetActiveWindow(), TEXT( "" ), TEXT( "No Menu!" ),
                  MB_OK | MB_ICONINFORMATION );
      hb_retl( 0 );
   }
   else
   {
      MENUITEMINFO mii;
      void * hData;
      mii.cbSize = sizeof( MENUITEMINFO );
      mii.fMask = MIIM_TYPE;
      mii.fType = MFT_STRING;
      mii.dwTypeData = ( LPTSTR ) HB_PARSTR( 3, &hData, NULL );

      if( SetMenuItemInfo( hMenu, hb_parni( 2 ), 0, &mii ) )
         hb_retl( 1 );
      else
         hb_retl( 0 );
      hb_strfree( hData );
   }
}

HB_FUNC( SETMENUITEMBITMAPS )
{
   hb_retl( SetMenuItemBitmaps( ( HMENU ) HB_PARHANDLE( 1 ), hb_parni( 2 ),
                                MF_BYCOMMAND, ( HBITMAP ) HB_PARHANDLE( 3 ),
                                ( HBITMAP ) HB_PARHANDLE( 4 ) ) );
}

HB_FUNC( GETMENUCHECKMARKDIMENSIONS )
{
   hb_retnl( ( LONG ) GetMenuCheckMarkDimensions() );
}


HB_FUNC( GETSIZEMENUBITMAPWIDTH )
{
   hb_retni( GetSystemMetrics( SM_CXMENUSIZE ) );
}

HB_FUNC( GETSIZEMENUBITMAPHEIGHT )
{
   hb_retni( GetSystemMetrics( SM_CYMENUSIZE ) );
}

HB_FUNC( GETMENUCHECKMARKWIDTH )
{
   hb_retni( GetSystemMetrics( SM_CXMENUCHECK ) );
}

HB_FUNC( GETMENUCHECKMARKHEIGHT )
{
   hb_retni( GetSystemMetrics( SM_CYMENUCHECK ) );
}

HB_FUNC( STRETCHBLT )
{
   hb_retl( StretchBlt( ( HDC ) HB_PARHANDLE( 1 ),
               hb_parni( 2 ),
               hb_parni( 3 ),
               hb_parni( 4 ),
               hb_parni( 5 ),
               ( HDC ) HB_PARHANDLE( 6 ),
               hb_parni( 7 ),
               hb_parni( 8 ),
               hb_parni( 9 ), hb_parni( 10 ), ( DWORD ) hb_parnl( 11 ) ) );
}


HB_FUNC( HWG__INSERTBITMAPMENU )
{
   MENUITEMINFO mii;

   mii.cbSize = sizeof( MENUITEMINFO );
   mii.fMask = MIIM_ID | MIIM_BITMAP | MIIM_DATA;
   mii.hbmpItem = ( HBITMAP ) HB_PARHANDLE( 3 );

   hb_retl( ( LONG ) SetMenuItemInfo( ( HMENU ) HB_PARHANDLE( 1 ),
                                      hb_parni( 2 ), 0, &mii ) );
}

HB_FUNC( CHANGEMENU )
{
   void * hStr;
   hb_retl( ChangeMenu( ( HMENU ) HB_PARHANDLE( 1 ), ( UINT ) hb_parni( 2 ),
                        HB_PARSTR( 3, &hStr, NULL ), ( UINT ) hb_parni( 4 ),
                        ( UINT ) hb_parni( 5 ) ) );
   hb_strfree( hStr );
}

HB_FUNC( MODIFYMENU )
{
   void * hStr;
   hb_retl( ModifyMenu( ( HMENU ) HB_PARHANDLE( 1 ), ( UINT ) hb_parni( 2 ),
                        ( UINT ) hb_parni( 3 ), ( UINT ) hb_parni( 4 ),
                        HB_PARSTR( 5, &hStr, NULL ) ) );
   hb_strfree( hStr );
}


HB_FUNC( ENABLEMENUSYSTEMITEM )
{
   HMENU hMenu; 
   UINT  uEnable = ( hb_pcount() < 3 || !HB_ISLOG( 3 ) || hb_parl( 3 ) )? MF_ENABLED:MF_GRAYED;
   UINT  uFlag = ( hb_pcount() < 4 || !HB_ISLOG( 4 ) || hb_parl( 4 ) )? MF_BYCOMMAND:MF_BYPOSITION;

   hMenu = ( HMENU ) GetSystemMenu( ( HWND ) HB_PARHANDLE( 1 ), 0 ) ;
   if( !hMenu )
   {
      HB_RETHANDLE( NULL );
   }
   else
   {
      HB_RETHANDLE( EnableMenuItem(
                                    hMenu,            // handle to menu
                                    hb_parni( 2 ),    // menu item to check or uncheck
                                    uFlag | uEnable   // menu item flags
                                  ) );
   }
}


HB_FUNC( HWG_SETMENUINFO )
{
 
   HMENU hMenu; 
   MENUINFO mi;
   HBRUSH hbrush;
   
   if( HB_ISOBJECT( 1 ) )
   {
      PHB_ITEM pObject = hb_param( 1, HB_IT_OBJECT );
      hMenu = ( HMENU ) HB_GETHANDLE( GetObjectVar( pObject, "HANDLE" ) );
   }
   else
   {
      HWND handle = ( hb_pcount() > 0 &&
            ! HB_ISNIL( 1 ) ) ? ( ( HWND ) HB_PARHANDLE( 1 ) ) : aWindows[0];
      hMenu = GetMenu( handle );
   }
   if( !hMenu )
      hMenu = ( HMENU ) HB_PARHANDLE( 1 );
   if( hMenu )
   {
      hbrush = hb_pcount() > 1 && ! HB_ISNIL( 2 ) ? CreateSolidBrush( ( COLORREF ) hb_parnl( 2 ) ) : NULL ; 
      mi.cbSize          = sizeof( mi );
      mi.fMask           = MIM_APPLYTOSUBMENUS | MIM_BACKGROUND ;
      mi.hbrBack         = hbrush;
      SetMenuInfo( hMenu, &mi );
   } 
}

//-------------------------------------------
//_colorMenu(ownd:hwnd,RGB(163,194,245),.f.)

HB_FUNC ( _COLORMENU )
{
   HMENU      iMenu;
   MENUINFO   iMenuInfo ;
   COLORREF lColor = hb_parnl(2);
   BOOL  lSubMenu = hb_parl(3);
   HWND  himage ;

   himage = (HWND)LoadImage(0,hb_parc(4),IMAGE_BITMAP ,0,0,LR_LOADFROMFILE | LR_LOADMAP3DCOLORS | LR_LOADTRANSPARENT );

   if (himage==NULL)
     {
       himage = (HWND)LoadImage(GetModuleHandle(NULL),hb_parc(4),IMAGE_BITMAP ,0,0, LR_LOADMAP3DCOLORS   | LR_LOADTRANSPARENT );
     }

   iMenu              = GetMenu((HWND) HB_PARHANDLE(1));
   GetMenuInfo(iMenu, &iMenuInfo);
   iMenuInfo.cbSize   = sizeof(MENUINFO);
   //iMenuInfo.dwStyle  = MNS_AUTODISMISS;

   if (lSubMenu)
    {
      iMenuInfo.fMask    = MIM_BACKGROUND | MIM_APPLYTOSUBMENUS ;
    }
   else
    {
      iMenuInfo.fMask    = MIM_BACKGROUND;
    }

   if (himage==NULL)
    {
       iMenuInfo.hbrBack = CreateSolidBrush(lColor);
    }
   else
    {
       iMenuInfo.hbrBack = CreatePatternBrush((HBITMAP) himage);
//       iMenuInfo.hbrBack = CreatePatternBrush(himage);
    }

   SetMenuInfo(iMenu, &iMenuInfo);
   DrawMenuBar((HWND) HB_PARHANDLE(1));
   //DrawMenuBar((HWND) hb_parnl(1));
}

HB_FUNC ( _COLORSUBMENU )
{
   HMENU      iMenu;
   MENUINFO   iMenuInfo ;
   COLORREF lColor = hb_parnl(2);
   iMenu              = GetMenu((HWND) hb_parnl(1));
   GetMenuInfo(iMenu, &iMenuInfo);
   iMenuInfo.cbSize   = sizeof(MENUINFO);
   iMenuInfo.fMask    = MIM_BACKGROUND | MIM_APPLYTOSUBMENUS;
   iMenuInfo.hbrBack  = CreateSolidBrush(lColor);
   SetMenuInfo(iMenu, &iMenuInfo);
//   DrawMenuBar((HWND) hb_parnl(1));
}

