#ifndef AUDIO_TRANSCODE_AUDIO_RAW_TO_GSM_STREAM_HPP
#define AUDIO_TRANSCODE_AUDIO_RAW_TO_GSM_STREAM_HPP
#include <baseStream/baseStream.hpp>
#include <conference/constant.hpp>
#include <conference/parameterManager/parameterManager.hpp>
#include <conference/parameterManager/parameterManagerCAPI.h>

class audioTranscodeAudioRawToGSMStream: public baseStream
{
private:
	int Set_UDPSrc_Params( paraUDPSrc *ptr );
	int Set_GSTRtpJitterBuffer_Params 
		( GstElement *e, paraGSTRtpJitterBuffer *ptr);
	int Set_MultiUDPSink_Params
		( paraMultiUDPSink *ptr );
public:
	audioTranscodeAudioRawToGSMStream();
	~audioTranscodeAudioRawToGSMStream();
	int Create(); // override the baseStream
};

#endif
