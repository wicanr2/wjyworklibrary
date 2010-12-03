#ifndef STREAM_PARAMETER_MANAGER_HPP
#define STREAM_PARAMETER_MANAGER_HPP
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <cstdlib>
// util 
#include <list/fastLinkedList.hpp>
#include <utils/debugClass.hpp>
#include <utils/staticMutexLocker.hpp>
#include <utils/mutexLocker.hpp>

// xml config
#include <xmlConfig/xmlConfig2.hpp>
#include <xmlConfig/xmlConfig2CPPAPI.hpp>

#include <conference/constant.hpp>
#include <conference/parameterManager/paraBase.hpp>
#include <conference/parameterManager/paraMJPEG.hpp>
#include <conference/parameterManager/paraV4L2.hpp>
#include <conference/parameterManager/paraVideoRate.hpp>
#include <conference/parameterManager/paraVideoScale.hpp>
#include <conference/parameterManager/paraUDPSink.hpp>
#include <conference/parameterManager/paraMultiUDPSink.hpp>
#include <conference/parameterManager/paraX264Enc.hpp>
#include <conference/parameterManager/paraUDPSrc.hpp>
#include <conference/parameterManager/paraAudioResample.hpp>
#include <conference/parameterManager/paraPulseSrc.hpp>
#include <conference/parameterManager/paraAudioConvert.hpp>
#include <conference/parameterManager/paraGSTRtpJitterBuffer.hpp>
#include <conference/parameterManager/paraXVImageSink.hpp>
#include <conference/parameterManager/paraPulseSink.hpp>
#include <conference/parameterManager/paraAudioAmplify.hpp>
// macro for parameter manager
#include <macro/macroParameterManagerAid.hpp>
#include <macro/macroDebugClassAid.hpp>
#include <streamStarter/security_lock.h>
class parameterManager:public debugClass {
private:	
	fastLinkedList<paraBase> *pool ;
	fastLinkedList<paraBase> *tmpPool;
	
	int InitParams();
	
	// transmitter video
	int InitTransmitterVideoCaptureStream();
	int InitTransmitterVideoTranscodeStream();
	int InitTransmitterVideoRelayStream();
	
	// transmitter audio
	int InitTransmitterAudioCaptureStream();
	int InitTransmitterAudioTranscodeStream();
	int InitTransmitterAudioRelayStream();
	
	// receiver video
	int InitReceiverVideoRelayStream();
	int InitReceiverVideoStream();
	// receiver audio
	int InitReceiverAudioRelayStream();
	int InitReceiverAudioStream();

	int HashMapping();
	// single instance
	static parameterManager* instance;
	// static mutex
	static staticMutexLocker sMutex;
	// mutex locker
#ifdef PARAMETER_MANAGER_HIGH_SECURITY_LOCK
	mutexLocker ML;
#endif
	parameterManager();
	~parameterManager();
public:
	static parameterManager* getInstance();
	static void putInstance();
	
	paraBase * Query(
		char *role,
		char *streamName, char *paraName);
	int QueryStreamParams( 
		char *role,
		char *stream );
	int GetQueryStreamParamsSize();
	paraBase *QueryStreamParamsI ( int i ) ;
	// query, return *paraBase pointer
	// refresh, read parameter from xml
	
	// state 
	
	//dump 
	void Dump();
	void EnableDebug();
	void DisableDebug();
};

#endif
