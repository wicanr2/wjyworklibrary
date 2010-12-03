#ifndef STREAM_TRANSFER_MANAGER_C_API_H 
#define STREAM_TRANSFER_MANAGER_C_API_H 
#ifdef __cplusplus
extern "C" {
#endif
//-----------------------------------------------------
// video capture
int STREAM_TRANS_MGR_CreateVideoCaptureStream();
int STREAM_TRANS_MGR_StartVideoCaptureStream();
int STREAM_TRANS_MGR_RestartVideoCaptureStream();
int STREAM_TRANS_MGR_StopVideoCaptureStream();
// video transcode 
int STREAM_TRANS_MGR_CreateVideoTranscodeStream();
int STREAM_TRANS_MGR_StartVideoTranscodeStream();
int STREAM_TRANS_MGR_RestartVideoTranscodeStream();
int STREAM_TRANS_MGR_StopVideoTranscodeStream();
// video relay
int STREAM_TRANS_MGR_CreateVideoRelayStream();
int STREAM_TRANS_MGR_StartVideoRelayStream();
int STREAM_TRANS_MGR_RestartVideoRelayStream();
int STREAM_TRANS_MGR_StopVideoRelayStream();
//-----------------------------------------------------
// audio capture
int STREAM_TRANS_MGR_CreateAudioCaptureStream();
int STREAM_TRANS_MGR_StartAudioCaptureStream();
int STREAM_TRANS_MGR_RestartAudioCaptureStream();
int STREAM_TRANS_MGR_StopAudioCaptureStream();
// audio transcode 
int STREAM_TRANS_MGR_CreateAudioTranscodeStream();
int STREAM_TRANS_MGR_StartAudioTranscodeStream();
int STREAM_TRANS_MGR_RestartAudioTranscodeStream();
int STREAM_TRANS_MGR_StopAudioTranscodeStream();
// audio relay
int STREAM_TRANS_MGR_CreateAudioRelayStream();
int STREAM_TRANS_MGR_StartAudioRelayStream();
int STREAM_TRANS_MGR_RestartAudioRelayStream();
int STREAM_TRANS_MGR_StopAudioRelayStream();
//-----------------------------------------------------
int STREAM_TRANS_MGR_CreateAllStream();
int STREAM_TRANS_MGR_StartAllStream();
int STREAM_TRANS_MGR_RestartAllStream();
int STREAM_TRANS_MGR_StopAllStream();
//-----------------------------------------------------
void STREAM_TRANS_MGR_PUT_INSTANCE();
//-----------------------------------------------------
int STREAM_TRANS_MGR_ENABLE_RESTART();
int STREAM_TRANS_MGR_DISABLE_RESTART();
#ifdef __cplusplus
}
#endif
#endif
