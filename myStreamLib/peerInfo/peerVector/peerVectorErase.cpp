#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <peer/peer.hpp>
#include <peer/peerVector.hpp>

//erase all
void peerVector::ErasePeer(int i) {
	int j = 0;
	int e = 0;
	peerInfo *pi = 0;
	peerInfo *pi2 = 0;
	if ( i < 0 ) {
		if ( this->selfInfo == 0 ) return ;
		if ( i != this->selfInfo->GetIndex() ) return ;
		//this->selfInfo->Erase();
	}
	if ( i >=0 && i < _PEER_VECTOR_MAX_PEER_SIZE ) {
		for ( j = 0 ; j < _PEER_VECTOR_MAX_PEER_SIZE ; j++ ) {
			pi2 = (*list)[j];
			if ( pi2 != 0 ) {
				if ( pi2->GetIndex() == i ) {
					pi = pi2;
					break;
				}
			}
		}
		if ( pi != 0 )
			pi->Erase();
	}
}
void peerVector::EraseAll() {
	peerInfo *pi = 0;
	//if ( this->selfInfo ) this->selfInfo->Erase();
	for ( int i = 0 ; i < _PEER_VECTOR_MAX_PEER_SIZE ; i++ ) {
		pi = (*list)[i];
		if ( pi != 0 )
			pi->Erase();
	}
}
