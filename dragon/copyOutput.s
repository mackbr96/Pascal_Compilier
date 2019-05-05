	.file	"output.s"
	.section	.rodata
.LC0: # reading
	.string "%d"
	.text
	.global	main
	.type main, @function
.LC1: # writing
	.string "%d\n"
	.text
	.global	main
	.type main, @function
# FUNCTION HEADER
boo:
	pushq		%rbp
	movq		%rsp, %rbp
	subq		$64, %rsp
	movq		16(%rbp), %r8
	movq		%r8, -8(%rbp)
	movq		24(%rbp), %r8
	movq		%r8, -8(%rbp)

# Assignment Evaluation
	movq		-8(%rcx), %r8
# Printing operation
	addq		$1, %r8
# assign gencode
	mov		%r8, -8(%rcx)
# Function Footer
	movq		-8(%rbp), %rax
	movq		%rbp, %rsp
	popq		%rbp
	ret
main:
	pushq		%rbp
	movq		%rsp, %rbp
	pushq		$0
	pushq		%rbp
	movq		%rbp, %rcx

# Assignment Evaluation
	movq		$10, %r8
# assign gencode
	mov		%r8, -8(%rbp)
# Evaluating Procedure Argsuments
	movq		$2, %r8
	pushq		%r8
	movq		$2, %r8
	pushq		%r8
	movq		%rcx, %r8
	movq		%rbp, %rcx

# call procedure 'boo'
	call	boo

	movq		%r8, %rcx

# evaluate 'write' arguments
	movl		-8(%rbp), %edx

# call 'write' using fprintf
	movq		stderr(%rip), %rax
	movl		$.LC1, %esi
	movq		%rax, %rdi
	movl		$0, %eax
	call	fprintf

	movl		$0, %eax
	leave
	ret

	.size	main, .-main


	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.4) 5.4.0 20160609"

	.section	.note.GNU-stack,"",@progbits
