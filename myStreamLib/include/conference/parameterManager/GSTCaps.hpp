#ifndef GSTREAMER_CAPABILITIES_HPP
#define GSTREAMER_CAPABILITIES_HPP
#include <iostream>
#include <iomanip>
#include <baseStream/baseStream.hpp>
#include <conference/constant.hpp>
#include <conference/parameterManager/paraBase.hpp>

class GSTCaps:public paraBase
{
protected:
	char 		mediaType[255];
	char 		media[255];
	gint 		clock_rate;
	char 		encoding_name[255];
	gint 		payload;
	gint 		width;
	gint 		height;
	gint 		framerate;
	gint 	 	framerate_base;
	gint 	 	depth;
	gint 	 	rate;
	gint 	 	channels;
	gboolean 	_signed;
	gint 	 	endianness;

public:
	GSTCaps();
	virtual ~GSTCaps();
	
	// get field type 
	gulong GetFieldType(char *field);
	
	// setter
	int SetMediaType(char *v);
	int SetMedia(char *v);
	int SetClockRate(gint v);
	int SetEncodingName(char *v);
	int SetPayload(gint v);
	int SetWidth(gint v);
	int SetHeight(gint v);
	int SetFramerate(gint v);
	int SetBase(gint v);
	int SetDepth(gint v);
	int SetRate(gint v);
	int SetChannels(gint v);
	int SetSigned(gboolean v);
	int SetEndianness(gint v);
	// getter
	
	char* 	 GetMediaType();
	char* 	 GetMedia();
	gint  	 GetClockRate();
	char* 	 GetEncodingName();
	gint  	 GetPayload();
	gint  	 GetWidth();
	gint  	 GetHeight();
	gint  	 GetFramerate();
	gint  	 GetBase();
	gint   	 GetDepth();
	gint  	 GetRate();
	gint  	 GetChannels();
	gboolean GetSigned();
	gint  	 GetEndianness();
	
	std::ostream& Dump(std::ostream& out)const;
	
	friend std::ostream& operator<< 
		(std::ostream &out, GSTCaps &rhs) 
	{
		rhs.Dump(out);
		return out;
		
	}
};
#endif
