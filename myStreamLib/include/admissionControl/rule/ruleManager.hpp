#ifndef RULE_MANAGER_HPP
#define RULE_MANAGER_HPP
#include <iostream>
#include <iomanip>
#include <utils/debugClass.hpp> 
#include <utils/staticMutexLocker.hpp>
#include <utils/mutexLocker.hpp>
#include <macro/macroErrorCheck.hpp>
#include <macro/macroVariableAccess.hpp>
#include <macro/macroLoggerAid.hpp>
#include <admissionControl/rule/rule.hpp>
#include <list/fastLinkedList.hpp>
#include <utils/smartPointer.hpp>
#include <callbackRegister/callbackRegisterCAPI.h>
#include <xmlConfig/constant.hpp>
#include <xmlConfig/xmlConfig2CPPAPI.hpp>

typedef fastLinkedList<adaptiveRule> ruleList;
class ruleManager:public debugClass {
private:
	ruleList *list;

	static ruleManager* instance;
	// static mutex
	static staticMutexLocker sMutex;
	// mutex locker
	mutexLocker ML;
	
	int InitRuleList();
	
	ruleManager();
	~ruleManager();

public:
	static ruleManager* 
		getInstance();
	static void 
		putInstance();
	
	int TriggerRule(float v);
	int RefreshRule();	
	std::ostream& Dump(std::ostream& out)const; 

	friend std::ostream& operator<< 
		(std::ostream &out, ruleManager& rhs) 
	{
		if ( rhs.GetDebugFlagLevel4() ) 
			rhs.Dump(out);
		return out;
	}
};

#endif

