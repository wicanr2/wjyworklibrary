/*
	Video Stream XML configuration reader
*/
#ifndef XMLCONFIG_H
#define XMLCONFIG_H
#include <libxml/xmlreader.h>
#include <glib.h>
#include "vc_debug.h"
#ifdef __cplusplus
#include <iostream>
#include <string>
#include <map>

#include <cstdlib>
#include <cstring>

using namespace std;
#endif
/*
 * XML Property Type Enum
 * */
typedef enum __XMLPropTypeEnum { INT, CSTR, 
G_BOOL, G_STR, G_INT64, G_UINT, G_INT, G_FLOAT , G_DOUBLE, LAST } XMLPropTypeEnum;

/*
 * XML Property Type Pool
 * */
typedef struct __TypePool {
	char *element;
	char *attr;
	char *pad;
	XMLPropTypeEnum type;
	void *ptr;
}TypePool;




//--------------------------------------------------------
#ifdef __cplusplus

class _XMLConfig;
class _XMLParser;

/* mapXMLConfig for convinent access class _XMLConfig */
typedef map< string, _XMLConfig* > mapXMLConfig;


/* class definition area */
/* _XMLConfig for containing the each profile */ 
class _XMLConfig {
	private:
		int 	 _no; // govern by xml register
		char  	 _name[255];
		char 	 _path[255];
		TypePool *_tP;
		int		 _tpSz ;


		TypePool* findType(const char* e, const char* attr);
		void Parse(xmlTextReaderPtr reader);
		
		void CountTypePool();
	public:
		_XMLConfig(int no, char *n, char* p, TypePool *tP);
		void RunParse(xmlTextReaderPtr reader);
		char* GetPath();
		int GetProp(const char* e, const char* attr, void *value);
		XMLPropTypeEnum GetPropType(const char* e, const char* attr);
		
};
/* _XMLParser as the _XMLConfig collector
 * for gathering the _XMLConfig in only one place */
class _XMLParser {
	private:
		mapXMLConfig mapTest;
	public:
		_XMLParser();
		~_XMLParser();
		void PutConf(char *name, char* path, TypePool *tP);
		void ParserConf(char *name);
		int GetProp(const char*name, const char* e, const char* attr, void *value);
		XMLPropTypeEnum GetPropType(const char*name, const char* e, const char* attr);
};
#else
typedef struct _XMLParser XMLParser;
#endif
//--------------------------------------------------------
/*
 * the extern function for c accessing XMLParser
 * */
#ifdef __cplusplus
extern "C" {
#endif
	void __XMLParserInit();
	void __XMLParserDeInit();
	void __PufConf(char *name,char* path, TypePool *tP);
	void __ParserConf(char *name);
	int __GetProp(const char*name, const char* e, const char* attr, void *value);
	XMLPropTypeEnum __GetPropType(const char*name, const char* e, const char* attr);
	void __XMLRegister(char* name,char *path, TypePool *tp);
	
#ifdef __cplusplus
}
#endif

#endif
