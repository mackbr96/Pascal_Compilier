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
main:
	pushq		%rbp
	movq		%rsp, %rbp
	pushq		$0
	pushq		%rbp

# Assignment Evaluation
	movq		$6, %r8
# assign gencode
	mov		%r8, -16(%rbp)
# Start IF
	movq		-16(%rbp), %r8
# Printing operation
	cmpq		$8, %r8
	jge		.L2

# Assignment Evaluation
	movq		$1, %r8
# assign gencode
	mov		%r8, -16(%rbp)
	jmp		.L4
.L2:

# Assignment Evaluation
	movq		$2, %r8
# assign gencode
	mov		%r8, -16(%rbp)
# END IF
.L4:

# evaluate 'write' arguments
	movl		-16(%rbp), %edx

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
