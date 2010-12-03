#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <xmlConfig/xmlConfig2CPPAPI.hpp>
#include <utils/directorySubsidiary.h>
#include <hash/hashTable.hpp>
#include <conference/parameterManager/parameterManager.hpp>
#include <conference/parameterManager/parameterManagerCAPI.h>
#include <pthread.h>
void *WorkWrapper(void* ptr) {
	printf(" thread wrapper \n" );
	XCFG2_Init();
	pthread_exit(NULL);
}
int main( int argc, char *argv[] ) {
	hashTable *ht = new hashTable();
	{
		char name[] = "Test";
		ht->PutValue ( 	name ,HASH_ENTRY_TYPE_INT, new int(5566)); 
	}
	{
		char name[] = "Test1";
		ht->PutValue ( 	name ,HASH_ENTRY_TYPE_INT, new int(5566)); 
	}
	{
		char name[] = "Test2";
		ht->PutValue ( 	name ,HASH_ENTRY_TYPE_INT, new int(5566)); 
	}
	{
		char name[] = "Test3";
		ht->PutValue ( 	name ,HASH_ENTRY_TYPE_INT, new int(5566)); 
	}
	{
		char name[] = "Test4";
		ht->PutValue ( 	name ,HASH_ENTRY_TYPE_INT, new int(5566)); 
	}
	{
		char name[] = "Test5";
		ht->PutValue ( 	name ,HASH_ENTRY_TYPE_INT, new int(5566)); 
	}

	{
		char name[] = "Test6";
		ht->PutValue ( 	name ,HASH_ENTRY_TYPE_INT, new int(5566)); 
	}
	int X = 1000;
	{
		char name[] = "Test7";
		ht->PutValue ( 	name ,HASH_ENTRY_TYPE_INT, &X ); 
	}
	int y = 500;
	{
		char name[] = "Test8";
		ht->PutValue ( 	name ,HASH_ENTRY_TYPE_INT, &y ); 
	}
	int z = 555;
	{
		char name[] = "Test9";
		ht->PutValue ( 	name ,HASH_ENTRY_TYPE_INT, &z ); 
	}
	int h = 777;	
	{
		char name[] = "Test10";
		ht->PutValue ( 	name ,HASH_ENTRY_TYPE_INT, &h ); 
	}
	std::cout << *ht ;
	//return 0;
/*	hashString<int> *HSI = new hashString<int>();	
	{
		char key[] = "1234" ;
		HSI->PutValue( key , new int(1234) );
	}
	{
		char key[] = "5678" ;
		HSI->PutValue( key , new int(5678) );
	}
	{
		char key[] = "Wang" ;
		HSI->PutValue( key , new int(710402) );
	}
	{
		char key[] = "Momo"; 
		HSI->PutValue( key , new int(710106) );
	}
	HSI->EnableDebug();
	std::cout << *HSI << std::endl;
	delete HSI; 
	return 0; */
	{
		pthread_t threads[10];
		int i = 0;
		for ( i = 0 ; i < 10 ; i++ ){
			pthread_create(
				&threads[i],
				NULL,
				WorkWrapper,
				NULL );
		}
		for ( i = 0; i < 10 ; i++ ) {
			pthread_join( threads[i], NULL );
		}
	}	
	{	
		// get parameter pointer
		// hash mapping 
		int r =	XCFG2_Init();	
		printf(" r = %d\n", r );
		XCFG2_Init();	
		XCFG2_Init();	
		XCFG2_Init();	
		XCFG2_Dump();
		char role  [] = ROLE_TRANSMITTER;
		char stream[] = TRANSCODE_MJPEG_TO_H264_STREAM ;
		char para  [] = PARA_VIDEORATE_FILTER;
		paraBase *tmp = 0;
		//PARAMETER_MANAGER_EnableDebug();
		PARAMETER_MANAGER_QueryStreamParams ( role, stream );
		for ( int i = 0 ; 
			 i < PARAMETER_MANAGER_GetQueryStreamParamsSize() ; 
			 i++ ) 
		{
			tmp = (paraBase*) PARAMETER_MANAGER_QueryStreamParamsI(i);
			if ( tmp != 0 ) { 
				std::cout << *tmp ;
				printf("do hashmapping\n");
				r = XCFG2_HashMapping( stream, tmp );
				if ( r >= 0 ) {
					printf(" parameter hash mapping successfully\n" );
					std::cout << *tmp ;
				}
			}		
		}
		PARAMETER_MANAGER_PutInstance();
		return 0;
		/*tmp = (paraBase*) PARAMETER_MANAGER_Query
			(role, stream, para );
		printf(" get parameter %s in %s(%s)\n",
			para, stream, role );
		//std::cout << *tmp;
		//std::cout << std::endl;
		if ( tmp != 0 ) { 
			std::cout << *tmp ;
			printf("do hashmapping\n");
			XCFG2_HashMapping( stream, tmp );
			std::cout << *tmp ;
		}
		return 0;*/
	}
	{
		char name [] = XML_SUMMARY_PROFILE_NAME;
		char file[] = XML_SUMMARY_PROFILE_LOCATION;
		char location[] = XML_SUMMARY_PROFILE_PATH;
		char finalPath[255];
		DirSub_MakeFullPath( finalPath, 255, location, file );
		XCFG2_AddProfile( name , file );
		XCFG2_Dump();
		char element[] = "Profile";
		char attr_name[] ="name";
		char attr_location[] = "location";
		int size =
		XCFG2_GetElements( name, element );		
		printf("size = %d\n", size );
		for ( int i = 0 ; i < size ; i++ ) {
			XCFG2_GetElementsI(i);
			printf(" element name =%s\n", 
				XCFG2_GetElementName() );		
			printf(" value =%s\n", XCFG2_GetElementValue() );		
			printf(" attr name = %s\n",
				XCFG2_GetElementAttribute( attr_name ));
			printf(" attr location = %s\n",
				XCFG2_GetElementAttribute( attr_location ));
		}
		XCFG2_GetElements( name, element );		
		printf("size = %d\n", size );
		for ( int i = 0 ; i < size ; i++ ) {
			XCFG2_GetElementsI(i);
			printf(" element name =%s\n", 
				XCFG2_GetElementName() );		
			printf(" value =%s\n", XCFG2_GetElementValue() );		
			printf(" attr name = %s\n",
				XCFG2_GetElementAttribute( attr_name ));
			printf(" attr location = %s\n",
				XCFG2_GetElementAttribute( attr_location ));
		}
	}
	return 0;
}
