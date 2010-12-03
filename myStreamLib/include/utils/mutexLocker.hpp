#ifndef MUTEX_LOCKER_HPP
#define MUTEX_LOCKER_HPP
#include <cstdio>
#include <pthread.h>
#include <utils/debugClass.hpp>
class mutexLocker:public debugClass {
private:
	pthread_mutex_t mutex;
	bool bCreated;
public:
	mutexLocker();
	~mutexLocker();
	void Lock  ();
	void Unlock();
};

#endif
