.text:
.globl _addtest, _addF

_addF:
	pushl %ebp
	movl  %esp,%ebp
	flds  12(%ebp)
	#fadds 12(%ebp)
	fdiv  8(%ebp)
	#fchs
	#fcos
	popl   %ebp
	ret

_addtest:
	movl 4(%esp), %eax
	addl 8(%esp), %eax
	cmpl $30, %eax
	jne _addtestLeave
	incl %eax
	incl %eax
_addtestLeave:	
	ret
