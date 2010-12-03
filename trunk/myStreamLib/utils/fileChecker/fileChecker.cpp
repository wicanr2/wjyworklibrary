
#include <utils/fileChecker.hpp>

// for singleton instance
fileChecker* fileChecker::instance = NULL;

// for static mutex
staticMutexLocker fileChecker::sMutex;

fileChecker::fileChecker() {
}

fileChecker::~fileChecker() {
}

// check file exit or not
int fileChecker::CheckFileExisted( char *file ) {
	struct stat buf;
	int e = 0;
	if ( this->GetDebugFlag() )
	{
		printf("Call \tfileChecker::CheckFileExisted()\n");
	}
	if ( stat( file , &buf ) < 0 ) {
		e = errno;
		// print debug message
		if ( this->GetDebugFlag() )
			printf("\t--- \tFile: \"%s\" %s\t ---\n"
				,file, strerror(e) );
			
		if ( e == ENOENT ) {
			return -1;
		}
		return -2;
	}
	if ( this->GetDebugFlag() ) {
		printf("\t--- \tFile: \"%s\" is exited\t ---\n", file );
	}
	return 0;
}

// get instance
fileChecker* fileChecker::getInstance() {
	staticMutexLocker::Lock( &fileChecker::sMutex );
	#if 0 // "broken" optimization
	if ( !_instance )
	#else
	if ( true )
	#endif
	{
		if ( !instance ) {
			instance = new fileChecker();
		}
	}
	staticMutexLocker::Unlock( &fileChecker::sMutex );
	return instance;
}

// put instance
void fileChecker::putInstance() {
	staticMutexLocker::Lock( &fileChecker::sMutex );
	if ( instance ) {
		delete fileChecker::instance;
		fileChecker::instance = NULL;
	}
	staticMutexLocker::Unlock( &fileChecker::sMutex );
}
