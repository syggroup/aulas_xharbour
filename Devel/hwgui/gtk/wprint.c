/*
 * $Id: wprint.c 1625 2011-08-05 13:14:50Z druzus $
 *
 * HWGUI - Harbour Linux (GTK) GUI library source code:
 * C level print functions
 *
 * Copyright 2005 Alexander S.Kresin <alex@belacy.belgorod.su>
 * www - http://kresin.belgorod.su
*/

#include "guilib.h"
#include "hbapi.h"
#include "hbapifs.h"
#include "hbapiitm.h"
#include "hbvm.h"

#include <locale.h>
#include "gtk/gtk.h"
#include "hwgtk.h"

#if !defined(__MINGW32__)

#include <libgnomeprint/gnome-print.h>
#include <libgnomeprint/gnome-print-job.h>
#include <libgnomeprint/private/gnome-font-private.h>

#define DT_CENTER                   1
#define DT_RIGHT                    2

typedef struct HWGUI_PRINT_STRU
{
   GnomePrintJob *job;
   GnomePrintContext *gpc;
   GnomePrintConfig *config;
   GnomeFont *font;

} HWGUI_PRINT, * PHWGUI_PRINT;

#ifdef G_CONSOLE_MODE
static BOOL bGtkInit = 0;
#endif

HB_FUNC( HWG_OPENPRINTER )
{
   PHWGUI_PRINT print = (PHWGUI_PRINT) hb_xgrab( sizeof(HWGUI_PRINT) );

#ifdef G_CONSOLE_MODE
   if( !bGtkInit )
   {
      // gtk_set_locale();
      g_type_init();
      bGtkInit = 1;
   }
#endif
   memset( print,0,sizeof(HWGUI_PRINT) );
   print->config = gnome_print_config_default();
   gnome_print_config_set( print->config, (const guchar*)"Printer", (const guchar*)"GENERIC" );
   gnome_print_config_set( print->config, (const guchar*)"Settings.Transport.Backend.Printer", (const guchar*)hb_parc(1) );
   gnome_print_config_set( print->config, (const guchar*)GNOME_PRINT_KEY_PAGE_ORIENTATION, (const guchar*)"R0" );

   print->job = gnome_print_job_new( print->config );
   print->gpc = gnome_print_job_get_context( print->job );
   hb_retnl( (HB_LONG) print );
}

HB_FUNC( HWG_OPENDEFAULTPRINTER )
{
   PHWGUI_PRINT print = (PHWGUI_PRINT) hb_xgrab( sizeof(HWGUI_PRINT) );
   
#ifdef G_CONSOLE_MODE
   if( !bGtkInit )
   {
      // gtk_set_locale();
      g_type_init();
      bGtkInit = 1;
   }
#endif
   memset( print,0,sizeof(HWGUI_PRINT) );
   print->config = gnome_print_config_default();
   gnome_print_config_set( print->config, (const guchar*)"Printer", (const guchar*)"GENERIC" );
   gnome_print_config_set( print->config, (const guchar*)GNOME_PRINT_KEY_PAGE_ORIENTATION, (const guchar*)"R0" );

   print->job = gnome_print_job_new( print->config );
   print->gpc = gnome_print_job_get_context( print->job );
   hb_retnl( (HB_LONG) print );
}

HB_FUNC( HWG_GETPRINTERS )
{
   HB_FHANDLE hInput = hb_fsOpen( "/etc/printcap", FO_READ );
   PHB_ITEM aMetr = NULL, temp;

   if( hInput != -1 )
   {
      HB_ULONG ulLen = hb_fsSeek( hInput, 0, FS_END );
      unsigned char *cBuffer, *ptr, *ptr1;

      hb_fsSeek( hInput, 0, FS_SET );
      cBuffer = (unsigned char*) hb_xgrab( ulLen + 1 );
      ulLen = hb_fsReadLarge( hInput, cBuffer, ulLen );
      cBuffer[ulLen] = '\0';

      ptr = cBuffer;
      while( 1 )
      {
         while( *ptr && ( *ptr == ' ' || *ptr == 0x9 || *ptr == 0x0a ) ) ptr ++;
         if( *ptr )
         {
            if( *ptr == '#' )
            {
               while( *ptr && *ptr != 0x0a ) ptr ++;
               if( *ptr ) ptr++;
                  continue;
            }
            if( !aMetr )
               aMetr = hb_itemArrayNew( 0 );
            ptr1 = ptr;
            while( *ptr && *ptr != 0x0a && *ptr != '|' ) ptr++;
            temp = hb_itemPutCL( NULL,(char*)ptr1,ptr-ptr1 );
            hb_arrayAdd( aMetr, temp );
            hb_itemRelease( temp );
            while( *ptr && *ptr != 0x0a ) ptr++;
            if( *ptr ) ptr++;
         }
         else
            break;
      }
      hb_xfree( cBuffer );
   }
   if( aMetr )
   {
      hb_itemReturn( aMetr );
      hb_itemRelease( aMetr );
   }
   else
      hb_ret();

}

/*
 * SetPrinterMode( print, nOrientation )
 */

HB_FUNC( SETPRINTERMODE )
{
   PHWGUI_PRINT print = (PHWGUI_PRINT) hb_parnl(1);

   gnome_print_config_set( print->config,
            (const guchar*)GNOME_PRINT_KEY_PAGE_ORIENTATION,
            (hb_parni(2)==1)? (const guchar*)"R0":(const guchar*)"R270" );
}

HB_FUNC( CLOSEPRINTER )
{
   // HANDLE hPrinter = (HANDLE)hb_parnl(1);
   // ClosePrinter( hPrinter );
}

HB_FUNC( HWG_UNREFPRINTER )
{
   PHWGUI_PRINT print = (PHWGUI_PRINT) hb_parnl(1);

   g_object_unref( G_OBJECT (print->config) );
   g_object_unref( G_OBJECT (print->gpc) );
   g_object_unref( G_OBJECT (print->job) );
   hb_xfree( print );
}

HB_FUNC( HWG_STARTDOC )
{
   PHWGUI_PRINT print = (PHWGUI_PRINT) hb_parnl(1); 

   hb_retnl( (HB_LONG) print->job );
}

HB_FUNC( HWG_ENDDOC )
{
   PHWGUI_PRINT print = (PHWGUI_PRINT) hb_parnl(1);

   gnome_print_job_close( print->job );
   gnome_print_job_print( print->job );
}

HB_FUNC( HWG_STARTPAGE )
{
   PHWGUI_PRINT print = (PHWGUI_PRINT) hb_parnl(1);
   hb_retnl( (HB_LONG) gnome_print_beginpage( print->gpc, NULL ) );
}

HB_FUNC( HWG_ENDPAGE )
{
   PHWGUI_PRINT print = (PHWGUI_PRINT) hb_parnl(1);
   hb_retnl( (HB_LONG) gnome_print_showpage( print->gpc ) );
}

/*
 * HORZRES	Width, in pixels, of the screen.
 * VERTRES	Height, in raster lines, of the screen.
 * HORZSIZE	Width, in millimeters, of the physical screen.
 * VERTSIZE	Height, in millimeters, of the physical screen.
 * LOGPIXELSX	Number of pixels per logical inch along the screen width.
 * LOGPIXELSY	Number of pixels per logical inch along the screen height.
 *
 */
HB_FUNC( HWG_GP_GETDEVICEAREA )
{
   PHWGUI_PRINT print = (PHWGUI_PRINT) hb_parnl(1);

   PHB_ITEM aMetr = hb_itemArrayNew( 9 );
   PHB_ITEM temp;
   gdouble width,  height;
   
   gnome_print_config_get_page_size( print->config, &width, &height );

   temp = hb_itemPutNL( NULL, (HB_LONG)width );
   hb_itemArrayPut( aMetr, 1, temp );
   hb_itemRelease( temp );

   temp = hb_itemPutNL( NULL, (HB_LONG)height );
   hb_itemArrayPut( aMetr, 2, temp );
   hb_itemRelease( temp );

   temp = hb_itemPutNL( NULL, (HB_LONG)(width*25.4/72) );
   hb_itemArrayPut( aMetr, 3, temp );
   hb_itemRelease( temp );

   temp = hb_itemPutNL( NULL, (HB_LONG)(height*25.4/72) );
   hb_itemArrayPut( aMetr, 4, temp );
   hb_itemRelease( temp );

   temp = hb_itemPutNL( NULL, 72 );
   hb_itemArrayPut( aMetr, 5, temp );
   hb_itemRelease( temp );

   temp = hb_itemPutNL( NULL, 72 );
   hb_itemArrayPut( aMetr, 6, temp );
   hb_itemRelease( temp );

   temp = hb_itemPutNL( NULL, 0 );
   hb_itemArrayPut( aMetr, 7, temp );
   hb_itemRelease( temp );

   temp = hb_itemPutNL( NULL, (HB_LONG)width );
   hb_itemArrayPut( aMetr, 8, temp );
   hb_itemRelease( temp );

   temp = hb_itemPutNL( NULL, (HB_LONG)height );
   hb_itemArrayPut( aMetr, 9, temp );
   hb_itemRelease( temp );

   hb_itemReturn( aMetr );
   hb_itemRelease( aMetr );
}

HB_FUNC( HWG_GP_RECTANGLE )
{
   PHWGUI_PRINT print = (PHWGUI_PRINT) hb_parnl(1);
   int x1 = hb_parni( 2 ), y1 = hb_parni( 3 );

   gnome_print_rect_stroked( print->gpc, (gdouble)x1, (gdouble)y1, 
     (gdouble)(hb_parni(4)-x1+1), (gdouble)(hb_parni(5)-y1+1) );
}

HB_FUNC( HWG_GP_DRAWLINE )
{
   PHWGUI_PRINT print = (PHWGUI_PRINT) hb_parnl(1);

   gnome_print_line_stroked( print->gpc, (gdouble)hb_parni(2), 
            (gdouble)hb_parni(3), (gdouble)hb_parni(4), (gdouble)hb_parni(5) );
}

/*
HB_FUNC( HWG_GP_DRAWTEXT )
{
   PHWGUI_PRINT print = (PHWGUI_PRINT) hb_parnl(1);
   char * cText = hwg_convert_to_utf8( hb_parc(2) );
   // guchar *cText = g_convert( hb_parc(2),-1,"UTF-8","KOI8-R",NULL,NULL,NULL );
   int iOption = (HB_ISNIL(7))? 0 : hb_parni(7);
   int x1 = hb_parni(3);

   if( print->font && ( iOption == DT_RIGHT || iOption == DT_CENTER ) )
   {
      int iLen = (int) gnome_font_get_width_utf8( print->font, cText );
      int x2 = hb_parni(5);
      if( iOption == DT_RIGHT )
         x1 = x2 - iLen;
      else
         x1 = x1 + ( (x2-x1-iLen)/2 );
   }

   gnome_print_moveto( print->gpc, (gdouble)x1, (gdouble)hb_parni(4) );
   gnome_print_show( print->gpc, (guchar*)cText );
   g_free( cText );

}
*/

HB_FUNC( HWG_GP_DRAWTEXT )
{
   PHWGUI_PRINT print = (PHWGUI_PRINT) hb_parnl(1);
   int i = 0, nLen = hb_parclen(2);
   gchar *p, *cText;
   int iOption = (HB_ISNIL(7))? 0 : hb_parni(7);
   gdouble x1 = (gdouble)hb_parni(3);
   gdouble x2 = (gdouble)hb_parni(5);
   gdouble delta, dWidth = 0;
   gint unival, glyph;

   cText = hwg_convert_to_utf8( hb_parc(2) );
   if( print->font )
   {
      for( p = cText; p && i < nLen; p = g_utf8_next_char(p), i++ )
      {
         unival = g_utf8_get_char (p);
         glyph = gnome_font_lookup_default( print->font, unival );
         dWidth += gnome_font_face_get_glyph_width( print->font->face, glyph ) * 
            0.001 * print->font->size;
         if( dWidth > (x2-x1) )
            break;
      }
      nLen = p - cText;
   }
   if( dWidth && dWidth < (x2-x1) && ( iOption == DT_RIGHT || iOption == DT_CENTER ) )
   {
      if( iOption == DT_RIGHT )
         x1 = x2 - dWidth;
      else
         x1 = x1 + ( (x2-x1-dWidth)/2 );
   }

   delta = gnome_font_get_size(print->font) / 2;
   gnome_print_moveto( print->gpc, x1, (gdouble)hb_parni(4)+delta );
   gnome_print_show_sized( print->gpc, (guchar*)cText, nLen );
   g_free( cText );

}

HB_FUNC( HWG_GP_ADDFONT )
{
   GnomeFont *font = gnome_font_find_closest ( (const guchar*)hb_parc(1), hb_parni(2) );
   
   hb_retnl( (HB_LONG) font );
}

HB_FUNC( HWG_GP_SETFONT )
{
   PHWGUI_PRINT print = (PHWGUI_PRINT) hb_parnl(1);
   GnomeFont *font = (GnomeFont *) hb_parnl(2);

   gnome_print_setfont( print->gpc, font );
   print->font = font;
}

HB_FUNC( HWG_GP_TOFILE )
{
   PHWGUI_PRINT print = (PHWGUI_PRINT) hb_parnl(1);
   gnome_print_job_print_to_file( print->job, hb_parc(2) );
}

HB_FUNC( HWG_GP_FONTLIST )
{
   GList *list, *tmp;
   int i = 0;
   PHB_ITEM aMetr, temp;
	
   tmp = list = gnome_font_list();
   while( tmp )
   {
      tmp = tmp->next;
      i++;
   }
   aMetr = hb_itemArrayNew( i );
   tmp = list;
   i = 1;
   while( tmp )
   {
      temp = hb_itemPutC( NULL, tmp->data );
      hb_itemArrayPut( aMetr, i, temp );
      hb_itemRelease( temp );
      tmp = tmp->next;
      i++;
   }
    
   gnome_font_list_free( list );
   hb_itemReturn( aMetr );
   hb_itemRelease( aMetr );
    
}

HB_FUNC( HWG_GP_GETTEXTSIZE )
{
   PHWGUI_PRINT print = (PHWGUI_PRINT) hb_parnl(1);
   char * cText;
   GnomeFont *font = (HB_ISNIL(3))? print->font : ( (GnomeFont *) hb_parnl(3) );

   if( font )
   {
      cText = hwg_convert_to_utf8( hb_parc(2) );
      hb_retnl( (HB_LONG) gnome_font_get_width_utf8( font, cText ) );
      g_free( cText );
   }
   else
      hb_retni( 0 );
}

HB_FUNC( HWG_GP_TRANSLATE )
{
   PHWGUI_PRINT print = (PHWGUI_PRINT) hb_parnl(1);
   hb_retni( gnome_print_translate( print->gpc, hb_parnl( 2 ), hb_parnl( 3 ) ) );
}
    
HB_FUNC( HWG_GP_RELEASE )
{
   g_object_unref (G_OBJECT (hb_parnl(1)));
}

HB_FUNC( HWG_GP_SETLINEWIDTH )
{
   PHWGUI_PRINT print = (PHWGUI_PRINT) hb_parnl(1);

   gnome_print_setlinewidth( print->gpc, (gdouble)hb_parni(2) );
}

#endif
