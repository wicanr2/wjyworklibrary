#include <utils/gio.hpp>
#ifdef __cplusplus
extern "C" {
#endif

static 
gboolean channel_shutdown(GIOChannel *io_channel);
static 
gboolean gchannel_process(
	GIOChannel *source, GIOCondition condition, gpointer data);

static 
gboolean channel_shutdown(GIOChannel *io_channel)
{
	g_io_channel_shutdown (io_channel, TRUE, NULL);
	g_io_channel_unref (io_channel);
	return TRUE;
}

static 
gboolean gchannel_process(
	GIOChannel *source, GIOCondition condition, gpointer data)
{
	__gio_event_fnPtr fnPtr = (__gio_event_fnPtr)data;
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
		if ( fnPtr != 0 ) fnPtr ( str );
		
	} else if (condition & (G_IO_HUP | G_IO_ERR | G_IO_NVAL)) {
		g_printf("we are going to shutdown the channel now.");
		channel_shutdown(source);
	}
	return TRUE;
}

// Terminal IOs process function
int AddKeyEvenetReader(__gio_event_fnPtr fp) {
	GIOChannel* gchannel = NULL;
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

	g_io_add_watch( 
		gchannel , gcond , gchannel_process , (gpointer)fp );
	return 0;
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
	return 0;
}
#ifdef __cplusplus
}
#endif
