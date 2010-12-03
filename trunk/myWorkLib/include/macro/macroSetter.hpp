#ifndef MACRO_SETTER_HPP
#define MACRO_SETTER_HPP
#include <macro/macroErrorCheck.hpp>
//--------------------------------------------------------
#define MACRO_SETTER_DECL(input_type,name)\
	int Set##name(input_type v);

#define MACRO_SETTER_IMPL(_cls,input_type,name,var) \
	 int _cls::Set##name(input_type v) \
	 { \
	 	this->var = v;\
        return 0;\
	 }
	 
#define MACRO_SETTER_IMPL_WITH_LOCK(_cls,input_type,name,var,_Mutexlock) \
	 int _cls::Set##name(input_type v) \
	 { \
		_Mutexlock.Lock();\
	 	this->var = v;\
		_Mutexlock.Unlock();\
        return 0;\
	 }
//--------------------------------------------------------
#define MACRO_SETTER_STR_DECL(name)\
	MACRO_SETTER_DECL(char*,name)

#define MACRO_SETTER_STR_IMPL(_cls,name,var) \
	 int _cls::Set##name(char* v) \
	 { \
		MACRO_ERROR_CHECK_0_WITH_PRINTF( this->var );\
	 	snprintf( this->var, 255, "%s", v);\
        return 0;\
	 }
	 
#define MACRO_SETTER_STR_IMPL_2(_cls,name,var,width) \
	 int _cls::Set##name(char* v) \
	 { \
		MACRO_ERROR_CHECK_0_WITH_PRINTF( this->var );\
	 	snprintf( this->var, width, "%s", v);\
        return 0;\
	 }
//--------------------------------------------------------
#endif
