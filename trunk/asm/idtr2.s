.text:
.globl _loadIDTR2
_loadIDTR2:
	pushl %ebp
	movl  %esp,%ebp
	movl  8(%esp), %eax
	sidt  (%eax)
	popl  %ebp
	ret
