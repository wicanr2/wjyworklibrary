#ifndef MACRO_PARAMETER_AID_HPP
#define MACRO_PARAMETER_AID_HPP

// for initial the parameter
#define MACRO_PARA_SET_XML_NAME(xmlname)\
	do{\
		char name[]= xmlname;\
		this->SetXMLName(name);\
	}while(0)

#define MACRO_PARA_SET_PARA_NAME(para_name)\
	do{\
		char name[]= para_name;\
		this->SetParameterName(name);\
	}while(0)

#define MACRO_PARA_ASSOCIATE_XML_ATTR(xmlattr,_hashtype,_var)\
	do{\
	 	char name[]=xmlattr;\
		hashEntryType type=_hashtype;\
		this->PutValue(name,type,&this->_var);\
	}while(0)

// for dump usage
#define MACRO_PARA_PRINT_DIVIDE_LINE(_out)\
	_out << std::endl;\
	do{\
		for ( int i = 0 ; i < 80 ; i++ ) {\
			_out << "_";\
		}\
		_out <<std::endl;\
	}while(0)

#define MACRO_PARA_PRINT_SUBDIVIDE_LINE(_out)\
	_out << std::endl;\
	do{\
		for ( int i = 0 ; i < 80 ; i++ ) {\
			_out << "-";\
		}\
		_out <<std::endl;\
	}while(0)

#define MACRO_PARA_PRINT_VAR(_out, _varname, _var,width)\
	do{\
	 _out << _varname << std::setw(width) << this->_var; \
	}while(0)

#define MACRO_PARA_PRINT_COMMA(_out)\
	do{\
	 _out << ", "; \
	}while(0)

#define MACRO_PARA_PRINT_NEWLINE(_out)\
	do{\
	 _out << std::endl; \
	}while(0)

#endif
