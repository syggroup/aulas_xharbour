#include <WinTen.h>   
#include <Windows.h>
#include <hbApi.h>  
#include <commctrl.h>
#include <StdLib.h>

void DegradColor( HDC hDC, RECT * rori, COLORREF cFrom, COLORREF cTo, int iType, int iRound )
{
   int clr1r, clr1g, clr1b, clr2r, clr2g, clr2b ;
   signed int iEle, iRed, iGreen, iBlue, iTot, iHalf ;
   BOOL bHorz = ( iType == 2 || iType == 4 ) ;
   BOOL bDir ;
   RECT rct ;
   HPEN hOldPen, hPen ;
   LOGBRUSH lb ;
   HBRUSH hOldBrush, hBrush, hNull ;

   rct.top = rori->top ;
   rct.left = rori->left ;
   rct.bottom = rori->bottom ;
   rct.right = rori->right ;

 	iTot   = ( ! bHorz ? ( rct.bottom  - rct.top + 1 ) : ( rct.right - rct.left + 1 ) ) ;

   iHalf  = iTot / 2 ;
	lb.lbStyle = BS_NULL ;
	hNull  = CreateBrushIndirect(&lb) ;

   clr1r = GetRValue( cFrom ) ;
   clr1g = GetGValue( cFrom ) ;
   clr1b = GetBValue( cFrom ) ;

   clr2r = GetRValue( cTo ) ;
   clr2g = GetGValue( cTo ) ;
   clr2b = GetBValue( cTo ) ;

   iRed   =  abs( clr2r - clr1r ) ;
   iGreen =  abs( clr2g - clr1g ) ;
   iBlue  =  abs( clr2b - clr1b ) ;

   iRed   = ( iRed <= 0 ? 0 : ( iRed / iTot ) );
   iGreen = ( iGreen <= 0 ? 0 : ( iGreen / iTot ) ) ;
   iBlue  = ( iBlue <= 0 ? 0 : ( iBlue / iTot ) ) ;

   if( iType == 3 || iType == 4 )
   {
   	iRed   *= 2 ;
      iGreen *= 2 ;
      iBlue  *= 2 ;
   }

   if( iType == 5 )
   {
      rct.top  += ( ( rct.bottom - rct.top ) / 2 ) ;
      rct.left += ( ( rct.right - rct.left ) / 2 ) ;
      rct.top  -= ( ( rct.bottom - rct.top ) / 3 ) ;
      rct.bottom = rct.top + 2 ;
      rct.right  = rct.left + 2 ;
   }
   else
   {
   	if( ! bHorz )
	   	rct.bottom = rct.top + 1 ;
	   else
   		rct.right = rct.left + 1 ;
   }


   if( iType == 5 )
   {
	   hPen      = CreatePen( PS_SOLID, 1, RGB( clr2r, clr2g, clr2b ) ) ;
   	hOldPen   = SelectObject( hDC, hPen ) ;
		hBrush    = CreateSolidBrush( RGB( clr2r, clr2g, clr2b ) ) ;
   	hOldBrush = SelectObject( hDC, hBrush ) ;
      if( iRound == 1 )
	  		Ellipse( hDC, rori->left, rori->top, rori->right, rori->bottom ) ;
      else
	  		RoundRect( hDC, rori->left, rori->top, rori->right, rori->bottom, 16, 16 ) ;

   	SelectObject( hDC, hOldBrush ) ;
  	   DeleteObject( hBrush ) ;
   	SelectObject( hDC, hOldPen ) ;
  	   DeleteObject( hPen ) ;
	   hPen    = CreatePen( PS_SOLID, 2, RGB( clr1r, clr1g, clr1b ) ) ;
   	hOldPen = SelectObject( hDC, hPen ) ;
   	SelectObject( hDC, hNull ) ;
      if( iRound == 1 )
	  		Ellipse( hDC, rct.left, rct.top, rct.right, rct.bottom ) ;
      else
	  		RoundRect( hDC, rct.left, rct.top, rct.right, rct.bottom, 16, 16 ) ;

   }
   else
   {
	   hPen      = CreatePen( PS_SOLID, 1, RGB( clr1r, clr1g, clr1b ) ) ;
   	hOldPen   = SelectObject( hDC, hPen ) ;
		hBrush    = CreateSolidBrush( RGB( clr1r, clr1g, clr1b ) ) ;
   	hOldBrush = SelectObject( hDC, hBrush ) ;
   }

   for( iEle = 1; iEle < iTot; iEle++ )
   {

		if( iType > 2 && iType < 5 && iEle > iHalf )
      {
      	clr2r = GetRValue( cFrom ) ;
   		clr2g = GetGValue( cFrom ) ;
   		clr2b = GetBValue( cFrom ) ;
      }

      bDir = ( clr2r > clr1r ? TRUE : FALSE ) ;
      if( bDir )
      	clr1r += iRed ;
      else
      	clr1r -= iRed ;

      clr1r = ( clr1r < 0 ? 0 : clr1r > 255 ? 255 : clr1r ) ;

      bDir = ( clr2g > clr1g ? TRUE : FALSE  ) ;
      if( bDir )
      	clr1g += iGreen ;
      else
      	clr1g -= iGreen ;

      clr1g = ( clr1g < 0 ? 0 : clr1g > 255 ? 255 : clr1g ) ;

      bDir = ( clr2b > clr1b ? TRUE : FALSE  ) ;

      if( bDir )
      	clr1b += iBlue ;
      else
      	clr1b -= iBlue ;

      clr1b = ( clr1b < 0 ? 0 : clr1b > 255 ? 255 : clr1b ) ;

      if( iType == 5 )
      {
		      SelectObject( hDC, hOldBrush ) ;
   		   DeleteObject( hNull ) ;
				hNull  = CreateBrushIndirect(&lb) ;
		      SelectObject( hDC, hNull ) ;
   	      SelectObject( hDC, hOldPen ) ;
      		DeleteObject( hPen ) ;
   			hPen = CreatePen( PS_SOLID, 2, RGB( clr1r, clr1g, clr1b ) ) ;
	      	SelectObject( hDC, hPen ) ;
   	   if( iRound == 1 )
   			Ellipse( hDC, rct.left, rct.top, rct.right + 1, rct.bottom + 1 ) ;
	      else
   			RoundRect( hDC, rct.left, rct.top, rct.right + 1, rct.bottom + 1, 16, 16 ) ;

	      if( iRound == 1 )
   			Ellipse( hDC, rct.left, rct.top, rct.right + 1, rct.bottom + 1 ) ;
      	else
   			RoundRect( hDC, rct.left, rct.top, rct.right + 1, rct.bottom + 1, 16, 16 ) ;

	       	rct.top    -= ( rct.top <= rori->top ? 0 : 1 ) ;
   	    	rct.left   -= ( rct.left <= rori->left ? 0 : 1 );
      	 	rct.bottom +=  ( rct.bottom >= rori->bottom ? 0 : 1 ) ;
       		rct.right  +=  ( rct.right >= rori->right ? 0 : 1 ) ;
	   }
      else
      {
	      SelectObject( hDC, hOldBrush ) ;
   	   DeleteObject( hBrush ) ;
      	hBrush = CreateSolidBrush( RGB( clr1r, clr1g, clr1b ) ) ;
	      SelectObject( hDC, hBrush ) ;

      	FillRect( hDC, &rct, hBrush ) ;

      	if( ! bHorz )
      	{
	 			rct.top++ ;
   	   	rct.bottom++ ;
      	}
      	else
      	{
      		rct.left++ ;
         	rct.right++ ;
      	}
      }
   }
	SelectObject( hDC, hOldBrush ) ;
	SelectObject( hDC, hOldPen ) ;
   DeleteObject( hBrush ) ;
   DeleteObject( hPen ) ;
   DeleteObject( hNull ) ;
}

//---------------------------------------------------------------------------//

void DegardeFill( HDC hDC, RECT* rct, COLORREF crStart, COLORREF crEnd, int bVertical )
    {
       int nSegments = 100;
       COLORREF cr;
       int nR      = GetRValue(crStart);
       int nG      = GetGValue(crStart);
       int nB      = GetBValue(crStart);
       int neB     = GetBValue(crEnd);
       int neG     = GetGValue(crEnd);
       int neR     = GetRValue(crEnd);
       int nDiffR  = (neR - nR);
       int nDiffG  = (neG - nG);
       int nDiffB  = (neB - nB);
       int ndR ;
       int ndG ;
       int ndB ;
       int nCX ;
       int nCY ;
       int nTop    = rct->top;
       int nBottom = rct->bottom;
       int nLeft   = rct->left;
       int nRight  = rct->right;
       HBRUSH hBrush;
       RECT rc;

       int i;

       if( !bVertical )
       {
          if( nSegments > ( rct->right - rct->left ) )
          {
            nSegments = ( rct->right - rct->left );
          }
       }
       else
       {
          if( nSegments > ( rct->bottom - rct->top ) )
          {
            nSegments = ( rct->bottom - rct->top );
          }
       }

       ndR = 256 * (nDiffR) / (max(nSegments,1));
       ndG = 256 * (nDiffG) / (max(nSegments,1));
       ndB = 256 * (nDiffB) / (max(nSegments,1));
       nCX = (rct->right-rct->left) / max(nSegments,1);
       nCY = (rct->bottom-rct->top) / max(nSegments,1);

       nR *= 256;
       nG *= 256;
       nB *= 256;

       for (i = 0; i < nSegments; i++, nR += ndR, nG += ndG, nB += ndB)
       {

               if(i == (nSegments - 1))
               {
                  nRight  = rct->right;
                  nBottom = rct->bottom;
               }
               else
               {
                  nBottom = nTop + nCY;
                  nRight = nLeft + nCX;
               }

               cr = RGB(nR / 256, nG / 256, nB / 256);

               {
                  hBrush = CreateSolidBrush( cr );
                  if( bVertical )
                  {
                     rc.top    = nTop;
                     rc.left   = rct->left;
                     rc.bottom = nBottom + 1;
                     rc.right  = rct->right;
                  }
                  else
                  {
                     rc.top    = rct->top;
                     rc.left   = nLeft;
                     rc.bottom = rct->bottom;
                     rc.right  = nRight+1;
                  }
                  FillRect(hDC, &rc, hBrush );
                  DeleteObject( hBrush );
               }

               nLeft = nRight;
               nTop = nBottom;
       }
    }

COLORREF MixedColor(COLORREF colorA,COLORREF colorB)
{
  // ( 86a + 14b ) / 100
  int red   = MulDiv(86,GetRValue(colorA),100) + MulDiv(14,GetRValue(colorB),100);
  int green = MulDiv(86,GetGValue(colorA),100) + MulDiv(14,GetGValue(colorB),100);
  int blue  = MulDiv(86,GetBValue(colorA),100) + MulDiv(14,GetBValue(colorB),100);

  return RGB( min(red,0xff),min(green,0xff), min(blue,0xff));
}

COLORREF MidColor(COLORREF colorA,COLORREF colorB)
{
  // (7a + 3b)/10
  int red   = MulDiv(7,GetRValue(colorA),10) + MulDiv(3,GetRValue(colorB),10);
  int green = MulDiv(7,GetGValue(colorA),10) + MulDiv(3,GetGValue(colorB),10);
  int blue  = MulDiv(7,GetBValue(colorA),10) + MulDiv(3,GetBValue(colorB),10);

  return RGB( min(red,0xff),min(green,0xff), min(blue,0xff));
}

COLORREF GrayColor(COLORREF crColor)
{
  int Gray  = (((int)GetRValue(crColor)) + GetGValue(crColor) + GetBValue(crColor))/3;

  return RGB( Gray,Gray,Gray);
}

BOOL IsLightColor(COLORREF crColor)
{
  return (((int)GetRValue(crColor)) + GetGValue(crColor) + GetBValue(crColor))>(3*128);
}

COLORREF BleachColor(int Add, COLORREF color)
{
  return RGB( min (GetRValue(color)+Add, 255),
              min (GetGValue(color)+Add, 255),
              min (GetBValue(color)+Add, 255));
}
//------------------------------------------------------//
HARBOUR HB_FUN_DARKENCOLORXP() //COLORREF lcolor)
{
  COLORREF lcolor = hb_parnl(1);
  hb_retnl( RGB( MulDiv(GetRValue(lcolor),7,10),
                 MulDiv(GetGValue(lcolor),7,10),
                 MulDiv(GetBValue(lcolor)+55,7,10)) );
}
//------------------------------------------------------//
HARBOUR HB_FUN_DARKENCOLOR() // long lScale, COLORREF lColor)
{
  COLORREF lColor = hb_parnl(2);
  LONG lScale = hb_parni(1);

  long red   = MulDiv(GetRValue(lColor),(255-lScale),255);
  long green = MulDiv(GetGValue(lColor),(255-lScale),255);
  long blue  = MulDiv(GetBValue(lColor),(255-lScale),255);

  hb_retnl( RGB(red, green, blue));
}

COLORREF DarkenColor(long lScale, COLORREF lColor)
{

  long red   = MulDiv(GetRValue(lColor),(255-lScale),255);
  long green = MulDiv(GetGValue(lColor),(255-lScale),255);
  long blue  = MulDiv(GetBValue(lColor),(255-lScale),255);

  return( RGB(red, green, blue));
}

//-------------------------------------------------------//
HARBOUR HB_FUN_LIGHTCOLOR( ) //long lScale, COLORREF lColor)
{
  COLORREF lColor = hb_parnl(2);
  LONG lScale = hb_parni(1);

  long R = MulDiv(255-GetRValue(lColor),lScale,255)+GetRValue(lColor);
  long G = MulDiv(255-GetGValue(lColor),lScale,255)+GetGValue(lColor);
  long B = MulDiv(255-GetBValue(lColor),lScale,255)+GetBValue(lColor);

  hb_retnl( RGB(R, G, B) );
}

COLORREF LightenColor( long lScale, COLORREF lColor)
{
  long R = MulDiv(255-GetRValue(lColor),lScale,255)+GetRValue(lColor);
  long G = MulDiv(255-GetGValue(lColor),lScale,255)+GetGValue(lColor);
  long B = MulDiv(255-GetBValue(lColor),lScale,255)+GetBValue(lColor);

  return( RGB(R, G, B) );
}

//-------------------------------------//

HARBOUR HB_FUN_DEGRADADO()
   {
           RECT rct;

           rct.top      = hb_parni( 2, 1 );
           rct.left     = hb_parni( 2, 2 );
           rct.bottom   = hb_parni( 2, 3 );
           rct.right    = hb_parni( 2, 4 );

           DegardeFill( ( HDC ) hb_parnl( 1 ) , &rct, hb_parnl( 3 ), hb_parnl( 4 ), hb_parl(5) );
   }



