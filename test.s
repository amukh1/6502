;
; File generated by cc65 v 2.18 - Ubuntu 2.18-1
;
	.fopt		compiler,"cc65 v 2.18 - Ubuntu 2.18-1"
	.setcpu		"6502"
	.smart		on
	.autoimport	on
	.case		on
	.debuginfo	off
	.importzp	sp, sreg, regsave, regbank
	.importzp	tmp1, tmp2, tmp3, tmp4, ptr1, ptr2, ptr3, ptr4
	.macpack	longbranch
	.forceimport	__STARTUP__
	.export		_testm
	.export		_tests
	.export		_main

; ---------------------------------------------------------------
; void __near__ testm (unsigned char, unsigned char)
; ---------------------------------------------------------------

.segment	"CODE"

.proc	_testm: near

.segment	"CODE"

	jsr     pusha
	ldy     #$01
	ldx     #$00
	lda     (sp),y
	sta     $0010
	ldy     #$00
	ldx     #$00
	lda     (sp),y
	sta     $0011
	jsr     incsp2
	rts

.endproc

; ---------------------------------------------------------------
; void __near__ tests (unsigned char)
; ---------------------------------------------------------------

.segment	"CODE"

.proc	_tests: near

.segment	"CODE"

	jsr     pusha
	ldy     #$00
	ldx     #$00
	lda     (sp),y
	sta     $0010
	jsr     incsp1
	rts

.endproc

; ---------------------------------------------------------------
; int __near__ main (void)
; ---------------------------------------------------------------

.segment	"CODE"

.proc	_main: near

.segment	"CODE"

	jsr     decsp1
	ldx     #$00
	lda     #$04
	ldy     #$00
	sta     (sp),y
	ldx     #$00
	lda     #$00
	jmp     L0009
L0009:	jsr     incsp1
	rts

.endproc

