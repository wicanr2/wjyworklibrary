#ifndef XML_CONFIG_2_HPP
#define XML_CONFIG_2_HPP

#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <iostream>
#include <iomanip>
#include <string>

// external library
#include <libxml/xmlreader.h>
#include <glib.h>

#include <utils/debugClass.hpp>
#include <utils/staticMutexLocker.hpp>
#include <utils/mutexLocker.hpp>
#include <xmlConfig/constant.hpp>
#include <xmlConfig/xmlProfilesPool.hpp> 
#include <utils/directorySubsidiary.h>

#ifdef XML2_CONFIGURATOR_STREAM_HAHS_MAPPING	
#include <conference/parameterManager/paraBase.hpp>
#endif
#include <hash/hashTable.hpp>

// the xml configurator 2
class baseStream;
class XMLConfigurator2:public debugClass {
private:
	xmlProfilesPool *profilePool;
	XC_xmlElementsPool *currentElementsPool;
	int poolPtr ;
	// single instance
	static XMLConfigurator2* instance;
	// static mutex
	static staticMutexLocker sMutex;
	// mutex locker
	mutexLocker ML;
	
	int DoParseElement (
		xmlProfile *profile,
		xmlTextReaderPtr reader);
		
	int DoParseAttributes (
		XC_xmlElement *element,
		xmlTextReaderPtr reader);
	int PutHashValue( 
		hashEntry *he, 
		Attributes *attr);	
public:
	XMLConfigurator2();
	~XMLConfigurator2();
	static XMLConfigurator2* 
		getInstance();
	static void 
		putInstance();
	// init
	
	// parse action
	int AddProfile(char *name, char *location);
	int ParseProfile(char *name);
	int ParseAllProfile();
	
	int GetElements(char *profile, char *element);
	
	int GetNextElement();
	int GetElementsI( int i );
	const char* GetElementName();
	const char* GetElementValue();
	const char* GetElementAttributeValue( char *attr );
	attributesPool *GetElementAttributesPool();
	//In the specifiy profile, this function gets the first element of the elemenet pool. 
	const char* GetElementName(char *profile, char *element);
	const char* GetElementValue(char *profile, char *element);
	const char* GetElementAttributeValue(char *profile, char *element, char *attr );
#ifdef XML2_CONFIGURATOR_STREAM_HAHS_MAPPING	
	// parameter hashing mapping utility
	int HashMappingParams(char *profile, paraBase *param);
	int HashMappingStream(char *profile, baseStream *stream);
#endif
	// enable debug and dump
	void EnableDebug();
	void DisableDebug();
	void Dump();
};
#endif
