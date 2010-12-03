#ifndef MACRO_STRING_AID_HPP
#define MACRO_STRING_AID_HPP

#define MACRO_STRING_MAKE_STRING(str) #str

#define MACRO_STRING_CLEAN_STR(targetStr,size)\
	do{\
		int k=0;\
		for ( k = 0 ; k < size ; k++ ){\
			targetStr[k] = 0;\
		}\
	}while(0)
#endif
