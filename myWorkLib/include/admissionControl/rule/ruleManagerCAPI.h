#ifndef RULE_MANAGER_C_API_H
#define RULE_MANAGER_C_API_H
#ifdef __cplusplus
extern "C" {
#endif
int RULE_MGR_TRIGGER_RULE(float v);
int RULE_MGR_REFRESH_RULE();
int RULE_MGR_DUMP();
int RULE_MGR_PUT_INSTANCE();
#ifdef __cplusplus
}
#endif
#endif

