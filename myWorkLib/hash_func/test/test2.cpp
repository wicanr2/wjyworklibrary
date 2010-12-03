#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <curses.h>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#include <gst/gst.h>
#include <gst/interfaces/xoverlay.h>
#include <gdk/gdkx.h>
#include <gdk/gdk.h>
#include <gtk/gtk.h>
#include <glib.h>
#include <glib/gprintf.h>
#include <peer/peerInfo.h>
#include <xmlConfig/xmlConfig2CPPAPI.hpp>
#include <callbackRegister/callbackRegisterCAPI.h>
#include <admissionControl/rule/rule.hpp>
#include <utils/thread/threadWorker.hpp>
GIOChannel* gchannel = NULL;
GMainLoop*  loop = NULL; 

int key_event( gchar cmd );
gboolean channel_shutdown(GIOChannel *io_channel);
gboolean gchannel_test(GIOChannel *source, GIOCondition condition, gpointer data);
int AddKeyEvenetReader(); 
int RestoreTerminalAttribute();

int Test1(void *p) {
	if ( p == 0 ) {
		 printf(" the p is null\n");
		 return -1;
	}
	callbackArguments *cbArgs = (callbackArguments*)p;
	printf(" trigger test1 argument_size = %d\n", cbArgs->size);
	for ( int i = 0 ; i < cbArgs->size ; i++ )
	{
		printf("%s,", cbArgs->arg[i] );
	}
	printf("\n");
	return 0;
}
int Test2(void *p) {
	if ( p == 0 ) {
		 printf(" the p is null\n");
		 return -1;
	}
	callbackArguments *cbArgs = (callbackArguments*)p;
	printf(" trigger test2 argument_size = %d\n", cbArgs->size);
	for ( int i = 0 ; i < cbArgs->size ; i++ )
	{
		printf("%s|", cbArgs->arg[i] );
	}
	printf("\n");
	return 0;
}
int Test3UseArguments(void *p) 
{
	if ( p == 0 ) {
		 printf(" the p is null\n");
		 return -1;
	}
	callbackArguments *cbArgs = (callbackArguments*)p;
	printf(" trigger test3 argument_size = %d\n", cbArgs->size);
	for ( int i = 0 ; i < cbArgs->size ; i++ )
	{
		printf("%s", cbArgs->arg[i] );
	}
	printf("\n");
	return 0;
}
adaptiveRule **adaptive_rules = 0;
int ar_size = 0;
int readAdaptiveRule()
{
	char profile[] = "AdaptiveRuleDatabase";
	char rule[] = "AdaptiveRule";

	char name[] = "name";
	char category[] = "category";
	char type[] = "type";
	char target[] = "target";
	char response_action[] = "response_action";
	char trigger_unit[] = "trigger_unit";
	char trigger_bandwidth_min[] = "trigger_bandwidth_min";
	char trigger_bandwidth_max[] = "trigger_bandwidth_max";
	char callback_action[] = "callback_action";
	char callback_argument_size[] = "callback_argument_size";
	char callback_argument_1[] = "callback_argument_1";
	char callback_argument_2[] = "callback_argument_2";
	char callback_argument_3[] = "callback_argument_3";
	char callback_argument_4[] = "callback_argument_4";
	char callback_argument_5[] = "callback_argument_5";
	char buf[255];
	int size = 0; 
	int i = 0 ;
	hashFuncEntryPtr hfep = 0;
	size = XCFG2_GetElements ( profile, rule );
	if ( size < 0 ) {
		return -1;
	}
	ar_size = size;
	adaptive_rules = new adaptiveRule*[ size ];
	for ( i = 0 ; i < size ; i ++ ) {
		adaptive_rules[i] = new adaptiveRule();	
		XCFG2_GetElementsI(i);

		snprintf(buf,255,"%s",XCFG2_GetElementAttribute(name));
		MACRO_VAR_STR_SET_DIRECT_64 ( adaptive_rules[i], name, buf );

		snprintf(buf,255,"%s",XCFG2_GetElementAttribute(category));
		MACRO_VAR_STR_SET_DIRECT_64 ( adaptive_rules[i], category, buf );
		
		snprintf(buf,255,"%s",XCFG2_GetElementAttribute(type));
		MACRO_VAR_STR_SET_DIRECT_64 ( adaptive_rules[i], type, buf );

		snprintf(buf,255,"%s",XCFG2_GetElementAttribute(target));
		MACRO_VAR_STR_SET_DIRECT_64 ( adaptive_rules[i], target, buf );

		snprintf(buf,255,"%s",XCFG2_GetElementAttribute(response_action));
		MACRO_VAR_STR_SET_DIRECT_64 ( adaptive_rules[i], response_action , buf );

		snprintf(buf,255,"%s",XCFG2_GetElementAttribute(trigger_unit));
		MACRO_VAR_STR_SET_DIRECT_64 ( adaptive_rules[i], trigger_unit, buf );

		snprintf(buf,255,"%s",XCFG2_GetElementAttribute(callback_action));
		MACRO_VAR_STR_SET_DIRECT_64 ( adaptive_rules[i], callback_action , buf );
		MACRO_VAR_ACCESS_SET_DIRECT( adaptive_rules[i], callback, CB_REG_GET_CALLBACK(buf) );

		snprintf(buf,255,"%s",XCFG2_GetElementAttribute(callback_argument_1));
		MACRO_VAR_STR_SET_DIRECT_64 ( adaptive_rules[i], cb_arg1 , buf );

		snprintf(buf,255,"%s",XCFG2_GetElementAttribute(callback_argument_2));
		MACRO_VAR_STR_SET_DIRECT_64 ( adaptive_rules[i], cb_arg2 , buf );

		snprintf(buf,255,"%s",XCFG2_GetElementAttribute(callback_argument_3));
		MACRO_VAR_STR_SET_DIRECT_64 ( adaptive_rules[i], cb_arg3 , buf );

		snprintf(buf,255,"%s",XCFG2_GetElementAttribute(callback_argument_4));
		MACRO_VAR_STR_SET_DIRECT_64 ( adaptive_rules[i], cb_arg4 , buf );

		snprintf(buf,255,"%s",XCFG2_GetElementAttribute(callback_argument_5));
		MACRO_VAR_STR_SET_DIRECT_64 ( adaptive_rules[i], cb_arg5 , buf );
		
		snprintf(buf,255,"%s", XCFG2_GetElementAttribute(callback_argument_size) );
		MACRO_VAR_ACCESS_SET_DIRECT( adaptive_rules[i], arguments_size, atoi(buf) );

		snprintf(buf,255,"%s", XCFG2_GetElementAttribute(trigger_bandwidth_min) );
		MACRO_VAR_ACCESS_SET_DIRECT( adaptive_rules[i], trigger_bandwidth_min , atoi(buf) );
	
		snprintf(buf,255,"%s", XCFG2_GetElementAttribute(trigger_bandwidth_max) );
		MACRO_VAR_ACCESS_SET_DIRECT( adaptive_rules[i], trigger_bandwidth_max , atoi(buf) );

		printf("name            = %s\n",XCFG2_GetElementAttribute(name));
		printf("category        = %s\n",XCFG2_GetElementAttribute(category));
		printf("type            = %s\n",XCFG2_GetElementAttribute(type));
		printf("target          = %s\n",XCFG2_GetElementAttribute(target));
		printf("response_action = %s\n",XCFG2_GetElementAttribute(response_action));
		printf("trigger_unit    = %s\n",XCFG2_GetElementAttribute(trigger_unit));
		printf("bandwidth_min   = %s\n",XCFG2_GetElementAttribute(trigger_bandwidth_min));
		printf("bandwidth_max   = %s\n",XCFG2_GetElementAttribute(trigger_bandwidth_max));
		printf("callbackAction  = %s\n",XCFG2_GetElementAttribute(callback_action));
		printf("callback_size   = %s\n",XCFG2_GetElementAttribute(callback_argument_size));
		printf("callback_arg1   = %s\n",XCFG2_GetElementAttribute(callback_argument_1));
		printf("callback_arg2   = %s\n",XCFG2_GetElementAttribute(callback_argument_2));
		printf("callback_arg3   = %s\n",XCFG2_GetElementAttribute(callback_argument_3));
		printf("callback_arg4   = %s\n",XCFG2_GetElementAttribute(callback_argument_4));
		printf("callback_arg5   = %s\n",XCFG2_GetElementAttribute(callback_argument_5));
	}
	return 0;
}
int DumpAdaptiveRule()
{
	printf(" ar_size = %d\n", ar_size);
	for ( int i = 0 ; i < ar_size ; i++ )
	{
		std::cout << *adaptive_rules[i] << std::endl ; 
	}
	return 0;
}
class work1:public threadWorker{
protected:
	void DoRealWork(){
		float var = 0.0f;
		var = (float)(rand() % 100 );	
		printf("\n Send Event %5.2f\n", var);
		for ( int i = 0 ; i < ar_size ; i++ )
		{
			adaptive_rules[i]->Trigger(var);
		}
	}  
public:
	
	work1(){
		snprintf( this->name,255,"%s","work1");	
	}
	~work1(){}
};
int TriggerEvent() 
{
	float var = 0.0f;
	var = (float)(rand() % 100 );	
	printf("\n Send Event %5.2f\n", var);
	for ( int i = 0 ; i < ar_size ; i++ )
	{
		adaptive_rules[i]->Trigger(var);
	}
	return 0;
}
int main( int argc, char *argv[] ) {
	srand( time(0) );
	{
		char ip[] = "127.0.0.1";
		char aport[] = "5000";
		char vport[] = "6000";
		PI_AddPeer    (4, ip, vport, aport );
	}
	PI_Dump();

	readAdaptiveRule();
	XCFG2_Init();
	loop = g_main_loop_new( NULL, FALSE );
	{
		char fnName[] = "Test1";
		CB_REG_PUT_CALLBACK( fnName, Test1);
	}
	{
		char fnName[] = "Test2";
		CB_REG_PUT_CALLBACK( fnName, Test2);
	}
	{
		char fnName[] = "Test3UseArguments";
		CB_REG_PUT_CALLBACK( fnName, Test3UseArguments);
	}

	readAdaptiveRule();
	AddKeyEvenetReader();
	printf("\n");
	printf("\tHash Function Table Demo...\n\n");	

	g_print("\n\tRunning...\n");
	threadWorker *thw = new work1;
	thw->SetDetachable(false);
	thw->ActivateThread();
	g_main_loop_run(loop);	
	thw->StopThread();
	thw->WaitThreadJoin();	
	PI_Destory();
	
	RestoreTerminalAttribute();
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
			TriggerEvent();
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
			DumpAdaptiveRule();
			break;
		case 'x':
			XCFG2_Dump();
			break;
		default:
			break;
	}
	return 0;
}
gboolean channel_shutdown(GIOChannel *io_channel)
{
	g_io_channel_shutdown (io_channel, TRUE, NULL);
	g_io_channel_unref (io_channel);
	return TRUE;
}
gboolean gchannel_test(GIOChannel *source, GIOCondition condition, gpointer data)
{
	if (condition & G_IO_IN) {
		int fp = g_io_channel_unix_get_fd(source);
		gchar buffer[1<<10];
		int len;
	 	gsize term_pos;
		GIOStatus giostatus;
		gchar str;	
		GError *gerror = NULL;
		giostatus = g_io_channel_read_chars(source, &str, sizeof(str), &term_pos, &gerror);
		//str = getchar();
		g_printf("got %c\n", str);
		key_event( str );	
		
	} else if (condition & (G_IO_HUP | G_IO_ERR | G_IO_NVAL)) {
		g_printf("we are going to shutdown the channel now.");
		channel_shutdown(source);
	}
	return TRUE;
}

// Terminal IOs process function
int AddKeyEvenetReader() {
	int fd = fileno(stdin);
	int opts = fcntl ( fd, F_GETFL );
	
	struct termios oldt, newt;
	
	tcgetattr ( fd , &oldt );
	//ECHO = echo input character
	// ICANON = Enable canonical mode, enable special characters and buffers by lines
	oldt.c_lflag &= ~( ICANON | ECHO );
	//oldt.c_lflag &= ~( ECHO );
	//oldt.c_lflag &= ~( ICANON );
	tcsetattr ( fd, TCSANOW, &oldt );
	//fcntl ( fd , F_SETFL, opts | O_NONBLOCK  );	
	// 打開 nonblock 會在成 console output 有時候匯出不來
	gchannel = 	g_io_channel_unix_new( fd );
	
	GIOCondition gcond = (GIOCondition)(G_IO_IN | G_IO_PRI);

	g_io_add_watch( gchannel , gcond, 
					gchannel_test, NULL );
}

int RestoreTerminalAttribute() {
	int fd = fileno(stdin);
	int opts = fcntl ( fd, F_GETFL );
	
	struct termios oldt, newt;
	
	tcgetattr ( fd , &oldt );
	//ECHO = echo input character
	// ICANON = Enable canonical mode, enable special characters and buffers by lines
	oldt.c_lflag |= ( ICANON | ECHO );
	tcsetattr ( fd, TCSANOW, &oldt );
	fcntl ( fd , F_SETFL, opts | O_NONBLOCK  );	
	close ( fd );
}
