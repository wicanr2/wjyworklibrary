#include <cstdio>
#include <cstdlib>
#include <cstring>

#include "peer/peer.hpp"
#include "vc_debug.h"

int peerInfo::SetIP         ( char *ip   ) {
	if ( ip == 0 )
		return -1;
	strncpy ( this->ip  , ip, _PEER_INFO_MAX_IP_STR_SIZE * sizeof(char) );
	this->SetUsed(1);
	return 0;
}

int	peerInfo::SetVideoPort  ( char *port ) {
	if ( port == 0 )
		return -1;

	strncpy ( this->videoPort  , port, _PEER_INFO_MAX_PORT_STR_SIZE * sizeof(char) );
	this->SetUsed(1);
	return 0;
}

int peerInfo::SetAudioPort  ( char *port ) {
	if ( port == 0 )
		return -1;

	strncpy ( this->audioPort  , port, _PEER_INFO_MAX_PORT_STR_SIZE * sizeof(char) );
	this->SetUsed(1);
	return 0;
}

int peerInfo::SetProbingPort( char *port ) {
	if ( port == 0 )
		return -1;

	strncpy ( this->probingPort, port, _PEER_INFO_MAX_PORT_STR_SIZE * sizeof(char) );
	this->SetUsed(1);
	return 0;
}

int peerInfo::SetUUID       ( char *uuid ) {
	if ( uuid == 0 )
		return -1;

	strncpy ( this->UUID       , uuid, _PEER_INFO_MAX_UUID_STR_SIZE * sizeof(char) );
	this->SetUsed(1);
	return 0;
}

int peerInfo::SetName		( char *name ) {
	if ( name == 0 )
		return -1;

	strncpy ( this->name       , name, _PEER_INFO_MAX_UUID_STR_SIZE * sizeof(char) );		
	this->SetUsed(1);
	return 0;
}

int	peerInfo::SetCurAvaBW	  ( float bw   ) {
	this->curAvailableBW = bw;
	this->SetUsed(1);
	return 0;
}

int peerInfo::SetIndex	( int i ) {
	this->index = i;
	return 0;
}

//private set function
int peerInfo::SetUsed(int u) {
	this->used = u;
}

