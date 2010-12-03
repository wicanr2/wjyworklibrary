#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <curses.h>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
//#include <gst/gst.h>
//#include <gst/interfaces/xoverlay.h>
//#include <gdk/gdkx.h>
//#include <gdk/gdk.h>
//#include <gtk/gtk.h>
#include <glib.h>
//#include <glib/gprintf.h>
#include <peer/peerInfo.h>
#include <xmlConfig/xmlConfig2CPPAPI.hpp>
#include <callbackRegister/callbackRegisterCAPI.h>
#include <admissionControl/rule/ruleManagerCAPI.h>
#include <utils/thread/threadWorker.hpp>
#include <utils/gio.hpp>
#include <streamStarter/streamStarter.h>

GMainLoop*  loop = NULL; 
int key_event( gchar cmd );

int TriggerEvent(void *p) 
{
	float var = 0.0f;
	var = (float)( ((float)rand())/((float)RAND_MAX) * 100.0f );	
	printf("\n Send Event %5.2f\n", var);
	RULE_MGR_TRIGGER_RULE(var);
	return 0;
}
int main( int argc, char *argv[] ) {

	srand( time(0) );
	StreamLibraryStarter1();
	{
		char ip[] = "127.0.0.1";
		char aport[] = "5000";
		char vport[] = "6000";
		PI_AddPeer    (4, ip, vport, aport );
	}
	PI_Dump();
	
	loop = g_main_loop_new( NULL, FALSE );
	AddKeyEvenetReader(key_event);
	printf("\n");
	printf("\tHash Function Table Demo...\n\n");	

	printf("\n\tRunning...\n");

	threadWorker *thw = 0;
	{
		char name[] = "Trigger Event";
		thw = new threadWorker(name ,TriggerEvent); 
	}
	MACRO_VAR_ACCESS_SET_DIRECT( thw, st, Thread::SleepInNanoSecond );
	MACRO_VAR_ACCESS_SET_DIRECT( thw, usleepInterval, 450000);

	thw->ActivateThread();
	g_main_loop_run(loop);	
	thw->StopThread();
	thw->WaitThreadJoin();	
	delete thw;
	RestoreTerminalAttribute();
	StreamLibraryFree();
	return 0;
}
int CallHashFuncTableFunction()
{
	int test = 0;
	hashFuncEntryPtr hfep = 0;
	{
		char fnName[] = "Test1";
		hfep = CB_REG_GET_CALLBACK(fnName);
		if ( hfep != 0 ) (*hfep)(0);
	}

	{
		char fnName[] = "Test2";
		hfep = CB_REG_GET_CALLBACK(fnName);
		if ( hfep != 0 ) (*hfep)(0);
	}

	{
		char fnName[] = "Test3UseArguments";
		callbackArguments cba;
		cba.size = 5;

		for(int i = 0 ; i < 5 ; i ++ ) 
			cba.arg[i] = (char*)malloc( sizeof(char) * 64 );

		snprintf(cba.arg[0],64,"%s","hello ");
		snprintf(cba.arg[1],64,"%s","world 1");
		snprintf(cba.arg[2],64,"%s",", hello ");
		snprintf(cba.arg[3],64,"%s","itri ");
		snprintf(cba.arg[4],64,"%s","world 2.");
		hfep = CB_REG_GET_CALLBACK(fnName);
		if ( hfep != 0 ) (*hfep)((void*)&cba);

		for(int i = 0 ; i < 5 ; i ++ ) 
			free( cba.arg[i] );
	}
	return 0;
}
int key_event( gchar cmd ) {
	switch (cmd) {
		case 'a':
			TriggerEvent(0);
			break;
		case 'l':
			CB_REG_DUMP();
			break;
		case 'q':
			g_main_loop_quit(loop);
			break;
		case 'c':
			CallHashFuncTableFunction();
			break;
		case 'f':
			RULE_MGR_DUMP();
			break;
		case 'x':
			XCFG2_Dump();
			break;
		default:
			break;
	}
	return 0;
}

