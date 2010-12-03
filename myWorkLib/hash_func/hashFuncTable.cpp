#include <hash_func/hashFuncTable.hpp>

staticMutexLocker hashFuncTable::sMutex;
int hashFuncTable::hashPoolSize = 0;

int hashFuncTable::classInit(char *file)
{
	if ( file == 0 ) return -1;
	staticMutexLocker::Lock( &hashFuncTable::sMutex );
	if ( hashFuncTable::hashPoolSize == 0 )
	{
		FILE *pFILE = fopen(file,"r");
		if ( pFILE ) {
			fscanf(pFILE,"%d",&hashFuncTable::hashPoolSize);
			printf("----- Set the hash table size to %d.        -----\n\n", hashFuncTable::hashPoolSize);
			fclose(pFILE);
		} else {	
			printf("----- Lacks the hash.cfg for hash function. -----\n");
			printf("----- Uses the default hash table size 587. -----\n\n");
			hashFuncTable::hashPoolSize = 587; // the minial magic number 587
		}
	}
	staticMutexLocker::Unlock( &hashFuncTable::sMutex );
	if ( hashFuncTable::hashPoolSize <= 0 ) return -1;
	this->hashFuncStr = new hashString<hashFuncEntry>(hashFuncTable::hashPoolSize);
	return 0;
}
hashFuncTable::hashFuncTable():
	hashFuncStr(0)
{
	char file[] = HASH_FUNC_TABLE_CONFIGURATION_FILE; 
	this->classInit(file);	
}
hashFuncTable::hashFuncTable(char *file):
	hashFuncStr(0)
{
	this->classInit(file);	
}
hashFuncTable::~hashFuncTable(){
	if ( hashFuncStr != 0 )
		delete hashFuncStr;
}
std::ostream& hashFuncTable::Dump(std::ostream& out)const {
	MACRO_LOGGER_CHECK_VAR( out, this->hashFuncStr );
	
	MACRO_LOGGER_PRINT_SUBDIVIDE_LINE_2(out);

	MACRO_LOGGER_PRINT_VAR_DIRECTLY(out, *this->hashFuncStr ); 
	
	MACRO_LOGGER_PRINT_SUBDIVIDE_LINE_2(out);
	return out;
}
