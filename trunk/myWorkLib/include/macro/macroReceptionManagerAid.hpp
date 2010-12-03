#ifndef MACRO_RECEPTION_MANAGER_AID_HPP
#define MACRO_RECEPTION_MANAGER_AID_HPP
#include <macro/macroDebugClassAid.hpp>

#define MACRO_RECP_MGR_CHECK_INDEX(index)\
	do {\
		if ( this->StreamSize <= 0 ) {\
			MACRO_DEBUG_CLASS_PRINT("StreamSize(%d) <= 0\n", this->StreamSize);\
			return -1;\
		}\
		if ( this->StreamSize > this->maxRecvStream ) {\
			MACRO_DEBUG_CLASS_PRINT("StreamSize(%d) > maxRecvStream(%d)\n",\
					this->StreamSize, this->maxRecvStream);\
			return -1;\
		}\
		if ( index < 0 ) {\
			MACRO_DEBUG_CLASS_PRINT("index(%d) < 0\n", index);\
			return -1;\
		}\
		if ( index >= this->StreamSize ) {\
			MACRO_DEBUG_CLASS_PRINT("index(%d) >= StreamSize(%d)\n", index, this->StreamSize);\
			return -1;\
		}\
	}while(0)

#define MACRO_RECP_MGR_CHECK_WINDOWS_SIZE(size)\
	do{\
		if ( size != this->StreamSize ) {\
			MACRO_DEBUG_CLASS_PRINT("size(%d) != StreamSize(%d)\n",size,this->StreamSize);\
			return -1;\
		}\
	}while(0)

#endif
