	.file	"free_tree_iter.c"
	.text
	.globl	insert_root
	.def	insert_root;	.scl	2;	.type	32;	.endef
	.seh_proc	insert_root
insert_root:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movl	%edx, 24(%rbp)
	movq	16(%rbp), %rax
	movq	(%rax), %rax
	testq	%rax, %rax
	jne	.L2
	movl	$24, %edx
	movl	$1, %ecx
	call	calloc
	movq	%rax, %rdx
	movq	16(%rbp), %rax
	movq	%rdx, (%rax)
	movq	16(%rbp), %rax
	movq	(%rax), %rax
	movl	24(%rbp), %edx
	movl	%edx, 16(%rax)
	jmp	.L1
.L2:
	movq	16(%rbp), %rax
	movq	(%rax), %rax
	movl	16(%rax), %eax
	cmpl	%eax, 24(%rbp)
	jge	.L4
	movq	16(%rbp), %rax
	movq	(%rax), %rax
	movq	%rax, %rcx
	movl	24(%rbp), %eax
	movl	%eax, %edx
	call	insert_root
	jmp	.L1
.L4:
	movq	16(%rbp), %rax
	movq	(%rax), %rax
	leaq	8(%rax), %rcx
	movl	24(%rbp), %eax
	movl	%eax, %edx
	call	insert_root
	nop
.L1:
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section .rdata,"dr"
.LC0:
	.ascii "%p:%d \0"
	.text
	.globl	f
	.def	f;	.scl	2;	.type	32;	.endef
	.seh_proc	f
f:
	pushq	%rbp
	.seh_pushreg	%rbp
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$72, %rsp
	.seh_stackalloc	72
	leaq	128(%rsp), %rbp
	.seh_setframe	%rbp, 128
	.seh_endprologue
	movq	%rcx, -32(%rbp)
	movl	%edx, -24(%rbp)
	movq	%rsp, %rax
	movq	%rax, %rbx
	movl	-24(%rbp), %eax
	movslq	%eax, %rdx
	subq	$1, %rdx
	movq	%rdx, -88(%rbp)
	movslq	%eax, %rdx
	movq	%rdx, %r10
	movl	$0, %r11d
	movslq	%eax, %rdx
	movq	%rdx, %r8
	movl	$0, %r9d
	cltq
	salq	$3, %rax
	addq	$7, %rax
	addq	$15, %rax
	shrq	$4, %rax
	salq	$4, %rax
	call	___chkstk_ms
	subq	%rax, %rsp
	leaq	32(%rsp), %rax
	addq	$7, %rax
	shrq	$3, %rax
	salq	$3, %rax
	movq	%rax, -96(%rbp)
	movq	-96(%rbp), %rax
	movq	-32(%rbp), %rdx
	movq	%rdx, (%rax)
	movq	-96(%rbp), %rax
	movq	%rax, -80(%rbp)
	movq	-96(%rbp), %rax
	movq	%rax, -72(%rbp)
	jmp	.L6
.L9:
	movq	-80(%rbp), %rax
	movq	(%rax), %rax
	testq	%rax, %rax
	je	.L7
	movq	-80(%rbp), %rax
	movq	(%rax), %rax
	movq	(%rax), %rax
	testq	%rax, %rax
	je	.L8
	movq	-80(%rbp), %rax
	movq	(%rax), %rax
	addq	$8, -72(%rbp)
	movq	(%rax), %rdx
	movq	-72(%rbp), %rax
	movq	%rdx, (%rax)
.L8:
	movq	-80(%rbp), %rax
	movq	(%rax), %rax
	movq	8(%rax), %rax
	testq	%rax, %rax
	je	.L7
	movq	-80(%rbp), %rax
	movq	(%rax), %rax
	addq	$8, -72(%rbp)
	movq	8(%rax), %rdx
	movq	-72(%rbp), %rax
	movq	%rdx, (%rax)
.L7:
	movq	-80(%rbp), %rax
	movq	(%rax), %rax
	movl	16(%rax), %edx
	movq	-80(%rbp), %rax
	movq	(%rax), %rax
	movl	%edx, %r8d
	movq	%rax, %rdx
	leaq	.LC0(%rip), %rcx
	call	printf
	movq	-80(%rbp), %rax
	movq	(%rax), %rax
	movq	%rax, %rcx
	call	free
	addq	$8, -80(%rbp)
.L6:
	movq	-80(%rbp), %rax
	cmpq	-72(%rbp), %rax
	jbe	.L9
	movl	$10, %ecx
	call	putchar
	movq	%rbx, %rsp
	nop
	leaq	-56(%rbp), %rsp
	popq	%rbx
	popq	%rbp
	ret
	.seh_endproc
	.def	__main;	.scl	2;	.type	32;	.endef
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
	pushq	%rbp
	.seh_pushreg	%rbp
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$56, %rsp
	.seh_stackalloc	56
	leaq	128(%rsp), %rbp
	.seh_setframe	%rbp, 128
	.seh_endprologue
	movl	%ecx, -48(%rbp)
	movq	%rdx, -40(%rbp)
	call	__main
	movl	$24, %edx
	movl	$1, %ecx
	call	calloc
	movq	%rax, -96(%rbp)
	movq	-40(%rbp), %rax
	addq	$8, %rax
	movq	(%rax), %rax
	movq	-96(%rbp), %rbx
	movl	$10, %r8d
	movl	$0, %edx
	movq	%rax, %rcx
	call	strtol
	movl	%eax, 16(%rbx)
	movq	-40(%rbp), %rax
	addq	$8, %rax
	movq	%rax, -88(%rbp)
	jmp	.L11
.L12:
	movq	-88(%rbp), %rax
	movq	(%rax), %rax
	movl	$10, %r8d
	movl	$0, %edx
	movq	%rax, %rcx
	call	strtol
	movl	%eax, %edx
	leaq	-96(%rbp), %rax
	movq	%rax, %rcx
	call	insert_root
.L11:
	addq	$8, -88(%rbp)
	movq	-88(%rbp), %rax
	movq	(%rax), %rax
	testq	%rax, %rax
	jne	.L12
	movl	-48(%rbp), %eax
	leal	-1(%rax), %edx
	movq	-96(%rbp), %rax
	movq	%rax, %rcx
	call	f
	movl	$0, %eax
	addq	$56, %rsp
	popq	%rbx
	popq	%rbp
	ret
	.seh_endproc
	.ident	"GCC: (GNU) 7.4.0"
	.def	calloc;	.scl	2;	.type	32;	.endef
	.def	printf;	.scl	2;	.type	32;	.endef
	.def	free;	.scl	2;	.type	32;	.endef
	.def	putchar;	.scl	2;	.type	32;	.endef
	.def	strtol;	.scl	2;	.type	32;	.endef
