#ifndef PARAMETER_AUDIOAMPLIFY_HPP
#define PARAMETER_AUDIOAMPLIFY_HPP
#include <baseStream/baseStream.hpp>
#include <conference/parameterManager/paraBase.hpp>
#include <conference/parameterManager/GSTCaps.hpp>
class paraAudioAmplify:public GSTCaps {
private:
	MACRO_VAR_DECL_FULL( gfloat, Amplification  , amplification   );
	MACRO_VAR_DECL_FULL( gint  , ClippingMethod , clipping_method );
public:
	paraAudioAmplify();
	~paraAudioAmplify();

	std::ostream& Dump(std::ostream& out)const;
};
#endif
