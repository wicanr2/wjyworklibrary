include makefiles/variables.mk
ifeq ($(MAKE_STREAM_LIBRARY),$(TRUE))
include $(PWD)/makefiles/stream_make_lib.mk
else
include $(PWD)/makefiles/thread_test.mk
endif

.PHONY: help
help:
	$(ECHO) "\n"
	$(ECHO) "\t_______________ The Stream Libary Make Command ___________________"
	$(ECHO) "\t                                                                  "
	$(ECHO) "\tmake          : Create the stream library sliently."
	$(ECHO) "\tmake verbose=1: Enable the verbose in the creating stream library."
	$(ECHO) "\tmake clean    : Clean  the stream library."
	$(ECHO) "\t__________________________________________________________________"
	$(ECHO) "\n"

