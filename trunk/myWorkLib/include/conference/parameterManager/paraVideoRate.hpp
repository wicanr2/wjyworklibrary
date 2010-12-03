#ifndef PARAMETER_VIDEORATE_HPP
#define PARAMETER_VIDEORATE_HPP

#include <conference/parameterManager/paraMediaType.hpp>
#include <conference/parameterManager/GSTCaps.hpp>
class paraVideoRate:
	public GSTCaps 
{

public:
	paraVideoRate();
	~paraVideoRate();
	
	std::ostream& Dump(std::ostream& out)const;
};
#endif
