; da65 V2.18 - Ubuntu 2.18-1
; Created:    2024-02-27 17:56:21
; Input file: test
; Page:       1


        .setcpu "6502"

L803D           := $803D
L8067           := $8067
L807C           := $807C
L808A           := $808A
L808F           := $808F
L80D5           := $80D5
L8137           := $8137
L817C           := $817C
L8187           := $8187
L81A1           := $81A1
L81B7           := $81B7
        .byte   $12
        .byte   $02
        .byte   $12
        .byte   $02
        .byte   $12
        .byte   $02
        brk
        brk
        brk
        brk
        ldx     #$FF
        txs
        jsr     L803D
        brk
        brk
        brk
        .byte   $80
        brk
        brk
        jsr     L81B7
        ldy     #$01
        lda     ($02),y
        tax
        dey
        lda     ($02),y
        jmp     L807C

        jsr     L81A1
        lda     $02
        ldx     $03
        jsr     L81B7
        nop
        jmp     L808A

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
        sta     $020A
        lda     #$06
        sta     $020D
        lda     $020A
        sta     $10
        lda     #$02
        sta     $020C
        lda     #$0A
        sta     $020B
        lda     #$16
        sta     $00
        ldx     #$00
        lda     #$08
        jsr     L808F
        ldx     #$00
        lda     #$10
        rts

        iny
        pha
        clc
        tya
        adc     $02
        sta     $02
        bcc     LFE95
        inc     $03
LFE95:  pla
        rts

        ldy     #$01
        lda     ($02),y
        tax
        dey
        lda     ($02),y
        inc     $02
        beq     LFEA8
        inc     $02
        beq     LFEAA
        rts

LFEA8:  inc     $02
LFEAA:  inc     $03
        rts

        ldy     #$03
        jmp     L8067

        sta     $0A
        stx     $0B
        ora     $0B
        beq     LFF19
        lda     $0A
        clc
        adc     #$04
        sta     $0A
        bcc     LFEC5
        inc     $0B
LFEC5:  ldx     $0B
        bne     LFED1
        cmp     #$07
        bcs     LFED1
        lda     #$06
        sta     $0A
LFED1:  lda     $0206
        sta     $0C
        lda     $0207
        sta     $0D
        jmp     L80D5

LFEDE:  ldy     #$00
        lda     ($0C),y
        sec
        sbc     $0A
        tax
        iny
        lda     ($0C),y
        sbc     $0B
        bcs     LFF2D
        iny
        lda     ($0C),y
        tax
        iny
        lda     ($0C),y
        stx     $0C
        sta     $0D
        ora     $0C
        bne     LFEDE
        lda     $0202
        clc
        adc     $0A
        tay
        lda     $0203
        adc     $0B
        bcs     LFF16
        cmp     $0205
        bne     LFF12
        cpy     $0204
LFF12:  bcc     LFF1A
        beq     LFF1A
LFF16:  lda     #$00
        tax
LFF19:  rts

LFF1A:  ldx     $0202
        stx     $0C
        ldx     $0203
        stx     $0D
        sty     $0202
        sta     $0203
        jmp     L817C

LFF2D:  bne     LFF82
        cpx     #$06
        bcs     LFF82
        ldy     #$05
        lda     ($0C),y
        sta     $0F
        dey
        lda     ($0C),y
        sta     $0E
        dey
        ora     $0F
        beq     LFF4F
        lda     ($0C),y
        sta     ($0E),y
        dey
        lda     ($0C),y
        sta     ($0E),y
        jmp     L8137

LFF4F:  lda     ($0C),y
        sta     $0207
        dey
        lda     ($0C),y
        sta     $0206
        lda     ($0C),y
        sta     $0E
        iny
        lda     ($0C),y
        sta     $0F
        iny
        ora     $0E
        beq     LFF74
        lda     ($0C),y
        sta     ($0E),y
        iny
        lda     ($0C),y
        sta     ($0E),y
        jmp     L8187

LFF74:  lda     ($0C),y
        sta     $0208
        iny
        lda     ($0C),y
        sta     $0209
        jmp     L8187

LFF82:  dey
        lda     ($0C),y
        sec
        sbc     $0A
        sta     ($0C),y
        tax
        iny
        lda     ($0C),y
        sbc     $0B
        sta     ($0C),y
        txa
        clc
        adc     $0C
        tax
        lda     ($0C),y
        adc     $0D
        stx     $0C
        sta     $0D
        ldy     #$00
        lda     $0A
        sta     ($0C),y
        iny
        lda     $0B
        sta     ($0C),y
        ldy     #$02
        lda     $0C
        sta     ($0C),y
        iny
        lda     $0D
        sta     ($0C),y
        lda     $0C
        ldx     $0D
        clc
        adc     #$04
        bcc     LFFBF
        inx
LFFBF:  rts

        ldy     #$00
        lda     ($02),y
        ldy     $02
        beq     LFFCF
        dec     $02
        ldy     #$00
        sta     ($02),y
        rts

LFFCF:  dec     $03
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
        bcs     LFFE6
        dec     $03
LFFE6:  ldy     #$01
        txa
        sta     ($02),y
        pla
        dey
        sta     ($02),y
        rts

        sec
        lda     $02
        sbc     #$00
        sta     $0204
        lda     $03
        .byte   $E9
LFFFB:  .byte   $02
LFFFC:  .byte   $8D
LFFFD:  ora     $02
        rts

