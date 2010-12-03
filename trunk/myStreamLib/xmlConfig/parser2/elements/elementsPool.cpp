#include <xmlConfig/elementsPool.hpp> 

XC_xmlElementsPool::XC_xmlElementsPool():
	list(0)
{
	{
		list = new XC_xmlElementList();
		int size = XML_CONSTANT_MAX_ELEMENTS_SIZE;
		list->SetMaxPoolSize( size );
	}
}
XC_xmlElementsPool::~XC_xmlElementsPool() {
	if ( list != 0 ) {
		MACRO_DEBUG_CLASS_PRINT_L5("Destory\tElements Pool\n");
		delete list;
	}
}

void XC_xmlElementsPool::Dump(){
	MACRO_DEBUG_CLASS_PRINT_L5("Dump\tElements Pool\n");
	if ( list != 0 ) {
		list->Dump();
	}
}
void XC_xmlElementsPool::DumpOut( std::ostream &out ) {
	if ( list != 0 ) {
		out<<"   Elements List:"<<std::endl;
		if ( this->list->GetUsedPoolSize() > 0 ) {
			list->DumpOut(out);
		} else {
			out << "    No Elements " << std::endl;
		}
		
	}
}

void XC_xmlElementsPool::EnableDebug() {
	if ( list ) list->EnableDebug();
	debugClass::EnableDebug();
}
void XC_xmlElementsPool::DisableDebug() {
	if ( list ) list->DisableDebug();
	debugClass::DisableDebug();
}
