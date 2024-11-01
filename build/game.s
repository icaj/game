	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 10, 15, 6	sdk_version 10, 15, 6
	.globl	_inicializar            ## -- Begin function inicializar
	.p2align	4, 0x90
_inicializar:                           ## @inicializar
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movq	_jogador@GOTPCREL(%rip), %rax
	movl	$40, (%rax)
	movl	$21, 4(%rax)
	movl	$0, -4(%rbp)
LBB0_1:                                 ## =>This Inner Loop Header: Depth=1
	cmpl	$5, -4(%rbp)
	jge	LBB0_4
## %bb.2:                               ##   in Loop: Header=BB0_1 Depth=1
	movq	_projeteis@GOTPCREL(%rip), %rax
	movslq	-4(%rbp), %rcx
	imulq	$12, %rcx, %rcx
	addq	%rcx, %rax
	movl	$0, 8(%rax)
## %bb.3:                               ##   in Loop: Header=BB0_1 Depth=1
	movl	-4(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -4(%rbp)
	jmp	LBB0_1
LBB0_4:
	movl	$0, -8(%rbp)
LBB0_5:                                 ## =>This Inner Loop Header: Depth=1
	cmpl	$19, -8(%rbp)
	jge	LBB0_8
## %bb.6:                               ##   in Loop: Header=BB0_5 Depth=1
	movq	_invasores@GOTPCREL(%rip), %rax
	movslq	-8(%rbp), %rcx
	imulq	$12, %rcx, %rcx
	movq	%rax, %rdx
	addq	%rcx, %rdx
	movl	$1, 8(%rdx)
	movl	-8(%rbp), %esi
	shll	$2, %esi
	addl	$4, %esi
	movslq	-8(%rbp), %rcx
	imulq	$12, %rcx, %rcx
	movq	%rax, %rdx
	addq	%rcx, %rdx
	movl	%esi, (%rdx)
	movslq	-8(%rbp), %rcx
	imulq	$12, %rcx, %rcx
	movq	%rax, %rdx
	addq	%rcx, %rdx
	movl	$4, 4(%rdx)
	movslq	-8(%rbp), %rcx
	imulq	$12, %rcx, %rcx
	movq	%rax, %rdx
	addq	%rcx, %rdx
	movl	(%rdx), %edi
	movslq	-8(%rbp), %rcx
	imulq	$12, %rcx, %rcx
	addq	%rcx, %rax
	movl	4(%rax), %esi
	callq	_screenGotoxy
	leaq	L_.str(%rip), %rdi
	movl	$42, %esi
	movb	$0, %al
	callq	_printf
## %bb.7:                               ##   in Loop: Header=BB0_5 Depth=1
	movl	-8(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -8(%rbp)
	jmp	LBB0_5
LBB0_8:
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_gameOver               ## -- Begin function gameOver
	.p2align	4, 0x90
_gameOver:                              ## @gameOver
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$48, %rsp
	movq	___stack_chk_guard@GOTPCREL(%rip), %rax
	movq	(%rax), %rax
	movq	%rax, -8(%rbp)
	movl	$4, -36(%rbp)
	movq	L___const.gameOver.szMens(%rip), %rax
	movq	%rax, -32(%rbp)
	movq	L___const.gameOver.szMens+8(%rip), %rax
	movq	%rax, -24(%rbp)
	movb	L___const.gameOver.szMens+16(%rip), %cl
	movb	%cl, -16(%rbp)
	movl	$1, _fimJogo(%rip)
	callq	_screenClear
	leaq	-32(%rbp), %rdi
	callq	_strlen
	movl	$80, %edx
	subq	%rax, %rdx
	shrq	$1, %rdx
                                        ## kill: def $edx killed $edx killed $rdx
	movl	%edx, %edi
	movl	$12, %esi
	callq	_screenGotoxy
	callq	_screenSetBlink
	xorl	%esi, %esi
	movl	$1, %edi
	callq	_screenSetColor
	leaq	-32(%rbp), %rsi
	leaq	L_.str.1(%rip), %rdi
	movb	$0, %al
	callq	_printf
	movl	%eax, -40(%rbp)         ## 4-byte Spill
	callq	_screenUpdate
LBB1_1:                                 ## =>This Inner Loop Header: Depth=1
	cmpl	$0, -36(%rbp)
	je	LBB1_5
## %bb.2:                               ##   in Loop: Header=BB1_1 Depth=1
	movb	$0, %al
	callq	_timerTimeOver
	cmpl	$1, %eax
	jne	LBB1_4
## %bb.3:                               ##   in Loop: Header=BB1_1 Depth=1
	movl	-36(%rbp), %eax
	addl	$-1, %eax
	movl	%eax, -36(%rbp)
LBB1_4:                                 ##   in Loop: Header=BB1_1 Depth=1
	jmp	LBB1_1
LBB1_5:
	movq	___stack_chk_guard@GOTPCREL(%rip), %rax
	movq	(%rax), %rax
	movq	-8(%rbp), %rcx
	cmpq	%rcx, %rax
	jne	LBB1_7
## %bb.6:
	addq	$48, %rsp
	popq	%rbp
	retq
LBB1_7:
	callq	___stack_chk_fail
	ud2
	.cfi_endproc
                                        ## -- End function
	.globl	_isGameOver             ## -- Begin function isGameOver
	.p2align	4, 0x90
_isGameOver:                            ## @isGameOver
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	movl	_fimJogo(%rip), %eax
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_desenhar               ## -- Begin function desenhar
	.p2align	4, 0x90
_desenhar:                              ## @desenhar
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	movl	$0, -4(%rbp)
LBB3_1:                                 ## =>This Inner Loop Header: Depth=1
	cmpl	$19, -4(%rbp)
	jge	LBB3_7
## %bb.2:                               ##   in Loop: Header=BB3_1 Depth=1
	movq	_invasores@GOTPCREL(%rip), %rax
	movslq	-4(%rbp), %rcx
	imulq	$12, %rcx, %rcx
	movq	%rax, %rdx
	addq	%rcx, %rdx
	movl	(%rdx), %edi
	movslq	-4(%rbp), %rcx
	imulq	$12, %rcx, %rcx
	addq	%rcx, %rax
	movl	4(%rax), %esi
	callq	_screenGotoxy
	movq	_invasores@GOTPCREL(%rip), %rax
	movslq	-4(%rbp), %rcx
	imulq	$12, %rcx, %rcx
	addq	%rcx, %rax
	cmpl	$0, 8(%rax)
	je	LBB3_4
## %bb.3:                               ##   in Loop: Header=BB3_1 Depth=1
	leaq	L_.str(%rip), %rdi
	movl	$42, %esi
	movb	$0, %al
	callq	_printf
	jmp	LBB3_5
LBB3_4:                                 ##   in Loop: Header=BB3_1 Depth=1
	leaq	L_.str.2(%rip), %rdi
	movb	$0, %al
	callq	_printf
LBB3_5:                                 ##   in Loop: Header=BB3_1 Depth=1
	jmp	LBB3_6
LBB3_6:                                 ##   in Loop: Header=BB3_1 Depth=1
	movl	-4(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -4(%rbp)
	jmp	LBB3_1
LBB3_7:
	movl	$0, -8(%rbp)
LBB3_8:                                 ## =>This Inner Loop Header: Depth=1
	cmpl	$5, -8(%rbp)
	jge	LBB3_17
## %bb.9:                               ##   in Loop: Header=BB3_8 Depth=1
	movq	_projeteis@GOTPCREL(%rip), %rax
	movslq	-8(%rbp), %rcx
	imulq	$12, %rcx, %rcx
	addq	%rcx, %rax
	cmpl	$0, 8(%rax)
	je	LBB3_15
## %bb.10:                              ##   in Loop: Header=BB3_8 Depth=1
	movq	_jogador@GOTPCREL(%rip), %rax
	movq	_projeteis@GOTPCREL(%rip), %rcx
	movslq	-8(%rbp), %rdx
	imulq	$12, %rdx, %rdx
	addq	%rdx, %rcx
	movl	4(%rcx), %esi
	movl	4(%rax), %edi
	subl	$1, %edi
	cmpl	%edi, %esi
	je	LBB3_12
## %bb.11:                              ##   in Loop: Header=BB3_8 Depth=1
	movq	_projeteis@GOTPCREL(%rip), %rax
	movslq	-8(%rbp), %rcx
	imulq	$12, %rcx, %rcx
	movq	%rax, %rdx
	addq	%rcx, %rdx
	movl	(%rdx), %edi
	movslq	-8(%rbp), %rcx
	imulq	$12, %rcx, %rcx
	addq	%rcx, %rax
	movl	4(%rax), %esi
	addl	$1, %esi
	callq	_screenGotoxy
	leaq	L_.str.2(%rip), %rdi
	movb	$0, %al
	callq	_printf
LBB3_12:                                ##   in Loop: Header=BB3_8 Depth=1
	movq	_projeteis@GOTPCREL(%rip), %rax
	movslq	-8(%rbp), %rcx
	imulq	$12, %rcx, %rcx
	addq	%rcx, %rax
	cmpl	$1, 4(%rax)
	jle	LBB3_14
## %bb.13:                              ##   in Loop: Header=BB3_8 Depth=1
	movq	_projeteis@GOTPCREL(%rip), %rax
	movslq	-8(%rbp), %rcx
	imulq	$12, %rcx, %rcx
	movq	%rax, %rdx
	addq	%rcx, %rdx
	movl	(%rdx), %edi
	movslq	-8(%rbp), %rcx
	imulq	$12, %rcx, %rcx
	addq	%rcx, %rax
	movl	4(%rax), %esi
	callq	_screenGotoxy
	leaq	L_.str.3(%rip), %rdi
	movb	$0, %al
	callq	_printf
LBB3_14:                                ##   in Loop: Header=BB3_8 Depth=1
	jmp	LBB3_15
LBB3_15:                                ##   in Loop: Header=BB3_8 Depth=1
	jmp	LBB3_16
LBB3_16:                                ##   in Loop: Header=BB3_8 Depth=1
	movl	-8(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -8(%rbp)
	jmp	LBB3_8
LBB3_17:
	movq	_jogador@GOTPCREL(%rip), %rax
	movl	(%rax), %edi
	movl	4(%rax), %esi
	callq	_screenGotoxy
	leaq	L_.str.4(%rip), %rdi
	movb	$0, %al
	callq	_printf
	movl	$64, %edi
	movl	$24, %esi
	movl	%eax, -12(%rbp)         ## 4-byte Spill
	callq	_screenGotoxy
	movl	_pontuacao(%rip), %esi
	leaq	L_.str.5(%rip), %rdi
	movb	$0, %al
	callq	_printf
	movl	$3, %edi
	movl	$24, %esi
	movl	%eax, -16(%rbp)         ## 4-byte Spill
	callq	_screenGotoxy
	leaq	L_.str.6(%rip), %rdi
	movb	$0, %al
	callq	_printf
	movl	%eax, -20(%rbp)         ## 4-byte Spill
	callq	_screenUpdate
	addq	$32, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_atualizar              ## -- Begin function atualizar
	.p2align	4, 0x90
_atualizar:                             ## @atualizar
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	cmpl	$0, _contador(%rip)
	jne	LBB4_10
## %bb.1:
	movl	$0, -4(%rbp)
LBB4_2:                                 ## =>This Inner Loop Header: Depth=1
	cmpl	$19, -4(%rbp)
	jge	LBB4_9
## %bb.3:                               ##   in Loop: Header=BB4_2 Depth=1
	movq	_invasores@GOTPCREL(%rip), %rax
	movslq	-4(%rbp), %rcx
	imulq	$12, %rcx, %rcx
	addq	%rcx, %rax
	cmpl	$0, 8(%rax)
	je	LBB4_7
## %bb.4:                               ##   in Loop: Header=BB4_2 Depth=1
	movq	_invasores@GOTPCREL(%rip), %rax
	movslq	-4(%rbp), %rcx
	imulq	$12, %rcx, %rcx
	movq	%rax, %rdx
	addq	%rcx, %rdx
	movl	(%rdx), %edi
	movslq	-4(%rbp), %rcx
	imulq	$12, %rcx, %rcx
	addq	%rcx, %rax
	movl	4(%rax), %esi
	callq	_screenGotoxy
	leaq	L_.str.2(%rip), %rdi
	movb	$0, %al
	callq	_printf
	movq	_jogador@GOTPCREL(%rip), %rcx
	movq	_invasores@GOTPCREL(%rip), %rdx
	movslq	-4(%rbp), %rdi
	imulq	$12, %rdi, %rdi
	movq	%rdx, %r8
	addq	%rdi, %r8
	movl	4(%r8), %esi
	addl	$1, %esi
	movl	%esi, 4(%r8)
	movslq	-4(%rbp), %rdi
	imulq	$12, %rdi, %rdi
	addq	%rdi, %rdx
	movl	4(%rdx), %esi
	cmpl	4(%rcx), %esi
	jl	LBB4_6
## %bb.5:                               ##   in Loop: Header=BB4_2 Depth=1
	callq	_gameOver
LBB4_6:                                 ##   in Loop: Header=BB4_2 Depth=1
	jmp	LBB4_7
LBB4_7:                                 ##   in Loop: Header=BB4_2 Depth=1
	jmp	LBB4_8
LBB4_8:                                 ##   in Loop: Header=BB4_2 Depth=1
	movl	-4(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -4(%rbp)
	jmp	LBB4_2
LBB4_9:
	jmp	LBB4_10
LBB4_10:
	movl	$0, -8(%rbp)
LBB4_11:                                ## =>This Inner Loop Header: Depth=1
	cmpl	$5, -8(%rbp)
	jge	LBB4_18
## %bb.12:                              ##   in Loop: Header=BB4_11 Depth=1
	movq	_projeteis@GOTPCREL(%rip), %rax
	movslq	-8(%rbp), %rcx
	imulq	$12, %rcx, %rcx
	addq	%rcx, %rax
	cmpl	$0, 8(%rax)
	je	LBB4_16
## %bb.13:                              ##   in Loop: Header=BB4_11 Depth=1
	movq	_projeteis@GOTPCREL(%rip), %rax
	movslq	-8(%rbp), %rcx
	imulq	$12, %rcx, %rcx
	movq	%rax, %rdx
	addq	%rcx, %rdx
	movl	4(%rdx), %esi
	subl	$1, %esi
	movl	%esi, 4(%rdx)
	movslq	-8(%rbp), %rcx
	imulq	$12, %rcx, %rcx
	addq	%rcx, %rax
	cmpl	$1, 4(%rax)
	jge	LBB4_15
## %bb.14:                              ##   in Loop: Header=BB4_11 Depth=1
	movq	_projeteis@GOTPCREL(%rip), %rax
	movslq	-8(%rbp), %rcx
	imulq	$12, %rcx, %rcx
	addq	%rcx, %rax
	movl	$0, 8(%rax)
LBB4_15:                                ##   in Loop: Header=BB4_11 Depth=1
	jmp	LBB4_16
LBB4_16:                                ##   in Loop: Header=BB4_11 Depth=1
	jmp	LBB4_17
LBB4_17:                                ##   in Loop: Header=BB4_11 Depth=1
	movl	-8(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -8(%rbp)
	jmp	LBB4_11
LBB4_18:
	movl	$0, -12(%rbp)
LBB4_19:                                ## =>This Loop Header: Depth=1
                                        ##     Child Loop BB4_22 Depth 2
	cmpl	$5, -12(%rbp)
	jge	LBB4_31
## %bb.20:                              ##   in Loop: Header=BB4_19 Depth=1
	movq	_projeteis@GOTPCREL(%rip), %rax
	movslq	-12(%rbp), %rcx
	imulq	$12, %rcx, %rcx
	addq	%rcx, %rax
	cmpl	$0, 8(%rax)
	je	LBB4_29
## %bb.21:                              ##   in Loop: Header=BB4_19 Depth=1
	movl	$0, -16(%rbp)
LBB4_22:                                ##   Parent Loop BB4_19 Depth=1
                                        ## =>  This Inner Loop Header: Depth=2
	cmpl	$19, -16(%rbp)
	jge	LBB4_28
## %bb.23:                              ##   in Loop: Header=BB4_22 Depth=2
	movq	_projeteis@GOTPCREL(%rip), %rax
	movq	_invasores@GOTPCREL(%rip), %rcx
	movslq	-16(%rbp), %rdx
	imulq	$12, %rdx, %rdx
	addq	%rdx, %rcx
	movl	(%rcx), %esi
	movslq	-12(%rbp), %rcx
	imulq	$12, %rcx, %rcx
	addq	%rcx, %rax
	cmpl	(%rax), %esi
	jne	LBB4_26
## %bb.24:                              ##   in Loop: Header=BB4_22 Depth=2
	movq	_projeteis@GOTPCREL(%rip), %rax
	movq	_invasores@GOTPCREL(%rip), %rcx
	movslq	-16(%rbp), %rdx
	imulq	$12, %rdx, %rdx
	addq	%rdx, %rcx
	movl	4(%rcx), %esi
	movslq	-12(%rbp), %rcx
	imulq	$12, %rcx, %rcx
	addq	%rcx, %rax
	cmpl	4(%rax), %esi
	jne	LBB4_26
## %bb.25:                              ##   in Loop: Header=BB4_22 Depth=2
	movq	_invasores@GOTPCREL(%rip), %rax
	movq	_projeteis@GOTPCREL(%rip), %rcx
	movslq	-16(%rbp), %rdx
	imulq	$12, %rdx, %rdx
	movq	%rax, %rsi
	addq	%rdx, %rsi
	movl	$0, 8(%rsi)
	movslq	-12(%rbp), %rdx
	imulq	$12, %rdx, %rdx
	addq	%rdx, %rcx
	movl	$0, 8(%rcx)
	movl	_pontuacao(%rip), %edi
	addl	$10, %edi
	movl	%edi, _pontuacao(%rip)
	movslq	-16(%rbp), %rcx
	imulq	$12, %rcx, %rcx
	movq	%rax, %rdx
	addq	%rcx, %rdx
	movl	(%rdx), %edi
	movslq	-16(%rbp), %rcx
	imulq	$12, %rcx, %rcx
	addq	%rcx, %rax
	movl	4(%rax), %esi
	callq	_screenGotoxy
	leaq	L_.str.2(%rip), %rdi
	movb	$0, %al
	callq	_printf
	movq	_invasores@GOTPCREL(%rip), %rcx
	movslq	-16(%rbp), %rdx
	imulq	$12, %rdx, %rdx
	movq	%rcx, %rdi
	addq	%rdx, %rdi
	movl	(%rdi), %edi
	movslq	-16(%rbp), %rdx
	imulq	$12, %rdx, %rdx
	addq	%rdx, %rcx
	movl	4(%rcx), %esi
	addl	$1, %esi
	movl	%eax, -20(%rbp)         ## 4-byte Spill
	callq	_screenGotoxy
	leaq	L_.str.2(%rip), %rdi
	movb	$0, %al
	callq	_printf
LBB4_26:                                ##   in Loop: Header=BB4_22 Depth=2
	jmp	LBB4_27
LBB4_27:                                ##   in Loop: Header=BB4_22 Depth=2
	movl	-16(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -16(%rbp)
	jmp	LBB4_22
LBB4_28:                                ##   in Loop: Header=BB4_19 Depth=1
	jmp	LBB4_29
LBB4_29:                                ##   in Loop: Header=BB4_19 Depth=1
	jmp	LBB4_30
LBB4_30:                                ##   in Loop: Header=BB4_19 Depth=1
	movl	-12(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -12(%rbp)
	jmp	LBB4_19
LBB4_31:
	callq	_screenUpdate
	addq	$32, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_controle               ## -- Begin function controle
	.p2align	4, 0x90
_controle:                              ## @controle
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movl	$0, -4(%rbp)
	movb	$0, %al
	callq	_keyhit
	cmpl	$0, %eax
	je	LBB5_20
## %bb.1:
	movb	$0, %al
	callq	_readch
	movl	%eax, -4(%rbp)
	cmpl	$97, -4(%rbp)
	je	LBB5_3
## %bb.2:
	cmpl	$100, -4(%rbp)
	jne	LBB5_11
LBB5_3:
	movq	_jogador@GOTPCREL(%rip), %rax
	movl	(%rax), %edi
	movl	4(%rax), %esi
	callq	_screenGotoxy
	leaq	L_.str.2(%rip), %rdi
	movb	$0, %al
	callq	_printf
	cmpl	$97, -4(%rbp)
	jne	LBB5_6
## %bb.4:
	movq	_jogador@GOTPCREL(%rip), %rax
	cmpl	$0, (%rax)
	jle	LBB5_6
## %bb.5:
	movq	_jogador@GOTPCREL(%rip), %rax
	movl	(%rax), %ecx
	subl	$1, %ecx
	movl	%ecx, (%rax)
	jmp	LBB5_10
LBB5_6:
	cmpl	$100, -4(%rbp)
	jne	LBB5_9
## %bb.7:
	movq	_jogador@GOTPCREL(%rip), %rax
	cmpl	$79, (%rax)
	jge	LBB5_9
## %bb.8:
	movq	_jogador@GOTPCREL(%rip), %rax
	movl	(%rax), %ecx
	addl	$1, %ecx
	movl	%ecx, (%rax)
LBB5_9:
	jmp	LBB5_10
LBB5_10:
	jmp	LBB5_11
LBB5_11:
	cmpl	$32, -4(%rbp)
	jne	LBB5_19
## %bb.12:
	movl	$0, -8(%rbp)
LBB5_13:                                ## =>This Inner Loop Header: Depth=1
	cmpl	$5, -8(%rbp)
	jge	LBB5_18
## %bb.14:                              ##   in Loop: Header=BB5_13 Depth=1
	movq	_projeteis@GOTPCREL(%rip), %rax
	movslq	-8(%rbp), %rcx
	imulq	$12, %rcx, %rcx
	addq	%rcx, %rax
	cmpl	$0, 8(%rax)
	jne	LBB5_16
## %bb.15:
	movq	_projeteis@GOTPCREL(%rip), %rax
	movq	_jogador@GOTPCREL(%rip), %rcx
	movl	(%rcx), %edx
	movslq	-8(%rbp), %rsi
	imulq	$12, %rsi, %rsi
	movq	%rax, %rdi
	addq	%rsi, %rdi
	movl	%edx, (%rdi)
	movl	4(%rcx), %edx
	subl	$1, %edx
	movslq	-8(%rbp), %rcx
	imulq	$12, %rcx, %rcx
	movq	%rax, %rsi
	addq	%rcx, %rsi
	movl	%edx, 4(%rsi)
	movslq	-8(%rbp), %rcx
	imulq	$12, %rcx, %rcx
	addq	%rcx, %rax
	movl	$1, 8(%rax)
	jmp	LBB5_18
LBB5_16:                                ##   in Loop: Header=BB5_13 Depth=1
	jmp	LBB5_17
LBB5_17:                                ##   in Loop: Header=BB5_13 Depth=1
	movl	-8(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -8(%rbp)
	jmp	LBB5_13
LBB5_18:
	leaq	L_.str.7(%rip), %rdi
	movb	$0, %al
	callq	_printf
LBB5_19:
	jmp	LBB5_20
LBB5_20:
	callq	_screenUpdate
	movl	-4(%rbp), %eax
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_loop_jogo              ## -- Begin function loop_jogo
	.p2align	4, 0x90
_loop_jogo:                             ## @loop_jogo
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movl	$0, -4(%rbp)
	movl	$1, %edi
	callq	_screenInit
	movb	$0, %al
	callq	_keyboardInit
	movl	$50, %edi
	callq	_timerInit
LBB6_1:                                 ## =>This Inner Loop Header: Depth=1
	cmpl	$102, -4(%rbp)
	je	LBB6_9
## %bb.2:                               ##   in Loop: Header=BB6_1 Depth=1
	callq	_isGameOver
	cmpl	$0, %eax
	je	LBB6_4
## %bb.3:
	jmp	LBB6_9
LBB6_4:                                 ##   in Loop: Header=BB6_1 Depth=1
	movb	$0, %al
	callq	_timerTimeOver
	cmpl	$1, %eax
	jne	LBB6_8
## %bb.5:                               ##   in Loop: Header=BB6_1 Depth=1
	callq	_desenhar
	callq	_atualizar
	callq	_controle
	movl	%eax, -4(%rbp)
	movl	_contador(%rip), %eax
	addl	$-1, %eax
	movl	%eax, _contador(%rip)
	cmpl	$0, _contador(%rip)
	jge	LBB6_7
## %bb.6:                               ##   in Loop: Header=BB6_1 Depth=1
	movl	$60, _contador(%rip)
LBB6_7:                                 ##   in Loop: Header=BB6_1 Depth=1
	jmp	LBB6_8
LBB6_8:                                 ##   in Loop: Header=BB6_1 Depth=1
	jmp	LBB6_1
LBB6_9:
	movb	$0, %al
	callq	_keyboardDestroy
	movb	$0, %al
	callq	_screenDestroy
	movb	$0, %al
	callq	_timerDestroy
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_main                   ## -- Begin function main
	.p2align	4, 0x90
_main:                                  ## @main
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movl	$0, -4(%rbp)
	callq	_inicializar
	callq	_loop_jogo
	xorl	%eax, %eax
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.p2align	4, 0x90         ## -- Begin function screenClear
_screenClear:                           ## @screenClear
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	callq	_screenHomeCursor
	leaq	L_.str.8(%rip), %rdi
	leaq	L_.str.9(%rip), %rsi
	leaq	L_.str.10(%rip), %rdx
	movb	$0, %al
	callq	_printf
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.p2align	4, 0x90         ## -- Begin function screenHomeCursor
_screenHomeCursor:                      ## @screenHomeCursor
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	leaq	L_.str.8(%rip), %rdi
	leaq	L_.str.9(%rip), %rsi
	leaq	L_.str.11(%rip), %rdx
	movb	$0, %al
	callq	_printf
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.p2align	4, 0x90         ## -- Begin function screenSetBlink
_screenSetBlink:                        ## @screenSetBlink
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	leaq	L_.str.8(%rip), %rdi
	leaq	L_.str.9(%rip), %rsi
	leaq	L_.str.12(%rip), %rdx
	movb	$0, %al
	callq	_printf
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.p2align	4, 0x90         ## -- Begin function screenUpdate
_screenUpdate:                          ## @screenUpdate
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	movq	___stdoutp@GOTPCREL(%rip), %rax
	movq	(%rax), %rdi
	callq	_fflush
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_pontuacao              ## @pontuacao
.zerofill __DATA,__common,_pontuacao,4,2
	.section	__DATA,__data
	.globl	_contador               ## @contador
	.p2align	2
_contador:
	.long	60                      ## 0x3c

	.globl	_fimJogo                ## @fimJogo
.zerofill __DATA,__common,_fimJogo,4,2
	.comm	_jogador,8,2            ## @jogador
	.comm	_projeteis,60,4         ## @projeteis
	.comm	_invasores,228,4        ## @invasores
	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"%c"

	.p2align	4               ## @__const.gameOver.szMens
L___const.gameOver.szMens:
	.asciz	"G A M E  O V E R"

L_.str.1:                               ## @.str.1
	.asciz	"%s"

L_.str.2:                               ## @.str.2
	.asciz	" "

L_.str.3:                               ## @.str.3
	.asciz	"|"

L_.str.4:                               ## @.str.4
	.asciz	"A"

L_.str.5:                               ## @.str.5
	.asciz	"Pontua\303\247\303\243o: %3d"

L_.str.6:                               ## @.str.6
	.asciz	"Direita: A - Esquerda: D - Tiro: espa\303\247o"

L_.str.7:                               ## @.str.7
	.asciz	"\007"

L_.str.8:                               ## @.str.8
	.asciz	"%s%s"

L_.str.9:                               ## @.str.9
	.asciz	"\033"

L_.str.10:                              ## @.str.10
	.asciz	"[2J"

L_.str.11:                              ## @.str.11
	.asciz	"[f"

L_.str.12:                              ## @.str.12
	.asciz	"[5m"

.subsections_via_symbols
