#ifndef AUDIO_DEVICE_MANAGEMENT_HPP
#define AUDIO_DEVICE_MANAGEMENT_HPP

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <pulse/pulseaudio.h>
#include <pulse/ext-stream-restore.h>
#include <pulse/version.h>
#include <pulse/glib-mainloop.h>
#include <glib.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <pthread.h>
#include <vc_debug.h>
#include <xmlConfig/xmlConfig.h>
#include <audioManager/constant.hpp>
#include <audioManager/USBPhone.hpp>
#include <audioManager/deviceBindle.hpp>
#include <audioManager/deviceProfile.hpp>
#include <audioManager/deviceType.hpp>
#include <audioManager/serverInfo.hpp>
#include <utils/mutexLocker.hpp>
#include <utils/staticMutexLocker.hpp>
#ifdef __cplusplus
#include <vector>
#include <algorithm>
using namespace std;
#endif


/*
 * 		audio_type 	紀錄該 audio 是屬於哪種裝置
 * 		name 		audio device full name
 * 		short_name	audio device short name
 * 		pa_map		audio device channel map
 * 		pa_volume	audio device default volume
 * */
#ifdef __cplusplus



typedef vector< __AudioDeviceProfile*> DeviceSet;

// the class __AudioDeviceManager
class __AudioDeviceManager{
	//XML profile
private:	
	DeviceSet sinkSet;
	DeviceSet sourceSet;
	// input list
	// output list
	// pulseaudio needed variable
	struct 
	pa_glib_mainloop *paGlibMainloop;
	pa_mainloop_api  *paMainloopApi;
	pa_context 		 *paContext;
	pa_proplist      *paPropList;
	GMainContext	 *gMainContext;
	guint	_reconnectId;
	
	// flag
	bool bInit;
	bool bInChangeDevice;
	bool bBindSwitch;
	bool bDoNotSwitch;
	gboolean updateSourceStreamVolumeDB;
	gboolean updateSinkStreamVolumeDB;
	
	int	_selectSinkIdx;
	int	_selectSourceIdx;
	int	_defaultSinkIdx;
	int	_defaultSourceIdx;
	
	char prevSinkName		[255]; //record the previous sink name
	char prevSourceName		[255]; //record the previous source name
	char prevRingSinkName	[255]; //record the previous sink name before enter conferece
	char prevRingSourceName	[255]; //record the previous source name before enter conferece
	
	__PAServerInfo serverInfo;
	__AudioDeviceProfile * nextSinkProfile ;
	__AudioDeviceProfile * nextSourceProfile ;
	
	// bindle check
	__AudioBindle *bindleCheck;
	
	// USB Phone Device
	__USBB2KDevice *usbb2kDevice;
	
	// locker 
	mutexLocker ML;
	// static locker
	static staticMutexLocker sMutex;
	
public:	//non-callback methods
	__AudioDeviceManager		(GMainContext *GMC);
	//Information Request function
	int ConnectToPAServer		();
	
private:
	//operation waiting method
	// VolumeOpActive
	pa_operation *volOp;
	bool VolumeOpActive();
	bool DeviceEqual(const char* n1, const char* n2);
	
public:
	// ---------- Bind switching funcs---------
	// Bind switching functions
	// AudioDeviceManagmenetBindSwitch.cpp
	void ChangeToConferenceBindleWithRinging	();
	void ChangeToConferenceBindle				();
	void RestoreToPreviousBindle				();
	void RestoreToPreviousConferenceBindle		();
private:	
	//bindle switch
	bool NeedBindSwitch();
	void SourceBindleSwitch();
	void SinkBindleSwitch();
	// ---------- Bind Switching End ----------
	
	
public:	
	// ---------- Lock Functions --------------
	// Lock functions
	// AudioDeviceManagementLock.cpp
	// Request Lock
	bool isInChangeDevice		();
	void SetInChangeDevice		();
	void UnsetInChangeDevice	();
	// ---------- Lock Function End -----------
	
	
	// ----------------------------------------
	// USB Phone Control
	// AudioDeviceManagementUSBPhoneControl.cpp
	void RingOn					();
	void RingOff				();
	void SetHandsetOnKeyEnable	();
	// ----------------------------------------
private:	
	
	// ----------------------------------------
	// Request PA Functions
	// AudioDeviceManagementRequestPA.cpp
	void RequestPAServerInfo ();
	void RequestPASinkInfo();
	void RequestPASourceInfo();
	void RequestPASinkInputInfo();
	void RequestPAClientInfo();
	// ----------------------------------------
	
	// ----------------------------------------
	// Set Maintain Function
	// AudioDeviceManagementSetMaintain.cpp
	void UpdateServerInfo		(const pa_server_info *i);
	void UpdateSinkInfo			(const pa_sink_info *l);
	void UpdateSourceInfo		(const pa_source_info* l);
	void RemoveSinkInfo			(unsigned int index);
	void RemoveSourceInfo		(unsigned int index);
	//repeat check
	bool isMonitor				(const char* name);
	bool isSinkInSet			(const pa_sink_info *l);
	bool isSourceInSet			(const pa_source_info *l);
	__AudioDeviceProfile * 
		 GetNextSinkProfile		();
	__AudioDeviceProfile * 
		 FindSinkProfile		(const char* name);
	__AudioDeviceProfile * 
		 GetNextSourceProfile	();
	__AudioDeviceProfile * 
		 FindSourceProfile		(const char* name);
	// ----------------------------------------
	
	// ----------------------------------------
	// callbacks
	// AudioDeviceManagementCallback.cpp
	static void StateQuery(pa_context *c, void *userdata);
	static void Subscribe (pa_context *c, pa_subscription_event_type_t t, uint32_t index, void *userdata);
	// ----------------------------------------
	
	// ----------------------------------------
	// Retrieve Callback
	// AudioDeviceManagementRetrieve.cpp
	static void RetrievedServerInfo
				(pa_context *c, const pa_server_info *i, void *userdata);
	static void RetrievedSinkInfo
				(pa_context *c, const pa_sink_info *l, int eol, void *userdata);
	static void RetrievedSourceInfo 
				(pa_context *c, const pa_source_info *l, int eol, void *userdata);
	static void RetrievedSinkInputInfo 
				(pa_context *c, const pa_sink_input_info *i, int eol,void *userdata);
	static void RetrievedClientInfo 
				(pa_context *c, const pa_client_info *i, int eol,void *userdata);
	// ----------------------------------------
	
	// ----------------------------------------
	// Stream Restore Callback
	// AudioDeviceManagementStreamRestore.cpp
	static void StreamRestoreRead 
				(pa_context *c, const pa_ext_stream_restore_info *i, int eol,void *userdata);
	static void StreamRestoreSubscribe 
				(pa_context *c, void *userdata);
	static void StreamRestore 
				(pa_context *c, const pa_ext_stream_restore_info *info, int eol, void *userdata);
	static void StreamRestoreInput 
				(pa_context *c, const pa_ext_stream_restore_info *info, int eol, void *userdata);
	// ----------------------------------------
	
	// ----------------------------------------
	// success callback
	// AudioDeviceManagementSuccess.cpp
	static void Success 
				(pa_context *c, int success, void *userdata);
	static void SuccessChangeSink
				(pa_context *c, int success, void *userdata);
	static void SuccessChangeSinkVolume
				(pa_context *c, int success, void *userdata);
	static void SuccessChangeSinkMute
				(pa_context *c, int success, void *userdata);
	// ----------------------------------------			
	
	// ----------------------------------------			
	// Request Sink functions
	// AudioDeviceManagementRequestSink.cpp
	int  RequestSink(const char *name);
	int  DoChangeSink();
	void DoChangeSink2();
	void _SetNewSink();
	void _SetNewSinkVolume();
	void _SetNewSinkMute();
	void _RestoreSinkDataBase();
	void _SubscribesSink();
	void UpdateExternalStreamSink
		 (const pa_ext_stream_restore_info *info);
public:		 
	void RequestNextSink ();
	// ----------------------------------------			
private:	
	// ----------------------------------------		
	// Request Source functions
	// AudioDeviceManagementRequestSource.cpp
	int  RequestSource(const char *name);
	int  DoChangeSource();
	void UpdateExternalStreamSource
		 (const pa_ext_stream_restore_info *info);
public:		 
	void RequestNextSource		();
	// ----------------------------------------		

	
public:	
	// ----------------------------------------
	// gtk callback functions
	// AudioDeviceManagementGTKEvent.cpp
	static gboolean GTK_ChangeNextSink						(gpointer data);
	static gboolean GTK_ChangeNextSource					(gpointer data);
	static gboolean GTK_ChangeToConferenceDeviceWithRinging	(gpointer data);
	static gboolean GTK_ChangeToConferenceDevice			(gpointer data);
	static gboolean GTK_ChangeToPreviousDevice				(gpointer data);
	static gboolean GTK_ChangeToPreviousConferenceDevice	(gpointer data);
	static gboolean GTK_RingOff								(gpointer data);
	// ----------------------------------------
};


#endif
#endif
