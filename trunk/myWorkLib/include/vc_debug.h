#ifndef VC_DEBUG_H
#define VC_DEBUG_H
#include <syslog.h>

//---------------------------------------------------------
// video stream debug
#define VIDEO_STREAM_DEBUG 4

#if VIDEO_STREAM_DEBUG >= 1
#define __VC_L1_DEBUG_PRINT(_fmt, ...) \
	openlog("WJY_LOG_V1", LOG_PID, LOG_USER ); \
	syslog( LOG_DEBUG, _fmt, __VA_ARGS__ ); \
	closelog();
#else
#define __VC_L1_DEBUG_PRINT(_fmt, ...)
#endif

#if VIDEO_STREAM_DEBUG >= 1
#define __VC_L1_DEBUG_PRINT_NOARG(msg) \
	openlog("WJY_LOG_V1", LOG_PID, LOG_USER ); \
	syslog( LOG_DEBUG, msg ); \
	closelog();
#else
#define __VC_L1_DEBUG_PRINT_NOARG(msg)
#endif

#if VIDEO_STREAM_DEBUG >= 1
#define __VC_L1_DEBUG_PRINTERR(_fmt, ...) \
	openlog("WJY_LOG_V1D", LOG_PID, LOG_USER ); \
	syslog( LOG_DEBUG, _fmt, __VA_ARGS__ ); \
	closelog();
#else
#define __VC_L1_DEBUG_PRINTERR(_fmt, ...)
#endif

#if VIDEO_STREAM_DEBUG >= 1
#define __VC_L1_DEBUG_PRINTERR_NOARG(msg) \
	openlog("WJY_LOG_V1ERR", LOG_PID, LOG_USER ); \
	syslog( LOG_DEBUG, msg ); \
	closelog();
#else
#define __VC_L1_DEBUG_PRINTERR_NOARG(msg)
#endif

#if VIDEO_STREAM_DEBUG >= 1
#define __VC_L1_DEBUG_WARN(_fmt, ...)  \
	openlog("WJY_LOG_V1W", LOG_PID, LOG_USER ); \
	syslog( LOG_DEBUG, _fmt, __VA_ARGS__ ); \
	closelog();
#else
#define __VC_L1_DEBUG_WARN(_fmt, ...)
#endif

#if VIDEO_STREAM_DEBUG >= 1
#define __VC_L1_DEBUG_WARN_NOARG(msg)  \
	openlog("WJY_LOG_V1W", LOG_PID, LOG_USER ); \
	syslog( LOG_DEBUG, msg ); \
	closelog();
#else
#define __VC_L1_DEBUG_WARN_NOARG(msg)
#endif

#if VIDEO_STREAM_DEBUG >= 2
#define __VC_L2_DEBUG_PRINT(_fmt, ...)  \
	openlog("WJY_LOG_V2", LOG_PID, LOG_USER ); \
	syslog( LOG_DEBUG, _fmt, __VA_ARGS__ ); \
	closelog();
#else
#define __VC_L2_DEBUG_PRINT(_fmt, ...)
#endif

#if VIDEO_STREAM_DEBUG >= 2
#define __VC_L2_DEBUG_PRINT_NOARG(msg)  \
	openlog("WJY_LOG_V2", LOG_PID, LOG_USER ); \
	syslog( LOG_DEBUG, msg ); \
	closelog();
#else
#define __VC_L2_DEBUG_PRINT_NOARG(msg)
#endif

#if VIDEO_STREAM_DEBUG >= 3
#define __VC_L3_DEBUG_PRINT(_fmt, ...)  \
	openlog("WJY_LOG_V3", LOG_PID, LOG_USER ); \
	syslog( LOG_DEBUG, _fmt, __VA_ARGS__ ); \
	closelog();
#else
#define __VC_L3_DEBUG_PRINT(_fmt, ...)
#endif

#if VIDEO_STREAM_DEBUG >= 3
#define __VC_L3_DEBUG_PRINT_NOARG(msg)  \
	openlog("WJY_LOG_V3", LOG_PID, LOG_USER ); \
	syslog( LOG_DEBUG, msg ); \
	closelog();
#else
#define __VC_L3_DEBUG_PRINT_NOARG(msg)
#endif

#if VIDEO_STREAM_DEBUG >= 3
#define __VC_L3_DEBUG_WARN_NOARG(msg)  \
	openlog("WJY_LOG_V3W", LOG_PID, LOG_USER ); \
	syslog( LOG_DEBUG, msg ); \
	closelog();
#else
#define __VC_L3_DEBUG_WARN_NOARG(msg)
#endif

#if VIDEO_STREAM_DEBUG >= 4
#define __VC_L4_DEBUG_PRINT(_fmt, ...)  \
	openlog("WJY_LOG_V4", LOG_PID, LOG_USER ); \
	syslog( LOG_DEBUG, _fmt, __VA_ARGS__ ); \
	closelog();
#else
#define __VC_L4_DEBUG_PRINT(_fmt, ...)
#endif

#if VIDEO_STREAM_DEBUG >= 4
#define __VC_L4_DEBUG_PRINT_NOARG(msg)  \
	openlog("WJY_LOG_V4", LOG_PID, LOG_USER ); \
	syslog( LOG_DEBUG, msg ); \
	closelog();
#else
#define __VC_L4_DEBUG_PRINT_NOARG(msg)
#endif



#endif
