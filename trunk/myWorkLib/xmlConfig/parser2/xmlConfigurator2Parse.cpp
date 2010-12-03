#include <xmlConfig/xmlConfig2.hpp>

int XMLConfigurator2::ParseProfile(char *name) {
	xmlTextReaderPtr reader;
	int ret = 0;
	if ( name == 0 ) return -1;

	MACRO_DEBUG_CLASS_PRINT_L5("Call\tXMLConfigurator2::ParseProfile()\n");
	
	xmlProfile *profile = profilePool->GetItemByName ( name );
	if ( profile == 0 ) return -1;
	//std::cout<< *profile ;
	XC_xmlElementsPool *eP = profile->GetElementsPool();
	eP->RemoveAll();
	//reader = xmlNewTextReaderFilename( profile->GetValue() );
	reader = xmlReaderForFile( profile->GetValue(), NULL,
	 XML_PARSE_DTDLOAD | XML_PARSE_DTDATTR );
	if ( reader == NULL ) return -1;
	this->ML.Lock();	
    ret = xmlTextReaderRead( reader );
    while (ret == 1) {
         this->DoParseElement( profile, reader );
         ret = xmlTextReaderRead( reader );
    }
    xmlFreeTextReader(reader);
	this->ML.Unlock();	
	return 0;
}

int XMLConfigurator2::DoParseElement 
	( xmlProfile *profile, xmlTextReaderPtr reader) 
{
	MACRO_DEBUG_CLASS_PRINT_L6("Call\tXMLConfigurator2::DoParseElement()\n");

	if ( profile == 0 ) return -1;
	if ( reader  == NULL ) return -1;
	
	int NodeType         = 0;
	char *elementName    = 0;
	char *value          = 0;
	XC_xmlElement *xc_element = 0;
	XC_xmlElementsPool *eP = profile->GetElementsPool();
	
	NodeType = xmlTextReaderNodeType(reader);

	MACRO_DEBUG_CLASS_PRINT_L6(" xmlTextReaderDepth(reader) = %d\n",xmlTextReaderDepth(reader));
	if( NodeType != 1 ) return -1;
	
	elementName = (char*)xmlTextReaderConstName(reader);
	value       = (char*)xmlTextReaderValue(reader);
	if( elementName == 0 ) return -1;
	xc_element = new XC_xmlElement(elementName,value);
	eP->Append(xc_element);
	this->DoParseAttributes( xc_element , reader );
	return 0;
}

int XMLConfigurator2::DoParseAttributes 
	(XC_xmlElement *element, xmlTextReaderPtr reader) 	
{
	char *attribute      = 0;
	char *attributeValue = 0;
	if ( xmlTextReaderHasAttributes(reader) != 1) 
		return -1;
	attributesPool *attrlist = element->GetAttributesPool();
	while ( xmlTextReaderMoveToNextAttribute(reader) == 1 )
	{
		attribute      = (char*)xmlTextReaderConstName(reader);
		attributeValue = (char*)xmlTextReaderConstValue(reader);
		Attributes *tmp = new Attributes(attribute , attributeValue);
		attrlist->Append( tmp );
	}
	return 0;
}
