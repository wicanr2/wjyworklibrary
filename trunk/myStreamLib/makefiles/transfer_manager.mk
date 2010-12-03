#define module name
TRANSFER_MANAGER_MODULE      := transfer_manager 
TRANSFER_MANAGER_MODULE_OBJS :=

# tranfer manager
TRANSFER_MANAGER_PREFIX  := conference/transferManager
TRANSFER_MANAGER_SRC_CPP := $(wildcard $(TRANSFER_MANAGER_PREFIX)/*.cpp)
TRANSFER_MANAGER_OBJ_CPP := $(notdir $(patsubst %.cpp,%.o,$(TRANSFER_MANAGER_SRC_CPP)))	
TRANSFER_MANAGER_OBJ_CPP_OUT := $(addprefix $(OUT_DIRS)/,$(TRANSFER_MANAGER_OBJ_CPP))

# capture mjpeg stream
CAPTURE_MJPEG_STREAM_PREFIX  := conference/transferManager/captureMJPEGStream
CAPTURE_MJPEG_STREAM_SRC_CPP := $(wildcard $(CAPTURE_MJPEG_STREAM_PREFIX)/*.cpp)
CAPTURE_MJPEG_STREAM_OBJ_CPP := $(notdir $(patsubst %.cpp,%.o,$(CAPTURE_MJPEG_STREAM_SRC_CPP)))	
CAPTURE_MJPEG_STREAM_OBJ_CPP_OUT := $(addprefix $(OUT_DIRS)/,$(CAPTURE_MJPEG_STREAM_OBJ_CPP))

# transcode mjpeg to h264 stream
TRANSCODE_MJPEG_TO_H264_STREAM_PREFIX  := conference/transferManager/transcodeMJPEGToH264Stream
TRANSCODE_MJPEG_TO_H264_STREAM_SRC_CPP := $(wildcard $(TRANSCODE_MJPEG_TO_H264_STREAM_PREFIX)/*.cpp)
TRANSCODE_MJPEG_TO_H264_STREAM_OBJ_CPP := $(notdir $(patsubst %.cpp,%.o,$(TRANSCODE_MJPEG_TO_H264_STREAM_SRC_CPP)))	
TRANSCODE_MJPEG_TO_H264_STREAM_OBJ_CPP_OUT := $(addprefix $(OUT_DIRS)/,$(TRANSCODE_MJPEG_TO_H264_STREAM_OBJ_CPP))

# capture audio raw stream
CAPTURE_AUDIO_RAW_STREAM_PREFIX  := conference/transferManager/captureAudioRawStream
CAPTURE_AUDIO_RAW_STREAM_SRC_CPP := $(wildcard $(CAPTURE_AUDIO_RAW_STREAM_PREFIX)/*.cpp)
CAPTURE_AUDIO_RAW_STREAM_OBJ_CPP := $(notdir $(patsubst %.cpp,%.o,$(CAPTURE_AUDIO_RAW_STREAM_SRC_CPP)))	
CAPTURE_AUDIO_RAW_STREAM_OBJ_CPP_OUT := $(addprefix $(OUT_DIRS)/,$(CAPTURE_AUDIO_RAW_STREAM_OBJ_CPP))

TRANSFER_MANAGER_MODULE_OBJS += $(TRANSFER_MANAGER_OBJ_CPP_OUT)
TRANSFER_MANAGER_MODULE_OBJS += $(CAPTURE_MJPEG_STREAM_OBJ_CPP_OUT)
TRANSFER_MANAGER_MODULE_OBJS += $(TRANSCODE_MJPEG_TO_H264_STREAM_OBJ_CPP_OUT)
TRANSFER_MANAGER_MODULE_OBJS += $(CAPTURE_AUDIO_RAW_STREAM_OBJ_CPP_OUT)



MODULES_OBJS += $(TRANSFER_MANAGER_MODULE_OBJS) 