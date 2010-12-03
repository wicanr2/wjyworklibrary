#ifndef MACRO_RECEPTION_STREAM_INFO_MANAGER_AID_HPP
#define MACRO_RECEPTION_STREAM_INFO_MANAGER_AID_HPP
#include <macro/macroErrorCheck.hpp>
#define MACRO_RECEPTION_STREAM_INFO_MANAGER_GETTER_IMPL_AID(which,type,field,failedrv)\
	do{\
		struct receptionStreamInfoTable *p = 0;\
		int size = 0;\
		if ( type == 0 ) \
		{\
			p = this->RSIT_RELAY_VIDEO;\
			size = this->GetVideoTableSize(); \
		}\
		if ( type == 1 ) {\
			p = this->RSIT_RELAY_AUDIO;\
			size = this->GetAudioTableSize(); \
		}\
		if ( type == 2 ) {\
			p = this->RSIT_RECV_VIDEO;\
			size = this->GetVideoTableSize(); \
		}\
		if ( type == 3 ) {\
			p = this->RSIT_RECV_AUDIO;\
			size = this->GetAudioTableSize(); \
		}\
		MACRO_ERROR_CHECK_WITH_DEBUG(p   , 0, failedrv, "the p    is 0\n");\
		MACRO_ERROR_CHECK_WITH_DEBUG(size, 0, failedrv, "the size is 0\n");\
		for ( int i = 0 ; i < size ; i++ ){\
			if ( p[i].index == which )\
				return p[i].field;\
		}\
		return failedrv;\
	}while(0)	

#define MACRO_RECEPTION_STREAM_INFO_MANAGER_INIT_RELAY_STREAM_TABLE(table,size,rpb,fpb,nameb)\
	do{\
		MACRO_ERROR_CHECK_NOT_0_WITH_DEBUG(table);\
		table = new receptionStreamInfoTable[ size ];\
		MACRO_ERROR_CHECK_0_WITH_DEBUG(table);\
		for ( int i = 0 ; i < size ; i++ ) \
		{\
				table[i].index = i;\
				table[i].recvPort = rpb + i;\
				table[i].defaultForwardPort = fpb + i;\
				snprintf( table[i].name, 32, "%s_%d", nameb, i );\
		}\
	}while(0)

#endif
