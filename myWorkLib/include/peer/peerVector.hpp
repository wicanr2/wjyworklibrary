#ifndef PEER_VECTOR_HPP
#define PEER_VECTOR_HPP
#include <pthread.h>
#include <peer/peerConstant.hpp>
#include <peer/peer.hpp>
#include <utils/staticMutexLocker.hpp>
#include <utils/mutexLocker.hpp>
#include <list/fastLinkedList.hpp>
#include <utils/debugClass.hpp>
namespace PEER_VECTOR {
	const int self_index = -99;
};
class peerVector:public debugClass {

private:	
	fastLinkedList<peerInfo> *list;	
	peerInfo *selfInfo;
	// single instance
	static peerVector* instance;
	// static mutex
	static staticMutexLocker sMutex;
	// mutex locker
	mutexLocker ML;
	
	int peerBitArray[ _PEER_VECTOR_MAX_PEER_SIZE ];
	// count refresh
	void RefreshBitmap();
	void ClearPeerBitmap();
	
	
	peerVector();
	~peerVector();
	
public:	
	static peerVector* getInstance();
	static void putInstance();
		
	//dump function
	void Dump();
	void DumpI(int i);
	// add peer
	int Add    ( int i, char *ip, char *vport, char* aport );
	int AddExt ( int i, char *ip, char *vport, char* aport, char *pport );
	int AddExt2( int i, char *ip, char *vport, char* aport, 
				 char *pport, char *uuid, char *name );
				 
	// set
	int	SetPeerIP          ( int i, char *ip ) ;
	int SetPeerVideoPort   ( int i, char *port );
	int SetPeerAudioPort   ( int i, char *port );
	int SetPeerProbingPort ( int i, char *port );
	int SetPeerUUID        ( int i, char *uuid );
	int SetPeerName	       ( int i, char *name );

	// get
	char * GetPeerIP	      (int i);
	char * GetPeerVideoPort   (int i);
	char * GetPeerAudioPort   (int i);
	char * GetPeerProbingPort (int i);
	char * GetPeerUUID		  (int i);
	char * GetPeerName		  (int i);
	peerInfo *GetPeerPtr 	  (int i);
	smartPtr<peerInfo>* GetPeerSP(int i);	
	// get peer status
	int  GetMaxPeerNum();
	int *GetPeerBitmap();
	int  GetPeerNum();
	//erase all
	void ErasePeer(int i);
	void EraseAll();
	
	
};

#endif
