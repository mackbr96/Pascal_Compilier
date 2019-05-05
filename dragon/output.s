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
foo:
	pushq		%rbp
	movq		%rsp, %rbp
	subq		$32, %rsp
	movq		24(%rbp), %r8
	movq		%r8, -16(%rbp)

# Assignment Evaluation
	movq		-16(%rbp), %r8
# Printing operation
	addq		$10, %r8
# assign gencode
	mov		%r8, -32(%rcx)
# Function Footer
	movq		-8(%rbp), %rax
	movq		%rbp, %rsp
	popq		%rbp
	ret
# FUNCTION HEADER
boo:
	pushq		%rbp
	movq		%rsp, %rbp
	subq		$48, %rsp
	movq		24(%rbp), %r8
	movq		%r8, -40(%rbp)
	movq		32(%rbp), %r8
	movq		%r8, -32(%rbp)

# evaluate 'write' arguments
	movl		-32(%rcx), %edx

# call 'write' using fprintf
	movq		stderr(%rip), %rax
	movl		$.LC1, %esi
	movq		%rax, %rdi
	movl		$0, %eax
	call	fprintf


# Assignment Evaluation
	movq		$10, %r8
# assign gencode
	mov		%r8, -24(%rbp)
# Evaluating Procedure Argsuments
	movq		-24(%rbp), %r8
	pushq		%r8
	movq		%rcx, %rbx
	movq		%rbp, %rcx

# call procedure 'foo'
	call	foo

	movq		%rbx, %rcx

# Assignment Evaluation
	movq		-32(%rcx), %r8
# Printing operation
	addq		-24(%rbp), %r8
# assign gencode
	mov		%r8, -32(%rcx)
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
	mov		%r8, -32(%rbp)
# Evaluating Procedure Argsuments
	movq		$2, %r8
	pushq		%r8
	movq		$10, %r8
	pushq		%r8
	movq		%rcx, %rbx
	movq		%rbp, %rcx

# call procedure 'boo'
	call	boo

	movq		%rbx, %rcx
	movl		$0, %eax
	leave
	ret

	.size	main, .-main


	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.4) 5.4.0 20160609"

	.section	.note.GNU-stack,"",@progbits
