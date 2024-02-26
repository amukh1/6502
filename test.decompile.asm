; da65 V2.18 - Ubuntu 2.18-1
; Created:    2024-02-25 23:30:41
; Input file: test
; Page:       1


        .setcpu "6502"

L803D           := $803D
L8097           := $8097
L80AC           := $80AC
L80BA           := $80BA
L80C3           := $80C3
L80D9           := $80D9
        ldx     #$FF
        txs
        jsr     L803D
        brk
        brk
        brk
        .byte   $80
        brk
        brk
        jsr     L80D9
        ldy     #$01
        lda     ($02),y
        tax
        dey
        lda     ($02),y
        jmp     L80AC

        jsr     L80C3
        lda     $02
        ldx     $03
        jsr     L80D9
        nop
        jmp     L80BA

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
        lda     #$34
        sta     $0205
        lda     #$12
        sta     $0204
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
        jmp     L8097

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

