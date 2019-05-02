	.file	"empty.c"
	.text
	.globl	main
	.type	main, @function
main:
	pushq	%rbp
	movq	%rsp, %rbp
	movl	$5, -4(%rbp)
	cmpl	$5, -4(%rbp)
	jle	.L2
	movl	$1, -4(%rbp)
	jmp	.L4
.L2:
	movl	$2, -4(%rbp)
.L4:
	popq	%rbp
	ret
	.size	main, .-main
	.ident	"GCC: (GNU) 4.8.5 20150623 (Red Hat 4.8.5-36)"
	.section	.note.GNU-stack,"",@progbits
