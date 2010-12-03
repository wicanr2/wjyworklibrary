#ifndef MACRO_HASH_FUNC_TABLE_AID_HPP
#define MACRO_HASH_FUNC_TABLE_AID_HPP

#define MACRO_HASH_FUNC_TABLE_PUT_VALUE(hashTable, _name, _value)\
	do{\
		char vName[255];\
		snprintf( vName, 255, "%s", _name );\
		hashTable->PutValue( vName, _value );\
	}while(0)

#define MACRO_HASH_FUNC_TABLE_GET_PTR(hashTable,_name,ptr)\
	do {\
		char vName[255];\
		snprintf( vName, 255, "%s", _name );\
		ptr = hashTable->GetPtr(vName);\
	}while(0)

#endif 
