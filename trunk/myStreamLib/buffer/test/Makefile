DEP_PACKAGE=gstreamer-0.10 \
			gstreamer-interfaces-0.10 \
			glib-2.0 \
			libxml-2.0 \
			gtk+-2.0
#			libpulse \
#			libpulse-mainloop-glib 

COMPILE_FLAGS := -I../../include/			
COMPILE_FLAGS += $(shell pkg-config --cflags $(DEP_PACKAGE))
# enable debug
COMPILE_FLAGS += -g
LINK_FLAGS := $(shell pkg-config --libs $(DEP_PACKAGE))
LINK_FLAGS += -lstdc++

EXTERNAL_CPP := 
EXTERNAL_CPP += ../../utils/mutexLocker/*.cpp        
EXTERNAL_CPP += ../../utils/staticMutexLocker/*.cpp
EXTERNAL_CPP += ../../utils/debugClass/*.cpp
# EXTERNAL_CPP += ../../utils/directorySubsidiary/*.c
# EXTERNAL_CPP += ../../hash/hashEntry/*.cpp
# EXTERNAL_CPP += ../../hash/*.cpp
# EXTERNAL_CPP += ../../peerInfo/peer/*.cpp
# EXTERNAL_CPP += ../../peerInfo/peerInfo.cpp
# EXTERNAL_CPP += ../../peerInfo/peerVector/*.cpp
# EXTERNAL_CPP += ../../../baseStream/*.cpp
# EXTERNAL_CPP += ../captureMJPEGStream/*.cpp  
# EXTERNAL_CPP += ../transcodeMJPEGToH264Stream/*.cpp  
# EXTERNAL_CPP += ../videoTransferStream/*.cpp
# EXTERNAL_CPP += ../../conference/parameterManager/*.cpp
# EXTERNAL_CPP += ../../conference/parameterManager/paraMJPEG/*.cpp
# EXTERNAL_CPP += ../../conference/parameterManager/paraV4L2/*.cpp
# EXTERNAL_CPP += ../../conference/parameterManager/paraVideoRate/*.cpp
# EXTERNAL_CPP += ../../conference/parameterManager/paraVideoScale/*.cpp
# EXTERNAL_CPP += ../../conference/parameterManager/paraMultiUDPSink/*.cpp
# EXTERNAL_CPP += ../../conference/parameterManager/paraUDPSink/*.cpp
# EXTERNAL_CPP += ../../conference/parameterManager/paraX264Enc/*.cpp
# EXTERNAL_CPP += ../../conference/parameterManager/GSTCaps/*.cpp
# EXTERNAL_CPP += ../../conference/parameterManager/paraUDPSrc/*.cpp
# EXTERNAL_CPP += ../parser2/*.cpp
# EXTERNAL_CPP += ../parser2/profiles/*.cpp
# EXTERNAL_CPP += ../parser2/attributes/*.cpp
# EXTERNAL_CPP += ../parser2/elements/*.cpp
EXTERNAL_CPP += test.cpp
#EXTERNAL_CPP += test2.cpp

GCC := @gcc
RM  := @rm
ECHO := @echo
all: 
	$(ECHO) generate test file
#	$(ECHO) $(EXTERNAL_CPP)
	$(GCC) $(COMPILE_FLAGS) $(LINK_FLAGS) $(EXTERNAL_CPP) -o test
clean:
	$(ECHO) remove test
	$(RM) test
