#ifndef RECEIVER_RELAY_STREAM_HPP
#define RECEIVER_RELAY_STREAM_HPP
#include <conference/relayManager/relayStream.hpp>
class receiverRelayStream:public relayStream{
protected:
	MACRO_VAR_DECL_FULL (int , Index          , index         );
	MACRO_VAR_DECL_FULL (bool, EnableRecvPort , enableRecvPort);
	MACRO_VAR_DECL_FULL (gint, Port			  , recvPort      );
	int Set_UDPSrc_Params      ( paraUDPSrc *ptr );
public:
	receiverRelayStream();
	~receiverRelayStream();
};
#endif

