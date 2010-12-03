#include <xmlConfig/elementsPool.hpp> 

int XC_xmlElementsPool::Append(XC_xmlElement *element) {
	if ( list == 0 ) return -1;
	return list->AppendItem(element);
}
int XC_xmlElementsPool::AppendSmartPtr
	( smartPtr<XC_xmlElement> *sp ) {
	if ( list == 0 ) return -1;
	return list->AppendSmartPtr( sp );	
}
int XC_xmlElementsPool::Remove(int i) {
	if ( list == 0 ) return -1;
	return list->RemoveItem(i);
}
int XC_xmlElementsPool::RemoveTail() {
	if ( list == 0 ) return -1;
	return list->RemoveTailItem();
}
int XC_xmlElementsPool::RemoveAll() {
	if ( list == 0 ) return -1;
	return list->RemoveAllItem();
}
