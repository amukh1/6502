; da65 V2.18 - Ubuntu 2.18-1
; Created:    2024-02-14 16:05:59
; Input file: test
; Page:       1


        .setcpu "6502"

L8000           := $8000
L800E           := $800E
L801F           := $801F
L802F           := $802F
        lda     #$10
        jsr     L802F
        jmp     L801F

        ldx     #$FF
        txs
        jsr     L8000
        jmp     L800E

        brk
        brk
        php
        .byte   $80
        brk
        brk
        ldy     #$01
        lda     ($02),y
        tax
        dey
        lda     ($02),y
        inc     $02
        beq     LFFE1
        inc     $02
        beq     LFFE3
        rts

LFFE1:  inc     $02
LFFE3:  inc     $03
        rts

        lda     #$00
        ldx     #$00
        pha
        lda     $02
        sec
        sbc     #$02
        sta     $02
        bcs     LFFF6
        dec     $03
LFFF6:  ldy     #$01
        txa
        sta     ($02),y
        pla
        dey
        sta     ($02),y
        rts

