#include <xmlConfig/attributesPool.hpp> 

attributesPool::attributesPool():
	list(0)
{
	{
		list = new attributesList();
		int size = XML_CONSTANT_MAX_ATTRIBUTES_SIZE;
		list->SetMaxPoolSize( size );
	}
}
attributesPool::~attributesPool() {
	if ( list != 0 ) {
		MACRO_DEBUG_CLASS_PRINT_L5("Destory\tAttributes Pool\n");
		delete list;
	}
}

void attributesPool::Dump(){
	MACRO_DEBUG_CLASS_PRINT_L5("Dump\tAttributes Pool\n");
	if ( list != 0 ) {
		list->Dump();
	}
}
void attributesPool::DumpOut( std::ostream &out ) {
	if ( list != 0 ) {
		out<<"   Attributes List:"<<std::endl;
		if ( this->list->GetUsedPoolSize() > 0 ) {
			list->DumpOut(out);
		} else {
			out << "    No Attributes " << std::endl;
		}
		
	}
}
void attributesPool::EnableDebug() {
	if ( list ) list->EnableDebug();
	debugClass::EnableDebug();
}
void attributesPool::DisableDebug() {
	if ( list ) list->DisableDebug();
	debugClass::DisableDebug();
}
