#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <callbackRegister/callbackImpl.h>
#include <callbackRegister/callbackArguments.h>
#include <streamStarter/streamCAPI.h>
#include <glib.h>
#ifdef __cplusplus
extern "C" {
#endif
/*
	應該要把 glib 相關的 event 利用 g_timeout_add 去呼叫
	避免直接在 pthread 中呼叫, 這樣會讓 perforamnce degrade
*/
struct res_fr {
	int width;
	int height;
	int fr;
	int base;
};
static GStaticMutex my_mutex = G_STATIC_MUTEX_INIT;
static gboolean RestartTranscode(gpointer data)
{

	g_static_mutex_lock ( &my_mutex );
#if SLS_INIT_PARAMETER_MGR
	if ( data == 0 ) {
		g_static_mutex_unlock ( &my_mutex );
		return FALSE;
	}
	struct res_fr *resfr = (struct res_fr*)data;
	if ( resfr == 0 ) {
		g_static_mutex_unlock ( &my_mutex );
		return FALSE;
	}
	ChangeVideoTransmitterResolutionAndFramerate(
			resfr->width, resfr->height, resfr->fr, resfr->base);
	free( resfr );
#endif
#if SLS_INIT_STREAM_TRANS_MGR
	STREAM_TRANS_MGR_RestartVideoTranscodeStream();
#endif
	g_static_mutex_unlock ( &my_mutex );
	return FALSE;
}
int ChangeResolution(void *p)
{
	int i = 0;
	int width = 0;
	int height = 0;
	int framerate = 0;
	int base = 0;
	int old_w = 0;
	int old_h = 0;
	int old_fr = 0;
	int old_b = 0;
	bool NeedChange = false ;
	if ( p == 0 ) return -1;
	printf("\n trigger ChangeResolution\n" );
#if SLS_INIT_PARAMETER_MGR
	callbackArguments *cba = (callbackArguments*)p; 
	struct res_fr *resfr = (struct res_fr*)malloc(sizeof(struct res_fr));
	if ( cba->size != 4 ) return -1;
	if ( cba->arg == 0 ) return -1;
	for ( i = 0 ; i < 4 ; i++ )
		if ( cba->arg[i] == 0 ) return -1;

	resfr->width  = atoi( cba->arg[0] );		
	resfr->height = atoi( cba->arg[1] );		
	resfr->fr     = atoi( cba->arg[2] );		
	resfr->base   = atoi( cba->arg[3] );		
	
	QueryVideoTransmitterResolutionAndFramerate(
		&old_w, &old_h, &old_fr, &old_b
	);

	if ( old_w != resfr->width  ) NeedChange = true;
	if ( old_h != resfr->height ) NeedChange = true;
	if ( old_fr != resfr->fr  ) NeedChange = true;
	if ( old_b != resfr->base ) NeedChange = true;

	if ( NeedChange ) {
		g_timeout_add(200, RestartTranscode, (gpointer)resfr );
		//sleep(1);
	} else {
		free( resfr );
		printf("No Need Change Resolution and framerate\n");
	}
#endif
	return 0;
}
#ifdef __cplusplus
}
#endif
