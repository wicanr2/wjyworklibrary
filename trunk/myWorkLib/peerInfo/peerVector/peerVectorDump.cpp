#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <iomanip>
#include <peer/peer.hpp>
#include <peer/peerVector.hpp>

void peerVector::Dump() {
	
	peerInfo *pi = 0;
	if ( this->list == 0 ) return;
	std::cout << std::endl;
	{
		for ( int i = 0 ; i < 80 ; i++ ) {
			std::cout << "_";
		}
		std::cout <<std::endl;
	}
	std::cout<<"\tPeer Vector Dump";
	std::cout<< std::endl;
	std::cout<<"Max Peer Size     :"<< _PEER_VECTOR_MAX_PEER_SIZE;
	std::cout<< std::endl;
	std::cout<<"Current Peer Size :"<< this->GetPeerNum();
	std::cout<< std::endl;
	{
		for ( int i = 0 ; i < 80 ; i++ ) {
			std::cout << "-";
		}
		std::cout <<std::endl;
	}
	if ( this->selfInfo ) {
		std::cout<<"\tSelf Peer Information";
		std::cout<< std::endl;
		std::cout<< *this->selfInfo;
	}
	std::cout<<"\tPeer Information List";
	std::cout<< std::endl;
	list->EnableDebugFlagLevel4();
	list->Dump();
	std::cout<< std::endl;
	{
		for ( int i = 0 ; i < 80 ; i++ ) {
			std::cout << "_";
		}
		std::cout <<std::endl;
	}	
}

void peerVector::DumpI(int i) {
	peerInfo *pi = 0;
	printf("\n\t- Dump %d -\n",i);
	if ( i < 0 ) {
		if ( this->selfInfo == 0 ) return;
		if ( i != this->selfInfo->GetIndex() ) return;
		this->selfInfo->Dump();
	}
	if ( i >= 0 && i < _PEER_VECTOR_MAX_PEER_SIZE ) {
		pi = (*this->list)[i];
		if ( pi == 0 ) return;	
		if( pi->CheckUsed() ) {
			pi->Dump();
		}
	}
}
