#ifndef CALLBACK_IMPL_HPP
#define CALLBACK_IMPL_HPP
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <curses.h>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#ifdef __cplusplus
extern "C" {
#endif
int Test1(void *p);
int Test2(void *p);
int Test3UseArguments(void *p) ;
int ChangeResolution(void *p) ;
#ifdef __cplusplus
}
#endif
#endif
