#ifndef XML_ELEMENT_ATTRIBUTES_HPP
#define XML_ELEMENT_ATTRIBUTES_HPP
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <utils/debugClass.hpp>
#include <xmlConfig/constant.hpp>
class Attributes:public debugClass {
private:
	char name[ XML_CONSTANT_MAX_NAME_LENGTH ];
	char value[ XML_CONSTANT_MAX_VALUE_LENGTH ]; 
public:
	Attributes() {
		{
			char none[] = "none";
			this->SetName(none);
			this->SetValue(none);
		}
	}
	Attributes(char* n, char *v) {
		{
			this->SetName(n);
			this->SetValue(v);
		}
	}
	~Attributes() {
		MACRO_DEBUG_CLASS_PRINT_L6("Destory\tAttributes\n");
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
	// dump 
	friend std::ostream& operator<< ( std::ostream &out, 
			Attributes &rhs )
	{
		if ( rhs.GetDebugFlagLevel4() != true ) return out;
		out << rhs.name <<" ("<<rhs.value<<")" ;
		return out;
	}
};
#endif
