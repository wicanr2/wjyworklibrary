#define module name
AUDIO_MODULE      := audio_module_v1
AUDIO_MODULE_OBJS :=
MODULES_POOL      += $(AUDIO_MODULE)

# Old Audio Manager
AUDIO_PREFIX  := audio
AUDIO_SRC     := $(wildcard $(AUDIO_PREFIX)/*.c)
AUDIO_OBJ     := $(notdir $(patsubst %.c,%.o,$(AUDIO_SRC)))			
AUDIO_OBJ_OUT := $(addprefix $(OUT_DIRS)/,$(AUDIO_OBJ))

AUDIO_MODULE_OBJS += $(AUDIO_OBJ_OUT)
MODULES_OBJS += $(AUDIO_MODULE_OBJS) 
