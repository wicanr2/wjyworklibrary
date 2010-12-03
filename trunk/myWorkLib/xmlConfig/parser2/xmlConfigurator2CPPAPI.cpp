#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <xmlConfig/xmlConfig2.hpp>
#include <xmlConfig/xmlConfig2CPPAPI.hpp>

#ifdef XML2_CONFIGURATOR_STREAM_HAHS_MAPPING	
#include <baseStream/baseStream.hpp>
#endif

#include <utils/staticMutexLocker.hpp>
#ifdef __cplusplus
extern "C" {
#endif

int XCFG2_Init() {
	static staticMutexLocker staticLocker;
	static int inited = 0;
	int re = 0;
	int size = 0;
	int i = 0;
	char xmlboot[] = XML_SUMMARY_PROFILE_NAME;
	char xmlboot_location[] = XML_SUMMARY_PROFILE_LOCATION;
	char profile_element[] = XML_PROFILE_ELEMENT_NAME;          
	char profile_attr_name [] = XML_PROFILE_ELEMENT_ATTR_NAME ;    
	char profile_attr_location [] = XML_PROFILE_ELEMENT_ATTR_LOCATION; 
	char pName[255];
	char pLocation[255];
	staticMutexLocker::Lock( &staticLocker );
	if ( inited != 0 ) {
		printf(" XCFG2_Init() was been called before\n");
		staticMutexLocker::Unlock( &staticLocker );
		return -1;
	}
	re = XCFG2_AddProfile ( xmlboot, xmlboot_location ) ; 
	if ( re < 0 ) { 
		staticMutexLocker::Unlock( &staticLocker );
		return -1;
	}

	size = XCFG2_GetElements ( xmlboot, profile_element );
	if ( size < 0 ) {
		staticMutexLocker::Unlock( &staticLocker );
		return -1;
	}
	
	for ( i = 0 ; i < size ; i++ ) {	
		XCFG2_GetElementsI(i);
		snprintf(pName ,255 , "%s", XCFG2_GetElementAttribute( profile_attr_name ));
		snprintf(pLocation, 255, "%s", XCFG2_GetElementAttribute( profile_attr_location ));
		XCFG2_AddProfile ( pName , pLocation ) ; 
	}
	inited = 1;
	staticMutexLocker::Unlock( &staticLocker );
	return 0;
}
int XCFG2_AddProfile ( char *profileName, char *location ){
	XMLConfigurator2 *xcfg2 = XMLConfigurator2::getInstance(); 
	int r = 0;
	if ( xcfg2 == 0 ) return -1;
	r = xcfg2->AddProfile( profileName, location );
	if ( r < 0 ) return -1;
	xcfg2->ParseProfile( profileName );
	return 0;
}
int XCFG2_ParseProfile ( char *profileName ){
	XMLConfigurator2 *xcfg2 = XMLConfigurator2::getInstance(); 
	if ( xcfg2 == 0 ) return -1;
	xcfg2->ParseProfile( profileName );
	return 0;
}
int XCFG2_GetElements ( char *profileName, char *elements){
	XMLConfigurator2 *xcfg2 = XMLConfigurator2::getInstance(); 
	if ( xcfg2 == 0 ) return -1;
	return xcfg2->GetElements( profileName, elements );
}
int XCFG2_GetNextElement(){
	XMLConfigurator2 *xcfg2 = XMLConfigurator2::getInstance(); 
	if ( xcfg2 == 0 ) return -1;
	return xcfg2->GetNextElement();
}
int XCFG2_GetElementsI(int i){
	XMLConfigurator2 *xcfg2 = XMLConfigurator2::getInstance(); 
	if ( xcfg2 == 0 ) return -1;
	return xcfg2->GetElementsI(i);
}
const char* XCFG2_GetElementName(){
	XMLConfigurator2 *xcfg2 = XMLConfigurator2::getInstance(); 
	if ( xcfg2 == 0 ) return 0;
	return xcfg2->GetElementName();
}
const char* XCFG2_GetElementValue(){
	XMLConfigurator2 *xcfg2 = XMLConfigurator2::getInstance(); 
	if ( xcfg2 == 0 ) return 0;
	return xcfg2->GetElementValue();
}
const char* XCFG2_GetElementAttribute( char *attr ){
	XMLConfigurator2 *xcfg2 = XMLConfigurator2::getInstance(); 
	if ( xcfg2 == 0 ) return 0;
	return xcfg2->GetElementAttributeValue(attr);
}

const char* XCFG2_GetElementName2(char *profile, char *element){
	XMLConfigurator2 *xcfg2 = XMLConfigurator2::getInstance(); 
	if ( xcfg2 == 0 ) return 0;
	return xcfg2->GetElementName(profile, element);
}
const char* XCFG2_GetElementValue2(char *profile, char *element){
	XMLConfigurator2 *xcfg2 = XMLConfigurator2::getInstance(); 
	if ( xcfg2 == 0 ) return 0;
	return xcfg2->GetElementValue(profile, element);
}
const char* XCFG2_GetElementAttribute2( char* profile, char *element, char *attr){
	XMLConfigurator2 *xcfg2 = XMLConfigurator2::getInstance(); 
	if ( xcfg2 == 0 ) return 0;
	return xcfg2->GetElementAttributeValue(profile, element, attr);
}  

#ifdef XML2_CONFIGURATOR_STREAM_HAHS_MAPPING	
int XCFG2_HashMappingParams( char *profile, void *param ){
	XMLConfigurator2 *xcfg2 = XMLConfigurator2::getInstance(); 
	if ( xcfg2 == 0 ) return -1;
	return xcfg2->HashMappingParams(profile, (paraBase*) param);
}
int XCFG2_HashMappingStream( char *profile, void *stream ) {
	XMLConfigurator2 *xcfg2 = XMLConfigurator2::getInstance(); 
	if ( xcfg2 == 0 ) return -1;
	return xcfg2->HashMappingStream(profile, (baseStream*) stream);
}
#endif

void XCFG2_Dump(){
	XMLConfigurator2 *xcfg2 = XMLConfigurator2::getInstance(); 
	if ( xcfg2 == 0 ) return ;
	xcfg2->Dump();
}
void XCFG2_EnableDebug(){
	XMLConfigurator2 *xcfg2 = XMLConfigurator2::getInstance(); 
	if ( xcfg2 == 0 ) return ;
	xcfg2->EnableDebug();
}
void XCFG2_DisableDebug(){
	XMLConfigurator2 *xcfg2 = XMLConfigurator2::getInstance(); 
	if ( xcfg2 == 0 ) return ;
	xcfg2->DisableDebug();
}

void XCFG2_PutInstance() {
	XMLConfigurator2::putInstance();
}


#ifdef __cplusplus
}
#endif
