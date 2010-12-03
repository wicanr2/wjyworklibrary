#ifndef PARAMETER_XVIMAGESINK_HPP
#define PARAMETER_XVIMAGESINK_HPP
#include <baseStream/baseStream.hpp>
#include <conference/parameterManager/paraBase.hpp>
class paraXVImageSink:public paraBase {
private:
	MACRO_VAR_DECL_FULL(guint   , PrerollQueueLen  , preroll_queue_len  );
	MACRO_VAR_DECL_FULL(gboolean, Sync             , sync               );
	MACRO_VAR_DECL_FULL(gint64  , MaxLateness      , max_lateness       );
	MACRO_VAR_DECL_FULL(gboolean, Async            , async              );
	MACRO_VAR_DECL_FULL(gboolean, EnableLastBuffer , enable_last_buffer );
	MACRO_VAR_DECL_FULL(gboolean, ShowPrerollFrame , show_preroll_frame );
	MACRO_VAR_DECL_FULL(gint    , Contrast         , contrast           );
	MACRO_VAR_DECL_FULL(gint    , Brightness       , brightness         );
	MACRO_VAR_DECL_FULL(gint    , Hue              , hue                );
	MACRO_VAR_DECL_FULL(gint    , Saturation       , saturation         );
	MACRO_VAR_STR_DECL_FULL(      Display          , display            );
	MACRO_VAR_DECL_FULL(gboolean, HandleExpose     , handle_expose      );
	MACRO_VAR_DECL_FULL(gboolean, DoubleBuffer     , double_buffer      );
	MACRO_VAR_DECL_FULL(gboolean, AutopaintColorKey, autopaint_colorkey );
	MACRO_VAR_DECL_FULL(gboolean, DrawBorders      , draw_borders       );
	
public:
	paraXVImageSink();
	~paraXVImageSink();
	std::ostream& Dump(std::ostream& out)const;
};
#endif
