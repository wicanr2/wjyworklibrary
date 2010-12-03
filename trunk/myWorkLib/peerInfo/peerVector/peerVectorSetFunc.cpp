#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <pthread.h>
#include <peer/peer.hpp>
#include <peer/peerVector.hpp>

int	peerVector::SetPeerIP          ( int i, char *ip ) {
	int r = 0;
	int j = 0;
	int e = 0;
	peerInfo *pi = 0;
	peerInfo *pi2 = 0;
	if ( ip == 0 ) return -1;
	if ( i < 0 ) {
		if ( this->selfInfo == 0 ) return -1;
		if ( i != this->selfInfo->GetIndex() ) return -1;
		ML.Lock();
		r = this->selfInfo->SetIP( ip );
		ML.Unlock();
		return 0;
	}
	if ( i >=0 && i < _PEER_VECTOR_MAX_PEER_SIZE ) {
		ML.Lock();
		for ( j = 0 ; j < _PEER_VECTOR_MAX_PEER_SIZE ; j++ ) {
			pi2 = (*list)[j];
			if ( pi2 != 0 ) {
				if ( pi2->GetIndex() == i ) {
					pi = pi2;
					e = 1;
					break;
				}
			}
		}
		if ( e == 0 ) {
			pi = new peerInfo ;
			pi->SetIndex(i);
			list->AppendItem(pi);
		}
		r = pi->SetIP( ip );
		//r = this->_pV[i].SetIP( ip );
		ML.Unlock();
		return r;
	}
	return -1;
}
int peerVector::SetPeerVideoPort   ( int i, char *port ) {
	int r = 0;
	int j = 0;
	int e = 0;
	peerInfo *pi = 0;
	peerInfo *pi2 = 0;
	if ( port == 0 ) return -1;
	if ( i < 0 ) {
		if ( this->selfInfo == 0 ) return -1;
		if ( i != this->selfInfo->GetIndex() ) return -1;
		ML.Lock();
		r = this->selfInfo->SetVideoPort( port );
		ML.Unlock();
		return 0;
	}
	if ( i >=0 && i < _PEER_VECTOR_MAX_PEER_SIZE ) {
		ML.Lock();
		for ( j = 0 ; j < _PEER_VECTOR_MAX_PEER_SIZE ; j++ ) {
			pi2 = (*list)[j];
			if ( pi2 != 0 ) {
				if ( pi2->GetIndex() == i ) {
					pi = pi2;
					e = 1;
					break;
				}
			}
		}
		if ( e == 0 ) {
			pi = new peerInfo ;
			pi->SetIndex(i);
			list->AppendItem(pi);
		}
		r = pi->SetVideoPort( port );
		//r = this->_pV[i].SetVideoPort( port );
		ML.Unlock();
		return r;
	}
	return -1;
}
int peerVector::SetPeerAudioPort   ( int i, char *port ) {
	int r = 0;
	int j = 0;
	int e = 0;
	peerInfo *pi = 0;
	peerInfo *pi2 = 0;
	if ( port == 0 ) return -1;
	if ( i < 0 ) {
		if ( this->selfInfo == 0 ) return -1;
		if ( i != this->selfInfo->GetIndex() ) return -1;
		ML.Lock();
		r = this->selfInfo->SetAudioPort( port );
		ML.Unlock();
		return 0;
	}
	if ( i >=0 && i < _PEER_VECTOR_MAX_PEER_SIZE ) {
		ML.Lock();
		for ( j = 0 ; j < _PEER_VECTOR_MAX_PEER_SIZE ; j++ ) {
			pi2 = (*list)[j];
			if ( pi2 != 0 ) {
				if ( pi2->GetIndex() == i ) {
					pi = pi2;
					e = 1;
					break;
				}
			}
		}
		if ( e == 0 ) {
			pi = new peerInfo ;
			pi->SetIndex(i);
			list->AppendItem(pi);
		}
		r = pi->SetAudioPort( port );
		//r = this->_pV[i].SetAudioPort( port );
		ML.Unlock();
		return r;
	}
	return -1;
}
int peerVector::SetPeerProbingPort ( int i, char *port ) {
	int r = 0; 
	int j = 0;
	int e = 0;
	peerInfo *pi = 0;
	peerInfo *pi2 = 0;
	if ( port == 0 ) return -1;
	if ( i < 0 ) {
		if ( this->selfInfo == 0 ) return -1;
		if ( i != this->selfInfo->GetIndex() ) return -1;
		ML.Lock();
		r = this->selfInfo->SetProbingPort( port );
		ML.Unlock();
		return 0;
	}
	if ( i >=0 && i < _PEER_VECTOR_MAX_PEER_SIZE ) {
		ML.Lock();
		for ( j = 0 ; j < _PEER_VECTOR_MAX_PEER_SIZE ; j++ ) {
			pi2 = (*list)[j];
			if ( pi2 != 0 ) {
				if ( pi2->GetIndex() == i ) {
					pi = pi2;
					e = 1;
					break;
				}
			}
		}
		if ( e == 0 ) {
			pi = new peerInfo ;
			pi->SetIndex(i);
			list->AppendItem(pi);
		}
		r = pi->SetProbingPort( port );
		//r = this->_pV[i].SetProbingPort( port );
		ML.Unlock();
		return r;
	}
	return -1;
}
int peerVector::SetPeerUUID        ( int i, char *uuid ) {
	int r = 0;
	int j = 0;
	int e = 0;
	peerInfo *pi = 0;
	peerInfo *pi2 = 0;
	if ( uuid == 0 ) return -1;
	if ( i < 0 ) {
		if ( this->selfInfo == 0 ) return -1;
		if ( i != this->selfInfo->GetIndex() ) return -1;
		ML.Lock();
		r = this->selfInfo->SetUUID( uuid );
		ML.Unlock();
		return 0;
	}
	if ( i >=0 && i < _PEER_VECTOR_MAX_PEER_SIZE ) {
		ML.Lock();
		for ( j = 0 ; j < _PEER_VECTOR_MAX_PEER_SIZE ; j++ ) {
			pi2 = (*list)[j];
			if ( pi2 != 0 ) {
				if ( pi2->GetIndex() == i ) {
					pi = pi2;
					e = 1;
					break;
				}
			}
		}
		if ( e == 0 ) {
			pi = new peerInfo ;
			pi->SetIndex(i);
			list->AppendItem(pi);
		}
		r = pi->SetUUID( uuid );
		//r = this->_pV[i].SetUUID( uuid );
		ML.Unlock();
		return r;
	}
	return -1;
}
int peerVector::SetPeerName	       ( int i, char *name ) {
	int r = 0;
	int j = 0;
	int e = 0;
	peerInfo *pi = 0;
	peerInfo *pi2 = 0;
	if ( name == 0 ) return -1;
	if ( i < 0 ) {
		if ( this->selfInfo == 0 ) return -1;
		if ( i != this->selfInfo->GetIndex() ) return -1;
		ML.Lock();
		r = this->selfInfo->SetName( name );
		ML.Unlock();
		return 0;
	}
	if ( i >=0 && i < _PEER_VECTOR_MAX_PEER_SIZE ) {
		ML.Lock();
		for ( j = 0 ; j < _PEER_VECTOR_MAX_PEER_SIZE ; j++ ) {
			pi2 = (*list)[j];
			if ( pi2 != 0 ) {
				if ( pi2->GetIndex() == i ) {
					pi = pi2;
					e = 1;
					break;
				}
			}
		}
		if ( e == 0 ) {
			pi = new peerInfo ;
			pi->SetIndex(i);
			list->AppendItem(pi);
		}
		r = pi->SetName( name );
		//r = this->_pV[i].SetName( name );
		ML.Unlock();
		return r;
	}
	return -1;
}
