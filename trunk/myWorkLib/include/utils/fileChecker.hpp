#ifndef FILE_CHECKER_HPP
#define FILE_CHECKER_HPP
#include <cstdio>
#include <errno.h>
#include <cstring>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <utils/debugClass.hpp>
#include <utils/staticMutexLocker.hpp>
class fileChecker:public debugClass {
private:
	fileChecker();
	~fileChecker();
	static fileChecker* instance;
	static staticMutexLocker sMutex;
public:
	
	int CheckFileExisted( char *file );
	static fileChecker* getInstance();
	static void putInstance();
};

#endif
