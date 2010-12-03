#ifndef STREAM_RECEPTION_MANAGER_C_API_H 
#define STREAM_RECEPTION_MANAGER_C_API_H 
#ifdef __cplusplus
extern "C" {
#endif
//-----------------------------------------------------
// video receiver relay
int STREAM_RECP_MSR_CreateVideoReceiverRelayStream(int index);
int STREAM_RECP_MSR_StartVideoReceiverRelayStream(int index);
int STREAM_RECP_MSR_RestartVideoReceiverRelayStream(int index);
int STREAM_RECP_MSR_StopVideoReceiverRelayStream(int index);
// video receiver
int STREAM_RECP_MSR_CreateVideoReceiverStreamWithGTKWindow(int index, void *w);
int STREAM_RECP_MSR_CreateVideoReceiverStream(int index);
int STREAM_RECP_MSR_StartVideoReceiverStream(int index);
int STREAM_RECP_MSR_RestartVideoReceiverStream(int index);
int STREAM_RECP_MSR_StopVideoReceiverStream(int index);
// audio receiver relay
int STREAM_RECP_MSR_CreateAudioReceiverRelayStream(int index);
int STREAM_RECP_MSR_StartAudioReceiverRelayStream(int index);
int STREAM_RECP_MSR_RestartAudioReceiverRelayStream(int index);
int STREAM_RECP_MSR_StopAudioReceiverRelayStream(int index);
// audio receiver
int STREAM_RECP_MSR_CreateAudioReceiverStream(int index);
int STREAM_RECP_MSR_StartAudioReceiverStream(int index);
int STREAM_RECP_MSR_RestartAudioReceiverStream(int index);
int STREAM_RECP_MSR_StopAudioReceiverStream(int index);
//-----------------------------------------------------
// all video receiver relay
int STREAM_RECP_MSR_CreateAllVideoReceiverRelayStream();
int STREAM_RECP_MSR_StartAllVideoReceiverRelayStream();
int STREAM_RECP_MSR_RestartAllVideoReceiverRelayStream();
int STREAM_RECP_MSR_StopAllVideoReceiverRelayStream();
// all video receiver 
int STREAM_RECP_MSR_CreateAllVideoReceiverStreamWithGTKWindow
	(int size, void *w[] );
int STREAM_RECP_MSR_CreateAllVideoReceiverStream();
int STREAM_RECP_MSR_StartAllVideoReceiverStream();
int STREAM_RECP_MSR_RestartAllVideoReceiverStream();
int STREAM_RECP_MSR_StopAllVideoReceiverStream();
// all audio receiver relay
int STREAM_RECP_MSR_CreateAllAudioReceiverRelayStream();
int STREAM_RECP_MSR_StartAllAudioReceiverRelayStream();
int STREAM_RECP_MSR_RestartAllAudioReceiverRelayStream();
int STREAM_RECP_MSR_StopAllAudioReceiverRelayStream();
// all audio receiver 
int STREAM_RECP_MSR_CreateAllAudioReceiverStream();
int STREAM_RECP_MSR_StartAllAudioReceiverStream();
int STREAM_RECP_MSR_RestartAllAudioReceiverStream();
int STREAM_RECP_MSR_StopAllAudioReceiverStream();
//-----------------------------------------------------
int STREAM_RECP_MSR_CreateAllStreamWithGTKWindow(int size, void *w[] );
int STREAM_RECP_MSR_CreateAllStream();
int STREAM_RECP_MSR_StartAllStream();
int STREAM_RECP_MSR_RestartAllStream();
int STREAM_RECP_MSR_StopAllStream();
//-----------------------------------------------------
void STREAM_RECP_MGR_PUT_INSTANCE();
//-----------------------------------------------------
int STREAM_RECP_MGR_ENABLE_RESTART();
int STREAM_RECP_MGR_DISABLE_RESTART();
//-----------------------------------------------------
int STREAM_RECP_MGR_SET_STREAM_SIZE(int size);
#ifdef __cplusplus
}
#endif
#endif
