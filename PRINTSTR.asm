.org 0x8000
start:
JMP main

data:
.byte "I LOVE FISH SO MUCH!",10,0
main:
LDA #0x80
STA 0xFFFC
LDA #((data & 0xFF))
STA 0xFFFD


; start syscall
LDA #0x80
STA 0xFFFB

BRK
