/*
 * Copyright (c) 2013 Lailton Fernando Mariano <suporte@lailton.com.br>
 */

#ifndef __RIBBON_CH
#define __RIBBON_CH
#ifdef __XHARBOUR__
 #define RIBBONEXDESCRIPTION "RibbonEx for xHarbour"
#else
 #define RIBBONEXDESCRIPTION  "RibbonEx for Harbour"
 #include "hbcompat.ch"
#endif
#define RIBBONEXVERSION                                                "3.2.9.12"
#define TRUE                                                                   .t.
#define FALSE                                                                  .f.
#define AND                                                                  .and.
#define OR                                                                    .or.
#define NOT                                                                  .not.
#define DT_TOP                                                                   0
#define DT_LEFT                                                                  0
#define DT_CENTER                                                                1
#define DT_RIGHT                                                                 2
#define DT_VCENTER                                                               4
#define DT_BOTTOM                                                                8
#define DT_WORDBREAK                                                            16
#define DT_SINGLELINE                                                           32
#define DT_EXPANDTABS                                                           64
#define DT_TABSTOP                                                             128
#define DT_NOCLIP                                                              256
#define DT_EXTERNALLEADING                                                     512
#define DT_CALCRECT                                                           1024
#define DT_NOPREFIX                                                           2048
#define DT_INTERNAL                                                           4096
#define WM_MOUSELEAVE                                                        0x2A3
#define WM_NCMOUSEMOVE                                                         160
#define TME_LEAVE                                                              0x2
#define WS_EX_TRANSPARENT                                                     0x20
#define GWL_EXSTYLE                                                            -20
#define WM_TIMER                                                               275
#xcommand ENDSWITCH                                                         => END
                                                                      
#define RB_BLUE                                                                  1
#define RB_BLACK                                                                 2
#define RB_SILVER                                                                3
#define RB_WORD                                                                  4
#define RB_PUBLISHER                                                             5
#define RB_POWERPOINT                                                            6
#define RB_OUTLOOK                                                               7
#define RB_ONENOTE                                                               8
#define RB_EXCEL                                                                 9
#define RB_ACCESS                                                               10

#xcommand ribbon [<obj>][of<wnd>][theme<theme>]                                 =>;
 [<obj>:=]ribbon():new(<wnd>,<theme>)
 
#xcommand inserttab [<tab>][title<title>][of<obj>][<sel:selected>]              =>;
 [<tab>:=]rb_inserttab(<obj>,<title>,<.sel.>)
   
#xcommand insertgroup [<group>][title<title>][of<obj>];
                      [width<width>][action<action,...>]                        =>;
 [<group>:=]rb_insertgroup(<obj>,<title>,<width>,[{|self|<action>}])

#xcommand ribbon system [<obj>][title<title>][bitmap<bitmap>][action<action,...>] ;
                     [of<of>][<alpha:alpha>][when<when>][<l2007:2007>]          =>;
 [<obj>:=]rb_button(<of>,<title>,<bitmap>,[{|self|<action>}],<.l2007.>,<.alpha.>,[<{when}>])
   

   #xcommand INSERTQUICKBUTTON <oObj> [TITLE<cTitle>][BITMAP<cBitmap>][ACTION<bAction,...>][OF<oOF>];
                             [<isAlpha:ALPHA>]                                 ;
                             [WHEN <WhenFunc>]                               =>;
   [<oObj>]:=<oOF>:oQuickAccess:AddButton(<cTitle>,<cBitmap>,[{|self|<bAction>}],<.isAlpha.>,[<{WhenFunc}>])
   
   


   #xcommand INSERTBUTTON <oObj> [TITLE <cTitle>]                                 ;
                                 [OF <oOF>]                                       ;
                                 [BITMAP <cBitmap>]                               ;
                                 [ICON <cIcon>]                                   ;
                                 [<lsep:SEPARATOR>]                               ;
                                 [WIDTH <nWidth>]                                 ;
                                 [ACTION <uAction,...>]                           ;
                                 [<isAlpha:ALPHA>]                                ;
                                 [WHEN <WhenFunc>]                              =>;
   [<oObj>]:=<oOF>:AddButton(<cTitle>,<cBitmap>,<cIcon>,[{|self|<uAction>}],<nWidth>,<.lsep.>,<.isAlpha.>,[<{WhenFunc}>])
   #xcommand INSERTBUTTON <oObj> [TITLE <cTitle>]                                 ;
                                 [OF <oOF>]                                       ;
                                 [BITMAP <cBitmap>]                               ;
                                 [ICON <cIcon>]                                   ;
                                 [<lsep:SEPARATOR>]                               ;
                                 [WIDTH <nWidth>]                                 ;
                                 [ACTION <uActionU,...>]                          ;
                                 SPLIT                                            ;
                                 [ACTION <uActionD,...>]                          ;
                                 [<isAlpha:ALPHA>]                                ;
                                 [WHEN <WhenFunc>]                              =>;
   [<oObj>]:=<oOF>:AddButtonSplit(<cTitle>,<cBitmap>,<cIcon>,[{|self|<uActionU>}],[{|self|<uActionD>}],<nWidth>,<.lsep.>,<.isAlpha.>,[<{WhenFunc}>])
   #xcommand INSERTBUTTON <oObj> [TITLE <cTitle>]                                 ;
                                 [OF <oOF>]                                       ;
                                 [BITMAP <cBitmap>]                               ;
                                 [ICON <cIcon>]                                   ;
                                 [<lsep:SEPARATOR>]                               ;
                                 [WIDTH <nWidth>]                                 ;
                                 [ACTION <uAction,...>]                           ;
                                 SMALL                                            ;
                                 [<nLine:NEXTLINE>]                               ;
                                 [<isAlpha:ALPHA>]                                ;
                                 [WHEN <WhenFunc>]                              =>;
   [<oObj>]:=<oOF>:AddButtonSmall(<cTitle>,<cBitmap>,<cIcon>,[{|self|<uAction>}],<nWidth>,<.lsep.>,<.nLine.>,<.isAlpha.>,[<{WhenFunc}>])
   #xcommand INSERTBUTTON <oObj> [ACTION <uAction,...>] [OF <oOF>]                ;
                                 [BITMAP <cBitmap>]                               ;
                                 [ICON <cIcon>]                                   ;
                                 [<lsep:SEPARATOR>]                               ;
                                 [WIDTH <nWidth>]                                 ;
                                 GROUP                                            ;
                                 [<lBegin:BEGIN,START>]                           ;
                                 [<lCenter:CENTER>]                               ;
                                 [<lEnd:END,FINISH>]                              ;
                                 [<lPopup:POPUP> [ACTION <uActionP,...>]]         ;
                                 [<nLine:NEXTLINE>]                               ;
                                 [<isAlpha:ALPHA>]                                ;
                                 [WHEN <WhenFunc>]                              =>;
   [<oObj>]:=<oOF>:AddButtonGroup(<cBitmap>,<cIcon>,<.lBegin.>,<.lCenter.>,<.lEnd.>,<.lPopup.>,<.nLine.>,[{|self|<uAction>}],[{|self|<uActionP>}],<.lsep.>,<.isAlpha.>,[<{WhenFunc}>])
//--------------------------------------------------------------------------------------------------//
   #xcommand SET MSGBAREX [ OF <oWnd> ]                                          ;
             [ TO <cMsg> ]                                                       ;
             [ <center: CENTER, CENTERED> ]                                      ;
             [ <clock: CLOCK, TIME> ]                                            ;
             [ <date: DATE> ]                                                    ;
             [ <kbd: KEYBOARD> ]                                                 ;
             [ FONT <oFont> ]                                                    ;
             [ <color: COLOR, COLORS> <nClrFore> [,<nClrBack> ] ]                ;
             [ <inset: NO INSET, NOINSET> ]                                   => ;
   <oWnd>:oMsgBar := TMsgBarEx():New( <oWnd>, <cMsg>, <.center.>, <.clock.>,     ;
         <.date.>, <.kbd.>, <nClrFore>, <nClrBack>, <oFont>, [!<.inset.>] )
   #xcommand DEFINE MSGBAREX [<oMsg>]                                            ;
             [ OF <oWnd> ]                                                       ;
             [ <prm: PROMPT, TITLE> <cMsg> ]                                     ;
             [ <center: CENTER, CENTERED> ]                                      ;
             [ <clock: CLOCK, TIME> ]                                            ;
             [ <date: DATE> ]                                                    ;
             [ <kbd: KEYBOARD> ]                                                 ;
             [ FONT <oFont> ]                                                    ;
             [ <color: COLOR, COLORS> <nClrFore> [,<nClrBack> ] ]                ;
             [ <inset: NO INSET, NOINSET> ]                                   => ;
   [<oMsg> := ] TMsgBarEx():New( <oWnd>, <cMsg>, <.center.>, <.clock.>, <.date.>,;
          <.kbd.>, <nClrFore>, <nClrBack>, <oFont>, [!<.inset.>] )
   #xcommand DEFINE MSGITEMEX [<oMsgItem>]                                       ;
             [ OF <oMsgBar> ]                                                    ;
             [ PROMPT <cMsg> ]                                                   ;
             [ SIZE <nSize> ]                                                    ;
             [ FONT <oFont> ]                                                    ;
             [ <color: COLOR, COLORS> <nClrFore> [,<nClrBack> ] ]                ;
             [ <bmp: BITMAP, BITMAPS> <cBitmap1> [, <cBitmap2> ] ]               ;
             [ ACTION <uAction> ]                                                ;
             [ TOOLTIP <cToolTip> ]                                           => ;
   [<oMsgItem>:=] TMsgItemEx():New( <oMsgBar>, <cMsg>, <nSize>, <oFont>, ;
    <nClrFore>, <nClrBack>, .t., [<{uAction}>], [<cBitmap1>], [<cBitmap2>], [<cToolTip>] )
#endif