#ifndef AUDIO_CAPTURE_RAW_STREAM_HPP
#define AUDIO_CAPTURE_RAW_STREAM_HPP
#include <baseStream/baseStream.hpp>
#include <conference/constant.hpp>
#include <conference/parameterManager/parameterManager.hpp>
#include <conference/parameterManager/parameterManagerCAPI.h>
class audioCaptureRawStream: public baseStream
{
private:
	int Set_PulseSrc_Params( paraPulseSrc *ptr );
	int Set_AudioConvert_Params
		(GstElement *e, paraAudioConvert *ptr );
	int Set_AudioResample_Params
		(GstElement *e, paraAudioResample *ptr );
	int Set_UDPSink_Params( paraUDPSink *ptr );
public:
	audioCaptureRawStream();
	~audioCaptureRawStream();
	int Create();
};
#endif
