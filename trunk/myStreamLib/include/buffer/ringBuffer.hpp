#ifndef RING_BUFFER_H
#define RING_BUFFER_H
#include <iostream>
#include <iomanip>
#include <pthread.h>
#include <utils/debugClass.hpp>
#include <utils/mutexLocker.hpp>
#include <streamStarter/security_lock.h>

template < class T1 >
class RingBuffer:public debugClass {
private:
	int maxItemSize;
	int nextItemPtr;
	int itemSize;
	int *itemUsedBitmap;
	T1  **itemPool;
	
	void RefreshSize();
	
	// lock
#ifdef RING_BUFFER_HIGH_SECURITY_LOCK
	mutexLocker ML;
#endif
	
	
public:

	// initializer
	RingBuffer();
	~RingBuffer();
	
	// SetItemSize
	int SetMaxItemSize(int size);

	// add item
	int AddNextItem(T1 *item);
	
	// remove prev Item
	int RemovePrevItem();
	
	// erase all
	int RemoveAllItem();
	
	// GetItemNumber
	int Size();
	T1* GetItem(int i);

	// Dump
	void Dump();
	
	
};

template < class T1 >
RingBuffer<T1>::RingBuffer(): 
	maxItemSize(0),nextItemPtr(0),itemSize(0),
	itemUsedBitmap(0), itemPool(0) 
{
}
template < class T1 >
RingBuffer<T1>::~RingBuffer() {
	
	if ( this->itemUsedBitmap != 0 ) {
		delete [] this->itemUsedBitmap;
	}
	if ( this->itemPool != 0 ) {
		for ( int i = 0 ; i < this->maxItemSize ; i++ ) {
			if ( this->itemPool[i] != 0 ) {	
				delete this->itemPool[i];
				this->itemPool[i] = 0;
			}
		}
		delete [] this->itemPool;
	}
}

// set item size
template < class T1 >
int RingBuffer<T1>::SetMaxItemSize(int size) {
#ifdef RING_BUFFER_HIGH_SECURITY_LOCK
	this->ML.Lock();
#endif
	if ( this->itemPool != 0 ) {

#ifdef RING_BUFFER_HIGH_SECURITY_LOCK
		this->ML.Unlock();
#endif
	 	return -1;
	}
	if ( this->itemUsedBitmap != 0 ) {

#ifdef RING_BUFFER_HIGH_SECURITY_LOCK
		this->ML.Unlock();
#endif
		return -1;
	}
	if ( this->maxItemSize > 0 ) { 

#ifdef RING_BUFFER_HIGH_SECURITY_LOCK
		this->ML.Unlock();
#endif
		return -1;
	}
	if ( size <= 0 ) {

#ifdef RING_BUFFER_HIGH_SECURITY_LOCK
		this->ML.Unlock();
#endif
		return -1;
	}
	this->maxItemSize = size;
	this->itemUsedBitmap = new int[size];
	this->itemPool = new T1*[size];
	for ( int i = 0 ; i < this->maxItemSize ; i++ ) {	
		this->itemPool[i] = 0;
		this->itemUsedBitmap [i] = 0; 
	}
	this->nextItemPtr = 0 ;

#ifdef RING_BUFFER_HIGH_SECURITY_LOCK
	this->ML.Unlock();
#endif
	return 0;
}

template < class T1 >
void RingBuffer<T1>::RefreshSize() {
	int i = 0;
	this->itemSize = 0;
	for ( i = 0 ; i < this->maxItemSize ; i++ ) {
		if ( this->itemUsedBitmap[i] != 0 ) 
			this->itemSize++;
	}
}

template < class T1 >
int RingBuffer<T1>::AddNextItem(T1 *item) {
	if ( this->itemPool == 0 ) return -1;
	if ( this->itemUsedBitmap == 0 ) return -1;
	if ( item == 0 ) return -1;
#ifdef RING_BUFFER_HIGH_SECURITY_LOCK
	this->ML.Lock();
#endif
	if ( this->itemPool [ this->nextItemPtr ] != 0 ) 
	{
		T1 *tmp = this->itemPool [ this->nextItemPtr ] ;
		delete tmp;
		this->itemPool[ this->nextItemPtr ] = 0;
	}
	this->itemPool [ this->nextItemPtr ] = item ;
	this->itemUsedBitmap [ this->nextItemPtr ] ++ ;	
	this->nextItemPtr = ( this->nextItemPtr + 1 ) % this->maxItemSize;

#ifdef RING_BUFFER_HIGH_SECURITY_LOCK
	this->ML.Unlock();
#endif
	return 0;
}
	
// remove prev Item
template < class T1 >
int RingBuffer<T1>::RemovePrevItem(){
	if ( this->itemPool == 0 ) return -1;
	if ( this->itemUsedBitmap == 0 ) return -1;

#ifdef RING_BUFFER_HIGH_SECURITY_LOCK
	this->ML.Lock();
#endif
	int tmpPtr = this->nextItemPtr ;
	if ( this->itemPool[ tmpPtr ] != 0 ) {
		delete this->itemPool[ tmpPtr ];
		this->itemPool [ tmpPtr ] = 0;
	}
	if ( this->itemUsedBitmap[ tmpPtr ] != 0 ) {
		this->itemUsedBitmap[ tmpPtr ] = 0 ;
	}
	
	tmpPtr--;
	if ( tmpPtr < 0 ) tmpPtr = this->maxItemSize-1;
	this->nextItemPtr = tmpPtr;

#ifdef RING_BUFFER_HIGH_SECURITY_LOCK
	this->ML.Unlock();
#endif
	return 0;
}
	
// erase all
template < class T1 >
int RingBuffer<T1>::RemoveAllItem(){
	int i = 0, j = 0;
	if ( this->itemPool == 0 ) return -1;
	if ( this->itemUsedBitmap == 0 ) return -1;
#ifdef RING_BUFFER_HIGH_SECURITY_LOCK
	this->ML.Lock();
#endif
	if ( this->Size() > 0 ) {
		for ( i = 0 ; i < this->maxItemSize ; i++ ) {
			if ( this->itemPool[i] != 0 ) {
				delete this->itemPool[i];
				this->itemPool[i] = 0;
			}
		}

		for ( j = 0 ; j < this->maxItemSize ; j++ ) {
			this->itemUsedBitmap[j] = 0 ;	
		}
		this->nextItemPtr = 0;
		this->RefreshSize();
	}
#ifdef RING_BUFFER_HIGH_SECURITY_LOCK
	this->ML.Unlock();
#endif
	return 0;
}
	
// GetItemNumber
template < class T1 >
int RingBuffer<T1>::Size() { 
	this->RefreshSize();
	return this->itemSize;
}
	
template < class T1 >
T1* RingBuffer<T1>::GetItem(int i)
{	
	T1 *p = 0;
	if ( i >= 0 && i < this->maxItemSize ) {
		p = this->itemPool[i];
		if ( p == 0 ) return 0;
		return p;
	}
	return 0;	
}
template < class T1 >
void RingBuffer<T1>::Dump() {
	int i = 0;
	int width = 20;
	{
		for ( int i = 0 ; i < 80 ; i++ ) {
			std::cout << "_";
		}
		std::cout <<std::endl;
	}
	std::cout << "\tRing Buffer Dump()"; 
	std::cout << std::endl;	
	std::cout << "Size :";
	std::cout << std::setw(width); 
	std::cout << this->Size();
	std::cout << std::endl;	
	{
		for ( int i = 0 ; i < 80 ; i++ ) {
			std::cout << "-";
		}
		std::cout <<std::endl;
	}
	width = 5;
	std::cout << std::setw(width); 
	width = 20;
	std::cout << "Index";
	std::cout << std::setw(width) ;
	std::cout << "Used Times";
	std::cout << std::setw(width) ;
	std::cout << "Value" ;
	std::cout << std::endl;
	//width = 15;
	for ( i = 0 ; i < this->maxItemSize ;i ++ ) {
		if ( this->itemUsedBitmap[i] > 0
		   	 && this->itemPool[i] != 0 
	       ) {
			width = 5;
			std::cout << std::setw(width) ;
			width = 20;
			std::cout << i;
			std::cout << std::setw(width) ;
			std::cout << this->itemUsedBitmap[i];
			std::cout << std::setw(width) ;
			std::cout << *this->itemPool[i] ;
			std::cout << std::endl;
		}
	}
	{
		for ( int i = 0 ; i < 80 ; i++ ) {
			std::cout << "_";
		}
		std::cout <<std::endl;
	}
}
#endif
