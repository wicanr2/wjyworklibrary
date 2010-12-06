all:
	gcc -c -O0 helloip.S -o hello.o
	objcopy -O binary hello.o hello.bin
	objdump -d hello.o > hello.txt
	gcc -c helloip_at_and_t.S -o hello2.o
	objcopy -O binary hello2.o hello2.bin
	objdump -d hello2.o > hello2.txt
clean:
	del hello.bin *.o
