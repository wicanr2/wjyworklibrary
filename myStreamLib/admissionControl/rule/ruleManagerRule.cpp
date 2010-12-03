#include <admissionControl/rule/ruleManager.hpp>
int ruleManager::InitRuleList()
{
	MACRO_DEBUG_CLASS_PRINT_L4("Call \truleManager::InitRuleList()\n");
	MACRO_ERROR_CHECK_0_WITH_DEBUG(this->list);
	char profile[] = PROFILE_ADAPTIVE_DB_NAME ;
	char rule   [] = XML_ADAPTIVE_RULE_ELEMENT_NAME ;                        
	char name[] = XML_ADAPTIVE_RULE_ELEMENT_ATTR_NAME;
	char category[] = XML_ADAPTIVE_RULE_ELEMENT_ATTR_CATEGORY;
	char type[] = XML_ADAPTIVE_RULE_ELEMENT_ATTR_TYPE;
	char target[] = XML_ADAPTIVE_RULE_ELEMENT_ATTR_TARGET;
	char response_action[] = XML_ADAPTIVE_RULE_ELEMENT_ATTR_RESPONSE_ACTION;        
	char trigger_unit[] = XML_ADAPTIVE_RULE_ELEMENT_ATTR_TRIGGER_UNIT;
	char trigger_bandwidth_min[] = XML_ADAPTIVE_RULE_ELEMENT_ATTR_TRIGGER_BANDWIDTH_MIN;
	char trigger_bandwidth_max[] = XML_ADAPTIVE_RULE_ELEMENT_ATTR_TRIGGER_BANDWIDTH_MAX;
	char callback_action[] = XML_ADAPTIVE_RULE_ELEMENT_ATTR_CALLBACK_ACTION;
	char callback_argument_size[] = XML_ADAPTIVE_RULE_ELEMENT_ATTR_CALLBACK_ARGUMENT_SIZE;
	char callback_argument_1[] = XML_ADAPTIVE_RULE_ELEMENT_ATTR_CALLBACK_ARGUMENT_1;
	char callback_argument_2[] = XML_ADAPTIVE_RULE_ELEMENT_ATTR_CALLBACK_ARGUMENT_2;
	char callback_argument_3[] = XML_ADAPTIVE_RULE_ELEMENT_ATTR_CALLBACK_ARGUMENT_3;
	char callback_argument_4[] = XML_ADAPTIVE_RULE_ELEMENT_ATTR_CALLBACK_ARGUMENT_4;
	char callback_argument_5[] = XML_ADAPTIVE_RULE_ELEMENT_ATTR_CALLBACK_ARGUMENT_5;
	char buf[255];
	int i = 0;
	int size = 0;
	adaptiveRule *p = 0;
	size = XCFG2_GetElements ( profile, rule );
	if ( size <= 0 ) return -1;
	for ( i = 0 ; i < size ; i ++ ) {
		p = new adaptiveRule();	

		XCFG2_GetElementsI(i);

		snprintf(buf,255,"%s",XCFG2_GetElementAttribute(name));
		MACRO_VAR_STR_SET_DIRECT_64 ( p, name, buf );

		snprintf(buf,255,"%s",XCFG2_GetElementAttribute(category));
		MACRO_VAR_STR_SET_DIRECT_64 ( p, category, buf );
		
		snprintf(buf,255,"%s",XCFG2_GetElementAttribute(type));
		MACRO_VAR_STR_SET_DIRECT_64 ( p, type, buf );

		snprintf(buf,255,"%s",XCFG2_GetElementAttribute(target));
		MACRO_VAR_STR_SET_DIRECT_64 ( p, target, buf );

		snprintf(buf,255,"%s",XCFG2_GetElementAttribute(response_action));
		MACRO_VAR_STR_SET_DIRECT_64 ( p, response_action , buf );

		snprintf(buf,255,"%s",XCFG2_GetElementAttribute(trigger_unit));
		MACRO_VAR_STR_SET_DIRECT_64 ( p, trigger_unit, buf );

		snprintf(buf,255,"%s",XCFG2_GetElementAttribute(callback_action));
		MACRO_VAR_STR_SET_DIRECT_64 ( p, callback_action , buf );
		MACRO_VAR_ACCESS_SET_DIRECT( p, callback, CB_REG_GET_CALLBACK(buf) );

		snprintf(buf,255,"%s",XCFG2_GetElementAttribute(callback_argument_1));
		MACRO_VAR_STR_SET_DIRECT_64 ( p, cb_arg1 , buf );

		snprintf(buf,255,"%s",XCFG2_GetElementAttribute(callback_argument_2));
		MACRO_VAR_STR_SET_DIRECT_64 ( p, cb_arg2 , buf );

		snprintf(buf,255,"%s",XCFG2_GetElementAttribute(callback_argument_3));
		MACRO_VAR_STR_SET_DIRECT_64 ( p, cb_arg3 , buf );

		snprintf(buf,255,"%s",XCFG2_GetElementAttribute(callback_argument_4));
		MACRO_VAR_STR_SET_DIRECT_64 ( p, cb_arg4 , buf );

		snprintf(buf,255,"%s",XCFG2_GetElementAttribute(callback_argument_5));
		MACRO_VAR_STR_SET_DIRECT_64 ( p, cb_arg5 , buf );
		
		snprintf(buf,255,"%s", XCFG2_GetElementAttribute(callback_argument_size) );
		MACRO_VAR_ACCESS_SET_DIRECT( p, arguments_size, atoi(buf) );

		snprintf(buf,255,"%s", XCFG2_GetElementAttribute(trigger_bandwidth_min) );
		MACRO_VAR_ACCESS_SET_DIRECT( p, trigger_bandwidth_min , atoi(buf) );
	
		snprintf(buf,255,"%s", XCFG2_GetElementAttribute(trigger_bandwidth_max) );
		MACRO_VAR_ACCESS_SET_DIRECT( p, trigger_bandwidth_max , atoi(buf) );

		p->cba.size   = MACRO_VAR_ACCESS_GET_DIRECT(p, arguments_size);
		p->cba.target = MACRO_VAR_ACCESS_GET_DIRECT(p, target);
		p->cba.arg[0] = MACRO_VAR_ACCESS_GET_DIRECT(p, cb_arg1);
		p->cba.arg[1] = MACRO_VAR_ACCESS_GET_DIRECT(p, cb_arg2);
		p->cba.arg[2] = MACRO_VAR_ACCESS_GET_DIRECT(p, cb_arg3);
		p->cba.arg[3] = MACRO_VAR_ACCESS_GET_DIRECT(p, cb_arg4);
		p->cba.arg[4] = MACRO_VAR_ACCESS_GET_DIRECT(p, cb_arg5);
		this->list->AppendItem(p);
		p = 0 ;
	}
	return 0;
}
int ruleManager::TriggerRule(float v)
{
	MACRO_DEBUG_CLASS_PRINT_L4("Call \truleManager::TriggerRule()\n");
	MACRO_ERROR_CHECK_0_WITH_DEBUG(this->list);
	adaptiveRule *p = 0;
	for ( int i = 0 ; i < this->list->GetUsedPoolSize(); i++ )
	{
		p = (*this->list)[i];
		if ( p != 0 ) p->Trigger(v);		
	}
	return 0;
}
int ruleManager::RefreshRule()
{
	MACRO_DEBUG_CLASS_PRINT_L4("Call \truleManager::RefreshRule()\n");
	MACRO_ERROR_CHECK_0_WITH_DEBUG(this->list);
	this->list->RemoveAllItem();
	char profile[] = PROFILE_ADAPTIVE_DB_NAME ;
	XCFG2_ParseProfile ( profile );
	this->InitRuleList();
	return 0;
}	
