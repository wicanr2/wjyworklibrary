#ifndef HASH_ENTRY_HPP
#define HASH_ENTRY_HPP
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <iomanip>
#include <utils/debugClass.hpp>

#define HASH_ENTRY_NULL_NAME "null entry"

typedef enum HASH_ENTRY_TYPE { 
	HASH_ENTRY_TYPE_GBOOLEAN,
	HASH_ENTRY_TYPE_GINT,
	HASH_ENTRY_TYPE_GSTR,
	HASH_ENTRY_TYPE_GINT64,
	
	HASH_ENTRY_TYPE_GST_TIMEOUT,
	HASH_ENTRY_TYPE_GUINT64,
	HASH_ENTRY_TYPE_GULONG,
	
	HASH_ENTRY_TYPE_GUINT,
	HASH_ENTRY_TYPE_GFLOAT,
	HASH_ENTRY_TYPE_INT,
	HASH_ENTRY_TYPE_UINT,
	HASH_ENTRY_TYPE_CSTR,
	HASH_ENTRY_TYPE_GDOUBLE,
	HASH_ENTRY_TYPE_BOOL,
	HASH_ENTRY_TYPE_NULL
}hashEntryType;

class hashEntry:public debugClass {
private:
	char name[255];
	hashEntryType type;
	void *ptr;

public:
	hashEntry();
	~hashEntry();
	
	// setter
	int SetName(char *n);
	int SetType(hashEntryType t);
	int SetPtr( void *p ); 			
	// getter	
	
	char* GetName();
	hashEntryType
		  GetType();
	void* GetPtr();  	
	
	std::ostream& Dump(std::ostream& out)const;
	
	friend std::ostream& operator<< 
		(std::ostream &out, hashEntry& rhs) 
	{
		if ( rhs.GetDebugFlagLevel4() ) 
			rhs.Dump(out);
		return out;
	}
};
#endif
