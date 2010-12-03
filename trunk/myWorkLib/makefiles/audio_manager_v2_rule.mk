# rule database

# peer module rule
$(AUDIO_MANAGER_MODULE): $(AUDIO_MANAGER_MODULE_OBJS)

# AUDIO_MANAGER C API module
$(OUT_DIRS)/%.o: $(AUDIO_MANAGER_PREFIX)/%.cpp	
ifeq ($(ECHO_VERBOSE),$(TRUE))
	$(ECHO) "Compile $<"
endif	
	$(CC) $(COMPILE_FLAGS) $(LINK_FLAGS) -c $^ -o $@

# AUDIO_MANAGER device bindle module
$(OUT_DIRS)/%.o: $(AUDIO_MANAGER_DEVICE_BINDLE_PREFIX)/%.cpp	
ifeq ($(ECHO_VERBOSE),$(TRUE))
	$(ECHO) "Compile $<"
endif	
	$(CC) $(COMPILE_FLAGS) $(LINK_FLAGS) -c $^ -o $@

# AUDIO_MANAGER management module
$(OUT_DIRS)/%.o: $(AUDIO_MANAGER_AUDIO_MANAGEMENT_PREFIX)/%.cpp	
ifeq ($(ECHO_VERBOSE),$(TRUE))
	$(ECHO) "Compile $<"
endif	
	$(CC) $(COMPILE_FLAGS) $(LINK_FLAGS) -c $^ -o $@

# AUDIO_MANAGER device profile module
$(OUT_DIRS)/%.o: $(AUDIO_MANAGER_DEVICE_PROFILE_PREFIX)/%.cpp	
ifeq ($(ECHO_VERBOSE),$(TRUE))
	$(ECHO) "Compile $<"
endif	
	$(CC) $(COMPILE_FLAGS) $(LINK_FLAGS) -c $^ -o $@

# AUDIO_MANAGER server infor module
$(OUT_DIRS)/%.o: $(AUDIO_MANAGER_SERVER_INFO_PREFIX)/%.cpp	
ifeq ($(ECHO_VERBOSE),$(TRUE))
	$(ECHO) "Compile $<"
endif	
	$(CC) $(COMPILE_FLAGS) $(LINK_FLAGS) -c $^ -o $@

# AUDIO_MANAGER usb phone module
$(OUT_DIRS)/%.o: $(AUDIO_MANAGER_USB_PHONE_PREFIX)/%.cpp	
ifeq ($(ECHO_VERBOSE),$(TRUE))
	$(ECHO) "Compile $<"
endif	
	$(CC) $(COMPILE_FLAGS) $(LINK_FLAGS) -c $^ -o $@
