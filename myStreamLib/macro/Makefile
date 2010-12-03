DEP_PACKAGE=gstreamer-0.10 \
			gstreamer-interfaces-0.10 \
			glib-2.0 \
			libxml-2.0 \
			gtk+-2.0
#			libpulse \
#			libpulse-mainloop-glib 

COMPILE_FLAGS := -I../include/ -I/usr/lib/glib-2.0/include	
COMPILE_FLAGS += $(shell pkg-config --cflags $(DEP_PACKAGE))
# enable debug
COMPILE_FLAGS += -g -E
LINK_FLAGS := $(shell pkg-config --libs $(DEP_PACKAGE))
LINK_FLAGS += -lstdc++

EXTERNAL_CPP :=
EXTERNAL_CPP += *.cpp

GCC := @gcc
RM  := @rm
ECHO := @echo
all:
	$(ECHO) generate test file
	$(GCC) $(COMPILE_FLAGS) $(LINK_FLAGS) $(EXTERNAL_CPP) -o test
clean:
	$(ECHO) remove test
	$(RM) test
