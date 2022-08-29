/*
 * $Id: hmonthc.prg 1615 2011-02-18 13:53:35Z mlacecilia $
 *
 * HWGUI - Harbour Win32 GUI library source code:
 * HMonthCalendar class
 *
 * Copyright 2008 Luiz Rafael Culik (luiz at xharbour.com.br
 * www - http://www.xharbour.org
*/

//--------------------------------------------------------------------------//


#include "hbclass.ch"
#include "guilib.ch"

#define MCS_DAYSTATE             1
#define MCS_MULTISELECT          2
#define MCS_WEEKNUMBERS          4
#define MCS_NOTODAYCIRCLE        8
#define MCS_NOTODAY             16

//--------------------------------------------------------------------------//

CLASS HMonthCalendar INHERIT HControl

   CLASS VAR winclass   INIT "SysMonthCal32"

   DATA value
   DATA bChange

   METHOD New( oWndParent, nId, vari, nStyle, nLeft, nTop, nWidth, nHeight, ;
               oFont, bInit, bChange, cTooltip, lNoToday, lNoTodayCircle, ;
               lWeekNumbers )
   METHOD Activate()
   METHOD Init()
   METHOD SetValue( dValue )
   METHOD GetValue()

ENDCLASS

//--------------------------------------------------------------------------//

METHOD New( oWndParent, nId, vari, nStyle, nLeft, nTop, nWidth, nHeight, ;
            oFont, bInit, bChange, cTooltip, lNoToday, lNoTodayCircle, ;
            lWeekNumbers ) CLASS HMonthCalendar

//   nStyle := Hwg_BitOr( Iif( nStyle==Nil, 0, nStyle ), WS_TABSTOP )
//   nStyle   += Iif( lNoToday==Nil.OR.!lNoToday, 0, MCS_NOTODAY )
//   nStyle   += Iif( lNoTodayCircle==Nil.OR.!lNoTodayCircle, 0, MCS_NOTODAYCIRCLE )
//   nStyle   += Iif( lWeekNumbers==Nil.OR.!lWeekNumbers, 0, MCS_WEEKNUMBERS )
   Super:New( oWndParent,nId,nStyle,nLeft,nTop,nWidth,nHeight,oFont,bInit, ;
                  ,,ctooltip )

   ::value   := Iif( Valtype(vari)=="D" .And. !Empty(vari), vari, Date() )

   ::bChange := bChange

//   If bChange != Nil 
//      ::oParent:AddEvent( MCN_SELECT, ::id, bChange, .T. ) 
//      ::oParent:AddEvent( MCN_SELCHANGE, ::id, bChange, .T. ) 
//   EndIf 

   ::Activate()
Return Self

//--------------------------------------------------------------------------//

METHOD Activate CLASS HMonthCalendar

   If !empty(::oParent:handle )
      ::handle := InitMonthCalendar ( ::oParent:handle, , ;
                  ::nLeft, ::nTop, ::nWidth, ::nHeight )
      SetWindowObject( ::handle,Self )		  
//      MonthCalendarChange(::handle,{||
        MONTHCALENDAR_SETACTION(::handle,{||::value:=GetMonthCalendarDate( ::handle )})
      ::Init()
   EndIf

Return Nil

//--------------------------------------------------------------------------//

METHOD Init() CLASS HMonthCalendar

   If !::lInit
      Super:Init()
      If !Empty( ::value )
         SetMonthCalendarDate( ::handle , ::value )
      EndIf
   EndIf

Return Nil

//--------------------------------------------------------------------------//

METHOD SetValue( dValue ) CLASS HMonthCalendar

   If Valtype(dValue)=="D" .And. !Empty(dValue)
      SetMonthCalendarDate( ::handle, dValue )
      ::value := dValue
   EndIf

Return Nil

//--------------------------------------------------------------------------//

METHOD GetValue() CLASS HMonthCalendar

//   ::value := 

Return (::value)
