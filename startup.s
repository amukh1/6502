    .export __STARTUP__
    .import _main
    .importzp sp

__STARTUP__:
    ; Initialize the stack pointer
    ldx #$ff
    txs

    ; init software stack pointer
    lda #$01
    sta sp

    ; Call the main function
    jsr _main

    ; Endless loop after main returns
    ; jmp *

    ; Interrupt vectors
    ; .word $0000 ; NMI
    .word __STARTUP__ ; RESET
    .word $0000 ; IRQ