#ifndef STREAM_TRANSFER_MANAGER_HPP
#define STREAM_TRANSFER_MANAGER_HPP
#include <baseStream/baseStream.hpp>
#include <utils/staticMutexLocker.hpp>
#include <conference/transferManager/captureMJPEGStream.hpp>
#include <conference/transferManager/transcodeMJPEGToH264Stream.hpp>
#include <conference/relayManager/transmitterVideoRelayStream.hpp>
#include <conference/transferManager/captureAudioRawStream.hpp>
#include <conference/transferManager/transcodeAudioRawToGSMStream.hpp>
#include <conference/relayManager/transmitterAudioRelayStream.hpp>
#include <conference/parameterManager/parameterManager.hpp>
#include <conference/parameterManager/parameterManagerCAPI.h>
#include <xmlConfig/xmlConfig2CPPAPI.hpp>
#include <callbackRegister/callbackRegisterCAPI.h>
#include <admissionControl/rule/ruleManagerCAPI.h>
#include <macro/macroErrorCheck.hpp>
#include <streamStarter/security_lock.h>
class streamTransferManager:public debugClass
{
private:
#ifdef STREAM_TRANSFER_MANAGER_HIGH_SECURITY_LOCK
	mutexLocker ML;	
#endif
	static streamTransferManager* instance;
	static staticMutexLocker sMutex;

	MACRO_VAR_DECL_FULL(bool, Restartable, bRestartable);
	
	videoCaptureMJPEGStream         *v_capture  ;
	videoTranscodeMJPEGToH264Stream *v_transcode;
	transmitterVideoRelayStream     *v_relay    ;

	audioCaptureRawStream              *a_capture  ;
    audioTranscodeAudioRawToGSMStream  *a_transcode;
	transmitterAudioRelayStream        *a_relay    ;

	streamTransferManager();
	~streamTransferManager();
public:
	static streamTransferManager* 
		getInstance();
	static void 
		putInstance();

	std::ostream& Dump(std::ostream& out)const; 

	friend std::ostream& operator<< 
		(std::ostream &out, streamTransferManager& rhs) 
	{
		if ( rhs.GetDebugFlagLevel4() ) 
			rhs.Dump(out);
		return out;
	}
//-----------------------------------------------------
// video capture
	int CreateVideoCaptureStream();
	int StartVideoCaptureStream();
	int RestartVideoCaptureStream();
	int StopVideoCaptureStream();
// video transcode 
	int CreateVideoTranscodeStream();
	int StartVideoTranscodeStream();
	int RestartVideoTranscodeStream();
	int StopVideoTranscodeStream();
// video relay
	int CreateVideoRelayStream();
	int StartVideoRelayStream();
	int RestartVideoRelayStream();
	int StopVideoRelayStream();
//-----------------------------------------------------
// audio capture
	int CreateAudioCaptureStream();
	int StartAudioCaptureStream();
	int RestartAudioCaptureStream();
	int StopAudioCaptureStream();
// audio transcode 
	int CreateAudioTranscodeStream();
	int StartAudioTranscodeStream();
	int RestartAudioTranscodeStream();
	int StopAudioTranscodeStream();
// audio relay
	int CreateAudioRelayStream();
	int StartAudioRelayStream();
	int RestartAudioRelayStream();
	int StopAudioRelayStream();
//-----------------------------------------------------
	int CreateAllStream();
	int StartAllStream();
	int RestartAllStream();
	int StopAllStream();
//-----------------------------------------------------
};
#endif
