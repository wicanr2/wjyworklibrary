#ifndef PARAMETER_GSTRTPJITTERBUFFER_HPP
#define PARAMETER_GSTRTPJITTERBUFFER_HPP
#include <baseStream/baseStream.hpp>
#include <conference/parameterManager/paraBase.hpp>
class paraGSTRtpJitterBuffer:public paraBase {
private:
	MACRO_VAR_DECL_FULL( guint    , Latency      , latency );
	MACRO_VAR_DECL_FULL( gboolean , DropOnLatency, drop_on_latency );
	MACRO_VAR_DECL_FULL( gint     , Mode         , mode );

public:
	paraGSTRtpJitterBuffer();
	~paraGSTRtpJitterBuffer();
	std::ostream& Dump(std::ostream& out)const;
};
#endif

