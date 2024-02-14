.org 0x8000
start:
JMP main


data1:
.byte "FROG!",10,0
data2:
.byte "SUBFROG!",10,0

sub:
NOP
LDA #(data2 & 0xFF)
STA 0xFFFD

LDA #0x80
STA 0xFFFB
RTS
main:
LDA #0x80
STA 0xFFFC
LDA #(data1 & 0xFF)
STA 0xFFFD

LDA #0x80
STA 0xFFFB
JSR sub

STA 0xFFFB

BRK
