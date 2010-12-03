#ifndef PARAMETER_PULSESRC_HPP
#define PARAMETER_PULSESRC_HPP
#include <baseStream/baseStream.hpp>
#include <conference/parameterManager/paraBase.hpp>
class paraPulseSrc:public paraBase {
protected:
	gulong	 blocksize;
	gint   	 num_buffers;
	gboolean do_timestamp;
	gint64   buffer_time;
	gint64   latency_time;
    gboolean provide_clock;
	gint     slave_method;
 public:
	paraPulseSrc();
	~paraPulseSrc();
	
	// setter
	int SetBlockSize(gulong v); 
	int SetNumBuffers(gint v);
	int SetDoTimestamp(gboolean v);
	int SetBufferTime(gint64 v);
	int SetLatencyTime(gint64 v);
	int SetProvideClock(gboolean v);
	int SetSlaveMethod(gint v);

	// getter
	gulong   GetBlockSize(); 
	gint     GetNumBuffers();
	gboolean GetDoTimestamp();
	gint64   GetBufferTime();
	gint64   GetLatencyTime();
	gboolean GetProvideClock();
	gint     GetSlaveMethod();

	std::ostream& Dump(std::ostream& out)const;
};
#endif
