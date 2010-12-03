#ifndef MACRO_ERROR_CHECK_HPP
#define MACRO_ERROR_CHECK_HPP
#include <macro/macroDebugClassAid.hpp>

// the macros of error check have the return value
#define MACRO_ERROR_CHECK_WITH_DEBUG( lval, rval, rv, ... )\
	do{\
		if ( lval == rval ) {\
			MACRO_DEBUG_CLASS_PRINT( __VA_ARGS__ );\
			return rv;\
		}\
	}while(0)

#define MACRO_ERROR_CHECK_NOT_EQUAL_WITH_DEBUG( lval, rval, rv, ... )\
	do{\
		if ( lval != rval ) {\
			MACRO_DEBUG_CLASS_PRINT( __VA_ARGS__ );\
			return rv;\
		}\
	}while(0)

#define MACRO_ERROR_CHECK_NOT_EQUAL_WITH_NO_DEBUG( lval, rval, rv)\
	do{\
		if ( lval != rval ) {\
			return rv;\
		}\
	}while(0)

#define MACRO_ERROR_CHECK_0_WITH_DEBUG( lval )\
	MACRO_ERROR_CHECK_WITH_DEBUG( lval, 0, -1, "the "#lval" is 0\n" )
	
#define MACRO_ERROR_CHECK_0_RV0_WITH_DEBUG( lval )\
	MACRO_ERROR_CHECK_WITH_DEBUG( lval, 0, 0, "the "#lval" is 0\n" )

#define MACRO_ERROR_CHECK_NOT_0_WITH_DEBUG( lval )\
	MACRO_ERROR_CHECK_NOT_EQUAL_WITH_DEBUG( lval, 0, -1, "the "#lval" is not 0\n" )

#define MACRO_ERROR_CHECK_NOT_0_RV0_WITH_DEBUG( lval )\
	MACRO_ERROR_CHECK_NOT_EQUAL_WITH_DEBUG( lval, 0,  0, "the "#lval" is not 0\n" )

// the macros of error check have no return value
#define MACRO_ERROR_CHECK_NORV_WITH_DEBUG( lval, rval, ... )\
	do{\
		if ( lval == rval ) {\
			MACRO_DEBUG_CLASS_PRINT( __VA_ARGS__ );\
			return;\
		}\
	}while(0)

#define MACRO_ERROR_CHECK_NOT_EQUAL_NORV_WITH_DEBUG( lval, rval, ... )\
	do{\
		if ( lval != rval ) {\
			MACRO_DEBUG_CLASS_PRINT( __VA_ARGS__ );\
			return;\
		}\
	}while(0)

#define MACRO_ERROR_CHECK_0_NORV_WITH_DEBUG( lval )\
	MACRO_ERROR_CHECK_NORV_WITH_DEBUG( lval, 0,"the "#lval" is 0\n" )
	
#define MACRO_ERROR_CHECK_NOT_0_NORV_WITH_DEBUG( lval )\
	MACRO_ERROR_CHECK_NOT_EQUAL_NORV_WITH_DEBUG( lval, 0, -1, "the "#lval" is not 0\n" )

#define MACRO_ERROR_CHECK_WITH_NO_DEBUG( lval, rval, rv )\
	do{\
		if ( lval == rval ) {\
			return rv;\
		}\
	}while(0)

#define MACRO_ERROR_CHECK_WITH_PRINTF(lval, rval, rv,...)\
	do{\
		if ( lval == rval ){\
			printf(__VA_ARGS__);\
			return rv;\
		}\
	}while(0)

#define MACRO_ERROR_CHECK_0_WITH_PRINTF(lval)\
	MACRO_ERROR_CHECK_WITH_PRINTF(lval,0,-1,"the "#lval" is 0\n" );

#define MACRO_ERROR_CHECK_0_RV0_WITH_PRINTF(lval)\
	MACRO_ERROR_CHECK_WITH_PRINTF(lval,0, 0,"the "#lval" is 0\n" );

#endif
