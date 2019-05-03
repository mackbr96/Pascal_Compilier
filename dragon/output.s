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
	pushq		$0

# Assignment Evaluation
	movq		$10, %r8
# assign gencode
	mov		%r8, -16(%rbp)

# evaluate 'write' arguments
	movl		-16(%rbp), %edx

# call 'write' using fprintf
	movq		stderr(%rip), %rax
	movl		$.LC1, %esi
	movq		%rax, %rdi
	movl		$0, %eax
	call	fprintf

# Function Footer
	movq		%rbp, %rsp
	popq		%rbp
	ret
main:
	pushq		%rbp
	movq		%rsp, %rbp
	pushq		$0
	pushq		%rbp

# call procedure 'foo'
	call	foo


# Assignment Evaluation
	movq		$6, %r8
# assign gencode
	mov		%r8, -8(%rbp)
	movl		$0, %eax
	leave
	ret

	.size	main, .-main


	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.4) 5.4.0 20160609"

	.section	.note.GNU-stack,"",@progbits
