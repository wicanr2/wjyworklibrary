#include <utils/thread/threadWorker.hpp>

threadWorker::threadWorker():
	bActive(false), 	
	bInterrupt(false),
	bDetachable(false),
	sleepInterval(1),
	usleepInterval(1000),
	st(Thread::SleepInSecond),
	wt(Thread::Inherited),
	threadID(0),
	work_func(0),
	work_func_args(0)
{
	char n[] = "ThreadWorker";
	snprintf( MACRO_VAR_ACCESS_GET_DIRECT(this, name), 255, "%s", n );		
}
threadWorker::threadWorker(char *n):
	bActive(false), 	
	bInterrupt(false),
	bDetachable(false),
	sleepInterval(1),
	usleepInterval(1000),
	st(Thread::SleepInSecond),
	wt(Thread::Inherited),
	threadID(0),
	work_func(0),
	work_func_args(0)
{
	snprintf( MACRO_VAR_ACCESS_GET_DIRECT(this, name), 255, "%s", n );		
}
threadWorker::threadWorker(char *n, threadFuncPtr fp):
	bActive(false), 	
	bInterrupt(false),
	bDetachable(false),
	sleepInterval(1),
	usleepInterval(1000),
	st(Thread::SleepInSecond),
	wt(Thread::FunctionPointer),
	threadID(0),
	work_func(0),
	work_func_args(0)
{
	snprintf( MACRO_VAR_ACCESS_GET_DIRECT(this, name), 255, "%s", n );		
	MACRO_VAR_ACCESS_SET_DIRECT(this, work_func, fp);
}
threadWorker::~threadWorker()
{
}
