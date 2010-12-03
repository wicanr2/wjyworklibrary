#ifndef PEERINFO_H
#define PEERINFO_H
#include <macro/macroPeerAid.hpp>

// this header is for callee from c code
#ifdef __cplusplus
extern "C" {
#endif

// Add peer
int PI_AddPeer(int i, char *ip, char *vport, char* aport);
// AddExt2 peer
int PI_AddPeerExt(int i, char *ip, char *vport, char* aport, char *pport);
// AddExt3 peer
int PI_AddPeerExt2(int i, char *ip, char *vport, char* aport, 
				 char *pport, char *uuid, char *name);

// Individually Set
int	PI_SetPeerIP          ( int i, char *ip ) ;
int PI_SetPeerVideoPort   ( int i, char *port );
int PI_SetPeerAudioPort   ( int i, char *port );
int PI_SetPeerProbingPort ( int i, char *port );
int PI_SetPeerUUID        ( int i, char *uuid );
int PI_SetPeerName	      ( int i, char *name );

// Self Peer Info Set
int	PI_SetSelfIP          ( char *ip ) ;
int PI_SetSelfVideoPort   ( char *port );
int PI_SetSelfAudioPort   ( char *port );
int PI_SetSelfProbingPort ( char *port );
int PI_SetSelfUUID        ( char *uuid );
int PI_SetSelfName	      ( char *name );


// Individually Get
char * PI_GetPeerIP	          (int i);
char * PI_GetPeerVideoPort    (int i);
char * PI_GetPeerAudioPort    (int i);
char * PI_GetPeerProbingPort  (int i);
char * PI_GetPeerUUID		  (int i);
char * PI_GetPeerName		  (int i);
void * PI_GetPeerPtr		  (int i);
void * PI_GetPeerSP			  (int i);

// Self Peer Info Get 
char * PI_GetSelfIP	          ();
char * PI_GetSelfVideoPort    ();
char * PI_GetSelfAudioPort    ();
char * PI_GetSelfProbingPort  ();
char * PI_GetSelfUUID		  ();
char * PI_GetSelfName		  ();
void * PI_GetSelfPtr		  ();


// Get Current Number of peers
int		PI_GetMaxPeerNum();
int * 	PI_GetPeerBitmap();
int 	PI_GetNumPeers();

// Erase peer
void PI_ErasePeer(int i);
// Erase all
void PI_EraseAllPeer();

// Dump
void PI_Dump();
void PI_DumpI(int i);

// Destory
void PI_Destory();

#ifdef __cplusplus
}
#endif

#endif
