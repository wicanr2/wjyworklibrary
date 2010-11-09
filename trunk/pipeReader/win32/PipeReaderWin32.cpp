#include "PipeReader.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
pipeReader::pipeReader() :
	outputPool(0),outputPoolSize(0),lineSize(0),
	usedSize(0)
{
	int _64k = 64 * 1024 * 1024 ;
	this->SetLineSize(80);
	this->SetOutputPoolSize( _64k );
}
pipeReader::~pipeReader() {
}

int pipeReader::SetLineSize(int lSize) {
	this->lineSize = lSize;
	return 0;
}
int pipeReader::SetOutputPoolSize(int oSize) {
	if ( this->outputPool != 0 ) {
		free(outputPool);
	}
	this->outputPoolSize = oSize;
	if ( this->outputPoolSize > 0 ) {
		this->outputPool = 
			(char*) malloc(sizeof(char) * this->outputPoolSize );
	} else {
		return -1;
	}
	return 0;
}

int pipeReader::RunCommand(char *cmd ) {
	FILE *pfp = _popen(cmd,"r");
	int totalSize = 0;
	int curSize = 0;
	int i = 0 ;
	char *nextPtr = 0;
	if ( pfp == 0) 
		return -1;
	if ( this->outputPool == 0 ) 
		return -1;
	if ( this->lineSize == 0 )
		return -1;
	for ( i = 0 ; i < this->outputPoolSize ; i++ ){
		this->outputPool[i] = 0;
	}
	while ( true ) {
		nextPtr = fgets( (this->outputPool + totalSize), this->lineSize, pfp ) ;
		if ( nextPtr == 0 )
				break;
		totalSize += this->lineSize;
	}
	_pclose(pfp);
	
	this->usedSize = totalSize;
	return totalSize;
}
int pipeReader::Dump() {
	int curSize = 0;
	char buf[500];
	int i = 0;
	if ( this->outputPool == 0 ) 
		return -1;
	if ( this->outputPoolSize == 0 )
		return -1;
	if ( this->lineSize == 0 )
		return -1;
	while ( curSize < this->usedSize ) {
		snprintf( buf, this->lineSize, "%s",  this->outputPool + curSize );
		printf("[%d] %s\n", i, buf );
		i ++ ;
		curSize += this->lineSize;
	}
	return 0;
}
