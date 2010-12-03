#include <macro/macroSetter.hpp>
#include <macro/macroGetter.hpp>
#ifndef MACRO_VARIABLE_ACCESS_HPP
#define MACRO_VARIABLE_ACCESS_HPP

#define MACRO_VARIABLE_ACCESS_DECL(type,name)\
	MACRO_SETTER_DECL (type,name)\
	MACRO_GETTER_DECL (type,name)

#define MACRO_VARIABLE_ACCESS_IMPL(_cls,type,name,var)\
	MACRO_SETTER_IMPL (_cls,type,name,var) \
	MACRO_GETTER_IMPL (_cls,type,name,var) 
//-------------------------------------------------------
// simpler macro
#define MACRO_VAR_DECL(type,name)\
	MACRO_VARIABLE_ACCESS_DECL(type,name)

#define MACRO_VAR_IMPL(_cls,type,name,var)\
	MACRO_VARIABLE_ACCESS_IMPL(_cls,type,name,var)

#define MACRO_VAR_IMPL_WITH_LOCK(_cls,type,name,var,_Mutexlock)\
	MACRO_SETTER_IMPL_WITH_LOCK(_cls,type,name,var,_Mutexlock)\
	MACRO_GETTER_IMPL_WITH_LOCK(_cls,type,name,var,_Mutexlock)

//-------------------------------------------------------
// declare var , getter and setter
#define MACRO_VAR_DECL_FULL(type,name,var)\
	private:\
		type var;\
	public:\
		MACRO_VAR_DECL(type,name)	
// declare var and getter
#define MACRO_VAR_DECL_GETTER(type,name,var)\
	private:\
		type var;\
	public:\
		MACRO_GETTER_DECL (type,name)
// declare var and setter
#define MACRO_VAR_DECL_SETTER(type,name,var)\
	private:\
		type var;\
	public:\
		MACRO_SETTER_DECL (type,name)
//----------------------------------------------
// str version
#define MACRO_VAR_STR_DECL(name)\
	MACRO_SETTER_STR_DECL(name)\
	MACRO_GETTER_STR_DECL(name)
	
#define MACRO_VAR_STR_DECL_FULL(name,var)\
	private:\
		char var[255];\
	public:\
		MACRO_VAR_STR_DECL(name)	

#define MACRO_VAR_STR_IMPL(_cls,name,var)\
	MACRO_SETTER_STR_IMPL(_cls,name,var)\
	MACRO_GETTER_STR_IMPL(_cls,name,var)

//---------------------------------------------------
// 64 str
#define MACRO_VAR_STR_DECL_FULL_2(name,var)\
	private:\
		char var[64];\
	public:\
		MACRO_VAR_STR_DECL(name)	

#define MACRO_VAR_STR_IMPL_2(_cls,name,var)\
	MACRO_SETTER_STR_IMPL_2(_cls,name,var,64)\
	MACRO_GETTER_STR_IMPL(_cls,name,var)
//----------------------------------------------------
// avoid using the getter and setter marcos
#define MACRO_VAR_ACCESS_DECL_DIRECT(type, var)\
	public:\
		type var

#define MACRO_VAR_ACCESS_SET_DIRECT(cls, dest_var, src_var)\
	do{\
		cls->dest_var = src_var;\
	}while(0)

#define MACRO_VAR_ACCESS_GET_DIRECT(cls, dest_var )\
	cls->dest_var

#define MACRO_VAR_STR_DECL_DIRECT(var,size)\
	public:\
		char var[size];

#define MACRO_VAR_STR_DECL_DIRECT_64(var)\
	MACRO_VAR_STR_DECL_DIRECT(var,64)

#define MACRO_VAR_STR_SET_DIRECT_64(cls, dest_var, src_var)\
	do{\
		snprintf( cls->dest_var, 64, "%s", src_var );\
	}while(0)

#endif
