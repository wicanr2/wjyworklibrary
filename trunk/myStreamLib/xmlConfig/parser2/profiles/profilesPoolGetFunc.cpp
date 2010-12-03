#include <xmlConfig/xmlProfilesPool.hpp> 
int xmlProfilesPool::GetSize() {
	if ( list == 0 ) return -1;
	return list->GetUsedPoolSize();
}
int xmlProfilesPool::GetMaxSize() {
	if ( list == 0 ) return -1;
	return list->GetMaxPoolSize();
}
xmlProfile* xmlProfilesPool::GetItem(int i){
	if ( list == 0 ) return 0;
	return (*list)[i];
}

xmlProfile* xmlProfilesPool::GetItemByName(char *name) {
	int i = 0;
	xmlProfile *etmp = 0;
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

xmlProfilesPool* 
xmlProfilesPool::GetItemPoolContain(char *v) {
	int i = 0;
	int x = 0;
	if ( v == 0 ) return 0;
	xmlProfilesPool *tmpPool = new xmlProfilesPool;	
	xmlProfile *etmp = 0;
	x = XML_CONSTANT_MAX_NAME_LENGTH;
	for ( i = 0 ; i < this->GetSize() ; i++ ) {
		etmp = this->GetItem(i);
		//printf(" etmp->GetName() = %s\n", etmp->GetName() );
		if ( strstr( etmp->GetName(), v  ) != 0 ) {
			//printf(" strstr( v, etmp->GetName() ) != 0\n" );
			tmpPool->AppendSmartPtr ( 
				this->list->GetSmartPtr(i)  
			);
		}
	}
	return tmpPool;
} 
