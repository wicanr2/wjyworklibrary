#ifndef __GIO_CHANNEL_AID_HPP
#define __GIO_CHANNEL_AID_HPP
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <curses.h>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#include <glib.h>
#include <glib/gprintf.h>
#ifdef __cplusplus
extern "C" {
#endif
typedef int(*__gio_event_fnPtr)(gchar cmd);
int AddKeyEvenetReader      (__gio_event_fnPtr fp); 
int RestoreTerminalAttribute();
#ifdef __cplusplus
}
#endif
#endif
