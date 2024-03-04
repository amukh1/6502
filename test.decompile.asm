; da65 V2.18 - Ubuntu 2.18-1
; Created:    2024-03-04 18:50:57
; Input file: test
; Page:       1


        .setcpu "6502"

L800C           := $800C
L8023           := $8023
L8032           := $8032
L8068           := $8068
L806C           := $806C
L8079           := $8079
L8088           := $8088
L809A           := $809A
        ldx     #$FF
        txs
        jsr     L8032
        brk
        brk
        brk
        .byte   $80
        brk
        brk
        jsr     L809A
        ldy     #$01
        ldx     #$00
        lda     ($02),y
        sta     $10
        ldy     #$00
        ldx     #$00
        lda     ($02),y
        sta     $11
        jsr     L8088
        rts

        jsr     L809A
        ldy     #$00
        ldx     #$00
        lda     ($02),y
        sta     $12
        jsr     L8079
        rts

        jsr     L806C
        ldx     #$00
        lda     #$06
        ldy     #$01
        sta     ($02),y
        ldy     #$01
        lda     ($02),y
        jsr     L8023
        ldx     #$00
        lda     #$04
        ldy     #$00
        sta     ($02),y
        ldy     #$00
        lda     ($02),y
        jsr     L8023
        ldy     #$01
        lda     ($02),y
        jsr     L809A
        ldy     #$01
        lda     ($02),y
        jsr     L800C
        ldx     #$00
        lda     #$00
        jmp     L8068

        jsr     L8088
        rts

        lda     $02
        sec
        sbc     #$02
        sta     $02
        bcc     LFFCA
        rts

LFFCA:  dec     $03
        rts

        inc     $02
        bne     LFFD3
        inc     $03
LFFD3:  rts

        ldy     #$01
        lda     ($02),y
        tax
        dey
        lda     ($02),y
        inc     $02
        beq     LFFE5
        inc     $02
        beq     LFFE7
        rts

LFFE5:  inc     $02
LFFE7:  inc     $03
        rts

        ldy     #$00
        lda     ($02),y
        ldy     $02
        beq     LFFF9
        dec     $02
        ldy     #$00
        sta     ($02),y
        rts

LFFF9:  dec     $03
        dec     $02
        sta     ($02),y
        rts

