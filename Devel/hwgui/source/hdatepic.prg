/*
 * $Id: hdatepic.prg 1889 2012-09-09 22:28:07Z lfbasso $
 *
 * HWGUI - Harbour Win32 GUI library source code:
 * HDatePicker class
 *
 * Copyright 2002 Alexander S.Kresin <alex@belacy.belgorod.su>
 * www - http://kresin.belgorod.su
*/

#include "windows.ch"
#include "hbclass.ch"
#include "guilib.ch"

#define DTN_DATETIMECHANGE    - 759
#define DTN_CLOSEUP           - 753
#define DTM_GETMONTHCAL        4104   // 0x1008
#define DTM_CLOSEMONTHCAL      4109 
#define NM_KILLFOCUS          - 8
#define NM_SETFOCUS           - 7

CLASS HDatePicker INHERIT HControl

CLASS VAR winclass   INIT "SYSDATETIMEPICK32"
   DATA bSetGet
   DATA dValue, tValue
   DATA bChange
   DATA lnoValid       INIT .F.
   DATA lShowTime      INIT .T.
   DATA lNAOTraduz     INIT .F.        // N�o Traduzir  ?

   METHOD New( oWndParent, nId, vari, bSetGet, nStyle, nLeft, nTop, nWidth, nHeight, ;
               oFont, bInit, bGfocus, bLfocus, bChange, ctooltip, tcolor, bcolor, lShowTime, lNAOTraduz )
   METHOD Activate()
   METHOD Init()
   METHOD OnEvent( msg, wParam, lParam )
   METHOD Refresh()
   METHOD GetValue()
   METHOD SetValue( xValue )
   METHOD SetText( xValue ) INLINE ( ::SetValue( xValue ) )
   METHOD Redefine( oWndParent, nId, vari, bSetGet, oFont, bSize, bInit, ;
                    bGfocus, bLfocus, bChange, ctooltip, tcolor, bcolor, lShowTime )
   METHOD onChange( nMess )
   METHOD When( )
   METHOD Valid( )
   METHOD Value ( Value ) SETGET
   METHOD VarGet()      INLINE ::GetValue()
   METHOD GetText()     INLINE ::GetValue()

ENDCLASS

METHOD New( oWndParent, nId, vari, bSetGet, nStyle, nLeft, nTop, nWidth, nHeight, ;
            oFont, bInit, bGfocus, bLfocus, bChange, ctooltip, tcolor, bcolor, lShowTime, lNAOTraduz ) CLASS HDatePicker

   nStyle := Hwg_BitOr( Iif( nStyle==Nil,0,nStyle ), IIF( bSetGet != Nil,WS_TABSTOP , 0 ) + ;
                        IIF( lShowTime == Nil.OR. ! lShowTime, 0, DTS_TIMEFORMAT ) )

   ::lNAOTraduz     := IIf( lNAOTraduz  == Nil, .F., lNAOTraduz  )

   // DATEPICKER - Ana Brock - Projeto TRADUZIR - 20/03/2018
   IF ::lNAOTraduz
      ctooltip  := ctooltip
   Else
      If Valtype( vari ) = "C"
         vari      := HWG_TRANSLATOR( vari , 'DATEPICKER' )
      Endif
      ctooltip  := HWG_TRANSLATOR( ctooltip, 'DATEPICKER / TOOLTIP' )
   Endif

   Super:New( oWndParent, nId, nStyle, nLeft, nTop, nWidth, nHeight, oFont, bInit, ;
              ,, ctooltip, tcolor, bcolor )

   ::lShowTime := Hwg_BitAnd( nStyle, DTS_TIMEFORMAT ) > 0
   ::dValue    := IIF( vari == Nil .OR. ValType( vari ) != "D", CToD( Space( 8 ) ), vari )
   ::tValue    := IIF( vari == Nil .OR. Valtype( vari ) != "C", SPACE(6), vari )
   ::title     := IIF( ! ::lShowTime, ::dValue, ::tValue )

   ::bSetGet := bSetGet
   ::bChange := bChange

   HWG_InitCommonControlsEx()
   ::Activate()

   IF bSetGet != Nil
      ::bGetFocus := bGfocus
      ::bLostFocus := bLfocus
      ::oParent:AddEvent( NM_SETFOCUS , Self, { | o, id | ::When( o:FindControl( id ) )  }, .T., "onGotFocus" )
      ::oParent:AddEvent( NM_KILLFOCUS, Self, { | o, id | ::Valid( o:FindControl( id ) ) }, .T., "onLostFocus" )
   ELSE
      IF bGfocus != Nil
         ::lnoValid := .T.
         ::oParent:AddEvent( NM_SETFOCUS, Self, bGfocus, .T., "onGotFocus" )
      ENDIF
      IF bLfocus != Nil
         ::oParent:AddEvent( NM_KILLFOCUS, Self, bLfocus, .T., "onLostFocus" )
      ENDIF
   ENDIF
   ::oParent:AddEvent( DTN_DATETIMECHANGE, Self, { | | ::onChange( DTN_DATETIMECHANGE ) }, .T., "onChange" )
   ::oParent:AddEvent( DTN_CLOSEUP, Self, { | | ::onChange( DTN_CLOSEUP ) }, .T., "onClose" )

   RETURN Self

METHOD Redefine( oWndParent, nId, vari, bSetGet, oFont, bSize, bInit, ;
                 bGfocus, bLfocus, bChange, ctooltip, tcolor, bcolor, lShowTime ) CLASS  HDatePicker
   Super:New( oWndParent, nId, 0, 0, 0, 0, 0, oFont, bInit, ;
              bSize,, ctooltip, tcolor, bcolor )
              
   HWG_InitCommonControlsEx()
   ::dValue   := IIf( vari == Nil .OR. ValType( vari ) != "D", CToD( Space( 8 ) ), vari )
   ::tValue    := IIF( vari == Nil .OR. Valtype( vari ) != "C", SPACE(6), vari )
   ::bSetGet := bSetGet
   ::bChange := bChange
   ::lShowTime := lShowTime
   IF bGfocus != Nil
      ::oParent:AddEvent( NM_SETFOCUS, Self, bGfocus, .T., "onGotFocus" )
   ENDIF
   ::oParent:AddEvent( DTN_DATETIMECHANGE, Self, { | | ::onChange( DTN_DATETIMECHANGE ) }, .T., "onChange" )
   ::oParent:AddEvent( DTN_CLOSEUP, Self, { | | ::onChange(  DTN_CLOSEUP ) }, .T., "onClose" )
   IF bSetGet != Nil
      ::bLostFocus := bLfocus
      ::oParent:AddEvent( NM_KILLFOCUS, Self, { | o, id | ::Valid( o:FindControl( id ) ) }, .T., "onLostFocus" )
   ELSE
      IF bLfocus != Nil
         ::oParent:AddEvent( NM_KILLFOCUS, Self, bLfocus, .T., "onLostFocus" )
      ENDIF
   ENDIF


   RETURN Self

METHOD Activate() CLASS HDatePicker
   IF ! Empty( ::oParent:handle )
      ::handle := CreateDatePicker( ::oParent:handle, ::id, ;
                                    ::nLeft, ::nTop, ::nWidth, ::nHeight, ::style )
      ::Init()
   ENDIF
   RETURN Nil

METHOD Init() CLASS HDatePicker
   IF ! ::lInit
      ::nHolder := 1
      SetWindowObject( ::handle, Self )
      HWG_INITDATEPICKERPROC( ::handle )
      Super:Init()
      IF Empty( ::dValue )
         SetDatePickerNull( ::handle )
      ELSE
         SetDatePicker( ::handle, ::dValue, ::tValue )
      ENDIF
      //HWG_SETWINDOWTHEME( ::handle, 0 ) // desabilita o tema do windows
      //::tcolor:=0
      //::bcolor:= RGB(240,255,144)
      //::SetColor( 0, RGB(240,255,144) )
      //::Refresh()
   ENDIF
   RETURN Nil

METHOD OnEvent( msg, wParam, lParam ) CLASS HDatePicker

   IF ::bOther != Nil
      IF Eval( ::bOther,Self,msg,wParam,lParam ) != -1
         RETURN 0
      ENDIF
   ENDIF
   IF msg == WM_CHAR
      IF wParam = VK_TAB
        GetSkip( ::oParent, ::handle, , iif( IsCtrlShift(.f., .t.), -1, 1) )
        RETURN 0
      ELSEIF wParam == VK_RETURN
         GetSkip( ::oParent, ::handle, , 1 )
         RETURN 0
		  ENDIF
	 ELSEIF msg = WM_KEYDOWN
		  IF  ProcKeyList( Self, wParam )
		     RETURN 0
		  ENDIF
   ELSEIF  msg = WM_GETDLGCODE
      IF wParam = VK_TAB //.AND.  ::GetParentForm( Self ):Type < WND_DLG_RESOURCE
        // GetSkip( ::oParent, ::handle, , iif( IsCtrlShift(.f., .t.), -1, 1) )
         RETURN DLGC_WANTTAB
      ENDIF
	 ENDIF
  IF msg == WM_SETFOCUS
     POSTMESSAGE( ::handle, WM_KEYDOWN, VK_LEFT, 0 )
     POSTMESSAGE( ::handle, WM_KEYDOWN, VK_RIGHT, 0 )
  ENDIF
RETURN -1

METHOD Value( Value )  CLASS HDatePicker

   IF Value != Nil
      ::SetValue( ::dValue, Value  )
   ENDIF
   RETURN IIF( ::lShowTime, ::tValue, ::dValue )

METHOD GetValue() CLASS HDatePicker
   RETURN IIF( ! ::lShowTime, GetDatePicker( ::handle ), GetTimePicker( ::handle ) )

METHOD SetValue( xValue ) CLASS HDatePicker
//showmsg({'1',xValue,::dValue,::lShowTime})   
   IF Empty( xValue )
      SetDatePickerNull( ::handle )
   ELSEIF ::lShowTime
      SetDatePicker( ::handle, Date(), STRTRAN( xValue, ":", "" ) )
   ELSE
      SetDatePicker( ::handle, xValue, STRTRAN( ::tValue, ":", "" ) )
   ENDIF
   ::dValue := GetDatePicker( ::handle )
   ::tValue := GetTimePicker( ::handle )
   ::title := IIF( ::lShowTime, ::tValue, ::dValue )
   IF ::bSetGet != Nil
      Eval( ::bSetGet, IIF( ::lShowTime, ::tValue,::dValue ), Self )
   ENDIF
   RETURN Nil

METHOD Refresh() CLASS HDatePicker

   IF ::bSetGet != Nil
      IF ! ::lShowTime
         ::dValue := Eval( ::bSetGet,, Self )
      ELSE
         ::tValue := Eval( ::bSetGet,, Self )
      ENDIF
   ENDIF
   IF Empty( ::dValue ) .AND. ! ::lShowTime
      //SetDatePickerNull( ::handle )
      SetDatePicker( ::handle, date(), STRTRAN( Time(), ":", "" ) )
   ELSE
      ::SetValue( IIF( ! ::lShowTime, ::dValue, ::tValue ) )
   ENDIF
   RETURN Nil


METHOD onChange( nMess ) CLASS HDatePicker

   IF ( nMess == DTN_DATETIMECHANGE .AND. ;
        SendMessage( ::handle, DTM_GETMONTHCAL, 0, 0 ) == 0 ) .OR. ;
      nMess == DTN_CLOSEUP
      IF nMess = DTN_CLOSEUP
         POSTMESSAGE( ::handle, WM_KEYDOWN, VK_RIGHT, 0 )
         ::SetFocus()
      ENDIF
      ::dValue := GetDatePicker( ::handle )
      ::tValue := GetTimePicker( ::handle )
      IF ::bSetGet != Nil
         Eval( ::bSetGet, IIF( ::lShowTime, ::tValue, ::dValue ), Self )
      ENDIF
      IF ::bChange != Nil
         ::oparent:lSuspendMsgsHandling := .T.
         Eval( ::bChange, IIF( ::lShowTime, ::tValue, ::dValue), Self )
         ::oparent:lSuspendMsgsHandling := .F.
      ENDIF
   ENDIF
   RETURN .T.

METHOD When( ) CLASS HDatePicker
   LOCAL res := .t.,  nSkip

   IF ! CheckFocus( Self, .f. )
      RETURN .t.
   ENDIF
   IF ::bGetFocus != Nil
      nSkip := IIf( GetKeyState( VK_UP ) < 0 .or. ( GetKeyState( VK_TAB ) < 0 .and. GetKeyState( VK_SHIFT ) < 0 ), - 1, 1 )
      ::oParent:lSuspendMsgsHandling := .T.
      ::lnoValid := .T.
      res :=  Eval( ::bGetFocus, IIF( ::lShowTime, ::tValue, ::dValue ), Self )
      IF VALTYPE(res) = "L"
         ::lnoValid := ! res
      ELSE
         ::lnoValid := .F.
      ENDIF
      ::oParent:lSuspendMsgsHandling := .F.
      IF VALTYPE(res) = "L" .AND. ! res
         WhenSetFocus( Self, nSkip )
         SendMessage( ::handle, DTM_CLOSEMONTHCAL, 0, 0 )
      ELSE
         ::SetFocus()
      ENDIF
   ENDIF

   RETURN res

METHOD Valid( ) CLASS HDatePicker
   LOCAL  res := .t.

   /*
   IF ! SELFFOCUS( GetParent( GetFocus() ) , ::GetParentForm():Handle )
      RETURN .T.
   ENDIF
   */
   IF ! CheckFocus( Self, .T. ) .OR. ::lnoValid
      RETURN .T.
   ENDIF
   ::dValue := GetDatePicker( ::handle )
   IF ::bSetGet != Nil
      Eval( ::bSetGet, IIF( ::lShowTime, ::tValue,::dValue ), Self )
   ENDIF
   IF ::bLostFocus != Nil
      ::oparent:lSuspendMsgsHandling := .T.
      res := Eval( ::bLostFocus, IIF( ::lShowTime, ::tValue, ::dValue ), Self )
      res := IIF( ValType( res ) == "L", res, .T. )
      ::oparent:lSuspendMsgsHandling := .F.
      IF ! res
         POSTMESSAGE( ::handle, WM_KEYDOWN, VK_RIGHT, 0 )
         ::SetFocus( .T. )
      ENDIF
   ENDIF
   RETURN res
