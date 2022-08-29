/*
 * $Id: hwgtk.h 1625 2011-08-05 13:14:50Z druzus $
 */


typedef struct HWGUI_HDC_STRU
{
  GtkWidget * widget;
  GdkDrawable * window;
  GdkGC * gc;
  PangoFontDescription * hFont;
  PangoLayout * layout;
  long fcolor, bcolor;
} HWGUI_HDC, * PHWGUI_HDC;

typedef struct HWGUI_PPS_STRU
{
  PHWGUI_HDC hDC;
} HWGUI_PPS, * PHWGUI_PPS;

#define HWGUI_OBJECT_PEN    1
#define HWGUI_OBJECT_BRUSH  2
#define HWGUI_OBJECT_FONT   3
#define HWGUI_OBJECT_PIXBUF 4

typedef struct HWGUI_HDC_OBJECT_STRU
{
   short int type;
} HWGUI_HDC_OBJECT;

typedef struct HWGUI_PEN_STRU
{
   short int type;
   gint width;
   GdkLineStyle style;
   GdkColor color;
} HWGUI_PEN, * PHWGUI_PEN;

typedef struct HWGUI_BRUSH_STRU
{
   short int type;
   GdkColor color;
} HWGUI_BRUSH, * PHWGUI_BRUSH;

typedef struct HWGUI_FONT_STRU
{
   short int type;
   PangoFontDescription * hFont;
} HWGUI_FONT, * PHWGUI_FONT;

typedef struct HWGUI_PIXBUF_STRU
{
   short int type;
   GdkPixbuf * handle;
} HWGUI_PIXBUF, * PHWGUI_PIXBUF;

extern gchar * hwg_convert_to_utf8( const char * szText );
extern gchar * hwg_convert_from_utf8( const char * szText );
