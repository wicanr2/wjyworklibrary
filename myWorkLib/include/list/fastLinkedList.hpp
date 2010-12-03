#ifndef FAST_LINKED_LIST_HPP
#define FAST_LINKED_LIST_HPP
#include <iostream>
#include <iomanip>
#include <utils/debugClass.hpp>
#include <utils/smartPointer.hpp>
#include <macro/macroDebugClassAid.hpp>
#include <macro/macroErrorCheck.hpp>

template < class T >
class linkedListItem {
	smartPtr<T> *_value;
	linkedListItem *_next;
	linkedListItem *_prev;
public:
	linkedListItem() ;
	~linkedListItem();
	int SetValue( T* value );
	int SetValue( smartPtr<T> *svalue);
	int SetNext(linkedListItem *item);
	int SetPrev(linkedListItem *item);
	T* GetValue();
	smartPtr<T>* GetSmartPtr();
	linkedListItem* GetNext();
	linkedListItem* GetPrev();
};
//--------------------------------------------
template < class T >
class fastLinkedList:public debugClass {
	//link 
private:
	int maxPoolSize;
	int usedPoolSize;
	linkedListItem<T> *head;
	linkedListItem<T> *cur;
	linkedListItem<T> **fastPool;
	
	int IndexFastPool();
public:
	fastLinkedList();
	~fastLinkedList();
	int SetMaxPoolSize(int size);
	int GetMaxPoolSize();
	int GetUsedPoolSize();
	
	int AppendItem(T* item);
	int AppendSmartPtr( smartPtr<T>* sp );
	int InsertItemAfter(int iItem, T* item);
	int RemoveItem(int iItem);
	int RemoveTailItem();
	int RemoveAllItem();
	// overriding the operator
	T* operator[](unsigned int index);
	smartPtr<T>* GetSmartPtr(int index);
	// Dump
	int Dump();
	int DumpOut(std::ostream &out);
	//debug 
	void EnableDebug() ;
	void DisableDebug() ;
};
//--------------------------------------------
// the implementation of fastLinkedList

template < class T >
int fastLinkedList<T>::IndexFastPool() {
	linkedListItem<T> *tmp  = 0;
	MACRO_DEBUG_CLASS_PRINT_L6("Call \tfastLinkedList::IndexFastPool()");
	if ( this->fastPool == 0 ) 
		return -1;
	
	tmp = this->head;
	this->usedPoolSize = 0;
	while ( tmp != 0 ) {
		this->fastPool[ this->usedPoolSize ] = tmp;
		this->usedPoolSize++;
		tmp = tmp->GetNext();
	}
	return 0;
}

template < class T >
fastLinkedList<T>::fastLinkedList() :
	head(0),cur(0),fastPool(0), maxPoolSize(0),
	usedPoolSize(0)
{
}

template < class T >
fastLinkedList<T>::~fastLinkedList() {
	MACRO_DEBUG_CLASS_PRINT_L5("Destory\tfastLinkedList");
	this->RemoveAllItem();
}

template < class T >
int fastLinkedList<T>::SetMaxPoolSize(int size) {
	if ( this->maxPoolSize == 0 ) {
		this->maxPoolSize = size;
		this->fastPool = 
			new linkedListItem<T>* [ this->maxPoolSize ];
		return 0;
	}
	return -1;
}

template < class T >
int fastLinkedList<T>::GetMaxPoolSize() {
	return this->maxPoolSize;
}

template < class T >
int fastLinkedList<T>::GetUsedPoolSize() {
	return this->usedPoolSize;
}

template < class T >
int fastLinkedList<T>::AppendItem(T* item) {
	MACRO_DEBUG_CLASS_PRINT_L6("Call \tfastLinkedList::AppendItem()");
	if ( this->fastPool == 0 ) 
		return -1;
		
	if ( this->usedPoolSize >= this->maxPoolSize ) 
		return -1;
	
	if ( this->head == 0 ) {
		this->head = new linkedListItem<T>;
		this->cur = this->head ;
		this->cur->SetValue( item );
		this->fastPool[ this->usedPoolSize ] = this->cur;
		this->usedPoolSize++;
	} else {
		linkedListItem<T> *tmp = new linkedListItem<T>;
		tmp->SetValue( item );
		this->cur->SetNext(tmp);
		tmp->SetPrev(this->cur);
		this->fastPool[ this->usedPoolSize ] = tmp;
		this->usedPoolSize++;
		this->cur = tmp;
	}
	
	return 0;
}
// append smart ptr
template < class T >
int fastLinkedList<T>::AppendSmartPtr( smartPtr<T>* sp ) {
	MACRO_DEBUG_CLASS_PRINT_L6("Call \tfastLinkedList::AppendSmartPtr()");
	if ( this->fastPool == 0 ) 
		return -1;
		
	if ( this->usedPoolSize >= this->maxPoolSize ) 
		return -1;
	
	if ( this->head == 0 ) {
		this->head = new linkedListItem<T>;
		this->cur = this->head ;
		this->cur->SetValue( sp );
		this->fastPool[ this->usedPoolSize ] = this->cur;
		this->usedPoolSize++;
	} else {
		linkedListItem<T> *tmp = new linkedListItem<T>;
		tmp->SetValue( sp );
		this->cur->SetNext(tmp);
		tmp->SetPrev(this->cur);
		this->fastPool[ this->usedPoolSize ] = tmp;
		this->usedPoolSize++;
		this->cur = tmp;
	}
	
	return 0;
}
template < class T >
int fastLinkedList<T>::InsertItemAfter(int iItem, T* item) {
	MACRO_DEBUG_CLASS_PRINT_L6("Call \tfastLinkedList::InsertItemAfter()");
	return 0;
}

template < class T >
int fastLinkedList<T>::RemoveItem(int iItem) {
	
	linkedListItem<T> *tmp  = 0;
	linkedListItem<T> *next = 0;
	linkedListItem<T> *prev = 0;

	MACRO_DEBUG_CLASS_PRINT_L6("Call \tfastLinkedList::RemoveItem(%d)",iItem);
	
	if ( this->fastPool == 0 ) 
		return -1;
	if ( this->usedPoolSize <= 0 ) 
		return -1;
	if ( iItem < 0 || iItem >= this->usedPoolSize ) 
		return -1;
		
	if ( iItem == this->usedPoolSize - 1 ) {
		this->RemoveTailItem();
		
	} else if ( iItem == 0 ) {
		tmp  = this->head;
		next = this->head->GetNext();
		if ( this->head == this->cur ) {
			this->cur = next;
		}
		if ( next )
			next->SetPrev(0);
		this->head = next;
		delete tmp;
		// reindex
		this->IndexFastPool();
	} else {
		tmp = this->fastPool[ iItem ];
		next = tmp->GetNext();
		prev = tmp->GetPrev();
		if ( next )
			next->SetPrev(prev);
		if ( prev )
			prev->SetNext(next);
		delete tmp;
		this->IndexFastPool();
	}
	return 0;
	
	
}

template < class T >
int fastLinkedList<T>::RemoveTailItem() {
	MACRO_DEBUG_CLASS_PRINT_L6("Call \tfastLinkedList::RemoveTailItem()");
	if ( this->fastPool == 0 ) 
		return -1;
	if ( this->usedPoolSize <= 0 ) 
		return -1;
	linkedListItem<T> *tmp = this->fastPool[this->usedPoolSize-1];
	if ( tmp == 0 ) return -1;
	this->fastPool[this->usedPoolSize] = 0;
	this->usedPoolSize--;
	linkedListItem<T> *prev = tmp->GetPrev();
	if ( prev != 0 ) {
		prev->SetNext(0);
	} else {
		this->head = 0;
		this->cur = 0;
	}
	delete tmp;
	return 0;
}
// remove all item
template < class T >
int fastLinkedList<T>::RemoveAllItem() {
	int i = 0;
	linkedListItem<T> *tmp = 0;

	MACRO_DEBUG_CLASS_PRINT_L6("this->usedPoolSize = %d\n", this->usedPoolSize );
	
	for ( int i = 0 ; i < this->usedPoolSize ; i++ ){
		tmp = this->fastPool[i];
		if ( tmp ) {
			delete tmp;
		}
	}
	this->head = 0;
	this->cur  = 0;
	this->IndexFastPool();
}
//
template < class T >
T* fastLinkedList<T>::operator[](unsigned int index) {
	MACRO_DEBUG_CLASS_PRINT_L6("Call \tfastLinkedList[%d]",index);

	if ( index >= 0 && index < this->usedPoolSize ) {
		return this->fastPool[index]->GetValue();
	}
	return 0;
}

template < class T >
smartPtr<T>* fastLinkedList<T>::GetSmartPtr(int index){
	MACRO_DEBUG_CLASS_PRINT_L6("Call \tGetSmartPtr(%d)",index);
	if ( index >= 0 && index < this->usedPoolSize ) {
		return this->fastPool[index]->GetSmartPtr();
	}
	return 0;
}
template < class T >
int fastLinkedList<T>::Dump() {
	linkedListItem<T> *tmp = 0;
	
	MACRO_DEBUG_CLASS_PRINT_L6("Call \tfastLinkedList::Dump()");
	
	if ( this->fastPool == 0 ) 
		return -1;
	if ( this->usedPoolSize <= 0 ) 
		return -1;
	if ( this->GetDebugFlagLevel4() == false ) return -1;

	{
		for ( int i = 0 ; i < 80 ; i++ ) {
			std::cout << "_";
		}
		std::cout <<std::endl;
	}
	std::cout<<std::endl;
	std::cout
		<<std::setw(50)
		<<"Fast Linked List Dump"<<std::endl;
	for ( int i = 0 ; i < this->usedPoolSize ; i++ ){
		tmp = this->fastPool[i];
		T* value= tmp->GetValue();
		std::cout<<"Item ["<<std::setw(3)<<i<<"] = "<< *value <<std::endl;
	}
	std::cout
		<< std::setw(44)
		<<"End of List"<<std::endl;
	{
		for ( int i = 0 ; i < 80 ; i++ ) {
			std::cout << "_";
		}
		std::cout <<std::endl;
	}
	//std::cout<<std::endl;
	return 0;
}
template < class T >
int fastLinkedList<T>::DumpOut(std::ostream &out) {
	linkedListItem<T> *tmp = 0;
	MACRO_DEBUG_CLASS_PRINT_L6("Call \tfastLinkedList::DumpOut()");
	MACRO_ERROR_CHECK_0_WITH_DEBUG(this->fastPool);

	if ( this->usedPoolSize <= 0 ) 
		return -1;

	MACRO_DEBUG_CLASS_ERROR_CHECK_FALSE_L4();
	//out<<"--- Fast Linked List Dump ---"<<std::endl;
	for ( int i = 0 ; i < this->usedPoolSize ; i++ ){
		tmp = this->fastPool[i];
		T* value= tmp->GetValue();
		out<<"Item ["<<std::setw(3)<<i<<"] = "<< *value <<std::endl;
	}
	//out<<"---      End of List      ---"<<std::endl;
	//out<<std::endl;
	return 0;
}
template < class T >
void fastLinkedList<T>::EnableDebug() {
	smartPtr<T> *tmp = 0;
	
	if ( this->fastPool == 0 ) 
		return ;
	if ( this->usedPoolSize <= 0 ) 
		return ;
	//out<<"--- Fast Linked List Dump ---"<<std::endl;
	for ( int i = 0 ; i < this->usedPoolSize ; i++ ){
		tmp = this->GetSmartPtr(i);
		tmp->EnableDebug();
	}
	debugClass::EnableDebug();
}
template < class T >
void fastLinkedList<T>::DisableDebug() {
	smartPtr<T> *tmp = 0;
	
	if ( this->fastPool == 0 ) 
		return ;
	if ( this->usedPoolSize <= 0 ) 
		return ;
	//out<<"--- Fast Linked List Dump ---"<<std::endl;
	for ( int i = 0 ; i < this->usedPoolSize ; i++ ){
		tmp = this->GetSmartPtr(i);
		tmp->DisableDebug();
	}
	debugClass::DisableDebug();
}
//--------------------------------------------
// the implementation of linkedListItme
template < class T >
linkedListItem<T>::linkedListItem():
	_value(0), _next(0), _prev(0)
{
}
template < class T >
linkedListItem<T>::~linkedListItem() {
	
	//std::cout<<"Destory\tlinkedListItem"<<std::endl;
	
	if ( this->_value != 0 ) {
		delete _value;
	}
}
template < class T >
int linkedListItem<T>::SetValue( T* value ) {
	this->_value = new smartPtr<T>(value);
	//this->_value->EnableDebug();
}
template < class T >
int linkedListItem<T>::SetValue( smartPtr<T> *svalue) {
	this->_value = new smartPtr<T>(svalue);
	//this->_value->EnableDebug();
}
template < class T >
int linkedListItem<T>::SetNext(linkedListItem *item) {
	this->_next = item;
}

template < class T >
int linkedListItem<T>::SetPrev(linkedListItem *item) {
	this->_prev = item;
}

template < class T >
T* linkedListItem<T>::GetValue() {
	return *(*_value);
}
template < class T >
smartPtr<T>* linkedListItem<T>::GetSmartPtr() {
	return this->_value;
}
template < class T >
linkedListItem<T>* linkedListItem<T>::GetNext() {
	return this->_next;
}

template < class T >
linkedListItem<T>* linkedListItem<T>::GetPrev() {
	return this->_prev;
}
#endif
