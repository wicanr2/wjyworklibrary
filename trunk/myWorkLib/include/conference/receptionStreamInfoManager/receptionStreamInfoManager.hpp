#ifndef RECEPTION_STREAM_INFORMATION_MANAGER_HPP
#define RECEPTION_STREAM_INFORMATION_MANAGER_HPP
#include <conference/relayManager/relayStream.hpp>
#include <conference/constant.hpp>
#include <macro/macroReceptionStreamInfoManagerAid.hpp>
#include <utils/staticMutexLocker.hpp>
#include <utils/mutexLocker.hpp>
#include <utils/debugClass.hpp>

#define RECEPTION_STREAM_INFORMATION_MANAGER_CONFIG_FILE "config/receptionStreamInfo.cfg"
class receptionStreamInfoManager:public debugClass{
private:
	struct receptionStreamInfoTable {
		int  index;
		char name[32];
		gint recvPort; 
		gint defaultForwardPort; //only for relay stream
	};	
	struct receptionStreamInfoTable *RSIT_RELAY_VIDEO; //type 0
	struct receptionStreamInfoTable *RSIT_RECV_VIDEO;  //type 2
	int RSIT_RELAY_VIDEO_SIZE;

	struct receptionStreamInfoTable *RSIT_RELAY_AUDIO; //type 1
	struct receptionStreamInfoTable *RSIT_RECV_AUDIO;  //type 3
	int RSIT_RELAY_AUDIO_SIZE;

	static staticMutexLocker sMutex;
	static staticMutexLocker sMutexReadConf;
	static bool bReadExternalConf;	
	static receptionStreamInfoManager* instance;
	
	int InitVideoTable();
	int InitAudioTable();
public:
	receptionStreamInfoManager();
	~receptionStreamInfoManager();
	// singleton
	static receptionStreamInfoManager* getInstance();
	static void putInstance();

	int   GetVideoTableSize();
	int   GetAudioTableSize();
	int	  GetIndex      ( int i    , int type );
	char* GetName       ( int index, int type );
	gint  GetRecvPort   ( int index, int type );
	gint  GetForwardPort( int index, int type );
};
#endif
