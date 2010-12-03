#include <callbackRegister/callbackImpl.h>
#include <callbackRegister/callbackArguments.h>
#ifdef __cplusplus
extern "C" {
#endif
int Test1(void *p) {
	if ( p == 0 ) {
		 printf(" the p is null\n");
		 return -1;
	}
	callbackArguments *cbArgs = (callbackArguments*)p;
	printf(" trigger test1 argument_size = %d\n", cbArgs->size);
	for ( int i = 0 ; i < cbArgs->size ; i++ )
	{
		printf("%s,", cbArgs->arg[i] );
	}
	printf("\n");
	return 0;
}
int Test2(void *p) {
	if ( p == 0 ) {
		 printf(" the p is null\n");
		 return -1;
	}
	callbackArguments *cbArgs = (callbackArguments*)p;
	printf(" trigger test2 argument_size = %d\n", cbArgs->size);
	for ( int i = 0 ; i < cbArgs->size ; i++ )
	{
		printf("%s|", cbArgs->arg[i] );
	}
	printf("\n");
	return 0;
}
int Test3UseArguments(void *p) 
{
	if ( p == 0 ) {
		 printf(" the p is null\n");
		 return -1;
	}
	callbackArguments *cbArgs = (callbackArguments*)p;
	printf(" trigger test3 argument_size = %d\n", cbArgs->size);
	for ( int i = 0 ; i < cbArgs->size ; i++ )
	{
		printf("%s", cbArgs->arg[i] );
	}
	printf("\n");
	return 0;
}
#ifdef __cplusplus
}
#endif

