#ifndef XML_ELEMENT_HPP
#define XML_ELEMENT_HPP

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <list/fastLinkedList.hpp>
#include <utils/debugClass.hpp>
#include <xmlConfig/attributesPool.hpp> 
#include <xmlConfig/constant.hpp>

class XC_xmlElement:public debugClass {
private:
	attributesPool *attrPool ;
	int  level;
	int  poolLocation; // -1 = no used
	char name[XML_CONSTANT_MAX_NAME_LENGTH];
	char value[XML_CONSTANT_MAX_VALUE_LENGTH]; 
public:
	
	XC_xmlElement():
	attrPool(0), level(-1), poolLocation(-1)
	{
		{
			char none[] = "none";
			this->SetName(none);
			this->SetValue(none);
		}
		attrPool = new attributesPool; 
	}
	XC_xmlElement(char* n, char *v) {
		{
			this->SetName(n);
			this->SetValue(v);
		}
		attrPool = new attributesPool; 
	}
	~XC_xmlElement() {
		MACRO_DEBUG_CLASS_PRINT_L6("Destory\tXC_xmlElement\n");
		if ( attrPool != 0 )
			delete this->attrPool;
	}
	// setter
	int SetName(char *v) {
		if ( v==0 ) return -1;
		int nameLen = XML_CONSTANT_MAX_NAME_LENGTH ;
		strncpy( name  ,  v , nameLen );
		return 0;
	}
	int SetValue(char *v) {
		int valueLen = XML_CONSTANT_MAX_VALUE_LENGTH ; 
		if ( v==0 ) {
			char _v [] = XML_NO_VALUE;
			strncpy( value ,  _v , valueLen );
		} else {
			strncpy( value ,  v , valueLen );
		}
		return 0;
	}
	int SetElementLevel(int v) {
		if ( v < 0 ) return -1;
		level = v;
		return 0;
	}
	int SetPoolPosition(int v) {
		if ( v < 0 ) return -1;
		poolLocation = v;
		return 0;
	}
	// getter
	char *GetName() {
		return this->name;
	}

	char *GetValue() {
		return this->value;
	}
    int GetElementLevel() {
		return this->level;
	}
	int GetPoolPosition() {
		return this->poolLocation;
	}
	
	attributesPool* GetAttributesPool() {
		return this->attrPool;
	}
	// dump
	friend std::ostream& operator<< ( std::ostream &out, 
			XC_xmlElement &rhs )
	{
		if ( rhs.GetDebugFlagLevel4() != true ) return out;
		out << std::endl;
		{
			for ( int i = 0 ; i < 80 ; i++ ) {
				out << "_";
			}
			out <<std::endl;
		}
		out << "Element ";
		out << "Name : " << rhs.name;
		out << ", ";
		out << "Value: " << rhs.value;
		out <<std::endl;
		rhs.attrPool->DumpOut(out);
		{
			for ( int i = 0 ; i < 80 ; i++ ) {
				out << "_";
			}
			out <<std::endl;
		}
		
		return out;
	}
};

#endif
