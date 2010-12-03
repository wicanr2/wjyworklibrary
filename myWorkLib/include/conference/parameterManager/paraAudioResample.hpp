#ifndef PARAMETER_AUDIORESAMPLE_HPP
#define PARAMETER_AUDIORESAMPLE_HPP
#include <baseStream/baseStream.hpp>
#include <conference/parameterManager/paraBase.hpp>
#include <conference/parameterManager/GSTCaps.hpp>
class paraAudioResample:public GSTCaps{
private:
	gint quality;
	gint filter_length;
public:

	paraAudioResample();
	~paraAudioResample();

	//setter
	int SetQuality(gint v);
	int SetFilterLength(gint v); 

	//getter
	gint GetQuality();
	gint GetFilterLength(); 

	std::ostream& Dump(std::ostream& out)const;
};
#endif
