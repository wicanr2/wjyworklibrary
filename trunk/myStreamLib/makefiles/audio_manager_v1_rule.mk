# define module rule
$(AUDIO_MODULE): $(AUDIO_MODULE_OBJS)

# Audio Manager V1 module
$(OUT_DIRS)/%.o: $(AUDIO_PREFIX)/%.c 
ifeq ($(ECHO_VERBOSE),$(TRUE))
	$(ECHO) "Compile $<"
endif	
	$(CC) $(COMPILE_FLAGS) $(LINK_FLAGS) -c $^ -o $@
