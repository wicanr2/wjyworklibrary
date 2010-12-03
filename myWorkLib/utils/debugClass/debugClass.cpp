#include <utils/debugClass.hpp>
#include <utils/staticMutexLocker.hpp>
staticMutexLocker debugClass::sMutex;
bool debugClass::bReadExternalFile = false;
bool debugClass::bExnternalEnable = false;
int  debugClass::iDebugLevel= 1;

debugClass::debugClass():
	debugFlag(false),
	debugFlagLevel2(false),
	debugFlagLevel3(false), 
	debugFlagLevel4(false), 
	debugFlagLevel5(false), 
	debugFlagLevel6(false)
{
	staticMutexLocker::Lock( &debugClass::sMutex );
	if ( debugClass::bReadExternalFile == false ) {
		debugClass::bReadExternalFile = true; 
		char file[] = DEBUG_CONFIG_FILE; 
		char buf[32] ;
		FILE *pFILE = fopen( file, "r");
		if ( pFILE ) {
			fgets( buf, 32, pFILE );
			sscanf( buf, "Debug=%s", buf );
			for(int i = 0 ; i < strlen(buf); i++){
				buf[i] = tolower(buf[i]);
			}
			//printf("buf = %s\n",buf);
			if ( strncmp( buf, "enable", 32 ) == 0 )
				debugClass::bExnternalEnable = true;
			
			if ( strncmp( buf, "yes", 32 ) == 0 )
				debugClass::bExnternalEnable = true;

			if ( debugClass::bExnternalEnable ) { 
				if ( feof ( pFILE ) == 0 ) {
					fgets( buf, 32, pFILE );
					sscanf( buf, "Level=%s", buf );
					//printf("buf = %s\n",buf);
					debugClass::iDebugLevel = atoi(buf); 
					printf("The default debug level is %d.\n", debugClass::iDebugLevel );

				}
			}
			fclose(pFILE);
		} 	
	}
	staticMutexLocker::Unlock( &debugClass::sMutex );
	if ( debugClass::bExnternalEnable ) 
		this->debugFlag = true; 
	if ( debugClass::iDebugLevel <= 1 ) return; 
	switch ( debugClass::iDebugLevel ) {
		default:
		case 6:
			this->EnableDebugFlagLevel6();
		case 5:
			this->EnableDebugFlagLevel5();
		case 4:
			this->EnableDebugFlagLevel4();
		case 3:
			this->EnableDebugFlagLevel3();
		case 2:
			this->EnableDebugFlagLevel2();
		case 1:
		case 0:
			break;
	};
}
debugClass::~debugClass() {
}
void debugClass::EnableDebug(){
	this->SetDebugFlag ( true );
}
void debugClass::DisableDebug() {
	this->SetDebugFlag ( false );
}
bool debugClass::GetDebugFlag() {
	return this->debugFlag;
}
void debugClass::SetDebugFlag(bool v) {
	this->debugFlag = v;
}

MACRO_GETTER_IMPL( debugClass, bool, DebugFlagLevel2, debugFlagLevel2 );
MACRO_GETTER_IMPL( debugClass, bool, DebugFlagLevel3, debugFlagLevel3 );
MACRO_GETTER_IMPL( debugClass, bool, DebugFlagLevel4, debugFlagLevel4 );
MACRO_GETTER_IMPL( debugClass, bool, DebugFlagLevel5, debugFlagLevel5 );
MACRO_GETTER_IMPL( debugClass, bool, DebugFlagLevel6, debugFlagLevel6 );

MACRO_DEBUG_CLASS_ENABLE_DISABLE_IMPL( debugClass,  DebugFlagLevel2, debugFlagLevel2 );
MACRO_DEBUG_CLASS_ENABLE_DISABLE_IMPL( debugClass,  DebugFlagLevel3, debugFlagLevel3 );
MACRO_DEBUG_CLASS_ENABLE_DISABLE_IMPL( debugClass,  DebugFlagLevel4, debugFlagLevel4 );
MACRO_DEBUG_CLASS_ENABLE_DISABLE_IMPL( debugClass,  DebugFlagLevel5, debugFlagLevel5 );
MACRO_DEBUG_CLASS_ENABLE_DISABLE_IMPL( debugClass,  DebugFlagLevel6, debugFlagLevel6 );
