; da65 V2.18 - Ubuntu 2.18-1
; Created:    2024-02-22 21:08:36
; Input file: test
; Page:       1


        .setcpu "6502"

L803D           := $803D
L8050           := $8050
L805D           := $805D
L806C           := $806C
L807A           := $807A
L8083           := $8083
L8099           := $8099
        ldx     #$FF
        txs
        jsr     L803D
        brk
        brk
        brk
        .byte   $80
        brk
        brk
        jsr     L8099
        ldy     #$01
        lda     ($02),y
        tax
        dey
        lda     ($02),y
        jmp     L806C

        jsr     L8083
        lda     $02
        ldx     $03
        jsr     L8099
        nop
        jmp     L807A

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

        lda     #$19
        jsr     L8083
        ldy     #$00
        lda     ($02),y
        sta     $0A
        ldx     #$00
        lda     #$10
        jmp     L805D

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
        jmp     L8050

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

