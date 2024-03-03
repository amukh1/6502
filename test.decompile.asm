; da65 V2.18 - Ubuntu 2.18-1
; Created:    2024-03-03 00:31:49
; Input file: test
; Page:       1


        .setcpu "6502"

L206F           := $206F
L8049           := $8049
L8087           := $8087
L809C           := $809C
L80AA           := $80AA
L80B3           := $80B3
L80C9           := $80C9
        ldx     #$FF
        txs
        jsr     L8049
        brk
        brk
        brk
        .byte   $80
        brk
        brk
        jsr     L80B3
        lda     $02
        ldx     $03
        jsr     L80C9
        nop
        jmp     L80AA

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

        jsr     L80C9
        ldy     #$01
        lda     ($02),y
        sta     LFFFC
        dey
        lda     ($02),y
        sta     LFFFD
        lda     #$80
        sta     LFFFB
        jmp     L809C

        lda     #$06
        sta     $0200
        lda     #$12
        sta     $0210
        ldx     #$02
        lda     #$11
        sta     $0201
        stx     $0202
        sta     $0A
        stx     $0B
        lda     #$13
        ldy     #$00
        sta     ($0A),y
        lda     #$80
        sta     $0204
        lda     #$DF
        sta     $0203
        lda     $0204
        sta     LFFFC
        lda     $0203
        sta     LFFFD
        lda     #$80
        sta     LFFFB
        ldx     #$00
        txa
        rts

        iny
        pha
        clc
        tya
        adc     $02
        sta     $02
        bcc     LFFA5
        inc     $03
LFFA5:  pla
        rts

        ldy     #$01
        lda     ($02),y
        tax
        dey
        lda     ($02),y
        inc     $02
        beq     LFFB8
        inc     $02
        beq     LFFBA
        rts

LFFB8:  inc     $02
LFFBA:  inc     $03
        rts

        ldy     #$03
        jmp     L8087

        ldy     #$00
        lda     ($02),y
        ldy     $02
        beq     LFFD1
        dec     $02
        ldy     #$00
        sta     ($02),y
        rts

LFFD1:  dec     $03
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
        bcs     LFFE8
        dec     $03
LFFE8:  ldy     #$01
        txa
        sta     ($02),y
        pla
        dey
        sta     ($02),y
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
