# tranfer manager 
$(OUT_DIRS)/%.o: $(TRANSFER_MANAGER_PREFIX)/%.cpp
ifeq ($(ECHO_VERBOSE),$(TRUE))
	$(ECHO) "Compile $<"
endif	
	$(CC) $(COMPILE_FLAGS) $(LINK_FLAGS) -c $^ -o $@

# capture mjpeg stream
$(OUT_DIRS)/%.o: $(CAPTURE_MJPEG_STREAM_PREFIX)/%.cpp
ifeq ($(ECHO_VERBOSE),$(TRUE))
	$(ECHO) "Compile $<"
endif	
	$(CC) $(COMPILE_FLAGS) $(LINK_FLAGS) -c $^ -o $@

# transcode mjpeg to h264 stream
$(OUT_DIRS)/%.o: $(TRANSCODE_MJPEG_TO_H264_STREAM_PREFIX)/%.cpp
ifeq ($(ECHO_VERBOSE),$(TRUE))
	$(ECHO) "Compile $<"
endif	
	$(CC) $(COMPILE_FLAGS) $(LINK_FLAGS) -c $^ -o $@

# capture audio raw stream
$(OUT_DIRS)/%.o: $(CAPTURE_AUDIO_RAW_STREAM_PREFIX)/%.cpp
ifeq ($(ECHO_VERBOSE),$(TRUE))
	$(ECHO) "Compile $<"
endif	
	$(CC) $(COMPILE_FLAGS) $(LINK_FLAGS) -c $^ -o $@
