#ifndef PARAMETER_UDPSRC_HPP
#define PARAMETER_UDPSRC_HPP

#include <baseStream/baseStream.hpp>
#include <conference/parameterManager/paraBase.hpp>
#include <conference/parameterManager/GSTCaps.hpp>
class paraUDPSrc:public GSTCaps
{
private:
	guint	 blocksize;
	gint 	 num_buffers;
	gboolean typefind;
	gboolean do_timestamp;
	gint	 port;
	char	 multicast_group[255];
	char 	 multicast_iface[255];
	char	 uri[255];
	gint	 sockfd;
	gint	 buffer_size;
	guint	 timeout;
	gint	 skip_first_bytes;
	gboolean closefd;
	gboolean auto_multicast;

public:
	paraUDPSrc();
	~paraUDPSrc();
	
	//setter
	int SetBlockSize(guint v);
	int SetNumBuffers(gint v);
	int SetTyepfind(gboolean v);
	int SetDoTimesamp(gboolean v);
	int SetPort(gint v);
	int SetMulticastGroup(char* v);
	int SetMulticastIface(char* v);
	int SetURI(char* v);

	int SetSockfd(gint v);
	int SetBufferSize(gint v);
	int SetTimeout(guint v);
	int SetSkipFirstBytes(gint v);
	int SetClosefd(gboolean v);
	int SetAutoMulticast(gboolean v);
	
	//getter	
	guint    GetBlockSize();
	gint     GetNumBuffers();
	gboolean GetTyepfind();
	gboolean GetDoTimesamp();
	gint     GetPort();
	char*    GetMulticastGroup();
	char*    GetMulticastIface();
	char*    GetURI();

	gint     GetSockfd();
	gint     GetBufferSize();
	guint    GetTimeout();
	gint     GetSkipFirstBytes();
	gboolean GetClosefd();
	gboolean GetAutoMulticast();

	std::ostream& Dump(std::ostream& out)const;
};
#endif
