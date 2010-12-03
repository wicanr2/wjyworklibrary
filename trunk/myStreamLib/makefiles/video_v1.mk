#define module name
VIDEO_MODULE      := video_module
VIDEO_MODULE_OBJS :=
MODULES_POOL      += $(VIDEO_MODULE)

# Video Stream
VIDEO_PREFIX := video
VIDEO_SRC := $(wildcard $(VIDEO_PREFIX)/*.c)
VIDEO_OBJ := $(notdir $(patsubst %.c,%.o,$(VIDEO_SRC)))
VIDEO_OBJ_OUT := $(addprefix $(OUT_DIRS)/,$(VIDEO_OBJ))

VIDEO_MODULE_OBJS += $(VIDEO_OBJ_OUT)

MODULES_OBJS += $(VIDEO_MODULE_OBJS) 
