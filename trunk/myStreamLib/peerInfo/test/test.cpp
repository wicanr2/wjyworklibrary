#include <cstdio>
#include <peer/peerVector.hpp>
#include <peer/peer.hpp>
#include <peer/peerInfo.h>

int main( int argc, char *argv[] ) {
	int i = 0;
	int *pbitmap = 0;
	peerInfo *p = 0;

	p = new peerInfo();
	
	printf("\n\n");
	{
		char ip[]= "127.0.0.1";
		char vport[] = "5000";
		char aport[] = "5010";
		char pport[] = "7000";
		char UUID[] = "uuid-###########3DSDSFSFSDFDSFSDFsdfds";
		char name[] = "anr"; 
		p->SetIP(ip);
		p->SetVideoPort ( vport );
		p->SetAudioPort ( aport );
		p->SetProbingPort ( pport );
		p->SetUUID( UUID );
		p->SetName( name );
	}
	//p->Dump();
	delete p;
	{
		char ip[]= "127.0.0.1";
		char vport[] = "2000";
		char aport[] = "2000";
		char pport[] = "2000";
		char UUID[] = "uuid-###########3DSDSFSFSDFDSFSDFsdfds";
		char name[] = "anr2"; 
		PI_SetPeerIP(2, ip );
		PI_SetPeerVideoPort(2, vport );
		PI_SetPeerAudioPort(2, aport );
		PI_SetPeerProbingPort(2, pport );
	}
	{
		char ip[]= "140.96.23.76";
		char vport[] = "1234";
		char aport[] = "5678";
		char pport[] = "9012";
		char UUID[] = "uuid-anr_is_handsome_man";
		char name[] = "wang_jyun_you"; 
		PI_SetSelfIP( ip );
		PI_SetSelfVideoPort( vport );
		PI_SetSelfAudioPort( aport );
		PI_SetSelfProbingPort( pport );
		PI_SetSelfUUID( UUID );
		PI_SetSelfName( name );
	}
	{
		char ip[]= "127.0.0.1";
		char vport[] = "0001";
		char aport[] = "0001";
		char pport[] = "0001";
		char UUID[] = "uuid-###########3DSDSFSFSDFDSFSDFsdfds";
		char name[] = "anr0"; 
		PI_SetPeerIP(0, ip );
		PI_SetPeerVideoPort(0, vport );
		PI_SetPeerAudioPort(0, aport );
		PI_SetPeerProbingPort(0, pport );
	}
	{
		char ip[]= "127.0.0.1";
		char vport[] = "1000";
		char aport[] = "1000";
		char pport[] = "1000";
		char UUID[] = "uuid-###########3DSDSFSFSDFDSFSDFsdfds";
		char name[] = "anr1"; 
		PI_SetPeerIP(1, ip );
		PI_SetPeerVideoPort(1, vport );
		PI_SetPeerAudioPort(1, aport );
		PI_SetPeerProbingPort(1, pport );
	}
	
	{
		char ip[]= "127.0.0.1";
		char vport[] = "2000";
		char aport[] = "2000";
		char pport[] = "2000";
		char UUID[] = "uuid-###########3DSDSFSFSDFDSFSDFsdfds";
		char name[] = "anr22"; 
		PI_SetPeerIP(2, ip );
		PI_SetPeerVideoPort(2, vport );
		PI_SetPeerAudioPort(2, aport );
		PI_SetPeerProbingPort(2, pport );
	}

	{
		char ip[]= "127.0.0.1";
		char vport[] = "3000";
		char aport[] = "3000";
		char pport[] = "3000";
		char UUID[] = "uuid-###########3DSDSFSFSDFDSFSDFsdfds";
		char name[] = "anr3"; 
		PI_SetPeerIP(3, ip );
		PI_SetPeerVideoPort(3, vport );
		PI_SetPeerAudioPort(3, aport );
		PI_SetPeerProbingPort(3, pport );
	}
	{
		char ip[]= "123.123.123.123";
		char vport[] = "456000";
		char aport[] = "456000";
		char pport[] = "456000";
		char UUID[] = "uuid-###########3DSDSFSFSDFDSFSDFsdfds";
		char name[] = "anr456"; 
		PI_AddPeer    (4, ip , vport , aport );
		PI_AddPeerExt (5, ip , vport , aport, pport );
		PI_AddPeerExt2(6, ip , vport , aport, pport, UUID, name );
	}
	PI_ErasePeer(2);
	PI_Dump();
	//return 0;
	{
		char ip[]= "127.0.0.1";
		char vport[] = "6000";
		char aport[] = "8000";
		char pport[] = "3213213";
		char UUID[] = "uuid-###########3DSDSFSFSDFDSFSDFsdfds";
		char name[] = "anr222"; 
		PI_SetPeerIP(2, ip );
		PI_SetPeerVideoPort(2, vport );
		PI_SetPeerAudioPort(2, aport );
		PI_SetPeerProbingPort(2, pport );
	}
	peerInfo *peerPtr = (peerInfo*) PI_GetPeerPtr(2);
	if ( peerPtr )
		std::cout << *peerPtr;
	
	peerPtr = (peerInfo*) PI_GetPeerPtr(10);
	if ( peerPtr )
		std::cout << *peerPtr;

	peerPtr = (peerInfo*) PI_GetPeerPtr(6);
	if ( peerPtr )
		std::cout << *peerPtr;

	pbitmap = PI_GetPeerBitmap();
	for ( i = 0 ; i < PI_GetMaxPeerNum() ; i++ ) {
		if ( pbitmap[i] ) {
			PI_DumpI(i);
		}
	}
	PI_EraseAllPeer();
	PI_Dump();
	{
		printf(" Self Information Getter Test ");
		printf(" Self IP = %s\n", PI_GetSelfIP() );
		printf(" Self Video Port = %s\n", PI_GetSelfVideoPort() );
		printf(" Self Audio Port = %s\n", PI_GetSelfAudioPort() );
		printf(" Self Probing Port = %s\n", PI_GetSelfProbingPort() );
		printf(" Self UUID = %s\n", PI_GetSelfUUID() );
		printf(" Self Name = %s\n", PI_GetSelfName() );
		printf(" Self Ptr = %d\n", (int)PI_GetSelfPtr() );
	}	
	PI_Destory();
	return 0;
}
