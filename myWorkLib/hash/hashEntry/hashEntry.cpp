#include <hash/hashEntry.hpp>
#include <glib.h>

hashEntry::hashEntry():
	type( HASH_ENTRY_TYPE_NULL ),
	ptr ( 0 )
{
	{
		char name[] = HASH_ENTRY_NULL_NAME ;
		this->SetName( name );	
	}	
}
hashEntry::~hashEntry(){
}

std::ostream& hashEntry::Dump(std::ostream& out)const {
	int width = 19 ; 
	//out << "HashEntry" ;
	out << "name :" << std::setw(width)<< this->name;
	out << ", ";
	width = 3;
	switch ( this->type ) {
		case HASH_ENTRY_TYPE_GBOOLEAN:
			out << "type :" << std::setw(width)<< "GB";
			break;
		case HASH_ENTRY_TYPE_GINT:
			out << "type :" << std::setw(width)<< "GI";
			break;
		case HASH_ENTRY_TYPE_GSTR:
			out << "type :" << std::setw(width)<< "GS";
			break;
		case HASH_ENTRY_TYPE_GINT64:
			out << "type :" << std::setw(width)<< "G64";
			break;
		case HASH_ENTRY_TYPE_GST_TIMEOUT:
		case HASH_ENTRY_TYPE_GUINT64:
		case HASH_ENTRY_TYPE_GULONG:
			out << "type :" << std::setw(width)<< "GUL";
			break;
		case HASH_ENTRY_TYPE_GUINT:
			out << "type :" << std::setw(width)<< "GUI";
			break;
		case HASH_ENTRY_TYPE_GFLOAT:
			out << "type :" << std::setw(width)<< "GFL";
			break;
		case HASH_ENTRY_TYPE_UINT:
			out << "type :" << std::setw(width)<< "UI";
			break;
		case HASH_ENTRY_TYPE_INT:
			out << "type :" << std::setw(width)<< "I";
			break;
		case HASH_ENTRY_TYPE_CSTR:
			out << "type :" << std::setw(width)<< "S";
			break;
		case HASH_ENTRY_TYPE_GDOUBLE:
			out << "type :" << std::setw(width)<< "GDB";
			break;
		case HASH_ENTRY_TYPE_BOOL:
			out << "type :" << std::setw(width)<< "B";
			break;
		case HASH_ENTRY_TYPE_NULL:
		default:
			out << "type :" << std::setw(width)<< "NUL";
			break;
	}
	
	out << ", ";
	width = 10;
	out << "ptr :" << std::setw(width)<< this->ptr;
	out << ", ";
	width = 19;
	switch ( this->type ) {
		case HASH_ENTRY_TYPE_GBOOLEAN:
			{
				gboolean *tmp = (gboolean*) this->ptr;
				if ( tmp != 0 ) {
					out << "*ptr :" << std::setw(width)<< *tmp;
					out << std::endl;
				}
			}
			break;
		case HASH_ENTRY_TYPE_GINT:
			{	
				gint *tmp = (gint*) this->ptr;
				if ( tmp != 0 ) {
					out << "*ptr :" << std::setw(width)<< *tmp;
					out << std::endl;
				}
			}
			break;
		case HASH_ENTRY_TYPE_GSTR:
			{
				gchar *tmp = (gchar*) this->ptr;
				if ( tmp != 0 ) {
					out << "*ptr :" << std::setw(width)<< tmp;
					out << std::endl;
				}
				out << std::endl;
			}
			break;
		case HASH_ENTRY_TYPE_GINT64:
			{
				gint64 *tmp = (gint64*) this->ptr;
				if ( tmp != 0 ) {
					out << "*ptr :" << std::setw(width)<< *tmp;
					out << std::endl;
				}
			}
			break;
		case HASH_ENTRY_TYPE_GST_TIMEOUT:
		case HASH_ENTRY_TYPE_GUINT64:
		case HASH_ENTRY_TYPE_GULONG:
			{
				gulong *tmp = (gulong*) this->ptr;
				if ( tmp != 0 ) {
					out << "*ptr :" << std::setw(width)<< *tmp;
					out << std::endl;
				}
			}
			break;
		case HASH_ENTRY_TYPE_GUINT:
			{
				guint *tmp = (guint*) this->ptr;
				if ( tmp != 0 ) {
					out << "*ptr :" << std::setw(width)<< *tmp;
					out << std::endl;
				}
			}
			break;
		case HASH_ENTRY_TYPE_GFLOAT:
			{
				gfloat *tmp = (gfloat*) this->ptr;
				if ( tmp != 0 ) {
					out << "*ptr :" << std::setw(width)<< *tmp;
					out << std::endl;
				}
			}
			break;
		case HASH_ENTRY_TYPE_UINT:
			{	
				unsigned int *tmp = (unsigned int*) this->ptr;
				if ( tmp != 0 ) {
					out << "*ptr :" << std::setw(width)<< *tmp;
					out << std::endl;
				}
			}
			break;
		case HASH_ENTRY_TYPE_INT:
			{	
				int *tmp = (int*) this->ptr;
				if ( tmp != 0 ) {
					out << "*ptr :" << std::setw(width)<< *tmp;
					out << std::endl;
				}
			}
			break;
		case HASH_ENTRY_TYPE_CSTR:
			{
				char *tmp = (char*) this->ptr;
				if ( tmp != 0 ) {
					out << "*ptr :" << std::setw(width)<< tmp;
					out << std::endl;
				}
			}
			break;
		case HASH_ENTRY_TYPE_GDOUBLE:
			{
				gdouble *tmp = (gdouble*) this->ptr;
				if ( tmp != 0 ) {
					out << "*ptr :" << std::setw(width)<< *tmp;
					out << std::endl;
				}
			}
			break;
		case HASH_ENTRY_TYPE_BOOL:
			{
				bool *tmp = (bool*) this->ptr;
				if ( tmp != 0 ) {
					out << "*ptr :" << std::setw(width)<< *tmp;
					out << std::endl;
				}
			}
			break;
		case HASH_ENTRY_TYPE_NULL:
		default:
			out << " error type " << std::endl;
			break;
	}	


	return out;
}
