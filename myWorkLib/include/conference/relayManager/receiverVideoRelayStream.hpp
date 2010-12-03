#ifndef RECEIVER_VIDEO_RELAY_STREAM_HPP
#define RECEIVER_VIDEO_RELAY_STREAM_HPP
#include <conference/relayManager/receiverRelayStream.hpp>
class receiverVideoRelayStream:public receiverRelayStream{
protected:
public:
	receiverVideoRelayStream(int index);
	~receiverVideoRelayStream();
};
#endif
