#ifndef CALLBACK_REGISTER_HPP
#define CALLBACK_REGISTER_HPP
#include <iostream>
#include <iomanip>
#include <hash_func/hashFuncTable.hpp>
#include <utils/debugClass.hpp> 
#include <utils/staticMutexLocker.hpp>
#include <utils/mutexLocker.hpp>
#include <macro/macroErrorCheck.hpp>
#include <macro/macroVariableAccess.hpp>
#include <macro/macroLoggerAid.hpp>

class callbackRegister:public debugClass {
private:
	hashFuncTable *hft; 
	static callbackRegister* instance;
	// static mutex
	static staticMutexLocker sMutex;
	// mutex locker
	mutexLocker ML;

	callbackRegister();
	~callbackRegister();
public:
	static callbackRegister* 
		getInstance();
	static void 
		putInstance();

	int PutCallback
		( char* name, hashFuncEntryPtr ptr);			
	hashFuncEntryPtr  GetCallback ( char *name );
		
	std::ostream& Dump(std::ostream& out)const; 
	
	friend std::ostream& operator<< 
		(std::ostream &out, callbackRegister& rhs) 
	{
		if ( rhs.GetDebugFlagLevel4() ) 
			rhs.Dump(out);
		return out;
	}
};
#endif
