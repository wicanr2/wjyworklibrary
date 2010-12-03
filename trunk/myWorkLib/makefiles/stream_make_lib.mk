include makefiles/include.mk

PATH_OF_MAKEFILES := $(PWD)/makefiles
INCLUDE_MAKEFILES := $(addprefix $(PATH_OF_MAKEFILES)/,$(MAKEFILES))
INCLUDE_RULE_MAKEFILES := $(addprefix $(PATH_OF_MAKEFILES)/,$(RULE_MAKEFILES))

include $(INCLUDE_MAKEFILES) 

# define phony list
.PHONY : clean $(MODULES_POOL)

all:$(VIDEOSTREAM_LIB) 
#	$(ECHO) $(MODULES_OBJS)

#$(VIDEOSTREAM_LIB): $(MODULE_POOL) $(OUT_DIRS) $(VIDEOSTREAM_OBJS) $(VIDEOSTREAM_CPP_OBJS)	
#	$(ECHO) "Archive $(VIDEOSTREAM_LIB)"
#	$(AR) rcs $@ $(VIDEOSTREAM_OBJS) $(VIDEOSTREAM_CPP_OBJS) 

$(VIDEOSTREAM_LIB): $(OUT_DIRS) $(MODULES_OBJS) 
	$(ECHO) "Archive $(VIDEOSTREAM_LIB)"
	$(AR) rcs $(VIDEOSTREAM_LIB) $(OUT_DIRS)/*.o 
#	$(STRIP) $(VIDEOSTREAM_LIB)	

$(OUT_DIRS): 
ifeq ($(ECHO_VERBOSE),$(TRUE))
	$(ECHO) "Create Objects Directory [$(OUT_DIRS)]"
endif	
	$(MKDIR) $(OUT_DIRS) 

clean: 
ifeq ($(ECHO_VERBOSE),$(TRUE))
	$(ECHO) "Remove all objects" 
endif	
	$(RM) -rf $(OUT_DIRS) 
	$(RM) -rf $(VIDEOSTREAM_LIB) 

include $(INCLUDE_RULE_MAKEFILES)
