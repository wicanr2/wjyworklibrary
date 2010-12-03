#ifndef STREAM_PARAMETER_MANAGER_CAPI_H
#define STREAM_PARAMETER_MANAGER_CAPI_H

#ifdef __cplusplus
extern "C" {
#endif

void *PARAMETER_MANAGER_Query( char* role, char* streamName, char* paraName );
int PARAMETER_MANAGER_QueryStreamParams( char* role, char *stream);
int PARAMETER_MANAGER_GetQueryStreamParamsSize();
void *PARAMETER_MANAGER_QueryStreamParamsI ( int i );
void PARAMETER_MANAGER_Dump();
void PARAMETER_MANAGER_EnableDebug();
void PARAMETER_MANAGER_DisableDebug();
void PARAMETER_MANAGER_PutInstance();

void ChangeVideoTransmitterResolutionAndFramerate(int width, int height,int fr, int frBase );
void QueryVideoTransmitterResolutionAndFramerate(int *width, int *height,int *fr, int *frBase );
#ifdef __cplusplus
}
#endif

#endif

