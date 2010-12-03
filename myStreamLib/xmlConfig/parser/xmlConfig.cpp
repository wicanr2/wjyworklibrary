
#include <xmlConfig/xmlConfig.h>



_XMLConfig::_XMLConfig(int no, char *n, char* p,
				   TypePool *tP)
{
	this->_no = no;
	strncpy(this->_name , n , 255);
	strncpy(this->_path , p , 255);
	if ( tP ) {
		this->_tP = tP;
		this->CountTypePool();
	}
	else
		this->_tP = 0;
	
}

void _XMLConfig::RunParse(xmlTextReaderPtr reader) {
	if ( this->_tP ) {
		this->Parse(reader);
	}
}

char * _XMLConfig::GetPath() {
	return this->_path;
}

void _XMLConfig::Parse(xmlTextReaderPtr reader){
	char *elementName = 0;
	char *attr = 0;
	char *attr_v = 0;
	gchar tmpGChar[255];
	int NodeType = 0;
	TypePool *tmp = 0;
	NodeType = xmlTextReaderNodeType(reader);
	if( NodeType != 1 ) return ;
	elementName = (char*)xmlTextReaderConstName(reader);
	//debug
	__VC_L2_DEBUG_PRINT("Depth:%4d NodeType:%4d Name:%15s isEmpty:%2d\n", 
		xmlTextReaderDepth(reader),
		NodeType,
		elementName,
		xmlTextReaderIsEmptyElement(reader) );
	
	__VC_L2_DEBUG_PRINT("extract value from element %15s : (VALUE) %10s\n",
		elementName,
		 xmlTextReaderValue(reader) );
	if ( xmlTextReaderHasAttributes(reader) ){
		//printf("the %s has attributes\n", elementName);
		while ( xmlTextReaderMoveToNextAttribute(reader) == 1 ) {

			attr = (char*)xmlTextReaderConstName(reader);
			attr_v = (char*)xmlTextReaderConstValue(reader);
			
			__VC_L2_DEBUG_PRINT("e:%-7s, attr:%-10s, v:%10s\n",
				elementName,
				attr, attr_v );
			//printf("attr %s %s \n", attr, attr_v);
			tmp = this->findType(elementName, attr);
			if ( tmp == 0 ) {
				continue;
			}
			//convert to int
			if ( tmp->type == INT ) {
				int *p = (int*)tmp->ptr;
				(*p) = atoi(attr_v);
				continue;
			}
			else if ( tmp->type == CSTR ) {
				char *p = (char*) tmp->ptr;
				snprintf( p , 255, "%s" , attr_v );
				continue;
			}
			//convert to gboolean
			else if ( tmp->type == G_BOOL ) {
				gboolean *p = (gboolean*)tmp->ptr;
				if ( strcmp ( attr_v, "FALSE" ) == 0 ) {
					(*p) = FALSE;
				}else{
					(*p) = TRUE;
				}
				continue;
			}
			//convert to guint
			else if ( tmp->type == G_UINT ) {
				guint *p = (guint*) tmp->ptr;
				g_snprintf( tmpGChar , 255, "%s" , attr_v );
				(*p) = (guint) g_ascii_strtoull( tmpGChar, NULL , 10);
				continue;
			}
			//convert to gint64
			else if ( tmp->type == G_INT64 ) {
				gint64 *p = (gint64*) tmp->ptr;
				g_snprintf( tmpGChar , 255, "%s" , attr_v );
				(*p) = g_ascii_strtoll( tmpGChar, NULL , 10);
				continue; 
			}
			//convert to gchar*
			else if ( tmp->type == G_STR ) {
				gchar *p = (gchar*) tmp->ptr;
				g_snprintf( p , 255, "%s" , attr_v );
				continue;
			}
			//convert to G_INT
			else if ( tmp->type == G_INT ) {
				gint *p = (gint*) tmp->ptr;
				g_snprintf( tmpGChar , 255, "%s" , attr_v );
				(*p) = (gint) g_ascii_strtoll( tmpGChar, NULL , 10);
				continue;
			}
			//convert to G_FLOAT 
			else if ( tmp->type == G_FLOAT ) {
				gfloat *p = (gfloat*) tmp->ptr;
				g_snprintf( tmpGChar , 255, "%s" , attr_v );
				(*p) = (gfloat) g_ascii_strtod ( tmpGChar, NULL );
				continue;
			}
			//convert to G_DOUBLE
			else if ( tmp->type == G_DOUBLE ) {
				gdouble *p = (gdouble*) tmp->ptr;
				g_snprintf( tmpGChar , 255, "%s" , attr_v );
				(*p) = (gdouble) g_ascii_strtod ( tmpGChar, NULL );
				continue;
			}
		}// end while
	}// end if
}

TypePool* _XMLConfig::findType(const char* e, const char* attr) {
	int i = 0;
	TypePool *tmp = 0;
	for ( i = 0 ; i < _tpSz ; i++ ) {
		tmp = &_tP[i];
		if ( strcmp(e,tmp->element) == 0 && strcmp(attr,tmp->attr) == 0 ) {
			return tmp;
		}
	}
	return 0;
}

void _XMLConfig::CountTypePool() {
	int i = 0;
	TypePool *te = 0;
	if ( this->_tP ) {
		do {
			te = &_tP[i];
			if ( te->type == LAST )
				break;
			i++;
		}while( true );
	}
	_tpSz = i;
	__VC_L2_DEBUG_PRINT(" the TypePool size is %d\n", _tpSz);
}
XMLPropTypeEnum _XMLConfig::GetPropType(const char* e, const char* attr){
	TypePool *tmp = findType(e,attr);
	if ( tmp != 0 ) {
		return tmp->type;
	}
}
int _XMLConfig::GetProp(const char* e, const char* attr, void *value) {
	TypePool *tmp = findType(e,attr);
	if ( tmp != 0 ) {
		if ( tmp->type == INT ) {
			int *p = (int*) value;
			int *q = (int*) tmp->ptr;
			(*p) = (*q);
		}else if ( tmp->type == CSTR ) {
			char *p = (char*) value;
			char *q = (char*) tmp->ptr;
			strncpy( p, q, 255 );
		}else if ( tmp->type == G_BOOL ) {
			gboolean *p = (gboolean*) value;
			gboolean *q = (gboolean*) tmp->ptr;
			(*p) = (*q);
		}else if ( tmp->type == G_UINT ) {
			guint *p = (guint*) value;
			guint *q = (guint*) tmp->ptr;
			(*p) = (*q);
		}else if ( tmp->type == G_INT64 ) {
			gint64 *p = (gint64*) value;
			gint64 *q = (gint64*) tmp->ptr;
			(*p) = (*q);
		}else if ( tmp->type == G_STR ) {
			gchar *p = (gchar*) value;
			gchar *q = (gchar*) tmp->ptr;
			g_stpcpy ( p, q );
		}else if ( tmp->type == G_INT ) {
			gint *p = (gint*) value;
			gint *q = (gint*) tmp->ptr;
			(*p) = (*q) ;
		}else if ( tmp->type == G_FLOAT ) {
			gfloat *p = (gfloat*) value;
			gfloat *q = (gfloat*) tmp->ptr;
			(*p) = (*q) ;
		}else if ( tmp->type == G_DOUBLE ) {
			gdouble *p = (gdouble*) value;
			gdouble *q = (gdouble*) tmp->ptr;
			(*p) = (*q) ;
		}
		
	} else {
		__VC_L1_DEBUG_PRINT(" the Attribute [%s.%s] is not existed \n", e, attr );
	}
	return 0;
}
