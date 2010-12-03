#ifndef CALLBACK_REGISTER_SINGLETON_C_API_H
#define CALLBACK_REGISTER_SINGLETON_C_API_H
#include <hash_func/hashFuncType.h>
#include <callbackRegister/callbackArguments.h>
#ifdef __cplusplus
extern "C" {
#endif
int CB_REG_INIT();
int CB_REG_PUT_CALLBACK( char *name, hashFuncEntryPtr ptr );  
hashFuncEntryPtr  CB_REG_GET_CALLBACK( char *name );  
void CB_REG_DUMP();
void CB_REG_PUT_INSTANCE();
#ifdef __cplusplus
}
#endif
#endif
