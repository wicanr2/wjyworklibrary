#include<admissionControl/rule/ruleManager.hpp>
#include<admissionControl/rule/ruleManagerCAPI.h>

#ifdef __cplusplus
extern "C" {
#endif
int RULE_MGR_TRIGGER_RULE(float v)
{
	ruleManager *rm = ruleManager::getInstance();
	if ( rm == 0 ) return -1;
	return rm->TriggerRule(v);
}

int RULE_MGR_REFRESH_RULE()
{
	ruleManager *rm = ruleManager::getInstance();
	if ( rm == 0 ) return -1;
	return rm->RefreshRule();
}
int RULE_MGR_DUMP()
{
	ruleManager *rm = ruleManager::getInstance();
	if ( rm == 0 ) return -1;
	std::cout << *rm << std::endl;	
	return 0;
}
int RULE_MGR_PUT_INSTANCE()
{
	ruleManager::putInstance();
	return 0;
}
#ifdef __cplusplus
}
#endif
