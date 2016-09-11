#
# This is an example GNUmakefile for my packages
#

# specific names for this package
DICT  = pylard_PyAnalzyerDict
SHLIB = libpylard_PyAnalzyer.so
SOURCES = $(filter-out $(DICT).cxx, $(wildcard *.cxx))
FMWK_HEADERS = LinkDef.h $(DICT).h
HEADERS = $(filter-out $(FMWK_HEADERS), $(wildcard *.h))
OBJECTS = $(SOURCES:.cxx=.o)

# include options for this package
INCFLAGS  = -I.                       #Include itself
INCFLAGS += $(shell larlite-config --includes)
INCFLAGS += $(shell larlite-config --includes)/../UserDev

# platform-specific options
OSNAME          = $(shell uname -s)
HOST            = $(shell uname -n)
OSNAMEMODE      = $(OSNAME)

# call kernel specific compiler setup
include $(LARLITE_BASEDIR)/Makefile/Makefile.${OSNAME}

# call the common GNUmakefile
LDFLAGS += $(shell larlite-config --libs)
LDFLAGS += -L$(shell root-config --libdir) -lPyROOT -lBasicTool_FhiclLite
include $(LARLITE_BASEDIR)/Makefile/GNUmakefile.CORE


