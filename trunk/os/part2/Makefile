all:
	gcc -c helloip_at_and_t.S -o hello.o
	ld -T my.ld -o hello.out hello.o
	objcopy -O binary hello.out hello.bin

#ld -nostdlib -nostartfiles --no-undefined -Ttext 0x7c00 -j .text -e _start -o hello.out hello.o
#objcopy -O binary hello.out hello.bin

#ld -static -Ttext 0x7c00 -e _start -o hello.out hello.o
#objcopy -O binary -j .text hello.out hello.bin
clean:
	del hello.bin
	del hello.out
	del hello.o
