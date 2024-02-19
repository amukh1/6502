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
	.export		_fish
	.export		_frog
	.export		_main

; ---------------------------------------------------------------
; int __near__ fish (int)
; ---------------------------------------------------------------

.segment	"CODE"

.proc	_fish: near

.segment	"CODE"

	jsr     pushax
	ldy     #$01
	lda     (sp),y
	tax
	dey
	lda     (sp),y
	jmp     incsp2

.endproc

; ---------------------------------------------------------------
; int __near__ frog (int)
; ---------------------------------------------------------------

.segment	"CODE"

.proc	_frog: near

.segment	"CODE"

	jsr     pushax
	ldx     #$00
	lda     #$07
	jsr     _fish
	ldy     #$01
	lda     (sp),y
	tax
	dey
	lda     (sp),y
	jmp     incsp2

.endproc

; ---------------------------------------------------------------
; int __near__ main (void)
; ---------------------------------------------------------------

.segment	"CODE"

.proc	_main: near

.segment	"CODE"

	ldx     #$00
	lda     #$06
	jsr     _frog
	ldx     #$00
	lda     #$10
	rts

.endproc

