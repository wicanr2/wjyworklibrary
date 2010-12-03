# xml configurator module rule
$(XML_CONFIGURATOR_MODULE): $(XML_CONFIGURATOR_MODULE_OBJS)

# xml profile module
$(OUT_DIRS)/%.o: $(XML_PROFILE_PREFIX)/%.c
ifeq ($(ECHO_VERBOSE),$(TRUE))
	$(ECHO) "Compile $<"
endif	
	$(CC) $(COMPILE_FLAGS) $(LINK_FLAGS) -c $^ -o $@

# xml parser module
$(OUT_DIRS)/%.o: $(XML_PARSER_PREFIX)/%.cpp
ifeq ($(ECHO_VERBOSE),$(TRUE))
	$(ECHO) "Compile $<"
endif	
	$(CC) $(COMPILE_FLAGS) $(LINK_FLAGS) -c $^ -o $@
