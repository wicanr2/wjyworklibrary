#ifndef TRHEAD_WORKER_HPP
#define TRHEAD_WORKER_HPP

#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#include <utils/debugClass.hpp>
#include <utils/mutexLocker.hpp>
#include <utils/thread/threadFuncPtr.h>
#include <macro/macroVariableAccess.hpp>
#include <macro/macroErrorCheck.hpp>
namespace Thread { 
	enum SleepType {
		SleepInSecond,
		SleepInNanoSecond,
		NoSleep
	};
	enum WorkType {
		Inherited,
		FunctionPointer
	};
};

class threadWorker:public debugClass {
protected:
	char	  name[255];
	mutexLocker ML;
	// thread action
	static void* DoWork(void *pThis);
	virtual void DoRealWork();
	int DoSleep();

	MACRO_VAR_DECL_FULL( bool, Active    , bActive     );
	MACRO_VAR_DECL_FULL( bool, Interrupt , bInterrupt  );
	MACRO_VAR_DECL_FULL( bool, Detachable, bDetachable );

	MACRO_VAR_ACCESS_DECL_DIRECT( unsigned int     , sleepInterval  );
	MACRO_VAR_ACCESS_DECL_DIRECT( unsigned long    , usleepInterval );
	MACRO_VAR_ACCESS_DECL_DIRECT( Thread::SleepType, st             );
	MACRO_VAR_ACCESS_DECL_DIRECT( Thread::WorkType , wt             );
	MACRO_VAR_ACCESS_DECL_DIRECT( pthread_t        , threadID       );
	MACRO_VAR_ACCESS_DECL_DIRECT( threadFuncPtr    , work_func      );
	MACRO_VAR_ACCESS_DECL_DIRECT( void *           , work_func_args );
public:
	threadWorker();
	threadWorker(char *n);
	threadWorker(char *n, threadFuncPtr fp);
	~threadWorker();
	
	int ActivateThread();
	int StopThread();
	int WaitThreadJoin();	
	int KillThread();
};

#endif
