; da65 V2.18 - Ubuntu 2.18-1
; Created:    2024-02-20 16:01:28
; Input file: test
; Page:       1


        .setcpu "6502"

L803D           := $803D
L806C           := $806C
L8079           := $8079
L8088           := $8088
L8096           := $8096
L809F           := $809F
L80B5           := $80B5
        ldx     #$FF
        txs
        jsr     L803D
        brk
        brk
        brk
        .byte   $80
        brk
        brk
        jsr     L80B5
        ldy     #$01
        lda     ($02),y
        tax
        dey
        lda     ($02),y
        jmp     L8088

        jsr     L809F
        lda     $02
        ldx     $03
        jsr     L80B5
        nop
        jmp     L8096

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

        lda     #$02
        jsr     L809F
        sta     $02
        lda     #$61
        sta     $02
        ldx     #$12
        lda     #$34
        sta     $07
        stx     $08
        lda     #$68
        sta     $09
        lda     $09
        sta     LFFFC
        lda     $0A
        sta     LFFFD
        lda     #$80
        sta     LFFFB
        nop
        ldx     #$00
        lda     #$10
        jmp     L8079

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
        jmp     L806C

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

