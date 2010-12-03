#ifndef DEBUG_CLASS_HPP
#define DEBUG_CLASS_HPP
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <macro/macroVariableAccess.hpp>
#include <macro/macroDebugClassAid.hpp>
#include <macro/macroErrorCheck.hpp>
class staticMutexLocker;
#define DEBUG_CONFIG_FILE "debug.cfg"
class debugClass {
private:
	bool debugFlag;
	MACRO_VAR_DECL_GETTER( bool, DebugFlagLevel2, debugFlagLevel2 );
	MACRO_VAR_DECL_GETTER( bool, DebugFlagLevel3, debugFlagLevel3 );
	MACRO_VAR_DECL_GETTER( bool, DebugFlagLevel4, debugFlagLevel4 );
	MACRO_VAR_DECL_GETTER( bool, DebugFlagLevel5, debugFlagLevel5 );
	MACRO_VAR_DECL_GETTER( bool, DebugFlagLevel6, debugFlagLevel6 );
	static staticMutexLocker sMutex;
	static bool bReadExternalFile;
	static bool bExnternalEnable;
	static int  iDebugLevel;
protected:
	void SetDebugFlag(bool v);
public:
	debugClass() ;
	~debugClass();
	
	void EnableDebug();
	void DisableDebug();
	bool GetDebugFlag();
	MACRO_DEBUG_CLASS_ENABLE_DISABLE_DECL( DebugFlagLevel2 );
	MACRO_DEBUG_CLASS_ENABLE_DISABLE_DECL( DebugFlagLevel3 );
	MACRO_DEBUG_CLASS_ENABLE_DISABLE_DECL( DebugFlagLevel4 );
	MACRO_DEBUG_CLASS_ENABLE_DISABLE_DECL( DebugFlagLevel5 );
	MACRO_DEBUG_CLASS_ENABLE_DISABLE_DECL( DebugFlagLevel6 );
	
};
#endif
