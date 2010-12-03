
#include <stdio.h>
#include <glib.h>
#include <xmlConfig/xmlConfig.h>

/*
 * XmlNodeType.Element Field = 1
 * XmlNodeType.EndElement Field = 15
 * XmlNodeType.DocumentType  = 10  <!DOCTYPE
 * XmlNodeType.SignificantWhitespace  = 14
 * */
#define PROFILE_NAME "RecvProfile"

struct _RecvProfile {
	//video
	gboolean 	sync;
	gboolean	async;
	gint64		maxLateness;
	guint		jitterLatency;
	gboolean 	jitterDropOnLatency;
	
	//audio
	gboolean 	_doTimestamp;
	gboolean	_sync;
	gboolean	_async;
	gint64		_bufferTime;
	gint64		_latencyTime;
	gdouble		_volume;
	gfloat		_amplification;
	guint		_jitterLatency;
	gboolean 	_jitterDropOnLatency;
	gboolean	_detect_dtmf;
	gint		_delayEquivalent;
	gint		_debugMessageLevel;
};
static struct _RecvProfile __RecvProfile;
static TypePool __RecvTypePool[] = {
	{ "Video", "synchronize" ,"sync", G_BOOL, &__RecvProfile.sync },
	{ "Video", "asynchronous","async", G_BOOL, &__RecvProfile.async },
	{ "Video", "maxLateness" ,"max-lateness", G_INT64, &__RecvProfile.maxLateness },
	/*
	  latency           : Amount of ms to buffer
                        flags: readable, writable
                        Unsigned Integer. Range: 0 - 4294967295 Default: 200 Current: 200

	*/
	{ "Video", "jitterLatency"      ,"latency", G_UINT, &__RecvProfile.jitterLatency },
	{ "Video", "jitterDropOnLatency","drop-on-latency", G_BOOL, &__RecvProfile.jitterDropOnLatency },
	
	{ "Audio", "doTimestamp" ,"do-timestamp", G_BOOL, &__RecvProfile._doTimestamp },
	{ "Audio", "synchronize" ,"sync", G_BOOL, &__RecvProfile._sync },
	{ "Audio", "asynchronous","async", G_BOOL, &__RecvProfile._async },
	{ "Audio", "bufferTime"  ,"buffer-time", G_INT64, &__RecvProfile._bufferTime },
	{ "Audio", "latencyTime" ,"latency-time", G_INT64, &__RecvProfile._latencyTime },
	/*
	 volume             : Volume of this stream, 1.0=100%
                        flags: readable, writable
                        Double. Range:               0 -              10 Default:               1 Current:               1

	*/
	{ "Audio", "volume","volume", G_DOUBLE, &__RecvProfile._volume },
	/*
	  amplification     : Factor of amplification
                        flags: readable, writable, controllable
                        Float. Range:               0 -    3.402823e+38 Default:               1 Current:               1

	*/
	{ "Audio", "amplification"		,"amplification", G_FLOAT, &__RecvProfile._amplification },
	{ "Audio", "jitterLatency"      ,"latency", G_UINT , &__RecvProfile._jitterLatency },
	{ "Audio", "jitterDropOnLatency","drop-on-latency", G_BOOL , &__RecvProfile._jitterDropOnLatency },
	{ "Audio", "detectDTMF","none", G_BOOL , &__RecvProfile._detect_dtmf },
	{ "Audio", "delayEquivalent","none", G_INT , &__RecvProfile._delayEquivalent },
	{ "Audio", "debugMessageLevel","none", G_INT , &__RecvProfile._debugMessageLevel },
	{ 0, 0, 0, LAST, 0 }
};

int RecvProfile_Init()
{
	__XMLRegister( PROFILE_NAME, "config//recvstream.xml", __RecvTypePool);
	return 0;
}
