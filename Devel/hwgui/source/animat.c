#include "hwingui.h"
#include <commctrl.h>

HB_FUNC( ANIMATE_CREATE )
{
   HWND hwnd;

   hwnd = Animate_Create( ( HWND ) HB_PARHANDLE( 1 ), ( LONG ) hb_parnl( 2 ),
         ( LONG ) hb_parnl( 3 ), GetModuleHandle( NULL ) );
   MoveWindow( hwnd, hb_parnl( 4 ), hb_parnl( 5 ), hb_parnl( 6 ),
         hb_parnl( 7 ), TRUE );
   HB_RETHANDLE( hwnd );
}

HB_FUNC( ANIMATE_OPEN )
{
   void * hStr;
   Animate_Open( ( HWND ) HB_PARHANDLE( 1 ), HB_PARSTR( 2, &hStr, NULL ) );
   hb_strfree( hStr );
}

HB_FUNC( ANIMATE_PLAY )
{
   Animate_Play( ( HWND ) HB_PARHANDLE( 1 ), hb_parni( 2 ), hb_parni( 3 ),
         hb_parni( 4 ) );
}

HB_FUNC( ANIMATE_SEEK )
{
   Animate_Seek( ( HWND ) HB_PARHANDLE( 1 ), hb_parni( 2 ) );
}

HB_FUNC( ANIMATE_STOP )
{
   Animate_Stop( ( HWND ) HB_PARHANDLE( 1 ) );
}

HB_FUNC( ANIMATE_CLOSE )
{
   Animate_Close( ( HWND ) HB_PARHANDLE( 1 ) );
}

HB_FUNC( ANIMATE_DESTROY )
{
   DestroyWindow( ( HWND ) HB_PARHANDLE( 1 ) );
}

HB_FUNC( ANIMATE_OPENEX )
{
#if defined(__DMC__)
   #define Animate_OpenEx(hwnd, hInst, szName) (BOOL)SNDMSG(hwnd, ACM_OPEN, (WPARAM)hInst, (LPARAM)(LPTSTR)(szName))
#endif
   void * hResource;
   LPCTSTR lpResource = HB_PARSTR( 3, &hResource, NULL );

   if( !lpResource && HB_ISNUM( 3 ) )
      lpResource = MAKEINTRESOURCE( hb_parni( 3 ) );

   Animate_OpenEx( ( HWND ) HB_PARHANDLE( 1 ),
                   ( HINSTANCE ) hb_parnl( 2 ),
                   lpResource );

   hb_strfree( hResource );
}
