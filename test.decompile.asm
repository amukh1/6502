; da65 V2.18 - Ubuntu 2.18-1
; Created:    2024-03-05 13:27:12
; Input file: test
; Page:       1


        .setcpu "6502"

L206F           := $206F
L8034           := $8034
L8062           := $8062
L8063           := $8063
L8072           := $8072
L8084           := $8084
        ldx     #$FF
        txs
        lda     #$01
        sta     $00
        jsr     L8034
        brk
        .byte   $80
        brk
        brk
        jsr     L8084
        ldy     #$01
        ldx     #$00
        lda     ($00),y
        sta     $10
        ldy     #$00
        ldx     #$00
        lda     ($00),y
        sta     $11
        jsr     L8072
        rts

        jsr     L8084
        ldy     #$00
        ldx     #$00
        lda     ($00),y
        sta     $10
        jsr     L8063
        rts

        lda     #$96
        ldx     #$80
        sta     $0200
        stx     $0201
        ldx     #$00
        lda     $0201
        ldx     #$00
        sta     LFFFC
        ldx     #$00
        lda     $0200
        ldx     #$00
        ldx     #$00
        sta     LFFFD
        ldx     #$00
        lda     #$80
        sta     LFFFB
        ldx     #$00
        lda     #$00
        jmp     L8062

        rts

        inc     $00
        bne     LFFC5
        inc     $01
LFFC5:  rts

        ldy     #$01
        lda     ($00),y
        tax
        dey
        lda     ($00),y
        inc     $00
        beq     LFFD7
        inc     $00
        beq     LFFD9
        rts

LFFD7:  inc     $00
LFFD9:  inc     $01
        rts

        ldy     #$00
        lda     ($00),y
        ldy     $00
        beq     LFFEB
        dec     $00
        ldy     #$00
        sta     ($00),y
        rts

LFFEB:  dec     $01
        dec     $00
        sta     ($00),y
        rts

        pha
        adc     $6C
        jmp     (L206F)

        .byte   $57
        .byte   $6F
        .byte   $72
LFFFB:  .byte   $6C
LFFFC:  .byte   $64
LFFFD:  and     ($0A,x)
        brk
