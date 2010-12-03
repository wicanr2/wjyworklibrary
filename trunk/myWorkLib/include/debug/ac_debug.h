#ifndef AC_DEBUG_H
#define AC_DEBUG_H
#include <syslog.h>
//---------------------------------------------------------
// admission control debug
#define ADMISSION_CONTROL_DEBUG 4

#if ADMISSION_CONTROL_DEBUG >= 1
#define __AC_L1_PRINT(_fmt, ...) \
	openlog("WJY_AC_L1", LOG_PID, LOG_USER ); \
	syslog( LOG_INFO, _fmt, __VA_ARGS__ ); \
	closelog();
#else
#define __AC_L1_PRINT(_fmt, ...)
#endif

#if ADMISSION_CONTROL_DEBUG >= 1
#define __AC_L1_PRINT_NOARG(msg) \
	openlog("WJY_AC_L1", LOG_PID, LOG_USER ); \
	syslog( LOG_INFO, msg ); \
	closelog();
#else
#define __AC_L1_PRINT_NOARG(msg)
#endif

#endif
