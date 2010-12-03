#include <hash/hashEntry.hpp>


char* hashEntry::GetName(){
	return this->name;
}
hashEntryType
	  hashEntry::GetType() {
	return this->type;
}
void* hashEntry::GetPtr() {
	return this->ptr;
}
