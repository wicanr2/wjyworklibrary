# rule database
# parameter module rule
$(PARAMETER_MANAGER_MODULE): $(PARAMETER_MANAGER_MODULE_OBJS)

# parameter manager 
$(OUT_DIRS)/%.o: $(PARAMETER_MANAGER_PREFIX)/%.cpp
ifeq ($(ECHO_VERBOSE),$(TRUE))
	$(ECHO) "Compile $<"
endif	
	$(CC) $(COMPILE_FLAGS) $(LINK_FLAGS) -c $^ -o $@

# GSTCaps parameter
$(OUT_DIRS)/%.o: $(GST_CAPS_PREFIX)/%.cpp
ifeq ($(ECHO_VERBOSE),$(TRUE))
	$(ECHO) "Compile $<"
endif	
	$(CC) $(COMPILE_FLAGS) $(LINK_FLAGS) -c $^ -o $@

# paraMJPEG parameter  
$(OUT_DIRS)/%.o: $(PARA_MJPEG_PREFIX)/%.cpp
ifeq ($(ECHO_VERBOSE),$(TRUE))
	$(ECHO) "Compile $<"
endif	
	$(CC) $(COMPILE_FLAGS) $(LINK_FLAGS) -c $^ -o $@

# paraMultiUDPSink parameter 
$(OUT_DIRS)/%.o: $(PARA_MULTIUDPSINK_PREFIX)/%.cpp
ifeq ($(ECHO_VERBOSE),$(TRUE))
	$(ECHO) "Compile $<"
endif	
	$(CC) $(COMPILE_FLAGS) $(LINK_FLAGS) -c $^ -o $@

# paraUDPSink parameter 
$(OUT_DIRS)/%.o: $(PARA_UDPSINK_PREFIX)/%.cpp
ifeq ($(ECHO_VERBOSE),$(TRUE))
	$(ECHO) "Compile $<"
endif	
	$(CC) $(COMPILE_FLAGS) $(LINK_FLAGS) -c $^ -o $@

# paraUDPSrc parameter 
$(OUT_DIRS)/%.o: $(PARA_UDPSRC_PREFIX)/%.cpp
ifeq ($(ECHO_VERBOSE),$(TRUE))
	$(ECHO) "Compile $<"
endif	
	$(CC) $(COMPILE_FLAGS) $(LINK_FLAGS) -c $^ -o $@

# paraV4L2 parameter 
$(OUT_DIRS)/%.o: $(PARA_V4L2_PREFIX)/%.cpp
ifeq ($(ECHO_VERBOSE),$(TRUE))
	$(ECHO) "Compile $<"
endif	
	$(CC) $(COMPILE_FLAGS) $(LINK_FLAGS) -c $^ -o $@

# paraVideoRate parameter 
$(OUT_DIRS)/%.o: $(PARA_VIDEO_RATE_PREFIX)/%.cpp
ifeq ($(ECHO_VERBOSE),$(TRUE))
	$(ECHO) "Compile $<"
endif	
	$(CC) $(COMPILE_FLAGS) $(LINK_FLAGS) -c $^ -o $@

# paraVideoScale parameter 
$(OUT_DIRS)/%.o: $(PARA_VIDEO_SCALE_PREFIX)/%.cpp
ifeq ($(ECHO_VERBOSE),$(TRUE))
	$(ECHO) "Compile $<"
endif	
	$(CC) $(COMPILE_FLAGS) $(LINK_FLAGS) -c $^ -o $@

# paraX264Enc parameter 
$(OUT_DIRS)/%.o: $(PARA_X264_ENC_PREFIX)/%.cpp
ifeq ($(ECHO_VERBOSE),$(TRUE))
	$(ECHO) "Compile $<"
endif	
	$(CC) $(COMPILE_FLAGS) $(LINK_FLAGS) -c $^ -o $@

# paraAudioConvert parameter 
$(OUT_DIRS)/%.o: $(PARA_AUDIO_CONVERT_PREFIX)/%.cpp
ifeq ($(ECHO_VERBOSE),$(TRUE))
	$(ECHO) "Compile $<"
endif	
	$(CC) $(COMPILE_FLAGS) $(LINK_FLAGS) -c $^ -o $@

# paraAudioResample parameter 
$(OUT_DIRS)/%.o: $(PARA_AUDIO_RESAMPLE_PREFIX)/%.cpp
ifeq ($(ECHO_VERBOSE),$(TRUE))
	$(ECHO) "Compile $<"
endif	
	$(CC) $(COMPILE_FLAGS) $(LINK_FLAGS) -c $^ -o $@

# paraGSTRtpJitterBuffer parameter 
$(OUT_DIRS)/%.o: $(PARA_GST_RTP_JITTER_BUFFER_PREFIX)/%.cpp
ifeq ($(ECHO_VERBOSE),$(TRUE))
	$(ECHO) "Compile $<"
endif	
	$(CC) $(COMPILE_FLAGS) $(LINK_FLAGS) -c $^ -o $@

# paraPulseSrc parameter 
$(OUT_DIRS)/%.o: $(PARA_PULSE_SRC_PREFIX)/%.cpp
ifeq ($(ECHO_VERBOSE),$(TRUE))
	$(ECHO) "Compile $<"
endif	
	$(CC) $(COMPILE_FLAGS) $(LINK_FLAGS) -c $^ -o $@
