#include <callbackRegister/callbackRegister.hpp>
int callbackRegister::PutCallback
		( char* name, hashFuncEntryPtr ptr)
{
	MACRO_DEBUG_CLASS_PRINT_L2("Call \tcallbackRegister::PutCallback()\n");
	MACRO_ERROR_CHECK_0_WITH_DEBUG( this->hft );
	MACRO_ERROR_CHECK_0_WITH_DEBUG( name );
	MACRO_ERROR_CHECK_0_WITH_DEBUG( ptr  );
	MACRO_HASH_FUNC_TABLE_PUT_VALUE( this->hft, name, ptr );
	return 0;
}			
hashFuncEntryPtr  callbackRegister::GetCallback
		( char *name )
{
	MACRO_DEBUG_CLASS_PRINT_L2("Call \tcallbackRegister::GetCallback()\n");
	hashFuncEntryPtr p = 0; 
	MACRO_ERROR_CHECK_0_RV0_WITH_DEBUG( this->hft );
	MACRO_ERROR_CHECK_0_RV0_WITH_DEBUG( name );
	MACRO_HASH_FUNC_TABLE_GET_PTR( this->hft, name, p );
	MACRO_ERROR_CHECK_0_RV0_WITH_DEBUG( p );
	return p;	
}
