#ifndef AUDIO_RECEPTION_GSM_STREAM_HPP
#define AUDIO_RECEPTION_GSM_STREAM_HPP
#include <baseStream/baseStream.hpp>
#include <conference/constant.hpp>
#include <conference/parameterManager/parameterManager.hpp>
#include <conference/parameterManager/parameterManagerCAPI.h>
class audioReceptionGSMStream: public baseStream 
{
private:
	MACRO_VAR_DECL_FULL (int , Index          , index          );
	MACRO_VAR_DECL_FULL (bool, EnableRecvPort , enableRecvPort );
	MACRO_VAR_DECL_FULL (gint, Port			  , recvPort       );

	int Set_UDPSrc_Params             ( paraUDPSrc *ptr );
	int Set_GSTRtpJitterBuffer_Params ( GstElement *e, paraGSTRtpJitterBuffer *ptr );
	int Set_AudioConvert_Params       ( GstElement *e, paraAudioConvert *ptr       );
	int Set_AudioResample_Params      ( GstElement *e, paraAudioResample *ptr      );
	int Set_AudioAmplify_Params       ( GstElement *e, paraAudioAmplify *ptr       );
	int Set_PulseSink_Params          ( paraPulseSink *ptr ); 
	
public:
	audioReceptionGSMStream(int index);
	~audioReceptionGSMStream();
	int Create();
};
#endif 
