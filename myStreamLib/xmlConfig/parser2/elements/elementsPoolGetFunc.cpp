#include <xmlConfig/elementsPool.hpp> 
int XC_xmlElementsPool::GetSize() {
	if ( list == 0 ) return -1;
	return list->GetUsedPoolSize();
}
int XC_xmlElementsPool::GetMaxSize() {
	if ( list == 0 ) return -1;
	return list->GetMaxPoolSize();
}
XC_xmlElement* XC_xmlElementsPool::GetItem(int i){
	if ( list == 0 ) return 0;
	return (*list)[i];
}

XC_xmlElement* XC_xmlElementsPool::GetItemByName(char *name){
	int i = 0;
	XC_xmlElement *etmp = 0;
	int maxSize = XML_CONSTANT_MAX_NAME_LENGTH;
	if ( name == 0 ) return 0;
	for ( i = 0 ; i < this->GetSize() ; i++ ) {
		etmp = this->GetItem(i);
		if ( strncmp ( name, etmp->GetName() , maxSize ) == 0 ) 
		{
			return etmp;
		}
	}
	return 0;
}
XC_xmlElementsPool* XC_xmlElementsPool::GetItemPool(char *v) {
	int i = 0;
	int x = 0;
	if ( v == 0 ) return 0;
	XC_xmlElementsPool *tmpPool = new XC_xmlElementsPool;	
	XC_xmlElement *etmp = 0;
	x = XML_CONSTANT_MAX_NAME_LENGTH;
	for ( i = 0 ; i < this->GetSize() ; i++ ) {
		etmp = this->GetItem(i);
		//printf(" etmp->GetName() = %s\n", etmp->GetName() );
		if ( strncmp( v, etmp->GetName(), x ) == 0 ) {
			tmpPool->AppendSmartPtr ( 
				this->list->GetSmartPtr(i)  
			);
		}
	}
	return tmpPool;
} 	
