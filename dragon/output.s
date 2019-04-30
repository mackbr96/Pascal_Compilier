	.file	"output.s"
	.intel_syntax noprefix

	.section	.rodata
.LC0: # reading
	.string "%lld"
.LC1: # writing
	.string "%lld\n"
	.text


	.globl	main
	.type	main, @function
main:
	push	rbp
	mov		rbp, rsp
	push	0
	push	rbp

# Assignment Evaluation
	mov		r8, 2
# Printing operation
	imul		r8, 6
# assign gencode
	mov		QWORD PTR [rbp - 0], r8

# Assignment Evaluation
	mov		r8, QWORD PTR [rbp - 0]
# Printing operation
	add		r8, 8
# assign gencode
	mov		QWORD PTR [rbp - 16], r8

# evaluate 'write' arguments
	mov		r8, QWORD PTR [rbp - 16]

# call 'write' using fprintf
	mov		rdx, r8
	mov		rax, QWORD PTR stderr[rip]
	mov		esi, OFFSET FLAT:.LC1
	mov		rdi, rax
	mov		eax, 0
	call	fprintf

	mov		eax, 0
	leave
	ret

	.size	main, .-main


	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.4) 5.4.0 20160609"

	.section	.note.GNU-stack,"",@progbits
