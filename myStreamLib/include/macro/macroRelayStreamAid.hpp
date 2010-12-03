#ifndef MACRO_RELAY_STREAM_AID_HPP
#define MACRO_RELAY_STREAM_AID_HPP
#include <macro/macroStringAid.hpp>
#define MACRO_RELAY_STREAM_MAKE_PEERLIST(peerPool,targetStr)\
	do {\
		int _i = 0;\
		int offsetVar = strlen(targetStr);\
		for ( int _i = 0 ; _i < _PEER_VECTOR_MAX_PEER_SIZE ; _i++ )\
		{\
			if ( peerPool[_i] == 0 ) continue;\
			switch( this->forwardType ) \
			{\
				case RELAY_STREAM::ForwardType_Audio:\
					offsetVar += snprintf( \
							targetStr + offsetVar, MAX_PEER_RELAY_STRING_SIZE-offsetVar,\
							"%s:%s,", \
							peerPool[_i]->GetIP(),\
							peerPool[_i]->GetAudioPort()\
							);\
					break;\
				case RELAY_STREAM::ForwardType_Video:\
				case RELAY_STREAM::ForwardType_NULL:\
					offsetVar += snprintf( \
							targetStr + offsetVar , MAX_PEER_RELAY_STRING_SIZE-offsetVar,\
							"%s:%s,",\
							peerPool[_i]->GetIP(),\
							peerPool[_i]->GetVideoPort()\
							);\
				default:\
					break;\
			}\
		}\
	}while(0)

#define MACRO_RELAY_STREAM_CLEAN_PEERRELAYSTR()\
	MACRO_STRING_CLEAN_STR( this->peerRelayStr, MAX_PEER_RELAY_STRING_SIZE )
#endif
