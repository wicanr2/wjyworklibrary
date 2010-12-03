# XML configurator 2 module rule
$(XML_CONFIGURATOR_2_MODULE): $(XML_CONFIGURATOR_2_MODULE_OBJS)

# XML parser 2 module
$(OUT_DIRS)/%.o: $(XML_PARSER_2_PREFIX)/%.cpp
ifeq ($(ECHO_VERBOSE),$(TRUE))
	$(ECHO) "Compile $<"
endif	
	$(CC) $(COMPILE_FLAGS) $(LINK_FLAGS) -c $^ -o $@

# XML profile 2 module
$(OUT_DIRS)/%.o: $(XML_PROFILE_2_PREFIX)/%.cpp
ifeq ($(ECHO_VERBOSE),$(TRUE))
	$(ECHO) "Compile $<"
endif	
	$(CC) $(COMPILE_FLAGS) $(LINK_FLAGS) -c $^ -o $@

# XML attributes 2 module
$(OUT_DIRS)/%.o: $(XML_ATTRIBUTES_2_PREFIX)/%.cpp
ifeq ($(ECHO_VERBOSE),$(TRUE))
	$(ECHO) "Compile $<"
endif	
	$(CC) $(COMPILE_FLAGS) $(LINK_FLAGS) -c $^ -o $@

# XML elements 2 module
$(OUT_DIRS)/%.o: $(XML_ELEMENTS_2_PREFIX)/%.cpp
ifeq ($(ECHO_VERBOSE),$(TRUE))
	$(ECHO) "Compile $<"
endif	
	$(CC) $(COMPILE_FLAGS) $(LINK_FLAGS) -c $^ -o $@
