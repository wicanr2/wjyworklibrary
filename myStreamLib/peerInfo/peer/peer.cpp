#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <peer/peer.hpp>

#define _STRING_INIT "none"

peerInfo::peerInfo() {
	this->Erase();
}

peerInfo::~peerInfo() {
}

int peerInfo::SetInfoBasic ( char *ip, char *vPort, char *aPort ) {
			
	int r = 0;

	r = this->SetIP( ip );
	if ( r < 0 ) return r;
	r = this->SetVideoPort( vPort );
	if ( r < 0 ) return r;
	r = this->SetAudioPort( aPort );
	if ( r < 0 ) return r;
	
	return 0;
}

void peerInfo::Erase() {
	char msg[] = _STRING_INIT;
	this->SetIP          ( msg );
	this->SetVideoPort   ( msg );
	this->SetAudioPort   ( msg );
	this->SetProbingPort ( msg );
	this->SetUUID        ( msg );
	this->SetName        ( msg );
	this->SetCurAvaBW	 (0.0);
	//this->SetIndex		 (-1);
	this->SetUsed		 (0);
	
}
