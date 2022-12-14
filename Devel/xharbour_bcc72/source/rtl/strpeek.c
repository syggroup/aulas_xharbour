/*
 * $Id: strpeek.c 10082 2014-12-27 02:04:38Z lculik $
 */

/*
 * Harbour Project source code FlagShip compatible functions:
 * STRPEEK(cStr,nPos)->nASC, STRPOKE(cStr,nPos,nASCval)->cStr
 *
 * Copyright 2003 Przemyslaw Czerpak <druzus@acn.waw.pl>
 * www - http://www.xharbour.org
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this software; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 59 Temple Place, Suite 330,
 * Boston, MA 02111-1307 USA (or visit the web site http://www.gnu.org/).
 *
 * As a special exception, the Harbour Project gives permission for
 * additional uses of the text contained in its release of Harbour.
 *
 * The exception is that, if you link the Harbour libraries with other
 * files to produce an executable, this does not by itself cause the
 * resulting executable to be covered by the GNU General Public License.
 * Your use of that executable is in no way restricted on account of
 * linking the Harbour library code into it.
 *
 * This exception does not however invalidate any other reasons why
 * the executable file might be covered by the GNU General Public License.
 *
 * This exception applies only to the code released by the Harbour
 * Project under the name Harbour.  If you copy code from other
 * Harbour Project or Free Software Foundation releases into a copy of
 * Harbour, as the General Public License permits, the exception does
 * not apply to the code that you add in this way.  To avoid misleading
 * anyone as to the status of such modified files, you must delete
 * this exception notice from them.
 *
 * If you write modifications of your own for Harbour, it is your choice
 * whether to permit this exception to apply to your modifications.
 * If you do not wish that, delete this exception notice.
 *
 */

#include "hbapi.h"
#include "hbapiitm.h"
#include "hbfast.h"
#include "hbapierr.h"

#ifdef HB_COMPAT_FLAGSHIP

HB_FUNC( STRPEEK )
{
   PHB_ITEM pText = hb_param( 1, HB_IT_STRING );

   if( pText && ISNUM( 2 ) )
   {
      HB_SIZE ulPos = hb_parnl( 2 );
      const char * szText = hb_itemGetCPtr( pText ) ;

      if( ulPos > 0 && ulPos <= hb_itemGetCLen( pText ) )
         hb_retni( ( BYTE ) *( szText + ulPos - 1 ) );
      else
         hb_retni( 0 );
   }
   else
      hb_errRT_BASE_SubstR( EG_ARG, 1099, NULL, "STRPEEK", 2, hb_paramError( 1 ), hb_paramError( 2 ) );
}


HB_FUNC( STRPOKE )
{
   PHB_ITEM pText = hb_param( 1, HB_IT_STRING );

   if( pText && ISNUM( 2 ) && ISNUM( 3 ) )
   {
      HB_ISIZ    ulPos = (HB_ISIZ)hb_parnl( 2 );
      HB_SIZE  ulLen;
      char *   pszText;

      if( ulPos > 0 && hb_itemGetWriteCL( pText, &pszText, &ulLen ) &&
          ulPos <= (HB_ISIZ)ulLen )
      {
         pszText[ ulPos - 1 ] = ( char ) ( hb_parni( 3 ) & 0xff );
      }
      hb_itemReturn( pText );
   }
   else
      hb_errRT_BASE_SubstR( EG_ARG, 1099, NULL, "STRPOKE", 3, hb_paramError( 1 ), hb_paramError( 2 ), hb_paramError( 3 ) );
}

#endif /* HB_COMPAT_FLAGSHIP */
