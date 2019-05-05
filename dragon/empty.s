	.file	"empty.c"
	.globl	outside
	.data
	.align 4
	.type	outside, @object
	.size	outside, 4
outside:
	.long	5
	.text
	.globl	foo
	.type	foo, @function
foo:
	pushq	%rbp
	movq	%rsp, %rbp
	movl	%edi, -4(%rbp)
	movl	outside(%rip), %edx
	movl	-4(%rbp), %eax
	addl	%edx, %eax
	popq	%rbp
	ret
	.size	foo, .-foo
	.globl	main
	.type	main, @function
main:
	pushq	%rbp
	movq	%rsp, %rbp
	subq	$16, %rsp
	movl	$9, -4(%rbp)
	movl	-4(%rbp), %eax
	movl	%eax, %edi
	call	foo
	movl	%eax, -8(%rbp)
	leave
	ret
	.size	main, .-main
	.ident	"GCC: (GNU) 4.8.5 20150623 (Red Hat 4.8.5-36)"
	.section	.note.GNU-stack,"",@progbits
