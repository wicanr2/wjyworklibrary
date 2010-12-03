#define module name
UTILS_MODULE      := utils_module
UTILS_MODULE_OBJS :=
MODULES_POOL      += $(UTILS_MODULE)

# Mutex Locker 
LOCKER_PREFIX  := utils/mutexLocker
LOCKER_SRC_CPP := $(wildcard $(LOCKER_PREFIX)/*.cpp)
LOCKER_OBJ_CPP := $(notdir $(patsubst %.cpp,%.o,$(LOCKER_SRC_CPP)))	
LOCKER_OBJ_CPP_OUT := $(addprefix $(OUT_DIRS)/,$(LOCKER_OBJ_CPP))	

# Static Mutex Locker
STATIC_LOCKER_PREFIX  := utils/staticMutexLocker
STATIC_LOCKER_SRC_CPP := $(wildcard $(STATIC_LOCKER_PREFIX)/*.cpp)
STATIC_LOCKER_OBJ_CPP := $(notdir $(patsubst %.cpp,%.o,$(STATIC_LOCKER_SRC_CPP)))	
STATIC_LOCKER_OBJ_CPP_OUT := $(addprefix $(OUT_DIRS)/,$(STATIC_LOCKER_OBJ_CPP))

# debug class
DEBUG_CLASS_PREFIX  := utils/debugClass
DEBUG_CLASS_SRC_CPP := $(wildcard $(DEBUG_CLASS_PREFIX)/*.cpp)
DEBUG_CLASS_OBJ_CPP := $(notdir $(patsubst %.cpp,%.o,$(DEBUG_CLASS_SRC_CPP)))	
DEBUG_CLASS_OBJ_CPP_OUT := $(addprefix $(OUT_DIRS)/,$(DEBUG_CLASS_OBJ_CPP))

# filechecker class
FILE_CHECKER_PREFIX  := utils/fileChecker
FILE_CHECKER_SRC_CPP := $(wildcard $(FILE_CHECKER_PREFIX)/*.cpp)
FILE_CHECKER_OBJ_CPP := $(notdir $(patsubst %.cpp,%.o,$(FILE_CHECKER_SRC_CPP)))	
FILE_CHECKER_OBJ_CPP_OUT := $(addprefix $(OUT_DIRS)/,$(FILE_CHECKER_OBJ_CPP))

UTILS_MODULE_OBJS += $(LOCKER_OBJ_CPP_OUT)
UTILS_MODULE_OBJS += $(STATIC_LOCKER_OBJ_CPP_OUT)
UTILS_MODULE_OBJS += $(DEBUG_CLASS_OBJ_CPP_OUT)
UTILS_MODULE_OBJS += $(FILE_CHECKER_OBJ_CPP_OUT)

MODULES_OBJS += $(UTILS_MODULE_OBJS) 
