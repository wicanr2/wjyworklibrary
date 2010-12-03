#ifndef FILE_CHECKER_C_API_HPP
#define FILE_CHECKER_C_API_HPP
#ifdef __cplusplus
extern "C" {
#endif
int 	FC_CheckFileExisted( char* file );
void	FC_EnableDebug();
void 	FC_Destory();

#ifdef __cplusplus
}
#endif
#endif
