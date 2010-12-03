#include <xmlConfig/xmlConfig.h>
struct _VideoProfile {
	gboolean doTimestamp ;
	gboolean alwaysCopy ;
	gboolean sync;
	gboolean async;
	int capWidth ; // the capture Width
	int capHeight ; // the caputre Height
	int capFR ; // the framerate
	int scaleWidth ;
	int scaleHeight;
	int scaleFR;
	int divideBase;
	guint capQueueSize ; // the capture Queue size only for V4L2
	guint 	prerollQueueLength;
	guint   blkSize;
	gint64	maxlateness;
	gboolean debug;
	gchar device[255];
};
static struct _VideoProfile _vcProfile ;
static TypePool __videoTypePool[] = {
	{ "Camera", "doTimestamp","do-timestamp", G_BOOL, &_vcProfile.doTimestamp } ,
	{ "Camera", "alwaysCopy","always-copy", G_BOOL , &_vcProfile.alwaysCopy  } ,
	{ "Convey", "synchronize","sync", G_BOOL, &_vcProfile.sync },
	{ "Convey", "asynchronous","async", G_BOOL, &_vcProfile.async },
	{ "Camera", "width" ,"none", INT, &_vcProfile.capWidth },
	{ "Camera", "height","none", INT, &_vcProfile.capHeight },
	{ "Camera", "framerate","none", INT, &_vcProfile.capFR  },
	{ "Scale",  "width" ,"none", INT , &_vcProfile.scaleWidth},
	{ "Scale",  "height","none", INT , &_vcProfile.scaleHeight},
	{ "Scale",  "framerate","none", INT , &_vcProfile.scaleFR},
	{ "Scale",  "divideBase","none", INT , &_vcProfile.divideBase},
	{ "Camera", "queueSize","queue-size", G_UINT, &_vcProfile.capQueueSize },
	{ "Convey", "prerollQueueLen","preroll-queue-len", G_UINT , &_vcProfile.prerollQueueLength },
	{ "Convey", "blocksize","blocksize", G_UINT , &_vcProfile.blkSize },
	{ "Convey", "maxLateness" ,"max-lateness", G_INT64, &_vcProfile.maxlateness },
	{ "Convey", "debug" ,"none", G_BOOL, &_vcProfile.debug },
	{ "Device", "location" ,"none", G_STR, &_vcProfile.device },
	{ 0, 0, 0, LAST, 0 }
};

void VideoXMLProfile_Init() {
	__XMLRegister("VideoCaptureProfile", "config//camera.xml", __videoTypePool);
}
