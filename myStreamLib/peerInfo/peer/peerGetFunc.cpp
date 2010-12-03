#include <cstdio>
#include <cstdlib>
#include <cstring>

#include "peer/peer.hpp"
#include "vc_debug.h"

char * peerInfo::GetVideoPort() {
	return this->videoPort;
}

char * peerInfo::GetAudioPort() {
	return this->audioPort;
}

char * peerInfo::GetProbingPort() {
	return this->probingPort;
}

char * peerInfo::GetUUID() {
	return this->UUID;
}

char * peerInfo::GetIP() {
	return this->ip;
}

char * peerInfo::GetName() {
	return this->name;
}

int	 peerInfo::CheckUsed() {
	return this->used;
}

float peerInfo::GetCurAvaBW() {
	return this->curAvailableBW;
}

int peerInfo::GetIndex() {
	return this->index;
}
