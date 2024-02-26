; da65 V2.18 - Ubuntu 2.18-1
; Created:    2024-02-25 22:29:32
; Input file: test
; Page:       1


        .setcpu "6502"

L006F           := $006F
L803D           := $803D
L80A7           := $80A7
L80B4           := $80B4
L80C3           := $80C3
L80D1           := $80D1
L80DA           := $80DA
L80F0           := $80F0
        ldx     #$FF
        txs
        jsr     L803D
        brk
        brk
        brk
        .byte   $80
        brk
        brk
        jsr     L80F0
        ldy     #$01
        lda     ($02),y
        tax
        dey
        lda     ($02),y
        jmp     L80C3

        jsr     L80DA
        lda     $02
        ldx     $03
        jsr     L80F0
        nop
        jmp     L80D1

        lda     #$46
        sta     $00
        lda     #$00
        sta     LFFFC
        sta     LFFFD
        lda     #$80
        sta     LFFFB
        ldx     #$00
        txa
        rts

        lda     #$04
        jsr     L80DA
        lda     #$0C
        sta     $0200
        lda     #$06
        sta     $0203
        lda     $0200
        sta     $10
        lda     #$00
        ldx     #$02
        sta     $0201
        stx     $0202
        sta     $14
        stx     $15
        lda     $0201
        sta     $0205
        lda     $0200
        sta     $0204
        lda     $0201
        ldx     $0202
        sta     $0206
        stx     $0207
        sta     $14
        stx     $15
        sta     $0A
        stx     $0B
        ldy     #$01
        lda     ($0A),y
        sta     $0205
        dey
        lda     ($0A),y
        sta     $0204
        lda     $0203
        sta     $00
        lda     ($02),y
        sta     $05
        lda     #$81
        sta     $0209
        lda     #$06
        sta     $0208
        ldx     #$00
        lda     #$10
        jmp     L80B4

        iny
        pha
        clc
        tya
        adc     $02
        sta     $02
        bcc     LFFA6
        inc     $03
LFFA6:  pla
        rts

        inc     $02
        bne     LFFAE
        inc     $03
LFFAE:  rts

        ldy     #$01
        lda     ($02),y
        tax
        dey
        lda     ($02),y
        inc     $02
        beq     LFFC0
        inc     $02
        beq     LFFC2
        rts

LFFC0:  inc     $02
LFFC2:  inc     $03
        rts

        ldy     #$03
        jmp     L80A7

        ldy     #$00
        lda     ($02),y
        ldy     $02
        beq     LFFD9
        dec     $02
        ldy     #$00
        sta     ($02),y
        rts

LFFD9:  dec     $03
        dec     $02
        sta     ($02),y
        rts

        lda     #$00
        ldx     #$00
        pha
        lda     $02
        sec
        sbc     #$02
        sta     $02
        bcs     LFFF0
        dec     $03
LFFF0:  ldy     #$01
        txa
        sta     ($02),y
        pla
        dey
        sta     ($02),y
        rts

        pla
LFFFB:  .byte   $65
LFFFC:  .byte   $6C
LFFFD:  jmp     (L006F)

