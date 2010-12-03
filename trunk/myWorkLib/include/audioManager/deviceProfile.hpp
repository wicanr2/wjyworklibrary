#ifndef AUDIO_DEVICE_PROFILE_HPP
#define AUDIO_DEVICE_PROFILE_HPP
#include <pulse/pulseaudio.h>
#include <pulse/ext-stream-restore.h>
#include <pulse/version.h>
#include <audioManager/deviceType.hpp>
//the class __AudioDeviceProfile
class __AudioDeviceProfile {
private:	
	__DeviceType 	 	type;
	__DeviceCategory 	category;
	unsigned int 		paIndex;
	char 				_name[255];
	pa_channel_map		_paChannelMap;
	pa_cvolume			_paCVolume;
	int 				isMute;
	__DeviceCategory 
		FindCategory(const char* name);
public:
	__AudioDeviceProfile();
	void UpdateSinkInfo	(const pa_sink_info *l);
	void UpdateSourceInfo (const pa_source_info *l);
	const char* 
		GetName();
	unsigned int 
		GetIndex();
	int GetMute();
	pa_channel_map* 
		GetChannelMap();
	pa_cvolume* 
		GetCVolume();
};
#endif
