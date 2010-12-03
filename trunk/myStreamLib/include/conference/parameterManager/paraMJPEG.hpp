#ifndef PARAMETER_MJPEG_HPP
#define PARAMETER_MJPEG_HPP
#include <baseStream/baseStream.hpp>
#include <conference/parameterManager/paraBase.hpp>
class paraMJPEG:public paraBase {
private:
	gchar 	name[255];
	gulong 	bitrate; 
	gint	gopSize;
	gint	meMethod;
	gulong	rtpPayloadSize;
public:
	paraMJPEG();
	~paraMJPEG();
	
	//set function
	int SetName(char *_name);
	int SetBitrate(gulong br);
	int SetGopSize(gint size);
	int SetMeMethod(gint _meMethod);
	int SetRtpPayloadSize(gulong size);
	
	//get function
	gchar* GetName();
	gulong GetBitrate();
	gint   GetGopSize();
	gint   GetMeMethod();
	gulong GetRtpPayloadSize();
	
	std::ostream& Dump(std::ostream& out)const;
};
#endif
