.code16
.intel_syntax noprefix 
.section .text
.equ boot_mem_location, 0x7c00
.equ write_text_int, 0x0e
main:
	jmp start_prog
	nop
	.ascii "HELLOIPL"
	.word 512
	.byte 1
	.word 1
	.byte 2
	.word 224
	.word 2880
	.byte 0xf0
	.word 9
	.word 18
	.word 2
	.long 0
	.long 2880
	.byte 0x0, 0x0, 0x29
	.long 0xffffffff
	.ascii "Hello-os   "
	.ascii "FAT12   "
    .fill 18,1,0	 
start_prog:
	xor eax, eax
	mov ss, ax
	mov ds, ax
	mov es, ax
	#mov si, offset flat:[msg]
	#lea si, byte ptr msg
#----------------------
# symbol version
# 這個可能是 gnu as 的 bug 相同的 code 用 at&t syntax translate 出來與 intel syntax不一樣
	#mov si, 0x72 
	#addr16 si, boot_mem_location
	xor si, si
	add si, 0x74 
	add si, boot_mem_location 
#----------------------
# work 
#	mov si, 0x72 
#	add si, 0x7c00
#----------------------

loop:
	mov ah, 0x0e
	mov al,byte ptr [si]
	cmp al, 0
	je fin
	int 0x10
	add si,1
	jmp loop
fin:
	nop
	jmp fin
#start_prog:
#	.byte 0xb8, 0x00, 0x00, 0x8e, 0xd0, 0xbc, 0x00, 0x7c
#	.byte 0x8e, 0xd8, 0x8e, 0xc0, 0xbe, 0x74, 0x7c, 0x8a
#	.byte 0x04, 0x83, 0xc6, 0x01, 0x3c, 0x00, 0x74, 0x09
#	.byte 0xb4, 0x0e, 0xbb, 0x0f, 0x00, 0xcd, 0x10, 0xeb
#	.byte 0xee, 0xf4, 0xeb, 0xfd
msg: 
	.byte 0x0a, 0x0a
	.ascii "Hello, World"
	.byte 0x0a
	.byte 0
	.org 0x1fe, 0
	.byte 0x55, 0xaa
	.byte 0xf0, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00
	.fill 4600,1,0
	.byte 0xf0, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00
	.fill 1469432,1,0

	



