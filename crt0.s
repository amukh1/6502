.export _init, _exit
.exportzp sp
.import _main

.export __STARTUP__: absolute = 1
.import __RAM_START__, __RAM_SIZE__

.import copydata, zerobss, initlib, donelib

; .include "zeropage.inc"

; reserve byte or sp
.segment "ZEROPAGE"
sp: .res 1



.segment "STARTUP"

_init: ldx #$ff
        txs
        cld

        lda #<(__RAM_START__ + __RAM_SIZE__)
        STA sp
        lda #>(__RAM_START__ + __RAM_SIZE__)
        STA sp+1

        jsr zerobss
        jsr copydata
        jsr initlib

        jsr _main

_exit:
        jsr donelib
        brk

