# video module rule
$(VIDEO_MODULE): $(VIDEO_MODULE_OBJS)

# video module
$(OUT_DIRS)/%.o: $(VIDEO_PREFIX)/%.c
ifeq ($(ECHO_VERBOSE),$(TRUE))
	$(ECHO) "Compile $<"
endif	
	$(CC) $(COMPILE_FLAGS) $(LINK_FLAGS) -c $^ -o $@
