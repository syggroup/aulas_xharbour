/*
 * $Id: ascpos.c 9784 2012-10-23 21:26:49Z andijahja $
 */

/*
 * Harbour Project source code:
 *   CT3 string function
 *     - ASCPOS
 *     - VALPOS
 *
 * Copyright 2001 IntTec GmbH, Neunlindenstr 32, 79106 Freiburg, Germany
 *        Author: Martin Vogel <vogel@inttec.de>
 *
 * www - http://www.harbour-project.org
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

#include <ctype.h>
#include "ct.h"

/* defines */
#define DO_ASCPOS_ASCPOS   0
#define DO_ASCPOS_VALPOS   1

/* helper function */
static void do_ascpos( int iSwitch )
{
   if( ISCHAR( 1 ) )
   {
      HB_SIZE  sStrSize = hb_parclen( 1 );
      BYTE *   pcString = ( BYTE * ) hb_parc( 1 );
      HB_SIZE  sPos;

      if( ISNUM( 2 ) )
         sPos = hb_parnl( 2 );
      else
         sPos = sStrSize;

      if( ( sPos == 0 ) || ( sPos > sStrSize ) )
      {
         hb_retnl( 0 );
      }
      else
      {
         if( iSwitch == DO_ASCPOS_VALPOS )
         {
            if( isdigit( ( size_t ) pcString[ sPos - 1 ] ) )
               hb_retnl( pcString[ sPos - 1 ] - 48 );
            else
               hb_retnl( 0 );
         }
         else /* iSwitch == DO_ASCPOS_ASCPOS */
         {
            hb_retnl( pcString[ sPos - 1 ] );
         }
      }

   }
   else
   {
      PHB_ITEM pSubst         = NULL;
      int      iArgErrorMode  = ct_getargerrormode();
      if( iArgErrorMode != CT_ARGERR_IGNORE )
      {
         pSubst = ct_error_subst( ( USHORT ) iArgErrorMode, EG_ARG,
                                  ( iSwitch == DO_ASCPOS_VALPOS ? CT_ERROR_VALPOS : CT_ERROR_ASCPOS ),
                                  NULL,
                                  ( iSwitch == DO_ASCPOS_VALPOS ? "VALPOS" : "ASCPOS" ),
                                  0, EF_CANSUBSTITUTE, 1, hb_paramError( 1 ) );
      }

      if( pSubst != NULL )
      {
         hb_itemRelease( hb_itemReturnForward( pSubst ) );
      }
      else
      {
         hb_retnl( 0 );
      }
   }

}

HB_FUNC( ASCPOS )
{
   do_ascpos( DO_ASCPOS_ASCPOS );
}

HB_FUNC( VALPOS )
{
   do_ascpos( DO_ASCPOS_VALPOS );
}

