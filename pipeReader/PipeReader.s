	.file	"PipeReader.cpp"
	.text
	.align 2
.globl __ZN10pipeReaderC2Ev
	.def	__ZN10pipeReaderC2Ev;	.scl	2;	.type	32;	.endef
__ZN10pipeReaderC2Ev:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	$0, (%eax)
	movl	8(%ebp), %eax
	movl	$0, 4(%eax)
	movl	8(%ebp), %eax
	movl	$0, 8(%eax)
	movl	8(%ebp), %eax
	movl	$0, 12(%eax)
	movl	$67108864, -4(%ebp)
	movl	$80, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN10pipeReader11SetLineSizeEi
	movl	-4(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN10pipeReader17SetOutputPoolSizeEi
	leave
	ret
	.align 2
.globl __ZN10pipeReaderC1Ev
	.def	__ZN10pipeReaderC1Ev;	.scl	2;	.type	32;	.endef
__ZN10pipeReaderC1Ev:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	$0, (%eax)
	movl	8(%ebp), %eax
	movl	$0, 4(%eax)
	movl	8(%ebp), %eax
	movl	$0, 8(%eax)
	movl	8(%ebp), %eax
	movl	$0, 12(%eax)
	movl	$67108864, -4(%ebp)
	movl	$80, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN10pipeReader11SetLineSizeEi
	movl	-4(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN10pipeReader17SetOutputPoolSizeEi
	leave
	ret
	.align 2
.globl __ZN10pipeReaderD2Ev
	.def	__ZN10pipeReaderD2Ev;	.scl	2;	.type	32;	.endef
__ZN10pipeReaderD2Ev:
	pushl	%ebp
	movl	%esp, %ebp
	popl	%ebp
	ret
	.align 2
.globl __ZN10pipeReaderD1Ev
	.def	__ZN10pipeReaderD1Ev;	.scl	2;	.type	32;	.endef
__ZN10pipeReaderD1Ev:
	pushl	%ebp
	movl	%esp, %ebp
	popl	%ebp
	ret
	.align 2
.globl __ZN10pipeReader11SetLineSizeEi
	.def	__ZN10pipeReader11SetLineSizeEi;	.scl	2;	.type	32;	.endef
__ZN10pipeReader11SetLineSizeEi:
	pushl	%ebp
	movl	%esp, %ebp
	movl	8(%ebp), %eax
	movl	12(%ebp), %edx
	movl	%edx, 8(%eax)
	movl	$0, %eax
	popl	%ebp
	ret
	.align 2
.globl __ZN10pipeReader17SetOutputPoolSizeEi
	.def	__ZN10pipeReader17SetOutputPoolSizeEi;	.scl	2;	.type	32;	.endef
__ZN10pipeReader17SetOutputPoolSizeEi:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%ebx
	subl	$20, %esp
	movl	8(%ebp), %eax
	cmpl	$0, (%eax)
	je	L11
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, (%esp)
	call	_free
L11:
	movl	8(%ebp), %eax
	movl	12(%ebp), %edx
	movl	%edx, 4(%eax)
	movl	8(%ebp), %eax
	cmpl	$0, 4(%eax)
	jle	L12
	movl	8(%ebp), %ebx
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	movl	%eax, (%esp)
	call	_malloc
	movl	%eax, (%ebx)
	jmp	L13
L12:
	movl	$-1, -8(%ebp)
	jmp	L10
L13:
	movl	$0, -8(%ebp)
L10:
	movl	-8(%ebp), %eax
	addl	$20, %esp
	popl	%ebx
	popl	%ebp
	ret
	.section .rdata,"dr"
LC0:
	.ascii "r\0"
	.text
	.align 2
.globl __ZN10pipeReader10RunCommandEPc
	.def	__ZN10pipeReader10RunCommandEPc;	.scl	2;	.type	32;	.endef
__ZN10pipeReader10RunCommandEPc:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$40, %esp
	movl	$LC0, 4(%esp)
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__popen
	movl	%eax, -4(%ebp)
	movl	$0, -8(%ebp)
	movl	$0, -12(%ebp)
	movl	$0, -16(%ebp)
	movl	$0, -20(%ebp)
	cmpl	$0, -4(%ebp)
	jne	L15
	movl	$-1, -24(%ebp)
	jmp	L14
L15:
	movl	8(%ebp), %eax
	cmpl	$0, (%eax)
	jne	L16
	movl	$-1, -24(%ebp)
	jmp	L14
L16:
	movl	8(%ebp), %eax
	cmpl	$0, 8(%eax)
	jne	L17
	movl	$-1, -24(%ebp)
	jmp	L14
L17:
	movl	$0, -16(%ebp)
L18:
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	cmpl	-16(%ebp), %eax
	jle	L21
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	addl	-16(%ebp), %eax
	movb	$0, (%eax)
	leal	-16(%ebp), %eax
	incl	(%eax)
	jmp	L18
L21:
	movl	-4(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	8(%ebp), %eax
	movl	8(%eax), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %edx
	movl	-8(%ebp), %eax
	addl	(%edx), %eax
	movl	%eax, (%esp)
	call	_fgets
	movl	%eax, -20(%ebp)
	cmpl	$0, -20(%ebp)
	jne	L23
	jmp	L22
L23:
	movl	8(%ebp), %eax
	movl	8(%eax), %edx
	leal	-8(%ebp), %eax
	addl	%edx, (%eax)
	jmp	L21
L22:
	movl	-4(%ebp), %eax
	movl	%eax, (%esp)
	call	__pclose
	movl	8(%ebp), %edx
	movl	-8(%ebp), %eax
	movl	%eax, 12(%edx)
	movl	-8(%ebp), %eax
	movl	%eax, -24(%ebp)
L14:
	movl	-24(%ebp), %eax
	leave
	ret
	.section .rdata,"dr"
LC1:
	.ascii "%s\0"
LC2:
	.ascii "[%d] %s\12\0"
	.text
	.align 2
.globl __ZN10pipeReader4DumpEv
	.def	__ZN10pipeReader4DumpEv;	.scl	2;	.type	32;	.endef
__ZN10pipeReader4DumpEv:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$568, %esp
	movl	$0, -12(%ebp)
	movl	$0, -540(%ebp)
	movl	8(%ebp), %eax
	cmpl	$0, (%eax)
	jne	L25
	movl	$-1, -544(%ebp)
	jmp	L24
L25:
	movl	8(%ebp), %eax
	cmpl	$0, 4(%eax)
	jne	L26
	movl	$-1, -544(%ebp)
	jmp	L24
L26:
	movl	8(%ebp), %eax
	cmpl	$0, 8(%eax)
	jne	L28
	movl	$-1, -544(%ebp)
	jmp	L24
L28:
	movl	8(%ebp), %eax
	movl	12(%eax), %eax
	cmpl	-12(%ebp), %eax
	jle	L29
	movl	8(%ebp), %edx
	movl	-12(%ebp), %eax
	addl	(%edx), %eax
	movl	%eax, 12(%esp)
	movl	$LC1, 8(%esp)
	movl	8(%ebp), %eax
	movl	8(%eax), %eax
	movl	%eax, 4(%esp)
	leal	-536(%ebp), %eax
	movl	%eax, (%esp)
	call	_snprintf
	leal	-536(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	-540(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC2, (%esp)
	call	_printf
	leal	-540(%ebp), %eax
	incl	(%eax)
	movl	8(%ebp), %eax
	movl	8(%eax), %edx
	leal	-12(%ebp), %eax
	addl	%edx, (%eax)
	jmp	L28
L29:
	movl	$0, -544(%ebp)
L24:
	movl	-544(%ebp), %eax
	leave
	ret
	.def	_printf;	.scl	2;	.type	32;	.endef
	.def	_snprintf;	.scl	2;	.type	32;	.endef
	.def	__pclose;	.scl	3;	.type	32;	.endef
	.def	_fgets;	.scl	3;	.type	32;	.endef
	.def	__popen;	.scl	3;	.type	32;	.endef
	.def	_malloc;	.scl	2;	.type	32;	.endef
	.def	_free;	.scl	3;	.type	32;	.endef
	.def	__ZN10pipeReader17SetOutputPoolSizeEi;	.scl	3;	.type	32;	.endef
	.def	__ZN10pipeReader11SetLineSizeEi;	.scl	3;	.type	32;	.endef
