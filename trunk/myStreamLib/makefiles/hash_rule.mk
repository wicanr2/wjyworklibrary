# hash module rule
$(HASH_MODULE): $(HASH_MODULE_OBJS)

# hash table 
$(OUT_DIRS)/%.o: $(HASH_TABLE_PREFIX)/%.cpp
ifeq ($(ECHO_VERBOSE),$(TRUE))
	$(ECHO) "Compile $<"
endif	
	$(CC) $(COMPILE_FLAGS) $(LINK_FLAGS) -c $^ -o $@

# hash entry 
$(OUT_DIRS)/%.o: $(HASH_ENTRY_PREFIX)/%.cpp
ifeq ($(ECHO_VERBOSE),$(TRUE))
	$(ECHO) "Compile $<"
endif	
	$(CC) $(COMPILE_FLAGS) $(LINK_FLAGS) -c $^ -o $@
