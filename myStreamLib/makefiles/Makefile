


#------------------------------------------------------------------------
# Generate the Archive
# C files

# C object files

# Cpp object files




#--------------------------------------------------
# Check output dir
CheckOutputDir:
	@if test -d $(OUTPUT_LOCATION_OF_OBJECTS); \
    then echo $(OUTPUT_LOCATION_OF_OBJECTS) existed; \
    else mkdir $(OUTPUT_LOCATION_OF_OBJECTS); \
    fi;



# wrong Makefile syntax
#stream:
#	@echo "compile $<"
#	$(CC) $(COMPILE_FLAGS) $(LINK_FLAGS) -g -c $(VIDEOSTREAM_SRC) $(VIDEOSTREAM_CPP)

# many error message print out when use fellow statement
#include $(subst .c,.d,$(VIDEO_SRC))

#%.d: %.c
#	@gcc -M -x c++ -nostdinc -nostdinc++ -I/usr/include/libpurple $(COMPILE_FLAGS)  $< > $@.$$$$;\
#	sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@;\
#	rm -f $@.$$$$	
