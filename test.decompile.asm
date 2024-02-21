; da65 V2.18 - Ubuntu 2.18-1
; Created:    2024-02-21 16:35:54
; Input file: test
; Page:       1


        .setcpu "6502"

L803D           := $803D
L805E           := $805E
L806B           := $806B
L807A           := $807A
L8088           := $8088
L8091           := $8091
L80A7           := $80A7
        ldx     #$FF
        txs
        jsr     L803D
        brk
        brk
        brk
        .byte   $80
        brk
        brk
        jsr     L80A7
        ldy     #$01
        lda     ($02),y
        tax
        dey
        lda     ($02),y
        jmp     L807A

        jsr     L8091
        lda     $02
        ldx     $03
        jsr     L80A7
        nop
        jmp     L8088

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

        lda     $1B
        jsr     L8091
        lda     #$19
        sta     $1B
        lda     #$25
        sta     $04
        pla
        sta     $05
        pla
        sta     $06
        ldx     #$00
        lda     #$10
        pha
        lda     ($02,x)
        sta     $1B
        pla
        jmp     L806B

        iny
        pha
        clc
        tya
        adc     $02
        sta     $02
        bcc     LFFAC
        inc     $03
LFFAC:  pla
        rts

        inc     $02
        bne     LFFB4
        inc     $03
LFFB4:  rts

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
        jmp     L805E

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

