#include<admissionControl/rule/rule.hpp>
int adaptiveRule::Trigger(float v)
{
	int i = 0;
	MACRO_ERROR_CHECK_0_WITH_DEBUG(this->callback);
	if ( v >= MACRO_VAR_ACCESS_GET_DIRECT(this, trigger_bandwidth_min ) 
		 &&	
		 v <= MACRO_VAR_ACCESS_GET_DIRECT(this, trigger_bandwidth_max ) ) 
	{
		MACRO_DEBUG_CLASS_PRINT_L2("Trigger Event %9s at value is %5.2f\n",this->name,v);
		this->callback( &(this->cba) );
	}
	return 0;
}
