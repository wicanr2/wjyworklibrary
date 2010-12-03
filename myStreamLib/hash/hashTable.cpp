#include <hash/hashTable.hpp>

staticMutexLocker hashTable::sMutex;
int hashTable::hashPoolSize = 0;

int hashTable::classInit(char *file)
{
	if ( file == 0 ) return -1;
	staticMutexLocker::Lock( &hashTable::sMutex );
	if ( hashTable::hashPoolSize == 0 )
	{
		FILE *pFILE = fopen(file,"r");
		if ( pFILE ) {
			fscanf(pFILE,"%d",&hashTable::hashPoolSize);
			printf("----- Set the hash table size to %d.        -----\n\n", hashTable::hashPoolSize);
			fclose(pFILE);
		} else {	
			printf("----- Lacks the hash.cfg for hash function. -----\n");
			printf("----- Uses the default hash table size 587. -----\n\n");
			hashTable::hashPoolSize = 587; // the minial magic number 587
		}
	}
	staticMutexLocker::Unlock( &hashTable::sMutex );
	if ( hashTable::hashPoolSize <= 0 ) return -1;
	this->hashStr = new hashString<hashEntry>(hashTable::hashPoolSize);
	return 0;
}
hashTable::hashTable():
	hashStr(0)
{
	char file[] = HASH_TABLE_CONFIGURATION_FILE; 
	this->classInit(file);	
}
hashTable::hashTable(char *file):
	hashStr(0)
{
	this->classInit(file);	
}
hashTable::~hashTable(){
	if ( hashStr != 0 )
		delete hashStr;
}
std::ostream& hashTable::Dump(std::ostream& out)const {
	out << std::endl;
	for ( int i = 0 ; i < 80 ; i ++ ) {
		out << "~" ;
	}
	out << std::endl;
	out << *this->hashStr;
	for ( int i = 0 ; i < 80 ; i ++ ) {
		out << "~" ;
	}
	out << std::endl;
}
