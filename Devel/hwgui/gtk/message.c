/*
 * $Id: message.c 1615 2011-02-18 13:53:35Z mlacecilia $
 *
 * HWGUI - Harbour Linux (GTK) GUI library source code:
 * Message box functions
 *
 * Copyright 2004 Alexander S.Kresin <alex@belacy.belgorod.su>
 * www - http://kresin.belgorod.su
 */

#include "guilib.h"
#include "hbapifs.h"
#include "hbapiitm.h"
#include "hbvm.h"
#include "item.api"
#include "gtk/gtk.h"
#include "hwgtk.h"

extern GtkWidget * GetActiveWindow( void );

static int MessageBox( const char * cMsg, const char * cTitle, int message_type, int button_type )
{
   GtkWidget * dialog;
   int result;
   gchar * gcptr;

   gcptr = hwg_convert_to_utf8( cMsg );
   dialog = gtk_message_dialog_new( GTK_WINDOW( GetActiveWindow() ),
                                     GTK_DIALOG_MODAL | GTK_DIALOG_DESTROY_WITH_PARENT,
                                     message_type,
                                     button_type,
                                     gcptr );
   g_free( gcptr );
   if( *cTitle )
   {
      gcptr = hwg_convert_to_utf8( cTitle );
      gtk_window_set_title( GTK_WINDOW(dialog), gcptr );
      g_free( gcptr );
   }
   gtk_window_set_position( GTK_WINDOW(dialog), GTK_WIN_POS_CENTER );
   gtk_window_set_policy( GTK_WINDOW(dialog), TRUE, TRUE, TRUE );

   result = gtk_dialog_run( GTK_DIALOG(dialog) );
   gtk_widget_destroy( dialog );
   return result;
}

HB_FUNC( MSGINFO )
{
   const char* cTitle = ( hb_pcount() == 1 )? "":hb_parc( 2 );
   MessageBox( hb_parc(1), cTitle, GTK_MESSAGE_INFO, GTK_BUTTONS_OK );
}

HB_FUNC( MSGSTOP )
{
   const char* cTitle = ( hb_pcount() == 1 )? "":hb_parc( 2 );
   MessageBox( hb_parc(1), cTitle, GTK_MESSAGE_ERROR, GTK_BUTTONS_CLOSE );        
}

HB_FUNC( MSGOKCANCEL )
{
   const char* cTitle = ( hb_pcount() == 1 )? "":hb_parc( 2 );
   hb_retl( MessageBox( hb_parc(1), cTitle, GTK_MESSAGE_QUESTION, GTK_BUTTONS_OK_CANCEL ) == GTK_RESPONSE_OK );
}

HB_FUNC( MSGYESNO )
{
   const char* cTitle = ( hb_pcount() == 1 )? "":hb_parc( 2 );
   hb_retl( MessageBox( hb_parc(1), cTitle, GTK_MESSAGE_QUESTION, GTK_BUTTONS_YES_NO ) == GTK_RESPONSE_YES );
}

HB_FUNC( MSGEXCLAMATION )
{
   const char* cTitle = ( hb_pcount() == 1 )? "":hb_parc( 2 );
   MessageBox( hb_parc(1), cTitle, GTK_MESSAGE_WARNING, GTK_BUTTONS_CLOSE );
}

