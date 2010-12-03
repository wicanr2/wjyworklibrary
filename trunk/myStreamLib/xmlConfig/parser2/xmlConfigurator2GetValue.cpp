
#include <xmlConfig/xmlConfig2.hpp>

// get elements
int XMLConfigurator2::GetElements(char *profile, char *element) {
	if ( profile == 0 ) return -1;
	if ( element == 0 ) return -1;

	if ( this->profilePool == 0 ) return -1;
	
	// clear previous pool
	if ( this->currentElementsPool != 0 ) {
		delete this->currentElementsPool;
		this->currentElementsPool = 0;
	}
	
	xmlProfile *ptmp = 
		this->profilePool->GetItemByName( profile );
	if ( ptmp == 0 ) return -1;
	
	XC_xmlElementsPool *elementsPool = ptmp->GetElementsPool();
	if ( elementsPool == 0 ) return -1;	
	
	this->currentElementsPool = elementsPool->GetItemPool( element );
	if ( this->currentElementsPool == 0 ) return -1;
	
	if ( this->GetDebugFlag() ) 
		this->currentElementsPool->EnableDebug();
		
	this->poolPtr = 0;
	return this->currentElementsPool->GetSize();
}
// get next elements
int XMLConfigurator2::GetNextElement() {
	if ( this->profilePool == 0 ) return -1;
	if ( this->currentElementsPool == 0 ) return -1;
	this->poolPtr = (this->poolPtr+1) % this->currentElementsPool->GetSize();
	return this->poolPtr;
}
int XMLConfigurator2::GetElementsI( int i ) {
	if ( this->profilePool == 0 ) return -1;
	if ( this->currentElementsPool == 0 ) return -1;
	if ( i < 0 ) return -1;
	if ( i >= this->currentElementsPool->GetSize() ) return -1;
	this->poolPtr = i;
	return 0;
}
const char* XMLConfigurator2::GetElementName() {
	if ( this->profilePool == 0 ) return 0;
	if ( this->currentElementsPool == 0 ) return 0;
	XC_xmlElement *etmp = this->currentElementsPool->GetItem( this->poolPtr ); 
	if ( etmp == 0 ) return 0;
	return etmp->GetName();	
}
const char* XMLConfigurator2::GetElementValue() 
{
	if ( this->profilePool == 0 ) return 0;
	if ( this->currentElementsPool == 0 ) return 0;
	XC_xmlElement *etmp = this->currentElementsPool->GetItem( this->poolPtr ); 
	if ( etmp == 0 ) return 0;
	return etmp->GetValue();	

}
const char* XMLConfigurator2::GetElementAttributeValue( char *attr )
{
	if ( this->profilePool == 0 ) return 0;
	if ( this->currentElementsPool == 0 ) return 0;
	if ( attr == 0 ) return 0;
	
	XC_xmlElement *etmp = this->currentElementsPool->GetItem( this->poolPtr ); 
	if ( etmp == 0 ) return 0;
	
	attributesPool *attrPool = etmp->GetAttributesPool();
	if ( attrPool == 0 ) return 0;
	
	Attributes *atmp = attrPool->GetItemByName( attr );
	if ( atmp == 0 ) return 0;
	
	return atmp->GetValue();
}
attributesPool* XMLConfigurator2::GetElementAttributesPool() {
	if ( this->profilePool == 0 ) return 0;
	if ( this->currentElementsPool == 0 ) return 0;

	XC_xmlElement *etmp = this->currentElementsPool->GetItem( this->poolPtr ); 
	if ( etmp == 0 ) return 0;

	attributesPool *attrPool = etmp->GetAttributesPool();
	if ( attrPool == 0 ) return 0;
	
	return attrPool;
}
const char* XMLConfigurator2::GetElementName(char *profile, char *element){
	if ( profile == 0 ) return 0;
	if ( element == 0 ) return 0;
	
	if ( this->profilePool == 0 ) return 0;

	xmlProfile *ptmp = 
		this->profilePool->GetItemByName( profile );
	if ( ptmp == 0 ) return 0;
	
	XC_xmlElementsPool *elementsPool = ptmp->GetElementsPool();
	if ( elementsPool == 0 ) return 0;	
	
	XC_xmlElement *etmp = elementsPool->GetItemByName( element );
	if ( etmp == 0 ) return 0;

	return etmp->GetName();	
}
const char* XMLConfigurator2::GetElementValue(char *profile, char *element){
	if ( profile == 0 ) return 0;
	if ( element == 0 ) return 0;
	if ( this->profilePool == 0 ) return 0;

	xmlProfile *ptmp = 
		this->profilePool->GetItemByName( profile );
	if ( ptmp == 0 ) return 0;
	
	XC_xmlElementsPool *elementsPool = ptmp->GetElementsPool();
	if ( elementsPool == 0 ) return 0;	
	
	XC_xmlElement *etmp = elementsPool->GetItemByName( element );
	if ( etmp == 0 ) return 0;

	return etmp->GetValue();	
}
const char* XMLConfigurator2::GetElementAttributeValue
	(char *profile, char *element, char *attr )
{
	if ( profile == 0 ) return 0;
	if ( element == 0 ) return 0;
	if ( attr == 0 ) return 0;
	if ( this->profilePool == 0 ) return 0;

	xmlProfile *ptmp = 
		this->profilePool->GetItemByName( profile );
	if ( ptmp == 0 ) return 0;
	
	XC_xmlElementsPool *elementsPool = ptmp->GetElementsPool();
	if ( elementsPool == 0 ) return 0;	
	
	XC_xmlElement *etmp = elementsPool->GetItemByName( element );
	if ( etmp == 0 ) return 0;

	attributesPool *attrPool = etmp->GetAttributesPool();
	if ( attrPool == 0 ) return 0;
	
	Attributes *atmp = attrPool->GetItemByName( attr );
	if ( atmp == 0 ) return 0;
	
	return atmp->GetValue();
}
