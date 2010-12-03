DEP_PACKAGE=gstreamer-0.10 \
			gstreamer-interfaces-0.10 \
			glib-2.0 \
			libxml-2.0 \
			gtk+-2.0 \
			libpulse \
			libpulse-mainloop-glib 

COMPILE_FLAGS := -I./include -I./xmlConfig -I./profile			
COMPILE_FLAGS += $(shell pkg-config --cflags $(DEP_PACKAGE))
# enable debug
COMPILE_FLAGS += -g
COMPILE_FLAGS += -lstdc++
LINK_FLAGS := $(shell pkg-config --libs $(DEP_PACKAGE))

AR    := @ar
CC    := @gcc
ECHO  := @echo
RM    := @rm
MKDIR := @mkdir
RANLIB:= @ranlib
STRIP := @strip
PWD   := $(shell pwd)

STREAM_LIBRARY  := stream_library
VIDEOSTREAM_LIB := videostream.a

MODULES_POOL := 
MODULES_OBJS :=

# the object output location
OBJ_OUT  := obj_out
OUT_DIRS := $(PWD)/objs

# for debug usage 
TRUE	 := true
FALSE    := false
ifdef verbose
ECHO_VERBOSE := $(TRUE)
else
ECHO_VERBOSE := $(FALSE)
endif
ifdef stream_lib
MAKE_STREAM_LIBRARY := $(TRUE)
else
MAKE_STREAM_LIBRARY := $(FALSE)
endif
