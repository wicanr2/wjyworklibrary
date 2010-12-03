#include <callbackRegister/callbackRegister.hpp>

callbackRegister* callbackRegister::instance = NULL;
staticMutexLocker callbackRegister::sMutex;

callbackRegister::callbackRegister():hft(0)
{
	MACRO_DEBUG_CLASS_PRINT_L4("Init\tcallbackRegister\n");
	hft = new hashFuncTable();  
}
callbackRegister::~callbackRegister()
{
	MACRO_DEBUG_CLASS_PRINT_L4("Destory\tcallbackRegister\n");
	if ( this->hft != NULL ) delete hft;
}
std::ostream& callbackRegister::Dump(std::ostream& out)const
{
	MACRO_LOGGER_CHECK_VAR( out, this->hft );
	MACRO_LOGGER_PRINT_VAR_DIRECTLY( out, *this->hft);
	return out;
} 
// singleton
callbackRegister* callbackRegister::getInstance() {
	staticMutexLocker::Lock( &callbackRegister::sMutex );
	#if 0 // "broken" optimization
	if ( !_instance )
	#else
	if ( true )
	#endif
	{
		if ( !instance ) {
			instance = new callbackRegister();
		}
	}
	staticMutexLocker::Unlock( &callbackRegister::sMutex );
	return instance;
}
void callbackRegister::putInstance() {
	
	staticMutexLocker::Lock( &callbackRegister::sMutex );
	if ( instance ) {
		delete callbackRegister::instance;
		callbackRegister::instance = NULL;
	}
	staticMutexLocker::Unlock( &callbackRegister::sMutex );
	
}
