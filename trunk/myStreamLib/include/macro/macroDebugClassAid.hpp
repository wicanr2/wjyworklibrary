#ifndef MACRO_DEBUG_CLASS_AID_HPP
#define MACRO_DEBUG_CLASS_AID_HPP

#define MACRO_DEBUG_CLASS_PRINT(...)\
	do{\
		if ( this->GetDebugFlag() ){\
			printf(__VA_ARGS__);\
		}\
	}while(0)

#define	MACRO_DEBUG_CLASS_PRINT_WITH(funcName, ...)\
	do{\
		if ( this->Get##funcName() ) {\
			printf(__VA_ARGS__);\
		}\
	}while(0)

#define	MACRO_DEBUG_CLASS_PRINT_LEVEL(level, ...)\
	MACRO_DEBUG_CLASS_PRINT_WITH( DebugFlagLevel##level,__VA_ARGS__) 

#define MACRO_DEBUG_CLASS_PRINT_L2(...)\
	MACRO_DEBUG_CLASS_PRINT_LEVEL(2, __VA_ARGS__)

#define MACRO_DEBUG_CLASS_PRINT_L3(...)\
	MACRO_DEBUG_CLASS_PRINT_LEVEL(3, __VA_ARGS__)
	
#define MACRO_DEBUG_CLASS_PRINT_L4(...)\
	MACRO_DEBUG_CLASS_PRINT_LEVEL(4, __VA_ARGS__)

#define MACRO_DEBUG_CLASS_PRINT_L5(...)\
	MACRO_DEBUG_CLASS_PRINT_LEVEL(5, __VA_ARGS__)

#define MACRO_DEBUG_CLASS_PRINT_L6(...)\
	MACRO_DEBUG_CLASS_PRINT_LEVEL(6, __VA_ARGS__)

#define MACRO_DEBUG_CLASS_ENABLE_DISABLE_DECL( funcName )\
	public:\
		void Enable##funcName();\
		void Disable##funcName();

#define MACRO_DEBUG_CLASS_ENABLE_DISABLE_IMPL( cls, funcName, var )\
	void cls::Enable##funcName() {\
		this->var = true;\
	}\
	void cls::Disable##funcName() {\
		this->var = false;\
	}

#define MACRO_DEBUG_CLASS_ERROR_CHECK_WITH_LEVEL(level,rval,rv)\
	MACRO_ERROR_CHECK_WITH_NO_DEBUG(this->GetDebugFlagLevel##level(),rval,rv)

// no specify = return -1;
// RV0 = return 0;
// NORV = return;
#define MACRO_DEBUG_CLASS_ERROR_CHECK_FALSE_L2()\
	MACRO_DEBUG_CLASS_ERROR_CHECK_WITH_LEVEL(2,false,-1)

#define MACRO_DEBUG_CLASS_ERROR_CHECK_FALSE_L3()\
	MACRO_DEBUG_CLASS_ERROR_CHECK_WITH_LEVEL(3,false,-1)

#define MACRO_DEBUG_CLASS_ERROR_CHECK_FALSE_L4()\
	MACRO_DEBUG_CLASS_ERROR_CHECK_WITH_LEVEL(4,false,-1)

#define MACRO_DEBUG_CLASS_ERROR_CHECK_FALSE_L5()\
	MACRO_DEBUG_CLASS_ERROR_CHECK_WITH_LEVEL(5,false,-1)

#define MACRO_DEBUG_CLASS_ERROR_CHECK_FALSE_L6()\
	MACRO_DEBUG_CLASS_ERROR_CHECK_WITH_LEVEL(6,false,-1)


#endif
