#ifndef PARAMETER_MULTIUDPSINK_HPP
#define PARAMETER_MULTIUDPSINK_HPP

#include <baseStream/baseStream.hpp>
#include <conference/parameterManager/paraBase.hpp>
#include <conference/parameterManager/paraUDPSink.hpp>
class paraMultiUDPSink:
	public paraUDPSink
{
private:
	
public:
	paraMultiUDPSink();
	~paraMultiUDPSink();
	
	std::ostream& Dump(std::ostream& out)const;
};
#endif
