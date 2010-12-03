#include <utils/mutexLocker.hpp>

mutexLocker::mutexLocker():
	bCreated(true)
{
	if ( pthread_mutex_init( &this->mutex, NULL ) != 0 ) {
		this->bCreated = false;
	} 
}

mutexLocker::~mutexLocker() {
	MACRO_DEBUG_CLASS_PRINT_L6("Destory\tmutexLocker\n");
	if ( this->bCreated ) 
		pthread_mutex_destroy( &this->mutex );
}

void mutexLocker::Lock() {
	if ( this->bCreated )
		pthread_mutex_lock( &this->mutex );
}
void mutexLocker::Unlock() {
	if ( this->bCreated )
		pthread_mutex_unlock( &this->mutex );
}
