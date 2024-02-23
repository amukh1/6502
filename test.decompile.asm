; da65 V2.18 - Ubuntu 2.18-1
; Created:    2024-02-23 18:13:55
; Input file: test
; Page:       1


        .setcpu "6502"

L803D           := $803D
L807D           := $807D
L8092           := $8092
L80A0           := $80A0
L80A9           := $80A9
L80BF           := $80BF
        ldx     #$FF
        txs
        jsr     L803D
        brk
        brk
        brk
        .byte   $80
        brk
        brk
        jsr     L80BF
        ldy     #$01
        lda     ($02),y
        tax
        dey
        lda     ($02),y
        jmp     L8092

        jsr     L80A9
        lda     $02
        ldx     $03
        jsr     L80BF
        nop
        jmp     L80A0

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

        lda     #$0C
        sta     $0200
        lda     #$06
        sta     $0203
        lda     $0200
        sta     $10
        ldx     #$02
        lda     #$00
        sta     $0201
        stx     $0202
        sta     $0A
        stx     $0B
        tay
        lda     ($0A),y
        sta     $0203
        sta     $00
        lda     $0200
        sta     $0203
        lda     $0202
        sta     $12
        lda     $0201
        sta     $11
        lda     $0201
        sta     $05
        ldx     #$00
        lda     #$10
        rts

        iny
        pha
        clc
        tya
        adc     $02
        sta     $02
        bcc     LFFB3
        inc     $03
LFFB3:  pla
        rts

        ldy     #$01
        lda     ($02),y
        tax
        dey
        lda     ($02),y
        inc     $02
        beq     LFFC6
        inc     $02
        beq     LFFC8
        rts

LFFC6:  inc     $02
LFFC8:  inc     $03
        rts

        ldy     #$03
        jmp     L807D

        ldy     #$00
        lda     ($02),y
        ldy     $02
        beq     LFFDF
        dec     $02
        ldy     #$00
        sta     ($02),y
        rts

LFFDF:  dec     $03
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
        bcs     LFFF6
        dec     $03
LFFF6:  ldy     #$01
        txa
        sta     ($02),y
LFFFB:  pla
LFFFC:  dey
LFFFD:  sta     ($02),y
        rts

