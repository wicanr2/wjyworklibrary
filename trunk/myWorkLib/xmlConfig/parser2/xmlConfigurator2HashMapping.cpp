
#ifdef XML2_CONFIGURATOR_STREAM_HAHS_MAPPING	
#include <xmlConfig/xmlConfig2.hpp>
#include <baseStream/baseStream.hpp>
/*
 this function read the attributes of the parameter element  from profile, 
 and fill those attributes into paraBase.
*/
int XMLConfigurator2::HashMappingParams(char *profile, paraBase *param) {
	char *xmlName = 0;
	hashTable *ht = 0;
	Attributes *atmp = 0;
	hashEntry  *he = 0;
	xmlProfile *ptmp = 0; 
	XC_xmlElementsPool *elementsPool = 0;
	XC_xmlElement *etmp = 0; 
	attributesPool *attrPool = 0;

	MACRO_DEBUG_CLASS_PRINT_L5("Call\tXMLConfigurator2::HashMapping()\n");
	
	if ( param == 0 ) return -1;
	if ( profile == 0 ) return -1;
	if ( this->profilePool == 0 ) return -1;

	xmlName = param->GetXMLName();
	ht = param->GetHashTable();
	if ( xmlName == 0 ) return -1;
	if ( ht == 0 ) return -1;

	ptmp = this->profilePool->GetItemByName( profile );
	if ( ptmp == 0 ) {
		MACRO_DEBUG_CLASS_PRINT("WARNING: the profile %25s was not exsited in the profile pool\n", profile);
		return -1;
	}
	elementsPool = ptmp->GetElementsPool();
	if ( elementsPool == 0 ) {
		MACRO_DEBUG_CLASS_PRINT("WARNING: the elements pool is null\n");
		return -1;	
	}
	etmp = elementsPool->GetItemByName( xmlName ); 
	if ( etmp == 0 ) {
		MACRO_DEBUG_CLASS_PRINT("WARNING: the element %25s was not existed in the element pool\n", xmlName );	
		return -1;
	}
	attrPool = etmp->GetAttributesPool();
	if ( attrPool == 0 ) {
		MACRO_DEBUG_CLASS_PRINT("the attributes pool is null.\n");	
		return -1;
	}
	atmp = 0;
	he = 0; 
	for ( int i = 0 ; i < attrPool->GetSize() ; i++ ) {
		atmp = attrPool->GetItem(i);
		if ( atmp == 0 ) continue;
		he = ht->GetValue( atmp->GetName() ) ;
		if ( he != 0 ) {
			MACRO_DEBUG_CLASS_PRINT_L3("Before :");
			if ( this->GetDebugFlagLevel3() )
				std::cout << *he ;	

			this->ML.Lock();
			this->PutHashValue( he, atmp );
			this->ML.Unlock();

			MACRO_DEBUG_CLASS_PRINT_L3("After  :");	

			if ( this->GetDebugFlagLevel3() )
				std::cout << *he ;	
		}else{ 
			MACRO_DEBUG_CLASS_PRINT("he == 0\n");
			MACRO_DEBUG_CLASS_PRINT("atmp->GetName(): %s\n",atmp->GetName());
		}

	}
	return 0;
}
/*
<stream 
	role=""
	name=""
	sleep_interval=""
	gst_state_timeout=""
	timeout_count=""
>
the below function read the "stream" element attributes 
and fill those values into the baseStream.
*/
int XMLConfigurator2::HashMappingStream(char *profile, baseStream *stream){
	int size = 0; 
	char stream_name[] = XML_STREAM_ELEMENT_NAME; 
	char attr_name  [] = XML_STREAM_ELEMENT_ATTR_NAME;  
	char attr_role  [] = XML_STREAM_ELEMENT_ATTR_ROLE;
	char cmp_name[255];

	hashTable *ht = 0;
	hashEntry  *he = 0;
	attributesPool *attrPool = 0;
	Attributes *atmp = 0;
	if ( stream == 0 ) return -1;
	if ( profile == 0 ) return -1;
	if ( this->profilePool == 0 ) return -1;
	
	ht = stream->GetHashTable();
	if ( ht == 0 ) return -1;	

	size = this->GetElements( profile, stream_name );
	if ( size <= 0 ) return -1;

	for ( int i = 0 ; i < size ; i++ ) {
		this->GetElementsI(i);
		attrPool = GetElementAttributesPool();
		if ( attrPool == 0 ) continue;

		snprintf( cmp_name, 255, "%s", 
			this->GetElementAttributeValue( attr_name ) );			
		if ( strncmp( stream->GetStreamName(), cmp_name, 255 ) != 0 ) 
			continue;

		MACRO_DEBUG_CLASS_PRINT_L2("Matching Stream : %s\n", cmp_name );
		
		snprintf( cmp_name, 255, "%s", 
			this->GetElementAttributeValue( attr_role ) );			
		if ( strncmp( stream->GetRole(), cmp_name, 255 ) != 0 ) 
			continue;
		MACRO_DEBUG_CLASS_PRINT_L2("Matching Role   : %s\n", cmp_name );
		
		for ( int j = 0 ; j < attrPool->GetSize(); j++ ) {
			atmp = attrPool->GetItem(j);
			if ( atmp == 0 ) continue;
			he = ht->GetValue( atmp->GetName() ) ;
			if ( he != 0 ) {
				
				MACRO_DEBUG_CLASS_PRINT_L3("Before :");
				if ( this->GetDebugFlagLevel3() )
					std::cout << *he ;	

				this->ML.Lock();
				this->PutHashValue( he, atmp );
				this->ML.Unlock();

				MACRO_DEBUG_CLASS_PRINT_L3("After  :");	
				if ( this->GetDebugFlagLevel3() )
					std::cout << *he ;	
				
			}
		}
		break;
	}
	return 0;
}
int XMLConfigurator2::PutHashValue( hashEntry *he, Attributes *attr) {
	if ( he == 0 ) return -1;
	if ( attr == 0 ) return -1;
	if ( strncmp ( he->GetName(), attr->GetName() , 255 ) != 0 ) 
		return -1;
	if ( he->GetPtr() == 0 ) return -1;
	if ( attr->GetValue() == 0 ) return -1;
	gchar tmpGChar[255];
	switch ( he->GetType() ) {
		case HASH_ENTRY_TYPE_GBOOLEAN:
			{
				gboolean *p = (gboolean*) he->GetPtr();
				char STRUE[]="TRUE";
				if ( strncmp ( STRUE, attr->GetValue(), 255) == 0 ) {
					*p = TRUE;
				} else {
					*p = FALSE;
				}
			}
			break;
		case HASH_ENTRY_TYPE_GINT:
			{
				gint *p = (gint*) he->GetPtr();
				g_snprintf( tmpGChar , 255, "%s" , attr->GetValue() );
				(*p) = (gint) g_ascii_strtoll( tmpGChar, NULL , 10);
			}
			break;
		case HASH_ENTRY_TYPE_GSTR:
			{
				gchar *p = (gchar*) he->GetPtr();
				g_snprintf( p , 255, "%s" , attr->GetValue() );
			}
			break;
		case HASH_ENTRY_TYPE_GINT64:
			{
				gint64 *p = (gint64*) he->GetPtr();
				g_snprintf( tmpGChar , 255, "%s" , attr->GetValue() );
				(*p) = g_ascii_strtoll( tmpGChar, NULL , 10);
			}
			break;
			
		case HASH_ENTRY_TYPE_GST_TIMEOUT:
		case HASH_ENTRY_TYPE_GUINT64:
		case HASH_ENTRY_TYPE_GULONG:
			{
				guint64 *p = (guint64*) he->GetPtr();
				g_snprintf( tmpGChar , 255, "%s" , attr->GetValue() );
				(*p) = g_ascii_strtoull( tmpGChar, NULL , 10);
			}
			break;
		case HASH_ENTRY_TYPE_GUINT:
			{
				guint *p = (guint*) he->GetPtr();
				g_snprintf( tmpGChar , 255, "%s" , attr->GetValue() );
				(*p) = (guint) g_ascii_strtoull( tmpGChar, NULL , 10);
			}
			break;
		case HASH_ENTRY_TYPE_GFLOAT:
			{
				gfloat *p = (gfloat*) he->GetPtr();
				g_snprintf( tmpGChar , 255, "%s" , attr->GetValue() );
				(*p) = (gfloat) g_ascii_strtod ( tmpGChar, NULL );
			}
			break;
		case HASH_ENTRY_TYPE_INT:
			{
				int *p = (int*)he->GetPtr();
				(*p) = atoi(attr->GetValue());
			}
			break;
		case HASH_ENTRY_TYPE_UINT:
			{
				unsigned int *p = (unsigned int*)he->GetPtr();
				(*p) = atoi(attr->GetValue());
			}
			break;
		case HASH_ENTRY_TYPE_CSTR:
			{
				char *p = (char*) he->GetPtr();
				snprintf( p , 255, "%s" , attr->GetValue() );
			}
			break;
		case HASH_ENTRY_TYPE_GDOUBLE:
			{
				gdouble *p = (gdouble*) he->GetPtr();
				g_snprintf( tmpGChar , 255, "%s" , attr->GetValue() );
				(*p) = (gdouble) g_ascii_strtod ( tmpGChar, NULL );
			}
			break;
		case HASH_ENTRY_TYPE_BOOL:
			{
				bool *p = (bool*) he->GetPtr();
				char STRUE[]="TRUE";
				if ( strncmp ( STRUE, attr->GetValue(), 255) == 0 ) {
					*p = true;
				} else {
					*p = false;
				}
			}
			break;
		case HASH_ENTRY_TYPE_NULL:
		default:
			break;
	}
	return 0;
}	
#endif
