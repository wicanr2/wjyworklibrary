#include <xmlConfig/xmlConfig.h>

static _XMLParser* _gXMLParser = 0;
static int _gNumXMLConf = 0;

_XMLParser::_XMLParser(){
	
}
_XMLParser:: ~_XMLParser(){
	
}
/* Put XML Configuration */
void _XMLParser::PutConf(
	char *name, char* path,
	TypePool *tP){
	string xmlConfName(name);

	_XMLConfig 	*xmlConf =
		new _XMLConfig( _gNumXMLConf, name, path, tP );
	
	mapTest[xmlConfName] = xmlConf;

	_gNumXMLConf++;
}
/*
	Parse Con
 */
void _XMLParser::ParserConf(char *name) {
	xmlTextReaderPtr reader;
	int ret = 0;
	
	string xmlConfName(name);
	_XMLConfig *p = mapTest[xmlConfName];

	//reader = xmlNewTextReaderFilename( p->GetPath() );
	reader = xmlReaderForFile( p->GetPath(), NULL,
	 XML_PARSE_DTDLOAD | XML_PARSE_DTDVALID | XML_PARSE_DTDATTR );
	if (reader != NULL) {
        ret = xmlTextReaderRead( reader );
        while (ret == 1) {

            p->RunParse( reader );

            ret = xmlTextReaderRead( reader );
        }
        xmlFreeTextReader(reader);
        if (ret != 0) {
           // __VC_L1_DEBUG_PRINT("%s : failed to parse\n", filename);
        }
    } else {
        //__VC_L1_DEBUG_PRINT_NOARG("the reader is NULL\n");
    }
}
int _XMLParser::GetProp(
	const char *name, const char* e,
	const char* attr, void *value){
	string xmlConfName(name);
	
	_XMLConfig *p = mapTest[xmlConfName];
	if ( p != 0 ) {
		return p->GetProp(e, attr, value);
	}
	__VC_L2_DEBUG_PRINT("The XMLConfig %s is not existed\n", name );
	return -1;
}

XMLPropTypeEnum _XMLParser::GetPropType
(const char*name, const char* e, const char* attr) {
	string xmlConfName(name);
	_XMLConfig *p = mapTest[xmlConfName];
	// improve the reilabilty 
	if ( p != 0 ) {
		return p->GetPropType(e,attr);
	} 
	__VC_L2_DEBUG_PRINT("The XMLConfig %s is not existed\n", name );
	return LAST;
}
/* extern C method */
#ifdef __cplusplus
extern "C" {
#endif
	void __XMLParserInit() {
		if ( _gXMLParser == 0 )
			_gXMLParser = new _XMLParser();
	}
	void __XMLParserDeInit() {
		if ( _gXMLParser != 0 )
			delete _gXMLParser;
	}
	void __PufConf(char *name, char* path,
				   TypePool *tP) {
		if ( _gXMLParser != 0 ){
			_gXMLParser->PutConf( name, path, tP );
		}
	}
	void __ParserConf(char *name) {
		if ( _gXMLParser != 0 ){
			_gXMLParser->ParserConf(name);
		}
	}
	int __GetProp(
		const char*name, const char* e,
		const char* attr, void *value)
	{
		if ( _gXMLParser != 0 ) {
			return _gXMLParser->GetProp(name,e,attr,value);
		}
		return -1;
	}
	void __XMLRegister(char* name, char *path, TypePool *tp) {
		__XMLParserInit();
		__PufConf( name, path, tp);
		__ParserConf( name );
	}
	
	XMLPropTypeEnum __GetPropType(const char*name, const char* e, const char* attr) {
		if ( _gXMLParser != 0 ) {
			return _gXMLParser->GetPropType(name,e,attr);
		}
	}
#ifdef __cplusplus
}
#endif
