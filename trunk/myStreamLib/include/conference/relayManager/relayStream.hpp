#ifndef RELAY_STREAM_HPP
#define RELAY_STREAM_HPP
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <baseStream/baseStream.hpp>
#include <conference/constant.hpp>
#include <conference/parameterManager/parameterManager.hpp>
#include <conference/parameterManager/parameterManagerCAPI.h>
#include <peer/peer.hpp>
#include <peer/peerInfo.h>
#include <macro/macroRelayStreamAid.hpp>
namespace RELAY_STREAM {
	enum RelayForwardType {
		ForwardType_Video,
		ForwardType_Audio,
		ForwardType_NULL
	};
};
class relayStream:public baseStream {
protected:
	// one-to-one mapping
	peerInfo **peerRelayList;
	char peerRelayStr[ MAX_PEER_RELAY_STRING_SIZE ];	
	char internalDefault[32];
	RELAY_STREAM::RelayForwardType forwardType;
	
	char *GetRelayList();
	char *GetRelayList(char *defaultDest);
	//setter
	virtual int Set_UDPSrc_Params      ( paraUDPSrc *ptr );
	virtual int Set_MultiUDPSink_Params( paraMultiUDPSink *ptr );
	
public:
	relayStream();
	~relayStream();	
	virtual int Create();
	int AddRelayPeer(int i);		
	int AddAllPeer();
	int RemoveRelayPeer(int i);
	int RemoveAllPeer();	
	//setter
	int SetForwardType(RELAY_STREAM::RelayForwardType type); 
};
#endif
