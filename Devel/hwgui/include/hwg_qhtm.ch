/*
 * $Id: hwg_qhtm.ch 1615 2011-02-18 13:53:35Z mlacecilia $
*/

#ifndef __HWG_QHTM_CH__
#define __HWG_QHTM_CH__

#define QHTMN_HYPERLINK		1

#xcommand @ <x>,<y> QHTM [ <oQhtm> ]    ;
             [ CAPTION  <caption> ]      ;
             [ FILE <fname> ]            ;
             [ RESOURCE <resname> ]      ;
             [ OF <oWnd> ]               ;
             [ ID <nId> ]                ;
             [ SIZE <width>, <height> ]  ;
             [ ON INIT <bInit> ]         ;
             [ ON SIZE <bSize> ]         ;
             [ ON CLICK <bLink> ]        ;
             [ ON SUBMIT <bSubmit> ]     ;
             [ STYLE <nStyle> ]          ;
          => ;
          [<oQhtm> :=] HQhtm():New( <oWnd>,<nId>,<nStyle>,<x>,<y>,<width>,<height>, ;
             <caption>,<bInit>,<bSize>,<bLink>,<bSubmit>,<fname>,<resname> )

#xcommand REDEFINE QHTM [ <oQhtm> ]     ;
             [ CAPTION  <caption> ]      ;
             [ FILE <fname> ]            ;
             [ RESOURCE <resname> ]      ;
             [ OF <oWnd> ]               ;
             ID <nId>                    ;
             [ ON INIT <bInit> ]         ;
             [ ON SIZE <bSize> ]         ;
             [ ON CLICK <bLink> ]        ;
             [ ON SUBMIT <bSubmit> ]     ;
          => ;
          [<oQhtm> :=] HQhtm():Redefine( <oWnd>,<nId>,<caption>, ;
             <bInit>,<bSize>,<bLink>,,<bSubmit><fname>,<resname> )

#xcommand @ <x>,<y> QHTMBUTTON [ <oBut> CAPTION ] <caption> ;
             [ OF <oWnd> ]              ;
             [ ID <nId> ]               ;
             [ SIZE <width>, <height> ] ;
             [ FONT <oFont> ]           ;
             [ ON INIT <bInit> ]        ;
             [ ON SIZE <bSize> ]        ;
             [ ON CLICK <bClick> ]      ;
             [ STYLE <nStyle> ]         ;
             [ TOOLTIP <ctoolt> ]       ;
          => ;
          [<oBut> := ] HQhtmButton():New( <oWnd>,<nId>,<nStyle>,<x>,<y>,<width>, ;
             <height>,<caption>,<oFont>,<bInit>,<bSize>,<bClick>,<ctoolt> )

#xcommand REDEFINE QHTMBUTTON [ <oBut> CAPTION ] <caption> ;
             [ OF <oWnd> ]              ;
             ID <nId>                   ;
             [ FONT <oFont> ]           ;
             [ ON INIT <bInit> ]        ;
             [ ON SIZE <bSize> ]        ;
             [ ON CLICK <bClick> ]      ;
             [ TOOLTIP <ctoolt> ]       ;
          => ;
          [<oBut> := ] HQhtmButton():Redefine( <oWnd>,<nId>,<caption>,<oFont>,<bInit>,<bSize>, ;
             <bClick>,<ctoolt> )

#endif /* __HWG_QHTM_CH__ */
