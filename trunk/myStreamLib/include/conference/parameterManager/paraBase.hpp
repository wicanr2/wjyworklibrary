#ifndef PARAMETER_BASE_HPP
#define PARAMETER_BASE_HPP
#include <cstdio>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <conference/constant.hpp>
#include <unistd.h>
#include <hash/hashTable.hpp>
#include <xmlConfig/constant.hpp>
#include <macro/macroVariableAccess.hpp>
#include <macro/macroParameterAid.hpp>
#include <utils/debugClass.hpp>


class paraBase:public debugClass {
protected:
	char belongStream[255];
	char parameterName[255];
	char role[255];
	char xmlName[255];
	hashTable *hashMappingTable;		
public:
	paraBase():
		hashMappingTable(0)
	{
		char _n[] = PARAMETER_NULL_NAME;
		this->SetParameterName( _n );
		this->SetBelongStream ( _n );
		this->SetRole         ( _n );
		this->SetXMLName      ( _n );
		this->hashMappingTable = new hashTable();
	}
	virtual ~paraBase() {
		MACRO_DEBUG_CLASS_PRINT_L6("Destory\t%s\n",this->GetParameterName());
		if ( this->hashMappingTable != 0 ) {
			delete this->hashMappingTable; 
		}
	}
	// hash utility functions
	int PutValue( char *name, hashEntryType type, void *ptr) {
		if ( this->hashMappingTable == 0 ) return -1;
		return this->hashMappingTable->PutValue( name, type, ptr );
	}
	// setter
	int SetBelongStream(char *name) {
		if ( name == 0 ) return -1;
		snprintf( this->belongStream, 255, "%s", name );
		
		return 0;
	}
	int SetParameterName(char *name) {
		if ( name == 0 ) return -1;
		snprintf( this->parameterName, 255, "%s", name );
		return 0;
	}
	int SetRole(char *name) {
		if ( name == 0 ) return -1;
		snprintf( this->role, 255, "%s", name );
		return 0;
	}
	int SetXMLName(char *name) {
		if ( name == 0 ) return -1;
		snprintf( this->xmlName, 255, "%s", name );
		return 0;
	}
	// getter
	char *GetBelongStream() {
		return this->belongStream;
	}
	char *GetParameterName() {
		return this->parameterName;
	}
	char *GetRole(){
		return this->role;
	}
	hashTable *GetHashTable() {
		return this->hashMappingTable;
	}
	char *GetXMLName() {
		return this->xmlName;
	}
	virtual std::ostream& Dump(std::ostream& out)const {
		out << "Parameter :" << this->parameterName ;
		out << std::endl;
		out << "Role      :" << this->role ;
		out << std::endl;
		out << "Belong    :" << this->belongStream ;
		out << std::endl;
		out << "XML Name  :" << this->xmlName ;
		out << std::endl;
		out << "hashTBL   :" << this->hashMappingTable;
		out << std::endl;
		out << "*hashTBL  :" << *this->hashMappingTable;
		return out;
	}
	friend std::ostream& operator<< 
		(std::ostream &out, paraBase &rhs) 
	{
		if ( rhs.GetDebugFlag() ) 
			rhs.Dump(out);
		return out;
		
	}
};
#endif
