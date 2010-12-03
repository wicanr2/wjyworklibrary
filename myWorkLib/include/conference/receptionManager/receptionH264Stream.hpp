#ifndef VIDEO_RECEPTION_H264_STREAM_HPP
#define VIDEO_RECEPTION_H264_STREAM_HPP
#include <gst/gst.h>
#include <gst/interfaces/xoverlay.h>
#include <gdk/gdkx.h>
#include <gdk/gdk.h>
#include <gtk/gtk.h>
#include <glib.h>
#include <baseStream/baseStream.hpp>
#include <conference/constant.hpp>
#include <conference/parameterManager/parameterManager.hpp>
#include <conference/parameterManager/parameterManagerCAPI.h>
typedef gboolean (*GTK_expose_cb) (GtkWidget *widget, GdkEventExpose *event, gpointer data);
class videoReceptionH264Stream: public baseStream 
{
private:
	MACRO_VAR_DECL_FULL (int           , Index                                , index                               );
	MACRO_VAR_DECL_FULL (bool          , EnableRecvPort                       , enableRecvPort                      );
	MACRO_VAR_DECL_FULL (gint          , Port			                      , recvPort                            );
	MACRO_VAR_DECL_FULL (bool          , UseGTKWindow                         , bUseGTKWindow                       );
	MACRO_VAR_DECL_FULL (GtkWidget*    , RecvGTKWindow                        , recvGTKWindow                       );
	MACRO_VAR_DECL_FULL (gulong        , RecvGTKWindowHandle                  , recvGTKWindowHandle                 );
	MACRO_VAR_DECL_FULL (GTK_expose_cb , RecvGTKWindowRestoreRepaintCallback  , recvGTKWindowRestoreRepaintCallback );

	int Set_UDPSrc_Params( paraUDPSrc *ptr );
	int Set_GSTRtpJitterBuffer_Params ( GstElement *e, paraGSTRtpJitterBuffer *ptr);
	int Set_XVImageSink_Params( paraXVImageSink *ptr); 
	// for gtk window handle
	int GTKWindow_Repaint_Callback_Disconnect();
	int GTKWindow_Repaint_Callback_Connect   ();
	int GTKWindow_Disable_DoubleBuffer       ();
	int GTKWindow_Enable_DoubleBuffer        ();
	int GTKWindow_Redraw					 ();
	int GTKWindow_Realize					 ();
	
	
public:
	videoReceptionH264Stream(int index);
	~videoReceptionH264Stream();
	int Create();
	int Stop();
};
#endif 
