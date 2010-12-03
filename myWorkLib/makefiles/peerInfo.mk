#define module name
PEER_MODULE      := peer_module
PEER_MODULE_OBJS :=
MODULES_POOL     += $(PEER_MODULE)

# PeerInfo 
PEERINFO_PREFIX  := peerInfo
PEERINFO_SRC_CPP := $(wildcard $(PEERINFO_PREFIX)/*.cpp)
PEERINFO_OBJ_CPP := $(notdir $(patsubst %.cpp,%.o,$(PEERINFO_SRC_CPP)))	
PEERINFO_OBJ_CPP_OUT := $(addprefix $(OUT_DIRS)/,$(PEERINFO_OBJ_CPP))

# PeerVector
PEERVECTOR_PREFIX := peerInfo/peerVector
PEERVECTOR_SRC_CPP := $(wildcard $(PEERVECTOR_PREFIX)/*.cpp)
PEERVECTOR_OBJ_CPP := $(notdir $(patsubst %.cpp,%.o,$(PEERVECTOR_SRC_CPP)))	
PEERVECTOR_OBJ_CPP_OUT := $(addprefix $(OUT_DIRS)/,$(PEERVECTOR_OBJ_CPP))

# Peer 
PEER_PREFIX := $(PEERINFO_PREFIX)/peer
PEER_SRC_CPP := $(wildcard $(PEER_PREFIX)/*.cpp)
PEER_OBJ_CPP := $(notdir $(patsubst %.cpp,%.o,$(PEER_SRC_CPP)))	
PEER_OBJ_CPP_OUT := $(addprefix $(OUT_DIRS)/,$(PEER_OBJ_CPP))

PEER_MODULE_OBJS += $(PEERINFO_OBJ_CPP_OUT)
PEER_MODULE_OBJS += $(PEERVECTOR_OBJ_CPP_OUT)
PEER_MODULE_OBJS += $(PEER_OBJ_CPP_OUT)

MODULES_OBJS += $(PEER_MODULE_OBJS) 
