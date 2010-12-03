DEP_PACKAGE=glib-2.0 \
			libxml-2.0 \
			gtk+-2.0
#			libpulse \
#			gstreamer-0.10 \
#			gstreamer-interfaces-0.10 \
#			libpulse-mainloop-glib 

COMPILE_FLAGS := -I../../include/ -I/usr/lib/glib-2.0/include	
COMPILE_FLAGS += $(shell pkg-config --cflags $(DEP_PACKAGE))
# enable debug
COMPILE_FLAGS += -g
COMPILE_FLAGS += -DSLS_INIT_XCFG2
COMPILE_FLAGS += -DSLS_INIT_CALLBACK
COMPILE_FLAGS += -DSLS_INIT_RULE_MGR
LINK_FLAGS := $(shell pkg-config --libs $(DEP_PACKAGE))
LINK_FLAGS += -lstdc++

EXTERNAL_CPP :=
EXTERNAL_CPP += ../../callbackImpl/*.cpp       
EXTERNAL_CPP += ../../callbackRegister/*.cpp       
EXTERNAL_CPP += ../../admissionControl/rule/*.cpp       
EXTERNAL_CPP += ../../hash/*.cpp       
EXTERNAL_CPP += ../../hash/hashEntry/*.cpp       
EXTERNAL_CPP += ../../hash_func/*.cpp       
EXTERNAL_CPP += ../../hash_func/hashFuncEntry/*.cpp       
EXTERNAL_CPP += ../../utils/mutexLocker/*.cpp       
EXTERNAL_CPP += ../../utils/staticMutexLocker/*.cpp
EXTERNAL_CPP += ../../utils/debugClass/*.cpp
EXTERNAL_CPP += ../../utils/thread/threadWorker/*.cpp
EXTERNAL_CPP += ../../utils/gio/*.cpp
EXTERNAL_CPP += ../../peerInfo/peer/*.cpp
EXTERNAL_CPP += ../../peerInfo/peerInfo.cpp
EXTERNAL_CPP += ../../peerInfo/peerVector/*.cpp
#EXTERNAL_CPP += ../../baseStream/*.cpp
EXTERNAL_CPP += ../../streamStarter/*.c
#video stream
#EXTERNAL_CPP += ../captureMJPEGStream/*.cpp  
#EXTERNAL_CPP += ../transcodeMJPEGToH264Stream/*.cpp  
#audio stream
#EXTERNAL_CPP += ../captureAudioRawStream/*.cpp  
#EXTERNAL_CPP += ../transcodeAudioRawToGSMStream/*.cpp  
# reception Stream Information Manager
# EXTERNAL_CPP += ../../receptionStreamInfoManager/*.cpp
# reception h264 stream
#EXTERNAL_CPP += ../../receptionManager/receptionH264Stream/*.cpp
# reception GSM stream
#EXTERNAL_CPP += ../../receptionManager/receptionGSMStream/*.cpp
#relay stream
#EXTERNAL_CPP += ../../relayManager/relayStream/*.cpp
#EXTERNAL_CPP += ../../relayManager/receiverRelayStream/*.cpp
#EXTERNAL_CPP += ../../relayManager/receiverRelayStream/video/*.cpp
#EXTERNAL_CPP += ../../relayManager/receiverRelayStream/audio/*.cpp
#EXTERNAL_CPP += ../../relayManager/transmitterRelayStream/video/*.cpp
#EXTERNAL_CPP += ../../relayManager/transmitterRelayStream/audio/*.cpp

#EXTERNAL_CPP += ../../parameterManager/*.cpp
#EXTERNAL_CPP += ../../parameterManager/paraMJPEG/*.cpp
#EXTERNAL_CPP += ../../parameterManager/paraAudioAmplify/*.cpp
#EXTERNAL_CPP += ../../parameterManager/paraAudioConvert/*.cpp
#EXTERNAL_CPP += ../../parameterManager/paraAudioResample/*.cpp
#EXTERNAL_CPP += ../../parameterManager/paraGSTRtpJitterBuffer/*.cpp
#EXTERNAL_CPP += ../../parameterManager/paraPulseSrc/*.cpp
#EXTERNAL_CPP += ../../parameterManager/paraV4L2/*.cpp
#EXTERNAL_CPP += ../../parameterManager/paraVideoRate/*.cpp
#EXTERNAL_CPP += ../../parameterManager/paraVideoScale/*.cpp
#EXTERNAL_CPP += ../../parameterManager/paraMultiUDPSink/*.cpp
#EXTERNAL_CPP += ../../parameterManager/paraUDPSink/*.cpp
#EXTERNAL_CPP += ../../parameterManager/paraX264Enc/*.cpp
#EXTERNAL_CPP += ../../parameterManager/GSTCaps/*.cpp
#EXTERNAL_CPP += ../../parameterManager/paraUDPSrc/*.cpp
#EXTERNAL_CPP += ../../parameterManager/paraXVImageSink/*.cpp
#EXTERNAL_CPP += ../../parameterManager/paraPulseSink/*.cpp

EXTERNAL_CPP += ../../xmlConfig/parser2/*.cpp
EXTERNAL_CPP += ../../xmlConfig/parser2/elements/*.cpp
EXTERNAL_CPP += ../../xmlConfig/parser2/attributes/*.cpp
EXTERNAL_CPP += ../../xmlConfig/parser2/profiles/*.cpp
EXTERNAL_CPP += test.cpp

GCC := @gcc
RM  := @rm
ECHO := @echo
all:
	$(ECHO) generate test file
	$(GCC) $(COMPILE_FLAGS) $(LINK_FLAGS) $(EXTERNAL_CPP) -o test
clean:
	$(ECHO) remove test
	$(RM) test
