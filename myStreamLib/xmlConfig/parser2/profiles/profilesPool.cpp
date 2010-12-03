#include <xmlConfig/xmlProfilesPool.hpp> 

xmlProfilesPool::xmlProfilesPool():
	list(0)
{
	{
		list = new xmlProfileList();
		int size = XML_CONSTANT_MAX_PROFILES_SIZE ;
		list->SetMaxPoolSize( size );
	}
}
xmlProfilesPool::~xmlProfilesPool() {
	if ( list != 0 ) {
		MACRO_DEBUG_CLASS_PRINT_L5("Destory\tProfiles Pool\n");
		delete list;
	}
}

void xmlProfilesPool::Dump(){
	MACRO_DEBUG_CLASS_PRINT_L5("Dump\tProfiles Pool\n");
	if ( list != 0 ) {
		if ( this->GetDebugFlagLevel4() )
			list->Dump();
	}
}
void xmlProfilesPool::DumpOut( std::ostream &out ) {
	if ( list != 0 ) {
		out<<"   Profiles List:"<<std::endl;
		if ( this->list->GetUsedPoolSize() > 0 ) {
			list->DumpOut(out);
		} else {
			out << "    No Profiles " << std::endl;
		}
		
	}
}

void xmlProfilesPool::EnableDebug() {
	if ( list ) list->EnableDebug();
	debugClass::EnableDebug();
}
void xmlProfilesPool::DisableDebug() {
	if ( list ) list->DisableDebug();
	debugClass::DisableDebug();
}
