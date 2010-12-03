#ifndef PEER_INFO_HEADER_HPP
#define PEER_INFO_HEADER_HPP
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <peer/peerConstant.hpp>
#include <utils/debugClass.hpp>
class peerInfo:public debugClass {
private:
	char ip         [ _PEER_INFO_MAX_IP_STR_SIZE ];
	char videoPort  [ _PEER_INFO_MAX_PORT_STR_SIZE ];
	char audioPort  [ _PEER_INFO_MAX_PORT_STR_SIZE ];
	char probingPort[ _PEER_INFO_MAX_PORT_STR_SIZE ];
	char UUID	    [ _PEER_INFO_MAX_UUID_STR_SIZE ];
	char name		[ _PEER_INFO_MAX_UUID_STR_SIZE ];
	int  used;
	int  index;
	float curAvailableBW;
	
private:
	int SetUsed(int u);
	
public:
	peerInfo();
	~peerInfo();
	// erase function
	void Erase();
	
	// dump function
	void Dump();
	std::ostream& 
		 Dump(std::ostream &out);	
	// combined set function
	int SetInfoBasic ( char *ip, char *vPort, char *aPort );
	
	// basic set function
	int SetIP         ( char *ip   );
	int	SetVideoPort  ( char *port );
	int SetAudioPort  ( char *port );
	int SetProbingPort( char *port );
	int SetUUID       ( char *uuid );
	int SetName		  ( char *name );
	int	SetCurAvaBW	  ( float bw   );
	int SetIndex      ( int i ) ;
	
	// basic get function
	char *GetVideoPort();
	char *GetAudioPort();
	char *GetProbingPort();
	char *GetUUID();
	char *GetIP();
	char *GetName();
	int	 CheckUsed();
	float GetCurAvaBW();
	int   GetIndex();

	friend std::ostream& operator<< ( std::ostream &out, 
			peerInfo &rhs );
};
#endif
