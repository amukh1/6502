; da65 V2.18 - Ubuntu 2.18-1
; Created:    2024-02-10 19:02:59
; Input file: test.bin
; Page:       1


        .setcpu "6502"

L8000           := $8000
L800A           := $800A
        ldx     #$00
        txa
        rts

        ldx     #$FF
        txs
        jsr     L8000
        jmp     L800A

        brk
        brk
        .byte   $04
        .byte   $80
        brk
        brk
