#include <streamStarter/streamStarter.h>

#ifdef __cplusplus
extern "C" {
#endif

int StreamLibraryStarter1()
{
#if SLS_INIT_XCFG2
	XCFG2_Init();
#endif
#if SLS_INIT_CALLBACK
	CB_REG_INIT();
#endif
#if SLS_INIT_RULE_MGR
	RULE_MGR_REFRESH_RULE();
#endif
	return 0;
}

int StreamLibraryFree()
{

#if SLS_INIT_XCFG2
	XCFG2_PutInstance();
#endif

#if SLS_INIT_PEER_INFORMATION_MGR
	PI_Destory();
#endif

#if SLS_INIT_CALLBACK
	CB_REG_PUT_INSTANCE();
#endif

#if SLS_INIT_RULE_MGR
	RULE_MGR_PUT_INSTANCE();
#endif

#if SLS_INIT_RECEPTION_STREAM_INFO_MGR
	RSIM_PutInstance();
#endif

#if SLS_INIT_STREAM_TRANS_MGR
	STREAM_TRANS_MGR_PUT_INSTANCE();
#endif
#if SLS_INIT_PARAMETER_MGR
	PARAMETER_MANAGER_PutInstance();
#endif 

#if SLS_INIT_STREAM_RECP_MGR
	STREAM_RECP_MGR_PUT_INSTANCE();
#endif 

	return 0;
}
#ifdef __cplusplus
}
#endif
