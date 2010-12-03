MAKEFILES1 :=
#MAKEFILES1 += variables.mk
MAKEFILES1 += utils.mk 
MAKEFILES1 += peerInfo.mk 
MAKEFILES1 += video_v1.mk 
MAKEFILES1 += xml_config_v1.mk 
MAKEFILES1 += xml_config_v2.mk 
MAKEFILES1 += desktop_sharing.mk 
MAKEFILES1 += base_stream.mk 
MAKEFILES1 += audio_manager_v2.mk 
MAKEFILES1 += parameter_manager.mk 
MAKEFILES1 += hash.mk 
MAKEFILES1 += transfer_manager.mk 
#MAKEFILES1 += audio_manager_v1.mk 

MAKEFILES2 := \
    variables.mk \
	peerInfo.mk \
    output_library.mk

RULE_MAKEFILES1 :=
RULE_MAKEFILES1 += utils_rule.mk 
RULE_MAKEFILES1 += peerInfo_rule.mk 
RULE_MAKEFILES1 += video_v1_rule.mk 
RULE_MAKEFILES1 += xml_config_v1_rule.mk 
RULE_MAKEFILES1 += xml_config_v2_rule.mk 
RULE_MAKEFILES1 += desktop_sharing_rule.mk 
RULE_MAKEFILES1 += base_stream_rule.mk 
RULE_MAKEFILES1 += audio_manager_v2_rule.mk 
RULE_MAKEFILES1 += parameter_manager_rule.mk 
RULE_MAKEFILES1 += hash_rule.mk 
RULE_MAKEFILES1 += transfer_manager_rule.mk 
#RULE_MAKEFILES1 += audio_manager_v1_rule.mk 

MAKEFILES      := $(MAKEFILES1)
RULE_MAKEFILES := $(RULE_MAKEFILES1)
