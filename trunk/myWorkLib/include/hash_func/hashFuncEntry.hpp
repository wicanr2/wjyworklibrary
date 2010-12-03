#ifndef HASH_FUNC_ENTRY_HPP
#define HASH_FUNC_ENTRY_HPP
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <iomanip>
#include <utils/debugClass.hpp>
#include <macro/macroVariableAccess.hpp>
#include <hash_func/hashFuncType.h>
#include <macro/macroLoggerAid.hpp>
#define HASH_FUNC_ENTRY_NULL_NAME "NULL_FunctionPointer"


class hashFuncEntry:public debugClass {
private:
	MACRO_VAR_STR_DECL_FULL(Name, name);
	MACRO_VAR_DECL_FULL (hashFuncEntryPtr, FuncPtr, funcPtr );
	
public:
	hashFuncEntry();
	~hashFuncEntry();
	
	std::ostream& Dump(std::ostream& out)const;
	
	friend std::ostream& operator<< 
		(std::ostream &out, hashFuncEntry& rhs) 
	{
		if ( rhs.GetDebugFlagLevel4() ) 
			rhs.Dump(out);
		return out;
	}
};
#endif
