

start:
main:
JMP (0x800A)
LDA #0x00
STA 0xFFFC
LDA #0x00
STA 0xFFFD
LDA #0x00
STA 0xFFFE
LDA #0x0A
STA 0xFFFF



; start syscall
LDA #0x80
STA 0xFFFB

BRK
