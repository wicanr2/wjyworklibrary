#ifndef STREAM_RECEPTION_MANAGER_HPP
#define STREAM_RECEPTION_MANAGER_HPP
#include <gdk/gdkx.h>
#include <gdk/gdk.h>
#include <gtk/gtk.h>
#include <glib.h>
#include <glib/gprintf.h>

#include <baseStream/baseStream.hpp>
#include <utils/staticMutexLocker.hpp>

#include <conference/relayManager/receiverVideoRelayStream.hpp>
#include <conference/relayManager/receiverAudioRelayStream.hpp>
#include <conference/receptionManager/receptionH264Stream.hpp>
#include <conference/receptionManager/receptionGSMStream.hpp>

#include <conference/parameterManager/parameterManager.hpp>
#include <conference/parameterManager/parameterManagerCAPI.h>
#include <xmlConfig/xmlConfig2CPPAPI.hpp>
#include <callbackRegister/callbackRegisterCAPI.h>
#include <admissionControl/rule/ruleManagerCAPI.h>
#include <macro/macroErrorCheck.hpp>
#include <macro/macroReceptionManagerAid.hpp>
#include <streamStarter/security_lock.h>

class streamReceptionManager:public debugClass
{
private:
#ifdef STREAM_RECEPTION_MANAGER_HIGH_SECURITY_LOCK
	mutexLocker ML;	
#endif
	static streamReceptionManager* instance;
	static staticMutexLocker sMutex;
	MACRO_VAR_DECL_FULL(bool, Restartable, bRestartable);
	

	receiverVideoRelayStream **v_relay;
	videoReceptionH264Stream **v_recv; 

	receiverAudioRelayStream **a_relay;
	audioReceptionGSMStream  **a_recv; 

	streamReceptionManager();
	~streamReceptionManager();
	
	MACRO_VAR_ACCESS_DECL_DIRECT(int, StreamSize);
	MACRO_VAR_ACCESS_DECL_DIRECT(int, maxRecvStream );
public:
	static streamReceptionManager* 
		getInstance();
	static void 
		putInstance();

	std::ostream& Dump(std::ostream& out)const; 

	friend std::ostream& operator<< 
		(std::ostream &out, streamReceptionManager& rhs) 
	{
		if ( rhs.GetDebugFlagLevel4() ) 
			rhs.Dump(out);
		return out;
	}
//-----------------------------------------------------
// video receiver relay
	int CreateVideoReceiverRelayStream(int index);
	int StartVideoReceiverRelayStream(int index);
	int RestartVideoReceiverRelayStream(int index);
	int StopVideoReceiverRelayStream(int index);
// video receiver
	int CreateVideoReceiverStreamWithGTKWindow(int index, GtkWidget *w);
	int CreateVideoReceiverStream(int index);
	int StartVideoReceiverStream(int index);
	int RestartVideoReceiverStream(int index);
	int StopVideoReceiverStream(int index);
// audio receiver relay
	int CreateAudioReceiverRelayStream(int index);
	int StartAudioReceiverRelayStream(int index);
	int RestartAudioReceiverRelayStream(int index);
	int StopAudioReceiverRelayStream(int index);
// audio receiver
	int CreateAudioReceiverStream(int index);
	int StartAudioReceiverStream(int index);
	int RestartAudioReceiverStream(int index);
	int StopAudioReceiverStream(int index);
//-----------------------------------------------------
// all video receiver relay
	int CreateAllVideoReceiverRelayStream();
	int StartAllVideoReceiverRelayStream();
	int RestartAllVideoReceiverRelayStream();
	int StopAllVideoReceiverRelayStream();
// all video receiver 
	int CreateAllVideoReceiverStreamWithGTKWindow(int size, GtkWidget *w[] );
	int CreateAllVideoReceiverStream();
	int StartAllVideoReceiverStream();
	int RestartAllVideoReceiverStream();
	int StopAllVideoReceiverStream();
// all audio receiver relay
	int CreateAllAudioReceiverRelayStream();
	int StartAllAudioReceiverRelayStream();
	int RestartAllAudioReceiverRelayStream();
	int StopAllAudioReceiverRelayStream();
// all audio receiver 
	int CreateAllAudioReceiverStream();
	int StartAllAudioReceiverStream();
	int RestartAllAudioReceiverStream();
	int StopAllAudioReceiverStream();
//-----------------------------------------------------
	int CreateAllStreamWithGTKWindow(int size, GtkWidget *w[] );
	int CreateAllStream();
	int StartAllStream();
	int RestartAllStream();
	int StopAllStream();
//-----------------------------------------------------

};
#endif
