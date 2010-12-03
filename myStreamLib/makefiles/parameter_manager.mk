#define module name
PARAMETER_MANAGER_MODULE      := parameter_manager_module
PARAMETER_MANAGER_MODULE_OBJS :=
MODULES_POOL                  += $(PARAMETER_MANAGER_MODULE)

# parameter manager 
PARAMETER_MANAGER_PREFIX  := conference/parameterManager
PARAMETER_MANAGER_SRC_CPP := $(wildcard $(PARAMETER_MANAGER_PREFIX)/*.cpp)
PARAMETER_MANAGER_OBJ_CPP := $(notdir $(patsubst %.cpp,%.o,$(PARAMETER_MANAGER_SRC_CPP)))	
PARAMETER_MANAGER_OBJ_CPP_OUT := $(addprefix $(OUT_DIRS)/,$(PARAMETER_MANAGER_OBJ_CPP))	

# GSTCaps parameter 
GST_CAPS_PREFIX  := conference/parameterManager/GSTCaps
GST_CAPS_SRC_CPP := $(wildcard $(GST_CAPS_PREFIX)/*.cpp)
GST_CAPS_OBJ_CPP := $(notdir $(patsubst %.cpp,%.o,$(GST_CAPS_SRC_CPP)))	
GST_CAPS_OBJ_CPP_OUT := $(addprefix $(OUT_DIRS)/,$(GST_CAPS_OBJ_CPP))	

# paraMJPEG parameter  
PARA_MJPEG_PREFIX  := conference/parameterManager/paraMJPEG
PARA_MJPEG_SRC_CPP := $(wildcard $(PARA_MJPEG_PREFIX)/*.cpp)
PARA_MJPEG_OBJ_CPP := $(notdir $(patsubst %.cpp,%.o,$(PARA_MJPEG_SRC_CPP)))	
PARA_MJPEG_OBJ_CPP_OUT := $(addprefix $(OUT_DIRS)/,$(PARA_MJPEG_OBJ_CPP))	

# paraMultiUDPSink parameter 
PARA_MULTIUDPSINK_PREFIX  := conference/parameterManager/paraMultiUDPSink
PARA_MULTIUDPSINK_SRC_CPP := $(wildcard $(PARA_MULTIUDPSINK_PREFIX)/*.cpp)
PARA_MULTIUDPSINK_OBJ_CPP := $(notdir $(patsubst %.cpp,%.o,$(PARA_MULTIUDPSINK_SRC_CPP)))	
PARA_MULTIUDPSINK_OBJ_CPP_OUT := $(addprefix $(OUT_DIRS)/,$(PARA_MULTIUDPSINK_OBJ_CPP))	

# paraUDPSink parameter 
PARA_UDPSINK_PREFIX  := conference/parameterManager/paraUDPSink
PARA_UDPSINK_SRC_CPP := $(wildcard $(PARA_UDPSINK_PREFIX)/*.cpp)
PARA_UDPSINK_OBJ_CPP := $(notdir $(patsubst %.cpp,%.o,$(PARA_UDPSINK_SRC_CPP)))	
PARA_UDPSINK_OBJ_CPP_OUT := $(addprefix $(OUT_DIRS)/,$(PARA_UDPSINK_OBJ_CPP))	

# paraUDPSrc parameter 
PARA_UDPSRC_PREFIX  := conference/parameterManager/paraUDPSrc
PARA_UDPSRC_SRC_CPP := $(wildcard $(PARA_UDPSRC_PREFIX)/*.cpp)
PARA_UDPSRC_OBJ_CPP := $(notdir $(patsubst %.cpp,%.o,$(PARA_UDPSRC_SRC_CPP)))	
PARA_UDPSRC_OBJ_CPP_OUT := $(addprefix $(OUT_DIRS)/,$(PARA_UDPSRC_OBJ_CPP))	

# paraV4L2 parameter 
PARA_V4L2_PREFIX  := conference/parameterManager/paraV4L2
PARA_V4L2_SRC_CPP := $(wildcard $(PARA_V4L2_PREFIX)/*.cpp)
PARA_V4L2_OBJ_CPP := $(notdir $(patsubst %.cpp,%.o,$(PARA_V4L2_SRC_CPP)))	
PARA_V4L2_OBJ_CPP_OUT := $(addprefix $(OUT_DIRS)/,$(PARA_V4L2_OBJ_CPP))	

# paraVideoRate parameter 
PARA_VIDEO_RATE_PREFIX  := conference/parameterManager/paraVideoRate
PARA_VIDEO_RATE_SRC_CPP := $(wildcard $(PARA_VIDEO_RATE_PREFIX)/*.cpp)
PARA_VIDEO_RATE_OBJ_CPP := $(notdir $(patsubst %.cpp,%.o,$(PARA_VIDEO_RATE_SRC_CPP)))	
PARA_VIDEO_RATE_OBJ_CPP_OUT := $(addprefix $(OUT_DIRS)/,$(PARA_VIDEO_RATE_OBJ_CPP))	

# paraVideoScale parameter 
PARA_VIDEO_SCALE_PREFIX  := conference/parameterManager/paraVideoScale
PARA_VIDEO_SCALE_SRC_CPP := $(wildcard $(PARA_VIDEO_SCALE_PREFIX)/*.cpp)
PARA_VIDEO_SCALE_OBJ_CPP := $(notdir $(patsubst %.cpp,%.o,$(PARA_VIDEO_SCALE_SRC_CPP)))	
PARA_VIDEO_SCALE_OBJ_CPP_OUT := $(addprefix $(OUT_DIRS)/,$(PARA_VIDEO_SCALE_OBJ_CPP))	

# paraX264Enc parameter 
PARA_X264_ENC_PREFIX  := conference/parameterManager/paraX264Enc
PARA_X264_ENC_SRC_CPP := $(wildcard $(PARA_X264_ENC_PREFIX)/*.cpp)
PARA_X264_ENC_OBJ_CPP := $(notdir $(patsubst %.cpp,%.o,$(PARA_X264_ENC_SRC_CPP)))	
PARA_X264_ENC_OBJ_CPP_OUT := $(addprefix $(OUT_DIRS)/,$(PARA_X264_ENC_OBJ_CPP))	

# paraAudioConvert parameter 
PARA_AUDIO_CONVERT_PREFIX  := conference/parameterManager/paraAudioConvert
PARA_AUDIO_CONVERT_SRC_CPP := $(wildcard $(PARA_AUDIO_CONVERT_PREFIX)/*.cpp)
PARA_AUDIO_CONVERT_OBJ_CPP := $(notdir $(patsubst %.cpp,%.o,$(PARA_AUDIO_CONVERT_SRC_CPP)))	
PARA_AUDIO_CONVERT_OBJ_CPP_OUT := $(addprefix $(OUT_DIRS)/,$(PARA_AUDIO_CONVERT_OBJ_CPP))	

# paraAudioResample parameter 
PARA_AUDIO_RESAMPLE_PREFIX  := conference/parameterManager/paraAudioResample
PARA_AUDIO_RESAMPLE_SRC_CPP := $(wildcard $(PARA_AUDIO_RESAMPLE_PREFIX)/*.cpp)
PARA_AUDIO_RESAMPLE_OBJ_CPP := $(notdir $(patsubst %.cpp,%.o,$(PARA_AUDIO_RESAMPLE_SRC_CPP)))	
PARA_AUDIO_RESAMPLE_OBJ_CPP_OUT := $(addprefix $(OUT_DIRS)/,$(PARA_AUDIO_RESAMPLE_OBJ_CPP))	

# paraGSTRtpJitterBuffer parameter 
PARA_GST_RTP_JITTER_BUFFER_PREFIX  := conference/parameterManager/paraGSTRtpJitterBuffer
PARA_GST_RTP_JITTER_BUFFER_SRC_CPP := $(wildcard $(PARA_GST_RTP_JITTER_BUFFER_PREFIX)/*.cpp)
PARA_GST_RTP_JITTER_BUFFER_OBJ_CPP := $(notdir $(patsubst %.cpp,%.o,$(PARA_GST_RTP_JITTER_BUFFER_SRC_CPP)))	
PARA_GST_RTP_JITTER_BUFFER_OBJ_CPP_OUT := $(addprefix $(OUT_DIRS)/,$(PARA_GST_RTP_JITTER_BUFFER_OBJ_CPP))	

# paraPulseSrc parameter 
PARA_PULSE_SRC_PREFIX  := conference/parameterManager/paraPulseSrc
PARA_PULSE_SRC_SRC_CPP := $(wildcard $(PARA_PULSE_SRC_PREFIX)/*.cpp)
PARA_PULSE_SRC_OBJ_CPP := $(notdir $(patsubst %.cpp,%.o,$(PARA_PULSE_SRC_SRC_CPP)))	
PARA_PULSE_SRC_OBJ_CPP_OUT := $(addprefix $(OUT_DIRS)/,$(PARA_PULSE_SRC_OBJ_CPP))	

PARAMETER_MANAGER_MODULE_OBJS += $(PARAMETER_MANAGER_OBJ_CPP_OUT)
PARAMETER_MANAGER_MODULE_OBJS += $(GST_CAPS_OBJ_CPP_OUT)
PARAMETER_MANAGER_MODULE_OBJS += $(PARA_MJPEG_OBJ_CPP_OUT)
PARAMETER_MANAGER_MODULE_OBJS += $(PARA_MULTIUDPSINK_OBJ_CPP_OUT)
PARAMETER_MANAGER_MODULE_OBJS += $(PARA_UDPSINK_OBJ_CPP_OUT)
PARAMETER_MANAGER_MODULE_OBJS += $(PARA_UDPSRC_OBJ_CPP_OUT)
PARAMETER_MANAGER_MODULE_OBJS += $(PARA_V4L2_OBJ_CPP_OUT)
PARAMETER_MANAGER_MODULE_OBJS += $(PARA_VIDEO_RATE_OBJ_CPP_OUT)
PARAMETER_MANAGER_MODULE_OBJS += $(PARA_VIDEO_SCALE_OBJ_CPP_OUT)
PARAMETER_MANAGER_MODULE_OBJS += $(PARA_X264_ENC_OBJ_CPP_OUT)
PARAMETER_MANAGER_MODULE_OBJS += $(PARA_AUDIO_CONVERT_OBJ_CPP_OUT)
PARAMETER_MANAGER_MODULE_OBJS += $(PARA_AUDIO_RESAMPLE_OBJ_CPP_OUT)
PARAMETER_MANAGER_MODULE_OBJS += $(PARA_GST_RTP_JITTER_BUFFER_OBJ_CPP_OUT)
PARAMETER_MANAGER_MODULE_OBJS += $(PARA_PULSE_SRC_OBJ_CPP_OUT)

MODULES_OBJS += $(PARAMETER_MANAGER_MODULE_OBJS) 
