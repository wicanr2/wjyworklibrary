#ifndef PARAMETER_UDPSINK_HPP
#define PARAMETER_UDPSINK_HPP
#include <baseStream/baseStream.hpp>
#include <conference/parameterManager/paraBase.hpp>
class paraUDPSink:public paraBase {
protected:
	char	 clients[512];
	char	 host[255];
	gint	 port;
	gboolean sync;
	gboolean async;
	guint	 blocksize;
	guint	 prerollQueueSize;
	gint64	 maxLateness;
	guint64  bytesToServe;
	guint64  byteServed;
	
public:
	paraUDPSink();
	~paraUDPSink();
	
	//set function
	int SetClients(char *str);
	int SetHost(char *str);
	int SetPort(gint v);
	int SetSync(gboolean b);
	int SetAsync(gboolean b);
	int SetBlockSize(guint v);
	int SetPreroll(guint v);
	int SetMaxLateness(gint64 v);
	
	//get function
	gchar*   GetClients();
	gchar* 	 GetHost();
	gint     GetPort();	
	gboolean GetSync();
	gboolean GetAsync();
	guint	 GetBlockSize();
	guint	 GetPreroll();
	gint64	 GetMaxLateness();
	
	std::ostream& Dump(std::ostream& out)const;
};
#endif
