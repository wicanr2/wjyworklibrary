#include <xmlConfig/attributesPool.hpp> 
int attributesPool::GetSize() {
	if ( list == 0 ) return -1;
	return list->GetUsedPoolSize();
}
int attributesPool::GetMaxSize() {
	if ( list == 0 ) return -1;
	return list->GetMaxPoolSize();
}
Attributes* attributesPool::GetItem(int i){
	if ( list == 0 ) return 0;
	return (*list)[i];
}
Attributes* attributesPool::GetItemByName(char *name){
	int i = 0;
	Attributes *etmp = 0;
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
