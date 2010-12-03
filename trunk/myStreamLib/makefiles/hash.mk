#define module name
HASH_MODULE      := hash_module
HASH_MODULE_OBJS :=
MODULES_POOL      += $(HASH_MODULE)

# hash table 
HASH_TABLE_PREFIX  := hash
HASH_TABLE_SRC_CPP := $(wildcard $(HASH_TABLE_PREFIX)/*.cpp)
HASH_TABLE_OBJ_CPP := $(notdir $(patsubst %.cpp,%.o,$(HASH_TABLE_SRC_CPP)))	
HASH_TABLE_OBJ_CPP_OUT := $(addprefix $(OUT_DIRS)/,$(HASH_TABLE_OBJ_CPP))	

# hash table 
HASH_ENTRY_PREFIX  := hash/hashEntry
HASH_ENTRY_SRC_CPP := $(wildcard $(HASH_ENTRY_PREFIX)/*.cpp)
HASH_ENTRY_OBJ_CPP := $(notdir $(patsubst %.cpp,%.o,$(HASH_ENTRY_SRC_CPP)))	
HASH_ENTRY_OBJ_CPP_OUT := $(addprefix $(OUT_DIRS)/,$(HASH_ENTRY_OBJ_CPP))	

HASH_MODULE_OBJS += $(HASH_TABLE_OBJ_CPP_OUT)
HASH_MODULE_OBJS += $(HASH_ENTRY_OBJ_CPP_OUT)

MODULES_OBJS += $(HASH_MODULE_OBJS) 
