/*
 * $Id: commond.c 1830 2012-01-12 12:47:11Z LFBASSO $
 *
 * HWGUI - Harbour Win32 GUI library source code:
 * C level common dialogs functions
 *
 * Copyright 2001 Alexander S.Kresin <alex@belacy.belgorod.su>
 * www - http://kresin.belgorod.su
*/

#define OEMRESOURCE
#include "hwingui.h"
#include "hbapiitm.h"
#include "hbvm.h"

HB_FUNC( SELECTFONT )
{

   CHOOSEFONT cf;
   LOGFONT lf;
   HFONT hfont;
   PHB_ITEM pObj = ( HB_ISNIL( 1 ) ) ? NULL : hb_param( 1, HB_IT_OBJECT );
   PHB_ITEM temp1;
   PHB_ITEM aMetr = hb_itemArrayNew( 9 ), temp;

   /* Initialize members of the CHOOSEFONT structure. */
   if( pObj )
   {
      memset( &lf, 0, sizeof( LOGFONT ) );
      temp1 = GetObjectVar( pObj, "NAME" );
      HB_ITEMCOPYSTR( temp1, lf.lfFaceName, HB_SIZEOFARRAY( lf.lfFaceName ) );
      lf.lfFaceName[ HB_SIZEOFARRAY( lf.lfFaceName ) - 1 ] = '\0';
      temp1 = GetObjectVar( pObj, "WIDTH" );
      lf.lfWidth = hb_itemGetNI( temp1 );
      temp1 = GetObjectVar( pObj, "HEIGHT" );
      lf.lfHeight = hb_itemGetNI( temp1 );
      temp1 = GetObjectVar( pObj, "WEIGHT" );
      lf.lfWeight = hb_itemGetNI( temp1 );
      temp1 = GetObjectVar( pObj, "CHARSET" );
      lf.lfCharSet = hb_itemGetNI( temp1 );
      temp1 = GetObjectVar( pObj, "ITALIC" );
      lf.lfItalic = hb_itemGetNI( temp1 );
      temp1 = GetObjectVar( pObj, "UNDERLINE" );
      lf.lfUnderline = hb_itemGetNI( temp1 );
      temp1 = GetObjectVar( pObj, "STRIKEOUT" );
      lf.lfStrikeOut = hb_itemGetNI( temp1 );
   }

   cf.lStructSize = sizeof( CHOOSEFONT );
   cf.hwndOwner = ( HWND ) NULL;
   cf.hDC = ( HDC ) NULL;
   cf.lpLogFont = &lf;
   cf.iPointSize = 0;
   cf.Flags = CF_SCREENFONTS | ( ( pObj ) ? CF_INITTOLOGFONTSTRUCT : 0 );
   cf.rgbColors = RGB( 0, 0, 0 );
   cf.lCustData = 0L;
   cf.lpfnHook = ( LPCFHOOKPROC ) NULL;
   cf.lpTemplateName = NULL;

   cf.hInstance = ( HINSTANCE ) NULL;
   cf.lpszStyle = NULL;
   cf.nFontType = SCREEN_FONTTYPE;
   cf.nSizeMin = 0;
   cf.nSizeMax = 0;

   /* Display the CHOOSEFONT common-dialog box. */

   if( !ChooseFont( &cf ) )
   {
      hb_itemRelease( aMetr );
      hb_ret();
      return;
   }

   /* Create a logical font based on the user's   */
   /* selection and return a handle identifying   */
   /* that font.                                  */

   hfont = CreateFontIndirect( cf.lpLogFont );

   temp = HB_PUTHANDLE( NULL, hfont );
   hb_itemArrayPut( aMetr, 1, temp );

   HB_ITEMPUTSTR( temp, lf.lfFaceName );
   hb_itemArrayPut( aMetr, 2, temp );

   hb_itemPutNL( temp, lf.lfWidth );
   hb_itemArrayPut( aMetr, 3, temp );

   hb_itemPutNL( temp, lf.lfHeight );
   hb_itemArrayPut( aMetr, 4, temp );

   hb_itemPutNL( temp, lf.lfWeight );
   hb_itemArrayPut( aMetr, 5, temp );

   hb_itemPutNI( temp, lf.lfCharSet );
   hb_itemArrayPut( aMetr, 6, temp );

   hb_itemPutNI( temp, lf.lfItalic );
   hb_itemArrayPut( aMetr, 7, temp );

   hb_itemPutNI( temp, lf.lfUnderline );
   hb_itemArrayPut( aMetr, 8, temp );

   hb_itemPutNI( temp, lf.lfStrikeOut );
   hb_itemArrayPut( aMetr, 9, temp );

   hb_itemRelease( temp );

   hb_itemRelease( hb_itemReturn( aMetr ) );

}

HB_FUNC( HWG_SELECTFILE )
{
   OPENFILENAME ofn;
   TCHAR buffer[1024];
   LPTSTR lpFilter;
   void * hTitle, * hInitDir;

   if( HB_ISCHAR( 1 ) && HB_ISCHAR( 2 ) )
   {
      void * hStr1, * hStr2;
      LPCTSTR lpStr1, lpStr2;
      HB_SIZE nLen1, nLen2;

      lpStr1 = HB_PARSTRDEF( 1, &hStr1, &nLen1 );
      lpStr2 = HB_PARSTRDEF( 2, &hStr2, &nLen2 );

      lpFilter = ( LPTSTR ) hb_xgrab( ( nLen1 + nLen2 + 4 ) * sizeof( TCHAR ) );
      memset( lpFilter, 0, ( nLen1 + nLen2 + 4 ) * sizeof( TCHAR ) );
      memcpy( lpFilter, lpStr1, nLen1 * sizeof( TCHAR ) );
      memcpy( lpFilter + nLen1 + 1, lpStr2, nLen2 * sizeof( TCHAR ) );

      hb_strfree( hStr1 );
      hb_strfree( hStr2 );
   }
   else if( HB_ISARRAY( 1 ) && HB_ISARRAY( 2 ) )
   {
      struct _hb_arrStr {
         void *   hStr1;
         LPCTSTR  lpStr1;
         HB_SIZE  nLen1;
         void *   hStr2;
         LPCTSTR  lpStr2;
         HB_SIZE  nLen2;
      } * pArrStr;
      PHB_ITEM pArr1 = hb_param( 1, HB_IT_ARRAY );
      PHB_ITEM pArr2 = hb_param( 2, HB_IT_ARRAY );
      HB_SIZE n, nArrLen = hb_arrayLen( pArr1 ), nSize;
      LPTSTR ptr;

      pArrStr = ( struct _hb_arrStr * )
                hb_xgrab( nArrLen * sizeof( struct _hb_arrStr ) );
      nSize = 4;
      for( n = 0; n < nArrLen; n++ )
      {
         pArrStr[ n ].lpStr1 = HB_ARRAYGETSTR( pArr1, n + 1,
                                               &pArrStr[ n ].hStr1,
                                               &pArrStr[ n ].nLen1 );
         pArrStr[ n ].lpStr2 = HB_ARRAYGETSTR( pArr2, n + 1,
                                               &pArrStr[ n ].hStr2,
                                               &pArrStr[ n ].nLen2 );
         nSize += pArrStr[ n ].nLen1 + pArrStr[ n ].nLen2 + 2;
      }
      lpFilter = ( LPTSTR ) hb_xgrab( nSize * sizeof( TCHAR ) );
      ptr = lpFilter;
      for( n = 0; n < nArrLen; n++ )
      {
         memcpy( ptr, pArrStr[ n ].lpStr1, pArrStr[ n ].nLen1 * sizeof( TCHAR ) );
         ptr += pArrStr[ n ].nLen1;
         *ptr++ = 0;
         memcpy( ptr, pArrStr[ n ].lpStr2, pArrStr[ n ].nLen2 * sizeof( TCHAR ) );
         ptr += pArrStr[ n ].nLen2;
         *ptr++ = 0;
         hb_strfree( pArrStr[ n ].hStr1 );
         hb_strfree( pArrStr[ n ].hStr2 );
      }
      *ptr++ = 0;
      *ptr = 0;
      hb_xfree( pArrStr );
   }
   else
   {
      hb_retc( NULL );
      return;
   }

   memset( ( void * ) &ofn, 0, sizeof( OPENFILENAME ) );
   ofn.lStructSize = sizeof( ofn );
   ofn.hwndOwner = GetActiveWindow(  );
   ofn.lpstrFilter = lpFilter;
   ofn.lpstrFile = buffer;
   buffer[0] = 0;
   ofn.nMaxFile = 1024;
   ofn.lpstrInitialDir = HB_PARSTR( 3, &hInitDir, NULL );
   ofn.lpstrTitle = HB_PARSTR( 4, &hTitle, NULL );
   ofn.Flags             = OFN_HIDEREADONLY | OFN_NOCHANGEDIR |
    OFN_SHAREAWARE |
    OFN_NODEREFERENCELINKS | OFN_NOTESTFILECREATE | OFN_PATHMUSTEXIST |
    OFN_OVERWRITEPROMPT ;

   //ofn.Flags = OFN_FILEMUSTEXIST | OFN_EXPLORER;

   if( GetOpenFileName( &ofn ) )
      HB_RETSTR( ofn.lpstrFile );
   else
      hb_retc( NULL );
   hb_xfree( lpFilter );

   hb_strfree( hInitDir );
   hb_strfree( hTitle );
}

HB_FUNC( HWG_SAVEFILE )
{
   OPENFILENAME ofn;
   TCHAR buffer[1024];
   void * hFileName, * hStr1, * hStr2, * hTitle, * hInitDir;
   LPCTSTR lpFileName, lpStr1, lpStr2;
   HB_SIZE nSize, nLen1, nLen2;
   LPTSTR lpFilter, lpFileBuff;

   lpFileName = HB_PARSTR( 1, &hFileName, &nSize );
   if( nSize < 1024 )
   {
      memcpy( buffer, lpFileName, nSize * sizeof( TCHAR ) );
      memset( &buffer[ nSize ], 0, ( 1024 - nSize ) * sizeof( TCHAR ) );
      lpFileBuff = buffer;
      nSize = 1024;
   }
   else
      lpFileBuff = HB_STRUNSHARE( &hFileName, lpFileName, nSize );


   lpStr1 = HB_PARSTRDEF( 2, &hStr1, &nLen1 );
   lpStr2 = HB_PARSTRDEF( 3, &hStr2, &nLen2 );

   lpFilter = ( LPTSTR ) hb_xgrab( ( nLen1 + nLen2 + 4 ) * sizeof( TCHAR ) );
   memset( lpFilter, 0, ( nLen1 + nLen2 + 4 ) * sizeof( TCHAR ) );
   memcpy( lpFilter, lpStr1, nLen1 * sizeof( TCHAR ) );
   memcpy( lpFilter + nLen1 + 1, lpStr2, nLen2 * sizeof( TCHAR ) );

   hb_strfree( hStr1 );
   hb_strfree( hStr2 );

   memset( ( void * ) &ofn, 0, sizeof( OPENFILENAME ) );
   ofn.lStructSize = sizeof( ofn );
   ofn.hwndOwner = GetActiveWindow();
   ofn.lpstrFilter = lpFilter;
   ofn.lpstrFile = lpFileBuff;
   ofn.nMaxFile = nSize;
   ofn.lpstrInitialDir = HB_PARSTR( 4, &hInitDir, NULL );
   ofn.lpstrTitle = HB_PARSTR( 5, &hTitle, NULL );
   ofn.Flags             = OFN_HIDEREADONLY | OFN_NOCHANGEDIR |
    OFN_SHAREAWARE |
    OFN_NODEREFERENCELINKS | OFN_NOTESTFILECREATE | OFN_PATHMUSTEXIST |
    OFN_OVERWRITEPROMPT ;
   if ( HB_ISLOG( 6 ) && hb_parl( 6 ) )
      ofn.Flags = ofn.Flags | OFN_OVERWRITEPROMPT;

   //ofn.Flags = OFN_FILEMUSTEXIST | OFN_EXPLORER;

   if( GetSaveFileName( &ofn ) )
      HB_RETSTR( ofn.lpstrFile );
   else
      hb_retc( NULL );
   hb_xfree( lpFilter );

   hb_strfree( hFileName );
   hb_strfree( hInitDir );
   hb_strfree( hTitle );
}

HB_FUNC( PRINTSETUP )
{
   PRINTDLG pd;

   memset( ( void * ) &pd, 0, sizeof( PRINTDLG ) );

   pd.lStructSize = sizeof( PRINTDLG );
   // pd.hDevNames = (HANDLE) NULL; 
   pd.Flags = PD_RETURNDC;
   pd.hwndOwner = GetActiveWindow(  );
   // pd.hDC = (HDC) NULL; 
   pd.nFromPage = 1;
   pd.nToPage = 1;
   // pd.nMinPage = 0; 
   // pd.nMaxPage = 0; 
   pd.nCopies = 1;
   // pd.hInstance = (HANDLE) NULL; 
   // pd.lCustData = 0L; 
   // pd.lpfnPrintHook = (LPPRINTHOOKPROC) NULL;
   // pd.lpfnSetupHook = (LPSETUPHOOKPROC) NULL; 
   // pd.lpPrintTemplateName = NULL; 
   // pd.lpSetupTemplateName = NULL; 
   // pd.hPrintTemplate = (HANDLE) NULL; 
   // pd.hSetupTemplate = (HANDLE) NULL; 

   if( PrintDlg( &pd ) )
   {
      if( pd.hDevNames )
      {
         if( hb_pcount(  ) > 0 )
         {
            LPDEVNAMES lpdn = ( LPDEVNAMES ) GlobalLock( pd.hDevNames );
            HB_STORSTR( ( LPCTSTR ) lpdn + lpdn->wDeviceOffset, 1 );
            GlobalUnlock( pd.hDevNames );
         }
         GlobalFree( pd.hDevNames );
         GlobalFree( pd.hDevMode );
      }
      HB_RETHANDLE( pd.hDC );
   }
   else
      HB_RETHANDLE( 0 );
}

HB_FUNC( HWG_CHOOSECOLOR )
{
   CHOOSECOLOR cc;
   COLORREF rgb[16];
   DWORD nStyle = ( HB_ISLOG( 2 ) && hb_parl( 2 ) ) ? CC_FULLOPEN : 0;

   memset( ( void * ) &cc, 0, sizeof( CHOOSECOLOR ) );

   cc.lStructSize = sizeof( CHOOSECOLOR );
   cc.hwndOwner = GetActiveWindow(  );
   cc.lpCustColors = rgb;
   if( HB_ISNUM( 1 ) )
   {
      cc.rgbResult = ( COLORREF ) hb_parnl( 1 );
      nStyle |= CC_RGBINIT;
   }
   cc.Flags = nStyle;

   if( ChooseColor( &cc ) )
      hb_retnl( ( LONG ) cc.rgbResult );
   else
      hb_ret(  );
}


static unsigned long Get_SerialNumber( LPCTSTR RootPathName )
{
   unsigned long SerialNumber;

   GetVolumeInformation( RootPathName, NULL, 0, &SerialNumber,
                         NULL, NULL, NULL, 0 );
   return SerialNumber;
}

HB_FUNC( HDGETSERIAL )
{
   void * hStr;
   hb_retnl( Get_SerialNumber( HB_PARSTR( 1, &hStr, NULL ) ) );
   hb_strfree( hStr );
}

/*
 The functions added by extract for the Minigui Lib Open Source project
 Copyright 2002 Roberto Lopez <roblez@ciudad.com.ar>
 http://www.geocities.com/harbour_minigui/
 HB_FUNC( GETPRIVATEPROFILESTRING )
 HB_FUNC( WRITEPRIVATEPROFILESTRING )
*/

HB_FUNC( GETPRIVATEPROFILESTRING )
{
   TCHAR buffer[2048];
   DWORD dwLen;
   void * hSection, * hEntry, * hDefault, * hFileName;
   LPCTSTR lpDefault = HB_PARSTR( 3, &hDefault, NULL );

   dwLen = GetPrivateProfileString( HB_PARSTR( 1, &hSection, NULL ),
                                    HB_PARSTR( 2, &hEntry, NULL ),
                                    lpDefault, buffer, HB_SIZEOFARRAY( buffer ),
                                    HB_PARSTR( 4, &hFileName, NULL ) );
   if( dwLen )
      HB_RETSTRLEN( buffer, dwLen );
   else
      HB_RETSTR( lpDefault );

   hb_strfree( hSection );
   hb_strfree( hEntry );
   hb_strfree( hDefault );
   hb_strfree( hFileName );
}

HB_FUNC( WRITEPRIVATEPROFILESTRING )
{
   void * hSection, * hEntry, * hData, * hFileName;

   hb_retl( WritePrivateProfileString( HB_PARSTR( 1, &hSection, NULL ),
                                       HB_PARSTR( 2, &hEntry, NULL ),
                                       HB_PARSTR( 3, &hData, NULL ),
                                       HB_PARSTR( 4, &hFileName, NULL ) ) ?
            TRUE : FALSE );

   hb_strfree( hSection );
   hb_strfree( hEntry );
   hb_strfree( hData );
   hb_strfree( hFileName );
}

static far PRINTDLG s_pd;
static far BOOL s_fInit = FALSE;
static far BOOL s_fPName = FALSE;

static void StartPrn( void )
{
   if( !s_fInit )
   {
      s_fInit = TRUE;
      memset( &s_pd, 0, sizeof( PRINTDLG ) );
      s_pd.lStructSize = sizeof( PRINTDLG );
      s_pd.hwndOwner = GetActiveWindow();
      s_pd.Flags = PD_RETURNDEFAULT;
      s_pd.nMinPage = 1;
      s_pd.nMaxPage = 65535;

      PrintDlg( &s_pd );

      /*
         if (PrintDlg(&s_pd)==TRUE)
         {
         hb_retl(TRUE);
         }
         else
         {
         hb_retl(FALSE);
         }
       */
   }
}

HB_FUNC( PRINTPORTNAME )
{
   if( !s_fPName && s_pd.hDevNames )
   {
      LPDEVNAMES lpDevNames;

      s_fPName = TRUE;
      lpDevNames = ( LPDEVNAMES ) GlobalLock( s_pd.hDevNames );
      HB_RETSTR( ( LPCTSTR ) lpDevNames + lpDevNames->wOutputOffset );
      GlobalUnlock( s_pd.hDevNames );
   }
}

HB_FUNC( PRINTSETUPDOS )
{

   StartPrn();

   memset( ( void * ) &s_pd, 0, sizeof( PRINTDLG ) );

   s_pd.lStructSize = sizeof( PRINTDLG );
   s_pd.Flags = PD_RETURNDC;
   s_pd.hwndOwner = GetActiveWindow(  );
   s_pd.nFromPage = 0xFFFF;
   s_pd.nToPage = 0xFFFF;
   s_pd.nMinPage = 1;
   s_pd.nMaxPage = 0xFFFF;
   s_pd.nCopies = 1;

   if( PrintDlg( &s_pd ) )
   {
      s_fPName = FALSE;
      hb_stornl( s_pd.nFromPage, 1 );
      hb_stornl( s_pd.nToPage, 2 );
      hb_stornl( s_pd.nCopies, 3 );
      HB_RETHANDLE( s_pd.hDC );
   }
   else
   {
      s_fPName = TRUE;
      HB_RETHANDLE( 0 );
   }
}

HB_FUNC( PRINTSETUPEX )
{
   PRINTDLG pd;
   DEVMODE *pDevMode;

   memset( ( void * ) &pd, 0, sizeof( PRINTDLG ) );

   pd.lStructSize = sizeof( PRINTDLG );
   pd.Flags = PD_RETURNDC;
   pd.hwndOwner = GetActiveWindow();
   pd.nFromPage = 1;
   pd.nToPage = 1;
   pd.nCopies = 1;

   if( PrintDlg( &pd ) )
   {
      pDevMode = ( LPDEVMODE ) GlobalLock( pd.hDevMode );
      HB_RETSTR( ( LPCTSTR ) pDevMode->dmDeviceName );
      GlobalUnlock( pd.hDevMode );
   }
}

HB_FUNC( _GETOPENFILENAME )
{
   OPENFILENAME ofn;
   TCHAR buffer[ 1024 ];
   void * hFileName, * hTitle, * hFilter, * hInitDir, * hDefExt;
   HB_SIZE nSize;
   LPCTSTR lpFileName = HB_PARSTR( 2, &hFileName, &nSize );
   LPTSTR lpFileBuff;

   if( nSize < 1024 )
   {
      memcpy( buffer, lpFileName, nSize * sizeof( TCHAR ) );
      memset( &buffer[ nSize ], 0, ( 1024 - nSize ) * sizeof( TCHAR ) );
      lpFileBuff = buffer;
      nSize = 1024;
   }
   else
      lpFileBuff = HB_STRUNSHARE( &hFileName, lpFileName, nSize );

   ZeroMemory( &ofn, sizeof( ofn ) );
   ofn.hInstance = GetModuleHandle( NULL );
   ofn.lStructSize = sizeof( ofn );
   ofn.hwndOwner =
         ( HB_ISNIL( 1 ) ? GetActiveWindow(  ) : ( HWND ) HB_PARHANDLE( 1 ) );
   ofn.lpstrTitle = HB_PARSTR( 3, &hTitle, NULL );
   ofn.lpstrFilter = HB_PARSTR( 4, &hFilter, NULL );
   ofn.Flags = OFN_EXPLORER | OFN_ALLOWMULTISELECT;
   ofn.lpstrInitialDir = HB_PARSTR( 6, &hInitDir, NULL );
   ofn.lpstrDefExt = HB_PARSTR( 7, &hDefExt, NULL );
   ofn.nFilterIndex = hb_parni( 8 );
   ofn.lpstrFile = lpFileBuff;
   ofn.nMaxFile = nSize;

   if( GetOpenFileName( &ofn ) )
   {
      hb_stornl( ofn.nFilterIndex, 8 );
      HB_STORSTRLEN( lpFileBuff, nSize, 2 );
      HB_RETSTR( ofn.lpstrFile );
   }
   else
      hb_retc( NULL );

   hb_strfree( hFileName );
   hb_strfree( hTitle );
   hb_strfree( hFilter );
   hb_strfree( hInitDir );
   hb_strfree( hDefExt );
}
