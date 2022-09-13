C:\aulas_xharbour\Devel\bcc72\bin\impdef -a libeay32.def libeay32.dll
C:\aulas_xharbour\Devel\bcc72\bin\implib -a libeay32.lib libeay32.def

C:\aulas_xharbour\Devel\bcc72\bin\impdef -a ssleay32.def ssleay32.dll
C:\aulas_xharbour\Devel\bcc72\bin\implib -a ssleay32.lib ssleay32.def

del libeay32.def
del ssleay32.def