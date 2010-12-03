#include <xmlConfig/attributesPool.hpp> 

int attributesPool::Append(Attributes *item) {
	if ( list == 0 ) return -1;
	return list->AppendItem(item);
}
int attributesPool::Remove(int i) {
	if ( list == 0 ) return -1;
	return list->RemoveItem(i);
}
int attributesPool::RemoveTail() {
	if ( list == 0 ) return -1;
	return list->RemoveTailItem();
}
int attributesPool::RemoveAll() {
	if ( list == 0 ) return -1;
	return list->RemoveAllItem();
}
