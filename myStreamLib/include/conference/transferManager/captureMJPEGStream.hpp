#ifndef VIDEO_CAPTURE_MJPEG_STREAM_HPP
#define VIDEO_CAPTURE_MJPEG_STREAM_HPP
#include <baseStream/baseStream.hpp>
#include <conference/constant.hpp>
#include <conference/parameterManager/parameterManager.hpp>
#include <conference/parameterManager/parameterManagerCAPI.h>

class videoCaptureMJPEGStream: public baseStream
{
private:
	

	//gint internalRelayPort;

	int Set_V4L2Src_Params(paraV4L2 *ptr);
	int Set_MJPEGEnc_Params
		(GstElement* enc , paraMJPEG *ptr);
	int Set_UDPSink_Params
		(paraUDPSink *ptr);
	int FindVideoCaptureDevice();
	
public:
	videoCaptureMJPEGStream();
	~videoCaptureMJPEGStream();
	int Create();
};
#endif
