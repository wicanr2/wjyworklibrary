#ifndef TRIGGER_RULE_HPP
#define TRIGGER_RULE_HPP
#include <iostream>
#include <iomanip>
#include <utils/debugClass.hpp> 
#include <macro/macroErrorCheck.hpp>
#include <macro/macroHashFuncTableAid.hpp>
#include <macro/macroLoggerAid.hpp>
#include <macro/macroVariableAccess.hpp>
#include <hash_func/hashFuncType.h>
#include <callbackRegister/callbackArguments.h>
class adaptiveRule:public debugClass{
private:
	MACRO_VAR_STR_DECL_DIRECT_64( name            );
	MACRO_VAR_STR_DECL_DIRECT_64( category        );
	MACRO_VAR_STR_DECL_DIRECT_64( type            );
	MACRO_VAR_STR_DECL_DIRECT_64( target          );
	MACRO_VAR_STR_DECL_DIRECT_64( response_action );
	MACRO_VAR_STR_DECL_DIRECT_64( trigger_unit    );
	MACRO_VAR_STR_DECL_DIRECT_64( callback_action );
	MACRO_VAR_STR_DECL_DIRECT_64( cb_arg1         );
	MACRO_VAR_STR_DECL_DIRECT_64( cb_arg2         );
	MACRO_VAR_STR_DECL_DIRECT_64( cb_arg3         );
	MACRO_VAR_STR_DECL_DIRECT_64( cb_arg4         );
	MACRO_VAR_STR_DECL_DIRECT_64( cb_arg5         );

	MACRO_VAR_ACCESS_DECL_DIRECT(float            , trigger_bandwidth_min );
	MACRO_VAR_ACCESS_DECL_DIRECT(float            , trigger_bandwidth_max );
	MACRO_VAR_ACCESS_DECL_DIRECT(int              , arguments_size        );
	MACRO_VAR_ACCESS_DECL_DIRECT(hashFuncEntryPtr , callback              );
	MACRO_VAR_ACCESS_DECL_DIRECT(callbackArguments, cba                  );
public:
	adaptiveRule();
 	~adaptiveRule();	
	int Trigger(float v);
	
	std::ostream& Dump(std::ostream& out)const; 
	
	friend std::ostream& operator<< 
		(std::ostream &out, adaptiveRule& rhs) 
	{
		if ( rhs.GetDebugFlagLevel2() ) 
			rhs.Dump(out);
		return out;
	}
};
#endif
