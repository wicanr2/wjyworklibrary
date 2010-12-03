#include <admissionControl/rule/ruleManager.hpp>
ruleManager* ruleManager::instance = NULL;
staticMutexLocker ruleManager::sMutex;

ruleManager::ruleManager():
	list(0)
{
	MACRO_DEBUG_CLASS_PRINT_L4("Init\truleManager\n");
	list = new ruleList();
	int size = XML_CONSTANT_MAX_ADAPTIVE_RULE_LIST_SIZE ;
	list->SetMaxPoolSize( size );
	this->InitRuleList();
}
ruleManager::~ruleManager()
{
	MACRO_DEBUG_CLASS_PRINT_L4("Destory\truleManager\n");
	if ( this->list != NULL ) delete this->list;
}
std::ostream& ruleManager::Dump(std::ostream& out)const
{
	MACRO_LOGGER_CHECK_VAR( out, this->list );
	out<<"   Rule List:"<<std::endl;
	if ( this->list->GetUsedPoolSize() > 0 ) {
		list->DumpOut(out);
	} else {
		out << "    No Rule" << std::endl;
	}

	return out;
} 
// singleton
ruleManager* ruleManager::getInstance() {
	staticMutexLocker::Lock( &ruleManager::sMutex );
	#if 0 // "broken" optimization
	if ( !_instance )
	#else
	if ( true )
	#endif
	{
		if ( !instance ) {
			instance = new ruleManager();
		}
	}
	staticMutexLocker::Unlock( &ruleManager::sMutex );
	return instance;
}
void ruleManager::putInstance() {
	
	staticMutexLocker::Lock( &ruleManager::sMutex );
	if ( instance ) {
		delete ruleManager::instance;
		ruleManager::instance = NULL;
	}
	staticMutexLocker::Unlock( &ruleManager::sMutex );
	
}
