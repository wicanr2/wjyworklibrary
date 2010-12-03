#include <xmlConfig/xmlProfilesPool.hpp> 

int xmlProfilesPool::Append(xmlProfile *profile) {
	if ( list == 0 ) return -1;
	return list->AppendItem(profile);
}
int xmlProfilesPool::AppendSmartPtr
	( smartPtr<xmlProfile> *sp ) {
	if ( list == 0 ) return -1;
	return list->AppendSmartPtr( sp );	
}
int xmlProfilesPool::Remove(int i) {
	if ( list == 0 ) return -1;
	return list->RemoveItem(i);
}
int xmlProfilesPool::RemoveTail() {
	if ( list == 0 ) return -1;
	return list->RemoveTailItem();
}
int xmlProfilesPool::RemoveAll() {
	if ( list == 0 ) return -1;
	return list->RemoveAllItem();
}
