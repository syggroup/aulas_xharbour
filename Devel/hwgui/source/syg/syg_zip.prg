
/*
Funções genéricas Hwgui
*/

#include "hwgui.ch"

#include 'dbstruct.ch'
#include 'directry.ch'
#include 'error.ch'
#include 'inkey.ch'
#include 'fileio.ch'
#include 'dbinfo.ch'
#include 'hbclass.ch'
#include 'ord.ch'
#include "DbInfo.ch"

#define MZIP_BUFFER_READ 1024

/*
   SYG_ZIPFILE( <cFile>,
               <cFileToCompress> | <aFilesToCompress>,
               [<nLevel>],
               [<bUpdate>],
               [<lOverWrite>],
               [<cPassword>],
               [<lWithPath>],
               [<lWithDrive>],
               [<bFileUpdate>] ) --> lCompress

   This function creates a zip file named <cFile>. If the extension
   is omitted, .ZIP will be assumed. If the second parameter is a
   character string, this file will be added to the zip file. If the
   second parameter is an array, all file names contained in <aFiles>
   will be compressed.

   If <nLevel> is used, it determines the compression type where 0
means
   no compression and 9 means best compression.

   If <bUpdate> is used, every time the file is opened to compress it
   will evaluate bBlock. Parameters of bBlock are cFile and nPos.

   If <lOverWrite> is used, it toggles to overwrite or not the
existing
   file. Default is to overwrite the file,otherwise if <lOverWrite> is
false
   the new files are added to the <cFile>.

   If <cPassword> is used, all files that are added to the archive are
encrypted
   with the password.

   If <lWithPath> is used, it tells  the path should also be stored
with
   the file name. Default is false.

   If <lWithDrive> is used, it tells thats the Drive and path should
also be stored
   with the file name. Default is false.

   If <bFileUpdate> is used, an Code block is evaluated, showing the
total
   of that file has being processed.
   The codeblock must be defined as follow {|nPos,nTotal|
GaugeUpdate(aGauge1,(nPos/nTotal))}

   lWithPath and lWithDrive are not supported yet
*/

procedure SYG_ZipFile( cFile, uFileToCompress, nLevel, bUpdate,lOverwrite, cPassword, lWithPath, lWithDrive, bFileUpdate, cComment )

   local hZip, hHandle, nLen, cBuffer := Space( MZIP_BUFFER_READ ),cFileToZip, nPos := 1, nRead, cExt

   if !( ".zip" $ cFile )
      cFile += ".zip"
   endif

   hZip = HB_ZipOpen( cFile )

   if !Empty( hZip )

      if HB_IsString( uFileToCompress )
         uFileToCompress = { uFileToCompress }
      endif

      for each cFileToZip in uFileToCompress

         if HB_IsBlock( bUpdate )
            Eval( bUpdate, cFileToZip, nPos++ )
         endif

         hHandle = FOpen( cFileToZip )

         nRead = 0

         HB_FNameSplit( cFileToZip, nil, @cFileToZip, @cExt )

         HB_ZipFileCreate( hZip, cFileToZip + cExt, nil, nil, nil,nil, nil, nLevel, cPassword, nil, nil )

         while ( nLen := FRead( hHandle, @cBuffer, MZIP_BUFFER_READ )) > 0

            if HB_IsBlock( bFileUpdate )

               nRead += nLen

               Eval( bFileUpdate, nRead, FSize( cFileToZip ) )

            endif

            HB_ZipFileWrite( hZip, SubStr( cBuffer, 1, nLen ), nLen )

         enddo

         FClose( hHandle )

         HB_ZipFileClose( hZip )

      next

      HB_ZipClose( hZip, cComment )

   endif

return

/*
   SYG_UNZIPFILE( <cFile>,
                 [<bUpdate>],
                 [<lWithPath>],
                 [<cPassword>],
                 [<cPath>],
                 [<cFile> | <aFile>],
                 [<bFileUpdate>]  ) --> lCompress

   <cFile>     Name of the zip file to extract

   <bUpdate>   Code block to execute while extracting

   <lWithPath> Toggle to create directory if needed

   <cPassword> Password to use to extract files

   <cPath>     Path to extract the files to - mandatory

   <cFile> | <aFiles> A File or Array of files to extract - mandatory

   <bFileUpdate> Code block for File Progress

   lWithPath are not supported yet
*/

FUNCTION SYG_UnZipFile( cFile, bUpdate, lWithPath, cPassword, cPath,uFileToUnzip, bFileUpdate )

   local hUnZip, nErr, cZipName, nTentativa:=0
/*
   if !( ".zip" $ cFile )
      cFile += ".zip"
   endif
*/
   hUnZip = HB_UnZipOpen( cFile )

   if !Empty( hUnZip )

      if HB_IsString( uFileToUnzip )
         uFileToUnzip = { uFileToUnzip }
      endif

      if Empty( cPath )
         HB_FNameSplit( cFile, @cPath )
      endif

      nErr = HB_UnZipFileFirst( hUnZip )

      while nErr == 0
         nTentativa:=nTentativa+1

         if HB_UnzipFileInfo( hUnzip, @cZipName ) == 0

            if AScan( uFileToUnzip, cZipName ) > 0

               cZipName = cPath + cZipName

               HB_UnzipExtractCurrentFile( hUnZip, cZipName, cPassword )

            endif

         endif

         nErr = HB_UnZipFileNext( hUnZip )
         if nTentativa>1000
            exit
         endif
      enddo

      HB_UnZipClose( hUnZip )

   endif

return(.t.)

/*
   SYG_GETFILESINZIP( <cFile>, [<lExtended>] )

   <cFile>        Is the zip file to get information

   <lExtended>    Is the type of information. The default is .f. and
is compatible with old ZipArch method,
                  returning an array with file name only. If lExtended
is TRUE, the returned array have additional
                  informations like: { cFile, dDate, cTime, nSize,
nCompSize, lCrypted, cComment }
*/

function SYG_GetFilesInZip( cFile, lExtended )

   local hUnZip, nErr, dDate, cTime, nSize, nCompSize, lCrypted, cComment, aFiles := {}
/*
   if !( ".zip" $ cFile )
      cFile += ".zip"
   endif
*/
   if !HB_IsLogical( lExtended )
      lExtended = .f.
   endif

   hUnZip = HB_UnZipOpen( cFile )

   if !Empty( hUnZip )

      nErr = HB_UnZipFileFirst( hUnZip )

      while nErr == 0

         HB_UnzipFileInfo( hUnzip, @cFile, @dDate, @cTime, nil, nil,nil, @nSize, @nCompSize, @lCrypted, @cComment )

         if lExtended
            AAdd( aFiles, { cFile, dDate, cTime, nSize, nCompSize,lCrypted, cComment } )
         else
            AAdd( aFiles, cFile )
         endif

         nErr = HB_UnZipFileNext( hUnZip )

      enddo

      HB_UnZipClose( hUnZip )

   endif

return aFiles

function FSize( cFile ) // returns the size of filename
	     local aFiles := Directory( cFile )
	     If Len( aFiles ) > 0
	        return aFiles[ 1 ][ 2 ]
	     endif
	     return 0
