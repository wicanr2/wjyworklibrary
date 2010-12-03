# desktop_sharing module rule
$(DESKTOP_SHARING_MODULE): $(DESKTOP_SHARING_MODULE_OBJS)

# Desktop Sharing module
$(OUT_DIRS)/%.o: $(DESKTOP_SHARING_PREFIX)/%.c	
ifeq ($(ECHO_VERBOSE),$(TRUE))
	$(ECHO) "Compile $<"
endif	
	$(CC) $(COMPILE_FLAGS) $(LINK_FLAGS) -c $^ -o $@
