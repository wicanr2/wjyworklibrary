#include <utils/fileChecker.hpp>
#include <utils/fileCheckerCAPI.h>

#ifdef __cplusplus
extern "C" {
#endif
int FC_CheckFileExisted( char* file ) {
	fileChecker *fc = fileChecker::getInstance();
	if ( fc )
		return fc->CheckFileExisted( file );
	return -1;
}
void FC_EnableDebug() {
	fileChecker *fc = fileChecker::getInstance();
	if ( fc )
		fc->EnableDebug();
	
}
void FC_Destory() {
	fileChecker::putInstance();
}

#ifdef __cplusplus
}
#endif
