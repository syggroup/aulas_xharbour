/*
 * $Id: cxshade.c 1625 2011-08-05 13:14:50Z druzus $
 *
 * HWGUI - Harbour Win32 GUI library source code:
 * C level functions for special drawing effects
 *
 * Based on an article of Davide Pizzolato "CxShadeButton",
 * published on http://www.codeproject.com
 *
 * Copyright 2006 Alexander S.Kresin <alex@belacy.belgorod.su>
 * www - http://kresin.belgorod.su
*/

#include "hwingui.h"
#include "hbapiitm.h"

#define STATE_DEFAULT    1
#define STATE_SELECTED   2
#define STATE_FOCUS      4
#define STATE_OVER       8
#define STATE_DISABLED  16

#define SHS_NOISE 0
#define SHS_DIAGSHADE 1
#define SHS_HSHADE 2
#define SHS_VSHADE 3
#define SHS_HBUMP 4
#define SHS_VBUMP 5
#define SHS_SOFTBUMP 6
#define SHS_HARDBUMP 7
#define SHS_METAL 8

#define HDIB HANDLE
#define WIDTHBYTES(bits)    (((bits) + 31) / 32 * 4)

typedef struct CXDIB_STRU
{
   HDIB hDib;
   BITMAPINFOHEADER m_bi;
   DWORD m_LineWidth;
   WORD m_nColors;

} CXDIB, *PCXDIB;

PCXDIB cxdib_New( void );
void cxdib_Release( PCXDIB pdib );
BOOL cxdib_IsWin30Dib( PCXDIB pdib );
WORD cxdib_GetPaletteSize( PCXDIB pdib );
BYTE *cxdib_GetBits( PCXDIB pdib );
long cxdib_GetSize( PCXDIB pdib );
BOOL cxdib_IsValid( PCXDIB pdib );
void cxdib_Clone( PCXDIB pdib, PCXDIB src );
void cxdib_Clear( PCXDIB pdib, BYTE bval );
HDIB cxdib_Create( PCXDIB pdib, DWORD dwWidth, DWORD dwHeight,
      WORD wBitCount );
long cxdib_Draw( PCXDIB pdib, HDC pDC, long xoffset, long yoffset );
long cxdib_Stretch( PCXDIB pdib, HDC pDC, long xoffset, long yoffset,
      long xsize, long ysize );
void cxdib_SetPaletteIndex( PCXDIB pdib, BYTE idx, BYTE r, BYTE g, BYTE b );
void cxdib_BlendPalette( PCXDIB pdib, COLORREF cr, long perc );
void cxdib_SetPixelIndex( PCXDIB pdib, long x, long y, BYTE i );

typedef struct CXSHADE_STRU
{
   RECT m_rect;                 // object coordinates
   CXDIB m_dNormal, m_dDown, m_dDisabled, m_dOver, m_dh, m_dv;
   short m_FocusRectMargin;     //dotted margin offset
   BOOL m_Border;               //0=flat; 1=3D;
   BOOL m_flat;

} CXSHADE, *PCXSHADE;

PCXSHADE cxshade_New( RECT * prect, BOOL lFlat );
void cxshade_Release( PCXSHADE pshade );
void cxshade_Draw( PCXSHADE pshade, HDC pRealDC, short state );
void cxshade_SetShade( PCXSHADE pshade, UINT shadeID, BYTE palette,
      BYTE granularity, BYTE highlight, BYTE coloring, COLORREF color,
      RECT * prect );
void cxshade_SetFlat( PCXSHADE pshade, BOOL bFlag );
COLORREF cxshade_SetTextColor( PCXSHADE pshade, COLORREF new_color );

void Draw3dRect( HDC hDC, RECT * lprect, COLORREF clrTopLeft,
      COLORREF clrBottomRight )
{
   RECT r;
   int x, y, cx, cy;

   x = lprect->left;
   y = lprect->top;
   cx = lprect->right - lprect->left;
   cy = lprect->bottom - lprect->top;

   SetBkColor( hDC, clrTopLeft );

   SetRect( &r, x, y, x + cx - 1, y + 1 );
   ExtTextOut( hDC, 0, 0, ETO_OPAQUE, &r, NULL, 0, NULL );

   SetRect( &r, x, y, x + 1, y + cy - 1 );
   ExtTextOut( hDC, 0, 0, ETO_OPAQUE, &r, NULL, 0, NULL );

   SetBkColor( hDC, clrBottomRight );

   SetRect( &r, x + cx, y, x + cx - 1, y + cy );
   ExtTextOut( hDC, 0, 0, ETO_OPAQUE, &r, NULL, 0, NULL );

   SetRect( &r, x, y + cy, x + cx, y + cy - 1 );
   ExtTextOut( hDC, 0, 0, ETO_OPAQUE, &r, NULL, 0, NULL );

}

void cxdib_Release( PCXDIB pdib )
{
   if( pdib->hDib )
      hb_xfree( pdib->hDib );
}

WORD cxdib_GetPaletteSize( PCXDIB pdib )
{
   return ( pdib->m_nColors * sizeof( RGBQUAD ) );
}

BYTE *cxdib_GetBits( PCXDIB pdib )
{
   if( pdib->hDib )
      return ( ( BYTE * ) pdib->hDib + *( LPDWORD ) pdib->hDib +
            cxdib_GetPaletteSize( pdib ) );
   return NULL;
}

long cxdib_GetSize( PCXDIB pdib )
{
   return pdib->m_bi.biSize + pdib->m_bi.biSizeImage +
         cxdib_GetPaletteSize( pdib );
}

BOOL cxdib_IsValid( PCXDIB pdib )
{
   return ( pdib->hDib != NULL );
}

void cxdib_Clone( PCXDIB pdib, PCXDIB src )
{
   cxdib_Create( pdib, src->m_bi.biWidth, src->m_bi.biHeight,
         src->m_bi.biBitCount );
   if( pdib->hDib )
      memcpy( pdib->hDib, src->hDib, cxdib_GetSize( pdib ) );
}

void cxdib_Clear( PCXDIB pdib, BYTE bval )
{
   if( pdib->hDib )
      memset( cxdib_GetBits( pdib ), bval, pdib->m_bi.biSizeImage );
}

HDIB cxdib_Create( PCXDIB pdib, DWORD dwWidth, DWORD dwHeight,
      WORD wBitCount )
{
   LPBITMAPINFOHEADER lpbi;     // pointer to BITMAPINFOHEADER
   DWORD dwLen;                 // size of memory block

   if( pdib->hDib )
      hb_xfree( pdib->hDib );
   pdib->hDib = NULL;

   // Make sure bits per pixel is valid
   if( wBitCount <= 1 )
      wBitCount = 1;
   else if( wBitCount <= 4 )
      wBitCount = 4;
   else if( wBitCount <= 8 )
      wBitCount = 8;
   else
      wBitCount = 24;

   switch ( wBitCount )
   {
      case 1:
         pdib->m_nColors = 2;
         break;
      case 4:
         pdib->m_nColors = 16;
         break;
      case 8:
         pdib->m_nColors = 256;
         break;
      default:
         pdib->m_nColors = 0;
   }

   pdib->m_LineWidth = WIDTHBYTES( wBitCount * dwWidth );

   // initialize BITMAPINFOHEADER
   pdib->m_bi.biSize = sizeof( BITMAPINFOHEADER );
   pdib->m_bi.biWidth = dwWidth;        // fill in width from parameter
   pdib->m_bi.biHeight = dwHeight;      // fill in height from parameter
   pdib->m_bi.biPlanes = 1;     // must be 1
   pdib->m_bi.biBitCount = wBitCount;   // from parameter
   pdib->m_bi.biCompression = BI_RGB;
   pdib->m_bi.biSizeImage = pdib->m_LineWidth * dwHeight;
   pdib->m_bi.biXPelsPerMeter = 0;
   pdib->m_bi.biYPelsPerMeter = 0;
   pdib->m_bi.biClrUsed = 0;
   pdib->m_bi.biClrImportant = 0;

   // calculate size of memory block required to store the DIB.  This
   // block should be big enough to hold the BITMAPINFOHEADER, the color
   // table, and the bits
   dwLen = cxdib_GetSize( pdib );

   pdib->hDib = hb_xgrab( dwLen );        // alloc memory block to store our bitmap
   // hDib = new (HDIB[dwLen]); //fixes allocation problem under Win2k
   if( !pdib->hDib )
      return NULL;

   // use our bitmap info structure to fill in first part of
   // our DIB with the BITMAPINFOHEADER
   lpbi = ( LPBITMAPINFOHEADER ) ( pdib->hDib );
   *lpbi = pdib->m_bi;

   return pdib->hDib;           //return handle to the DIB
}

long cxdib_Draw( PCXDIB pdib, HDC pDC, long xoffset, long yoffset )
{
   if( ( pdib->hDib ) && ( pDC ) )
   {
      //palette must be correctly filled
      BITMAPINFO * lpDIB = ( BITMAPINFO * ) pdib->hDib;      //set image to hdc...
      SetStretchBltMode( pDC, COLORONCOLOR );
      SetDIBitsToDevice( pDC, xoffset, yoffset,
            pdib->m_bi.biWidth, pdib->m_bi.biHeight, 0, 0, 0,
            pdib->m_bi.biHeight, cxdib_GetBits( pdib ),
            lpDIB, DIB_RGB_COLORS );
      return 1;
   }
   return 0;
}

long cxdib_Stretch( PCXDIB pdib, HDC pDC, long xoffset, long yoffset,
      long xsize, long ysize )
{
   if( ( pdib->hDib ) && ( pDC ) )
   {
      //palette must be correctly filled
      BITMAPINFO * lpDIB = ( BITMAPINFO * ) pdib->hDib;      //set image to hdc...
      SetStretchBltMode( pDC, COLORONCOLOR );
      StretchDIBits( pDC, xoffset, yoffset,
            xsize, ysize, 0, 0, pdib->m_bi.biWidth, pdib->m_bi.biHeight,
            cxdib_GetBits( pdib ), lpDIB, DIB_RGB_COLORS,
            SRCCOPY );
      return 1;
   }
   return 0;
}

void cxdib_SetPaletteIndex( PCXDIB pdib, BYTE idx, BYTE r, BYTE g, BYTE b )
{
   if( ( pdib->hDib ) && ( pdib->m_nColors ) )
   {
      BYTE *iDst = ( BYTE * ) ( pdib->hDib ) + sizeof( BITMAPINFOHEADER );
      if( idx < pdib->m_nColors )
      {
         long ldx = idx * sizeof( RGBQUAD );
         iDst[ldx++] = ( BYTE ) b;
         iDst[ldx++] = ( BYTE ) g;
         iDst[ldx++] = ( BYTE ) r;
         iDst[ldx] = ( BYTE ) 0;
      }
   }
}

void cxdib_BlendPalette( PCXDIB pdib, COLORREF cr, long perc )
{
   if( ( pdib->hDib == NULL ) || ( pdib->m_nColors == 0 ) )
      return;
   else
   {
      BYTE *iDst = ( BYTE * ) ( pdib->hDib ) + sizeof( BITMAPINFOHEADER );
      long i, r, g, b;
      RGBQUAD *pPal = ( RGBQUAD * ) iDst;

      r = GetRValue( cr );
      g = GetGValue( cr );
      b = GetBValue( cr );
      if( perc > 100 )
         perc = 100;
      for( i = 0; i < pdib->m_nColors; i++ )
      {
         pPal[i].rgbBlue =
               ( BYTE ) ( ( pPal[i].rgbBlue * ( 100 - perc ) +
                     b * perc ) / 100 );
         pPal[i].rgbGreen =
               ( BYTE ) ( ( pPal[i].rgbGreen * ( 100 - perc ) +
                     g * perc ) / 100 );
         pPal[i].rgbRed =
               ( BYTE ) ( ( pPal[i].rgbRed * ( 100 - perc ) +
                     r * perc ) / 100 );
      }
   }
}

void cxdib_SetPixelIndex( PCXDIB pdib, long x, long y, BYTE i )
{
   BYTE *iDst;

   if( ( pdib->hDib == NULL ) || ( pdib->m_nColors == 0 ) ||
         ( x < 0 ) || ( y < 0 ) || ( x >= pdib->m_bi.biWidth ) ||
         ( y >= pdib->m_bi.biHeight ) )
      return;
   iDst = cxdib_GetBits( pdib );
   iDst[( pdib->m_bi.biHeight - y - 1 ) * pdib->m_LineWidth + x] = i;
}



/*  --------------------------------------------------------------  */

PCXSHADE cxshade_New( RECT * prect, BOOL lFlat )
{
   PCXSHADE pshade = ( PCXSHADE ) hb_xgrab( sizeof( CXSHADE ) );

   memset( pshade, 0, sizeof( CXSHADE ) );
   SetRect( &( pshade->m_rect ), prect->left, prect->top, prect->right,
         prect->bottom );
   pshade->m_Border = 1;        //draw 3D border
   pshade->m_FocusRectMargin = 4;       //focus dotted rect margin
   pshade->m_flat = lFlat;

   return pshade;
}

void cxshade_Release( PCXSHADE pshade )
{
   cxdib_Release( &( pshade->m_dNormal ) );
   cxdib_Release( &( pshade->m_dDown ) );
   cxdib_Release( &( pshade->m_dDisabled ) );
   cxdib_Release( &( pshade->m_dOver ) );
   cxdib_Release( &( pshade->m_dh ) );
   cxdib_Release( &( pshade->m_dv ) );
   hb_xfree( pshade );
}

void cxshade_Draw( PCXSHADE pshade, HDC pRealDC, short state )
{
   int cx = pshade->m_rect.right - pshade->m_rect.left;
   int cy = pshade->m_rect.bottom - pshade->m_rect.top;
   RECT r;

   HBITMAP hBitmap;             //create a destination for raster operations
   HBITMAP holdBitmap;
   HDC hdcMem;                  //create a memory DC to avoid flicker
   HDC pDC;

   SetRect( &r, pshade->m_rect.left, pshade->m_rect.top, pshade->m_rect.right,
         pshade->m_rect.bottom );

   hdcMem = CreateCompatibleDC( pRealDC );
   pDC = hdcMem;                //(just use pRealDC to paint directly the screen)

   hBitmap = CreateCompatibleBitmap( pRealDC, cx, cy );
   holdBitmap = ( HBITMAP ) SelectObject( hdcMem, hBitmap );    //select the destination for MemDC

   SetBkMode( pDC, TRANSPARENT );

   // Select the correct skin
   if( state & STATE_DISABLED )
   {                            // DISABLED BUTTON
      if( cxdib_IsValid( &( pshade->m_dDisabled ) ) )   // paint the skin
         cxdib_Draw( &( pshade->m_dDisabled ), pDC, 0, 0 );
      // if needed, draw the standard 3D rectangular border
      if( ( pshade->m_Border ) && ( pshade->m_flat == FALSE ) )
         DrawEdge( pDC, &r, EDGE_RAISED, BF_RECT );
   }
   else
   {
      //---------------------------------------------------------------------------
      if( state & STATE_SELECTED )
      {                         //SELECTED (DOWN) BUTTON
         if( cxdib_IsValid( &( pshade->m_dDown ) ) )
         {
            cxdib_Draw( &( pshade->m_dDown ), pDC, pshade->m_Border,
                  pshade->m_Border );
         }
         // if needed, draw the standard 3D rectangular border
         if( pshade->m_Border )
         {
            if( pshade->m_flat )
               Draw3dRect( pDC, &r, GetSysColor( COLOR_BTNSHADOW ),
                     GetSysColor( COLOR_BTNHILIGHT ) );
            else
               DrawEdge( pDC, &r, EDGE_SUNKEN, BF_RECT );
         }

      }
      else
      {
         //-----------------------------------------------------------------------
         if( cxdib_IsValid( &( pshade->m_dNormal ) ) )
         {                      // DEFAULT BUTTON
            if( ( state & STATE_OVER ) &&
                  ( cxdib_IsValid( &( pshade->m_dOver ) ) ) )
            {
               cxdib_Draw( &( pshade->m_dOver ), pDC, 0, 0 );
            }
            else
            {
               cxdib_Draw( &( pshade->m_dNormal ), pDC, 0, 0 );
            }
         }
         // if needed, draw the standard 3D rectangular border
         if( ( pshade->m_Border ) && ( ( state & STATE_OVER ) ||
                     !( pshade->m_flat ) ) )
         {
            if( !( pshade->m_flat ) )   // ( state & STATE_DEFAULT )
            {
               DrawEdge( pDC, &r, EDGE_SUNKEN, BF_RECT );
               InflateRect( &r, -1, -1 );
               DrawEdge( pDC, &r, EDGE_RAISED, BF_RECT );
            }
            else
            {
               if( pshade->m_flat )
                  Draw3dRect( pDC, &r, GetSysColor( COLOR_BTNHILIGHT ),
                        GetSysColor( COLOR_BTNSHADOW ) );
               else
                  DrawEdge( pDC, &r, EDGE_RAISED, BF_RECT );
            }
         }
      }
      /*
         // paint the focus rect
         if( (state & STATE_FOCUS) && (pshade->m_FocusRectMargin > 0) )
         {
         InflateRect( &r,-pshade->m_FocusRectMargin,-pshade->m_FocusRectMargin );
         cxdib_Draw( &(pshade->m_dh), pDC, 1+r.left, r.top );
         cxdib_Draw( &(pshade->m_dh), pDC, 1+r.left, r.bottom );
         cxdib_Draw( &(pshade->m_dv), pDC, r.left, 1+r.top );
         cxdib_Draw( &(pshade->m_dv), pDC, r.right, 1+r.top );
         }
       */
   }

   //copy in the real world
   BitBlt( pRealDC, 0, 0, cx, cy, hdcMem, 0, 0, SRCCOPY );

   if( holdBitmap )
      SelectObject( hdcMem, holdBitmap );
   DeleteDC( hdcMem );
   DeleteObject( hBitmap );

}

// #include "stdio.h"
void cxshade_SetShade( PCXSHADE pshade, UINT shadeID, BYTE palette,
      BYTE granularity, BYTE highlight, BYTE coloring, COLORREF color,
      RECT * prect )
{
   long sXSize, sYSize, bytes, j, i, k, h;
   BYTE *iDst, *posDst;
   //get the button base colors
   COLORREF hicr = ( palette ) ? 16777215 : GetSysColor( COLOR_BTNHIGHLIGHT );
   COLORREF midcr = ( palette ) ? 12632256 : GetSysColor( COLOR_BTNFACE );
   COLORREF locr = ( palette ) ? 8421504 : GetSysColor( COLOR_BTNSHADOW );
   long r, g, b;
   long a, x, y, d, xs, idxmax, idxmin;
   long aa, bb;
   int grainx2;

   if( prect )
      SetRect( &( pshade->m_rect ), prect->left, prect->top, prect->right,
            prect->bottom );
   sYSize = pshade->m_rect.bottom - pshade->m_rect.top;
   sXSize = pshade->m_rect.right - pshade->m_rect.left;

   //create the horizontal focus bitmap
   cxdib_Create( &( pshade->m_dh ), max( 1,
               sXSize - 2 * pshade->m_FocusRectMargin - 1 ), 1, 8 );
   //create the vertical focus bitmap
   cxdib_Create( &( pshade->m_dv ), 1, max( 1,
               sYSize - 2 * pshade->m_FocusRectMargin ), 8 );
   //create the default bitmap
   cxdib_Create( &( pshade->m_dNormal ), sXSize, sYSize, 8 );

   for( i = 0; i < 129; i++ )
   {
      r = ( ( 128 - i ) * GetRValue( locr ) + i * GetRValue( midcr ) ) / 128;
      g = ( ( 128 - i ) * GetGValue( locr ) + i * GetGValue( midcr ) ) / 128;
      b = ( ( 128 - i ) * GetBValue( locr ) + i * GetBValue( midcr ) ) / 128;
      cxdib_SetPaletteIndex( &( pshade->m_dNormal ), ( BYTE ) i, ( BYTE ) r,
            ( BYTE ) g, ( BYTE ) b );
      cxdib_SetPaletteIndex( &( pshade->m_dh ), ( BYTE ) i, ( BYTE ) r,
            ( BYTE ) g, ( BYTE ) b );
      cxdib_SetPaletteIndex( &( pshade->m_dv ), ( BYTE ) i, ( BYTE ) r,
            ( BYTE ) g, ( BYTE ) b );
   }
   for( i = 1; i < 129; i++ )
   {
      r = ( ( 128 - i ) * GetRValue( midcr ) + i * GetRValue( hicr ) ) / 128;
      g = ( ( 128 - i ) * GetGValue( midcr ) + i * GetGValue( hicr ) ) / 128;
      b = ( ( 128 - i ) * GetBValue( midcr ) + i * GetBValue( hicr ) ) / 128;
      cxdib_SetPaletteIndex( &( pshade->m_dNormal ), ( BYTE ) ( i + 127 ),
            ( BYTE ) r, ( BYTE ) g, ( BYTE ) b );
      cxdib_SetPaletteIndex( &( pshade->m_dh ), ( BYTE ) ( i + 127 ),
            ( BYTE ) r, ( BYTE ) g, ( BYTE ) b );
      cxdib_SetPaletteIndex( &( pshade->m_dv ), ( BYTE ) ( i + 127 ),
            ( BYTE ) r, ( BYTE ) g, ( BYTE ) b );
   }

   cxdib_BlendPalette( &( pshade->m_dNormal ), color, coloring );       //color the palette

   iDst = cxdib_GetBits( &( pshade->m_dh ) );   //build the horiz. dotted focus bitmap
   j = ( long ) pshade->m_dh.m_bi.biWidth;
   for( i = 0; i < j; i++ )
   {
      // iDst[i]=64+127*(i%2);  //soft
      iDst[i] = (BYTE) (255 * ( i % 2 ));        //hard
   }

   iDst = cxdib_GetBits( &( pshade->m_dv ) );   //build the vert. dotted focus bitmap
   j = ( long ) pshade->m_dv.m_bi.biWidth;
   for( i = 0; i < j; i++ )
   {
      // *iDst=64+127*(i%2);            //soft
      *iDst = (BYTE) ( 255 * ( i % 2 ));  //hard
      iDst += 4;
   }

   bytes = pshade->m_dNormal.m_LineWidth;
   iDst = cxdib_GetBits( &( pshade->m_dNormal ) );
   posDst = iDst;

   grainx2 = RAND_MAX / ( max( 1, 2 * granularity ) );
   idxmax = 255 - granularity;
   idxmin = granularity;

   switch ( shadeID )
   {
      case 8:                  //SHS_METAL
         cxdib_Clear( &( pshade->m_dNormal ), 0 );
         // create the strokes
         k = 40;                //stroke granularity
         for( a = 0; a < 200; a++ )
         {
            x = rand(  ) / ( RAND_MAX / sXSize );       //stroke postion
            y = rand(  ) / ( RAND_MAX / sYSize );       //stroke position
            xs = rand(  ) / ( RAND_MAX / min( sXSize, sYSize ) ) / 2;   //stroke lenght
            d = rand(  ) / ( RAND_MAX / k );    //stroke color
            for( i = 0; i < xs; i++ )
            {
               if( ( ( x - i ) > 0 ) && ( ( y + i ) < sYSize ) )
                  cxdib_SetPixelIndex( &( pshade->m_dNormal ), x - i, y + i,
                        ( BYTE ) d );
               if( ( ( x + i ) < sXSize ) && ( ( y - i ) > 0 ) )
                  cxdib_SetPixelIndex( &( pshade->m_dNormal ), sXSize - x + i,
                        y - i, ( BYTE ) d );
            }
         }
         //blend strokes with SHS_DIAGONAL
         posDst = iDst;
         a = ( idxmax - idxmin - k ) / 2;
         for( i = 0; i < sYSize; i++ )
         {
            for( j = 0; j < sXSize; j++ )
            {
               d = posDst[j] + ( ( a * i ) / sYSize + ( a * ( sXSize -
                                 j ) ) / sXSize );
               posDst[j] = ( BYTE ) d;
               posDst[j] += rand(  ) / grainx2;
            }
            posDst += bytes;
         }
         break;
//----------------------------------------------------
      case 7:                  // SHS_HARDBUMP
         //set horizontal bump
         for( i = 0; i < sYSize; i++ )
         {
            k = ( 255 * i / sYSize ) - 127;
            k = ( k * ( k * k ) / 128 ) / 128;
            k = ( k * ( 128 - granularity * 2 ) ) / 128 + 128;
            for( j = 0; j < sXSize; j++ )
            {
               posDst[j] = ( BYTE ) k;
               posDst[j] += rand(  ) / grainx2 - granularity;
            }
            posDst += bytes;
         }
         //set vertical bump
         d = min( 16, sXSize / 6 );     //max edge=16
         a = sYSize * sYSize / 4;
         posDst = iDst;
         for( i = 0; i < sYSize; i++ )
         {
            y = i - sYSize / 2;
            for( j = 0; j < sXSize; j++ )
            {
               x = j - sXSize / 2;
               xs = sXSize / 2 - d + ( y * y * d ) / a;
               if( x > xs )
                  posDst[j] =
                        (BYTE) idxmin + ( BYTE ) ( ( ( sXSize - j ) * 128 ) / d );
               if( ( x + xs ) < 0 )
                  posDst[j] = (BYTE) idxmax - ( BYTE ) ( ( j * 128 ) / d );
               posDst[j] += rand(  ) / grainx2 - granularity;
            }
            posDst += bytes;
         }
         break;
//----------------------------------------------------
      case 6:                  //SHS_SOFTBUMP
         for( i = 0; i < sYSize; i++ )
         {
            h = ( 255 * i / sYSize ) - 127;
            for( j = 0; j < sXSize; j++ )
            {
               k = ( 255 * ( sXSize - j ) / sXSize ) - 127;
               k = ( h * ( h * h ) / 128 ) / 128 +
                     ( k * ( k * k ) / 128 ) / 128;
               k = k * ( 128 - granularity ) / 128 + 128;
               if( k < idxmin )
                  k = idxmin;
               if( k > idxmax )
                  k = idxmax;
               posDst[j] = ( BYTE ) k;
               posDst[j] += rand(  ) / grainx2 - granularity;
            }
            posDst += bytes;
         }
         break;
//----------------------------------------------------
      case 5:                  // SHS_VBUMP
         for( j = 0; j < sXSize; j++ )
         {
            k = ( 255 * ( sXSize - j ) / sXSize ) - 127;
            k = ( k * ( k * k ) / 128 ) / 128;
            k = ( k * ( 128 - granularity ) ) / 128 + 128;
            for( i = 0; i < sYSize; i++ )
            {
               posDst[j + i * bytes] = ( BYTE ) k;
               posDst[j + i * bytes] += rand(  ) / grainx2 - granularity;
            }
         }
         break;
//----------------------------------------------------
      case 4:                  //SHS_HBUMP
         for( i = 0; i < sYSize; i++ )
         {
            k = ( 255 * i / sYSize ) - 127;
            k = ( k * ( k * k ) / 128 ) / 128;
            k = ( k * ( 128 - granularity ) ) / 128 + 128;
            for( j = 0; j < sXSize; j++ )
            {
               posDst[j] = ( BYTE ) k;
               posDst[j] += rand(  ) / grainx2 - granularity;
            }
            posDst += bytes;
         }
         break;
//----------------------------------------------------
      case 1:                  //SHS_DIAGSHADE
         a = ( idxmax - idxmin ) / 2;
         for( i = 0; i < sYSize; i++ )
         {
            for( j = 0; j < sXSize; j++ )
            {
               bb = a * ( sXSize - j ) / sXSize;
               aa = idxmin + a * ( i / sYSize );
//                posDst[j] = (BYTE) ( idxmin + a *( i / sYSize) + a * (sXSize-j) /sXSize );
               posDst[j] = ( BYTE ) ( aa + bb );
               posDst[j] += rand(  ) / grainx2 - granularity;
            }
            posDst += bytes;
         }
         break;
//----------------------------------------------------
      case 2:                  //SHS_HSHADE
         a = idxmax - idxmin;
         for( i = 0; i < sYSize; i++ )
         {
            k = a * i / sYSize + idxmin;
            for( j = 0; j < sXSize; j++ )
            {
               posDst[j] = ( BYTE ) k;
               posDst[j] += rand(  ) / grainx2 - granularity;
            }
            posDst += bytes;
         }
         break;
//----------------------------------------------------
      case 3:                  //SHS_VSHADE:
         a = idxmax - idxmin;
         for( j = 0; j < sXSize; j++ )
         {
            k = a * ( sXSize - j ) / sXSize + idxmin;
            for( i = 0; i < sYSize; i++ )
            {
               posDst[j + i * bytes] = ( BYTE ) k;
               posDst[j + i * bytes] += rand(  ) / grainx2 - granularity;
            }
         }
         break;
//----------------------------------------------------
      default:                 //SHS_NOISE
         for( i = 0; i < sYSize; i++ )
         {
            for( j = 0; j < sXSize; j++ )
            {
               posDst[j] = 128 + rand(  ) / grainx2 - granularity;
            }
            posDst += bytes;
         }
   }

   cxdib_Clone( &( pshade->m_dDisabled ), &( pshade->m_dNormal ) );
   cxdib_Clone( &( pshade->m_dOver ), &( pshade->m_dNormal ) );
   cxdib_BlendPalette( &( pshade->m_dOver ), hicr, highlight );
   cxdib_Clone( &( pshade->m_dDown ), &( pshade->m_dOver ) );
}

/* --------------------------------------------------------------- */

/*
 * shade_New( nLeft, nTop, nRight, nBottom, lFlat ) -> pshade
 */
HB_FUNC( SHADE_NEW )
{
   RECT rect;
   PCXSHADE pshade;

   SetRect( &rect, hb_parni( 1 ), hb_parni( 2 ), hb_parni( 3 ),
         hb_parni( 4 ) );
   pshade = cxshade_New( &rect, ( HB_ISNIL( 5 ) ) ? 0 : hb_parl( 5 ) );
   HB_RETHANDLE( pshade );
}

/*
 * shade_Release( pshade )
 */
HB_FUNC( SHADE_RELEASE )
{
   cxshade_Release( ( PCXSHADE ) HB_PARHANDLE( 1 ) );
}

/*
 * shade_Set( pshade, shadeID, palette, granularity, highlight, coloring, color, nLeft, nTop, nRight, nBottom )
 */
HB_FUNC( SHADE_SET )
{
   PCXSHADE pshade = ( PCXSHADE ) HB_PARHANDLE( 1 );
   UINT shadeID = ( HB_ISNIL( 2 ) ) ? SHS_SOFTBUMP : hb_parni( 2 );
   BYTE palette = ( HB_ISNIL( 3 ) ) ? 0 : ( BYTE ) hb_parni( 3 );
   BYTE granularity = ( HB_ISNIL( 4 ) ) ? 8 : ( BYTE ) hb_parni( 4 );
   BYTE highlight = ( HB_ISNIL( 5 ) ) ? 10 : ( BYTE ) hb_parni( 5 );
   BYTE coloring = ( HB_ISNIL( 6 ) ) ? 0 : ( BYTE ) hb_parni( 6 );
   COLORREF color = ( HB_ISNIL( 7 ) ) ? 0 : ( COLORREF ) hb_parnl( 7 );
   RECT rect;

   if( !HB_ISNIL( 7 ) )
      SetRect( &rect, hb_parni( 7 ), hb_parni( 8 ), hb_parni( 9 ),
            hb_parni( 10 ) );

   cxshade_SetShade( pshade, shadeID, palette, granularity, highlight,
         coloring, color, ( HB_ISNIL( 8 ) ) ? NULL : &rect );
}

/*
 * shade_Draw( pshade, hDC, nState )
 */
HB_FUNC( SHADE_DRAW )
{
   cxshade_Draw( ( PCXSHADE ) HB_PARHANDLE( 1 ), ( HDC ) HB_PARHANDLE( 2 ),
         (short) hb_parni( 3 ) );
}
