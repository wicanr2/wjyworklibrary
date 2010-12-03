#include <hash_func/hashFuncEntry.hpp>

hashFuncEntry::hashFuncEntry():funcPtr( 0 )
{
	do{
		char name[] = HASH_FUNC_ENTRY_NULL_NAME;
		this->SetName( name );	
	}while(0);	
}
hashFuncEntry::~hashFuncEntry(){
}

std::ostream& hashFuncEntry::Dump(std::ostream& out)const {
	int width = 10 ; 
	char buf[255];
	MACRO_LOGGER_PRINT_VAR(out,"Name            :", this->name, width );
	MACRO_LOGGER_PRINT_COMMA(out);

	snprintf( buf, 255, "%d", (int)this->funcPtr );
	MACRO_LOGGER_PRINT_VAR(out,"FuncPtr Address :", buf, width );

	MACRO_LOGGER_PRINT_NEWLINE(out);
	return out;
}
