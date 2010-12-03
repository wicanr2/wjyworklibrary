#include <utils/thread/threadWorker.hpp>

void* threadWorker::DoWork(void *pThis)
{

	if ( pThis == 0 ) pthread_exit(NULL);
	threadWorker *thw = (threadWorker*) pThis;

	if ( thw->GetDetachable() )
		pthread_detach( pthread_self() );

	if ( thw->GetDebugFlagLevel3() )
		printf("Call\t threadWorker[%s]::DoWork()\n",thw->name);

	if ( thw->GetActive() == false ) 
		pthread_exit(NULL);

	while ( true ) {
		if ( thw->GetInterrupt() ) {
			break;
		}
		if ( thw->wt == Thread::Inherited ){
			thw->DoRealWork();
		} else if ( thw->wt == Thread::FunctionPointer ) {
			if ( thw->work_func != 0 )
				(*thw->work_func)(thw->work_func_args);	
		}
		pthread_yield();
		if ( thw->st != Thread::NoSleep )
			thw->DoSleep();
	}

	thw->SetInterrupt( false );
	if ( thw->GetDetachable() )
		thw->SetActive( false );

	pthread_exit(NULL);
}
void threadWorker::DoRealWork()
{
	MACRO_DEBUG_CLASS_PRINT_L3("Call\t threadWorker[%s]::DoRealWork()\n",
		MACRO_VAR_ACCESS_GET_DIRECT(this,name)	);

	MACRO_DEBUG_CLASS_PRINT_L3("Hello World, I am thread %u\n", 
		(unsigned int)MACRO_VAR_ACCESS_GET_DIRECT(this, threadID) );
	//printf("mutexLocker addr :%d\n", (int)&this->ML );
}
int threadWorker::DoSleep()
{
	MACRO_DEBUG_CLASS_PRINT_L3("Call\t threadWorker[%s]::DoSleep()\n",
		MACRO_VAR_ACCESS_GET_DIRECT(this,name)	);
	if ( this->st == Thread::SleepInSecond ) {
		MACRO_DEBUG_CLASS_PRINT_L4("sleep %d\n", 
			MACRO_VAR_ACCESS_GET_DIRECT( this, sleepInterval ) );
		sleep( MACRO_VAR_ACCESS_GET_DIRECT( this, sleepInterval ) );
	}
	if ( this->st == Thread::SleepInNanoSecond ) {
		MACRO_DEBUG_CLASS_PRINT_L4("sleep %ld\n", 
			MACRO_VAR_ACCESS_GET_DIRECT( this, usleepInterval ) );
		usleep( MACRO_VAR_ACCESS_GET_DIRECT( this, usleepInterval ) );
	}
	return 0;
}
