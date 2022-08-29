//--------------------------------------------------------------------------//

#include "windows.ch"
#include "guilib.ch"

//--------------------------------------------------------------------------//

Static oWnd
Static oDlg1
Static oDlg2
Static oTB
Static oTB1
Static oTB2
Static oSay
Static oSayDlg1
Static oSayDlg2

//--------------------------------------------------------------------------//

Function Main ()

   INIT WINDOW oWnd MAIN TITLE "TrackBar Control - Demo" ;
      COLOR COLOR_3DLIGHT+1 ;
      AT 100,100 SIZE 640,480

   MENU OF oWnd
      MENUITEM "&Dialog 1" ACTION Dlg1()
      MENUITEM "&Dialog 2" ACTION Dlg2()
      MENUITEM "&Exit"     ACTION EndWindow()
   ENDMENU

   @ 20,20 TRACKBAR oTB ;
      SIZE 300,50 ;
      RANGE 0,10 ;
      INIT 5 AUTOTICKS ;
      ON CHANGE {||UpdateSay()}

   @ 300,200 BUTTON "Get Value" ON CLICK {||MsgInfo(str(oTB:GetValue()))} SIZE 100,40
   @ 300,300 BUTTON "Set Value" ON CLICK {||oTB:SetValue(5),UpdateSay()} SIZE 100,40

   @ 100,100 SAY oSay CAPTION "5" SIZE 40,40

   ACTIVATE WINDOW oWnd

   Return Nil

//--------------------------------------------------------------------------//

Function UpdateSay ()

   oSay:SetValue( str( oTB:GetValue() ) )

   Return Nil

//--------------------------------------------------------------------------//

Function Dlg1 ()

   INIT DIALOG oDlg1 TITLE "Dialog 1" ;
      AT 20,20 SIZE 500,300

   @ 20,20 TRACKBAR oTB1 ;
      SIZE 400,50 ;
      RANGE 0,100 ;
      INIT 25 ;
      ON INIT {||MsgInfo("On Init","TrackBar")} ;
      ON CHANGE {||UpdateSayDlg1()} AUTOTICKS TOOLTIP "trackbar control"

   @ 300,100 BUTTON "Get Value" ON CLICK {||MsgInfo(str(oTB1:GetValue()))} SIZE 100,40
   @ 300,200 BUTTON "Set Value" ON CLICK {||oTB1:SetValue(25),UpdateSayDlg1()} SIZE 100,40

   @ 100,100 SAY oSayDlg1 CAPTION "25" SIZE 40,40

   ACTIVATE DIALOG oDlg1

   Return Nil

//--------------------------------------------------------------------------//

Function UpdateSayDlg1 ()

   oSayDlg1:SetValue( str( oTB1:GetValue() ) )

   Return Nil

//--------------------------------------------------------------------------//

Function Dlg2 ()

   INIT DIALOG oDlg2 TITLE "Dialog 2" ;
      AT 20,20 SIZE 500,300

   @ 20,20 TRACKBAR oTB2 ;
      OF oDlg2 ;
      SIZE 100,200 ;
      RANGE 0,50 ;
      INIT 50 ;
      VERTICAL AUTOTICKS TOOLTIP "trackbar control" ;
      ON CHANGE {||UpdateSayDlg2()}

   @ 300,060 BUTTON "Get Value" ON CLICK {||MsgInfo(str(oTB2:GetValue()))} SIZE 100,40
   @ 300,100 BUTTON "Set Value" ON CLICK {||oTB2:SetValue(50),UpdateSayDlg2()} SIZE 100,40

   @ 200,100 SAY oSayDlg2 CAPTION "50" SIZE 40,40

   ACTIVATE DIALOG oDlg2

   Return Nil

//--------------------------------------------------------------------------//

Function UpdateSayDlg2 ()

   oSayDlg2:SetValue( str( oTB2:GetValue() ) )

   Return Nil

//--------------------------------------------------------------------------//

