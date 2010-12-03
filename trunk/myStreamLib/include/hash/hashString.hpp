#ifndef HASH_STRING_HPP
#define HASH_STRING_HPP
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <utils/debugClass.hpp> 

#define MAX_HASH_VALUE_POOL_SIZE 89
template < class T >
class hashString:public debugClass {
private:
	T **_valuePool;
	int maxPoolSize;
	unsigned int DJBHash( char *key, int len ) {
   		unsigned int hash = 5381;
	   	unsigned int i    = 0;

	    for(i = 0; i < len; key++, i++)
	  	{
      		hash = ((hash << 5) + hash) + (*key);
   		}
   		return hash;
	}
	unsigned int DEKHash(char* str, unsigned int len)
	{
   		unsigned int hash = len;
   		unsigned int i    = 0;

 	  	for(i = 0; i < len; str++, i++)
		{
      		hash = ((hash << 5) ^ (hash >> 27)) ^ (*str);
	   	}
   		return hash;
	}
	unsigned int Hash( char *key) {
		char buf[255];
		char tmp[255];
		int size = 0;
		int i = 0, j = 0;
		size = snprintf( buf, 255, "%d%s",strlen(key),key );
		snprintf( tmp,255,"%s",key);	
		while ( size < 180 ) {	
			if ( i % 2 == 0 ) { 
				for ( j =0 ; j < strlen(tmp); j++ )
					tmp[j] = toupper(tmp[j]);
			}else {
				for ( j =0 ; j < strlen(tmp); j++ )
					tmp[j] = tolower(tmp[j]);
			}
			size += snprintf(buf+size, 255-size, "%d%s", strlen(buf),tmp );
			i++;
		}
		//printf("hash buf = %s\n", buf );
		return this->DEKHash( buf, strlen(buf) );
		//return this->DJBHash( buf, strlen(buf) );
	}
public:
	hashString(int size) : maxPoolSize(0)
	{
		this->maxPoolSize = size;
		if ( maxPoolSize <= 0 ) exit(1);
		this->_valuePool = new T*[ this->maxPoolSize ];
		for ( int i = 0 ; i <  this->maxPoolSize ; i++ ) 
		{
			this->_valuePool[i] = 0 ; 
		}
	}
	~hashString() {
			
		if ( _valuePool != 0 ) {
			for ( int i = 0 ; i <  this->maxPoolSize ; i++ ) 
			{
				if ( this->_valuePool[i] != 0 ) 
					delete _valuePool[i];
			}
				 
			delete [] _valuePool;
		}
	}
	int GetHash ( char *key ) {
		if ( key == 0 ) return -1;
		return this->Hash( key );
	}
	T*  GetValue ( int i ) {
		if ( i < 0 ) return 0;
		if ( i >= this->maxPoolSize ) return 0;
		if ( this->_valuePool[i] == 0 ) return 0;
		return this->_valuePool[i] ;
	}
	T*  GetValue ( char *key ) {
		if ( key == 0 ) return 0;
		int i = this->Hash( key );
		i = abs(i) % this->maxPoolSize; 
		if ( i < 0 ) return 0;
		if ( i >= this->maxPoolSize ) return 0;
		if ( this->_valuePool[i] == 0 ) return 0;
		return this->_valuePool[i] ;
	}
	int PutValue ( char *key, T *value ) {
		if ( key == 0 ) return -1;
		int i = this->Hash( key );
		i = abs(i) % this->maxPoolSize; 
		if ( this->_valuePool[i] != 0 ) {
			printf("!!!!!!!!!!!!! double hash value occured !!!!!!!!!!!!!\n");	
			printf("key %s\n", key );
			std::cout << *_valuePool[i] ;
	
			printf("-----------------------------------------------------\n");	
			exit(1);
			//return -1;
		}
		this->_valuePool[i] = value;
		return 0;
	}
	void Dump() {
		if ( this->GetDebugFlag() == false ) return ;
		int count = 0;
		for ( int i = 0 ; i <  this->maxPoolSize ; i++ ) 
		{
			if ( this->_valuePool[i] != 0 ) {
				std::cout << *_valuePool[i] << std::endl;
				count++;
			}
		}
		std::cout << "Hash Table Size : " << count << std::endl;
	} 
	std::ostream& Dump(std::ostream& out)const {
		int count = 0;
		for ( int i = 0 ; i <  this->maxPoolSize ; i++ ) 
		{
			if ( this->_valuePool[i] != 0 ) {
				out << *_valuePool[i] ;
				count++;
			}
		}
		std::cout << "Hash Table Size : " << count << std::endl;
		return out;
	}
	
	friend std::ostream& operator<< 
		(std::ostream &out, hashString& rhs) 
	{
		if ( rhs.GetDebugFlagLevel4() )
			rhs.Dump(out);
		return out;
	}
};

#endif
