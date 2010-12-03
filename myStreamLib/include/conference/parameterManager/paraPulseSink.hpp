#ifndef PARAMETER_PULSESINK_HPP
#define PARAMETER_PULSESINK_HPP
#include <baseStream/baseStream.hpp>
#include <conference/parameterManager/paraBase.hpp>
class paraPulseSink:public paraBase {
private:
	MACRO_VAR_DECL_FULL(guint   , PrerollQueueLen  , preroll_queue_len  );
	MACRO_VAR_DECL_FULL(gboolean, Sync             , sync               );
	MACRO_VAR_DECL_FULL(gint64  , MaxLateness      , max_lateness       );
	MACRO_VAR_DECL_FULL(gboolean, Async            , async              );
	MACRO_VAR_DECL_FULL(gboolean, EnableLastBuffer , enable_last_buffer );
	MACRO_VAR_DECL_FULL(guint64 , RenderDelay      , render_delay       );
	MACRO_VAR_DECL_FULL(gint64  , BufferTime       , buffer_time        );
	MACRO_VAR_DECL_FULL(gint64  , LatencyTime      , latency_time       );
	MACRO_VAR_DECL_FULL(gboolean, ProvideClock     , provide_clock      );
	MACRO_VAR_DECL_FULL(gint    , SlaveMethod      , slave_method       );
	MACRO_VAR_DECL_FULL(gboolean, CanActivatePull  , can_activate_pull  );
	MACRO_VAR_DECL_FULL(gint64  , DriftTolerance   , drift_tolerance    );
	MACRO_VAR_DECL_FULL(gdouble , Volume           , volume             );
	MACRO_VAR_DECL_FULL(gboolean, Mute             , mute               );
	MACRO_VAR_DECL_FULL(bool    , IsVersionITRI    , is_version_itri    );
	MACRO_VAR_DECL_FULL(gboolean, DetectDtmf       , detect_dtmf        );
	MACRO_VAR_DECL_FULL(gint    , DelayEquivalent  , delay_equivalent   );
	MACRO_VAR_DECL_FULL(gint    , DebugMessageLevel, debug_message_level);
	
public:
	paraPulseSink();
	~paraPulseSink();
	std::ostream& Dump(std::ostream& out)const;
};
#endif
