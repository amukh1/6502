.org 0x8000
start:
JMP (main+1)
.byte "FROG"
main:
JMP (0x800E)
LDA #0x80
STA 0xFFFC
LDA #0x03
STA 0xFFFD
LDA #0x80
STA 0xFFFE
LDA #0x0A
STA 0xFFFF



; start syscall
LDA #0x80
STA 0xFFFB

BRK
