#ifndef PULSEAUDIO_SERVER_INFO_HPP
#define PULSEAUDIO_SERVER_INFO_HPP
#include <pulse/pulseaudio.h>
#include <pulse/ext-stream-restore.h>
#include <pulse/version.h>
#include <pulse/glib-mainloop.h>
//for record the server information
class __PAServerInfo {
private:
	char userName[255];
	char hostName[255];
	char serverVersion[255];
	char serverName[255];
	char defaultSinkName[255];
	char defaultSourceName[255];
	
	unsigned int cookie;
	pa_sample_spec	sampleSpec;
	pa_channel_map  channelMap;
public:
	__PAServerInfo();
	void UpdateServerInfo(const pa_server_info *i);
	const char* GetDefaultSinkName();
	const char* GetDefaultSourceName();
	
};
#endif
