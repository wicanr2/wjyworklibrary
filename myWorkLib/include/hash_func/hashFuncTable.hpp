#ifndef HASH_FUNC_TABLE_HPP
#define HASH_FUNC_TABLE_HPP
#include <hash/hashString.hpp>
#include <hash_func/hashFuncEntry.hpp>
#include <utils/debugClass.hpp> 
#include <utils/staticMutexLocker.hpp>
#include <macro/macroErrorCheck.hpp>
#include <macro/macroHashFuncTableAid.hpp>
#include <macro/macroLoggerAid.hpp>
#define HASH_FUNC_TABLE_CONFIGURATION_FILE "config/hash.cfg"

class hashFuncTable:public debugClass {
private:
	hashString<hashFuncEntry> *hashFuncStr;
	static int hashPoolSize; 
	static staticMutexLocker sMutex;
	int classInit(char *file);
public:
	hashFuncTable();
	hashFuncTable(char *file);
	~hashFuncTable();
	int	PutValue( char *name, hashFuncEntryPtr  ptr);
	hashFuncEntry*    GetValue( char *name );
	hashFuncEntryPtr  GetPtr  ( char *name );
	
	std::ostream& Dump(std::ostream& out)const; 
	
	friend std::ostream& operator<< 
		(std::ostream &out, hashFuncTable& rhs) 
	{
		if ( rhs.GetDebugFlagLevel4() ) 
			rhs.Dump(out);
		return out;
	}
};
#endif
