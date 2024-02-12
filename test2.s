; da65 V2.18 - Ubuntu 2.18-1
; Created:    2024-02-12 18:56:05
; Input file: test
; Page:       1


        .setcpu "6502"

L0000           := $0000
L0840           := $0840
L0850           := $0850
L085A           := $085A
L086A           := $086A
L086E           := $086E
L0875           := $0875
L0878           := $0878
L088B           := $088B
L0897           := $0897
L08A2           := $08A2
L08B4           := $08B4
L08C0           := $08C0
L08FE           := $08FE
L0908           := $0908
L0916           := $0916
L0920           := $0920
L092B           := $092B
L0943           := $0943
L0950           := $0950
L095D           := $095D
L0990           := $0990
L0A15           := $0A15
L0A5E           := $0A5E
L0A85           := $0A85
L0A8B           := $0A8B
L0BAF           := $0BAF
L0C0F           := $0C0F
L0C19           := $0C19
L0C26           := $0C26
L0C2C           := $0C2C
L0C33           := $0C33
L0C4A           := $0C4A
L0C56           := $0C56
L0C63           := $0C63
L0C7E           := $0C7E
L0CF9           := $0CF9
L0D01           := $0D01
L0D0F           := $0D0F
L0D16           := $0D16
L0D1D           := $0D1D
L0D44           := $0D44
L0D5C           := $0D5C
L0D74           := $0D74
L0DB5           := $0DB5
L0DB8           := $0DB8
L0DEC           := $0DEC
L0DF1           := $0DF1
L0E38           := $0E38
L0E42           := $0E42
L0E70           := $0E70
L0E86           := $0E86
L0E94           := $0E94
L0EC7           := $0EC7
L0ECE           := $0ECE
L0ED0           := $0ED0
L0EE8           := $0EE8
L0F02           := $0F02
L0F1E           := $0F1E
L0F34           := $0F34
L0F5E           := $0F5E
L0F6D           := $0F6D
L0FE3           := $0FE3
L100C           := $100C
L1060           := $1060
L1219           := $1219
L1220           := $1220
L1279           := $1279
L1285           := $1285
L12A6           := $12A6
L9E03           := $9E03
        ora     ($08,x)
        .byte   $0B
        php
        jsr     L9E03
        .byte   $32
        bmi     LF58D
        and     (L0000),y
        brk
        brk
        lda     $01
        sta     $125D
        and     #$F8
        ora     #$06
        sta     $01
        tsx
        stx     $125E
        jsr     L1285
        jsr     L1060
        jsr     L0C33
        pha
        jsr     L0C4A
        ldx     #$19
LF579:  lda     $125F,x
        sta     $02,x
        dex
        bpl     LF579
        pla
        sta     $90
        ldx     $125E
        txs
        ldx     $125D
        stx     $01
LF58D:  rts

        lda     #$83
        ldx     #$10
        jsr     L0ED0
        ldy     #$02
        jsr     L0E94
        ldx     #$00
        txa
        rts

        jsr     L0C0F
        sta     L1279
        lda     #$FF
        tax
        rts

        sta     L1279
        tax
        beq     LF5B7
        jsr     L0E70
        jsr     L0C0F
        lda     #$FF
        tax
LF5B7:  rts

        ldy     #$00
        lda     ($18),y
        inc     $18
        bne     LF5C2
        inc     $19
LF5C2:  rts

        lda     L1285
        sta     $1280
        jsr     L0916
        lda     #$80
        ldx     #$12
        jsr     L0ED0
        jsr     L0EC7
        jmp     L1219

        lda     $16
        sec
        sbc     #$02
        sta     $16
        bcs     LF5E4
        dec     $17
LF5E4:  rts

        lda     $128A
        bne     LF5FB
        jsr     L08B4
        jmp     L0C2C

        lda     $128A
        bne     LF5FB
        jsr     L08B4
        jmp     L0C26

LF5FB:  jsr     L08B4
        sta     $04
        stx     $05
        jsr     L088B
        ldy     #$01
        lda     ($16),y
        tax
        dey
        lda     ($16),y
        rts

        ldy     #$00
        sty     $0A
        sty     $0B
LF614:  lda     ($18),y
        sec
        sbc     #$30
        bcc     LF647
        cmp     #$0A
        bcs     LF647
        jsr     L086E
        pha
        lda     $0A
        ldx     $0B
        asl     $0A
        rol     $0B
        asl     $0A
        rol     $0B
        adc     $0A
        sta     $0A
        txa
        adc     $0B
        sta     $0B
        asl     $0A
        rol     $0B
        pla
        adc     $0A
        sta     $0A
        bcc     LF614
        inc     $0B
        bcs     LF614
LF647:  lda     $0A
        ldx     $0B
        rts

        ldy     $128C
        inc     $128C
        sta     $128D,y
        rts

        lda     #$8D
        ldx     #$12
        clc
        adc     $128C
        bcc     LF661
        inx
LF661:  jmp     L0ED0

        lda     $1A
        ldx     $1B
        jmp     L0ED0

LF66B:  jsr     L0875
        inc     $1286
        bne     LF66B
        inc     $1287
        bne     LF66B
        rts

        jsr     L0916
        lda     $12A1
        ldx     $12A2
        jsr     L0ED0
        lda     $12A3
        ldx     $12A4
        jsr     L0ED0
        jmp     L1219

        sty     $0A
        jsr     L0D44
        jsr     L0908
        lda     $0A
        jmp     L0D74

        sty     $0A
        jsr     L0D44
        jsr     L0908
        lda     $0A
        jmp     L0DB5

        pha
        ldy     #$05
LF6AE:  lda     $16,y
        sta     $127A,y
        dey
        bpl     LF6AE
        pla
        sta     $16
        stx     $17
        jsr     L0CF9
        sta     $18
        stx     $19
        jsr     L0CF9
        sta     $1A
        stx     $1B
        lda     #$00
        tay
        sta     ($1A),y
        iny
        sta     ($1A),y
        iny
        lda     ($1A),y
        sta     $121A
        iny
        lda     ($1A),y
        sta     $121B
        lda     $18
        sta     $0A
        lda     $19
        sta     $0B
        ldy     #$00
LF6E8:  lda     ($18),y
        beq     LF6F7
        cmp     #$25
        beq     LF6F7
        iny
        bne     LF6E8
        inc     $19
        bne     LF6E8
LF6F7:  tya
        clc
        adc     $18
        sta     $18
        bcc     LF701
        inc     $19
LF701:  sec
        sbc     $0A
        sta     $0C
        lda     $19
        sbc     $0B
        sta     $0D
        ora     $0C
        beq     LF735
        jsr     L0C63
        ldy     #$05
        lda     $1B
        sta     ($02),y
        dey
        lda     $1A
        sta     ($02),y
        dey
        lda     $0B
        sta     ($02),y
        dey
        lda     $0A
        sta     ($02),y
        dey
        lda     $0D
        sta     ($02),y
        dey
        lda     $0C
        sta     ($02),y
        jsr     L1219
LF735:  jsr     L086A
        tax
        bne     LF746
        ldx     #$05
LF73D:  lda     $127A,x
        sta     $16,x
        dex
        bpl     LF73D
        rts

LF746:  cmp     #$25
        bne     LF753
        lda     ($18),y
        cmp     #$25
        bne     LF759
        jsr     L086E
LF753:  jsr     L0878
        jmp     L0990

LF759:  lda     #$00
        ldx     #$0B
LF75D:  sta     $1281,x
        dex
        bpl     LF75D
        lda     ($18),y
        cmp     #$2D
        bne     LF76E
        stx     $1281
        beq     LF787
LF76E:  cmp     #$2B
        bne     LF777
        stx     $1282
        beq     LF787
LF777:  cmp     #$20
        bne     LF780
        stx     $1283
        beq     LF787
LF780:  cmp     #$23
        bne     LF78D
        stx     $1284
LF787:  jsr     L086E
        jmp     L0A15

LF78D:  ldx     #$20
        cmp     #$30
        bne     LF799
        tax
        jsr     L086E
        lda     ($18),y
LF799:  stx     L1285
        cmp     #$2A
        bne     LF7A9
        jsr     L086E
        jsr     L08B4
        jmp     L0A5E

LF7A9:  jsr     L08C0
        sta     $1286
        stx     $1287
        sty     $1288
        sty     $1289
        lda     ($18),y
        cmp     #$2E
        bne     LF7D9
        jsr     L086E
        lda     ($18),y
        cmp     #$2A
        bne     LF7D0
        jsr     L086E
        jsr     L08B4
        jmp     L0A85

LF7D0:  jsr     L08C0
        sta     $1288
        stx     $1289
LF7D9:  lda     ($18),y
        cmp     #$5A
        beq     LF7F8
        cmp     #$48
        beq     LF7F8
        cmp     #$54
        beq     LF7F8
        cmp     #$4A
        beq     LF7F3
        cmp     #$CC
        beq     LF7F3
        cmp     #$4C
        bne     LF7FE
LF7F3:  lda     #$FF
        sta     $128A
LF7F8:  jsr     L086E
        jmp     L0A8B

LF7FE:  sty     $128C
        ldx     #$8D
        stx     $12A1
        ldx     #$12
        stx     $12A2
        jsr     L086E
        cmp     #$43
        bne     LF820
        jsr     L08B4
        sta     $128D
        lda     #$00
        sta     $128E
        jmp     L0BAF

LF820:  cmp     #$44
        beq     LF828
        cmp     #$49
        bne     LF855
LF828:  ldx     #$00
        lda     $1283
        beq     LF831
        ldx     #$20
LF831:  lda     $1282
        beq     LF838
        ldx     #$2B
LF838:  stx     $128B
        jsr     L08A2
        ldy     $05
        bmi     LF84D
        ldy     $128B
        beq     LF84D
        sty     $128D
        inc     $128C
LF84D:  ldy     #$0A
        jsr     L0943
        jmp     L0BAF

LF855:  cmp     #$4E
        bne     LF86E
        jsr     L08B4
        sta     $0A
        stx     $0B
        ldy     #$00
        lda     ($1A),y
        sta     ($0A),y
        iny
        lda     ($1A),y
        sta     ($0A),y
        jmp     L0990

LF86E:  cmp     #$4F
        bne     LF899
        jsr     L08A2
        ldy     $1284
        beq     LF891
        pha
        stx     $12
        ora     $12
        ora     $04
        ora     $05
        ora     $1288
        ora     $1289
        beq     LF891
        lda     #$30
        jsr     L08FE
        pla
LF891:  ldy     #$08
        jsr     L0943
        jmp     L0BAF

LF899:  cmp     #$50
        bne     LF8AA
        ldx     #$00
        stx     $128A
        inx
        stx     $1284
        lda     #$58
        bne     LF8D1
LF8AA:  cmp     #$53
        bne     LF8BA
        jsr     L08B4
        sta     $12A1
        stx     $12A2
        jmp     L0BAF

LF8BA:  cmp     #$55
        bne     LF8C9
        jsr     L0897
        ldy     #$0A
        jsr     L0950
        jmp     L0BAF

LF8C9:  cmp     #$58
        beq     LF8D1
        cmp     #$D8
        bne     LF8FA
LF8D1:  pha
        lda     $1284
        beq     LF8E1
        lda     #$30
        jsr     L08FE
        lda     #$D8
        jsr     L08FE
LF8E1:  jsr     L0897
        ldy     #$10
        jsr     L0950
        pla
        cmp     #$58
        bne     LF8F7
        lda     $12A1
        ldx     $12A2
        jsr     L0F34
LF8F7:  jmp     L0BAF

LF8FA:  jmp     L0990

        lda     $12A1
        ldx     $12A2
        jsr     L0F1E
        sta     $12A3
        stx     $12A4
        lda     $1288
        ora     $1289
        beq     LF929
        ldx     $1288
        cpx     $12A3
        lda     $1289
        tay
        sbc     $12A4
        bcs     LF929
        stx     $12A3
        sty     $12A4
LF929:  sec
        lda     $1286
        sbc     $12A3
        tax
        lda     $1287
        sbc     $12A4
        bcs     LF93C
        lda     #$00
        tax
LF93C:  eor     #$FF
        sta     $1287
        txa
        eor     #$FF
        sta     $1286
        lda     $1281
        bne     LF94F
        jsr     L0920
LF94F:  jsr     L092B
        lda     $1281
        beq     LF95A
        jsr     L0920
LF95A:  jmp     L0990

        sta     $12A5
        lda     #$00
        sta     L12A6
        rts

        iny
        pha
        clc
        tya
        adc     $02
        sta     $02
        bcc     LF972
        inc     $03
LF972:  pla
        rts

        ldy     #$FF
        cpx     #$80
        bcs     LF97C
        ldy     #$00
LF97C:  sty     $04
        sty     $05
        rts

        lda     $121C
        ldx     $121D
        jsr     L0ED0
        lda     $121E
        ldx     $121F
        jsr     L0ED0
        ldy     #$04
        jmp     L0840

        ldy     #$00
        beq     LF9A3
        lda     #$FB
        ldx     #$11
        jmp     L1220

LF9A3:  rts

        lda     $02
        sec
        sbc     #$04
        sta     $02
        bcc     LF9AE
        rts

LF9AE:  dec     $03
        rts

        lda     $02
        sec
        sbc     #$06
        sta     $02
        bcc     LF9BB
        rts

LF9BB:  dec     $03
        rts

        ldx     #$00
        clc
LF9C1:  lda     $1245,x
        beq     LF9CB
        inx
        cpx     #$08
        bcc     LF9C1
LF9CB:  rts

        sta     $12A7
        sta     $0A
        stx     $12A8
        stx     $0B
        ldy     #$01
        lda     ($0A),y
        and     #$01
        bne     LF9E7
LF9DE:  lda     #$10
        jsr     L0C0F
        tax
        jmp     L0D0F

LF9E7:  lda     ($0A),y
        and     #$04
        bne     LF9DE
        ldy     #$00
        lda     ($0A),y
        ldx     #$00
        jsr     L0ED0
        ldy     #$09
        jsr     L0EE8
        ldy     #$07
        jsr     L0EE8
        ldy     #$09
        jsr     L0D16
        jsr     L0DF1
        cpx     #$00
        bne     LFA1A
        cmp     #$00
        bne     LFA1A
        ldy     #$05
        jsr     L0D16
        ldy     #$0A
        jmp     L0C19

LFA1A:  jsr     L100C
        cpx     #$FF
        bne     LFA39
        cmp     #$FF
        bne     LFA39
        lda     $12A7
        sta     $0A
        lda     $12A8
        sta     $0B
        ldy     #$01
        lda     ($0A),y
        ora     #$04
        sta     ($0A),y
        bne     LF9DE
LFA39:  jsr     L0ED0
        ldy     #$05
        jsr     L0D16
        jsr     L0F5E
        jmp     L0D0F

        ldy     #$01
        lda     ($02),y
        tax
        dey
        lda     ($02),y
        inc     $02
        beq     LFA58
        inc     $02
        beq     LFA5A
        rts

LFA58:  inc     $02
LFA5A:  inc     $03
        rts

        ldy     #$06
        jmp     L0C19

        ldy     #$01
        lda     ($02),y
        tax
        dey
        lda     ($02),y
        rts

        clc
        eor     #$FF
        adc     #$01
        pha
        txa
        eor     #$FF
        adc     #$00
        tax
        lda     $04
        eor     #$FF
        adc     #$00
        sta     $04
        lda     $05
        eor     #$FF
        adc     #$00
        sta     $05
        pla
        rts

        lda     #$00
        tax
        ldy     #$00
        sty     $04
        sty     $05
        pha
        jsr     L0C56
        ldy     #$03
        lda     $05
        sta     ($02),y
        dey
        lda     $04
        sta     ($02),y
        dey
        txa
        sta     ($02),y
        pla
        dey
        sta     ($02),y
        rts

        sta     $12
        jsr     L0CF9
        sta     $0C
        stx     $0D
        sta     $0E
        stx     $0F
        jsr     L0E86
        jsr     L0CF9
        sta     $04
        stx     $05
        rts

        jsr     L0D5C
        ldx     $05
        ldy     $12
        cpy     #$0A
        bne     LFB06
        lda     $04
        ora     $0B
        ora     $0A
        bne     LFAE6
        cpx     #$80
        bne     LFAE6
        ldy     #$0B
LFADB:  lda     $1095,y
        sta     ($0C),y
        dey
        bpl     LFADB
        jmp     L0DEC

LFAE6:  txa
        bpl     LFB06
        lda     #$2D
        ldy     #$00
        sta     ($0C),y
        inc     $0C
        bne     LFAF5
        inc     $0D
LFAF5:  lda     $0A
        ldx     $0B
        jsr     L0D1D
        sta     $0A
        stx     $0B
        jmp     L0DB8

        jsr     L0D5C
LFB06:  lda     #$00
        pha
LFB09:  ldy     #$20
        lda     #$00
LFB0D:  asl     $0A
        rol     $0B
        rol     $04
        rol     $05
        rol     a
        cmp     $12
        bcc     LFB1E
        sbc     $12
        inc     $0A
LFB1E:  dey
        bne     LFB0D
        tay
        lda     $1085,y
        pha
        lda     $0A
        ora     $0B
        ora     $04
        ora     $05
        bne     LFB09
        ldy     #$00
LFB32:  pla
        sta     ($0C),y
        beq     LFB3A
        iny
        bne     LFB32
LFB3A:  lda     $0E
        ldx     $0F
        rts

        sta     $10
        txa
        beq     LFB72
        stx     $11
        jsr     L0E86
        tya
        ldy     $0B
        beq     LFB75
        sta     $12
        ldy     #$10
        lsr     $11
        ror     $10
LFB56:  bcc     LFB63
        clc
        adc     $0A
        tax
        lda     $0B
        adc     $12
        sta     $12
        txa
LFB63:  ror     $12
        ror     a
        ror     $11
        ror     $10
        dey
        bne     LFB56
        lda     $10
        ldx     $11
        rts

LFB72:  jmp     L0E38

LFB75:  stx     $0B
        ldy     $0A
        ldx     $10
        stx     $0A
        sty     $10
        ldy     #$08
        jmp     L0E42

        sta     $10
        jsr     L0E86
        tya
        ldy     #$08
        ldx     $0B
        beq     LFBAD
        sta     $11
        lsr     $10
LFB94:  bcc     LFBA1
        clc
        adc     $0A
        tax
        lda     $0B
        adc     $11
        sta     $11
        txa
LFBA1:  ror     $11
        ror     a
        ror     $10
        dey
        bne     LFB94
        tax
        lda     $10
        rts

LFBAD:  lsr     $10
LFBAF:  bcc     LFBB4
        clc
        adc     $0A
LFBB4:  ror     a
        ror     $10
        dey
        bne     LFBAF
        tax
        lda     $10
        rts

        ldx     #$5A
LFBC0:  cmp     $119F,x
        beq     LFBCE
        dex
        dex
        bne     LFBC0
        lda     #$12
        ldx     #$00
        rts

LFBCE:  lda     $11A0,x
        ldx     #$00
        rts

        ldy     #$01
        lda     ($02),y
        sta     $0B
        dey
        lda     ($02),y
        sta     $0A
        jmp     L0D01

        sty     $12A9
        lda     $1215
        ldx     $1216
        jsr     L0ED0
        lda     $02
        ldx     $03
        clc
        adc     $12A9
        bcc     LFBF9
        inx
LFBF9:  sta     $0A
        stx     $0B
        ldy     #$01
        lda     ($0A),y
        tax
        dey
        lda     ($0A),y
        jsr     L0ED0
        lda     $0A
        ldx     $0B
        jsr     L0FE3
        ldy     $12A9
        jmp     L0C19

        lda     #$01
        jmp     L0ECE

        lda     #$00
        ldx     #$00
        pha
        lda     $02
        sec
        sbc     #$02
        sta     $02
        bcs     LFC2A
        dec     $03
LFC2A:  ldy     #$01
        txa
        sta     ($02),y
        pla
        dey
        sta     ($02),y
        rts

        ldy     #$03
        lda     $02
        sec
        sbc     #$02
        sta     $02
        bcs     LFC41
        dec     $03
LFC41:  lda     ($02),y
        tax
        dey
        lda     ($02),y
        ldy     #$00
        sta     ($02),y
        iny
        txa
        sta     ($02),y
        rts

        eor     #$FF
        sta     $0C
        txa
        eor     #$FF
        sta     $0D
        jsr     L0E86
        sty     $0E
        sty     $0F
        jsr     L0CF9
        cpx     #$01
        bcs     LFC6B
        cmp     #$08
        sta     $13
LFC6B:  rts

        sta     $0C
        stx     $0D
        ldx     #$00
        ldy     #$00
LFC74:  lda     ($0C),y
        beq     LFC80
        iny
        bne     LFC74
        inc     $0D
        inx
        bne     LFC74
LFC80:  tya
        rts

        sta     $0A
        stx     $0B
        sta     $0C
        stx     $0D
        ldy     #$00
LFC8C:  lda     ($0A),y
        beq     LFCA5
        tax
        lda     $10A1,x
        and     #$02
        beq     LFC9E
        txa
        sec
        sbc     #$80
        sta     ($0A),y
LFC9E:  iny
        bne     LFC8C
        inc     $0B
        bne     LFC8C
LFCA5:  lda     $0C
        ldx     $0D
        rts

        ldx     #$00
        sta     $10
        stx     $11
        jsr     L0E86
        jsr     L0F6D
        lda     $0A
        ldx     $0B
        rts

        lda     #$00
        sta     $05
        ldy     #$10
        ldx     $11
        beq     LFCE4
LFCC5:  asl     $0A
        rol     $0B
        rol     a
        rol     $05
        tax
        cmp     $10
        lda     $05
        sbc     $11
        bcc     LFCDD
        sta     $05
        txa
        sbc     $10
        tax
        inc     $0A
LFCDD:  txa
        dey
        bne     LFCC5
        sta     $04
        rts

LFCE4:  asl     $0A
        rol     $0B
        rol     a
        bcs     LFCEF
        cmp     $10
        bcc     LFCF3
LFCEF:  sbc     $10
        inc     $0A
LFCF3:  dey
        bne     LFCE4
        sta     $04
        rts

        ldy     #$05
        jsr     L0EE8
        jsr     L0EC7
        ldy     #$07
        jsr     L0EE8
        lda     $1259
        ldx     $125A
        jsr     L0C7E
        sta     $0A
        stx     $0B
        ora     $0B
        bne     LFD1E
        lda     #$FF
        sta     $1255
        bne     LFD2B
LFD1E:  lda     $0A
        clc
        adc     $1255
        sta     $1255
        txa
        adc     $1256
LFD2B:  sta     $1256
        jmp     L0D0F

        pha
        lda     #$00
        sta     $1255
        sta     $1256
        ldy     #$02
        lda     ($02),y
        sta     $1259
        lda     #$55
        sta     ($02),y
        iny
        lda     ($02),y
        sta     $125A
        lda     #$12
        sta     ($02),y
        pla
        jsr     L095D
        lda     $1255
        ldx     $1256
        rts

        jsr     L0F02
        bcs     LFDA9
        adc     #$03
        tax
        lda     $1242,x
        and     #$02
        beq     LFDA9
        jsr     LFFC9
        bcc     LFD8E
        jmp     L085A

LFD71:  ldy     #$00
        lda     ($0A),y
        inc     $0A
        bne     LFD7B
        inc     $0B
LFD7B:  jsr     LFFD2
        pha
        jsr     LFFB7
        lsr     a
        bne     LFDA3
        pla
        bcs     LFD96
        inc     $0E
        bne     LFD8E
        inc     $0F
LFD8E:  inc     $0C
        bne     LFD71
        inc     $0D
        bne     LFD71
LFD96:  jsr     LFFCC
        lda     #$00
        sta     L1279
        lda     $0E
        ldx     $0F
        rts

LFDA3:  pla
        lda     #$04
        jmp     L0850

LFDA9:  lda     #$10
        jmp     L0850

        lda     #$79
        sta     $0A
        lda     #$12
        sta     $0B
        lda     #$00
        tay
        ldx     #$00
        beq     LFDC7
LFDBD:  sta     ($0A),y
        iny
        bne     LFDBD
        inc     $0B
        dex
        bne     LFDBD
LFDC7:  cpy     #$31
LFDC9:  beq     LFDD0
        sta     ($0A),y
        iny
        bne     LFDC7
LFDD0:  rts

        pha
        brk
        bmi     LFE06
        .byte   $32
        .byte   $33
        .byte   $34
        and     $36,x
        .byte   $37
        sec
        and     $C2C1,y
        .byte   $C3
        cpy     $C5
        dec     $2D
        .byte   $32
        and     ($34),y
        .byte   $37
        .byte   $34
        sec
        .byte   $33
        rol     $34,x
        sec
        brk
        bpl     LFE01
        bpl     LFE03
        bpl     LFE05
        bpl     LFE07
        bpl     LFDC9
        bvc     LFE0B
        bpl     LFE4D
        bpl     LFE0F
        bpl     LFE51
LFE01:  bpl     LFE53
LFE03:  bvc     LFE15
LFE05:  .byte   $10
LFE06:  .byte   $10
LFE07:  bpl     LFE19
        bpl     LFE1B
LFE0B:  bpl     LFE5D
        bpl     LFE1F
LFE0F:  ldy     #$00
        brk
        brk
        brk
        brk
LFE15:  brk
        brk
        brk
        brk
LFE19:  brk
        brk
LFE1B:  brk
        brk
        brk
        brk
LFE1F:  .byte   $0C
        .byte   $0C
        .byte   $0C
        .byte   $0C
        .byte   $0C
        .byte   $0C
        .byte   $0C
        .byte   $0C
        .byte   $0C
        .byte   $0C
        brk
        brk
        brk
        brk
        brk
        brk
        brk
        ora     #$09
        ora     #$09
        ora     #$09
        ora     ($01,x)
        ora     ($01,x)
        ora     ($01,x)
        ora     ($01,x)
        ora     ($01,x)
        ora     ($01,x)
        ora     ($01,x)
        ora     ($01,x)
        ora     ($01,x)
        ora     ($01,x)
        brk
        brk
        brk
LFE4D:  brk
        brk
        brk
        brk
LFE51:  brk
        brk
LFE53:  brk
        brk
        brk
        brk
        brk
        brk
        brk
        brk
        brk
        brk
LFE5D:  brk
        brk
        brk
        brk
        brk
        brk
        brk
        brk
        brk
        brk
        brk
        brk
        brk
        brk
        brk
        brk
        brk
        brk
        bpl     LFE81
        bpl     LFE83
        bpl     LFE85
        bpl     LFE87
        bpl     LFE89
        bpl     LFE8B
        bpl     LFECD
        bpl     LFE8F
        bpl     LFED1
LFE81:  bpl     LFED3
LFE83:  bvc     LFE95
LFE85:  bpl     LFE97
LFE87:  bpl     LFE99
LFE89:  bpl     LFE9B
LFE8B:  bpl     LFEDD
        bpl     LFE9F
LFE8F:  ldy     #$00
        brk
        brk
        brk
        brk
LFE95:  brk
        brk
LFE97:  brk
        brk
LFE99:  brk
        brk
LFE9B:  brk
        brk
        brk
        brk
LFE9F:  brk
        brk
        brk
        brk
        brk
        brk
        brk
        brk
        brk
        brk
        brk
        brk
        brk
        brk
        brk
        brk
        brk
        asl     a
        asl     a
        asl     a
        asl     a
        asl     a
        asl     a
        .byte   $02
        .byte   $02
        .byte   $02
        .byte   $02
        .byte   $02
        .byte   $02
        .byte   $02
        .byte   $02
        .byte   $02
        .byte   $02
        .byte   $02
        .byte   $02
        .byte   $02
        .byte   $02
        .byte   $02
        .byte   $02
        .byte   $02
        .byte   $02
        .byte   $02
        .byte   $02
        brk
        brk
        brk
LFECD:  brk
        brk
        brk
        brk
LFED1:  brk
        brk
LFED3:  brk
        brk
        brk
        brk
        brk
        brk
        brk
        brk
        brk
        brk
LFEDD:  brk
        brk
        brk
        brk
        brk
        brk
        brk
        brk
        brk
        brk
        brk
        brk
        brk
        brk
        brk
        brk
        brk
        brk
        ora     ($05,x)
        .byte   $02
        .byte   $07
        .byte   $03
        .byte   $07
        .byte   $04
        ora     ($05,x)
        .byte   $04
        asl     $07
        .byte   $07
        .byte   $07
        php
        .byte   $07
        ora     #$04
        .byte   $14
        asl     $15
        asl     $16
        .byte   $0B
        .byte   $17
        .byte   $0B
        clc
        .byte   $0B
        ora     $1A0B,y
        .byte   $03
        .byte   $1B
        .byte   $0B
        .byte   $1C
        .byte   $0B
        ora     $1E06,x
        .byte   $07
        .byte   $1F
        ora     $0720
        and     ($07,x)
        .byte   $22
        .byte   $07
        .byte   $27
        ora     ($31,x)
        .byte   $03
        .byte   $32
        asl     $0833
        .byte   $34
        php
        .byte   $3C
        asl     $3D
        .byte   $07
        rol     $3F01,x
        ora     #$40
        .byte   $07
        eor     ($0E,x)
        .byte   $42
        .byte   $07
        .byte   $43
        .byte   $0B
        lsr     $06
        .byte   $47
        .byte   $0B
        pha
        php
        eor     #$03
        lsr     a
        .byte   $04
        .byte   $4B
        .byte   $0B
        eor     $4E07
        .byte   $0B
        brk
        ora     (L0000,x)
        ora     ($01,x)
        brk
        .byte   $02
        ora     (L0000,x)
        brk
        brk
        brk
        brk
        brk
        brk
        brk
        brk
        brk
        brk
        brk
        brk
        brk
        brk
        brk
        .byte   $FB
        ora     ($FE),y
        ora     ($01),y
        .byte   $12
        jmp     L0000

        brk
        brk
        brk
        brk
        .byte   $8D
        .byte   $2E
LFF70:  .byte   $12
        stx     $122F
        sta     $1235
        stx     $1236
LFF7A:  dey
        lda     LFFFF,y
        sta     $123F
        dey
        lda     LFFFF,y
        sta     $123E
        sty     $1241
        jsr     LFFFF
        ldy     #$FF
        bne     LFF7A
        rts

        ora     ($02,x)
        .byte   $02
        brk
        brk
        brk
        brk
        brk
        brk
        .byte   $03
        .byte   $03
        brk
        brk
        brk
        brk
        brk
        brk
        brk
        .byte   $AB
        .byte   $0F
        brk
        brk
        brk
        brk
        brk
        brk
        brk
        brk
        brk
        brk
        brk
        brk
        brk
        brk
        brk
        brk
LFFB7:  brk
        brk
        brk
LFFBA:  brk
        brk
        brk
        brk
        brk
        brk
LFFC0:  brk
        brk
        brk
        brk
        brk
        brk
        brk
        ldy     #$02
LFFC9:  beq     LFFD2
        .byte   $A9
LFFCC:  bcs     LFF70
        .byte   $12
        jmp     L1220

LFFD2:  rts

        ldx     #$19
LFFD5:  lda     $02,x
        sta     $125F,x
        dex
        bpl     LFFD5
        lda     #$00
        ldx     #$D0
        sta     $02
        stx     $03
        lda     #$0E
        jsr     LFFD2
        jmp     L1279

        lda     #$04
        jsr     L12A6
        lda     #$05
        ldx     #$03
        ldy     #$FF
        jsr     LFFBA
        jmp     LFFC0

        .byte   $9F
LFFFF:  .byte   $12
