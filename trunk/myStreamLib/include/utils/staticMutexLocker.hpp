#ifndef STATIC_MUTEX_LOCKER_HPP
#define STATIC_MUTEX_LOCKER_HPP
#include <cstdio>
#include <pthread.h>
#include <utils/debugClass.hpp>
class staticMutexLocker:public debugClass {
private:
	pthread_mutex_t mutex;
	bool bCreated;
public:
	staticMutexLocker();
	~staticMutexLocker();
	static void Lock  (staticMutexLocker *sMutex);
	static void Unlock(staticMutexLocker *sMutex);
};

#endif
