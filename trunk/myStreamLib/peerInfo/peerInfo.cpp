#include <cstdio>
#include <peer/peerInfo.h>
#include <peer/peerVector.hpp>
#include <peer/peer.hpp>


#ifdef __cplusplus
extern "C" {
#endif

// Add peer
int PI_AddPeer(int i, char *ip, char *vport, char* aport) {
	peerVector *pv = peerVector::getInstance();
	if ( pv )
		return pv->Add( i, ip, vport, aport );
	return -1;
}
// AddExt2 peer
int PI_AddPeerExt(int i, char *ip, char *vport, 
				   char* aport, char *pport) 
{
	peerVector *pv = peerVector::getInstance();
	if ( pv )
		return pv->AddExt ( i, ip, vport, aport, pport );
	return -1;
}
// AddExt3 peer
int PI_AddPeerExt2(int i, char *ip, char *vport, char* aport, 
				 char *pport, char *uuid, char *name)
{
	peerVector *pv = peerVector::getInstance();
	if ( pv )
		return pv->AddExt2( i, ip, vport, aport, pport, uuid, name );
	return -1;
}

// Individually Set, if failed return -1
int	PI_SetPeerIP          ( int i, char *ip ) {
	peerVector *pv = peerVector::getInstance();
	if ( pv )
		return pv->SetPeerIP ( i, ip );
	return -1;
}
int PI_SetPeerVideoPort   ( int i, char *port ) {
	peerVector *pv = peerVector::getInstance();
	if ( pv )
		return pv->SetPeerVideoPort ( i, port );
	return -1;
}
int PI_SetPeerAudioPort   ( int i, char *port ) {
	peerVector *pv = peerVector::getInstance();
	if ( pv )
		return pv->SetPeerAudioPort ( i, port );
	return -1;
}
int PI_SetPeerProbingPort ( int i, char *port ) {
	peerVector *pv = peerVector::getInstance();
	if ( pv )
		return pv->SetPeerProbingPort ( i, port );
	return -1;
}
int PI_SetPeerUUID        ( int i, char *uuid ) {
	peerVector *pv = peerVector::getInstance();
	if ( pv )
		return pv->SetPeerUUID ( i, uuid );
	return -1;
}
int PI_SetPeerName	      ( int i, char *name ) {
	peerVector *pv = peerVector::getInstance();
	if ( pv )
		return pv->SetPeerName ( i, name );
	return -1;
}

// Self Peer Info Set
int	PI_SetSelfIP          ( char *ip ) 
{
	peerVector *pv = peerVector::getInstance();
	if ( pv )
		return pv->SetPeerIP ( PEER_VECTOR::self_index , ip );
	return -1;
}
int PI_SetSelfVideoPort   ( char *port ) 
{
	peerVector *pv = peerVector::getInstance();
	if ( pv )
		return pv->SetPeerVideoPort ( PEER_VECTOR::self_index , port );
	return -1;
}
int PI_SetSelfAudioPort   ( char *port )
{
	peerVector *pv = peerVector::getInstance();
	if ( pv )
		return pv->SetPeerAudioPort ( PEER_VECTOR::self_index , port );
	return -1;
}
int PI_SetSelfProbingPort ( char *port )
{
	peerVector *pv = peerVector::getInstance();
	if ( pv )
		return pv->SetPeerProbingPort ( PEER_VECTOR::self_index , port );
	return -1;
}
int PI_SetSelfUUID        ( char *uuid )
{
	peerVector *pv = peerVector::getInstance();
	if ( pv )
		return pv->SetPeerUUID ( PEER_VECTOR::self_index , uuid );
	return -1;
}
int PI_SetSelfName	      ( char *name )
{
	peerVector *pv = peerVector::getInstance();
	if ( pv )
		return pv->SetPeerName ( PEER_VECTOR::self_index , name );
	return -1;
}

// Individually Get, if failed return 0
char * PI_GetPeerIP	          (int i) {
	peerVector *pv = peerVector::getInstance();
	if ( pv )
		return pv->GetPeerIP(i);
	return 0;
}
char * PI_GetPeerVideoPort    (int i) {
	peerVector *pv = peerVector::getInstance();
	if ( pv )
		return pv->GetPeerVideoPort(i);
	return 0;
}
char * PI_GetPeerAudioPort    (int i) {
	peerVector *pv = peerVector::getInstance();
	if ( pv )
		return pv->GetPeerAudioPort(i);
	return 0;
}
char * PI_GetPeerProbingPort  (int i) {
	peerVector *pv = peerVector::getInstance();
	if ( pv )
		return pv->GetPeerProbingPort(i);
	return 0;
}
char * PI_GetPeerUUID		  (int i) {
	peerVector *pv = peerVector::getInstance();
	if ( pv )
		return pv->GetPeerUUID(i);
	return 0;
}
char * PI_GetPeerName		  (int i) {
	peerVector *pv = peerVector::getInstance();
	if ( pv )
		return pv->GetPeerName(i);
	return 0;
}

void * PI_GetPeerPtr		  (int i) {
	peerVector *pv = peerVector::getInstance();
	if ( pv )
		return pv->GetPeerPtr(i);
	return 0;
}

void * PI_GetPeerSP			  (int i) {
	peerVector *pv = peerVector::getInstance();
	if ( pv )
		return pv->GetPeerSP(i);
	return 0;
}
// Sefl Peer Info Get, if failed return 0
char * PI_GetSelfIP	          () {
	peerVector *pv = peerVector::getInstance();
	if ( pv )
		return pv->GetPeerIP( PEER_VECTOR::self_index );
	return 0;
}
char * PI_GetSelfVideoPort    () {
	peerVector *pv = peerVector::getInstance();
	if ( pv )
		return pv->GetPeerVideoPort( PEER_VECTOR::self_index );
	return 0;
}
char * PI_GetSelfAudioPort    () {
	peerVector *pv = peerVector::getInstance();
	if ( pv )
		return pv->GetPeerAudioPort( PEER_VECTOR::self_index );
	return 0;
}
char * PI_GetSelfProbingPort  () {
	peerVector *pv = peerVector::getInstance();
	if ( pv )
		return pv->GetPeerProbingPort( PEER_VECTOR::self_index );
	return 0;
}
char * PI_GetSelfUUID		  () {
	peerVector *pv = peerVector::getInstance();
	if ( pv )
		return pv->GetPeerUUID( PEER_VECTOR::self_index );
	return 0;
}
char * PI_GetSelfName		  () {
	peerVector *pv = peerVector::getInstance();
	if ( pv )
		return pv->GetPeerName( PEER_VECTOR::self_index );
	return 0;
}

void * PI_GetSelfPtr		  () {
	peerVector *pv = peerVector::getInstance();
	if ( pv )
		return pv->GetPeerPtr( PEER_VECTOR::self_index );
	return 0;
}
// Get Current Number of peers
int PI_GetMaxPeerNum() {
	peerVector *pv = peerVector::getInstance();
	if ( pv )
		return pv->GetMaxPeerNum();
	return -1;
}

int* PI_GetPeerBitmap() {
	peerVector *pv = peerVector::getInstance();
	if ( pv )
		return pv->GetPeerBitmap();
	return 0;
}

int PI_GetNumPeers() {
	peerVector *pv = peerVector::getInstance();
	if ( pv )
		return pv->GetPeerNum();
	return -1;
}

// Erase peer
void PI_ErasePeer(int i) {
	peerVector *pv = peerVector::getInstance();
	if ( pv )
		pv->ErasePeer(i);
}

// Erase all
void PI_EraseAllPeer() {
	peerVector *pv = peerVector::getInstance();
	if ( pv )
		pv->EraseAll();
}

// Dump
void PI_Dump() {
	peerVector *pv = peerVector::getInstance();
	if ( pv )
		pv->Dump();
}

void PI_DumpI(int i) {
	peerVector *pv = peerVector::getInstance();
	if ( pv )
		pv->DumpI(i);
}

// Destory
void PI_Destory() {
	peerVector::putInstance();
}


#ifdef __cplusplus
}
#endif
