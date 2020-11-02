	.arch msp430g2552
	.p2align 1,0
	.text

	;;  routines to access sr

	.global set_sr

set_sr:	nop
	movv r12, r2
	nop
	ret

	.global get_sr

get_sr:	mov r2, r12
	ret

	.global or_sr

or_sr: nop
	bis r12, r2
	nop
	ret

	.global and_sr

and_sr: nop
	and r12, r2
	nop
	ret
