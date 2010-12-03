
#include <xmlConfig/xmlConfig2.hpp>

XMLConfigurator2* XMLConfigurator2::instance = NULL;
staticMutexLocker XMLConfigurator2::sMutex;

XMLConfigurator2::XMLConfigurator2():
	profilePool(0), currentElementsPool (0),
	poolPtr(0)
{
	MACRO_DEBUG_CLASS_PRINT_L4("Init\tXMLConfigurator2\n");
	profilePool = new xmlProfilesPool;
}

XMLConfigurator2::~XMLConfigurator2() {
	MACRO_DEBUG_CLASS_PRINT_L4("Destory\tXMLConfigurator2\n");
	if ( profilePool != 0 )
		delete profilePool;
	if ( this->currentElementsPool != 0 )
		delete this->currentElementsPool;
}

XMLConfigurator2* XMLConfigurator2::getInstance() {
	
	staticMutexLocker::Lock( &XMLConfigurator2::sMutex );
	#if 0 // "broken" optimization
	if ( !_instance )
	#else
	if ( true )
	#endif
	{
		if ( !instance ) {
			instance = new XMLConfigurator2();
		}
	}
	staticMutexLocker::Unlock( &XMLConfigurator2::sMutex );
	return instance;
}
void XMLConfigurator2::putInstance() {
	
	staticMutexLocker::Lock( &XMLConfigurator2::sMutex );
	if ( instance ) {
		delete XMLConfigurator2::instance;
		XMLConfigurator2::instance = NULL;
	}
	staticMutexLocker::Unlock( &XMLConfigurator2::sMutex );
	
}

