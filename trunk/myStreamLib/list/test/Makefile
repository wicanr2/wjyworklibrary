GCC := @gcc
RM  := @rm
ECHO := @echo
all:
	$(ECHO) generate test file
	$(GCC) -I../../include/ -lstdc++ ../../utils/debugClass/*.cpp *.cpp -o test
clean:
	$(ECHO) remove test
	$(RM) test
