/*
 * $Id: control.c 1625 2011-08-05 13:14:50Z druzus $
 *
 * HWGUI - Harbour Linux (GTK) GUI library source code:
 * Widget creation functions
 *
 * Copyright 2004 Alexander S.Kresin <alex@belacy.belgorod.su>
 * www - http://kresin.belgorod.su
 *
 * StatusBar /ProgressBar and monthCalendar Functions
 *
 * Copyright 2008 Luiz Rafael Culik Guimaraes <luiz at xharbour.com.br >
 * www - http://sites.uol.com.br/culikr/
 
*/

#include "guilib.h"
#include "hbapifs.h"
#include "hbapiitm.h"
#include "hbvm.h"
#include "item.api"
#include "gtk/gtk.h"
#include "hwgtk.h"
#include "hbdate.h"
#ifdef __XHARBOUR__
#include "hbfast.h"
#endif

#define SS_CENTER                 1
#define SS_RIGHT                  2
#define ES_PASSWORD 32
#define ES_MULTILINE        4
#define ES_READONLY      2048

#define BS_AUTO3STATE       6
#define BS_GROUPBOX         7
#define BS_AUTORADIOBUTTON  9

#define SS_OWNERDRAW        13    // 0x0000000DL

#define WM_PAINT            15
#define WM_HSCROLL         276
#define WM_VSCROLL         277
#define WS_EX_TRANSPARENT      32      // 0x00000020L

extern PHB_ITEM GetObjectVar( PHB_ITEM pObject, char* varname );
extern void SetObjectVar( PHB_ITEM pObject, char* varname, PHB_ITEM pValue );
extern void SetWindowObject( GtkWidget * hWnd, PHB_ITEM pObject );
extern void set_signal( gpointer handle, char * cSignal, long int p1, long int p2, long int p3 );
extern void set_event( gpointer handle, char * cSignal, long int p1, long int p2, long int p3 );
extern void cb_signal( GtkWidget *widget,gchar* data );
extern void all_signal_connect( gpointer hWnd );
extern GtkWidget * GetActiveWindow( void );
extern GdkPixbuf * alpha2pixbuf( GdkPixbuf * hPixIn, long int nColor );
static GtkTooltips * pTooltip = NULL;
static PHB_DYNS pSymTimerProc = NULL;

GtkFixed * getFixedBox( GObject * handle )
{
   return (GtkFixed *) g_object_get_data( handle, "fbox" );
}

/*
   CreateStatic( hParentWindow, nControlID, nStyle, x, y, nWidth, nHeight, nExtStyle, cTitle )
*/
HB_FUNC( CREATESTATIC )
{
   HB_ULONG ulStyle = hb_parnl(3);
   const char * cTitle = ( hb_pcount() > 8 )? hb_parc(9) : "";
   GtkWidget * hCtrl, * hLabel;
   GtkFixed * box;
   HB_ULONG ulExtStyle = hb_parnl( 8 ) ;

   if( ( ulStyle & SS_OWNERDRAW ) == SS_OWNERDRAW )
      hCtrl = gtk_drawing_area_new();
   else
   {
      gchar * gcTitle = hwg_convert_to_utf8( cTitle );
      hCtrl = gtk_event_box_new();
      hLabel = gtk_label_new( gcTitle );
      g_free( gcTitle );
      gtk_container_add( GTK_CONTAINER(hCtrl), hLabel );
      g_object_set_data( (GObject*) hCtrl, "label", (gpointer) hLabel );
      if( ulExtStyle && WS_EX_TRANSPARENT )
      {
         gtk_event_box_set_visible_window( GTK_EVENT_BOX( hCtrl ) , 0 );
      }
      


      if( !( ulStyle & SS_CENTER ) )
         gtk_misc_set_alignment( GTK_MISC(hLabel), ( ulStyle & SS_RIGHT )? 1 : 0, 0 );
   }
   box = getFixedBox( (GObject*) HB_PARHANDLE(1) );
   if ( box )
      gtk_fixed_put( box, hCtrl, hb_parni(4), hb_parni(5) );
   gtk_widget_set_size_request( hCtrl,hb_parni(6),hb_parni(7) );

   if( ( ulStyle & SS_OWNERDRAW ) == SS_OWNERDRAW )
   {
      set_event( (gpointer)hCtrl, "expose_event", WM_PAINT, 0, 0 );
   }
   HB_RETHANDLE( hCtrl );

}

HB_FUNC( HWG_STATIC_SETTEXT )
{
   gchar * gcTitle = hwg_convert_to_utf8( hb_parcx(2) );
   GtkLabel * hLabel = (GtkLabel*) g_object_get_data( (GObject*) HB_PARHANDLE(1),"label" );
   gtk_label_set_text( hLabel, gcTitle );
   g_free( gcTitle );
}

/*
   CreateButton( hParentWindow, nButtonID, nStyle, x, y, nWidth, nHeight,
                 cCaption )
*/
HB_FUNC( CREATEBUTTON )
{
   GtkWidget * hCtrl,* img;
   HB_ULONG ulStyle = hb_parnl( 3 );
   const char * cTitle = ( hb_pcount() > 7 )? hb_parc(8) : "";
   GtkFixed * box;
   PHWGUI_PIXBUF szFile = HB_ISPOINTER(9) ? (PHWGUI_PIXBUF) HB_PARHANDLE(9): NULL;
   gchar * gcTitle = hwg_convert_to_utf8( cTitle );

   if( ( ulStyle & 0xf ) == BS_AUTORADIOBUTTON )
   {
      GSList * group = (GSList*)HB_PARHANDLE(2);
      hCtrl = gtk_radio_button_new_with_label( group, gcTitle );
      group = gtk_radio_button_get_group( (GtkRadioButton*)hCtrl );
      HB_STOREHANDLE( group,2 );
   }
   else if( ( ulStyle & 0xf ) == BS_AUTO3STATE )
      hCtrl = gtk_check_button_new_with_label( gcTitle );
   else if( ( ulStyle & 0xf ) == BS_GROUPBOX )
      hCtrl = gtk_frame_new( gcTitle );
   else
      hCtrl = gtk_button_new_with_mnemonic( gcTitle );

#if GTK_CHECK_VERSION(2,4,1)
   if (szFile )
   {
      img = gtk_image_new_from_pixbuf(szFile->handle);
      gtk_button_set_image(GTK_BUTTON(hCtrl),img);
   }
#endif
   g_free( gcTitle );
   box = getFixedBox( (GObject*) HB_PARHANDLE(1) );
   if ( box )
      gtk_fixed_put( box, hCtrl, hb_parni(4), hb_parni(5) );
   gtk_widget_set_size_request( hCtrl,hb_parni(6),hb_parni(7) );

   HB_RETHANDLE( hCtrl );
}

HB_FUNC( HWG_CHECKBUTTON )
{
   gtk_toggle_button_set_active( (GtkToggleButton*)HB_PARHANDLE(1), hb_parl(2) );
}

HB_FUNC( HWG_ISBUTTONCHECKED )
{
   hb_retl( gtk_toggle_button_get_active( (GtkToggleButton*)HB_PARHANDLE(1) ) );
}

/*
   CreateEdit( hParentWIndow, nEditControlID, nStyle, x, y, nWidth, nHeight,
               cInitialString )
*/
HB_FUNC( CREATEEDIT )
{
   GtkWidget * hCtrl;
   const char * cTitle = ( hb_pcount() > 7 )? hb_parc(8) : "";
   unsigned long ulStyle = (HB_ISNIL(3))? 0 : hb_parnl(3);

   if( ulStyle & ES_MULTILINE )
   {
      hCtrl = gtk_text_view_new();
      g_object_set_data( (GObject*) hCtrl, "multi", (gpointer) 1 );
      if( ulStyle & ES_READONLY )
         gtk_text_view_set_editable( (GtkTextView*)hCtrl, 0 );
   }
   else
      hCtrl = gtk_entry_new();
   if( ulStyle & ES_PASSWORD )
      gtk_entry_set_visibility((GtkEntry*)hCtrl,FALSE);


   GtkFixed * box = getFixedBox( (GObject*) HB_PARHANDLE(1) );
   if ( box )
      gtk_fixed_put( box, hCtrl, hb_parni(4), hb_parni(5) );
   gtk_widget_set_size_request( hCtrl,hb_parni(6),hb_parni(7) );

   if( *cTitle )
   {
      gchar * gcTitle = hwg_convert_to_utf8( cTitle );
      if( ulStyle & ES_MULTILINE )
      {
         GtkTextBuffer *buffer = gtk_text_view_get_buffer (GTK_TEXT_VIEW (hCtrl));
         gtk_text_buffer_set_text( buffer, gcTitle, -1 );
      }
      else
         gtk_entry_set_text( (GtkEntry*)hCtrl, gcTitle );
      g_free( gcTitle );
   }

   all_signal_connect( (gpointer) hCtrl );
   HB_RETHANDLE( hCtrl );

}

HB_FUNC( HWG_EDIT_SETTEXT )
{
   GtkWidget * hCtrl = (GtkWidget *)HB_PARHANDLE(1);
   gchar * gcTitle = hwg_convert_to_utf8( hb_parcx(2) );

   if( g_object_get_data( (GObject *)hCtrl, "multi" ) )
   {
      GtkTextBuffer *buffer = gtk_text_view_get_buffer (GTK_TEXT_VIEW (hCtrl));
      gtk_text_buffer_set_text( buffer, gcTitle, -1 );
   }
   else
      gtk_entry_set_text( (GtkEntry*)hCtrl, gcTitle );
   g_free( gcTitle );
}

HB_FUNC( HWG_EDIT_GETTEXT )
{
   GtkWidget * hCtrl = (GtkWidget *)HB_PARHANDLE(1);
   char * cptr;

   if( g_object_get_data( (GObject *)hCtrl, "multi" ) )
   {
      GtkTextBuffer *buffer = gtk_text_view_get_buffer (GTK_TEXT_VIEW (hCtrl));
      GtkTextIter iterStart, iterEnd;

      gtk_text_buffer_get_start_iter( buffer, &iterStart );
      gtk_text_buffer_get_end_iter( buffer, &iterEnd );
      cptr = gtk_text_buffer_get_text( buffer, &iterStart, &iterEnd, 1 );
   }
   else
      cptr = (char*) gtk_entry_get_text( (GtkEntry*)hCtrl );

   if( *cptr )
   {
      cptr = hwg_convert_from_utf8( cptr );
      hb_retc( cptr );
      g_free( cptr );
   }
   else
      hb_retc( "" );
}

HB_FUNC( HWG_EDIT_SETPOS )
{
   gtk_editable_set_position( (GtkEditable*)HB_PARHANDLE(1), hb_parni(2) );
}

HB_FUNC( HWG_EDIT_GETPOS )
{
   hb_retni( gtk_editable_get_position( (GtkEditable*)HB_PARHANDLE(1) ) );
}

/*
   CreateCombo( hParentWIndow, nComboID, nStyle, x, y, nWidth, nHeight )
*/
HB_FUNC( CREATECOMBO )
{
   GtkWidget * hCtrl = gtk_combo_new();
   GtkFixed * box = getFixedBox( (GObject*) HB_PARHANDLE(1) );
   if ( box )
      gtk_fixed_put( box, hCtrl, hb_parni(4), hb_parni(5) );
   gtk_widget_set_size_request( hCtrl,hb_parni(6),hb_parni(7) );

   HB_RETHANDLE( hCtrl );
}

HB_FUNC( HWG_COMBOSETARRAY )
{
   PHB_ITEM pArray = hb_param( 2, HB_IT_ARRAY );
   GList *glist = NULL;

   if( pArray )
   {
      HB_ULONG ul, ulLen = hb_arrayLen( pArray );
      char * cItem;

      for( ul = 1; ul <= ulLen; ++ul )
      {
         cItem = hwg_convert_to_utf8( hb_arrayGetCPtr( pArray, ul ) );
         glist = g_list_append( glist, cItem );
         // g_free( cItem );
      }
   }

   gtk_combo_set_popdown_strings( GTK_COMBO( HB_PARHANDLE(1) ), glist );

}

HB_FUNC( HWG_COMBOGETEDIT )
{
   hb_retptr( (void *) (GTK_COMBO( HB_PARHANDLE(1) )->entry) );
}

/*
HB_FUNC( HWG_COMBOSETSTRING )
{
   gtk_entry_set_text( GTK_ENTRY (GTK_COMBO( hb_parnl(1) )->entry), hb_parc(2) );
}

HB_FUNC( HWG_COMBOGETSTRING )
{
   gtk_entry_get_text( GTK_ENTRY ( GTK_COMBO( hb_parnl(1) )->entry) );
}
*/

HB_FUNC( CREATEUPDOWNCONTROL )
{
   GtkObject * adj = gtk_adjustment_new( (gdouble) hb_parnl(6),  // value
                             (gdouble) hb_parnl(7),  // lower
                             (gdouble) hb_parnl(8),  // upper
                               1, 1, 1 );
   GtkWidget * hCtrl = gtk_spin_button_new( (GtkAdjustment*)adj,0.5,0 );

   GtkFixed * box = getFixedBox( (GObject*) HB_PARHANDLE(1) );
   if ( box )
      gtk_fixed_put( box, hCtrl, hb_parni(2), hb_parni(3) );
   gtk_widget_set_size_request( hCtrl,hb_parni(4),hb_parni(5) );

   HB_RETHANDLE( hCtrl );

}

HB_FUNC( HWG_SETUPDOWN )
{
   gtk_spin_button_set_value( (GtkSpinButton*)HB_PARHANDLE(1), (gdouble)hb_parnl(2) );
}

HB_FUNC( HWG_GETUPDOWN )
{
   hb_retnl( gtk_spin_button_get_value_as_int( (GtkSpinButton*)HB_PARHANDLE(1) ) );
}

#define WS_VSCROLL          2097152    // 0x00200000L
#define WS_HSCROLL          1048576    // 0x00100000L

HB_FUNC( CREATEBROWSE )
{
   GtkWidget *vbox, *hbox;
   GtkWidget *vscroll, *hscroll;
   GtkWidget *area;
   GtkFixed * box;
   PHB_ITEM pObject = hb_param( 1, HB_IT_OBJECT ), temp; 
   GObject * handle;
   int nLeft = hb_itemGetNI( GetObjectVar( pObject, "NLEFT" ) );
   int nTop = hb_itemGetNI( GetObjectVar( pObject, "NTOP" ) );
   int nWidth = hb_itemGetNI( GetObjectVar( pObject, "NWIDTH" ) );
   int nHeight = hb_itemGetNI( GetObjectVar( pObject, "NHEIGHT" ) );
   unsigned long int ulStyle = hb_itemGetNL( GetObjectVar( pObject, "STYLE" ) );

   temp = GetObjectVar( pObject, "OPARENT" );
   handle = (GObject*) HB_GETHANDLE( GetObjectVar( temp, "HANDLE" ) );

   hbox = gtk_hbox_new( FALSE, 0 );
   vbox = gtk_vbox_new( FALSE, 0 );

   area    = gtk_drawing_area_new();

   gtk_box_pack_start( GTK_BOX( hbox ), vbox, TRUE, TRUE, 0 );
   if( ulStyle & WS_VSCROLL )
   {
      GtkObject *adjV;
      adjV = gtk_adjustment_new( 0.0, 0.0, 101.0, 1.0, 10.0, 10.0 );
      vscroll = gtk_vscrollbar_new( GTK_ADJUSTMENT (adjV) );
      gtk_box_pack_end( GTK_BOX( hbox ), vscroll, FALSE, FALSE, 0 );

      temp = HB_PUTHANDLE( NULL, adjV );
      SetObjectVar( pObject, "_HSCROLLV", temp );
      hb_itemRelease( temp );

      SetWindowObject( (GtkWidget*)adjV, pObject );
      set_signal( (gpointer)adjV, "value_changed", WM_VSCROLL, 0, 0 );
   }

   gtk_box_pack_start( GTK_BOX( vbox ), area, TRUE, TRUE, 0 );
   if( ulStyle & WS_HSCROLL )
   {
      GtkObject *adjH;
      adjH = gtk_adjustment_new( 0.0, 0.0, 101.0, 1.0, 10.0, 10.0 );
      hscroll = gtk_hscrollbar_new( GTK_ADJUSTMENT (adjH) );
      gtk_box_pack_end( GTK_BOX( vbox ), hscroll, FALSE, FALSE, 0 );

      temp = HB_PUTHANDLE( NULL, adjH );
      SetObjectVar( pObject, "_HSCROLLH", temp );
      hb_itemRelease( temp );

      SetWindowObject( (GtkWidget*)adjH, pObject );
      set_signal( (gpointer)adjH, "value_changed", WM_HSCROLL, 0, 0 );
   }

   box = getFixedBox( handle );
   if ( box )
      gtk_fixed_put( box, hbox, nLeft, nTop );
   gtk_widget_set_size_request( hbox, nWidth, nHeight );

   temp = HB_PUTHANDLE( NULL, area );
   SetObjectVar( pObject, "_AREA", temp );
   hb_itemRelease( temp );

   SetWindowObject( area, pObject );
   set_event( (gpointer)area, "expose_event", WM_PAINT, 0, 0 );

   GTK_WIDGET_SET_FLAGS( area,GTK_CAN_FOCUS );

   gtk_widget_add_events( area, GDK_BUTTON_PRESS_MASK |
         GDK_BUTTON_RELEASE_MASK | GDK_KEY_PRESS_MASK | GDK_KEY_RELEASE_MASK |
         GDK_POINTER_MOTION_MASK | GDK_SCROLL_MASK );
   set_event( (gpointer)area, "button_press_event", 0, 0, 0 );
   set_event( (gpointer)area, "button_release_event", 0, 0, 0 );
   set_event( (gpointer)area, "motion_notify_event", 0, 0, 0 );
   set_event( (gpointer)area, "key_press_event", 0, 0, 0 );
   set_event( (gpointer)area, "key_release_event", 0, 0, 0 );
   set_event( (gpointer)area, "scroll_event", 0, 0, 0 );

   // gtk_widget_show_all( hbox );
   all_signal_connect( (gpointer) area );
   HB_RETHANDLE( hbox );
}

HB_FUNC( HWG_GETADJVALUE )
{
   GtkAdjustment *adj = (GtkAdjustment *) HB_PARHANDLE(1);
   int iOption = (HB_ISNIL(2))? 0 : hb_parni(2);

   if( iOption == 0 )
      hb_retnl( (HB_LONG) adj->value );
   else if( iOption == 1 )
      hb_retnl( (HB_LONG) adj->upper );
   else if( iOption == 2 )
      hb_retnl( (HB_LONG) adj->step_increment );
   else if( iOption == 3 )
      hb_retnl( (HB_LONG) adj->page_increment );
   else if( iOption == 4 )
      hb_retnl( (HB_LONG) adj->page_size );
   else
      hb_retnl( 0 );
}

/*
 * hwg_SetAdjOptions( hAdj, value, maxpos, step, pagestep, pagesize )
 */
HB_FUNC( HWG_SETADJOPTIONS )
{
   GtkAdjustment *adj = (GtkAdjustment *) HB_PARHANDLE(1);
   gdouble value;
   int lChanged = 0;

   if( !HB_ISNIL(2) && ( value = (gdouble)hb_parnl(2) ) != adj->value )
   {
      adj->value = value;
      lChanged = 1;
   }
   if( !HB_ISNIL(3) && ( value = (gdouble)hb_parnl(3) ) != adj->upper )
   {
      adj->upper = value;
      lChanged = 1;
   }
   if( !HB_ISNIL(4) && ( value = (gdouble)hb_parnl(4) ) != adj->step_increment )
   {
      adj->step_increment = value;
      lChanged = 1;
   }
   if( !HB_ISNIL(5) && ( value = (gdouble)hb_parnl(5) ) != adj->page_increment )
   {
      adj->page_increment = value;
      lChanged = 1;
   }
   if( !HB_ISNIL(6) && ( value = (gdouble)hb_parnl(6) ) != adj->page_size )
   {
      adj->page_size = value;
      lChanged = 1;
   }
   if( lChanged )
      gtk_adjustment_changed( adj );
}

HB_FUNC( CREATETABCONTROL )
{
   GtkWidget * hCtrl = gtk_notebook_new();

   GtkFixed * box = getFixedBox( (GObject*) HB_PARHANDLE(1) );
   if ( box )
      gtk_fixed_put( box, hCtrl, hb_parni(4), hb_parni(5) );
   gtk_widget_set_size_request( hCtrl,hb_parni(6),hb_parni(7) );

   HB_RETHANDLE( hCtrl );

}

HB_FUNC( ADDTAB )
{
   GtkNotebook * nb = (GtkNotebook*) HB_PARHANDLE(1);
   GtkWidget * box = gtk_fixed_new();
   GtkWidget * hLabel;
   char * cLabel = hwg_convert_to_utf8( hb_parc(2) );

   hLabel = gtk_label_new( cLabel );
   g_free( cLabel );

   gtk_notebook_append_page( nb, box, hLabel );

   g_object_set_data( (GObject*) nb, "fbox", (gpointer) box );

   HB_RETHANDLE( nb );
}

HB_FUNC( GETCURRENTTAB )
{
   hb_retni( gtk_notebook_get_current_page( (GtkNotebook*)HB_PARHANDLE(1) ) + 1 );
}

HB_FUNC( HWG_CREATESEP )
{
   HB_BOOL lVert = hb_parl(2);
   GtkWidget * hCtrl;
   GtkFixed * box;

   if( lVert )
      hCtrl = gtk_vseparator_new();
   else
      hCtrl = gtk_hseparator_new();
   box = getFixedBox( (GObject*) HB_PARHANDLE(1) );
   if ( box )
      gtk_fixed_put( box, hCtrl, hb_parni(3), hb_parni(4) );
   gtk_widget_set_size_request( hCtrl,hb_parni(5),hb_parni(6) );

   HB_RETHANDLE( hCtrl );
}

/*
   CreatePanel( hParentWindow, nControlID, nStyle, x, y, nWidth, nHeight, nExtStyle, cTitle )
*/
HB_FUNC( CREATEPANEL )
{
   GtkWidget *hCtrl;
   GtkFixed *box, *fbox;

   fbox = (GtkFixed*)gtk_fixed_new();
   hCtrl = gtk_drawing_area_new();

   box = getFixedBox( (GObject*) HB_PARHANDLE(1) );
   if ( box )
   {
      gtk_fixed_put( box, (GtkWidget*)fbox, hb_parni(4), hb_parni(5) );
      gtk_widget_set_size_request( (GtkWidget*)fbox,hb_parni(6),hb_parni(7) );
   }
   gtk_fixed_put( fbox, hCtrl, 0, 0 );
   gtk_widget_set_size_request( hCtrl,hb_parni(6),hb_parni(7) );
   g_object_set_data( (GObject*) hCtrl, "fbox", (gpointer) fbox );
   GTK_WIDGET_SET_FLAGS( hCtrl, GTK_CAN_FOCUS );
   set_event( (gpointer)hCtrl, "expose_event", WM_PAINT, 0, 0 );
   gtk_widget_add_events( hCtrl, GDK_BUTTON_PRESS_MASK | 
        GDK_BUTTON_RELEASE_MASK | GDK_ENTER_NOTIFY_MASK | GDK_LEAVE_NOTIFY_MASK );
   set_event( (gpointer)hCtrl, "button_press_event", 0, 0, 0 );
   set_event( (gpointer)hCtrl, "button_release_event", 0, 0, 0 );
   set_event( (gpointer)hCtrl, "enter_notify_event", 0, 0, 0 );
   set_event( (gpointer)hCtrl, "leave_notify_event", 0, 0, 0 );
   all_signal_connect( (gpointer) hCtrl );

   HB_RETHANDLE( hCtrl );

}

HB_FUNC( DESTROYPANEL )
{
   GtkFixed *box = getFixedBox( (GObject*) HB_PARHANDLE(1) );
   if( box )
      gtk_widget_destroy( (GtkWidget *) box );
}

/*
   CreateOwnBtn( hParentWindow, nControlID, x, y, nWidth, nHeight )
*/
HB_FUNC( CREATEOWNBTN )
{
   GtkWidget * hCtrl;
   GtkFixed * box;

   hCtrl = gtk_drawing_area_new();

   box = getFixedBox( (GObject*) HB_PARHANDLE(1) );
   if ( box )
   {
      gtk_fixed_put( box, hCtrl, hb_parni(3), hb_parni(4) );
      gtk_widget_set_size_request( hCtrl,hb_parni(5),hb_parni(6) );
   }
   set_event( (gpointer)hCtrl, "expose_event", WM_PAINT, 0, 0 );
   gtk_widget_add_events( hCtrl, GDK_BUTTON_PRESS_MASK | 
        GDK_BUTTON_RELEASE_MASK | GDK_ENTER_NOTIFY_MASK | GDK_LEAVE_NOTIFY_MASK );
   set_event( (gpointer)hCtrl, "button_press_event", 0, 0, 0 );
   set_event( (gpointer)hCtrl, "button_release_event", 0, 0, 0 );
   set_event( (gpointer)hCtrl, "enter_notify_event", 0, 0, 0 );
   set_event( (gpointer)hCtrl, "leave_notify_event", 0, 0, 0 );
   all_signal_connect( (gpointer) hCtrl );

   HB_RETHANDLE( hCtrl );

}


HB_FUNC( ADDTOOLTIP )
{
   if( !pTooltip )
      pTooltip = gtk_tooltips_new();
   gtk_tooltips_set_tip( pTooltip, (GtkWidget*)HB_PARHANDLE(2), hb_parc(3), NULL );
}

static gint cb_timer( gchar * data )
{
   HB_LONG p1;

   sscanf( (char*)data,"%ld",&p1 );

   if( !pSymTimerProc )
      pSymTimerProc = hb_dynsymFind( "TIMERPROC" );

   if( pSymTimerProc )
   {
      hb_vmPushSymbol( hb_dynsymSymbol( pSymTimerProc ) );
      hb_vmPushNil();
      hb_vmPushLong( (HB_LONG ) p1 );
      hb_vmDo( 1 );
   }
   return 1;
}

/*
 *  HWG_SetTimer( idTimer,i_MilliSeconds ) -> tag
 */

HB_FUNC( HWG_SETTIMER )
{
   char buf[10]={0};
   sprintf( buf,"%ld",hb_parnl(1) );
   hb_retni( (gint) gtk_timeout_add( (guint32)hb_parnl(2), (GtkFunction)cb_timer, g_strdup(buf) ) );
}

/*
 *  HWG_KillTimer( tag )
 */

HB_FUNC( HWG_KILLTIMER )
{
   gtk_timeout_remove( (gint) hb_parni(1) );
}

HB_FUNC( GETPARENT )
{
   hb_retptr( (void*) ( (GtkWidget*) HB_PARHANDLE(1) )->parent );
}

HB_FUNC( LOADCURSOR )
{
   if( HB_ISCHAR(1) )
   {
      // hb_retnl( (HB_LONG) LoadCursor( GetModuleHandle( NULL ), hb_parc( 1 )  ) );
   }
   else
      HB_RETHANDLE( gdk_cursor_new( (GdkCursorType) hb_parni(1) ) );
}

HB_FUNC( HWG_SETCURSOR )
{
   GtkWidget * widget = (HB_ISPOINTER(2))? (GtkWidget*) HB_PARHANDLE(2) : GetActiveWindow();
   gdk_window_set_cursor( widget->window, (GdkCursor*) HB_PARHANDLE(1) );
}

HB_FUNC( HWG_MOVEWIDGET )
{
   GtkWidget * widget = (GtkWidget*) HB_PARHANDLE(1);
   GtkWidget * ch_widget = NULL;

   if( !HB_ISNIL(6) && hb_parl(6) )
   {
      ch_widget = widget;
      widget = widget->parent;
   }
 
   if( !HB_ISNIL(2) && !HB_ISNIL(3) )
   {
      gtk_fixed_move( (GtkFixed*) (widget->parent), widget, hb_parni(2), hb_parni(3) );
   }
   if( !HB_ISNIL(4) || !HB_ISNIL(5) )
   {
      gint w, h, w1, h1;

      gtk_widget_get_size_request( widget, &w, &h );
      w1 = ( HB_ISNIL(4) )? w : hb_parni(4);
      h1 = ( HB_ISNIL(5) )? h : hb_parni(5);
      if( w != w1 || h != h1 )
      {
         gtk_widget_set_size_request( widget, w1, h1 );
         if( ch_widget )
            gtk_widget_set_size_request( ch_widget, w1, h1 );
      }
   }
}

HB_FUNC(CREATEPROGRESSBAR)
{
   GtkWidget * hCtrl;
   GtkFixed * box = getFixedBox( (GObject*) HB_PARHANDLE(1) );
   hCtrl = gtk_progress_bar_new();

   if ( box )
      gtk_fixed_put( box, hCtrl, hb_parni(3), hb_parni(4) );
   gtk_widget_set_size_request( hCtrl,hb_parni(5),hb_parni(6) );
   HB_RETHANDLE( hCtrl );
}

HB_FUNC( UPDATEPROGRESSBAR )
{
  // SendMessage( (HWND) hb_parnl(1), PBM_STEPIT, 0, 0 );
  gtk_progress_bar_pulse((GtkProgressBar*)HB_PARHANDLE(1));
}

HB_FUNC( SETPROGRESSBAR )
{
   GtkWidget * widget = (GtkWidget*) HB_PARHANDLE(1);   
   gdouble b= (gdouble) hb_parnd( 2) ;

   gtk_progress_bar_update(GTK_PROGRESS_BAR(widget),b);
   while (gtk_events_pending()) { gtk_main_iteration();}

}

HB_FUNC( CREATESTATUSWINDOW )
{
   GtkWidget * w;
   GObject * handle = (GObject*) HB_PARHANDLE(1);
   GtkFixed * box = getFixedBox( handle );
   GtkWidget * vbox = ( (GtkWidget*)box )->parent;
   w  = gtk_statusbar_new() ;   
   gtk_box_pack_end( GTK_BOX (vbox), (GtkWidget*)w, FALSE, FALSE, 0);     
   gtk_box_reorder_child(GTK_BOX(vbox) ,w,9999);

  HB_RETHANDLE( w);
}

HB_FUNC( STATUSBARSETTEXT )
{
   gchar *gcTitle = hwg_convert_to_utf8( hb_parcx(3) );
   GtkWidget *w = (GtkWidget *) hb_parptr(1);
   int iStatus = hb_parni(2)-1;
   hb_retni(gtk_statusbar_push(GTK_STATUSBAR(w), iStatus, gcTitle));
   g_free( gcTitle );
}

/* ------------------------------------------------------------------------ */

/* void gtk_statusbar_pop (GtkStatusbar *statusbar, guint context_id); */
HB_FUNC( STATUSBARREMOVETEXT )
{
   GtkWidget *w = (GtkWidget *) HB_PARHANDLE(1);
   int iStatus = hb_parni(2-1);
   gtk_statusbar_pop(GTK_STATUSBAR(w), iStatus);
}

static void toolbar_clicked( GtkWidget *item,
                             gpointer user_data)
{
  PHB_ITEM pData = (PHB_ITEM) user_data;
  hb_vmEvalBlock( ( PHB_ITEM ) pData );
  HB_SYMBOL_UNUSED( item );
}

HB_FUNC(CREATETOOLBAR)
{
   GtkWidget * hCtrl = gtk_toolbar_new ();

//   GtkFixed * box = getFixedBox( (GObject*) HB_PARHANDLE(1) );
//   GtkWidget *tmp_image;
//   GtkWidget *toolbutton1;   
//   GtkWidget *toolbutton2;   
//   gint tmp_toolbar_icon_size;
   GObject * handle = (GObject*) HB_PARHANDLE(1);
   GtkFixed * box = getFixedBox( handle );
   GtkWidget * vbox = ( (GtkWidget*)box )->parent;
   gtk_box_pack_start( GTK_BOX (vbox), hCtrl, FALSE, FALSE, 0);  
   HB_RETHANDLE( hCtrl );
}

HB_FUNC(CREATETOOLBARBUTTON)
{
#if GTK_CHECK_VERSION(2,4,1)
  GtkWidget *toolbutton1,*img;   
  GtkWidget *hCtrl = (GtkWidget *) HB_PARHANDLE(1);
  PHWGUI_PIXBUF szFile = HB_ISPOINTER(2) ? (PHWGUI_PIXBUF) HB_PARHANDLE(2): NULL;  
  const char * szLabel = HB_ISCHAR( 3 ) ? hb_parc( 3 ) : NULL ;
  HB_BOOL lSep = hb_parl( 4 );
  gchar * gcLabel = NULL;

  if ( szLabel )
  {
     gcLabel = hwg_convert_to_utf8( szLabel );
  }
  if (lSep) 
  {
     toolbutton1 = ( GtkWidget * ) gtk_separator_tool_item_new();
  }
  else
  {
     if (szFile )
     {
        img = gtk_image_new_from_pixbuf( szFile->handle );
        gtk_widget_show( img );
        toolbutton1 = ( GtkWidget * ) gtk_tool_button_new( img, gcLabel );
     }
     else
     { 
        toolbutton1 = ( GtkWidget * ) gtk_tool_button_new( NULL, gcLabel );
     }
     if ( gcLabel )
     {
        g_free( gcLabel );
     }
  }
  gtk_widget_show ( toolbutton1 );   
  gtk_container_add ( GTK_CONTAINER( hCtrl ), toolbutton1 );

  HB_RETHANDLE( toolbutton1 );
#endif
}


HB_FUNC(TOOLBAR_SETACTION)
{
  GtkWidget *hCtrl = (GtkWidget *) HB_PARHANDLE(1);
  PHB_ITEM pItem = hb_itemParam( 2 ) ;
  g_signal_connect (hCtrl, "clicked",
                    G_CALLBACK (toolbar_clicked), (void*) pItem);
}

static void tabchange_clicked(GtkNotebook *item,
                              GtkNotebookPage * Page,
                              guint pagenum,
                              gpointer user_data)
{
  PHB_ITEM pData = (PHB_ITEM) user_data;
  gpointer dwNewLong = g_object_get_data( (GObject*) item, "obj" );
  PHB_ITEM pObject = (PHB_ITEM) dwNewLong ;
  PHB_ITEM Disk=hb_itemPutNL( NULL, pagenum+1);

  HB_SYMBOL_UNUSED( Page );
  hb_vmEvalBlockV( (PHB_ITEM) pData, 2,pObject,Disk  );
  hb_itemRelease( Disk );
}

//static void tabchange_clicked1(GtkNotebook *item,
//                               gint pagenum,
//                               gpointer user_data)
//{
//  PHB_ITEM pData = (PHB_ITEM) user_data;
//  gpointer dwNewLong = g_object_get_data( (GObject*) item, "obj" );
//  PHB_ITEM pObject = (PHB_ITEM) dwNewLong ;
//  PHB_ITEM Disk=hb_itemPutNL( NULL, pagenum);
//  hb_vmEvalBlockV( ( PHB_ITEM ) pData ,2,pObject,Disk);	    
//  hb_vmEvalBlockV( ChangeDiskBlock, 1, Disk  );
//  hb_itemRelease( Disk );
//}


HB_FUNC(TAB_SETACTION  )
{
  GtkWidget *hCtrl = (GtkWidget *) HB_PARHANDLE(1);
//  gpointer dwNewLong = g_object_get_data( (GObject*) HB_PARHANDLE(1), "obj" );  
  PHB_ITEM pItem = hb_itemParam( 2 ) ;
  g_signal_connect (hCtrl, "switch-page",
			    G_CALLBACK (tabchange_clicked), (void*) pItem);		    
}

HB_FUNC(INITMONTHCALENDAR)
{
   GtkWidget * hCtrl;
   GtkFixed * box = getFixedBox( (GObject*) HB_PARHANDLE(1) );

   hCtrl = gtk_calendar_new();

   if ( box )
      gtk_fixed_put( box, hCtrl, hb_parni(3), hb_parni(4) );
   gtk_widget_set_size_request( hCtrl,hb_parni(5),hb_parni(6) );
   HB_RETHANDLE( hCtrl );
}

HB_FUNC ( SETMONTHCALENDARDATE ) // adaptation of function SetDatePicker of file Control.c
{
   PHB_ITEM pDate = hb_param( 2, HB_IT_DATE );

   if( pDate )
   {
      GtkWidget *hCtrl = (GtkWidget *) HB_PARHANDLE(1);    
      #ifndef HARBOUR_OLD_VERSION
      int lYear, lMonth, lDay;
      #else
      long lYear, lMonth, lDay;
      #endif

      hb_dateDecode( hb_itemGetDL( pDate ), &lYear, &lMonth, &lDay );

      gtk_calendar_select_month(GTK_CALENDAR(hCtrl),lMonth,lYear);
      gtk_calendar_select_day(GTK_CALENDAR(hCtrl),lDay);


   }
}

HB_FUNC( GETMONTHCALENDARDATE )
{
   GtkWidget *hCtrl = (GtkWidget *) HB_PARHANDLE(1);    
   char szDate[9];
   #ifndef HARBOUR_OLD_VERSION
   int lYear, lMonth, lDay;
   #else
   long lYear, lMonth, lDay;
   #endif
   gtk_calendar_get_date( GTK_CALENDAR(hCtrl),(guint*)&lYear, (guint*)&lMonth, (guint*)&lDay );
   
   lMonth = lMonth + 1;  
      
   hb_dateStrPut( szDate, lYear, lMonth, lDay  );
   szDate[8] = 0;
   hb_retds( szDate );
}   


HB_FUNC( CREATEIMAGE )
{
   GtkWidget * hCtrl;
   GtkFixed * box = getFixedBox( (GObject*) HB_PARHANDLE(1) );
   GdkPixbuf * handle = gdk_pixbuf_new_from_file( hb_parc(2), NULL );   
   GdkPixbuf * pHandle= alpha2pixbuf( handle, 16777215 );   

   hCtrl = gtk_image_new_from_pixbuf(pHandle);

   if ( box )
      gtk_fixed_put( box, hCtrl, hb_parni(3), hb_parni(4) );
   gtk_widget_set_size_request( hCtrl,hb_parni(5),hb_parni(6) );
   HB_RETHANDLE( hCtrl );
}

HB_FUNC( MONTHCALENDAR_SETACTION )
{
   GtkWidget *hCtrl = (GtkWidget *) HB_PARHANDLE(1);
   PHB_ITEM pItem = hb_itemParam( 2 ) ;

   g_signal_connect (hCtrl, "day-selected", G_CALLBACK (toolbar_clicked), (void*) pItem);
}			    

void hwg_parse_color( HB_ULONG ncolor, GdkColor * pColor );

HB_FUNC( SETFGCOLOR )
{
   GtkWidget *hCtrl = (GtkWidget *) HB_PARHANDLE(1);
   GdkColor fColor;
   GtkWidget *label ;
   HB_ULONG hColor = hb_parnl( 2 ) ;

   if (GTK_IS_BUTTON(hCtrl) )
      label = gtk_bin_get_child(GTK_BIN(hCtrl));
   else if (GTK_IS_EVENT_BOX(hCtrl) )
      label = gtk_bin_get_child(GTK_BIN(hCtrl));               
   else     
      label = g_object_get_data( (GObject*) hCtrl, "label" );

   if( label )
   {     
      hwg_parse_color( hColor, &fColor );
      gtk_widget_modify_fg(label,GTK_STATE_NORMAL,&fColor);
   }
}  

HB_FUNC(SETBGCOLOR)
{
  GtkWidget *hCtrl = (GtkWidget *) HB_PARHANDLE(1);
  GdkColor fColor;
  GtkWidget *label ;
  HB_ULONG hColor = hb_parnl( 2 ) ;
//  TraceLog("cor.txt","cor = %lu control = %lu\n" , hColor,hCtrl);
  hwg_parse_color( hColor, &fColor );
//  label = g_object_get_data( (GObject*) hCtrl, "label" );  
  if (GTK_IS_BUTTON(hCtrl) )
     label = gtk_bin_get_child(GTK_BIN(hCtrl));
  else if (GTK_IS_EVENT_BOX(hCtrl) )
     label = gtk_bin_get_child(GTK_BIN(hCtrl));       
  else  
     label = g_object_get_data( (GObject*) hCtrl, "label" );
//  gtk_widget_modify_bg(hCtrl,GTK_STATE_NORMAL,&fColor);
  gtk_widget_modify_bg(label,GTK_STATE_NORMAL,&fColor);  
//  gtk_widget_modify_bg(hCtrl,GTK_STATE_ACTIVE,&fColor);
//  gtk_widget_modify_bg(hCtrl,GTK_STATE_PRELIGHT,&fColor);    
}  

/*
   CreateSplitter( hParentWindow, nControlID, nStyle, x, y, nWidth, nHeight )
*/
HB_FUNC( CREATESPLITTER )
{
   HB_ULONG ulStyle = hb_parnl(3);
   GtkWidget * hCtrl;
   GtkFixed *box, *fbox;

   fbox = (GtkFixed*)gtk_fixed_new();

   hCtrl = gtk_drawing_area_new();
   box = getFixedBox( (GObject*) HB_PARHANDLE(1) );

   if ( box )
   {
      gtk_fixed_put( box, (GtkWidget*)fbox, hb_parni(4), hb_parni(5) );
      gtk_widget_set_size_request( (GtkWidget*)fbox,hb_parni(6),hb_parni(7) );
   }
   gtk_fixed_put( fbox, hCtrl, 0, 0 );
   gtk_widget_set_size_request( hCtrl,hb_parni(6),hb_parni(7) );
   g_object_set_data( (GObject*) hCtrl, "fbox", (gpointer) fbox );

   set_event( (gpointer)hCtrl, "expose_event", WM_PAINT, 0, 0 );
   GTK_WIDGET_SET_FLAGS( hCtrl,GTK_CAN_FOCUS );

   gtk_widget_add_events( hCtrl, GDK_BUTTON_PRESS_MASK | 
        GDK_BUTTON_RELEASE_MASK | GDK_POINTER_MOTION_MASK );
   set_event( (gpointer)hCtrl, "button_press_event", 0, 0, 0 );
   set_event( (gpointer)hCtrl, "button_release_event", 0, 0, 0 );
   set_event( (gpointer)hCtrl, "motion_notify_event", 0, 0, 0 );

   all_signal_connect( (gpointer) hCtrl );
   HB_RETHANDLE( hCtrl );

}
