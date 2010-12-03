#ifndef PARAMETER_VIDEOSCALE_HPP
#define PARAMETER_VIDEOSCALE_HPP

#include <conference/parameterManager/paraMediaType.hpp>
#include <conference/parameterManager/GSTCaps.hpp>
class paraVideoScale:
	public GSTCaps
{

public:
	paraVideoScale();
	~paraVideoScale();
		
	std::ostream& Dump(std::ostream& out)const;
};
#endif
