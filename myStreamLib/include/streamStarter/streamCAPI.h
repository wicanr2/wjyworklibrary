#ifndef STREAM_STARTER_CAPI_H
#define STREAM_STARTER_CAPI_H

#if SLS_INIT_PEER_INFORMATION_MGR
#include <peer/peerInfo.h>
#endif

#if SLS_INIT_XCFG2
#include <xmlConfig/xmlConfig2CPPAPI.hpp>
#endif 

#if SLS_INIT_CALLBACK
#include <callbackRegister/callbackRegisterCAPI.h>
#endif

#if SLS_INIT_RULE_MGR
#include <admissionControl/rule/ruleManagerCAPI.h>
#endif

#if SLS_INIT_RECEPTION_STREAM_INFO_MGR
#include <conference/receptionStreamInfoManager/receptionStreamInfoManagerSingleton.hpp>
#endif 

#if SLS_INIT_STREAM_TRANS_MGR
#include <conference/transferManager/transferManagerCAPI.h>
#endif 

#if SLS_INIT_PARAMETER_MGR
#include <conference/parameterManager/parameterManagerCAPI.h>
#endif 

#if SLS_INIT_STREAM_RECP_MGR
#include <conference/receptionManager/receptionManagerCAPI.h>
#endif 

#endif
