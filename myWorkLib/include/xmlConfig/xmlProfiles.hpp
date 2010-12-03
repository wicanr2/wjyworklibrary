#ifndef XML_PROFILES_HPP
#define XML_RPOFILES_HPP
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <utils/debugClass.hpp>
#include <xmlConfig/elementsPool.hpp> 
#include <xmlConfig/constant.hpp>

class xmlProfile:public debugClass {
private:
	XC_xmlElementsPool* elementPool ;
	char name[XML_CONSTANT_MAX_NAME_LENGTH];
	char value[XML_CONSTANT_MAX_VALUE_LENGTH]; 
public:
	
	xmlProfile():elementPool(0) {
		{
			char none[] = "none";
			this->SetName(none);
			this->SetValue(none);
		}
		elementPool = new XC_xmlElementsPool ; 
	}
	xmlProfile(char* n, char *v) {
		{
			this->SetName(n);
			this->SetValue(v);
		}
		elementPool = new XC_xmlElementsPool ; 
	}
	~xmlProfile() {
		MACRO_DEBUG_CLASS_PRINT_L6("Destory\txmlProfile\n");
		if ( elementPool != 0 )
			delete this->elementPool;
	}
    	
	// setter
	int SetName(char *v) {
		if ( v==0 ) return -1;
		int nameLen = XML_CONSTANT_MAX_NAME_LENGTH ;
		strncpy( name  ,  v , nameLen );
	}
	int SetValue(char *v) {
		if ( v==0 ) return -1;
		int valueLen = XML_CONSTANT_MAX_VALUE_LENGTH ; 
		strncpy( value ,  v , valueLen );
	}
	// getter
	char *GetName() {
		return this->name;
	}

	char *GetValue() {
		return this->value;
	}

	XC_xmlElementsPool* GetElementsPool() {
		return this->elementPool;
	}
	// dump
	friend std::ostream& operator<< ( std::ostream &out, 
			xmlProfile &rhs )
	{
		if ( rhs.GetDebugFlagLevel4() != true ) return out;
		out << std::endl; 
		{
			for ( int i = 0 ; i < 80 ; i++ ) {
				out << "-";
			}
			out <<std::endl;
		}
		out << "\tProfile "; 
		out << std::endl;
		out << "Name     : " << rhs.name;
		out <<std::endl;
		out << "location : " << rhs.value;
		out <<std::endl;
		rhs.elementPool->DumpOut(out);
		{
			for ( int i = 0 ; i < 80 ; i++ ) {
				out << "_";
			}
			out <<std::endl;
		}
		out <<std::endl;
		return out;
	}
};

#endif
