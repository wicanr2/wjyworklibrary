#include<admissionControl/rule/rule.hpp>
adaptiveRule::adaptiveRule():
	trigger_bandwidth_min(0.0f),
	trigger_bandwidth_max(0.0f),
 	arguments_size(0),
	callback(0)
{
}
adaptiveRule::~adaptiveRule()
{
}	
std::ostream& adaptiveRule::Dump(std::ostream& out)const
{
	int width=0;
	MACRO_LOGGER_PRINT_DIVIDE_LINE_2( out );
	width=30;		
	MACRO_LOGGER_PRINT_VAR( out, "Name        :", this->name, width ); 
	MACRO_LOGGER_PRINT_NEWLINE( out );
	
	MACRO_LOGGER_PRINT_VAR( out, "Type        :", this->type, width ); 
	MACRO_LOGGER_PRINT_NEWLINE( out );
	
	MACRO_LOGGER_PRINT_VAR( out, "Target      :", this->target, width ); 
	MACRO_LOGGER_PRINT_NEWLINE( out );
	
	MACRO_LOGGER_PRINT_VAR( out, "Category    :", this->category, width ); 
	MACRO_LOGGER_PRINT_NEWLINE( out );
	
	MACRO_LOGGER_PRINT_VAR( out, "ResponseAct :", this->response_action, width ); 
	MACRO_LOGGER_PRINT_NEWLINE( out );

	MACRO_LOGGER_PRINT_VAR( out, "cb_Action   :", this->callback_action, width ); 
	MACRO_LOGGER_PRINT_NEWLINE( out );

	printf("callback    :%30d\n", (int)(this->callback) ); 

	width = 10;
	MACRO_LOGGER_PRINT_VAR( out, "TriggerUnit :", this->trigger_unit, width ); 
	MACRO_LOGGER_PRINT_COMMA( out );

	MACRO_LOGGER_PRINT_VAR( out, "bandwidthMin:", this->trigger_bandwidth_min, width ); 
	MACRO_LOGGER_PRINT_COMMA( out );

	MACRO_LOGGER_PRINT_VAR( out, "bandwidthMax:", this->trigger_bandwidth_max, width ); 
	MACRO_LOGGER_PRINT_NEWLINE( out );

	MACRO_LOGGER_PRINT_VAR( out, "ArgSize     :", this->arguments_size, width ); 
	MACRO_LOGGER_PRINT_COMMA( out );

	MACRO_LOGGER_PRINT_VAR( out, "cb_Arg1     :", this->cb_arg1, width ); 
	MACRO_LOGGER_PRINT_COMMA( out );

	MACRO_LOGGER_PRINT_VAR( out, "cb_Arg2     :", this->cb_arg2, width ); 
	MACRO_LOGGER_PRINT_NEWLINE( out );

	MACRO_LOGGER_PRINT_VAR( out, "cb_Arg3     :", this->cb_arg3, width ); 
	MACRO_LOGGER_PRINT_COMMA( out );

	MACRO_LOGGER_PRINT_VAR( out, "cb_Arg4     :", this->cb_arg4, width ); 
	MACRO_LOGGER_PRINT_COMMA( out );

	MACRO_LOGGER_PRINT_VAR( out, "cb_Arg5     :", this->cb_arg5, width ); 

	MACRO_LOGGER_PRINT_DIVIDE_LINE_2( out );
	return out;
} 
