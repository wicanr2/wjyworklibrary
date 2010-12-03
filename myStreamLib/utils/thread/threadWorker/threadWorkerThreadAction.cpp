#include <utils/thread/threadWorker.hpp>
#include <signal.h>
int threadWorker::ActivateThread()
{
	MACRO_DEBUG_CLASS_PRINT_L3("Call\t threadWorker[%s]::CreateThread()\n",
		MACRO_VAR_ACCESS_GET_DIRECT(this,name)	);

	int r = 0;
	if ( this->GetActive() ) {
		MACRO_DEBUG_CLASS_PRINT_L3("Thread[%s] had been activated.\n",
				MACRO_VAR_ACCESS_GET_DIRECT(this,name)	);
		return -1;
	}

	pthread_attr_t attr;
	pthread_attr_init ( &attr );
	
	if ( this->GetDetachable() ) {
		pthread_attr_setdetachstate ( 
			&attr, 
			PTHREAD_CREATE_DETACHED
		);
	} else {
		pthread_attr_setdetachstate ( 
			&attr, 
			PTHREAD_CREATE_JOINABLE 
		);
	}
	ML.Lock();	
	r = pthread_create( 
			&this->threadID, 
			&attr,
			threadWorker::DoWork,
			(void*) this);

	pthread_attr_destroy( &attr );
	if ( r == 0 ) this->bActive = true;
	ML.Unlock();
	return r;
}
int threadWorker::StopThread()
{
	MACRO_DEBUG_CLASS_PRINT_L3("Call\t threadWorker[%s]::StopThread()\n",
		MACRO_VAR_ACCESS_GET_DIRECT(this,name)	);
	if ( this->GetActive() == false ) {
		MACRO_DEBUG_CLASS_PRINT_L3("Thread[%s] was not been activated.\n",
				MACRO_VAR_ACCESS_GET_DIRECT(this,name)	);
		return -1;
	}
	this->SetInterrupt(true);
	return 0;
}
int threadWorker::WaitThreadJoin()
{
	MACRO_DEBUG_CLASS_PRINT_L3("Call\t threadWorker[%s]::WaitThreadJoin()\n",
		MACRO_VAR_ACCESS_GET_DIRECT(this,name)	);
	if ( this->GetActive() == false ) {
		MACRO_DEBUG_CLASS_PRINT_L3("Thread[%s] was not been activated.\n",
				MACRO_VAR_ACCESS_GET_DIRECT(this,name)	);
		return -1;
	}
	if ( this->GetDetachable() ) {
		MACRO_DEBUG_CLASS_PRINT_L3("Thread[%s] is detachable.\n",
				MACRO_VAR_ACCESS_GET_DIRECT(this,name)	);
		return -1;
	}
	if ( this->GetInterrupt() == false ) {
		MACRO_DEBUG_CLASS_PRINT_L3("Thread[%s] is running, try to stop it.\n",
				MACRO_VAR_ACCESS_GET_DIRECT(this,name)	);
		this->StopThread();
	}

	MACRO_DEBUG_CLASS_PRINT_L4("\tWaiting for Thread[%s] Joining.\n",
		MACRO_VAR_ACCESS_GET_DIRECT(this,name)	);
	pthread_join( this->threadID, NULL );	
	this->threadID = 0;
	this->SetActive( false );

	return 0;
}

int threadWorker::KillThread()
{
	//pthread_kill( this->threadID, SIGKILL);	
	//pthread_kill( this->threadID, SIGSTOP);	
	return 0;
}
