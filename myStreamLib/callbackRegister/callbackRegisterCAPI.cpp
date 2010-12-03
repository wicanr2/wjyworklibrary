#include <callbackRegister/callbackRegister.hpp>
#include <callbackRegister/callbackRegisterCAPI.h>
#include <callbackRegister/callbackImpl.h>
struct callbackTable {
	char name[64];	
	hashFuncEntryPtr fp;
};
static struct callbackTable ct[] =
{
	#include <callbackRegister/callbackTable.h>
};
int CB_REG_INIT()
{
	int size = sizeof(ct)/sizeof(ct[0]);
	for ( int i = 0 ; i < size ; i++ )
		CB_REG_PUT_CALLBACK( ct[i].name, ct[i].fp );
	return 0;
}
int CB_REG_PUT_CALLBACK( char *name, hashFuncEntryPtr ptr )
{
	callbackRegister *cr = callbackRegister::getInstance();
	if ( cr == 0 ) return -1;
	return cr->PutCallback( name, ptr );
}  
hashFuncEntryPtr  CB_REG_GET_CALLBACK( char *name )
{
	callbackRegister *cr = callbackRegister::getInstance();
	if ( cr == 0 ) return 0;
	return cr->GetCallback( name );
}  
void CB_REG_DUMP()
{
	callbackRegister *cr = callbackRegister::getInstance();
	if ( cr == 0 ) return ;
	std::cout << *cr << std::endl;
}
void CB_REG_PUT_INSTANCE()
{
	callbackRegister::putInstance();
}
