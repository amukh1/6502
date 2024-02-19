.org 0x8000
start:
JMP main

.equ HELLO, data
.equ FROSCH, data+8
.equ ARR, data+17
data:
.byte "HELLO.",10,0
.byte "FROSCH.",10,0
.byte "ARRAY.",10,0

main:

LDA #0x80
STA 0xFFFC
LDA #(HELLO & 0xFF)
STA 0xFFFD

LDA #0x80
STA 0xFFFB

LDA #0x80
STA 0xFFFC
LDA #(FROSCH & 0xFF)
STA 0xFFFD

LDA #0x80
STA 0xFFFB

LDY #0

loop:
LDA (ARR & 0xFF),Y
CPY #5
BEQ end
INY
JMP loop
end:

BRK