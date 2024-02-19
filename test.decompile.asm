; da65 V2.18 - Ubuntu 2.18-1
; Created:    2024-02-15 18:11:00
; Input file: test
; Page:       1


        .setcpu "6502"

L800C           := $800C
L801A           := $801A
L802F           := $802F
L8043           := $8043
L8055           := $8055
        ldx     #$FF
        txs
        jsr     L802F
        brk
        brk
        brk
        .byte   $80
        brk
        brk
        jsr     L8055
        ldy     #$01
        lda     ($02),y
        tax
        dey
        lda     ($02),y
        jmp     L8043

        jsr     L8055
        ldx     #$00
        lda     #$07
        jsr     L800C
        ldy     #$01
        lda     ($02),y
        tax
        dey
        lda     ($02),y
        jmp     L8043

        ldx     #$00
        lda     #$06
        jsr     L801A
        ldx     #$00
        lda     #$10
        rts

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

