#ifndef MACRO_GETTER_HPP
#define MACRO_GETTER_HPP

//--------------------------------------------------------
// normal variable getter
#define MACRO_GETTER_DECL(output_type,name)\
	output_type Get##name();

#define MACRO_GETTER_IMPL(_cls,output_type,name,var) \
	 output_type _cls::Get##name() \
	 { \
	 	return this->var ;\
	 }

#define MACRO_GETTER_IMPL_WITH_LOCK(_cls,output_type,name,var,_Mutexlock) \
	 output_type _cls::Get##name() \
	 { \
		output_type tmp;\
		_Mutexlock.Lock();\
		tmp = this->var;\
		_Mutexlock.Unlock();\
	 	return tmp ;\
	 }
//--------------------------------------------------------
#define MACRO_GETTER_STR_DECL(name)\
	MACRO_GETTER_DECL(char*,name)

#define MACRO_GETTER_STR_IMPL(_cls,name,var) \
	MACRO_GETTER_IMPL(_cls,char*,name,var)

#endif
