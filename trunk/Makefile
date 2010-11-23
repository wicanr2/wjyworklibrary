CC=gcc
RM=del
ECHO=echo

.PHONY: testasm clean 

all: testasm
	$(ECHO) Hello Win32 Makefile World

testasm:
	$(CC) -Iasm asm/*.s asm/*.c -o testasm.exe

clean:
	$(RM) *.exe *.o 
