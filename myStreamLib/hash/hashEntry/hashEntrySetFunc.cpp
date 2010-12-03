#include <hash/hashEntry.hpp>

int hashEntry::SetName(char *n){
	if ( n == 0 ) return -1;
	strncpy ( this->name , n , 255 );
	return 0;
}
int hashEntry::SetType(hashEntryType t) {
	this->type = t;
	return 0;
}
int hashEntry::SetPtr( void *p ) {
	if ( p == 0 ) return -1;
	this->ptr = p; 
	return 0; 
} 			
