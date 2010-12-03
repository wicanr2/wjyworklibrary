#include <hash_func/hashFuncTable.hpp>

int	hashFuncTable::PutValue( char *name, hashFuncEntryPtr ptr) 
{
	MACRO_ERROR_CHECK_0_WITH_DEBUG ( this->hashFuncStr );
	MACRO_ERROR_CHECK_0_WITH_DEBUG ( name );
	MACRO_ERROR_CHECK_0_WITH_DEBUG ( ptr  );

	int r = 0;
	hashFuncEntry *he = new hashFuncEntry();
	he->SetName( name );
	he->SetFuncPtr( ptr ) ;

	r = this->hashFuncStr->PutValue ( name , he );
	if ( r < 0 ) { 
		delete he ;
		return -1 ;
	}
	return 0;
}
hashFuncEntryPtr hashFuncTable::GetPtr( char *name ){
	MACRO_ERROR_CHECK_0_RV0_WITH_DEBUG ( this->hashFuncStr );
	MACRO_ERROR_CHECK_0_RV0_WITH_DEBUG ( name );

	hashFuncEntry *tmp = this->hashFuncStr->GetValue(name);

	MACRO_ERROR_CHECK_0_RV0_WITH_DEBUG ( tmp );
	
	return tmp->GetFuncPtr();
}
hashFuncEntry* hashFuncTable::GetValue( char *name ) {
	MACRO_ERROR_CHECK_0_RV0_WITH_DEBUG ( this->hashFuncStr );
	MACRO_ERROR_CHECK_0_RV0_WITH_DEBUG ( name );

	return this->hashFuncStr->GetValue(name);
	
}
