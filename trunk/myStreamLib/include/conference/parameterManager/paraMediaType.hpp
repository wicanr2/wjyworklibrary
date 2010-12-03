#ifndef PARAMETER_MEDIATYPE_HPP
#define PARAMETER_MEDIATYPE_HPP
#include <baseStream/baseStream.hpp>
#include <conference/parameterManager/paraBase.hpp>
class paraMediaType:
	public paraBase
{
protected:
	char mediaType[255];

public:

	int SetMediaType(char *m){
		if ( m == 0 )
			return -1;
		snprintf( this->mediaType, 255, "%s", m );
		return 0;
	}
	
	char *GetMediaType(){
		return this->mediaType;
	}
	
	std::ostream& Dump(std::ostream& out)const {
		paraBase::Dump(out);
		out << std::endl;
		out << "Media Type : " << this->mediaType<< ", ";
		return out;
	}
};
#endif
