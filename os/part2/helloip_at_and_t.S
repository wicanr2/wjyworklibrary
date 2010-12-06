.code16
.section .text
.global _start
_start:
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
	xor %eax,%eax
	movw %ax, %ss
	movw $0xf000, %sp
	movw %ax, %ds
	movw %ax, %es
	movw $msg, %si
loop:
	movb (%si), %al
	cmpb $0, %al
	je read_1_sector 
	movb $0xe, %ah
	movw $15, %bx
	int $0x10
	inc %si
	jmp loop

read_1_sector:
	movw $0x0820, %ax
	movw %ax, %es
	movb $0, %ch # cylinder 
	movb $0, %dh # head
	movb $2, %cl # sector
	
	xor %si, %si # si == 0
read_retry:
	movb $0x02, %ah # read fdd
	movb $0x01, %al # sector number 1
	movb $0, %dl # fdd 0
	movw $0, %bx
	int $0x13 # call bios to read something
	jnc read_ok
	inc %si
	cmpw $5, %si
	jae error
reset_fdd:
	movb $0, %ah
	movb $0, %dl
	int $0x13
	jmp read_retry

read_ok:
	movw $msg_success, %si
loop_2:
	movb (%si), %al
	cmpb $0, %al
	je fin
	movb $0xe, %ah
	movw $15, %bx
	int $0x10
	inc %si
	jmp loop_2

fin:
	hlt
	jmp fin
error:
	movw $msg_error, %si
loop_3:
	movb (%si), %al
	cmpb $0, %al
	je fin
	movb $0xe, %ah
	movw $15, %bx
	int $0x10
	inc %si
	jmp loop_3
#------------------------------------------------------
msg:
  	.byte 0x0a, 0x0a
	.ascii "Hello, World"
	.byte 0x0a
	.byte 0
msg_success:
	.asciz "Read 1 Sector Success\n"
msg_error:
	.asciz "Error Occurred\n"
	.org 0x1fe, 0
	.byte 0x55, 0xaa
