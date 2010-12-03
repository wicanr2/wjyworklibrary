#ifndef XML_ELEMENT_ATTRIBUTES_POOL_HPP
#define XML_ELEMENT_ATTRIBUTES_POOL_HPP
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <list/fastLinkedList.hpp>
#include <xmlConfig/attributes.hpp> 
#include <xmlConfig/constant.hpp>

typedef fastLinkedList<Attributes> attributesList;

class attributesPool:public debugClass {
private:
	attributesList *list;
public:
	attributesPool();
	~attributesPool();
	
	// action
	int Append(Attributes *item);
	int Remove(int i);
	int RemoveTail();
	int RemoveAll();
	
	// GetSize
	int GetSize();
	int GetMaxSize();
	Attributes* GetItem(int i);
	Attributes* GetItemByName(char *name);
	// dump
	void Dump();
	void DumpOut( std::ostream &out );
	
	//debug 
	void EnableDebug();
	void DisableDebug() ;
};
#endif
