; da65 V2.18 - Ubuntu 2.18-1
; Created:    2024-03-04 21:22:59
; Input file: test
; Page:       1


        .setcpu "6502"

L8034           := $8034
L8046           := $8046
L804A           := $804A
L8053           := $8053
L8062           := $8062
L8074           := $8074
        ldx     #$FF
        txs
        lda     #$01
        sta     $00
        jsr     L8034
        brk
        .byte   $80
        brk
        brk
        jsr     L8074
        ldy     #$01
        ldx     #$00
        lda     ($00),y
        sta     $10
        ldy     #$00
        ldx     #$00
        lda     ($00),y
        sta     $11
        jsr     L8062
        rts

        jsr     L8074
        ldy     #$00
        ldx     #$00
        lda     ($00),y
        sta     $10
        jsr     L8053
        rts

        jsr     L804A
        ldx     #$00
        lda     #$02
        ldy     #$00
        sta     ($00),y
        ldx     #$00
        lda     #$00
        jmp     L8046

        jsr     L8053
        rts

        ldy     $00
        bne     LFFCA
        dec     $01
LFFCA:  dec     $00
        rts

        inc     $00
        bne     LFFD3
        inc     $01
LFFD3:  rts

        ldy     #$01
        lda     ($00),y
        tax
        dey
        lda     ($00),y
        inc     $00
        beq     LFFE5
        inc     $00
        beq     LFFE7
        rts

LFFE5:  inc     $00
LFFE7:  inc     $01
        rts

        ldy     #$00
        lda     ($00),y
        ldy     $00
        beq     LFFF9
        dec     $00
        ldy     #$00
        sta     ($00),y
        rts

LFFF9:  dec     $01
        dec     $00
        sta     ($00),y
        rts

