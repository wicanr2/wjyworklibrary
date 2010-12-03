#ifndef VIDEO_TRANSCODE_MJPEG_TO_H264_STREAM_HPP
#define VIDEO_TRANSCODE_MJPEG_TO_H264_STREAM_HPP
#include <baseStream/baseStream.hpp>
#include <conference/constant.hpp>
#include <conference/parameterManager/parameterManager.hpp>
#include <conference/parameterManager/parameterManagerCAPI.h>

class videoTranscodeMJPEGToH264Stream: public baseStream
{
private:
	int Set_UDPSrc_Params
		( paraUDPSrc *ptr );
	int Set_X264Enc_Params
		( GstElement* e, paraX264Enc *ptr );
	int Set_MultiUDPSink_Params
		( paraMultiUDPSink *ptr );
	int Set_GSTRtpJitterBuffer_Params 
		( GstElement *e, paraGSTRtpJitterBuffer *ptr);
public:
	videoTranscodeMJPEGToH264Stream();
	~videoTranscodeMJPEGToH264Stream();
	int Create(); // override the baseStream
};

#endif
