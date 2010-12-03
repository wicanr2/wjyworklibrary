# peer module rule
$(PEER_MODULE): $(PEER_MODULE_OBJS)

# peerInfo module
$(OUT_DIRS)/%.o: $(PEERINFO_PREFIX)/%.cpp	
ifeq ($(ECHO_VERBOSE),$(TRUE))
	$(ECHO) "Compile $<"
endif	
	$(CC) $(COMPILE_FLAGS) $(LINK_FLAGS) -c $^ -o $@

# peerInfo/peer module
$(OUT_DIRS)/%.o: $(PEER_PREFIX)/%.cpp 
ifeq ($(ECHO_VERBOSE),$(TRUE))
	$(ECHO) "Compile $<"
endif	
	$(CC) $(COMPILE_FLAGS) $(LINK_FLAGS) -c $^ -o $@

# peerInfo/peerVector module
$(OUT_DIRS)/%.o: $(PEERVECTOR_PREFIX)/%.cpp 
ifeq ($(ECHO_VERBOSE),$(TRUE))
	$(ECHO) "Compile $<"
endif	
	$(CC) $(COMPILE_FLAGS) $(LINK_FLAGS) -c $^ -o $@
