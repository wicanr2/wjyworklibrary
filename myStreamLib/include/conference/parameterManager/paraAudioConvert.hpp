#ifndef PARAMETER_AUDIOCONVERT_HPP
#define PARAMETER_AUDIOCONVERT_HPP
#include <baseStream/baseStream.hpp>
#include <conference/parameterManager/paraBase.hpp>
#include <conference/parameterManager/GSTCaps.hpp>
class paraAudioConvert:public GSTCaps {
private:
	MACRO_VAR_DECL_FULL( gint, Dithering, dithering );
	//gint dithering;
	//gint noise_shaping;
	MACRO_VAR_DECL_FULL( gint, NoiseShaping,noise_shaping);
public:
	paraAudioConvert();
	~paraAudioConvert();

	// setter and getter declartion
	//MACRO_VAR_DECL(gint ,Dithering);
	//MACRO_VAR_DECL(gint, NoiseShaping);
	//setter
	//MACRO_SETTER_DECL(gint, Dithering);
	//MACRO_SETTER_DECL(gint, NoiseShaping);
	//int SetDithering(gint v);
	//int SetNoiseShaping(gint v);

	//getter
	//gint GetDithering();
	//gint GetNoiseShaping();
	
	std::ostream& Dump(std::ostream& out)const;
};
#endif
