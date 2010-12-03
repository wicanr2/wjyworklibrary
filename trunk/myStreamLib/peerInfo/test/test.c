#include <stdio.h>
#include <peer/peerInfo.h>

int main( int argc, char *argv[] ) {
	int i = 0;
	int *pbitmap = 0;
	PI_SetPeerIP(0, "127.0.0.1");
	PI_SetPeerVideoPort(0, "6000");
	PI_SetPeerAudioPort(0, "8000");
	PI_SetPeerProbingPort(0, "3213213");

	PI_SetPeerIP(1, "127.0.0.1");
	PI_SetPeerVideoPort(1, "6000");
	PI_SetPeerAudioPort(1, "8000");
	PI_SetPeerProbingPort(1, "3213213");
	
	PI_SetPeerIP(2, "127.0.0.1");
	PI_SetPeerVideoPort(2, "6000");
	PI_SetPeerAudioPort(2, "8000");
	PI_SetPeerProbingPort(2, "3213213");

	PI_SetPeerIP(3, "127.0.0.1");
	PI_SetPeerVideoPort(3, "6000");
	PI_SetPeerAudioPort(3, "8000");
	PI_SetPeerProbingPort(3, "3213213");
	
	PI_AddPeer    (4, "123.123.123.123", "5000", "6000" );
	PI_AddPeerExt (5, "123.123.123.123", "5000", "6000","7000" );
	PI_AddPeerExt2(6, "123.123.123.123", "5000", "6000",
				   "7000","#!###12", "Anr" );
	
	PI_ErasePeer(2);
	PI_Dump();
	
	pbitmap = PI_GetPeerBitmap();
	for ( i = 0 ; i < PI_GetMaxPeerNum() ; i++ ) {
		if ( pbitmap[i] ) {
			PI_DumpI(i);
		}
	}
	
	PI_Destory();
	
	return 0;
}
