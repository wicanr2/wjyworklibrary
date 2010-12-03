#ifndef HASH_TABLE_HPP
#define HASH_TABLE_HPP
#include <hash/hashString.hpp>
#include <hash/hashEntry.hpp>
#include <utils/debugClass.hpp> 
#include <utils/staticMutexLocker.hpp>

#define HASH_TABLE_CONFIGURATION_FILE "config/hash.cfg"

class hashTable:public debugClass {
private:
	hashString<hashEntry> *hashStr;
	static int hashPoolSize; 
	static staticMutexLocker sMutex;
	int classInit(char *file);
public:
	hashTable();
	hashTable(char *file);
	~hashTable();
	int	PutValue( 
		char *name, 
		hashEntryType type,
		void *ptr);
	hashEntry *GetValue( char *name );
	void* GetPtr( char *name );
	
	std::ostream& Dump(std::ostream& out)const; 
	
	friend std::ostream& operator<< 
		(std::ostream &out, hashTable& rhs) 
	{
		if ( rhs.GetDebugFlagLevel4() ) 
			rhs.Dump(out);
		return out;
	}
};
#endif
