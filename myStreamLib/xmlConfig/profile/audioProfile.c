
#include <stdio.h>
#include <glib.h>
#include <xmlConfig/xmlConfig.h>

/*
 * XmlNodeType.Element Field = 1
 * XmlNodeType.EndElement Field = 15
 * XmlNodeType.DocumentType  = 10  <!DOCTYPE
 * XmlNodeType.SignificantWhitespace  = 14
 * */


struct _AudioCaptureProfile {
	char capType[255];
	gint capEndianness;
	gboolean capSigned;
	gint capWidth;
	gint capHeight;
	gint capRate;
	gint capChannels;
	gboolean capDoTimestamp;
	gint64 capBufferTime;
	gint64 capLatencyTime;
	gint capSlaveMethod;

	char scaleType[255];
	gint scaleEndianness;
	gboolean scaleSigned;
	gint scaleWidth;
	gint scaleHeight;
	gint scaleRate;
	gint scaleChannels;

	gboolean conveySync;
	gboolean conveyAsync;
	gint64 conveyMaxlateness;
	guint 	conveyPrerollQueueLength;
	guint   conveyBlkSize;
};
static struct _AudioCaptureProfile __auProfile;
static TypePool __audioTypePool[] = {
	{"MicInput", "type","none", G_STR, &__auProfile.capType },
	{"MicInput", "endianness","none", G_INT, &__auProfile.capEndianness },
	{"MicInput", "signed","none", G_BOOL, &__auProfile.capSigned },
	{"MicInput", "width","none", G_INT, &__auProfile.capWidth },
	{"MicInput", "height","none", G_INT, &__auProfile.capHeight },
	{"MicInput", "rate","none", G_INT, &__auProfile.capRate },
	{"MicInput", "channels","none", G_INT, &__auProfile.capChannels },
	{"MicInput", "doTimestamp","do-timestamp", G_BOOL, &__auProfile.capDoTimestamp },
	{"MicInput", "bufferTime","buffer-time", G_INT64, &__auProfile.capBufferTime },
	{"MicInput", "latencyTime","latency-time", G_INT64, &__auProfile.capLatencyTime },
	{"MicInput", "slaveMethod","slave-method", G_INT, &__auProfile.capSlaveMethod },
	
	{"Scale", "type","none", G_STR, &__auProfile.scaleType },
	{"Scale", "endianness","none", G_INT, &__auProfile.scaleEndianness },
	{"Scale", "signed","none", G_BOOL, &__auProfile.scaleSigned },
	{"Scale", "width","none", G_INT, &__auProfile.scaleWidth },
	{"Scale", "height","none", G_INT, &__auProfile.scaleHeight },
	{"Scale", "rate","none", G_INT, &__auProfile.scaleRate },
	{"Scale", "channels","none", G_INT, &__auProfile.scaleChannels },

	{"Convey", "synchronize","sync", G_BOOL, &__auProfile.conveySync },
	{"Convey", "asynchronous","async", G_BOOL, &__auProfile.conveyAsync },
	{"Convey", "maxLateness","max-lateness", G_INT64, &__auProfile.conveyMaxlateness },
	{"Convey", "prerollQueueLen","preroll-queue-len", G_UINT, &__auProfile.conveyPrerollQueueLength },
	{"Convey", "blocksize","blocksize", G_UINT, &__auProfile.conveyBlkSize },
	{ 0, 0, 0, LAST, 0 }
};

int AudioProfile_Init()
{
	__XMLRegister("AudioCaptureProfile", "config//audio.xml", __audioTypePool);
	return 0;
}
