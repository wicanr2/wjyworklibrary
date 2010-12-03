#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <peer/peer.hpp>
#include <peer/peerVector.hpp>

peerVector* peerVector::instance = NULL;
staticMutexLocker peerVector::sMutex;

peerVector::peerVector():
	list(0), selfInfo(0) 
{
	MACRO_DEBUG_CLASS_PRINT_L4("Init\tpeerVector\n");
	//this->_pV = new peerInfo[ _PEER_VECTOR_MAX_PEER_SIZE ];
	this->list = new fastLinkedList<peerInfo>;
	this->list->SetMaxPoolSize( _PEER_VECTOR_MAX_PEER_SIZE ); 
	this->RefreshBitmap();
	this->selfInfo = new peerInfo;
	this->selfInfo->SetIndex( PEER_VECTOR::self_index );
}

peerVector::~peerVector() {
	//if ( _pV ) delete [] _pV;
	MACRO_DEBUG_CLASS_PRINT_L4("Destory\tPeerVector\n");
	if ( list ) delete list ;
}

void peerVector::ClearPeerBitmap() {
	int i = 0;
	for ( i = 0 ; i < _PEER_VECTOR_MAX_PEER_SIZE ; i++ ) {
		this->peerBitArray[i] = 0;
	}
}

void peerVector::RefreshBitmap() {
	int i = 0;
	peerInfo *pi = 0;
	if ( this->list == 0 ) return;

	this->ClearPeerBitmap();
	for ( i = 0 ; i < _PEER_VECTOR_MAX_PEER_SIZE ; i++ ) {
		pi = (*this->list)[i];
		if ( pi == 0 ) continue;
		if ( pi->CheckUsed() ) {
			this->peerBitArray[i] = 1;
		}
	}
}

peerVector* peerVector::getInstance() {
	
	staticMutexLocker::Lock( &peerVector::sMutex );
	#if 0 // "broken" optimization
	if ( !_instance )
	#else
	if ( true )
	#endif
	{
		if ( !instance ) {
			instance = new peerVector();
		}
	}
	staticMutexLocker::Unlock( &peerVector::sMutex );
	return instance;
}
void peerVector::putInstance() {
	
	staticMutexLocker::Lock( &peerVector::sMutex );
	if ( instance ) {
		delete peerVector::instance;
		peerVector::instance = NULL;
	}
	staticMutexLocker::Unlock( &peerVector::sMutex );
	
}
