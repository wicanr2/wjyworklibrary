#ifndef MACRO_LOGGER_AID_HPP
#define MACRO_LOGGER_AID_HPP

#define MACRO_LOGGER_PRINT_DIVIDE_LINE()\
	do{\
		for ( int i = 0 ; i < 80 ; i++ ) {\
			printf("-");\
		}\
		printf("\n");\
	}while(0)

// for dump usage
#define MACRO_LOGGER_PRINT_DIVIDE_LINE_2(_out)\
	_out << std::endl;\
	do{\
		for ( int i = 0 ; i < 80 ; i++ ) {\
			_out << "_";\
		}\
		_out <<std::endl;\
	}while(0)

#define MACRO_LOGGER_PRINT_SUBDIVIDE_LINE(_out)\
	_out << std::endl;\
	do{\
		for ( int i = 0 ; i < 80 ; i++ ) {\
			_out << "-";\
		}\
		_out <<std::endl;\
	}while(0)

#define MACRO_LOGGER_PRINT_SUBDIVIDE_LINE_2(_out)\
	_out << std::endl;\
	do{\
		for ( int i = 0 ; i < 80 ; i++ ) {\
			_out << "~";\
		}\
		_out <<std::endl;\
	}while(0)

#define MACRO_LOGGER_PRINT_VAR(_out, _varname, _var,width)\
	do{\
	 _out << _varname << std::setw(width) << _var; \
	}while(0)

#define MACRO_LOGGER_PRINT_COMMA(_out)\
	do{\
	 _out << ", "; \
	}while(0)

#define MACRO_LOGGER_PRINT_NEWLINE(_out)\
	do{\
	 _out << std::endl; \
	}while(0)

#define MACRO_LOGGER_CHECK_VAR( _out, _var )\
	do{\
		if ( _var == NULL ) return _out;\
	}while(0)

#define MACRO_LOGGER_PRINT_VAR_DIRECTLY(_out, _var )\
	do{\
		_out << _var << std::endl;\
	}while(0)

#endif
