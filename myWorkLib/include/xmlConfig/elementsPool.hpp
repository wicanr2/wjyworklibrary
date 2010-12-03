
#ifndef XML_ELEMENT_POOL_HPP
#define XML_ELEMENT_POOL_HPP
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <list/fastLinkedList.hpp>
#include <xmlConfig/elements.hpp> 
#include <xmlConfig/constant.hpp>
#include <utils/smartPointer.hpp>

typedef fastLinkedList<XC_xmlElement> XC_xmlElementList;

class XC_xmlElementsPool:public debugClass {
private:
	XC_xmlElementList* list;

public:
	XC_xmlElementsPool();
	~XC_xmlElementsPool();
	
	// action
	int Append(XC_xmlElement *element);
	int AppendSmartPtr( smartPtr<XC_xmlElement> *sp );
	int Remove(int i);
	int RemoveTail();
	int RemoveAll();
	
	// GetSize
	int GetSize();
	int GetMaxSize();
	XC_xmlElement* GetItem(int i);
	XC_xmlElement* GetItemByName(char *name);
	XC_xmlElementsPool* GetItemPool(char *v); 	
	// dump
	void Dump();
	// this function is be called by another 
	void DumpOut( std::ostream &out );
	
	//debug 
	void EnableDebug() ;
	void DisableDebug() ;
};
#endif
