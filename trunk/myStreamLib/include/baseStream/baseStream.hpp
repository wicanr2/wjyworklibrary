#ifndef BASE_STREAM_HPP
#define BASE_STREAM_HPP

#include <cstdio>
#include <ctime> 
#include <cstdarg>
#include <cstdlib>
#include <cstring>
#include <glib.h>
#include <gst/gst.h>
#include <gst/interfaces/xoverlay.h>
#include <vc_debug.h>
#include <utils/debugClass.hpp>
#include <utils/mutexLocker.hpp>
#include <unistd.h>
#include <peer/peerInfo.h>
#include <hash/hashTable.hpp>
#include <xmlConfig/constant.hpp>
#include <xmlConfig/xmlConfig2.hpp>
#include <xmlConfig/xmlConfig2CPPAPI.hpp>
#include <conference/constant.hpp>
#include <macro/macroVariableAccess.hpp>
#include <macro/macroBaseStreamAid.hpp>
#include <macro/macroDebugClassAid.hpp>
#include <streamStarter/security_lock.h>

class baseStream:public debugClass {
protected:
	char streamName[255];
	char role[255];
	bool bCreated;
	bool passiveStream;
	unsigned int sleepInterval ;
	
	GstClockTime gstTimeout; // 0.25s
	int timeoutCount;
	char xmlName[255];
	hashTable *hashMappingTable;	
	// hash function
	int PutValue( char *name, hashEntryType type, void *ptr);
	
	// set Function
	int SetStateCreated(bool b);
#ifdef BASESTREAM_HIGH_SECURITY_LOCK
	mutexLocker ML;	
#endif
	//----------------------------------------
	// gstreamer action area
	GstElement* pipeline;
	GstElement* source;
	GstElement* sink;
	// create gstream element
	GstElement* CreateGstElement( char* element, char *name );
	// link auxiliary functions
	int LinkGstElementWithFiltered(
		GstElement *a,
		GstElement *b,
		GstCaps    *caps);
	// close gstream pipeline
	int	CloseGstPipeline();
	// play gstream pipeline
	int PlayGstPipeline();
	// prepare gstream pipeline
	int	PrepareGstPipeline();
	// pause gstream pipeline
	int PauseGstPipeline();
	// change gstream pipeline state
	int ChangeGstPipelineState(GstState desiredState);
	//---------------------------------------
	// test function
	char peerList[512]; // ip:port, ip:port
	char *GetPeerListWithVideoPort();
	char *GetPeerListWithVideoPort(char *defaultPeers);
public:
	baseStream();
	virtual ~baseStream();
	virtual int Create();
	virtual int Start();
	virtual int Stop();
	virtual int Restart();
	virtual int Destory();
	
	// set functions
	int SetPipeline(GstElement *e);
	int SetSource  (GstElement *e);
	int SetSink    (GstElement *e);
	int SetStreamName(char *name);
	int SetSleepInterval(unsigned int v);
	int SetXMLName(char *name);
	int SetRole(char *name);
	int SetGstTimeout( GstClockTime v );
	int SetTimeoutCount( int v );
	int SetPassiveStream( bool v );
	
	// get functions
	bool isCreated();
	GstElement* GetPipeline();
	GstElement* GetSource();
	GstElement* GetSink();
	char* GetStreamName();
	char* GetXMLName();
	char* GetRole();
	GstClockTime GetGstTimeout();
	unsigned int GetSleepInterval();
	hashTable* GetHashTable();
	int GetTimeoutCount();
	bool GetPassiveStream();
};

#endif
