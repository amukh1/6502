; da65 V2.18 - Ubuntu 2.18-1
; Created:    2024-03-04 14:00:48
; Input file: test
; Page:       1


        .setcpu "6502"

L801D           := $801D
L8035           := $8035
L8047           := $8047
        ldx     #$FF
        txs
        jsr     L801D
        brk
        brk
        brk
        .byte   $80
        brk
        brk
        jsr     L8047
        ldy     #$01
        lda     ($02),y
        sta     $10
        dey
        lda     ($02),y
        sta     $11
        jmp     L8035

        lda     #$04
        jsr     L8047
        lda     #$05
        jsr     L8047
        ldx     #$00
        txa
        jmp     L8035

        ldy     #$01
        lda     ($02),y
        tax
        dey
        lda     ($02),y
        inc     $02
        beq     LFFE5
        inc     $02
        beq     LFFE7
        rts

LFFE5:  inc     $02
LFFE7:  inc     $03
        rts

        ldy     #$00
        lda     ($02),y
        ldy     $02
        beq     LFFF9
        dec     $02
        ldy     #$00
        sta     ($02),y
        rts

LFFF9:  dec     $03
        dec     $02
        sta     ($02),y
        rts

