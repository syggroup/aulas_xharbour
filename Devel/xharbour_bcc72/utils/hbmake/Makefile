#
# $Id: Makefile 9858 2012-12-06 01:40:02Z druzus $
#

ifeq ($(HB_MAIN),)
    HB_MAIN = std
endif

ROOT = ../../

PRG_SOURCES=\
    hbmake.prg \
    tmake.prg \
    hbmutils.prg \
    fclass1.prg \
    ffile1.prg \
    ft_funcs.prg \
    radios.prg \
    checks.prg  \
    pickarry.prg \
    pickfile.prg \
    prb_stak.prg \

C_SOURCES=\
   hbmlang.c        \


PRG_MAIN=hbmake.prg

LIBS=\
	debug \
	vm \
	rtl \
	rdd \
	rtl \
	vm \
	macro \
	pp \
	lang \
	common \
	rtl \

ifeq ($(HB_ARCHITECTURE)/$(HB_COMPILER),w32/mingw32)
LIBS += mainstd
endif

include $(TOP)$(ROOT)config/bin.cf

