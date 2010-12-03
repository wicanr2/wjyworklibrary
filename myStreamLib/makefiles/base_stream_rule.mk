# rule database

# base stream module rule
$(BASE_STREAM_MODULE): $(BASE_STREAM_MODULE_OBJS)

# base stream 
$(OUT_DIRS)/%.o: $(BASE_STREAM_PREFIX)/%.cpp
ifeq ($(ECHO_VERBOSE),$(TRUE))
	$(ECHO) "Compile $<"
endif	
	$(CC) $(COMPILE_FLAGS) $(LINK_FLAGS) -c $^ -o $@
