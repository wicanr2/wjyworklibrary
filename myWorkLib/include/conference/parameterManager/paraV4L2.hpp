#ifndef PARAMETER_V4L2_HPP
#define PARAMETER_V4L2_HPP

#include <conference/parameterManager/paraBase.hpp>
#include <conference/parameterManager/GSTCaps.hpp>
class paraV4L2:
	public GSTCaps {
private:
	gboolean doTimeStamp;
	gboolean alwaysCopy;
	
public:
	paraV4L2();
	~paraV4L2();
	
	//set function
	int SetDoTimeStamp(gboolean b);
	int SetAlwayCopy(gboolean b);
	
	//get function
	gboolean
		 GetDoTimeStamp();
	gboolean
		 GetAlwayCopy();
		 
	
	std::ostream& Dump(std::ostream& out)const;
};
#endif
