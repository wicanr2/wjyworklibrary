#ifndef RECEIVER_AUDIO_RELAY_STREAM_HPP
#define RECEIVER_AUDIO_RELAY_STREAM_HPP
#include <conference/relayManager/receiverRelayStream.hpp>
class receiverAudioRelayStream:public receiverRelayStream{
protected:
public:
	receiverAudioRelayStream(int index);
	~receiverAudioRelayStream();
};
#endif
