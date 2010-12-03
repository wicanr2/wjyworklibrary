#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <pthread.h>
#include "peer/peer.hpp"
#include "peer/peerVector.hpp"


int peerVector::Add    ( int i, char *ip, char *vport, char* aport ) {
	int r = 0;
	r += this->SetPeerIP ( i, ip );
	r += this->SetPeerVideoPort( i, vport );
	r += this->SetPeerAudioPort( i, aport );
	return r;
}
int peerVector::AddExt 
	( int i, char *ip, char *vport, char* aport, char *pport ) 
{
	int r = 0;
	
	r += this->SetPeerIP ( i, ip );
	r += this->SetPeerVideoPort( i, vport );
	r += this->SetPeerAudioPort( i, aport );
	r += this->SetPeerProbingPort ( i, pport );
	
	return r;
}
int peerVector::AddExt2
	( int i, char *ip, char *vport, char* aport, 
			 char *pport, char *uuid, char *name )
{
	int r = 0;
	
	r += this->SetPeerIP ( i, ip );
	r += this->SetPeerVideoPort( i, vport );
	r += this->SetPeerAudioPort( i, aport );
	r += this->SetPeerProbingPort ( i, pport );
	r += this->SetPeerUUID ( i, uuid );
	r += this->SetPeerName ( i, name );
	
	return r;
}
