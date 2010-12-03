#ifndef CALLBACK_ARGUMENTS_STRUCTURE_H
#define CALLBACK_ARGUMENTS_STRUCTURE_H

#ifdef __cplusplus
extern "C" {
#endif

struct _callbackArguments {
	int size;
	char *target;
	char *arg[5];
};
typedef struct _callbackArguments callbackArguments;
#ifdef __cplusplus
}
#endif
#endif
