; da65 V2.18 - Ubuntu 2.18-1
; Created:    2024-02-28 13:55:48
; Input file: test
; Page:       1


        .setcpu "6502"

L803D           := $803D
L804C           := $804C
L8061           := $8061
L806F           := $806F
L8078           := $8078
L808C           := $808C
L808E           := $808E
        ldx     #$FF
        txs
        jsr     L803D
        brk
        brk
        brk
        .byte   $80
        brk
        brk
        jsr     L808E
        ldy     #$01
        lda     ($02),y
        tax
        dey
        lda     ($02),y
        jmp     L8061

        jsr     L8078
        lda     $02
        ldx     $03
        jsr     L808E
        nop
        jmp     L806F

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

        lda     #$01
        jsr     L808C
        nop
        pla
        sta     $04
        lda     #$10
        jmp     L8061

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
        jmp     L804C

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

