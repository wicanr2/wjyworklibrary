#ifndef AUDIO_CONTROL_H
#define AUDIO_CONTROL_H

//#include "audio_core.h"


//-------------------------------------------------------------------------------
// public method
/* audio_sink_num  */
#ifdef __cplusplus
extern "C" {
#endif
int 	audio_sink_num();
char* 	audio_sink_name(int idx); // return audio sink name
char* 	audio_sink_short_name(int idx);
int 	ADMNextSink();
int 	ADMNextSource();
int 	ADMConfereceDeviceWithRinging();
int		ADMConfereceDevice();
int		ADMPreviousDevice();
int		ADMPreviousConfereceDevice();
char* 	audio_default_sink_name(); // return audio default_sink name
void 	ADMInit(GMainContext *gmc);
void	ADMRinging();
void 	ADMRingOff();
void	ADMSetHandsetOnKeyEnable();
void 	ADMSetHandsetOnKeyEnableAndRinging();
void	ADMClearPulseAudioDataBase();
void 	audio_server_close();
#ifdef __cplusplus
}
#endif
#endif
