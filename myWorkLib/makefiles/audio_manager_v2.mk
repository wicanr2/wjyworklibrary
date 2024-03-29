#define module name
AUDIO_MANAGER_MODULE      := audio_module_v2
AUDIO_MANAGER_MODULE_OBJS :=
MODULES_POOL              += $(AUDIO_MANAGER_MODULE)

# Audio Device Manager
AUDIO_MANAGER_PREFIX := audioManager
AUDIO_MANAGER_SRC_CPP := $(wildcard $(AUDIO_MANAGER_PREFIX)/*.cpp)
AUDIO_MANAGER_OBJ_CPP := $(notdir $(patsubst %.cpp,$(OUT_DIRS)/%.o,$(AUDIO_MANAGER_SRC_CPP)))		
AUDIO_MANAGER_OBJ_CPP_OUT := $(addprefix $(OUT_DIRS)/,$(AUDIO_MANAGER_OBJ_CPP))

# Audio Device Bindle 
AUDIO_MANAGER_DEVICE_BINDLE_PREFIX := audioManager/audioDeviceBindle
AUDIO_MANAGER_DEVICE_BINDLE_SRC_CPP := $(wildcard $(AUDIO_MANAGER_DEVICE_BINDLE_PREFIX)/*.cpp)
AUDIO_MANAGER_DEVICE_BINDLE_OBJ_CPP := $(notdir $(patsubst %.cpp,$(OUT_DIRS)/%.o,$(AUDIO_MANAGER_DEVICE_BINDLE_SRC_CPP)))		
AUDIO_MANAGER_DEVICE_BINDLE_OBJ_CPP_OUT := $(addprefix $(OUT_DIRS)/,$(AUDIO_MANAGER_DEVICE_BINDLE_OBJ_CPP))

# Audio Device Manager
AUDIO_MANAGER_AUDIO_MANAGEMENT_PREFIX := audioManager/audioManagement
AUDIO_MANAGER_AUDIO_MANAGEMENT_SRC_CPP := $(wildcard $(AUDIO_MANAGER_AUDIO_MANAGEMENT_PREFIX)/*.cpp)
AUDIO_MANAGER_AUDIO_MANAGEMENT_OBJ_CPP := $(notdir $(patsubst %.cpp,$(OUT_DIRS)/%.o,$(AUDIO_MANAGER_AUDIO_MANAGEMENT_SRC_CPP)))		
AUDIO_MANAGER_AUDIO_MANAGEMENT_OBJ_CPP_OUT := $(addprefix $(OUT_DIRS)/,$(AUDIO_MANAGER_AUDIO_MANAGEMENT_OBJ_CPP))

# Audio Device Profile
AUDIO_MANAGER_DEVICE_PROFILE_PREFIX := audioManager/deviceProfile
AUDIO_MANAGER_DEVICE_PROFILE_SRC_CPP := $(wildcard $(AUDIO_MANAGER_DEVICE_PROFILE_PREFIX)/*.cpp)
AUDIO_MANAGER_DEVICE_PROFILE_OBJ_CPP := $(notdir $(patsubst %.cpp,$(OUT_DIRS)/%.o,$(AUDIO_MANAGER_DEVICE_PROFILE_SRC_CPP)))		
AUDIO_MANAGER_DEVICE_PROFILE_OBJ_CPP_OUT := $(addprefix $(OUT_DIRS)/,$(AUDIO_MANAGER_DEVICE_PROFILE_OBJ_CPP))

# Audio Pulseaudio Server Info
AUDIO_MANAGER_SERVER_INFO_PREFIX := audioManager/serverInfo
AUDIO_MANAGER_SERVER_INFO_SRC_CPP := $(wildcard $(AUDIO_MANAGER_SERVER_INFO_PREFIX)/*.cpp)
AUDIO_MANAGER_SERVER_INFO_OBJ_CPP := $(notdir $(patsubst %.cpp,$(OUT_DIRS)/%.o,$(AUDIO_MANAGER_SERVER_INFO_SRC_CPP)))		
AUDIO_MANAGER_SERVER_INFO_OBJ_CPP_OUT := $(addprefix $(OUT_DIRS)/,$(AUDIO_MANAGER_SERVER_INFO_OBJ_CPP))

# Audio USB Phone Controller
AUDIO_MANAGER_USB_PHONE_PREFIX := audioManager/USBPhone
AUDIO_MANAGER_USB_PHONE_SRC_CPP := $(wildcard $(AUDIO_MANAGER_USB_PHONE_PREFIX)/*.cpp)
AUDIO_MANAGER_USB_PHONE_OBJ_CPP := $(notdir $(patsubst %.cpp,$(OUT_DIRS)/%.o,$(AUDIO_MANAGER_USB_PHONE_SRC_CPP)))		
AUDIO_MANAGER_USB_PHONE_OBJ_CPP_OUT := $(addprefix $(OUT_DIRS)/,$(AUDIO_MANAGER_USB_PHONE_OBJ_CPP))

# add into AUDIO_MANAGER_MODULE_OBJS
AUDIO_MANAGER_MODULE_OBJS += $(AUDIO_MANAGER_OBJ_CPP_OUT)
AUDIO_MANAGER_MODULE_OBJS += $(AUDIO_MANAGER_DEVICE_BINDLE_OBJ_CPP_OUT)
AUDIO_MANAGER_MODULE_OBJS += $(AUDIO_MANAGER_AUDIO_MANAGEMENT_OBJ_CPP_OUT)
AUDIO_MANAGER_MODULE_OBJS += $(AUDIO_MANAGER_DEVICE_PROFILE_OBJ_CPP_OUT)
AUDIO_MANAGER_MODULE_OBJS += $(AUDIO_MANAGER_SERVER_INFO_OBJ_CPP_OUT)
AUDIO_MANAGER_MODULE_OBJS += $(AUDIO_MANAGER_USB_PHONE_OBJ_CPP_OUT)

MODULES_OBJS += $(AUDIO_MANAGER_MODULE_OBJS) 
