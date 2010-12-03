#include <hash/hashTable.hpp>

int	hashTable::PutValue( 
		char *name, 
		hashEntryType type,
		void *ptr) 
{
	if ( this->hashStr == 0 ) return -1;
	if ( name == 0 ) return -1;
	if ( ptr == 0  ) return -1;
	int r = 0;
	hashEntry *he = new hashEntry();
	he->SetName( name );
	he->SetType( type );
	he->SetPtr ( ptr ) ;
	r = this->hashStr->PutValue ( name , he );
	if ( r < 0 ) { 
		delete he ;
		return -1 ;
	}
	return 0;
}
void* hashTable::GetPtr( char *name ){
	if ( this->hashStr == 0 ) return 0;
	hashEntry *tmp = 
		this->hashStr->GetValue(name);
	if ( tmp == 0 ) return 0;
	return tmp->GetPtr();
}
hashEntry* hashTable::GetValue( char *name ) {
	if ( this->hashStr == 0 ) return 0; 
	if ( name == 0 ) return 0;
	return this->hashStr->GetValue(name);
	
}
