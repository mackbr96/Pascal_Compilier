	.file	"t0.p"
.section	.rodata
.LLC0:
	.string "%d"
.LLC1:
	.string "%d\n"
.LLD0:
	.string "%f"
.LLD1:
	.string "%f\n"
.section	".text"
	.globl main
	.type	main,@function
main:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$8, %esp
	andl	$-16, %esp
	movl	$0, %eax
	subl	%eax, %esp
	call	boo
	leave
	ret
.LLfe0:
	.size	main, .LLfe0-main
	.globl boo
	.type	boo,@function
boo:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$36, %esp
	pushl	%ebx
	pushl	%esi
	pushl	%edi
	movl %ecx, -8(%ebp)
.LL1:
	movl -4(%ebp),%eax
	popl	%edi
	popl	%esi
	popl	%ebx
	addl	$36, %esp
	leave
	ret
.LLfe1:
	.size	boo, .LLfe1-boo
	.section	.note.GNU-stack,"",@progbits
	.ident	"GCC: (GNU) 3.2.3 20030502 (Red Hat Linux 3.2.3-58)"
