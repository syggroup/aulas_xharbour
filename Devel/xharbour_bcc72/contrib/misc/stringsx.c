/*
 * $Id: stringsx.c 10165 2016-10-22 23:23:36Z lculik $
 */

#include "hbapi.h"

/* TODO: search this file for TODO and find 'em! */

static char *hb_strtoken( char *szText,
                  HB_ISIZ lText,
                  HB_ISIZ lIndex,
                  char cDelimiter,
                  HB_ISIZ *lLen)
{
   HB_ISIZ wStart;
   HB_ISIZ wEnd = 0;
   HB_ISIZ wCounter = 0;

   HB_TRACE(HB_TR_DEBUG, ("hb_strtoken(%s, %" HB_PFS "d, %" HB_PFS "d, %d, %p)", szText, lText, lIndex, (int) cDelimiter, lLen));

   do
     {
       wStart = wEnd;

       if( cDelimiter != ' ' )
       {
          if( szText[wStart] == cDelimiter )
             wStart++;
       }
       else
       {
          while( wStart < lText && szText[wStart] == cDelimiter )
             wStart++;
       }

       if( wStart < lText && szText[wStart] != cDelimiter )
       {
          wEnd = wStart + 1;

          while( wEnd < lText && szText[wEnd] != cDelimiter )
             wEnd++;
       }
       else
          wEnd = wStart;

     } while( wCounter++ < lIndex - 1 && wEnd < lText );

   if( wCounter < lIndex )
   {
      *lLen = 0;
      return "";
   }
   else
   {
      *lLen = wEnd - wStart;
      return szText + wStart;
   }
}

/* returns the nth occurence of a substring within a token-delimited string */
HB_FUNC( STRTOKEN )
{
   char *szText;
   HB_ISIZ lIndex = hb_parns(2);
   char cDelimiter = *hb_parcx(3);
   HB_ISIZ lLen;

   if( !cDelimiter )
      cDelimiter = ' ';

   szText = hb_strtoken( (char*) hb_parcx(1), hb_parclen(1), lIndex, cDelimiter, &lLen );

   hb_storns(  lLen, 4 );
   hb_retclen( szText, lLen );
}

/* debug function to dump the ASCII values of an entire string */
HB_FUNC( STRDUMP )
{
   const char *szText = hb_parcx(1);
   HB_SIZE i, lLength = hb_parclen(1);

   for( i = 0; i < lLength; i++ )
     printf("%d ", szText[i]);

   printf("\n");
}

HB_FUNC( ROT13 )
{
   if( ISCHAR(1) )
   {
      const char *szText = hb_parcx( 1 );
      HB_SIZE i, lLen = hb_parclen( 1 );
      char *szResult = (char*) hb_xgrab(lLen + 1);

      for( i = 0; i < lLen; i++ )
      {
         char c = szText[i];

         if( (c >= 'A' && c <= 'M') || (c >= 'a' && c <= 'm') )
            c += 13;
         else if( (c >= 'N' && c <= 'Z') || (c >= 'n' && c <= 'z') )
            c -= 13;

         szResult[i] = c;
      }

      hb_retclen(szResult, lLen);
      hb_xfree(szResult);
   }
   else
      hb_retc("");
}
