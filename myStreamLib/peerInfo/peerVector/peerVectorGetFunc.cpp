#include <cstdio>
#include <cstdlib>
#include <cstring>

#include "peer/peer.hpp"
#include "peer/peerVector.hpp"


char * peerVector::GetPeerIP	      (int i) {
	int j = 0;
	int e = 0;
	peerInfo *pi = 0;
	peerInfo *pi2 = 0;
	if ( this->list == 0 ) return 0;
	if ( i < 0 ) {
		if ( this->selfInfo == 0 ) return 0;
		if ( i != this->selfInfo->GetIndex() ) return 0;
		return this->selfInfo->GetIP();
	}
	if ( i >= 0 && i < _PEER_VECTOR_MAX_PEER_SIZE ) {
		for ( j = 0 ; j < _PEER_VECTOR_MAX_PEER_SIZE ; j++ ) {
			pi2 = (*list)[j];
			if ( pi2 != 0 ) {
				if ( pi2->GetIndex() == i ) {
					pi = pi2;
					break;
				}
			}
		}
		if ( pi == 0 ) return 0;
		return pi->GetIP();
	}
	return 0;
}
char * peerVector::GetPeerVideoPort   (int i) {
	int j = 0;
	int e = 0;
	peerInfo *pi = 0;
	peerInfo *pi2 = 0;
	if ( this->list == 0 ) return 0;
	if ( i < 0 ) {
		if ( this->selfInfo == 0 ) return 0;
		if ( i != this->selfInfo->GetIndex() ) return 0;
		return this->selfInfo->GetVideoPort();
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
		if ( pi == 0 ) return 0;
		return pi->GetVideoPort();
	}
	return 0;
}
char * peerVector::GetPeerAudioPort   (int i) {
	int j = 0;
	int e = 0;
	peerInfo *pi = 0;
	peerInfo *pi2 = 0;
	if ( this->list == 0 ) return 0;
	if ( i < 0 ) {
		if ( this->selfInfo == 0 ) return 0;
		if ( i != this->selfInfo->GetIndex() ) return 0;
		return this->selfInfo->GetAudioPort();
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
		if ( pi == 0 ) return 0;
		return pi->GetAudioPort();
	}
	return 0;
}
char * peerVector::GetPeerProbingPort (int i) {
	int j = 0;
	int e = 0;
	peerInfo *pi = 0;
	peerInfo *pi2 = 0;
	if ( this->list == 0 ) return 0;
	if ( i < 0 ) {
		if ( this->selfInfo == 0 ) return 0;
		if ( i != this->selfInfo->GetIndex() ) return 0;
		return this->selfInfo->GetProbingPort();
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
		if ( pi == 0 ) return 0;
		return pi->GetProbingPort();
	}
	return 0;
}
char * peerVector::GetPeerUUID		  (int i) {
	int j = 0;
	int e = 0;
	peerInfo *pi = 0;
	peerInfo *pi2 = 0;
	if ( this->list == 0 ) return 0;
	if ( i < 0 ) {
		if ( this->selfInfo == 0 ) return 0;
		if ( i != this->selfInfo->GetIndex() ) return 0;
		return this->selfInfo->GetUUID();
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
		if ( pi == 0 ) return 0;
		return pi->GetUUID();
	}
	return 0;
}
char * peerVector::GetPeerName		  (int i) {
	int j = 0;
	int e = 0;
	peerInfo *pi = 0;
	peerInfo *pi2 = 0;
	if ( this->list == 0 ) return 0;
	if ( i < 0 ) {
		if ( this->selfInfo == 0 ) return 0;
		if ( i != this->selfInfo->GetIndex() ) return 0;
		return this->selfInfo->GetName();
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
		if ( pi == 0 ) return 0;
		return pi->GetName();
	}
	return 0;
}

int peerVector::GetPeerNum() {
	if ( this->list == 0 ) return -1;
	return this->list->GetUsedPoolSize();
}

int peerVector::GetMaxPeerNum() {
	return _PEER_VECTOR_MAX_PEER_SIZE;
}
int* peerVector::GetPeerBitmap() {
	this->RefreshBitmap();
	return this->peerBitArray;
}

peerInfo* peerVector::GetPeerPtr 	  (int i) {
	int j = 0;
	int e = 0;
	peerInfo *pi = 0;
	peerInfo *pi2 = 0;
	if ( this->list == 0 ) return 0;
	if ( i < 0 ) {
		if ( this->selfInfo == 0 ) return 0;
		if ( i != this->selfInfo->GetIndex() ) return 0;
		return this->selfInfo;
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
		if ( pi == 0 ) return 0;
		return pi;
	}
	return 0;
}
smartPtr<peerInfo>* peerVector::GetPeerSP(int i) {
	int j = 0; 
	peerInfo *pi2 = 0;
	if ( this->list == 0 ) return 0;
	if ( i >=0 && i < _PEER_VECTOR_MAX_PEER_SIZE ) {
		for ( j = 0 ; j < _PEER_VECTOR_MAX_PEER_SIZE ; j++ ) {
			pi2 = (*list)[j];
			if ( pi2 != 0 ) {
				if ( pi2->GetIndex() == i ) {
					return list->GetSmartPtr(j);	
				}
			}
		}
	}
	return 0;
}	
