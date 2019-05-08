Ben Mack

Haiku:
Rex is my dragon,
He grew all semester long,
He breathes fire at last.


Lexical Analysis
Line Number - Working
Two style of comments - Working
Syntax Analysis
Unlimited Nesting of subprograms - Working
Array access on both sides of assignment - working
For loops - Working
Symbol Table
Memory Leak handler - Working
Syntax Tree
Working on all check list files
Error reporting - Working with excellent messages
Code Generation
I/O - Working
Simple expression - Working
Statements - Working
Nonlocal Names - Working
Recursion - Working
Complex Expressions - Working
Floating point - Not Working
Arrays - Not Working
For Loops can be a little finicky as seen during the demo

Other Non working aspects:
Dangling else - I was unable to get dangling else to work although the code is in place for If-then statements in gencode. So once I get it figured out it’ll work.  

Install: make
Run: ./mypc < <Name of pascal file> ; gcc output.s ; ./a.out

Each aspect of the compiler has a debug flag that can be set or unset to print out the different components. 
Ex: The syntax Tree
By default the syntax tree and the hash table but have debug on but the Lexical Analyzer, nodes, and the Tree itself all have debugs that can be set.  

Design Document

Register usage for the 64 Bit AT&T framework

rax = return value
rbx = static parent pointer
rsp = stack pointer
rbp = base pointer
rip = instruction pointer

rdi = reserved for io use, temp regs
rsi = reserved for io use, temp regs
rdx = division


r8  = temp var (top of stack)
	r9  = temp var
	r10 = temp var	
	r11 = temp var
	r12 = temp var
	r13 = temp var
	r14 = temp var
r15 = temp var (bottom of stack) 

	2. Stack Frame Contents:   

	low memory addresses

	.
	.
	-------------------
	|     rsp          | 
	-------------------
	|     local3      |
	-------------------
	|     local2      |
	-------------------
	|     local1      |
	-------------------
	| parent  pointer |  rbp - 8
	-------------------
	|     old_rbp     | 
	-------------------
	|     return_val  |	
	-------------------
	|     param3      |
	-------------------
	|     param2      |
	-------------------
	|     param1      |
	-------------------
	.
	.
	.
	high memory addresses

	Extra Free Will:
	I believe my Semantic checking has great error messages that make it easy to fix the type errors
	I used 64 bit architecture instead of 32 allowing for very complex expressions
	I also added Do-While loops that look like this:

	1 program main(input, output);
	2 var x : integer;
	3 procedure boo(y : integer);
	4 begin
	5    write(x);
	6    x := x + 1
	7 end;
	8  begin
	9       x := 11;
	10       do
	11          boo(x)
12       while (x < 10)
	13 end.
	14
	This allows for doing the contents of the while loop before checking the condition.  Meaning the content after the do will always run at least once regardless of the condition.  The above program will print 11 (the value of x) once.  If x is lowered it will print x multiple times until the condition is met. 

	Thanks for a great 4 years Tino. Till next time.




