#ifndef RECEPTION_STREAM_INFORMATION_MANAGER_SINGLETON_HPP
#define RECEPTION_STREAM_INFORMATION_MANAGER_SINGLETON_HPP

#include <glib.h>
#ifdef __cplusplus
extern "C" {
#endif
// type = 0 , relay VIDEO    , type = 1,  relay AUDIO,
// tyoe = 2 , reception VIDEO, type = 2,  reception AUDIO
const int TYPE_RELAY_VIDEO = 0;
const int TYPE_RELAY_AUDIO = 1;
const int TYPE_RECV_VIDEO  = 2;
const int TYPE_RECV_AUDIO  = 3;
int   RSIM_GetVideoTableSize();
int   RSIM_GetAudioTableSize();
int	  RSIM_GetIndex      ( int i    , int type );
char* RSIM_GetName       ( int index, int type );
gint  RSIM_GetRecvPort   ( int index, int type );
gint  RSIM_GetForwardPort( int index, int type );
void  RSIM_PutInstance();
void  RSIM_Dump(int type);
#ifdef __cplusplus
}
#endif

#endif
