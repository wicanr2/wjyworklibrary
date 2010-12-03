#ifndef XML_CONFIG_2_CPP_API_HPP
#define XML_CONFIG_2_CPP_API_HPP

#ifdef __cplusplus
extern "C" {
#endif
int XCFG2_Init();

int XCFG2_AddProfile ( char *profileName, char *location );
int XCFG2_ParseProfile ( char *profileName );
int XCFG2_GetElements ( char *profileName, char *elements);
int XCFG2_GetNextElement();
int XCFG2_GetElementsI(int i);
const char* XCFG2_GetElementName();
const char* XCFG2_GetElementValue();
const char* XCFG2_GetElementAttribute( char *attr );

const char* XCFG2_GetElementName2(char *profile, char *element);
const char* XCFG2_GetElementValue2(char *profile, char *element);
const char* XCFG2_GetElementAttribute2( char* profile, char *element, char *attr);  

#ifdef XML2_CONFIGURATOR_STREAM_HAHS_MAPPING	
int XCFG2_HashMappingParams( char *profile, void *param );
int XCFG2_HashMappingStream( char *profile, void *stream );
#endif
void XCFG2_Dump();
void XCFG2_EnableDebug();
void XCFG2_DisableDebug();

void XCFG2_PutInstance();


#ifdef __cplusplus
}
#endif

#endif
