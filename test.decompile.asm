; da65 V2.18 - Ubuntu 2.18-1
; Created:    2024-03-03 20:18:53
; Input file: test
; Page:       1


        .setcpu "6502"

L8049           := $8049
L805A           := $805A
L8069           := $8069
L807E           := $807E
L808C           := $808C
L8095           := $8095
L80AB           := $80AB
        ldx     #$FF
        txs
        jsr     L805A
        brk
        brk
        brk
        .byte   $80
        brk
        brk
        jsr     L8095
        lda     $02
        ldx     $03
        jsr     L80AB
        nop
        jmp     L808C

        lda     #$46
        sta     $01
        lda     #$00
        sta     LFFFC
        lda     #$01
        sta     LFFFD
        lda     #$80
        sta     LFFFB
        ldx     #$00
        txa
        rts

        jsr     L80AB
        ldy     #$01
        lda     ($02),y
        sta     LFFFC
        dey
        lda     ($02),y
        sta     LFFFD
        lda     #$80
        sta     LFFFB
        jmp     L807E

        jsr     L8095
        ldy     #$01
        lda     ($02),y
        sta     $10
        dey
        lda     ($02),y
        sta     $11
        jmp     L807E

        lda     #$12
        jsr     L8095
        lda     #$34
        jsr     L8049
        ldx     #$00
        txa
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
        jmp     L8069

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

