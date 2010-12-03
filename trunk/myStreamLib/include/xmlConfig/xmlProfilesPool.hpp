#ifndef XML_PROFILES_POOL_HPP
#define XML_PROFILES_POOL_HPP
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <list/fastLinkedList.hpp>
#include <xmlConfig/xmlProfiles.hpp> 
#include <xmlConfig/constant.hpp>
#include <utils/smartPointer.hpp>
typedef fastLinkedList<xmlProfile> xmlProfileList;

class xmlProfilesPool:public debugClass {
private:
	xmlProfileList* list;

public:
	xmlProfilesPool();
	~xmlProfilesPool();
	
	// action
	int Append(xmlProfile *profile);
	int AppendSmartPtr( smartPtr<xmlProfile> *sp );
	int Remove(int i);
	int RemoveTail();
	int RemoveAll();
	
	// GetSize
	int GetSize();
	int GetMaxSize();
	xmlProfile* GetItem(int i);
	xmlProfile* GetItemByName(char *name);
	xmlProfilesPool* GetItemPoolContain(char *v);
	// dump
	void Dump();
	// this function is be called by another 
	void DumpOut( std::ostream &out );

	//debug 
	void EnableDebug() ;
	void DisableDebug() ;
};
#endif
