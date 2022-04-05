	.file	"benchmark.c"
# GNU C (GCC) version 4.8.5 20150623 (Red Hat 4.8.5-44) (x86_64-redhat-linux)
#	compiled by GNU C version 4.8.5 20150623 (Red Hat 4.8.5-44), GMP version 6.0.0, MPFR version 3.1.1, MPC version 1.0.1
# GGC heuristics: --param ggc-min-expand=100 --param ggc-min-heapsize=131072
# options passed:  benchmark.c -mtune=generic -march=x86-64 -fverbose-asm
# options enabled:  -faggressive-loop-optimizations
# -fasynchronous-unwind-tables -fauto-inc-dec -fbranch-count-reg -fcommon
# -fdelete-null-pointer-checks -fdwarf2-cfi-asm -fearly-inlining
# -feliminate-unused-debug-types -ffunction-cse -fgcse-lm -fgnu-runtime
# -fgnu-unique -fident -finline-atomics -fira-hoist-pressure
# -fira-share-save-slots -fira-share-spill-slots -fivopts
# -fkeep-static-consts -fleading-underscore -fmath-errno
# -fmerge-debug-strings -fmove-loop-invariants -fpeephole
# -fprefetch-loop-arrays -freg-struct-return
# -fsched-critical-path-heuristic -fsched-dep-count-heuristic
# -fsched-group-heuristic -fsched-interblock -fsched-last-insn-heuristic
# -fsched-rank-heuristic -fsched-spec -fsched-spec-insn-heuristic
# -fsched-stalled-insns-dep -fshow-column -fsigned-zeros
# -fsplit-ivs-in-unroller -fstrict-volatile-bitfields -fsync-libcalls
# -ftrapping-math -ftree-coalesce-vars -ftree-cselim -ftree-forwprop
# -ftree-loop-if-convert -ftree-loop-im -ftree-loop-ivcanon
# -ftree-loop-optimize -ftree-parallelize-loops= -ftree-phiprop -ftree-pta
# -ftree-reassoc -ftree-scev-cprop -ftree-slp-vectorize
# -ftree-vect-loop-version -funit-at-a-time -funwind-tables -fverbose-asm
# -fzero-initialized-in-bss -m128bit-long-double -m64 -m80387
# -maccumulate-outgoing-args -malign-stringops -mfancy-math-387
# -mfp-ret-in-387 -mfxsr -mglibc -mieee-fp -mlong-double-80 -mmmx -mno-sse4
# -mpush-args -mred-zone -msse -msse2 -mtls-direct-seg-refs

	.section	.rodata
.LC2:
	.string	"Execution time: %11.8f s\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushq	%rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp	#,
	.cfi_def_cfa_register 6
	subq	$2400048, %rsp	#,
	movl	$0, -4(%rbp)	#, i
	jmp	.L2	#
.L3:
	movl	-4(%rbp), %eax	# i, tmp66
	movslq	%eax, %rdx	# tmp66, tmp65
	movabsq	$4631811479262199808, %rax	#, tmp67           # representation of 47 in bits, explained by int and printed out as decimal value
	movq	%rax, -800032(%rbp,%rdx,8)	# tmp67, a
	movl	-4(%rbp), %eax	# i, tmp69
	movslq	%eax, %rdx	# tmp69, tmp68
	movabsq	$4614256447914709615, %rax	#, tmp70           # 3.1415
	movq	%rax, -1600032(%rbp,%rdx,8)	# tmp70, b
	addl	$1, -4(%rbp)	#, i
.L2:
	cmpl	$99999, -4(%rbp)	#, i
	jle	.L3	#,
	movl	$0, %eax	#,
	call	mysecond	#
	movsd	%xmm0, -2400040(%rbp)	#, %sfp
	movq	-2400040(%rbp), %rax	# %sfp, tmp71
	movq	%rax, -16(%rbp)	# tmp71, t1
	movl	$0, -4(%rbp)	#, i
	jmp	.L4	#
.L5:
	movl	-4(%rbp), %eax	# i, tmp73
	cltq
	movsd	-800032(%rbp,%rax,8), %xmm1	# a, D.2283
	movl	-4(%rbp), %eax	# i, tmp75
	cltq
	movsd	-1600032(%rbp,%rax,8), %xmm0	# b, D.2283
	mulsd	%xmm1, %xmm0	# D.2283, D.2283
	movl	-4(%rbp), %eax	# i, tmp77
	cltq
	movsd	%xmm0, -2400032(%rbp,%rax,8)	# D.2283, c
	addl	$1, -4(%rbp)	#, i
.L4:
	cmpl	$99999, -4(%rbp)	#, i
	jle	.L5	#,
	movl	$0, %eax	#,
	call	mysecond	#
	movsd	%xmm0, -2400040(%rbp)	#, %sfp
	movq	-2400040(%rbp), %rax	# %sfp, tmp78
	movq	%rax, -24(%rbp)	# tmp78, t2
	movsd	-24(%rbp), %xmm0	# t2, tmp79
	subsd	-16(%rbp), %xmm0	# t1, D.2283
	movl	$.LC2, %edi	#,
	movl	$1, %eax	#,
	call	printf	#
	movl	$0, %eax	#, D.2284
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.globl	mysecond
	.type	mysecond, @function
mysecond:
.LFB1:
	.cfi_startproc
	pushq	%rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp	#,
	.cfi_def_cfa_register 6
	subq	$64, %rsp	#,
	leaq	-48(%rbp), %rdx	#, tmp66
	leaq	-32(%rbp), %rax	#, tmp67
	movq	%rdx, %rsi	# tmp66,
	movq	%rax, %rdi	# tmp67,
	call	gettimeofday	#
	movl	%eax, -4(%rbp)	# tmp68, i
	movq	-32(%rbp), %rax	# tp.tv_sec, D.2287
	cvtsi2sdq	%rax, %xmm1	# D.2287, D.2288
	movq	-24(%rbp), %rax	# tp.tv_usec, D.2287
	cvtsi2sdq	%rax, %xmm0	# D.2287, D.2288
	movsd	.LC3(%rip), %xmm2	#, tmp69
	mulsd	%xmm2, %xmm0	# tmp69, D.2288
	addsd	%xmm1, %xmm0	# D.2288, D.2288
	movsd	%xmm0, -56(%rbp)	# D.2288, %sfp
	movq	-56(%rbp), %rax	# %sfp, <retval>
	movq	%rax, -56(%rbp)	# <retval>, %sfp
	movsd	-56(%rbp), %xmm0	# %sfp,
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	mysecond, .-mysecond
	.section	.rodata
	.align 8
.LC3:
	.long	2696277389
	.long	1051772663
	.ident	"GCC: (GNU) 4.8.5 20150623 (Red Hat 4.8.5-44)"
	.section	.note.GNU-stack,"",@progbits
