/*
 * HWinPrn using sample
 * 
 *
 * Copyright 2005 Alexander S.Kresin <alex@belacy.belgorod.su>
 * www - http://kresin.belgorod.su
*/

#include "hwgui.ch"

/*
REQUEST HB_CODEPAGE_RU866
#ifdef __LINUX__
REQUEST HB_CODEPAGE_RUKOI8
#else
REQUEST HB_CODEPAGE_RU1251
#endif
*/

Function Main
Local oWinPrn, i

#ifdef __PLATFORM__Linux__
   oWinPrn := HWinPrn():New( ,"RU866","RUKOI8" )
   oWinPrn:StartDoc( .T.,"/apps/a2.ps" )
#else
   oWinPrn := HWinPrn():New( ,"RU866","RU1251" )
   oWinPrn:StartDoc( .T. )
#endif

   oWinPrn:PrintLine( oWinPrn:oFont:name + " " + Str(oWinPrn:oFont:height) + " " + Str(oWinPrn:nCharW) + " " + Str(oWinPrn:nLineHeight) )
   oWinPrn:PrintLine( "A123456789012345678901234567890123456789012345678901234567890123456789012345678Z" )
/*
   oWinPrn:PrintLine( "��������������������������������" )
   oWinPrn:PrintLine( "��������������������������������" )
*/
   oWinPrn:PrintLine( "abcdefghijklmnopqrstuvwxyz" )
   oWinPrn:PrintLine( "ABCDEFGHIJKLMNOPQRSTUVWXYZ" )
   oWinPrn:PrintLine( "�������������������������Ŀ" )
   oWinPrn:PrintLine( "�   129.54�           0.00�" )
   oWinPrn:PrintLine( "�������������������������Ĵ" )
   oWinPrn:PrintLine( "�    17.88�      961014.21�" )
   oWinPrn:PrintLine( "���������������������������" )
   oWinPrn:PrintLine()
   oWinPrn:PrintLine( "�������������������������Ŀ" )
   oWinPrn:PrintLine( "���������������������������" )

   oWinPrn:PrintLine()
   oWinPrn:PrintLine()

   oWinPrn:SetMode( .T. )
   oWinPrn:PrintLine( "A12345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678Z" )
   oWinPrn:PrintLine( "A123456789012345678901234567890123456789012345678901234567890123456789012345678Z" )
   oWinPrn:PrintLine()
   oWinPrn:PrintLine()

   oWinPrn:SetMode( .F.,.T. )
   oWinPrn:PrintLine( "A12345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678Z" )
   oWinPrn:PrintLine( "A123456789012345678901234567890123456789012345678901234567890123456789012345678Z" )
   oWinPrn:PrintLine()
   oWinPrn:PrintLine()

   oWinPrn:SetMode( .T.,.T. )
   oWinPrn:PrintLine( "A12345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678Z" )
   oWinPrn:PrintLine( "A123456789012345678901234567890123456789012345678901234567890123456789012345678Z" )

   oWinPrn:SetMode( .F.,.F. )
   oWinPrn:NextPage()
   oWinPrn:PrintLine( oWinPrn:oFont:name + " " + Str(oWinPrn:oFont:height) + " " + Str(oWinPrn:nCharW) + " " + Str(oWinPrn:nLineHeight) )
   FOR i := 1 TO 80
      oWinPrn:PrintLine( Padl( i,3 ) + " --------" )
   NEXT

   oWinPrn:End()

Return Nil
