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
	movq		16(%rbp), %r8
# ARG NUM 1
	movq		%r8, -24(%rbp)
	movq		%rbx, -8(%rbp)

# evaluate 'write' arguments
#Looking for nonlocal var
	movq -8(%rbp), %rbx
	movq		-8(%rbx), %rbx
# end nonlocal variable
# ARG NUM 6
	movl		-40(%rbx), %edx

# call 'write' using fprintf
	movq		stderr(%rip), %rax
	movl		$.LC1, %esi
	movq		%rax, %rdi
	movl		$0, %eax
	call	fprintf


# Assignment Evaluation
#Looking for nonlocal var
	movq -8(%rbp), %rbx
	movq		-8(%rbx), %rbx
# end nonlocal variable
# ARG NUM 6
	movq		-40(%rbx), %r8
# Printing operation
# ARG NUM 1
	addq		-24(%rbp), %r8
# assign gencode
#Looking for nonlocal var
	movq -8(%rbp), %rbx
	movq		-8(%rbx), %rbx
# end nonlocal variable
# ARG NUM 6
	mov		%r8, -40(%rbx)
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
	movq		16(%rbp), %r8
# ARG NUM 4
	movq		%r8, -24(%rbp)
	movq		24(%rbp), %r8
# ARG NUM 4
	movq		%r8, -32(%rbp)
	movq		%rbx, -8(%rbp)

# evaluate 'write' arguments
# ARG NUM 4
	movl		-24(%rbp), %edx

# call 'write' using fprintf
	movq		stderr(%rip), %rax
	movl		$.LC1, %esi
	movq		%rax, %rdi
	movl		$0, %eax
	call	fprintf

# Evaluating Procedure Argsuments
# ARG NUM 4
	movq		-24(%rbp), %r8
	pushq		%r8
	movq		%rbp, %rbx

# call procedure 'foo'
	call	foo

# Function Footer
	movq		-8(%rbp), %rax
	movq		%rbp, %rsp
	popq		%rbp
	ret
# FUNCTION HEADER
gloo:
	pushq		%rbp
	movq		%rsp, %rbp
	subq		$32, %rsp
	movq		16(%rbp), %r8
# ARG NUM 1
	movq		%r8, -24(%rbp)
	movq		%rbx, -8(%rbp)

# Assignment Evaluation
#Looking for nonlocal var
	movq -8(%rbp), %rbx
# end nonlocal variable
# ARG NUM 7
	movq		-40(%rbx), %r8
# Printing operation
	addq		$10, %r8

# return statement
	movq		%r8, -8(%rbp)
# assign gencode
	mov		%r8, %rax
# Function Footer
	movq		-8(%rbp), %rax
	movq		%rbp, %rsp
	popq		%rbp
	ret
main:
	pushq		%rbp
	movq		%rsp, %rbp
	subq		$72, %rsp
	pushq		$0
	pushq		%rbp
	movq		%rbp, %rbx

# Assignment Evaluation
	movq		$10, %r8
# assign gencode
# ARG NUM 7
	mov		%r8, -40(%rbp)
# Evaluating Procedure Argsuments
	movq		$2, %r8
	pushq		%r8
	movq		$80, %r8
	pushq		%r8
	movq		%rbp, %rbx

# call procedure 'boo'
	call	boo


# evaluate 'write' arguments
# ARG NUM 7
	movl		-40(%rbp), %edx

# call 'write' using fprintf
	movq		stderr(%rip), %rax
	movl		$.LC1, %esi
	movq		%rax, %rdi
	movl		$0, %eax
	call	fprintf

