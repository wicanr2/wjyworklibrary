#include <utils/staticMutexLocker.hpp>


staticMutexLocker::staticMutexLocker():
	bCreated(true)
{
	if ( pthread_mutex_init( &this->mutex, NULL ) != 0 ) {
		this->bCreated = false;
	} 
}

staticMutexLocker::~staticMutexLocker() {
	MACRO_DEBUG_CLASS_PRINT_L6("Destory\tstaticMutexLocker\n");

	if ( this->bCreated ) 
		pthread_mutex_destroy( &this->mutex );
}

void staticMutexLocker::Lock(staticMutexLocker *sMutex) {
	if ( sMutex->bCreated )
		pthread_mutex_lock( &sMutex->mutex );
}
void staticMutexLocker::Unlock(staticMutexLocker *sMutex) {
	if ( sMutex->bCreated )
		pthread_mutex_unlock( &sMutex->mutex );
}
