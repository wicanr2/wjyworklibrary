#define module name
DESKTOP_SHARING_MODULE      := desktop_sharing_module
DESKTOP_SHARING_MODULE_OBJS :=
MODULES_POOL                += $(DESKTOP_SHARING_MODULE)

# Desktop Sharing
DESKTOP_SHARING_PREFIX  := desktopSharing
DESKTOP_SHARING_SRC     := $(wildcard $(DESKTOP_SHARING_PREFIX)/*.c)
DESKTOP_SHARING_OBJ     := $(notdir $(patsubst %.c,%.o,$(DESKTOP_SHARING_SRC)))	
DESKTOP_SHARING_OBJ_OUT := $(addprefix $(OUT_DIRS)/,$(DESKTOP_SHARING_OBJ))	

DESKTOP_SHARING_MODULE_OBJS += $(DESKTOP_SHARING_OBJ_OUT)

MODULES_OBJS += $(DESKTOP_SHARING_MODULE_OBJS) 
